package main

import "fmt"

type node struct {
	v int
	next *node
}

var head *node = nil

func (l *node) pushH(val int) *node {
	if head == nil {
		l.v = val
		l.next = nil
		head = l
		return l
	} else {
		nnode := new(node)
		nnode = head

		nnode2 := &node {
			v: val,
			next: nnode,
		}
		head = nnode2
		return head
	}
}

func (l *node) pushT(val int) *node {
	if head == nil {
		l.v = val
		l.next = nil
		head = l
		return l
	} else {
		for l.next != nil {
			l = l.next
		}

		l.next = new(node)
		l.next.v = val
		l.next.next = nil
		return l
	}
}

func (l *node) popH() *node {
	if head == nil {
		return head
	}

	cpnode := new(node)
	cpnode = head.next
	head = cpnode

	return head
}

func (l *node) popT() *node {
	if head == nil {
		return head
	}

	cpnode := new(node)
	cpnode = head

	for cpnode.next.next != nil {
		cpnode = cpnode.next
	}

	cpnode.next = nil
	return head
}

func main() {
	lista := new(node)
	lista.pushT(25).pushT(24).pushT(32)
	lista.pushT(56)
	lista.pushH(36)
	lista.popH()
	lista.popT()
	for head != nil {
		fmt.Printf("%d ",head.v)
		head = head.next
	}
}
