 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -o a.out"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32
 ## Begin max
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
max::
.trace 1
	      ## auto_size == 0
	c0    cmpgt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 15,  t19(I1),  t17,  t18
;;								## 0
	c0    brf $b0.0, L0?3   ## bblock 0, line 15,  t19(I1)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 15,  t5,  ?2.1?2auto_size(I32),  t4
;;								## 2
.trace 2
L0?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 16,  t5,  ?2.1?2auto_size(I32),  t4
	c0    mov $r0.3 = $r0.4   ## t18
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.1?2auto_size, 0x0
 ## End max
 ## Begin min
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
min::
.trace 1
	      ## auto_size == 0
	c0    cmplt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 21,  t19(I1),  t17,  t18
;;								## 0
	c0    brf $b0.0, L1?3   ## bblock 0, line 21,  t19(I1)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 21,  t5,  ?2.2?2auto_size(I32),  t4
;;								## 2
.trace 2
L1?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 22,  t5,  ?2.2?2auto_size(I32),  t4
	c0    mov $r0.3 = $r0.4   ## t18
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.2?2auto_size, 0x0
 ## End min
 ## Begin NOP
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg()
NOP::
.trace 1
	      ## auto_size == 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 24,  t1,  ?2.3?2auto_size(I32),  t0
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.3?2auto_size, 0x0
 ## End NOP
.equ _?1TEMPLATEPACKET.5, 0x0
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
main::
.trace 8
	c0    add $r0.1 = $r0.1, (-0x20)
;;								## 0
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 36,  raddr(NOP)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t62
;;								## 1
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t397,  (~0xfff)(I32)
	c0    mov $r0.3 = (grey_framebuffer + 0)   ## bblock 1, line 0,  t396,  addr(grey_framebuffer?1.0)(P32)
;;								## 2
	c0    ldw $r0.16 = 0x10[$r0.1]  ## restore ## t62
;;								## 3
;;								## 4
.trace 4
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 59,  t448(I1),  t397,  0(SI32)
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 17, line 0,  t397,  t397,  4(I32)
;;								## 0
	c0    brf $b0.0, L3?3   ## bblock 2, line 59,  t448(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 17, line 60, t396, 0(SI32)
	c0    stw 4[$r0.3] = $r0.0   ## bblock 17, line 60-1, t396, 0(SI32)
;;								## 2
	c0    stw 8[$r0.3] = $r0.0   ## bblock 17, line 60-2, t396, 0(SI32)
	c0    stw 12[$r0.3] = $r0.0   ## bblock 17, line 60-3, t396, 0(SI32)
	c0    add $r0.3 = $r0.3, 16   ## bblock 17, line 0,  t396,  t396,  16(I32)
	c0    goto L2?3 ## goto
;;								## 3
.trace 7
L3?3:
	c0    mov $r0.6 = (grey_framebuffer + 0)   ## bblock 3, line 0,  t301,  addr(grey_framebuffer?1.0)(P32)
	c0    mov $r0.7 = (grey_image + 0)   ## bblock 3, line 0,  t305,  addr(grey_image?1.0)(P32)
;;								## 0
	c0    mov $r0.3 = (~0x3f)   ## bblock 3, line 0,  t306,  (~0x3f)(I32)
;;								## 1
.trace 3
L4?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 4, line 68,  t449(I1),  t306,  0(SI32)
	c0    mov $r0.4 = (~0x3f)   ## [spec] bblock 7, line 0,  t179,  (~0x3f)(I32)
	c0    mov $r0.5 = $r0.6   ## [spec] bblock 7, line 0,  t177,  t301
	c0    mov $r0.2 = $r0.7   ## [spec] bblock 7, line 0,  t178,  t305
;;								## 0
	c0    mov $r0.13 = $r0.3   ## t306
	c0    mov $r0.14 = $r0.6   ## t301
	c0    mov $r0.15 = $r0.7   ## t305
	c0    brf $b0.0, L5?3   ## bblock 4, line 68,  t449(I1)
