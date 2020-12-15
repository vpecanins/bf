/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/8_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

/********************************************/
/*         SYSTEM HEADER                    */
/********************************************/

extern int sim_mem_probe(volatile unsigned int);
extern unsigned int sim_mem_access32(volatile unsigned int);
extern unsigned short sim_mem_access16(volatile unsigned int);
extern unsigned char sim_mem_access8(volatile unsigned int);
extern unsigned long long sim_cycle_counter;
extern unsigned long long sim_stall_counter;
extern unsigned long long sim_branch_stall;
extern unsigned long long sim_bundle_index[];
extern unsigned long long sim_oper_counter;
extern unsigned long long sim_bnt_counter;
extern unsigned long long sim_btc_counter;
extern unsigned long long sim_btu_counter;
extern unsigned long long sim_nop_counter;
extern unsigned int mem_trace_ld(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_st(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_pf(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_lds(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_sts(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_pfs(unsigned int, unsigned int, unsigned int);
extern void sim_ta_init(int);
/*         TRACING HANDLES                */
#define __GOTO(x) /**/
#define __CALL(x) /**/
#define __ENTRY(x) /**/
#define __RETURN(x) /**/
#define __BRANCH(x) /**/
#define __BRANCHF(x) /**/
#define __LABEL(x) /**/
#define __INC_STALL_CNT() sim_stall_counter += sim_branch_stall
#define __INC_BNT_CNT() sim_bnt_counter++
#define __INC_BTC_CNT() sim_btc_counter++
#define __INC_BTU_CNT() sim_btu_counter++
#define __INC_NOP_CNT(n) sim_nop_counter += (n)
#define __INC_BUNDLE_CNT(index) sim_bundle_index[index]++
#define __ADD_CYCLES(cycles)  sim_cycle_counter += (cycles)

typedef struct
{
  char *name;
  int length;
  int init;
  int offset;
  int linesize;
  int rta;
} sim_fileinfo_t;

extern int sim_init_fileinfo(sim_fileinfo_t *);
extern void sim_icache_fetch(int, int);
extern void sim_gprof_enter(int *, char *f);
extern void sim_gprof_start(int *);
extern void sim_gprof_stop(int *);
extern void sim_gprof_exit(int *);
/***********************************************/
/*         MACHINE MODEL HEADER                */
/***********************************************/

#define __UINT8(s)  ((s) & 0xff)
#define __INT8(s)   (((int) ((s) << 24)) >> 24)
#define __UINT16(s) ((s) & 0xffff)
#define __INT16(s)  (((int) ((s) << 16)) >> 16)
#define __UINT32(s) ((unsigned int) (s))
#define __INT32(s)  ((int) (s))


 		 /*  MEMORY MACROS */

#define __ADDR8(a)  ((a) ^ 0x3)
#define __ADDR16(a) ((a) ^ 0x2)
#define __ADDR32(a) (a)
#define __MEM8(a) (*((volatile unsigned char  *)(__ADDR8(a))))
#define __MEM16(a) (*((volatile unsigned short *)(__ADDR16(a))))
#define __MEM32(a) (*((volatile unsigned int *)(__ADDR32(a))))
#define __MEMSPEC8(a) sim_mem_access8(__ADDR8(a))
#define __MEMSPEC16(a) sim_mem_access16(__ADDR16(a))
#define __MEMSPEC32(a) sim_mem_access32(__ADDR32(a))
#define __LDBs(t,s1) t = __INT8(__MEMSPEC8(s1))
#define __LDB(t,s1) t = __INT8(__MEM8(s1))
#define __LDBUs(t,s1) t = __UINT8(__MEMSPEC8(s1))
#define __LDBU(t,s1) t = __UINT8(__MEM8(s1))
#define __LDHs(t,s1) t = __INT16(__MEMSPEC16(s1))
#define __LDH(t,s1) t = __INT16(__MEM16(s1))
#define __LDHUs(t,s1) t = __UINT16(__MEMSPEC16(s1))
#define __LDHU(t,s1) t = __UINT16(__MEM16(s1))
#define __LDWs(t,s1) t = __INT32(__MEMSPEC32(s1))
#define __LDW(t,s1) t = __INT32(__MEM32(s1))
#define __STB(t,s1) __MEM8(t) = __UINT8(s1)
#define __STH(t,s1) __MEM16(t) = __UINT16(s1)
#define __STW(t,s1) __MEM32(t) = __UINT32(s1)


 		 /*  INSTRUCTION MACROS */

#define __MULL(t,s1,s2) t = (s1) * __INT16(s2)
#define __MULLU(t,s1,s2) t = (s1) * __UINT16(s2)
#define __MULH(t,s1,s2) t = (s1) * __INT16((s2) >> 16)
#define __MULHU(t,s1,s2) t = (s1) * __UINT16((s2) >> 16)
#define __MULHS(t,s1,s2) t = ((s1) * __UINT16((s2) >> 16)) << 16
#define __MULLL(t,s1,s2)  t = __INT16(s1) * __INT16(s2)
#define __MULLLU(t,s1,s2) t = __UINT16(s1) * __UINT16(s2)
#define __MULLH(t,s1,s2)  t = __INT16(s1) * __INT16((s2) >> 16)
#define __MULLHU(t,s1,s2) t = __UINT16(s1) * __UINT16((s2) >> 16)
#define __MULHH(t,s1,s2)  t = __INT16((s1) >> 16) * __INT16((s2) >> 16)
#define __MULHHU(t,s1,s2) t = __UINT16((s1) >> 16) * __UINT16((s2) >> 16)
#define __ADD(t,s1,s2) t = (s1) + (s2)
#define __AND(t,s1,s2) t = (s1) & (s2)
#define __ANDC(t,s1,s2) t = ~(s1) & (s2)
#define __ANDL(t,s1,s2) t = ((((s1) == 0) | ((s2) == 0)) ? 0 : 1)
#define __CMPEQ(t,s1,s2) t = ((s1) == (s2))
#define __CMPGE(t,s1,s2) t = ((int) (s1) >= (int) (s2))
#define __CMPGEU(t,s1,s2) t = ((unsigned int) (s1) >= (unsigned int) (s2))
#define __CMPGT(t,s1,s2) t = ((int) (s1) > (int) (s2))
#define __CMPGTU(t,s1,s2) t = ((unsigned int) (s1) > (unsigned int) (s2))
#define __CMPLE(t,s1,s2) t = ((int) (s1) <= (int) (s2))
#define __CMPLEU(t,s1,s2) t = ((unsigned int) (s1) <= (unsigned int) (s2))
#define __CMPLT(t,s1,s2) t = ((int) (s1) < (int) (s2))
#define __CMPLTU(t,s1,s2) t = ((unsigned int) (s1) < (unsigned int) (s2))
#define __CMPNE(t,s1,s2) t = ( (s1) !=  (s2))
#define __MAX(t,s1,s2) t = ((int) (s1) > (int) (s2)) ? (s1) : (s2)
#define __MAXU(t,s1,s2) t = ((unsigned int) (s1) > (unsigned int) (s2)) ? (s1) : (s2)
#define __MIN(t,s1,s2) t = ((int) (s1) < (int) (s2)) ? (s1) : (s2)
#define __MINU(t,s1,s2) t = ((unsigned int) (s1) < (unsigned int) (s2)) ? (s1) : (s2)
#define __MFB(t,s1) t = s1
#define __MFL(t,s1) t = s1
#define __MOV(t,s1) t = s1
#define __MTL(t,s1) t = s1
#define __MTB(t,s1) t = ((s1) == 0) ? 0 : 1
#define __MTBINV(t,s1) t = ((s1) == 0) ? 1 : 0
#define __MUL(t,s1,s2) t = (s1) * (s2)
#define __NANDL(t,s1,s2) t = (((s1) == 0) | ((s2) == 0)) ? 1 : 0
#define __NOP()
#define __NORL(t,s1,s2) t = (((s1) == 0) & ((s2) == 0)) ? 1 : 0
#define __ORL(t,s1,s2) t = (((s1) == 0) & ((s2) == 0)) ? 0 : 1
#define __OR(t,s1,s2) t = (s1) | (s2)
#define __ORC(t,s1,s2) t = (~(s1)) | (s2)
#define __PFT(s1) (s1)
#define __SBIT(t,s1,s2) t = (s1) | ((unsigned int) 1 << (s2))
#define __SBITF(t,s1,s2) t = (s1) & ~((unsigned int) 1 << (s2))
#define __SH1ADD(t,s1,s2) t = ((s1) << 1) + (s2)
#define __SH2ADD(t,s1,s2) t = ((s1) << 2) + (s2)
#define __SH3ADD(t,s1,s2) t = ((s1) << 3) + (s2)
#define __SH4ADD(t,s1,s2) t = ((s1) << 4) + (s2)
#define __SHL(t,s1,s2) t = ((int) (s1)) << (s2)
#define __SHR(t,s1,s2) t = ((int) (s1)) >> (s2)
#define __SHRU(t,s1,s2) t = ((unsigned int) (s1)) >> (s2)
#define __SLCT(t,s1,s2,s3) t = (unsigned int) (((s1) != 0) ? (s2) : (s3))
#define __SLCTF(t,s1,s2,s3) t = (unsigned int) (((s1) == 0) ? (s2) : (s3))
#define __SUB(t,s1,s2) t = (s1) - (s2)
#define __SXTB(t,s1) t = (unsigned int) (((signed int) ((s1) << 24)) >> 24)
#define __SXTH(t,s1) t = (unsigned int) (((signed int) ((s1) << 16)) >> 16)
#define __TBIT(t,s1,s2) t = ((s1) & ((unsigned int) 1 << (s2))) ? 1 : 0
#define __TBITF(t,s1,s2) t = ((s1) & ((unsigned int) 1 << (s2))) ? 0 : 1
#define __XNOP(s1)
#define __XOR(t,s1,s2) t = (s1) ^ (s2)
#define __ZXTB(t,s1) t = ((s1) & 0xff)
#define __ZXTH(t,s1) t = ((s1) & 0xffff)
#define __ADDCG(t,cout,s1,s2,cin) {\
    t = (s1) + (s2) + ((cin) & 0x1);\
    cout =   ((cin) & 0x1)\
           ? ((unsigned int) t <= (unsigned int) (s1))\
           : ((unsigned int) t <  (unsigned int) (s1));\
}
#define __DIVS(t,cout,s1,s2,cin) {\
    unsigned int tmp = ((s1) << 1) | (cin);\
    cout = (unsigned int) (s1) >> 31;\
    t = cout ? tmp + (s2) : tmp - (s2);\
}
static sim_fileinfo_t t_thisfile;
extern void sim_asm_op0(int, ...);
extern unsigned int sim_asm_op1(int, ...);
typedef struct { unsigned int n0,n1; } sim_asm2_t;
extern sim_asm2_t sim_asm_op2(int, ...);
typedef struct { unsigned int n0,n1,n2; } sim_asm3_t;
extern sim_asm3_t sim_asm_op3(int, ...);
typedef struct { unsigned int n0,n1,n2,n3; } sim_asm4_t;
extern sim_asm4_t sim_asm_op4(int, ...);

/*********************************
            BSS SYMBOLS
*********************************/

unsigned int strbuf[3];
unsigned int conv7_result[4096];
unsigned int conv7_image[4096];

/*********************************
            ENTRY SYMBOLS
*********************************/

extern unsigned int max( unsigned int, unsigned int );
extern unsigned int min( unsigned int, unsigned int );
extern unsigned int NOP(  );
extern unsigned int __vex_main(  );
extern  puts(  );

/*********************************
            DATA SYMBOLS
*********************************/

static unsigned int _X1STRINGPACKETX1[7]; 
unsigned int filter7x7[49]; 
static unsigned int _X1STRINGPACKETX1[7] = { 
	0x436F6E76,
	0x6F6C7574,
	0x696F6E20,
	0x3778373A,
	0x20737563,
	0x63657373,
	0x0A000000
}; 

unsigned int filter7x7[49] = { 
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020
}; 


/*********************************
            TEXT
*********************************/
extern unsigned int sim_create_stack(unsigned int, unsigned int);
extern void sim_check_stack(unsigned int, unsigned int);
extern void sim_bad_label(int);
unsigned int reg_b0_0;
unsigned int reg_b0_1;
unsigned int reg_b0_2;
unsigned int reg_b0_3;
unsigned int reg_b0_4;
unsigned int reg_b0_5;
unsigned int reg_b0_6;
unsigned int reg_b0_7;
unsigned int reg_b0_8;
unsigned int reg_b0_9;
unsigned int reg_b0_10;
unsigned int reg_b0_11;
unsigned int reg_b0_12;
unsigned int reg_b0_13;
unsigned int reg_b0_14;
unsigned int reg_b0_15;
unsigned int reg_b1_0;
unsigned int reg_b1_1;
unsigned int reg_b1_2;
unsigned int reg_b1_3;
unsigned int reg_b1_4;
unsigned int reg_b1_5;
unsigned int reg_b1_6;
unsigned int reg_b1_7;
unsigned int reg_b1_8;
unsigned int reg_b1_9;
unsigned int reg_b1_10;
unsigned int reg_b1_11;
unsigned int reg_b1_12;
unsigned int reg_b1_13;
unsigned int reg_b1_14;
unsigned int reg_b1_15;
unsigned int reg_b2_0;
unsigned int reg_b2_1;
unsigned int reg_b2_2;
unsigned int reg_b2_3;
unsigned int reg_b2_4;
unsigned int reg_b2_5;
unsigned int reg_b2_6;
unsigned int reg_b2_7;
unsigned int reg_b2_8;
unsigned int reg_b2_9;
unsigned int reg_b2_10;
unsigned int reg_b2_11;
unsigned int reg_b2_12;
unsigned int reg_b2_13;
unsigned int reg_b2_14;
unsigned int reg_b2_15;
unsigned int reg_b3_0;
unsigned int reg_b3_1;
unsigned int reg_b3_2;
unsigned int reg_b3_3;
unsigned int reg_b3_4;
unsigned int reg_b3_5;
unsigned int reg_b3_6;
unsigned int reg_b3_7;
unsigned int reg_b3_8;
unsigned int reg_b3_9;
unsigned int reg_b3_10;
unsigned int reg_b3_11;
unsigned int reg_b3_12;
unsigned int reg_b3_13;
unsigned int reg_b3_14;
unsigned int reg_b3_15;
unsigned int reg_l0_0;
unsigned int reg_r0_0;
unsigned int reg_r0_1;
unsigned int reg_r0_2;
unsigned int reg_r0_3;
unsigned int reg_r0_4;
unsigned int reg_r0_5;
unsigned int reg_r0_6;
unsigned int reg_r0_7;
unsigned int reg_r0_8;
unsigned int reg_r0_9;
unsigned int reg_r0_10;
unsigned int reg_r0_11;
unsigned int reg_r0_12;
unsigned int reg_r0_13;
unsigned int reg_r0_14;
unsigned int reg_r0_15;
unsigned int reg_r0_16;
unsigned int reg_r0_17;
unsigned int reg_r0_18;
unsigned int reg_r0_19;
unsigned int reg_r0_20;
unsigned int reg_r0_21;
unsigned int reg_r0_22;
unsigned int reg_r0_23;
unsigned int reg_r0_24;
unsigned int reg_r0_25;
unsigned int reg_r0_26;
unsigned int reg_r0_27;
unsigned int reg_r0_28;
unsigned int reg_r0_29;
unsigned int reg_r0_30;
unsigned int reg_r0_31;
unsigned int reg_r0_32;
unsigned int reg_r0_33;
unsigned int reg_r0_34;
unsigned int reg_r0_35;
unsigned int reg_r0_36;
unsigned int reg_r0_37;
unsigned int reg_r0_38;
unsigned int reg_r0_39;
unsigned int reg_r0_40;
unsigned int reg_r0_41;
unsigned int reg_r0_42;
unsigned int reg_r0_43;
unsigned int reg_r0_44;
unsigned int reg_r0_45;
unsigned int reg_r0_46;
unsigned int reg_r0_47;
unsigned int reg_r0_48;
unsigned int reg_r0_49;
unsigned int reg_r0_50;
unsigned int reg_r0_51;
unsigned int reg_r0_52;
unsigned int reg_r0_53;
unsigned int reg_r0_54;
unsigned int reg_r0_55;
unsigned int reg_r0_56;
unsigned int reg_r0_57;
unsigned int reg_r0_58;
unsigned int reg_r0_59;
unsigned int reg_r0_60;
unsigned int reg_r0_61;
unsigned int reg_r0_62;
unsigned int reg_r0_63;
unsigned int reg_r0_64;
unsigned int reg_r0_65;
unsigned int reg_r0_66;
unsigned int reg_r0_67;
unsigned int reg_r0_68;
unsigned int reg_r0_69;
unsigned int reg_r0_70;
unsigned int reg_r0_71;
unsigned int reg_r0_72;
unsigned int reg_r0_73;
unsigned int reg_r0_74;
unsigned int reg_r0_75;
unsigned int reg_r0_76;
unsigned int reg_r0_77;
unsigned int reg_r0_78;
unsigned int reg_r0_79;
unsigned int reg_r0_80;
unsigned int reg_r0_81;
unsigned int reg_r0_82;
unsigned int reg_r0_83;
unsigned int reg_r0_84;
unsigned int reg_r0_85;
unsigned int reg_r0_86;
unsigned int reg_r0_87;
unsigned int reg_r0_88;
unsigned int reg_r0_89;
unsigned int reg_r0_90;
unsigned int reg_r0_91;
unsigned int reg_r0_92;
unsigned int reg_r0_93;
unsigned int reg_r0_94;
unsigned int reg_r0_95;
unsigned int reg_r0_96;
unsigned int reg_r0_97;
unsigned int reg_r0_98;
unsigned int reg_r0_99;
unsigned int reg_r0_100;
unsigned int reg_r0_101;
unsigned int reg_r0_102;
unsigned int reg_r0_103;
unsigned int reg_r0_104;
unsigned int reg_r0_105;
unsigned int reg_r0_106;
unsigned int reg_r0_107;
unsigned int reg_r0_108;
unsigned int reg_r0_109;
unsigned int reg_r0_110;
unsigned int reg_r0_111;
unsigned int reg_r0_112;
unsigned int reg_r0_113;
unsigned int reg_r0_114;
unsigned int reg_r0_115;
unsigned int reg_r0_116;
unsigned int reg_r0_117;
unsigned int reg_r0_118;
unsigned int reg_r0_119;
unsigned int reg_r0_120;
unsigned int reg_r0_121;
unsigned int reg_r0_122;
unsigned int reg_r0_123;
unsigned int reg_r0_124;
unsigned int reg_r0_125;
unsigned int reg_r0_126;
unsigned int reg_r0_127;
unsigned int reg_r1_0;
unsigned int reg_r1_1;
unsigned int reg_r1_2;
unsigned int reg_r1_3;
unsigned int reg_r1_4;
unsigned int reg_r1_5;
unsigned int reg_r1_6;
unsigned int reg_r1_7;
unsigned int reg_r1_8;
unsigned int reg_r1_9;
unsigned int reg_r1_10;
unsigned int reg_r1_11;
unsigned int reg_r1_12;
unsigned int reg_r1_13;
unsigned int reg_r1_14;
unsigned int reg_r1_15;
unsigned int reg_r1_16;
unsigned int reg_r1_17;
unsigned int reg_r1_18;
unsigned int reg_r1_19;
unsigned int reg_r1_20;
unsigned int reg_r1_21;
unsigned int reg_r1_22;
unsigned int reg_r1_23;
unsigned int reg_r1_24;
unsigned int reg_r1_25;
unsigned int reg_r1_26;
unsigned int reg_r1_27;
unsigned int reg_r1_28;
unsigned int reg_r1_29;
unsigned int reg_r1_30;
unsigned int reg_r1_31;
unsigned int reg_r1_32;
unsigned int reg_r1_33;
unsigned int reg_r1_34;
unsigned int reg_r1_35;
unsigned int reg_r1_36;
unsigned int reg_r1_37;
unsigned int reg_r1_38;
unsigned int reg_r1_39;
unsigned int reg_r1_40;
unsigned int reg_r1_41;
unsigned int reg_r1_42;
unsigned int reg_r1_43;
unsigned int reg_r1_44;
unsigned int reg_r1_45;
unsigned int reg_r1_46;
unsigned int reg_r1_47;
unsigned int reg_r1_48;
unsigned int reg_r1_49;
unsigned int reg_r1_50;
unsigned int reg_r1_51;
unsigned int reg_r1_52;
unsigned int reg_r1_53;
unsigned int reg_r1_54;
unsigned int reg_r1_55;
unsigned int reg_r1_56;
unsigned int reg_r1_57;
unsigned int reg_r1_58;
unsigned int reg_r1_59;
unsigned int reg_r1_60;
unsigned int reg_r1_61;
unsigned int reg_r1_62;
unsigned int reg_r1_63;
unsigned int reg_r1_64;
unsigned int reg_r1_65;
unsigned int reg_r1_66;
unsigned int reg_r1_67;
unsigned int reg_r1_68;
unsigned int reg_r1_69;
unsigned int reg_r1_70;
unsigned int reg_r1_71;
unsigned int reg_r1_72;
unsigned int reg_r1_73;
unsigned int reg_r1_74;
unsigned int reg_r1_75;
unsigned int reg_r1_76;
unsigned int reg_r1_77;
unsigned int reg_r1_78;
unsigned int reg_r1_79;
unsigned int reg_r1_80;
unsigned int reg_r1_81;
unsigned int reg_r1_82;
unsigned int reg_r1_83;
unsigned int reg_r1_84;
unsigned int reg_r1_85;
unsigned int reg_r1_86;
unsigned int reg_r1_87;
unsigned int reg_r1_88;
unsigned int reg_r1_89;
unsigned int reg_r1_90;
unsigned int reg_r1_91;
unsigned int reg_r1_92;
unsigned int reg_r1_93;
unsigned int reg_r1_94;
unsigned int reg_r1_95;
unsigned int reg_r1_96;
unsigned int reg_r1_97;
unsigned int reg_r1_98;
unsigned int reg_r1_99;
unsigned int reg_r1_100;
unsigned int reg_r1_101;
unsigned int reg_r1_102;
unsigned int reg_r1_103;
unsigned int reg_r1_104;
unsigned int reg_r1_105;
unsigned int reg_r1_106;
unsigned int reg_r1_107;
unsigned int reg_r1_108;
unsigned int reg_r1_109;
unsigned int reg_r1_110;
unsigned int reg_r1_111;
unsigned int reg_r1_112;
unsigned int reg_r1_113;
unsigned int reg_r1_114;
unsigned int reg_r1_115;
unsigned int reg_r1_116;
unsigned int reg_r1_117;
unsigned int reg_r1_118;
unsigned int reg_r1_119;
unsigned int reg_r1_120;
unsigned int reg_r1_121;
unsigned int reg_r1_122;
unsigned int reg_r1_123;
unsigned int reg_r1_124;
unsigned int reg_r1_125;
unsigned int reg_r1_126;
unsigned int reg_r1_127;
unsigned int reg_r2_0;
unsigned int reg_r2_1;
unsigned int reg_r2_2;
unsigned int reg_r2_3;
unsigned int reg_r2_4;
unsigned int reg_r2_5;
unsigned int reg_r2_6;
unsigned int reg_r2_7;
unsigned int reg_r2_8;
unsigned int reg_r2_9;
unsigned int reg_r2_10;
unsigned int reg_r2_11;
unsigned int reg_r2_12;
unsigned int reg_r2_13;
unsigned int reg_r2_14;
unsigned int reg_r2_15;
unsigned int reg_r2_16;
unsigned int reg_r2_17;
unsigned int reg_r2_18;
unsigned int reg_r2_19;
unsigned int reg_r2_20;
unsigned int reg_r2_21;
unsigned int reg_r2_22;
unsigned int reg_r2_23;
unsigned int reg_r2_24;
unsigned int reg_r2_25;
unsigned int reg_r2_26;
unsigned int reg_r2_27;
unsigned int reg_r2_28;
unsigned int reg_r2_29;
unsigned int reg_r2_30;
unsigned int reg_r2_31;
unsigned int reg_r2_32;
unsigned int reg_r2_33;
unsigned int reg_r2_34;
unsigned int reg_r2_35;
unsigned int reg_r2_36;
unsigned int reg_r2_37;
unsigned int reg_r2_38;
unsigned int reg_r2_39;
unsigned int reg_r2_40;
unsigned int reg_r2_41;
unsigned int reg_r2_42;
unsigned int reg_r2_43;
unsigned int reg_r2_44;
unsigned int reg_r2_45;
unsigned int reg_r2_46;
unsigned int reg_r2_47;
unsigned int reg_r2_48;
unsigned int reg_r2_49;
unsigned int reg_r2_50;
unsigned int reg_r2_51;
unsigned int reg_r2_52;
unsigned int reg_r2_53;
unsigned int reg_r2_54;
unsigned int reg_r2_55;
unsigned int reg_r2_56;
unsigned int reg_r2_57;
unsigned int reg_r2_58;
unsigned int reg_r2_59;
unsigned int reg_r2_60;
unsigned int reg_r2_61;
unsigned int reg_r2_62;
unsigned int reg_r2_63;
unsigned int reg_r2_64;
unsigned int reg_r2_65;
unsigned int reg_r2_66;
unsigned int reg_r2_67;
unsigned int reg_r2_68;
unsigned int reg_r2_69;
unsigned int reg_r2_70;
unsigned int reg_r2_71;
unsigned int reg_r2_72;
unsigned int reg_r2_73;
unsigned int reg_r2_74;
unsigned int reg_r2_75;
unsigned int reg_r2_76;
unsigned int reg_r2_77;
unsigned int reg_r2_78;
unsigned int reg_r2_79;
unsigned int reg_r2_80;
unsigned int reg_r2_81;
unsigned int reg_r2_82;
unsigned int reg_r2_83;
unsigned int reg_r2_84;
unsigned int reg_r2_85;
unsigned int reg_r2_86;
unsigned int reg_r2_87;
unsigned int reg_r2_88;
unsigned int reg_r2_89;
unsigned int reg_r2_90;
unsigned int reg_r2_91;
unsigned int reg_r2_92;
unsigned int reg_r2_93;
unsigned int reg_r2_94;
unsigned int reg_r2_95;
unsigned int reg_r2_96;
unsigned int reg_r2_97;
unsigned int reg_r2_98;
unsigned int reg_r2_99;
unsigned int reg_r2_100;
unsigned int reg_r2_101;
unsigned int reg_r2_102;
unsigned int reg_r2_103;
unsigned int reg_r2_104;
unsigned int reg_r2_105;
unsigned int reg_r2_106;
unsigned int reg_r2_107;
unsigned int reg_r2_108;
unsigned int reg_r2_109;
unsigned int reg_r2_110;
unsigned int reg_r2_111;
unsigned int reg_r2_112;
unsigned int reg_r2_113;
unsigned int reg_r2_114;
unsigned int reg_r2_115;
unsigned int reg_r2_116;
unsigned int reg_r2_117;
unsigned int reg_r2_118;
unsigned int reg_r2_119;
unsigned int reg_r2_120;
unsigned int reg_r2_121;
unsigned int reg_r2_122;
unsigned int reg_r2_123;
unsigned int reg_r2_124;
unsigned int reg_r2_125;
unsigned int reg_r2_126;
unsigned int reg_r2_127;
unsigned int reg_r3_0;
unsigned int reg_r3_1;
unsigned int reg_r3_2;
unsigned int reg_r3_3;
unsigned int reg_r3_4;
unsigned int reg_r3_5;
unsigned int reg_r3_6;
unsigned int reg_r3_7;
unsigned int reg_r3_8;
unsigned int reg_r3_9;
unsigned int reg_r3_10;
unsigned int reg_r3_11;
unsigned int reg_r3_12;
unsigned int reg_r3_13;
unsigned int reg_r3_14;
unsigned int reg_r3_15;
unsigned int reg_r3_16;
unsigned int reg_r3_17;
unsigned int reg_r3_18;
unsigned int reg_r3_19;
unsigned int reg_r3_20;
unsigned int reg_r3_21;
unsigned int reg_r3_22;
unsigned int reg_r3_23;
unsigned int reg_r3_24;
unsigned int reg_r3_25;
unsigned int reg_r3_26;
unsigned int reg_r3_27;
unsigned int reg_r3_28;
unsigned int reg_r3_29;
unsigned int reg_r3_30;
unsigned int reg_r3_31;
unsigned int reg_r3_32;
unsigned int reg_r3_33;
unsigned int reg_r3_34;
unsigned int reg_r3_35;
unsigned int reg_r3_36;
unsigned int reg_r3_37;
unsigned int reg_r3_38;
unsigned int reg_r3_39;
unsigned int reg_r3_40;
unsigned int reg_r3_41;
unsigned int reg_r3_42;
unsigned int reg_r3_43;
unsigned int reg_r3_44;
unsigned int reg_r3_45;
unsigned int reg_r3_46;
unsigned int reg_r3_47;
unsigned int reg_r3_48;
unsigned int reg_r3_49;
unsigned int reg_r3_50;
unsigned int reg_r3_51;
unsigned int reg_r3_52;
unsigned int reg_r3_53;
unsigned int reg_r3_54;
unsigned int reg_r3_55;
unsigned int reg_r3_56;
unsigned int reg_r3_57;
unsigned int reg_r3_58;
unsigned int reg_r3_59;
unsigned int reg_r3_60;
unsigned int reg_r3_61;
unsigned int reg_r3_62;
unsigned int reg_r3_63;
unsigned int reg_r3_64;
unsigned int reg_r3_65;
unsigned int reg_r3_66;
unsigned int reg_r3_67;
unsigned int reg_r3_68;
unsigned int reg_r3_69;
unsigned int reg_r3_70;
unsigned int reg_r3_71;
unsigned int reg_r3_72;
unsigned int reg_r3_73;
unsigned int reg_r3_74;
unsigned int reg_r3_75;
unsigned int reg_r3_76;
unsigned int reg_r3_77;
unsigned int reg_r3_78;
unsigned int reg_r3_79;
unsigned int reg_r3_80;
unsigned int reg_r3_81;
unsigned int reg_r3_82;
unsigned int reg_r3_83;
unsigned int reg_r3_84;
unsigned int reg_r3_85;
unsigned int reg_r3_86;
unsigned int reg_r3_87;
unsigned int reg_r3_88;
unsigned int reg_r3_89;
unsigned int reg_r3_90;
unsigned int reg_r3_91;
unsigned int reg_r3_92;
unsigned int reg_r3_93;
unsigned int reg_r3_94;
unsigned int reg_r3_95;
unsigned int reg_r3_96;
unsigned int reg_r3_97;
unsigned int reg_r3_98;
unsigned int reg_r3_99;
unsigned int reg_r3_100;
unsigned int reg_r3_101;
unsigned int reg_r3_102;
unsigned int reg_r3_103;
unsigned int reg_r3_104;
unsigned int reg_r3_105;
unsigned int reg_r3_106;
unsigned int reg_r3_107;
unsigned int reg_r3_108;
unsigned int reg_r3_109;
unsigned int reg_r3_110;
unsigned int reg_r3_111;
unsigned int reg_r3_112;
unsigned int reg_r3_113;
unsigned int reg_r3_114;
unsigned int reg_r3_115;
unsigned int reg_r3_116;
unsigned int reg_r3_117;
unsigned int reg_r3_118;
unsigned int reg_r3_119;
unsigned int reg_r3_120;
unsigned int reg_r3_121;
unsigned int reg_r3_122;
unsigned int reg_r3_123;
unsigned int reg_r3_124;
unsigned int reg_r3_125;
unsigned int reg_r3_126;
unsigned int reg_r3_127;


extern unsigned int max( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(max);  sim_gprof_enter(&sim_gprof_idx,"max");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (102 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(0 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 20 */
} /* line 20 */
  sim_icache_fetch(1 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L0X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 22 */
  sim_icache_fetch(2 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(max);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 25 */
l_L0X3: ;/* line 28 */
__LABEL(l_L0X3);
  sim_icache_fetch(3 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_4); /* line 31 */
   __RETURN(max);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 31 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 101: goto l_L0X3;
    case 102:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int min( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(min);  sim_gprof_enter(&sim_gprof_idx,"min");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (104 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 47 */
} /* line 47 */
  sim_icache_fetch(6 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 49 */
  sim_icache_fetch(7 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(min);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 52 */
l_L1X3: ;/* line 55 */
__LABEL(l_L1X3);
  sim_icache_fetch(8 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_4); /* line 58 */
   __RETURN(min);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 58 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 103: goto l_L1X3;
    case 104:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int NOP(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(NOP);  sim_gprof_enter(&sim_gprof_idx,"NOP");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (105 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(10 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 74 */
} /* line 74 */
  sim_icache_fetch(11 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(NOP);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 77 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 105:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int __vex_main(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(__vex_main);  sim_gprof_enter(&sim_gprof_idx,"__vex_main");

  sim_ta_init(1); /* enable cache simulation */
  reg_r0_1 = sim_create_stack(1048576,reg_r0_1); 

  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (118 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 93 */
} /* line 93 */
		 /* line 94 */
  sim_icache_fetch(13 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 97 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(NOP);
   reg_l0_0 = (118 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) NOP;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 97 */
l_lr_6: ;/* line 97 */
__LABEL(l_lr_6);
  sim_icache_fetch(16 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, (unsigned int) -4096); /* line 99 */
   __MOV(reg_r0_3, (unsigned int) conv7_result); /* line 100 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 101 */
} /* line 101 */
  sim_icache_fetch(21 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 102 */
l_L2X3: ;/* line 105 */
__LABEL(l_L2X3);
  sim_icache_fetch(22 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 106 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 64); /* line 107 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 108 */
} /* line 108 */
  sim_icache_fetch(25 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 110 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 111 */
  sim_icache_fetch(27 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st(reg_r0_3,0,4), 0); /* line 113 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), 0); /* line 114 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), 0); /* line 115 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), 0); /* line 116 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), 0); /* line 117 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), 0); /* line 118 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), 0); /* line 119 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), 0); /* line 120 */
} /* line 120 */
  sim_icache_fetch(35 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), 0); /* line 122 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), 0); /* line 123 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), 0); /* line 124 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), 0); /* line 125 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), 0); /* line 126 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), 0); /* line 127 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), 0); /* line 128 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), 0); /* line 129 */
} /* line 129 */
  sim_icache_fetch(43 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st(reg_r0_4,0,4), 0); /* line 131 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), 0); /* line 132 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), 0); /* line 133 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), 0); /* line 134 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), 0); /* line 135 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), 0); /* line 136 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), 0); /* line 137 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) 64); /* line 138 */
} /* line 138 */
  sim_icache_fetch(51 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), 0); /* line 140 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), 0); /* line 141 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), 0); /* line 142 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), 0); /* line 143 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), 0); /* line 144 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), 0); /* line 145 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), 0); /* line 146 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), 0); /* line 147 */
} /* line 147 */
  sim_icache_fetch(59 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), 0); /* line 149 */
   __GOTO(l_L2X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L2X3;
} /* line 150 */
l_L3X3: ;/* line 153 */
__LABEL(l_L3X3);
  sim_icache_fetch(61 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_8, 0); /* line 154 */
   __MOV(reg_r0_3, 0); /* line 155 */
   __MOV(reg_r0_42, ((unsigned int) conv7_result + (unsigned int) 1012)); /* line 156 */
   __MOV(reg_r0_43, reg_r0_5); /* line 157 */
} /* line 157 */
l_L4X3: ;/* line 160 */
__LABEL(l_L4X3);
  sim_icache_fetch(66 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, (unsigned int) 58); /* line 161 */
   __MOV(reg_r0_4, (unsigned int) -58); /* line 162 */
   __MOV(reg_r0_7, 0); /* line 163 */
} /* line 163 */
  sim_icache_fetch(69 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 165 */
l_L6X3: ;/* line 168 */
__LABEL(l_L6X3);
  sim_icache_fetch(70 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 169 */
   __MOV(reg_r0_2, (unsigned int) -7); /* line 170 */
   __MOV(reg_r0_6, 0); /* line 171 */
   __MOV(reg_r0_5, reg_r0_7); /* line 172 */
   __MOV(reg_r0_15, 0); /* line 173 */
   __MOV(reg_r0_14, 0); /* line 174 */
   __MOV(reg_r0_16, 0); /* line 175 */
   __MOV(reg_r0_40, reg_r0_4); /* line 176 */
} /* line 176 */
  sim_icache_fetch(78 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_41, reg_r0_7); /* line 178 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 179 */
l_L8X3: ;/* line 182 */
__LABEL(l_L8X3);
  sim_icache_fetch(80 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 183 */
   __SH2ADD(reg_r0_10, reg_r0_6, (unsigned int) filter7x7); /* line 184 */
   __ADD(reg_r0_9, reg_r0_5, reg_r0_8); /* line 185 */
   __ADD(reg_r0_11, reg_r0_3, (unsigned int) 2); /* line 186 */
   __SH2ADD(reg_r0_12, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 8)); /* line 187 */
   __ADD(reg_r0_13, reg_r0_3, (unsigned int) 3); /* line 188 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 6); /* line 189 */
   __SH2ADD(reg_r0_7, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 24)); /* line 190 */
} /* line 190 */
  sim_icache_fetch(91 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDWs(reg_r0_10, mem_trace_ld(reg_r0_10,0,4)); /* line 192 */
   __SH2ADD(reg_r0_9, reg_r0_9, (unsigned int) conv7_image); /* line 193 */
   __SHL(reg_r0_11, reg_r0_11, (unsigned int) 6); /* line 194 */
   __LDWs(reg_r0_12, mem_trace_ld(reg_r0_12,0,4)); /* line 195 */
   __SHL(reg_r0_13, reg_r0_13, (unsigned int) 6); /* line 196 */
   __SHL(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 197 */
   __LDWs(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 198 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 199 */
  sim_icache_fetch(100 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_9, mem_trace_ld(reg_r0_9,0,4)); /* line 201 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 1); /* line 202 */
   __ADD(reg_r0_11, reg_r0_5, reg_r0_11); /* line 203 */
   __ADD(reg_r0_13, reg_r0_5, reg_r0_13); /* line 204 */
   __SH2ADD(reg_r0_17, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 12)); /* line 205 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 5); /* line 206 */
   __SH2ADD(reg_r0_19, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 20)); /* line 207 */
   __ADD(reg_r0_4, reg_r0_5, reg_r0_4); /* line 208 */
} /* line 208 */
  sim_icache_fetch(110 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SH2ADD(reg_r0_21, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 4)); /* line 210 */
   __SHL(reg_r0_20, reg_r0_20, (unsigned int) 6); /* line 211 */
   __SH2ADD(reg_r0_11, reg_r0_11, (unsigned int) conv7_image); /* line 212 */
   __SH2ADD(reg_r0_13, reg_r0_13, (unsigned int) conv7_image); /* line 213 */
   __LDW(reg_r0_17, mem_trace_ld(reg_r0_17,0,4)); /* line 214 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 6); /* line 215 */
   __LDW(reg_r0_19, mem_trace_ld(reg_r0_19,0,4)); /* line 216 */
   __SH2ADD(reg_r0_4, reg_r0_4, (unsigned int) conv7_image); /* line 217 */
} /* line 217 */
  sim_icache_fetch(122 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SHRU(reg_r0_22, reg_r0_9, (unsigned int) 8); /* line 219 */
   __LDW(reg_r0_21, mem_trace_ld(reg_r0_21,0,4)); /* line 220 */
   __ADD(reg_r0_20, reg_r0_5, reg_r0_20); /* line 221 */
   __LDW(reg_r0_11, mem_trace_ld(reg_r0_11,0,4)); /* line 222 */
   __LDW(reg_r0_13, mem_trace_ld(reg_r0_13,0,4)); /* line 223 */
   __ADD(reg_r0_23, reg_r0_3, (unsigned int) 4); /* line 224 */
   __ADD(reg_r0_18, reg_r0_5, reg_r0_18); /* line 225 */
   __LDW(reg_r0_4, mem_trace_ld(reg_r0_4,0,4)); /* line 226 */
} /* line 226 */
  sim_icache_fetch(130 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SHRU(reg_r0_25, reg_r0_9, (unsigned int) 16); /* line 228 */
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 229 */
   __AND(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 230 */
   __SH2ADD(reg_r0_20, reg_r0_20, (unsigned int) conv7_image); /* line 231 */
   __SHL(reg_r0_23, reg_r0_23, (unsigned int) 6); /* line 232 */
   __SH2ADD(reg_r0_24, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 16)); /* line 233 */
   __SH2ADD(reg_r0_18, reg_r0_18, (unsigned int) conv7_image); /* line 234 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 7); /* line 235 */
} /* line 235 */
  sim_icache_fetch(141 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MULLU(reg_r0_27, reg_r0_10, reg_r0_22); /* line 237 */
   __MULHS(reg_r0_22, reg_r0_10, reg_r0_22); /* line 238 */
   __LDW(reg_r0_20, mem_trace_ld(reg_r0_20,0,4)); /* line 239 */
   __SHRU(reg_r0_28, reg_r0_11, (unsigned int) 8); /* line 240 */
   __SHRU(reg_r0_29, reg_r0_13, (unsigned int) 8); /* line 241 */
   __ADD(reg_r0_23, reg_r0_5, reg_r0_23); /* line 242 */
   __LDW(reg_r0_18, mem_trace_ld(reg_r0_18,0,4)); /* line 243 */
   __SHRU(reg_r0_26, reg_r0_4, (unsigned int) 8); /* line 244 */
} /* line 244 */
  sim_icache_fetch(149 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 246 */
   __SHRU(reg_r0_31, reg_r0_11, (unsigned int) 16); /* line 247 */
   __AND(reg_r0_28, reg_r0_28, (unsigned int) 255); /* line 248 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 249 */
   __SH2ADD(reg_r0_23, reg_r0_23, (unsigned int) conv7_image); /* line 250 */
   __LDW(reg_r0_24, mem_trace_ld(reg_r0_24,0,4)); /* line 251 */
   __SHRU(reg_r0_30, reg_r0_4, (unsigned int) 16); /* line 252 */
   __AND(reg_r0_26, reg_r0_26, (unsigned int) 255); /* line 253 */
} /* line 253 */
  sim_icache_fetch(158 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_27, reg_r0_27, reg_r0_22); /* line 255 */
   __MULLU(reg_r0_22, reg_r0_12, reg_r0_28); /* line 256 */
   __MULHS(reg_r0_28, reg_r0_12, reg_r0_28); /* line 257 */
   __MULLU(reg_r0_33, reg_r0_17, reg_r0_29); /* line 258 */
   __MULHS(reg_r0_29, reg_r0_17, reg_r0_29); /* line 259 */
   __SHRU(reg_r0_34, reg_r0_18, (unsigned int) 8); /* line 260 */
   __MULLU(reg_r0_32, reg_r0_7, reg_r0_26); /* line 261 */
   __MULHS(reg_r0_26, reg_r0_7, reg_r0_26); /* line 262 */
} /* line 262 */
  sim_icache_fetch(166 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MULLU(reg_r0_37, reg_r0_10, reg_r0_25); /* line 264 */
   __MULHS(reg_r0_25, reg_r0_10, reg_r0_25); /* line 265 */
   __CMPLT(reg_b0_0, reg_r0_27, 0); /* line 266 */
   __ADD(reg_r0_35, reg_r0_27, (unsigned int) 255); /* line 267 */
   __SHRU(reg_r0_36, reg_r0_20, (unsigned int) 8); /* line 268 */
   __LDW(reg_r0_23, mem_trace_ld(reg_r0_23,0,4)); /* line 269 */
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 270 */
   __AND(reg_r0_30, reg_r0_30, (unsigned int) 255); /* line 271 */
} /* line 271 */
  sim_icache_fetch(174 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_26 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_35, reg_b0_0, reg_r0_35, reg_r0_27); /* line 273 */
   __AND(reg_r0_36, reg_r0_36, (unsigned int) 255); /* line 274 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_28); /* line 275 */
   __ADD(reg_r0_33, reg_r0_33, reg_r0_29); /* line 276 */
   __MULLU(reg_r0_26, reg_r0_19, reg_r0_34); /* line 277 */
   __MULHS(reg_r0_34, reg_r0_19, reg_r0_34); /* line 278 */
   __MULLU(reg_r0_27, reg_r0_7, reg_r0_30); /* line 279 */
   __ADD(reg_r0_32, reg_r0_32, t__i32_0); /* line 280 */
} /* line 280 */
  sim_icache_fetch(182 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SHR(reg_r0_35, reg_r0_35, (unsigned int) 8); /* line 282 */
   __MULLU(reg_r0_39, reg_r0_21, reg_r0_36); /* line 283 */
   __CMPLT(reg_b0_1, reg_r0_22, 0); /* line 284 */
   __ADD(reg_r0_29, reg_r0_22, (unsigned int) 255); /* line 285 */
   __CMPLT(reg_b0_2, reg_r0_33, 0); /* line 286 */
   __ADD(reg_r0_38, reg_r0_33, (unsigned int) 255); /* line 287 */
   __CMPLT(reg_b0_0, reg_r0_32, 0); /* line 288 */
   __ADD(reg_r0_28, reg_r0_32, (unsigned int) 255); /* line 289 */
} /* line 289 */
  sim_icache_fetch(190 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_37, reg_r0_37, reg_r0_25); /* line 291 */
   __MULHS(reg_r0_36, reg_r0_21, reg_r0_36); /* line 292 */
   __SLCT(reg_r0_29, reg_b0_1, reg_r0_29, reg_r0_22); /* line 293 */
   __SLCT(reg_r0_38, reg_b0_2, reg_r0_38, reg_r0_33); /* line 294 */
   __SHRU(reg_r0_22, reg_r0_23, (unsigned int) 8); /* line 295 */
   __ADD(reg_r0_26, reg_r0_26, reg_r0_34); /* line 296 */
   __MULHS(reg_r0_30, reg_r0_7, reg_r0_30); /* line 297 */
   __SLCT(reg_r0_28, reg_b0_0, reg_r0_28, reg_r0_32); /* line 298 */
} /* line 298 */
  sim_icache_fetch(198 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPLT(reg_b0_1, reg_r0_37, 0); /* line 300 */
   __ADD(reg_r0_32, reg_r0_37, (unsigned int) 255); /* line 301 */
   __SHR(reg_r0_29, reg_r0_29, (unsigned int) 8); /* line 302 */
   __SHR(reg_r0_38, reg_r0_38, (unsigned int) 8); /* line 303 */
   __AND(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 304 */
   __CMPLT(reg_b0_0, reg_r0_26, 0); /* line 305 */
   __ADD(reg_r0_25, reg_r0_26, (unsigned int) 255); /* line 306 */
   __SHR(reg_r0_28, reg_r0_28, (unsigned int) 8); /* line 307 */
} /* line 307 */
  sim_icache_fetch(206 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_26 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_32, reg_b0_1, reg_r0_32, reg_r0_37); /* line 309 */
   __ADD(reg_r0_39, reg_r0_39, reg_r0_36); /* line 310 */
   __MULLU(reg_r0_26, reg_r0_24, reg_r0_22); /* line 311 */
   __MULHS(reg_r0_22, reg_r0_24, reg_r0_22); /* line 312 */
   __SLCT(reg_r0_25, reg_b0_0, reg_r0_25, t__i32_0); /* line 313 */
   __ADD(reg_r0_27, reg_r0_27, reg_r0_30); /* line 314 */
   __ADD(reg_r0_35, reg_r0_35, reg_r0_28); /* line 315 */
   __ADD(reg_r0_29, reg_r0_29, reg_r0_38); /* line 316 */
} /* line 316 */
  sim_icache_fetch(214 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_29 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SHR(reg_r0_32, reg_r0_32, (unsigned int) 8); /* line 318 */
   __CMPLT(reg_b0_0, reg_r0_39, 0); /* line 319 */
   __ADD(reg_r0_28, reg_r0_39, (unsigned int) 255); /* line 320 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 321 */
   __SHR(reg_r0_25, reg_r0_25, (unsigned int) 8); /* line 322 */
   __CMPLT(reg_b0_1, reg_r0_27, 0); /* line 323 */
   __ADD(reg_r0_29, reg_r0_27, (unsigned int) 255); /* line 324 */
   __ADD(reg_r0_35, reg_r0_35, t__i32_0); /* line 325 */
} /* line 325 */
  sim_icache_fetch(222 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_27 ;
  t__i32_2 = reg_r0_25 ;
  t__i32_0 = reg_r0_22 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_28, reg_b0_0, reg_r0_28, reg_r0_39); /* line 327 */
   __MULLU(reg_r0_22, reg_r0_12, reg_r0_31); /* line 328 */
   __MULHS(reg_r0_31, reg_r0_12, reg_r0_31); /* line 329 */
   __SHRU(reg_r0_25, reg_r0_13, (unsigned int) 16); /* line 330 */
   __ADD(reg_r0_26, reg_r0_26, t__i32_0); /* line 331 */
   __SHRU(reg_r0_27, reg_r0_18, (unsigned int) 16); /* line 332 */
   __SLCT(reg_r0_29, reg_b0_1, reg_r0_29, t__i32_1); /* line 333 */
   __ADD(reg_r0_14, reg_r0_14, t__i32_2); /* line 334 */
} /* line 334 */
  sim_icache_fetch(230 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SHRU(reg_r0_33, reg_r0_20, (unsigned int) 16); /* line 336 */
   __SHR(reg_r0_28, reg_r0_28, (unsigned int) 8); /* line 337 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 338 */
   __SHRU(reg_r0_34, reg_r0_23, (unsigned int) 16); /* line 339 */
   __CMPLT(reg_b0_0, reg_r0_26, 0); /* line 340 */
   __ADD(reg_r0_30, reg_r0_26, (unsigned int) 255); /* line 341 */
   __AND(reg_r0_27, reg_r0_27, (unsigned int) 255); /* line 342 */
   __SHR(reg_r0_29, reg_r0_29, (unsigned int) 8); /* line 343 */
} /* line 343 */
  sim_icache_fetch(238 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_29 ;
  t__i32_0 = reg_r0_26 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 345 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_31); /* line 346 */
   __MULLU(reg_r0_26, reg_r0_17, reg_r0_25); /* line 347 */
   __MULHS(reg_r0_25, reg_r0_17, reg_r0_25); /* line 348 */
   __SLCT(reg_r0_30, reg_b0_0, reg_r0_30, t__i32_0); /* line 349 */
   __MULLU(reg_r0_29, reg_r0_19, reg_r0_27); /* line 350 */
   __MULHS(reg_r0_27, reg_r0_19, reg_r0_27); /* line 351 */
   __ADD(reg_r0_32, reg_r0_32, t__i32_1); /* line 352 */
} /* line 352 */
  sim_icache_fetch(246 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MULLU(reg_r0_37, reg_r0_10, reg_r0_9); /* line 354 */
   __MULLU(reg_r0_36, reg_r0_21, reg_r0_33); /* line 355 */
   __MULHS(reg_r0_33, reg_r0_21, reg_r0_33); /* line 356 */
   __CMPLT(reg_b0_0, reg_r0_22, 0); /* line 357 */
   __ADD(reg_r0_31, reg_r0_22, (unsigned int) 255); /* line 358 */
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 359 */
   __SHR(reg_r0_30, reg_r0_30, (unsigned int) 8); /* line 360 */
   __AND(reg_r0_4, reg_r0_4, (unsigned int) 255); /* line 361 */
} /* line 361 */
  sim_icache_fetch(254 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_31, reg_b0_0, reg_r0_31, reg_r0_22); /* line 363 */
   __ADD(reg_r0_26, reg_r0_26, reg_r0_25); /* line 364 */
   __MULLU(reg_r0_22, reg_r0_24, reg_r0_34); /* line 365 */
   __MULHS(reg_r0_34, reg_r0_24, reg_r0_34); /* line 366 */
   __ADD(reg_r0_29, reg_r0_29, reg_r0_27); /* line 367 */
   __MULLU(reg_r0_25, reg_r0_7, reg_r0_4); /* line 368 */
   __MULHS(reg_r0_7, reg_r0_7, reg_r0_4); /* line 369 */
   __ADD(reg_r0_28, reg_r0_28, reg_r0_30); /* line 370 */
} /* line 370 */
  sim_icache_fetch(262 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MULHS(reg_r0_10, reg_r0_10, reg_r0_9); /* line 372 */
   __ADD(reg_r0_36, reg_r0_36, reg_r0_33); /* line 373 */
   __SHR(reg_r0_31, reg_r0_31, (unsigned int) 8); /* line 374 */
   __CMPLT(reg_b0_0, reg_r0_26, 0); /* line 375 */
   __ADD(reg_r0_4, reg_r0_26, (unsigned int) 255); /* line 376 */
   __CMPLT(reg_b0_1, reg_r0_29, 0); /* line 377 */
   __ADD(reg_r0_27, reg_r0_29, (unsigned int) 255); /* line 378 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_28); /* line 379 */
} /* line 379 */
  sim_icache_fetch(270 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPLT(reg_b0_0, reg_r0_36, 0); /* line 381 */
   __ADD(reg_r0_9, reg_r0_36, (unsigned int) 255); /* line 382 */
   __AND(reg_r0_11, reg_r0_11, (unsigned int) 255); /* line 383 */
   __SLCT(reg_r0_4, t__i32_0, reg_r0_4, reg_r0_26); /* line 384 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_34); /* line 385 */
   __SLCT(reg_r0_27, reg_b0_1, reg_r0_27, reg_r0_29); /* line 386 */
   __ADD(reg_r0_25, reg_r0_25, reg_r0_7); /* line 387 */
   __ADD(reg_r0_14, reg_r0_35, reg_r0_14); /* line 388 */
} /* line 388 */
  sim_icache_fetch(278 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_37, reg_r0_37, reg_r0_10); /* line 390 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_36); /* line 391 */
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 392 */
   __CMPLT(reg_b0_0, reg_r0_22, 0); /* line 393 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 255); /* line 394 */
   __SHR(reg_r0_27, reg_r0_27, (unsigned int) 8); /* line 395 */
   __CMPLT(reg_b0_1, reg_r0_25, 0); /* line 396 */
   __ADD(reg_r0_26, reg_r0_25, (unsigned int) 255); /* line 397 */
} /* line 397 */
  sim_icache_fetch(286 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_4 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPLT(reg_b0_0, reg_r0_37, 0); /* line 399 */
   __ADD(reg_r0_4, reg_r0_37, (unsigned int) 255); /* line 400 */
   __SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 401 */
   __MULLU(reg_r0_10, reg_r0_12, reg_r0_11); /* line 402 */
   __SLCT(reg_r0_7, t__i32_0, reg_r0_7, reg_r0_22); /* line 403 */
   __SLCT(reg_r0_26, reg_b0_1, reg_r0_26, reg_r0_25); /* line 404 */
   __ADD(reg_r0_15, reg_r0_15, reg_r0_27); /* line 405 */
   __ADD(reg_r0_31, reg_r0_31, t__i32_1); /* line 406 */
} /* line 406 */
  sim_icache_fetch(294 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_37); /* line 408 */
   __AND(reg_r0_20, reg_r0_20, (unsigned int) 255); /* line 409 */
   __MULHS(reg_r0_12, reg_r0_12, reg_r0_11); /* line 410 */
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 411 */
   __SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 412 */
   __AND(reg_r0_18, reg_r0_18, (unsigned int) 255); /* line 413 */
   __SHR(reg_r0_26, reg_r0_26, (unsigned int) 8); /* line 414 */
   __ADD(reg_r0_32, reg_r0_32, reg_r0_31); /* line 415 */
} /* line 415 */
  sim_icache_fetch(302 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_13 ;
  t__i32_1 = reg_r0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 417 */
   __MULLU(reg_r0_13, reg_r0_21, reg_r0_20); /* line 418 */
   __MULHS(reg_r0_21, reg_r0_21, reg_r0_20); /* line 419 */
   __MULLU(reg_r0_7, reg_r0_17, t__i32_0); /* line 420 */
   __MULHS(reg_r0_17, reg_r0_17, t__i32_0); /* line 421 */
   __MULLU(reg_r0_11, reg_r0_19, reg_r0_18); /* line 422 */
   __MULHS(reg_r0_19, reg_r0_19, reg_r0_18); /* line 423 */
   __ADD(reg_r0_9, reg_r0_9, t__i32_1); /* line 424 */
} /* line 424 */
  sim_icache_fetch(310 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 426 */
   __AND(reg_r0_23, reg_r0_23, (unsigned int) 255); /* line 427 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 428 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 429 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_26); /* line 430 */
   __ADD(reg_r0_15, reg_r0_15, reg_r0_9); /* line 431 */
} /* line 431 */
  sim_icache_fetch(316 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_13, reg_r0_13, reg_r0_21); /* line 433 */
   __CMPLT(reg_b0_0, reg_r0_10, 0); /* line 434 */
   __ADD(reg_r0_9, reg_r0_10, (unsigned int) 255); /* line 435 */
   __ADD(reg_r0_7, reg_r0_7, reg_r0_17); /* line 436 */
   __MULLU(reg_r0_12, reg_r0_24, reg_r0_23); /* line 437 */
   __MULHS(reg_r0_24, reg_r0_24, reg_r0_23); /* line 438 */
   __ADD(reg_r0_11, reg_r0_11, reg_r0_19); /* line 439 */
   __ADD(reg_r0_15, reg_r0_32, reg_r0_15); /* line 440 */
} /* line 440 */
  sim_icache_fetch(324 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __CMPLT(reg_b0_2, reg_r0_13, 0); /* line 442 */
   __ADD(reg_r0_18, reg_r0_13, (unsigned int) 255); /* line 443 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 444 */
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 445 */
   __ADD(reg_r0_10, reg_r0_7, (unsigned int) 255); /* line 446 */
   __CMPLT(reg_b0_1, reg_r0_11, 0); /* line 447 */
   __ADD(reg_r0_17, reg_r0_11, (unsigned int) 255); /* line 448 */
} /* line 448 */
  sim_icache_fetch(331 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_18, reg_b0_2, reg_r0_18, reg_r0_13); /* line 450 */
   __SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 451 */
   __SLCT(reg_r0_10, reg_b0_0, reg_r0_10, reg_r0_7); /* line 452 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_24); /* line 453 */
   __SLCT(reg_r0_17, reg_b0_1, reg_r0_17, reg_r0_11); /* line 454 */
} /* line 454 */
  sim_icache_fetch(336 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 456 */
   __SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 457 */
   __CMPLT(reg_b0_0, reg_r0_12, 0); /* line 458 */
   __ADD(reg_r0_7, reg_r0_12, (unsigned int) 255); /* line 459 */
   __SHR(reg_r0_17, reg_r0_17, (unsigned int) 8); /* line 460 */
} /* line 460 */
  sim_icache_fetch(341 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_12); /* line 462 */
   __ADD(reg_r0_16, reg_r0_16, reg_r0_17); /* line 463 */
   __ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 464 */
} /* line 464 */
  sim_icache_fetch(344 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 466 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_9); /* line 467 */
} /* line 467 */
  sim_icache_fetch(346 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, reg_r0_7); /* line 469 */
} /* line 469 */
  sim_icache_fetch(347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_16, reg_r0_18); /* line 471 */
} /* line 471 */
  sim_icache_fetch(348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_16, reg_r0_4, reg_r0_16); /* line 473 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 474 */
