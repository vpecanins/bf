 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -o a.out"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg()
main::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    mov $r0.5 = 9   ## 9(SI32)
;;								## 0
	c0    add $r0.2 = $r0.1, 0x10   ## bblock 0, line 12,  t11,  t15,  offset(v?1.85)=0x10(P32)
	c0    add $r0.4 = $r0.1, 0x1c   ## bblock 0, line 13,  t6,  t15,  offset(fname?1.85)=0x1c(P32)
	c0    stw 0x28[$r0.1] = $l0.0  ## spill ## t14
;;								## 1
	c0    mov $r0.3 = (_?1PACKET.4 + 0)   ## addr(fname.?1AUTOINIT?1.85)(P32)
	c0    stw 0x2c[$r0.1] = $r0.4  ## spill ## t6
	c0    stw 0x30[$r0.1] = $r0.2  ## spill ## t11
;;								## 2
.call _bcopy, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:s32), ret()
	c0    call $l0.0 = _bcopy   ## bblock 0, line 13,  raddr(_bcopy)(P32),  addr(fname.?1AUTOINIT?1.85)(P32),  t6,  9(SI32)
;;								## 3
	c0    mov $r0.5 = (compress_3906.Buf + 0)   ## addr(compress_3906.Buf?1.0)(P32)
	c0    ldw $r0.2 = 0x2c[$r0.1]  ## restore ## t6
	c0    ldw $r0.4 = 0x30[$r0.1]  ## restore ## t11
;;								## 4
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    mov $r0.6 = 800   ## 800(SI32)
;;								## 5
	c0    stw 0[$r0.4] = $r0.2   ## bblock 0, line 16, t11, t6
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.0   ## bblock 0, line 17, 0(I32), 0x0(P32)
;;								## 6
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.5   ## bblock 0, line 18, 0(I32), addr(compress_3906.Buf?1.0)(P32)
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.6   ## bblock 0, line 19, 0(I32), 800(SI32)
;;								## 7
.call Compress, caller, arg($r0.3:s32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = Compress   ## bblock 0, line 20,  raddr(Compress)(P32),  1(SI32),  t11
;;								## 8
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 1, line 21,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 9
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x28[$r0.1]  ## restore ## t14
	      xnop 1
;;								## 11
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 2, line 22,  t15,  ?2.1?2auto_size(I32),  t14
;;								## 12
.endp
.section .bss
.section .data
_?1PACKET.4:
    .data1 67
    .data1 111
    .data1 109
    .data1 112
    .data1 114
    .data1 101
    .data1 115
    .data1 115
    .data1 0
.skip 3
_?1STRINGPACKET.1:
    .data1 99
    .data1 111
    .data1 109
    .data1 112
    .data1 114
    .data1 101
    .data1 115
    .data1 115
    .data1 58
    .data1 32
    .data1 115
    .data1 117
    .data1 99
    .data1 99
    .data1 101
    .data1 115
    .data1 115
    .data1 10
    .data1 0
.equ ?2.1?2scratch.0, 0x0
.equ _?1PACKET.3, 0x10
.equ _?1PACKET.5, 0x1c
.equ ?2.1?2ras_p, 0x28
.equ ?2.1?2spill_p, 0x2c
.section .data
.section .text
.equ ?2.1?2auto_size, 0x40
 ## End main
 ## Begin Usage
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
Usage::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    mov $r0.3 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
;;								## 0
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 0, line 44,  raddr(puts)(P32),  addr(_?1STRINGVAR.2)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t2
;;								## 1
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t2
	      xnop 1
;;								## 3
.return ret()
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 45,  t3,  ?2.2?2auto_size(I32),  t2
;;								## 4
.endp
.section .bss
.section .data
.skip 1
_?1STRINGPACKET.2:
    .data1 85
    .data1 115
    .data1 97
    .data1 103
    .data1 101
    .data1 58
    .data1 32
    .data1 99
    .data1 111
    .data1 109
    .data1 112
    .data1 114
    .data1 101
    .data1 115
    .data1 115
    .data1 32
    .data1 91
    .data1 45
    .data1 100
    .data1 102
    .data1 118
    .data1 99
    .data1 86
    .data1 93
    .data1 32
    .data1 91
    .data1 45
    .data1 98
    .data1 32
    .data1 109
    .data1 97
    .data1 120
    .data1 98
    .data1 105
    .data1 116
    .data1 115
    .data1 93
    .data1 32
    .data1 10
    .data1 0
.equ ?2.2?2scratch.0, 0x0
.equ ?2.2?2ras_p, 0x10
.section .data
.section .text
.equ ?2.2?2auto_size, 0x20
 ## End Usage
.equ _?1TEMPLATEPACKET.11, 0x0
 ## Begin rindex
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:u32,$r0.4:u32)
rindex::
.trace 3
	      ## auto_size == 0
	c0    add $r0.9 = $r0.3, 3   ## bblock 0, line 0,  t40,  t0,  3(I32)
	c0    add $r0.8 = $r0.3, 2   ## bblock 0, line 0,  t39,  t0,  2(I32)
;;								## 0
	c0    sxtb $r0.4 = $r0.4   ## bblock 0, line 61,  t1(SI8),  t20
	c0    mov $r0.5 = $r0.0   ## bblock 0, line 64,  t23,  0x0(P32)
	c0    add $r0.6 = $r0.3, 1   ## bblock 0, line 0,  t41,  t0,  1(I32)
	c0    mov $r0.2 = $r0.3   ## t0
;;								## 1
.trace 1
L0?3:
	c0    ldb $r0.3 = 0[$r0.2]   ## bblock 1, line 64, t2(SI8), t0
	c0    ldb.d $r0.7 = 0[$r0.6]   ## [spec] bblock 3, line 64-1, t35(SI8), t41
;;								## 0
	c0    ldb.d $r0.10 = 0[$r0.8]   ## [spec] bblock 11, line 64-2, t34(SI8), t39
	c0    ldb.d $r0.11 = 0[$r0.9]   ## [spec] bblock 8, line 64-3, t28(SI8), t40
;;								## 1
	c0    cmpne $b0.0 = $r0.3, $r0.0   ## bblock 1, line 64,  t51(I1),  t2(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.3, $r0.4   ## [spec] bblock 3, line 65,  t27(I1),  t2(SI8),  t1(SI8)
	c0    cmpne $b0.2 = $r0.7, $r0.0   ## [spec] bblock 3, line 64-1,  t52(I1),  t35(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.7, $r0.4   ## [spec] bblock 11, line 65-1,  t36(I1),  t35(SI8),  t1(SI8)
;;								## 2
	c0    slct $r0.3 = $b0.1, $r0.2, $r0.5   ## [spec] bblock 3, line 66,  t30,  t27(I1),  t0,  t23
	c0    cmpne $b0.0 = $r0.10, $r0.0   ## [spec] bblock 11, line 64-2,  t54(I1),  t34(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.10, $r0.4   ## [spec] bblock 8, line 65-2,  t32(I1),  t34(SI8),  t1(SI8)
	c0    brf $b0.0, L1?3   ## bblock 1, line 64,  t51(I1)
;;								## 3
	c0    slct $r0.7 = $b0.3, $r0.6, $r0.3   ## [spec] bblock 11, line 66-1,  t37,  t36(I1),  t41,  t30
	c0    cmpne $b0.2 = $r0.11, $r0.0   ## [spec] bblock 8, line 64-3,  t53(I1),  t28(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.11, $r0.4   ## [spec] bblock 5, line 65-3,  t24(I1),  t28(SI8),  t1(SI8)
	c0    brf $b0.2, L2?3   ## bblock 3, line 64-1,  t52(I1)
;;								## 4
	c0    slct $r0.3 = $b0.1, $r0.8, $r0.7   ## [spec] bblock 8, line 66-2,  t33,  t32(I1),  t39,  t37
	c0    add $r0.8 = $r0.8, 4   ## [spec] bblock 5, line 0,  t39,  t39,  4(I32)
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 5, line 64-3,  t0,  t0,  4(SI32)
	c0    brf $b0.0, L3?3   ## bblock 11, line 64-2,  t54(I1)
;;								## 5
	c0    slct $r0.5 = $b0.3, $r0.9, $r0.3   ## [spec] bblock 5, line 66-3,  t23,  t24(I1),  t40,  t33
	c0    add $r0.6 = $r0.6, 4   ## [spec] bblock 5, line 0,  t41,  t41,  4(I32)
	c0    add $r0.9 = $r0.9, 4   ## [spec] bblock 5, line 0,  t40,  t40,  4(I32)
	c0    brf $b0.2, L4?3   ## bblock 8, line 64-3,  t53(I1)
	      ## goto
;;
	c0    goto L0?3 ## goto
;;								## 6
.trace 7
L4?3:
.return ret($r0.3:u32)
	   ## bblock 6, line 0,  t29,  t33## $r0.3(skipped)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 67,  t8,  ?2.3?2auto_size(I32),  t7
;;								## 0
.trace 6
L3?3:
.return ret($r0.3:u32)
	c0    mov $r0.3 = $r0.7   ## bblock 9, line 0,  t29,  t37
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 67,  t8,  ?2.3?2auto_size(I32),  t7
;;								## 0
.trace 5
L2?3:
.return ret($r0.3:u32)
	   ## bblock 12, line 0,  t29,  t30## $r0.3(skipped)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 67,  t8,  ?2.3?2auto_size(I32),  t7
;;								## 0
.trace 4
L1?3:
.return ret($r0.3:u32)
	c0    mov $r0.3 = $r0.5   ## bblock 13, line 0,  t29,  t23
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 67,  t8,  ?2.3?2auto_size(I32),  t7
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.3?2auto_size, 0x0
 ## End rindex
.equ _?1TEMPLATEPACKET.1, 0x0
 ## Begin Compress
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:s32,$r0.4:u32)
Compress::
.trace 19
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    mov $r0.5 = (CompBuf + 0)   ## addr(CompBuf?1.0)(P32)
;;								## 0
	c0    stw 0x1c[$r0.1] = $r0.3  ## spill ## t0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t107
;;								## 1
	c0    ldw $r0.7 = ((buflen + 0) + 0)[$r0.0]   ## bblock 0, line 82, t123, 0(I32)
	c0    stw 0x20[$r0.1] = $r0.4  ## spill ## t121
;;								## 2
	c0    stw ((do_decomp + 0) + 0)[$r0.0] = $r0.0   ## bblock 0, line 77, 0(I32), 0(SI32)
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.5   ## bblock 0, line 80, 0(I32), addr(CompBuf?1.0)(P32)
;;								## 3
	c0    ldw $r0.3 = 0[$r0.4]   ## bblock 0, line 83, t10, t121
	c0    mov $r0.4 = 47   ## 47(SI32)
	c0    stw 0x24[$r0.1] = $r0.7  ## spill ## t123
;;								## 4
.call rindex, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:u32)
	c0    call $l0.0 = rindex   ## bblock 0, line 83,  raddr(rindex)(P32),  t10,  47(SI32)
;;								## 5
	c0    ldw $r0.3 = 0x1c[$r0.1]  ## restore ## t0
	c0    ldw $r0.4 = 0x20[$r0.1]  ## restore ## t121
	      xnop 1
;;								## 7
	c0    add $r0.2 = $r0.4, 4   ## bblock 3, line 89,  t127,  t121,  4(SI32)
	c0    add $r0.6 = $r0.3, -1   ## bblock 3, line 89,  t128,  t0,  -1(SI32)
;;								## 8
.trace 3
L5?3:
	c0    cmpgt $b0.0 = $r0.6, $r0.0   ## bblock 4, line 89,  t129(I1),  t128,  0(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 39, line 91, t25, t127
;;								## 0
	c0    brf $b0.0, L6?3   ## bblock 4, line 89,  t129(I1)
;;								## 1
	c0    ldb $r0.3 = 0[$r0.3]   ## bblock 39, line 91, t26(SI8), t25
	      xnop 1
;;								## 3
	c0    cmpeq $b0.0 = $r0.3, 45   ## bblock 39, line 91,  t144(I1),  t26(SI8),  45(SI32)
;;								## 4
	c0    brf $b0.0, L7?3   ## bblock 39, line 91,  t144(I1)
;;								## 5
.trace 1
L8?3:
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 41, line 93, t28, t127
	      xnop 1
;;								## 1
	c0    add $r0.4 = $r0.3, 1   ## bblock 41, line 93,  t29,  t28,  1(SI32)
;;								## 2
	c0    stw 0[$r0.2] = $r0.4   ## bblock 41, line 93, t127, t29
;;								## 3
	c0    ldb $r0.3 = 1[$r0.3]   ## bblock 41, line 93, t30(SI8), t28
	      xnop 1
;;								## 5
	c0    cmpne $b0.0 = $r0.3, $r0.0   ## bblock 41, line 93,  t145(I1),  t30(SI8),  0(SI32)
	c0    cmplt $r0.4 = $r0.3, 67   ## [spec] bblock 42, line 130,  t47,  t30(SI8),  67(SI32)
	c0    cmpgt $r0.5 = $r0.3, 118   ## [spec] bblock 42, line 130,  t48,  t30(SI8),  118(SI32)
;;								## 6
	c0    orl $b0.0 = $r0.4, $r0.5   ## [spec] bblock 42, line 130,  t146(I1),  t47,  t48
	c0    sh2add $r0.3 = $r0.3, ((_?1.Compress.TAGPACKET.0 + 0) - 268)   ## [spec] bblock 43, line 130,  t147,  t30(SI8),  (addr(_?1.Compress.TAGARRAY.0)(P32) - 0x10c(I32))(P32)
	c0    brf $b0.0, L7?3   ## bblock 41, line 93,  t145(I1)
;;								## 7
	c0    ldw.d $l0.0 = 0[$r0.3]   ## [spec] bblock 43, line 130, t50, t147
	c0    br $b0.0, L9?3   ## bblock 42, line 130,  t146(I1)
;;								## 8
;;								## 9
	c0    goto $l0.0   ## bblock 43, line 130,  t50
;;								## 10
_?1.Compress.TAG.0.0:
	c0    stw ((block_compress + 0) + 0)[$r0.0] = $r0.0   ## bblock 64, line 110, 0(I32), 0(SI32)
	c0    goto L8?3 ## goto
;;								## 11
.trace 9
_?1.Compress.TAG.0.7:
	c0    stw ((quiet + 0) + 0)[$r0.0] = $r0.0   ## bblock 45, line 101, 0(I32), 0(SI32)
	c0    goto L8?3 ## goto
;;								## 0
.trace 5
_?1.Compress.TAG.0.6:
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((quiet + 0) + 0)[$r0.0] = $r0.3   ## bblock 47, line 124, 0(I32), 1(SI32)
	c0    goto L8?3 ## goto
;;								## 1
.trace 6
_?1.Compress.TAG.0.5:
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((nomagic + 0) + 0)[$r0.0] = $r0.3   ## bblock 49, line 107, 0(I32), 1(SI32)
	c0    goto L8?3 ## goto
;;								## 1
.trace 7
_?1.Compress.TAG.0.4:
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((do_decomp + 0) + 0)[$r0.0] = $r0.3   ## bblock 51, line 104, 0(I32), 1(SI32)
	c0    goto L8?3 ## goto
;;								## 1
.trace 8
_?1.Compress.TAG.0.3:
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((zcat_flg + 0) + 0)[$r0.0] = $r0.3   ## bblock 53, line 121, 0(I32), 1(SI32)
	c0    goto L8?3 ## goto
;;								## 1
.trace 2
_?1.Compress.TAG.0.2:
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 55, line 113, t36, t127
	      xnop 1
;;								## 1
	c0    add $r0.4 = $r0.3, 1   ## bblock 55, line 113,  t37,  t36,  1(SI32)
;;								## 2
	c0    stw 0[$r0.2] = $r0.4   ## bblock 55, line 113, t127, t37
;;								## 3
	c0    ldb $r0.3 = 1[$r0.3]   ## bblock 55, line 113, t38(SI8), t36
	      xnop 1
;;								## 5
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## bblock 55, line 113,  t148(I1),  t38(SI8),  0(SI32)
;;								## 6
	c0    br $b0.0, L10?3   ## bblock 55, line 113,  t148(I1)
;;								## 7
L7?3:
	c0    add $r0.2 = $r0.2, 4   ## bblock 40, line 89,  t127,  t127,  4(SI32)
	c0    add $r0.6 = $r0.6, -1   ## bblock 40, line 89,  t128,  t128,  -1(SI32)
	c0    goto L5?3 ## goto
;;								## 8
.trace 13
L10?3:
	c0    add $r0.6 = $r0.6, -1   ## bblock 56, line 113,  t128,  t128,  -1(SI32)
	c0    ldw.d $r0.3 = 4[$r0.2]   ## [spec] bblock 57, line 113, t42, t127
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 57, line 113,  t127,  t127,  4(SI32)
;;								## 0
	c0    cmpeq $b0.0 = $r0.6, $r0.0   ## bblock 56, line 113,  t149(I1),  t128,  0(SI32)
;;								## 1
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## [spec] bblock 57, line 113,  t150(I1),  t42,  0x0(P32)
	c0    br $b0.0, L11?3   ## bblock 56, line 113,  t149(I1)
;;								## 2
	c0    br $b0.0, L11?3   ## bblock 57, line 113,  t150(I1)
	      ## goto
;;
	c0    goto L7?3 ## goto
;;								## 3
.trace 18
L11?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 58, line 115,  raddr(puts)(P32),  addr(_?1STRINGVAR.3)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.3 + 0)   ## addr(_?1STRINGVAR.3)(P32)
;;								## 0
.call Usage, caller, arg(), ret()
	c0    call $l0.0 = Usage   ## bblock 59, line 116,  raddr(Usage)(P32)
;;								## 1
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t107
	      xnop 1
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 60, line 117,  t108,  ?2.4?2auto_size(I32),  t107
;;								## 4
.trace 10
_?1.Compress.TAG.0.1:
.call version, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = version   ## bblock 62, line 98,  raddr(version)(P32)
	c0    stw 0x14[$r0.1] = $r0.2  ## spill ## t127
	c0    stw 0x18[$r0.1] = $r0.6  ## spill ## t128
;;								## 0
	c0    ldw $r0.2 = 0x14[$r0.1]  ## restore ## t127
	c0    ldw $r0.6 = 0x18[$r0.1]  ## restore ## t128
;;								## 1
	c0    goto L8?3 ## goto
;;								## 2
.trace 4
L12?3:
_?1.Compress.TAG.0.DEFAULT:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 66, line 127,  raddr(puts)(P32),  addr(_?1STRINGVAR.4)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.4 + 0)   ## addr(_?1STRINGVAR.4)(P32)
;;								## 0
.call Usage, caller, arg(), ret()
	c0    call $l0.0 = Usage   ## bblock 67, line 128,  raddr(Usage)(P32)
;;								## 1
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t107
	      xnop 1
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 68, line 129,  t108,  ?2.4?2auto_size(I32),  t107
;;								## 4
.trace 17
L9?3:
	c0    goto L12?3 ## goto
;;								## 0
.trace 21
L6?3:
	c0    ldw $r0.2 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 5, line 135, t51, 0(I32)
	c0    mov $r0.5 = 12   ## 12(SI32)
	c0    mov $r0.4 = 9   ## 9(SI32)
;;								## 0
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 9   ## bblock 5, line 135,  t130(I1),  t51,  9(SI32)
	c0    ldw.d $r0.8 = ((fsize + 0) + 0)[$r0.0]   ## [spec] bblock 7, line 141, t55, 0(I32)
;;								## 2
	c0    brf $b0.0, L13?3   ## bblock 5, line 135,  t130(I1)
;;								## 3
	c0    stw ((maxbits + 0) + 0)[$r0.0] = $r0.4   ## bblock 38, line 136, 0(I32), 9(SI32)
	c0    cmplt $b0.0 = $r0.8, 4096   ## [spec] bblock 7, line 141,  t132(I1),  t55,  4096(SI32)
;;								## 4
L14?3:
	c0    ldw $r0.2 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 6, line 137, t52, 0(I32)
	      xnop 1
;;								## 6
	c0    cmpgt $b0.1 = $r0.2, 12   ## bblock 6, line 137,  t131(I1),  t52,  12(SI32)
;;								## 7
	c0    brf $b0.1, L15?3   ## bblock 6, line 137,  t131(I1)
;;								## 8
	c0    stw ((maxbits + 0) + 0)[$r0.0] = $r0.5   ## bblock 37, line 138, 0(I32), 12(SI32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 7, line 140, 0(I32), 5003(SI32)
;;								## 9
L16?3:
	c0    ldw $r0.2 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 7, line 139, t53, 0(I32)
	      xnop 1
;;								## 11
	c0    shl $r0.3 = $r0.3, $r0.2   ## bblock 7, line 139,  t54,  1(SI32),  t53
;;								## 12
	c0    stw ((maxmaxcode + 0) + 0)[$r0.0] = $r0.3   ## bblock 7, line 139, 0(I32), t54
	c0    brf $b0.0, L17?3   ## bblock 7, line 141,  t132(I1)
;;								## 13
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 36, line 142, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 14
L18?3:
	c0    ldw $r0.2 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 13, line 153, t62, 0(I32)
	c0    mov $r0.5 = (CompBuf + 0)   ## addr(CompBuf?1.0)(P32)
;;								## 15
	c0    ldw $r0.6 = ((nomagic + 0) + 0)[$r0.0]   ## bblock 13, line 156, t66, 0(I32)
	c0    mov $r0.4 = (UnComp + 0)   ## addr(UnComp?1.0)(P32)
