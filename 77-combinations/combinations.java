class Solution {

public List<List<Integer>> combine(int n, int k) {

    List<List<Integer>> set = new ArrayList<>();
    backtrack(set, new ArrayList<>(), n, k, 1);

    return set;
}

public void backtrack(List<List<Integer>> set, List<Integer> list, int range, int combinations, int index) {

    if (list.size() == combinations) {
        set.add(new ArrayList<>(list));
        return;
    }
    
    for (int i = index; i <= range; i++) {

        list.add(i);
        backtrack(set, list, range, combinations, i + 1);
        list.remove(list.size() - 1);
    }
}
}