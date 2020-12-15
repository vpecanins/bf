 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/6_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out"
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
.trace 7
	c0    add $r0.1 = $r0.1, (-0x20)
;;								## 0
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 36,  raddr(NOP)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t62
;;								## 1
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t1230,  (~0xfff)(I32)
	c0    mov $r0.3 = (grey_framebuffer + 0)   ## bblock 1, line 0,  t1232,  addr(grey_framebuffer?1.0)(P32)
	c0    ldw $r0.5 = 0x10[$r0.1]  ## restore ## t62
;;								## 2
;;								## 3
.trace 4
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 60,  t1250(I1),  t1230,  0(SI32)
	c0    add $r0.4 = $r0.3, 64   ## [spec] bblock 17, line 0,  t1007,  t1232,  64(I32)
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 17, line 0,  t1008,  t1230,  16(I32)
;;								## 0
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 17, line 0-1,  t1230,  t1008,  16(I32)
	c0    brf $b0.0, L3?3   ## bblock 2, line 60,  t1250(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 17, line 61, t1232, 0(SI32)
	c0    stw 4[$r0.3] = $r0.0   ## bblock 17, line 61-1, t1232, 0(SI32)
	c0    stw 8[$r0.3] = $r0.0   ## bblock 17, line 61-2, t1232, 0(SI32)
	c0    stw 12[$r0.3] = $r0.0   ## bblock 17, line 61-3, t1232, 0(SI32)
	c0    stw 16[$r0.3] = $r0.0   ## bblock 17, line 61-4, t1232, 0(SI32)
	c0    stw 20[$r0.3] = $r0.0   ## bblock 17, line 61-5, t1232, 0(SI32)
;;								## 2
	c0    stw 24[$r0.3] = $r0.0   ## bblock 17, line 61-6, t1232, 0(SI32)
	c0    stw 28[$r0.3] = $r0.0   ## bblock 17, line 61-7, t1232, 0(SI32)
	c0    stw 32[$r0.3] = $r0.0   ## bblock 17, line 61-8, t1232, 0(SI32)
	c0    stw 36[$r0.3] = $r0.0   ## bblock 17, line 61-9, t1232, 0(SI32)
	c0    stw 40[$r0.3] = $r0.0   ## bblock 17, line 61-10, t1232, 0(SI32)
	c0    stw 44[$r0.3] = $r0.0   ## bblock 17, line 61-11, t1232, 0(SI32)
