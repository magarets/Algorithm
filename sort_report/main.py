import copy

import pandas as pd
import random
import sys
import os
import math
import datetime
from time import time


def create_random_number(number_size, list_size):
    print("create random number . . .")

    num_list = []
    chk_list = [0 for i in range(list_size)]  # 0으로 초기화
    count = 0
    while count < list_size:
        num = random.randrange(0, number_size)
        if chk_list[num] != 0:
            continue
        count += 1
        num_list.append(num)
        chk_list[num] = 1
    print("done!\n")

    return num_list


def create_random_number_list(number_size, list_size):
    st = time()
    random_number_list = create_random_number(number_size, list_size)
    end = time()
    get_time(st, end)
    return random_number_list


# pivot is first number
def quick_sort_1(array):
    # 리스트가 하나 이하의 원소만을 담고 있다면 종료
    if len(array) <= 1:
        return array

    pivot = array[0]  # 피벗은 첫 번째 원소
    tail = array[1:]  # 피벗을 제외한 리스트

    left_side = [x for x in tail if x <= pivot]  # 분할된 왼쪽 부분
    right_side = [x for x in tail if x > pivot]  # 분할된 오른쪽 부분

    # 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬을 수행하고, 전체 리스트를 반환
    return quick_sort_1(left_side) + [pivot] + quick_sort_1(right_side)


def get_time(st, end):
    sec = end - st
    res = datetime.timedelta(seconds=sec)
    # print(f"time: {res}\n")
    return res


def quick_sort_2(arr, first, last):
    if first >= last:
        return

    mid = partition(arr, first, last)

    quick_sort_2(arr, first, mid - 1)
    quick_sort_2(arr, mid, last)

    return arr


def partition(arr, first, last):
    pivot = arr[(first + last) // 2]

    while first <= last:
        while arr[first] < pivot:
            first += 1

        while arr[last] > pivot:
            last -= 1

        if first <= last:
            arr[first], arr[last] = arr[last], arr[first]
            first, last = first + 1, last - 1

    return first


# quick sort from random number list
def quick_sort_from_random_number_list(random_number_list, number_size):
    sys.setrecursionlimit(10 ** 8)
    st = time()
    print("quick sort start . . .")
    quick_sort_number_list = quick_sort_2(random_number_list, 0, number_size - 1)
    print("quick sort end !\n")
    end = time()
    quick_sort_time = get_time(st, end)

    return quick_sort_number_list, quick_sort_time


# list.sort()
def sort_by_list_func(copy_random_number_list):
    st = time()
    print("list.sort start . . .")
    # quick_sort_number_list = quick_sort_1(random_number_list)
    list.sort(copy_random_number_list)
    print("list.sort end !\n")
    end = time()
    list_sort_time = get_time(st, end)
    return copy_random_number_list, list_sort_time


def get_perform_diff(x, y):
    """
        * print format
        1. custom_quick_sort_time
        2. list.sort()_time
        3. difference time
    """
    print(f"quick sort time: {x}")
    print(f"list.sort time : {y}")
    print(f"diff: {y - x if x < y else x - y}\n")


def data_to_csv(random_number_list, path):
    st = time()
    print("create {} file . . .".format(path))
    with open("{}".format(path), "w") as file:
        for i in range(len(random_number_list)):
            file.write("{}\n".format(random_number_list[i]))
    file.close()
    end = time()
    print("success !\n")
    get_time(st, end)


def reverse_data_to_csv(_list, path):
    print("create {} file . . .".format(path))
    with open("{}".format(path), "w") as file:
        for i in range(len(_list) - 1, -1, -1):
            file.write("{}\n".format(_list[i]))
    file.close()
    print("success !\n")


def read_csv_file(path):
    # read csv file
    file = pd.read_csv(path)
    return file


def main():
    number_size = 1000000  # maximum number size
    list_size = number_size  # maximum list size { 0 ~ number_size }
    random_path = "random_number.csv"
    forward_path = "forward_quick_sort.csv"
    reverse_path = "reverse_quick_sort.csv"

    # create random number list
    random_number_list = create_random_number_list(number_size=number_size, list_size=list_size)

    # use random_number_list instead create list
    #read_csv_file({})

    # copy random_number for using list.sort()
    copy_random_number_list = copy.deepcopy(random_number_list)

    # quick sort
    quick_sort_number_list, quick_sort_time = quick_sort_from_random_number_list(random_number_list, number_size)

    # quick sort by list.sort()
    quick_sort_list_func, quick_sort_list_func_time = sort_by_list_func(copy_random_number_list)

    # get difference time
    get_perform_diff(quick_sort_time, quick_sort_list_func_time)

    # random number to csv file
    data_to_csv(random_number_list, random_path)

    # quick sort to csv file
    data_to_csv(quick_sort_number_list, forward_path)

    # reverse sort to csv file
    reverse_data_to_csv(quick_sort_number_list, reverse_path)


if __name__ == '__main__':
    main()
