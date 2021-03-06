 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/1_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out"
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
;;								## 0
	c0    cmpgt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 15,  t19(I1),  t17,  t18
;;								## 1
	c0    brf $b0.0, L0?3   ## bblock 0, line 15,  t19(I1)
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 15,  t5,  ?2.1?2auto_size(I32),  t4
;;								## 3
.trace 2
L0?3:
	c0    mov $r0.3 = $r0.4   ## t18
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 16,  t5,  ?2.1?2auto_size(I32),  t4
;;								## 1
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
;;								## 0
	c0    cmplt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 21,  t19(I1),  t17,  t18
;;								## 1
	c0    brf $b0.0, L1?3   ## bblock 0, line 21,  t19(I1)
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 21,  t5,  ?2.2?2auto_size(I32),  t4
;;								## 3
.trace 2
L1?3:
	c0    mov $r0.3 = $r0.4   ## t18
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 22,  t5,  ?2.2?2auto_size(I32),  t4
;;								## 1
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
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 24,  t1,  ?2.3?2auto_size(I32),  t0
;;								## 2
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
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t62
;;								## 1
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 36,  raddr(NOP)(P32)
;;								## 2
	c0    mov $r0.3 = (grey_framebuffer + 0)   ## bblock 1, line 0,  t1232,  addr(grey_framebuffer?1.0)(P32)
;;								## 3
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t1230,  (~0xfff)(I32)
;;								## 4
	c0    ldw $r0.5 = 0x10[$r0.1]  ## restore ## t62
;;								## 5
;;								## 6
.trace 4
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 60,  t1250(I1),  t1230,  0(SI32)
;;								## 0
	c0    brf $b0.0, L3?3   ## bblock 2, line 60,  t1250(I1)
;;								## 1
	c0    add $r0.4 = $r0.3, 64   ## bblock 17, line 0,  t1007,  t1232,  64(I32)
;;								## 2
	c0    add $r0.2 = $r0.2, 16   ## bblock 17, line 0,  t1008,  t1230,  16(I32)
;;								## 3
	c0    add $r0.2 = $r0.2, 16   ## bblock 17, line 0-1,  t1230,  t1008,  16(I32)
;;								## 4
	c0    stw 0[$r0.3] = $r0.0   ## bblock 17, line 61, t1232, 0(SI32)
;;								## 5
	c0    stw 4[$r0.3] = $r0.0   ## bblock 17, line 61-1, t1232, 0(SI32)
;;								## 6
	c0    stw 8[$r0.3] = $r0.0   ## bblock 17, line 61-2, t1232, 0(SI32)
;;								## 7
	c0    stw 12[$r0.3] = $r0.0   ## bblock 17, line 61-3, t1232, 0(SI32)
;;								## 8
	c0    stw 16[$r0.3] = $r0.0   ## bblock 17, line 61-4, t1232, 0(SI32)
;;								## 9
	c0    stw 20[$r0.3] = $r0.0   ## bblock 17, line 61-5, t1232, 0(SI32)
;;								## 10
	c0    stw 24[$r0.3] = $r0.0   ## bblock 17, line 61-6, t1232, 0(SI32)
;;								## 11
	c0    stw 28[$r0.3] = $r0.0   ## bblock 17, line 61-7, t1232, 0(SI32)
;;								## 12
	c0    stw 32[$r0.3] = $r0.0   ## bblock 17, line 61-8, t1232, 0(SI32)
;;								## 13
	c0    stw 36[$r0.3] = $r0.0   ## bblock 17, line 61-9, t1232, 0(SI32)
;;								## 14
	c0    stw 40[$r0.3] = $r0.0   ## bblock 17, line 61-10, t1232, 0(SI32)
;;								## 15
	c0    stw 44[$r0.3] = $r0.0   ## bblock 17, line 61-11, t1232, 0(SI32)
;;								## 16
	c0    stw 48[$r0.3] = $r0.0   ## bblock 17, line 61-12, t1232, 0(SI32)
;;								## 17
	c0    stw 52[$r0.3] = $r0.0   ## bblock 17, line 61-13, t1232, 0(SI32)
;;								## 18
	c0    stw 56[$r0.3] = $r0.0   ## bblock 17, line 61-14, t1232, 0(SI32)
;;								## 19
	c0    stw 60[$r0.3] = $r0.0   ## bblock 17, line 61-15, t1232, 0(SI32)
