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
.equ _?1TEMPLATEPACKET.7, 0x0
 ## Begin x264_8525.x264_pixel_sad_16x16
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:u32,$r0.4:s32,$r0.5:u32,$r0.6:s32)
x264_8525.x264_pixel_sad_16x16::
.trace 5
	c0    add $r0.1 = $r0.1, (-0x40)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t25
;;								## 1
	c0    stw 0x14[$r0.1] = $r0.57  ## spill ## t29
;;								## 2
	c0    stw 0x18[$r0.1] = $r0.58  ## spill ## t30
;;								## 3
	c0    stw 0x1c[$r0.1] = $r0.59  ## spill ## t31
;;								## 4
	c0    stw 0x20[$r0.1] = $r0.60  ## spill ## t32
;;								## 5
	c0    stw 0x24[$r0.1] = $r0.61  ## spill ## t33
;;								## 6
	c0    stw 0x28[$r0.1] = $r0.62  ## spill ## t34
;;								## 7
	c0    stw 0x2c[$r0.1] = $r0.63  ## spill ## t35
;;								## 8
	c0    add $r0.58 = $r0.3, 16   ## bblock 0, line 0,  t62,  t40,  16(I32)
;;								## 9
	c0    add $r0.59 = $r0.5, 16   ## bblock 0, line 0,  t63,  t42,  16(I32)
;;								## 10
	c0    mov $r0.60 = $r0.0   ## bblock 0, line 9,  t46,  0(SI32)
;;								## 11
	c0    mov $r0.2 = (~0xf)   ## bblock 0, line 0,  t64,  (~0xf)(I32)
;;								## 12
	c0    mov $r0.63 = $r0.6   ## t43
;;								## 13
	c0    mov $r0.62 = $r0.4   ## t41
;;								## 14
.trace 3
L0?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 1, line 11,  t75(I1),  t64,  0(SI32)
;;								## 0
	c0    brf $b0.0, L1?3   ## bblock 1, line 11,  t75(I1)
;;								## 1
	c0    mov $r0.57 = (~0xf)   ## bblock 3, line 0,  t50,  (~0xf)(I32)
;;								## 2
	c0    mov $r0.61 = $r0.2   ## t64
;;								## 3
.trace 1
L2?3:
	c0    add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 6, line 15,  t78,  t50,  t62
;;								## 0
	c0    ldbu.d $r0.2 = 0[$r0.2]   ## [spec] bblock 6, line 15, t15(I8), t78
;;								## 1
	c0    add $r0.4 = $r0.57, $r0.59   ## [spec] bblock 6, line 15,  t77,  t50,  t63
;;								## 2
	c0    ldbu.d $r0.4 = 0[$r0.4]   ## [spec] bblock 6, line 15, t11(I8), t77
;;								## 3
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 4, line 13,  t76(I1),  t50,  0(SI32)
;;								## 4
	c0    sub $r0.3 = $r0.2, $r0.4   ## [spec] bblock 6, line 15,  t16,  t15(I8),  t11(I8)
;;								## 5
	c0    brf $b0.0, L3?3   ## bblock 4, line 13,  t76(I1)
;;								## 6
.call abs, caller, arg($r0.3:s32), ret($r0.3:s32)
	c0    call $l0.0 = abs   ## bblock 6, line 15,  raddr(abs)(P32),  t16
;;								## 7
	c0    add $r0.60 = $r0.3, $r0.60   ## bblock 7, line 15,  t46,  t7,  t46
;;								## 8
	c0    add $r0.57 = $r0.57, 1   ## bblock 7, line 0,  t50,  t50,  1(I32)
	      ## goto
;;
	c0    goto L2?3 ## goto
;;								## 9
.trace 4
L3?3:
	c0    add $r0.58 = $r0.62, $r0.58   ## bblock 8, line 0,  t62,  t41,  t62
;;								## 0
	c0    add $r0.59 = $r0.63, $r0.59   ## bblock 8, line 0,  t63,  t43,  t63
;;								## 1
	c0    add $r0.2 = $r0.61, 1   ## bblock 8, line 0,  t64,  t64,  1(I32)
	      ## goto
;;
	c0    goto L0?3 ## goto
;;								## 2
.trace 6
L1?3:
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t25
;;								## 0
	c0    mov $r0.3 = $r0.60   ## t46
;;								## 1
	c0    ldw $r0.63 = 0x2c[$r0.1]  ## restore ## t35
