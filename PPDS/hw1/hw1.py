import pandas as pd
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import OneHotEncoder
from sklearn.svm import SVC


def one_hot_encoding(df, cols, ohe: OneHotEncoder):
    one_hot_features = ohe.transform(df[cols]).toarray()
    one_hot_features = pd.DataFrame(
        one_hot_features, columns=ohe.get_feature_names_out(cols)
    )

    # print(one_hot_features)
    return one_hot_features


def prepare_x(df: pd.DataFrame, features, nominal_features, ohe):
    return df[[x for x in features if x not in nominal_features]].join(
        one_hot_encoding(df, nominal_features, ohe)
    )


def get_ohe(df, target_columns):
    ohe = OneHotEncoder()
    ohe.fit(df[target_columns])
    return ohe


def train(train_data: pd.DataFrame, features, nominal_features, output, ohe):
    train_x = prepare_x(train_data, features, nominal_features, ohe)
    train_y = train_data[output].transpose().iloc[0]  # reshape from n*1 to 1d

    # print(train_x)
    # print(train_y)

    adult_svm = SVC()
    adult_svm.fit(X=train_x, y=train_y)  # train svm
    return adult_svm


def test(test_data: pd.DataFrame, features, nominal_features, output, ohe, model: SVC):
    # prepare test data

    test_x = prepare_x(test_data, features, nominal_features, ohe)
    test_y = test_data[output].transpose().iloc[0].to_numpy()  # reshape from n*1 to 1d

    # print(test_x)
    # print(test_y)

    # print(type(test_y))

    y_pred = model.predict(test_x)

    # print(y_pred)
    # print(type(y_pred))

    return accuracy_score(y_true=test_y, y_pred=y_pred)


def train_and_test(
    train_data: pd.DataFrame,
    test_data: pd.DataFrame,
    features,
    nominal_features,
    output,
):
    ohe = get_ohe(train_data, nominal_features)

    model = train(train_data, features, nominal_features, output, ohe)

    print(f"{test(test_data,features,nominal_features, output,ohe,model)=}")


def k_anonymize(df: pd.DataFrame):
    return df


def preprocess(df):
    """process range type data fields"""
    return df


def main():
    # column names
    features = [
        "age",
        "workclass",
        "fnlwgt",
        "education",
        "education-num",
        "marital-status",
        "occupation",
        "relationship",
        "race",
        "sex",
        "capital-gain",
        "capital-loss",
        "hours-per-week",
        "native-country",
    ]
    nominal_features = [
        "workclass",
        "education",
        "marital-status",
        "occupation",
        "relationship",
        "race",
        "sex",
        "native-country",
    ]
    output = ["income"]

    adult_data = pd.read_csv("./hw1/adult/adult.data", names=features + output)
    adult_test = pd.read_csv("./hw1/adult/adult.test", names=features + output)

    # print(adult_data)
    # print(adult_test)

    # print(adult_data[features])
    # print(adult_data[output])

    mini_features = features[::2]
    mini_nominal_features = [x for x in nominal_features if x in mini_features]

    # train and test with origin data
    train_and_test(adult_data, adult_test, mini_features, mini_nominal_features, output)

    # do k-anonymity
    k_data = k_anonymize(adult_data)

    k_data = preprocess(k_data)

    train_and_test(k_data, adult_test, mini_features, mini_nominal_features, output)


main()