;;								## 20
	c0    add $r0.3 = $r0.4, 64   ## bblock 17, line 0-1,  t1232,  t1007,  64(I32)
;;								## 21
	c0    stw 0[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 22
	c0    stw 4[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 23
	c0    stw 8[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 24
	c0    stw 12[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 25
	c0    stw 16[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 26
	c0    stw 20[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 27
	c0    stw 24[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 28
	c0    stw 28[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 29
	c0    stw 32[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 30
	c0    stw 36[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 31
	c0    stw 40[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 32
	c0    stw 44[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 33
	c0    stw 48[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 34
	c0    stw 52[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 35
	c0    stw 56[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
;;								## 36
	c0    stw 60[$r0.4] = $r0.0   ## bblock 17, line 61-1, t1007, 0(SI32)
	      ## goto
;;
	c0    goto L2?3 ## goto
;;								## 37
.trace 8
L3?3:
	c0    mov $r0.7 = (grey_image + 0)   ## bblock 3, line 0,  t740,  addr(grey_image?1.0)(P32)
;;								## 0
	c0    mov $r0.6 = (grey_framebuffer + 0)   ## bblock 3, line 0,  t729,  addr(grey_framebuffer?1.0)(P32)
;;								## 1
	c0    mov $r0.3 = (~0x3f)   ## bblock 3, line 0,  t741,  (~0x3f)(I32)
;;								## 2
	c0    mov $r0.21 = $r0.5   ## t62
;;								## 3
.trace 3
L4?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 4, line 70,  t1251(I1),  t741,  0(SI32)
;;								## 0
	c0    brf $b0.0, L5?3   ## bblock 4, line 70,  t1251(I1)
;;								## 1
	c0    mov $r0.5 = (~0x36)   ## bblock 7, line 0,  t390,  (~0x36)(I32)
;;								## 2
	c0    mov $r0.4 = $r0.6   ## bblock 7, line 0,  t388,  t729
;;								## 3
	c0    mov $r0.2 = $r0.7   ## bblock 7, line 0,  t389,  t740
;;								## 4
	c0    mov $r0.18 = $r0.3   ## t741
;;								## 5
	c0    mov $r0.19 = $r0.6   ## t729
;;								## 6
	c0    mov $r0.20 = $r0.7   ## t740
;;								## 7
.trace 1
L6?3:
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 8, line 76, t113, t389
;;								## 0
	c0    ldw $r0.6 = 4[$r0.2]   ## bblock 8, line 76-1, t319, t389
;;								## 1
	c0    shru $r0.7 = $r0.3, 8   ## bblock 8, line 77,  t31(I24),  t113,  8(SI32)
;;								## 2
	c0    and $r0.7 = $r0.7, 255   ## bblock 8, line 77,  t87,  t31(I24),  255(I32)
;;								## 3
	c0    and $r0.8 = $r0.3, 255   ## bblock 8, line 77,  t86,  t113,  255(I32)
;;								## 4
	c0    max $r0.8 = $r0.8, $r0.7   ## bblock 8, line 77,  t89,  t86,  t87
;;								## 5
	c0    shru $r0.3 = $r0.3, 16   ## bblock 8, line 77,  t34(I16),  t113,  16(SI32)
;;								## 6
	c0    and $r0.3 = $r0.3, 255   ## bblock 8, line 77,  t90,  t34(I16),  255(I32)
;;								## 7
	c0    max $r0.8 = $r0.8, $r0.3   ## bblock 8, line 77,  t26,  t89,  t90
;;								## 8
	c0    zxtb $r0.8 = $r0.8   ## bblock 8, line 77,  t41(I8),  t26
;;								## 9
	c0    shl $r0.3 = $r0.8, 16   ## bblock 8, line 88,  t42,  t41(I8),  16(SI32)
;;								## 10
	c0    or $r0.3 = $r0.8, $r0.3   ## bblock 8, line 88,  t1252,  t41(I8),  t42
;;								## 11
	c0    shl $r0.8 = $r0.8, 8   ## bblock 8, line 88,  t40,  t41(I8),  8(SI32)
;;								## 12
	c0    or $r0.3 = $r0.3, $r0.8   ## bblock 8, line 88,  t44,  t1252,  t40
;;								## 13
	c0    shru $r0.7 = $r0.6, 8   ## bblock 8, line 77-1,  t321(I24),  t319,  8(SI32)
;;								## 14
	c0    and $r0.7 = $r0.7, 255   ## bblock 8, line 77-1,  t322,  t321(I24),  255(I32)
;;								## 15
	c0    and $r0.8 = $r0.6, 255   ## bblock 8, line 77-1,  t320,  t319,  255(I32)
;;								## 16
	c0    max $r0.8 = $r0.8, $r0.7   ## bblock 8, line 77-1,  t324,  t320,  t322
;;								## 17
	c0    shru $r0.6 = $r0.6, 16   ## bblock 8, line 77-1,  t325(I16),  t319,  16(SI32)
;;								## 18
	c0    and $r0.6 = $r0.6, 255   ## bblock 8, line 77-1,  t326,  t325(I16),  255(I32)
;;								## 19
	c0    max $r0.8 = $r0.8, $r0.6   ## bblock 8, line 77-1,  t328,  t324,  t326
;;								## 20
	c0    zxtb $r0.8 = $r0.8   ## bblock 8, line 77-1,  t330(I8),  t328
;;								## 21
	c0    shl $r0.6 = $r0.8, 16   ## bblock 8, line 88-1,  t332,  t330(I8),  16(SI32)
;;								## 22
	c0    or $r0.6 = $r0.8, $r0.6   ## bblock 8, line 88-1,  t1253,  t330(I8),  t332
;;								## 23
	c0    shl $r0.8 = $r0.8, 8   ## bblock 8, line 88-1,  t331,  t330(I8),  8(SI32)
;;								## 24
	c0    or $r0.6 = $r0.6, $r0.8   ## bblock 8, line 88-1,  t333,  t1253,  t331
;;								## 25
	c0    ldw $r0.7 = 8[$r0.2]   ## bblock 8, line 76-2, t299, t389
;;								## 26
	c0    ldw $r0.8 = 12[$r0.2]   ## bblock 8, line 76-3, t279, t389
;;								## 27
	c0    shru $r0.9 = $r0.7, 8   ## bblock 8, line 77-2,  t301(I24),  t299,  8(SI32)
;;								## 28
	c0    and $r0.9 = $r0.9, 255   ## bblock 8, line 77-2,  t302,  t301(I24),  255(I32)
;;								## 29
	c0    and $r0.10 = $r0.7, 255   ## bblock 8, line 77-2,  t300,  t299,  255(I32)
;;								## 30
	c0    max $r0.10 = $r0.10, $r0.9   ## bblock 8, line 77-2,  t304,  t300,  t302
;;								## 31
	c0    shru $r0.7 = $r0.7, 16   ## bblock 8, line 77-2,  t305(I16),  t299,  16(SI32)
;;								## 32
	c0    and $r0.7 = $r0.7, 255   ## bblock 8, line 77-2,  t306,  t305(I16),  255(I32)
;;								## 33
	c0    max $r0.10 = $r0.10, $r0.7   ## bblock 8, line 77-2,  t308,  t304,  t306
;;								## 34
	c0    zxtb $r0.10 = $r0.10   ## bblock 8, line 77-2,  t310(I8),  t308
;;								## 35
	c0    shl $r0.7 = $r0.10, 16   ## bblock 8, line 88-2,  t312,  t310(I8),  16(SI32)
;;								## 36
	c0    or $r0.7 = $r0.10, $r0.7   ## bblock 8, line 88-2,  t1254,  t310(I8),  t312
;;								## 37
	c0    shl $r0.10 = $r0.10, 8   ## bblock 8, line 88-2,  t311,  t310(I8),  8(SI32)
;;								## 38
	c0    or $r0.7 = $r0.7, $r0.10   ## bblock 8, line 88-2,  t313,  t1254,  t311
;;								## 39
	c0    shru $r0.9 = $r0.8, 8   ## bblock 8, line 77-3,  t281(I24),  t279,  8(SI32)
;;								## 40
	c0    and $r0.9 = $r0.9, 255   ## bblock 8, line 77-3,  t282,  t281(I24),  255(I32)
;;								## 41
	c0    and $r0.10 = $r0.8, 255   ## bblock 8, line 77-3,  t280,  t279,  255(I32)
;;								## 42
	c0    max $r0.10 = $r0.10, $r0.9   ## bblock 8, line 77-3,  t284,  t280,  t282
;;								## 43
	c0    shru $r0.8 = $r0.8, 16   ## bblock 8, line 77-3,  t285(I16),  t279,  16(SI32)
;;								## 44
	c0    and $r0.8 = $r0.8, 255   ## bblock 8, line 77-3,  t286,  t285(I16),  255(I32)
;;								## 45
	c0    max $r0.10 = $r0.10, $r0.8   ## bblock 8, line 77-3,  t288,  t284,  t286
;;								## 46
	c0    zxtb $r0.10 = $r0.10   ## bblock 8, line 77-3,  t290(I8),  t288
;;								## 47
	c0    shl $r0.8 = $r0.10, 16   ## bblock 8, line 88-3,  t292,  t290(I8),  16(SI32)
;;								## 48
	c0    or $r0.8 = $r0.10, $r0.8   ## bblock 8, line 88-3,  t1255,  t290(I8),  t292
;;								## 49
	c0    shl $r0.10 = $r0.10, 8   ## bblock 8, line 88-3,  t291,  t290(I8),  8(SI32)
;;								## 50
	c0    or $r0.8 = $r0.8, $r0.10   ## bblock 8, line 88-3,  t293,  t1255,  t291
;;								## 51
	c0    ldw $r0.9 = 16[$r0.2]   ## bblock 8, line 76-4, t259, t389
;;								## 52
	c0    ldw $r0.10 = 20[$r0.2]   ## bblock 8, line 76-5, t239, t389
;;								## 53
	c0    shru $r0.11 = $r0.9, 8   ## bblock 8, line 77-4,  t261(I24),  t259,  8(SI32)
;;								## 54
	c0    and $r0.11 = $r0.11, 255   ## bblock 8, line 77-4,  t262,  t261(I24),  255(I32)
;;								## 55
	c0    and $r0.12 = $r0.9, 255   ## bblock 8, line 77-4,  t260,  t259,  255(I32)
;;								## 56
	c0    max $r0.12 = $r0.12, $r0.11   ## bblock 8, line 77-4,  t264,  t260,  t262
;;								## 57
	c0    shru $r0.9 = $r0.9, 16   ## bblock 8, line 77-4,  t265(I16),  t259,  16(SI32)
;;								## 58
	c0    and $r0.9 = $r0.9, 255   ## bblock 8, line 77-4,  t266,  t265(I16),  255(I32)
;;								## 59
	c0    max $r0.12 = $r0.12, $r0.9   ## bblock 8, line 77-4,  t268,  t264,  t266
;;								## 60
	c0    zxtb $r0.12 = $r0.12   ## bblock 8, line 77-4,  t270(I8),  t268
;;								## 61
	c0    shl $r0.9 = $r0.12, 16   ## bblock 8, line 88-4,  t272,  t270(I8),  16(SI32)
;;								## 62
	c0    or $r0.9 = $r0.12, $r0.9   ## bblock 8, line 88-4,  t1256,  t270(I8),  t272
;;								## 63
	c0    shl $r0.12 = $r0.12, 8   ## bblock 8, line 88-4,  t271,  t270(I8),  8(SI32)
;;								## 64
	c0    or $r0.9 = $r0.9, $r0.12   ## bblock 8, line 88-4,  t273,  t1256,  t271
;;								## 65
	c0    shru $r0.11 = $r0.10, 8   ## bblock 8, line 77-5,  t241(I24),  t239,  8(SI32)
;;								## 66
	c0    and $r0.11 = $r0.11, 255   ## bblock 8, line 77-5,  t242,  t241(I24),  255(I32)
;;								## 67
	c0    and $r0.12 = $r0.10, 255   ## bblock 8, line 77-5,  t240,  t239,  255(I32)
;;								## 68
	c0    max $r0.12 = $r0.12, $r0.11   ## bblock 8, line 77-5,  t244,  t240,  t242
;;								## 69
	c0    shru $r0.10 = $r0.10, 16   ## bblock 8, line 77-5,  t245(I16),  t239,  16(SI32)
;;								## 70
	c0    and $r0.10 = $r0.10, 255   ## bblock 8, line 77-5,  t246,  t245(I16),  255(I32)
;;								## 71
	c0    max $r0.12 = $r0.12, $r0.10   ## bblock 8, line 77-5,  t248,  t244,  t246
;;								## 72
	c0    zxtb $r0.12 = $r0.12   ## bblock 8, line 77-5,  t250(I8),  t248
;;								## 73
	c0    shl $r0.10 = $r0.12, 16   ## bblock 8, line 88-5,  t252,  t250(I8),  16(SI32)
;;								## 74
	c0    or $r0.10 = $r0.12, $r0.10   ## bblock 8, line 88-5,  t1257,  t250(I8),  t252
;;								## 75
	c0    shl $r0.12 = $r0.12, 8   ## bblock 8, line 88-5,  t251,  t250(I8),  8(SI32)
;;								## 76
	c0    or $r0.10 = $r0.10, $r0.12   ## bblock 8, line 88-5,  t253,  t1257,  t251
;;								## 77
	c0    ldw $r0.11 = 24[$r0.2]   ## bblock 8, line 76-6, t219, t389
;;								## 78
	c0    ldw $r0.12 = 28[$r0.2]   ## bblock 8, line 76-7, t199, t389
;;								## 79
	c0    shru $r0.13 = $r0.11, 8   ## bblock 8, line 77-6,  t221(I24),  t219,  8(SI32)
;;								## 80
	c0    and $r0.13 = $r0.13, 255   ## bblock 8, line 77-6,  t222,  t221(I24),  255(I32)
;;								## 81
	c0    and $r0.14 = $r0.11, 255   ## bblock 8, line 77-6,  t220,  t219,  255(I32)
;;								## 82
	c0    max $r0.14 = $r0.14, $r0.13   ## bblock 8, line 77-6,  t224,  t220,  t222
;;								## 83
	c0    shru $r0.11 = $r0.11, 16   ## bblock 8, line 77-6,  t225(I16),  t219,  16(SI32)
;;								## 84
	c0    and $r0.11 = $r0.11, 255   ## bblock 8, line 77-6,  t226,  t225(I16),  255(I32)
;;								## 85
	c0    max $r0.14 = $r0.14, $r0.11   ## bblock 8, line 77-6,  t228,  t224,  t226
;;								## 86
	c0    zxtb $r0.14 = $r0.14   ## bblock 8, line 77-6,  t230(I8),  t228
;;								## 87
	c0    shl $r0.11 = $r0.14, 16   ## bblock 8, line 88-6,  t232,  t230(I8),  16(SI32)
;;								## 88
	c0    or $r0.11 = $r0.14, $r0.11   ## bblock 8, line 88-6,  t1258,  t230(I8),  t232
;;								## 89
	c0    shl $r0.14 = $r0.14, 8   ## bblock 8, line 88-6,  t231,  t230(I8),  8(SI32)
;;								## 90
	c0    or $r0.11 = $r0.11, $r0.14   ## bblock 8, line 88-6,  t233,  t1258,  t231
;;								## 91
	c0    shru $r0.13 = $r0.12, 8   ## bblock 8, line 77-7,  t201(I24),  t199,  8(SI32)
;;								## 92
	c0    and $r0.13 = $r0.13, 255   ## bblock 8, line 77-7,  t202,  t201(I24),  255(I32)
;;								## 93
	c0    and $r0.14 = $r0.12, 255   ## bblock 8, line 77-7,  t200,  t199,  255(I32)
;;								## 94
	c0    max $r0.14 = $r0.14, $r0.13   ## bblock 8, line 77-7,  t204,  t200,  t202
;;								## 95
	c0    shru $r0.12 = $r0.12, 16   ## bblock 8, line 77-7,  t205(I16),  t199,  16(SI32)
;;								## 96
	c0    and $r0.12 = $r0.12, 255   ## bblock 8, line 77-7,  t206,  t205(I16),  255(I32)
;;								## 97
	c0    max $r0.14 = $r0.14, $r0.12   ## bblock 8, line 77-7,  t208,  t204,  t206
;;								## 98
	c0    zxtb $r0.14 = $r0.14   ## bblock 8, line 77-7,  t210(I8),  t208
;;								## 99
	c0    shl $r0.12 = $r0.14, 16   ## bblock 8, line 88-7,  t212,  t210(I8),  16(SI32)
;;								## 100
	c0    or $r0.12 = $r0.14, $r0.12   ## bblock 8, line 88-7,  t1259,  t210(I8),  t212
;;								## 101
	c0    shl $r0.14 = $r0.14, 8   ## bblock 8, line 88-7,  t211,  t210(I8),  8(SI32)
;;								## 102
	c0    or $r0.12 = $r0.12, $r0.14   ## bblock 8, line 88-7,  t213,  t1259,  t211
;;								## 103
	c0    ldw $r0.13 = 32[$r0.2]   ## bblock 8, line 76-8, t179, t389
;;								## 104
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 8, line 73-9,  t1261(I1),  t390,  0(SI32)
;;								## 105
	c0    shru $r0.14 = $r0.13, 8   ## bblock 8, line 77-8,  t181(I24),  t179,  8(SI32)
;;								## 106
	c0    and $r0.14 = $r0.14, 255   ## bblock 8, line 77-8,  t182,  t181(I24),  255(I32)
;;								## 107
	c0    and $r0.15 = $r0.13, 255   ## bblock 8, line 77-8,  t180,  t179,  255(I32)
;;								## 108
	c0    max $r0.15 = $r0.15, $r0.14   ## bblock 8, line 77-8,  t184,  t180,  t182
;;								## 109
	c0    shru $r0.13 = $r0.13, 16   ## bblock 8, line 77-8,  t185(I16),  t179,  16(SI32)
;;								## 110
	c0    and $r0.13 = $r0.13, 255   ## bblock 8, line 77-8,  t186,  t185(I16),  255(I32)
;;								## 111
	c0    max $r0.15 = $r0.15, $r0.13   ## bblock 8, line 77-8,  t188,  t184,  t186
;;								## 112
	c0    zxtb $r0.15 = $r0.15   ## bblock 8, line 77-8,  t190(I8),  t188
;;								## 113
	c0    shl $r0.13 = $r0.15, 16   ## bblock 8, line 88-8,  t192,  t190(I8),  16(SI32)
;;								## 114
	c0    or $r0.13 = $r0.15, $r0.13   ## bblock 8, line 88-8,  t1260,  t190(I8),  t192
;;								## 115
	c0    shl $r0.15 = $r0.15, 8   ## bblock 8, line 88-8,  t191,  t190(I8),  8(SI32)
;;								## 116
	c0    or $r0.13 = $r0.13, $r0.15   ## bblock 8, line 88-8,  t193,  t1260,  t191
;;								## 117
	c0    ldw.d $r0.14 = 36[$r0.2]   ## [spec] bblock 62, line 76-9, t159, t389
;;								## 118
	c0    ldw.d $r0.15 = 40[$r0.2]   ## [spec] bblock 62, line 76-10, t78, t389
;;								## 119
	c0    shru $r0.16 = $r0.14, 8   ## [spec] bblock 62, line 77-9,  t161(I24),  t159,  8(SI32)
;;								## 120
	c0    and $r0.16 = $r0.16, 255   ## [spec] bblock 62, line 77-9,  t162,  t161(I24),  255(I32)
;;								## 121
	c0    and $r0.17 = $r0.14, 255   ## [spec] bblock 62, line 77-9,  t160,  t159,  255(I32)
;;								## 122
	c0    max $r0.17 = $r0.17, $r0.16   ## [spec] bblock 62, line 77-9,  t164,  t160,  t162
;;								## 123
	c0    shru $r0.14 = $r0.14, 16   ## [spec] bblock 62, line 77-9,  t165(I16),  t159,  16(SI32)
;;								## 124
	c0    and $r0.14 = $r0.14, 255   ## [spec] bblock 62, line 77-9,  t166,  t165(I16),  255(I32)
;;								## 125
	c0    max $r0.17 = $r0.17, $r0.14   ## [spec] bblock 62, line 77-9,  t168,  t164,  t166
;;								## 126
	c0    zxtb $r0.17 = $r0.17   ## [spec] bblock 62, line 77-9,  t170(I8),  t168
;;								## 127
	c0    shl $r0.14 = $r0.17, 16   ## [spec] bblock 62, line 88-9,  t172,  t170(I8),  16(SI32)
;;								## 128
	c0    or $r0.14 = $r0.17, $r0.14   ## [spec] bblock 62, line 88-9,  t1262,  t170(I8),  t172
;;								## 129
	c0    shl $r0.17 = $r0.17, 8   ## [spec] bblock 62, line 88-9,  t171,  t170(I8),  8(SI32)
;;								## 130
	c0    or $r0.14 = $r0.14, $r0.17   ## [spec] bblock 62, line 88-9,  t173,  t1262,  t171
;;								## 131
	c0    shru $r0.16 = $r0.15, 8   ## [spec] bblock 62, line 77-10,  t121(I24),  t78,  8(SI32)
;;								## 132
	c0    and $r0.16 = $r0.16, 255   ## [spec] bblock 62, line 77-10,  t125,  t121(I24),  255(I32)
;;								## 133
	c0    and $r0.17 = $r0.15, 255   ## [spec] bblock 62, line 77-10,  t117,  t78,  255(I32)
;;								## 134
	c0    max $r0.17 = $r0.17, $r0.16   ## [spec] bblock 62, line 77-10,  t133,  t117,  t125
;;								## 135
	c0    shru $r0.15 = $r0.15, 16   ## [spec] bblock 62, line 77-10,  t137(I16),  t78,  16(SI32)
;;								## 136
	c0    and $r0.15 = $r0.15, 255   ## [spec] bblock 62, line 77-10,  t141,  t137(I16),  255(I32)
;;								## 137
	c0    max $r0.17 = $r0.17, $r0.15   ## [spec] bblock 62, line 77-10,  t149,  t133,  t141
;;								## 138
	c0    zxtb $r0.17 = $r0.17   ## [spec] bblock 62, line 77-10,  t151(I8),  t149
;;								## 139
	c0    shl $r0.15 = $r0.17, 16   ## [spec] bblock 62, line 88-10,  t153,  t151(I8),  16(SI32)
;;								## 140
	c0    or $r0.15 = $r0.17, $r0.15   ## [spec] bblock 62, line 88-10,  t1263,  t151(I8),  t153
;;								## 141
	c0    shl $r0.17 = $r0.17, 8   ## [spec] bblock 62, line 88-10,  t152,  t151(I8),  8(SI32)
;;								## 142
	c0    or $r0.15 = $r0.15, $r0.17   ## [spec] bblock 62, line 88-10,  t154,  t1263,  t152
;;								## 143
	c0    add $r0.2 = $r0.2, 44   ## [spec] bblock 62, line 0,  t389,  t389,  44(I32)
;;								## 144
	c0    add $r0.5 = $r0.5, 11   ## [spec] bblock 62, line 0,  t390,  t390,  11(I32)
;;								## 145
	c0    stw 0[$r0.4] = $r0.3   ## bblock 8, line 89, t388, t44
;;								## 146
	c0    stw 4[$r0.4] = $r0.6   ## bblock 8, line 89-1, t388, t333
;;								## 147
	c0    stw 8[$r0.4] = $r0.7   ## bblock 8, line 89-2, t388, t313
;;								## 148
	c0    stw 12[$r0.4] = $r0.8   ## bblock 8, line 89-3, t388, t293
;;								## 149
	c0    stw 16[$r0.4] = $r0.9   ## bblock 8, line 89-4, t388, t273
;;								## 150
	c0    stw 20[$r0.4] = $r0.10   ## bblock 8, line 89-5, t388, t253
;;								## 151
	c0    stw 24[$r0.4] = $r0.11   ## bblock 8, line 89-6, t388, t233
;;								## 152
	c0    stw 28[$r0.4] = $r0.12   ## bblock 8, line 89-7, t388, t213
;;								## 153
	c0    stw 32[$r0.4] = $r0.13   ## bblock 8, line 89-8, t388, t193
;;								## 154
	c0    brf $b0.0, L7?3   ## bblock 8, line 73-9,  t1261(I1)
;;								## 155
	c0    stw 36[$r0.4] = $r0.14   ## bblock 62, line 89-9, t388, t173
;;								## 156
	c0    stw 40[$r0.4] = $r0.15   ## bblock 62, line 89-10, t388, t154
;;								## 157
	c0    add $r0.4 = $r0.4, 44   ## bblock 62, line 0,  t388,  t388,  44(I32)
	      ## goto
;;
	c0    goto L6?3 ## goto
;;								## 158
.trace 5
L7?3:
	c0    add $r0.7 = $r0.20, 256   ## bblock 9, line 0,  t740,  t740,  256(I32)
;;								## 0
	c0    add $r0.6 = $r0.19, 256   ## bblock 9, line 0,  t729,  t729,  256(I32)
;;								## 1
	c0    add $r0.3 = $r0.18, 1   ## bblock 9, line 0,  t741,  t741,  1(I32)
	      ## goto
;;
	c0    goto L4?3 ## goto
;;								## 2
.trace 9
L5?3:
	c0    stw 0x10[$r0.1] = $r0.21  ## spill ## t62
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 1
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 105,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
;;								## 2
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t62
;;								## 3
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 4
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 6, line 107,  t63,  ?2.4?2auto_size(I32),  t62
;;								## 5
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
