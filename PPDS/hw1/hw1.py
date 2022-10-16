import pandas as pd
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import OneHotEncoder
from sklearn.svm import SVC, LinearSVC

# prepare data #

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


ohe = OneHotEncoder()
ohe.fit(adult_data[nominal_features])


def one_hot_encoding(df, cols):
    one_hot_features = ohe.transform(df[cols]).toarray()
    one_hot_features = pd.DataFrame(
        one_hot_features, columns=ohe.get_feature_names_out(cols)
    )

    # print(one_hot_features)
    return one_hot_features


def prepare_x(df: pd.DataFrame):
    return df[[x for x in features if x not in nominal_features]].join(
        one_hot_encoding(df, nominal_features)
    )


train_x = prepare_x(adult_data)
train_y = adult_data[output].transpose().iloc[0]  # reshape from n*1 to 1d

# print(train_x)
# print(train_y)

adult_svm = SVC()
adult_svm.fit(X=train_x, y=train_y)  # train svm

# prepare test data

test_x = prepare_x(adult_test)
test_y = adult_test[output].transpose().iloc[0].to_numpy()  # reshape from n*1 to 1d

# print(test_x)
# print(test_y)

# print(type(test_y))

y_pred = adult_svm.predict(test_x)

# print(y_pred)
# print(type(y_pred))

accuracy_origin = accuracy_score(y_true=test_y, y_pred=y_pred)

print(f"{accuracy_origin=}")

# do k-anonymity
# preprocessing datasets
# run svm on origin data
# test with origin test data
# run svm on processed data
# test with origin test data
