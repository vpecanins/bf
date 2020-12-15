 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/20_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out"
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
	c0    mov $r0.3 = (_?1PACKET.4 + 0)   ## addr(fname.?1AUTOINIT?1.85)(P32)
;;								## 0
	c0    add $r0.2 = $r0.1, 0x10   ## bblock 0, line 12,  t11,  t15,  offset(v?1.85)=0x10(P32)
	c0    add $r0.4 = $r0.1, 0x1c   ## bblock 0, line 13,  t6,  t15,  offset(fname?1.85)=0x1c(P32)
	c0    stw 0x28[$r0.1] = $l0.0  ## spill ## t14
;;								## 1
.call _bcopy, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:s32), ret()
	c0    call $l0.0 = _bcopy   ## bblock 0, line 13,  raddr(_bcopy)(P32),  addr(fname.?1AUTOINIT?1.85)(P32),  t6,  9(SI32)
	c0    stw 0x2c[$r0.1] = $r0.4  ## spill ## t6
	c0    stw 0x30[$r0.1] = $r0.2  ## spill ## t11
;;								## 2
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.0   ## bblock 0, line 17, 0(I32), 0x0(P32)
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    mov $r0.6 = 800   ## 800(SI32)
	c0    mov $r0.5 = (compress_16460.Buf + 0)   ## addr(compress_16460.Buf?1.0)(P32)
	c0    ldw $r0.2 = 0x2c[$r0.1]  ## restore ## t6
	c0    ldw $r0.4 = 0x30[$r0.1]  ## restore ## t11
;;								## 3
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.5   ## bblock 0, line 18, 0(I32), addr(compress_16460.Buf?1.0)(P32)
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.6   ## bblock 0, line 19, 0(I32), 800(SI32)
;;								## 4
.call Compress, caller, arg($r0.3:s32,$r0.4:u32), ret($r0.3:s32)
	c0    stw 0[$r0.4] = $r0.2   ## bblock 0, line 16, t11, t6
	c0    call $l0.0 = Compress   ## bblock 0, line 20,  raddr(Compress)(P32),  1(SI32),  t11
;;								## 5
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 1, line 21,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 6
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x28[$r0.1]  ## restore ## t14
	      xnop 1
;;								## 8
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 2, line 22,  t15,  ?2.1?2auto_size(I32),  t14
;;								## 9
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
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg($r0.3:u32,$r0.4:u32)
rindex::
.trace 3
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    sxtb $r0.4 = $r0.4   ## bblock 0, line 61,  t1(SI8),  t20
	c0    add $r0.10 = $r0.3, 3   ## bblock 0, line 0,  t153,  t170,  3(I32)
	c0    mov $r0.5 = $r0.0   ## bblock 0, line 64,  t23,  0x0(P32)
	c0    add $r0.6 = $r0.3, 1   ## bblock 0, line 0,  t169,  t170,  1(I32)
	c0    add $r0.34 = $r0.3, 15   ## bblock 0, line 0,  t168,  t170,  15(I32)
	c0    add $r0.32 = $r0.3, 14   ## bblock 0, line 0,  t166,  t170,  14(I32)
	c0    add $r0.30 = $r0.3, 13   ## bblock 0, line 0,  t164,  t170,  13(I32)
	c0    add $r0.28 = $r0.3, 12   ## bblock 0, line 0,  t162,  t170,  12(I32)
	c0    add $r0.26 = $r0.3, 11   ## bblock 0, line 0,  t96,  t170,  11(I32)
	c0    add $r0.24 = $r0.3, 10   ## bblock 0, line 0,  t95,  t170,  10(I32)
	c0    add $r0.22 = $r0.3, 9   ## bblock 0, line 0,  t94,  t170,  9(I32)
	c0    add $r0.20 = $r0.3, 8   ## bblock 0, line 0,  t157,  t170,  8(I32)
	c0    add $r0.18 = $r0.3, 7   ## bblock 0, line 0,  t155,  t170,  7(I32)
	c0    add $r0.16 = $r0.3, 6   ## bblock 0, line 0,  t152,  t170,  6(I32)
	c0    add $r0.14 = $r0.3, 5   ## bblock 0, line 0,  t90,  t170,  5(I32)
	c0    add $r0.12 = $r0.3, 4   ## bblock 0, line 0,  t89,  t170,  4(I32)
	c0    add $r0.8 = $r0.3, 2   ## bblock 0, line 0,  t87,  t170,  2(I32)
	c0    mov $r0.2 = $r0.3   ## t170
;;								## 0
	c0    stw 0x0[$r0.1] = $r0.57  ## spill ## t11
	c0    stw 0x4[$r0.1] = $r0.58  ## spill ## t12
	c0    stw 0x8[$r0.1] = $r0.59  ## spill ## t13
	c0    stw 0xc[$r0.1] = $r0.60  ## spill ## t14
	c0    stw 0x10[$r0.1] = $r0.61  ## spill ## t15
	c0    stw 0x14[$r0.1] = $r0.62  ## spill ## t16
	c0    stw 0x18[$r0.1] = $r0.63  ## spill ## t17
;;								## 1
.trace 1
L0?3:
	c0    ldb $r0.3 = 0[$r0.2]   ## bblock 1, line 64, t2(SI8), t170
	c0    ldb.d $r0.7 = 0[$r0.6]   ## [spec] bblock 3, line 64-1, t83(SI8), t169
	c0    ldb.d $r0.9 = 0[$r0.8]   ## [spec] bblock 47, line 64-2, t79(SI8), t87
	c0    ldb.d $r0.11 = 0[$r0.10]   ## [spec] bblock 44, line 64-3, t75(SI8), t153
	c0    ldb.d $r0.13 = 0[$r0.12]   ## [spec] bblock 41, line 64-4, t71(SI8), t89
	c0    ldb.d $r0.15 = 0[$r0.14]   ## [spec] bblock 38, line 64-5, t67(SI8), t90
	c0    ldb.d $r0.17 = 0[$r0.16]   ## [spec] bblock 35, line 64-6, t63(SI8), t152
	c0    ldb.d $r0.19 = 0[$r0.18]   ## [spec] bblock 32, line 64-7, t59(SI8), t155
	c0    ldb.d $r0.21 = 0[$r0.20]   ## [spec] bblock 29, line 64-8, t55(SI8), t157
	c0    ldb.d $r0.23 = 0[$r0.22]   ## [spec] bblock 26, line 64-9, t51(SI8), t94
	c0    ldb.d $r0.25 = 0[$r0.24]   ## [spec] bblock 23, line 64-10, t47(SI8), t95
	c0    ldb.d $r0.27 = 0[$r0.26]   ## [spec] bblock 20, line 64-11, t43(SI8), t96
	c0    ldb.d $r0.29 = 0[$r0.28]   ## [spec] bblock 17, line 64-12, t39(SI8), t162
	c0    ldb.d $r0.31 = 0[$r0.30]   ## [spec] bblock 14, line 64-13, t35(SI8), t164
	c0    ldb.d $r0.33 = 0[$r0.32]   ## [spec] bblock 11, line 64-14, t34(SI8), t166
	c0    ldb.d $r0.35 = 0[$r0.34]   ## [spec] bblock 8, line 64-15, t28(SI8), t168
	c0    add $r0.36 = $r0.6, 16   ## [spec] bblock 5, line 0,  t101,  t169,  16(I32)
	c0    add $r0.37 = $r0.32, 16   ## [spec] bblock 5, line 0,  t99,  t166,  16(I32)
	c0    add $r0.38 = $r0.30, 16   ## [spec] bblock 5, line 0,  t98,  t164,  16(I32)
	c0    add $r0.39 = $r0.28, 16   ## [spec] bblock 5, line 0,  t97,  t162,  16(I32)
;;								## 0
	c0    add $r0.40 = $r0.26, 16   ## [spec] bblock 5, line 0,  t163,  t96,  16(I32)
	c0    add $r0.41 = $r0.24, 16   ## [spec] bblock 5, line 0,  t165,  t95,  16(I32)
	c0    add $r0.42 = $r0.22, 16   ## [spec] bblock 5, line 0,  t167,  t94,  16(I32)
	c0    add $r0.43 = $r0.20, 16   ## [spec] bblock 5, line 0,  t93,  t157,  16(I32)
	c0    add $r0.44 = $r0.18, 16   ## [spec] bblock 5, line 0,  t92,  t155,  16(I32)
	c0    add $r0.45 = $r0.16, 16   ## [spec] bblock 5, line 0,  t91,  t152,  16(I32)
	c0    add $r0.46 = $r0.14, 16   ## [spec] bblock 5, line 0,  t148,  t90,  16(I32)
	c0    add $r0.47 = $r0.12, 16   ## [spec] bblock 5, line 0,  t149,  t89,  16(I32)
	c0    add $r0.48 = $r0.10, 16   ## [spec] bblock 5, line 0,  t88,  t153,  16(I32)
	c0    add $r0.49 = $r0.8, 16   ## [spec] bblock 5, line 0,  t147,  t87,  16(I32)
	c0    add $r0.50 = $r0.34, 16   ## [spec] bblock 5, line 0,  t100,  t168,  16(I32)
	c0    add $r0.51 = $r0.2, 16   ## [spec] bblock 5, line 64-15,  t0,  t170,  16(SI32)
	c0    ldb.d $r0.52 = 0[$r0.36]   ## [spec] bblock 40, line 64-1, t180(SI8), t101
	c0    ldb.d $r0.53 = 0[$r0.39]   ## [spec] bblock 25, line 64-1, t189(SI8), t97
	c0    ldb.d $r0.54 = 0[$r0.38]   ## [spec] bblock 28, line 64-1, t187(SI8), t98
	c0    ldb.d $r0.55 = 0[$r0.37]   ## [spec] bblock 31, line 64-1, t185(SI8), t99
;;								## 1
	c0    cmpne $b0.0 = $r0.3, $r0.0   ## bblock 1, line 64,  t210(I1),  t2(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.3, $r0.4   ## [spec] bblock 3, line 65,  t27(I1),  t2(SI8),  t1(SI8)
	c0    cmpne $b0.2 = $r0.7, $r0.0   ## [spec] bblock 3, line 64-1,  t211(I1),  t83(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.7, $r0.4   ## [spec] bblock 47, line 65-1,  t84(I1),  t83(SI8),  t1(SI8)
	c0    cmpne $b0.4 = $r0.9, $r0.0   ## [spec] bblock 47, line 64-2,  t239(I1),  t79(SI8),  0(SI32)
	c0    cmpeq $b0.5 = $r0.9, $r0.4   ## [spec] bblock 44, line 65-2,  t80(I1),  t79(SI8),  t1(SI8)
	c0    cmpne $b0.6 = $r0.11, $r0.0   ## [spec] bblock 44, line 64-3,  t237(I1),  t75(SI8),  0(SI32)
	c0    cmpeq $b0.7 = $r0.11, $r0.4   ## [spec] bblock 41, line 65-3,  t76(I1),  t75(SI8),  t1(SI8)
	c0    ldb.d $r0.3 = 0[$r0.51]   ## [spec] bblock 5, line 64-1, t171(SI8), t0
	c0    ldb.d $r0.7 = 0[$r0.49]   ## [spec] bblock 51, line 64-1, t209(SI8), t147
	c0    ldb.d $r0.9 = 0[$r0.48]   ## [spec] bblock 50, line 64-1, t207(SI8), t88
	c0    ldb.d $r0.11 = 0[$r0.47]   ## [spec] bblock 46, line 64-1, t205(SI8), t149
	c0    ldb.d $r0.56 = 0[$r0.46]   ## [spec] bblock 4, line 64-1, t203(SI8), t148
	c0    ldb.d $r0.57 = 0[$r0.45]   ## [spec] bblock 7, line 64-1, t201(SI8), t91
	c0    ldb.d $r0.58 = 0[$r0.44]   ## [spec] bblock 10, line 64-1, t199(SI8), t92
	c0    ldb.d $r0.59 = 0[$r0.43]   ## [spec] bblock 13, line 64-1, t197(SI8), t93
	c0    ldb.d $r0.60 = 0[$r0.42]   ## [spec] bblock 16, line 64-1, t195(SI8), t167
	c0    ldb.d $r0.61 = 0[$r0.41]   ## [spec] bblock 19, line 64-1, t193(SI8), t165
	c0    ldb.d $r0.62 = 0[$r0.40]   ## [spec] bblock 22, line 64-1, t191(SI8), t163
	c0    ldb.d $r0.63 = 0[$r0.50]   ## [spec] bblock 34, line 64-1, t183(SI8), t100
;;								## 2
	c0    slct $r0.2 = $b0.1, $r0.2, $r0.5   ## [spec] bblock 3, line 66,  t30,  t27(I1),  t170,  t23
	c0    cmpne $b0.0 = $r0.13, $r0.0   ## [spec] bblock 41, line 64-4,  t236(I1),  t71(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.13, $r0.4   ## [spec] bblock 38, line 65-4,  t72(I1),  t71(SI8),  t1(SI8)
	c0    brf $b0.0, L1?3   ## bblock 1, line 64,  t210(I1)
;;								## 3
	c0    slct $r0.6 = $b0.3, $r0.6, $r0.2   ## [spec] bblock 47, line 66-1,  t85,  t84(I1),  t169,  t30
	c0    cmpne $b0.2 = $r0.15, $r0.0   ## [spec] bblock 38, line 64-5,  t234(I1),  t67(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.15, $r0.4   ## [spec] bblock 35, line 65-5,  t68(I1),  t67(SI8),  t1(SI8)
	c0    brf $b0.2, L2?3   ## bblock 3, line 64-1,  t211(I1)
;;								## 4
	c0    slct $r0.8 = $b0.5, $r0.8, $r0.6   ## [spec] bblock 44, line 66-2,  t81,  t80(I1),  t87,  t85
	c0    cmpne $b0.4 = $r0.17, $r0.0   ## [spec] bblock 35, line 64-6,  t233(I1),  t63(SI8),  0(SI32)
	c0    cmpeq $b0.5 = $r0.17, $r0.4   ## [spec] bblock 32, line 65-6,  t64(I1),  t63(SI8),  t1(SI8)
	c0    add $r0.2 = $r0.51, 16   ## [spec] bblock 37, line 64-1,  t170,  t0,  16(SI32)
	c0    brf $b0.4, L3?3   ## bblock 47, line 64-2,  t239(I1)
;;								## 5
	c0    slct $r0.10 = $b0.7, $r0.10, $r0.8   ## [spec] bblock 41, line 66-3,  t77,  t76(I1),  t153,  t81
	c0    cmpne $b0.6 = $r0.19, $r0.0   ## [spec] bblock 32, line 64-7,  t231(I1),  t59(SI8),  0(SI32)
	c0    cmpeq $b0.7 = $r0.19, $r0.4   ## [spec] bblock 29, line 65-7,  t60(I1),  t59(SI8),  t1(SI8)
	c0    add $r0.6 = $r0.36, 16   ## [spec] bblock 37, line 0-1,  t169,  t101,  16(I32)
	c0    brf $b0.6, L4?3   ## bblock 44, line 64-3,  t237(I1)
;;								## 6
	c0    slct $r0.12 = $b0.1, $r0.12, $r0.10   ## [spec] bblock 38, line 66-4,  t73,  t72(I1),  t89,  t77
	c0    cmpne $b0.0 = $r0.21, $r0.0   ## [spec] bblock 29, line 64-8,  t229(I1),  t55(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.21, $r0.4   ## [spec] bblock 26, line 65-8,  t56(I1),  t55(SI8),  t1(SI8)
	c0    add $r0.8 = $r0.49, 16   ## [spec] bblock 37, line 0-1,  t87,  t147,  16(I32)
	c0    brf $b0.0, L5?3   ## bblock 41, line 64-4,  t236(I1)
;;								## 7
	c0    slct $r0.14 = $b0.3, $r0.14, $r0.12   ## [spec] bblock 35, line 66-5,  t69,  t68(I1),  t90,  t73
	c0    cmpne $b0.2 = $r0.23, $r0.0   ## [spec] bblock 26, line 64-9,  t227(I1),  t51(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.23, $r0.4   ## [spec] bblock 23, line 65-9,  t52(I1),  t51(SI8),  t1(SI8)
	c0    add $r0.10 = $r0.48, 16   ## [spec] bblock 37, line 0-1,  t153,  t88,  16(I32)
	c0    brf $b0.2, L6?3   ## bblock 38, line 64-5,  t234(I1)
;;								## 8
	c0    slct $r0.16 = $b0.5, $r0.16, $r0.14   ## [spec] bblock 32, line 66-6,  t65,  t64(I1),  t152,  t69
	c0    cmpne $b0.4 = $r0.25, $r0.0   ## [spec] bblock 23, line 64-10,  t225(I1),  t47(SI8),  0(SI32)
	c0    cmpeq $b0.5 = $r0.25, $r0.4   ## [spec] bblock 20, line 65-10,  t48(I1),  t47(SI8),  t1(SI8)
	c0    add $r0.12 = $r0.47, 16   ## [spec] bblock 37, line 0-1,  t89,  t149,  16(I32)
	c0    brf $b0.4, L7?3   ## bblock 35, line 64-6,  t233(I1)
;;								## 9
	c0    slct $r0.18 = $b0.7, $r0.18, $r0.16   ## [spec] bblock 29, line 66-7,  t61,  t60(I1),  t155,  t65
	c0    cmpne $b0.6 = $r0.27, $r0.0   ## [spec] bblock 20, line 64-11,  t223(I1),  t43(SI8),  0(SI32)
	c0    cmpeq $b0.7 = $r0.27, $r0.4   ## [spec] bblock 17, line 65-11,  t44(I1),  t43(SI8),  t1(SI8)
	c0    add $r0.14 = $r0.46, 16   ## [spec] bblock 37, line 0-1,  t90,  t148,  16(I32)
	c0    brf $b0.6, L8?3   ## bblock 32, line 64-7,  t231(I1)
;;								## 10
	c0    slct $r0.20 = $b0.1, $r0.20, $r0.18   ## [spec] bblock 26, line 66-8,  t57,  t56(I1),  t157,  t61
	c0    cmpne $b0.0 = $r0.29, $r0.0   ## [spec] bblock 17, line 64-12,  t221(I1),  t39(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.29, $r0.4   ## [spec] bblock 14, line 65-12,  t40(I1),  t39(SI8),  t1(SI8)
	c0    add $r0.16 = $r0.45, 16   ## [spec] bblock 37, line 0-1,  t152,  t91,  16(I32)
	c0    brf $b0.0, L9?3   ## bblock 29, line 64-8,  t229(I1)
;;								## 11
	c0    slct $r0.22 = $b0.3, $r0.22, $r0.20   ## [spec] bblock 23, line 66-9,  t53,  t52(I1),  t94,  t57
	c0    cmpne $b0.2 = $r0.31, $r0.0   ## [spec] bblock 14, line 64-13,  t219(I1),  t35(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.31, $r0.4   ## [spec] bblock 11, line 65-13,  t36(I1),  t35(SI8),  t1(SI8)
	c0    add $r0.18 = $r0.44, 16   ## [spec] bblock 37, line 0-1,  t155,  t92,  16(I32)
	c0    brf $b0.2, L10?3   ## bblock 26, line 64-9,  t227(I1)
;;								## 12
	c0    slct $r0.24 = $b0.5, $r0.24, $r0.22   ## [spec] bblock 20, line 66-10,  t49,  t48(I1),  t95,  t53
	c0    cmpne $b0.4 = $r0.33, $r0.0   ## [spec] bblock 11, line 64-14,  t217(I1),  t34(SI8),  0(SI32)
	c0    cmpeq $b0.5 = $r0.33, $r0.4   ## [spec] bblock 8, line 65-14,  t32(I1),  t34(SI8),  t1(SI8)
	c0    add $r0.20 = $r0.43, 16   ## [spec] bblock 37, line 0-1,  t157,  t93,  16(I32)
	c0    brf $b0.4, L11?3   ## bblock 23, line 64-10,  t225(I1)
;;								## 13
	c0    slct $r0.26 = $b0.7, $r0.26, $r0.24   ## [spec] bblock 17, line 66-11,  t45,  t44(I1),  t96,  t49
	c0    cmpne $b0.6 = $r0.35, $r0.0   ## [spec] bblock 8, line 64-15,  t215(I1),  t28(SI8),  0(SI32)
	c0    cmpeq $b0.7 = $r0.35, $r0.4   ## [spec] bblock 5, line 65-15,  t24(I1),  t28(SI8),  t1(SI8)
	c0    add $r0.22 = $r0.42, 16   ## [spec] bblock 37, line 0-1,  t94,  t167,  16(I32)
	c0    brf $b0.6, L12?3   ## bblock 20, line 64-11,  t223(I1)
;;								## 14
	c0    slct $r0.28 = $b0.1, $r0.28, $r0.26   ## [spec] bblock 14, line 66-12,  t41,  t40(I1),  t162,  t45
	c0    cmpne $b0.0 = $r0.3, $r0.0   ## [spec] bblock 5, line 64-1,  t213(I1),  t171(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.3, $r0.4   ## [spec] bblock 40, line 65-1,  t179(I1),  t171(SI8),  t1(SI8)
	c0    add $r0.24 = $r0.41, 16   ## [spec] bblock 37, line 0-1,  t95,  t165,  16(I32)
	c0    brf $b0.0, L13?3   ## bblock 17, line 64-12,  t221(I1)
;;								## 15
	c0    slct $r0.30 = $b0.3, $r0.30, $r0.28   ## [spec] bblock 11, line 66-13,  t37,  t36(I1),  t164,  t41
	c0    cmpne $b0.2 = $r0.52, $r0.0   ## [spec] bblock 40, line 64-1,  t235(I1),  t180(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.52, $r0.4   ## [spec] bblock 51, line 65-1,  t208(I1),  t180(SI8),  t1(SI8)
	c0    add $r0.26 = $r0.40, 16   ## [spec] bblock 37, line 0-1,  t96,  t163,  16(I32)
	c0    brf $b0.2, L14?3   ## bblock 14, line 64-13,  t219(I1)
;;								## 16
	c0    slct $r0.32 = $b0.5, $r0.32, $r0.30   ## [spec] bblock 8, line 66-14,  t33,  t32(I1),  t166,  t37
	c0    cmpne $b0.4 = $r0.7, $r0.0   ## [spec] bblock 51, line 64-1,  t241(I1),  t209(SI8),  0(SI32)
	c0    cmpeq $b0.5 = $r0.7, $r0.4   ## [spec] bblock 50, line 65-1,  t206(I1),  t209(SI8),  t1(SI8)
	c0    add $r0.28 = $r0.39, 16   ## [spec] bblock 37, line 0-1,  t162,  t97,  16(I32)
	c0    brf $b0.4, L15?3   ## bblock 11, line 64-14,  t217(I1)
;;								## 17
	c0    slct $r0.5 = $b0.7, $r0.34, $r0.32   ## [spec] bblock 5, line 66-15,  t23,  t24(I1),  t168,  t33
	c0    cmpne $b0.6 = $r0.9, $r0.0   ## [spec] bblock 50, line 64-1,  t240(I1),  t207(SI8),  0(SI32)
	c0    cmpeq $b0.7 = $r0.9, $r0.4   ## [spec] bblock 46, line 65-1,  t204(I1),  t207(SI8),  t1(SI8)
	c0    add $r0.30 = $r0.38, 16   ## [spec] bblock 37, line 0-1,  t164,  t98,  16(I32)
	c0    add $r0.34 = $r0.50, 16   ## [spec] bblock 37, line 0-1,  t168,  t100,  16(I32)
	c0    brf $b0.6, L16?3   ## bblock 8, line 64-15,  t215(I1)
;;								## 18
	c0    slct $r0.51 = $b0.1, $r0.51, $r0.5   ## [spec] bblock 40, line 66-1,  t30,  t179(I1),  t0,  t23
	c0    cmpne $b0.0 = $r0.11, $r0.0   ## [spec] bblock 46, line 64-1,  t238(I1),  t205(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.11, $r0.4   ## [spec] bblock 4, line 65-1,  t202(I1),  t205(SI8),  t1(SI8)
	c0    add $r0.32 = $r0.37, 16   ## [spec] bblock 37, line 0-1,  t166,  t99,  16(I32)
	c0    brf $b0.0, L1?3   ## bblock 5, line 64-1,  t213(I1)
;;								## 19
	c0    slct $r0.36 = $b0.3, $r0.36, $r0.51   ## [spec] bblock 51, line 66-1,  t85,  t208(I1),  t101,  t30
	c0    cmpne $b0.2 = $r0.56, $r0.0   ## [spec] bblock 4, line 64-1,  t212(I1),  t203(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.56, $r0.4   ## [spec] bblock 7, line 65-1,  t200(I1),  t203(SI8),  t1(SI8)
	c0    brf $b0.2, L17?3   ## bblock 40, line 64-1,  t235(I1)
;;								## 20
	c0    slct $r0.49 = $b0.5, $r0.49, $r0.36   ## [spec] bblock 50, line 66-1,  t81,  t206(I1),  t147,  t85
	c0    cmpne $b0.4 = $r0.57, $r0.0   ## [spec] bblock 7, line 64-1,  t214(I1),  t201(SI8),  0(SI32)
	c0    cmpeq $b0.5 = $r0.57, $r0.4   ## [spec] bblock 10, line 65-1,  t198(I1),  t201(SI8),  t1(SI8)
	c0    brf $b0.4, L18?3   ## bblock 51, line 64-1,  t241(I1)
;;								## 21
	c0    slct $r0.48 = $b0.7, $r0.48, $r0.49   ## [spec] bblock 46, line 66-1,  t77,  t204(I1),  t88,  t81
	c0    cmpne $b0.6 = $r0.58, $r0.0   ## [spec] bblock 10, line 64-1,  t216(I1),  t199(SI8),  0(SI32)
	c0    cmpeq $b0.7 = $r0.58, $r0.4   ## [spec] bblock 13, line 65-1,  t196(I1),  t199(SI8),  t1(SI8)
	c0    brf $b0.6, L19?3   ## bblock 50, line 64-1,  t240(I1)
;;								## 22
	c0    slct $r0.47 = $b0.1, $r0.47, $r0.48   ## [spec] bblock 4, line 66-1,  t73,  t202(I1),  t149,  t77
	c0    cmpne $b0.0 = $r0.59, $r0.0   ## [spec] bblock 13, line 64-1,  t218(I1),  t197(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.59, $r0.4   ## [spec] bblock 16, line 65-1,  t194(I1),  t197(SI8),  t1(SI8)
	c0    brf $b0.0, L20?3   ## bblock 46, line 64-1,  t238(I1)
;;								## 23
	c0    slct $r0.46 = $b0.3, $r0.46, $r0.47   ## [spec] bblock 7, line 66-1,  t69,  t200(I1),  t148,  t73
	c0    cmpne $b0.2 = $r0.60, $r0.0   ## [spec] bblock 16, line 64-1,  t220(I1),  t195(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.60, $r0.4   ## [spec] bblock 19, line 65-1,  t192(I1),  t195(SI8),  t1(SI8)
	c0    brf $b0.2, L21?3   ## bblock 4, line 64-1,  t212(I1)
;;								## 24
	c0    slct $r0.45 = $b0.5, $r0.45, $r0.46   ## [spec] bblock 10, line 66-1,  t65,  t198(I1),  t91,  t69
	c0    cmpne $b0.4 = $r0.61, $r0.0   ## [spec] bblock 19, line 64-1,  t222(I1),  t193(SI8),  0(SI32)
	c0    cmpeq $b0.5 = $r0.61, $r0.4   ## [spec] bblock 22, line 65-1,  t190(I1),  t193(SI8),  t1(SI8)
	c0    brf $b0.4, L22?3   ## bblock 7, line 64-1,  t214(I1)
;;								## 25
	c0    slct $r0.44 = $b0.7, $r0.44, $r0.45   ## [spec] bblock 13, line 66-1,  t61,  t196(I1),  t92,  t65
	c0    cmpne $b0.6 = $r0.62, $r0.0   ## [spec] bblock 22, line 64-1,  t224(I1),  t191(SI8),  0(SI32)
	c0    cmpeq $b0.7 = $r0.62, $r0.4   ## [spec] bblock 25, line 65-1,  t188(I1),  t191(SI8),  t1(SI8)
	c0    brf $b0.6, L23?3   ## bblock 10, line 64-1,  t216(I1)
;;								## 26
	c0    slct $r0.43 = $b0.1, $r0.43, $r0.44   ## [spec] bblock 16, line 66-1,  t57,  t194(I1),  t93,  t61
	c0    cmpne $b0.0 = $r0.53, $r0.0   ## [spec] bblock 25, line 64-1,  t226(I1),  t189(SI8),  0(SI32)
	c0    cmpeq $b0.1 = $r0.53, $r0.4   ## [spec] bblock 28, line 65-1,  t186(I1),  t189(SI8),  t1(SI8)
	c0    brf $b0.0, L24?3   ## bblock 13, line 64-1,  t218(I1)
;;								## 27
	c0    slct $r0.42 = $b0.3, $r0.42, $r0.43   ## [spec] bblock 19, line 66-1,  t53,  t192(I1),  t167,  t57
	c0    cmpne $b0.2 = $r0.54, $r0.0   ## [spec] bblock 28, line 64-1,  t228(I1),  t187(SI8),  0(SI32)
	c0    cmpeq $b0.3 = $r0.54, $r0.4   ## [spec] bblock 31, line 65-1,  t184(I1),  t187(SI8),  t1(SI8)
	c0    brf $b0.2, L25?3   ## bblock 16, line 64-1,  t220(I1)
;;								## 28
	c0    slct $r0.41 = $b0.5, $r0.41, $r0.42   ## [spec] bblock 22, line 66-1,  t49,  t190(I1),  t165,  t53
	c0    cmpne $b0.4 = $r0.55, $r0.0   ## [spec] bblock 31, line 64-1,  t230(I1),  t185(SI8),  0(SI32)
	c0    cmpeq $b0.5 = $r0.55, $r0.4   ## [spec] bblock 34, line 65-1,  t182(I1),  t185(SI8),  t1(SI8)
	c0    brf $b0.4, L26?3   ## bblock 19, line 64-1,  t222(I1)
;;								## 29
	c0    slct $r0.40 = $b0.7, $r0.40, $r0.41   ## [spec] bblock 25, line 66-1,  t45,  t188(I1),  t163,  t49
	c0    cmpne $b0.6 = $r0.63, $r0.0   ## [spec] bblock 34, line 64-1,  t232(I1),  t183(SI8),  0(SI32)
	c0    cmpeq $b0.7 = $r0.63, $r0.4   ## [spec] bblock 37, line 65-1,  t181(I1),  t183(SI8),  t1(SI8)
	c0    brf $b0.6, L27?3   ## bblock 22, line 64-1,  t224(I1)
;;								## 30
	c0    slct $r0.39 = $b0.1, $r0.39, $r0.40   ## [spec] bblock 28, line 66-1,  t41,  t186(I1),  t97,  t45
	c0    brf $b0.0, L28?3   ## bblock 25, line 64-1,  t226(I1)
;;								## 31
	c0    slct $r0.38 = $b0.3, $r0.38, $r0.39   ## [spec] bblock 31, line 66-1,  t37,  t184(I1),  t98,  t41
	c0    brf $b0.2, L29?3   ## bblock 28, line 64-1,  t228(I1)
;;								## 32
	c0    slct $r0.37 = $b0.5, $r0.37, $r0.38   ## [spec] bblock 34, line 66-1,  t33,  t182(I1),  t99,  t37
	c0    brf $b0.4, L30?3   ## bblock 31, line 64-1,  t230(I1)
;;								## 33
	c0    slct $r0.5 = $b0.7, $r0.50, $r0.37   ## [spec] bblock 37, line 66-1,  t23,  t181(I1),  t100,  t33
	c0    brf $b0.6, L31?3   ## bblock 34, line 64-1,  t232(I1)
	      ## goto
;;
	c0    goto L0?3 ## goto
;;								## 34
.trace 35
L31?3:
	c0    mov $r0.32 = $r0.37   ## t33
;;								## 0
.trace 19
L16?3:
	c0    mov $r0.3 = $r0.32   ## bblock 6, line 0,  t29,  t33
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 34
L30?3:
	c0    mov $r0.30 = $r0.38   ## t37
;;								## 0
.trace 18
L15?3:
	c0    mov $r0.3 = $r0.30   ## bblock 9, line 0,  t29,  t37
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 33
L29?3:
	c0    mov $r0.28 = $r0.39   ## t41
;;								## 0
.trace 17
L14?3:
	c0    mov $r0.3 = $r0.28   ## bblock 12, line 0,  t29,  t41
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 32
L28?3:
	c0    mov $r0.26 = $r0.40   ## t45
;;								## 0
.trace 16
L13?3:
	c0    mov $r0.3 = $r0.26   ## bblock 15, line 0,  t29,  t45
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 31
L27?3:
	c0    mov $r0.24 = $r0.41   ## t49
;;								## 0
.trace 15
L12?3:
	c0    mov $r0.3 = $r0.24   ## bblock 18, line 0,  t29,  t49
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 30
L26?3:
	c0    mov $r0.22 = $r0.42   ## t53
;;								## 0
.trace 14
L11?3:
	c0    mov $r0.3 = $r0.22   ## bblock 21, line 0,  t29,  t53
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 29
L25?3:
	c0    mov $r0.20 = $r0.43   ## t57
;;								## 0
.trace 13
L10?3:
	c0    mov $r0.3 = $r0.20   ## bblock 24, line 0,  t29,  t57
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 28
L24?3:
	c0    mov $r0.18 = $r0.44   ## t61
;;								## 0
.trace 12
L9?3:
	c0    mov $r0.3 = $r0.18   ## bblock 27, line 0,  t29,  t61
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 27
L23?3:
	c0    mov $r0.16 = $r0.45   ## t65
;;								## 0
.trace 11
L8?3:
	c0    mov $r0.3 = $r0.16   ## bblock 30, line 0,  t29,  t65
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 26
L22?3:
	c0    mov $r0.14 = $r0.46   ## t69
;;								## 0
.trace 10
L7?3:
	c0    mov $r0.3 = $r0.14   ## bblock 33, line 0,  t29,  t69
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 25
L21?3:
	c0    mov $r0.12 = $r0.47   ## t73
;;								## 0
.trace 9
L6?3:
	c0    mov $r0.3 = $r0.12   ## bblock 36, line 0,  t29,  t73
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 24
L20?3:
	c0    mov $r0.10 = $r0.48   ## t77
;;								## 0
.trace 8
L5?3:
	c0    mov $r0.3 = $r0.10   ## bblock 39, line 0,  t29,  t77
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 23
L19?3:
	c0    mov $r0.8 = $r0.49   ## t81
;;								## 0
.trace 7
L4?3:
	c0    mov $r0.3 = $r0.8   ## bblock 42, line 0,  t29,  t81
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 22
L18?3:
	c0    mov $r0.6 = $r0.36   ## t85
;;								## 0
.trace 6
L3?3:
	c0    mov $r0.3 = $r0.6   ## bblock 45, line 0,  t29,  t85
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 21
L17?3:
	c0    mov $r0.2 = $r0.51   ## t30
;;								## 0
.trace 5
L2?3:
	c0    mov $r0.3 = $r0.2   ## bblock 48, line 0,  t29,  t30
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
	c0    goto L32?3 ## goto
;;								## 0
.trace 4
L1?3:
	c0    mov $r0.3 = $r0.5   ## bblock 49, line 0,  t29,  t23
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t17
	c0    ldw $r0.62 = 0x14[$r0.1]  ## restore ## t16
	c0    ldw $r0.61 = 0x10[$r0.1]  ## restore ## t15
	c0    ldw $r0.60 = 0xc[$r0.1]  ## restore ## t14
	c0    ldw $r0.59 = 0x8[$r0.1]  ## restore ## t13
	c0    ldw $r0.58 = 0x4[$r0.1]  ## restore ## t12
	c0    ldw $r0.57 = 0x0[$r0.1]  ## restore ## t11
;;								## 0
L32?3:
.return ret($r0.3:u32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 2, line 67,  t8,  ?2.3?2auto_size(I32),  t7
;;								## 1
.endp
.section .bss
.section .data
.equ ?2.3?2spill_p, 0x0
.section .data
.section .text
.equ ?2.3?2auto_size, 0x20
 ## End rindex
.equ _?1TEMPLATEPACKET.1, 0x0
 ## Begin Compress
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:s32,$r0.4:u32)
Compress::
.trace 19
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    stw ((do_decomp + 0) + 0)[$r0.0] = $r0.0   ## bblock 0, line 77, 0(I32), 0(SI32)
	c0    ldw $r0.7 = ((buflen + 0) + 0)[$r0.0]   ## bblock 0, line 82, t123, 0(I32)
	c0    mov $r0.5 = (CompBuf + 0)   ## addr(CompBuf?1.0)(P32)
;;								## 0
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.5   ## bblock 0, line 80, 0(I32), addr(CompBuf?1.0)(P32)
	c0    stw 0x20[$r0.1] = $r0.3  ## spill ## t0
	c0    stw 0x24[$r0.1] = $r0.4  ## spill ## t121
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t107
;;								## 1
	c0    ldw $r0.3 = 0[$r0.4]   ## bblock 0, line 83, t10, t121
	c0    mov $r0.4 = 47   ## 47(SI32)
	c0    stw 0x1c[$r0.1] = $r0.7  ## spill ## t123
;;								## 2
.call rindex, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:u32)
	c0    call $l0.0 = rindex   ## bblock 0, line 83,  raddr(rindex)(P32),  t10,  47(SI32)
;;								## 3
	c0    ldw $r0.3 = 0x20[$r0.1]  ## restore ## t0
	c0    ldw $r0.4 = 0x24[$r0.1]  ## restore ## t121
	      xnop 1
;;								## 5
	c0    add $r0.2 = $r0.4, 4   ## bblock 3, line 89,  t127,  t121,  4(SI32)
	c0    add $r0.6 = $r0.3, -1   ## bblock 3, line 89,  t128,  t0,  -1(SI32)
;;								## 6
.trace 3
L33?3:
	c0    cmpgt $b0.0 = $r0.6, $r0.0   ## bblock 4, line 89,  t129(I1),  t128,  0(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 39, line 91, t25, t127
;;								## 0
	c0    brf $b0.0, L34?3   ## bblock 4, line 89,  t129(I1)
;;								## 1
	c0    ldb $r0.3 = 0[$r0.3]   ## bblock 39, line 91, t26(SI8), t25
	      xnop 1
;;								## 3
	c0    cmpeq $b0.0 = $r0.3, 45   ## bblock 39, line 91,  t144(I1),  t26(SI8),  45(SI32)
;;								## 4
	c0    brf $b0.0, L35?3   ## bblock 39, line 91,  t144(I1)
;;								## 5
.trace 1
L36?3:
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
	c0    sh2add $r0.3 = $r0.3, ((_?1.Compress.TAGPACKET.0 + 0) - 268)   ## [spec] bblock 43, line 130,  t147,  t30(SI8),  (addr(_?1.Compress.TAGARRAY.0)(P32) - 0x10c(I32))(P32)
;;								## 6
	c0    orl $b0.0 = $r0.4, $r0.5   ## [spec] bblock 42, line 130,  t146(I1),  t47,  t48
	c0    ldw.d $l0.0 = 0[$r0.3]   ## [spec] bblock 43, line 130, t50, t147
	c0    brf $b0.0, L37?3   ## bblock 41, line 93,  t145(I1)
;;								## 7
	c0    br $b0.0, L38?3   ## bblock 42, line 130,  t146(I1)
;;								## 8
;;								## 9
	c0    goto $l0.0   ## bblock 43, line 130,  t50
;;								## 10
_?1.Compress.TAG.0.0:
	c0    stw ((block_compress + 0) + 0)[$r0.0] = $r0.0   ## bblock 64, line 110, 0(I32), 0(SI32)
	c0    goto L36?3 ## goto
;;								## 11
.trace 9
_?1.Compress.TAG.0.7:
	c0    stw ((quiet + 0) + 0)[$r0.0] = $r0.0   ## bblock 45, line 101, 0(I32), 0(SI32)
	c0    goto L36?3 ## goto
;;								## 0
.trace 5
_?1.Compress.TAG.0.6:
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((quiet + 0) + 0)[$r0.0] = $r0.3   ## bblock 47, line 124, 0(I32), 1(SI32)
	c0    goto L36?3 ## goto
;;								## 1
.trace 6
_?1.Compress.TAG.0.5:
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((nomagic + 0) + 0)[$r0.0] = $r0.3   ## bblock 49, line 107, 0(I32), 1(SI32)
	c0    goto L36?3 ## goto
;;								## 1
.trace 7
_?1.Compress.TAG.0.4:
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((do_decomp + 0) + 0)[$r0.0] = $r0.3   ## bblock 51, line 104, 0(I32), 1(SI32)
	c0    goto L36?3 ## goto
;;								## 1
.trace 8
_?1.Compress.TAG.0.3:
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
	c0    stw ((zcat_flg + 0) + 0)[$r0.0] = $r0.3   ## bblock 53, line 121, 0(I32), 1(SI32)
	c0    goto L36?3 ## goto
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
	c0    br $b0.0, L39?3   ## bblock 55, line 113,  t148(I1)
;;								## 7
L35?3:
	c0    add $r0.2 = $r0.2, 4   ## bblock 40, line 89,  t127,  t127,  4(SI32)
	c0    add $r0.6 = $r0.6, -1   ## bblock 40, line 89,  t128,  t128,  -1(SI32)
	c0    goto L33?3 ## goto
;;								## 8
.trace 13
L39?3:
	c0    add $r0.6 = $r0.6, -1   ## bblock 56, line 113,  t128,  t128,  -1(SI32)
	c0    ldw.d $r0.3 = 4[$r0.2]   ## [spec] bblock 57, line 113, t42, t127
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 57, line 113,  t127,  t127,  4(SI32)
;;								## 0
	c0    cmpeq $b0.0 = $r0.6, $r0.0   ## bblock 56, line 113,  t149(I1),  t128,  0(SI32)
;;								## 1
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## [spec] bblock 57, line 113,  t150(I1),  t42,  0x0(P32)
	c0    br $b0.0, L40?3   ## bblock 56, line 113,  t149(I1)
;;								## 2
	c0    br $b0.0, L40?3   ## bblock 57, line 113,  t150(I1)
	      ## goto
;;
	c0    goto L35?3 ## goto
;;								## 3
.trace 18
L40?3:
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
	c0    goto L36?3 ## goto
;;								## 2
.trace 4
L38?3:
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
.trace 15
L37?3:
	c0    goto L35?3 ## goto
;;								## 0
.trace 21
L34?3:
	c0    ldw $r0.2 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 5, line 135, t51, 0(I32)
	c0    ldw.d $r0.8 = ((fsize + 0) + 0)[$r0.0]   ## [spec] bblock 7, line 141, t55, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    mov $r0.5 = 12   ## 12(SI32)
	c0    mov $r0.4 = 9   ## 9(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 9   ## bblock 5, line 135,  t130(I1),  t51,  9(SI32)
	c0    cmplt $b0.1 = $r0.8, 4096   ## [spec] bblock 7, line 141,  t132(I1),  t55,  4096(SI32)
;;								## 2
	c0    brf $b0.0, L41?3   ## bblock 5, line 135,  t130(I1)
;;								## 3
	c0    stw ((maxbits + 0) + 0)[$r0.0] = $r0.4   ## bblock 38, line 136, 0(I32), 9(SI32)
;;								## 4
L42?3:
	c0    ldw $r0.2 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 6, line 137, t52, 0(I32)
	      xnop 1
;;								## 6
	c0    cmpgt $b0.0 = $r0.2, 12   ## bblock 6, line 137,  t131(I1),  t52,  12(SI32)
;;								## 7
	c0    brf $b0.0, L43?3   ## bblock 6, line 137,  t131(I1)
;;								## 8
	c0    stw ((maxbits + 0) + 0)[$r0.0] = $r0.5   ## bblock 37, line 138, 0(I32), 12(SI32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 7, line 140, 0(I32), 5003(SI32)
;;								## 9
L44?3:
	c0    ldw $r0.2 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 7, line 139, t53, 0(I32)
	      xnop 1
;;								## 11
	c0    shl $r0.3 = $r0.3, $r0.2   ## bblock 7, line 139,  t54,  1(SI32),  t53
;;								## 12
	c0    stw ((maxmaxcode + 0) + 0)[$r0.0] = $r0.3   ## bblock 7, line 139, 0(I32), t54
	c0    brf $b0.1, L45?3   ## bblock 7, line 141,  t132(I1)
;;								## 13
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 36, line 142, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 14
L46?3:
	c0    ldw $r0.2 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 13, line 153, t62, 0(I32)
	c0    ldw $r0.6 = ((nomagic + 0) + 0)[$r0.0]   ## bblock 13, line 156, t66, 0(I32)
	c0    ldb.d $r0.9 = ((CompBuf + 0) + 0)[$r0.0]   ## [spec] bblock 31, line 158, t72(SI8), 0(I32)
	c0    ldbu.d $r0.10 = ((magic_header + 0) + 0)[$r0.0]   ## [spec] bblock 18, line 158, t75(I8), 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
	c0    mov $r0.8 = ((CompBuf + 0) + 1)   ## (addr(CompBuf?1.0)(P32) + 0x1(I32))(P32)
	c0    mov $r0.4 = (UnComp + 0)   ## addr(UnComp?1.0)(P32)
	c0    mov $r0.5 = (CompBuf + 0)   ## addr(CompBuf?1.0)(P32)
;;								## 15
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.5   ## bblock 13, line 152, 0(I32), addr(CompBuf?1.0)(P32)
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 13, line 154, 0(I32), addr(UnComp?1.0)(P32)
;;								## 16
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 13, line 153, 0(I32), t62
	c0    cmpeq $b0.0 = $r0.6, $r0.0   ## bblock 13, line 156,  t137(I1),  t66,  0(SI32)
	c0    add $r0.4 = $r0.2, -1   ## [spec] bblock 16, line 159,  t69,  t62,  -1(SI32)
	c0    zxtb $r0.9 = $r0.9   ## [spec] bblock 31, line 158,  t67(I8),  t72(SI8)
	c0    and $r0.10 = $r0.10, 255   ## [spec] bblock 18, line 158,  t76,  t75(I8),  255(I32)
;;								## 17
	c0    cmpge $b0.0 = $r0.4, $r0.0   ## [spec] bblock 16, line 158,  t138(I1),  t69,  0(SI32)
	c0    cmpne $b0.1 = $r0.9, $r0.10   ## [spec] bblock 18, line 158,  t139(I1),  t67(I8),  t76
	c0    brf $b0.0, L47?3   ## bblock 13, line 156,  t137(I1)
;;								## 18
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.4   ## bblock 16, line 158, 0(I32), t69
	c0    brf $b0.0, L48?3   ## bblock 16, line 158,  t138(I1)
;;								## 19
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.8   ## bblock 31, line 158, 0(I32), (addr(CompBuf?1.0)(P32) + 0x1(I32))(P32)
	c0    brf $b0.1, L49?3   ## bblock 18, line 158,  t139(I1)
;;								## 20
L50?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 28, line 161,  raddr(puts)(P32),  addr(_?1STRINGVAR.5)(P32)
;;								## 21
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t107
	      xnop 1
;;								## 23
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 29, line 162,  t108,  ?2.4?2auto_size(I32),  t107
;;								## 24
.trace 26
L49?3:
	c0    ldw $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## bblock 19, line 159, t78, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 30, line 159, t80, 0(I32)
	c0    ldbu.d $r0.5 = (((magic_header + 0) + 1) + 0)[$r0.0]   ## [spec] bblock 21, line 159, t85(I8), 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, -1   ## bblock 19, line 159,  t79,  t78,  -1(SI32)
	c0    add $r0.6 = $r0.4, 1   ## [spec] bblock 30, line 159,  t81,  t80,  1(SI32)
	c0    and $r0.5 = $r0.5, 255   ## [spec] bblock 21, line 159,  t86,  t85(I8),  255(I32)
;;								## 2
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 19, line 159, 0(I32), t79
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 19, line 159,  t140(I1),  t79,  0(SI32)
;;								## 3
	c0    brf $b0.0, L51?3   ## bblock 19, line 159,  t140(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.6   ## bblock 30, line 159, 0(I32), t81
;;								## 5
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 30, line 159, t82(SI8), t80
	      xnop 1
;;								## 7
	c0    zxtb $r0.4 = $r0.4   ## bblock 30, line 159,  t77(I8),  t82(SI8)
;;								## 8
L52?3:
	c0    cmpne $b0.0 = $r0.4, $r0.5   ## bblock 21, line 159,  t141(I1),  t77(I8),  t86
;;								## 9
	c0    brf $b0.0, L53?3   ## bblock 21, line 159,  t141(I1)
	      ## goto
;;
	c0    goto L50?3 ## goto
;;								## 10
.trace 31
L53?3:
	c0    ldw $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## bblock 22, line 164, t90, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 27, line 164, t92, 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.6 + 0)   ## addr(_?1STRINGVAR.6)(P32)
	c0    mov $r0.6 = 100000   ## 100000(SI32)
	c0    mov $r0.5 = 1   ## 1(SI32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, -1   ## bblock 22, line 164,  t91,  t90,  -1(SI32)
	c0    add $r0.8 = $r0.4, 1   ## [spec] bblock 27, line 164,  t93,  t92,  1(SI32)
;;								## 2
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 22, line 164, 0(I32), t91
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 22, line 164,  t142(I1),  t91,  0(SI32)
;;								## 3
	c0    brf $b0.0, L54?3   ## bblock 22, line 164,  t142(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.8   ## bblock 27, line 164, 0(I32), t93
;;								## 5
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 27, line 164, t94(SI8), t92
	      xnop 1
;;								## 7
	c0    zxtb $r0.4 = $r0.4   ## bblock 27, line 164,  t89(I8),  t94(SI8)
	c0    stw ((fsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 24, line 168, 0(I32), 100000(SI32)
;;								## 8
L55?3:
	c0    and $r0.6 = $r0.4, 128   ## bblock 24, line 165,  t97,  t89(I8),  128(I32)
	c0    and $r0.2 = $r0.4, 31   ## bblock 24, line 166,  t102,  t89(I8),  31(I32)
;;								## 9
	c0    stw ((block_compress + 0) + 0)[$r0.0] = $r0.6   ## bblock 24, line 165, 0(I32), t97
	c0    stw ((maxbits + 0) + 0)[$r0.0] = $r0.2   ## bblock 24, line 166, 0(I32), t102
	c0    shl $r0.5 = $r0.5, $r0.2   ## bblock 24, line 167,  t101,  1(SI32),  t102
	c0    cmpgt $b0.0 = $r0.2, 12   ## bblock 24, line 169,  t143(I1),  t102,  12(SI32)
;;								## 10
	c0    stw ((maxmaxcode + 0) + 0)[$r0.0] = $r0.5   ## bblock 24, line 167, 0(I32), t101
	c0    brf $b0.0, L47?3   ## bblock 24, line 169,  t143(I1)
;;								## 11
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 25, line 172,  raddr(puts)(P32),  addr(_?1STRINGVAR.6)(P32)
;;								## 12
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t107
	      xnop 1
;;								## 14
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 26, line 173,  t108,  ?2.4?2auto_size(I32),  t107
;;								## 15
.trace 22
L47?3:
.call decompress, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = decompress   ## bblock 14, line 176,  raddr(decompress)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t107
	c0    ldw $r0.7 = 0x1c[$r0.1]  ## restore ## t123
	      xnop 1
;;								## 2
.return ret($r0.3:s32)
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.7   ## bblock 15, line 177, 0(I32), t123
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 15, line 178,  t108,  ?2.4?2auto_size(I32),  t107
;;								## 3
.trace 34
L54?3:
	c0    mov $r0.4 = -1   ## bblock 23, line 164,  t89(I8),  -1(SI32)
	c0    mov $r0.5 = 1   ## 1(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.6 + 0)   ## addr(_?1STRINGVAR.6)(P32)
	c0    mov $r0.6 = 100000   ## 100000(SI32)
;;								## 0
	c0    stw ((fsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 24, line 168, 0(I32), 100000(SI32)
	c0    goto L55?3 ## goto
;;								## 1
.trace 32
L51?3:
	c0    mov $r0.4 = -1   ## bblock 20, line 159,  t77(I8),  -1(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
	c0    goto L52?3 ## goto
;;								## 0
.trace 28
L48?3:
	c0    mov $r0.9 = -1   ## bblock 17, line 158,  t67(I8),  -1(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
;;								## 0
	c0    cmpne $b0.0 = $r0.9, $r0.10   ## bblock 18, line 158,  t139(I1),  t67(I8),  t76
;;								## 1
	c0    brf $b0.0, L49?3   ## bblock 18, line 158,  t139(I1)
	      ## goto
;;
	c0    goto L50?3 ## goto
;;								## 2
.trace 25
L45?3:
	c0    ldw $r0.2 = ((fsize + 0) + 0)[$r0.0]   ## bblock 8, line 143, t56, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 8192   ## bblock 8, line 143,  t133(I1),  t56,  8192(SI32)
;;								## 2
	c0    brf $b0.0, L56?3   ## bblock 8, line 143,  t133(I1)
;;								## 3
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 35, line 144, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 4
	c0    goto L46?3 ## goto
;;								## 5
.trace 27
L56?3:
	c0    ldw $r0.2 = ((fsize + 0) + 0)[$r0.0]   ## bblock 9, line 145, t57, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 16384   ## bblock 9, line 145,  t134(I1),  t57,  16384(SI32)
;;								## 2
	c0    brf $b0.0, L57?3   ## bblock 9, line 145,  t134(I1)
;;								## 3
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 34, line 146, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 4
	c0    goto L46?3 ## goto
;;								## 5
.trace 29
L57?3:
	c0    ldw $r0.2 = ((fsize + 0) + 0)[$r0.0]   ## bblock 10, line 147, t58, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 32768   ## bblock 10, line 147,  t135(I1),  t58,  32768(SI32)
;;								## 2
	c0    brf $b0.0, L58?3   ## bblock 10, line 147,  t135(I1)
;;								## 3
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 33, line 148, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 4
	c0    goto L46?3 ## goto
;;								## 5
.trace 33
L58?3:
	c0    ldw $r0.2 = ((fsize + 0) + 0)[$r0.0]   ## bblock 11, line 149, t59, 0(I32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.2, 47000   ## bblock 11, line 149,  t136(I1),  t59,  47000(SI32)
;;								## 2
	c0    brf $b0.0, L59?3   ## bblock 11, line 149,  t136(I1)
;;								## 3
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 32, line 150, 0(I32), 5003(SI32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 4
	c0    goto L46?3 ## goto
;;								## 5
.trace 36
L59?3:
.call compressf, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = compressf   ## bblock 12, line 151,  raddr(compressf)(P32)
;;								## 0
	c0    goto L46?3 ## goto
;;								## 1
.trace 23
L43?3:
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    mov $r0.6 = 5003   ## 5003(SI32)
;;								## 0
	c0    stw ((hsize + 0) + 0)[$r0.0] = $r0.6   ## bblock 7, line 140, 0(I32), 5003(SI32)
	c0    goto L44?3 ## goto
;;								## 1
.trace 24
L41?3:
	c0    mov $r0.5 = 12   ## 12(SI32)
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    goto L42?3 ## goto
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
.trace 13
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    ldw $r0.5 = ((nomagic + 0) + 0)[$r0.0]   ## bblock 0, line 191, t7, 0(I32)
	c0    ldw.d $r0.11 = ((block_compress + 0) + 0)[$r0.0]   ## [spec] bblock 1, line 205, t26, 0(I32)
	c0    ldw.d $r0.13 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 1, line 206, t29, 0(I32)
	c0    ldw.d $r0.14 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 33, line 206, t31, 0(I32)
	c0    ldw.d $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## [spec] bblock 3, line 208, t320, 0(I32)
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 3, line 207,  t127,  0(SI32)
	c0    mov $r0.12 = 257   ## 257(SI32)
	c0    mov $r0.10 = 511   ## 511(SI32)
	c0    mov $r0.9 = 9   ## 9(SI32)
	c0    mov $r0.8 = 10000   ## 10000(SI32)
	c0    mov $r0.7 = 1   ## 1(SI32)
	c0    mov $r0.6 = 3   ## 3(SI32)
	c0    mov $r0.3 = 65536   ## 65536(SI32)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t98
;;								## 1
	c0    cmpeq $b0.0 = $r0.5, $r0.0   ## bblock 0, line 191,  t406(I1),  t7,  0(SI32)
	c0    cmpne $b0.1 = $r0.11, $r0.0   ## [spec] bblock 1, line 205,  t407(I1),  t26,  0(SI32)
	c0    add $r0.13 = $r0.13, -1   ## [spec] bblock 1, line 206,  t30,  t29,  -1(SI32)
	c0    add $r0.15 = $r0.14, 1   ## [spec] bblock 33, line 206,  t32,  t31,  1(SI32)
;;								## 2
	c0    slct $r0.12 = $b0.1, $r0.12, 256   ## [spec] bblock 1, line 205,  t27,  t407(I1),  257(SI32),  256(SI32)
	c0    cmpge $b0.0 = $r0.13, $r0.0   ## [spec] bblock 1, line 206,  t408(I1),  t30,  0(SI32)
	c0    mov $r0.5 = $l0.0   ## t98
	c0    br $b0.0, L60?3   ## bblock 0, line 191,  t406(I1)
;;								## 3
L61?3:
	c0    stw ((compress_16460.offset + 0) + 0)[$r0.0] = $r0.0   ## bblock 1, line 197, 0(I32), 0(SI32)
	c0    stw ((bytes_out + 0) + 0)[$r0.0] = $r0.6   ## bblock 1, line 198, 0(I32), 3(SI32)
	c0    stw ((out_count + 0) + 0)[$r0.0] = $r0.0   ## bblock 1, line 199, 0(I32), 0(SI32)
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.0   ## bblock 1, line 200, 0(I32), 0(SI32)
	c0    stw ((ratio + 0) + 0)[$r0.0] = $r0.0   ## bblock 1, line 201, 0(I32), 0(SI32)
	c0    stw ((in_count + 0) + 0)[$r0.0] = $r0.7   ## bblock 1, line 202, 0(I32), 1(SI32)
	c0    stw ((checkpoint + 0) + 0)[$r0.0] = $r0.8   ## bblock 1, line 203, 0(I32), 10000(SI32)
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.9   ## bblock 1, line 204, 0(I32), 9(SI32)
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.10   ## bblock 1, line 204, 0(I32), 511(SI32)
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.12   ## bblock 1, line 205, 0(I32), t27
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.13   ## bblock 1, line 206, 0(I32), t30
	c0    brf $b0.0, L62?3   ## bblock 1, line 206,  t408(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.15   ## bblock 33, line 206, 0(I32), t32
;;								## 5
	c0    ldb $r0.14 = 0[$r0.14]   ## bblock 33, line 206, t33(SI8), t31
	      xnop 1
;;								## 7
	c0    zxtb $r0.14 = $r0.14   ## bblock 33, line 206,  t28(I8),  t33(SI8)
;;								## 8
L63?3:
	c0    mov $r0.6 = $r0.14   ## bblock 3, line 206,  t3,  t28(I8)
;;								## 9
.trace 3
L64?3:
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## bblock 4, line 208,  t409(I1),  t320,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 32, line 208,  t128,  t320,  1(I32)
;;								## 0
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 32, line 208-1,  t430(I1),  t128,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 77, line 208-1,  t155,  t128,  1(I32)
	c0    brf $b0.0, L65?3   ## bblock 4, line 208,  t409(I1)
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 77, line 208-2,  t458(I1),  t155,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 74, line 208-2,  t153,  t155,  1(I32)
	c0    brf $b0.0, L66?3   ## bblock 32, line 208-1,  t430(I1)
;;								## 2
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 74, line 208-3,  t456(I1),  t153,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 71, line 208-3,  t151,  t153,  1(I32)
	c0    brf $b0.0, L67?3   ## bblock 77, line 208-2,  t458(I1)
;;								## 3
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 71, line 208-4,  t455(I1),  t151,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 68, line 208-4,  t149,  t151,  1(I32)
	c0    brf $b0.0, L68?3   ## bblock 74, line 208-3,  t456(I1)
;;								## 4
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 68, line 208-5,  t454(I1),  t149,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 65, line 208-5,  t147,  t149,  1(I32)
	c0    brf $b0.0, L69?3   ## bblock 71, line 208-4,  t455(I1)
;;								## 5
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 65, line 208-6,  t452(I1),  t147,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 62, line 208-6,  t145,  t147,  1(I32)
	c0    brf $b0.0, L70?3   ## bblock 68, line 208-5,  t454(I1)
;;								## 6
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 62, line 208-7,  t450(I1),  t145,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 59, line 208-7,  t143,  t145,  1(I32)
	c0    brf $b0.0, L71?3   ## bblock 65, line 208-6,  t452(I1)
;;								## 7
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 59, line 208-8,  t448(I1),  t143,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 56, line 208-8,  t141,  t143,  1(I32)
	c0    brf $b0.0, L72?3   ## bblock 62, line 208-7,  t450(I1)
;;								## 8
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 56, line 208-9,  t446(I1),  t141,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 53, line 208-9,  t139,  t141,  1(I32)
	c0    brf $b0.0, L73?3   ## bblock 59, line 208-8,  t448(I1)
;;								## 9
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 53, line 208-10,  t444(I1),  t139,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 50, line 208-10,  t137,  t139,  1(I32)
	c0    brf $b0.0, L74?3   ## bblock 56, line 208-9,  t446(I1)
;;								## 10
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 50, line 208-11,  t442(I1),  t137,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 47, line 208-11,  t0,  t137,  1(I32)
	c0    brf $b0.0, L75?3   ## bblock 53, line 208-10,  t444(I1)
;;								## 11
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 47, line 208-12,  t440(I1),  t0,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 44, line 208-12,  t131,  t0,  1(I32)
	c0    brf $b0.0, L76?3   ## bblock 50, line 208-11,  t442(I1)
;;								## 12
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 44, line 208-13,  t438(I1),  t131,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 41, line 208-13,  t133,  t131,  1(I32)
	c0    brf $b0.0, L77?3   ## bblock 47, line 208-12,  t440(I1)
;;								## 13
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 41, line 208-14,  t436(I1),  t133,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 38, line 208-14,  t136,  t133,  1(I32)
	c0    brf $b0.0, L78?3   ## bblock 44, line 208-13,  t438(I1)
;;								## 14
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 38, line 208-15,  t434(I1),  t136,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 28, line 208-15,  t126,  t136,  1(I32)
	c0    brf $b0.0, L79?3   ## bblock 41, line 208-14,  t436(I1)
;;								## 15
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 28, line 208-1,  t428(I1),  t126,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 67, line 208-1,  t327,  t126,  1(I32)
	c0    brf $b0.0, L80?3   ## bblock 38, line 208-15,  t434(I1)
;;								## 16
	c0    add $r0.4 = $r0.4, 16   ## bblock 28, line 209-15,  t127,  t127,  16(SI32)
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 67, line 208-1,  t453(I1),  t327,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 20, line 208-1,  t341,  t327,  1(I32)
	c0    brf $b0.0, L65?3   ## bblock 28, line 208-1,  t428(I1)
;;								## 17
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 20, line 208-1,  t421(I1),  t341,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 37, line 208-1,  t340,  t341,  1(I32)
	c0    brf $b0.0, L66?3   ## bblock 67, line 208-1,  t453(I1)
;;								## 18
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 37, line 208-1,  t433(I1),  t340,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 76, line 208-1,  t339,  t340,  1(I32)
	c0    brf $b0.0, L67?3   ## bblock 20, line 208-1,  t421(I1)
;;								## 19
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 76, line 208-1,  t457(I1),  t339,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 36, line 208-1,  t338,  t339,  1(I32)
	c0    brf $b0.0, L68?3   ## bblock 37, line 208-1,  t433(I1)
;;								## 20
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 36, line 208-1,  t432(I1),  t338,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 35, line 208-1,  t337,  t338,  1(I32)
	c0    brf $b0.0, L69?3   ## bblock 76, line 208-1,  t457(I1)
;;								## 21
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 35, line 208-1,  t431(I1),  t337,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 40, line 208-1,  t336,  t337,  1(I32)
	c0    brf $b0.0, L70?3   ## bblock 36, line 208-1,  t432(I1)
;;								## 22
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 40, line 208-1,  t435(I1),  t336,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 43, line 208-1,  t335,  t336,  1(I32)
	c0    brf $b0.0, L71?3   ## bblock 35, line 208-1,  t431(I1)
;;								## 23
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 43, line 208-1,  t437(I1),  t335,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 46, line 208-1,  t334,  t335,  1(I32)
	c0    brf $b0.0, L72?3   ## bblock 40, line 208-1,  t435(I1)
;;								## 24
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 46, line 208-1,  t439(I1),  t334,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 49, line 208-1,  t333,  t334,  1(I32)
	c0    brf $b0.0, L73?3   ## bblock 43, line 208-1,  t437(I1)
;;								## 25
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 49, line 208-1,  t441(I1),  t333,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 52, line 208-1,  t332,  t333,  1(I32)
	c0    brf $b0.0, L74?3   ## bblock 46, line 208-1,  t439(I1)
;;								## 26
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 52, line 208-1,  t443(I1),  t332,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 55, line 208-1,  t331,  t332,  1(I32)
	c0    brf $b0.0, L75?3   ## bblock 49, line 208-1,  t441(I1)
;;								## 27
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 55, line 208-1,  t445(I1),  t331,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 58, line 208-1,  t330,  t331,  1(I32)
	c0    brf $b0.0, L76?3   ## bblock 52, line 208-1,  t443(I1)
;;								## 28
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 58, line 208-1,  t447(I1),  t330,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 61, line 208-1,  t329,  t330,  1(I32)
	c0    brf $b0.0, L77?3   ## bblock 55, line 208-1,  t445(I1)
;;								## 29
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 61, line 208-1,  t449(I1),  t329,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 64, line 208-1,  t328,  t329,  1(I32)
	c0    brf $b0.0, L78?3   ## bblock 58, line 208-1,  t447(I1)
;;								## 30
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## [spec] bblock 64, line 208-1,  t451(I1),  t328,  65536(SI32)
	c0    shl $r0.2 = $r0.2, 1   ## [spec] bblock 70, line 208-1,  t320,  t328,  1(I32)
	c0    brf $b0.0, L79?3   ## bblock 61, line 208-1,  t449(I1)
;;								## 31
	c0    brf $b0.0, L80?3   ## bblock 64, line 208-1,  t451(I1)
;;								## 32
	c0    add $r0.4 = $r0.4, 16   ## bblock 70, line 209-1,  t127,  t127,  16(SI32)
	c0    goto L64?3 ## goto
;;								## 33
.trace 97
L80?3:
	c0    add $r0.4 = $r0.4, 15   ## bblock 29, line 0,  t6,  t127,  15(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 4
L82?3:
	c0    ldw $r0.3 = ((buflen + 0) + 0)[$r0.0]   ## bblock 6, line 214, t42, 0(I32)
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 31, line 214, t44, 0(I32)
	c0    ldw.d $r0.7 = ((in_count + 0) + 0)[$r0.0]   ## [spec] bblock 16, line 216, t48, 0(I32)
	c0    ldw.d $r0.10 = ((maxbits + 0) + 0)[$r0.0]   ## [spec] bblock 16, line 217, t50, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.3 = $r0.3, -1   ## bblock 6, line 214,  t43,  t42,  -1(SI32)
	c0    add $r0.11 = $r0.6, 1   ## [spec] bblock 31, line 214,  t45,  t44,  1(SI32)
	c0    add $r0.7 = $r0.7, 1   ## [spec] bblock 16, line 216,  t49,  t48,  1(SI32)
;;								## 2
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.3   ## bblock 6, line 214, 0(I32), t43
	c0    cmpge $b0.0 = $r0.3, $r0.0   ## bblock 6, line 214,  t410(I1),  t43,  0(SI32)
;;								## 3
	c0    brf $b0.0, L83?3   ## bblock 6, line 214,  t410(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.11   ## bblock 31, line 214, 0(I32), t45
;;								## 5
	c0    ldb $r0.6 = 0[$r0.6]   ## bblock 31, line 214, t46(SI8), t44
	      xnop 1
;;								## 7
	c0    zxtb $r0.6 = $r0.6   ## bblock 31, line 214,  t41(I8),  t46(SI8)
;;								## 8
L84?3:
	c0    cmpne $b0.0 = $r0.6, -1   ## bblock 8, line 214,  t411(I1),  t41(I8),  -1(SI32)
	c0    shl $r0.10 = $r0.6, $r0.10   ## [spec] bblock 16, line 217,  t51,  t41(I8),  t50
	c0    shl $r0.3 = $r0.6, $r0.8   ## [spec] bblock 16, line 218,  t53,  t41(I8),  t113
;;								## 9
	c0    add $r0.5 = $r0.10, $r0.9   ## [spec] bblock 16, line 217,  t114,  t51,  t3
	c0    xor $r0.2 = $r0.9, $r0.3   ## [spec] bblock 16, line 218,  t1,  t3,  t53
	c0    brf $b0.0, L85?3   ## bblock 8, line 214,  t411(I1)
;;								## 10
	c0    stw ((in_count + 0) + 0)[$r0.0] = $r0.7   ## bblock 16, line 216, 0(I32), t49
	c0    sh2add $r0.3 = $r0.2, (htab + 0)   ## bblock 16, line 219,  t414,  t1,  addr(htab?1.0)(P32)
	c0    sh1add $r0.10 = $r0.2, (codetab + 0)   ## [spec] bblock 30, line 221,  t429,  t1,  addr(codetab?1.0)(P32)
;;								## 11
	c0    ldw $r0.3 = 0[$r0.3]   ## bblock 16, line 219, t56, t414
	      xnop 1
;;								## 13
	c0    cmpeq $b0.0 = $r0.3, $r0.5   ## bblock 16, line 219,  t415(I1),  t56,  t114
;;								## 14
	c0    brf $b0.0, L86?3   ## bblock 16, line 219,  t415(I1)
;;								## 15
	c0    ldhu $r0.9 = 0[$r0.10]   ## bblock 30, line 221, t3, t429
;;								## 16
	c0    goto L82?3 ## goto
;;								## 17
.trace 8
L86?3:
	c0    sh2add $r0.7 = $r0.2, (htab + 0)   ## bblock 17, line 224,  t416,  t1,  addr(htab?1.0)(P32)
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    stw 0x18[$r0.1] = $r0.8  ## spill ## t113
	c0    stw 0x1c[$r0.1] = $r0.6  ## spill ## t41(I8)
	c0    mov $r0.3 = $r0.9   ## t3
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
;;								## 0
	c0    ldw $r0.7 = 0[$r0.7]   ## bblock 17, line 224, t60, t416
	      xnop 1
;;								## 2
	c0    cmplt $b0.0 = $r0.7, $r0.0   ## bblock 17, line 224,  t417(I1),  t60,  0(SI32)
;;								## 3
	c0    brf $b0.0, L87?3   ## bblock 17, line 224,  t417(I1)
;;								## 4
L88?3:
.call output, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = output   ## bblock 22, line 244,  raddr(output)(P32),  t3
;;								## 5
	c0    ldw $r0.3 = ((out_count + 0) + 0)[$r0.0]   ## bblock 23, line 245, t70, 0(I32)
	c0    ldw $r0.7 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 23, line 247, t72, 0(I32)
	c0    ldw $r0.10 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 23, line 247, t73, 0(I32)
	c0    ldw $r0.5 = 0x14[$r0.1]  ## restore ## t114
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    ldw $r0.6 = 0x1c[$r0.1]  ## restore ## t41(I8)
	c0    ldw $r0.2 = 0x20[$r0.1]  ## restore ## t1
	      xnop 1
;;								## 7
	c0    add $r0.3 = $r0.3, 1   ## bblock 23, line 245,  t71,  t70,  1(SI32)
	c0    mov $r0.9 = $r0.6   ## bblock 23, line 246,  t3,  t41(I8)
	c0    cmplt $b0.0 = $r0.7, $r0.10   ## bblock 23, line 247,  t423(I1),  t72,  t73
	c0    add $r0.11 = $r0.7, 1   ## [spec] bblock 26, line 249,  t75,  t72,  1(SI32)
	c0    sh1add $r0.12 = $r0.2, (codetab + 0)   ## [spec] bblock 26, line 249,  t425,  t1,  addr(codetab?1.0)(P32)
	c0    sh2add $r0.13 = $r0.2, (htab + 0)   ## [spec] bblock 26, line 250,  t426,  t1,  addr(htab?1.0)(P32)
;;								## 8
	c0    stw ((out_count + 0) + 0)[$r0.0] = $r0.3   ## bblock 23, line 245, 0(I32), t71
	c0    brf $b0.0, L89?3   ## bblock 23, line 247,  t423(I1)
;;								## 9
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.11   ## bblock 26, line 249, 0(I32), t75
	c0    sth 0[$r0.12] = $r0.7   ## bblock 26, line 249, t425, t72
	c0    stw 0[$r0.13] = $r0.5   ## bblock 26, line 250, t426, t114
	c0    goto L82?3 ## goto
;;								## 10
.trace 10
L89?3:
	c0    ldw $r0.2 = ((in_count + 0) + 0)[$r0.0]   ## bblock 24, line 252, t79, 0(I32)
	c0    ldw $r0.3 = ((checkpoint + 0) + 0)[$r0.0]   ## bblock 24, line 252, t80, 0(I32)
	c0    ldw $r0.5 = ((block_compress + 0) + 0)[$r0.0]   ## bblock 24, line 252, t82, 0(I32)
	c0    stw 0x18[$r0.1] = $r0.8  ## spill ## t113
	c0    stw 0x24[$r0.1] = $r0.9  ## spill ## t3
	      xnop 1
;;								## 1
	c0    cmpge $r0.2 = $r0.2, $r0.3   ## bblock 24, line 252,  t81,  t79,  t80
;;								## 2
	c0    andl $b0.0 = $r0.2, $r0.5   ## bblock 24, line 252,  t424(I1),  t81,  t82
;;								## 3
	c0    brf $b0.0, L90?3   ## bblock 24, line 252,  t424(I1)
;;								## 4
.call cl_block, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = cl_block   ## bblock 25, line 254,  raddr(cl_block)(P32)
;;								## 5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    ldw $r0.9 = 0x24[$r0.1]  ## restore ## t3
;;								## 6
	c0    goto L82?3 ## goto
;;								## 7
.trace 12
L90?3:
	c0    ldw $r0.9 = 0x24[$r0.1]  ## restore ## t3
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
;;								## 0
	c0    goto L82?3 ## goto
;;								## 1
.trace 9
L87?3:
	c0    ldw $r0.5 = 0x14[$r0.1]  ## restore ## t114
	c0    mov $r0.11 = $r0.9   ## t3
	c0    ldw $r0.2 = 0x20[$r0.1]  ## restore ## t1
	c0    mov $r0.4 = $r0.57   ## t5
	      xnop 1
;;								## 1
	c0    sub $r0.57 = $r0.57, $r0.2   ## bblock 18, line 228,  t121,  t5,  t1
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 18, line 230,  t418(I1),  t1,  0(I32)
;;								## 2
	c0    slct $r0.3 = $b0.0, $r0.57, 1   ## bblock 18, line 230,  t4,  t418(I1),  t121,  1(SI32)
;;								## 3
.trace 1
L91?3:
	c0    sub $r0.2 = $r0.2, $r0.3   ## bblock 19, line 232,  t123,  t1,  t4
;;								## 0
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 19, line 232,  t117(I1),  t123,  0(SI32)
	c0    add $r0.6 = $r0.2, $r0.4   ## bblock 19, line 233,  t118,  t123,  t5
;;								## 1
	c0    slct $r0.2 = $b0.0, $r0.2, $r0.6   ## bblock 19, line 233,  t135,  t117(I1),  t123,  t118
;;								## 2
	c0    sh2add $r0.6 = $r0.2, (htab + 0)   ## bblock 19, line 234,  t419,  t135,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.2, $r0.3   ## [spec] bblock 136, line 232-1,  t227,  t135,  t4
;;								## 3
	c0    ldw $r0.6 = 0[$r0.6]   ## bblock 19, line 234, t65, t419
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 136, line 232-1,  t228(I1),  t227,  0(SI32)
	c0    add $r0.8 = $r0.4, $r0.7   ## [spec] bblock 136, line 233-1,  t229,  t5,  t227
;;								## 4
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.8   ## [spec] bblock 136, line 233-1,  t230,  t228(I1),  t227,  t229
;;								## 5
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 19, line 234,  t420(I1),  t65,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 21, line 239,  t422(I1),  t65,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 136, line 234-1,  t501,  t230,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 132, line 232-2,  t222,  t230,  t4
;;								## 6
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 136, line 234-1, t231, t501
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 132, line 232-2,  t223(I1),  t222,  0(SI32)
	c0    add $r0.9 = $r0.4, $r0.8   ## [spec] bblock 132, line 233-2,  t224,  t5,  t222
	c0    br $b0.0, L92?3   ## bblock 19, line 234,  t420(I1)
;;								## 7
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.9   ## [spec] bblock 132, line 233-2,  t225,  t223(I1),  t222,  t224
	c0    brf $b0.1, L93?3   ## bblock 21, line 239,  t422(I1)
;;								## 8
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 136, line 234-1,  t502(I1),  t231,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 137, line 239-1,  t503(I1),  t231,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 132, line 234-2,  t498,  t225,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 128, line 232-3,  t217,  t225,  t4
;;								## 9
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 132, line 234-2, t226, t498
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 128, line 232-3,  t218(I1),  t217,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 128, line 233-3,  t219,  t5,  t217
	c0    br $b0.0, L94?3   ## bblock 136, line 234-1,  t502(I1)
;;								## 10
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 128, line 233-3,  t220,  t218(I1),  t217,  t219
	c0    brf $b0.1, L95?3   ## bblock 137, line 239-1,  t503(I1)
;;								## 11
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 132, line 234-2,  t499(I1),  t226,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 133, line 239-2,  t500(I1),  t226,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 128, line 234-3,  t495,  t220,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 124, line 232-4,  t212,  t220,  t4
;;								## 12
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 128, line 234-3, t221, t495
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 124, line 232-4,  t213(I1),  t212,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 124, line 233-4,  t214,  t5,  t212
	c0    br $b0.0, L96?3   ## bblock 132, line 234-2,  t499(I1)
;;								## 13
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 124, line 233-4,  t215,  t213(I1),  t212,  t214
	c0    brf $b0.1, L97?3   ## bblock 133, line 239-2,  t500(I1)
;;								## 14
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 128, line 234-3,  t496(I1),  t221,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 129, line 239-3,  t497(I1),  t221,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 124, line 234-4,  t492,  t215,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 120, line 232-5,  t207,  t215,  t4
;;								## 15
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 124, line 234-4, t216, t492
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 120, line 232-5,  t208(I1),  t207,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.8   ## [spec] bblock 120, line 233-5,  t209,  t5,  t207
	c0    br $b0.0, L98?3   ## bblock 128, line 234-3,  t496(I1)
;;								## 16
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.10   ## [spec] bblock 120, line 233-5,  t210,  t208(I1),  t207,  t209
	c0    brf $b0.1, L99?3   ## bblock 129, line 239-3,  t497(I1)
;;								## 17
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 124, line 234-4,  t493(I1),  t216,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 125, line 239-4,  t494(I1),  t216,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 120, line 234-5,  t489,  t210,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 116, line 232-6,  t202,  t210,  t4
;;								## 18
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 120, line 234-5, t211, t489
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 116, line 232-6,  t203(I1),  t202,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 116, line 233-6,  t204,  t5,  t202
	c0    br $b0.0, L100?3   ## bblock 124, line 234-4,  t493(I1)
;;								## 19
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 116, line 233-6,  t205,  t203(I1),  t202,  t204
	c0    brf $b0.1, L101?3   ## bblock 125, line 239-4,  t494(I1)
;;								## 20
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 120, line 234-5,  t490(I1),  t211,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 121, line 239-5,  t491(I1),  t211,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 116, line 234-6,  t486,  t205,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 112, line 232-7,  t197,  t205,  t4
;;								## 21
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 116, line 234-6, t206, t486
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 112, line 232-7,  t198(I1),  t197,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 112, line 233-7,  t199,  t5,  t197
	c0    br $b0.0, L102?3   ## bblock 120, line 234-5,  t490(I1)
;;								## 22
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 112, line 233-7,  t200,  t198(I1),  t197,  t199
	c0    brf $b0.1, L103?3   ## bblock 121, line 239-5,  t491(I1)
;;								## 23
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 116, line 234-6,  t487(I1),  t206,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 117, line 239-6,  t488(I1),  t206,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 112, line 234-7,  t483,  t200,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 108, line 232-8,  t192,  t200,  t4
;;								## 24
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 112, line 234-7, t201, t483
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 108, line 232-8,  t193(I1),  t192,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.8   ## [spec] bblock 108, line 233-8,  t194,  t5,  t192
	c0    br $b0.0, L104?3   ## bblock 116, line 234-6,  t487(I1)
;;								## 25
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.10   ## [spec] bblock 108, line 233-8,  t195,  t193(I1),  t192,  t194
	c0    brf $b0.1, L105?3   ## bblock 117, line 239-6,  t488(I1)
;;								## 26
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 112, line 234-7,  t484(I1),  t201,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 113, line 239-7,  t485(I1),  t201,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 108, line 234-8,  t480,  t195,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 104, line 232-9,  t187,  t195,  t4
;;								## 27
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 108, line 234-8, t196, t480
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 104, line 232-9,  t188(I1),  t187,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 104, line 233-9,  t189,  t5,  t187
	c0    br $b0.0, L106?3   ## bblock 112, line 234-7,  t484(I1)
;;								## 28
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 104, line 233-9,  t190,  t188(I1),  t187,  t189
	c0    brf $b0.1, L107?3   ## bblock 113, line 239-7,  t485(I1)
;;								## 29
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 108, line 234-8,  t481(I1),  t196,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 109, line 239-8,  t482(I1),  t196,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 104, line 234-9,  t477,  t190,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 100, line 232-10,  t182,  t190,  t4
;;								## 30
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 104, line 234-9, t191, t477
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 100, line 232-10,  t183(I1),  t182,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 100, line 233-10,  t184,  t5,  t182
	c0    br $b0.0, L108?3   ## bblock 108, line 234-8,  t481(I1)
;;								## 31
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 100, line 233-10,  t185,  t183(I1),  t182,  t184
	c0    brf $b0.1, L109?3   ## bblock 109, line 239-8,  t482(I1)
;;								## 32
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 104, line 234-9,  t478(I1),  t191,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 105, line 239-9,  t479(I1),  t191,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 100, line 234-10,  t474,  t185,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 96, line 232-11,  t177,  t185,  t4
;;								## 33
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 100, line 234-10, t186, t474
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 96, line 232-11,  t178(I1),  t177,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.8   ## [spec] bblock 96, line 233-11,  t179,  t5,  t177
	c0    br $b0.0, L110?3   ## bblock 104, line 234-9,  t478(I1)
;;								## 34
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.10   ## [spec] bblock 96, line 233-11,  t180,  t178(I1),  t177,  t179
	c0    brf $b0.1, L111?3   ## bblock 105, line 239-9,  t479(I1)
;;								## 35
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 100, line 234-10,  t475(I1),  t186,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 101, line 239-10,  t476(I1),  t186,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 96, line 234-11,  t471,  t180,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 92, line 232-12,  t172,  t180,  t4
;;								## 36
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 96, line 234-11, t181, t471
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 92, line 232-12,  t173(I1),  t172,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 92, line 233-12,  t174,  t5,  t172
	c0    br $b0.0, L112?3   ## bblock 100, line 234-10,  t475(I1)
;;								## 37
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 92, line 233-12,  t175,  t173(I1),  t172,  t174
	c0    brf $b0.1, L113?3   ## bblock 101, line 239-10,  t476(I1)
;;								## 38
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 96, line 234-11,  t472(I1),  t181,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 97, line 239-11,  t473(I1),  t181,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 92, line 234-12,  t468,  t175,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 88, line 232-13,  t167,  t175,  t4
;;								## 39
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 92, line 234-12, t176, t468
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 88, line 232-13,  t168(I1),  t167,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 88, line 233-13,  t169,  t5,  t167
	c0    br $b0.0, L114?3   ## bblock 96, line 234-11,  t472(I1)
;;								## 40
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 88, line 233-13,  t170,  t168(I1),  t167,  t169
	c0    brf $b0.1, L115?3   ## bblock 97, line 239-11,  t473(I1)
;;								## 41
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 92, line 234-12,  t469(I1),  t176,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 93, line 239-12,  t470(I1),  t176,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 88, line 234-13,  t465,  t170,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 84, line 232-14,  t162,  t170,  t4
;;								## 42
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 88, line 234-13, t171, t465
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 84, line 232-14,  t163(I1),  t162,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.8   ## [spec] bblock 84, line 233-14,  t164,  t5,  t162
	c0    br $b0.0, L116?3   ## bblock 92, line 234-12,  t469(I1)
;;								## 43
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.10   ## [spec] bblock 84, line 233-14,  t165,  t163(I1),  t162,  t164
	c0    brf $b0.1, L117?3   ## bblock 93, line 239-12,  t470(I1)
;;								## 44
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 88, line 234-13,  t466(I1),  t171,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 89, line 239-13,  t467(I1),  t171,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 84, line 234-14,  t462,  t165,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 80, line 232-15,  t157,  t165,  t4
;;								## 45
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 84, line 234-14, t166, t462
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 80, line 232-15,  t158(I1),  t157,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 80, line 233-15,  t159,  t5,  t157
	c0    br $b0.0, L118?3   ## bblock 88, line 234-13,  t466(I1)
;;								## 46
	c0    slct $r0.2 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 80, line 233-15,  t1,  t158(I1),  t157,  t159
	c0    brf $b0.1, L119?3   ## bblock 89, line 239-13,  t467(I1)
;;								## 47
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 84, line 234-14,  t463(I1),  t166,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 85, line 239-14,  t464(I1),  t166,  0(SI32)
	c0    sh2add $r0.6 = $r0.2, (htab + 0)   ## [spec] bblock 80, line 234-15,  t459,  t1,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.2, $r0.3   ## [spec] bblock 142, line 232-1,  t342,  t1,  t4
;;								## 48
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 80, line 234-15, t160, t459
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 142, line 232-1,  t343(I1),  t342,  0(SI32)
	c0    add $r0.9 = $r0.7, $r0.4   ## [spec] bblock 142, line 233-1,  t344,  t342,  t5
	c0    br $b0.0, L120?3   ## bblock 84, line 234-14,  t463(I1)
;;								## 49
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.9   ## [spec] bblock 142, line 233-1,  t135,  t343(I1),  t342,  t344
	c0    brf $b0.1, L121?3   ## bblock 85, line 239-14,  t464(I1)
;;								## 50
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 80, line 234-15,  t460(I1),  t160,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 81, line 239-15,  t461(I1),  t160,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 142, line 234-1,  t504,  t135,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 172, line 232-1,  t402,  t135,  t4
;;								## 51
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 142, line 234-1, t345, t504
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 172, line 232-1,  t403(I1),  t402,  0(SI32)
	c0    add $r0.9 = $r0.4, $r0.8   ## [spec] bblock 172, line 233-1,  t404,  t5,  t402
	c0    br $b0.0, L122?3   ## bblock 80, line 234-15,  t460(I1)
;;								## 52
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.9   ## [spec] bblock 172, line 233-1,  t230,  t403(I1),  t402,  t404
	c0    brf $b0.1, L123?3   ## bblock 81, line 239-15,  t461(I1)
;;								## 53
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 142, line 234-1,  t505(I1),  t345,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 143, line 239-1,  t506(I1),  t345,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 172, line 234-1,  t549,  t230,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 170, line 232-1,  t398,  t230,  t4
;;								## 54
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 172, line 234-1, t405, t549
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 170, line 232-1,  t399(I1),  t398,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 170, line 233-1,  t400,  t5,  t398
	c0    br $b0.0, L124?3   ## bblock 142, line 234-1,  t505(I1)
;;								## 55
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 170, line 233-1,  t225,  t399(I1),  t398,  t400
	c0    brf $b0.1, L125?3   ## bblock 143, line 239-1,  t506(I1)
;;								## 56
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 172, line 234-1,  t550(I1),  t405,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 173, line 239-1,  t551(I1),  t405,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 170, line 234-1,  t546,  t225,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 168, line 232-1,  t394,  t225,  t4
;;								## 57
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 170, line 234-1, t401, t546
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 168, line 232-1,  t395(I1),  t394,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 168, line 233-1,  t396,  t5,  t394
	c0    br $b0.0, L126?3   ## bblock 172, line 234-1,  t550(I1)
;;								## 58
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 168, line 233-1,  t220,  t395(I1),  t394,  t396
	c0    brf $b0.1, L127?3   ## bblock 173, line 239-1,  t551(I1)
;;								## 59
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 170, line 234-1,  t547(I1),  t401,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 171, line 239-1,  t548(I1),  t401,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 168, line 234-1,  t543,  t220,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 166, line 232-1,  t390,  t220,  t4
;;								## 60
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 168, line 234-1, t397, t543
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 166, line 232-1,  t391(I1),  t390,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.8   ## [spec] bblock 166, line 233-1,  t392,  t5,  t390
	c0    br $b0.0, L128?3   ## bblock 170, line 234-1,  t547(I1)
;;								## 61
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.10   ## [spec] bblock 166, line 233-1,  t215,  t391(I1),  t390,  t392
	c0    brf $b0.1, L129?3   ## bblock 171, line 239-1,  t548(I1)
;;								## 62
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 168, line 234-1,  t544(I1),  t397,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 169, line 239-1,  t545(I1),  t397,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 166, line 234-1,  t540,  t215,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 164, line 232-1,  t386,  t215,  t4
;;								## 63
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 166, line 234-1, t393, t540
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 164, line 232-1,  t387(I1),  t386,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 164, line 233-1,  t388,  t5,  t386
	c0    br $b0.0, L130?3   ## bblock 168, line 234-1,  t544(I1)
;;								## 64
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 164, line 233-1,  t210,  t387(I1),  t386,  t388
	c0    brf $b0.1, L131?3   ## bblock 169, line 239-1,  t545(I1)
;;								## 65
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 166, line 234-1,  t541(I1),  t393,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 167, line 239-1,  t542(I1),  t393,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 164, line 234-1,  t537,  t210,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 162, line 232-1,  t382,  t210,  t4
;;								## 66
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 164, line 234-1, t389, t537
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 162, line 232-1,  t383(I1),  t382,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 162, line 233-1,  t384,  t5,  t382
	c0    br $b0.0, L132?3   ## bblock 166, line 234-1,  t541(I1)
;;								## 67
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 162, line 233-1,  t205,  t383(I1),  t382,  t384
	c0    brf $b0.1, L133?3   ## bblock 167, line 239-1,  t542(I1)
;;								## 68
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 164, line 234-1,  t538(I1),  t389,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 165, line 239-1,  t539(I1),  t389,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 162, line 234-1,  t534,  t205,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 160, line 232-1,  t378,  t205,  t4
;;								## 69
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 162, line 234-1, t385, t534
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 160, line 232-1,  t379(I1),  t378,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.8   ## [spec] bblock 160, line 233-1,  t380,  t5,  t378
	c0    br $b0.0, L134?3   ## bblock 164, line 234-1,  t538(I1)
;;								## 70
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.10   ## [spec] bblock 160, line 233-1,  t200,  t379(I1),  t378,  t380
	c0    brf $b0.1, L135?3   ## bblock 165, line 239-1,  t539(I1)
;;								## 71
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 162, line 234-1,  t535(I1),  t385,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 163, line 239-1,  t536(I1),  t385,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 160, line 234-1,  t531,  t200,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 158, line 232-1,  t374,  t200,  t4
;;								## 72
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 160, line 234-1, t381, t531
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 158, line 232-1,  t375(I1),  t374,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 158, line 233-1,  t376,  t5,  t374
	c0    br $b0.0, L136?3   ## bblock 162, line 234-1,  t535(I1)
;;								## 73
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 158, line 233-1,  t195,  t375(I1),  t374,  t376
	c0    brf $b0.1, L137?3   ## bblock 163, line 239-1,  t536(I1)
;;								## 74
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 160, line 234-1,  t532(I1),  t381,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 161, line 239-1,  t533(I1),  t381,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 158, line 234-1,  t528,  t195,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 156, line 232-1,  t370,  t195,  t4
;;								## 75
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 158, line 234-1, t377, t528
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 156, line 232-1,  t371(I1),  t370,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 156, line 233-1,  t372,  t5,  t370
	c0    br $b0.0, L138?3   ## bblock 160, line 234-1,  t532(I1)
;;								## 76
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 156, line 233-1,  t190,  t371(I1),  t370,  t372
	c0    brf $b0.1, L139?3   ## bblock 161, line 239-1,  t533(I1)
;;								## 77
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 158, line 234-1,  t529(I1),  t377,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 159, line 239-1,  t530(I1),  t377,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 156, line 234-1,  t525,  t190,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 154, line 232-1,  t366,  t190,  t4
;;								## 78
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 156, line 234-1, t373, t525
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 154, line 232-1,  t367(I1),  t366,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.8   ## [spec] bblock 154, line 233-1,  t368,  t5,  t366
	c0    br $b0.0, L140?3   ## bblock 158, line 234-1,  t529(I1)
;;								## 79
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.10   ## [spec] bblock 154, line 233-1,  t185,  t367(I1),  t366,  t368
	c0    brf $b0.1, L141?3   ## bblock 159, line 239-1,  t530(I1)
;;								## 80
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 156, line 234-1,  t526(I1),  t373,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 157, line 239-1,  t527(I1),  t373,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 154, line 234-1,  t522,  t185,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 152, line 232-1,  t362,  t185,  t4
;;								## 81
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 154, line 234-1, t369, t522
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 152, line 232-1,  t363(I1),  t362,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 152, line 233-1,  t364,  t5,  t362
	c0    br $b0.0, L142?3   ## bblock 156, line 234-1,  t526(I1)
;;								## 82
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 152, line 233-1,  t180,  t363(I1),  t362,  t364
	c0    brf $b0.1, L143?3   ## bblock 157, line 239-1,  t527(I1)
;;								## 83
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 154, line 234-1,  t523(I1),  t369,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 155, line 239-1,  t524(I1),  t369,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 152, line 234-1,  t519,  t180,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 150, line 232-1,  t358,  t180,  t4
;;								## 84
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 152, line 234-1, t365, t519
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 150, line 232-1,  t359(I1),  t358,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 150, line 233-1,  t360,  t5,  t358
	c0    br $b0.0, L144?3   ## bblock 154, line 234-1,  t523(I1)
;;								## 85
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 150, line 233-1,  t175,  t359(I1),  t358,  t360
	c0    brf $b0.1, L145?3   ## bblock 155, line 239-1,  t524(I1)
;;								## 86
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 152, line 234-1,  t520(I1),  t365,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 153, line 239-1,  t521(I1),  t365,  0(SI32)
	c0    sh2add $r0.6 = $r0.7, (htab + 0)   ## [spec] bblock 150, line 234-1,  t516,  t175,  addr(htab?1.0)(P32)
	c0    sub $r0.8 = $r0.7, $r0.3   ## [spec] bblock 148, line 232-1,  t354,  t175,  t4
;;								## 87
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 150, line 234-1, t361, t516
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## [spec] bblock 148, line 232-1,  t355(I1),  t354,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.8   ## [spec] bblock 148, line 233-1,  t356,  t5,  t354
	c0    br $b0.0, L146?3   ## bblock 152, line 234-1,  t520(I1)
;;								## 88
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.10   ## [spec] bblock 148, line 233-1,  t170,  t355(I1),  t354,  t356
	c0    brf $b0.1, L147?3   ## bblock 153, line 239-1,  t521(I1)
;;								## 89
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 150, line 234-1,  t517(I1),  t361,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 151, line 239-1,  t518(I1),  t361,  0(SI32)
	c0    sh2add $r0.6 = $r0.8, (htab + 0)   ## [spec] bblock 148, line 234-1,  t513,  t170,  addr(htab?1.0)(P32)
	c0    sub $r0.9 = $r0.8, $r0.3   ## [spec] bblock 146, line 232-1,  t350,  t170,  t4
;;								## 90
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 148, line 234-1, t357, t513
	c0    cmpge $b0.0 = $r0.9, $r0.0   ## [spec] bblock 146, line 232-1,  t351(I1),  t350,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.9   ## [spec] bblock 146, line 233-1,  t352,  t5,  t350
	c0    br $b0.0, L148?3   ## bblock 150, line 234-1,  t517(I1)
;;								## 91
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## [spec] bblock 146, line 233-1,  t165,  t351(I1),  t350,  t352
	c0    brf $b0.1, L149?3   ## bblock 151, line 239-1,  t518(I1)
;;								## 92
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 148, line 234-1,  t514(I1),  t357,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 149, line 239-1,  t515(I1),  t357,  0(SI32)
	c0    sh2add $r0.6 = $r0.9, (htab + 0)   ## [spec] bblock 146, line 234-1,  t510,  t165,  addr(htab?1.0)(P32)
	c0    sub $r0.7 = $r0.9, $r0.3   ## [spec] bblock 144, line 232-1,  t346,  t165,  t4
;;								## 93
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 146, line 234-1, t353, t510
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## [spec] bblock 144, line 232-1,  t347(I1),  t346,  0(SI32)
	c0    add $r0.10 = $r0.4, $r0.7   ## [spec] bblock 144, line 233-1,  t348,  t5,  t346
	c0    br $b0.0, L150?3   ## bblock 148, line 234-1,  t514(I1)
;;								## 94
	c0    slct $r0.2 = $b0.0, $r0.7, $r0.10   ## [spec] bblock 144, line 233-1,  t1,  t347(I1),  t346,  t348
	c0    brf $b0.1, L151?3   ## bblock 149, line 239-1,  t515(I1)
;;								## 95
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 146, line 234-1,  t511(I1),  t353,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 147, line 239-1,  t512(I1),  t353,  0(SI32)
	c0    sh2add $r0.6 = $r0.2, (htab + 0)   ## [spec] bblock 144, line 234-1,  t507,  t1,  addr(htab?1.0)(P32)
;;								## 96
	c0    ldw.d $r0.6 = 0[$r0.6]   ## [spec] bblock 144, line 234-1, t349, t507
	c0    br $b0.0, L152?3   ## bblock 146, line 234-1,  t511(I1)
;;								## 97
	c0    brf $b0.1, L153?3   ## bblock 147, line 239-1,  t512(I1)
;;								## 98
	c0    cmpeq $b0.0 = $r0.6, $r0.5   ## bblock 144, line 234-1,  t508(I1),  t349,  t114
	c0    cmpgt $b0.1 = $r0.6, $r0.0   ## [spec] bblock 145, line 239-1,  t509(I1),  t349,  0(SI32)
;;								## 99
	c0    br $b0.0, L154?3   ## bblock 144, line 234-1,  t508(I1)
;;								## 100
	c0    brf $b0.1, L155?3   ## bblock 145, line 239-1,  t509(I1)
	      ## goto
;;
	c0    goto L91?3 ## goto
;;								## 101
.trace 82
L155?3:
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
	c0    goto L88?3 ## goto
;;								## 0
.trace 81
L154?3:
	   ## bblock 82, line 0,  t161,  t1## $r0.2(skipped)
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 80
L153?3:
	c0    mov $r0.8 = $r0.9   ## t165
;;								## 0
.trace 44
L121?3:
	c0    mov $r0.2 = $r0.8   ## bblock 87, line 0,  t1,  t165
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 79
L152?3:
	c0    mov $r0.2 = $r0.9   ## bblock 86, line 0,  t161,  t165
	c0    mov $r0.57 = $r0.4   ## t5
	c0    goto L157?3 ## goto
;;								## 0
.trace 78
L151?3:
	c0    mov $r0.7 = $r0.8   ## t170
;;								## 0
.trace 42
L119?3:
	c0    mov $r0.2 = $r0.7   ## bblock 91, line 0,  t1,  t170
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 77
L150?3:
	c0    mov $r0.2 = $r0.8   ## bblock 90, line 0,  t161,  t170
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 76
L149?3:
	c0    mov $r0.9 = $r0.7   ## t175
;;								## 0
.trace 40
L117?3:
	c0    mov $r0.2 = $r0.9   ## bblock 95, line 0,  t1,  t175
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 75
L148?3:
	c0    mov $r0.2 = $r0.7   ## bblock 94, line 0,  t161,  t175
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 74
L147?3:
	c0    mov $r0.8 = $r0.9   ## t180
;;								## 0
.trace 38
L115?3:
	c0    mov $r0.2 = $r0.8   ## bblock 99, line 0,  t1,  t180
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 73
L146?3:
	c0    mov $r0.2 = $r0.9   ## bblock 98, line 0,  t161,  t180
	c0    mov $r0.57 = $r0.4   ## t5
	c0    goto L158?3 ## goto
;;								## 0
.trace 72
L145?3:
	c0    mov $r0.7 = $r0.8   ## t185
;;								## 0
.trace 36
L113?3:
	c0    mov $r0.2 = $r0.7   ## bblock 103, line 0,  t1,  t185
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 71
L144?3:
	c0    mov $r0.2 = $r0.8   ## bblock 102, line 0,  t161,  t185
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 70
L143?3:
	c0    mov $r0.9 = $r0.7   ## t190
;;								## 0
.trace 34
L111?3:
	c0    mov $r0.2 = $r0.9   ## bblock 107, line 0,  t1,  t190
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 69
L142?3:
	c0    mov $r0.2 = $r0.7   ## bblock 106, line 0,  t161,  t190
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 68
L141?3:
	c0    mov $r0.8 = $r0.9   ## t195
;;								## 0
.trace 32
L109?3:
	c0    mov $r0.2 = $r0.8   ## bblock 111, line 0,  t1,  t195
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 67
L140?3:
	c0    mov $r0.2 = $r0.9   ## bblock 110, line 0,  t161,  t195
	c0    mov $r0.57 = $r0.4   ## t5
	c0    goto L159?3 ## goto
;;								## 0
.trace 66
L139?3:
	c0    mov $r0.7 = $r0.8   ## t200
;;								## 0
.trace 30
L107?3:
	c0    mov $r0.2 = $r0.7   ## bblock 115, line 0,  t1,  t200
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 65
L138?3:
	c0    mov $r0.2 = $r0.8   ## bblock 114, line 0,  t161,  t200
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 64
L137?3:
	c0    mov $r0.9 = $r0.7   ## t205
;;								## 0
.trace 28
L105?3:
	c0    mov $r0.2 = $r0.9   ## bblock 119, line 0,  t1,  t205
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 63
L136?3:
	c0    mov $r0.2 = $r0.7   ## bblock 118, line 0,  t161,  t205
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 62
L135?3:
	c0    mov $r0.8 = $r0.9   ## t210
;;								## 0
.trace 26
L103?3:
	c0    mov $r0.2 = $r0.8   ## bblock 123, line 0,  t1,  t210
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 61
L134?3:
	c0    mov $r0.2 = $r0.9   ## bblock 122, line 0,  t161,  t210
	c0    mov $r0.57 = $r0.4   ## t5
	c0    goto L160?3 ## goto
;;								## 0
.trace 60
L133?3:
	c0    mov $r0.7 = $r0.8   ## t215
;;								## 0
.trace 24
L101?3:
	c0    mov $r0.2 = $r0.7   ## bblock 127, line 0,  t1,  t215
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 59
L132?3:
	c0    mov $r0.2 = $r0.8   ## bblock 126, line 0,  t161,  t215
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 58
L131?3:
	c0    mov $r0.9 = $r0.7   ## t220
;;								## 0
.trace 22
L99?3:
	c0    mov $r0.2 = $r0.9   ## bblock 131, line 0,  t1,  t220
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 57
L130?3:
	c0    mov $r0.2 = $r0.7   ## bblock 130, line 0,  t161,  t220
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 56
L129?3:
	c0    mov $r0.8 = $r0.9   ## t225
;;								## 0
.trace 20
L97?3:
	c0    mov $r0.2 = $r0.8   ## bblock 135, line 0,  t1,  t225
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 55
L128?3:
	c0    mov $r0.2 = $r0.9   ## bblock 134, line 0,  t161,  t225
	c0    mov $r0.57 = $r0.4   ## t5
	c0    goto L161?3 ## goto
;;								## 0
.trace 54
L127?3:
	c0    mov $r0.7 = $r0.8   ## t230
;;								## 0
.trace 18
L95?3:
	c0    mov $r0.2 = $r0.7   ## bblock 139, line 0,  t1,  t230
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 53
L126?3:
	c0    mov $r0.2 = $r0.8   ## bblock 138, line 0,  t161,  t230
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 52
L125?3:
	c0    mov $r0.2 = $r0.7   ## t135
;;								## 0
.trace 16
L93?3:
	   ## bblock 141, line 0,  t1,  t135## $r0.2(skipped)
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    goto L88?3 ## goto
;;								## 1
.trace 51
L124?3:
	c0    mov $r0.2 = $r0.7   ## bblock 140, line 0,  t161,  t135
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 50
L123?3:
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t1
	c0    mov $r0.3 = $r0.11   ## t3
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t114
	c0    mov $r0.57 = $r0.4   ## t5
	c0    goto L88?3 ## goto
;;								## 0
.trace 45
L122?3:
	   ## bblock 82, line 0,  t161,  t1## $r0.2(skipped)
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 43
L120?3:
	c0    mov $r0.2 = $r0.8   ## bblock 86, line 0,  t161,  t165
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
L157?3:
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 1
.trace 41
L118?3:
	c0    mov $r0.2 = $r0.7   ## bblock 90, line 0,  t161,  t170
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 39
L116?3:
	c0    mov $r0.2 = $r0.9   ## bblock 94, line 0,  t161,  t175
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 37
L114?3:
	c0    mov $r0.2 = $r0.8   ## bblock 98, line 0,  t161,  t180
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
L158?3:
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 1
.trace 35
L112?3:
	c0    mov $r0.2 = $r0.7   ## bblock 102, line 0,  t161,  t185
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 33
L110?3:
	c0    mov $r0.2 = $r0.9   ## bblock 106, line 0,  t161,  t190
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 31
L108?3:
	c0    mov $r0.2 = $r0.8   ## bblock 110, line 0,  t161,  t195
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
L159?3:
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 1
.trace 29
L106?3:
	c0    mov $r0.2 = $r0.7   ## bblock 114, line 0,  t161,  t200
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 27
L104?3:
	c0    mov $r0.2 = $r0.9   ## bblock 118, line 0,  t161,  t205
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 25
L102?3:
	c0    mov $r0.2 = $r0.8   ## bblock 122, line 0,  t161,  t210
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
L160?3:
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 1
.trace 23
L100?3:
	c0    mov $r0.2 = $r0.7   ## bblock 126, line 0,  t161,  t215
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 21
L98?3:
	c0    mov $r0.2 = $r0.9   ## bblock 130, line 0,  t161,  t220
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 19
L96?3:
	c0    mov $r0.2 = $r0.8   ## bblock 134, line 0,  t161,  t225
	c0    mov $r0.57 = $r0.4   ## t5
;;								## 0
L161?3:
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 1
.trace 17
L94?3:
	c0    mov $r0.2 = $r0.7   ## bblock 138, line 0,  t161,  t230
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
	c0    goto L156?3 ## goto
;;								## 0
.trace 11
L92?3:
	   ## bblock 140, line 0,  t161,  t135## $r0.2(skipped)
	c0    mov $r0.57 = $r0.4   ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
;;								## 0
L156?3:
	c0    sh1add $r0.2 = $r0.2, (codetab + 0)   ## bblock 27, line 236,  t427,  t161,  addr(codetab?1.0)(P32)
;;								## 1
	c0    ldhu $r0.9 = 0[$r0.2]   ## bblock 27, line 236, t3, t427
;;								## 2
	c0    goto L82?3 ## goto
;;								## 3
.trace 14
L85?3:
.call output, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = output   ## bblock 9, line 257,  raddr(output)(P32),  t3
	c0    mov $r0.3 = $r0.9   ## t3
;;								## 0
	c0    ldw $r0.2 = ((out_count + 0) + 0)[$r0.0]   ## bblock 10, line 258, t84, 0(I32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	      xnop 1
;;								## 2
	c0    add $r0.2 = $r0.2, 1   ## bblock 10, line 258,  t85,  t84,  1(SI32)
;;								## 3
.call output, caller, arg($r0.3:s32), ret()
	c0    stw ((out_count + 0) + 0)[$r0.0] = $r0.2   ## bblock 10, line 258, 0(I32), t85
	c0    call $l0.0 = output   ## bblock 10, line 259,  raddr(output)(P32),  -1(SI32)
;;								## 4
	c0    ldw $r0.2 = ((zcat_flg + 0) + 0)[$r0.0]   ## bblock 11, line 260, t86, 0(I32)
	c0    ldw $r0.4 = ((quiet + 0) + 0)[$r0.0]   ## bblock 11, line 260, t88, 0(I32)
	c0    ldw.d $r0.6 = ((bytes_out + 0) + 0)[$r0.0]   ## [spec] bblock 12, line 265, t96, 0(I32)
	c0    ldw.d $r0.7 = ((in_count + 0) + 0)[$r0.0]   ## [spec] bblock 12, line 265, t97, 0(I32)
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    mov $r0.8 = 2   ## 2(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t98
	      xnop 1
;;								## 6
	c0    norl $b0.0 = $r0.2, $r0.4   ## bblock 11, line 260,  t412(I1),  t86,  t88
	c0    cmpgt $b0.1 = $r0.6, $r0.7   ## [spec] bblock 12, line 265,  t413(I1),  t96,  t97
;;								## 7
	c0    br $b0.0, L162?3   ## bblock 11, line 260,  t412(I1)
;;								## 8
L163?3:
	c0    brf $b0.1, L164?3   ## bblock 12, line 265,  t413(I1)
;;								## 9
	c0    stw ((exit_stat + 0) + 0)[$r0.0] = $r0.8   ## bblock 14, line 266, 0(I32), 2(SI32)
	c0    ldw $r0.57 = 0x28[$r0.1]  ## restore ## t102
;;								## 10
L165?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 13, line 267,  t99,  ?2.5?2auto_size(I32),  t98
;;								## 11
.trace 49
L164?3:
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $r0.57 = 0x28[$r0.1]  ## restore ## t102
	c0    goto L165?3 ## goto
;;								## 0
.trace 48
L162?3:
	c0    ldw $r0.2 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 15, line 263, t92, 0(I32)
	c0    ldw $r0.4 = ((in_count + 0) + 0)[$r0.0]   ## bblock 15, line 263, t95, 0(I32)
	      xnop 1
;;								## 1
.call prratio, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    sub $r0.3 = $r0.4, $r0.2   ## bblock 15, line 263,  t94,  t95,  t92
	c0    call $l0.0 = prratio   ## bblock 15, line 263,  raddr(prratio)(P32),  t94,  t95
;;								## 2
	c0    ldw $r0.6 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 12, line 265, t96, 0(I32)
	c0    ldw $r0.7 = ((in_count + 0) + 0)[$r0.0]   ## bblock 12, line 265, t97, 0(I32)
	c0    mov $r0.8 = 2   ## 2(SI32)
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t98
	      xnop 1
;;								## 4
	c0    cmpgt $b0.1 = $r0.6, $r0.7   ## bblock 12, line 265,  t413(I1),  t96,  t97
	c0    goto L163?3 ## goto
;;								## 5
.trace 6
L83?3:
	c0    mov $r0.6 = -1   ## bblock 7, line 214,  t41(I8),  -1(SI32)
	c0    goto L84?3 ## goto
;;								## 0
.trace 96
L79?3:
	c0    add $r0.4 = $r0.4, 14   ## bblock 39, line 0,  t6,  t127,  14(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 95
L78?3:
	c0    add $r0.4 = $r0.4, 13   ## bblock 42, line 0,  t6,  t127,  13(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 94
L77?3:
	c0    add $r0.4 = $r0.4, 12   ## bblock 45, line 0,  t6,  t127,  12(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 93
L76?3:
	c0    add $r0.4 = $r0.4, 11   ## bblock 48, line 0,  t6,  t127,  11(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 92
L75?3:
	c0    add $r0.4 = $r0.4, 10   ## bblock 51, line 0,  t6,  t127,  10(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 91
L74?3:
	c0    add $r0.4 = $r0.4, 9   ## bblock 54, line 0,  t6,  t127,  9(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 90
L73?3:
	c0    add $r0.4 = $r0.4, 8   ## bblock 57, line 0,  t6,  t127,  8(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 89
L72?3:
	c0    add $r0.4 = $r0.4, 7   ## bblock 60, line 0,  t6,  t127,  7(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 88
L71?3:
	c0    add $r0.4 = $r0.4, 6   ## bblock 63, line 0,  t6,  t127,  6(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 87
L70?3:
	c0    add $r0.4 = $r0.4, 5   ## bblock 66, line 0,  t6,  t127,  5(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 86
L69?3:
	c0    add $r0.4 = $r0.4, 4   ## bblock 69, line 0,  t6,  t127,  4(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 85
L68?3:
	c0    add $r0.4 = $r0.4, 3   ## bblock 72, line 0,  t6,  t127,  3(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 84
L67?3:
	c0    add $r0.4 = $r0.4, 2   ## bblock 75, line 0,  t6,  t127,  2(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 83
L66?3:
	c0    add $r0.4 = $r0.4, 1   ## bblock 78, line 0,  t6,  t127,  1(I32)
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    goto L81?3 ## goto
;;								## 0
.trace 15
L65?3:
	   ## bblock 79, line 0,  t6,  t127## $r0.4(skipped)
	c0    ldw $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## bblock 5, line 211, t5, 0(I32)
	c0    stw 0x24[$r0.1] = $r0.6  ## spill ## t3
	c0    stw 0x10[$r0.1] = $r0.5  ## spill ## t98
	c0    stw 0x28[$r0.1] = $r0.57  ## spill ## t102
;;								## 0
L81?3:
	c0    sub $r0.8 = 8, $r0.4   ## bblock 5, line 210,  t113,  8(SI32),  t6
;;								## 1
.call cl_hash, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = cl_hash   ## bblock 5, line 212,  raddr(cl_hash)(P32),  t5
	c0    stw 0x2c[$r0.1] = $r0.2  ## spill ## t5
	c0    mov $r0.3 = $r0.2   ## t5
	c0    stw 0x18[$r0.1] = $r0.8  ## spill ## t113
;;								## 2
	c0    ldw $r0.9 = 0x24[$r0.1]  ## restore ## t3
	c0    ldw $r0.57 = 0x2c[$r0.1]  ## restore ## t5
	c0    ldw $r0.8 = 0x18[$r0.1]  ## restore ## t113
;;								## 3
	c0    goto L82?3 ## goto
;;								## 4
.trace 47
L62?3:
	c0    mov $r0.14 = -1   ## bblock 2, line 206,  t28(I8),  -1(SI32)
	c0    goto L63?3 ## goto
;;								## 0
.trace 46
L60?3:
	c0    ldbu $r0.16 = ((magic_header + 0) + 0)[$r0.0]   ## bblock 34, line 193, t9(I8), 0(I32)
	c0    ldw $r0.11 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 34, line 193, t11, 0(I32)
	c0    mov $r0.6 = 3   ## 3(SI32)
	c0    mov $r0.9 = 9   ## 9(SI32)
	c0    mov $r0.17 = 257   ## 257(SI32)
	c0    mov $r0.7 = 1   ## 1(SI32)
	      xnop 1
;;								## 1
	c0    add $r0.18 = $r0.11, 1   ## bblock 34, line 193,  t12,  t11,  1(SI32)
;;								## 2
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.18   ## bblock 34, line 193, 0(I32), t12
;;								## 3
	c0    stb 0[$r0.11] = $r0.16   ## bblock 34, line 193, t11, t9(I8)
;;								## 4
	c0    ldw $r0.11 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 34, line 194, t16, 0(I32)
	c0    ldbu $r0.16 = (((magic_header + 0) + 1) + 0)[$r0.0]   ## bblock 34, line 194, t14(I8), 0(I32)
	      xnop 1
;;								## 6
	c0    add $r0.18 = $r0.11, 1   ## bblock 34, line 194,  t17,  t16,  1(SI32)
;;								## 7
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.18   ## bblock 34, line 194, 0(I32), t17
;;								## 8
	c0    stb 0[$r0.11] = $r0.16   ## bblock 34, line 194, t16, t14(I8)
;;								## 9
	c0    ldw $r0.11 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 34, line 195, t22, 0(I32)
	c0    ldw $r0.16 = ((block_compress + 0) + 0)[$r0.0]   ## bblock 34, line 195, t18, 0(I32)
	c0    ldw $r0.18 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 34, line 195, t19, 0(I32)
	      xnop 1
;;								## 11
	c0    add $r0.19 = $r0.11, 1   ## bblock 34, line 195,  t23,  t22,  1(SI32)
	c0    or $r0.16 = $r0.16, $r0.18   ## bblock 34, line 195,  t20,  t18,  t19
;;								## 12
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.19   ## bblock 34, line 195, 0(I32), t23
;;								## 13
	c0    stb 0[$r0.11] = $r0.16   ## bblock 34, line 195, t22, t20
;;								## 14
	c0    ldw $r0.11 = ((block_compress + 0) + 0)[$r0.0]   ## bblock 1, line 205, t26, 0(I32)
	c0    ldw $r0.16 = ((buflen + 0) + 0)[$r0.0]   ## bblock 1, line 206, t29, 0(I32)
	c0    ldw.d $r0.14 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 33, line 206, t31, 0(I32)
	c0    ldw.d $r0.2 = ((hsize + 0) + 0)[$r0.0]   ## [spec] bblock 3, line 208, t320, 0(I32)
	      xnop 1
;;								## 16
	c0    cmpne $b0.1 = $r0.11, $r0.0   ## bblock 1, line 205,  t407(I1),  t26,  0(SI32)
	c0    add $r0.13 = $r0.16, -1   ## bblock 1, line 206,  t30,  t29,  -1(SI32)
	c0    add $r0.15 = $r0.14, 1   ## [spec] bblock 33, line 206,  t32,  t31,  1(SI32)
;;								## 17
	c0    slct $r0.12 = $b0.1, $r0.17, 256   ## bblock 1, line 205,  t27,  t407(I1),  257(SI32),  256(SI32)
	c0    cmpge $b0.0 = $r0.13, $r0.0   ## bblock 1, line 206,  t408(I1),  t30,  0(SI32)
	c0    goto L61?3 ## goto
;;								## 18
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
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 0, line 275, t1, 0(I32)
	c0    ldw $r0.4 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 0, line 275, t2, 0(I32)
	c0    cmpge $b0.0 = $r0.3, $r0.0   ## bblock 0, line 278,  t768(I1),  t0,  0(SI32)
;;								## 0
	c0    brf $b0.0, L166?3   ## bblock 0, line 278,  t768(I1)
;;								## 1
	c0    shr $r0.7 = $r0.2, 3   ## bblock 7, line 280,  t8(SI29),  t1,  3(SI32)
	c0    and $r0.6 = $r0.2, 7   ## bblock 7, line 281,  t112,  t1,  7(I32)
	c0    add $r0.4 = $r0.4, -8   ## bblock 7, line 284,  t781,  t2,  -8(SI32)
;;								## 2
	c0    add $r0.12 = $r0.7, (compress_16460.buf + 0)   ## bblock 7, line 280,  t21,  t8(SI29),  addr(compress_16460.buf?1.0)(P32)
	c0    ldb $r0.10 = (compress_16460.buf + 0)[$r0.7]   ## bblock 7, line 282, t17(SI8), t8(SI29)
	c0    add $r0.13 = $r0.7, ((compress_16460.buf + 0) + 1)   ## bblock 7, line 283,  t3,  t8(SI29),  (addr(compress_16460.buf?1.0)(P32) + 0x1(I32))(P32)
	c0    ldbu $r0.2 = (lmask + 0)[$r0.6]   ## bblock 7, line 282, t12(I8), t112
	c0    shl $r0.8 = $r0.3, $r0.6   ## bblock 7, line 282,  t13,  t0,  t112
	c0    ldbu $r0.9 = (rmask + 0)[$r0.6]   ## bblock 7, line 282, t16(I8), t112
	c0    sub $r0.11 = 8, $r0.6   ## bblock 7, line 285,  t24,  8(SI32),  t112
	c0    add $r0.4 = $r0.4, $r0.6   ## bblock 7, line 284,  t110,  t781,  t112
;;								## 3
	c0    shr $r0.3 = $r0.3, $r0.11   ## bblock 7, line 285,  t620,  t0,  t24
	c0    cmpge $b0.0 = $r0.4, 8   ## bblock 7, line 286,  t782(I1),  t110,  8(SI32)
;;								## 4
	c0    and $r0.2 = $r0.2, $r0.8   ## bblock 7, line 282,  t14,  t12(I8),  t13
	c0    and $r0.9 = $r0.9, $r0.10   ## bblock 7, line 282,  t18,  t16(I8),  t17(SI8)
	c0    mov $r0.6 = $r0.3   ## bblock 7, line 285,  t111(SI24),  t620
;;								## 5
	c0    or $r0.2 = $r0.2, $r0.9   ## bblock 7, line 282,  t19,  t14,  t18
;;								## 6
	c0    stb (compress_16460.buf + 0)[$r0.7] = $r0.2   ## bblock 7, line 282, t8(SI29), t19
	c0    brf $b0.0, L167?3   ## bblock 7, line 286,  t782(I1)
;;								## 7
	c0    stb 1[$r0.12] = $r0.3   ## bblock 25, line 288, t21, t620
	c0    add $r0.13 = $r0.12, 2   ## bblock 25, line 288,  t3,  t21,  2(SI32)
	c0    shr $r0.6 = $r0.3, 8   ## bblock 25, line 289,  t111(SI24),  t620,  8(SI32)
	c0    add $r0.4 = $r0.4, -8   ## bblock 25, line 290,  t110,  t110,  -8(SI32)
;;								## 8
L167?3:
	c0    cmpne $b0.0 = $r0.4, $r0.0   ## bblock 8, line 292,  t783(I1),  t110,  0(SI32)
	c0    mov $r0.3 = (compress_16460.buf + 0)   ## [spec] bblock 21, line 297,  t710,  addr(compress_16460.buf?1.0)(P32)
;;								## 9
	c0    brf $b0.0, L168?3   ## bblock 8, line 292,  t783(I1)
;;								## 10
	c0    stb 0[$r0.13] = $r0.6   ## bblock 24, line 293, t3, t111(SI24)
;;								## 11
L168?3:
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 9, line 294, t32, 0(I32)
	c0    ldw $r0.4 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 9, line 294, t36, 0(I32)
	c0    ldw.d $r0.6 = ((bytes_out + 0) + 0)[$r0.0]   ## [spec] bblock 21, line 299, t41, 0(I32)
	      xnop 1
;;								## 13
	c0    add $r0.2 = $r0.2, $r0.4   ## bblock 9, line 294,  t35,  t32,  t36
	c0    shl $r0.7 = $r0.4, 3   ## bblock 9, line 295,  t37,  t36,  3(SI32)
	c0    add $r0.6 = $r0.4, $r0.6   ## [spec] bblock 21, line 299,  t42,  t36,  t41
	c0    mov $r0.5 = $r0.4   ## [spec] bblock 21, line 294,  t711,  t36
;;								## 14
	c0    stw ((compress_16460.offset + 0) + 0)[$r0.0] = $r0.2   ## bblock 9, line 294, 0(I32), t35
	c0    cmpeq $b0.0 = $r0.2, $r0.7   ## bblock 9, line 295,  t784(I1),  t35,  t37
;;								## 15
	c0    brf $b0.0, L169?3   ## bblock 9, line 295,  t784(I1)
;;								## 16
	c0    stw ((bytes_out + 0) + 0)[$r0.0] = $r0.6   ## bblock 21, line 299, 0(I32), t42
;;								## 17
.trace 2
L170?3:
	c0    ldb $r0.4 = 0[$r0.3]   ## bblock 22, line 302, t43(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 22, line 302, t44, 0(I32)
	c0    cmpeq $b0.0 = $r0.5, 1   ## bblock 22, line 305,  t791(I1),  t711,  1(SI32)
	c0    cmpeq $b0.1 = $r0.5, 2   ## [spec] bblock 101, line 305-1,  t875(I1),  t711,  2(SI32)
	c0    cmpeq $b0.2 = $r0.5, 3   ## [spec] bblock 99, line 305-2,  t874(I1),  t711,  3(SI32)
	c0    cmpeq $b0.3 = $r0.5, 4   ## [spec] bblock 97, line 305-3,  t873(I1),  t711,  4(SI32)
	c0    cmpeq $b0.4 = $r0.5, 5   ## [spec] bblock 95, line 305-4,  t872(I1),  t711,  5(SI32)
	c0    cmpeq $b0.5 = $r0.5, 6   ## [spec] bblock 93, line 305-5,  t871(I1),  t711,  6(SI32)
	c0    cmpeq $b0.6 = $r0.5, 7   ## [spec] bblock 91, line 305-6,  t870(I1),  t711,  7(SI32)
	c0    cmpeq $b0.7 = $r0.5, 8   ## [spec] bblock 89, line 305-7,  t869(I1),  t711,  8(SI32)
	c0    add $r0.7 = $r0.5, -16   ## [spec] bblock 73, line 305-15,  t113,  t711,  -16(SI32)
	c0    add $r0.6 = $r0.3, 16   ## [spec] bblock 73, line 303-15,  t114,  t710,  16(SI32)
	      xnop 1
;;								## 1
	c0    add $r0.8 = $r0.2, 1   ## bblock 22, line 302,  t45,  t44,  1(SI32)
;;								## 2
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 22, line 302, 0(I32), t45
;;								## 3
	c0    stb 0[$r0.2] = $r0.4   ## bblock 22, line 302, t44, t43(SI8)
	c0    br $b0.0, L171?3   ## bblock 22, line 305,  t791(I1)
;;								## 4
	c0    ldb $r0.4 = 1[$r0.3]   ## bblock 101, line 302-1, t292(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 101, line 302-1, t293, 0(I32)
	c0    cmpeq $b0.0 = $r0.5, 9   ## [spec] bblock 87, line 305-8,  t868(I1),  t711,  9(SI32)
	      xnop 1
;;								## 6
	c0    add $r0.8 = $r0.2, 1   ## bblock 101, line 302-1,  t294,  t293,  1(SI32)
;;								## 7
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 101, line 302-1, 0(I32), t294
;;								## 8
	c0    stb 0[$r0.2] = $r0.4   ## bblock 101, line 302-1, t293, t292(SI8)
	c0    br $b0.1, L171?3   ## bblock 101, line 305-1,  t875(I1)
;;								## 9
	c0    ldb $r0.4 = 2[$r0.3]   ## bblock 99, line 302-2, t287(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 99, line 302-2, t288, 0(I32)
	c0    cmpeq $b0.1 = $r0.5, 10   ## [spec] bblock 85, line 305-9,  t867(I1),  t711,  10(SI32)
	      xnop 1
;;								## 11
	c0    add $r0.8 = $r0.2, 1   ## bblock 99, line 302-2,  t289,  t288,  1(SI32)
;;								## 12
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 99, line 302-2, 0(I32), t289
;;								## 13
	c0    stb 0[$r0.2] = $r0.4   ## bblock 99, line 302-2, t288, t287(SI8)
	c0    br $b0.2, L171?3   ## bblock 99, line 305-2,  t874(I1)
;;								## 14
	c0    ldb $r0.4 = 3[$r0.3]   ## bblock 97, line 302-3, t282(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 97, line 302-3, t283, 0(I32)
	c0    cmpeq $b0.2 = $r0.5, 11   ## [spec] bblock 83, line 305-10,  t866(I1),  t711,  11(SI32)
	      xnop 1
;;								## 16
	c0    add $r0.8 = $r0.2, 1   ## bblock 97, line 302-3,  t284,  t283,  1(SI32)
;;								## 17
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 97, line 302-3, 0(I32), t284
;;								## 18
	c0    stb 0[$r0.2] = $r0.4   ## bblock 97, line 302-3, t283, t282(SI8)
	c0    br $b0.3, L171?3   ## bblock 97, line 305-3,  t873(I1)
;;								## 19
	c0    ldb $r0.4 = 4[$r0.3]   ## bblock 95, line 302-4, t277(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 95, line 302-4, t278, 0(I32)
	c0    cmpeq $b0.3 = $r0.5, 12   ## [spec] bblock 81, line 305-11,  t865(I1),  t711,  12(SI32)
	      xnop 1
;;								## 21
	c0    add $r0.8 = $r0.2, 1   ## bblock 95, line 302-4,  t279,  t278,  1(SI32)
;;								## 22
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 95, line 302-4, 0(I32), t279
;;								## 23
	c0    stb 0[$r0.2] = $r0.4   ## bblock 95, line 302-4, t278, t277(SI8)
	c0    br $b0.4, L171?3   ## bblock 95, line 305-4,  t872(I1)
;;								## 24
	c0    ldb $r0.4 = 5[$r0.3]   ## bblock 93, line 302-5, t272(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 93, line 302-5, t273, 0(I32)
	c0    cmpeq $b0.4 = $r0.5, 13   ## [spec] bblock 79, line 305-12,  t864(I1),  t711,  13(SI32)
	      xnop 1
;;								## 26
	c0    add $r0.8 = $r0.2, 1   ## bblock 93, line 302-5,  t274,  t273,  1(SI32)
;;								## 27
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 93, line 302-5, 0(I32), t274
;;								## 28
	c0    stb 0[$r0.2] = $r0.4   ## bblock 93, line 302-5, t273, t272(SI8)
	c0    br $b0.5, L171?3   ## bblock 93, line 305-5,  t871(I1)
;;								## 29
	c0    ldb $r0.4 = 6[$r0.3]   ## bblock 91, line 302-6, t267(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 91, line 302-6, t268, 0(I32)
	c0    cmpeq $b0.5 = $r0.5, 14   ## [spec] bblock 77, line 305-13,  t863(I1),  t711,  14(SI32)
	      xnop 1
;;								## 31
	c0    add $r0.8 = $r0.2, 1   ## bblock 91, line 302-6,  t269,  t268,  1(SI32)
;;								## 32
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 91, line 302-6, 0(I32), t269
;;								## 33
	c0    stb 0[$r0.2] = $r0.4   ## bblock 91, line 302-6, t268, t267(SI8)
	c0    br $b0.6, L171?3   ## bblock 91, line 305-6,  t870(I1)
;;								## 34
	c0    ldb $r0.4 = 7[$r0.3]   ## bblock 89, line 302-7, t262(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 89, line 302-7, t263, 0(I32)
	c0    cmpeq $b0.6 = $r0.5, 15   ## [spec] bblock 75, line 305-14,  t862(I1),  t711,  15(SI32)
	c0    add $r0.5 = $r0.7, -16   ## [spec] bblock 140, line 305-1,  t711,  t113,  -16(SI32)
	      xnop 1
;;								## 36
	c0    add $r0.8 = $r0.2, 1   ## bblock 89, line 302-7,  t264,  t263,  1(SI32)
;;								## 37
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 89, line 302-7, 0(I32), t264
;;								## 38
	c0    stb 0[$r0.2] = $r0.4   ## bblock 89, line 302-7, t263, t262(SI8)
	c0    br $b0.7, L171?3   ## bblock 89, line 305-7,  t869(I1)
;;								## 39
	c0    ldb $r0.4 = 8[$r0.3]   ## bblock 87, line 302-8, t257(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 87, line 302-8, t258, 0(I32)
	c0    cmpeq $b0.7 = $r0.7, $r0.0   ## [spec] bblock 73, line 305-15,  t861(I1),  t113,  0(SI32)
	      xnop 1
;;								## 41
	c0    add $r0.8 = $r0.2, 1   ## bblock 87, line 302-8,  t259,  t258,  1(SI32)
;;								## 42
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 87, line 302-8, 0(I32), t259
;;								## 43
	c0    stb 0[$r0.2] = $r0.4   ## bblock 87, line 302-8, t258, t257(SI8)
	c0    br $b0.0, L171?3   ## bblock 87, line 305-8,  t868(I1)
;;								## 44
	c0    ldb $r0.4 = 9[$r0.3]   ## bblock 85, line 302-9, t252(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 85, line 302-9, t253, 0(I32)
	c0    cmpeq $b0.0 = $r0.7, 1   ## [spec] bblock 143, line 305-1,  t902(I1),  t113,  1(SI32)
	      xnop 1
;;								## 46
	c0    add $r0.8 = $r0.2, 1   ## bblock 85, line 302-9,  t254,  t253,  1(SI32)
;;								## 47
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 85, line 302-9, 0(I32), t254
;;								## 48
	c0    stb 0[$r0.2] = $r0.4   ## bblock 85, line 302-9, t253, t252(SI8)
	c0    br $b0.1, L171?3   ## bblock 85, line 305-9,  t867(I1)
;;								## 49
	c0    ldb $r0.4 = 10[$r0.3]   ## bblock 83, line 302-10, t247(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 83, line 302-10, t248, 0(I32)
	c0    cmpeq $b0.1 = $r0.7, 2   ## [spec] bblock 63, line 305-1,  t846(I1),  t113,  2(SI32)
	      xnop 1
;;								## 51
	c0    add $r0.8 = $r0.2, 1   ## bblock 83, line 302-10,  t249,  t248,  1(SI32)
;;								## 52
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 83, line 302-10, 0(I32), t249
;;								## 53
	c0    stb 0[$r0.2] = $r0.4   ## bblock 83, line 302-10, t248, t247(SI8)
	c0    br $b0.2, L171?3   ## bblock 83, line 305-10,  t866(I1)
;;								## 54
	c0    ldb $r0.4 = 11[$r0.3]   ## bblock 81, line 302-11, t242(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 81, line 302-11, t243, 0(I32)
	c0    cmpeq $b0.2 = $r0.7, 3   ## [spec] bblock 66, line 305-1,  t851(I1),  t113,  3(SI32)
	      xnop 1
;;								## 56
	c0    add $r0.8 = $r0.2, 1   ## bblock 81, line 302-11,  t244,  t243,  1(SI32)
;;								## 57
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 81, line 302-11, 0(I32), t244
;;								## 58
	c0    stb 0[$r0.2] = $r0.4   ## bblock 81, line 302-11, t243, t242(SI8)
	c0    br $b0.3, L171?3   ## bblock 81, line 305-11,  t865(I1)
;;								## 59
	c0    ldb $r0.4 = 12[$r0.3]   ## bblock 79, line 302-12, t237(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 79, line 302-12, t238, 0(I32)
	c0    cmpeq $b0.3 = $r0.7, 4   ## [spec] bblock 104, line 305-1,  t876(I1),  t113,  4(SI32)
	      xnop 1
;;								## 61
	c0    add $r0.8 = $r0.2, 1   ## bblock 79, line 302-12,  t239,  t238,  1(SI32)
;;								## 62
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 79, line 302-12, 0(I32), t239
;;								## 63
	c0    stb 0[$r0.2] = $r0.4   ## bblock 79, line 302-12, t238, t237(SI8)
	c0    br $b0.4, L171?3   ## bblock 79, line 305-12,  t864(I1)
;;								## 64
	c0    ldb $r0.4 = 13[$r0.3]   ## bblock 77, line 302-13, t232(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 77, line 302-13, t233, 0(I32)
	c0    cmpeq $b0.4 = $r0.7, 5   ## [spec] bblock 107, line 305-1,  t878(I1),  t113,  5(SI32)
	      xnop 1
;;								## 66
	c0    add $r0.8 = $r0.2, 1   ## bblock 77, line 302-13,  t234,  t233,  1(SI32)
;;								## 67
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 77, line 302-13, 0(I32), t234
;;								## 68
	c0    stb 0[$r0.2] = $r0.4   ## bblock 77, line 302-13, t233, t232(SI8)
	c0    br $b0.5, L171?3   ## bblock 77, line 305-13,  t863(I1)
;;								## 69
	c0    ldb $r0.4 = 14[$r0.3]   ## bblock 75, line 302-14, t227(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 75, line 302-14, t228, 0(I32)
	c0    cmpeq $b0.5 = $r0.7, 6   ## [spec] bblock 110, line 305-1,  t880(I1),  t113,  6(SI32)
	      xnop 1
;;								## 71
	c0    add $r0.8 = $r0.2, 1   ## bblock 75, line 302-14,  t229,  t228,  1(SI32)
;;								## 72
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.8   ## bblock 75, line 302-14, 0(I32), t229
;;								## 73
	c0    stb 0[$r0.2] = $r0.4   ## bblock 75, line 302-14, t228, t227(SI8)
	c0    br $b0.6, L171?3   ## bblock 75, line 305-14,  t862(I1)
;;								## 74
	c0    ldb $r0.3 = 15[$r0.3]   ## bblock 73, line 302-15, t224(SI8), t710
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 73, line 302-15, t225, 0(I32)
	c0    cmpeq $b0.6 = $r0.7, 7   ## [spec] bblock 113, line 305-1,  t882(I1),  t113,  7(SI32)
	      xnop 1
;;								## 76
	c0    add $r0.4 = $r0.2, 1   ## bblock 73, line 302-15,  t226,  t225,  1(SI32)
;;								## 77
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 73, line 302-15, 0(I32), t226
;;								## 78
	c0    stb 0[$r0.2] = $r0.3   ## bblock 73, line 302-15, t225, t224(SI8)
	c0    cmpeq $b0.7 = $r0.5, $r0.0   ## [spec] bblock 140, line 305-1,  t900(I1),  t711,  0(SI32)
	c0    br $b0.7, L171?3   ## bblock 73, line 305-15,  t861(I1)
;;								## 79
	c0    ldb $r0.4 = 0[$r0.6]   ## bblock 143, line 302-1, t718(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 143, line 302-1, t716, 0(I32)
	c0    cmpeq $b0.7 = $r0.7, 8   ## [spec] bblock 116, line 305-1,  t884(I1),  t113,  8(SI32)
	c0    add $r0.3 = $r0.6, 16   ## [spec] bblock 140, line 303-1,  t710,  t114,  16(SI32)
	c0    mfb $r0.8 = $b0.7   ## [spec] t900(I1)
	      xnop 1
;;								## 81
	c0    add $r0.9 = $r0.2, 1   ## bblock 143, line 302-1,  t715,  t716,  1(SI32)
;;								## 82
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.9   ## bblock 143, line 302-1, 0(I32), t715
;;								## 83
	c0    stb 0[$r0.2] = $r0.4   ## bblock 143, line 302-1, t716, t718(SI8)
	c0    br $b0.0, L171?3   ## bblock 143, line 305-1,  t902(I1)
;;								## 84
	c0    ldb $r0.4 = 1[$r0.6]   ## bblock 63, line 302-1, t670(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 63, line 302-1, t669, 0(I32)
	c0    cmpeq $b0.0 = $r0.7, 9   ## [spec] bblock 119, line 305-1,  t886(I1),  t113,  9(SI32)
	      xnop 1
;;								## 86
	c0    add $r0.9 = $r0.2, 1   ## bblock 63, line 302-1,  t668,  t669,  1(SI32)
;;								## 87
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.9   ## bblock 63, line 302-1, 0(I32), t668
;;								## 88
	c0    stb 0[$r0.2] = $r0.4   ## bblock 63, line 302-1, t669, t670(SI8)
	c0    br $b0.1, L171?3   ## bblock 63, line 305-1,  t846(I1)
;;								## 89
	c0    ldb $r0.4 = 2[$r0.6]   ## bblock 66, line 302-1, t673(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 66, line 302-1, t672, 0(I32)
	c0    cmpeq $b0.1 = $r0.7, 10   ## [spec] bblock 122, line 305-1,  t888(I1),  t113,  10(SI32)
	      xnop 1
;;								## 91
	c0    add $r0.9 = $r0.2, 1   ## bblock 66, line 302-1,  t671,  t672,  1(SI32)
;;								## 92
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.9   ## bblock 66, line 302-1, 0(I32), t671
;;								## 93
	c0    stb 0[$r0.2] = $r0.4   ## bblock 66, line 302-1, t672, t673(SI8)
	c0    br $b0.2, L171?3   ## bblock 66, line 305-1,  t851(I1)
;;								## 94
	c0    ldb $r0.4 = 3[$r0.6]   ## bblock 104, line 302-1, t676(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 104, line 302-1, t675, 0(I32)
	c0    cmpeq $b0.2 = $r0.7, 11   ## [spec] bblock 125, line 305-1,  t890(I1),  t113,  11(SI32)
	      xnop 1
;;								## 96
	c0    add $r0.9 = $r0.2, 1   ## bblock 104, line 302-1,  t674,  t675,  1(SI32)
;;								## 97
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.9   ## bblock 104, line 302-1, 0(I32), t674
;;								## 98
	c0    stb 0[$r0.2] = $r0.4   ## bblock 104, line 302-1, t675, t676(SI8)
	c0    br $b0.3, L171?3   ## bblock 104, line 305-1,  t876(I1)
;;								## 99
	c0    ldb $r0.4 = 4[$r0.6]   ## bblock 107, line 302-1, t679(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 107, line 302-1, t678, 0(I32)
	c0    cmpeq $b0.3 = $r0.7, 12   ## [spec] bblock 128, line 305-1,  t892(I1),  t113,  12(SI32)
	      xnop 1
;;								## 101
	c0    add $r0.9 = $r0.2, 1   ## bblock 107, line 302-1,  t677,  t678,  1(SI32)
;;								## 102
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.9   ## bblock 107, line 302-1, 0(I32), t677
;;								## 103
	c0    stb 0[$r0.2] = $r0.4   ## bblock 107, line 302-1, t678, t679(SI8)
	c0    br $b0.4, L171?3   ## bblock 107, line 305-1,  t878(I1)
;;								## 104
	c0    ldb $r0.4 = 5[$r0.6]   ## bblock 110, line 302-1, t682(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 110, line 302-1, t681, 0(I32)
	c0    cmpeq $b0.4 = $r0.7, 13   ## [spec] bblock 131, line 305-1,  t894(I1),  t113,  13(SI32)
	      xnop 1
;;								## 106
	c0    add $r0.9 = $r0.2, 1   ## bblock 110, line 302-1,  t680,  t681,  1(SI32)
;;								## 107
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.9   ## bblock 110, line 302-1, 0(I32), t680
;;								## 108
	c0    stb 0[$r0.2] = $r0.4   ## bblock 110, line 302-1, t681, t682(SI8)
	c0    br $b0.5, L171?3   ## bblock 110, line 305-1,  t880(I1)
;;								## 109
	c0    ldb $r0.4 = 6[$r0.6]   ## bblock 113, line 302-1, t685(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 113, line 302-1, t684, 0(I32)
	c0    cmpeq $b0.5 = $r0.7, 14   ## [spec] bblock 134, line 305-1,  t896(I1),  t113,  14(SI32)
	      xnop 1
;;								## 111
	c0    add $r0.9 = $r0.2, 1   ## bblock 113, line 302-1,  t683,  t684,  1(SI32)
;;								## 112
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.9   ## bblock 113, line 302-1, 0(I32), t683
;;								## 113
	c0    stb 0[$r0.2] = $r0.4   ## bblock 113, line 302-1, t684, t685(SI8)
	c0    br $b0.6, L171?3   ## bblock 113, line 305-1,  t882(I1)
;;								## 114
	c0    ldb $r0.4 = 7[$r0.6]   ## bblock 116, line 302-1, t688(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 116, line 302-1, t687, 0(I32)
	c0    cmpeq $b0.6 = $r0.7, 15   ## [spec] bblock 137, line 305-1,  t898(I1),  t113,  15(SI32)
	      xnop 1
;;								## 116
	c0    add $r0.7 = $r0.2, 1   ## bblock 116, line 302-1,  t686,  t687,  1(SI32)
;;								## 117
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.7   ## bblock 116, line 302-1, 0(I32), t686
;;								## 118
	c0    stb 0[$r0.2] = $r0.4   ## bblock 116, line 302-1, t687, t688(SI8)
	c0    br $b0.7, L171?3   ## bblock 116, line 305-1,  t884(I1)
;;								## 119
	c0    ldb $r0.4 = 8[$r0.6]   ## bblock 119, line 302-1, t691(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 119, line 302-1, t690, 0(I32)
	c0    mtb $b0.7 = $r0.8   ## [spec] t900(I1)
	      xnop 1
;;								## 121
	c0    add $r0.7 = $r0.2, 1   ## bblock 119, line 302-1,  t689,  t690,  1(SI32)
;;								## 122
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.7   ## bblock 119, line 302-1, 0(I32), t689
;;								## 123
	c0    stb 0[$r0.2] = $r0.4   ## bblock 119, line 302-1, t690, t691(SI8)
	c0    br $b0.0, L171?3   ## bblock 119, line 305-1,  t886(I1)
;;								## 124
	c0    ldb $r0.4 = 9[$r0.6]   ## bblock 122, line 302-1, t694(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 122, line 302-1, t693, 0(I32)
	      xnop 1
;;								## 126
	c0    add $r0.7 = $r0.2, 1   ## bblock 122, line 302-1,  t692,  t693,  1(SI32)
;;								## 127
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.7   ## bblock 122, line 302-1, 0(I32), t692
;;								## 128
	c0    stb 0[$r0.2] = $r0.4   ## bblock 122, line 302-1, t693, t694(SI8)
	c0    br $b0.1, L171?3   ## bblock 122, line 305-1,  t888(I1)
;;								## 129
	c0    ldb $r0.4 = 10[$r0.6]   ## bblock 125, line 302-1, t697(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 125, line 302-1, t696, 0(I32)
	      xnop 1
;;								## 131
	c0    add $r0.7 = $r0.2, 1   ## bblock 125, line 302-1,  t695,  t696,  1(SI32)
;;								## 132
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.7   ## bblock 125, line 302-1, 0(I32), t695
;;								## 133
	c0    stb 0[$r0.2] = $r0.4   ## bblock 125, line 302-1, t696, t697(SI8)
	c0    br $b0.2, L171?3   ## bblock 125, line 305-1,  t890(I1)
;;								## 134
	c0    ldb $r0.4 = 11[$r0.6]   ## bblock 128, line 302-1, t700(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 128, line 302-1, t699, 0(I32)
	      xnop 1
;;								## 136
	c0    add $r0.7 = $r0.2, 1   ## bblock 128, line 302-1,  t698,  t699,  1(SI32)
;;								## 137
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.7   ## bblock 128, line 302-1, 0(I32), t698
;;								## 138
	c0    stb 0[$r0.2] = $r0.4   ## bblock 128, line 302-1, t699, t700(SI8)
	c0    br $b0.3, L171?3   ## bblock 128, line 305-1,  t892(I1)
;;								## 139
	c0    ldb $r0.4 = 12[$r0.6]   ## bblock 131, line 302-1, t703(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 131, line 302-1, t702, 0(I32)
	      xnop 1
;;								## 141
	c0    add $r0.7 = $r0.2, 1   ## bblock 131, line 302-1,  t701,  t702,  1(SI32)
;;								## 142
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.7   ## bblock 131, line 302-1, 0(I32), t701
;;								## 143
	c0    stb 0[$r0.2] = $r0.4   ## bblock 131, line 302-1, t702, t703(SI8)
	c0    br $b0.4, L171?3   ## bblock 131, line 305-1,  t894(I1)
;;								## 144
	c0    ldb $r0.4 = 13[$r0.6]   ## bblock 134, line 302-1, t706(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 134, line 302-1, t705, 0(I32)
	      xnop 1
;;								## 146
	c0    add $r0.7 = $r0.2, 1   ## bblock 134, line 302-1,  t704,  t705,  1(SI32)
;;								## 147
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.7   ## bblock 134, line 302-1, 0(I32), t704
;;								## 148
	c0    stb 0[$r0.2] = $r0.4   ## bblock 134, line 302-1, t705, t706(SI8)
	c0    br $b0.5, L171?3   ## bblock 134, line 305-1,  t896(I1)
;;								## 149
	c0    ldb $r0.4 = 14[$r0.6]   ## bblock 137, line 302-1, t709(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 137, line 302-1, t708, 0(I32)
	      xnop 1
;;								## 151
	c0    add $r0.7 = $r0.2, 1   ## bblock 137, line 302-1,  t707,  t708,  1(SI32)
;;								## 152
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.7   ## bblock 137, line 302-1, 0(I32), t707
;;								## 153
	c0    stb 0[$r0.2] = $r0.4   ## bblock 137, line 302-1, t708, t709(SI8)
	c0    br $b0.6, L171?3   ## bblock 137, line 305-1,  t898(I1)
;;								## 154
	c0    ldb $r0.6 = 15[$r0.6]   ## bblock 140, line 302-1, t714(SI8), t114
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 140, line 302-1, t713, 0(I32)
	      xnop 1
;;								## 156
	c0    add $r0.4 = $r0.2, 1   ## bblock 140, line 302-1,  t712,  t713,  1(SI32)
;;								## 157
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 140, line 302-1, 0(I32), t712
;;								## 158
	c0    stb 0[$r0.2] = $r0.6   ## bblock 140, line 302-1, t713, t714(SI8)
	c0    br $b0.7, L171?3   ## bblock 140, line 305-1,  t900(I1)
	      ## goto
;;
	c0    goto L170?3 ## goto
;;								## 159
.trace 15
L171?3:
	c0    stw ((compress_16460.offset + 0) + 0)[$r0.0] = $r0.0   ## bblock 23, line 306, 0(I32), 0(SI32)
;;								## 0
.trace 9
L169?3:
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 10, line 308, t49, 0(I32)
	c0    ldw $r0.4 = ((maxcode + 0) + 0)[$r0.0]   ## bblock 10, line 308, t50, 0(I32)
	c0    ldw $r0.6 = ((clear_flg + 0) + 0)[$r0.0]   ## bblock 10, line 308, t52, 0(I32)
	c0    ldw.d $r0.22 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## [spec] bblock 11, line 310, t54, 0(I32)
	c0    mov $r0.8 = 2   ## [spec] bblock 17, line 0,  t371,  2(I32)
	c0    mov $r0.9 = 3   ## [spec] bblock 17, line 0,  t372,  3(I32)
	c0    mov $r0.10 = 4   ## [spec] bblock 17, line 0,  t373,  4(I32)
	c0    mov $r0.11 = 5   ## [spec] bblock 17, line 0,  t374,  5(I32)
	c0    mov $r0.12 = 6   ## [spec] bblock 17, line 0,  t375,  6(I32)
	c0    mov $r0.13 = 7   ## [spec] bblock 17, line 0,  t376,  7(I32)
	c0    mov $r0.14 = 8   ## [spec] bblock 17, line 0,  t377,  8(I32)
	c0    mov $r0.15 = 9   ## [spec] bblock 17, line 0,  t378,  9(I32)
	c0    mov $r0.16 = 10   ## [spec] bblock 17, line 0,  t628,  10(I32)
	c0    mov $r0.17 = 11   ## [spec] bblock 17, line 0,  t626,  11(I32)
	c0    mov $r0.18 = 12   ## [spec] bblock 17, line 0,  t627,  12(I32)
	c0    mov $r0.19 = 13   ## [spec] bblock 17, line 0,  t624,  13(I32)
	c0    mov $r0.20 = 14   ## [spec] bblock 17, line 0,  t625,  14(I32)
	c0    mov $r0.21 = 15   ## [spec] bblock 17, line 0,  t629,  15(I32)
	c0    mov $r0.7 = 1   ## [spec] bblock 17, line 0,  t385,  1(I32)
	c0    mov $r0.5 = (compress_16460.buf + 0)   ## [spec] bblock 17, line 0,  t630,  addr(compress_16460.buf?1.0)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## [spec] bblock 17, line 312,  t138,  0(SI32)
;;								## 1
	c0    cmpgt $r0.2 = $r0.2, $r0.4   ## bblock 10, line 308,  t51,  t49,  t50
	c0    cmpgt $r0.6 = $r0.6, $r0.0   ## bblock 10, line 308,  t53,  t52,  0(SI32)
	c0    cmpgt $b0.0 = $r0.22, $r0.0   ## [spec] bblock 11, line 310,  t786(I1),  t54,  0(SI32)
;;								## 2
	c0    orl $b0.1 = $r0.2, $r0.6   ## bblock 10, line 308,  t785(I1),  t51,  t53
;;								## 3
	c0    brf $b0.1, L172?3   ## bblock 10, line 308,  t785(I1)
;;								## 4
	c0    brf $b0.0, L173?3   ## bblock 11, line 310,  t786(I1)
;;								## 5
.trace 5
L174?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 18, line 312, t666, 0(I32)
	c0    ldb.d $r0.6 = 0[$r0.5]   ## [spec] bblock 20, line 313, t648(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 20, line 313, t647, 0(I32)
	c0    add $r0.22 = $r0.7, 16   ## [spec] bblock 105, line 0,  t623,  t385,  16(I32)
	c0    add $r0.23 = $r0.20, 16   ## [spec] bblock 105, line 0,  t383,  t625,  16(I32)
	c0    add $r0.24 = $r0.19, 16   ## [spec] bblock 105, line 0,  t382,  t624,  16(I32)
	c0    add $r0.25 = $r0.18, 16   ## [spec] bblock 105, line 0,  t381,  t627,  16(I32)
	c0    add $r0.26 = $r0.17, 16   ## [spec] bblock 105, line 0,  t380,  t626,  16(I32)
	c0    add $r0.27 = $r0.16, 16   ## [spec] bblock 105, line 0,  t379,  t628,  16(I32)
	c0    add $r0.28 = $r0.15, 16   ## [spec] bblock 105, line 0,  t641,  t378,  16(I32)
	c0    add $r0.29 = $r0.14, 16   ## [spec] bblock 105, line 0,  t643,  t377,  16(I32)
	c0    add $r0.30 = $r0.13, 16   ## [spec] bblock 105, line 0,  t644,  t376,  16(I32)
	c0    add $r0.31 = $r0.12, 16   ## [spec] bblock 105, line 0,  t645,  t375,  16(I32)
	c0    add $r0.32 = $r0.11, 16   ## [spec] bblock 105, line 0,  t637,  t374,  16(I32)
	c0    add $r0.33 = $r0.10, 16   ## [spec] bblock 105, line 0,  t636,  t373,  16(I32)
	c0    add $r0.34 = $r0.9, 16   ## [spec] bblock 105, line 0,  t635,  t372,  16(I32)
	c0    add $r0.35 = $r0.8, 16   ## [spec] bblock 105, line 0,  t634,  t371,  16(I32)
	c0    add $r0.36 = $r0.21, 16   ## [spec] bblock 105, line 0,  t384,  t629,  16(I32)
	c0    add $r0.37 = $r0.5, 16   ## [spec] bblock 105, line 0,  t386,  t630,  16(I32)
	c0    add $r0.38 = $r0.3, 16   ## [spec] bblock 105, line 312-15,  t633,  t138,  16(SI32)
	      xnop 1
;;								## 1
	c0    cmplt $b0.0 = $r0.3, $r0.2   ## bblock 18, line 312,  t789(I1),  t138,  t666
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 20, line 313,  t622,  t647,  1(SI32)
	c0    add $r0.3 = $r0.38, 16   ## [spec] bblock 54, line 312-1,  t138,  t633,  16(SI32)
;;								## 2
	c0    brf $b0.0, L175?3   ## bblock 18, line 312,  t789(I1)
;;								## 3
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 20, line 313, 0(I32), t622
;;								## 4
	c0    stb 0[$r0.4] = $r0.6   ## bblock 20, line 313, t647, t648(SI8)
;;								## 5
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 20, line 312-1, t621, 0(I32)
	c0    ldb.d $r0.6 = 1[$r0.5]   ## [spec] bblock 147, line 313-1, t367(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 147, line 313-1, t368, 0(I32)
	      xnop 1
;;								## 7
	c0    cmplt $b0.0 = $r0.7, $r0.2   ## bblock 20, line 312-1,  t790(I1),  t385,  t621
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 147, line 313-1,  t369,  t368,  1(SI32)
	c0    add $r0.7 = $r0.22, 16   ## [spec] bblock 54, line 0-1,  t385,  t623,  16(I32)
;;								## 8
	c0    brf $b0.0, L175?3   ## bblock 20, line 312-1,  t790(I1)
;;								## 9
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 147, line 313-1, 0(I32), t369
;;								## 10
	c0    stb 0[$r0.4] = $r0.6   ## bblock 147, line 313-1, t368, t367(SI8)
;;								## 11
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 147, line 312-2, t361, 0(I32)
	c0    ldb.d $r0.6 = 2[$r0.5]   ## [spec] bblock 144, line 313-2, t362(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 144, line 313-2, t363, 0(I32)
	      xnop 1
;;								## 13
	c0    cmplt $b0.0 = $r0.8, $r0.2   ## bblock 147, line 312-2,  t906(I1),  t371,  t361
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 144, line 313-2,  t364,  t363,  1(SI32)
	c0    add $r0.8 = $r0.35, 16   ## [spec] bblock 54, line 0-1,  t371,  t634,  16(I32)
;;								## 14
	c0    brf $b0.0, L175?3   ## bblock 147, line 312-2,  t906(I1)
;;								## 15
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 144, line 313-2, 0(I32), t364
;;								## 16
	c0    stb 0[$r0.4] = $r0.6   ## bblock 144, line 313-2, t363, t362(SI8)
;;								## 17
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 144, line 312-3, t356, 0(I32)
	c0    ldb.d $r0.6 = 3[$r0.5]   ## [spec] bblock 141, line 313-3, t357(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 141, line 313-3, t358, 0(I32)
	      xnop 1
;;								## 19
	c0    cmplt $b0.0 = $r0.9, $r0.2   ## bblock 144, line 312-3,  t903(I1),  t372,  t356
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 141, line 313-3,  t359,  t358,  1(SI32)
	c0    add $r0.9 = $r0.34, 16   ## [spec] bblock 54, line 0-1,  t372,  t635,  16(I32)
;;								## 20
	c0    brf $b0.0, L175?3   ## bblock 144, line 312-3,  t903(I1)
;;								## 21
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 141, line 313-3, 0(I32), t359
;;								## 22
	c0    stb 0[$r0.4] = $r0.6   ## bblock 141, line 313-3, t358, t357(SI8)
;;								## 23
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 141, line 312-4, t351, 0(I32)
	c0    ldb.d $r0.6 = 4[$r0.5]   ## [spec] bblock 138, line 313-4, t352(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 138, line 313-4, t353, 0(I32)
	      xnop 1
;;								## 25
	c0    cmplt $b0.0 = $r0.10, $r0.2   ## bblock 141, line 312-4,  t901(I1),  t373,  t351
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 138, line 313-4,  t354,  t353,  1(SI32)
	c0    add $r0.10 = $r0.33, 16   ## [spec] bblock 54, line 0-1,  t373,  t636,  16(I32)
;;								## 26
	c0    brf $b0.0, L175?3   ## bblock 141, line 312-4,  t901(I1)
;;								## 27
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 138, line 313-4, 0(I32), t354
;;								## 28
	c0    stb 0[$r0.4] = $r0.6   ## bblock 138, line 313-4, t353, t352(SI8)
;;								## 29
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 138, line 312-5, t346, 0(I32)
	c0    ldb.d $r0.6 = 5[$r0.5]   ## [spec] bblock 135, line 313-5, t347(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 135, line 313-5, t348, 0(I32)
	      xnop 1
;;								## 31
	c0    cmplt $b0.0 = $r0.11, $r0.2   ## bblock 138, line 312-5,  t899(I1),  t374,  t346
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 135, line 313-5,  t349,  t348,  1(SI32)
	c0    add $r0.11 = $r0.32, 16   ## [spec] bblock 54, line 0-1,  t374,  t637,  16(I32)
;;								## 32
	c0    brf $b0.0, L175?3   ## bblock 138, line 312-5,  t899(I1)
;;								## 33
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 135, line 313-5, 0(I32), t349
;;								## 34
	c0    stb 0[$r0.4] = $r0.6   ## bblock 135, line 313-5, t348, t347(SI8)
;;								## 35
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 135, line 312-6, t341, 0(I32)
	c0    ldb.d $r0.6 = 6[$r0.5]   ## [spec] bblock 132, line 313-6, t342(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 132, line 313-6, t343, 0(I32)
	      xnop 1
;;								## 37
	c0    cmplt $b0.0 = $r0.12, $r0.2   ## bblock 135, line 312-6,  t897(I1),  t375,  t341
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 132, line 313-6,  t344,  t343,  1(SI32)
	c0    add $r0.12 = $r0.31, 16   ## [spec] bblock 54, line 0-1,  t375,  t645,  16(I32)
;;								## 38
	c0    brf $b0.0, L175?3   ## bblock 135, line 312-6,  t897(I1)
;;								## 39
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 132, line 313-6, 0(I32), t344
;;								## 40
	c0    stb 0[$r0.4] = $r0.6   ## bblock 132, line 313-6, t343, t342(SI8)
;;								## 41
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 132, line 312-7, t336, 0(I32)
	c0    ldb.d $r0.6 = 7[$r0.5]   ## [spec] bblock 129, line 313-7, t337(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 129, line 313-7, t338, 0(I32)
	      xnop 1
;;								## 43
	c0    cmplt $b0.0 = $r0.13, $r0.2   ## bblock 132, line 312-7,  t895(I1),  t376,  t336
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 129, line 313-7,  t339,  t338,  1(SI32)
	c0    add $r0.13 = $r0.30, 16   ## [spec] bblock 54, line 0-1,  t376,  t644,  16(I32)
;;								## 44
	c0    brf $b0.0, L175?3   ## bblock 132, line 312-7,  t895(I1)
;;								## 45
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 129, line 313-7, 0(I32), t339
;;								## 46
	c0    stb 0[$r0.4] = $r0.6   ## bblock 129, line 313-7, t338, t337(SI8)
;;								## 47
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 129, line 312-8, t331, 0(I32)
	c0    ldb.d $r0.6 = 8[$r0.5]   ## [spec] bblock 126, line 313-8, t332(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 126, line 313-8, t333, 0(I32)
	      xnop 1
;;								## 49
	c0    cmplt $b0.0 = $r0.14, $r0.2   ## bblock 129, line 312-8,  t893(I1),  t377,  t331
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 126, line 313-8,  t334,  t333,  1(SI32)
	c0    add $r0.14 = $r0.29, 16   ## [spec] bblock 54, line 0-1,  t377,  t643,  16(I32)
;;								## 50
	c0    brf $b0.0, L175?3   ## bblock 129, line 312-8,  t893(I1)
;;								## 51
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 126, line 313-8, 0(I32), t334
;;								## 52
	c0    stb 0[$r0.4] = $r0.6   ## bblock 126, line 313-8, t333, t332(SI8)
;;								## 53
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 126, line 312-9, t326, 0(I32)
	c0    ldb.d $r0.6 = 9[$r0.5]   ## [spec] bblock 123, line 313-9, t327(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 123, line 313-9, t328, 0(I32)
	      xnop 1
;;								## 55
	c0    cmplt $b0.0 = $r0.15, $r0.2   ## bblock 126, line 312-9,  t891(I1),  t378,  t326
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 123, line 313-9,  t329,  t328,  1(SI32)
	c0    add $r0.15 = $r0.28, 16   ## [spec] bblock 54, line 0-1,  t378,  t641,  16(I32)
;;								## 56
	c0    brf $b0.0, L175?3   ## bblock 126, line 312-9,  t891(I1)
;;								## 57
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 123, line 313-9, 0(I32), t329
;;								## 58
	c0    stb 0[$r0.4] = $r0.6   ## bblock 123, line 313-9, t328, t327(SI8)
;;								## 59
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 123, line 312-10, t321, 0(I32)
	c0    ldb.d $r0.6 = 10[$r0.5]   ## [spec] bblock 120, line 313-10, t322(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 120, line 313-10, t323, 0(I32)
	      xnop 1
;;								## 61
	c0    cmplt $b0.0 = $r0.16, $r0.2   ## bblock 123, line 312-10,  t889(I1),  t628,  t321
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 120, line 313-10,  t324,  t323,  1(SI32)
	c0    add $r0.16 = $r0.27, 16   ## [spec] bblock 54, line 0-1,  t628,  t379,  16(I32)
;;								## 62
	c0    brf $b0.0, L175?3   ## bblock 123, line 312-10,  t889(I1)
;;								## 63
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 120, line 313-10, 0(I32), t324
;;								## 64
	c0    stb 0[$r0.4] = $r0.6   ## bblock 120, line 313-10, t323, t322(SI8)
;;								## 65
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 120, line 312-11, t316, 0(I32)
	c0    ldb.d $r0.6 = 11[$r0.5]   ## [spec] bblock 117, line 313-11, t317(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 117, line 313-11, t318, 0(I32)
	      xnop 1
;;								## 67
	c0    cmplt $b0.0 = $r0.17, $r0.2   ## bblock 120, line 312-11,  t887(I1),  t626,  t316
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 117, line 313-11,  t319,  t318,  1(SI32)
	c0    add $r0.17 = $r0.26, 16   ## [spec] bblock 54, line 0-1,  t626,  t380,  16(I32)
;;								## 68
	c0    brf $b0.0, L175?3   ## bblock 120, line 312-11,  t887(I1)
;;								## 69
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 117, line 313-11, 0(I32), t319
;;								## 70
	c0    stb 0[$r0.4] = $r0.6   ## bblock 117, line 313-11, t318, t317(SI8)
;;								## 71
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 117, line 312-12, t311, 0(I32)
	c0    ldb.d $r0.6 = 12[$r0.5]   ## [spec] bblock 114, line 313-12, t312(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 114, line 313-12, t313, 0(I32)
	      xnop 1
;;								## 73
	c0    cmplt $b0.0 = $r0.18, $r0.2   ## bblock 117, line 312-12,  t885(I1),  t627,  t311
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 114, line 313-12,  t314,  t313,  1(SI32)
	c0    add $r0.18 = $r0.25, 16   ## [spec] bblock 54, line 0-1,  t627,  t381,  16(I32)
;;								## 74
	c0    brf $b0.0, L175?3   ## bblock 117, line 312-12,  t885(I1)
;;								## 75
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 114, line 313-12, 0(I32), t314
;;								## 76
	c0    stb 0[$r0.4] = $r0.6   ## bblock 114, line 313-12, t313, t312(SI8)
;;								## 77
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 114, line 312-13, t306, 0(I32)
	c0    ldb.d $r0.6 = 13[$r0.5]   ## [spec] bblock 111, line 313-13, t639(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 111, line 313-13, t638, 0(I32)
	      xnop 1
;;								## 79
	c0    cmplt $b0.0 = $r0.19, $r0.2   ## bblock 114, line 312-13,  t883(I1),  t624,  t306
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 111, line 313-13,  t309,  t638,  1(SI32)
	c0    add $r0.19 = $r0.24, 16   ## [spec] bblock 54, line 0-1,  t624,  t382,  16(I32)
;;								## 80
	c0    brf $b0.0, L175?3   ## bblock 114, line 312-13,  t883(I1)
;;								## 81
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 111, line 313-13, 0(I32), t309
;;								## 82
	c0    stb 0[$r0.4] = $r0.6   ## bblock 111, line 313-13, t638, t639(SI8)
;;								## 83
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 111, line 312-14, t301, 0(I32)
	c0    ldb.d $r0.6 = 14[$r0.5]   ## [spec] bblock 108, line 313-14, t632(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 108, line 313-14, t631, 0(I32)
	      xnop 1
;;								## 85
	c0    cmplt $b0.0 = $r0.20, $r0.2   ## bblock 111, line 312-14,  t881(I1),  t625,  t301
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 108, line 313-14,  t642,  t631,  1(SI32)
	c0    add $r0.20 = $r0.23, 16   ## [spec] bblock 54, line 0-1,  t625,  t383,  16(I32)
;;								## 86
	c0    brf $b0.0, L175?3   ## bblock 111, line 312-14,  t881(I1)
;;								## 87
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 108, line 313-14, 0(I32), t642
;;								## 88
	c0    stb 0[$r0.4] = $r0.6   ## bblock 108, line 313-14, t631, t632(SI8)
;;								## 89
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 108, line 312-15, t640, 0(I32)
	c0    ldb.d $r0.5 = 15[$r0.5]   ## [spec] bblock 105, line 313-15, t652(SI8), t630
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 105, line 313-15, t654, 0(I32)
	      xnop 1
;;								## 91
	c0    cmplt $b0.0 = $r0.21, $r0.2   ## bblock 108, line 312-15,  t879(I1),  t629,  t640
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 105, line 313-15,  t656,  t654,  1(SI32)
	c0    add $r0.21 = $r0.36, 16   ## [spec] bblock 54, line 0-1,  t629,  t384,  16(I32)
;;								## 92
	c0    brf $b0.0, L175?3   ## bblock 108, line 312-15,  t879(I1)
;;								## 93
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 105, line 313-15, 0(I32), t656
;;								## 94
	c0    stb 0[$r0.4] = $r0.5   ## bblock 105, line 313-15, t654, t652(SI8)
;;								## 95
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 105, line 312-1, t56, 0(I32)
	c0    ldb.d $r0.6 = 0[$r0.37]   ## [spec] bblock 57, line 313-1, t61(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 57, line 313-1, t62, 0(I32)
	c0    add $r0.5 = $r0.37, 16   ## [spec] bblock 54, line 0-1,  t630,  t386,  16(I32)
	      xnop 1
;;								## 97
	c0    cmplt $b0.0 = $r0.38, $r0.2   ## bblock 105, line 312-1,  t877(I1),  t633,  t56
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 57, line 313-1,  t63,  t62,  1(SI32)
;;								## 98
	c0    brf $b0.0, L175?3   ## bblock 105, line 312-1,  t877(I1)
;;								## 99
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 57, line 313-1, 0(I32), t63
;;								## 100
	c0    stb 0[$r0.4] = $r0.6   ## bblock 57, line 313-1, t62, t61(SI8)
;;								## 101
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 57, line 312-1, t366, 0(I32)
	c0    ldb.d $r0.6 = 1[$r0.37]   ## [spec] bblock 145, line 313-1, t764(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 145, line 313-1, t765, 0(I32)
	      xnop 1
;;								## 103
	c0    cmplt $b0.0 = $r0.22, $r0.2   ## bblock 57, line 312-1,  t837(I1),  t623,  t366
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 145, line 313-1,  t766,  t765,  1(SI32)
;;								## 104
	c0    brf $b0.0, L175?3   ## bblock 57, line 312-1,  t837(I1)
;;								## 105
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 145, line 313-1, 0(I32), t766
;;								## 106
	c0    stb 0[$r0.4] = $r0.6   ## bblock 145, line 313-1, t765, t764(SI8)
;;								## 107
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 145, line 312-1, t767, 0(I32)
	c0    ldb.d $r0.6 = 2[$r0.37]   ## [spec] bblock 148, line 313-1, t760(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 148, line 313-1, t761, 0(I32)
	      xnop 1
;;								## 109
	c0    cmplt $b0.0 = $r0.35, $r0.2   ## bblock 145, line 312-1,  t904(I1),  t634,  t767
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 148, line 313-1,  t762,  t761,  1(SI32)
;;								## 110
	c0    brf $b0.0, L175?3   ## bblock 145, line 312-1,  t904(I1)
;;								## 111
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 148, line 313-1, 0(I32), t762
;;								## 112
	c0    stb 0[$r0.4] = $r0.6   ## bblock 148, line 313-1, t761, t760(SI8)
;;								## 113
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 148, line 312-1, t763, 0(I32)
	c0    ldb.d $r0.6 = 3[$r0.37]   ## [spec] bblock 149, line 313-1, t756(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 149, line 313-1, t757, 0(I32)
	      xnop 1
;;								## 115
	c0    cmplt $b0.0 = $r0.34, $r0.2   ## bblock 148, line 312-1,  t907(I1),  t635,  t763
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 149, line 313-1,  t758,  t757,  1(SI32)
;;								## 116
	c0    brf $b0.0, L175?3   ## bblock 148, line 312-1,  t907(I1)
;;								## 117
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 149, line 313-1, 0(I32), t758
;;								## 118
	c0    stb 0[$r0.4] = $r0.6   ## bblock 149, line 313-1, t757, t756(SI8)
;;								## 119
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 149, line 312-1, t759, 0(I32)
	c0    ldb.d $r0.6 = 4[$r0.37]   ## [spec] bblock 69, line 313-1, t752(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 69, line 313-1, t753, 0(I32)
	      xnop 1
;;								## 121
	c0    cmplt $b0.0 = $r0.33, $r0.2   ## bblock 149, line 312-1,  t908(I1),  t636,  t759
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 69, line 313-1,  t754,  t753,  1(SI32)
;;								## 122
	c0    brf $b0.0, L175?3   ## bblock 149, line 312-1,  t908(I1)
;;								## 123
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 69, line 313-1, 0(I32), t754
;;								## 124
	c0    stb 0[$r0.4] = $r0.6   ## bblock 69, line 313-1, t753, t752(SI8)
;;								## 125
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 69, line 312-1, t755, 0(I32)
	c0    ldb.d $r0.6 = 5[$r0.37]   ## [spec] bblock 146, line 313-1, t748(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 146, line 313-1, t749, 0(I32)
	      xnop 1
;;								## 127
	c0    cmplt $b0.0 = $r0.32, $r0.2   ## bblock 69, line 312-1,  t856(I1),  t637,  t755
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 146, line 313-1,  t750,  t749,  1(SI32)
;;								## 128
	c0    brf $b0.0, L175?3   ## bblock 69, line 312-1,  t856(I1)
;;								## 129
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 146, line 313-1, 0(I32), t750
;;								## 130
	c0    stb 0[$r0.4] = $r0.6   ## bblock 146, line 313-1, t749, t748(SI8)
;;								## 131
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 146, line 312-1, t751, 0(I32)
	c0    ldb.d $r0.6 = 6[$r0.37]   ## [spec] bblock 27, line 313-1, t721(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 27, line 313-1, t720, 0(I32)
	      xnop 1
;;								## 133
	c0    cmplt $b0.0 = $r0.31, $r0.2   ## bblock 146, line 312-1,  t905(I1),  t645,  t751
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 27, line 313-1,  t719,  t720,  1(SI32)
;;								## 134
	c0    brf $b0.0, L175?3   ## bblock 146, line 312-1,  t905(I1)
;;								## 135
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 27, line 313-1, 0(I32), t719
;;								## 136
	c0    stb 0[$r0.4] = $r0.6   ## bblock 27, line 313-1, t720, t721(SI8)
;;								## 137
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 27, line 312-1, t747, 0(I32)
	c0    ldb.d $r0.6 = 7[$r0.37]   ## [spec] bblock 30, line 313-1, t725(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 30, line 313-1, t724, 0(I32)
	      xnop 1
;;								## 139
	c0    cmplt $b0.0 = $r0.30, $r0.2   ## bblock 27, line 312-1,  t792(I1),  t644,  t747
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 30, line 313-1,  t723,  t724,  1(SI32)
;;								## 140
	c0    brf $b0.0, L175?3   ## bblock 27, line 312-1,  t792(I1)
;;								## 141
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 30, line 313-1, 0(I32), t723
;;								## 142
	c0    stb 0[$r0.4] = $r0.6   ## bblock 30, line 313-1, t724, t725(SI8)
;;								## 143
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 30, line 312-1, t722, 0(I32)
	c0    ldb.d $r0.6 = 8[$r0.37]   ## [spec] bblock 33, line 313-1, t729(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 33, line 313-1, t728, 0(I32)
	      xnop 1
;;								## 145
	c0    cmplt $b0.0 = $r0.29, $r0.2   ## bblock 30, line 312-1,  t793(I1),  t643,  t722
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 33, line 313-1,  t727,  t728,  1(SI32)
;;								## 146
	c0    brf $b0.0, L175?3   ## bblock 30, line 312-1,  t793(I1)
;;								## 147
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 33, line 313-1, 0(I32), t727
;;								## 148
	c0    stb 0[$r0.4] = $r0.6   ## bblock 33, line 313-1, t728, t729(SI8)
;;								## 149
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 33, line 312-1, t726, 0(I32)
	c0    ldb.d $r0.6 = 9[$r0.37]   ## [spec] bblock 36, line 313-1, t733(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 36, line 313-1, t732, 0(I32)
	      xnop 1
;;								## 151
	c0    cmplt $b0.0 = $r0.28, $r0.2   ## bblock 33, line 312-1,  t798(I1),  t641,  t726
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 36, line 313-1,  t731,  t732,  1(SI32)
;;								## 152
	c0    brf $b0.0, L175?3   ## bblock 33, line 312-1,  t798(I1)
;;								## 153
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 36, line 313-1, 0(I32), t731
;;								## 154
	c0    stb 0[$r0.4] = $r0.6   ## bblock 36, line 313-1, t732, t733(SI8)
;;								## 155
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 36, line 312-1, t730, 0(I32)
	c0    ldb.d $r0.6 = 10[$r0.37]   ## [spec] bblock 39, line 313-1, t737(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 39, line 313-1, t736, 0(I32)
	      xnop 1
;;								## 157
	c0    cmplt $b0.0 = $r0.27, $r0.2   ## bblock 36, line 312-1,  t803(I1),  t379,  t730
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 39, line 313-1,  t735,  t736,  1(SI32)
;;								## 158
	c0    brf $b0.0, L175?3   ## bblock 36, line 312-1,  t803(I1)
;;								## 159
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 39, line 313-1, 0(I32), t735
;;								## 160
	c0    stb 0[$r0.4] = $r0.6   ## bblock 39, line 313-1, t736, t737(SI8)
;;								## 161
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 39, line 312-1, t734, 0(I32)
	c0    ldb.d $r0.6 = 11[$r0.37]   ## [spec] bblock 42, line 313-1, t741(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 42, line 313-1, t740, 0(I32)
	      xnop 1
;;								## 163
	c0    cmplt $b0.0 = $r0.26, $r0.2   ## bblock 39, line 312-1,  t808(I1),  t380,  t734
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 42, line 313-1,  t739,  t740,  1(SI32)
;;								## 164
	c0    brf $b0.0, L175?3   ## bblock 39, line 312-1,  t808(I1)
;;								## 165
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 42, line 313-1, 0(I32), t739
;;								## 166
	c0    stb 0[$r0.4] = $r0.6   ## bblock 42, line 313-1, t740, t741(SI8)
;;								## 167
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 42, line 312-1, t738, 0(I32)
	c0    ldb.d $r0.6 = 12[$r0.37]   ## [spec] bblock 45, line 313-1, t745(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 45, line 313-1, t744, 0(I32)
	      xnop 1
;;								## 169
	c0    cmplt $b0.0 = $r0.25, $r0.2   ## bblock 42, line 312-1,  t813(I1),  t381,  t738
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 45, line 313-1,  t743,  t744,  1(SI32)
;;								## 170
	c0    brf $b0.0, L175?3   ## bblock 42, line 312-1,  t813(I1)
;;								## 171
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 45, line 313-1, 0(I32), t743
;;								## 172
	c0    stb 0[$r0.4] = $r0.6   ## bblock 45, line 313-1, t744, t745(SI8)
;;								## 173
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 45, line 312-1, t742, 0(I32)
	c0    ldb.d $r0.6 = 13[$r0.37]   ## [spec] bblock 48, line 313-1, t307(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 48, line 313-1, t308, 0(I32)
	      xnop 1
;;								## 175
	c0    cmplt $b0.0 = $r0.24, $r0.2   ## bblock 45, line 312-1,  t818(I1),  t382,  t742
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 48, line 313-1,  t717,  t308,  1(SI32)
;;								## 176
	c0    brf $b0.0, L175?3   ## bblock 45, line 312-1,  t818(I1)
;;								## 177
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 48, line 313-1, 0(I32), t717
;;								## 178
	c0    stb 0[$r0.4] = $r0.6   ## bblock 48, line 313-1, t308, t307(SI8)
;;								## 179
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 48, line 312-1, t746, 0(I32)
	c0    ldb.d $r0.6 = 14[$r0.37]   ## [spec] bblock 51, line 313-1, t302(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 51, line 313-1, t303, 0(I32)
	      xnop 1
;;								## 181
	c0    cmplt $b0.0 = $r0.23, $r0.2   ## bblock 48, line 312-1,  t823(I1),  t383,  t746
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 51, line 313-1,  t304,  t303,  1(SI32)
;;								## 182
	c0    brf $b0.0, L175?3   ## bblock 48, line 312-1,  t823(I1)
;;								## 183
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 51, line 313-1, 0(I32), t304
;;								## 184
	c0    stb 0[$r0.4] = $r0.6   ## bblock 51, line 313-1, t303, t302(SI8)
;;								## 185
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 51, line 312-1, t297, 0(I32)
	c0    ldb.d $r0.37 = 15[$r0.37]   ## [spec] bblock 54, line 313-1, t298(SI8), t386
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 54, line 313-1, t299, 0(I32)
	      xnop 1
;;								## 187
	c0    cmplt $b0.0 = $r0.36, $r0.2   ## bblock 51, line 312-1,  t828(I1),  t384,  t297
	c0    add $r0.2 = $r0.4, 1   ## [spec] bblock 54, line 313-1,  t300,  t299,  1(SI32)
;;								## 188
	c0    brf $b0.0, L175?3   ## bblock 51, line 312-1,  t828(I1)
;;								## 189
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 54, line 313-1, 0(I32), t300
;;								## 190
	c0    stb 0[$r0.4] = $r0.37   ## bblock 54, line 313-1, t299, t298(SI8)
	c0    goto L174?3 ## goto
;;								## 191
.trace 17
L175?3:
	c0    ldw $r0.2 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 19, line 314, t64, 0(I32)
	c0    ldw $r0.3 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 19, line 314, t65, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, $r0.3   ## bblock 19, line 314,  t66,  t64,  t65
;;								## 2
	c0    stw ((bytes_out + 0) + 0)[$r0.0] = $r0.2   ## bblock 19, line 314, 0(I32), t66
;;								## 3
.trace 14
L173?3:
	c0    stw ((compress_16460.offset + 0) + 0)[$r0.0] = $r0.0   ## bblock 12, line 316, 0(I32), 0(SI32)
	c0    ldw $r0.2 = ((clear_flg + 0) + 0)[$r0.0]   ## bblock 12, line 317, t67, 0(I32)
	c0    mov $r0.4 = 511   ## 511(SI32)
	c0    mov $r0.3 = 9   ## 9(SI32)
	      xnop 1
;;								## 1
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 12, line 317,  t787(I1),  t67,  0(SI32)
;;								## 2
	c0    brf $b0.0, L176?3   ## bblock 12, line 317,  t787(I1)
;;								## 3
.return ret()
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.3   ## bblock 16, line 319, 0(I32), 9(SI32)
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.4   ## bblock 16, line 319, 0(I32), 511(SI32)
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.0   ## bblock 16, line 320, 0(I32), 0(SI32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 340,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 4
.trace 16
L176?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 13, line 324, t70, 0(I32)
	c0    ldw $r0.3 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 13, line 325, t73, 0(I32)
	c0    ldw.d $r0.4 = ((maxmaxcode + 0) + 0)[$r0.0]   ## [spec] bblock 15, line 326, t74, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, 1   ## bblock 13, line 324,  t72,  t70,  1(SI32)
;;								## 2
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.2   ## bblock 13, line 324, 0(I32), t72
	c0    cmpeq $b0.0 = $r0.2, $r0.3   ## bblock 13, line 325,  t788(I1),  t72,  t73
;;								## 3
	c0    brf $b0.0, L177?3   ## bblock 13, line 325,  t788(I1)
;;								## 4
.return ret()
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.4   ## bblock 15, line 326, 0(I32), t74
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 340,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 5
.trace 18
L177?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 14, line 328, t75, 0(I32)
	c0    mov $r0.3 = 1   ## 1(SI32)
	      xnop 1
;;								## 1
	c0    shl $r0.3 = $r0.3, $r0.2   ## bblock 14, line 328,  t76,  1(SI32),  t75
;;								## 2
	c0    add $r0.3 = $r0.3, -1   ## bblock 14, line 328,  t77,  t76,  -1(SI32)
;;								## 3
.return ret()
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.3   ## bblock 14, line 328, 0(I32), t77
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 340,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 4
.trace 13
L172?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 340,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 0
.trace 8
L166?3:
	c0    ldw $r0.4 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 1, line 334, t78, 0(I32)
	c0    ldw.d $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## [spec] bblock 2, line 337, t90, 0(I32)
	c0    ldw.d $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## [spec] bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    cmpgt $b0.0 = $r0.4, $r0.0   ## bblock 1, line 334,  t769(I1),  t78,  0(SI32)
	c0    add $r0.2 = $r0.2, 7   ## [spec] bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## [spec] bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## [spec] bblock 2, line 337,  t771,  t92,  7(I32)
	c0    br $b0.0, L178?3   ## bblock 1, line 334,  t769(I1)
;;								## 3
L179?3:
	c0    slct $r0.4 = $b0.1, $r0.4, $r0.2   ## bblock 2, line 337,  t772,  t770,  t771,  t92
	c0    stw ((compress_16460.offset + 0) + 0)[$r0.0] = $r0.0   ## bblock 2, line 338, 0(I32), 0(SI32)
;;								## 4
	c0    shr $r0.4 = $r0.4, 3   ## bblock 2, line 337,  t93,  t772,  3(I32)
;;								## 5
	c0    add $r0.3 = $r0.3, $r0.4   ## bblock 2, line 337,  t94,  t90,  t93
;;								## 6
.return ret()
	c0    stw ((bytes_out + 0) + 0)[$r0.0] = $r0.3   ## bblock 2, line 337, 0(I32), t94
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 3, line 340,  t96,  ?2.6?2auto_size(I32),  t95
;;								## 7
.trace 10
L178?3:
	c0    mov $r0.8 = 2   ## bblock 4, line 0,  t555,  2(I32)
	c0    mov $r0.9 = 3   ## bblock 4, line 0,  t556,  3(I32)
	c0    mov $r0.10 = 4   ## bblock 4, line 0,  t557,  4(I32)
	c0    mov $r0.11 = 5   ## bblock 4, line 0,  t558,  5(I32)
	c0    mov $r0.12 = 6   ## bblock 4, line 0,  t559,  6(I32)
	c0    mov $r0.13 = 7   ## bblock 4, line 0,  t560,  7(I32)
	c0    mov $r0.14 = 8   ## bblock 4, line 0,  t561,  8(I32)
	c0    mov $r0.15 = 9   ## bblock 4, line 0,  t562,  9(I32)
	c0    mov $r0.16 = 10   ## bblock 4, line 0,  t563,  10(I32)
	c0    mov $r0.17 = 11   ## bblock 4, line 0,  t564,  11(I32)
	c0    mov $r0.18 = 12   ## bblock 4, line 0,  t565,  12(I32)
	c0    mov $r0.19 = 13   ## bblock 4, line 0,  t566,  13(I32)
	c0    mov $r0.20 = 14   ## bblock 4, line 0,  t567,  14(I32)
	c0    mov $r0.21 = 15   ## bblock 4, line 0,  t568,  15(I32)
	c0    mov $r0.7 = 1   ## bblock 4, line 0,  t569,  1(I32)
	c0    mov $r0.5 = (compress_16460.buf + 0)   ## bblock 4, line 0,  t570,  addr(compress_16460.buf?1.0)(P32)
	c0    mov $r0.3 = $r0.0   ## bblock 4, line 335,  t122,  0(SI32)
;;								## 0
.trace 1
L180?3:
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 5, line 335, t135, 0(I32)
	c0    ldb.d $r0.6 = 0[$r0.5]   ## [spec] bblock 6, line 336, t131(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 6, line 336, t137, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.2, 7   ## bblock 5, line 335,  t134,  t135,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 6, line 336,  t136,  t137,  1(SI32)
;;								## 2
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 5, line 335,  t773,  t134,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 5, line 335,  t774,  t134,  7(I32)
;;								## 3
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 5, line 335,  t775,  t773,  t774,  t134
;;								## 4
	c0    shr $r0.23 = $r0.23, 3   ## bblock 5, line 335,  t133,  t775,  3(I32)
;;								## 5
	c0    cmplt $b0.0 = $r0.3, $r0.23   ## bblock 5, line 335,  t776(I1),  t122,  t133
	c0    add $r0.3 = $r0.3, 16   ## [spec] bblock 28, line 335-15,  t122,  t122,  16(SI32)
;;								## 6
	c0    brf $b0.0, L181?3   ## bblock 5, line 335,  t776(I1)
;;								## 7
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 6, line 336, 0(I32), t136
;;								## 8
	c0    stb 0[$r0.4] = $r0.6   ## bblock 6, line 336, t137, t131(SI8)
;;								## 9
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 6, line 335-1, t217, 0(I32)
	c0    ldb.d $r0.6 = 1[$r0.5]   ## [spec] bblock 70, line 336-1, t220(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 70, line 336-1, t221, 0(I32)
	      xnop 1
;;								## 11
	c0    add $r0.2 = $r0.2, 7   ## bblock 6, line 335-1,  t218,  t217,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 70, line 336-1,  t222,  t221,  1(SI32)
;;								## 12
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 6, line 335-1,  t777,  t218,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 6, line 335-1,  t778,  t218,  7(I32)
;;								## 13
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 6, line 335-1,  t779,  t777,  t778,  t218
;;								## 14
	c0    shr $r0.23 = $r0.23, 3   ## bblock 6, line 335-1,  t219,  t779,  3(I32)
;;								## 15
	c0    cmplt $b0.0 = $r0.7, $r0.23   ## bblock 6, line 335-1,  t780(I1),  t569,  t219
	c0    add $r0.7 = $r0.7, 16   ## [spec] bblock 28, line 0,  t569,  t569,  16(I32)
;;								## 16
	c0    brf $b0.0, L182?3   ## bblock 6, line 335-1,  t780(I1)
;;								## 17
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 70, line 336-1, 0(I32), t222
;;								## 18
	c0    stb 0[$r0.4] = $r0.6   ## bblock 70, line 336-1, t221, t220(SI8)
;;								## 19
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 70, line 335-2, t210, 0(I32)
	c0    ldb.d $r0.6 = 2[$r0.5]   ## [spec] bblock 67, line 336-2, t213(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 67, line 336-2, t214, 0(I32)
	      xnop 1
;;								## 21
	c0    add $r0.2 = $r0.2, 7   ## bblock 70, line 335-2,  t211,  t210,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 67, line 336-2,  t215,  t214,  1(SI32)
;;								## 22
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 70, line 335-2,  t857,  t211,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 70, line 335-2,  t858,  t211,  7(I32)
;;								## 23
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 70, line 335-2,  t859,  t857,  t858,  t211
;;								## 24
	c0    shr $r0.23 = $r0.23, 3   ## bblock 70, line 335-2,  t212,  t859,  3(I32)
;;								## 25
	c0    cmplt $b0.0 = $r0.8, $r0.23   ## bblock 70, line 335-2,  t860(I1),  t555,  t212
	c0    add $r0.8 = $r0.8, 16   ## [spec] bblock 28, line 0,  t555,  t555,  16(I32)
;;								## 26
	c0    brf $b0.0, L183?3   ## bblock 70, line 335-2,  t860(I1)
;;								## 27
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 67, line 336-2, 0(I32), t215
;;								## 28
	c0    stb 0[$r0.4] = $r0.6   ## bblock 67, line 336-2, t214, t213(SI8)
;;								## 29
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 67, line 335-3, t203, 0(I32)
	c0    ldb.d $r0.6 = 3[$r0.5]   ## [spec] bblock 64, line 336-3, t206(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 64, line 336-3, t207, 0(I32)
	      xnop 1
;;								## 31
	c0    add $r0.2 = $r0.2, 7   ## bblock 67, line 335-3,  t204,  t203,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 64, line 336-3,  t208,  t207,  1(SI32)
;;								## 32
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 67, line 335-3,  t852,  t204,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 67, line 335-3,  t853,  t204,  7(I32)
;;								## 33
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 67, line 335-3,  t854,  t852,  t853,  t204
;;								## 34
	c0    shr $r0.23 = $r0.23, 3   ## bblock 67, line 335-3,  t205,  t854,  3(I32)
;;								## 35
	c0    cmplt $b0.0 = $r0.9, $r0.23   ## bblock 67, line 335-3,  t855(I1),  t556,  t205
	c0    add $r0.9 = $r0.9, 16   ## [spec] bblock 28, line 0,  t556,  t556,  16(I32)
;;								## 36
	c0    brf $b0.0, L184?3   ## bblock 67, line 335-3,  t855(I1)
;;								## 37
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 64, line 336-3, 0(I32), t208
;;								## 38
	c0    stb 0[$r0.4] = $r0.6   ## bblock 64, line 336-3, t207, t206(SI8)
;;								## 39
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 64, line 335-4, t196, 0(I32)
	c0    ldb.d $r0.6 = 4[$r0.5]   ## [spec] bblock 61, line 336-4, t199(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 61, line 336-4, t200, 0(I32)
	      xnop 1
;;								## 41
	c0    add $r0.2 = $r0.2, 7   ## bblock 64, line 335-4,  t197,  t196,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 61, line 336-4,  t201,  t200,  1(SI32)
;;								## 42
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 64, line 335-4,  t847,  t197,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 64, line 335-4,  t848,  t197,  7(I32)
;;								## 43
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 64, line 335-4,  t849,  t847,  t848,  t197
;;								## 44
	c0    shr $r0.23 = $r0.23, 3   ## bblock 64, line 335-4,  t198,  t849,  3(I32)
;;								## 45
	c0    cmplt $b0.0 = $r0.10, $r0.23   ## bblock 64, line 335-4,  t850(I1),  t557,  t198
	c0    add $r0.10 = $r0.10, 16   ## [spec] bblock 28, line 0,  t557,  t557,  16(I32)
;;								## 46
	c0    brf $b0.0, L185?3   ## bblock 64, line 335-4,  t850(I1)
;;								## 47
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 61, line 336-4, 0(I32), t201
;;								## 48
	c0    stb 0[$r0.4] = $r0.6   ## bblock 61, line 336-4, t200, t199(SI8)
;;								## 49
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 61, line 335-5, t189, 0(I32)
	c0    ldb.d $r0.6 = 5[$r0.5]   ## [spec] bblock 58, line 336-5, t192(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 58, line 336-5, t193, 0(I32)
	      xnop 1
;;								## 51
	c0    add $r0.2 = $r0.2, 7   ## bblock 61, line 335-5,  t190,  t189,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 58, line 336-5,  t194,  t193,  1(SI32)
;;								## 52
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 61, line 335-5,  t842,  t190,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 61, line 335-5,  t843,  t190,  7(I32)
;;								## 53
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 61, line 335-5,  t844,  t842,  t843,  t190
;;								## 54
	c0    shr $r0.23 = $r0.23, 3   ## bblock 61, line 335-5,  t191,  t844,  3(I32)
;;								## 55
	c0    cmplt $b0.0 = $r0.11, $r0.23   ## bblock 61, line 335-5,  t845(I1),  t558,  t191
	c0    add $r0.11 = $r0.11, 16   ## [spec] bblock 28, line 0,  t558,  t558,  16(I32)
;;								## 56
	c0    brf $b0.0, L186?3   ## bblock 61, line 335-5,  t845(I1)
;;								## 57
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 58, line 336-5, 0(I32), t194
;;								## 58
	c0    stb 0[$r0.4] = $r0.6   ## bblock 58, line 336-5, t193, t192(SI8)
;;								## 59
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 58, line 335-6, t182, 0(I32)
	c0    ldb.d $r0.6 = 6[$r0.5]   ## [spec] bblock 55, line 336-6, t185(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 55, line 336-6, t186, 0(I32)
	      xnop 1
;;								## 61
	c0    add $r0.2 = $r0.2, 7   ## bblock 58, line 335-6,  t183,  t182,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 55, line 336-6,  t187,  t186,  1(SI32)
;;								## 62
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 58, line 335-6,  t838,  t183,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 58, line 335-6,  t839,  t183,  7(I32)
;;								## 63
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 58, line 335-6,  t840,  t838,  t839,  t183
;;								## 64
	c0    shr $r0.23 = $r0.23, 3   ## bblock 58, line 335-6,  t184,  t840,  3(I32)
;;								## 65
	c0    cmplt $b0.0 = $r0.12, $r0.23   ## bblock 58, line 335-6,  t841(I1),  t559,  t184
	c0    add $r0.12 = $r0.12, 16   ## [spec] bblock 28, line 0,  t559,  t559,  16(I32)
;;								## 66
	c0    brf $b0.0, L187?3   ## bblock 58, line 335-6,  t841(I1)
;;								## 67
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 55, line 336-6, 0(I32), t187
;;								## 68
	c0    stb 0[$r0.4] = $r0.6   ## bblock 55, line 336-6, t186, t185(SI8)
;;								## 69
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 55, line 335-7, t175, 0(I32)
	c0    ldb.d $r0.6 = 7[$r0.5]   ## [spec] bblock 52, line 336-7, t178(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 52, line 336-7, t179, 0(I32)
	      xnop 1
;;								## 71
	c0    add $r0.2 = $r0.2, 7   ## bblock 55, line 335-7,  t176,  t175,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 52, line 336-7,  t180,  t179,  1(SI32)
;;								## 72
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 55, line 335-7,  t833,  t176,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 55, line 335-7,  t834,  t176,  7(I32)
;;								## 73
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 55, line 335-7,  t835,  t833,  t834,  t176
;;								## 74
	c0    shr $r0.23 = $r0.23, 3   ## bblock 55, line 335-7,  t177,  t835,  3(I32)
;;								## 75
	c0    cmplt $b0.0 = $r0.13, $r0.23   ## bblock 55, line 335-7,  t836(I1),  t560,  t177
	c0    add $r0.13 = $r0.13, 16   ## [spec] bblock 28, line 0,  t560,  t560,  16(I32)
;;								## 76
	c0    brf $b0.0, L188?3   ## bblock 55, line 335-7,  t836(I1)
;;								## 77
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 52, line 336-7, 0(I32), t180
;;								## 78
	c0    stb 0[$r0.4] = $r0.6   ## bblock 52, line 336-7, t179, t178(SI8)
;;								## 79
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 52, line 335-8, t168, 0(I32)
	c0    ldb.d $r0.6 = 8[$r0.5]   ## [spec] bblock 49, line 336-8, t171(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 49, line 336-8, t172, 0(I32)
	      xnop 1
;;								## 81
	c0    add $r0.2 = $r0.2, 7   ## bblock 52, line 335-8,  t169,  t168,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 49, line 336-8,  t173,  t172,  1(SI32)
;;								## 82
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 52, line 335-8,  t829,  t169,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 52, line 335-8,  t830,  t169,  7(I32)
;;								## 83
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 52, line 335-8,  t831,  t829,  t830,  t169
;;								## 84
	c0    shr $r0.23 = $r0.23, 3   ## bblock 52, line 335-8,  t170,  t831,  3(I32)
;;								## 85
	c0    cmplt $b0.0 = $r0.14, $r0.23   ## bblock 52, line 335-8,  t832(I1),  t561,  t170
	c0    add $r0.14 = $r0.14, 16   ## [spec] bblock 28, line 0,  t561,  t561,  16(I32)
;;								## 86
	c0    brf $b0.0, L189?3   ## bblock 52, line 335-8,  t832(I1)
;;								## 87
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 49, line 336-8, 0(I32), t173
;;								## 88
	c0    stb 0[$r0.4] = $r0.6   ## bblock 49, line 336-8, t172, t171(SI8)
;;								## 89
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 49, line 335-9, t161, 0(I32)
	c0    ldb.d $r0.6 = 9[$r0.5]   ## [spec] bblock 46, line 336-9, t164(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 46, line 336-9, t165, 0(I32)
	      xnop 1
;;								## 91
	c0    add $r0.2 = $r0.2, 7   ## bblock 49, line 335-9,  t162,  t161,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 46, line 336-9,  t166,  t165,  1(SI32)
;;								## 92
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 49, line 335-9,  t824,  t162,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 49, line 335-9,  t825,  t162,  7(I32)
;;								## 93
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 49, line 335-9,  t826,  t824,  t825,  t162
;;								## 94
	c0    shr $r0.23 = $r0.23, 3   ## bblock 49, line 335-9,  t163,  t826,  3(I32)
;;								## 95
	c0    cmplt $b0.0 = $r0.15, $r0.23   ## bblock 49, line 335-9,  t827(I1),  t562,  t163
	c0    add $r0.15 = $r0.15, 16   ## [spec] bblock 28, line 0,  t562,  t562,  16(I32)
;;								## 96
	c0    brf $b0.0, L190?3   ## bblock 49, line 335-9,  t827(I1)
;;								## 97
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 46, line 336-9, 0(I32), t166
;;								## 98
	c0    stb 0[$r0.4] = $r0.6   ## bblock 46, line 336-9, t165, t164(SI8)
;;								## 99
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 46, line 335-10, t154, 0(I32)
	c0    ldb.d $r0.6 = 10[$r0.5]   ## [spec] bblock 43, line 336-10, t157(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 43, line 336-10, t158, 0(I32)
	      xnop 1
;;								## 101
	c0    add $r0.2 = $r0.2, 7   ## bblock 46, line 335-10,  t155,  t154,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 43, line 336-10,  t159,  t158,  1(SI32)
;;								## 102
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 46, line 335-10,  t819,  t155,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 46, line 335-10,  t820,  t155,  7(I32)
;;								## 103
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 46, line 335-10,  t821,  t819,  t820,  t155
;;								## 104
	c0    shr $r0.23 = $r0.23, 3   ## bblock 46, line 335-10,  t156,  t821,  3(I32)
;;								## 105
	c0    cmplt $b0.0 = $r0.16, $r0.23   ## bblock 46, line 335-10,  t822(I1),  t563,  t156
	c0    add $r0.16 = $r0.16, 16   ## [spec] bblock 28, line 0,  t563,  t563,  16(I32)
;;								## 106
	c0    brf $b0.0, L191?3   ## bblock 46, line 335-10,  t822(I1)
;;								## 107
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 43, line 336-10, 0(I32), t159
;;								## 108
	c0    stb 0[$r0.4] = $r0.6   ## bblock 43, line 336-10, t158, t157(SI8)
;;								## 109
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 43, line 335-11, t147, 0(I32)
	c0    ldb.d $r0.6 = 11[$r0.5]   ## [spec] bblock 40, line 336-11, t150(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 40, line 336-11, t151, 0(I32)
	      xnop 1
;;								## 111
	c0    add $r0.2 = $r0.2, 7   ## bblock 43, line 335-11,  t148,  t147,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 40, line 336-11,  t152,  t151,  1(SI32)
;;								## 112
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 43, line 335-11,  t814,  t148,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 43, line 335-11,  t815,  t148,  7(I32)
;;								## 113
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 43, line 335-11,  t816,  t814,  t815,  t148
;;								## 114
	c0    shr $r0.23 = $r0.23, 3   ## bblock 43, line 335-11,  t149,  t816,  3(I32)
;;								## 115
	c0    cmplt $b0.0 = $r0.17, $r0.23   ## bblock 43, line 335-11,  t817(I1),  t564,  t149
	c0    add $r0.17 = $r0.17, 16   ## [spec] bblock 28, line 0,  t564,  t564,  16(I32)
;;								## 116
	c0    brf $b0.0, L192?3   ## bblock 43, line 335-11,  t817(I1)
;;								## 117
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 40, line 336-11, 0(I32), t152
;;								## 118
	c0    stb 0[$r0.4] = $r0.6   ## bblock 40, line 336-11, t151, t150(SI8)
;;								## 119
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 40, line 335-12, t125, 0(I32)
	c0    ldb.d $r0.6 = 12[$r0.5]   ## [spec] bblock 37, line 336-12, t143(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 37, line 336-12, t144, 0(I32)
	      xnop 1
;;								## 121
	c0    add $r0.2 = $r0.2, 7   ## bblock 40, line 335-12,  t141,  t125,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 37, line 336-12,  t145,  t144,  1(SI32)
;;								## 122
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 40, line 335-12,  t809,  t141,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 40, line 335-12,  t810,  t141,  7(I32)
;;								## 123
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 40, line 335-12,  t811,  t809,  t810,  t141
;;								## 124
	c0    shr $r0.23 = $r0.23, 3   ## bblock 40, line 335-12,  t142,  t811,  3(I32)
;;								## 125
	c0    cmplt $b0.0 = $r0.18, $r0.23   ## bblock 40, line 335-12,  t812(I1),  t565,  t142
	c0    add $r0.18 = $r0.18, 16   ## [spec] bblock 28, line 0,  t565,  t565,  16(I32)
;;								## 126
	c0    brf $b0.0, L193?3   ## bblock 40, line 335-12,  t812(I1)
;;								## 127
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 37, line 336-12, 0(I32), t145
;;								## 128
	c0    stb 0[$r0.4] = $r0.6   ## bblock 37, line 336-12, t144, t143(SI8)
;;								## 129
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 37, line 335-13, t80, 0(I32)
	c0    ldb.d $r0.6 = 13[$r0.5]   ## [spec] bblock 34, line 336-13, t87(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 34, line 336-13, t88, 0(I32)
	      xnop 1
;;								## 131
	c0    add $r0.2 = $r0.2, 7   ## bblock 37, line 335-13,  t81,  t80,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 34, line 336-13,  t89,  t88,  1(SI32)
;;								## 132
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 37, line 335-13,  t804,  t81,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 37, line 335-13,  t805,  t81,  7(I32)
;;								## 133
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 37, line 335-13,  t806,  t804,  t805,  t81
;;								## 134
	c0    shr $r0.23 = $r0.23, 3   ## bblock 37, line 335-13,  t82,  t806,  3(I32)
;;								## 135
	c0    cmplt $b0.0 = $r0.19, $r0.23   ## bblock 37, line 335-13,  t807(I1),  t566,  t82
	c0    add $r0.19 = $r0.19, 16   ## [spec] bblock 28, line 0,  t566,  t566,  16(I32)
;;								## 136
	c0    brf $b0.0, L194?3   ## bblock 37, line 335-13,  t807(I1)
;;								## 137
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 34, line 336-13, 0(I32), t89
;;								## 138
	c0    stb 0[$r0.4] = $r0.6   ## bblock 34, line 336-13, t88, t87(SI8)
;;								## 139
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 34, line 335-14, t121, 0(I32)
	c0    ldb.d $r0.6 = 14[$r0.5]   ## [spec] bblock 31, line 336-14, t118(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 31, line 336-14, t117, 0(I32)
	      xnop 1
;;								## 141
	c0    add $r0.2 = $r0.2, 7   ## bblock 34, line 335-14,  t120,  t121,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 31, line 336-14,  t116,  t117,  1(SI32)
;;								## 142
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 34, line 335-14,  t799,  t120,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 34, line 335-14,  t800,  t120,  7(I32)
;;								## 143
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 34, line 335-14,  t801,  t799,  t800,  t120
;;								## 144
	c0    shr $r0.23 = $r0.23, 3   ## bblock 34, line 335-14,  t119,  t801,  3(I32)
;;								## 145
	c0    cmplt $b0.0 = $r0.20, $r0.23   ## bblock 34, line 335-14,  t802(I1),  t567,  t119
	c0    add $r0.20 = $r0.20, 16   ## [spec] bblock 28, line 0,  t567,  t567,  16(I32)
;;								## 146
	c0    brf $b0.0, L195?3   ## bblock 34, line 335-14,  t802(I1)
;;								## 147
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 31, line 336-14, 0(I32), t116
;;								## 148
	c0    stb 0[$r0.4] = $r0.6   ## bblock 31, line 336-14, t117, t118(SI8)
;;								## 149
	c0    ldw $r0.2 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 31, line 335-15, t132, 0(I32)
	c0    ldb.d $r0.6 = 15[$r0.5]   ## [spec] bblock 28, line 336-15, t128(SI8), t570
	c0    ldw.d $r0.4 = ((outbuf + 0) + 0)[$r0.0]   ## [spec] bblock 28, line 336-15, t127, 0(I32)
	c0    add $r0.5 = $r0.5, 16   ## [spec] bblock 28, line 0,  t570,  t570,  16(I32)
	      xnop 1
;;								## 151
	c0    add $r0.2 = $r0.2, 7   ## bblock 31, line 335-15,  t130,  t132,  7(SI32)
	c0    add $r0.22 = $r0.4, 1   ## [spec] bblock 28, line 336-15,  t126,  t127,  1(SI32)
;;								## 152
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 31, line 335-15,  t794,  t130,  0(I32)
	c0    add $r0.23 = $r0.2, 7   ## bblock 31, line 335-15,  t795,  t130,  7(I32)
;;								## 153
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.2   ## bblock 31, line 335-15,  t796,  t794,  t795,  t130
;;								## 154
	c0    shr $r0.23 = $r0.23, 3   ## bblock 31, line 335-15,  t129,  t796,  3(I32)
;;								## 155
	c0    cmplt $b0.0 = $r0.21, $r0.23   ## bblock 31, line 335-15,  t797(I1),  t568,  t129
	c0    add $r0.21 = $r0.21, 16   ## [spec] bblock 28, line 0,  t568,  t568,  16(I32)
;;								## 156
	c0    brf $b0.0, L196?3   ## bblock 31, line 335-15,  t797(I1)
;;								## 157
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.22   ## bblock 28, line 336-15, 0(I32), t126
;;								## 158
	c0    stb 0[$r0.4] = $r0.6   ## bblock 28, line 336-15, t127, t128(SI8)
	c0    goto L180?3 ## goto
;;								## 159
.trace 34
L196?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 33
L195?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 32
L194?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 31
L193?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 30
L192?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 29
L191?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 28
L190?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 27
L189?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 26
L188?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 25
L187?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 24
L186?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 23
L185?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 22
L184?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 21
L183?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 20
L182?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
.trace 19
L181?3:
	c0    ldw $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 2, line 337, t90, 0(I32)
	c0    ldw $r0.5 = ((compress_16460.offset + 0) + 0)[$r0.0]   ## bblock 2, line 337, t91, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.5, 7   ## bblock 2, line 337,  t92,  t91,  7(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.2, $r0.0   ## bblock 2, line 337,  t770,  t92,  0(I32)
	c0    add $r0.4 = $r0.2, 7   ## bblock 2, line 337,  t771,  t92,  7(I32)
	c0    goto L179?3 ## goto
;;								## 3
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
.trace 62
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    mov $r0.3 = ((codetab + 0) + 480)   ## bblock 0, line 0,  t634,  (addr(codetab?1.0)(P32) + 0x1e0(I32))(P32)
	c0    mov $r0.4 = ((htab + 0) + 240)   ## bblock 0, line 0,  t684,  (addr(htab?1.0)(P32) + 0xf0(I32))(P32)
	c0    mov $r0.5 = 254   ## bblock 0, line 0,  t685,  254(I32)
	c0    mov $r0.6 = 253   ## bblock 0, line 0,  t678,  253(I32)
	c0    mov $r0.7 = 252   ## bblock 0, line 0,  t679,  252(I32)
	c0    mov $r0.8 = 251   ## bblock 0, line 0,  t672,  251(I32)
	c0    mov $r0.9 = 250   ## bblock 0, line 0,  t673,  250(I32)
	c0    mov $r0.10 = 249   ## bblock 0, line 0,  t666,  249(I32)
	c0    mov $r0.11 = 248   ## bblock 0, line 0,  t667,  248(I32)
	c0    mov $r0.12 = 247   ## bblock 0, line 0,  t660,  247(I32)
	c0    mov $r0.13 = 246   ## bblock 0, line 0,  t661,  246(I32)
	c0    mov $r0.14 = 245   ## bblock 0, line 0,  t654,  245(I32)
	c0    mov $r0.15 = 244   ## bblock 0, line 0,  t655,  244(I32)
	c0    mov $r0.16 = 243   ## bblock 0, line 0,  t491,  243(I32)
	c0    mov $r0.17 = 242   ## bblock 0, line 0,  t489,  242(I32)
	c0    mov $r0.18 = 241   ## bblock 0, line 0,  t487,  241(I32)
	c0    mov $r0.19 = 240   ## bblock 0, line 0,  t485,  240(I32)
	c0    mov $r0.21 = 511   ## 511(SI32)
	c0    mov $r0.20 = 9   ## 9(SI32)
;;								## 0
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.20   ## bblock 0, line 346, 0(I32), 9(SI32)
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.21   ## bblock 0, line 346, 0(I32), 511(SI32)
	c0    mov $r0.2 = 255   ## bblock 0, line 347,  t686,  255(SI32)
	c0    mov $r0.38 = $l0.0   ## t66
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t66
;;								## 1
.trace 7
L197?3:
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 1, line 347,  t778(I1),  t686,  0(SI32)
	c0    add $r0.20 = $r0.3, (~0x1f)   ## [spec] bblock 24, line 0,  t515,  t634,  (~0x1f)(I32)
	c0    add $r0.37 = $r0.19, (~0xf)   ## [spec] bblock 24, line 0,  t630,  t485,  (~0xf)(I32)
	c0    add $r0.36 = $r0.18, (~0xf)   ## [spec] bblock 24, line 0,  t633,  t487,  (~0xf)(I32)
	c0    add $r0.35 = $r0.17, (~0xf)   ## [spec] bblock 24, line 0,  t632,  t489,  (~0xf)(I32)
	c0    add $r0.34 = $r0.16, (~0xf)   ## [spec] bblock 24, line 0,  t631,  t491,  (~0xf)(I32)
	c0    add $r0.33 = $r0.15, (~0xf)   ## [spec] bblock 24, line 0,  t493,  t655,  (~0xf)(I32)
	c0    add $r0.32 = $r0.14, (~0xf)   ## [spec] bblock 24, line 0,  t495,  t654,  (~0xf)(I32)
	c0    add $r0.31 = $r0.13, (~0xf)   ## [spec] bblock 24, line 0,  t497,  t661,  (~0xf)(I32)
	c0    add $r0.30 = $r0.12, (~0xf)   ## [spec] bblock 24, line 0,  t499,  t660,  (~0xf)(I32)
	c0    add $r0.29 = $r0.11, (~0xf)   ## [spec] bblock 24, line 0,  t501,  t667,  (~0xf)(I32)
	c0    add $r0.28 = $r0.10, (~0xf)   ## [spec] bblock 24, line 0,  t503,  t666,  (~0xf)(I32)
	c0    add $r0.27 = $r0.9, (~0xf)   ## [spec] bblock 24, line 0,  t505,  t673,  (~0xf)(I32)
	c0    add $r0.26 = $r0.8, (~0xf)   ## [spec] bblock 24, line 0,  t507,  t672,  (~0xf)(I32)
	c0    add $r0.25 = $r0.7, (~0xf)   ## [spec] bblock 24, line 0,  t509,  t679,  (~0xf)(I32)
	c0    add $r0.24 = $r0.6, (~0xf)   ## [spec] bblock 24, line 0,  t511,  t678,  (~0xf)(I32)
	c0    add $r0.23 = $r0.5, (~0xf)   ## [spec] bblock 24, line 0,  t513,  t685,  (~0xf)(I32)
	c0    add $r0.22 = $r0.4, (~0xf)   ## [spec] bblock 24, line 0,  t484,  t684,  (~0xf)(I32)
	c0    add $r0.21 = $r0.2, -16   ## [spec] bblock 24, line 347-15,  t2,  t686,  -16(SI32)
;;								## 0
	c0    brf $b0.0, L198?3   ## bblock 1, line 347,  t778(I1)
;;								## 1
	c0    sth 30[$r0.3] = $r0.0   ## bblock 24, line 349, t634, 0(I32)
	c0    stb 15[$r0.4] = $r0.2   ## bblock 24, line 350, t684, t686
	c0    sth 28[$r0.3] = $r0.0   ## bblock 24, line 349-1, t634, 0(I32)
	c0    stb 14[$r0.4] = $r0.5   ## bblock 24, line 350-1, t684, t685
	c0    sth 26[$r0.3] = $r0.0   ## bblock 24, line 349-2, t634, 0(I32)
	c0    stb 13[$r0.4] = $r0.6   ## bblock 24, line 350-2, t684, t678
	c0    sth 24[$r0.3] = $r0.0   ## bblock 24, line 349-3, t634, 0(I32)
	c0    stb 12[$r0.4] = $r0.7   ## bblock 24, line 350-3, t684, t679
	c0    sth 22[$r0.3] = $r0.0   ## bblock 24, line 349-4, t634, 0(I32)
	c0    stb 11[$r0.4] = $r0.8   ## bblock 24, line 350-4, t684, t672
	c0    sth 20[$r0.3] = $r0.0   ## bblock 24, line 349-5, t634, 0(I32)
	c0    stb 10[$r0.4] = $r0.9   ## bblock 24, line 350-5, t684, t673
	c0    sth 18[$r0.3] = $r0.0   ## bblock 24, line 349-6, t634, 0(I32)
	c0    stb 9[$r0.4] = $r0.10   ## bblock 24, line 350-6, t684, t666
	c0    add $r0.9 = $r0.27, (~0xf)   ## bblock 24, line 0-1,  t673,  t505,  (~0xf)(I32)
	c0    add $r0.8 = $r0.26, (~0xf)   ## bblock 24, line 0-1,  t672,  t507,  (~0xf)(I32)
	c0    add $r0.7 = $r0.25, (~0xf)   ## bblock 24, line 0-1,  t679,  t509,  (~0xf)(I32)
	c0    add $r0.6 = $r0.24, (~0xf)   ## bblock 24, line 0-1,  t678,  t511,  (~0xf)(I32)
	c0    add $r0.5 = $r0.23, (~0xf)   ## bblock 24, line 0-1,  t685,  t513,  (~0xf)(I32)
	c0    add $r0.2 = $r0.21, -16   ## bblock 24, line 347-1,  t686,  t2,  -16(SI32)
;;								## 2
	c0    sth 16[$r0.3] = $r0.0   ## bblock 24, line 349-7, t634, 0(I32)
	c0    stb 8[$r0.4] = $r0.11   ## bblock 24, line 350-7, t684, t667
	c0    sth 14[$r0.3] = $r0.0   ## bblock 24, line 349-8, t634, 0(I32)
	c0    stb 7[$r0.4] = $r0.12   ## bblock 24, line 350-8, t684, t660
	c0    sth 12[$r0.3] = $r0.0   ## bblock 24, line 349-9, t634, 0(I32)
	c0    stb 6[$r0.4] = $r0.13   ## bblock 24, line 350-9, t684, t661
	c0    sth 10[$r0.3] = $r0.0   ## bblock 24, line 349-10, t634, 0(I32)
	c0    stb 5[$r0.4] = $r0.14   ## bblock 24, line 350-10, t684, t654
	c0    sth 8[$r0.3] = $r0.0   ## bblock 24, line 349-11, t634, 0(I32)
	c0    stb 4[$r0.4] = $r0.15   ## bblock 24, line 350-11, t684, t655
	c0    sth 6[$r0.3] = $r0.0   ## bblock 24, line 349-12, t634, 0(I32)
	c0    stb 3[$r0.4] = $r0.16   ## bblock 24, line 350-12, t684, t491
	c0    sth 4[$r0.3] = $r0.0   ## bblock 24, line 349-13, t634, 0(I32)
	c0    add $r0.16 = $r0.34, (~0xf)   ## bblock 24, line 0-1,  t491,  t631,  (~0xf)(I32)
	c0    add $r0.15 = $r0.33, (~0xf)   ## bblock 24, line 0-1,  t655,  t493,  (~0xf)(I32)
	c0    add $r0.14 = $r0.32, (~0xf)   ## bblock 24, line 0-1,  t654,  t495,  (~0xf)(I32)
	c0    add $r0.13 = $r0.31, (~0xf)   ## bblock 24, line 0-1,  t661,  t497,  (~0xf)(I32)
	c0    add $r0.12 = $r0.30, (~0xf)   ## bblock 24, line 0-1,  t660,  t499,  (~0xf)(I32)
	c0    add $r0.11 = $r0.29, (~0xf)   ## bblock 24, line 0-1,  t667,  t501,  (~0xf)(I32)
	c0    add $r0.10 = $r0.28, (~0xf)   ## bblock 24, line 0-1,  t666,  t503,  (~0xf)(I32)
;;								## 3
	c0    stb 2[$r0.4] = $r0.17   ## bblock 24, line 350-13, t684, t489
	c0    sth 2[$r0.3] = $r0.0   ## bblock 24, line 349-14, t634, 0(I32)
	c0    stb 1[$r0.4] = $r0.18   ## bblock 24, line 350-14, t684, t487
	c0    sth 0[$r0.3] = $r0.0   ## bblock 24, line 349-15, t634, 0(I32)
	c0    stb 0[$r0.4] = $r0.19   ## bblock 24, line 350-15, t684, t485
	c0    sth 30[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 15[$r0.22] = $r0.21   ## bblock 24, line 350-1, t484, t2
	c0    sth 28[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 14[$r0.22] = $r0.23   ## bblock 24, line 350-1, t484, t513
	c0    sth 26[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 13[$r0.22] = $r0.24   ## bblock 24, line 350-1, t484, t511
	c0    sth 24[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 12[$r0.22] = $r0.25   ## bblock 24, line 350-1, t484, t509
	c0    sth 22[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 11[$r0.22] = $r0.26   ## bblock 24, line 350-1, t484, t507
	c0    add $r0.3 = $r0.20, (~0x1f)   ## bblock 24, line 0-1,  t634,  t515,  (~0x1f)(I32)
	c0    add $r0.19 = $r0.37, (~0xf)   ## bblock 24, line 0-1,  t485,  t630,  (~0xf)(I32)
	c0    add $r0.18 = $r0.36, (~0xf)   ## bblock 24, line 0-1,  t487,  t633,  (~0xf)(I32)
	c0    add $r0.17 = $r0.35, (~0xf)   ## bblock 24, line 0-1,  t489,  t632,  (~0xf)(I32)
	c0    add $r0.4 = $r0.22, (~0xf)   ## bblock 24, line 0-1,  t684,  t484,  (~0xf)(I32)
;;								## 4
	c0    sth 20[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 10[$r0.22] = $r0.27   ## bblock 24, line 350-1, t484, t505
	c0    sth 18[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 9[$r0.22] = $r0.28   ## bblock 24, line 350-1, t484, t503
	c0    sth 16[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 8[$r0.22] = $r0.29   ## bblock 24, line 350-1, t484, t501
	c0    sth 14[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 7[$r0.22] = $r0.30   ## bblock 24, line 350-1, t484, t499
	c0    sth 12[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 6[$r0.22] = $r0.31   ## bblock 24, line 350-1, t484, t497
	c0    sth 10[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 5[$r0.22] = $r0.32   ## bblock 24, line 350-1, t484, t495
	c0    sth 8[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 4[$r0.22] = $r0.33   ## bblock 24, line 350-1, t484, t493
	c0    sth 6[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 3[$r0.22] = $r0.34   ## bblock 24, line 350-1, t484, t631
	c0    sth 4[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 2[$r0.22] = $r0.35   ## bblock 24, line 350-1, t484, t632
	c0    sth 2[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 1[$r0.22] = $r0.36   ## bblock 24, line 350-1, t484, t633
;;								## 5
	c0    sth 0[$r0.20] = $r0.0   ## bblock 24, line 349-1, t515, 0(I32)
	c0    stb 0[$r0.22] = $r0.37   ## bblock 24, line 350-1, t484, t630
	c0    goto L197?3 ## goto
;;								## 6
.trace 63
L198?3:
	c0    ldw $r0.2 = ((block_compress + 0) + 0)[$r0.0]   ## bblock 2, line 352, t14, 0(I32)
	c0    stw 0x10[$r0.1] = $r0.38  ## spill ## t66
	c0    mov $r0.4 = 257   ## 257(SI32)
	      xnop 1
;;								## 1
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 2, line 352,  t779(I1),  t14,  0(SI32)
;;								## 2
	c0    slct $r0.4 = $b0.0, $r0.4, 256   ## bblock 2, line 352,  t15,  t779(I1),  257(SI32),  256(SI32)
;;								## 3
.call compressgetcode, caller, arg(), ret($r0.3:s32)
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.4   ## bblock 2, line 352, 0(I32), t15
	c0    call $l0.0 = compressgetcode   ## bblock 2, line 353,  raddr(compressgetcode)(P32)
;;								## 4
	c0    mov $r0.2 = $r0.3   ## bblock 3, line 353,  t3,  t16
	c0    mov $r0.4 = $r0.3   ## bblock 3, line 353,  t1,  t16
	c0    cmpeq $b0.0 = $r0.3, -1   ## bblock 3, line 354,  t780(I1),  t16,  -1(SI32)
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t66
	c0    mov $r0.5 = $r0.3   ## t16
;;								## 5
	c0    brf $b0.0, L199?3   ## bblock 3, line 354,  t780(I1)
;;								## 6
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 23, line 356,  t67,  ?2.7?2auto_size(I32),  t66
;;								## 7
.trace 64
L199?3:
	c0    ldw $r0.3 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 4, line 358, t18, 0(I32)
	c0    stw 0x14[$r0.1] = $r0.57  ## spill ## t70
	c0    stw 0x18[$r0.1] = $r0.58  ## spill ## t71
	c0    stw 0x1c[$r0.1] = $r0.59  ## spill ## t72
;;								## 0
	c0    mov $r0.58 = ((htab + 0) + 4096)   ## bblock 4, line 359,  t0,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    mov $r0.57 = $r0.4   ## t1
	c0    mov $r0.59 = $r0.2   ## t3
;;								## 1
	c0    add $r0.2 = $r0.3, 1   ## bblock 4, line 358,  t19,  t18,  1(SI32)
;;								## 2
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.2   ## bblock 4, line 358, 0(I32), t19
;;								## 3
	c0    stb 0[$r0.3] = $r0.5   ## bblock 4, line 358, t18, t16
;;								## 4
.trace 9
L200?3:
.call compressgetcode, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = compressgetcode   ## bblock 5, line 360,  raddr(compressgetcode)(P32)
;;								## 0
	c0    mov $r0.4 = $r0.3   ## bblock 6, line 360,  t78,  t23
	c0    cmpgt $b0.0 = $r0.3, -1   ## bblock 6, line 360,  t781(I1),  t23,  -1(SI32)
	c0    cmpeq $r0.3 = $r0.3, 256   ## [spec] bblock 8, line 362,  t24,  t23,  256(SI32)
	c0    ldw.d $r0.6 = ((block_compress + 0) + 0)[$r0.0]   ## [spec] bblock 8, line 362, t25, 0(I32)
	c0    mov $r0.2 = 255   ## [spec] bblock 18, line 366,  t79,  255(SI32)
;;								## 1
	c0    brf $b0.0, L201?3   ## bblock 6, line 360,  t781(I1)
;;								## 2
	c0    andl $b0.0 = $r0.3, $r0.6   ## bblock 8, line 362,  t782(I1),  t24,  t25
	c0    mov $r0.3 = ((codetab + 0) + 480)   ## [spec] bblock 18, line 0,  t433,  (addr(codetab?1.0)(P32) + 0x1e0(I32))(P32)
;;								## 3
	c0    brf $b0.0, L202?3   ## bblock 8, line 362,  t782(I1)
;;								## 4
.trace 5
L203?3:
	c0    cmpge $b0.0 = $r0.2, $r0.0   ## bblock 19, line 366,  t790(I1),  t79,  0(SI32)
	c0    add $r0.2 = $r0.2, -16   ## [spec] bblock 22, line 366-15,  t79,  t79,  -16(SI32)
;;								## 0
	c0    brf $b0.0, L204?3   ## bblock 19, line 366,  t790(I1)
;;								## 1
	c0    sth 30[$r0.3] = $r0.0   ## bblock 22, line 367, t433, 0(I32)
	c0    sth 28[$r0.3] = $r0.0   ## bblock 22, line 367-1, t433, 0(I32)
	c0    sth 26[$r0.3] = $r0.0   ## bblock 22, line 367-2, t433, 0(I32)
	c0    sth 24[$r0.3] = $r0.0   ## bblock 22, line 367-3, t433, 0(I32)
	c0    sth 22[$r0.3] = $r0.0   ## bblock 22, line 367-4, t433, 0(I32)
	c0    sth 20[$r0.3] = $r0.0   ## bblock 22, line 367-5, t433, 0(I32)
	c0    sth 18[$r0.3] = $r0.0   ## bblock 22, line 367-6, t433, 0(I32)
	c0    sth 16[$r0.3] = $r0.0   ## bblock 22, line 367-7, t433, 0(I32)
	c0    sth 14[$r0.3] = $r0.0   ## bblock 22, line 367-8, t433, 0(I32)
	c0    sth 12[$r0.3] = $r0.0   ## bblock 22, line 367-9, t433, 0(I32)
	c0    sth 10[$r0.3] = $r0.0   ## bblock 22, line 367-10, t433, 0(I32)
	c0    sth 8[$r0.3] = $r0.0   ## bblock 22, line 367-11, t433, 0(I32)
	c0    sth 6[$r0.3] = $r0.0   ## bblock 22, line 367-12, t433, 0(I32)
	c0    sth 4[$r0.3] = $r0.0   ## bblock 22, line 367-13, t433, 0(I32)
	c0    sth 2[$r0.3] = $r0.0   ## bblock 22, line 367-14, t433, 0(I32)
	c0    sth 0[$r0.3] = $r0.0   ## bblock 22, line 367-15, t433, 0(I32)
	c0    add $r0.3 = $r0.3, (~0x1f)   ## bblock 22, line 0,  t433,  t433,  (~0x1f)(I32)
	c0    goto L203?3 ## goto
;;								## 2
.trace 13
L204?3:
	c0    mov $r0.3 = 256   ## 256(SI32)
	c0    mov $r0.2 = 1   ## 1(SI32)
;;								## 0
.call compressgetcode, caller, arg(), ret($r0.3:s32)
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.2   ## bblock 20, line 368, 0(I32), 1(SI32)
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.3   ## bblock 20, line 369, 0(I32), 256(SI32)
	c0    call $l0.0 = compressgetcode   ## bblock 20, line 370,  raddr(compressgetcode)(P32)
;;								## 1
	c0    mov $r0.4 = $r0.3   ## bblock 21, line 370,  t78,  t29
	c0    cmpeq $b0.0 = $r0.3, -1   ## bblock 21, line 370,  t791(I1),  t29,  -1(SI32)
;;								## 2
	c0    br $b0.0, L201?3   ## bblock 21, line 370,  t791(I1)
;;								## 3
.trace 10
L202?3:
	c0    ldw $r0.3 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 9, line 374, t30, 0(I32)
	c0    mov $r0.8 = $r0.4   ## bblock 9, line 373,  t4,  t78
	      xnop 1
;;								## 1
	c0    cmpge $b0.0 = $r0.4, $r0.3   ## bblock 9, line 374,  t783(I1),  t78,  t30
	c0    mov $r0.2 = $r0.4   ## t78
;;								## 2
	c0    mov $r0.4 = 256   ## 256(SI32)
	c0    brf $b0.0, L205?3   ## bblock 9, line 374,  t783(I1)
;;								## 3
	c0    stb 0[$r0.58] = $r0.57   ## bblock 17, line 376, t0, t1
	c0    mov $r0.2 = $r0.59   ## bblock 17, line 377,  t78,  t3
	c0    add $r0.5 = $r0.58, 1   ## bblock 17, line 376,  t0,  t0,  1(SI32)
;;								## 4
.trace 1
L206?3:
	c0    cmpge $b0.0 = $r0.2, $r0.4   ## bblock 10, line 381,  t784(I1),  t78,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.2]   ## [spec] bblock 16, line 383, t37(I8), t78
	c0    sh1add $r0.6 = $r0.2, (codetab + 0)   ## [spec] bblock 16, line 384,  t788,  t78,  addr(codetab?1.0)(P32)
;;								## 0
	c0    ldhu.d $r0.6 = 0[$r0.6]   ## [spec] bblock 16, line 384, t90, t788
	c0    brf $b0.0, L207?3   ## bblock 10, line 381,  t784(I1)
;;								## 1
	c0    stb 0[$r0.5] = $r0.3   ## bblock 16, line 383, t0, t37(I8)
;;								## 2
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 16, line 381-1,  t789(I1),  t90,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 163, line 383-1, t202(I8), t90
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 163, line 384-1,  t835,  t90,  addr(codetab?1.0)(P32)
;;								## 3
	c0    ldhu.d $r0.7 = 0[$r0.7]   ## [spec] bblock 163, line 384-1, t203, t835
	c0    brf $b0.0, L208?3   ## bblock 16, line 381-1,  t789(I1)
;;								## 4
	c0    stb 1[$r0.5] = $r0.3   ## bblock 163, line 383-1, t0, t202(I8)
;;								## 5
	c0    cmpge $b0.0 = $r0.7, $r0.4   ## bblock 163, line 381-2,  t836(I1),  t203,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.7]   ## [spec] bblock 160, line 383-2, t198(I8), t203
	c0    sh1add $r0.6 = $r0.7, (codetab + 0)   ## [spec] bblock 160, line 384-2,  t833,  t203,  addr(codetab?1.0)(P32)
;;								## 6
	c0    ldhu.d $r0.6 = 0[$r0.6]   ## [spec] bblock 160, line 384-2, t199, t833
	c0    brf $b0.0, L209?3   ## bblock 163, line 381-2,  t836(I1)
;;								## 7
	c0    stb 2[$r0.5] = $r0.3   ## bblock 160, line 383-2, t0, t198(I8)
;;								## 8
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 160, line 381-3,  t834(I1),  t199,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 157, line 383-3, t194(I8), t199
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 157, line 384-3,  t831,  t199,  addr(codetab?1.0)(P32)
;;								## 9
	c0    ldhu.d $r0.7 = 0[$r0.7]   ## [spec] bblock 157, line 384-3, t195, t831
	c0    brf $b0.0, L210?3   ## bblock 160, line 381-3,  t834(I1)
;;								## 10
	c0    stb 3[$r0.5] = $r0.3   ## bblock 157, line 383-3, t0, t194(I8)
;;								## 11
	c0    cmpge $b0.0 = $r0.7, $r0.4   ## bblock 157, line 381-4,  t832(I1),  t195,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.7]   ## [spec] bblock 154, line 383-4, t190(I8), t195
	c0    sh1add $r0.6 = $r0.7, (codetab + 0)   ## [spec] bblock 154, line 384-4,  t829,  t195,  addr(codetab?1.0)(P32)
;;								## 12
	c0    ldhu.d $r0.6 = 0[$r0.6]   ## [spec] bblock 154, line 384-4, t191, t829
	c0    brf $b0.0, L211?3   ## bblock 157, line 381-4,  t832(I1)
;;								## 13
	c0    stb 4[$r0.5] = $r0.3   ## bblock 154, line 383-4, t0, t190(I8)
;;								## 14
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 154, line 381-5,  t830(I1),  t191,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 151, line 383-5, t186(I8), t191
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 151, line 384-5,  t827,  t191,  addr(codetab?1.0)(P32)
;;								## 15
	c0    ldhu.d $r0.7 = 0[$r0.7]   ## [spec] bblock 151, line 384-5, t187, t827
	c0    brf $b0.0, L212?3   ## bblock 154, line 381-5,  t830(I1)
;;								## 16
	c0    stb 5[$r0.5] = $r0.3   ## bblock 151, line 383-5, t0, t186(I8)
;;								## 17
	c0    cmpge $b0.0 = $r0.7, $r0.4   ## bblock 151, line 381-6,  t828(I1),  t187,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.7]   ## [spec] bblock 148, line 383-6, t182(I8), t187
	c0    sh1add $r0.6 = $r0.7, (codetab + 0)   ## [spec] bblock 148, line 384-6,  t824,  t187,  addr(codetab?1.0)(P32)
;;								## 18
	c0    ldhu.d $r0.6 = 0[$r0.6]   ## [spec] bblock 148, line 384-6, t183, t824
	c0    brf $b0.0, L213?3   ## bblock 151, line 381-6,  t828(I1)
;;								## 19
	c0    stb 6[$r0.5] = $r0.3   ## bblock 148, line 383-6, t0, t182(I8)
;;								## 20
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 148, line 381-7,  t825(I1),  t183,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 145, line 383-7, t178(I8), t183
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 145, line 384-7,  t821,  t183,  addr(codetab?1.0)(P32)
;;								## 21
	c0    ldhu.d $r0.7 = 0[$r0.7]   ## [spec] bblock 145, line 384-7, t179, t821
	c0    brf $b0.0, L214?3   ## bblock 148, line 381-7,  t825(I1)
;;								## 22
	c0    stb 7[$r0.5] = $r0.3   ## bblock 145, line 383-7, t0, t178(I8)
;;								## 23
	c0    cmpge $b0.0 = $r0.7, $r0.4   ## bblock 145, line 381-8,  t822(I1),  t179,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.7]   ## [spec] bblock 142, line 383-8, t174(I8), t179
	c0    sh1add $r0.6 = $r0.7, (codetab + 0)   ## [spec] bblock 142, line 384-8,  t818,  t179,  addr(codetab?1.0)(P32)
;;								## 24
	c0    ldhu.d $r0.6 = 0[$r0.6]   ## [spec] bblock 142, line 384-8, t175, t818
	c0    brf $b0.0, L215?3   ## bblock 145, line 381-8,  t822(I1)
;;								## 25
	c0    stb 8[$r0.5] = $r0.3   ## bblock 142, line 383-8, t0, t174(I8)
;;								## 26
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 142, line 381-9,  t819(I1),  t175,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 139, line 383-9, t170(I8), t175
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 139, line 384-9,  t815,  t175,  addr(codetab?1.0)(P32)
;;								## 27
	c0    ldhu.d $r0.7 = 0[$r0.7]   ## [spec] bblock 139, line 384-9, t171, t815
	c0    brf $b0.0, L216?3   ## bblock 142, line 381-9,  t819(I1)
;;								## 28
	c0    stb 9[$r0.5] = $r0.3   ## bblock 139, line 383-9, t0, t170(I8)
;;								## 29
	c0    cmpge $b0.0 = $r0.7, $r0.4   ## bblock 139, line 381-10,  t816(I1),  t171,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.7]   ## [spec] bblock 136, line 383-10, t166(I8), t171
	c0    sh1add $r0.6 = $r0.7, (codetab + 0)   ## [spec] bblock 136, line 384-10,  t812,  t171,  addr(codetab?1.0)(P32)
;;								## 30
	c0    ldhu.d $r0.6 = 0[$r0.6]   ## [spec] bblock 136, line 384-10, t167, t812
	c0    brf $b0.0, L217?3   ## bblock 139, line 381-10,  t816(I1)
;;								## 31
	c0    stb 10[$r0.5] = $r0.3   ## bblock 136, line 383-10, t0, t166(I8)
;;								## 32
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 136, line 381-11,  t813(I1),  t167,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 133, line 383-11, t162(I8), t167
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 133, line 384-11,  t809,  t167,  addr(codetab?1.0)(P32)
;;								## 33
	c0    ldhu.d $r0.7 = 0[$r0.7]   ## [spec] bblock 133, line 384-11, t163, t809
	c0    brf $b0.0, L218?3   ## bblock 136, line 381-11,  t813(I1)
;;								## 34
	c0    stb 11[$r0.5] = $r0.3   ## bblock 133, line 383-11, t0, t162(I8)
;;								## 35
	c0    cmpge $b0.0 = $r0.7, $r0.4   ## bblock 133, line 381-12,  t810(I1),  t163,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.7]   ## [spec] bblock 130, line 383-12, t158(I8), t163
	c0    sh1add $r0.6 = $r0.7, (codetab + 0)   ## [spec] bblock 130, line 384-12,  t806,  t163,  addr(codetab?1.0)(P32)
;;								## 36
	c0    ldhu.d $r0.6 = 0[$r0.6]   ## [spec] bblock 130, line 384-12, t159, t806
	c0    brf $b0.0, L219?3   ## bblock 133, line 381-12,  t810(I1)
;;								## 37
	c0    stb 12[$r0.5] = $r0.3   ## bblock 130, line 383-12, t0, t158(I8)
;;								## 38
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 130, line 381-13,  t807(I1),  t159,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 127, line 383-13, t154(I8), t159
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 127, line 384-13,  t803,  t159,  addr(codetab?1.0)(P32)
;;								## 39
	c0    ldhu.d $r0.7 = 0[$r0.7]   ## [spec] bblock 127, line 384-13, t155, t803
	c0    brf $b0.0, L220?3   ## bblock 130, line 381-13,  t807(I1)
;;								## 40
	c0    stb 13[$r0.5] = $r0.3   ## bblock 127, line 383-13, t0, t154(I8)
;;								## 41
	c0    cmpge $b0.0 = $r0.7, $r0.4   ## bblock 127, line 381-14,  t804(I1),  t155,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.7]   ## [spec] bblock 124, line 383-14, t147(I8), t155
	c0    sh1add $r0.6 = $r0.7, (codetab + 0)   ## [spec] bblock 124, line 384-14,  t800,  t155,  addr(codetab?1.0)(P32)
;;								## 42
	c0    ldhu.d $r0.6 = 0[$r0.6]   ## [spec] bblock 124, line 384-14, t150, t800
	c0    brf $b0.0, L221?3   ## bblock 127, line 381-14,  t804(I1)
;;								## 43
	c0    stb 14[$r0.5] = $r0.3   ## bblock 124, line 383-14, t0, t147(I8)
;;								## 44
	c0    cmpge $b0.0 = $r0.6, $r0.4   ## bblock 124, line 381-15,  t801(I1),  t150,  256(SI32)
	c0    ldbu.d $r0.3 = (htab + 0)[$r0.6]   ## [spec] bblock 121, line 383-15, t134(I8), t150
	c0    sh1add $r0.7 = $r0.6, (codetab + 0)   ## [spec] bblock 121, line 384-15,  t798,  t150,  addr(codetab?1.0)(P32)
;;								## 45
	c0    ldhu.d $r0.2 = 0[$r0.7]   ## [spec] bblock 121, line 384-15, t78, t798
	c0    brf $b0.0, L222?3   ## bblock 124, line 381-15,  t801(I1)
;;								## 46
	c0    stb 15[$r0.5] = $r0.3   ## bblock 121, line 383-15, t0, t134(I8)
	c0    add $r0.5 = $r0.5, 16   ## bblock 121, line 383-15,  t0,  t0,  16(SI32)
	c0    goto L206?3 ## goto
;;								## 47
.trace 37
L222?3:
	c0    add $r0.5 = $r0.5, 15   ## bblock 122, line 0,  t139,  t0,  15(I32)
	c0    mov $r0.41 = $r0.8   ## t4
;;								## 0
	c0    mov $r0.2 = $r0.6   ## bblock 122, line 0,  t141,  t150
	c0    goto L223?3 ## goto
;;								## 1
.trace 2
L224?3:
	c0    mov $r0.5 = $r0.3   ## bblock 12, line 0,  t94,  t309
	c0    ldbu $r0.4 = 0[$r0.3]   ## bblock 12, line 390, t707(I8), t309
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 12, line 390, t709, 0(I32)
	c0    cmpleu $b0.0 = $r0.3, ((htab + 0) + 4096)   ## bblock 12, line 392,  t785(I1),  t309,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    cmpleu $b0.1 = $r0.6, ((htab + 0) + 4096)   ## [spec] bblock 194, line 392-1,  t851(I1),  t294,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    cmpleu $b0.2 = $r0.7, ((htab + 0) + 4096)   ## [spec] bblock 192, line 392-2,  t850(I1),  t295,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    cmpleu $b0.3 = $r0.8, ((htab + 0) + 4096)   ## [spec] bblock 190, line 392-3,  t849(I1),  t296,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    cmpleu $b0.4 = $r0.9, ((htab + 0) + 4096)   ## [spec] bblock 188, line 392-4,  t848(I1),  t297,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    cmpleu $b0.5 = $r0.10, ((htab + 0) + 4096)   ## [spec] bblock 186, line 392-5,  t847(I1),  t298,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    cmpleu $b0.6 = $r0.11, ((htab + 0) + 4096)   ## [spec] bblock 184, line 392-6,  t846(I1),  t299,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    cmpleu $b0.7 = $r0.12, ((htab + 0) + 4096)   ## [spec] bblock 182, line 392-7,  t845(I1),  t300,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.3 = $r0.3, (~0xf)   ## [spec] bblock 166, line 0,  t646,  t309,  (~0xf)(I32)
	c0    add $r0.22 = $r0.19, (~0xf)   ## [spec] bblock 166, line 0,  t644,  t307,  (~0xf)(I32)
	c0    add $r0.23 = $r0.18, (~0xf)   ## [spec] bblock 166, line 0,  t643,  t306,  (~0xf)(I32)
	c0    add $r0.24 = $r0.17, (~0xf)   ## [spec] bblock 166, line 0,  t642,  t305,  (~0xf)(I32)
	c0    add $r0.25 = $r0.16, (~0xf)   ## [spec] bblock 166, line 0,  t641,  t304,  (~0xf)(I32)
	c0    add $r0.26 = $r0.15, (~0xf)   ## [spec] bblock 166, line 0,  t303,  t639,  (~0xf)(I32)
	c0    add $r0.27 = $r0.14, (~0xf)   ## [spec] bblock 166, line 0,  t302,  t640,  (~0xf)(I32)
	c0    add $r0.28 = $r0.13, (~0xf)   ## [spec] bblock 166, line 0,  t692,  t301,  (~0xf)(I32)
	c0    add $r0.29 = $r0.12, (~0xf)   ## [spec] bblock 166, line 0,  t691,  t300,  (~0xf)(I32)
;;								## 0
	c0    mov $r0.37 = $r0.20   ## [spec] bblock 166, line 0,  t694,  t308
	c0    add $r0.30 = $r0.11, (~0xf)   ## [spec] bblock 166, line 0,  t652,  t299,  (~0xf)(I32)
	c0    add $r0.31 = $r0.10, (~0xf)   ## [spec] bblock 166, line 0,  t651,  t298,  (~0xf)(I32)
	c0    add $r0.32 = $r0.9, (~0xf)   ## [spec] bblock 166, line 0,  t650,  t297,  (~0xf)(I32)
	c0    add $r0.33 = $r0.8, (~0xf)   ## [spec] bblock 166, line 0,  t649,  t296,  (~0xf)(I32)
	c0    add $r0.34 = $r0.7, (~0xf)   ## [spec] bblock 166, line 0,  t648,  t295,  (~0xf)(I32)
	c0    add $r0.35 = $r0.6, (~0xf)   ## [spec] bblock 166, line 0,  t647,  t294,  (~0xf)(I32)
	c0    add $r0.36 = $r0.20, (~0xf)   ## [spec] bblock 166, line 0,  t645,  t308,  (~0xf)(I32)
	c0    add $r0.38 = $r0.3, (~0xf)   ## [spec] bblock 147, line 0-1,  t309,  t646,  (~0xf)(I32)
;;								## 1
	c0    add $r0.39 = $r0.2, 1   ## bblock 12, line 390,  t710,  t709,  1(SI32)
	c0    mov $r0.40 = $r0.36   ## [spec] bblock 147, line 0-1,  t629,  t645
;;								## 2
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.39   ## bblock 12, line 390, 0(I32), t710
;;								## 3
	c0    stb 0[$r0.2] = $r0.4   ## bblock 12, line 390, t709, t707(I8)
	c0    br $b0.0, L225?3   ## bblock 12, line 392,  t785(I1)
;;								## 4
	c0    ldbu $r0.6 = 0[$r0.6]   ## bblock 194, line 390-1, t289(I8), t294
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 194, line 390-1, t291, 0(I32)
	c0    cmpleu $b0.0 = $r0.13, ((htab + 0) + 4096)   ## [spec] bblock 180, line 392-8,  t844(I1),  t301,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	      xnop 1
;;								## 6
	c0    add $r0.4 = $r0.2, 1   ## bblock 194, line 390-1,  t292,  t291,  1(SI32)
;;								## 7
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 194, line 390-1, 0(I32), t292
;;								## 8
	c0    stb 0[$r0.2] = $r0.6   ## bblock 194, line 390-1, t291, t289(I8)
	c0    cmpleu $b0.1 = $r0.40, ((htab + 0) + 4096)   ## [spec] bblock 147, line 392-1,  t823(I1),  t629,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    br $b0.1, L226?3   ## bblock 194, line 392-1,  t851(I1)
;;								## 9
	c0    ldbu $r0.7 = 0[$r0.7]   ## bblock 192, line 390-2, t283(I8), t295
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 192, line 390-2, t285, 0(I32)
	c0    cmpleu $b0.1 = $r0.14, ((htab + 0) + 4096)   ## [spec] bblock 178, line 392-9,  t843(I1),  t640,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.6 = $r0.35, (~0xf)   ## [spec] bblock 147, line 0-1,  t294,  t647,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.1   ## [spec] t823(I1)
	      xnop 1
;;								## 11
	c0    add $r0.39 = $r0.2, 1   ## bblock 192, line 390-2,  t286,  t285,  1(SI32)
;;								## 12
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.39   ## bblock 192, line 390-2, 0(I32), t286
;;								## 13
	c0    stb 0[$r0.2] = $r0.7   ## bblock 192, line 390-2, t285, t283(I8)
	c0    mtb $b0.2 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.2, L227?3   ## bblock 192, line 392-2,  t850(I1)
;;								## 14
	c0    ldbu $r0.8 = 0[$r0.8]   ## bblock 190, line 390-3, t277(I8), t296
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 190, line 390-3, t279, 0(I32)
	c0    cmpleu $b0.2 = $r0.15, ((htab + 0) + 4096)   ## [spec] bblock 176, line 392-10,  t842(I1),  t639,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.7 = $r0.34, (~0xf)   ## [spec] bblock 147, line 0-1,  t295,  t648,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.2   ## [spec] t823(I1)
	      xnop 1
;;								## 16
	c0    add $r0.39 = $r0.2, 1   ## bblock 190, line 390-3,  t280,  t279,  1(SI32)
;;								## 17
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.39   ## bblock 190, line 390-3, 0(I32), t280
;;								## 18
	c0    stb 0[$r0.2] = $r0.8   ## bblock 190, line 390-3, t279, t277(I8)
	c0    mtb $b0.3 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.3, L228?3   ## bblock 190, line 392-3,  t849(I1)
;;								## 19
	c0    ldbu $r0.9 = 0[$r0.9]   ## bblock 188, line 390-4, t271(I8), t297
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 188, line 390-4, t273, 0(I32)
	c0    cmpleu $b0.3 = $r0.16, ((htab + 0) + 4096)   ## [spec] bblock 174, line 392-11,  t841(I1),  t304,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.8 = $r0.33, (~0xf)   ## [spec] bblock 147, line 0-1,  t296,  t649,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.3   ## [spec] t823(I1)
	      xnop 1
;;								## 21
	c0    add $r0.39 = $r0.2, 1   ## bblock 188, line 390-4,  t274,  t273,  1(SI32)
;;								## 22
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.39   ## bblock 188, line 390-4, 0(I32), t274
;;								## 23
	c0    stb 0[$r0.2] = $r0.9   ## bblock 188, line 390-4, t273, t271(I8)
	c0    mtb $b0.4 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.4, L229?3   ## bblock 188, line 392-4,  t848(I1)
;;								## 24
	c0    ldbu $r0.10 = 0[$r0.10]   ## bblock 186, line 390-5, t265(I8), t298
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 186, line 390-5, t267, 0(I32)
	c0    cmpleu $b0.4 = $r0.17, ((htab + 0) + 4096)   ## [spec] bblock 172, line 392-12,  t840(I1),  t305,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.9 = $r0.32, (~0xf)   ## [spec] bblock 147, line 0-1,  t297,  t650,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.4   ## [spec] t823(I1)
	      xnop 1
;;								## 26
	c0    add $r0.39 = $r0.2, 1   ## bblock 186, line 390-5,  t268,  t267,  1(SI32)
;;								## 27
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.39   ## bblock 186, line 390-5, 0(I32), t268
;;								## 28
	c0    stb 0[$r0.2] = $r0.10   ## bblock 186, line 390-5, t267, t265(I8)
	c0    mtb $b0.5 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.5, L230?3   ## bblock 186, line 392-5,  t847(I1)
;;								## 29
	c0    ldbu $r0.11 = 0[$r0.11]   ## bblock 184, line 390-6, t259(I8), t299
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 184, line 390-6, t261, 0(I32)
	c0    cmpleu $b0.5 = $r0.18, ((htab + 0) + 4096)   ## [spec] bblock 170, line 392-13,  t839(I1),  t306,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.10 = $r0.31, (~0xf)   ## [spec] bblock 147, line 0-1,  t298,  t651,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.5   ## [spec] t823(I1)
	      xnop 1
;;								## 31
	c0    add $r0.39 = $r0.2, 1   ## bblock 184, line 390-6,  t262,  t261,  1(SI32)
;;								## 32
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.39   ## bblock 184, line 390-6, 0(I32), t262
;;								## 33
	c0    stb 0[$r0.2] = $r0.11   ## bblock 184, line 390-6, t261, t259(I8)
	c0    mtb $b0.6 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.6, L231?3   ## bblock 184, line 392-6,  t846(I1)
;;								## 34
	c0    ldbu $r0.12 = 0[$r0.12]   ## bblock 182, line 390-7, t253(I8), t300
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 182, line 390-7, t255, 0(I32)
	c0    cmpleu $b0.6 = $r0.19, ((htab + 0) + 4096)   ## [spec] bblock 168, line 392-14,  t838(I1),  t307,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.11 = $r0.30, (~0xf)   ## [spec] bblock 147, line 0-1,  t299,  t652,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.6   ## [spec] t823(I1)
	      xnop 1
;;								## 36
	c0    add $r0.39 = $r0.2, 1   ## bblock 182, line 390-7,  t256,  t255,  1(SI32)
;;								## 37
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.39   ## bblock 182, line 390-7, 0(I32), t256
;;								## 38
	c0    stb 0[$r0.2] = $r0.12   ## bblock 182, line 390-7, t255, t253(I8)
	c0    mtb $b0.7 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.7, L232?3   ## bblock 182, line 392-7,  t845(I1)
;;								## 39
	c0    ldbu $r0.13 = 0[$r0.13]   ## bblock 180, line 390-8, t247(I8), t301
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 180, line 390-8, t249, 0(I32)
	c0    cmpleu $b0.7 = $r0.37, ((htab + 0) + 4096)   ## [spec] bblock 166, line 392-15,  t837(I1),  t694,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.12 = $r0.29, (~0xf)   ## [spec] bblock 147, line 0-1,  t300,  t691,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.7   ## [spec] t823(I1)
	      xnop 1
;;								## 41
	c0    add $r0.37 = $r0.2, 1   ## bblock 180, line 390-8,  t250,  t249,  1(SI32)
;;								## 42
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.37   ## bblock 180, line 390-8, 0(I32), t250
;;								## 43
	c0    stb 0[$r0.2] = $r0.13   ## bblock 180, line 390-8, t249, t247(I8)
	c0    mtb $b0.0 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.0, L233?3   ## bblock 180, line 392-8,  t844(I1)
;;								## 44
	c0    ldbu $r0.14 = 0[$r0.14]   ## bblock 178, line 390-9, t241(I8), t640
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 178, line 390-9, t243, 0(I32)
	c0    cmpleu $b0.0 = $r0.3, ((htab + 0) + 4096)   ## [spec] bblock 150, line 392-1,  t826(I1),  t646,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.13 = $r0.28, (~0xf)   ## [spec] bblock 147, line 0-1,  t301,  t692,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.0   ## [spec] t823(I1)
	      xnop 1
;;								## 46
	c0    add $r0.37 = $r0.2, 1   ## bblock 178, line 390-9,  t244,  t243,  1(SI32)
;;								## 47
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.37   ## bblock 178, line 390-9, 0(I32), t244
;;								## 48
	c0    stb 0[$r0.2] = $r0.14   ## bblock 178, line 390-9, t243, t241(I8)
	c0    mtb $b0.1 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.1, L234?3   ## bblock 178, line 392-9,  t843(I1)
;;								## 49
	c0    ldbu $r0.15 = 0[$r0.15]   ## bblock 176, line 390-10, t683(I8), t639
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 176, line 390-10, t681, 0(I32)
	c0    cmpleu $b0.1 = $r0.35, ((htab + 0) + 4096)   ## [spec] bblock 35, line 392-1,  t796(I1),  t647,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.14 = $r0.27, (~0xf)   ## [spec] bblock 147, line 0-1,  t640,  t302,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.1   ## [spec] t823(I1)
	      xnop 1
;;								## 51
	c0    add $r0.37 = $r0.2, 1   ## bblock 176, line 390-10,  t680,  t681,  1(SI32)
;;								## 52
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.37   ## bblock 176, line 390-10, 0(I32), t680
;;								## 53
	c0    stb 0[$r0.2] = $r0.15   ## bblock 176, line 390-10, t681, t683(I8)
	c0    mtb $b0.2 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.2, L235?3   ## bblock 176, line 392-10,  t842(I1)
;;								## 54
	c0    ldbu $r0.16 = 0[$r0.16]   ## bblock 174, line 390-11, t677(I8), t304
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 174, line 390-11, t675, 0(I32)
	c0    cmpleu $b0.2 = $r0.34, ((htab + 0) + 4096)   ## [spec] bblock 31, line 392-1,  t794(I1),  t648,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.15 = $r0.26, (~0xf)   ## [spec] bblock 147, line 0-1,  t639,  t303,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.2   ## [spec] t823(I1)
	      xnop 1
;;								## 56
	c0    add $r0.37 = $r0.2, 1   ## bblock 174, line 390-11,  t674,  t675,  1(SI32)
;;								## 57
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.37   ## bblock 174, line 390-11, 0(I32), t674
;;								## 58
	c0    stb 0[$r0.2] = $r0.16   ## bblock 174, line 390-11, t675, t677(I8)
	c0    mtb $b0.3 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.3, L236?3   ## bblock 174, line 392-11,  t841(I1)
;;								## 59
	c0    ldbu $r0.17 = 0[$r0.17]   ## bblock 172, line 390-12, t671(I8), t305
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 172, line 390-12, t669, 0(I32)
	c0    cmpleu $b0.3 = $r0.33, ((htab + 0) + 4096)   ## [spec] bblock 32, line 392-1,  t795(I1),  t649,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.16 = $r0.25, (~0xf)   ## [spec] bblock 147, line 0-1,  t304,  t641,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.3   ## [spec] t823(I1)
	      xnop 1
;;								## 61
	c0    add $r0.37 = $r0.2, 1   ## bblock 172, line 390-12,  t668,  t669,  1(SI32)
;;								## 62
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.37   ## bblock 172, line 390-12, 0(I32), t668
;;								## 63
	c0    stb 0[$r0.2] = $r0.17   ## bblock 172, line 390-12, t669, t671(I8)
	c0    mtb $b0.4 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.4, L237?3   ## bblock 172, line 392-12,  t840(I1)
;;								## 64
	c0    ldbu $r0.18 = 0[$r0.18]   ## bblock 170, line 390-13, t665(I8), t306
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 170, line 390-13, t663, 0(I32)
	c0    cmpleu $b0.4 = $r0.32, ((htab + 0) + 4096)   ## [spec] bblock 28, line 392-1,  t792(I1),  t650,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.17 = $r0.24, (~0xf)   ## [spec] bblock 147, line 0-1,  t305,  t642,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.4   ## [spec] t823(I1)
	      xnop 1
;;								## 66
	c0    add $r0.37 = $r0.2, 1   ## bblock 170, line 390-13,  t662,  t663,  1(SI32)
;;								## 67
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.37   ## bblock 170, line 390-13, 0(I32), t662
;;								## 68
	c0    stb 0[$r0.2] = $r0.18   ## bblock 170, line 390-13, t663, t665(I8)
	c0    mtb $b0.5 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.5, L238?3   ## bblock 170, line 392-13,  t839(I1)
;;								## 69
	c0    ldbu $r0.19 = 0[$r0.19]   ## bblock 168, line 390-14, t659(I8), t307
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 168, line 390-14, t657, 0(I32)
	c0    cmpleu $b0.5 = $r0.31, ((htab + 0) + 4096)   ## [spec] bblock 29, line 392-1,  t793(I1),  t651,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.18 = $r0.23, (~0xf)   ## [spec] bblock 147, line 0-1,  t306,  t643,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.5   ## [spec] t823(I1)
	      xnop 1
;;								## 71
	c0    add $r0.37 = $r0.2, 1   ## bblock 168, line 390-14,  t656,  t657,  1(SI32)
;;								## 72
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.37   ## bblock 168, line 390-14, 0(I32), t656
;;								## 73
	c0    stb 0[$r0.2] = $r0.19   ## bblock 168, line 390-14, t657, t659(I8)
	c0    mtb $b0.6 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.6, L239?3   ## bblock 168, line 392-14,  t838(I1)
;;								## 74
	c0    ldbu $r0.20 = 0[$r0.20]   ## bblock 166, line 390-15, t653(I8), t308
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 166, line 390-15, t698, 0(I32)
	c0    add $r0.21 = $r0.21, -16   ## bblock 166, line 389-15,  t93,  t93,  -16(SI32)
	c0    cmpleu $b0.6 = $r0.30, ((htab + 0) + 4096)   ## [spec] bblock 120, line 392-1,  t797(I1),  t652,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.19 = $r0.22, (~0xf)   ## [spec] bblock 147, line 0-1,  t307,  t644,  (~0xf)(I32)
	c0    mfb $r0.4 = $b0.6   ## [spec] t823(I1)
	      xnop 1
;;								## 76
	c0    add $r0.37 = $r0.2, 1   ## bblock 166, line 390-15,  t699,  t698,  1(SI32)
;;								## 77
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.37   ## bblock 166, line 390-15, 0(I32), t699
;;								## 78
	c0    stb 0[$r0.2] = $r0.20   ## bblock 166, line 390-15, t698, t653(I8)
	c0    mtb $b0.7 = $r0.4   ## [spec] t823(I1)
	c0    br $b0.7, L240?3   ## bblock 166, line 392-15,  t837(I1)
;;								## 79
	c0    mov $r0.5 = $r0.3   ## bblock 150, line 0-1,  t94,  t646
	c0    ldbu $r0.4 = 0[$r0.3]   ## bblock 150, line 390-1, t50(I8), t646
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 150, line 390-1, t52, 0(I32)
	c0    cmpleu $b0.7 = $r0.29, ((htab + 0) + 4096)   ## [spec] bblock 123, line 392-1,  t799(I1),  t691,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	c0    add $r0.20 = $r0.36, (~0xf)   ## [spec] bblock 147, line 0-1,  t308,  t645,  (~0xf)(I32)
	c0    mov $r0.3 = $r0.38   ## [spec] t309
	c0    mfb $r0.37 = $b0.7   ## [spec] t823(I1)
	      xnop 1
;;								## 81
	c0    add $r0.38 = $r0.2, 1   ## bblock 150, line 390-1,  t53,  t52,  1(SI32)
;;								## 82
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.38   ## bblock 150, line 390-1, 0(I32), t53
;;								## 83
	c0    stb 0[$r0.2] = $r0.4   ## bblock 150, line 390-1, t52, t50(I8)
	c0    br $b0.0, L225?3   ## bblock 150, line 392-1,  t826(I1)
;;								## 84
	c0    ldbu $r0.35 = 0[$r0.35]   ## bblock 35, line 390-1, t745(I8), t647
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 35, line 390-1, t743, 0(I32)
	c0    cmpleu $b0.0 = $r0.28, ((htab + 0) + 4096)   ## [spec] bblock 126, line 392-1,  t802(I1),  t692,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	      xnop 1
;;								## 86
	c0    add $r0.4 = $r0.2, 1   ## bblock 35, line 390-1,  t742,  t743,  1(SI32)
;;								## 87
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 35, line 390-1, 0(I32), t742
;;								## 88
	c0    stb 0[$r0.2] = $r0.35   ## bblock 35, line 390-1, t743, t745(I8)
	c0    br $b0.1, L226?3   ## bblock 35, line 392-1,  t796(I1)
;;								## 89
	c0    ldbu $r0.34 = 0[$r0.34]   ## bblock 31, line 390-1, t749(I8), t648
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 31, line 390-1, t747, 0(I32)
	c0    cmpleu $b0.1 = $r0.27, ((htab + 0) + 4096)   ## [spec] bblock 129, line 392-1,  t805(I1),  t302,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	      xnop 1
;;								## 91
	c0    add $r0.4 = $r0.2, 1   ## bblock 31, line 390-1,  t746,  t747,  1(SI32)
;;								## 92
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 31, line 390-1, 0(I32), t746
;;								## 93
	c0    stb 0[$r0.2] = $r0.34   ## bblock 31, line 390-1, t747, t749(I8)
	c0    br $b0.2, L227?3   ## bblock 31, line 392-1,  t794(I1)
;;								## 94
	c0    ldbu $r0.33 = 0[$r0.33]   ## bblock 32, line 390-1, t753(I8), t649
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 32, line 390-1, t751, 0(I32)
	c0    cmpleu $b0.2 = $r0.26, ((htab + 0) + 4096)   ## [spec] bblock 132, line 392-1,  t808(I1),  t303,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	      xnop 1
;;								## 96
	c0    add $r0.4 = $r0.2, 1   ## bblock 32, line 390-1,  t750,  t751,  1(SI32)
;;								## 97
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 32, line 390-1, 0(I32), t750
;;								## 98
	c0    stb 0[$r0.2] = $r0.33   ## bblock 32, line 390-1, t751, t753(I8)
	c0    br $b0.3, L228?3   ## bblock 32, line 392-1,  t795(I1)
;;								## 99
	c0    ldbu $r0.32 = 0[$r0.32]   ## bblock 28, line 390-1, t757(I8), t650
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 28, line 390-1, t755, 0(I32)
	c0    cmpleu $b0.3 = $r0.25, ((htab + 0) + 4096)   ## [spec] bblock 135, line 392-1,  t811(I1),  t641,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	      xnop 1
;;								## 101
	c0    add $r0.4 = $r0.2, 1   ## bblock 28, line 390-1,  t754,  t755,  1(SI32)
;;								## 102
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 28, line 390-1, 0(I32), t754
;;								## 103
	c0    stb 0[$r0.2] = $r0.32   ## bblock 28, line 390-1, t755, t757(I8)
	c0    br $b0.4, L229?3   ## bblock 28, line 392-1,  t792(I1)
;;								## 104
	c0    ldbu $r0.31 = 0[$r0.31]   ## bblock 29, line 390-1, t761(I8), t651
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 29, line 390-1, t759, 0(I32)
	c0    cmpleu $b0.4 = $r0.24, ((htab + 0) + 4096)   ## [spec] bblock 138, line 392-1,  t814(I1),  t642,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	      xnop 1
;;								## 106
	c0    add $r0.4 = $r0.2, 1   ## bblock 29, line 390-1,  t758,  t759,  1(SI32)
;;								## 107
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 29, line 390-1, 0(I32), t758
;;								## 108
	c0    stb 0[$r0.2] = $r0.31   ## bblock 29, line 390-1, t759, t761(I8)
	c0    br $b0.5, L230?3   ## bblock 29, line 392-1,  t793(I1)
;;								## 109
	c0    ldbu $r0.30 = 0[$r0.30]   ## bblock 120, line 390-1, t765(I8), t652
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 120, line 390-1, t763, 0(I32)
	c0    cmpleu $b0.5 = $r0.23, ((htab + 0) + 4096)   ## [spec] bblock 141, line 392-1,  t817(I1),  t643,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	      xnop 1
;;								## 111
	c0    add $r0.4 = $r0.2, 1   ## bblock 120, line 390-1,  t762,  t763,  1(SI32)
;;								## 112
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 120, line 390-1, 0(I32), t762
;;								## 113
	c0    stb 0[$r0.2] = $r0.30   ## bblock 120, line 390-1, t763, t765(I8)
	c0    br $b0.6, L231?3   ## bblock 120, line 392-1,  t797(I1)
;;								## 114
	c0    ldbu $r0.29 = 0[$r0.29]   ## bblock 123, line 390-1, t769(I8), t691
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 123, line 390-1, t767, 0(I32)
	c0    cmpleu $b0.6 = $r0.22, ((htab + 0) + 4096)   ## [spec] bblock 144, line 392-1,  t820(I1),  t644,  (addr(htab?1.0)(P32) + 0x1000(I32))(P32)
	      xnop 1
;;								## 116
	c0    add $r0.4 = $r0.2, 1   ## bblock 123, line 390-1,  t766,  t767,  1(SI32)
;;								## 117
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 123, line 390-1, 0(I32), t766
;;								## 118
	c0    stb 0[$r0.2] = $r0.29   ## bblock 123, line 390-1, t767, t769(I8)
	c0    br $b0.7, L232?3   ## bblock 123, line 392-1,  t799(I1)
;;								## 119
	c0    ldbu $r0.28 = 0[$r0.28]   ## bblock 126, line 390-1, t773(I8), t692
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 126, line 390-1, t771, 0(I32)
	c0    mtb $b0.7 = $r0.37   ## [spec] t823(I1)
	      xnop 1
;;								## 121
	c0    add $r0.4 = $r0.2, 1   ## bblock 126, line 390-1,  t770,  t771,  1(SI32)
;;								## 122
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 126, line 390-1, 0(I32), t770
;;								## 123
	c0    stb 0[$r0.2] = $r0.28   ## bblock 126, line 390-1, t771, t773(I8)
	c0    br $b0.0, L233?3   ## bblock 126, line 392-1,  t802(I1)
;;								## 124
	c0    ldbu $r0.27 = 0[$r0.27]   ## bblock 129, line 390-1, t777(I8), t302
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 129, line 390-1, t775, 0(I32)
	      xnop 1
;;								## 126
	c0    add $r0.4 = $r0.2, 1   ## bblock 129, line 390-1,  t774,  t775,  1(SI32)
;;								## 127
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 129, line 390-1, 0(I32), t774
;;								## 128
	c0    stb 0[$r0.2] = $r0.27   ## bblock 129, line 390-1, t775, t777(I8)
	c0    br $b0.1, L234?3   ## bblock 129, line 392-1,  t805(I1)
;;								## 129
	c0    ldbu $r0.26 = 0[$r0.26]   ## bblock 132, line 390-1, t235(I8), t303
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 132, line 390-1, t237, 0(I32)
	      xnop 1
;;								## 131
	c0    add $r0.4 = $r0.2, 1   ## bblock 132, line 390-1,  t238,  t237,  1(SI32)
;;								## 132
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 132, line 390-1, 0(I32), t238
;;								## 133
	c0    stb 0[$r0.2] = $r0.26   ## bblock 132, line 390-1, t237, t235(I8)
	c0    br $b0.2, L235?3   ## bblock 132, line 392-1,  t808(I1)
;;								## 134
	c0    ldbu $r0.25 = 0[$r0.25]   ## bblock 135, line 390-1, t229(I8), t641
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 135, line 390-1, t231, 0(I32)
	      xnop 1
;;								## 136
	c0    add $r0.4 = $r0.2, 1   ## bblock 135, line 390-1,  t232,  t231,  1(SI32)
;;								## 137
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 135, line 390-1, 0(I32), t232
;;								## 138
	c0    stb 0[$r0.2] = $r0.25   ## bblock 135, line 390-1, t231, t229(I8)
	c0    br $b0.3, L236?3   ## bblock 135, line 392-1,  t811(I1)
;;								## 139
	c0    ldbu $r0.24 = 0[$r0.24]   ## bblock 138, line 390-1, t223(I8), t642
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 138, line 390-1, t225, 0(I32)
	      xnop 1
;;								## 141
	c0    add $r0.4 = $r0.2, 1   ## bblock 138, line 390-1,  t226,  t225,  1(SI32)
;;								## 142
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 138, line 390-1, 0(I32), t226
;;								## 143
	c0    stb 0[$r0.2] = $r0.24   ## bblock 138, line 390-1, t225, t223(I8)
	c0    br $b0.4, L237?3   ## bblock 138, line 392-1,  t814(I1)
;;								## 144
	c0    ldbu $r0.23 = 0[$r0.23]   ## bblock 141, line 390-1, t217(I8), t643
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 141, line 390-1, t219, 0(I32)
	      xnop 1
;;								## 146
	c0    add $r0.4 = $r0.2, 1   ## bblock 141, line 390-1,  t220,  t219,  1(SI32)
;;								## 147
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 141, line 390-1, 0(I32), t220
;;								## 148
	c0    stb 0[$r0.2] = $r0.23   ## bblock 141, line 390-1, t219, t217(I8)
	c0    br $b0.5, L238?3   ## bblock 141, line 392-1,  t817(I1)
;;								## 149
	c0    ldbu $r0.22 = 0[$r0.22]   ## bblock 144, line 390-1, t211(I8), t644
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 144, line 390-1, t213, 0(I32)
	      xnop 1
;;								## 151
	c0    add $r0.4 = $r0.2, 1   ## bblock 144, line 390-1,  t214,  t213,  1(SI32)
;;								## 152
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 144, line 390-1, 0(I32), t214
;;								## 153
	c0    stb 0[$r0.2] = $r0.22   ## bblock 144, line 390-1, t213, t211(I8)
	c0    br $b0.6, L239?3   ## bblock 144, line 392-1,  t820(I1)
;;								## 154
	c0    ldbu $r0.36 = 0[$r0.36]   ## bblock 147, line 390-1, t206(I8), t645
	c0    ldw $r0.2 = ((outbuf + 0) + 0)[$r0.0]   ## bblock 147, line 390-1, t208, 0(I32)
	c0    add $r0.21 = $r0.21, -16   ## bblock 147, line 389-1,  t93,  t93,  -16(SI32)
	      xnop 1
;;								## 156
	c0    add $r0.4 = $r0.2, 1   ## bblock 147, line 390-1,  t209,  t208,  1(SI32)
;;								## 157
	c0    stw ((outbuf + 0) + 0)[$r0.0] = $r0.4   ## bblock 147, line 390-1, 0(I32), t209
;;								## 158
	c0    stb 0[$r0.2] = $r0.36   ## bblock 147, line 390-1, t208, t206(I8)
	c0    br $b0.7, L240?3   ## bblock 147, line 392-1,  t823(I1)
	      ## goto
;;
	c0    goto L224?3 ## goto
;;								## 159
.trace 45
L240?3:
	c0    add $r0.58 = $r0.5, (~0xe)   ## bblock 167, line 0,  t0,  t94,  (~0xe)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 15
L243?3:
	c0    add $r0.4 = $r0.2, 1   ## bblock 15, line 397,  t65,  t80,  1(SI32)
	c0    sh1add $r0.3 = $r0.2, (codetab + 0)   ## bblock 15, line 395,  t787,  t80,  addr(codetab?1.0)(P32)
	c0    stb (htab + 0)[$r0.2] = $r0.57   ## bblock 15, line 396, t80, t1
;;								## 0
	c0    sth 0[$r0.3] = $r0.59   ## bblock 15, line 395, t787, t3
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.4   ## bblock 15, line 397, 0(I32), t65
	c0    goto L242?3 ## goto
;;								## 1
.trace 44
L239?3:
	c0    add $r0.58 = $r0.21, (~0xe)   ## bblock 169, line 0,  t0,  t93,  (~0xe)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 43
L238?3:
	c0    add $r0.58 = $r0.21, (~0xd)   ## bblock 171, line 0,  t0,  t93,  (~0xd)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 42
L237?3:
	c0    add $r0.58 = $r0.21, (~0xc)   ## bblock 173, line 0,  t0,  t93,  (~0xc)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 41
L236?3:
	c0    add $r0.58 = $r0.21, (~0xb)   ## bblock 175, line 0,  t0,  t93,  (~0xb)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 40
L235?3:
	c0    add $r0.58 = $r0.21, (~0xa)   ## bblock 177, line 0,  t0,  t93,  (~0xa)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 39
L234?3:
	c0    add $r0.58 = $r0.21, (~0x9)   ## bblock 179, line 0,  t0,  t93,  (~0x9)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 38
L233?3:
	c0    add $r0.58 = $r0.21, (~0x8)   ## bblock 181, line 0,  t0,  t93,  (~0x8)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 36
L232?3:
	c0    add $r0.58 = $r0.21, (~0x7)   ## bblock 183, line 0,  t0,  t93,  (~0x7)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 35
L231?3:
	c0    add $r0.58 = $r0.21, (~0x6)   ## bblock 185, line 0,  t0,  t93,  (~0x6)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 33
L230?3:
	c0    add $r0.58 = $r0.21, (~0x5)   ## bblock 187, line 0,  t0,  t93,  (~0x5)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 32
L229?3:
	c0    add $r0.58 = $r0.21, (~0x4)   ## bblock 189, line 0,  t0,  t93,  (~0x4)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 30
L228?3:
	c0    add $r0.58 = $r0.21, (~0x3)   ## bblock 191, line 0,  t0,  t93,  (~0x3)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 29
L227?3:
	c0    add $r0.58 = $r0.21, (~0x2)   ## bblock 193, line 0,  t0,  t93,  (~0x2)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 27
L226?3:
	c0    add $r0.58 = $r0.21, (~0x1)   ## bblock 195, line 0,  t0,  t93,  (~0x1)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
	c0    goto L241?3 ## goto
;;								## 0
.trace 12
L225?3:
	c0    add $r0.58 = $r0.21, (~0x0)   ## bblock 196, line 0,  t0,  t93,  (~0x0)(I32)
	c0    ldw $r0.2 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 13, line 393, t80, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 13, line 393, t58, 0(I32)
;;								## 0
L241?3:
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.3   ## bblock 13, line 393,  t786(I1),  t80,  t58
;;								## 2
	c0    br $b0.0, L243?3   ## bblock 13, line 393,  t786(I1)
;;								## 3
L242?3:
	c0    mov $r0.59 = $r0.41   ## bblock 14, line 399,  t3,  t4
	c0    goto L200?3 ## goto
;;								## 4
.trace 34
L221?3:
	c0    add $r0.5 = $r0.5, 14   ## bblock 125, line 0,  t139,  t0,  14(I32)
	c0    mov $r0.2 = $r0.7   ## bblock 125, line 0,  t141,  t155
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 31
L220?3:
	c0    add $r0.5 = $r0.5, 13   ## bblock 128, line 0,  t139,  t0,  13(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 128, line 0,  t141,  t159
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 28
L219?3:
	c0    add $r0.5 = $r0.5, 12   ## bblock 131, line 0,  t139,  t0,  12(I32)
	c0    mov $r0.2 = $r0.7   ## bblock 131, line 0,  t141,  t163
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 26
L218?3:
	c0    add $r0.5 = $r0.5, 11   ## bblock 134, line 0,  t139,  t0,  11(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 134, line 0,  t141,  t167
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 25
L217?3:
	c0    add $r0.5 = $r0.5, 10   ## bblock 137, line 0,  t139,  t0,  10(I32)
	c0    mov $r0.2 = $r0.7   ## bblock 137, line 0,  t141,  t171
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 24
L216?3:
	c0    add $r0.5 = $r0.5, 9   ## bblock 140, line 0,  t139,  t0,  9(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 140, line 0,  t141,  t175
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 23
L215?3:
	c0    add $r0.5 = $r0.5, 8   ## bblock 143, line 0,  t139,  t0,  8(I32)
	c0    mov $r0.2 = $r0.7   ## bblock 143, line 0,  t141,  t179
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 22
L214?3:
	c0    add $r0.5 = $r0.5, 7   ## bblock 146, line 0,  t139,  t0,  7(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 146, line 0,  t141,  t183
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 21
L213?3:
	c0    add $r0.5 = $r0.5, 6   ## bblock 149, line 0,  t139,  t0,  6(I32)
	c0    mov $r0.2 = $r0.7   ## bblock 149, line 0,  t141,  t187
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 20
L212?3:
	c0    add $r0.5 = $r0.5, 5   ## bblock 152, line 0,  t139,  t0,  5(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 152, line 0,  t141,  t191
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 19
L211?3:
	c0    add $r0.5 = $r0.5, 4   ## bblock 155, line 0,  t139,  t0,  4(I32)
	c0    mov $r0.2 = $r0.7   ## bblock 155, line 0,  t141,  t195
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 18
L210?3:
	c0    add $r0.5 = $r0.5, 3   ## bblock 158, line 0,  t139,  t0,  3(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 158, line 0,  t141,  t199
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 17
L209?3:
	c0    add $r0.5 = $r0.5, 2   ## bblock 161, line 0,  t139,  t0,  2(I32)
	c0    mov $r0.2 = $r0.7   ## bblock 161, line 0,  t141,  t203
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 16
L208?3:
	c0    add $r0.5 = $r0.5, 1   ## bblock 164, line 0,  t139,  t0,  1(I32)
	c0    mov $r0.2 = $r0.6   ## bblock 164, line 0,  t141,  t90
	c0    mov $r0.41 = $r0.8   ## t4
	c0    goto L223?3 ## goto
;;								## 0
.trace 11
L207?3:
	   ## bblock 165, line 0,  t141,  t78## $r0.2(skipped)
	   ## bblock 165, line 0,  t139,  t0## $r0.5(skipped)
	c0    mov $r0.41 = $r0.8   ## t4
;;								## 0
L223?3:
	c0    ldbu $r0.57 = (htab + 0)[$r0.2]   ## bblock 11, line 386, t1, t141
	c0    add $r0.8 = $r0.5, (~0x2)   ## bblock 11, line 0,  t296,  t139,  (~0x2)(I32)
	c0    mov $r0.3 = $r0.5   ## bblock 11, line 0,  t309,  t139
	c0    add $r0.21 = $r0.5, 1   ## bblock 11, line 386,  t93,  t139,  1(SI32)
	c0    add $r0.20 = $r0.5, (~0xe)   ## bblock 11, line 0,  t308,  t139,  (~0xe)(I32)
	c0    add $r0.19 = $r0.5, (~0xd)   ## bblock 11, line 0,  t307,  t139,  (~0xd)(I32)
	c0    add $r0.18 = $r0.5, (~0xc)   ## bblock 11, line 0,  t306,  t139,  (~0xc)(I32)
	c0    add $r0.17 = $r0.5, (~0xb)   ## bblock 11, line 0,  t305,  t139,  (~0xb)(I32)
	c0    add $r0.16 = $r0.5, (~0xa)   ## bblock 11, line 0,  t304,  t139,  (~0xa)(I32)
	c0    add $r0.15 = $r0.5, (~0x9)   ## bblock 11, line 0,  t639,  t139,  (~0x9)(I32)
	c0    add $r0.14 = $r0.5, (~0x8)   ## bblock 11, line 0,  t640,  t139,  (~0x8)(I32)
	c0    add $r0.13 = $r0.5, (~0x7)   ## bblock 11, line 0,  t301,  t139,  (~0x7)(I32)
	c0    add $r0.12 = $r0.5, (~0x6)   ## bblock 11, line 0,  t300,  t139,  (~0x6)(I32)
	c0    add $r0.11 = $r0.5, (~0x5)   ## bblock 11, line 0,  t299,  t139,  (~0x5)(I32)
	c0    add $r0.10 = $r0.5, (~0x4)   ## bblock 11, line 0,  t298,  t139,  (~0x4)(I32)
	c0    add $r0.9 = $r0.5, (~0x3)   ## bblock 11, line 0,  t297,  t139,  (~0x3)(I32)
	c0    add $r0.7 = $r0.5, (~0x1)   ## bblock 11, line 0,  t295,  t139,  (~0x1)(I32)
	c0    add $r0.6 = $r0.5, (~0x0)   ## bblock 11, line 0,  t294,  t139,  (~0x0)(I32)
	      xnop 1
;;								## 2
	c0    stb 0[$r0.5] = $r0.57   ## bblock 11, line 386, t139, t1
	c0    goto L224?3 ## goto
;;								## 3
.trace 14
L205?3:
	c0    mov $r0.5 = $r0.58   ## t0
	c0    goto L206?3 ## goto
;;								## 0
.trace 65
L201?3:
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $r0.59 = 0x1c[$r0.1]  ## restore ## t72
	c0    ldw $r0.58 = 0x18[$r0.1]  ## restore ## t71
	c0    ldw $r0.57 = 0x14[$r0.1]  ## restore ## t70
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t66
	      xnop 1
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 7, line 401,  t67,  ?2.7?2auto_size(I32),  t66
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
.trace 12
	      ## auto_size == 0
	c0    ldw $r0.7 = ((_?1PACKET.13 + 0) + 0)[$r0.0]   ## bblock 0, line 404, t89, 0(I32)
	c0    ldw $r0.8 = ((_?1PACKET.14 + 0) + 0)[$r0.0]   ## bblock 0, line 404, t88, 0(I32)
	c0    ldw $r0.2 = ((maxbits + 0) + 0)[$r0.0]   ## bblock 0, line 404, t87, 0(I32)
	c0    ldw $r0.3 = ((maxmaxcode + 0) + 0)[$r0.0]   ## bblock 0, line 404, t86, 0(I32)
	c0    ldw $r0.5 = ((free_ent + 0) + 0)[$r0.0]   ## bblock 0, line 404, t85, 0(I32)
	c0    ldw $r0.4 = ((clear_flg + 0) + 0)[$r0.0]   ## bblock 0, line 411, t6, 0(I32)
	c0    ldw $r0.6 = ((maxcode + 0) + 0)[$r0.0]   ## bblock 0, line 411, t12, 0(I32)
	c0    ldw.d $r0.9 = ((n_bits + 0) + 0)[$r0.0]   ## [spec] bblock 17, line 415, t16, 0(I32)
	      xnop 1
;;								## 1
	c0    cmpge $r0.11 = $r0.7, $r0.8   ## bblock 0, line 411,  t10,  t89,  t88
	c0    cmpgt $r0.4 = $r0.4, $r0.0   ## bblock 0, line 411,  t7,  t6,  0(SI32)
	c0    cmpgt $r0.10 = $r0.5, $r0.6   ## bblock 0, line 411,  t13,  t85,  t12
	c0    cmpgt $b0.0 = $r0.5, $r0.6   ## [spec] bblock 4, line 413,  t195(I1),  t85,  t12
	c0    add $r0.9 = $r0.9, 1   ## [spec] bblock 17, line 415,  t18,  t16,  1(SI32)
;;								## 2
	c0    orl $r0.4 = $r0.4, $r0.10   ## bblock 0, line 411,  t192,  t7,  t13
	c0    cmpeq $b0.1 = $r0.9, $r0.2   ## [spec] bblock 17, line 416,  t203(I1),  t18,  t87
;;								## 3
	c0    orl $b0.2 = $r0.4, $r0.11   ## bblock 0, line 411,  t193(I1),  t192,  t10
;;								## 4
	c0    brf $b0.2, L244?3   ## bblock 0, line 411,  t193(I1)
;;								## 5
	c0    brf $b0.0, L245?3   ## bblock 4, line 413,  t195(I1)
;;								## 6
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.9   ## bblock 17, line 415, 0(I32), t18
	c0    brf $b0.1, L246?3   ## bblock 17, line 416,  t203(I1)
;;								## 7
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.3   ## bblock 19, line 417, 0(I32), t86
;;								## 8
.trace 14
L245?3:
	c0    ldw $r0.2 = ((clear_flg + 0) + 0)[$r0.0]   ## bblock 5, line 421, t24, 0(I32)
	c0    ldw.d $r0.4 = ((n_bits + 0) + 0)[$r0.0]   ## [spec] bblock 6, line 0, t90, 0(I32)
	c0    mov $r0.5 = $r0.0   ## [spec] bblock 6, line 427,  t94,  0(SI32)
	c0    mov $r0.17 = $r0.7   ## t89
	      xnop 1
;;								## 1
	c0    cmpgt $b0.0 = $r0.2, $r0.0   ## bblock 5, line 421,  t196(I1),  t24,  0(SI32)
	c0    sub $r0.6 = $r0.0, $r0.4   ## [spec] bblock 6, line 0,  t112,  0(I32),  t90
	c0    mov $r0.18 = $r0.4   ## [spec] t90
;;								## 2
	c0    mov $r0.3 = $r0.6   ## [spec] bblock 6, line 0,  t126,  t112
	c0    br $b0.0, L247?3   ## bblock 5, line 421,  t196(I1)
;;								## 3
.trace 1
L248?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 7, line 427,  t197(I1),  t126,  0(SI32)
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 11, line 429, t121, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 15, line 429, t34, 0(I32)
	c0    add $r0.6 = $r0.3, 1   ## [spec] bblock 14, line 0,  t131,  t126,  1(I32)
;;								## 0
	c0    cmplt $b0.0 = $r0.6, $r0.0   ## [spec] bblock 14, line 427-1,  t202(I1),  t131,  0(SI32)
	c0    add $r0.7 = $r0.6, 1   ## [spec] bblock 66, line 0-1,  t176,  t131,  1(I32)
	c0    brf $b0.0, L249?3   ## bblock 7, line 427,  t197(I1)
;;								## 1
	c0    add $r0.2 = $r0.2, -1   ## bblock 11, line 429,  t33,  t121,  -1(SI32)
	c0    add $r0.8 = $r0.4, 1   ## [spec] bblock 15, line 429,  t124,  t34,  1(SI32)
	c0    cmplt $b0.1 = $r0.7, $r0.0   ## [spec] bblock 66, line 427-2,  t225(I1),  t176,  0(SI32)
	c0    add $r0.9 = $r0.7, 1   ## [spec] bblock 60, line 0-2,  t167,  t176,  1(I32)
;;								## 2
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 11, line 429, 0(I32), t33
	c0    cmpge $b0.2 = $r0.2, $r0.0   ## bblock 11, line 429,  t200(I1),  t33,  0(SI32)
	c0    cmplt $b0.3 = $r0.9, $r0.0   ## [spec] bblock 60, line 427-3,  t222(I1),  t167,  0(SI32)
	c0    add $r0.10 = $r0.9, 1   ## [spec] bblock 54, line 0-3,  t158,  t167,  1(I32)
;;								## 3
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 63, line 429-1, t185, 0(I32)
	c0    cmplt $b0.2 = $r0.10, $r0.0   ## [spec] bblock 54, line 427-4,  t219(I1),  t158,  0(SI32)
	c0    add $r0.11 = $r0.10, 1   ## [spec] bblock 48, line 0-4,  t149,  t158,  1(I32)
	c0    brf $b0.2, L250?3   ## bblock 11, line 429,  t200(I1)
;;								## 4
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.8   ## bblock 15, line 429, 0(I32), t124
	c0    cmplt $b0.4 = $r0.11, $r0.0   ## [spec] bblock 48, line 427-5,  t216(I1),  t149,  0(SI32)
	c0    add $r0.12 = $r0.11, 1   ## [spec] bblock 42, line 0-5,  t140,  t149,  1(I32)
;;								## 5
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 15, line 429, t123(SI8), t34
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 63, line 429-1,  t186,  t185,  -1(SI32)
	c0    ldw.d $r0.8 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 67, line 429-1, t189, 0(I32)
	c0    cmplt $b0.5 = $r0.12, $r0.0   ## [spec] bblock 42, line 427-6,  t213(I1),  t140,  0(SI32)
	c0    add $r0.13 = $r0.12, 1   ## [spec] bblock 36, line 0-6,  t111,  t140,  1(I32)
;;								## 6
	c0    cmpge $b0.6 = $r0.2, $r0.0   ## [spec] bblock 63, line 429-1,  t223(I1),  t186,  0(SI32)
	c0    cmplt $b0.7 = $r0.13, $r0.0   ## [spec] bblock 36, line 427-7,  t210(I1),  t111,  0(SI32)
	c0    add $r0.14 = $r0.13, 1   ## [spec] bblock 30, line 0-7,  t130,  t111,  1(I32)
;;								## 7
	c0    zxtb $r0.4 = $r0.4   ## bblock 15, line 429,  t122(I8),  t123(SI8)
	c0    add $r0.15 = $r0.8, 1   ## [spec] bblock 67, line 429-1,  t190,  t189,  1(SI32)
	c0    add $r0.3 = $r0.14, 1   ## [spec] bblock 24, line 0-8,  t126,  t130,  1(I32)
;;								## 8
L251?3:
	c0    zxtb $r0.16 = $r0.4   ## bblock 13, line 429,  t41(I8),  t122(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.4   ## bblock 13, line 429, t94, t122(I8)
;;								## 9
	c0    mfb $r0.4 = $b0.7   ## [spec] t210(I1)
;;								## 10
	c0    cmpeq $b0.7 = $r0.16, 255   ## bblock 13, line 430,  t201(I1),  t41(I8),  255(SI32)
;;								## 11
	c0    mtb $b0.7 = $r0.4   ## [spec] t210(I1)
	c0    br $b0.7, L252?3   ## bblock 13, line 430,  t201(I1)
;;								## 12
	c0    add $r0.5 = $r0.5, 1   ## bblock 14, line 427,  t94,  t94,  1(SI32)
	c0    cmplt $b0.0 = $r0.14, $r0.0   ## [spec] bblock 30, line 427-8,  t207(I1),  t130,  0(SI32)
	c0    brf $b0.0, L249?3   ## bblock 14, line 427-1,  t202(I1)
;;								## 13
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 63, line 429-1, 0(I32), t186
	c0    brf $b0.6, L253?3   ## bblock 63, line 429-1,  t223(I1)
;;								## 14
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.15   ## bblock 67, line 429-1, 0(I32), t190
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 57, line 429-2, t177, 0(I32)
;;								## 15
	c0    ldb $r0.8 = 0[$r0.8]   ## bblock 67, line 429-1, t191(SI8), t189
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 61, line 429-2, t181, 0(I32)
;;								## 16
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 57, line 429-2,  t178,  t177,  -1(SI32)
;;								## 17
	c0    zxtb $r0.8 = $r0.8   ## bblock 67, line 429-1,  t187(I8),  t191(SI8)
	c0    cmpge $b0.6 = $r0.2, $r0.0   ## [spec] bblock 57, line 429-2,  t220(I1),  t178,  0(SI32)
	c0    add $r0.6 = $r0.4, 1   ## [spec] bblock 61, line 429-2,  t182,  t181,  1(SI32)
;;								## 18
L254?3:
	c0    zxtb $r0.15 = $r0.8   ## bblock 65, line 429-1,  t188(I8),  t187(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.8   ## bblock 65, line 429-1, t94, t187(I8)
;;								## 19
	c0    mfb $r0.8 = $b0.0   ## [spec] t207(I1)
;;								## 20
	c0    cmpeq $b0.0 = $r0.15, 255   ## bblock 65, line 430-1,  t224(I1),  t188(I8),  255(SI32)
;;								## 21
	c0    mtb $b0.0 = $r0.8   ## [spec] t207(I1)
	c0    br $b0.0, L252?3   ## bblock 65, line 430-1,  t224(I1)
;;								## 22
	c0    add $r0.5 = $r0.5, 1   ## bblock 66, line 427-1,  t94,  t94,  1(SI32)
	c0    brf $b0.1, L249?3   ## bblock 66, line 427-2,  t225(I1)
;;								## 23
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 57, line 429-2, 0(I32), t178
	c0    brf $b0.6, L255?3   ## bblock 57, line 429-2,  t220(I1)
;;								## 24
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.6   ## bblock 61, line 429-2, 0(I32), t182
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 51, line 429-3, t168, 0(I32)
;;								## 25
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 61, line 429-2, t183(SI8), t181
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 55, line 429-3, t172, 0(I32)
;;								## 26
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 51, line 429-3,  t169,  t168,  -1(SI32)
;;								## 27
	c0    zxtb $r0.4 = $r0.4   ## bblock 61, line 429-2,  t179(I8),  t183(SI8)
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 51, line 429-3,  t217(I1),  t169,  0(SI32)
	c0    add $r0.7 = $r0.6, 1   ## [spec] bblock 55, line 429-3,  t173,  t172,  1(SI32)
;;								## 28
L256?3:
	c0    zxtb $r0.8 = $r0.4   ## bblock 59, line 429-2,  t180(I8),  t179(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.4   ## bblock 59, line 429-2, t94, t179(I8)
;;								## 29
	c0    cmpeq $b0.6 = $r0.8, 255   ## bblock 59, line 430-2,  t221(I1),  t180(I8),  255(SI32)
;;								## 30
	c0    br $b0.6, L252?3   ## bblock 59, line 430-2,  t221(I1)
;;								## 31
	c0    add $r0.5 = $r0.5, 1   ## bblock 60, line 427-2,  t94,  t94,  1(SI32)
	c0    brf $b0.3, L249?3   ## bblock 60, line 427-3,  t222(I1)
;;								## 32
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 51, line 429-3, 0(I32), t169
	c0    brf $b0.1, L257?3   ## bblock 51, line 429-3,  t217(I1)
;;								## 33
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.7   ## bblock 55, line 429-3, 0(I32), t173
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 45, line 429-4, t159, 0(I32)
;;								## 34
	c0    ldb $r0.6 = 0[$r0.6]   ## bblock 55, line 429-3, t174(SI8), t172
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 49, line 429-4, t163, 0(I32)
;;								## 35
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 45, line 429-4,  t160,  t159,  -1(SI32)
;;								## 36
	c0    zxtb $r0.6 = $r0.6   ## bblock 55, line 429-3,  t170(I8),  t174(SI8)
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 45, line 429-4,  t214(I1),  t160,  0(SI32)
	c0    add $r0.7 = $r0.4, 1   ## [spec] bblock 49, line 429-4,  t164,  t163,  1(SI32)
;;								## 37
L258?3:
	c0    zxtb $r0.8 = $r0.6   ## bblock 53, line 429-3,  t171(I8),  t170(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.6   ## bblock 53, line 429-3, t94, t170(I8)
;;								## 38
	c0    cmpeq $b0.3 = $r0.8, 255   ## bblock 53, line 430-3,  t218(I1),  t171(I8),  255(SI32)
;;								## 39
	c0    br $b0.3, L252?3   ## bblock 53, line 430-3,  t218(I1)
;;								## 40
	c0    add $r0.5 = $r0.5, 1   ## bblock 54, line 427-3,  t94,  t94,  1(SI32)
	c0    brf $b0.2, L249?3   ## bblock 54, line 427-4,  t219(I1)
;;								## 41
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 45, line 429-4, 0(I32), t160
	c0    brf $b0.1, L259?3   ## bblock 45, line 429-4,  t214(I1)
;;								## 42
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.7   ## bblock 49, line 429-4, 0(I32), t164
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 39, line 429-5, t150, 0(I32)
;;								## 43
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 49, line 429-4, t165(SI8), t163
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 43, line 429-5, t154, 0(I32)
;;								## 44
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 39, line 429-5,  t151,  t150,  -1(SI32)
;;								## 45
	c0    zxtb $r0.4 = $r0.4   ## bblock 49, line 429-4,  t161(I8),  t165(SI8)
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 39, line 429-5,  t211(I1),  t151,  0(SI32)
	c0    add $r0.7 = $r0.6, 1   ## [spec] bblock 43, line 429-5,  t155,  t154,  1(SI32)
;;								## 46
L260?3:
	c0    zxtb $r0.8 = $r0.4   ## bblock 47, line 429-4,  t162(I8),  t161(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.4   ## bblock 47, line 429-4, t94, t161(I8)
;;								## 47
	c0    cmpeq $b0.2 = $r0.8, 255   ## bblock 47, line 430-4,  t215(I1),  t162(I8),  255(SI32)
;;								## 48
	c0    br $b0.2, L252?3   ## bblock 47, line 430-4,  t215(I1)
;;								## 49
	c0    add $r0.5 = $r0.5, 1   ## bblock 48, line 427-4,  t94,  t94,  1(SI32)
	c0    brf $b0.4, L249?3   ## bblock 48, line 427-5,  t216(I1)
;;								## 50
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 39, line 429-5, 0(I32), t151
	c0    brf $b0.1, L261?3   ## bblock 39, line 429-5,  t211(I1)
;;								## 51
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.7   ## bblock 43, line 429-5, 0(I32), t155
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 33, line 429-6, t141, 0(I32)
;;								## 52
	c0    ldb $r0.6 = 0[$r0.6]   ## bblock 43, line 429-5, t156(SI8), t154
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 37, line 429-6, t145, 0(I32)
;;								## 53
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 33, line 429-6,  t142,  t141,  -1(SI32)
;;								## 54
	c0    zxtb $r0.6 = $r0.6   ## bblock 43, line 429-5,  t152(I8),  t156(SI8)
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 33, line 429-6,  t208(I1),  t142,  0(SI32)
	c0    add $r0.7 = $r0.4, 1   ## [spec] bblock 37, line 429-6,  t146,  t145,  1(SI32)
;;								## 55
L262?3:
	c0    zxtb $r0.8 = $r0.6   ## bblock 41, line 429-5,  t153(I8),  t152(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.6   ## bblock 41, line 429-5, t94, t152(I8)
;;								## 56
	c0    cmpeq $b0.2 = $r0.8, 255   ## bblock 41, line 430-5,  t212(I1),  t153(I8),  255(SI32)
;;								## 57
	c0    br $b0.2, L252?3   ## bblock 41, line 430-5,  t212(I1)
;;								## 58
	c0    add $r0.5 = $r0.5, 1   ## bblock 42, line 427-5,  t94,  t94,  1(SI32)
	c0    brf $b0.5, L249?3   ## bblock 42, line 427-6,  t213(I1)
;;								## 59
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 33, line 429-6, 0(I32), t142
	c0    brf $b0.1, L263?3   ## bblock 33, line 429-6,  t208(I1)
;;								## 60
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.7   ## bblock 37, line 429-6, 0(I32), t146
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 27, line 429-7, t32, 0(I32)
;;								## 61
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 37, line 429-6, t147(SI8), t145
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 31, line 429-7, t136, 0(I32)
;;								## 62
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 27, line 429-7,  t134,  t32,  -1(SI32)
;;								## 63
	c0    zxtb $r0.4 = $r0.4   ## bblock 37, line 429-6,  t143(I8),  t147(SI8)
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 27, line 429-7,  t205(I1),  t134,  0(SI32)
	c0    add $r0.7 = $r0.6, 1   ## [spec] bblock 31, line 429-7,  t137,  t136,  1(SI32)
;;								## 64
L264?3:
	c0    zxtb $r0.8 = $r0.4   ## bblock 35, line 429-6,  t144(I8),  t143(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.4   ## bblock 35, line 429-6, t94, t143(I8)
;;								## 65
	c0    cmpeq $b0.2 = $r0.8, 255   ## bblock 35, line 430-6,  t209(I1),  t144(I8),  255(SI32)
;;								## 66
	c0    br $b0.2, L252?3   ## bblock 35, line 430-6,  t209(I1)
;;								## 67
	c0    add $r0.5 = $r0.5, 1   ## bblock 36, line 427-6,  t94,  t94,  1(SI32)
	c0    brf $b0.7, L249?3   ## bblock 36, line 427-7,  t210(I1)
;;								## 68
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 27, line 429-7, 0(I32), t134
	c0    brf $b0.1, L265?3   ## bblock 27, line 429-7,  t205(I1)
;;								## 69
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.7   ## bblock 31, line 429-7, 0(I32), t137
	c0    ldw.d $r0.2 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 3, line 429-8, t129, 0(I32)
;;								## 70
	c0    ldb $r0.6 = 0[$r0.6]   ## bblock 31, line 429-7, t138(SI8), t136
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 25, line 429-8, t125, 0(I32)
;;								## 71
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 3, line 429-8,  t128,  t129,  -1(SI32)
;;								## 72
	c0    zxtb $r0.6 = $r0.6   ## bblock 31, line 429-7,  t133(I8),  t138(SI8)
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 3, line 429-8,  t194(I1),  t128,  0(SI32)
	c0    add $r0.7 = $r0.4, 1   ## [spec] bblock 25, line 429-8,  t35,  t125,  1(SI32)
;;								## 73
L266?3:
	c0    zxtb $r0.8 = $r0.6   ## bblock 29, line 429-7,  t135(I8),  t133(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.6   ## bblock 29, line 429-7, t94, t133(I8)
;;								## 74
	c0    cmpeq $b0.2 = $r0.8, 255   ## bblock 29, line 430-7,  t206(I1),  t135(I8),  255(SI32)
;;								## 75
	c0    br $b0.2, L252?3   ## bblock 29, line 430-7,  t206(I1)
;;								## 76
	c0    add $r0.5 = $r0.5, 1   ## bblock 30, line 427-7,  t94,  t94,  1(SI32)
	c0    brf $b0.0, L249?3   ## bblock 30, line 427-8,  t207(I1)
;;								## 77
	c0    stw ((buflen + 0) + 0)[$r0.0] = $r0.2   ## bblock 3, line 429-8, 0(I32), t128
	c0    brf $b0.1, L267?3   ## bblock 3, line 429-8,  t194(I1)
;;								## 78
	c0    stw ((bufp + 0) + 0)[$r0.0] = $r0.7   ## bblock 25, line 429-8, 0(I32), t35
;;								## 79
	c0    ldb $r0.4 = 0[$r0.4]   ## bblock 25, line 429-8, t36(SI8), t125
	      xnop 1
;;								## 81
	c0    zxtb $r0.4 = $r0.4   ## bblock 25, line 429-8,  t31(I8),  t36(SI8)
;;								## 82
L268?3:
	c0    zxtb $r0.2 = $r0.4   ## bblock 23, line 429-8,  t127(I8),  t31(I8)
	c0    stb (_?1PACKET.15 + 0)[$r0.5] = $r0.4   ## bblock 23, line 429-8, t94, t31(I8)
;;								## 83
	c0    cmpeq $b0.0 = $r0.2, 255   ## bblock 23, line 430-8,  t204(I1),  t127(I8),  255(SI32)
;;								## 84
	c0    br $b0.0, L252?3   ## bblock 23, line 430-8,  t204(I1)
;;								## 85
	c0    add $r0.5 = $r0.5, 1   ## bblock 24, line 427-8,  t94,  t94,  1(SI32)
	c0    goto L248?3 ## goto
;;								## 86
.trace 18
L252?3:
	c0    mov $r0.18 = $r0.5   ## bblock 20, line 0,  t110,  t94
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    goto L269?3 ## goto
;;								## 0
.trace 17
L270?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 9, line 436, t43, 0(I32)
	c0    mov $r0.7 = $r0.0   ## bblock 9, line 435,  t89,  0(SI32)
	c0    shl $r0.18 = $r0.18, 3   ## bblock 9, line 436,  t45,  t110,  3(SI32)
;;								## 0
	c0    add $r0.18 = $r0.18, 1   ## bblock 9, line 436,  t199,  t45,  1(SI32)
;;								## 1
	c0    sub $r0.8 = $r0.18, $r0.2   ## bblock 9, line 436,  t88,  t199,  t43
;;								## 2
.trace 13
L244?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 1, line 439, t72, 0(I32)
	c0    shr $r0.5 = $r0.7, 3   ## bblock 1, line 440,  t49(SI29),  t89,  3(SI32)
	c0    and $r0.4 = $r0.7, 7   ## bblock 1, line 441,  t51,  t89,  7(I32)
	c0    stw ((_?1PACKET.14 + 0) + 0)[$r0.0] = $r0.8   ## bblock 1, line 455, 0(I32), t88
;;								## 0
	c0    add $r0.6 = $r0.5, (_?1PACKET.15 + 0)   ## bblock 1, line 440,  t52,  t49(SI29),  addr(buf?1.134)(P32)
	c0    ldbu $r0.11 = (_?1PACKET.15 + 0)[$r0.5]   ## bblock 1, line 443, t54(I8), t49(SI29)
	c0    add $r0.8 = $r0.5, ((_?1PACKET.15 + 0) + 1)   ## bblock 1, line 443,  t107,  t49(SI29),  (addr(buf?1.134)(P32) + 0x1(I32))(P32)
	c0    sub $r0.9 = 16, $r0.4   ## bblock 1, line 449,  t102,  16(SI32),  t51
	c0    sub $r0.10 = 8, $r0.4   ## bblock 1, line 445,  t105,  8(SI32),  t51
;;								## 1
	c0    add $r0.7 = $r0.2, $r0.7   ## bblock 1, line 454,  t93,  t72,  t89
	c0    add $r0.12 = $r0.2, $r0.4   ## bblock 1, line 444,  t118,  t72,  t51
	c0    ldbu.d $r0.14 = 1[$r0.6]   ## [spec] bblock 1, line 448, t97(I8), t52
	c0    add $r0.13 = $r0.6, 2   ## bblock 1, line 448,  t98,  t52,  2(SI32)
;;								## 2
	c0    shr $r0.11 = $r0.11, $r0.4   ## bblock 1, line 443,  t108,  t54(I8),  t51
	c0    add $r0.2 = $r0.12, -8   ## bblock 1, line 444,  t106,  t118,  -8(SI32)
	c0    add $r0.5 = $r0.12, -16   ## bblock 1, line 450,  t101,  t118,  -16(SI32)
	c0    stw ((_?1PACKET.13 + 0) + 0)[$r0.0] = $r0.7   ## bblock 1, line 455, 0(I32), t93
;;								## 3
	c0    cmpge $b0.0 = $r0.2, 8   ## bblock 1, line 446,  t96(I1),  t106,  8(SI32)
	c0    shl $r0.14 = $r0.14, $r0.10   ## bblock 1, line 448,  t99,  t97(I8),  t105
;;								## 4
	c0    slct $r0.5 = $b0.0, $r0.5, $r0.2   ## bblock 1, line 450,  t3,  t96(I1),  t101,  t106
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.10   ## bblock 1, line 449,  t2,  t96(I1),  t102,  t105
	c0    or $r0.14 = $r0.11, $r0.14   ## bblock 1, line 448,  t100,  t108,  t99
	c0    slct $r0.13 = $b0.0, $r0.13, $r0.8   ## bblock 1, line 448,  t4,  t96(I1),  t98,  t107
;;								## 5
	c0    slct $r0.14 = $b0.0, $r0.14, $r0.11   ## bblock 1, line 448,  t0,  t96(I1),  t100,  t108
	c0    ldbu $r0.13 = 0[$r0.13]   ## bblock 1, line 453, t67(I8), t4
	c0    ldbu $r0.5 = (rmask + 0)[$r0.5]   ## bblock 1, line 453, t66(I8), t3
	      xnop 1
;;								## 7
	c0    and $r0.13 = $r0.13, $r0.5   ## bblock 1, line 453,  t68,  t67(I8),  t66(I8)
;;								## 8
	c0    shl $r0.13 = $r0.13, $r0.9   ## bblock 1, line 453,  t69,  t68,  t2
;;								## 9
.return ret($r0.3:s32)
	c0    or $r0.3 = $r0.14, $r0.13   ## bblock 1, line 453,  t95,  t0,  t69
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 455,  t75,  ?2.8?2auto_size(I32),  t74
;;								## 10
.trace 11
L267?3:
	c0    mov $r0.4 = -1   ## bblock 22, line 429-8,  t31(I8),  -1(SI32)
	c0    goto L268?3 ## goto
;;								## 0
.trace 15
L249?3:
	c0    max $r0.18 = $r0.18, $r0.0   ## bblock 2, line 0,  t110,  t90,  0(SI32)
	c0    mov $r0.3 = -1   ## -1(SI32)
;;								## 0
L269?3:
	c0    cmple $b0.0 = $r0.18, $r0.0   ## bblock 8, line 433,  t198(I1),  t110,  0(SI32)
;;								## 1
	c0    brf $b0.0, L270?3   ## bblock 8, line 433,  t198(I1)
;;								## 2
.return ret($r0.3:s32)
	c0    stw ((_?1PACKET.14 + 0) + 0)[$r0.0] = $r0.18   ## bblock 10, line 434, 0(I32), t110
	c0    stw ((_?1PACKET.13 + 0) + 0)[$r0.0] = $r0.17   ## bblock 10, line 434, 0(I32), t89
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 10, line 434,  t75,  ?2.8?2auto_size(I32),  t74
;;								## 3
.trace 10
L265?3:
	c0    mov $r0.6 = -1   ## bblock 28, line 429-7,  t133(I8),  -1(SI32)
	c0    ldw.d $r0.8 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 3, line 429-8, t129, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 25, line 429-8, t125, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.8, -1   ## [spec] bblock 3, line 429-8,  t128,  t129,  -1(SI32)
	c0    add $r0.7 = $r0.4, 1   ## [spec] bblock 25, line 429-8,  t35,  t125,  1(SI32)
;;								## 2
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 3, line 429-8,  t194(I1),  t128,  0(SI32)
	c0    goto L266?3 ## goto
;;								## 3
.trace 9
L263?3:
	c0    mov $r0.4 = -1   ## bblock 34, line 429-6,  t143(I8),  -1(SI32)
	c0    ldw.d $r0.8 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 27, line 429-7, t32, 0(I32)
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 31, line 429-7, t136, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.8, -1   ## [spec] bblock 27, line 429-7,  t134,  t32,  -1(SI32)
	c0    add $r0.7 = $r0.6, 1   ## [spec] bblock 31, line 429-7,  t137,  t136,  1(SI32)
;;								## 2
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 27, line 429-7,  t205(I1),  t134,  0(SI32)
	c0    goto L264?3 ## goto
;;								## 3
.trace 8
L261?3:
	c0    mov $r0.6 = -1   ## bblock 40, line 429-5,  t152(I8),  -1(SI32)
	c0    ldw.d $r0.8 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 33, line 429-6, t141, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 37, line 429-6, t145, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.8, -1   ## [spec] bblock 33, line 429-6,  t142,  t141,  -1(SI32)
	c0    add $r0.7 = $r0.4, 1   ## [spec] bblock 37, line 429-6,  t146,  t145,  1(SI32)
;;								## 2
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 33, line 429-6,  t208(I1),  t142,  0(SI32)
	c0    goto L262?3 ## goto
;;								## 3
.trace 7
L259?3:
	c0    mov $r0.4 = -1   ## bblock 46, line 429-4,  t161(I8),  -1(SI32)
	c0    ldw.d $r0.8 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 39, line 429-5, t150, 0(I32)
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 43, line 429-5, t154, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.8, -1   ## [spec] bblock 39, line 429-5,  t151,  t150,  -1(SI32)
	c0    add $r0.7 = $r0.6, 1   ## [spec] bblock 43, line 429-5,  t155,  t154,  1(SI32)
;;								## 2
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 39, line 429-5,  t211(I1),  t151,  0(SI32)
	c0    goto L260?3 ## goto
;;								## 3
.trace 6
L257?3:
	c0    mov $r0.6 = -1   ## bblock 52, line 429-3,  t170(I8),  -1(SI32)
	c0    ldw.d $r0.8 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 45, line 429-4, t159, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 49, line 429-4, t163, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.8, -1   ## [spec] bblock 45, line 429-4,  t160,  t159,  -1(SI32)
	c0    add $r0.7 = $r0.4, 1   ## [spec] bblock 49, line 429-4,  t164,  t163,  1(SI32)
;;								## 2
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 45, line 429-4,  t214(I1),  t160,  0(SI32)
	c0    goto L258?3 ## goto
;;								## 3
.trace 5
L255?3:
	c0    mov $r0.4 = -1   ## bblock 58, line 429-2,  t179(I8),  -1(SI32)
	c0    ldw.d $r0.8 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 51, line 429-3, t168, 0(I32)
	c0    ldw.d $r0.6 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 55, line 429-3, t172, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.8, -1   ## [spec] bblock 51, line 429-3,  t169,  t168,  -1(SI32)
	c0    add $r0.7 = $r0.6, 1   ## [spec] bblock 55, line 429-3,  t173,  t172,  1(SI32)
;;								## 2
	c0    cmpge $b0.1 = $r0.2, $r0.0   ## [spec] bblock 51, line 429-3,  t217(I1),  t169,  0(SI32)
	c0    goto L256?3 ## goto
;;								## 3
.trace 4
L253?3:
	c0    mov $r0.8 = -1   ## bblock 64, line 429-1,  t187(I8),  -1(SI32)
	c0    ldw.d $r0.15 = ((buflen + 0) + 0)[$r0.0]   ## [spec] bblock 57, line 429-2, t177, 0(I32)
	c0    ldw.d $r0.4 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 61, line 429-2, t181, 0(I32)
	      xnop 1
;;								## 1
	c0    add $r0.2 = $r0.15, -1   ## [spec] bblock 57, line 429-2,  t178,  t177,  -1(SI32)
	c0    add $r0.6 = $r0.4, 1   ## [spec] bblock 61, line 429-2,  t182,  t181,  1(SI32)
;;								## 2
	c0    cmpge $b0.6 = $r0.2, $r0.0   ## [spec] bblock 57, line 429-2,  t220(I1),  t178,  0(SI32)
	c0    goto L254?3 ## goto
;;								## 3
.trace 3
L250?3:
	c0    mov $r0.4 = -1   ## bblock 12, line 429,  t122(I8),  -1(SI32)
	c0    ldw.d $r0.8 = ((bufp + 0) + 0)[$r0.0]   ## [spec] bblock 67, line 429-1, t189, 0(I32)
	c0    cmplt $b0.4 = $r0.11, $r0.0   ## [spec] bblock 48, line 427-5,  t216(I1),  t149,  0(SI32)
	c0    add $r0.12 = $r0.11, 1   ## [spec] bblock 42, line 0-5,  t140,  t149,  1(I32)
;;								## 0
	c0    add $r0.2 = $r0.2, -1   ## [spec] bblock 63, line 429-1,  t186,  t185,  -1(SI32)
	c0    cmplt $b0.5 = $r0.12, $r0.0   ## [spec] bblock 42, line 427-6,  t213(I1),  t140,  0(SI32)
	c0    add $r0.13 = $r0.12, 1   ## [spec] bblock 36, line 0-6,  t111,  t140,  1(I32)
;;								## 1
	c0    cmpge $b0.6 = $r0.2, $r0.0   ## [spec] bblock 63, line 429-1,  t223(I1),  t186,  0(SI32)
	c0    add $r0.15 = $r0.8, 1   ## [spec] bblock 67, line 429-1,  t190,  t189,  1(SI32)
	c0    cmplt $b0.7 = $r0.13, $r0.0   ## [spec] bblock 36, line 427-7,  t210(I1),  t111,  0(SI32)
	c0    add $r0.14 = $r0.13, 1   ## [spec] bblock 30, line 0-7,  t130,  t111,  1(I32)
;;								## 2
	c0    add $r0.3 = $r0.14, 1   ## [spec] bblock 24, line 0-8,  t126,  t130,  1(I32)
	c0    goto L251?3 ## goto
;;								## 3
.trace 16
L247?3:
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.0   ## bblock 16, line 424, 0(I32), 0(SI32)
	c0    mov $r0.4 = 511   ## 511(SI32)
	c0    mov $r0.2 = 9   ## 9(SI32)
;;								## 0
	c0    stw ((n_bits + 0) + 0)[$r0.0] = $r0.2   ## bblock 16, line 423, 0(I32), 9(SI32)
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.4   ## bblock 16, line 423, 0(I32), 511(SI32)
;;								## 1
	c0    ldw $r0.18 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 6, line 0, t90, 0(I32)
	      xnop 1
;;								## 3
	c0    sub $r0.6 = $r0.0, $r0.18   ## bblock 6, line 0,  t112,  0(I32),  t90
;;								## 4
	c0    mov $r0.3 = $r0.6   ## bblock 6, line 0,  t126,  t112
	c0    goto L248?3 ## goto
;;								## 5
.trace 20
L246?3:
	c0    ldw $r0.2 = ((n_bits + 0) + 0)[$r0.0]   ## bblock 18, line 419, t21, 0(I32)
	c0    mov $r0.3 = 1   ## 1(SI32)
	      xnop 1
;;								## 1
	c0    shl $r0.3 = $r0.3, $r0.2   ## bblock 18, line 419,  t22,  1(SI32),  t21
;;								## 2
	c0    add $r0.3 = $r0.3, -1   ## bblock 18, line 419,  t23,  t22,  -1(SI32)
;;								## 3
	c0    stw ((maxcode + 0) + 0)[$r0.0] = $r0.3   ## bblock 18, line 419, 0(I32), t23
	c0    goto L245?3 ## goto
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
	c0    call $l0.0 = puts   ## bblock 0, line 460,  raddr(puts)(P32),  addr(_?1STRINGVAR.8)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t2
;;								## 1
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t2
	      xnop 1
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 461,  t3,  ?2.9?2auto_size(I32),  t2
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
	c0    ldw $r0.2 = ((bgnd_flag + 0) + 0)[$r0.0]   ## bblock 0, line 464, t0, 0(I32)
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	      xnop 1
;;								## 1
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 0, line 466,  t13(I1),  t0,  0x0(P32)
;;								## 2
	c0    brf $b0.0, L271?3   ## bblock 0, line 466,  t13(I1)
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 468,  t2,  ?2.10?2auto_size(I32),  t1
;;								## 4
.trace 2
L271?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 471,  t2,  ?2.10?2auto_size(I32),  t1
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
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 476,  t1,  ?2.11?2auto_size(I32),  t0
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
	c0    ldw $r0.2 = ((do_decomp + 0) + 0)[$r0.0]   ## bblock 0, line 481, t0, 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.9 + 0)   ## addr(_?1STRINGVAR.9)(P32)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t3
;;								## 1
	c0    cmpeq $b0.0 = $r0.2, 1   ## bblock 0, line 481,  t14(I1),  t0,  1(SI32)
;;								## 2
	c0    brf $b0.0, L272?3   ## bblock 0, line 481,  t14(I1)
;;								## 3
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 2, line 482,  raddr(puts)(P32),  addr(_?1STRINGVAR.9)(P32)
;;								## 4
L272?3:
	c0    mov $r0.3 = 1   ## 1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t3
	      xnop 1
;;								## 6
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 483,  t4,  ?2.12?2auto_size(I32),  t3
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
	c0    ldw $r0.2 = ((in_count + 0) + 0)[$r0.0]   ## bblock 0, line 489, t3, 0(I32)
	c0    ldw.d $r0.3 = ((bytes_out + 0) + 0)[$r0.0]   ## [spec] bblock 7, line 492, t4, 0(I32)
	c0    mov $r0.4 = 2147483647   ## [spec] bblock 9, line 495,  t25,  2147483647(SI32)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t14
;;								## 1
	c0    add $r0.5 = $r0.2, 10000   ## bblock 0, line 489,  t2,  t3,  10000(SI32)
	c0    cmpgt $b0.0 = $r0.2, 8388607   ## bblock 0, line 490,  t26(I1),  t3,  8388607(SI32)
	c0    shr $r0.3 = $r0.3, 8   ## [spec] bblock 7, line 492,  t0(SI24),  t4,  8(SI32)
;;								## 2
	c0    stw ((checkpoint + 0) + 0)[$r0.0] = $r0.5   ## bblock 0, line 489, 0(I32), t2
	c0    cmpeq $b0.1 = $r0.3, $r0.0   ## [spec] bblock 7, line 493,  t28(I1),  t0(SI24),  0(SI32)
	c0    brf $b0.0, L273?3   ## bblock 0, line 490,  t26(I1)
;;								## 3
	c0    brf $b0.1, L274?3   ## bblock 7, line 493,  t28(I1)
;;								## 4
.trace 2
L275?3:
	c0    ldw $r0.2 = ((ratio + 0) + 0)[$r0.0]   ## bblock 2, line 508, t12, 0(I32)
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t14
	      xnop 1
;;								## 1
	c0    cmpgt $b0.0 = $r0.4, $r0.2   ## bblock 2, line 508,  t27(I1),  t25,  t12
;;								## 2
	c0    brf $b0.0, L276?3   ## bblock 2, line 508,  t27(I1)
;;								## 3
.return ret($r0.3:s32)
	c0    stw ((ratio + 0) + 0)[$r0.0] = $r0.4   ## bblock 6, line 510, 0(I32), t25
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 5, line 521,  t15,  ?2.13?2auto_size(I32),  t14
;;								## 4
.trace 3
L276?3:
	c0    stw ((ratio + 0) + 0)[$r0.0] = $r0.0   ## bblock 3, line 514, 0(I32), 0(SI32)
	c0    ldw $r0.3 = ((hsize + 0) + 0)[$r0.0]   ## bblock 3, line 515, t13, 0(I32)
;;								## 0
.call cl_hash, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = cl_hash   ## bblock 3, line 515,  raddr(cl_hash)(P32),  t13
;;								## 1
	c0    mov $r0.4 = 1   ## 1(SI32)
	c0    mov $r0.2 = 257   ## 257(SI32)
	c0    mov $r0.3 = 256   ## 256(SI32)
;;								## 2
.call output, caller, arg($r0.3:s32), ret()
	c0    stw ((free_ent + 0) + 0)[$r0.0] = $r0.2   ## bblock 4, line 516, 0(I32), 257(SI32)
	c0    stw ((clear_flg + 0) + 0)[$r0.0] = $r0.4   ## bblock 4, line 517, 0(I32), 1(SI32)
	c0    call $l0.0 = output   ## bblock 4, line 518,  raddr(output)(P32),  256(SI32)
;;								## 3
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t14
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	      xnop 1
;;								## 5
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 5, line 521,  t15,  ?2.13?2auto_size(I32),  t14
;;								## 6
.trace 5
L274?3:
	c0    ldw $r0.2 = ((in_count + 0) + 0)[$r0.0]   ## bblock 8, line 499, t6, 0(I32)
	c0    mov $r0.4 = $r0.3   ## t0(SI24)
	      xnop 1
;;								## 1
.call _i_div, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = _i_div   ## bblock 8, line 499,  raddr(_i_div)(P32),  t6,  t0(SI24)
	c0    mov $r0.3 = $r0.2   ## t6
;;								## 2
	c0    mov $r0.4 = $r0.3   ## t25
	c0    goto L275?3 ## goto
;;								## 3
.trace 4
L273?3:
	c0    ldw $r0.2 = ((in_count + 0) + 0)[$r0.0]   ## bblock 1, line 505, t8, 0(I32)
	c0    ldw $r0.4 = ((bytes_out + 0) + 0)[$r0.0]   ## bblock 1, line 505, t10, 0(I32)
	      xnop 1
;;								## 1
.call _i_div, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    shl $r0.3 = $r0.2, 8   ## bblock 1, line 505,  t9,  t8,  8(SI32)
	c0    call $l0.0 = _i_div   ## bblock 1, line 505,  raddr(_i_div)(P32),  t9,  t10
;;								## 2
	c0    mov $r0.4 = $r0.3   ## t25
	c0    goto L275?3 ## goto
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
	c0    sh2add $r0.7 = $r0.3, (htab + 0)   ## bblock 0, line 527,  t1,  t0,  addr(htab?1.0)(P32)
	c0    add $r0.8 = $r0.3, -16   ## bblock 0, line 530,  t2,  t0,  -16(SI32)
	c0    add $r0.4 = $r0.3, (~0x1f)   ## bblock 0, line 0,  t247,  t0,  (~0x1f)(I32)
;;								## 0
	c0    add $r0.2 = $r0.7, (~0x3f)   ## bblock 0, line 0,  t235,  t1,  (~0x3f)(I32)
;;								## 1
.trace 1
L277?3:
	c0    mov $r0.3 = $r0.2   ## bblock 1, line 0,  t46,  t235
	c0    mov $r0.5 = $r0.4   ## bblock 1, line 0,  t47,  t247
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 1, line 552,  t366(I1),  t247,  0(SI32)
	c0    cmplt $b0.1 = $r0.4, 16   ## [spec] bblock 28, line 552-1,  t380(I1),  t247,  16(SI32)
	c0    cmplt $b0.2 = $r0.4, 32   ## [spec] bblock 26, line 552-2,  t379(I1),  t247,  32(SI32)
	c0    cmplt $b0.3 = $r0.4, 48   ## [spec] bblock 24, line 552-3,  t378(I1),  t247,  48(SI32)
	c0    cmplt $b0.4 = $r0.4, 64   ## [spec] bblock 22, line 552-4,  t377(I1),  t247,  64(SI32)
	c0    cmplt $b0.5 = $r0.4, 80   ## [spec] bblock 20, line 552-5,  t376(I1),  t247,  80(SI32)
	c0    cmplt $b0.6 = $r0.4, 96   ## [spec] bblock 18, line 552-6,  t375(I1),  t247,  96(SI32)
	c0    cmplt $b0.7 = $r0.4, 112   ## [spec] bblock 16, line 552-7,  t374(I1),  t247,  112(SI32)
	c0    mov $r0.6 = -1   ## -1(SI32)
;;								## 0
	c0    stw 0[$r0.2] = $r0.6   ## bblock 1, line 533, t235, -1(SI32)
	c0    stw 4[$r0.2] = $r0.6   ## bblock 1, line 534, t235, -1(SI32)
	c0    stw 8[$r0.2] = $r0.6   ## bblock 1, line 535, t235, -1(SI32)
	c0    stw 12[$r0.2] = $r0.6   ## bblock 1, line 536, t235, -1(SI32)
	c0    stw 16[$r0.2] = $r0.6   ## bblock 1, line 537, t235, -1(SI32)
	c0    stw 20[$r0.2] = $r0.6   ## bblock 1, line 538, t235, -1(SI32)
	c0    stw 24[$r0.2] = $r0.6   ## bblock 1, line 539, t235, -1(SI32)
	c0    stw 28[$r0.2] = $r0.6   ## bblock 1, line 540, t235, -1(SI32)
	c0    stw 32[$r0.2] = $r0.6   ## bblock 1, line 541, t235, -1(SI32)
	c0    stw 36[$r0.2] = $r0.6   ## bblock 1, line 542, t235, -1(SI32)
	c0    stw 40[$r0.2] = $r0.6   ## bblock 1, line 543, t235, -1(SI32)
	c0    stw 44[$r0.2] = $r0.6   ## bblock 1, line 544, t235, -1(SI32)
	c0    stw 48[$r0.2] = $r0.6   ## bblock 1, line 545, t235, -1(SI32)
	c0    stw 52[$r0.2] = $r0.6   ## bblock 1, line 546, t235, -1(SI32)
	c0    stw 56[$r0.2] = $r0.6   ## bblock 1, line 547, t235, -1(SI32)
	c0    stw 60[$r0.2] = $r0.6   ## bblock 1, line 548, t235, -1(SI32)
	c0    br $b0.0, L278?3   ## bblock 1, line 552,  t366(I1)
;;								## 1
	c0    stw (~0x3f)[$r0.2] = $r0.6   ## bblock 28, line 533-1, t235, -1(SI32)
	c0    stw (~0x3b)[$r0.2] = $r0.6   ## bblock 28, line 534-1, t235, -1(SI32)
	c0    stw (~0x37)[$r0.2] = $r0.6   ## bblock 28, line 535-1, t235, -1(SI32)
	c0    stw (~0x33)[$r0.2] = $r0.6   ## bblock 28, line 536-1, t235, -1(SI32)
	c0    stw (~0x2f)[$r0.2] = $r0.6   ## bblock 28, line 537-1, t235, -1(SI32)
	c0    stw (~0x2b)[$r0.2] = $r0.6   ## bblock 28, line 538-1, t235, -1(SI32)
	c0    stw (~0x27)[$r0.2] = $r0.6   ## bblock 28, line 539-1, t235, -1(SI32)
	c0    stw (~0x23)[$r0.2] = $r0.6   ## bblock 28, line 540-1, t235, -1(SI32)
	c0    stw (~0x1f)[$r0.2] = $r0.6   ## bblock 28, line 541-1, t235, -1(SI32)
	c0    stw (~0x1b)[$r0.2] = $r0.6   ## bblock 28, line 542-1, t235, -1(SI32)
	c0    stw (~0x17)[$r0.2] = $r0.6   ## bblock 28, line 543-1, t235, -1(SI32)
	c0    stw (~0x13)[$r0.2] = $r0.6   ## bblock 28, line 544-1, t235, -1(SI32)
	c0    stw (~0xf)[$r0.2] = $r0.6   ## bblock 28, line 545-1, t235, -1(SI32)
	c0    stw (~0xb)[$r0.2] = $r0.6   ## bblock 28, line 546-1, t235, -1(SI32)
	c0    stw (~0x7)[$r0.2] = $r0.6   ## bblock 28, line 547-1, t235, -1(SI32)
	c0    stw (~0x3)[$r0.2] = $r0.6   ## bblock 28, line 548-1, t235, -1(SI32)
	c0    cmplt $b0.0 = $r0.4, 128   ## [spec] bblock 14, line 552-8,  t373(I1),  t247,  128(SI32)
	c0    br $b0.1, L279?3   ## bblock 28, line 552-1,  t380(I1)
;;								## 2
	c0    stw (~0x7f)[$r0.2] = $r0.6   ## bblock 26, line 533-2, t235, -1(SI32)
	c0    stw (~0x7b)[$r0.2] = $r0.6   ## bblock 26, line 534-2, t235, -1(SI32)
	c0    stw (~0x77)[$r0.2] = $r0.6   ## bblock 26, line 535-2, t235, -1(SI32)
	c0    stw (~0x73)[$r0.2] = $r0.6   ## bblock 26, line 536-2, t235, -1(SI32)
	c0    stw (~0x6f)[$r0.2] = $r0.6   ## bblock 26, line 537-2, t235, -1(SI32)
	c0    stw (~0x6b)[$r0.2] = $r0.6   ## bblock 26, line 538-2, t235, -1(SI32)
	c0    stw (~0x67)[$r0.2] = $r0.6   ## bblock 26, line 539-2, t235, -1(SI32)
	c0    stw (~0x63)[$r0.2] = $r0.6   ## bblock 26, line 540-2, t235, -1(SI32)
	c0    stw (~0x5f)[$r0.2] = $r0.6   ## bblock 26, line 541-2, t235, -1(SI32)
	c0    stw (~0x5b)[$r0.2] = $r0.6   ## bblock 26, line 542-2, t235, -1(SI32)
	c0    stw (~0x57)[$r0.2] = $r0.6   ## bblock 26, line 543-2, t235, -1(SI32)
	c0    stw (~0x53)[$r0.2] = $r0.6   ## bblock 26, line 544-2, t235, -1(SI32)
	c0    stw (~0x4f)[$r0.2] = $r0.6   ## bblock 26, line 545-2, t235, -1(SI32)
	c0    stw (~0x4b)[$r0.2] = $r0.6   ## bblock 26, line 546-2, t235, -1(SI32)
	c0    stw (~0x47)[$r0.2] = $r0.6   ## bblock 26, line 547-2, t235, -1(SI32)
	c0    stw (~0x43)[$r0.2] = $r0.6   ## bblock 26, line 548-2, t235, -1(SI32)
	c0    cmplt $b0.1 = $r0.4, 144   ## [spec] bblock 12, line 552-9,  t372(I1),  t247,  144(SI32)
	c0    br $b0.2, L280?3   ## bblock 26, line 552-2,  t379(I1)
;;								## 3
	c0    stw (~0xbf)[$r0.2] = $r0.6   ## bblock 24, line 533-3, t235, -1(SI32)
	c0    stw (~0xbb)[$r0.2] = $r0.6   ## bblock 24, line 534-3, t235, -1(SI32)
	c0    stw (~0xb7)[$r0.2] = $r0.6   ## bblock 24, line 535-3, t235, -1(SI32)
	c0    stw (~0xb3)[$r0.2] = $r0.6   ## bblock 24, line 536-3, t235, -1(SI32)
	c0    stw (~0xaf)[$r0.2] = $r0.6   ## bblock 24, line 537-3, t235, -1(SI32)
	c0    stw (~0xab)[$r0.2] = $r0.6   ## bblock 24, line 538-3, t235, -1(SI32)
	c0    stw (~0xa7)[$r0.2] = $r0.6   ## bblock 24, line 539-3, t235, -1(SI32)
	c0    stw (~0xa3)[$r0.2] = $r0.6   ## bblock 24, line 540-3, t235, -1(SI32)
	c0    stw (~0x9f)[$r0.2] = $r0.6   ## bblock 24, line 541-3, t235, -1(SI32)
	c0    stw (~0x9b)[$r0.2] = $r0.6   ## bblock 24, line 542-3, t235, -1(SI32)
	c0    stw (~0x97)[$r0.2] = $r0.6   ## bblock 24, line 543-3, t235, -1(SI32)
	c0    stw (~0x93)[$r0.2] = $r0.6   ## bblock 24, line 544-3, t235, -1(SI32)
	c0    stw (~0x8f)[$r0.2] = $r0.6   ## bblock 24, line 545-3, t235, -1(SI32)
	c0    stw (~0x8b)[$r0.2] = $r0.6   ## bblock 24, line 546-3, t235, -1(SI32)
	c0    stw (~0x87)[$r0.2] = $r0.6   ## bblock 24, line 547-3, t235, -1(SI32)
	c0    stw (~0x83)[$r0.2] = $r0.6   ## bblock 24, line 548-3, t235, -1(SI32)
	c0    cmplt $b0.2 = $r0.4, 160   ## [spec] bblock 10, line 552-10,  t371(I1),  t247,  160(SI32)
	c0    br $b0.3, L281?3   ## bblock 24, line 552-3,  t378(I1)
;;								## 4
	c0    stw (~0xff)[$r0.2] = $r0.6   ## bblock 22, line 533-4, t235, -1(SI32)
	c0    stw (~0xfb)[$r0.2] = $r0.6   ## bblock 22, line 534-4, t235, -1(SI32)
	c0    stw (~0xf7)[$r0.2] = $r0.6   ## bblock 22, line 535-4, t235, -1(SI32)
	c0    stw (~0xf3)[$r0.2] = $r0.6   ## bblock 22, line 536-4, t235, -1(SI32)
	c0    stw (~0xef)[$r0.2] = $r0.6   ## bblock 22, line 537-4, t235, -1(SI32)
	c0    stw (~0xeb)[$r0.2] = $r0.6   ## bblock 22, line 538-4, t235, -1(SI32)
	c0    stw (~0xe7)[$r0.2] = $r0.6   ## bblock 22, line 539-4, t235, -1(SI32)
	c0    stw (~0xe3)[$r0.2] = $r0.6   ## bblock 22, line 540-4, t235, -1(SI32)
	c0    stw (~0xdf)[$r0.2] = $r0.6   ## bblock 22, line 541-4, t235, -1(SI32)
	c0    stw (~0xdb)[$r0.2] = $r0.6   ## bblock 22, line 542-4, t235, -1(SI32)
	c0    stw (~0xd7)[$r0.2] = $r0.6   ## bblock 22, line 543-4, t235, -1(SI32)
	c0    stw (~0xd3)[$r0.2] = $r0.6   ## bblock 22, line 544-4, t235, -1(SI32)
	c0    stw (~0xcf)[$r0.2] = $r0.6   ## bblock 22, line 545-4, t235, -1(SI32)
	c0    stw (~0xcb)[$r0.2] = $r0.6   ## bblock 22, line 546-4, t235, -1(SI32)
	c0    stw (~0xc7)[$r0.2] = $r0.6   ## bblock 22, line 547-4, t235, -1(SI32)
	c0    stw (~0xc3)[$r0.2] = $r0.6   ## bblock 22, line 548-4, t235, -1(SI32)
	c0    cmplt $b0.3 = $r0.4, 176   ## [spec] bblock 8, line 552-11,  t370(I1),  t247,  176(SI32)
	c0    add $r0.4 = $r0.4, (~0xcf)   ## [spec] bblock 6, line 0,  t247,  t247,  (~0xcf)(I32)
	c0    br $b0.4, L282?3   ## bblock 22, line 552-4,  t377(I1)
;;								## 5
	c0    stw (~0x13f)[$r0.2] = $r0.6   ## bblock 20, line 533-5, t235, -1(SI32)
	c0    stw (~0x13b)[$r0.2] = $r0.6   ## bblock 20, line 534-5, t235, -1(SI32)
	c0    stw (~0x137)[$r0.2] = $r0.6   ## bblock 20, line 535-5, t235, -1(SI32)
	c0    stw (~0x133)[$r0.2] = $r0.6   ## bblock 20, line 536-5, t235, -1(SI32)
	c0    stw (~0x12f)[$r0.2] = $r0.6   ## bblock 20, line 537-5, t235, -1(SI32)
	c0    stw (~0x12b)[$r0.2] = $r0.6   ## bblock 20, line 538-5, t235, -1(SI32)
	c0    stw (~0x127)[$r0.2] = $r0.6   ## bblock 20, line 539-5, t235, -1(SI32)
	c0    stw (~0x123)[$r0.2] = $r0.6   ## bblock 20, line 540-5, t235, -1(SI32)
	c0    stw (~0x11f)[$r0.2] = $r0.6   ## bblock 20, line 541-5, t235, -1(SI32)
	c0    stw (~0x11b)[$r0.2] = $r0.6   ## bblock 20, line 542-5, t235, -1(SI32)
	c0    stw (~0x117)[$r0.2] = $r0.6   ## bblock 20, line 543-5, t235, -1(SI32)
	c0    stw (~0x113)[$r0.2] = $r0.6   ## bblock 20, line 544-5, t235, -1(SI32)
	c0    stw (~0x10f)[$r0.2] = $r0.6   ## bblock 20, line 545-5, t235, -1(SI32)
	c0    stw (~0x10b)[$r0.2] = $r0.6   ## bblock 20, line 546-5, t235, -1(SI32)
	c0    stw (~0x107)[$r0.2] = $r0.6   ## bblock 20, line 547-5, t235, -1(SI32)
	c0    stw (~0x103)[$r0.2] = $r0.6   ## bblock 20, line 548-5, t235, -1(SI32)
	c0    br $b0.5, L283?3   ## bblock 20, line 552-5,  t376(I1)
;;								## 6
	c0    stw (~0x17f)[$r0.2] = $r0.6   ## bblock 18, line 533-6, t235, -1(SI32)
	c0    stw (~0x17b)[$r0.2] = $r0.6   ## bblock 18, line 534-6, t235, -1(SI32)
	c0    stw (~0x177)[$r0.2] = $r0.6   ## bblock 18, line 535-6, t235, -1(SI32)
	c0    stw (~0x173)[$r0.2] = $r0.6   ## bblock 18, line 536-6, t235, -1(SI32)
	c0    stw (~0x16f)[$r0.2] = $r0.6   ## bblock 18, line 537-6, t235, -1(SI32)
	c0    stw (~0x16b)[$r0.2] = $r0.6   ## bblock 18, line 538-6, t235, -1(SI32)
	c0    stw (~0x167)[$r0.2] = $r0.6   ## bblock 18, line 539-6, t235, -1(SI32)
	c0    stw (~0x163)[$r0.2] = $r0.6   ## bblock 18, line 540-6, t235, -1(SI32)
	c0    stw (~0x15f)[$r0.2] = $r0.6   ## bblock 18, line 541-6, t235, -1(SI32)
	c0    stw (~0x15b)[$r0.2] = $r0.6   ## bblock 18, line 542-6, t235, -1(SI32)
	c0    stw (~0x157)[$r0.2] = $r0.6   ## bblock 18, line 543-6, t235, -1(SI32)
	c0    stw (~0x153)[$r0.2] = $r0.6   ## bblock 18, line 544-6, t235, -1(SI32)
	c0    stw (~0x14f)[$r0.2] = $r0.6   ## bblock 18, line 545-6, t235, -1(SI32)
	c0    stw (~0x14b)[$r0.2] = $r0.6   ## bblock 18, line 546-6, t235, -1(SI32)
	c0    stw (~0x147)[$r0.2] = $r0.6   ## bblock 18, line 547-6, t235, -1(SI32)
	c0    stw (~0x143)[$r0.2] = $r0.6   ## bblock 18, line 548-6, t235, -1(SI32)
	c0    br $b0.6, L284?3   ## bblock 18, line 552-6,  t375(I1)
;;								## 7
	c0    stw (~0x1bf)[$r0.2] = $r0.6   ## bblock 16, line 533-7, t235, -1(SI32)
	c0    stw (~0x1bb)[$r0.2] = $r0.6   ## bblock 16, line 534-7, t235, -1(SI32)
	c0    stw (~0x1b7)[$r0.2] = $r0.6   ## bblock 16, line 535-7, t235, -1(SI32)
	c0    stw (~0x1b3)[$r0.2] = $r0.6   ## bblock 16, line 536-7, t235, -1(SI32)
	c0    stw (~0x1af)[$r0.2] = $r0.6   ## bblock 16, line 537-7, t235, -1(SI32)
	c0    stw (~0x1ab)[$r0.2] = $r0.6   ## bblock 16, line 538-7, t235, -1(SI32)
	c0    stw (~0x1a7)[$r0.2] = $r0.6   ## bblock 16, line 539-7, t235, -1(SI32)
	c0    stw (~0x1a3)[$r0.2] = $r0.6   ## bblock 16, line 540-7, t235, -1(SI32)
	c0    stw (~0x19f)[$r0.2] = $r0.6   ## bblock 16, line 541-7, t235, -1(SI32)
	c0    stw (~0x19b)[$r0.2] = $r0.6   ## bblock 16, line 542-7, t235, -1(SI32)
	c0    stw (~0x197)[$r0.2] = $r0.6   ## bblock 16, line 543-7, t235, -1(SI32)
	c0    stw (~0x193)[$r0.2] = $r0.6   ## bblock 16, line 544-7, t235, -1(SI32)
	c0    stw (~0x18f)[$r0.2] = $r0.6   ## bblock 16, line 545-7, t235, -1(SI32)
	c0    stw (~0x18b)[$r0.2] = $r0.6   ## bblock 16, line 546-7, t235, -1(SI32)
	c0    stw (~0x187)[$r0.2] = $r0.6   ## bblock 16, line 547-7, t235, -1(SI32)
	c0    stw (~0x183)[$r0.2] = $r0.6   ## bblock 16, line 548-7, t235, -1(SI32)
	c0    br $b0.7, L285?3   ## bblock 16, line 552-7,  t374(I1)
;;								## 8
	c0    stw (~0x1ff)[$r0.2] = $r0.6   ## bblock 14, line 533-8, t235, -1(SI32)
	c0    stw (~0x1fb)[$r0.2] = $r0.6   ## bblock 14, line 534-8, t235, -1(SI32)
	c0    stw (~0x1f7)[$r0.2] = $r0.6   ## bblock 14, line 535-8, t235, -1(SI32)
	c0    stw (~0x1f3)[$r0.2] = $r0.6   ## bblock 14, line 536-8, t235, -1(SI32)
	c0    stw (~0x1ef)[$r0.2] = $r0.6   ## bblock 14, line 537-8, t235, -1(SI32)
	c0    stw (~0x1eb)[$r0.2] = $r0.6   ## bblock 14, line 538-8, t235, -1(SI32)
	c0    stw (~0x1e7)[$r0.2] = $r0.6   ## bblock 14, line 539-8, t235, -1(SI32)
	c0    stw (~0x1e3)[$r0.2] = $r0.6   ## bblock 14, line 540-8, t235, -1(SI32)
	c0    stw (~0x1df)[$r0.2] = $r0.6   ## bblock 14, line 541-8, t235, -1(SI32)
	c0    stw (~0x1db)[$r0.2] = $r0.6   ## bblock 14, line 542-8, t235, -1(SI32)
	c0    stw (~0x1d7)[$r0.2] = $r0.6   ## bblock 14, line 543-8, t235, -1(SI32)
	c0    stw (~0x1d3)[$r0.2] = $r0.6   ## bblock 14, line 544-8, t235, -1(SI32)
	c0    stw (~0x1cf)[$r0.2] = $r0.6   ## bblock 14, line 545-8, t235, -1(SI32)
	c0    stw (~0x1cb)[$r0.2] = $r0.6   ## bblock 14, line 546-8, t235, -1(SI32)
	c0    stw (~0x1c7)[$r0.2] = $r0.6   ## bblock 14, line 547-8, t235, -1(SI32)
	c0    stw (~0x1c3)[$r0.2] = $r0.6   ## bblock 14, line 548-8, t235, -1(SI32)
	c0    br $b0.0, L286?3   ## bblock 14, line 552-8,  t373(I1)
;;								## 9
	c0    stw (~0x23f)[$r0.2] = $r0.6   ## bblock 12, line 533-9, t235, -1(SI32)
	c0    stw (~0x23b)[$r0.2] = $r0.6   ## bblock 12, line 534-9, t235, -1(SI32)
	c0    stw (~0x237)[$r0.2] = $r0.6   ## bblock 12, line 535-9, t235, -1(SI32)
	c0    stw (~0x233)[$r0.2] = $r0.6   ## bblock 12, line 536-9, t235, -1(SI32)
	c0    stw (~0x22f)[$r0.2] = $r0.6   ## bblock 12, line 537-9, t235, -1(SI32)
	c0    stw (~0x22b)[$r0.2] = $r0.6   ## bblock 12, line 538-9, t235, -1(SI32)
	c0    stw (~0x227)[$r0.2] = $r0.6   ## bblock 12, line 539-9, t235, -1(SI32)
	c0    stw (~0x223)[$r0.2] = $r0.6   ## bblock 12, line 540-9, t235, -1(SI32)
	c0    stw (~0x21f)[$r0.2] = $r0.6   ## bblock 12, line 541-9, t235, -1(SI32)
	c0    stw (~0x21b)[$r0.2] = $r0.6   ## bblock 12, line 542-9, t235, -1(SI32)
	c0    stw (~0x217)[$r0.2] = $r0.6   ## bblock 12, line 543-9, t235, -1(SI32)
	c0    stw (~0x213)[$r0.2] = $r0.6   ## bblock 12, line 544-9, t235, -1(SI32)
	c0    stw (~0x20f)[$r0.2] = $r0.6   ## bblock 12, line 545-9, t235, -1(SI32)
	c0    stw (~0x20b)[$r0.2] = $r0.6   ## bblock 12, line 546-9, t235, -1(SI32)
	c0    stw (~0x207)[$r0.2] = $r0.6   ## bblock 12, line 547-9, t235, -1(SI32)
	c0    stw (~0x203)[$r0.2] = $r0.6   ## bblock 12, line 548-9, t235, -1(SI32)
	c0    br $b0.1, L287?3   ## bblock 12, line 552-9,  t372(I1)
;;								## 10
	c0    stw (~0x27f)[$r0.2] = $r0.6   ## bblock 10, line 533-10, t235, -1(SI32)
	c0    stw (~0x27b)[$r0.2] = $r0.6   ## bblock 10, line 534-10, t235, -1(SI32)
	c0    stw (~0x277)[$r0.2] = $r0.6   ## bblock 10, line 535-10, t235, -1(SI32)
	c0    stw (~0x273)[$r0.2] = $r0.6   ## bblock 10, line 536-10, t235, -1(SI32)
	c0    stw (~0x26f)[$r0.2] = $r0.6   ## bblock 10, line 537-10, t235, -1(SI32)
	c0    stw (~0x26b)[$r0.2] = $r0.6   ## bblock 10, line 538-10, t235, -1(SI32)
	c0    stw (~0x267)[$r0.2] = $r0.6   ## bblock 10, line 539-10, t235, -1(SI32)
	c0    stw (~0x263)[$r0.2] = $r0.6   ## bblock 10, line 540-10, t235, -1(SI32)
	c0    stw (~0x25f)[$r0.2] = $r0.6   ## bblock 10, line 541-10, t235, -1(SI32)
	c0    stw (~0x25b)[$r0.2] = $r0.6   ## bblock 10, line 542-10, t235, -1(SI32)
	c0    stw (~0x257)[$r0.2] = $r0.6   ## bblock 10, line 543-10, t235, -1(SI32)
	c0    stw (~0x253)[$r0.2] = $r0.6   ## bblock 10, line 544-10, t235, -1(SI32)
	c0    stw (~0x24f)[$r0.2] = $r0.6   ## bblock 10, line 545-10, t235, -1(SI32)
	c0    stw (~0x24b)[$r0.2] = $r0.6   ## bblock 10, line 546-10, t235, -1(SI32)
	c0    stw (~0x247)[$r0.2] = $r0.6   ## bblock 10, line 547-10, t235, -1(SI32)
	c0    stw (~0x243)[$r0.2] = $r0.6   ## bblock 10, line 548-10, t235, -1(SI32)
	c0    br $b0.2, L288?3   ## bblock 10, line 552-10,  t371(I1)
;;								## 11
	c0    stw (~0x2bf)[$r0.2] = $r0.6   ## bblock 8, line 533-11, t235, -1(SI32)
	c0    stw (~0x2bb)[$r0.2] = $r0.6   ## bblock 8, line 534-11, t235, -1(SI32)
	c0    stw (~0x2b7)[$r0.2] = $r0.6   ## bblock 8, line 535-11, t235, -1(SI32)
	c0    stw (~0x2b3)[$r0.2] = $r0.6   ## bblock 8, line 536-11, t235, -1(SI32)
	c0    stw (~0x2af)[$r0.2] = $r0.6   ## bblock 8, line 537-11, t235, -1(SI32)
	c0    stw (~0x2ab)[$r0.2] = $r0.6   ## bblock 8, line 538-11, t235, -1(SI32)
	c0    stw (~0x2a7)[$r0.2] = $r0.6   ## bblock 8, line 539-11, t235, -1(SI32)
	c0    stw (~0x2a3)[$r0.2] = $r0.6   ## bblock 8, line 540-11, t235, -1(SI32)
	c0    stw (~0x29f)[$r0.2] = $r0.6   ## bblock 8, line 541-11, t235, -1(SI32)
	c0    stw (~0x29b)[$r0.2] = $r0.6   ## bblock 8, line 542-11, t235, -1(SI32)
	c0    stw (~0x297)[$r0.2] = $r0.6   ## bblock 8, line 543-11, t235, -1(SI32)
	c0    stw (~0x293)[$r0.2] = $r0.6   ## bblock 8, line 544-11, t235, -1(SI32)
	c0    stw (~0x28f)[$r0.2] = $r0.6   ## bblock 8, line 545-11, t235, -1(SI32)
	c0    stw (~0x28b)[$r0.2] = $r0.6   ## bblock 8, line 546-11, t235, -1(SI32)
	c0    stw (~0x287)[$r0.2] = $r0.6   ## bblock 8, line 547-11, t235, -1(SI32)
	c0    stw (~0x283)[$r0.2] = $r0.6   ## bblock 8, line 548-11, t235, -1(SI32)
	c0    br $b0.3, L289?3   ## bblock 8, line 552-11,  t370(I1)
;;								## 12
	c0    stw (~0x2ff)[$r0.2] = $r0.6   ## bblock 6, line 533-12, t235, -1(SI32)
	c0    stw (~0x2fb)[$r0.2] = $r0.6   ## bblock 6, line 534-12, t235, -1(SI32)
	c0    stw (~0x2f7)[$r0.2] = $r0.6   ## bblock 6, line 535-12, t235, -1(SI32)
	c0    stw (~0x2f3)[$r0.2] = $r0.6   ## bblock 6, line 536-12, t235, -1(SI32)
	c0    stw (~0x2ef)[$r0.2] = $r0.6   ## bblock 6, line 537-12, t235, -1(SI32)
	c0    stw (~0x2eb)[$r0.2] = $r0.6   ## bblock 6, line 538-12, t235, -1(SI32)
	c0    stw (~0x2e7)[$r0.2] = $r0.6   ## bblock 6, line 539-12, t235, -1(SI32)
	c0    stw (~0x2e3)[$r0.2] = $r0.6   ## bblock 6, line 540-12, t235, -1(SI32)
	c0    stw (~0x2df)[$r0.2] = $r0.6   ## bblock 6, line 541-12, t235, -1(SI32)
	c0    stw (~0x2db)[$r0.2] = $r0.6   ## bblock 6, line 542-12, t235, -1(SI32)
	c0    stw (~0x2d7)[$r0.2] = $r0.6   ## bblock 6, line 543-12, t235, -1(SI32)
	c0    stw (~0x2d3)[$r0.2] = $r0.6   ## bblock 6, line 544-12, t235, -1(SI32)
	c0    stw (~0x2cf)[$r0.2] = $r0.6   ## bblock 6, line 545-12, t235, -1(SI32)
	c0    stw (~0x2cb)[$r0.2] = $r0.6   ## bblock 6, line 546-12, t235, -1(SI32)
	c0    stw (~0x2c7)[$r0.2] = $r0.6   ## bblock 6, line 547-12, t235, -1(SI32)
	c0    stw (~0x2c3)[$r0.2] = $r0.6   ## bblock 6, line 548-12, t235, -1(SI32)
	c0    add $r0.8 = $r0.8, -208   ## bblock 6, line 552-12,  t2,  t2,  -208(SI32)
	c0    add $r0.2 = $r0.2, (~0x33f)   ## bblock 6, line 0,  t235,  t235,  (~0x33f)(I32)
	c0    add $r0.7 = $r0.7, -832   ## bblock 6, line 533-12,  t1,  t1,  -832(SI32)
;;								## 13
	c0    cmplt $b0.0 = $r0.8, $r0.0   ## bblock 6, line 552-12,  t369(I1),  t2,  0(SI32)
;;								## 14
	c0    br $b0.0, L290?3   ## bblock 6, line 552-12,  t369(I1)
	      ## goto
;;
	c0    goto L277?3 ## goto
;;								## 15
.trace 19
L290?3:
	c0    add $r0.7 = $r0.3, (~0x2ff)   ## bblock 7, line 0,  t45,  t46,  (~0x2ff)(I32)
	c0    add $r0.8 = $r0.5, (~0xbf)   ## bblock 7, line 0,  t44,  t47,  (~0xbf)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 2
L292?3:
	c0    cmpgt $b0.0 = $r0.2, $r0.0   ## bblock 3, line 553,  t367(I1),  t346,  0(SI32)
	c0    cmpgt $b0.1 = $r0.2, 1   ## [spec] bblock 5, line 553-1,  t368(I1),  t346,  1(SI32)
	c0    cmpgt $b0.2 = $r0.2, 2   ## [spec] bblock 74, line 553-2,  t408(I1),  t346,  2(SI32)
	c0    cmpgt $b0.3 = $r0.2, 3   ## [spec] bblock 71, line 553-3,  t406(I1),  t346,  3(SI32)
	c0    cmpgt $b0.4 = $r0.2, 4   ## [spec] bblock 68, line 553-4,  t405(I1),  t346,  4(SI32)
	c0    cmpgt $b0.5 = $r0.2, 5   ## [spec] bblock 65, line 553-5,  t403(I1),  t346,  5(SI32)
	c0    cmpgt $b0.6 = $r0.2, 6   ## [spec] bblock 62, line 553-6,  t402(I1),  t346,  6(SI32)
	c0    cmpgt $b0.7 = $r0.2, 7   ## [spec] bblock 59, line 553-7,  t400(I1),  t346,  7(SI32)
	c0    add $r0.5 = $r0.2, -16   ## [spec] bblock 32, line 553-15,  t43,  t346,  -16(SI32)
	c0    add $r0.4 = $r0.3, (~0x3f)   ## [spec] bblock 32, line 0,  t130,  t345,  (~0x3f)(I32)
	c0    mov $r0.6 = -1   ## -1(SI32)
;;								## 0
	c0    cmpgt $b0.0 = $r0.2, 8   ## [spec] bblock 56, line 553-8,  t398(I1),  t346,  8(SI32)
	c0    brf $b0.0, L293?3   ## bblock 3, line 553,  t367(I1)
;;								## 1
	c0    stw 60[$r0.3] = $r0.6   ## bblock 5, line 554, t345, -1(SI32)
	c0    brf $b0.1, L293?3   ## bblock 5, line 553-1,  t368(I1)
;;								## 2
	c0    stw 56[$r0.3] = $r0.6   ## bblock 74, line 554-1, t345, -1(SI32)
	c0    cmpgt $b0.1 = $r0.2, 9   ## [spec] bblock 53, line 553-9,  t396(I1),  t346,  9(SI32)
	c0    brf $b0.2, L293?3   ## bblock 74, line 553-2,  t408(I1)
;;								## 3
	c0    stw 52[$r0.3] = $r0.6   ## bblock 71, line 554-2, t345, -1(SI32)
	c0    cmpgt $b0.2 = $r0.2, 10   ## [spec] bblock 50, line 553-10,  t394(I1),  t346,  10(SI32)
	c0    brf $b0.3, L293?3   ## bblock 71, line 553-3,  t406(I1)
;;								## 4
	c0    stw 48[$r0.3] = $r0.6   ## bblock 68, line 554-3, t345, -1(SI32)
	c0    cmpgt $b0.3 = $r0.2, 11   ## [spec] bblock 47, line 553-11,  t392(I1),  t346,  11(SI32)
	c0    brf $b0.4, L293?3   ## bblock 68, line 553-4,  t405(I1)
;;								## 5
	c0    stw 44[$r0.3] = $r0.6   ## bblock 65, line 554-4, t345, -1(SI32)
	c0    cmpgt $b0.4 = $r0.2, 12   ## [spec] bblock 44, line 553-12,  t390(I1),  t346,  12(SI32)
	c0    brf $b0.5, L293?3   ## bblock 65, line 553-5,  t403(I1)
;;								## 6
	c0    stw 40[$r0.3] = $r0.6   ## bblock 62, line 554-5, t345, -1(SI32)
	c0    cmpgt $b0.5 = $r0.2, 13   ## [spec] bblock 41, line 553-13,  t388(I1),  t346,  13(SI32)
	c0    brf $b0.6, L293?3   ## bblock 62, line 553-6,  t402(I1)
;;								## 7
	c0    stw 36[$r0.3] = $r0.6   ## bblock 59, line 554-6, t345, -1(SI32)
	c0    cmpgt $b0.6 = $r0.2, 14   ## [spec] bblock 38, line 553-14,  t386(I1),  t346,  14(SI32)
	c0    brf $b0.7, L293?3   ## bblock 59, line 553-7,  t400(I1)
;;								## 8
	c0    stw 32[$r0.3] = $r0.6   ## bblock 56, line 554-7, t345, -1(SI32)
	c0    cmpgt $b0.7 = $r0.2, 15   ## [spec] bblock 35, line 553-15,  t384(I1),  t346,  15(SI32)
	c0    add $r0.2 = $r0.5, -16   ## [spec] bblock 64, line 553-1,  t346,  t43,  -16(SI32)
	c0    brf $b0.0, L293?3   ## bblock 56, line 553-8,  t398(I1)
;;								## 9
	c0    stw 28[$r0.3] = $r0.6   ## bblock 53, line 554-8, t345, -1(SI32)
	c0    cmpgt $b0.0 = $r0.5, $r0.0   ## [spec] bblock 32, line 553-1,  t382(I1),  t43,  0(SI32)
	c0    brf $b0.1, L293?3   ## bblock 53, line 553-9,  t396(I1)
;;								## 10
	c0    stw 24[$r0.3] = $r0.6   ## bblock 50, line 554-9, t345, -1(SI32)
	c0    cmpgt $b0.1 = $r0.5, 1   ## [spec] bblock 67, line 553-1,  t404(I1),  t43,  1(SI32)
	c0    brf $b0.2, L293?3   ## bblock 50, line 553-10,  t394(I1)
;;								## 11
	c0    stw 20[$r0.3] = $r0.6   ## bblock 47, line 554-10, t345, -1(SI32)
	c0    cmpgt $b0.2 = $r0.5, 2   ## [spec] bblock 75, line 553-1,  t409(I1),  t43,  2(SI32)
	c0    brf $b0.3, L293?3   ## bblock 47, line 553-11,  t392(I1)
;;								## 12
	c0    stw 16[$r0.3] = $r0.6   ## bblock 44, line 554-11, t345, -1(SI32)
	c0    cmpgt $b0.3 = $r0.5, 3   ## [spec] bblock 76, line 553-1,  t410(I1),  t43,  3(SI32)
	c0    brf $b0.4, L293?3   ## bblock 44, line 553-12,  t390(I1)
;;								## 13
	c0    stw 12[$r0.3] = $r0.6   ## bblock 41, line 554-12, t345, -1(SI32)
	c0    cmpgt $b0.4 = $r0.5, 4   ## [spec] bblock 73, line 553-1,  t407(I1),  t43,  4(SI32)
	c0    brf $b0.5, L293?3   ## bblock 41, line 553-13,  t388(I1)
;;								## 14
	c0    stw 8[$r0.3] = $r0.6   ## bblock 38, line 554-13, t345, -1(SI32)
	c0    cmpgt $b0.5 = $r0.5, 5   ## [spec] bblock 31, line 553-1,  t381(I1),  t43,  5(SI32)
	c0    brf $b0.6, L293?3   ## bblock 38, line 553-14,  t386(I1)
;;								## 15
	c0    stw 4[$r0.3] = $r0.6   ## bblock 35, line 554-14, t345, -1(SI32)
	c0    cmpgt $b0.6 = $r0.5, 6   ## [spec] bblock 34, line 553-1,  t383(I1),  t43,  6(SI32)
	c0    brf $b0.7, L293?3   ## bblock 35, line 553-15,  t384(I1)
;;								## 16
	c0    stw 0[$r0.3] = $r0.6   ## bblock 32, line 554-15, t345, -1(SI32)
	c0    cmpgt $b0.7 = $r0.5, 7   ## [spec] bblock 37, line 553-1,  t385(I1),  t43,  7(SI32)
	c0    add $r0.3 = $r0.4, (~0x3f)   ## [spec] bblock 64, line 0-1,  t345,  t130,  (~0x3f)(I32)
	c0    brf $b0.0, L293?3   ## bblock 32, line 553-1,  t382(I1)
;;								## 17
	c0    stw 60[$r0.4] = $r0.6   ## bblock 67, line 554-1, t130, -1(SI32)
	c0    cmpgt $b0.0 = $r0.5, 8   ## [spec] bblock 40, line 553-1,  t387(I1),  t43,  8(SI32)
	c0    brf $b0.1, L293?3   ## bblock 67, line 553-1,  t404(I1)
;;								## 18
	c0    stw 56[$r0.4] = $r0.6   ## bblock 75, line 554-1, t130, -1(SI32)
	c0    cmpgt $b0.1 = $r0.5, 9   ## [spec] bblock 43, line 553-1,  t389(I1),  t43,  9(SI32)
	c0    brf $b0.2, L293?3   ## bblock 75, line 553-1,  t409(I1)
;;								## 19
	c0    stw 52[$r0.4] = $r0.6   ## bblock 76, line 554-1, t130, -1(SI32)
	c0    cmpgt $b0.2 = $r0.5, 10   ## [spec] bblock 46, line 553-1,  t391(I1),  t43,  10(SI32)
	c0    brf $b0.3, L293?3   ## bblock 76, line 553-1,  t410(I1)
;;								## 20
	c0    stw 48[$r0.4] = $r0.6   ## bblock 73, line 554-1, t130, -1(SI32)
	c0    cmpgt $b0.3 = $r0.5, 11   ## [spec] bblock 49, line 553-1,  t393(I1),  t43,  11(SI32)
	c0    brf $b0.4, L293?3   ## bblock 73, line 553-1,  t407(I1)
;;								## 21
	c0    stw 44[$r0.4] = $r0.6   ## bblock 31, line 554-1, t130, -1(SI32)
	c0    cmpgt $b0.4 = $r0.5, 12   ## [spec] bblock 52, line 553-1,  t395(I1),  t43,  12(SI32)
	c0    brf $b0.5, L293?3   ## bblock 31, line 553-1,  t381(I1)
;;								## 22
	c0    stw 40[$r0.4] = $r0.6   ## bblock 34, line 554-1, t130, -1(SI32)
	c0    cmpgt $b0.5 = $r0.5, 13   ## [spec] bblock 55, line 553-1,  t397(I1),  t43,  13(SI32)
	c0    brf $b0.6, L293?3   ## bblock 34, line 553-1,  t383(I1)
;;								## 23
	c0    stw 36[$r0.4] = $r0.6   ## bblock 37, line 554-1, t130, -1(SI32)
	c0    cmpgt $b0.6 = $r0.5, 14   ## [spec] bblock 58, line 553-1,  t399(I1),  t43,  14(SI32)
	c0    brf $b0.7, L293?3   ## bblock 37, line 553-1,  t385(I1)
;;								## 24
	c0    stw 32[$r0.4] = $r0.6   ## bblock 40, line 554-1, t130, -1(SI32)
	c0    cmpgt $b0.7 = $r0.5, 15   ## [spec] bblock 61, line 553-1,  t401(I1),  t43,  15(SI32)
	c0    brf $b0.0, L293?3   ## bblock 40, line 553-1,  t387(I1)
;;								## 25
	c0    stw 28[$r0.4] = $r0.6   ## bblock 43, line 554-1, t130, -1(SI32)
	c0    brf $b0.1, L293?3   ## bblock 43, line 553-1,  t389(I1)
;;								## 26
	c0    stw 24[$r0.4] = $r0.6   ## bblock 46, line 554-1, t130, -1(SI32)
	c0    brf $b0.2, L293?3   ## bblock 46, line 553-1,  t391(I1)
;;								## 27
	c0    stw 20[$r0.4] = $r0.6   ## bblock 49, line 554-1, t130, -1(SI32)
	c0    brf $b0.3, L293?3   ## bblock 49, line 553-1,  t393(I1)
;;								## 28
	c0    stw 16[$r0.4] = $r0.6   ## bblock 52, line 554-1, t130, -1(SI32)
	c0    brf $b0.4, L293?3   ## bblock 52, line 553-1,  t395(I1)
;;								## 29
	c0    stw 12[$r0.4] = $r0.6   ## bblock 55, line 554-1, t130, -1(SI32)
	c0    brf $b0.5, L293?3   ## bblock 55, line 553-1,  t397(I1)
;;								## 30
	c0    stw 8[$r0.4] = $r0.6   ## bblock 58, line 554-1, t130, -1(SI32)
	c0    brf $b0.6, L293?3   ## bblock 58, line 553-1,  t399(I1)
;;								## 31
	c0    stw 4[$r0.4] = $r0.6   ## bblock 61, line 554-1, t130, -1(SI32)
	c0    brf $b0.7, L293?3   ## bblock 61, line 553-1,  t401(I1)
;;								## 32
	c0    stw 0[$r0.4] = $r0.6   ## bblock 64, line 554-1, t130, -1(SI32)
	c0    goto L292?3 ## goto
;;								## 33
.trace 7
L293?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 4, line 555,  t30,  ?2.14?2auto_size(I32),  t29
;;								## 0
.trace 18
L289?3:
	c0    add $r0.7 = $r0.7, (~0x2ff)   ## bblock 9, line 0,  t45,  t1,  (~0x2ff)(I32)
	c0    add $r0.8 = $r0.8, (~0xbf)   ## bblock 9, line 0,  t44,  t2,  (~0xbf)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 17
L288?3:
	c0    add $r0.7 = $r0.7, (~0x2bf)   ## bblock 11, line 0,  t45,  t1,  (~0x2bf)(I32)
	c0    add $r0.8 = $r0.8, (~0xaf)   ## bblock 11, line 0,  t44,  t2,  (~0xaf)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 16
L287?3:
	c0    add $r0.7 = $r0.7, (~0x27f)   ## bblock 13, line 0,  t45,  t1,  (~0x27f)(I32)
	c0    add $r0.8 = $r0.8, (~0x9f)   ## bblock 13, line 0,  t44,  t2,  (~0x9f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 15
L286?3:
	c0    add $r0.7 = $r0.7, (~0x23f)   ## bblock 15, line 0,  t45,  t1,  (~0x23f)(I32)
	c0    add $r0.8 = $r0.8, (~0x8f)   ## bblock 15, line 0,  t44,  t2,  (~0x8f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 14
L285?3:
	c0    add $r0.7 = $r0.7, (~0x1ff)   ## bblock 17, line 0,  t45,  t1,  (~0x1ff)(I32)
	c0    add $r0.8 = $r0.8, (~0x7f)   ## bblock 17, line 0,  t44,  t2,  (~0x7f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 13
L284?3:
	c0    add $r0.7 = $r0.7, (~0x1bf)   ## bblock 19, line 0,  t45,  t1,  (~0x1bf)(I32)
	c0    add $r0.8 = $r0.8, (~0x6f)   ## bblock 19, line 0,  t44,  t2,  (~0x6f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 12
L283?3:
	c0    add $r0.7 = $r0.7, (~0x17f)   ## bblock 21, line 0,  t45,  t1,  (~0x17f)(I32)
	c0    add $r0.8 = $r0.8, (~0x5f)   ## bblock 21, line 0,  t44,  t2,  (~0x5f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 11
L282?3:
	c0    add $r0.7 = $r0.7, (~0x13f)   ## bblock 23, line 0,  t45,  t1,  (~0x13f)(I32)
	c0    add $r0.8 = $r0.8, (~0x4f)   ## bblock 23, line 0,  t44,  t2,  (~0x4f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 10
L281?3:
	c0    add $r0.7 = $r0.7, (~0xff)   ## bblock 25, line 0,  t45,  t1,  (~0xff)(I32)
	c0    add $r0.8 = $r0.8, (~0x3f)   ## bblock 25, line 0,  t44,  t2,  (~0x3f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 9
L280?3:
	c0    add $r0.7 = $r0.7, (~0xbf)   ## bblock 27, line 0,  t45,  t1,  (~0xbf)(I32)
	c0    add $r0.8 = $r0.8, (~0x2f)   ## bblock 27, line 0,  t44,  t2,  (~0x2f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 8
L279?3:
	c0    add $r0.7 = $r0.7, (~0x7f)   ## bblock 29, line 0,  t45,  t1,  (~0x7f)(I32)
	c0    add $r0.8 = $r0.8, (~0x1f)   ## bblock 29, line 0,  t44,  t2,  (~0x1f)(I32)
	c0    goto L291?3 ## goto
;;								## 0
.trace 6
L278?3:
	c0    add $r0.7 = $r0.7, (~0x3f)   ## bblock 30, line 0,  t45,  t1,  (~0x3f)(I32)
	c0    add $r0.8 = $r0.8, (~0xf)   ## bblock 30, line 0,  t44,  t2,  (~0xf)(I32)
;;								## 0
L291?3:
	c0    add $r0.2 = $r0.8, 16   ## bblock 2, line 553,  t346,  t44,  16(SI32)
	c0    add $r0.3 = $r0.7, (~0x3f)   ## bblock 2, line 0,  t345,  t45,  (~0x3f)(I32)
	c0    goto L292?3 ## goto
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
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 577,  t18,  ?2.15?2auto_size(I32),  t17
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
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 582,  t1,  ?2.16?2auto_size(I32),  t0
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.16?2auto_size, 0x0
 ## End version
.section .bss
compress_16460.offset::
    .skip 4
compress_16460.buf::
    .skip 12
.section .data
.skip 1
compress_16460.Buf::
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
compress_16460.rcs_ident::
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