;;								## 2
	c0    ldw $r0.62 = 0x28[$r0.1]  ## restore ## t34
;;								## 3
	c0    ldw $r0.61 = 0x24[$r0.1]  ## restore ## t33
;;								## 4
	c0    ldw $r0.60 = 0x20[$r0.1]  ## restore ## t32
;;								## 5
	c0    ldw $r0.59 = 0x1c[$r0.1]  ## restore ## t31
;;								## 6
	c0    ldw $r0.58 = 0x18[$r0.1]  ## restore ## t30
;;								## 7
	c0    ldw $r0.57 = 0x14[$r0.1]  ## restore ## t29
;;								## 8
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 2, line 20,  t26,  ?2.1?2auto_size(I32),  t25
;;								## 9
.endp
.section .bss
.section .data
.equ ?2.1?2scratch.0, 0x0
.equ ?2.1?2ras_p, 0x10
.equ ?2.1?2spill_p, 0x14
.section .data
.section .text
.equ ?2.1?2auto_size, 0x40
 ## End x264_8525.x264_pixel_sad_16x16
.equ _?1TEMPLATEPACKET.9, 0x0
 ## Begin x264_8525.x264_pixel_sad_x4_16x16
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32,$r0.7:u32,$r0.8:s32,$r0.9:u32)
x264_8525.x264_pixel_sad_x4_16x16::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x40)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t24
;;								## 1
	c0    stw 0x14[$r0.1] = $r0.7  ## spill ## t46
;;								## 2
	c0    stw 0x18[$r0.1] = $r0.6  ## spill ## t45
;;								## 3
	c0    stw 0x1c[$r0.1] = $r0.5  ## spill ## t44
;;								## 4
	c0    stw 0x20[$r0.1] = $r0.9  ## spill ## t48
;;								## 5
	c0    stw 0x24[$r0.1] = $r0.8  ## spill ## t47
;;								## 6
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t42
;;								## 7
	c0    mov $r0.6 = $r0.8   ## t47
;;								## 8
	c0    mov $r0.5 = $r0.4   ## t2
;;								## 9
	c0    mov $r0.4 = 16   ## 16(SI32)
;;								## 10
.call x264_8525.x264_pixel_sad_16x16, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = x264_8525.x264_pixel_sad_16x16   ## bblock 0, line 26,  raddr(x264_8525.x264_pixel_sad_16x16)(P32),  t42,  16(SI32),  t2,  t47
;;								## 11
	c0    ldw $r0.9 = 0x20[$r0.1]  ## restore ## t48
;;								## 12
	c0    ldw $r0.5 = 0x1c[$r0.1]  ## restore ## t44
;;								## 13
	c0    ldw $r0.6 = 0x24[$r0.1]  ## restore ## t47
;;								## 14
	c0    stw 0[$r0.9] = $r0.3   ## bblock 1, line 26, t48, t0
;;								## 15
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t42
;;								## 16
	c0    mov $r0.4 = 16   ## 16(SI32)
;;								## 17
.call x264_8525.x264_pixel_sad_16x16, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = x264_8525.x264_pixel_sad_16x16   ## bblock 1, line 27,  raddr(x264_8525.x264_pixel_sad_16x16)(P32),  t42,  16(SI32),  t44,  t47
;;								## 18
	c0    ldw $r0.9 = 0x20[$r0.1]  ## restore ## t48
;;								## 19
	c0    ldw $r0.5 = 0x18[$r0.1]  ## restore ## t45
;;								## 20
	c0    ldw $r0.6 = 0x24[$r0.1]  ## restore ## t47
;;								## 21
	c0    stw 4[$r0.9] = $r0.3   ## bblock 2, line 27, t48, t6
;;								## 22
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t42
;;								## 23
	c0    mov $r0.4 = 16   ## 16(SI32)
;;								## 24
.call x264_8525.x264_pixel_sad_16x16, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = x264_8525.x264_pixel_sad_16x16   ## bblock 2, line 28,  raddr(x264_8525.x264_pixel_sad_16x16)(P32),  t42,  16(SI32),  t45,  t47
;;								## 25
	c0    ldw $r0.9 = 0x20[$r0.1]  ## restore ## t48
;;								## 26
	c0    ldw $r0.5 = 0x14[$r0.1]  ## restore ## t46
;;								## 27
	c0    ldw $r0.6 = 0x24[$r0.1]  ## restore ## t47