;;								## 16
	c0    add $r0.8 = $r0.2, -1   ## [spec] bblock 16, line 159,  t69,  t62,  -1(SI32)
	c0    mov $r0.9 = ((CompBuf + 0) + 1)   ## (addr(CompBuf?1.0)(P32) + 0x1(I32))(P32)
;;								## 17
	c0    cmpeq $b0.0 = $r0.6, $r0.0   ## bblock 13, line 156,  t137(I1),  t66,  0(SI32)
	c0    cmpge $b0.1 = $r0.8, $r0.0   ## [spec] bblock 16, line 158,  t138(I1),  t69,  0(SI32)
	c0    ldb.d $r0.10 = ((CompBuf + 0) + 0)[$r0.0]   ## [spec] bblock 31, line 158, t72(SI8), 0(I32)
;;								## 18
	c0    ldbu.d $r0.6 = ((magic_header + 0) + 0)[$r0.0]   ## [spec] bblock 18, line 158, t75(I8), 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
;;								## 19
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 13, line 153, 0(I32), t62
	c0    zxtb $r0.10 = $r0.10   ## [spec] bblock 31, line 158,  t67(I8),  t72(SI8)
;;								## 20
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.5   ## bblock 13, line 152, 0(I32), addr(CompBuf?1.0)(P32)
	c0    and $r0.6 = $r0.6, 255   ## [spec] bblock 18, line 158,  t76,  t75(I8),  255(I32)
;;								## 21
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 13, line 154, 0(I32), addr(UnComp?1.0)(P32)
	c0    cmpne $b0.2 = $r0.10, $r0.6   ## [spec] bblock 18, line 158,  t139(I1),  t67(I8),  t76
	c0    brf $b0.0, L19?3   ## bblock 13, line 156,  t137(I1)
;;								## 22
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.8   ## bblock 16, line 158, 0(I32), t69
	c0    brf $b0.1, L20?3   ## bblock 16, line 158,  t138(I1)
;;								## 23
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.9   ## bblock 31, line 158, 0(I32), (addr(CompBuf?1.0)(P32) + 0x1(I32))(P32)
	c0    brf $b0.2, L21?3   ## bblock 18, line 158,  t139(I1)
;;								## 24
L22?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 28, line 161,  raddr(puts)(P32),  addr(_?1STRINGVAR.5)(P32)
;;								## 25
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t107
	      xnop 1
;;								## 27
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 29, line 162,  t108,  ?2.4?2auto_size(I32),  t107
;;								## 28
.trace 27
L21?3:
	c0    ldw $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## bblock 19, line 159, t78, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 30, line 159, t80, 0(I32)
;;								## 0
	c0    ldbu.d $r0.5 = (((magic_header + 0) + 1) + 0)[$r0.0]   ## [spec] bblock 21, line 159, t85(I8), 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
;;								## 1
	c0    add $r0.2 = $r0.2, -1   ## bblock 19, line 159,  t79,  t78,  -1(SI32)
	c0    add $r0.6 = $r0.4, 1   ## [spec] bblock 30, line 159,  t81,  t80,  1(SI32)
;;								## 2
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 19, line 159, 0(I32), t79
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 19, line 159,  t140(I1),  t79,  0(SI32)
	c0    and $r0.5 = $r0.5, 255   ## [spec] bblock 21, line 159,  t86,  t85(I8),  255(I32)
;;								## 3
	c0    brf $b0.0, L23?3   ## bblock 19, line 159,  t140(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.6   ## bblock 30, line 159, 0(I32), t81
;;								## 5
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 30, line 159, t82(SI8), t80
	      xnop 1
;;								## 7
	c0    zxtb $r0.4 = $r0.4   ## bblock 30, line 159,  t77(I8),  t82(SI8)
;;								## 8
L24?3:
	c0    cmpne $b0.0 = $r0.4, $r0.5   ## bblock 21, line 159,  t141(I1),  t77(I8),  t86
;;								## 9
	c0    brf $b0.0, L25?3   ## bblock 21, line 159,  t141(I1)
	      ## goto
;;
	c0    goto L22?3 ## goto
;;								## 10
.trace 30
L25?3:
	c0    ldw $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## bblock 22, line 164, t90, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 27, line 164, t92, 0(I32)
;;								## 0
	c0    mov $r0.6 = 100000   ## 100000(SI32)
	c0    mov $r0.5 = 1   ## 1(SI32)
;;								## 1
	c0    add $r0.2 = $r0.2, -1   ## bblock 22, line 164,  t91,  t90,  -1(SI32)
	c0    add $r0.8 = $r0.4, 1   ## [spec] bblock 27, line 164,  t93,  t92,  1(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.6 + 0)   ## addr(_?1STRINGVAR.6)(P32)
;;								## 2
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 22, line 164, 0(I32), t91
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 22, line 164,  t142(I1),  t91,  0(SI32)
;;								## 3
	c0    brf $b0.0, L26?3   ## bblock 22, line 164,  t142(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.8   ## bblock 27, line 164, 0(I32), t93
;;								## 5
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 27, line 164, t94(SI8), t92
	      xnop 1
