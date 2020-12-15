 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/12_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out"
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
	c0    cmpgt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 19,  t19(I1),  t17,  t18
;;								## 0
	c0    brf $b0.0, L0?3   ## bblock 0, line 19,  t19(I1)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 19,  t5,  ?2.1?2auto_size(I32),  t4
;;								## 2
.trace 2
L0?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 20,  t5,  ?2.1?2auto_size(I32),  t4
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
	c0    cmplt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 25,  t19(I1),  t17,  t18
;;								## 0
	c0    brf $b0.0, L1?3   ## bblock 0, line 25,  t19(I1)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 25,  t5,  ?2.2?2auto_size(I32),  t4
;;								## 2
.trace 2
L1?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 26,  t5,  ?2.2?2auto_size(I32),  t4
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
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 46,  t1,  ?2.3?2auto_size(I32),  t0
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
.trace 9
	c0    add $r0.1 = $r0.1, (-0x20)
;;								## 0
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 64,  raddr(NOP)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t128
;;								## 1
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t719,  (~0xfff)(I32)
	c0    mov $r0.3 = (conv7_result + 0)   ## bblock 1, line 0,  t721,  addr(conv7_result?1.0)(P32)
	c0    ldw $r0.5 = 0x10[$r0.1]  ## restore ## t128
;;								## 2
;;								## 3
.trace 5
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 88,  t739(I1),  t719,  0(SI32)
	c0    add $r0.4 = $r0.3, 64   ## [spec] bblock 35, line 0,  t496,  t721,  64(I32)
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 35, line 0,  t497,  t719,  16(I32)
;;								## 0
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 35, line 0-1,  t719,  t497,  16(I32)
	c0    brf $b0.0, L3?3   ## bblock 2, line 88,  t739(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 35, line 89, t721, 0(SI32)
	c0    stw 4[$r0.3] = $r0.0   ## bblock 35, line 89-1, t721, 0(SI32)
	c0    stw 8[$r0.3] = $r0.0   ## bblock 35, line 89-2, t721, 0(SI32)
	c0    stw 12[$r0.3] = $r0.0   ## bblock 35, line 89-3, t721, 0(SI32)
	c0    stw 16[$r0.3] = $r0.0   ## bblock 35, line 89-4, t721, 0(SI32)
	c0    stw 20[$r0.3] = $r0.0   ## bblock 35, line 89-5, t721, 0(SI32)
	c0    stw 24[$r0.3] = $r0.0   ## bblock 35, line 89-6, t721, 0(SI32)
	c0    stw 28[$r0.3] = $r0.0   ## bblock 35, line 89-7, t721, 0(SI32)
	c0    stw 32[$r0.3] = $r0.0   ## bblock 35, line 89-8, t721, 0(SI32)
	c0    stw 36[$r0.3] = $r0.0   ## bblock 35, line 89-9, t721, 0(SI32)
	c0    stw 40[$r0.3] = $r0.0   ## bblock 35, line 89-10, t721, 0(SI32)
	c0    stw 44[$r0.3] = $r0.0   ## bblock 35, line 89-11, t721, 0(SI32)