;;								## 28
	c0    stw 8[$r0.9] = $r0.3   ## bblock 3, line 28, t48, t12
;;								## 29
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t42
;;								## 30
	c0    mov $r0.4 = 16   ## 16(SI32)
;;								## 31
.call x264_8525.x264_pixel_sad_16x16, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = x264_8525.x264_pixel_sad_16x16   ## bblock 3, line 29,  raddr(x264_8525.x264_pixel_sad_16x16)(P32),  t42,  16(SI32),  t46,  t47
;;								## 32
	c0    ldw $r0.9 = 0x20[$r0.1]  ## restore ## t48
;;								## 33
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t24
;;								## 34
	c0    stw 12[$r0.9] = $r0.3   ## bblock 4, line 29, t48, t18
;;								## 35
.return ret()
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 4, line 30,  t25,  ?2.2?2auto_size(I32),  t24
;;								## 36
.endp
.section .bss
.section .data
.equ ?2.2?2scratch.0, 0x0
.equ ?2.2?2ras_p, 0x10
.equ ?2.2?2spill_p, 0x14
.section .data
.section .text
.equ ?2.2?2auto_size, 0x40
 ## End x264_8525.x264_pixel_sad_x4_16x16
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
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 75,  t1,  ?2.3?2auto_size(I32),  t0
;;								## 2
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.3?2auto_size, 0x0
 ## End NOP
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg()
main::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x40)
;;								## 0
	c0    stw 0x30[$r0.1] = $l0.0  ## spill ## t43
;;								## 1
	c0    add $r0.9 = $r0.1, 0x10   ## bblock 0, line 79,  t0,  t44,  offset(scores1?1.24)=0x10(P32)
;;								## 2
	c0    stw 0x34[$r0.1] = $r0.9  ## spill ## t0
;;								## 3
	c0    add $r0.2 = $r0.1, 0x20   ## bblock 0, line 80,  t1,  t44,  offset(scores2?1.24)=0x20(P32)
;;								## 4
	c0    stw 0x38[$r0.1] = $r0.2  ## spill ## t1
;;								## 5
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 83,  raddr(NOP)(P32)
;;								## 6
	c0    ldw $r0.9 = 0x34[$r0.1]  ## restore ## t0
;;								## 7
	c0    mov $r0.8 = 16   ## 16(SI32)
;;								## 8
	c0    mov $r0.7 = (pix3 + 0)   ## addr(pix3?1.0)(P32)
;;								## 9
	c0    mov $r0.6 = (pix2 + 0)   ## addr(pix2?1.0)(P32)
;;								## 10
	c0    mov $r0.5 = (pix1 + 0)   ## addr(pix1?1.0)(P32)
;;								## 11
	c0    mov $r0.4 = (pix0 + 0)   ## addr(pix0?1.0)(P32)
;;								## 12
	c0    mov $r0.3 = (fenc1 + 0)   ## addr(fenc1?1.0)(P32)
;;								## 13
.call x264_8525.x264_pixel_sad_x4_16x16, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32,$r0.7:u32,$r0.8:s32,$r0.9:u32), ret()
	c0    call $l0.0 = x264_8525.x264_pixel_sad_x4_16x16   ## bblock 1, line 86,  raddr(x264_8525.x264_pixel_sad_x4_16x16)(P32),  addr(fenc1?1.0)(P32),  addr(pix0?1.0)(P32),  addr(pix1?1.0)(P32),  addr(pix2?1.0)(P32),  addr(pix3?1.0)(P32),  16(SI32),  t0
;;								## 14
	c0    ldw $r0.9 = 0x34[$r0.1]  ## restore ## t0
;;								## 15
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 16
	c0    ldw $r0.9 = 0[$r0.9]   ## bblock 2, line 89, t62, t0
	      xnop 1
;;								## 18
	c0    cmpne $b0.0 = $r0.9, 1920   ## bblock 2, line 89,  t71(I1),  t62,  1920(SI32)
;;								## 19
	c0    brf $b0.0, L4?3   ## bblock 2, line 89,  t71(I1)
;;								## 20
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 15, line 90,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
;;								## 21
	c0    ldw $l0.0 = 0x30[$r0.1]  ## restore ## t43
