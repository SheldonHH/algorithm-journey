package class035;

import java.util.HashMap;

// 实现LRU结构
public class Code02_LRU {

	// 测试链接 : https://leetcode.cn/problems/lru-cache/
	// 结构中最多只能装三条结构
	// a的记录是3
	// b的记录是9
	// c的记录是15
	// a3删掉，d2进来，因为最早没访问过 https://www.bilibili.com/opus/935785791089541155?spm_id_from=333.999.0.0
	// put方法，和get方法都会刷新数的值 

	class LRUCache {
		// 链表头代表最早
		// 链表尾代表最晚
		class DoubleNode {
			public int key;
			public int val;
			public DoubleNode last;
			public DoubleNode next;

			public DoubleNode(int k, int v) {
				key = k;
				val = v;
			}
		}

		class DoubleList {
			private DoubleNode head;
			private DoubleNode tail;

			public DoubleList() {
				head = null;
				tail = null;
			}

			public void addNode(DoubleNode newNode) {
				if (newNode == null) {//捣乱的滚
					return;
				}
				if (head == null) {
					head = newNode;
					tail = newNode;
				} else {
					tail.next = newNode;
					newNode.last = tail; // 指向老尾巴
					tail = newNode; // 你成为新尾巴
				}
			}

			public void moveNodeToTail(DoubleNode node) {
				if (tail == node) {//本来就是最晚最新被call的
					return;
				}
				if (head == node) {
					head = node.next; // 头后移
					head.last = null; // 头last指针标空, 悬空
				} else {
					// 🌟 https://www.bilibili.com/opus/935788488070004745?spm_id_from=333.999.0.0
					node.last.next = node.next; // 前节点的next指针指向我的后面
					
					node.next.last = node.last;
				} // 👇https://www.bilibili.com/opus/935789197000704003?spm_id_from=333.999.0.0
				node.last = tail; //我的last指向尾巴
				node.next = null; //我的next设置为null
				tail.next = node; // 尾巴的next指向node
				tail = node;
			}

			public DoubleNode removeHead() { // 空间不够了
				if (head == null) { // 不用移除了
					return null;
				}
				DoubleNode ans = head;
				if (head == tail) { // 标空
					head = null;
					tail = null;
				} else {  
					head = ans.next; //下一个节点做头
					ans.next = null; //  ans  head(左指向右断链)
					head.last = null; // ans  head(右指向左断链) 
				}
				return ans;
			}

		}

		// key对应节点的内存地址
		// 
		private HashMap<Integer, DoubleNode> keyNodeMap;

		private DoubleList nodeList;//维持时间顺序的

		private final int capacity;

		public LRUCache(int cap) {
			keyNodeMap = new HashMap<>(); 
			nodeList = new DoubleList(); //内部类，加节点到尾部，节点移动到尾部，移出头节点
			// 维持时间顺序的
			capacity = cap;
		}


		// 会修改时间，变成最晚的
		public int get(int key) {
			if (keyNodeMap.containsKey(key)) {
				DoubleNode ans = keyNodeMap.get(key); 
				nodeList.moveNodeToTail(ans); // 返回给用户之前，在时间序列上移动到尾巴上
				return ans.val;
			}
			return -1; // 没记录
		}


		// 会修改时间，变成最晚的
		public void put(int key, int value) {
			if (keyNodeMap.containsKey(key)) { // 更新即可，无需真的插入
				DoubleNode node = keyNodeMap.get(key);
				node.val = value;
				nodeList.moveNodeToTail(node); // 双向链表维持时序，就很爽，扔到尾部：https://www.bilibili.com/opus/935786340634591257?spm_id_from=333.999.0.0
			} else {
				// 新增操作要讨论空间满还是没满
				if (keyNodeMap.size() == capacity) {
					 // 双向链表移出之后会返回，他的key在哈希表里面也删掉
					keyNodeMap.remove(nodeList.removeHead().key); // // 删掉之后头节点向下移动到a7 https://www.bilibili.com/opus/935786611428294662?spm_id_from=333.999.0.0
				}

				// 空间没问题
				DoubleNode newNode = new DoubleNode(key, value);
				keyNodeMap.put(key, newNode);
				nodeList.addNode(newNode);
			}
		}

	}

}