;;								## 7
	c0    zxtb $r0.4 = $r0.4   ## bblock 27, line 164,  t89(I8),  t94(SI8)
	c0    stw ((fsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 24, line 168, 0(I32), 100000(SI32)
;;								## 8
L27?3:
	c0    and $r0.6 = $r0.4, 128   ## bblock 24, line 165,  t97,  t89(I8),  128(I32)
	c0    and $r0.2 = $r0.4, 31   ## bblock 24, line 166,  t102,  t89(I8),  31(I32)
;;								## 9
	c0    stw ((block_compress + 0) + 0)[$r0.0] = $r0.6   ## bblock 24, line 165, 0(I32), t97
	c0    shl $r0.5 = $r0.5, $r0.2   ## bblock 24, line 167,  t101,  1(SI32),  t102
	c0    cmpgt $b0.0 = $r0.2, 12   ## bblock 24, line 169,  t143(I1),  t102,  12(SI32)
;;								## 10
	c0    stw ((maxbits + 0) + 0)[$r0.0] = $r0.2   ## bblock 24, line 166, 0(I32), t102
	c0    stw ((maxmaxcode + 0) + 0)[$r0.0] = $r0.5   ## bblock 24, line 167, 0(I32), t101
;;								## 11
	c0    brf $b0.0, L19?3   ## bblock 24, line 169,  t143(I1)
;;								## 12
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 25, line 172,  raddr(puts)(P32),  addr(_?1STRINGVAR.6)(P32)
;;								## 13
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t107
	      xnop 1
;;								## 15
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 26, line 173,  t108,  ?2.4?2auto_size(I32),  t107
;;								## 16
.trace 22
L19?3:
.call decompress, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = decompress   ## bblock 14, line 176,  raddr(decompress)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t107
	c0    ldw $r0.7 = 0x24[$r0.1]  ## restore ## t123
	      xnop 1
;;								## 2
.return ret($r0.3:s32)
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.7   ## bblock 15, line 177, 0(I32), t123
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 15, line 178,  t108,  ?2.4?2auto_size(I32),  t107
;;								## 3
.trace 33
L26?3:
	c0    mov $r0.4 = -1   ## bblock 23, line 164,  t89(I8),  -1(SI32)
	c0    mov $r0.5 = 1   ## 1(SI32)
	c0    mov $r0.6 = 100000   ## 100000(SI32)
;;								## 0
	c0    stw ((fsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 24, line 168, 0(I32), 100000(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.6 + 0)   ## addr(_?1STRINGVAR.6)(P32)
	      ## goto
;;
	c0    goto L27?3 ## goto
;;								## 1
.trace 31
L23?3:
	c0    mov $r0.4 = -1   ## bblock 20, line 159,  t77(I8),  -1(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
	c0    goto L24?3 ## goto
;;								## 0
.trace 26
L20?3:
	c0    mov $r0.10 = -1   ## bblock 17, line 158,  t67(I8),  -1(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
;;								## 0
	c0    cmpne $b0.0 = $r0.10, $r0.6   ## bblock 18, line 158,  t139(I1),  t67(I8),  t76
;;								## 1
	c0    brf $b0.0, L21?3   ## bblock 18, line 158,  t139(I1)
	      ## goto
;;
	c0    goto L22?3 ## goto
;;								## 2
.trace 25
L17?3:
	c0    ldw $r0.2 = ((fsize + 0) + 0)[$r0.0]   ## bblock 8, line 143, t56, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 8192   ## bblock 8, line 143,  t133(I1),  t56,  8192(SI32)
;;								## 2
	c0    brf $b0.0, L28?3   ## bblock 8, line 143,  t133(I1)
;;								## 3
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 35, line 144, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 4
	c0    goto L18?3 ## goto
;;								## 5
.trace 28
L28?3:
	c0    ldw $r0.2 = ((fsize + 0) + 0)[$r0.0]   ## bblock 9, line 145, t57, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 16384   ## bblock 9, line 145,  t134(I1),  t57,  16384(SI32)
;;								## 2
	c0    brf $b0.0, L29?3   ## bblock 9, line 145,  t134(I1)
;;								## 3
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 34, line 146, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 4
	c0    goto L18?3 ## goto
;;								## 5
.trace 32
L29?3:
	c0    ldw $r0.2 = ((fsize + 0) + 0)[$r0.0]   ## bblock 10, line 147, t58, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 32768   ## bblock 10, line 147,  t135(I1),  t58,  32768(SI32)
;;								## 2
	c0    brf $b0.0, L30?3   ## bblock 10, line 147,  t135(I1)
;;								## 3
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 33, line 148, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 4
	c0    goto L18?3 ## goto
;;								## 5
.trace 34
L30?3:
	c0    ldw $r0.2 = ((fsize + 0) + 0)[$r0.0]   ## bblock 11, line 149, t59, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 47000   ## bblock 11, line 149,  t136(I1),  t59,  47000(SI32)
;;								## 2
	c0    brf $b0.0, L31?3   ## bblock 11, line 149,  t136(I1)
;;								## 3
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 32, line 150, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 4
	c0    goto L18?3 ## goto
;;								## 5
.trace 36
L31?3:
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 0
	c0    goto L18?3 ## goto
;;								## 1
.trace 23
L15?3:
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
;;								## 0
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 7, line 140, 0(I32), 5003(SI32)
	c0    goto L16?3 ## goto
;;								## 1
.trace 24
L13?3:
	c0    cmplt $b0.0 = $r0.8, 4096   ## [spec] bblock 7, line 141,  t132(I1),  t55,  4096(SI32)
	c0    mov $r0.5 = 12   ## 12(SI32)
	c0    mov $r0.3 = 1   ## 1(SI32)
	      ## goto
;;
	c0    goto L14?3 ## goto
;;								## 0
.endp
.section .bss
.section .data
_?1STRINGPACKET.4:
    .data1 85
    .data1 110
    .data1 107
    .data1 110
    .data1 111
    .data1 119
    .data1 110
    .data1 32
    .data1 102
    .data1 108
    .data1 97
    .data1 103
    .data1 0
.skip 3
_?1.Compress.TAGPACKET.0:
    .data4 (_?1.Compress.TAG.0.0)
    .data4 (_?1.Compress.TAG.0.DEFAULT):18
    .data4 (_?1.Compress.TAG.0.1)
    .data4 (_?1.Compress.TAG.0.DEFAULT):11
    .data4 (_?1.Compress.TAG.0.2)
    .data4 (_?1.Compress.TAG.0.3)
    .data4 (_?1.Compress.TAG.0.4)
    .data4 (_?1.Compress.TAG.0.DEFAULT):9
    .data4 (_?1.Compress.TAG.0.5)
    .data4 (_?1.Compress.TAG.0.DEFAULT):2
    .data4 (_?1.Compress.TAG.0.6)
    .data4 (_?1.Compress.TAG.0.DEFAULT):4
    .data4 (_?1.Compress.TAG.0.7)
_?1STRINGPACKET.5:
    .data1 68
    .data1 97
    .data1 116
    .data1 97
    .data1 32
    .data1 110
    .data1 111
    .data1 116
    .data1 32
    .data1 105
    .data1 110
    .data1 32
    .data1 99
    .data1 111
    .data1 109
    .data1 112
    .data1 114
    .data1 101
    .data1 115
    .data1 115
    .data1 101
    .data1 100
    .data1 32
    .data1 102
    .data1 111
    .data1 114
    .data1 109
    .data1 97
    .data1 116
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.6:
    .data1 115
    .data1 116
    .data1 100
    .data1 105
    .data1 110
    .data1 58
    .data1 32
    .data1 99
    .data1 111
    .data1 109
    .data1 112
    .data1 114
    .data1 101
    .data1 115
    .data1 115
    .data1 101
    .data1 100
    .data1 32
    .data1 119
    .data1 105
    .data1 116
    .data1 104
    .data1 32
    .data1 116
    .data1 111
    .data1 111
    .data1 32
    .data1 109
    .data1 97
    .data1 110
    .data1 121
    .data1 32
    .data1 98
    .data1 105
    .data1 116
    .data1 115
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.3:
    .data1 77
    .data1 105
    .data1 115
    .data1 115
    .data1 105
    .data1 110
    .data1 103
    .data1 32
    .data1 109
    .data1 97
    .data1 120
    .data1 98
    .data1 105
    .data1 116
    .data1 115
    .data1 10
    .data1 0
.equ ?2.4?2scratch.0, 0x0
.equ ?2.4?2ras_p, 0x10
.equ ?2.4?2spill_p, 0x14
.section .data
.section .text
.equ ?2.4?2auto_size, 0x40
 ## End Compress
 ## Begin compressf
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg()
compressf::
.trace 20
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    ldw $r0.5 = ((nomagic + 0) + 0)[$r0.0]   ## bblock 0, line 191, t7, 0(I32)
;;								## 0
	c0    mov $r0.8 = 9   ## 9(SI32)
	c0    mov $r0.7 = 1   ## 1(SI32)
	c0    mov $r0.6 = 3   ## 3(SI32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t98
;;								## 1
	c0    cmpeq $b0.0 = $r0.5, $r0.0   ## bblock 0, line 191,  t164(I1),  t7,  0(SI32)
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 3, line 207,  t6,  0(SI32)
	c0    mov $r0.9 = 10000   ## 10000(SI32)
;;								## 2
	c0    mov $r0.5 = 511   ## 511(SI32)
	c0    br $b0.0, L32?3   ## bblock 0, line 191,  t164(I1)
;;								## 3
L33?3:
	c0    ldw $r0.10 = ((block_compress + 0) + 0)[$r0.0]   ## bblock 1, line 205, t26, 0(I32)
	c0    mov $r0.11 = 257   ## 257(SI32)
;;								## 4
	c0    ldw $r0.12 = ((buflen + 0) + 0)[$r0.0]   ## bblock 1, line 206, t29, 0(I32)
	c0    ldw.d $r0.13 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 33, line 206, t31, 0(I32)
;;								## 5
	c0    cmpne $b0.0 = $r0.10, $r0.0   ## bblock 1, line 205,  t165(I1),  t26,  0(SI32)
	c0    ldw.d $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## [spec] bblock 3, line 208, t0, 0(I32)
;;								## 6
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.5   ## bblock 1, line 204, 0(I32), 511(SI32)
	c0    slct $r0.11 = $b0.0, $r0.11, 256   ## bblock 1, line 205,  t27,  t165(I1),  257(SI32),  256(SI32)
;;								## 7
	c0    add $r0.12 = $r0.12, -1   ## bblock 1, line 206,  t30,  t29,  -1(SI32)
	c0    add $r0.5 = $r0.13, 1   ## [spec] bblock 33, line 206,  t32,  t31,  1(SI32)
	c0    mov $r0.3 = 65536   ## 65536(SI32)
;;								## 8
	c0    stw ((compress_3906.offset + 0) + 0)[$r0.0] = $r0.0   ## bblock 1, line 197, 0(I32), 0(SI32)
	c0    cmpge $b0.0 = $r0.12, $r0.0   ## bblock 1, line 206,  t166(I1),  t30,  0(SI32)
;;								## 9
	c0    stw ((bytes_out + 0) + 0)[$r0.0] = $r0.6   ## bblock 1, line 198, 0(I32), 3(SI32)
	c0    stw ((out_count + 0) + 0)[$r0.0] = $r0.0   ## bblock 1, line 199, 0(I32), 0(SI32)
;;								## 10
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.0   ## bblock 1, line 200, 0(I32), 0(SI32)
	c0    stw ((ratio + 0) + 0)[$r0.0] = $r0.0   ## bblock 1, line 201, 0(I32), 0(SI32)
;;								## 11
	c0    stw ((in_count + 0) + 0)[$r0.0] = $r0.7   ## bblock 1, line 202, 0(I32), 1(SI32)
	c0    stw ((checkpoint + 0) + 0)[$r0.0] = $r0.9   ## bblock 1, line 203, 0(I32), 10000(SI32)
;;								## 12
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.8   ## bblock 1, line 204, 0(I32), 9(SI32)
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.11   ## bblock 1, line 205, 0(I32), t27
;;								## 13
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.12   ## bblock 1, line 206, 0(I32), t30
	c0    brf $b0.0, L34?3   ## bblock 1, line 206,  t166(I1)
;;								## 14
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.5   ## bblock 33, line 206, 0(I32), t32
;;								## 15
	c0    ldb $r0.13 = 0[$r0.13]   ## bblock 33, line 206, t33(SI8), t31
	c0    mov $r0.5 = $l0.0   ## t98
	      xnop 1
;;								## 17
	c0    zxtb $r0.13 = $r0.13   ## bblock 33, line 206,  t28(I8),  t33(SI8)
;;								## 18
L35?3:
	c0    mov $r0.6 = $r0.13   ## bblock 3, line 206,  t3,  t28(I8)
;;								## 19
.trace 3
L36?3:
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## bblock 4, line 208,  t167(I1),  t0,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 32, line 208,  t126,  t0,  1(I32)
;;								## 0
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 32, line 208-1,  t186(I1),  t126,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 41, line 208-1,  t131,  t126,  1(I32)
	c0    brf $b0.0, L37?3   ## bblock 4, line 208,  t167(I1)
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 41, line 208-2,  t188(I1),  t131,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 38, line 208-2,  t135,  t131,  1(I32)
	c0    brf $b0.0, L38?3   ## bblock 32, line 208-1,  t186(I1)
;;								## 2
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 38, line 208-3,  t187(I1),  t135,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 28, line 208-3,  t0,  t135,  1(I32)
	c0    brf $b0.0, L39?3   ## bblock 41, line 208-2,  t188(I1)
;;								## 3
	c0    brf $b0.0, L40?3   ## bblock 38, line 208-3,  t187(I1)
;;								## 4
	c0    add $r0.4 = $r0.4, 4   ## bblock 28, line 209-3,  t6,  t6,  4(SI32)
	c0    goto L36?3 ## goto
;;								## 5
.trace 29
L40?3:
	c0    add $r0.4 = $r0.4, 3   ## bblock 29, line 0,  t129,  t6,  3(I32)
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    goto L41?3 ## goto
;;								## 0
.trace 4
L42?3:
	c0    ldw $r0.3 = ((buflen + 0) + 0)[$r0.0]   ## bblock 6, line 213, t42, 0(I32)
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 31, line 213, t44, 0(I32)
;;								## 0
	c0    ldw.d $r0.9 = ((in_count + 0) + 0)[$r0.0]   ## [spec] bblock 16, line 215, t48, 0(I32)
	c0    ldw.d $r0.10 = ((maxbits + 0) + 0)[$r0.0]   ## [spec] bblock 16, line 216, t50, 0(I32)
;;								## 1
	c0    add $r0.3 = $r0.3, -1   ## bblock 6, line 213,  t43,  t42,  -1(SI32)
	c0    add $r0.11 = $r0.6, 1   ## [spec] bblock 31, line 213,  t45,  t44,  1(SI32)
;;								## 2
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.3   ## bblock 6, line 213, 0(I32), t43
	c0    cmpge $b0.0 = $r0.3, $r0.0   ## bblock 6, line 213,  t168(I1),  t43,  0(SI32)
	c0    add $r0.9 = $r0.9, 1   ## [spec] bblock 16, line 215,  t49,  t48,  1(SI32)
;;								## 3
	c0    brf $b0.0, L43?3   ## bblock 6, line 213,  t168(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.11   ## bblock 31, line 213, 0(I32), t45
;;								## 5
	c0    ldb $r0.6 = 0[$r0.6]   ## bblock 31, line 213, t46(SI8), t44
	      xnop 1
;;								## 7
	c0    zxtb $r0.6 = $r0.6   ## bblock 31, line 213,  t41(I8),  t46(SI8)
;;								## 8
L44?3:
	c0    cmpne $b0.0 = $r0.6, -1   ## bblock 8, line 213,  t169(I1),  t41(I8),  -1(SI32)
	c0    shl $r0.10 = $r0.6, $r0.10   ## [spec] bblock 16, line 216,  t51,  t41(I8),  t50
	c0    shl $r0.3 = $r0.6, $r0.7   ## [spec] bblock 16, line 217,  t53,  t41(I8),  t113
;;								## 9
	c0    add $r0.5 = $r0.10, $r0.8   ## [spec] bblock 16, line 216,  t114,  t51,  t3
	c0    xor $r0.2 = $r0.8, $r0.3   ## [spec] bblock 16, line 217,  t1,  t3,  t53
	c0    brf $b0.0, L45?3   ## bblock 8, line 213,  t169(I1)
;;								## 10
	c0    sh2add $r0.3 = $r0.2, (htab + 0)   ## bblock 16, line 218,  t172,  t1,  addr(htab?1.0)(P32)
	c0    sh1add $r0.10 = $r0.2, (codetab + 0)   ## [spec] bblock 30, line 220,  t185,  t1,  addr(codetab?1.0)(P32)
;;								## 11
	c0    stw ((in_count + 0) + 0)[$r0.0] = $r0.9   ## bblock 16, line 215, 0(I32), t49
	c0    ldw $r0.3 = 0[$r0.3]   ## bblock 16, line 218, t56, t172
	      xnop 1
;;								## 13
	c0    cmpeq $b0.0 = $r0.3, $r0.5   ## bblock 16, line 218,  t173(I1),  t56,  t114
;;								## 14
	c0    brf $b0.0, L46?3   ## bblock 16, line 218,  t173(I1)
;;								## 15
	c0    ldhu $r0.8 = 0[$r0.10]   ## bblock 30, line 220, t3, t185
;;								## 16
	c0    goto L42?3 ## goto
;;								## 17
.trace 8
L46?3:
	c0    sh2add $r0.9 = $r0.2, (htab + 0)   ## bblock 17, line 223,  t174,  t1,  addr(htab?1.0)(P32)
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    stw 0x18[$r0.1] = $r0.7  ## spill ## t113
;;								## 0
	c0    stw 0x1c[$r0.1] = $r0.6  ## spill ## t41(I8)
	c0    mov $r0.3 = $r0.8   ## t3
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
;;								## 1
	c0    ldw $r0.9 = 0[$r0.9]   ## bblock 17, line 223, t60, t174
	      xnop 1
;;								## 3
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 17, line 223,  t175(I1),  t60,  0(SI32)
;;								## 4
	c0    brf $b0.0, L47?3   ## bblock 17, line 223,  t175(I1)
;;								## 5
L48?3:
.call output, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = output   ## bblock 22, line 243,  raddr(output)(P32),  t3
;;								## 6
	c0    ldw $r0.3 = ((out_count + 0) + 0)[$r0.0]   ## bblock 23, line 244, t70, 0(I32)
	c0    ldw $r0.6 = 0x1c[$r0.1]  ## restore ## t41(I8)
;;								## 7
	c0    ldw $r0.9 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 23, line 246, t72, 0(I32)
	c0    ldw $r0.10 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 23, line 246, t73, 0(I32)
;;								## 8
	c0    add $r0.3 = $r0.3, 1   ## bblock 23, line 244,  t71,  t70,  1(SI32)
	c0    mov $r0.8 = $r0.6   ## bblock 23, line 245,  t3,  t41(I8)
	c0    ldw $r0.5 = 0x14[$r0.1]  ## restore ## t114
	c0    ldw $r0.2 = 0x20[$r0.1]  ## restore ## t1
;;								## 9
	c0    cmplt $b0.0 = $r0.9, $r0.10   ## bblock 23, line 246,  t180(I1),  t72,  t73
	c0    add $r0.11 = $r0.9, 1   ## [spec] bblock 26, line 248,  t75,  t72,  1(SI32)
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t113
;;								## 10
	c0    sh1add $r0.10 = $r0.2, (codetab + 0)   ## [spec] bblock 26, line 248,  t182,  t1,  addr(codetab?1.0)(P32)
	c0    sh2add $r0.12 = $r0.2, (htab + 0)   ## [spec] bblock 26, line 249,  t183,  t1,  addr(htab?1.0)(P32)
;;								## 11
	c0    stw ((out_count + 0) + 0)[$r0.0] = $r0.3   ## bblock 23, line 244, 0(I32), t71
	c0    brf $b0.0, L49?3   ## bblock 23, line 246,  t180(I1)
;;								## 12
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.11   ## bblock 26, line 248, 0(I32), t75
	c0    sth 0[$r0.10] = $r0.9   ## bblock 26, line 248, t182, t72
;;								## 13
	c0    stw 0[$r0.12] = $r0.5   ## bblock 26, line 249, t183, t114
	c0    goto L42?3 ## goto
;;								## 14
.trace 10
L49?3:
	c0    stw 0x18[$r0.1] = $r0.7  ## spill ## t113
	c0    stw 0x24[$r0.1] = $r0.8  ## spill ## t3
;;								## 0
	c0    ldw $r0.2 = ((in_count + 0) + 0)[$r0.0]   ## bblock 24, line 251, t79, 0(I32)
	c0    ldw $r0.3 = ((checkpoint + 0) + 0)[$r0.0]   ## bblock 24, line 251, t80, 0(I32)
;;								## 1
	c0    ldw $r0.5 = ((block_compress + 0) + 0)[$r0.0]   ## bblock 24, line 251, t82, 0(I32)
;;								## 2
	c0    cmpge $r0.2 = $r0.2, $r0.3   ## bblock 24, line 251,  t81,  t79,  t80
;;								## 3
	c0    andl $b0.0 = $r0.2, $r0.5   ## bblock 24, line 251,  t181(I1),  t81,  t82
;;								## 4
	c0    brf $b0.0, L50?3   ## bblock 24, line 251,  t181(I1)
;;								## 5
.call cl_block, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = cl_block   ## bblock 25, line 253,  raddr(cl_block)(P32)
;;								## 6
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t113
	c0    ldw $r0.8 = 0x24[$r0.1]  ## restore ## t3
;;								## 7
	c0    goto L42?3 ## goto
;;								## 8
.trace 12
L50?3:
	c0    ldw $r0.8 = 0x24[$r0.1]  ## restore ## t3
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t113
;;								## 0
	c0    goto L42?3 ## goto
;;								## 1
.trace 9
L47?3:
	c0    ldw $r0.5 = 0x14[$r0.1]  ## restore ## t114
	c0    mov $r0.11 = $r0.8   ## t3
	c0    ldw $r0.2 = 0x20[$r0.1]  ## restore ## t1
	c0    mov $r0.4 = $r0.57   ## t5
	      xnop 1
;;								## 1
	c0    sub $r0.57 = $r0.57, $r0.2   ## bblock 18, line 227,  t121,  t5,  t1
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 18, line 229,  t176(I1),  t1,  0(I32)
;;								## 2
	c0    slct $r0.3 = $b0.0, $r0.57, 1   ## bblock 18, line 229,  t4,  t176(I1),  t121,  1(SI32)
;;								## 3
.trace 1
L51?3:
	c0    sub $r0.2 = $r0.2, $r0.3   ## bblock 19, line 231,  t136,  t1,  t4
;;								## 0
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 19, line 231,  t137(I1),  t136,  0(SI32)
	c0    add $r0.6 = $r0.2, $r0.4   ## bblock 19, line 232,  t138,  t136,  t5
;;								## 1
	c0    slct $r0.2 = $b0.0, $r0.2, $r0.6   ## bblock 19, line 232,  t134,  t137(I1),  t136,  t138
;;								## 2
	c0    sh2add $r0.6 = $r0.2, (htab + 0)   ## bblock 19, line 233,  t177,  t134,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.2, $r0.3   ## [spec] bblock 52, line 231-1,  t143,  t134,  t4
;;								## 3
	c0    ldw $r0.6 = 0[$r0.6]   ## bblock 19, line 233, t132, t177
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 52, line 231-1,  t144(I1),  t143,  0(SI32)
	c0    add $r0.8 = $r0.4, $r0.7   ## [spec] bblock 52, line 232-1,  t145,  t5,  t143
;;								## 4
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.8   ## [spec] bblock 52, line 232-1,  t146,  t144(I1),  t143,  t145
;;								## 5
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 19, line 233,  t178(I1),  t132,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 21, line 238,  t179(I1),  t132,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 52, line 233-1,  t195,  t146,  addr(htab?1.0)(P32)
;;								## 6
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 52, line 233-1, t147, t195
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 48, line 231-2,  t123,  t146,  t4
	c0    br $b0.0, L52?3   ## bblock 19, line 233,  t178(I1)
;;								## 7
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 48, line 231-2,  t139(I1),  t123,  0(SI32)
	c0    add $r0.9 = $r0.4, $r0.8   ## [spec] bblock 48, line 232-2,  t140,  t5,  t123
	c0    brf $b0.1, L53?3   ## bblock 21, line 238,  t179(I1)
;;								## 8
	c0    cmpeq $b0.1 = $r0.6, $r0.5   ## bblock 52, line 233-1,  t196(I1),  t147,  t114
	c0    cmpgt $b0.2 = $r0.6, $r0.0   ## [spec] bblock 53, line 238-1,  t197(I1),  t147,  0(SI32)
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.9   ## [spec] bblock 48, line 232-2,  t141,  t139(I1),  t123,  t140
;;								## 9
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 48, line 233-2,  t192,  t141,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 44, line 231-3,  t128,  t141,  t4
	c0    br $b0.1, L54?3   ## bblock 52, line 233-1,  t196(I1)
;;								## 10
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 48, line 233-2, t142, t192
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 44, line 231-3,  t117(I1),  t128,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 44, line 232-3,  t118,  t5,  t128
	c0    brf $b0.2, L55?3   ## bblock 53, line 238-1,  t197(I1)
;;								## 11
	c0    slct $r0.2 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 44, line 232-3,  t1,  t117(I1),  t128,  t118
;;								## 12
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 48, line 233-2,  t193(I1),  t142,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 49, line 238-2,  t194(I1),  t142,  0(SI32)
	c0    sh2add $r0.6 = $r0.2, (htab + 0)   ## [spec] bblock 44, line 233-3,  t189,  t1,  addr(htab?1.0)(P32)
;;								## 13
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 44, line 233-3, t65, t189
	c0    br $b0.0, L56?3   ## bblock 48, line 233-2,  t193(I1)
;;								## 14
	c0    brf $b0.1, L57?3   ## bblock 49, line 238-2,  t194(I1)
;;								## 15
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 44, line 233-3,  t190(I1),  t65,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 45, line 238-3,  t191(I1),  t65,  0(SI32)
;;								## 16
	c0    br $b0.0, L58?3   ## bblock 44, line 233-3,  t190(I1)
;;								## 17
	c0    brf $b0.1, L59?3   ## bblock 45, line 238-3,  t191(I1)
	      ## goto
;;
	c0    goto L51?3 ## goto
;;								## 18
.trace 19
L59?3:
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
	      ## goto
;;
	c0    goto L48?3 ## goto
;;								## 0
.trace 18
L58?3:
	   ## bblock 46, line 0,  t125,  t1## $r0.2(skipped)
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L60?3 ## goto
;;								## 0
.trace 17
L57?3:
	c0    mov $r0.2 = $r0.8   ## bblock 51, line 0,  t1,  t141
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L48?3 ## goto
;;								## 1
.trace 16
L56?3:
	c0    mov $r0.2 = $r0.8   ## bblock 50, line 0,  t125,  t141
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L60?3 ## goto
;;								## 0
.trace 15
L55?3:
	c0    mov $r0.2 = $r0.7   ## bblock 55, line 0,  t1,  t146
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L48?3 ## goto
;;								## 1
.trace 14
L54?3:
	c0    mov $r0.2 = $r0.7   ## bblock 54, line 0,  t125,  t146
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L60?3 ## goto
;;								## 0
.trace 13
L53?3:
	   ## bblock 57, line 0,  t1,  t134## $r0.2(skipped)
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L48?3 ## goto
;;								## 1
.trace 11
L52?3:
	   ## bblock 56, line 0,  t125,  t134## $r0.2(skipped)
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t113
;;								## 0
L60?3:
	c0    sh1add $r0.2 = $r0.2, (codetab + 0)   ## bblock 27, line 235,  t184,  t125,  addr(codetab?1.0)(P32)
;;								## 1
	c0    ldhu $r0.8 = 0[$r0.2]   ## bblock 27, line 235, t3, t184
;;								## 2
	c0    goto L42?3 ## goto
;;								## 3
.trace 21
L45?3:
.call output, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = output   ## bblock 9, line 256,  raddr(output)(P32),  t3
	c0    mov $r0.3 = $r0.8   ## t3
;;								## 0
	c0    ldw $r0.2 = ((out_count + 0) + 0)[$r0.0]   ## bblock 10, line 257, t84, 0(I32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	      xnop 1
;;								## 2
	c0    add $r0.2 = $r0.2, 1   ## bblock 10, line 257,  t85,  t84,  1(SI32)
;;								## 3
.call output, caller, arg($r0.3:s32), ret()
	c0    stw ((out_count + 0) + 0)[$r0.0] = $r0.2   ## bblock 10, line 257, 0(I32), t85
	c0    call $l0.0 = output   ## bblock 10, line 258,  raddr(output)(P32),  -1(SI32)
;;								## 4
	c0    ldw $r0.2 = ((zcat_flg + 0) + 0)[$r0.0]   ## bblock 11, line 259, t86, 0(I32)
	c0    ldw $r0.4 = ((quiet + 0) + 0)[$r0.0]   ## bblock 11, line 259, t88, 0(I32)
;;								## 5
	c0    ldw.d $r0.6 = ((bytes_out + 0) + 0)[$r0.0]   ## [spec] bblock 12, line 264, t96, 0(I32)
	c0    ldw.d $r0.7 = ((in_count + 0) + 0)[$r0.0]   ## [spec] bblock 12, line 264, t97, 0(I32)
;;								## 6
	c0    norl $b0.0 = $r0.2, $r0.4   ## bblock 11, line 259,  t170(I1),  t86,  t88
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    mov $r0.8 = 2   ## 2(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t98
;;								## 7
	c0    cmpgt $b0.0 = $r0.6, $r0.7   ## [spec] bblock 12, line 264,  t171(I1),  t96,  t97
	c0    br $b0.0, L61?3   ## bblock 11, line 259,  t170(I1)
;;								## 8
L62?3:
	c0    brf $b0.0, L63?3   ## bblock 12, line 264,  t171(I1)
;;								## 9
	c0    stw ((exit_stat + 0) + 0)[$r0.0] = $r0.8   ## bblock 14, line 265, 0(I32), 2(SI32)
	c0    ldw $r0.57 = 0x28[$r0.1]  ## restore ## t102
;;								## 10
L64?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 13, line 266,  t99,  ?2.5?2auto_size(I32),  t98
;;								## 11
.trace 26
L63?3:
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $r0.57 = 0x28[$r0.1]  ## restore ## t102
	c0    goto L64?3 ## goto
;;								## 0
.trace 25
L61?3:
	c0    ldw $r0.2 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 15, line 262, t92, 0(I32)
	c0    ldw $r0.4 = ((in_count + 0) + 0)[$r0.0]   ## bblock 15, line 262, t95, 0(I32)
	      xnop 1
;;								## 1
.call prratio, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    sub $r0.3 = $r0.4, $r0.2   ## bblock 15, line 262,  t94,  t95,  t92
	c0    call $l0.0 = prratio   ## bblock 15, line 262,  raddr(prratio)(P32),  t94,  t95
;;								## 2
	c0    ldw $r0.6 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 12, line 264, t96, 0(I32)
	c0    ldw $r0.7 = ((in_count + 0) + 0)[$r0.0]   ## bblock 12, line 264, t97, 0(I32)
;;								## 3
	c0    mov $r0.8 = 2   ## 2(SI32)
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t98
;;								## 4
	c0    cmpgt $b0.0 = $r0.6, $r0.7   ## bblock 12, line 264,  t171(I1),  t96,  t97
	c0    goto L62?3 ## goto
;;								## 5
.trace 6
L43?3:
	c0    mov $r0.6 = -1   ## bblock 7, line 213,  t41(I8),  -1(SI32)
	c0    goto L44?3 ## goto
;;								## 0
.trace 28
L39?3:
	c0    add $r0.4 = $r0.4, 2   ## bblock 39, line 0,  t129,  t6,  2(I32)
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    goto L41?3 ## goto
;;								## 0
.trace 27
L38?3:
	c0    add $r0.4 = $r0.4, 1   ## bblock 42, line 0,  t129,  t6,  1(I32)
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    goto L41?3 ## goto
;;								## 0
.trace 22
L37?3:
	   ## bblock 43, line 0,  t129,  t6## $r0.4(skipped)
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
;;								## 0
L41?3:
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    sub $r0.7 = 8, $r0.4   ## bblock 5, line 210,  t113,  8(SI32),  t129
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
;;								## 1
	c0    stw 0x18[$r0.1] = $r0.7  ## spill ## t113
;;								## 2
.call cl_hash, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = cl_hash   ## bblock 5, line 212,  raddr(cl_hash)(P32),  t5
	c0    stw 0x2c[$r0.1] = $r0.2  ## spill ## t5
	c0    mov $r0.3 = $r0.2   ## t5
;;								## 3
	c0    ldw $r0.8 = 0x24[$r0.1]  ## restore ## t3
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t113
;;								## 4
	c0    ldw $r0.57 = 0x2c[$r0.1]  ## restore ## t5
;;								## 5
	c0    goto L42?3 ## goto
;;								## 6
.trace 24
L34?3:
	c0    mov $r0.13 = -1   ## bblock 2, line 206,  t28(I8),  -1(SI32)
	c0    ldw $r0.5 = 0x10[$r0.1]  ## restore ## t98
;;								## 0
	c0    goto L35?3 ## goto
;;								## 1
.trace 23
L32?3:
	c0    ldbu $r0.3 = ((magic_header + 0) + 0)[$r0.0]   ## bblock 34, line 193, t9(I8), 0(I32)
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 34, line 193, t11, 0(I32)
;;								## 0
	c0    mov $r0.6 = 3   ## 3(SI32)
	c0    mov $r0.8 = 9   ## 9(SI32)
	c0    mov $r0.7 = 1   ## 1(SI32)
;;								## 1
	c0    add $r0.10 = $r0.2, 1   ## bblock 34, line 193,  t12,  t11,  1(SI32)
;;								## 2
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 34, line 193, 0(I32), t12
;;								## 3
	c0    stb 0[$r0.2] = $r0.3   ## bblock 34, line 193, t11, t9(I8)
;;								## 4
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 34, line 194, t16, 0(I32)
	c0    ldbu $r0.3 = (((magic_header + 0) + 1) + 0)[$r0.0]   ## bblock 34, line 194, t14(I8), 0(I32)
	      xnop 1
;;								## 6
	c0    add $r0.10 = $r0.2, 1   ## bblock 34, line 194,  t17,  t16,  1(SI32)
;;								## 7
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 34, line 194, 0(I32), t17
;;								## 8
	c0    stb 0[$r0.2] = $r0.3   ## bblock 34, line 194, t16, t14(I8)
;;								## 9
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 34, line 195, t22, 0(I32)
	c0    ldw $r0.3 = ((block_compress + 0) + 0)[$r0.0]   ## bblock 34, line 195, t18, 0(I32)
;;								## 10
	c0    ldw $r0.10 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 34, line 195, t19, 0(I32)
;;								## 11
	c0    add $r0.11 = $r0.2, 1   ## bblock 34, line 195,  t23,  t22,  1(SI32)
;;								## 12
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.11   ## bblock 34, line 195, 0(I32), t23
	c0    or $r0.3 = $r0.3, $r0.10   ## bblock 34, line 195,  t20,  t18,  t19
;;								## 13
	c0    stb 0[$r0.2] = $r0.3   ## bblock 34, line 195, t22, t20
	c0    goto L33?3 ## goto
;;								## 14
.endp
.section .bss
.section .data
.equ ?2.5?2scratch.0, 0x0
.equ ?2.5?2ras_p, 0x10
.equ ?2.5?2spill_p, 0x14
.section .data
.section .text
.equ ?2.5?2auto_size, 0x40
 ## End compressf
 ## Begin output
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32)
output::
.trace 7
	      ## auto_size == 0
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 0, line 274, t1, 0(I32)
;;								## 0
	c0    ldw $r0.4 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 0, line 274, t2, 0(I32)
	c0    cmpge $b0.0 = $r0.3, $r0.0   ## bblock 0, line 277,  t225(I1),  t0,  0(SI32)
;;								## 1
	c0    shr $r0.7 = $r0.2, 3   ## [spec] bblock 7, line 279,  t8(SI29),  t1,  3(SI32)
	c0    and $r0.6 = $r0.2, 7   ## [spec] bblock 7, line 280,  t112,  t1,  7(I32)
	c0    brf $b0.0, L65?3   ## bblock 0, line 277,  t225(I1)
;;								## 2
	c0    ldbu $r0.2 = (lmask + 0)[$r0.6]   ## bblock 7, line 281, t12(I8), t112
	c0    shl $r0.8 = $r0.3, $r0.6   ## bblock 7, line 281,  t13,  t0,  t112
	c0    sub $r0.9 = 8, $r0.6   ## bblock 7, line 284,  t24,  8(SI32),  t112
;;								## 3
	c0    ldb $r0.11 = (compress_3906.buf + 0)[$r0.7]   ## bblock 7, line 281, t17(SI8), t8(SI29)
	c0    ldbu $r0.10 = (rmask + 0)[$r0.6]   ## bblock 7, line 281, t16(I8), t112
;;								## 4
	c0    add $r0.12 = $r0.7, (compress_3906.buf + 0)   ## bblock 7, line 279,  t21,  t8(SI29),  addr(compress_3906.buf?1.0)(P32)
	c0    and $r0.2 = $r0.2, $r0.8   ## bblock 7, line 281,  t14,  t12(I8),  t13
	c0    shr $r0.3 = $r0.3, $r0.9   ## bblock 7, line 284,  t224,  t0,  t24
;;								## 5
	c0    add $r0.9 = $r0.7, ((compress_3906.buf + 0) + 1)   ## bblock 7, line 282,  t3,  t8(SI29),  (addr(compress_3906.buf?1.0)(P32) + 0x1(I32))(P32)
	c0    and $r0.10 = $r0.10, $r0.11   ## bblock 7, line 281,  t18,  t16(I8),  t17(SI8)
	c0    mov $r0.8 = $r0.3   ## bblock 7, line 284,  t111(SI24),  t224
;;								## 6
	c0    or $r0.2 = $r0.2, $r0.10   ## bblock 7, line 281,  t19,  t14,  t18
	c0    add $r0.4 = $r0.4, -8   ## bblock 7, line 283,  t238,  t2,  -8(SI32)
;;								## 7
	c0    stb (compress_3906.buf + 0)[$r0.7] = $r0.2   ## bblock 7, line 281, t8(SI29), t19
	c0    add $r0.4 = $r0.4, $r0.6   ## bblock 7, line 283,  t110,  t238,  t112
;;								## 8
	c0    cmpge $b0.0 = $r0.4, 8   ## bblock 7, line 285,  t239(I1),  t110,  8(SI32)
;;								## 9
	c0    brf $b0.0, L66?3   ## bblock 7, line 285,  t239(I1)
;;								## 10
	c0    stb 1[$r0.12] = $r0.3   ## bblock 25, line 287, t21, t224
	c0    add $r0.9 = $r0.12, 2   ## bblock 25, line 287,  t3,  t21,  2(SI32)
	c0    shr $r0.8 = $r0.3, 8   ## bblock 25, line 288,  t111(SI24),  t224,  8(SI32)
	c0    add $r0.4 = $r0.4, -8   ## bblock 25, line 289,  t110,  t110,  -8(SI32)
;;								## 11
L66?3:
	c0    cmpne $b0.0 = $r0.4, $r0.0   ## bblock 8, line 291,  t240(I1),  t110,  0(SI32)
	c0    mov $r0.3 = (compress_3906.buf + 0)   ## [spec] bblock 21, line 296,  t114,  addr(compress_3906.buf?1.0)(P32)
;;								## 12
	c0    brf $b0.0, L67?3   ## bblock 8, line 291,  t240(I1)
;;								## 13
	c0    stb 0[$r0.9] = $r0.8   ## bblock 24, line 292, t3, t111(SI24)
;;								## 14
L67?3:
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 9, line 293, t32, 0(I32)
	c0    ldw $r0.4 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 9, line 293, t36, 0(I32)
;;								## 15
	c0    ldw.d $r0.6 = ((bytes_out + 0) + 0)[$r0.0]   ## [spec] bblock 21, line 298, t41, 0(I32)
;;								## 16
	c0    add $r0.2 = $r0.2, $r0.4   ## bblock 9, line 293,  t35,  t32,  t36
	c0    shl $r0.7 = $r0.4, 3   ## bblock 9, line 294,  t37,  t36,  3(SI32)
	c0    mov $r0.5 = $r0.4   ## [spec] bblock 21, line 293,  t113,  t36
;;								## 17
	c0    stw ((compress_3906.offset + 0) + 0)[$r0.0] = $r0.2   ## bblock 9, line 293, 0(I32), t35
	c0    cmpeq $b0.0 = $r0.2, $r0.7   ## bblock 9, line 294,  t241(I1),  t35,  t37
	c0    add $r0.4 = $r0.4, $r0.6   ## [spec] bblock 21, line 298,  t42,  t36,  t41
;;								## 18
	c0    brf $b0.0, L68?3   ## bblock 9, line 294,  t241(I1)
;;								## 19
	c0    stw ((bytes_out + 0) + 0)[$r0.0] = $r0.4   ## bblock 21, line 298, 0(I32), t42
;;								## 20
.trace 2
L69?3:
	c0    ldb $r0.4 = 0[$r0.3]   ## bblock 22, line 301, t43(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 22, line 301, t44, 0(I32)
	c0    cmpeq $b0.0 = $r0.5, 1   ## bblock 22, line 304,  t248(I1),  t113,  1(SI32)
;;								## 0
	c0    cmpeq $b0.1 = $r0.5, 2   ## [spec] bblock 41, line 304-1,  t259(I1),  t113,  2(SI32)
	c0    cmpeq $b0.2 = $r0.5, 3   ## [spec] bblock 39, line 304-2,  t258(I1),  t113,  3(SI32)
	c0    add $r0.5 = $r0.5, -4   ## [spec] bblock 37, line 304-3,  t113,  t113,  -4(SI32)
;;								## 1
	c0    add $r0.6 = $r0.2, 1   ## bblock 22, line 301,  t45,  t44,  1(SI32)
	c0    cmpeq $b0.3 = $r0.5, $r0.0   ## [spec] bblock 37, line 304-3,  t257(I1),  t113,  0(SI32)
;;								## 2
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.6   ## bblock 22, line 301, 0(I32), t45
;;								## 3
	c0    stb 0[$r0.2] = $r0.4   ## bblock 22, line 301, t44, t43(SI8)
	c0    br $b0.0, L70?3   ## bblock 22, line 304,  t248(I1)
;;								## 4
	c0    ldb $r0.4 = 1[$r0.3]   ## bblock 41, line 301-1, t148(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 41, line 301-1, t149, 0(I32)
	      xnop 1
;;								## 6
	c0    add $r0.6 = $r0.2, 1   ## bblock 41, line 301-1,  t150,  t149,  1(SI32)
;;								## 7
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.6   ## bblock 41, line 301-1, 0(I32), t150
;;								## 8
	c0    stb 0[$r0.2] = $r0.4   ## bblock 41, line 301-1, t149, t148(SI8)
	c0    br $b0.1, L70?3   ## bblock 41, line 304-1,  t259(I1)
;;								## 9
	c0    ldb $r0.4 = 2[$r0.3]   ## bblock 39, line 301-2, t143(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 39, line 301-2, t144, 0(I32)
	      xnop 1
;;								## 11
	c0    add $r0.6 = $r0.2, 1   ## bblock 39, line 301-2,  t145,  t144,  1(SI32)
;;								## 12
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.6   ## bblock 39, line 301-2, 0(I32), t145
;;								## 13
	c0    stb 0[$r0.2] = $r0.4   ## bblock 39, line 301-2, t144, t143(SI8)
	c0    br $b0.2, L70?3   ## bblock 39, line 304-2,  t258(I1)
;;								## 14
	c0    ldb $r0.4 = 3[$r0.3]   ## bblock 37, line 301-3, t125(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 37, line 301-3, t141, 0(I32)
	c0    add $r0.3 = $r0.3, 4   ## bblock 37, line 302-3,  t114,  t114,  4(SI32)
	      xnop 1
;;								## 16
	c0    add $r0.6 = $r0.2, 1   ## bblock 37, line 301-3,  t142,  t141,  1(SI32)
;;								## 17
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.6   ## bblock 37, line 301-3, 0(I32), t142
;;								## 18
	c0    stb 0[$r0.2] = $r0.4   ## bblock 37, line 301-3, t141, t125(SI8)
	c0    br $b0.3, L70?3   ## bblock 37, line 304-3,  t257(I1)
	      ## goto
;;
	c0    goto L69?3 ## goto
;;								## 19
.trace 15
L70?3:
	c0    stw ((compress_3906.offset + 0) + 0)[$r0.0] = $r0.0   ## bblock 23, line 305, 0(I32), 0(SI32)
;;								## 0
.trace 9
L68?3:
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 10, line 307, t49, 0(I32)
	c0    ldw $r0.4 = ((maxcode + 0) + 0)[$r0.0]   ## bblock 10, line 307, t50, 0(I32)
;;								## 0
	c0    ldw $r0.9 = ((clear_flg + 0) + 0)[$r0.0]   ## bblock 10, line 307, t52, 0(I32)
	c0    ldw.d $r0.10 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## [spec] bblock 11, line 309, t54, 0(I32)
;;								## 1
	c0    cmpgt $r0.2 = $r0.2, $r0.4   ## bblock 10, line 307,  t51,  t49,  t50
	c0    mov $r0.7 = 2   ## [spec] bblock 17, line 0,  t167,  2(I32)
	c0    mov $r0.8 = 3   ## [spec] bblock 17, line 0,  t168,  3(I32)
	c0    mov $r0.6 = 1   ## [spec] bblock 17, line 0,  t169,  1(I32)
;;								## 2
	c0    cmpgt $r0.9 = $r0.9, $r0.0   ## bblock 10, line 307,  t53,  t52,  0(SI32)
	c0    cmpgt $b0.0 = $r0.10, $r0.0   ## [spec] bblock 11, line 309,  t243(I1),  t54,  0(SI32)
	c0    mov $r0.5 = (compress_3906.buf + 0)   ## [spec] bblock 17, line 0,  t170,  addr(compress_3906.buf?1.0)(P32)
;;								## 3
	c0    orl $b0.1 = $r0.2, $r0.9   ## bblock 10, line 307,  t242(I1),  t51,  t53
	c0    mov $r0.3 = $r0.0   ## [spec] bblock 17, line 311,  t138,  0(SI32)
;;								## 4
	c0    brf $b0.1, L71?3   ## bblock 10, line 307,  t242(I1)
;;								## 5
	c0    brf $b0.0, L72?3   ## bblock 11, line 309,  t243(I1)
;;								## 6
.trace 5
L73?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 18, line 311, t56, 0(I32)
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 20, line 312, t62, 0(I32)
;;								## 0
	c0    ldb.d $r0.9 = 0[$r0.5]   ## [spec] bblock 20, line 312, t61(SI8), t170
;;								## 1
	c0    cmplt $b0.0 = $r0.3, $r0.2   ## bblock 18, line 311,  t246(I1),  t138,  t56
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 20, line 312,  t63,  t62,  1(SI32)
	c0    add $r0.3 = $r0.3, 4   ## [spec] bblock 45, line 311-3,  t138,  t138,  4(SI32)
;;								## 2
	c0    brf $b0.0, L74?3   ## bblock 18, line 311,  t246(I1)
;;								## 3
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 20, line 312, 0(I32), t63
;;								## 4
	c0    stb 0[$r0.4] = $r0.9   ## bblock 20, line 312, t62, t61(SI8)
;;								## 5
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 20, line 311-1, t162, 0(I32)
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 51, line 312-1, t164, 0(I32)
;;								## 6
	c0    ldb.d $r0.9 = 1[$r0.5]   ## [spec] bblock 51, line 312-1, t163(SI8), t170
;;								## 7
	c0    cmplt $b0.0 = $r0.6, $r0.2   ## bblock 20, line 311-1,  t247(I1),  t169,  t162
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 51, line 312-1,  t165,  t164,  1(SI32)
	c0    add $r0.6 = $r0.6, 4   ## [spec] bblock 45, line 0,  t169,  t169,  4(I32)
;;								## 8
	c0    brf $b0.0, L74?3   ## bblock 20, line 311-1,  t247(I1)
;;								## 9
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 51, line 312-1, 0(I32), t165
;;								## 10
	c0    stb 0[$r0.4] = $r0.9   ## bblock 51, line 312-1, t164, t163(SI8)
;;								## 11
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 51, line 311-2, t157, 0(I32)
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 48, line 312-2, t159, 0(I32)
;;								## 12
	c0    ldb.d $r0.9 = 2[$r0.5]   ## [spec] bblock 48, line 312-2, t158(SI8), t170
;;								## 13
	c0    cmplt $b0.0 = $r0.7, $r0.2   ## bblock 51, line 311-2,  t261(I1),  t167,  t157
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 48, line 312-2,  t160,  t159,  1(SI32)
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 45, line 0,  t167,  t167,  4(I32)
;;								## 14
	c0    brf $b0.0, L74?3   ## bblock 51, line 311-2,  t261(I1)
;;								## 15
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 48, line 312-2, 0(I32), t160
;;								## 16
	c0    stb 0[$r0.4] = $r0.9   ## bblock 48, line 312-2, t159, t158(SI8)
;;								## 17
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 48, line 311-3, t153, 0(I32)
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 45, line 312-3, t155, 0(I32)
;;								## 18
	c0    ldb.d $r0.9 = 3[$r0.5]   ## [spec] bblock 45, line 312-3, t154(SI8), t170
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 45, line 0,  t170,  t170,  4(I32)
;;								## 19
	c0    cmplt $b0.0 = $r0.8, $r0.2   ## bblock 48, line 311-3,  t260(I1),  t168,  t153
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 45, line 312-3,  t156,  t155,  1(SI32)
	c0    add $r0.8 = $r0.8, 4   ## [spec] bblock 45, line 0,  t168,  t168,  4(I32)
;;								## 20
	c0    brf $b0.0, L74?3   ## bblock 48, line 311-3,  t260(I1)
;;								## 21
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 45, line 312-3, 0(I32), t156
;;								## 22
	c0    stb 0[$r0.4] = $r0.9   ## bblock 45, line 312-3, t155, t154(SI8)
	c0    goto L73?3 ## goto
;;								## 23
.trace 17
L74?3:
	c0    ldw $r0.2 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 19, line 313, t64, 0(I32)
	c0    ldw $r0.3 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 19, line 313, t65, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, $r0.3   ## bblock 19, line 313,  t66,  t64,  t65
;;								## 2
	c0    stw ((bytes_out + 0) + 0)[$r0.0] = $r0.2   ## bblock 19, line 313, 0(I32), t66
;;								## 3
.trace 14
L72?3:
	c0    ldw $r0.2 = ((clear_flg + 0) + 0)[$r0.0]   ## bblock 12, line 316, t67, 0(I32)
	c0    mov $r0.3 = 9   ## 9(SI32)
;;								## 0
	c0    stw ((compress_3906.offset + 0) + 0)[$r0.0] = $r0.0   ## bblock 12, line 315, 0(I32), 0(SI32)
	c0    mov $r0.4 = 511   ## 511(SI32)
;;								## 1
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 12, line 316,  t244(I1),  t67,  0(SI32)
;;								## 2
	c0    brf $b0.0, L75?3   ## bblock 12, line 316,  t244(I1)
;;								## 3
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.3   ## bblock 16, line 318, 0(I32), 9(SI32)
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.4   ## bblock 16, line 318, 0(I32), 511(SI32)
;;								## 4
.return ret()
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.0   ## bblock 16, line 319, 0(I32), 0(SI32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 339,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 5
.trace 16
L75?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 13, line 323, t70, 0(I32)
	c0    ldw $r0.3 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 13, line 324, t73, 0(I32)
;;								## 0
	c0    ldw.d $r0.4 = ((maxmaxcode + 0) + 0)[$r0.0]   ## [spec] bblock 15, line 325, t74, 0(I32)
;;								## 1
	c0    add $r0.2 = $r0.2, 1   ## bblock 13, line 323,  t72,  t70,  1(SI32)
;;								## 2
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.2   ## bblock 13, line 323, 0(I32), t72
	c0    cmpeq $b0.0 = $r0.2, $r0.3   ## bblock 13, line 324,  t245(I1),  t72,  t73
;;								## 3
	c0    brf $b0.0, L76?3   ## bblock 13, line 324,  t245(I1)
;;								## 4
.return ret()
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.4   ## bblock 15, line 325, 0(I32), t74
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 339,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 5
.trace 21
L76?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 14, line 327, t75, 0(I32)
	c0    mov $r0.3 = 1   ## 1(SI32)
	      xnop 1
;;								## 1
	c0    shl $r0.3 = $r0.3, $r0.2   ## bblock 14, line 327,  t76,  1(SI32),  t75
;;								## 2
	c0    add $r0.3 = $r0.3, -1   ## bblock 14, line 327,  t77,  t76,  -1(SI32)
;;								## 3
.return ret()
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.3   ## bblock 14, line 327, 0(I32), t77
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 339,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 4
.trace 13
L71?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 339,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 0
.trace 8
L65?3:
	c0    ldw.d $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## [spec] bblock 2, line 336, t90, 0(I32)
	c0    ldw.d $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## [spec] bblock 2, line 336, t91, 0(I32)
;;								## 0
	c0    ldw $r0.4 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 1, line 333, t78, 0(I32)
;;								## 1
	c0    add $r0.2 = $r0.2, 7   ## [spec] bblock 2, line 336,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmpgt $b0.1 = $r0.4, $r0.0   ## bblock 1, line 333,  t226(I1),  t78,  0(SI32)
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## [spec] bblock 2, line 336,  t227,  t92,  0(I32)
	c0    add $r0.5 = $r0.2, 7   ## [spec] bblock 2, line 336,  t228,  t92,  7(I32)
;;								## 3
	c0    slct $r0.5 = $b0.0, $r0.5, $r0.2   ## [spec] bblock 2, line 336,  t229,  t227,  t228,  t92
	c0    br $b0.1, L77?3   ## bblock 1, line 333,  t226(I1)
;;								## 4
L78?3:
	c0    shr $r0.5 = $r0.5, 3   ## bblock 2, line 336,  t93,  t229,  3(I32)
	c0    stw ((compress_3906.offset + 0) + 0)[$r0.0] = $r0.0   ## bblock 2, line 337, 0(I32), 0(SI32)
;;								## 5
	c0    add $r0.3 = $r0.3, $r0.5   ## bblock 2, line 336,  t94,  t90,  t93
;;								## 6
.return ret()
	c0    stw ((bytes_out + 0) + 0)[$r0.0] = $r0.3   ## bblock 2, line 336, 0(I32), t94
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 339,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 7
.trace 10
L77?3:
	c0    mov $r0.7 = 2   ## bblock 4, line 0,  t207,  2(I32)
	c0    mov $r0.8 = 3   ## bblock 4, line 0,  t208,  3(I32)
	c0    mov $r0.6 = 1   ## bblock 4, line 0,  t209,  1(I32)
	c0    mov $r0.3 = $r0.0   ## bblock 4, line 334,  t122,  0(SI32)
;;								## 0
	c0    mov $r0.5 = (compress_3906.buf + 0)   ## bblock 4, line 0,  t210,  addr(compress_3906.buf?1.0)(P32)
;;								## 1
.trace 1
L79?3:
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 5, line 334, t135, 0(I32)
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 6, line 335, t137, 0(I32)
;;								## 0
	c0    ldb.d $r0.9 = 0[$r0.5]   ## [spec] bblock 6, line 335, t131(SI8), t210
;;								## 1
	c0    add $r0.2 = $r0.2, 7   ## bblock 5, line 334,  t134,  t135,  7(SI32)
	c0    add $r0.10 = $r0.4, 1   ## [spec] bblock 6, line 335,  t136,  t137,  1(SI32)
;;								## 2
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 5, line 334,  t230,  t134,  0(I32)
	c0    add $r0.11 = $r0.2, 7   ## bblock 5, line 334,  t231,  t134,  7(I32)
;;								## 3
	c0    slct $r0.11 = $b0.0, $r0.11, $r0.2   ## bblock 5, line 334,  t232,  t230,  t231,  t134
;;								## 4
	c0    shr $r0.11 = $r0.11, 3   ## bblock 5, line 334,  t133,  t232,  3(I32)
;;								## 5
	c0    cmplt $b0.0 = $r0.3, $r0.11   ## bblock 5, line 334,  t233(I1),  t122,  t133
	c0    add $r0.3 = $r0.3, 4   ## [spec] bblock 28, line 334-3,  t122,  t122,  4(SI32)
;;								## 6
	c0    brf $b0.0, L80?3   ## bblock 5, line 334,  t233(I1)
;;								## 7
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 6, line 335, 0(I32), t136
;;								## 8
	c0    stb 0[$r0.4] = $r0.9   ## bblock 6, line 335, t137, t131(SI8)
;;								## 9
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 6, line 334-1, t80, 0(I32)
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 34, line 335-1, t88, 0(I32)
;;								## 10
	c0    ldb.d $r0.9 = 1[$r0.5]   ## [spec] bblock 34, line 335-1, t87(SI8), t210
;;								## 11
	c0    add $r0.2 = $r0.2, 7   ## bblock 6, line 334-1,  t81,  t80,  7(SI32)
	c0    add $r0.10 = $r0.4, 1   ## [spec] bblock 34, line 335-1,  t89,  t88,  1(SI32)
;;								## 12
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 6, line 334-1,  t234,  t81,  0(I32)
	c0    add $r0.11 = $r0.2, 7   ## bblock 6, line 334-1,  t235,  t81,  7(I32)
;;								## 13
	c0    slct $r0.11 = $b0.0, $r0.11, $r0.2   ## bblock 6, line 334-1,  t236,  t234,  t235,  t81
;;								## 14
	c0    shr $r0.11 = $r0.11, 3   ## bblock 6, line 334-1,  t82,  t236,  3(I32)
;;								## 15
	c0    cmplt $b0.0 = $r0.6, $r0.11   ## bblock 6, line 334-1,  t237(I1),  t209,  t82
	c0    add $r0.6 = $r0.6, 4   ## [spec] bblock 28, line 0,  t209,  t209,  4(I32)
;;								## 16
	c0    brf $b0.0, L81?3   ## bblock 6, line 334-1,  t237(I1)
;;								## 17
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 34, line 335-1, 0(I32), t89
;;								## 18
	c0    stb 0[$r0.4] = $r0.9   ## bblock 34, line 335-1, t88, t87(SI8)
;;								## 19
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 34, line 334-2, t121, 0(I32)
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 31, line 335-2, t117, 0(I32)
;;								## 20
	c0    ldb.d $r0.9 = 2[$r0.5]   ## [spec] bblock 31, line 335-2, t118(SI8), t210
;;								## 21
	c0    add $r0.2 = $r0.2, 7   ## bblock 34, line 334-2,  t120,  t121,  7(SI32)
	c0    add $r0.10 = $r0.4, 1   ## [spec] bblock 31, line 335-2,  t116,  t117,  1(SI32)
;;								## 22
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 34, line 334-2,  t253,  t120,  0(I32)
	c0    add $r0.11 = $r0.2, 7   ## bblock 34, line 334-2,  t254,  t120,  7(I32)
;;								## 23
	c0    slct $r0.11 = $b0.0, $r0.11, $r0.2   ## bblock 34, line 334-2,  t255,  t253,  t254,  t120
;;								## 24
	c0    shr $r0.11 = $r0.11, 3   ## bblock 34, line 334-2,  t119,  t255,  3(I32)
;;								## 25
	c0    cmplt $b0.0 = $r0.7, $r0.11   ## bblock 34, line 334-2,  t256(I1),  t207,  t119
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 28, line 0,  t207,  t207,  4(I32)
;;								## 26
	c0    brf $b0.0, L82?3   ## bblock 34, line 334-2,  t256(I1)
;;								## 27
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 31, line 335-2, 0(I32), t116
;;								## 28
	c0    stb 0[$r0.4] = $r0.9   ## bblock 31, line 335-2, t117, t118(SI8)
;;								## 29
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 31, line 334-3, t132, 0(I32)
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 28, line 335-3, t127, 0(I32)
;;								## 30
	c0    ldb.d $r0.9 = 3[$r0.5]   ## [spec] bblock 28, line 335-3, t128(SI8), t210
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 28, line 0,  t210,  t210,  4(I32)
;;								## 31
	c0    add $r0.2 = $r0.2, 7   ## bblock 31, line 334-3,  t130,  t132,  7(SI32)
	c0    add $r0.10 = $r0.4, 1   ## [spec] bblock 28, line 335-3,  t126,  t127,  1(SI32)
;;								## 32
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 31, line 334-3,  t249,  t130,  0(I32)
	c0    add $r0.11 = $r0.2, 7   ## bblock 31, line 334-3,  t250,  t130,  7(I32)
;;								## 33
	c0    slct $r0.11 = $b0.0, $r0.11, $r0.2   ## bblock 31, line 334-3,  t251,  t249,  t250,  t130
;;								## 34
	c0    shr $r0.11 = $r0.11, 3   ## bblock 31, line 334-3,  t129,  t251,  3(I32)
;;								## 35
	c0    cmplt $b0.0 = $r0.8, $r0.11   ## bblock 31, line 334-3,  t252(I1),  t208,  t129
	c0    add $r0.8 = $r0.8, 4   ## [spec] bblock 28, line 0,  t208,  t208,  4(I32)
;;								## 36
	c0    brf $b0.0, L83?3   ## bblock 31, line 334-3,  t252(I1)
;;								## 37
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 28, line 335-3, 0(I32), t126
;;								## 38
	c0    stb 0[$r0.4] = $r0.9   ## bblock 28, line 335-3, t127, t128(SI8)
	c0    goto L79?3 ## goto
;;								## 39
.trace 24
L83?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 336, t90, 0(I32)
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 2, line 336, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, 7   ## bblock 2, line 336,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 336,  t227,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 336,  t228,  t92,  7(I32)
;;								## 3
	c0    slct $r0.5 = $b0.0, $r0.4, $r0.2   ## bblock 2, line 336,  t229,  t227,  t228,  t92
	c0    goto L78?3 ## goto
;;								## 4
.trace 22
L82?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 336, t90, 0(I32)
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 2, line 336, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, 7   ## bblock 2, line 336,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 336,  t227,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 336,  t228,  t92,  7(I32)
;;								## 3
	c0    slct $r0.5 = $b0.0, $r0.4, $r0.2   ## bblock 2, line 336,  t229,  t227,  t228,  t92
	c0    goto L78?3 ## goto
;;								## 4
.trace 20
L81?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 336, t90, 0(I32)
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 2, line 336, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, 7   ## bblock 2, line 336,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 336,  t227,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 336,  t228,  t92,  7(I32)
;;								## 3
	c0    slct $r0.5 = $b0.0, $r0.4, $r0.2   ## bblock 2, line 336,  t229,  t227,  t228,  t92
	c0    goto L78?3 ## goto
;;								## 4
.trace 18
L80?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 336, t90, 0(I32)
	c0    ldw $r0.2 = ((compress_3906.offset + 0) + 0)[$r0.0]   ## bblock 2, line 336, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, 7   ## bblock 2, line 336,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 336,  t227,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 336,  t228,  t92,  7(I32)
;;								## 3
	c0    slct $r0.5 = $b0.0, $r0.4, $r0.2   ## bblock 2, line 336,  t229,  t227,  t228,  t92
	c0    goto L78?3 ## goto
;;								## 4
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.6?2auto_size, 0x0
 ## End output
.equ _?1TEMPLATEPACKET.7, 0x0
 ## Begin decompress
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
decompress::
.trace 23
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    mov $r0.7 = 252   ## bblock 0, line 0,  t173,  252(I32)
	c0    mov $r0.8 = 9   ## 9(SI32)
;;								## 0
	c0    mov $r0.6 = 253   ## bblock 0, line 0,  t175,  253(I32)
	c0    mov $r0.9 = 511   ## 511(SI32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t66
;;								## 1
	c0    mov $r0.2 = 255   ## bblock 0, line 346,  t2,  255(SI32)
	c0    mov $r0.4 = ((htab + 0) + 252)   ## bblock 0, line 0,  t172,  (addr(htab?1.0)(P32) + 0xfc(I32))(P32)
	c0    mov $r0.5 = 254   ## bblock 0, line 0,  t177,  254(I32)
;;								## 2
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.8   ## bblock 0, line 345, 0(I32), 9(SI32)
	c0    mov $r0.3 = ((codetab + 0) + 504)   ## bblock 0, line 0,  t179,  (addr(codetab?1.0)(P32) + 0x1f8(I32))(P32)
;;								## 3
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.9   ## bblock 0, line 345, 0(I32), 511(SI32)
;;								## 4
.trace 7
L84?3:
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 1, line 346,  t210(I1),  t2,  0(SI32)
;;								## 0
	c0    brf $b0.0, L85?3   ## bblock 1, line 346,  t210(I1)
;;								## 1
	c0    sth 6[$r0.3] = $r0.0   ## bblock 24, line 348, t179, 0(I32)
	c0    stb 3[$r0.4] = $r0.2   ## bblock 24, line 349, t172, t2
	c0    add $r0.2 = $r0.2, -4   ## bblock 24, line 346-3,  t2,  t2,  -4(SI32)
;;								## 2
	c0    sth 4[$r0.3] = $r0.0   ## bblock 24, line 348-1, t179, 0(I32)
	c0    stb 2[$r0.4] = $r0.5   ## bblock 24, line 349-1, t172, t177
	c0    add $r0.5 = $r0.5, (~0x3)   ## bblock 24, line 0,  t177,  t177,  (~0x3)(I32)
;;								## 3
	c0    sth 2[$r0.3] = $r0.0   ## bblock 24, line 348-2, t179, 0(I32)
	c0    stb 1[$r0.4] = $r0.6   ## bblock 24, line 349-2, t172, t175
	c0    add $r0.6 = $r0.6, (~0x3)   ## bblock 24, line 0,  t175,  t175,  (~0x3)(I32)
;;								## 4
	c0    sth 0[$r0.3] = $r0.0   ## bblock 24, line 348-3, t179, 0(I32)
	c0    stb 0[$r0.4] = $r0.7   ## bblock 24, line 349-3, t172, t173
	c0    add $r0.3 = $r0.3, (~0x7)   ## bblock 24, line 0,  t179,  t179,  (~0x7)(I32)
	c0    add $r0.4 = $r0.4, (~0x3)   ## bblock 24, line 0,  t172,  t172,  (~0x3)(I32)
;;								## 5
	c0    add $r0.7 = $r0.7, (~0x3)   ## bblock 24, line 0,  t173,  t173,  (~0x3)(I32)
	c0    goto L84?3 ## goto
;;								## 6
.trace 22
L85?3:
	c0    ldw $r0.4 = ((block_compress + 0) + 0)[$r0.0]   ## bblock 2, line 351, t14, 0(I32)
	c0    mov $r0.5 = 257   ## 257(SI32)
	      xnop 1
;;								## 1
	c0    cmpne $b0.0 = $r0.4, $r0.0   ## bblock 2, line 351,  t211(I1),  t14,  0(SI32)
;;								## 2
	c0    slct $r0.5 = $b0.0, $r0.5, 256   ## bblock 2, line 351,  t15,  t211(I1),  257(SI32),  256(SI32)
;;								## 3
.call compressgetcode, caller, arg(), ret($r0.3:s32)
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.5   ## bblock 2, line 351, 0(I32), t15
	c0    call $l0.0 = compressgetcode   ## bblock 2, line 352,  raddr(compressgetcode)(P32)
;;								## 4
	c0    mov $r0.4 = $r0.3   ## bblock 3, line 352,  t3,  t16
	c0    mov $r0.2 = $r0.3   ## bblock 3, line 352,  t1,  t16
	c0    cmpeq $b0.0 = $r0.3, -1   ## bblock 3, line 353,  t212(I1),  t16,  -1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t66
;;								## 5
	c0    brf $b0.0, L86?3   ## bblock 3, line 353,  t212(I1)
;;								## 6
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 23, line 355,  t67,  ?2.7?2auto_size(I32),  t66
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 7
.trace 24
L86?3:
	c0    stw 0x14[$r0.1] = $r0.57  ## spill ## t70
	c0    stw 0x18[$r0.1] = $r0.58  ## spill ## t71
;;								## 0
	c0    ldw $r0.5 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 4, line 357, t18, 0(I32)
	c0    stw 0x1c[$r0.1] = $r0.59  ## spill ## t72
	c0    mov $r0.58 = $r0.2   ## t1
;;								## 1
	c0    mov $r0.57 = ((htab + 0) + 4096)   ## bblock 4, line 358,  t0,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    mov $r0.59 = $r0.4   ## t3
;;								## 2
	c0    add $r0.2 = $r0.5, 1   ## bblock 4, line 357,  t19,  t18,  1(SI32)
;;								## 3
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 4, line 357, 0(I32), t19
;;								## 4
	c0    stb 0[$r0.5] = $r0.3   ## bblock 4, line 357, t18, t16
;;								## 5
.trace 9
L87?3:
.call compressgetcode, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = compressgetcode   ## bblock 5, line 359,  raddr(compressgetcode)(P32)
;;								## 0
	c0    mov $r0.4 = $r0.3   ## bblock 6, line 359,  t78,  t23
	c0    cmpgt $b0.0 = $r0.3, -1   ## bblock 6, line 359,  t213(I1),  t23,  -1(SI32)
	c0    ldw.d $r0.6 = ((block_compress + 0) + 0)[$r0.0]   ## [spec] bblock 8, line 361, t25, 0(I32)
;;								## 1
	c0    cmpeq $r0.3 = $r0.3, 256   ## [spec] bblock 8, line 361,  t24,  t23,  256(SI32)
	c0    mov $r0.2 = 255   ## [spec] bblock 18, line 363,  t79,  255(SI32)
	c0    brf $b0.0, L88?3   ## bblock 6, line 359,  t213(I1)
;;								## 2
	c0    andl $b0.0 = $r0.3, $r0.6   ## bblock 8, line 361,  t214(I1),  t24,  t25
	c0    mov $r0.3 = ((codetab + 0) + 504)   ## [spec] bblock 18, line 0,  t157,  (addr(codetab?1.0)(P32) + 0x1f8(I32))(P32)
;;								## 3
	c0    brf $b0.0, L89?3   ## bblock 8, line 361,  t214(I1)
;;								## 4
.trace 5
L90?3:
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 19, line 363,  t222(I1),  t79,  0(SI32)
	c0    add $r0.2 = $r0.2, -4   ## [spec] bblock 22, line 363-3,  t79,  t79,  -4(SI32)
;;								## 0
	c0    brf $b0.0, L91?3   ## bblock 19, line 363,  t222(I1)
;;								## 1
	c0    sth 6[$r0.3] = $r0.0   ## bblock 22, line 364, t157, 0(I32)
	c0    sth 4[$r0.3] = $r0.0   ## bblock 22, line 364-1, t157, 0(I32)
;;								## 2
	c0    sth 2[$r0.3] = $r0.0   ## bblock 22, line 364-2, t157, 0(I32)
	c0    sth 0[$r0.3] = $r0.0   ## bblock 22, line 364-3, t157, 0(I32)
	c0    add $r0.3 = $r0.3, (~0x7)   ## bblock 22, line 0,  t157,  t157,  (~0x7)(I32)
	c0    goto L90?3 ## goto
;;								## 3
.trace 13
L91?3:
	c0    mov $r0.3 = 256   ## 256(SI32)
	c0    mov $r0.2 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.2   ## bblock 20, line 365, 0(I32), 1(SI32)
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.3   ## bblock 20, line 366, 0(I32), 256(SI32)
;;								## 1
.call compressgetcode, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = compressgetcode   ## bblock 20, line 367,  raddr(compressgetcode)(P32)
;;								## 2
	c0    mov $r0.4 = $r0.3   ## bblock 21, line 367,  t78,  t29
	c0    cmpeq $b0.0 = $r0.3, -1   ## bblock 21, line 367,  t223(I1),  t29,  -1(SI32)
;;								## 3
	c0    br $b0.0, L88?3   ## bblock 21, line 367,  t223(I1)
;;								## 4
.trace 10
L89?3:
	c0    ldw $r0.3 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 9, line 371, t30, 0(I32)
	c0    mov $r0.8 = $r0.4   ## bblock 9, line 370,  t4,  t78
	c0    mov $r0.2 = $r0.4   ## t78
	      xnop 1
;;								## 1
	c0    cmpge $b0.0 = $r0.4, $r0.3   ## bblock 9, line 371,  t215(I1),  t78,  t30
;;								## 2
	c0    mov $r0.4 = 256   ## 256(SI32)
	c0    mov $r0.5 = $r0.57   ## t0
	c0    br $b0.0, L92?3   ## bblock 9, line 371,  t215(I1)
;;								## 3
.trace 1
L93?3:
	c0    cmpge $b0.0 = $r0.2, $r0.4   ## bblock 10, line 376,  t216(I1),  t78,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.2]   ## [spec] bblock 16, line 378, t37(I8), t78
;;								## 0
	c0    sh1add $r0.6 = $r0.2, (codetab + 0)   ## [spec] bblock 16, line 379,  t220,  t78,  addr(codetab?1.0)(P32)
	c0    brf $b0.0, L94?3   ## bblock 10, line 376,  t216(I1)
;;								## 1
	c0    stb 0[$r0.5] = $r0.3   ## bblock 16, line 378, t0, t37(I8)
;;								## 2
	c0    ldhu $r0.6 = 0[$r0.6]   ## bblock 16, line 379, t90, t220
	      xnop 1
;;								## 4
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 16, line 376-1,  t221(I1),  t90,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 55, line 378-1, t106(I8), t90
;;								## 5
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 55, line 379-1,  t227,  t90,  addr(codetab?1.0)(P32)
	c0    brf $b0.0, L95?3   ## bblock 16, line 376-1,  t221(I1)
;;								## 6
	c0    stb 1[$r0.5] = $r0.3   ## bblock 55, line 378-1, t0, t106(I8)
;;								## 7
	c0    ldhu $r0.7 = 0[$r0.7]   ## bblock 55, line 379-1, t107, t227
	      xnop 1
;;								## 9
	c0    cmpge $b0.0 = $r0.7, $r0.4   ## bblock 55, line 376-2,  t228(I1),  t107,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.7]   ## [spec] bblock 52, line 378-2, t102(I8), t107
;;								## 10
	c0    sh1add $r0.6 = $r0.7, (codetab + 0)   ## [spec] bblock 52, line 379-2,  t225,  t107,  addr(codetab?1.0)(P32)
	c0    brf $b0.0, L96?3   ## bblock 55, line 376-2,  t228(I1)
;;								## 11
	c0    stb 2[$r0.5] = $r0.3   ## bblock 52, line 378-2, t0, t102(I8)
;;								## 12
	c0    ldhu $r0.6 = 0[$r0.6]   ## bblock 52, line 379-2, t103, t225
	      xnop 1
;;								## 14
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 52, line 376-3,  t226(I1),  t103,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 49, line 378-3, t98(I8), t103
;;								## 15
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 49, line 379-3,  t224,  t103,  addr(codetab?1.0)(P32)
	c0    brf $b0.0, L97?3   ## bblock 52, line 376-3,  t226(I1)
;;								## 16
	c0    stb 3[$r0.5] = $r0.3   ## bblock 49, line 378-3, t0, t98(I8)
	c0    add $r0.5 = $r0.5, 4   ## bblock 49, line 378-3,  t0,  t0,  4(SI32)
;;								## 17
	c0    ldhu $r0.2 = 0[$r0.7]   ## bblock 49, line 379-3, t78, t224
;;								## 18
	c0    goto L93?3 ## goto
;;								## 19
.trace 19
L97?3:
	c0    add $r0.5 = $r0.5, 3   ## bblock 50, line 0,  t99,  t0,  3(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 50, line 0,  t100,  t103
	c0    mov $r0.12 = $r0.8   ## t4
	c0    goto L98?3 ## goto
;;								## 0
.trace 2
L99?3:
	c0    mov $r0.5 = $r0.3   ## bblock 12, line 0,  t94,  t129
	c0    ldbu $r0.4 = 0[$r0.3]   ## bblock 12, line 385, t50(I8), t129
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 12, line 385, t52, 0(I32)
;;								## 0
	c0    cmpleu $b0.0 = $r0.3, ((htab + 0) + 4096)   ## bblock 12, line 387,  t217(I1),  t129,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    cmpleu $b0.1 = $r0.6, ((htab + 0) + 4096)   ## [spec] bblock 62, line 387-1,  t231(I1),  t126,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
;;								## 1
	c0    add $r0.10 = $r0.2, 1   ## bblock 12, line 385,  t53,  t52,  1(SI32)
	c0    cmpleu $b0.2 = $r0.7, ((htab + 0) + 4096)   ## [spec] bblock 60, line 387-2,  t230(I1),  t127,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.3 = $r0.3, (~0x3)   ## [spec] bblock 58, line 0,  t129,  t129,  (~0x3)(I32)
;;								## 2
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 12, line 385, 0(I32), t53
	c0    mov $r0.11 = $r0.8   ## [spec] bblock 58, line 0,  t209,  t128
;;								## 3
	c0    stb 0[$r0.2] = $r0.4   ## bblock 12, line 385, t52, t50(I8)
	c0    cmpleu $b0.3 = $r0.11, ((htab + 0) + 4096)   ## [spec] bblock 58, line 387-3,  t229(I1),  t209,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    br $b0.0, L100?3   ## bblock 12, line 387,  t217(I1)
;;								## 4
	c0    ldbu $r0.4 = 0[$r0.6]   ## bblock 62, line 385-1, t121(I8), t126
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 62, line 385-1, t123, 0(I32)
	c0    add $r0.6 = $r0.6, (~0x3)   ## [spec] bblock 58, line 0,  t126,  t126,  (~0x3)(I32)
	      xnop 1
;;								## 6
	c0    add $r0.10 = $r0.2, 1   ## bblock 62, line 385-1,  t124,  t123,  1(SI32)
;;								## 7
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 62, line 385-1, 0(I32), t124
;;								## 8
	c0    stb 0[$r0.2] = $r0.4   ## bblock 62, line 385-1, t123, t121(I8)
	c0    br $b0.1, L101?3   ## bblock 62, line 387-1,  t231(I1)
;;								## 9
	c0    ldbu $r0.4 = 0[$r0.7]   ## bblock 60, line 385-2, t115(I8), t127
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 60, line 385-2, t117, 0(I32)
	c0    add $r0.7 = $r0.7, (~0x3)   ## [spec] bblock 58, line 0,  t127,  t127,  (~0x3)(I32)
	      xnop 1
;;								## 11
	c0    add $r0.10 = $r0.2, 1   ## bblock 60, line 385-2,  t118,  t117,  1(SI32)
;;								## 12
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 60, line 385-2, 0(I32), t118
;;								## 13
	c0    stb 0[$r0.2] = $r0.4   ## bblock 60, line 385-2, t117, t115(I8)
	c0    br $b0.2, L102?3   ## bblock 60, line 387-2,  t230(I1)
;;								## 14
	c0    ldbu $r0.4 = 0[$r0.8]   ## bblock 58, line 385-3, t110(I8), t128
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 58, line 385-3, t112, 0(I32)
	c0    add $r0.9 = $r0.9, -4   ## bblock 58, line 384-3,  t93,  t93,  -4(SI32)
;;								## 15
	c0    add $r0.8 = $r0.8, (~0x3)   ## bblock 58, line 0,  t128,  t128,  (~0x3)(I32)
;;								## 16
	c0    add $r0.10 = $r0.2, 1   ## bblock 58, line 385-3,  t113,  t112,  1(SI32)
;;								## 17
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.10   ## bblock 58, line 385-3, 0(I32), t113
;;								## 18
	c0    stb 0[$r0.2] = $r0.4   ## bblock 58, line 385-3, t112, t110(I8)
	c0    br $b0.3, L103?3   ## bblock 58, line 387-3,  t229(I1)
	      ## goto
;;
	c0    goto L99?3 ## goto
;;								## 19
.trace 21
L103?3:
	c0    add $r0.57 = $r0.5, (~0x2)   ## bblock 59, line 0,  t0,  t94,  (~0x2)(I32)
	c0    mov $r0.58 = $r0.13   ## t1
	c0    ldw $r0.3 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 388, t80, 0(I32)
	      ## goto
;;
	c0    goto L104?3 ## goto
;;								## 0
.trace 15
L106?3:
	c0    add $r0.4 = $r0.3, 1   ## bblock 15, line 392,  t65,  t80,  1(SI32)
	c0    sh1add $r0.2 = $r0.3, (codetab + 0)   ## bblock 15, line 390,  t219,  t80,  addr(codetab?1.0)(P32)
;;								## 0
	c0    sth 0[$r0.2] = $r0.59   ## bblock 15, line 390, t219, t3
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.4   ## bblock 15, line 392, 0(I32), t65
;;								## 1
	c0    stb (htab + 0)[$r0.3] = $r0.58   ## bblock 15, line 391, t80, t1
	c0    goto L105?3 ## goto
;;								## 2
.trace 20
L102?3:
	c0    add $r0.57 = $r0.9, (~0x2)   ## bblock 61, line 0,  t0,  t93,  (~0x2)(I32)
	c0    mov $r0.58 = $r0.13   ## t1
	c0    ldw $r0.3 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 388, t80, 0(I32)
	      ## goto
;;
	c0    goto L104?3 ## goto
;;								## 0
.trace 18
L101?3:
	c0    add $r0.57 = $r0.9, (~0x1)   ## bblock 63, line 0,  t0,  t93,  (~0x1)(I32)
	c0    mov $r0.58 = $r0.13   ## t1
	c0    ldw $r0.3 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 388, t80, 0(I32)
	      ## goto
;;
	c0    goto L104?3 ## goto
;;								## 0
.trace 12
L100?3:
	c0    add $r0.57 = $r0.9, (~0x0)   ## bblock 64, line 0,  t0,  t93,  (~0x0)(I32)
	c0    ldw $r0.3 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 388, t80, 0(I32)
	c0    mov $r0.58 = $r0.13   ## t1
;;								## 0
L104?3:
	c0    ldw $r0.4 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 388, t58, 0(I32)
	      xnop 1
;;								## 2
	c0    cmplt $b0.0 = $r0.3, $r0.4   ## bblock 13, line 388,  t218(I1),  t80,  t58
;;								## 3
	c0    br $b0.0, L106?3   ## bblock 13, line 388,  t218(I1)
;;								## 4
L105?3:
	c0    mov $r0.59 = $r0.12   ## bblock 14, line 394,  t3,  t4
	c0    goto L87?3 ## goto
;;								## 5
.trace 17
L96?3:
	c0    add $r0.5 = $r0.5, 2   ## bblock 53, line 0,  t99,  t0,  2(I32)
	c0    mov $r0.2 = $r0.7   ## bblock 53, line 0,  t100,  t107
	c0    mov $r0.12 = $r0.8   ## t4
	c0    goto L98?3 ## goto
;;								## 0
.trace 16
L95?3:
	c0    add $r0.5 = $r0.5, 1   ## bblock 56, line 0,  t99,  t0,  1(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 56, line 0,  t100,  t90
	c0    mov $r0.12 = $r0.8   ## t4
	c0    goto L98?3 ## goto
;;								## 0
.trace 11
L94?3:
	   ## bblock 57, line 0,  t100,  t78## $r0.2(skipped)
	   ## bblock 57, line 0,  t99,  t0## $r0.5(skipped)
	c0    mov $r0.12 = $r0.8   ## t4
;;								## 0
L98?3:
	c0    ldbu $r0.2 = (htab + 0)[$r0.2]   ## bblock 11, line 381, t1, t100
	c0    add $r0.8 = $r0.5, (~0x2)   ## bblock 11, line 0,  t128,  t99,  (~0x2)(I32)
	c0    add $r0.7 = $r0.5, (~0x1)   ## bblock 11, line 0,  t127,  t99,  (~0x1)(I32)
;;								## 1
	c0    mov $r0.3 = $r0.5   ## bblock 11, line 0,  t129,  t99
	c0    add $r0.9 = $r0.5, 1   ## bblock 11, line 381,  t93,  t99,  1(SI32)
	c0    add $r0.6 = $r0.5, (~0x0)   ## bblock 11, line 0,  t126,  t99,  (~0x0)(I32)
;;								## 2
	c0    stb 0[$r0.5] = $r0.2   ## bblock 11, line 381, t99, t1
	c0    mov $r0.13 = $r0.2   ## t1
	c0    goto L99?3 ## goto
;;								## 3
.trace 14
L92?3:
	c0    stb 0[$r0.5] = $r0.58   ## bblock 17, line 373, t0, t1
	c0    mov $r0.2 = $r0.59   ## bblock 17, line 374,  t78,  t3
	c0    add $r0.5 = $r0.5, 1   ## bblock 17, line 373,  t0,  t0,  1(SI32)
	c0    goto L93?3 ## goto
;;								## 0
.trace 25
L88?3:
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $r0.59 = 0x1c[$r0.1]  ## restore ## t72
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t66
;;								## 0
	c0    ldw $r0.58 = 0x18[$r0.1]  ## restore ## t71
	c0    ldw $r0.57 = 0x14[$r0.1]  ## restore ## t70
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 7, line 396,  t67,  ?2.7?2auto_size(I32),  t66
;;								## 2
.endp
.section .bss
.section .data
.equ ?2.7?2scratch.0, 0x0
.equ ?2.7?2ras_p, 0x10
.equ ?2.7?2spill_p, 0x14
.section .data
.section .text
.equ ?2.7?2auto_size, 0x20
 ## End decompress
 ## Begin compressgetcode
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg()
compressgetcode::
.trace 7
	      ## auto_size == 0
	c0    ldw $r0.2 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 0, line 399, t87, 0(I32)
;;								## 0
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 0, line 399, t86, 0(I32)
	c0    ldw $r0.4 = ((clear_flg + 0) + 0)[$r0.0]   ## bblock 0, line 406, t6, 0(I32)
;;								## 1
	c0    ldw $r0.5 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 0, line 399, t85, 0(I32)
	c0    ldw $r0.6 = ((maxcode + 0) + 0)[$r0.0]   ## bblock 0, line 406, t12, 0(I32)
;;								## 2
	c0    ldw $r0.7 = ((_?1PACKET.13 + 0) + 0)[$r0.0]   ## bblock 0, line 399, t89, 0(I32)
	c0    cmpgt $r0.4 = $r0.4, $r0.0   ## bblock 0, line 406,  t7,  t6,  0(SI32)
;;								## 3
	c0    ldw $r0.9 = ((_?1PACKET.14 + 0) + 0)[$r0.0]   ## bblock 0, line 399, t88, 0(I32)
	c0    cmpgt $r0.8 = $r0.5, $r0.6   ## bblock 0, line 406,  t13,  t85,  t12
	c0    cmpgt $b0.0 = $r0.5, $r0.6   ## [spec] bblock 4, line 408,  t163(I1),  t85,  t12
;;								## 4
	c0    orl $r0.4 = $r0.4, $r0.8   ## bblock 0, line 406,  t161,  t7,  t13
	c0    ldw.d $r0.5 = ((n_bits + 0) + 0)[$r0.0]   ## [spec] bblock 17, line 410, t16, 0(I32)
;;								## 5
	c0    cmpge $r0.6 = $r0.7, $r0.9   ## bblock 0, line 406,  t10,  t89,  t88
;;								## 6
	c0    orl $b0.1 = $r0.4, $r0.6   ## bblock 0, line 406,  t162(I1),  t161,  t10
	c0    add $r0.5 = $r0.5, 1   ## [spec] bblock 17, line 410,  t18,  t16,  1(SI32)
;;								## 7
	c0    cmpeq $b0.1 = $r0.5, $r0.2   ## [spec] bblock 17, line 411,  t171(I1),  t18,  t87
	c0    brf $b0.1, L107?3   ## bblock 0, line 406,  t162(I1)
;;								## 8
	c0    brf $b0.0, L108?3   ## bblock 4, line 408,  t163(I1)
;;								## 9
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.5   ## bblock 17, line 410, 0(I32), t18
	c0    brf $b0.1, L109?3   ## bblock 17, line 411,  t171(I1)
;;								## 10
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.3   ## bblock 19, line 412, 0(I32), t86
;;								## 11
.trace 9
L108?3:
	c0    ldw $r0.2 = ((clear_flg + 0) + 0)[$r0.0]   ## bblock 5, line 416, t24, 0(I32)
	c0    ldw.d $r0.6 = ((n_bits + 0) + 0)[$r0.0]   ## [spec] bblock 6, line 0, t90, 0(I32)
;;								## 0
	c0    mov $r0.5 = $r0.0   ## [spec] bblock 6, line 421,  t111,  0(SI32)
	c0    mov $r0.4 = (_?1PACKET.15 + 0)   ## [spec] bblock 6, line 0,  t138,  addr(buf?1.134)(P32)
	c0    mov $r0.10 = $r0.7   ## t89
;;								## 1
	c0    cmpgt $b0.0 = $r0.2, $r0.0   ## bblock 5, line 416,  t164(I1),  t24,  0(SI32)
	c0    sub $r0.8 = 3, $r0.6   ## [spec] bblock 6, line 0,  t140,  3(I32),  t90
	c0    mov $r0.11 = $r0.6   ## [spec] t90
;;								## 2
	c0    mov $r0.3 = $r0.8   ## [spec] bblock 6, line 0,  t139,  t140
	c0    br $b0.0, L110?3   ## bblock 5, line 416,  t164(I1)
;;								## 3
.trace 1
L111?3:
	c0    cmplt $b0.0 = $r0.3, 3   ## bblock 7, line 421,  t165(I1),  t139,  3(SI32)
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 11, line 423, t32, 0(I32)
	c0    cmplt $b0.1 = $r0.3, 2   ## [spec] bblock 14, line 421-1,  t170(I1),  t139,  2(SI32)
;;								## 0
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 15, line 423, t113, 0(I32)
	c0    cmplt $b0.0 = $r0.3, 1   ## [spec] bblock 40, line 421-2,  t179(I1),  t139,  1(SI32)
	c0    brf $b0.0, L112?3   ## bblock 7, line 421,  t165(I1)
;;								## 1
	c0    add $r0.2 = $r0.2, -1   ## bblock 11, line 423,  t33,  t32,  -1(SI32)
	c0    cmplt $b0.2 = $r0.3, $r0.0   ## [spec] bblock 32, line 421-3,  t176(I1),  t139,  0(SI32)
;;								## 2
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 11, line 423, 0(I32), t33
	c0    cmpge $b0.3 = $r0.2, $r0.0   ## bblock 11, line 423,  t168(I1),  t33,  0(SI32)
	c0    add $r0.7 = $r0.6, 1   ## [spec] bblock 15, line 423,  t114,  t113,  1(SI32)
;;								## 3
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 37, line 423-1, t127, 0(I32)
	c0    brf $b0.3, L113?3   ## bblock 11, line 423,  t168(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.7   ## bblock 15, line 423, 0(I32), t114
;;								## 5
	c0    ldb $r0.6 = 0[$r0.6]   ## bblock 15, line 423, t115(SI8), t113
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 37, line 423-1,  t128,  t127,  -1(SI32)
	c0    ldw.d $r0.7 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 41, line 423-1, t132, 0(I32)
;;								## 6
	c0    cmpge $b0.3 = $r0.2, $r0.0   ## [spec] bblock 37, line 423-1,  t177(I1),  t128,  0(SI32)
;;								## 7
	c0    zxtb $r0.6 = $r0.6   ## bblock 15, line 423,  t116(I8),  t115(SI8)
	c0    add $r0.8 = $r0.7, 1   ## [spec] bblock 41, line 423-1,  t133,  t132,  1(SI32)
;;								## 8
L114?3:
	c0    zxtb $r0.9 = $r0.6   ## bblock 13, line 423,  t118(I8),  t116(I8)
	c0    stb 0[$r0.4] = $r0.6   ## bblock 13, line 423, t138, t116(I8)
;;								## 9
	c0    cmpeq $b0.4 = $r0.9, 255   ## bblock 13, line 424,  t169(I1),  t118(I8),  255(SI32)
;;								## 10
	c0    br $b0.4, L115?3   ## bblock 13, line 424,  t169(I1)
;;								## 11
	c0    brf $b0.1, L116?3   ## bblock 14, line 421-1,  t170(I1)
;;								## 12
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 37, line 423-1, 0(I32), t128
	c0    brf $b0.3, L117?3   ## bblock 37, line 423-1,  t177(I1)
;;								## 13
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.8   ## bblock 41, line 423-1, 0(I32), t133
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 29, line 423-2, t117, 0(I32)
;;								## 14
	c0    ldb $r0.7 = 0[$r0.7]   ## bblock 41, line 423-1, t134(SI8), t132
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 33, line 423-2, t34, 0(I32)
;;								## 15
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 29, line 423-2,  t112,  t117,  -1(SI32)
;;								## 16
	c0    zxtb $r0.7 = $r0.7   ## bblock 41, line 423-1,  t129(I8),  t134(SI8)
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 29, line 423-2,  t174(I1),  t112,  0(SI32)
	c0    add $r0.8 = $r0.6, 1   ## [spec] bblock 33, line 423-2,  t35,  t34,  1(SI32)
;;								## 17
L118?3:
	c0    zxtb $r0.9 = $r0.7   ## bblock 39, line 423-1,  t130(I8),  t129(I8)
	c0    stb 1[$r0.4] = $r0.7   ## bblock 39, line 423-1, t138, t129(I8)
;;								## 18
	c0    cmpeq $b0.3 = $r0.9, 255   ## bblock 39, line 424-1,  t178(I1),  t130(I8),  255(SI32)
;;								## 19
	c0    br $b0.3, L119?3   ## bblock 39, line 424-1,  t178(I1)
;;								## 20
	c0    brf $b0.0, L120?3   ## bblock 40, line 421-2,  t179(I1)
;;								## 21
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 29, line 423-2, 0(I32), t112
	c0    brf $b0.1, L121?3   ## bblock 29, line 423-2,  t174(I1)
;;								## 22
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.8   ## bblock 33, line 423-2, 0(I32), t35
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 20, line 423-3, t125, 0(I32)
;;								## 23
	c0    ldb $r0.6 = 0[$r0.6]   ## bblock 33, line 423-2, t126(SI8), t34
	c0    ldw.d $r0.7 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 25, line 423-3, t122, 0(I32)
;;								## 24
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 20, line 423-3,  t124,  t125,  -1(SI32)
;;								## 25
	c0    zxtb $r0.6 = $r0.6   ## bblock 33, line 423-2,  t31(I8),  t126(SI8)
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## [spec] bblock 20, line 423-3,  t172(I1),  t124,  0(SI32)
	c0    add $r0.8 = $r0.7, 1   ## [spec] bblock 25, line 423-3,  t121,  t122,  1(SI32)
;;								## 26
L122?3:
	c0    zxtb $r0.9 = $r0.6   ## bblock 31, line 423-2,  t41(I8),  t31(I8)
	c0    stb 2[$r0.4] = $r0.6   ## bblock 31, line 423-2, t138, t31(I8)
;;								## 27
	c0    cmpeq $b0.1 = $r0.9, 255   ## bblock 31, line 424-2,  t175(I1),  t41(I8),  255(SI32)
;;								## 28
	c0    br $b0.1, L123?3   ## bblock 31, line 424-2,  t175(I1)
;;								## 29
	c0    brf $b0.2, L124?3   ## bblock 32, line 421-3,  t176(I1)
;;								## 30
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 20, line 423-3, 0(I32), t124
	c0    brf $b0.0, L125?3   ## bblock 20, line 423-3,  t172(I1)
;;								## 31
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.8   ## bblock 25, line 423-3, 0(I32), t121
	c0    add $r0.3 = $r0.3, 4   ## [spec] bblock 24, line 0,  t139,  t139,  4(I32)
;;								## 32
	c0    ldb $r0.7 = 0[$r0.7]   ## bblock 25, line 423-3, t36(SI8), t122
	      xnop 1
;;								## 34
	c0    zxtb $r0.7 = $r0.7   ## bblock 25, line 423-3,  t119(I8),  t36(SI8)
;;								## 35
L126?3:
	c0    zxtb $r0.2 = $r0.7   ## bblock 23, line 423-3,  t123(I8),  t119(I8)
	c0    stb 3[$r0.4] = $r0.7   ## bblock 23, line 423-3, t138, t119(I8)
;;								## 36
	c0    cmpeq $b0.0 = $r0.2, 255   ## bblock 23, line 424-3,  t173(I1),  t123(I8),  255(SI32)
	c0    add $r0.4 = $r0.4, 4   ## [spec] bblock 24, line 0,  t138,  t138,  4(I32)
;;								## 37
	c0    br $b0.0, L127?3   ## bblock 23, line 424-3,  t173(I1)
;;								## 38
	c0    add $r0.5 = $r0.5, 4   ## bblock 24, line 421-3,  t111,  t111,  4(SI32)
	c0    goto L111?3 ## goto
;;								## 39
.trace 21
L127?3:
	c0    add $r0.11 = $r0.5, 3   ## bblock 27, line 0,  t110,  t111,  3(I32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    goto L128?3 ## goto
;;								## 0
.trace 12
L129?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 9, line 430, t43, 0(I32)
	c0    mov $r0.7 = $r0.0   ## bblock 9, line 429,  t89,  0(SI32)
	c0    shl $r0.11 = $r0.11, 3   ## bblock 9, line 430,  t45,  t110,  3(SI32)
;;								## 0
	c0    add $r0.11 = $r0.11, 1   ## bblock 9, line 430,  t167,  t45,  1(SI32)
;;								## 1
	c0    sub $r0.9 = $r0.11, $r0.2   ## bblock 9, line 430,  t88,  t167,  t43
;;								## 2
.trace 8
L107?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 1, line 433, t72, 0(I32)
	c0    shr $r0.5 = $r0.7, 3   ## bblock 1, line 434,  t49(SI29),  t89,  3(SI32)
	c0    and $r0.4 = $r0.7, 7   ## bblock 1, line 435,  t51,  t89,  7(I32)
;;								## 0
	c0    add $r0.6 = $r0.5, (_?1PACKET.15 + 0)   ## bblock 1, line 434,  t52,  t49(SI29),  addr(buf?1.134)(P32)
	c0    add $r0.8 = $r0.5, ((_?1PACKET.15 + 0) + 1)   ## bblock 1, line 437,  t107,  t49(SI29),  (addr(buf?1.134)(P32) + 0x1(I32))(P32)
;;								## 1
	c0    add $r0.10 = $r0.2, $r0.4   ## bblock 1, line 438,  t159,  t72,  t51
	c0    sub $r0.12 = 16, $r0.4   ## bblock 1, line 443,  t102,  16(SI32),  t51
	c0    sub $r0.13 = 8, $r0.4   ## bblock 1, line 439,  t105,  8(SI32),  t51
	c0    add $r0.11 = $r0.6, 2   ## bblock 1, line 442,  t98,  t52,  2(SI32)
;;								## 2
	c0    add $r0.2 = $r0.2, $r0.7   ## bblock 1, line 448,  t93,  t72,  t89
	c0    add $r0.14 = $r0.10, -8   ## bblock 1, line 438,  t106,  t159,  -8(SI32)
	c0    add $r0.15 = $r0.10, -16   ## bblock 1, line 444,  t101,  t159,  -16(SI32)
	c0    ldbu.d $r0.6 = 1[$r0.6]   ## [spec] bblock 1, line 442, t97(I8), t52
;;								## 3
	c0    ldbu $r0.5 = (_?1PACKET.15 + 0)[$r0.5]   ## bblock 1, line 437, t54(I8), t49(SI29)
	c0    cmpge $b0.0 = $r0.14, 8   ## bblock 1, line 440,  t96(I1),  t106,  8(SI32)
;;								## 4
	c0    slct $r0.15 = $b0.0, $r0.15, $r0.14   ## bblock 1, line 444,  t3,  t96(I1),  t101,  t106
	c0    slct $r0.12 = $b0.0, $r0.12, $r0.13   ## bblock 1, line 443,  t2,  t96(I1),  t102,  t105
	c0    shl $r0.6 = $r0.6, $r0.13   ## bblock 1, line 442,  t99,  t97(I8),  t105
	c0    slct $r0.11 = $b0.0, $r0.11, $r0.8   ## bblock 1, line 442,  t4,  t96(I1),  t98,  t107
;;								## 5
	c0    shr $r0.5 = $r0.5, $r0.4   ## bblock 1, line 437,  t108,  t54(I8),  t51
	c0    ldbu $r0.11 = 0[$r0.11]   ## bblock 1, line 447, t67(I8), t4
	c0    ldbu $r0.15 = (rmask + 0)[$r0.15]   ## bblock 1, line 447, t66(I8), t3
;;								## 6
	c0    or $r0.6 = $r0.5, $r0.6   ## bblock 1, line 442,  t100,  t108,  t99
	c0    stw ((_?1PACKET.13 + 0) + 0)[$r0.0] = $r0.2   ## bblock 1, line 449, 0(I32), t93
;;								## 7
	c0    slct $r0.6 = $b0.0, $r0.6, $r0.5   ## bblock 1, line 442,  t0,  t96(I1),  t100,  t108
	c0    and $r0.11 = $r0.11, $r0.15   ## bblock 1, line 447,  t68,  t67(I8),  t66(I8)
	c0    stw ((_?1PACKET.14 + 0) + 0)[$r0.0] = $r0.9   ## bblock 1, line 449, 0(I32), t88
;;								## 8
	c0    shl $r0.11 = $r0.11, $r0.12   ## bblock 1, line 447,  t69,  t68,  t2
;;								## 9
.return ret($r0.3:s32)
	c0    or $r0.3 = $r0.6, $r0.11   ## bblock 1, line 447,  t95,  t0,  t69
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 449,  t75,  ?2.8?2auto_size(I32),  t74
;;								## 10
.trace 6
L125?3:
	c0    mov $r0.7 = -1   ## bblock 22, line 423-3,  t119(I8),  -1(SI32)
	c0    add $r0.3 = $r0.3, 4   ## [spec] bblock 24, line 0,  t139,  t139,  4(I32)
	c0    goto L126?3 ## goto
;;								## 0
.trace 20
L124?3:
	c0    max $r0.11 = $r0.11, $r0.0   ## bblock 2, line 0,  t110,  t90,  0(SI32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    goto L128?3 ## goto
;;								## 0
.trace 19
L123?3:
	c0    add $r0.11 = $r0.5, 2   ## bblock 35, line 0,  t110,  t111,  2(I32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    goto L128?3 ## goto
;;								## 0
.trace 5
L121?3:
	c0    ldw.d $r0.9 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 20, line 423-3, t125, 0(I32)
	c0    ldw.d $r0.7 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 25, line 423-3, t122, 0(I32)
;;								## 0
	c0    mov $r0.6 = -1   ## bblock 30, line 423-2,  t31(I8),  -1(SI32)
;;								## 1
	c0    add $r0.2 = $r0.9, -1   ## [spec] bblock 20, line 423-3,  t124,  t125,  -1(SI32)
	c0    add $r0.8 = $r0.7, 1   ## [spec] bblock 25, line 423-3,  t121,  t122,  1(SI32)
;;								## 2
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## [spec] bblock 20, line 423-3,  t172(I1),  t124,  0(SI32)
	c0    goto L122?3 ## goto
;;								## 3
.trace 18
L120?3:
	c0    max $r0.11 = $r0.11, $r0.0   ## bblock 2, line 0,  t110,  t90,  0(SI32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    goto L128?3 ## goto
;;								## 0
.trace 17
L119?3:
	c0    add $r0.11 = $r0.5, 1   ## bblock 43, line 0,  t110,  t111,  1(I32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    goto L128?3 ## goto
;;								## 0
.trace 4
L117?3:
	c0    ldw.d $r0.9 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 29, line 423-2, t117, 0(I32)
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 33, line 423-2, t34, 0(I32)
;;								## 0
	c0    mov $r0.7 = -1   ## bblock 38, line 423-1,  t129(I8),  -1(SI32)
;;								## 1
	c0    add $r0.2 = $r0.9, -1   ## [spec] bblock 29, line 423-2,  t112,  t117,  -1(SI32)
	c0    add $r0.8 = $r0.6, 1   ## [spec] bblock 33, line 423-2,  t35,  t34,  1(SI32)
;;								## 2
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 29, line 423-2,  t174(I1),  t112,  0(SI32)
	c0    goto L118?3 ## goto
;;								## 3
.trace 16
L116?3:
	c0    max $r0.11 = $r0.11, $r0.0   ## bblock 2, line 0,  t110,  t90,  0(SI32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    goto L128?3 ## goto
;;								## 0
.trace 15
L115?3:
	c0    mov $r0.11 = $r0.5   ## bblock 45, line 0,  t110,  t111
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    goto L128?3 ## goto
;;								## 0
.trace 3
L113?3:
	c0    mov $r0.6 = -1   ## bblock 12, line 423,  t116(I8),  -1(SI32)
	c0    ldw.d $r0.7 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 41, line 423-1, t132, 0(I32)
;;								## 0
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 37, line 423-1,  t128,  t127,  -1(SI32)
;;								## 1
	c0    cmpge $b0.3 = $r0.2, $r0.0   ## [spec] bblock 37, line 423-1,  t177(I1),  t128,  0(SI32)
	c0    add $r0.8 = $r0.7, 1   ## [spec] bblock 41, line 423-1,  t133,  t132,  1(SI32)
	c0    goto L114?3 ## goto
;;								## 2
.trace 10
L112?3:
	c0    max $r0.11 = $r0.11, $r0.0   ## bblock 2, line 0,  t110,  t90,  0(SI32)
	c0    mov $r0.3 = -1   ## -1(SI32)
;;								## 0
L128?3:
	c0    cmple $b0.0 = $r0.11, $r0.0   ## bblock 8, line 427,  t166(I1),  t110,  0(SI32)
;;								## 1
	c0    brf $b0.0, L129?3   ## bblock 8, line 427,  t166(I1)
;;								## 2
	c0    stw ((_?1PACKET.14 + 0) + 0)[$r0.0] = $r0.11   ## bblock 10, line 428, 0(I32), t110
	c0    stw ((_?1PACKET.13 + 0) + 0)[$r0.0] = $r0.10   ## bblock 10, line 428, 0(I32), t89
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 10, line 428,  t75,  ?2.8?2auto_size(I32),  t74
;;								## 4
.trace 11
L110?3:
	c0    mov $r0.6 = 511   ## 511(SI32)
	c0    mov $r0.2 = 9   ## 9(SI32)
;;								## 0
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.2   ## bblock 16, line 418, 0(I32), 9(SI32)
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.6   ## bblock 16, line 418, 0(I32), 511(SI32)
;;								## 1
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.0   ## bblock 16, line 419, 0(I32), 0(SI32)
	c0    ldw $r0.11 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 6, line 0, t90, 0(I32)
	      xnop 1
;;								## 3
	c0    sub $r0.8 = 3, $r0.11   ## bblock 6, line 0,  t140,  3(I32),  t90
;;								## 4
	c0    mov $r0.3 = $r0.8   ## bblock 6, line 0,  t139,  t140
	c0    goto L111?3 ## goto
;;								## 5
.trace 14
L109?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 18, line 414, t21, 0(I32)
	c0    mov $r0.3 = 1   ## 1(SI32)
	      xnop 1
;;								## 1
	c0    shl $r0.3 = $r0.3, $r0.2   ## bblock 18, line 414,  t22,  1(SI32),  t21
;;								## 2
	c0    add $r0.3 = $r0.3, -1   ## bblock 18, line 414,  t23,  t22,  -1(SI32)
;;								## 3
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.3   ## bblock 18, line 414, 0(I32), t23
	c0    goto L108?3 ## goto
;;								## 4
.endp
.section .bss
_?1PACKET.15:
    .skip 12
.section .data
.skip 3
_?1PACKET.14:
    .data4 0
_?1PACKET.13:
    .data4 0
.section .data
.section .text
.equ ?2.8?2auto_size, 0x0
 ## End compressgetcode
 ## Begin writeerr
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
writeerr::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    mov $r0.3 = (_?1STRINGPACKET.8 + 0)   ## addr(_?1STRINGVAR.8)(P32)
;;								## 0
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 0, line 454,  raddr(puts)(P32),  addr(_?1STRINGVAR.8)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t2
;;								## 1
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t2
	      xnop 1
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 455,  t3,  ?2.9?2auto_size(I32),  t2
;;								## 4
.endp
.section .bss
.section .data
_?1STRINGPACKET.8:
    .data1 69
    .data1 82
    .data1 82
    .data1 79
    .data1 82
    .data1 58
    .data1 32
    .data1 119
    .data1 114
    .data1 105
    .data1 116
    .data1 101
    .data1 114
    .data1 114
    .data1 32
    .data1 119
    .data1 97
    .data1 115
    .data1 32
    .data1 99
    .data1 97
    .data1 108
    .data1 108
    .data1 101
    .data1 100
    .data1 10
    .data1 0
.equ ?2.9?2scratch.0, 0x0
.equ ?2.9?2ras_p, 0x10
.section .data
.section .text
.equ ?2.9?2auto_size, 0x20
 ## End writeerr
 ## Begin foreground
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg()
foreground::
.trace 1
	      ## auto_size == 0
	c0    ldw $r0.2 = ((bgnd_flag + 0) + 0)[$r0.0]   ## bblock 0, line 458, t0, 0(I32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 1
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 0, line 460,  t13(I1),  t0,  0x0(P32)
;;								## 2
	c0    brf $b0.0, L130?3   ## bblock 0, line 460,  t13(I1)
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 462,  t2,  ?2.10?2auto_size(I32),  t1
;;								## 4
.trace 2
L130?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 465,  t2,  ?2.10?2auto_size(I32),  t1
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.10?2auto_size, 0x0
 ## End foreground
 ## Begin onintr
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg()
onintr::
.trace 1
	      ## auto_size == 0
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 470,  t1,  ?2.11?2auto_size(I32),  t0
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.11?2auto_size, 0x0
 ## End onintr
 ## Begin oops
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
oops::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    ldw $r0.2 = ((do_decomp + 0) + 0)[$r0.0]   ## bblock 0, line 475, t0, 0(I32)
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.9 + 0)   ## addr(_?1STRINGVAR.9)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t3
;;								## 1
	c0    cmpeq $b0.0 = $r0.2, 1   ## bblock 0, line 475,  t14(I1),  t0,  1(SI32)
;;								## 2
	c0    brf $b0.0, L131?3   ## bblock 0, line 475,  t14(I1)
;;								## 3
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 2, line 476,  raddr(puts)(P32),  addr(_?1STRINGVAR.9)(P32)
;;								## 4
L131?3:
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t3
	      xnop 1
;;								## 6
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 477,  t4,  ?2.12?2auto_size(I32),  t3
;;								## 7
.endp
.section .bss
.section .data
.skip 1
_?1STRINGPACKET.9:
    .data1 117
    .data1 110
    .data1 99
    .data1 111
    .data1 109
    .data1 112
    .data1 114
    .data1 101
    .data1 115
    .data1 115
    .data1 58
    .data1 32
    .data1 99
    .data1 111
    .data1 114
    .data1 114
    .data1 117
    .data1 112
    .data1 116
    .data1 32
    .data1 105
    .data1 110
    .data1 112
    .data1 117
    .data1 116
    .data1 10
    .data1 0
.equ ?2.12?2scratch.0, 0x0
.equ ?2.12?2ras_p, 0x10
.section .data
.section .text
.equ ?2.12?2auto_size, 0x20
 ## End oops
 ## Begin cl_block
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
cl_block::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    ldw $r0.2 = ((in_count + 0) + 0)[$r0.0]   ## bblock 0, line 483, t3, 0(I32)
;;								## 0
	c0    ldw.d $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## [spec] bblock 7, line 486, t4, 0(I32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t14
;;								## 1
	c0    add $r0.4 = $r0.2, 10000   ## bblock 0, line 483,  t2,  t3,  10000(SI32)
	c0    cmpgt $b0.0 = $r0.2, 8388607   ## bblock 0, line 484,  t26(I1),  t3,  8388607(SI32)
;;								## 2
	c0    shr $r0.3 = $r0.3, 8   ## [spec] bblock 7, line 486,  t0(SI24),  t4,  8(SI32)
	c0    mov $r0.2 = 2147483647   ## [spec] bblock 9, line 489,  t25,  2147483647(SI32)
;;								## 3
	c0    stw ((checkpoint + 0) + 0)[$r0.0] = $r0.4   ## bblock 0, line 483, 0(I32), t2
	c0    cmpeq $b0.1 = $r0.3, $r0.0   ## [spec] bblock 7, line 487,  t28(I1),  t0(SI24),  0(SI32)
	c0    brf $b0.0, L132?3   ## bblock 0, line 484,  t26(I1)
;;								## 4
	c0    brf $b0.1, L133?3   ## bblock 7, line 487,  t28(I1)
;;								## 5
.trace 2
L134?3:
	c0    ldw $r0.4 = ((ratio + 0) + 0)[$r0.0]   ## bblock 2, line 502, t12, 0(I32)
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t14
	      xnop 1
;;								## 1
	c0    cmpgt $b0.0 = $r0.2, $r0.4   ## bblock 2, line 502,  t27(I1),  t25,  t12
;;								## 2
	c0    brf $b0.0, L135?3   ## bblock 2, line 502,  t27(I1)
;;								## 3
.return ret($r0.3:s32)
	c0    stw ((ratio + 0) + 0)[$r0.0] = $r0.2   ## bblock 6, line 504, 0(I32), t25
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 5, line 515,  t15,  ?2.13?2auto_size(I32),  t14
;;								## 4
.trace 3
L135?3:
	c0    stw ((ratio + 0) + 0)[$r0.0] = $r0.0   ## bblock 3, line 508, 0(I32), 0(SI32)
	c0    ldw $r0.3 = ((hsize + 0) + 0)[$r0.0]   ## bblock 3, line 509, t13, 0(I32)
;;								## 0
.call cl_hash, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = cl_hash   ## bblock 3, line 509,  raddr(cl_hash)(P32),  t13
;;								## 1
	c0    mov $r0.4 = 1   ## 1(SI32)
	c0    mov $r0.2 = 257   ## 257(SI32)
;;								## 2
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.2   ## bblock 4, line 510, 0(I32), 257(SI32)
	c0    mov $r0.3 = 256   ## 256(SI32)
;;								## 3
.call output, caller, arg($r0.3:s32), ret()
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.4   ## bblock 4, line 511, 0(I32), 1(SI32)
	c0    call $l0.0 = output   ## bblock 4, line 512,  raddr(output)(P32),  256(SI32)
;;								## 4
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t14
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	      xnop 1
;;								## 6
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 5, line 515,  t15,  ?2.13?2auto_size(I32),  t14
;;								## 7
.trace 5
L133?3:
	c0    ldw $r0.5 = ((in_count + 0) + 0)[$r0.0]   ## bblock 8, line 493, t6, 0(I32)
	c0    mov $r0.4 = $r0.3   ## t0(SI24)
	      xnop 1
;;								## 1
.call _i_div, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = _i_div   ## bblock 8, line 493,  raddr(_i_div)(P32),  t6,  t0(SI24)
	c0    mov $r0.3 = $r0.5   ## t6
;;								## 2
	c0    mov $r0.2 = $r0.3   ## t25
	c0    goto L134?3 ## goto
;;								## 3
.trace 4
L132?3:
	c0    ldw $r0.5 = ((in_count + 0) + 0)[$r0.0]   ## bblock 1, line 499, t8, 0(I32)
	c0    ldw $r0.4 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 1, line 499, t10, 0(I32)
	      xnop 1
;;								## 1
.call _i_div, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    shl $r0.3 = $r0.5, 8   ## bblock 1, line 499,  t9,  t8,  8(SI32)
	c0    call $l0.0 = _i_div   ## bblock 1, line 499,  raddr(_i_div)(P32),  t9,  t10
;;								## 2
	c0    mov $r0.2 = $r0.3   ## t25
	c0    goto L134?3 ## goto
;;								## 3
.endp
.section .bss
.section .data
.equ ?2.13?2scratch.0, 0x0
.equ ?2.13?2ras_p, 0x10
.section .data
.section .text
.equ ?2.13?2auto_size, 0x20
 ## End cl_block
.equ _?1TEMPLATEPACKET.9, 0x0
 ## Begin cl_hash
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32)
cl_hash::
.trace 5
	      ## auto_size == 0
	c0    sh2add $r0.7 = $r0.3, (htab + 0)   ## bblock 0, line 521,  t1,  t0,  addr(htab?1.0)(P32)
;;								## 0
	c0    add $r0.8 = $r0.3, -16   ## bblock 0, line 524,  t2,  t0,  -16(SI32)
	c0    add $r0.4 = $r0.3, (~0x1f)   ## bblock 0, line 0,  t87,  t0,  (~0x1f)(I32)
	c0    add $r0.2 = $r0.7, (~0x3f)   ## bblock 0, line 0,  t85,  t1,  (~0x3f)(I32)
;;								## 1
.trace 1
L136?3:
	c0    mov $r0.3 = $r0.2   ## bblock 1, line 0,  t46,  t85
	c0    mov $r0.5 = $r0.4   ## bblock 1, line 0,  t47,  t87
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 1, line 546,  t102(I1),  t87,  0(SI32)
	c0    mov $r0.6 = -1   ## -1(SI32)
;;								## 0
	c0    stw 0[$r0.2] = $r0.6   ## bblock 1, line 527, t85, -1(SI32)
	c0    stw 4[$r0.2] = $r0.6   ## bblock 1, line 528, t85, -1(SI32)
	c0    cmplt $b0.1 = $r0.4, 16   ## [spec] bblock 8, line 546-1,  t106(I1),  t87,  16(SI32)
	c0    add $r0.4 = $r0.4, (~0x2f)   ## [spec] bblock 6, line 0,  t87,  t87,  (~0x2f)(I32)
;;								## 1
	c0    stw 8[$r0.2] = $r0.6   ## bblock 1, line 529, t85, -1(SI32)
	c0    stw 12[$r0.2] = $r0.6   ## bblock 1, line 530, t85, -1(SI32)
;;								## 2
	c0    stw 16[$r0.2] = $r0.6   ## bblock 1, line 531, t85, -1(SI32)
	c0    stw 20[$r0.2] = $r0.6   ## bblock 1, line 532, t85, -1(SI32)
;;								## 3
	c0    stw 24[$r0.2] = $r0.6   ## bblock 1, line 533, t85, -1(SI32)
	c0    stw 28[$r0.2] = $r0.6   ## bblock 1, line 534, t85, -1(SI32)
;;								## 4
	c0    stw 32[$r0.2] = $r0.6   ## bblock 1, line 535, t85, -1(SI32)
	c0    stw 36[$r0.2] = $r0.6   ## bblock 1, line 536, t85, -1(SI32)
;;								## 5
	c0    stw 40[$r0.2] = $r0.6   ## bblock 1, line 537, t85, -1(SI32)
	c0    stw 44[$r0.2] = $r0.6   ## bblock 1, line 538, t85, -1(SI32)
;;								## 6
	c0    stw 48[$r0.2] = $r0.6   ## bblock 1, line 539, t85, -1(SI32)
	c0    stw 52[$r0.2] = $r0.6   ## bblock 1, line 540, t85, -1(SI32)
;;								## 7
	c0    stw 56[$r0.2] = $r0.6   ## bblock 1, line 541, t85, -1(SI32)
	c0    stw 60[$r0.2] = $r0.6   ## bblock 1, line 542, t85, -1(SI32)
	c0    br $b0.0, L137?3   ## bblock 1, line 546,  t102(I1)
;;								## 8
	c0    stw (~0x3f)[$r0.2] = $r0.6   ## bblock 8, line 527-1, t85, -1(SI32)
	c0    stw (~0x3b)[$r0.2] = $r0.6   ## bblock 8, line 528-1, t85, -1(SI32)
;;								## 9
	c0    stw (~0x37)[$r0.2] = $r0.6   ## bblock 8, line 529-1, t85, -1(SI32)
	c0    stw (~0x33)[$r0.2] = $r0.6   ## bblock 8, line 530-1, t85, -1(SI32)
;;								## 10
	c0    stw (~0x2f)[$r0.2] = $r0.6   ## bblock 8, line 531-1, t85, -1(SI32)
	c0    stw (~0x2b)[$r0.2] = $r0.6   ## bblock 8, line 532-1, t85, -1(SI32)
;;								## 11
	c0    stw (~0x27)[$r0.2] = $r0.6   ## bblock 8, line 533-1, t85, -1(SI32)
	c0    stw (~0x23)[$r0.2] = $r0.6   ## bblock 8, line 534-1, t85, -1(SI32)
;;								## 12
	c0    stw (~0x1f)[$r0.2] = $r0.6   ## bblock 8, line 535-1, t85, -1(SI32)
	c0    stw (~0x1b)[$r0.2] = $r0.6   ## bblock 8, line 536-1, t85, -1(SI32)
;;								## 13
	c0    stw (~0x17)[$r0.2] = $r0.6   ## bblock 8, line 537-1, t85, -1(SI32)
	c0    stw (~0x13)[$r0.2] = $r0.6   ## bblock 8, line 538-1, t85, -1(SI32)
;;								## 14
	c0    stw (~0xf)[$r0.2] = $r0.6   ## bblock 8, line 539-1, t85, -1(SI32)
	c0    stw (~0xb)[$r0.2] = $r0.6   ## bblock 8, line 540-1, t85, -1(SI32)
;;								## 15
	c0    stw (~0x7)[$r0.2] = $r0.6   ## bblock 8, line 541-1, t85, -1(SI32)
	c0    stw (~0x3)[$r0.2] = $r0.6   ## bblock 8, line 542-1, t85, -1(SI32)
	c0    br $b0.1, L138?3   ## bblock 8, line 546-1,  t106(I1)
;;								## 16
	c0    stw (~0x7f)[$r0.2] = $r0.6   ## bblock 6, line 527-2, t85, -1(SI32)
	c0    stw (~0x7b)[$r0.2] = $r0.6   ## bblock 6, line 528-2, t85, -1(SI32)
	c0    add $r0.8 = $r0.8, -48   ## bblock 6, line 546-2,  t2,  t2,  -48(SI32)
	c0    add $r0.7 = $r0.7, -192   ## bblock 6, line 527-2,  t1,  t1,  -192(SI32)
;;								## 17
	c0    stw (~0x77)[$r0.2] = $r0.6   ## bblock 6, line 529-2, t85, -1(SI32)
	c0    stw (~0x73)[$r0.2] = $r0.6   ## bblock 6, line 530-2, t85, -1(SI32)
	c0    cmplt $b0.0 = $r0.8, $r0.0   ## bblock 6, line 546-2,  t105(I1),  t2,  0(SI32)
;;								## 18
	c0    stw (~0x6f)[$r0.2] = $r0.6   ## bblock 6, line 531-2, t85, -1(SI32)
	c0    stw (~0x6b)[$r0.2] = $r0.6   ## bblock 6, line 532-2, t85, -1(SI32)
;;								## 19
	c0    stw (~0x67)[$r0.2] = $r0.6   ## bblock 6, line 533-2, t85, -1(SI32)
	c0    stw (~0x63)[$r0.2] = $r0.6   ## bblock 6, line 534-2, t85, -1(SI32)
;;								## 20
	c0    stw (~0x5f)[$r0.2] = $r0.6   ## bblock 6, line 535-2, t85, -1(SI32)
	c0    stw (~0x5b)[$r0.2] = $r0.6   ## bblock 6, line 536-2, t85, -1(SI32)
;;								## 21
	c0    stw (~0x57)[$r0.2] = $r0.6   ## bblock 6, line 537-2, t85, -1(SI32)
	c0    stw (~0x53)[$r0.2] = $r0.6   ## bblock 6, line 538-2, t85, -1(SI32)
;;								## 22
	c0    stw (~0x4f)[$r0.2] = $r0.6   ## bblock 6, line 539-2, t85, -1(SI32)
	c0    stw (~0x4b)[$r0.2] = $r0.6   ## bblock 6, line 540-2, t85, -1(SI32)
;;								## 23
	c0    stw (~0x47)[$r0.2] = $r0.6   ## bblock 6, line 541-2, t85, -1(SI32)
	c0    stw (~0x43)[$r0.2] = $r0.6   ## bblock 6, line 542-2, t85, -1(SI32)
	c0    add $r0.2 = $r0.2, (~0xbf)   ## bblock 6, line 0,  t85,  t85,  (~0xbf)(I32)
	c0    br $b0.0, L139?3   ## bblock 6, line 546-2,  t105(I1)
	      ## goto
;;
	c0    goto L136?3 ## goto
;;								## 24
.trace 9
L139?3:
	c0    add $r0.7 = $r0.3, (~0x7f)   ## bblock 7, line 0,  t45,  t46,  (~0x7f)(I32)
	c0    add $r0.8 = $r0.5, (~0x1f)   ## bblock 7, line 0,  t44,  t47,  (~0x1f)(I32)
	c0    goto L140?3 ## goto
;;								## 0
.trace 2
L141?3:
	c0    cmpgt $b0.0 = $r0.2, $r0.0   ## bblock 3, line 547,  t103(I1),  t43,  0(SI32)
	c0    cmpgt $b0.1 = $r0.2, 1   ## [spec] bblock 5, line 547-1,  t104(I1),  t43,  1(SI32)
	c0    cmpgt $b0.2 = $r0.2, 2   ## [spec] bblock 18, line 547-2,  t108(I1),  t43,  2(SI32)
	c0    mov $r0.6 = -1   ## -1(SI32)
;;								## 0
	c0    cmpgt $b0.0 = $r0.2, 3   ## [spec] bblock 15, line 547-3,  t107(I1),  t43,  3(SI32)
	c0    add $r0.2 = $r0.2, -4   ## [spec] bblock 12, line 547-3,  t43,  t43,  -4(SI32)
	c0    brf $b0.0, L142?3   ## bblock 3, line 547,  t103(I1)
;;								## 1
	c0    stw 12[$r0.3] = $r0.6   ## bblock 5, line 548, t62, -1(SI32)
	c0    brf $b0.1, L142?3   ## bblock 5, line 547-1,  t104(I1)
;;								## 2
	c0    stw 8[$r0.3] = $r0.6   ## bblock 18, line 548-1, t62, -1(SI32)
	c0    brf $b0.2, L142?3   ## bblock 18, line 547-2,  t108(I1)
;;								## 3
	c0    stw 4[$r0.3] = $r0.6   ## bblock 15, line 548-2, t62, -1(SI32)
	c0    brf $b0.0, L142?3   ## bblock 15, line 547-3,  t107(I1)
;;								## 4
	c0    stw 0[$r0.3] = $r0.6   ## bblock 12, line 548-3, t62, -1(SI32)
	c0    add $r0.3 = $r0.3, (~0xf)   ## bblock 12, line 0,  t62,  t62,  (~0xf)(I32)
	c0    goto L141?3 ## goto
;;								## 5
.trace 7
L142?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 4, line 549,  t30,  ?2.14?2auto_size(I32),  t29
;;								## 0
.trace 8
L138?3:
	c0    add $r0.7 = $r0.7, (~0x7f)   ## bblock 9, line 0,  t45,  t1,  (~0x7f)(I32)
	c0    add $r0.8 = $r0.8, (~0x1f)   ## bblock 9, line 0,  t44,  t2,  (~0x1f)(I32)
	c0    goto L140?3 ## goto
;;								## 0
.trace 6
L137?3:
	c0    add $r0.7 = $r0.7, (~0x3f)   ## bblock 10, line 0,  t45,  t1,  (~0x3f)(I32)
	c0    add $r0.8 = $r0.8, (~0xf)   ## bblock 10, line 0,  t44,  t2,  (~0xf)(I32)
;;								## 0
L140?3:
	c0    add $r0.2 = $r0.8, 16   ## bblock 2, line 547,  t43,  t44,  16(SI32)
	c0    add $r0.3 = $r0.7, (~0xf)   ## bblock 2, line 0,  t62,  t45,  (~0xf)(I32)
	c0    goto L141?3 ## goto
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.14?2auto_size, 0x0
 ## End cl_hash
 ## Begin prratio
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
prratio::
.trace 1
	      ## auto_size == 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 571,  t18,  ?2.15?2auto_size(I32),  t17
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.15?2auto_size, 0x0
 ## End prratio
 ## Begin version
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg()
version::
.trace 1
	      ## auto_size == 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 576,  t1,  ?2.16?2auto_size(I32),  t0
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.16?2auto_size, 0x0
 ## End version
.section .bss
compress_3906.offset::
    .skip 4
compress_3906.buf::
    .skip 12
.section .data
.skip 1
compress_3906.Buf::
    .data1 47
    .data1 42
    .data1 32
    .data1 82
    .data1 101
    .data1 112
    .data1 108
    .data1 97
    .data1 99
    .data1 101
    .data1 109
    .data1 101
    .data1 110
    .data1 116
    .data1 32
    .data1 114
    .data1 111
    .data1 117
    .data1 116
    .data1 105
    .data1 110
    .data1 101
    .data1 115
    .data1 32
    .data1 102
    .data1 111
    .data1 114
    .data1 32
    .data1 115
    .data1 116
    .data1 97
    .data1 110
    .data1 100
    .data1 97
    .data1 114
    .data1 100
    .data1 32
    .data1 67
    .data1 32
    .data1 114
    .data1 111
    .data1 117
    .data1 116
    .data1 105
    .data1 110
    .data1 101
    .data1 115
    .data1 46
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 35
    .data1 100
    .data1 101
    .data1 102
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 67
    .data1 79
    .data1 78
    .data1 83
    .data1 79
    .data1 76
    .data1 69
    .data1 32
    .data1 48
    .data1 0
    .data1 35
    .data1 105
    .data1 102
    .data1 110
    .data1 100
    .data1 101
    .data1 102
    .data1 32
    .data1 83
    .data1 85
    .data1 78
    .data1 0
    .data1 35
    .data1 100
    .data1 101
    .data1 102
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 115
    .data1 116
    .data1 100
    .data1 101
    .data1 114
    .data1 114
    .data1 32
    .data1 67
    .data1 79
    .data1 78
    .data1 83
    .data1 79
    .data1 76
    .data1 69
    .data1 0
    .data1 35
    .data1 100
    .data1 101
    .data1 102
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 69
    .data1 79
    .data1 70
    .data1 32
    .data1 40
    .data1 45
    .data1 49
    .data1 41
    .data1 0
    .data1 35
    .data1 101
    .data1 110
    .data1 100
    .data1 105
    .data1 102
    .data1 32
    .data1 47
    .data1 42
    .data1 32
    .data1 83
    .data1 85
    .data1 78
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 0
    .data1 35
    .data1 105
    .data1 110
    .data1 99
    .data1 108
    .data1 117
    .data1 100
    .data1 101
    .data1 32
    .data1 34
    .data1 98
    .data1 117
    .data1 102
    .data1 46
    .data1 99
    .data1 34
    .data1 0
    .data1 0
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 42
    .data1 32
    .data1 111
    .data1 117
    .data1 116
    .data1 98
    .data1 117
    .data1 102
    .data1 32
    .data1 61
    .data1 32
    .data1 48
    .data1 59
    .data1 0
    .data1 0
    .data1 105
    .data1 110
    .data1 116
    .data1 32
    .data1 103
    .data1 101
    .data1 116
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 40
    .data1 41
    .data1 0
    .data1 123
    .data1 32
    .data1 115
    .data1 116
    .data1 97
    .data1 116
    .data1 105
    .data1 99
    .data1 32
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 32
    .data1 42
    .data1 98
    .data1 117
    .data1 102
    .data1 112
    .data1 32
    .data1 61
    .data1 32
    .data1 66
    .data1 117
    .data1 102
    .data1 59
    .data1 0
    .data1 32
    .data1 32
    .data1 115
    .data1 116
    .data1 97
    .data1 116
    .data1 105
    .data1 99
    .data1 32
    .data1 105
    .data1 110
    .data1 116
    .data1 32
    .data1 110
    .data1 32
    .data1 61
    .data1 32
    .data1 66
    .data1 117
    .data1 102
    .data1 108
    .data1 101
    .data1 110
    .data1 59
    .data1 0
    .data1 35
    .data1 105
    .data1 102
    .data1 100
    .data1 101
    .data1 102
    .data1 32
    .data1 84
    .data1 69
    .data1 83
    .data1 84
    .data1 0
    .data1 32
    .data1 32
    .data1 105
    .data1 102
    .data1 32
    .data1 40
    .data1 32
    .data1 110
    .data1 32
    .data1 61
    .data1 61
    .data1 32
    .data1 48
    .data1 32
    .data1 41
    .data1 32
    .data1 123
    .data1 32
    .data1 32
    .data1 32
    .data1 47
    .data1 42
    .data1 32
    .data1 98
    .data1 117
    .data1 102
    .data1 102
    .data1 101
    .data1 114
    .data1 32
    .data1 105
    .data1 115
    .data1 32
    .data1 101
    .data1 109
    .data1 112
    .data1 116
    .data1 121
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 110
    .data1 32
    .data1 61
    .data1 32
    .data1 115
    .data1 116
    .data1 114
    .data1 116
    .data1 111
    .data1 108
    .data1 32
    .data1 40
    .data1 32
    .data1 98
    .data1 117
    .data1 102
    .data1 112
    .data1 44
    .data1 32
    .data1 38
    .data1 98
    .data1 117
    .data1 102
    .data1 112
    .data1 44
    .data1 32
    .data1 49
    .data1 48
    .data1 32
    .data1 41
    .data1 59
    .data1 32
    .data1 47
    .data1 42
    .data1 32
    .data1 114
    .data1 101
    .data1 97
    .data1 100
    .data1 32
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 32
    .data1 115
    .data1 105
    .data1 122
    .data1 101
    .data1 32
    .data1 102
    .data1 114
    .data1 111
    .data1 109
    .data1 32
    .data1 49
    .data1 115
    .data1 116
    .data1 32
    .data1 115
    .data1 116
    .data1 114
    .data1 105
    .data1 110
    .data1 103
    .data1 46
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 125
    .data1 0
    .data1 35
    .data1 101
    .data1 110
    .data1 100
    .data1 105
    .data1 102
    .data1 32
    .data1 84
    .data1 69
    .data1 83
    .data1 84
    .data1 0
    .data1 32
    .data1 32
    .data1 114
    .data1 101
    .data1 116
    .data1 117
    .data1 114
    .data1 110
    .data1 32
    .data1 40
    .data1 32
    .data1 45
    .data1 45
    .data1 110
    .data1 32
    .data1 62
    .data1 61
    .data1 32
    .data1 48
    .data1 32
    .data1 41
    .data1 32
    .data1 63
    .data1 32
    .data1 40
    .data1 117
    .data1 110
    .data1 115
    .data1 105
    .data1 103
    .data1 110
    .data1 101
    .data1 100
    .data1 32
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 41
    .data1 32
    .data1 42
    .data1 98
    .data1 117
    .data1 102
    .data1 112
    .data1 43
    .data1 43
    .data1 32
    .data1 58
    .data1 32
    .data1 69
    .data1 79
    .data1 70
    .data1 59
    .data1 0
    .data1 125
    .data1 32
    .data1 32
    .data1 0
    .data1 0
    .data1 47
    .data1 42
    .data1 118
    .data1 111
    .data1 105
    .data1 100
    .data1 32
    .data1 112
    .data1 117
    .data1 116
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 32
    .data1 40
    .data1 32
    .data1 99
    .data1 41
    .data1 0
    .data1 32
    .data1 32
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 32
    .data1 99
    .data1 59
    .data1 0
    .data1 123
    .data1 32
    .data1 0
    .data1 32
    .data1 32
    .data1 102
    .data1 112
    .data1 114
    .data1 105
    .data1 110
    .data1 116
    .data1 102
    .data1 40
    .data1 115
    .data1 116
    .data1 100
    .data1 101
    .data1 114
    .data1 114
    .data1 44
    .data1 34
    .data1 112
    .data1 117
    .data1 116
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 58
    .data1 32
    .data1 99
    .data1 32
    .data1 61
    .data1 32
    .data1 37
    .data1 120
    .data1 32
    .data1 92
    .data1 110
    .data1 34
    .data1 44
    .data1 32
    .data1 99
    .data1 41
    .data1 59
    .data1 0
    .data1 32
    .data1 32
    .data1 42
    .data1 111
    .data1 117
    .data1 116
    .data1 98
    .data1 117
    .data1 102
    .data1 43
    .data1 43
    .data1 32
    .data1 61
    .data1 32
    .data1 99
    .data1 59
    .data1 0
    .data1 125
    .data1 0
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 35
    .data1 105
    .data1 102
    .data1 110
    .data1 100
    .data1 101
    .data1 102
    .data1 32
    .data1 83
    .data1 85
    .data1 78
    .data1 0
    .data1 118
    .data1 111
    .data1 105
    .data1 100
    .data1 32
    .data1 101
    .data1 120
    .data1 105
    .data1 116
    .data1 40
    .data1 32
    .data1 120
    .data1 32
    .data1 41
    .data1 0
    .data1 32
    .data1 32
    .data1 105
    .data1 110
    .data1 116
    .data1 32
    .data1 120
    .data1 59
    .data1 0
    .data1 123
    .data1 0
    .data1 32
    .data1 32
    .data1 102
    .data1 112
    .data1 114
    .data1 105
    .data1 110
    .data1 116
    .data1 102
    .data1 32
    .data1 40
    .data1 115
    .data1 116
    .data1 100
    .data1 101
    .data1 114
    .data1 114
    .data1 44
    .data1 32
    .data1 34
    .data1 101
    .data1 120
    .data1 105
    .data1 116
    .data1 40
    .data1 48
    .data1 120
    .data1 37
    .data1 120
    .data1 41
    .data1 92
    .data1 110
    .data1 34
    .data1 44
    .data1 32
    .data1 120
    .data1 41
    .data1 59
    .data1 0
    .data1 35
    .data1 105
    .data1 102
    .data1 100
    .data1 101
    .data1 102
    .data1 32
    .data1 88
    .data1 73
    .data1 78
    .data1 85
    .data1 0
    .data1 32
    .data1 32
    .data1 117
    .data1 115
    .data1 101
    .data1 114
    .data1 114
    .data1 101
    .data1 116
    .data1 40
    .data1 41
    .data1 59
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 47
    .data1 42
    .data1 32
    .data1 77
    .data1 117
    .data1 115
    .data1 116
    .data1 32
    .data1 108
    .data1 105
    .data1 110
    .data1 107
    .data1 32
    .data1 119
    .data1 105
    .data1 116
    .data1 104
    .data1 32
    .data1 88
    .data1 73
    .data1 78
    .data1 85
    .data1 63
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 35
    .data1 101
    .data1 110
    .data1 100
    .data1 105
    .data1 102
    .data1 32
    .data1 47
    .data1 42
    .data1 32
    .data1 88
    .data1 73
    .data1 78
    .data1 85
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 125
    .data1 0
    .data1 32
    .data1 0
    .data1 105
    .data1 110
    .data1 116
    .data1 32
    .data1 112
    .data1 117
    .data1 116
    .data1 99
    .data1 40
    .data1 32
    .data1 100
    .data1 101
    .data1 118
    .data1 44
    .data1 32
    .data1 32
    .data1 99
    .data1 41
    .data1 32
    .data1 32
    .data1 32
    .data1 47
    .data1 42
    .data1 32
    .data1 112
    .data1 117
    .data1 116
    .data1 99
    .data1 32
    .data1 100
    .data1 101
    .data1 102
    .data1 105
    .data1 110
    .data1 101
    .data1 100
    .data1 32
    .data1 98
    .data1 117
    .data1 32
    .data1 88
    .data1 73
    .data1 78
    .data1 85
    .data1 46
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 32
    .data1 32
    .data1 105
    .data1 110
    .data1 116
    .data1 32
    .data1 100
    .data1 101
    .data1 118
    .data1 59
    .data1 0
    .data1 32
    .data1 32
    .data1 99
    .data1 104
    .data1 97
    .data1 114
    .data1 32
    .data1 99
    .data1 59
    .data1 0
    .data1 123
    .data1 0
    .data1 47
    .data1 42
    .data1 32
    .data1 105
    .data1 102
    .data1 32
    .data1 40
    .data1 100
    .data1 101
    .data1 118
    .data1 32
    .data1 61
    .data1 61
    .data1 32
    .data1 67
    .data1 79
    .data1 78
    .data1 83
    .data1 79
    .data1 76
    .data1 69
    .data1 41
    .data1 32
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 125
    .data1 0
    .data1 35
    .data1 101
    .data1 110
    .data1 100
    .data1 105
    .data1 102
    .data1 32
    .data1 47
    .data1 42
    .data1 32
    .data1 83
    .data1 85
    .data1 78
    .data1 32
    .data1 42
    .data1 47
    .data1 0
    .data1 120
    .data1 102
    .data1 102
    .data1 0
    .data1 120
    .data1 102
    .data1 102
    .data1 0
    .data1 120
    .data1 102
    .data1 102
    .data1 0
    .data1 120
    .data1 102
    .data1 102
    .data1 0
    .data1 120
    .data1 102
    .data1 102
    .data1 0
    .data1 120
    .data1 102
    .data1 102
    .data1 0
    .data1 120
    .data1 102
    .data1 102
    .data1 0
    .data1 120
    .data1 102
    .data1 102
    .data1 0
    .data1 0
compress_3906.rcs_ident::
    .data1 72
    .data1 101
    .data1 97
    .data1 100
    .data1 101
    .data1 114
    .data1 58
    .data1 32
    .data1 99
    .data1 111
    .data1 109
    .data1 112
    .data1 114
    .data1 101
    .data1 115
    .data1 115
    .data1 46
    .data1 99
    .data1 44
    .data1 118
    .data1 32
    .data1 0
.skip 2
do_decomp::
    .data4 0
quiet::
    .data4 1
nomagic::
    .data4 0
block_compress::
    .data4 128
zcat_flg::
    .data4 0
maxbits::
    .data4 12
maxmaxcode::
    .data4 4096
hsize::
    .data4 5003
magic_header::
    .data1 31
    .data1 -99
    .data1 0
.skip 1
free_ent::
    .data4 0
checkpoint::
    .data4 10000
in_count::
    .data4 1
ratio::
    .data4 0
clear_flg::
    .data4 0
out_count::
    .data4 0
exit_stat::
    .data4 0
lmask::
    .data1 255
    .data1 254
    .data1 252
    .data1 248
    .data1 240
    .data1 224
    .data1 192
    .data1 128
    .data1 0
.skip 3
rmask::
    .data1 0
    .data1 1
    .data1 3
    .data1 7
    .data1 15
    .data1 31
    .data1 63
    .data1 127
    .data1 255
.skip 3
force::
    .data4 0
.section .data
.comm bytes_out, 0x4, 4
.comm bgnd_flag, 0x4, 4
.comm fsize, 0x4, 4
.comm codetab, 0x2716, 4
.comm htab, 0x4e2c, 4
.comm maxcode, 0x4, 4
.comm n_bits, 0x4, 4
.comm buflen, 0x4, 4
.comm bufp, 0x4, 4
.comm outbuf, 0x4, 4
.comm CompBuf, 0x320, 4
.comm UnComp, 0x348, 4
.section .text
.import _i_div
.type _i_div,@function
.import _bcopy
.type _bcopy,@function
.import prratio
.type prratio,@function
.import cl_block
.type cl_block,@function
.import output
.type output,@function
.import cl_hash
.type cl_hash,@function
.import decompress
.type decompress,@function
.import compressf
.type compressf,@function
.import version
.type version,@function
.import rindex
.type rindex,@function
.import Usage
.type Usage,@function
.import compressgetcode
.type compressgetcode,@function
.import Compress
.type Compress,@function
.import puts
.type puts,@function