;;								## 22
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 23
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 16, line 91,  t44,  ?2.4?2auto_size(I32),  t43
;;								## 24
.trace 2
L4?3:
	c0    ldw $r0.9 = 0x34[$r0.1]  ## restore ## t0
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 1
	c0    ldw $r0.9 = 4[$r0.9]   ## bblock 14, line 89-1, t19, t0
	      xnop 1
;;								## 3
	c0    cmpne $b0.0 = $r0.9, 1920   ## bblock 14, line 89-1,  t74(I1),  t19,  1920(SI32)
;;								## 4
	c0    brf $b0.0, L6?3   ## bblock 14, line 89-1,  t74(I1)
	      ## goto
;;
	c0    goto L5?3 ## goto
;;								## 5
.trace 3
L6?3:
	c0    ldw $r0.9 = 0x34[$r0.1]  ## restore ## t0
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 1
	c0    ldw $r0.9 = 8[$r0.9]   ## bblock 34, line 89-2, t64, t0
	      xnop 1
;;								## 3
	c0    cmpne $b0.0 = $r0.9, 1920   ## bblock 34, line 89-2,  t78(I1),  t64,  1920(SI32)
;;								## 4
	c0    brf $b0.0, L7?3   ## bblock 34, line 89-2,  t78(I1)
	      ## goto
;;
	c0    goto L5?3 ## goto
;;								## 5
.trace 4
L7?3:
	c0    ldw $r0.9 = 0x34[$r0.1]  ## restore ## t0
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 1
	c0    ldw $r0.9 = 12[$r0.9]   ## bblock 29, line 89-3, t66, t0
	      xnop 1
;;								## 3
	c0    cmpne $b0.0 = $r0.9, 1920   ## bblock 29, line 89-3,  t75(I1),  t66,  1920(SI32)
;;								## 4
	c0    brf $b0.0, L8?3   ## bblock 29, line 89-3,  t75(I1)
	      ## goto
;;
	c0    goto L5?3 ## goto
;;								## 5
.trace 5
L8?3:
	c0    ldw $r0.9 = 0x38[$r0.1]  ## restore ## t1
;;								## 0
	c0    mov $r0.8 = 16   ## 16(SI32)
;;								## 1
	c0    mov $r0.7 = (pix7 + 0)   ## addr(pix7?1.0)(P32)
;;								## 2
	c0    mov $r0.6 = (pix6 + 0)   ## addr(pix6?1.0)(P32)
;;								## 3
	c0    mov $r0.5 = (pix5 + 0)   ## addr(pix5?1.0)(P32)
;;								## 4
	c0    mov $r0.4 = (pix4 + 0)   ## addr(pix4?1.0)(P32)
;;								## 5
	c0    mov $r0.3 = (fenc2 + 0)   ## addr(fenc2?1.0)(P32)
;;								## 6
.call x264_8525.x264_pixel_sad_x4_16x16, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32,$r0.7:u32,$r0.8:s32,$r0.9:u32), ret()
	c0    call $l0.0 = x264_8525.x264_pixel_sad_x4_16x16   ## bblock 24, line 94,  raddr(x264_8525.x264_pixel_sad_x4_16x16)(P32),  addr(fenc2?1.0)(P32),  addr(pix4?1.0)(P32),  addr(pix5?1.0)(P32),  addr(pix6?1.0)(P32),  addr(pix7?1.0)(P32),  16(SI32),  t1
;;								## 7
	c0    ldw $r0.2 = 0x38[$r0.1]  ## restore ## t1
;;								## 8
	c0    mov $r0.3 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
;;								## 9
	c0    ldw $r0.2 = 0[$r0.2]   ## bblock 5, line 97, t69, t1
	      xnop 1
;;								## 11
	c0    cmpne $b0.0 = $r0.2, 1920   ## bblock 5, line 97,  t72(I1),  t69,  1920(SI32)
;;								## 12
	c0    brf $b0.0, L9?3   ## bblock 5, line 97,  t72(I1)
;;								## 13
L10?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 11, line 98,  raddr(puts)(P32),  addr(_?1STRINGVAR.2)(P32)
;;								## 14
	c0    ldw $l0.0 = 0x30[$r0.1]  ## restore ## t43
;;								## 15
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 16
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 12, line 99,  t44,  ?2.4?2auto_size(I32),  t43
;;								## 17
.trace 6
L9?3:
	c0    ldw $r0.2 = 0x38[$r0.1]  ## restore ## t1
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
;;								## 1
	c0    ldw $r0.2 = 4[$r0.2]   ## bblock 10, line 97-1, t38, t1
	      xnop 1
