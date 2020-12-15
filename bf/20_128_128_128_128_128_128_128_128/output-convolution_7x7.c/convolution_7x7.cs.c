/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/20_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
  sim_icache_fetch(27 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __STW(mem_trace_st(reg_r0_3,0,4), 0); /* line 113 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), 0); /* line 114 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), 0); /* line 115 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), 0); /* line 116 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), 0); /* line 117 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), 0); /* line 118 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), 0); /* line 119 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), 0); /* line 120 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), 0); /* line 121 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), 0); /* line 122 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), 0); /* line 123 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), 0); /* line 124 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), 0); /* line 125 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), 0); /* line 126 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), 0); /* line 127 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), 0); /* line 128 */
   __STW(mem_trace_st(reg_r0_4,0,4), 0); /* line 129 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), 0); /* line 130 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), 0); /* line 131 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) 64); /* line 132 */
} /* line 132 */
  sim_icache_fetch(47 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), 0); /* line 134 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), 0); /* line 135 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), 0); /* line 136 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), 0); /* line 137 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), 0); /* line 138 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), 0); /* line 139 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), 0); /* line 140 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), 0); /* line 141 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), 0); /* line 142 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), 0); /* line 143 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), 0); /* line 144 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), 0); /* line 145 */
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), 0); /* line 146 */
   __GOTO(l_L2X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L2X3;
} /* line 147 */
l_L3X3: ;/* line 150 */
__LABEL(l_L3X3);
  sim_icache_fetch(61 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_8, 0); /* line 151 */
   __MOV(reg_r0_3, 0); /* line 152 */
   __MOV(reg_r0_54, ((unsigned int) conv7_result + (unsigned int) 1012)); /* line 153 */
   __MOV(reg_r0_55, reg_r0_5); /* line 154 */
} /* line 154 */
l_L4X3: ;/* line 157 */
__LABEL(l_L4X3);
  sim_icache_fetch(66 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, (unsigned int) 58); /* line 158 */
   __MOV(reg_r0_4, (unsigned int) -58); /* line 159 */
   __MOV(reg_r0_7, 0); /* line 160 */
} /* line 160 */
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
} /* line 162 */
l_L6X3: ;/* line 165 */
__LABEL(l_L6X3);
  sim_icache_fetch(70 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 166 */
   __MOV(reg_r0_2, (unsigned int) -7); /* line 167 */
   __MOV(reg_r0_6, 0); /* line 168 */
   __MOV(reg_r0_5, reg_r0_7); /* line 169 */
   __MOV(reg_r0_22, 0); /* line 170 */
   __MOV(reg_r0_17, 0); /* line 171 */
   __MOV(reg_r0_23, 0); /* line 172 */
   __MOV(reg_r0_52, reg_r0_4); /* line 173 */
   __MOV(reg_r0_53, reg_r0_7); /* line 174 */
} /* line 174 */
  sim_icache_fetch(79 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 176 */
l_L8X3: ;/* line 179 */
__LABEL(l_L8X3);
  sim_icache_fetch(80 + t_thisfile.offset, 24);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 180 */
   __SH2ADD(reg_r0_10, reg_r0_6, (unsigned int) filter7x7); /* line 181 */
   __ADD(reg_r0_9, reg_r0_5, reg_r0_8); /* line 182 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 1); /* line 183 */
   __SH2ADD(reg_r0_19, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 4)); /* line 184 */
   __ADD(reg_r0_11, reg_r0_3, (unsigned int) 2); /* line 185 */
   __SH2ADD(reg_r0_12, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 8)); /* line 186 */
   __ADD(reg_r0_13, reg_r0_3, (unsigned int) 3); /* line 187 */
   __SH2ADD(reg_r0_14, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 12)); /* line 188 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 4); /* line 189 */
   __SH2ADD(reg_r0_21, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 16)); /* line 190 */
   __ADD(reg_r0_15, reg_r0_3, (unsigned int) 5); /* line 191 */
   __SH2ADD(reg_r0_16, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 20)); /* line 192 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 6); /* line 193 */
   __SH2ADD(reg_r0_7, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 24)); /* line 194 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 7); /* line 195 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 196 */
} /* line 196 */
  sim_icache_fetch(104 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __LDWs(reg_r0_10, mem_trace_ld(reg_r0_10,0,4)); /* line 198 */
   __SH2ADD(reg_r0_9, reg_r0_9, (unsigned int) conv7_image); /* line 199 */
   __LDWs(reg_r0_19, mem_trace_ld(reg_r0_19,0,4)); /* line 200 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 6); /* line 201 */
   __SHL(reg_r0_11, reg_r0_11, (unsigned int) 6); /* line 202 */
   __LDWs(reg_r0_12, mem_trace_ld(reg_r0_12,0,4)); /* line 203 */
   __SHL(reg_r0_13, reg_r0_13, (unsigned int) 6); /* line 204 */
   __LDWs(reg_r0_14, mem_trace_ld(reg_r0_14,0,4)); /* line 205 */
   __SHL(reg_r0_20, reg_r0_20, (unsigned int) 6); /* line 206 */
   __LDWs(reg_r0_21, mem_trace_ld(reg_r0_21,0,4)); /* line 207 */
   __SHL(reg_r0_15, reg_r0_15, (unsigned int) 6); /* line 208 */
   __LDWs(reg_r0_16, mem_trace_ld(reg_r0_16,0,4)); /* line 209 */
   __SHL(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 210 */
   __LDWs(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 211 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 212 */
  sim_icache_fetch(120 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_9, mem_trace_ld(reg_r0_9,0,4)); /* line 214 */
   __ADD(reg_r0_18, reg_r0_5, reg_r0_18); /* line 215 */
   __ADD(reg_r0_11, reg_r0_5, reg_r0_11); /* line 216 */
   __ADD(reg_r0_13, reg_r0_5, reg_r0_13); /* line 217 */
   __ADD(reg_r0_20, reg_r0_5, reg_r0_20); /* line 218 */
   __ADD(reg_r0_15, reg_r0_5, reg_r0_15); /* line 219 */
   __ADD(reg_r0_4, reg_r0_5, reg_r0_4); /* line 220 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 221 */
} /* line 221 */
  sim_icache_fetch(128 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_18, reg_r0_18, (unsigned int) conv7_image); /* line 223 */
   __SH2ADD(reg_r0_11, reg_r0_11, (unsigned int) conv7_image); /* line 224 */
   __SH2ADD(reg_r0_13, reg_r0_13, (unsigned int) conv7_image); /* line 225 */
   __SH2ADD(reg_r0_20, reg_r0_20, (unsigned int) conv7_image); /* line 226 */
   __SH2ADD(reg_r0_15, reg_r0_15, (unsigned int) conv7_image); /* line 227 */
   __SH2ADD(reg_r0_4, reg_r0_4, (unsigned int) conv7_image); /* line 228 */
} /* line 228 */
  sim_icache_fetch(140 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_9 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __SHRU(reg_r0_25, t__i32_0, (unsigned int) 16); /* line 230 */
   __AND(reg_r0_9, t__i32_0, (unsigned int) 255); /* line 231 */
   __SHRU(reg_r0_24, t__i32_0, (unsigned int) 8); /* line 232 */
   __LDW(reg_r0_18, mem_trace_ld(reg_r0_18,0,4)); /* line 233 */
   __LDW(reg_r0_11, mem_trace_ld(reg_r0_11,0,4)); /* line 234 */
   __LDW(reg_r0_13, mem_trace_ld(reg_r0_13,0,4)); /* line 235 */
   __LDW(reg_r0_20, mem_trace_ld(reg_r0_20,0,4)); /* line 236 */
   __LDW(reg_r0_15, mem_trace_ld(reg_r0_15,0,4)); /* line 237 */
   __LDW(reg_r0_4, mem_trace_ld(reg_r0_4,0,4)); /* line 238 */
} /* line 238 */
  sim_icache_fetch(149 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 240 */
   __MULLU(reg_r0_26, reg_r0_10, reg_r0_9); /* line 241 */
   __MULHS(reg_r0_9, reg_r0_10, reg_r0_9); /* line 242 */
   __AND(reg_r0_24, reg_r0_24, (unsigned int) 255); /* line 243 */
} /* line 243 */
  sim_icache_fetch(153 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  unsigned int t__i32_3;
  unsigned int t__i32_4;
  t__i32_3 = reg_r0_15 ;
  t__i32_2 = reg_r0_13 ;
  t__i32_1 = reg_r0_11 ;
  t__i32_0 = reg_r0_10 ;
  t__i32_4 = reg_r0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __MULLU(reg_r0_35, t__i32_0, reg_r0_25); /* line 245 */
   __MULHS(reg_r0_10, t__i32_0, reg_r0_25); /* line 246 */
   __MULLU(reg_r0_28, t__i32_0, reg_r0_24); /* line 247 */
   __MULHS(reg_r0_24, t__i32_0, reg_r0_24); /* line 248 */
   __SHRU(reg_r0_38, reg_r0_18, (unsigned int) 16); /* line 249 */
   __SHRU(reg_r0_32, reg_r0_18, (unsigned int) 8); /* line 250 */
   __SHRU(reg_r0_25, t__i32_1, (unsigned int) 16); /* line 251 */
   __AND(reg_r0_11, t__i32_1, (unsigned int) 255); /* line 252 */
   __SHRU(reg_r0_29, t__i32_1, (unsigned int) 8); /* line 253 */
   __SHRU(reg_r0_36, t__i32_2, (unsigned int) 16); /* line 254 */
   __AND(reg_r0_13, t__i32_2, (unsigned int) 255); /* line 255 */
   __SHRU(reg_r0_30, t__i32_2, (unsigned int) 8); /* line 256 */
   __SHRU(reg_r0_39, reg_r0_20, (unsigned int) 16); /* line 257 */
   __SHRU(reg_r0_33, reg_r0_20, (unsigned int) 8); /* line 258 */
   __SHRU(reg_r0_37, t__i32_3, (unsigned int) 16); /* line 259 */
   __AND(reg_r0_15, t__i32_3, (unsigned int) 255); /* line 260 */
   __SHRU(reg_r0_31, t__i32_3, (unsigned int) 8); /* line 261 */
   __SHRU(reg_r0_34, t__i32_4, (unsigned int) 16); /* line 262 */
   __AND(reg_r0_4, t__i32_4, (unsigned int) 255); /* line 263 */
   __SHRU(reg_r0_27, t__i32_4, (unsigned int) 8); /* line 264 */
} /* line 264 */
  sim_icache_fetch(173 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __ADD(reg_r0_26, reg_r0_26, reg_r0_9); /* line 266 */
   __AND(reg_r0_38, reg_r0_38, (unsigned int) 255); /* line 267 */
   __AND(reg_r0_32, reg_r0_32, (unsigned int) 255); /* line 268 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 269 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 270 */
   __MULLU(reg_r0_9, reg_r0_12, reg_r0_11); /* line 271 */
   __MULHS(reg_r0_11, reg_r0_12, reg_r0_11); /* line 272 */
   __AND(reg_r0_36, reg_r0_36, (unsigned int) 255); /* line 273 */
   __AND(reg_r0_30, reg_r0_30, (unsigned int) 255); /* line 274 */
   __MULLU(reg_r0_41, reg_r0_14, reg_r0_13); /* line 275 */
   __MULHS(reg_r0_13, reg_r0_14, reg_r0_13); /* line 276 */
   __AND(reg_r0_39, reg_r0_39, (unsigned int) 255); /* line 277 */
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 278 */
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 279 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 280 */
   __MULLU(reg_r0_42, reg_r0_16, reg_r0_15); /* line 281 */
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 282 */
   __AND(reg_r0_27, reg_r0_27, (unsigned int) 255); /* line 283 */
   __MULLU(reg_r0_40, reg_r0_7, reg_r0_4); /* line 284 */
   __MULHS(reg_r0_4, reg_r0_7, reg_r0_4); /* line 285 */
} /* line 285 */
  sim_icache_fetch(193 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_14 ;
  t__i32_0 = reg_r0_12 ;
  t__i32_2 = reg_r0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __ADD(reg_r0_35, reg_r0_35, reg_r0_10); /* line 287 */
   __ADD(reg_r0_28, reg_r0_28, reg_r0_24); /* line 288 */
   __MULLU(reg_r0_46, reg_r0_19, reg_r0_32); /* line 289 */
   __MULHS(reg_r0_32, reg_r0_19, reg_r0_32); /* line 290 */
   __MULLU(reg_r0_10, t__i32_0, reg_r0_25); /* line 291 */
   __MULHS(reg_r0_12, t__i32_0, reg_r0_25); /* line 292 */
   __MULLU(reg_r0_24, t__i32_0, reg_r0_29); /* line 293 */
   __MULHS(reg_r0_29, t__i32_0, reg_r0_29); /* line 294 */
   __MULLU(reg_r0_25, t__i32_1, reg_r0_36); /* line 295 */
   __MULHS(reg_r0_14, t__i32_1, reg_r0_36); /* line 296 */
   __MULLU(reg_r0_44, t__i32_1, reg_r0_30); /* line 297 */
   __MULHS(reg_r0_30, t__i32_1, reg_r0_30); /* line 298 */
   __MULLU(reg_r0_47, reg_r0_21, reg_r0_33); /* line 299 */
   __MULHS(reg_r0_33, reg_r0_21, reg_r0_33); /* line 300 */
   __MULLU(reg_r0_45, reg_r0_16, reg_r0_31); /* line 301 */
   __MULHS(reg_r0_31, reg_r0_16, reg_r0_31); /* line 302 */
   __MULLU(reg_r0_48, t__i32_2, reg_r0_34); /* line 303 */
   __MULHS(reg_r0_7, t__i32_2, reg_r0_34); /* line 304 */
   __MULLU(reg_r0_43, t__i32_2, reg_r0_27); /* line 305 */
   __MULHS(reg_r0_27, t__i32_2, reg_r0_27); /* line 306 */
} /* line 306 */
  sim_icache_fetch(213 + t_thisfile.offset, 18);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(18);
   __CMPLT(reg_b0_1, reg_r0_35, 0); /* line 308 */
   __ADD(reg_r0_36, reg_r0_35, (unsigned int) 255); /* line 309 */
   __CMPLT(reg_b0_2, reg_r0_26, 0); /* line 310 */
   __ADD(reg_r0_4, reg_r0_26, (unsigned int) 255); /* line 311 */
   __CMPLT(reg_b0_0, reg_r0_28, 0); /* line 312 */
   __ADD(reg_r0_34, reg_r0_28, (unsigned int) 255); /* line 313 */
   __MULLU(reg_r0_50, reg_r0_19, reg_r0_38); /* line 314 */
   __MULHS(reg_r0_38, reg_r0_19, reg_r0_38); /* line 315 */
   __AND(reg_r0_18, reg_r0_18, (unsigned int) 255); /* line 316 */
   __ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 317 */
   __ADD(reg_r0_41, reg_r0_41, reg_r0_13); /* line 318 */
   __AND(reg_r0_20, reg_r0_20, (unsigned int) 255); /* line 319 */
   __MULLU(reg_r0_51, reg_r0_21, reg_r0_39); /* line 320 */
   __MULHS(reg_r0_39, reg_r0_21, reg_r0_39); /* line 321 */
   __MULLU(reg_r0_49, reg_r0_16, reg_r0_37); /* line 322 */
   __MULHS(reg_r0_37, reg_r0_16, reg_r0_37); /* line 323 */
   __MULHS(reg_r0_16, reg_r0_16, reg_r0_15); /* line 324 */
   __ADD(reg_r0_40, reg_r0_40, t__i32_0); /* line 325 */
} /* line 325 */
  sim_icache_fetch(231 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __SLCT(reg_r0_36, reg_b0_1, reg_r0_36, reg_r0_35); /* line 327 */
   __SLCT(reg_r0_4, reg_b0_2, reg_r0_4, reg_r0_26); /* line 328 */
   __SLCT(reg_r0_34, reg_b0_0, reg_r0_34, reg_r0_28); /* line 329 */
   __MULLU(reg_r0_13, reg_r0_19, reg_r0_18); /* line 330 */
   __MULHS(reg_r0_19, reg_r0_19, reg_r0_18); /* line 331 */
   __ADD(reg_r0_46, reg_r0_46, reg_r0_32); /* line 332 */
   __ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 333 */
   __CMPLT(reg_b0_1, reg_r0_9, 0); /* line 334 */
   __ADD(reg_r0_11, reg_r0_9, (unsigned int) 255); /* line 335 */
   __ADD(reg_r0_24, reg_r0_24, reg_r0_29); /* line 336 */
   __ADD(reg_r0_25, reg_r0_25, reg_r0_14); /* line 337 */
   __CMPLT(reg_b0_2, reg_r0_41, 0); /* line 338 */
   __ADD(reg_r0_12, reg_r0_41, (unsigned int) 255); /* line 339 */
   __ADD(reg_r0_44, reg_r0_44, reg_r0_30); /* line 340 */
   __ADD(reg_r0_47, reg_r0_47, reg_r0_33); /* line 341 */
   __ADD(reg_r0_45, reg_r0_45, reg_r0_31); /* line 342 */
   __ADD(reg_r0_48, reg_r0_48, reg_r0_7); /* line 343 */
   __CMPLT(reg_b0_0, reg_r0_40, 0); /* line 344 */
   __ADD(reg_r0_7, reg_r0_40, (unsigned int) 255); /* line 345 */
   __ADD(reg_r0_43, reg_r0_43, reg_r0_27); /* line 346 */
} /* line 346 */
  sim_icache_fetch(251 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_0 = reg_b0_2 ;
  t__i32_1 = reg_b0_1 ;
  t__i32_2 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __SHR(reg_r0_36, reg_r0_36, (unsigned int) 8); /* line 348 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 349 */
   __CMPLT(reg_b0_7, reg_r0_46, 0); /* line 350 */
   __ADD(reg_r0_27, reg_r0_46, (unsigned int) 255); /* line 351 */
   __CMPLT(reg_b0_0, reg_r0_10, 0); /* line 352 */
   __CMPLT(reg_b0_4, reg_r0_24, 0); /* line 353 */
   __ADD(reg_r0_15, reg_r0_24, (unsigned int) 255); /* line 354 */
   __CMPLT(reg_b0_5, reg_r0_44, 0); /* line 355 */
   __ADD(reg_r0_18, reg_r0_44, (unsigned int) 255); /* line 356 */
   __CMPLT(reg_b0_2, reg_r0_47, 0); /* line 357 */
   __ADD(reg_r0_29, reg_r0_47, (unsigned int) 255); /* line 358 */
   __CMPLT(reg_b0_6, reg_r0_45, 0); /* line 359 */
   __ADD(reg_r0_26, reg_r0_45, (unsigned int) 255); /* line 360 */
   __CMPLT(reg_b0_1, reg_r0_48, 0); /* line 361 */
   __ADD(reg_r0_31, reg_r0_48, (unsigned int) 255); /* line 362 */
   __CMPLT(reg_b0_3, reg_r0_43, 0); /* line 363 */
   __ADD(reg_r0_14, reg_r0_43, (unsigned int) 255); /* line 364 */
   __MFB(reg_r0_28, t__i32_0); /* line 365 */
   __MFB(reg_r0_30, t__i32_1); /* line 366 */
   __MFB(reg_r0_32, t__i32_2); /* line 367 */
} /* line 367 */
  sim_icache_fetch(271 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_0 = reg_r0_24 ;
  t__i32_1 = reg_r0_16 ;
  t__i32_2 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 369 */
   __ADD(reg_r0_50, reg_r0_50, reg_r0_38); /* line 370 */
   __ADD(reg_r0_13, reg_r0_13, reg_r0_19); /* line 371 */
   __SLCT(reg_r0_27, reg_b0_7, reg_r0_27, reg_r0_46); /* line 372 */
   __ADD(reg_r0_24, reg_r0_10, (unsigned int) 255); /* line 373 */
   __SLCT(reg_r0_15, reg_b0_4, reg_r0_15, t__i32_0); /* line 374 */
   __CMPLT(reg_b0_1, reg_r0_25, 0); /* line 375 */
   __ADD(reg_r0_33, reg_r0_25, (unsigned int) 255); /* line 376 */
   __SLCT(reg_r0_18, reg_b0_5, reg_r0_18, reg_r0_44); /* line 377 */
   __ADD(reg_r0_51, reg_r0_51, reg_r0_39); /* line 378 */
   __MULLU(reg_r0_16, reg_r0_21, reg_r0_20); /* line 379 */
   __SLCT(reg_r0_29, reg_b0_2, reg_r0_29, reg_r0_47); /* line 380 */
   __ADD(reg_r0_49, reg_r0_49, reg_r0_37); /* line 381 */
   __ADD(reg_r0_42, reg_r0_42, t__i32_1); /* line 382 */
   __SLCT(reg_r0_26, reg_b0_6, reg_r0_26, reg_r0_45); /* line 383 */
   __SLCT(reg_r0_31, t__i32_2, reg_r0_31, reg_r0_48); /* line 384 */
   __SLCT(reg_r0_14, reg_b0_3, reg_r0_14, reg_r0_43); /* line 385 */
   __MTB(reg_b0_4, reg_r0_28); /* line 386 */
   __MTB(reg_b0_3, reg_r0_30); /* line 387 */
   __MTB(reg_b0_2, reg_r0_32); /* line 388 */
} /* line 388 */
  sim_icache_fetch(291 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_b0_2 ;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __CMPLT(reg_b0_1, reg_r0_50, 0); /* line 390 */
   __ADD(reg_r0_19, reg_r0_50, (unsigned int) 255); /* line 391 */
   __SHR(reg_r0_27, reg_r0_27, (unsigned int) 8); /* line 392 */
   __SLCT(reg_r0_24, reg_b0_0, reg_r0_24, reg_r0_10); /* line 393 */
   __SLCT(reg_r0_11, reg_b0_3, reg_r0_11, reg_r0_9); /* line 394 */
   __SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 395 */
   __SLCT(reg_r0_33, t__i32_0, reg_r0_33, reg_r0_25); /* line 396 */
   __SLCT(reg_r0_12, reg_b0_4, reg_r0_12, reg_r0_41); /* line 397 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 398 */
   __CMPLT(reg_b0_5, reg_r0_51, 0); /* line 399 */
   __ADD(reg_r0_25, reg_r0_51, (unsigned int) 255); /* line 400 */
   __SHR(reg_r0_29, reg_r0_29, (unsigned int) 8); /* line 401 */
   __CMPLT(reg_b0_0, reg_r0_49, 0); /* line 402 */
   __ADD(reg_r0_10, reg_r0_49, (unsigned int) 255); /* line 403 */
   __CMPLT(reg_b0_2, reg_r0_42, 0); /* line 404 */
   __ADD(reg_r0_9, reg_r0_42, (unsigned int) 255); /* line 405 */
   __SHR(reg_r0_26, reg_r0_26, (unsigned int) 8); /* line 406 */
   __SHR(reg_r0_31, reg_r0_31, (unsigned int) 8); /* line 407 */
   __SLCT(reg_r0_7, t__i32_1, reg_r0_7, reg_r0_40); /* line 408 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 409 */
} /* line 409 */
  sim_icache_fetch(311 + t_thisfile.offset, 17);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_14 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __SLCT(reg_r0_19, reg_b0_1, reg_r0_19, reg_r0_50); /* line 411 */
   __CMPLT(reg_b0_0, reg_r0_13, 0); /* line 412 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 255); /* line 413 */
   __SHR(reg_r0_24, reg_r0_24, (unsigned int) 8); /* line 414 */
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 415 */
   __SHR(reg_r0_33, reg_r0_33, (unsigned int) 8); /* line 416 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 417 */
   __SLCT(reg_r0_25, reg_b0_5, reg_r0_25, reg_r0_51); /* line 418 */
   __MULHS(reg_r0_21, reg_r0_21, reg_r0_20); /* line 419 */
   __SLCT(reg_r0_10, t__i32_0, reg_r0_10, reg_r0_49); /* line 420 */
   __SLCT(reg_r0_9, reg_b0_2, reg_r0_9, reg_r0_42); /* line 421 */
   __SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 422 */
   __ADD(reg_r0_34, reg_r0_34, t__i32_1); /* line 423 */
   __ADD(reg_r0_17, reg_r0_17, reg_r0_26); /* line 424 */
   __ADD(reg_r0_27, reg_r0_27, reg_r0_29); /* line 425 */
   __ADD(reg_r0_15, reg_r0_15, reg_r0_18); /* line 426 */
   __ADD(reg_r0_36, reg_r0_36, reg_r0_31); /* line 427 */
} /* line 427 */
  sim_icache_fetch(328 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SHR(reg_r0_19, reg_r0_19, (unsigned int) 8); /* line 429 */
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_13); /* line 430 */
   __SHR(reg_r0_25, reg_r0_25, (unsigned int) 8); /* line 431 */
   __SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 432 */
   __SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 433 */
   __ADD(reg_r0_34, reg_r0_34, reg_r0_15); /* line 434 */
   __ADD(reg_r0_17, reg_r0_17, reg_r0_27); /* line 435 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_7); /* line 436 */
   __ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 437 */
   __ADD(reg_r0_24, reg_r0_24, reg_r0_33); /* line 438 */
} /* line 438 */
  sim_icache_fetch(338 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 440 */
   __ADD(reg_r0_16, reg_r0_16, reg_r0_21); /* line 441 */
   __ADD(reg_r0_17, reg_r0_34, reg_r0_17); /* line 442 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_9); /* line 443 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 444 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_10); /* line 445 */
   __ADD(reg_r0_19, reg_r0_19, reg_r0_25); /* line 446 */
   __ADD(reg_r0_36, reg_r0_36, reg_r0_24); /* line 447 */
} /* line 447 */
  sim_icache_fetch(346 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, 0); /* line 449 */
   __ADD(reg_r0_7, reg_r0_16, (unsigned int) 255); /* line 450 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_19); /* line 451 */
} /* line 451 */
  sim_icache_fetch(349 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_16); /* line 453 */
   __ADD(reg_r0_22, reg_r0_36, reg_r0_22); /* line 454 */
} /* line 454 */
  sim_icache_fetch(351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 456 */
} /* line 456 */
  sim_icache_fetch(352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_14, reg_r0_7); /* line 458 */
} /* line 458 */
  sim_icache_fetch(353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_23, reg_r0_23, reg_r0_14); /* line 460 */
} /* line 460 */
  sim_icache_fetch(354 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_23, reg_r0_4, reg_r0_23); /* line 462 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 463 */
