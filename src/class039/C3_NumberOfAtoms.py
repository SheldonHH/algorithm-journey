# 含有嵌套的分子式求原子数量
# 测试链接 : https://leetcode.cn/problems/number-of-atoms/
class Code03_NumberOfAtoms:
    def __init__(self):
        self.where = 0

    # 主函数
    def count_of_atoms(self, formula: str) -> str:
        self.where = 0
        atom_map = self._parse_formula(formula, 0)
        result = []
        for atom, count in sorted(atom_map.items()):
            result.append(atom)
            if count > 1:
                result.append(str(count))
        return ''.join(result)

    # formula[i....]开始计算，遇到字符串终止 或者 遇到 ')' 停止
    # 返回 : 自己负责的这一段字符串的结果，有序表！
    # 返回之间，更新全局变量where，为了上游函数知道从哪继续！
    def _parse_formula(self, formula: str, i: int):
        atom_map = {}
        name = ''
        pre = {}
        cnt = 0
        while i < len(formula) and formula[i] != ')':
            if formula[i].isupper() or formula[i] == '(':
                self._fill(atom_map, name, pre, cnt)
                name = ''
                pre = {}
                cnt = 0
                if formula[i].isupper():
                    name += formula[i]
                    i += 1
                else:  # 遇到 '('
                    pre, i = self._parse_formula(formula, i + 1)
            elif formula[i].islower():
                name += formula[i]
                i += 1
            else:
                cnt = cnt * 10 + int(formula[i])
                i += 1
        self._fill(atom_map, name, pre, cnt)
        self.where = i
        return atom_map, self.where

    # 将收集到的数据填充到总表中
    def _fill(self, atom_map, name, pre, cnt):
        cnt = 1 if cnt == 0 else cnt
        if name:
            atom_map[name] = atom_map.get(name, 0) + cnt
        else:
            for atom, count in pre.items():
                atom_map[atom] = atom_map.get(atom, 0) + count * cnt