l_L9X3: ;/* line 477 */
__LABEL(l_L9X3);
  sim_icache_fetch(350 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MAX(reg_r0_16, reg_r0_16, 0); /* line 478 */
   __MAX(reg_r0_14, reg_r0_14, 0); /* line 479 */
   __MAX(reg_r0_15, reg_r0_15, 0); /* line 480 */
   __SH2ADD(reg_r0_2, reg_r0_40, reg_r0_42); /* line 481 */
   __ADD(reg_r0_4, reg_r0_40, (unsigned int) 1); /* line 482 */
} /* line 482 */
  sim_icache_fetch(355 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MIN(reg_r0_16, reg_r0_16, (unsigned int) 255); /* line 484 */
   __MIN(reg_r0_14, reg_r0_14, (unsigned int) 255); /* line 485 */
   __MIN(reg_r0_15, reg_r0_15, (unsigned int) 255); /* line 486 */
   __ADD(reg_r0_7, reg_r0_41, (unsigned int) 1); /* line 487 */
} /* line 487 */
  sim_icache_fetch(359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 489 */
   __SHL(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 490 */
} /* line 490 */
  sim_icache_fetch(361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_16, reg_r0_16, reg_r0_15); /* line 492 */
} /* line 492 */
  sim_icache_fetch(362 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_16, reg_r0_16, reg_r0_14); /* line 494 */
} /* line 494 */
  sim_icache_fetch(363 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_16); /* line 496 */
   __GOTO(l_L6X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L6X3;
} /* line 497 */
l_L7X3: ;/* line 500 */
__LABEL(l_L7X3);
  sim_icache_fetch(365 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_42, reg_r0_42, (unsigned int) 256); /* line 501 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 64); /* line 502 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 503 */
   __GOTO(l_L4X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L4X3;
} /* line 504 */
l_L5X3: ;/* line 507 */
__LABEL(l_L5X3);
		 /* line 507 */
  sim_icache_fetch(370 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_43); /* line 510 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 511 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (118 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 511 */
l_lr_16: ;/* line 511 */
__LABEL(l_lr_16);
  sim_icache_fetch(375 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 513 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 514 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 515 */
   __ADD_CYCLES(1);
} /* line 515 */
  sim_icache_fetch(378 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 518 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 107: goto l_lr_6;
    case 108: goto l_L2X3;
    case 109: goto l_L3X3;
    case 110: goto l_L4X3;
    case 111: goto l_L6X3;
    case 112: goto l_L8X3;
    case 113: goto l_L9X3;
    case 114: goto l_L7X3;
    case 115: goto l_L5X3;
    case 117: goto l_lr_16;
    case 118:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"convolution_7x7.s", 384, 0, 0, 0, 2};

