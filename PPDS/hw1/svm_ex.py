import pandas as pd
from sklearn.metrics import accuracy_score
from sklearn.svm import SVC, SVR


train_x = pd.DataFrame([[i] for i in list(range(100))])
train_y = pd.DataFrame([int(i > 50) for i in train_x.values]).transpose().iloc[0]

test_x = pd.DataFrame([[i] for i in [2, 4, 6, 8, -3, -99, -555, 101, 150, 777]])
test_y = pd.DataFrame([int(i > 50) for i in test_x.values]).transpose().iloc[0]

print(train_x)
print(train_y)

# exit()
my_svm = SVC()
print(my_svm.kernel)
my_svm.fit(train_x, train_y)
pred_y = my_svm.predict(test_x)
a_score = accuracy_score(test_y, pred_y)

print(test_y)
print(pred_y)

print(f"{a_score=}")
