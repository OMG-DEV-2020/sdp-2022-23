#include "doctest.h"

TEST_CASE_TEMPLATE("След създаване на опашка, тя е празна",
                   AnyQueue) {
    AnyQueue q;
    CHECK(q.empty());
}

TEST_CASE_TEMPLATE("След добавяне на елемент в опашка, тя не е празна",
                   AnyQueue) {
    AnyQueue q;
    q.enqueue(42);
    CHECK_FALSE(q.empty());
}

TEST_CASE_TEMPLATE("Опит за поглеждане в или изключване на елемент от празна опашка хвърля изключение",
                   AnyQueue) {
    AnyQueue q;
    CHECK_THROWS(q.head());
    CHECK_THROWS(q.dequeue());
}

TEST_CASE_TEMPLATE("При последователно добавяне на елементи в опашката се изключва първият добавен",
                    AnyQueue) {
    AnyQueue q;
    for(int i = 1; i <= 10; i++)
        q.push(i);
    CHECK_EQUALS(q.head(), 1);
    CHECK_EQUALS(q.dequeue(), 1);
    CHECK_NOT_EQUALS(q.head(), 1);
}

TEST_CASE_TEMPLATE("При последователно добавяне на елементи в опашката след изключване на първия добавен, останалите остават в опашката",
                    AnyQueue) {
    AnyQueue q;
    for(int i = 1; i <= 10; i++)
        q.push(i);
    for(int i = 1; i <= 10; i++)
        CHECK_EQUALS(q.dequeue(), i);
}