;;								## 1
.trace 1
L6?3:
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 8, line 71,  t450(I1),  t179,  0(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 10, line 74, t108, t178
	c0    ldw.d $r0.6 = 4[$r0.2]   ## [spec] bblock 10, line 74-1, t143, t178
	c0    add $r0.4 = $r0.4, 4   ## [spec] bblock 10, line 0,  t179,  t179,  4(I32)
;;								## 0
	c0    ldw.d $r0.7 = 8[$r0.2]   ## [spec] bblock 10, line 74-2, t78, t178
	c0    ldw.d $r0.8 = 12[$r0.2]   ## [spec] bblock 10, line 74-3, t97, t178
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 10, line 0,  t178,  t178,  16(I32)
	c0    brf $b0.0, L7?3   ## bblock 8, line 71,  t450(I1)
;;								## 1
	c0    and $r0.10 = $r0.3, 255   ## bblock 10, line 75,  t86,  t108,  255(I32)
	c0    shru $r0.9 = $r0.3, 8   ## bblock 10, line 75,  t109(I24),  t108,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 75,  t103(I16),  t108,  16(SI32)
	c0    shru $r0.11 = $r0.6, 8   ## bblock 10, line 75-1,  t145(I24),  t143,  8(SI32)
;;								## 2
	c0    and $r0.9 = $r0.9, 255   ## bblock 10, line 75,  t110,  t109(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 75,  t90,  t103(I16),  255(I32)
	c0    and $r0.12 = $r0.6, 255   ## bblock 10, line 75-1,  t144,  t143,  255(I32)
	c0    and $r0.11 = $r0.11, 255   ## bblock 10, line 75-1,  t146,  t145(I24),  255(I32)
;;								## 3
	c0    max $r0.10 = $r0.10, $r0.9   ## bblock 10, line 75,  t89,  t86,  t110
	c0    max $r0.12 = $r0.12, $r0.11   ## bblock 10, line 75-1,  t148,  t144,  t146
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 75-1,  t149(I16),  t143,  16(SI32)
	c0    shru $r0.9 = $r0.7, 8   ## bblock 10, line 75-2,  t125(I24),  t78,  8(SI32)
;;								## 4
	c0    max $r0.10 = $r0.10, $r0.3   ## bblock 10, line 75,  t123,  t89,  t90
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 75-1,  t150,  t149(I16),  255(I32)
	c0    and $r0.3 = $r0.7, 255   ## bblock 10, line 75-2,  t124,  t78,  255(I32)
	c0    and $r0.9 = $r0.9, 255   ## bblock 10, line 75-2,  t126,  t125(I24),  255(I32)
;;								## 5
	c0    zxtb $r0.10 = $r0.10   ## bblock 10, line 75,  t120(I8),  t123
	c0    max $r0.12 = $r0.12, $r0.6   ## bblock 10, line 75-1,  t152,  t148,  t150
	c0    max $r0.3 = $r0.3, $r0.9   ## bblock 10, line 75-2,  t128,  t124,  t126
	c0    shru $r0.7 = $r0.7, 16   ## bblock 10, line 75-2,  t129(I16),  t78,  16(SI32)
;;								## 6
	c0    shl $r0.9 = $r0.10, 8   ## bblock 10, line 86,  t121,  t120(I8),  8(SI32)
	c0    shl $r0.6 = $r0.10, 16   ## bblock 10, line 86,  t117,  t120(I8),  16(SI32)
	c0    zxtb $r0.12 = $r0.12   ## bblock 10, line 75-1,  t154(I8),  t152
	c0    and $r0.7 = $r0.7, 255   ## bblock 10, line 75-2,  t130,  t129(I16),  255(I32)
;;								## 7
	c0    or $r0.10 = $r0.10, $r0.6   ## bblock 10, line 86,  t451,  t120(I8),  t117
	c0    shl $r0.11 = $r0.12, 8   ## bblock 10, line 86-1,  t155,  t154(I8),  8(SI32)
	c0    shl $r0.6 = $r0.12, 16   ## bblock 10, line 86-1,  t156,  t154(I8),  16(SI32)
	c0    max $r0.3 = $r0.3, $r0.7   ## bblock 10, line 75-2,  t132,  t128,  t130
;;								## 8
	c0    or $r0.10 = $r0.10, $r0.9   ## bblock 10, line 86,  t114,  t451,  t121
	c0    or $r0.12 = $r0.12, $r0.6   ## bblock 10, line 86-1,  t452,  t154(I8),  t156
	c0    zxtb $r0.3 = $r0.3   ## bblock 10, line 75-2,  t134(I8),  t132
	c0    shru $r0.6 = $r0.8, 8   ## bblock 10, line 75-3,  t31(I24),  t97,  8(SI32)
;;								## 9
	c0    or $r0.12 = $r0.12, $r0.11   ## bblock 10, line 86-1,  t157,  t452,  t155
	c0    shl $r0.9 = $r0.3, 8   ## bblock 10, line 86-2,  t135,  t134(I8),  8(SI32)
	c0    shl $r0.7 = $r0.3, 16   ## bblock 10, line 86-2,  t136,  t134(I8),  16(SI32)
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 75-3,  t87,  t31(I24),  255(I32)
;;								## 10
	c0    stw 0[$r0.5] = $r0.10   ## bblock 10, line 87, t177, t114
	c0    or $r0.3 = $r0.3, $r0.7   ## bblock 10, line 86-2,  t453,  t134(I8),  t136
	c0    and $r0.7 = $r0.8, 255   ## bblock 10, line 75-3,  t115,  t97,  255(I32)
	c0    shru $r0.8 = $r0.8, 16   ## bblock 10, line 75-3,  t34(I16),  t97,  16(SI32)
;;								## 11
	c0    stw 4[$r0.5] = $r0.12   ## bblock 10, line 87-1, t177, t157
	c0    or $r0.3 = $r0.3, $r0.9   ## bblock 10, line 86-2,  t137,  t453,  t135
	c0    max $r0.7 = $r0.7, $r0.6   ## bblock 10, line 75-3,  t94,  t115,  t87
	c0    and $r0.8 = $r0.8, 255   ## bblock 10, line 75-3,  t93,  t34(I16),  255(I32)
;;								## 12
	c0    stw 8[$r0.5] = $r0.3   ## bblock 10, line 87-2, t177, t137
	c0    max $r0.7 = $r0.7, $r0.8   ## bblock 10, line 75-3,  t26,  t94,  t93
;;								## 13
	c0    zxtb $r0.7 = $r0.7   ## bblock 10, line 75-3,  t41(I8),  t26
;;								## 14
	c0    shl $r0.6 = $r0.7, 8   ## bblock 10, line 86-3,  t40,  t41(I8),  8(SI32)
	c0    shl $r0.3 = $r0.7, 16   ## bblock 10, line 86-3,  t42,  t41(I8),  16(SI32)
;;								## 15
	c0    or $r0.7 = $r0.7, $r0.3   ## bblock 10, line 86-3,  t454,  t41(I8),  t42
;;								## 16
	c0    or $r0.7 = $r0.7, $r0.6   ## bblock 10, line 86-3,  t44,  t454,  t40
;;								## 17
	c0    stw 12[$r0.5] = $r0.7   ## bblock 10, line 87-3, t177, t44
	c0    add $r0.5 = $r0.5, 16   ## bblock 10, line 0,  t177,  t177,  16(I32)
	c0    goto L6?3 ## goto
;;								## 18
.trace 5
L7?3:
	c0    add $r0.6 = $r0.14, 256   ## bblock 9, line 0,  t301,  t301,  256(I32)
	c0    add $r0.3 = $r0.13, 1   ## bblock 9, line 0,  t306,  t306,  1(I32)
;;								## 0
	c0    add $r0.7 = $r0.15, 256   ## bblock 9, line 0,  t305,  t305,  256(I32)
	c0    goto L4?3 ## goto
;;								## 1
.trace 9
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 103,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    stw 0x10[$r0.1] = $r0.16  ## spill ## t62
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t62
	      xnop 1
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 6, line 105,  t63,  ?2.4?2auto_size(I32),  t62
;;								## 3
.endp
.section .bss
.section .data
_?1STRINGPACKET.1:
    .data1 71
    .data1 114
    .data1 101
    .data1 121
    .data1 115
    .data1 99
    .data1 97
    .data1 108
    .data1 101
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
.equ ?2.4?2scratch.0, 0x0
.equ ?2.4?2ras_p, 0x10
.section .data
.section .text
.equ ?2.4?2auto_size, 0x20
 ## End main
.section .bss
.section .data
.section .data
.comm grey_image, 0x4000, 4
.comm grey_framebuffer, 0x4000, 4
.section .text
.import NOP
.type NOP,@function
.import puts
.type puts,@function