;;								## 3
	c0    cmpne $b0.0 = $r0.2, 1920   ## bblock 10, line 97-1,  t73(I1),  t38,  1920(SI32)
;;								## 4
	c0    brf $b0.0, L11?3   ## bblock 10, line 97-1,  t73(I1)
	      ## goto
;;
	c0    goto L10?3 ## goto
;;								## 5
.trace 7
L11?3:
	c0    ldw $r0.2 = 0x38[$r0.1]  ## restore ## t1
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
;;								## 1
	c0    ldw $r0.2 = 8[$r0.2]   ## bblock 30, line 97-2, t57, t1
	      xnop 1
;;								## 3
	c0    cmpne $b0.0 = $r0.2, 1920   ## bblock 30, line 97-2,  t76(I1),  t57,  1920(SI32)
;;								## 4
	c0    brf $b0.0, L12?3   ## bblock 30, line 97-2,  t76(I1)
	      ## goto
;;
	c0    goto L10?3 ## goto
;;								## 5
.trace 8
L12?3:
	c0    ldw $r0.2 = 0x38[$r0.1]  ## restore ## t1
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
;;								## 1
	c0    ldw $r0.2 = 12[$r0.2]   ## bblock 31, line 97-3, t61, t1
	      xnop 1
;;								## 3
	c0    cmpne $b0.0 = $r0.2, 1920   ## bblock 31, line 97-3,  t77(I1),  t61,  1920(SI32)
;;								## 4
	c0    brf $b0.0, L13?3   ## bblock 31, line 97-3,  t77(I1)
	      ## goto
;;
	c0    goto L10?3 ## goto
;;								## 5
.trace 9
L13?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.3 + 0)   ## addr(_?1STRINGVAR.3)(P32)
;;								## 0
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 32, line 102,  raddr(puts)(P32),  addr(_?1STRINGVAR.3)(P32)
;;								## 1
	c0    ldw $l0.0 = 0x30[$r0.1]  ## restore ## t43
;;								## 2
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 8, line 104,  t44,  ?2.4?2auto_size(I32),  t43
;;								## 4
.endp
.section .bss
.section .data
_?1STRINGPACKET.3:
    .data1 120
    .data1 50
    .data1 54
    .data1 52
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
.skip 1
_?1STRINGPACKET.1:
    .data1 120
    .data1 50
    .data1 54
    .data1 52
    .data1 32
    .data1 84
    .data1 101
    .data1 115
    .data1 116
    .data1 32
    .data1 70
    .data1 97
    .data1 105
    .data1 108
    .data1 101
    .data1 100
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.2:
    .data1 120
    .data1 50
    .data1 54
    .data1 52
    .data1 32
    .data1 84
    .data1 101
    .data1 115
    .data1 116
    .data1 32
    .data1 70
    .data1 97
    .data1 105
    .data1 108
    .data1 101
    .data1 100
    .data1 10
    .data1 0
.equ ?2.4?2scratch.0, 0x0
.equ _?1PACKET.4, 0x10
.equ _?1PACKET.5, 0x20
.equ ?2.4?2ras_p, 0x30
.equ ?2.4?2spill_p, 0x34
.section .data
.section .text
.equ ?2.4?2auto_size, 0x40
 ## End main
.section .bss
.section .data
.skip 2
fenc1::
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 0
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
fenc2::
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
    .data1 15
    .data1 14
    .data1 13
    .data1 12
    .data1 11
    .data1 10
    .data1 9
    .data1 8
    .data1 7
    .data1 6
    .data1 5
    .data1 4
    .data1 3
    .data1 2
    .data1 1
    .data1 0
.section .data
.comm pix7, 0x100, 4
.comm pix6, 0x100, 4
.comm pix5, 0x100, 4
.comm pix4, 0x100, 4
.comm pix3, 0x100, 4
.comm pix2, 0x100, 4
.comm pix1, 0x100, 4
.comm pix0, 0x100, 4
.section .text
.import NOP
.type NOP,@function
.import x264_8525.x264_pixel_sad_x4_16x16
.type x264_8525.x264_pixel_sad_x4_16x16,@function
.import x264_8525.x264_pixel_sad_16x16
.type x264_8525.x264_pixel_sad_16x16,@function
.import puts
.type puts,@function
.import abs
.type abs,@function