;;								## 2
	c0    stw 48[$r0.3] = $r0.0   ## bblock 35, line 89-12, t721, 0(SI32)
	c0    stw 52[$r0.3] = $r0.0   ## bblock 35, line 89-13, t721, 0(SI32)
	c0    stw 56[$r0.3] = $r0.0   ## bblock 35, line 89-14, t721, 0(SI32)
	c0    stw 60[$r0.3] = $r0.0   ## bblock 35, line 89-15, t721, 0(SI32)
	c0    stw 0[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 4[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 8[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 12[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 16[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 20[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 24[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    add $r0.3 = $r0.4, 64   ## bblock 35, line 0-1,  t721,  t496,  64(I32)
;;								## 3
	c0    stw 28[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 32[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 36[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 40[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 44[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 48[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 52[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 56[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    stw 60[$r0.4] = $r0.0   ## bblock 35, line 89-1, t496, 0(SI32)
	c0    goto L2?3 ## goto
;;								## 4
.trace 10
L3?3:
	c0    mov $r0.8 = $r0.0   ## bblock 3, line 0,  t421,  0(I32)
	c0    mov $r0.3 = $r0.0   ## bblock 3, line 0,  t420,  0(I32)
	c0    mov $r0.49 = ((conv7_result + 0) + 1012)   ## bblock 3, line 0,  t425,  (addr(conv7_result?1.0)(P32) + 0x3f4(I32))(P32)
	c0    mov $r0.50 = $r0.5   ## t128
;;								## 0
.trace 6
L4?3:
	c0    cmplt $b0.0 = $r0.3, 58   ## bblock 4, line 95,  t740(I1),  t420,  58(SI32)
	c0    mov $r0.4 = (~0x39)   ## [spec] bblock 7, line 0,  t395,  (~0x39)(I32)
	c0    mov $r0.7 = $r0.0   ## [spec] bblock 7, line 0,  t394,  0(I32)
;;								## 0
	c0    brf $b0.0, L5?3   ## bblock 4, line 95,  t740(I1)
;;								## 1
.trace 3
L6?3:
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 8, line 96,  t741(I1),  t395,  0(SI32)
	c0    mov $r0.2 = (~0x6)   ## [spec] bblock 10, line 0,  t381,  (~0x6)(I32)
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 10, line 0,  t379,  0(I32)
	c0    mov $r0.5 = $r0.7   ## [spec] bblock 10, line 0,  t380,  t394
	c0    mov $r0.19 = $r0.0   ## [spec] bblock 10, line 98,  t153,  0(SI32)
	c0    mov $r0.17 = $r0.0   ## [spec] bblock 10, line 98,  t152,  0(SI32)
	c0    mov $r0.20 = $r0.0   ## [spec] bblock 10, line 98,  t151,  0(SI32)
	c0    mov $r0.47 = $r0.4   ## t395
	c0    mov $r0.48 = $r0.7   ## t394
;;								## 0
	c0    brf $b0.0, L7?3   ## bblock 8, line 96,  t741(I1)
;;								## 1
.trace 1
L8?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 11, line 102,  t742(I1),  t381,  0(SI32)
	c0    sh2add $r0.10 = $r0.6, (filter7x7 + 0)   ## [spec] bblock 31, line 111,  t745,  t379,  addr(filter7x7?1.0)(P32)
	c0    add $r0.9 = $r0.5, $r0.8   ## [spec] bblock 31, line 111,  t74,  t380,  t421
	c0    add $r0.18 = $r0.3, 1   ## [spec] bblock 31, line 109-1,  t353,  t420,  1(SI32)
	c0    add $r0.11 = $r0.3, 2   ## [spec] bblock 31, line 109-2,  t330,  t420,  2(SI32)
	c0    sh2add $r0.12 = $r0.6, ((filter7x7 + 0) + 8)   ## [spec] bblock 31, line 111-2,  t777,  t379,  (addr(filter7x7?1.0)(P32) + 0x8(I32))(P32)
	c0    add $r0.13 = $r0.3, 3   ## [spec] bblock 31, line 109-3,  t307,  t420,  3(SI32)
	c0    sh2add $r0.14 = $r0.6, ((filter7x7 + 0) + 12)   ## [spec] bblock 31, line 111-3,  t793,  t379,  (addr(filter7x7?1.0)(P32) + 0xc(I32))(P32)
	c0    add $r0.15 = $r0.3, 5   ## [spec] bblock 31, line 109-5,  t261,  t420,  5(SI32)
	c0    sh2add $r0.16 = $r0.6, ((filter7x7 + 0) + 20)   ## [spec] bblock 31, line 111-5,  t825,  t379,  (addr(filter7x7?1.0)(P32) + 0x14(I32))(P32)
	c0    add $r0.4 = $r0.3, 6   ## [spec] bblock 31, line 109-6,  t238,  t420,  6(SI32)
	c0    sh2add $r0.7 = $r0.6, ((filter7x7 + 0) + 24)   ## [spec] bblock 31, line 111-6,  t841,  t379,  (addr(filter7x7?1.0)(P32) + 0x18(I32))(P32)
;;								## 0
	c0    ldw.d $r0.10 = 0[$r0.10]   ## [spec] bblock 31, line 111, t70, t745
	c0    sh2add $r0.9 = $r0.9, (conv7_image + 0)   ## [spec] bblock 31, line 111,  t77,  t74,  addr(conv7_image?1.0)(P32)
	c0    shl $r0.18 = $r0.18, 6   ## [spec] bblock 31, line 111-1,  t356,  t353,  6(I32)
	c0    shl $r0.11 = $r0.11, 6   ## [spec] bblock 31, line 111-2,  t333,  t330,  6(I32)
	c0    ldw.d $r0.12 = 0[$r0.12]   ## [spec] bblock 31, line 111-2, t332, t777
	c0    shl $r0.13 = $r0.13, 6   ## [spec] bblock 31, line 111-3,  t310,  t307,  6(I32)
	c0    ldw.d $r0.14 = 0[$r0.14]   ## [spec] bblock 31, line 111-3, t309, t793
	c0    shl $r0.15 = $r0.15, 6   ## [spec] bblock 31, line 111-5,  t264,  t261,  6(I32)
	c0    ldw.d $r0.16 = 0[$r0.16]   ## [spec] bblock 31, line 111-5, t263, t825
	c0    shl $r0.4 = $r0.4, 6   ## [spec] bblock 31, line 111-6,  t241,  t238,  6(I32)
	c0    ldw.d $r0.7 = 0[$r0.7]   ## [spec] bblock 31, line 111-6, t240, t841
	c0    brf $b0.0, L9?3   ## bblock 11, line 102,  t742(I1)
;;								## 1
	c0    ldw $r0.9 = 0[$r0.9]   ## bblock 31, line 111, t78, t77
	c0    sh2add $r0.21 = $r0.6, ((filter7x7 + 0) + 4)   ## bblock 31, line 111-1,  t761,  t379,  (addr(filter7x7?1.0)(P32) + 0x4(I32))(P32)
	c0    add $r0.18 = $r0.5, $r0.18   ## bblock 31, line 111-1,  t357,  t380,  t356
	c0    add $r0.11 = $r0.5, $r0.11   ## bblock 31, line 111-2,  t334,  t380,  t333
	c0    add $r0.13 = $r0.5, $r0.13   ## bblock 31, line 111-3,  t311,  t380,  t310
	c0    add $r0.22 = $r0.3, 4   ## bblock 31, line 109-4,  t284,  t420,  4(SI32)
	c0    sh2add $r0.23 = $r0.6, ((filter7x7 + 0) + 16)   ## bblock 31, line 111-4,  t809,  t379,  (addr(filter7x7?1.0)(P32) + 0x10(I32))(P32)
	c0    add $r0.15 = $r0.5, $r0.15   ## bblock 31, line 111-5,  t265,  t380,  t264
	c0    add $r0.4 = $r0.5, $r0.4   ## bblock 31, line 111-6,  t242,  t380,  t241
	c0    add $r0.6 = $r0.6, 7   ## bblock 31, line 0,  t379,  t379,  7(I32)
	c0    add $r0.2 = $r0.2, 1   ## bblock 31, line 0,  t381,  t381,  1(I32)
;;								## 2
	c0    ldw $r0.21 = 0[$r0.21]   ## bblock 31, line 111-1, t355, t761
	c0    sh2add $r0.18 = $r0.18, (conv7_image + 0)   ## bblock 31, line 111-1,  t359,  t357,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.11 = $r0.11, (conv7_image + 0)   ## bblock 31, line 111-2,  t336,  t334,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.13 = $r0.13, (conv7_image + 0)   ## bblock 31, line 111-3,  t313,  t311,  addr(conv7_image?1.0)(P32)
	c0    shl $r0.22 = $r0.22, 6   ## bblock 31, line 111-4,  t287,  t284,  6(I32)
	c0    ldw $r0.23 = 0[$r0.23]   ## bblock 31, line 111-4, t286, t809
	c0    sh2add $r0.15 = $r0.15, (conv7_image + 0)   ## bblock 31, line 111-5,  t267,  t265,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.4 = $r0.4, (conv7_image + 0)   ## bblock 31, line 111-6,  t244,  t242,  addr(conv7_image?1.0)(P32)
;;								## 3
	c0    shru $r0.25 = $r0.9, 16   ## bblock 31, line 111,  t43(I16),  t78,  16(SI32)
	c0    and $r0.9 = $r0.9, 255   ## bblock 31, line 113,  t79,  t78,  255(I32)
	c0    shru $r0.24 = $r0.9, 8   ## bblock 31, line 112,  t61(I24),  t78,  8(SI32)
	c0    ldw $r0.18 = 0[$r0.18]   ## bblock 31, line 111-1, t360, t359
	c0    ldw $r0.11 = 0[$r0.11]   ## bblock 31, line 111-2, t337, t336
	c0    ldw $r0.13 = 0[$r0.13]   ## bblock 31, line 111-3, t314, t313
	c0    add $r0.22 = $r0.5, $r0.22   ## bblock 31, line 111-4,  t288,  t380,  t287
	c0    ldw $r0.15 = 0[$r0.15]   ## bblock 31, line 111-5, t268, t267
	c0    ldw $r0.4 = 0[$r0.4]   ## bblock 31, line 111-6, t245, t244
	c0    add $r0.5 = $r0.5, 1   ## bblock 31, line 0,  t380,  t380,  1(I32)
;;								## 4
	c0    and $r0.25 = $r0.25, 255   ## bblock 31, line 111,  t44,  t43(I16),  255(I32)
	c0    mpylu $r0.26 = $r0.10, $r0.9   ## bblock 31, line 113,  t748,  t70,  t79
	c0    mpyhs $r0.9 = $r0.10, $r0.9   ## bblock 31, line 113,  t749,  t70,  t79
	c0    and $r0.24 = $r0.24, 255   ## bblock 31, line 112,  t62,  t61(I24),  255(I32)
	c0    sh2add $r0.22 = $r0.22, (conv7_image + 0)   ## bblock 31, line 111-4,  t290,  t288,  addr(conv7_image?1.0)(P32)
;;								## 5
	c0    mpylu $r0.34 = $r0.10, $r0.25   ## bblock 31, line 111,  t746,  t70,  t44
	c0    mpyhs $r0.10 = $r0.10, $r0.25   ## bblock 31, line 111,  t747,  t70,  t44
	c0    mpylu $r0.28 = $r0.10, $r0.24   ## bblock 31, line 112,  t756,  t70,  t62
	c0    mpyhs $r0.24 = $r0.10, $r0.24   ## bblock 31, line 112,  t757,  t70,  t62
	c0    shru $r0.32 = $r0.18, 8   ## bblock 31, line 112-1,  t368(I24),  t360,  8(SI32)
	c0    shru $r0.25 = $r0.11, 16   ## bblock 31, line 111-2,  t338(I16),  t337,  16(SI32)
	c0    shru $r0.29 = $r0.11, 8   ## bblock 31, line 112-2,  t345(I24),  t337,  8(SI32)
	c0    shru $r0.30 = $r0.13, 8   ## bblock 31, line 112-3,  t322(I24),  t314,  8(SI32)
	c0    ldw $r0.22 = 0[$r0.22]   ## bblock 31, line 111-4, t291, t290
	c0    shru $r0.31 = $r0.15, 8   ## bblock 31, line 112-5,  t276(I24),  t268,  8(SI32)
	c0    shru $r0.33 = $r0.4, 16   ## bblock 31, line 111-6,  t246(I16),  t245,  16(SI32)
	c0    shru $r0.27 = $r0.4, 8   ## bblock 31, line 112-6,  t253(I24),  t245,  8(SI32)
;;								## 6
	c0    add $r0.26 = $r0.26, $r0.9   ## bblock 31, line 113,  t80,  t748,  t749
	c0    shru $r0.37 = $r0.18, 16   ## bblock 31, line 111-1,  t361(I16),  t360,  16(SI32)
	c0    and $r0.32 = $r0.32, 255   ## bblock 31, line 112-1,  t369,  t368(I24),  255(I32)
	c0    and $r0.25 = $r0.25, 255   ## bblock 31, line 111-2,  t339,  t338(I16),  255(I32)
	c0    and $r0.29 = $r0.29, 255   ## bblock 31, line 112-2,  t346,  t345(I24),  255(I32)
	c0    shru $r0.35 = $r0.13, 16   ## bblock 31, line 111-3,  t315(I16),  t314,  16(SI32)
	c0    and $r0.30 = $r0.30, 255   ## bblock 31, line 112-3,  t323,  t322(I24),  255(I32)
	c0    shru $r0.36 = $r0.15, 16   ## bblock 31, line 111-5,  t269(I16),  t268,  16(SI32)
	c0    and $r0.31 = $r0.31, 255   ## bblock 31, line 112-5,  t277,  t276(I24),  255(I32)
	c0    and $r0.33 = $r0.33, 255   ## bblock 31, line 111-6,  t247,  t246(I16),  255(I32)
	c0    and $r0.4 = $r0.4, 255   ## bblock 31, line 113-6,  t249,  t245,  255(I32)
	c0    and $r0.27 = $r0.27, 255   ## bblock 31, line 112-6,  t254,  t253(I24),  255(I32)
;;								## 7
	c0    add $r0.28 = $r0.28, $r0.24   ## bblock 31, line 112,  t63,  t756,  t757
	c0    mpylu $r0.40 = $r0.21, $r0.32   ## bblock 31, line 112-1,  t772,  t355,  t369
	c0    mpyhs $r0.32 = $r0.21, $r0.32   ## bblock 31, line 112-1,  t773,  t355,  t369
	c0    mpylu $r0.24 = $r0.12, $r0.29   ## bblock 31, line 112-2,  t788,  t332,  t346
	c0    mpyhs $r0.29 = $r0.12, $r0.29   ## bblock 31, line 112-2,  t789,  t332,  t346
	c0    mpylu $r0.38 = $r0.14, $r0.30   ## bblock 31, line 112-3,  t804,  t309,  t323
	c0    mpyhs $r0.30 = $r0.14, $r0.30   ## bblock 31, line 112-3,  t805,  t309,  t323
	c0    shru $r0.41 = $r0.22, 8   ## bblock 31, line 112-4,  t299(I24),  t291,  8(SI32)
	c0    mpylu $r0.39 = $r0.16, $r0.31   ## bblock 31, line 112-5,  t836,  t263,  t277
	c0    mpyhs $r0.31 = $r0.16, $r0.31   ## bblock 31, line 112-5,  t837,  t263,  t277
	c0    mpylu $r0.9 = $r0.7, $r0.27   ## bblock 31, line 112-6,  t852,  t240,  t254
	c0    mpyhs $r0.27 = $r0.7, $r0.27   ## bblock 31, line 112-6,  t853,  t240,  t254
;;								## 8
	c0    add $r0.34 = $r0.34, $r0.10   ## bblock 31, line 111,  t45,  t746,  t747
	c0    cmplt $b0.0 = $r0.28, $r0.0   ## bblock 31, line 112,  t758,  t63,  0(I32)
	c0    add $r0.42 = $r0.28, 255   ## bblock 31, line 112,  t759,  t63,  255(I32)
	c0    and $r0.37 = $r0.37, 255   ## bblock 31, line 111-1,  t362,  t361(I16),  255(I32)
	c0    mpylu $r0.10 = $r0.12, $r0.25   ## bblock 31, line 111-2,  t778,  t332,  t339
	c0    mpyhs $r0.25 = $r0.12, $r0.25   ## bblock 31, line 111-2,  t779,  t332,  t339
	c0    and $r0.35 = $r0.35, 255   ## bblock 31, line 111-3,  t316,  t315(I16),  255(I32)
	c0    shru $r0.44 = $r0.22, 16   ## bblock 31, line 111-4,  t292(I16),  t291,  16(SI32)
	c0    and $r0.41 = $r0.41, 255   ## bblock 31, line 112-4,  t300,  t299(I24),  255(I32)
	c0    and $r0.36 = $r0.36, 255   ## bblock 31, line 111-5,  t270,  t269(I16),  255(I32)
	c0    mpylu $r0.43 = $r0.7, $r0.33   ## bblock 31, line 111-6,  t842,  t240,  t247
	c0    mpyhs $r0.33 = $r0.7, $r0.33   ## bblock 31, line 111-6,  t843,  t240,  t247
;;								## 9
	c0    cmplt $b0.0 = $r0.34, $r0.0   ## bblock 31, line 111,  t750,  t45,  0(I32)
	c0    add $r0.28 = $r0.34, 255   ## bblock 31, line 111,  t751,  t45,  255(I32)
	c0    slct $r0.42 = $b0.0, $r0.42, $r0.28   ## bblock 31, line 112,  t760,  t758,  t759,  t63
	c0    add $r0.40 = $r0.40, $r0.32   ## bblock 31, line 112-1,  t370,  t772,  t773
	c0    add $r0.24 = $r0.24, $r0.29   ## bblock 31, line 112-2,  t347,  t788,  t789
	c0    mpylu $r0.29 = $r0.14, $r0.35   ## bblock 31, line 111-3,  t794,  t309,  t316
	c0    mpyhs $r0.35 = $r0.14, $r0.35   ## bblock 31, line 111-3,  t795,  t309,  t316
	c0    add $r0.38 = $r0.38, $r0.30   ## bblock 31, line 112-3,  t324,  t804,  t805
	c0    mpylu $r0.27 = $r0.23, $r0.41   ## bblock 31, line 112-4,  t820,  t286,  t300
	c0    mpyhs $r0.41 = $r0.23, $r0.41   ## bblock 31, line 112-4,  t821,  t286,  t300
	c0    add $r0.39 = $r0.39, $r0.31   ## bblock 31, line 112-5,  t278,  t836,  t837
	c0    add $r0.9 = $r0.9, $r0.27   ## bblock 31, line 112-6,  t255,  t852,  t853
;;								## 10
	c0    shr $r0.42 = $r0.42, 8   ## bblock 31, line 112,  t64,  t760,  8(I32)
	c0    cmplt $b0.5 = $r0.40, $r0.0   ## bblock 31, line 112-1,  t774,  t370,  0(I32)
	c0    add $r0.46 = $r0.40, 255   ## bblock 31, line 112-1,  t775,  t370,  255(I32)
	c0    cmplt $b0.2 = $r0.24, $r0.0   ## bblock 31, line 112-2,  t790,  t347,  0(I32)
	c0    add $r0.31 = $r0.24, 255   ## bblock 31, line 112-2,  t791,  t347,  255(I32)
	c0    cmplt $b0.3 = $r0.38, $r0.0   ## bblock 31, line 112-3,  t806,  t324,  0(I32)
	c0    add $r0.32 = $r0.38, 255   ## bblock 31, line 112-3,  t807,  t324,  255(I32)
	c0    cmplt $b0.4 = $r0.39, $r0.0   ## bblock 31, line 112-5,  t838,  t278,  0(I32)
	c0    add $r0.45 = $r0.39, 255   ## bblock 31, line 112-5,  t839,  t278,  255(I32)
	c0    add $r0.43 = $r0.43, $r0.33   ## bblock 31, line 111-6,  t248,  t842,  t843
	c0    cmplt $b0.1 = $r0.9, $r0.0   ## bblock 31, line 112-6,  t854,  t255,  0(I32)
	c0    add $r0.30 = $r0.9, 255   ## bblock 31, line 112-6,  t855,  t255,  255(I32)
;;								## 11
	c0    slct $r0.28 = $b0.0, $r0.28, $r0.34   ## bblock 31, line 111,  t752,  t750,  t751,  t45
	c0    slct $r0.46 = $b0.5, $r0.46, $r0.40   ## bblock 31, line 112-1,  t776,  t774,  t775,  t370
	c0    add $r0.10 = $r0.10, $r0.25   ## bblock 31, line 111-2,  t340,  t778,  t779
	c0    slct $r0.31 = $b0.2, $r0.31, $r0.24   ## bblock 31, line 112-2,  t792,  t790,  t791,  t347
	c0    add $r0.29 = $r0.29, $r0.35   ## bblock 31, line 111-3,  t317,  t794,  t795
	c0    slct $r0.32 = $b0.3, $r0.32, $r0.38   ## bblock 31, line 112-3,  t808,  t806,  t807,  t324
	c0    add $r0.27 = $r0.27, $r0.41   ## bblock 31, line 112-4,  t301,  t820,  t821
	c0    mpylu $r0.24 = $r0.16, $r0.36   ## bblock 31, line 111-5,  t826,  t263,  t270
	c0    slct $r0.45 = $b0.4, $r0.45, $r0.39   ## bblock 31, line 112-5,  t840,  t838,  t839,  t278
	c0    cmplt $b0.1 = $r0.43, $r0.0   ## bblock 31, line 111-6,  t844,  t248,  0(I32)
	c0    add $r0.9 = $r0.43, 255   ## bblock 31, line 111-6,  t845,  t248,  255(I32)
	c0    slct $r0.30 = $b0.1, $r0.30, $r0.9   ## bblock 31, line 112-6,  t856,  t854,  t855,  t255
;;								## 12
	c0    shr $r0.28 = $r0.28, 8   ## bblock 31, line 111,  t46,  t752,  8(I32)
	c0    shr $r0.46 = $r0.46, 8   ## bblock 31, line 112-1,  t371,  t776,  8(I32)
	c0    cmplt $b0.1 = $r0.10, $r0.0   ## bblock 31, line 111-2,  t780,  t340,  0(I32)
	c0    add $r0.33 = $r0.10, 255   ## bblock 31, line 111-2,  t781,  t340,  255(I32)
	c0    shr $r0.31 = $r0.31, 8   ## bblock 31, line 112-2,  t348,  t792,  8(I32)
	c0    cmplt $b0.2 = $r0.29, $r0.0   ## bblock 31, line 111-3,  t796,  t317,  0(I32)
	c0    shr $r0.32 = $r0.32, 8   ## bblock 31, line 112-3,  t325,  t808,  8(I32)
	c0    cmplt $b0.0 = $r0.27, $r0.0   ## bblock 31, line 112-4,  t822,  t301,  0(I32)
	c0    add $r0.25 = $r0.27, 255   ## bblock 31, line 112-4,  t823,  t301,  255(I32)
	c0    shr $r0.45 = $r0.45, 8   ## bblock 31, line 112-5,  t279,  t840,  8(I32)
	c0    slct $r0.9 = $b0.1, $r0.9, $r0.43   ## bblock 31, line 111-6,  t846,  t844,  t845,  t248
	c0    shr $r0.30 = $r0.30, 8   ## bblock 31, line 112-6,  t256,  t856,  8(I32)
;;								## 13
	c0    mpylu $r0.27 = $r0.21, $r0.37   ## bblock 31, line 111-1,  t762,  t355,  t362
	c0    mpyhs $r0.37 = $r0.21, $r0.37   ## bblock 31, line 111-1,  t763,  t355,  t362
	c0    slct $r0.33 = $b0.1, $r0.33, $r0.10   ## bblock 31, line 111-2,  t782,  t780,  t781,  t340
	c0    add $r0.10 = $r0.29, 255   ## bblock 31, line 111-3,  t797,  t317,  255(I32)
	c0    and $r0.44 = $r0.44, 255   ## bblock 31, line 111-4,  t293,  t292(I16),  255(I32)
	c0    slct $r0.25 = $b0.0, $r0.25, $r0.27   ## bblock 31, line 112-4,  t824,  t822,  t823,  t301
	c0    mpyhs $r0.36 = $r0.16, $r0.36   ## bblock 31, line 111-5,  t827,  t263,  t270
	c0    shr $r0.9 = $r0.9, 8   ## bblock 31, line 111-6,  t251,  t846,  8(I32)
	c0    mpylu $r0.30 = $r0.7, $r0.4   ## bblock 31, line 113-6,  t847,  t240,  t249
	c0    add $r0.42 = $r0.42, $r0.30   ## bblock 31, line 112-6,  t857,  t64,  t256
	c0    add $r0.17 = $r0.17, $r0.45   ## bblock 31, line 112-6,  t858,  t152,  t279
	c0    add $r0.31 = $r0.31, $r0.32   ## bblock 31, line 112-6,  t860,  t348,  t325
;;								## 14
	c0    cmplt $b0.0 = $r0.26, $r0.0   ## bblock 31, line 113,  t753,  t80,  0(I32)
	c0    add $r0.4 = $r0.26, 255   ## bblock 31, line 113,  t754,  t80,  255(I32)
	c0    and $r0.11 = $r0.11, 255   ## bblock 31, line 113-2,  t341,  t337,  255(I32)
	c0    shr $r0.33 = $r0.33, 8   ## bblock 31, line 111-2,  t343,  t782,  8(I32)
	c0    and $r0.13 = $r0.13, 255   ## bblock 31, line 113-3,  t318,  t314,  255(I32)
	c0    slct $r0.10 = $b0.2, $r0.10, $r0.29   ## bblock 31, line 111-3,  t798,  t796,  t797,  t317
	c0    mpylu $r0.9 = $r0.23, $r0.44   ## bblock 31, line 111-4,  t810,  t286,  t293
	c0    mpyhs $r0.44 = $r0.23, $r0.44   ## bblock 31, line 111-4,  t811,  t286,  t293
	c0    shr $r0.25 = $r0.25, 8   ## bblock 31, line 112-4,  t302,  t824,  8(I32)
	c0    mpyhs $r0.7 = $r0.7, $r0.4   ## bblock 31, line 113-6,  t848,  t240,  t249
	c0    add $r0.42 = $r0.42, $r0.31   ## bblock 31, line 112-6,  t861,  t857,  t860
	c0    add $r0.28 = $r0.28, $r0.9   ## bblock 31, line 111-6,  t869,  t46,  t251
;;								## 15
	c0    slct $r0.4 = $b0.0, $r0.4, $r0.26   ## bblock 31, line 113,  t755,  t753,  t754,  t80
	c0    add $r0.27 = $r0.27, $r0.37   ## bblock 31, line 111-1,  t363,  t762,  t763
	c0    and $r0.18 = $r0.18, 255   ## bblock 31, line 113-1,  t364,  t360,  255(I32)
	c0    mpylu $r0.25 = $r0.12, $r0.11   ## bblock 31, line 113-2,  t783,  t332,  t341
	c0    mpyhs $r0.12 = $r0.12, $r0.11   ## bblock 31, line 113-2,  t784,  t332,  t341
	c0    shr $r0.10 = $r0.10, 8   ## bblock 31, line 111-3,  t320,  t798,  8(I32)
	c0    mpylu $r0.11 = $r0.14, $r0.13   ## bblock 31, line 113-3,  t799,  t309,  t318
	c0    mpyhs $r0.14 = $r0.14, $r0.13   ## bblock 31, line 113-3,  t800,  t309,  t318
	c0    and $r0.22 = $r0.22, 255   ## bblock 31, line 113-4,  t295,  t291,  255(I32)
	c0    and $r0.15 = $r0.15, 255   ## bblock 31, line 113-5,  t272,  t268,  255(I32)
	c0    add $r0.24 = $r0.24, $r0.36   ## bblock 31, line 111-5,  t271,  t826,  t827
	c0    add $r0.46 = $r0.46, $r0.25   ## bblock 31, line 112-6,  t859,  t371,  t302
;;								## 16
	c0    shr $r0.4 = $r0.4, 8   ## bblock 31, line 113,  t81,  t755,  8(I32)
	c0    cmplt $b0.1 = $r0.27, $r0.0   ## bblock 31, line 111-1,  t764,  t363,  0(I32)
	c0    add $r0.13 = $r0.27, 255   ## bblock 31, line 111-1,  t765,  t363,  255(I32)
	c0    mpylu $r0.15 = $r0.21, $r0.18   ## bblock 31, line 113-1,  t767,  t355,  t364
	c0    add $r0.9 = $r0.9, $r0.44   ## bblock 31, line 111-4,  t294,  t810,  t811
	c0    cmplt $b0.0 = $r0.24, $r0.0   ## bblock 31, line 111-5,  t828,  t271,  0(I32)
	c0    add $r0.10 = $r0.24, 255   ## bblock 31, line 111-5,  t829,  t271,  255(I32)
	c0    mpylu $r0.7 = $r0.16, $r0.15   ## bblock 31, line 113-5,  t831,  t263,  t272
	c0    mpyhs $r0.16 = $r0.16, $r0.15   ## bblock 31, line 113-5,  t832,  t263,  t272
	c0    add $r0.30 = $r0.30, $r0.7   ## bblock 31, line 113-6,  t250,  t847,  t848
	c0    add $r0.17 = $r0.17, $r0.46   ## bblock 31, line 112-6,  t862,  t858,  t859
	c0    add $r0.33 = $r0.33, $r0.10   ## bblock 31, line 111-6,  t872,  t343,  t320
;;								## 17
	c0    slct $r0.13 = $b0.1, $r0.13, $r0.27   ## bblock 31, line 111-1,  t766,  t764,  t765,  t363
	c0    mpyhs $r0.21 = $r0.21, $r0.18   ## bblock 31, line 113-1,  t768,  t355,  t364
	c0    add $r0.25 = $r0.25, $r0.12   ## bblock 31, line 113-2,  t342,  t783,  t784
	c0    add $r0.11 = $r0.11, $r0.14   ## bblock 31, line 113-3,  t319,  t799,  t800
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 31, line 111-4,  t812,  t294,  0(I32)
	c0    add $r0.24 = $r0.9, 255   ## bblock 31, line 111-4,  t813,  t294,  255(I32)
	c0    mpylu $r0.12 = $r0.23, $r0.22   ## bblock 31, line 113-4,  t815,  t286,  t295
	c0    slct $r0.10 = $b0.0, $r0.10, $r0.24   ## bblock 31, line 111-5,  t830,  t828,  t829,  t271
	c0    cmplt $b0.1 = $r0.30, $r0.0   ## bblock 31, line 113-6,  t849,  t250,  0(I32)
	c0    add $r0.26 = $r0.30, 255   ## bblock 31, line 113-6,  t850,  t250,  255(I32)
	c0    add $r0.17 = $r0.42, $r0.17   ## bblock 31, line 112-6,  t152,  t861,  t862
	c0    add $r0.28 = $r0.28, $r0.33   ## bblock 31, line 111-6,  t873,  t869,  t872
;;								## 18
	c0    shr $r0.13 = $r0.13, 8   ## bblock 31, line 111-1,  t366,  t766,  8(I32)
	c0    cmplt $b0.0 = $r0.25, $r0.0   ## bblock 31, line 113-2,  t785,  t342,  0(I32)
	c0    add $r0.9 = $r0.25, 255   ## bblock 31, line 113-2,  t786,  t342,  255(I32)
	c0    cmplt $b0.1 = $r0.11, $r0.0   ## bblock 31, line 113-3,  t801,  t319,  0(I32)
	c0    add $r0.14 = $r0.11, 255   ## bblock 31, line 113-3,  t802,  t319,  255(I32)
	c0    slct $r0.24 = $b0.0, $r0.24, $r0.9   ## bblock 31, line 111-4,  t814,  t812,  t813,  t294
	c0    mpyhs $r0.23 = $r0.23, $r0.22   ## bblock 31, line 113-4,  t816,  t286,  t295
	c0    shr $r0.10 = $r0.10, 8   ## bblock 31, line 111-5,  t274,  t830,  8(I32)
	c0    add $r0.7 = $r0.7, $r0.16   ## bblock 31, line 113-5,  t273,  t831,  t832
	c0    slct $r0.26 = $b0.1, $r0.26, $r0.30   ## bblock 31, line 113-6,  t851,  t849,  t850,  t250
;;								## 19
	c0    add $r0.15 = $r0.15, $r0.21   ## bblock 31, line 113-1,  t365,  t767,  t768
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.25   ## bblock 31, line 113-2,  t787,  t785,  t786,  t342
	c0    slct $r0.14 = $b0.1, $r0.14, $r0.11   ## bblock 31, line 113-3,  t803,  t801,  t802,  t319
	c0    shr $r0.24 = $r0.24, 8   ## bblock 31, line 111-4,  t297,  t814,  8(I32)
	c0    cmplt $b0.0 = $r0.7, $r0.0   ## bblock 31, line 113-5,  t833,  t273,  0(I32)
	c0    add $r0.10 = $r0.7, 255   ## bblock 31, line 113-5,  t834,  t273,  255(I32)
	c0    shr $r0.26 = $r0.26, 8   ## bblock 31, line 113-6,  t252,  t851,  8(I32)
	c0    add $r0.19 = $r0.19, $r0.10   ## bblock 31, line 111-6,  t870,  t153,  t274
;;								## 20
	c0    cmplt $b0.0 = $r0.15, $r0.0   ## bblock 31, line 113-1,  t769,  t365,  0(I32)
	c0    add $r0.7 = $r0.15, 255   ## bblock 31, line 113-1,  t770,  t365,  255(I32)
	c0    shr $r0.9 = $r0.9, 8   ## bblock 31, line 113-2,  t344,  t787,  8(I32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 31, line 113-3,  t321,  t803,  8(I32)
	c0    add $r0.12 = $r0.12, $r0.23   ## bblock 31, line 113-4,  t296,  t815,  t816
	c0    slct $r0.10 = $b0.0, $r0.10, $r0.7   ## bblock 31, line 113-5,  t835,  t833,  t834,  t273
	c0    add $r0.4 = $r0.4, $r0.26   ## bblock 31, line 113-6,  t863,  t81,  t252
	c0    add $r0.13 = $r0.13, $r0.24   ## bblock 31, line 111-6,  t871,  t366,  t297
;;								## 21
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.15   ## bblock 31, line 113-1,  t771,  t769,  t770,  t365
	c0    cmplt $b0.0 = $r0.12, $r0.0   ## bblock 31, line 113-4,  t817,  t296,  0(I32)
	c0    add $r0.11 = $r0.12, 255   ## bblock 31, line 113-4,  t818,  t296,  255(I32)
	c0    shr $r0.10 = $r0.10, 8   ## bblock 31, line 113-5,  t275,  t835,  8(I32)
	c0    add $r0.9 = $r0.9, $r0.14   ## bblock 31, line 113-6,  t866,  t344,  t321
	c0    add $r0.19 = $r0.19, $r0.13   ## bblock 31, line 111-6,  t874,  t870,  t871
;;								## 22
	c0    shr $r0.7 = $r0.7, 8   ## bblock 31, line 113-1,  t367,  t771,  8(I32)
	c0    slct $r0.11 = $b0.0, $r0.11, $r0.12   ## bblock 31, line 113-4,  t819,  t817,  t818,  t296
	c0    add $r0.20 = $r0.20, $r0.10   ## bblock 31, line 113-6,  t864,  t151,  t275
	c0    add $r0.4 = $r0.4, $r0.9   ## bblock 31, line 113-6,  t867,  t863,  t866
	c0    add $r0.19 = $r0.28, $r0.19   ## bblock 31, line 111-6,  t153,  t873,  t874
;;								## 23
	c0    shr $r0.11 = $r0.11, 8   ## bblock 31, line 113-4,  t298,  t819,  8(I32)
;;								## 24
	c0    add $r0.7 = $r0.7, $r0.11   ## bblock 31, line 113-6,  t865,  t367,  t298
;;								## 25
	c0    add $r0.20 = $r0.20, $r0.7   ## bblock 31, line 113-6,  t868,  t864,  t865
;;								## 26
	c0    add $r0.20 = $r0.4, $r0.20   ## bblock 31, line 113-6,  t151,  t867,  t868
	c0    goto L8?3 ## goto
;;								## 27
.trace 4
L9?3:
	c0    max $r0.20 = $r0.20, $r0.0   ## bblock 29, line 157,  t173,  t151,  0(SI32)
	c0    max $r0.17 = $r0.17, $r0.0   ## bblock 29, line 156,  t179,  t152,  0(SI32)
	c0    max $r0.19 = $r0.19, $r0.0   ## bblock 29, line 155,  t185,  t153,  0(SI32)
	c0    sh2add $r0.2 = $r0.47, $r0.49   ## bblock 29, line 155,  t744,  t395,  t425
	c0    add $r0.4 = $r0.47, 1   ## bblock 29, line 0,  t395,  t395,  1(I32)
;;								## 0
	c0    min $r0.20 = $r0.20, 255   ## bblock 29, line 157,  t83,  t173,  255(SI32)
	c0    min $r0.17 = $r0.17, 255   ## bblock 29, line 156,  t86,  t179,  255(SI32)
	c0    min $r0.19 = $r0.19, 255   ## bblock 29, line 155,  t90,  t185,  255(SI32)
	c0    add $r0.7 = $r0.48, 1   ## bblock 29, line 0,  t394,  t394,  1(I32)
;;								## 1
	c0    shl $r0.17 = $r0.17, 8   ## bblock 29, line 157,  t89,  t86,  8(SI32)
	c0    shl $r0.19 = $r0.19, 16   ## bblock 29, line 156,  t93,  t90,  16(SI32)
;;								## 2
	c0    or $r0.20 = $r0.20, $r0.19   ## bblock 29, line 157,  t743,  t83,  t93
;;								## 3
	c0    or $r0.20 = $r0.20, $r0.17   ## bblock 29, line 157,  t94,  t743,  t89
;;								## 4
	c0    stw 0[$r0.2] = $r0.20   ## bblock 29, line 155, t744, t94
	c0    goto L6?3 ## goto
;;								## 5
.trace 7
L7?3:
	c0    add $r0.49 = $r0.49, 256   ## bblock 9, line 0,  t425,  t425,  256(I32)
	c0    add $r0.8 = $r0.8, 64   ## bblock 9, line 0,  t421,  t421,  64(I32)
	c0    add $r0.3 = $r0.3, 1   ## bblock 9, line 0,  t420,  t420,  1(I32)
	c0    goto L4?3 ## goto
;;								## 0
.trace 11
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 165,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    stw 0x10[$r0.1] = $r0.50  ## spill ## t128
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t128
	      xnop 1
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 6, line 167,  t129,  ?2.4?2auto_size(I32),  t128
;;								## 3
.endp
.section .bss
.section .data
_?1STRINGPACKET.1:
    .data1 67
    .data1 111
    .data1 110
    .data1 118
    .data1 111
    .data1 108
    .data1 117
    .data1 116
    .data1 105
    .data1 111
    .data1 110
    .data1 32
    .data1 55
    .data1 120
    .data1 55
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
.skip 2
filter7x7::
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
.section .data
.comm strbuf, 0xc, 4
.comm conv7_result, 0x4000, 4
.comm conv7_image, 0x4000, 4
.section .text
.import NOP
.type NOP,@function
.import puts
.type puts,@function