l_L9X3: ;/* line 466 */
__LABEL(l_L9X3);
  sim_icache_fetch(356 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MAX(reg_r0_23, reg_r0_23, 0); /* line 467 */
   __MAX(reg_r0_17, reg_r0_17, 0); /* line 468 */
   __MAX(reg_r0_22, reg_r0_22, 0); /* line 469 */
   __SH2ADD(reg_r0_2, reg_r0_52, reg_r0_54); /* line 470 */
   __ADD(reg_r0_4, reg_r0_52, (unsigned int) 1); /* line 471 */
} /* line 471 */
  sim_icache_fetch(361 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MIN(reg_r0_23, reg_r0_23, (unsigned int) 255); /* line 473 */
   __MIN(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 474 */
   __MIN(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 475 */
   __ADD(reg_r0_7, reg_r0_53, (unsigned int) 1); /* line 476 */
} /* line 476 */
  sim_icache_fetch(365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_17, reg_r0_17, (unsigned int) 8); /* line 478 */
   __SHL(reg_r0_22, reg_r0_22, (unsigned int) 16); /* line 479 */
} /* line 479 */
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_23, reg_r0_23, reg_r0_22); /* line 481 */
} /* line 481 */
  sim_icache_fetch(368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_23, reg_r0_23, reg_r0_17); /* line 483 */
} /* line 483 */
  sim_icache_fetch(369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_23); /* line 485 */
   __GOTO(l_L6X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L6X3;
} /* line 486 */
l_L7X3: ;/* line 489 */
__LABEL(l_L7X3);
  sim_icache_fetch(371 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_54, reg_r0_54, (unsigned int) 256); /* line 490 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 64); /* line 491 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 492 */
   __GOTO(l_L4X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L4X3;
} /* line 493 */
l_L5X3: ;/* line 496 */
__LABEL(l_L5X3);
		 /* line 496 */
  sim_icache_fetch(376 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_55); /* line 499 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 500 */
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
} /* line 500 */
l_lr_16: ;/* line 500 */
__LABEL(l_lr_16);
  sim_icache_fetch(381 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 502 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 503 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 504 */
   __ADD_CYCLES(1);
} /* line 504 */
  sim_icache_fetch(384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 507 */
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


static sim_fileinfo_t t_thisfile = {"convolution_7x7.s", 400, 0, 0, 0, 2};