;;								## 3
	c0    stw 48[$r0.3] = $r0.0   ## bblock 17, line 61-12, t1232, 0(SI32)
	c0    stw 52[$r0.3] = $r0.0   ## bblock 17, line 61-13, t1232, 0(SI32)
	c0    stw 56[$r0.3] = $r0.0   ## bblock 17, line 61-14, t1232, 0(SI32)
	c0    stw 60[$r0.3] = $r0.0   ## bblock 17, line 61-15, t1232, 0(SI32)
	c0    stw 0[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    add $r0.3 = $r0.4, 64   ## bblock 17, line 0-1,  t1232,  t1007,  64(I32)
;;								## 4
	c0    stw 4[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 8[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 12[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 16[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 20[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 24[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 5
	c0    stw 28[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 32[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 36[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 40[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 44[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 48[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 6
	c0    stw 52[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 56[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    stw 60[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	c0    goto L2?3 ## goto
;;								## 7
.trace 8
L3?3:
	c0    mov $r0.3 = (~0x3f)   ## bblock 3, line 0,  t741,  (~0x3f)(I32)
	c0    mov $r0.5 = (grey_framebuffer + 0)   ## bblock 3, line 0,  t729,  addr(grey_framebuffer?1.0)(P32)
	c0    mov $r0.6 = (grey_image + 0)   ## bblock 3, line 0,  t740,  addr(grey_image?1.0)(P32)
	c0    mov $r0.25 = $r0.5   ## t62
;;								## 0
;;								## 1
.trace 3
L4?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 4, line 70,  t1251(I1),  t741,  0(SI32)
	c0    mov $r0.10 = (~0x36)   ## [spec] bblock 7, line 0,  t390,  (~0x36)(I32)
	c0    mov $r0.4 = $r0.5   ## [spec] bblock 7, line 0,  t388,  t729
	c0    mov $r0.2 = $r0.6   ## [spec] bblock 7, line 0,  t389,  t740
	c0    mov $r0.22 = $r0.3   ## t741
	c0    mov $r0.23 = $r0.5   ## t729
;;								## 0
	c0    mov $r0.24 = $r0.6   ## t740
	c0    brf $b0.0, L5?3   ## bblock 4, line 70,  t1251(I1)
;;								## 1
.trace 1
L6?3:
	c0    ldw $r0.5 = 4[$r0.2]   ## bblock 8, line 76-1, t319, t389
	c0    ldw $r0.6 = 8[$r0.2]   ## bblock 8, line 76-2, t299, t389
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 8, line 76, t113, t389
	c0    ldw $r0.7 = 12[$r0.2]   ## bblock 8, line 76-3, t279, t389
	c0    ldw $r0.8 = 16[$r0.2]   ## bblock 8, line 76-4, t259, t389
	c0    ldw $r0.9 = 20[$r0.2]   ## bblock 8, line 76-5, t239, t389
;;								## 0
	c0    ldw $r0.11 = 24[$r0.2]   ## bblock 8, line 76-6, t219, t389
	c0    ldw $r0.12 = 28[$r0.2]   ## bblock 8, line 76-7, t199, t389
	c0    ldw $r0.13 = 32[$r0.2]   ## bblock 8, line 76-8, t179, t389
	c0    cmplt $b0.0 = $r0.10, $r0.0   ## bblock 8, line 73-9,  t1261(I1),  t390,  0(SI32)
	c0    ldw.d $r0.14 = 36[$r0.2]   ## [spec] bblock 62, line 76-9, t159, t389
	c0    ldw.d $r0.15 = 40[$r0.2]   ## [spec] bblock 62, line 76-10, t78, t389
;;								## 1
	c0    and $r0.17 = $r0.3, 255   ## bblock 8, line 77,  t86,  t113,  255(I32)
	c0    and $r0.19 = $r0.5, 255   ## bblock 8, line 77-1,  t320,  t319,  255(I32)
	c0    shru $r0.16 = $r0.3, 8   ## bblock 8, line 77,  t31(I24),  t113,  8(SI32)
	c0    shru $r0.18 = $r0.5, 8   ## bblock 8, line 77-1,  t321(I24),  t319,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 8, line 77,  t34(I16),  t113,  16(SI32)
	c0    shru $r0.5 = $r0.5, 16   ## bblock 8, line 77-1,  t325(I16),  t319,  16(SI32)
;;								## 2
	c0    and $r0.21 = $r0.6, 255   ## bblock 8, line 77-2,  t300,  t299,  255(I32)
	c0    and $r0.16 = $r0.16, 255   ## bblock 8, line 77,  t87,  t31(I24),  255(I32)
	c0    and $r0.18 = $r0.18, 255   ## bblock 8, line 77-1,  t322,  t321(I24),  255(I32)
	c0    shru $r0.20 = $r0.6, 8   ## bblock 8, line 77-2,  t301(I24),  t299,  8(SI32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 8, line 77,  t90,  t34(I16),  255(I32)
	c0    and $r0.5 = $r0.5, 255   ## bblock 8, line 77-1,  t326,  t325(I16),  255(I32)
;;								## 3
	c0    max $r0.17 = $r0.17, $r0.16   ## bblock 8, line 77,  t89,  t86,  t87
	c0    max $r0.19 = $r0.19, $r0.18   ## bblock 8, line 77-1,  t324,  t320,  t322
	c0    and $r0.20 = $r0.20, 255   ## bblock 8, line 77-2,  t302,  t301(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 8, line 77-2,  t305(I16),  t299,  16(SI32)
	c0    and $r0.18 = $r0.7, 255   ## bblock 8, line 77-3,  t280,  t279,  255(I32)
	c0    shru $r0.16 = $r0.7, 8   ## bblock 8, line 77-3,  t281(I24),  t279,  8(SI32)
;;								## 4
	c0    max $r0.21 = $r0.21, $r0.20   ## bblock 8, line 77-2,  t304,  t300,  t302
	c0    max $r0.17 = $r0.17, $r0.3   ## bblock 8, line 77,  t26,  t89,  t90
	c0    max $r0.19 = $r0.19, $r0.5   ## bblock 8, line 77-1,  t328,  t324,  t326
	c0    and $r0.6 = $r0.6, 255   ## bblock 8, line 77-2,  t306,  t305(I16),  255(I32)
	c0    and $r0.16 = $r0.16, 255   ## bblock 8, line 77-3,  t282,  t281(I24),  255(I32)
	c0    shru $r0.7 = $r0.7, 16   ## bblock 8, line 77-3,  t285(I16),  t279,  16(SI32)
;;								## 5
	c0    zxtb $r0.17 = $r0.17   ## bblock 8, line 77,  t41(I8),  t26
	c0    zxtb $r0.19 = $r0.19   ## bblock 8, line 77-1,  t330(I8),  t328
	c0    max $r0.21 = $r0.21, $r0.6   ## bblock 8, line 77-2,  t308,  t304,  t306
	c0    max $r0.18 = $r0.18, $r0.16   ## bblock 8, line 77-3,  t284,  t280,  t282
	c0    and $r0.7 = $r0.7, 255   ## bblock 8, line 77-3,  t286,  t285(I16),  255(I32)
	c0    shru $r0.3 = $r0.8, 8   ## bblock 8, line 77-4,  t261(I24),  t259,  8(SI32)
;;								## 6
	c0    shl $r0.6 = $r0.17, 8   ## bblock 8, line 88,  t40,  t41(I8),  8(SI32)
	c0    shl $r0.5 = $r0.17, 16   ## bblock 8, line 88,  t42,  t41(I8),  16(SI32)
	c0    shl $r0.20 = $r0.19, 8   ## bblock 8, line 88-1,  t331,  t330(I8),  8(SI32)
	c0    shl $r0.16 = $r0.19, 16   ## bblock 8, line 88-1,  t332,  t330(I8),  16(SI32)
	c0    zxtb $r0.21 = $r0.21   ## bblock 8, line 77-2,  t310(I8),  t308
	c0    max $r0.18 = $r0.18, $r0.7   ## bblock 8, line 77-3,  t288,  t284,  t286
;;								## 7
	c0    or $r0.17 = $r0.17, $r0.5   ## bblock 8, line 88,  t1252,  t41(I8),  t42
	c0    or $r0.19 = $r0.19, $r0.16   ## bblock 8, line 88-1,  t1253,  t330(I8),  t332
	c0    shl $r0.7 = $r0.21, 8   ## bblock 8, line 88-2,  t311,  t310(I8),  8(SI32)
	c0    shl $r0.5 = $r0.21, 16   ## bblock 8, line 88-2,  t312,  t310(I8),  16(SI32)
	c0    zxtb $r0.18 = $r0.18   ## bblock 8, line 77-3,  t290(I8),  t288
	c0    and $r0.3 = $r0.3, 255   ## bblock 8, line 77-4,  t262,  t261(I24),  255(I32)
;;								## 8
	c0    or $r0.17 = $r0.17, $r0.6   ## bblock 8, line 88,  t44,  t1252,  t40
	c0    or $r0.19 = $r0.19, $r0.20   ## bblock 8, line 88-1,  t333,  t1253,  t331
	c0    or $r0.21 = $r0.21, $r0.5   ## bblock 8, line 88-2,  t1254,  t310(I8),  t312
	c0    shl $r0.6 = $r0.18, 8   ## bblock 8, line 88-3,  t291,  t290(I8),  8(SI32)
	c0    shl $r0.5 = $r0.18, 16   ## bblock 8, line 88-3,  t292,  t290(I8),  16(SI32)
	c0    and $r0.16 = $r0.8, 255   ## bblock 8, line 77-4,  t260,  t259,  255(I32)
;;								## 9
	c0    or $r0.21 = $r0.21, $r0.7   ## bblock 8, line 88-2,  t313,  t1254,  t311
	c0    or $r0.18 = $r0.18, $r0.5   ## bblock 8, line 88-3,  t1255,  t290(I8),  t292
	c0    max $r0.16 = $r0.16, $r0.3   ## bblock 8, line 77-4,  t264,  t260,  t262
	c0    shru $r0.8 = $r0.8, 16   ## bblock 8, line 77-4,  t265(I16),  t259,  16(SI32)
	c0    and $r0.5 = $r0.9, 255   ## bblock 8, line 77-5,  t240,  t239,  255(I32)
	c0    shru $r0.3 = $r0.9, 8   ## bblock 8, line 77-5,  t241(I24),  t239,  8(SI32)
;;								## 10
	c0    or $r0.18 = $r0.18, $r0.6   ## bblock 8, line 88-3,  t293,  t1255,  t291
	c0    and $r0.8 = $r0.8, 255   ## bblock 8, line 77-4,  t266,  t265(I16),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 8, line 77-5,  t242,  t241(I24),  255(I32)
	c0    shru $r0.9 = $r0.9, 16   ## bblock 8, line 77-5,  t245(I16),  t239,  16(SI32)
	c0    and $r0.7 = $r0.11, 255   ## bblock 8, line 77-6,  t220,  t219,  255(I32)
	c0    shru $r0.6 = $r0.11, 8   ## bblock 8, line 77-6,  t221(I24),  t219,  8(SI32)
;;								## 11
	c0    max $r0.16 = $r0.16, $r0.8   ## bblock 8, line 77-4,  t268,  t264,  t266
	c0    max $r0.5 = $r0.5, $r0.3   ## bblock 8, line 77-5,  t244,  t240,  t242
	c0    and $r0.9 = $r0.9, 255   ## bblock 8, line 77-5,  t246,  t245(I16),  255(I32)
	c0    and $r0.6 = $r0.6, 255   ## bblock 8, line 77-6,  t222,  t221(I24),  255(I32)
	c0    shru $r0.11 = $r0.11, 16   ## bblock 8, line 77-6,  t225(I16),  t219,  16(SI32)
	c0    shru $r0.3 = $r0.12, 8   ## bblock 8, line 77-7,  t201(I24),  t199,  8(SI32)
;;								## 12
	c0    zxtb $r0.16 = $r0.16   ## bblock 8, line 77-4,  t270(I8),  t268
	c0    max $r0.5 = $r0.5, $r0.9   ## bblock 8, line 77-5,  t248,  t244,  t246
	c0    max $r0.7 = $r0.7, $r0.6   ## bblock 8, line 77-6,  t224,  t220,  t222
	c0    and $r0.11 = $r0.11, 255   ## bblock 8, line 77-6,  t226,  t225(I16),  255(I32)
	c0    and $r0.6 = $r0.12, 255   ## bblock 8, line 77-7,  t200,  t199,  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 8, line 77-7,  t202,  t201(I24),  255(I32)
;;								## 13
	c0    shl $r0.9 = $r0.16, 8   ## bblock 8, line 88-4,  t271,  t270(I8),  8(SI32)
	c0    shl $r0.8 = $r0.16, 16   ## bblock 8, line 88-4,  t272,  t270(I8),  16(SI32)
	c0    zxtb $r0.5 = $r0.5   ## bblock 8, line 77-5,  t250(I8),  t248
	c0    max $r0.7 = $r0.7, $r0.11   ## bblock 8, line 77-6,  t228,  t224,  t226
	c0    max $r0.6 = $r0.6, $r0.3   ## bblock 8, line 77-7,  t204,  t200,  t202
	c0    shru $r0.12 = $r0.12, 16   ## bblock 8, line 77-7,  t205(I16),  t199,  16(SI32)
;;								## 14
	c0    or $r0.16 = $r0.16, $r0.8   ## bblock 8, line 88-4,  t1256,  t270(I8),  t272
	c0    shl $r0.8 = $r0.5, 8   ## bblock 8, line 88-5,  t251,  t250(I8),  8(SI32)
	c0    shl $r0.3 = $r0.5, 16   ## bblock 8, line 88-5,  t252,  t250(I8),  16(SI32)
	c0    zxtb $r0.7 = $r0.7   ## bblock 8, line 77-6,  t230(I8),  t228
	c0    and $r0.12 = $r0.12, 255   ## bblock 8, line 77-7,  t206,  t205(I16),  255(I32)
	c0    shru $r0.11 = $r0.13, 8   ## bblock 8, line 77-8,  t181(I24),  t179,  8(SI32)
;;								## 15
	c0    or $r0.16 = $r0.16, $r0.9   ## bblock 8, line 88-4,  t273,  t1256,  t271
	c0    or $r0.5 = $r0.5, $r0.3   ## bblock 8, line 88-5,  t1257,  t250(I8),  t252
	c0    shl $r0.9 = $r0.7, 8   ## bblock 8, line 88-6,  t231,  t230(I8),  8(SI32)
	c0    shl $r0.3 = $r0.7, 16   ## bblock 8, line 88-6,  t232,  t230(I8),  16(SI32)
	c0    max $r0.6 = $r0.6, $r0.12   ## bblock 8, line 77-7,  t208,  t204,  t206
	c0    and $r0.11 = $r0.11, 255   ## bblock 8, line 77-8,  t182,  t181(I24),  255(I32)
;;								## 16
	c0    or $r0.5 = $r0.5, $r0.8   ## bblock 8, line 88-5,  t253,  t1257,  t251
	c0    or $r0.7 = $r0.7, $r0.3   ## bblock 8, line 88-6,  t1258,  t230(I8),  t232
	c0    zxtb $r0.6 = $r0.6   ## bblock 8, line 77-7,  t210(I8),  t208
	c0    and $r0.3 = $r0.13, 255   ## bblock 8, line 77-8,  t180,  t179,  255(I32)
	c0    shru $r0.13 = $r0.13, 16   ## bblock 8, line 77-8,  t185(I16),  t179,  16(SI32)
	c0    shru $r0.8 = $r0.14, 8   ## [spec] bblock 62, line 77-9,  t161(I24),  t159,  8(SI32)
;;								## 17
	c0    or $r0.7 = $r0.7, $r0.9   ## bblock 8, line 88-6,  t233,  t1258,  t231
	c0    shl $r0.12 = $r0.6, 8   ## bblock 8, line 88-7,  t211,  t210(I8),  8(SI32)
	c0    shl $r0.9 = $r0.6, 16   ## bblock 8, line 88-7,  t212,  t210(I8),  16(SI32)
	c0    max $r0.3 = $r0.3, $r0.11   ## bblock 8, line 77-8,  t184,  t180,  t182
	c0    and $r0.13 = $r0.13, 255   ## bblock 8, line 77-8,  t186,  t185(I16),  255(I32)
	c0    and $r0.8 = $r0.8, 255   ## [spec] bblock 62, line 77-9,  t162,  t161(I24),  255(I32)
;;								## 18
	c0    or $r0.6 = $r0.6, $r0.9   ## bblock 8, line 88-7,  t1259,  t210(I8),  t212
	c0    max $r0.3 = $r0.3, $r0.13   ## bblock 8, line 77-8,  t188,  t184,  t186
	c0    and $r0.9 = $r0.14, 255   ## [spec] bblock 62, line 77-9,  t160,  t159,  255(I32)
	c0    shru $r0.14 = $r0.14, 16   ## [spec] bblock 62, line 77-9,  t165(I16),  t159,  16(SI32)
	c0    and $r0.13 = $r0.15, 255   ## [spec] bblock 62, line 77-10,  t117,  t78,  255(I32)
	c0    shru $r0.11 = $r0.15, 8   ## [spec] bblock 62, line 77-10,  t121(I24),  t78,  8(SI32)
;;								## 19
	c0    or $r0.6 = $r0.6, $r0.12   ## bblock 8, line 88-7,  t213,  t1259,  t211
	c0    zxtb $r0.3 = $r0.3   ## bblock 8, line 77-8,  t190(I8),  t188
	c0    max $r0.9 = $r0.9, $r0.8   ## [spec] bblock 62, line 77-9,  t164,  t160,  t162
	c0    and $r0.14 = $r0.14, 255   ## [spec] bblock 62, line 77-9,  t166,  t165(I16),  255(I32)
	c0    and $r0.11 = $r0.11, 255   ## [spec] bblock 62, line 77-10,  t125,  t121(I24),  255(I32)
	c0    shru $r0.15 = $r0.15, 16   ## [spec] bblock 62, line 77-10,  t137(I16),  t78,  16(SI32)
;;								## 20
	c0    shl $r0.12 = $r0.3, 8   ## bblock 8, line 88-8,  t191,  t190(I8),  8(SI32)
	c0    shl $r0.8 = $r0.3, 16   ## bblock 8, line 88-8,  t192,  t190(I8),  16(SI32)
	c0    max $r0.9 = $r0.9, $r0.14   ## [spec] bblock 62, line 77-9,  t168,  t164,  t166
	c0    max $r0.13 = $r0.13, $r0.11   ## [spec] bblock 62, line 77-10,  t133,  t117,  t125
	c0    and $r0.15 = $r0.15, 255   ## [spec] bblock 62, line 77-10,  t141,  t137(I16),  255(I32)
	c0    add $r0.2 = $r0.2, 44   ## [spec] bblock 62, line 0,  t389,  t389,  44(I32)
;;								## 21
	c0    stw 0[$r0.4] = $r0.17   ## bblock 8, line 89, t388, t44
	c0    stw 4[$r0.4] = $r0.19   ## bblock 8, line 89-1, t388, t333
	c0    or $r0.3 = $r0.3, $r0.8   ## bblock 8, line 88-8,  t1260,  t190(I8),  t192
	c0    zxtb $r0.9 = $r0.9   ## [spec] bblock 62, line 77-9,  t170(I8),  t168
	c0    max $r0.13 = $r0.13, $r0.15   ## [spec] bblock 62, line 77-10,  t149,  t133,  t141
	c0    add $r0.10 = $r0.10, 11   ## [spec] bblock 62, line 0,  t390,  t390,  11(I32)
;;								## 22
	c0    stw 8[$r0.4] = $r0.21   ## bblock 8, line 89-2, t388, t313
	c0    stw 12[$r0.4] = $r0.18   ## bblock 8, line 89-3, t388, t293
	c0    or $r0.3 = $r0.3, $r0.12   ## bblock 8, line 88-8,  t193,  t1260,  t191
	c0    shl $r0.11 = $r0.9, 8   ## [spec] bblock 62, line 88-9,  t171,  t170(I8),  8(SI32)
	c0    shl $r0.8 = $r0.9, 16   ## [spec] bblock 62, line 88-9,  t172,  t170(I8),  16(SI32)
	c0    zxtb $r0.13 = $r0.13   ## [spec] bblock 62, line 77-10,  t151(I8),  t149
;;								## 23
	c0    stw 16[$r0.4] = $r0.16   ## bblock 8, line 89-4, t388, t273
	c0    stw 20[$r0.4] = $r0.5   ## bblock 8, line 89-5, t388, t253
	c0    stw 24[$r0.4] = $r0.7   ## bblock 8, line 89-6, t388, t233
	c0    or $r0.9 = $r0.9, $r0.8   ## [spec] bblock 62, line 88-9,  t1262,  t170(I8),  t172
	c0    shl $r0.12 = $r0.13, 8   ## [spec] bblock 62, line 88-10,  t152,  t151(I8),  8(SI32)
	c0    shl $r0.8 = $r0.13, 16   ## [spec] bblock 62, line 88-10,  t153,  t151(I8),  16(SI32)
;;								## 24
	c0    stw 28[$r0.4] = $r0.6   ## bblock 8, line 89-7, t388, t213
	c0    stw 32[$r0.4] = $r0.3   ## bblock 8, line 89-8, t388, t193
	c0    or $r0.9 = $r0.9, $r0.11   ## [spec] bblock 62, line 88-9,  t173,  t1262,  t171
	c0    or $r0.13 = $r0.13, $r0.8   ## [spec] bblock 62, line 88-10,  t1263,  t151(I8),  t153
	c0    brf $b0.0, L7?3   ## bblock 8, line 73-9,  t1261(I1)
;;								## 25
	c0    stw 36[$r0.4] = $r0.9   ## bblock 62, line 89-9, t388, t173
	c0    or $r0.13 = $r0.13, $r0.12   ## bblock 62, line 88-10,  t154,  t1263,  t152
;;								## 26
	c0    stw 40[$r0.4] = $r0.13   ## bblock 62, line 89-10, t388, t154
	c0    add $r0.4 = $r0.4, 44   ## bblock 62, line 0,  t388,  t388,  44(I32)
	c0    goto L6?3 ## goto
;;								## 27
.trace 5
L7?3:
	c0    add $r0.6 = $r0.24, 256   ## bblock 9, line 0,  t740,  t740,  256(I32)
	c0    add $r0.5 = $r0.23, 256   ## bblock 9, line 0,  t729,  t729,  256(I32)
	c0    add $r0.3 = $r0.22, 1   ## bblock 9, line 0,  t741,  t741,  1(I32)
	c0    goto L4?3 ## goto
;;								## 0
.trace 9
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 105,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    stw 0x10[$r0.1] = $r0.25  ## spill ## t62
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t62
	      xnop 1
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 6, line 107,  t63,  ?2.4?2auto_size(I32),  t62
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
