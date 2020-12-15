/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/6_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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

static unsigned int _X1PACKETX15[3];
unsigned int compress_10519Xoffset[1];
unsigned int compress_10519Xbuf[3];
unsigned int bytes_out[1];
unsigned int bgnd_flag[1];
unsigned int fsize[1];
unsigned int codetab[2502];
unsigned int htab[5003];
unsigned int maxcode[1];
unsigned int n_bits[1];
unsigned int buflen[1];
unsigned int bufp[1];
unsigned int outbuf[1];
unsigned int CompBuf[200];
unsigned int UnComp[210];

/*********************************
            ENTRY SYMBOLS
*********************************/

extern unsigned int __vex_main(  );
extern  Usage(  );
extern unsigned int rindex( unsigned int, unsigned int );
extern unsigned int Compress( unsigned int, unsigned int );
extern unsigned int compressf(  );
extern  output( unsigned int );
extern unsigned int decompress(  );
extern unsigned int compressgetcode(  );
extern unsigned int writeerr(  );
extern unsigned int foreground(  );
extern unsigned int onintr(  );
extern unsigned int oops(  );
extern unsigned int cl_block(  );
extern  cl_hash( unsigned int );
extern unsigned int prratio( unsigned int, unsigned int );
extern unsigned int version(  );
extern  _i_div(  );
extern  _bcopy(  );
extern  puts(  );

/*********************************
            DATA SYMBOLS
*********************************/

static unsigned int _X1PACKETX4[3]; 
static unsigned int _X1STRINGPACKETX1[5]; 
static unsigned int _X1STRINGPACKETX2[10]; 
static unsigned int _X1STRINGPACKETX4[4]; 
static unsigned int _X1XCompressXTAGPACKETX0[52]; 
static unsigned int _X1STRINGPACKETX5[8]; 
static unsigned int _X1STRINGPACKETX6[10]; 
static unsigned int _X1STRINGPACKETX3[5]; 
static unsigned int _X1PACKETX14[1]; 
static unsigned int _X1PACKETX13[1]; 
static unsigned int _X1STRINGPACKETX8[7]; 
static unsigned int _X1STRINGPACKETX9[7]; 
unsigned int compress_10519XBuf[216]; 
unsigned int compress_10519Xrcs_ident[6]; 
unsigned int do_decomp[1]; 
unsigned int quiet[1]; 
unsigned int nomagic[1]; 
unsigned int block_compress[1]; 
unsigned int zcat_flg[1]; 
unsigned int maxbits[1]; 
unsigned int maxmaxcode[1]; 
unsigned int hsize[1]; 
unsigned int magic_header[1]; 
unsigned int free_ent[1]; 
unsigned int checkpoint[1]; 
unsigned int in_count[1]; 
unsigned int ratio[1]; 
unsigned int clear_flg[1]; 
unsigned int out_count[1]; 
unsigned int exit_stat[1]; 
unsigned int lmask[3]; 
unsigned int rmask[3]; 
unsigned int force[1]; 
static unsigned int _X1PACKETX4[3] = { 
	0x436F6D70,
	0x72657373,
	0x00000000
}; 

static unsigned int _X1STRINGPACKETX1[5] = { 
	0x636F6D70,
	0x72657373,
	0x3A207375,
	0x63636573,
	0x730A0000
}; 

static unsigned int _X1STRINGPACKETX2[10] = { 
	0x55736167,
	0x653A2063,
	0x6F6D7072,
	0x65737320,
	0x5B2D6466,
	0x7663565D,
	0x205B2D62,
	0x206D6178,
	0x62697473,
	0x5D200A00
}; 

static unsigned int _X1STRINGPACKETX4[4] = { 
	0x556E6B6E,
	0x6F776E20,
	0x666C6167,
	0x00000000
}; 

static unsigned int _X1XCompressXTAGPACKETX0[52] = { 
	(149 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(163 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(155 << 5),
	(154 << 5),
	(153 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(152 << 5),
	(167 << 5),
	(167 << 5),
	(151 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(167 << 5),
	(150 << 5)
}; 

static unsigned int _X1STRINGPACKETX5[8] = { 
	0x44617461,
	0x206E6F74,
	0x20696E20,
	0x636F6D70,
	0x72657373,
	0x65642066,
	0x6F726D61,
	0x740A0000
}; 

static unsigned int _X1STRINGPACKETX6[10] = { 
	0x73746469,
	0x6E3A2063,
	0x6F6D7072,
	0x65737365,
	0x64207769,
	0x74682074,
	0x6F6F206D,
	0x616E7920,
	0x62697473,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX3[5] = { 
	0x4D697373,
	0x696E6720,
	0x6D617862,
	0x6974730A,
	0x00000000
}; 

static unsigned int _X1PACKETX14[1] = { 
	0x00000000
}; 

static unsigned int _X1PACKETX13[1] = { 
	0x00000000
}; 

static unsigned int _X1STRINGPACKETX8[7] = { 
	0x4552524F,
	0x523A2077,
	0x72697465,
	0x72722077,
	0x61732063,
	0x616C6C65,
	0x640A0000
}; 

static unsigned int _X1STRINGPACKETX9[7] = { 
	0x756E636F,
	0x6D707265,
	0x73733A20,
	0x636F7272,
	0x75707420,
	0x696E7075,
	0x740A0000
}; 

unsigned int compress_10519XBuf[216] = { 
	0x2F2A2052,
	0x65706C61,
	0x63656D65,
	0x6E742072,
	0x6F757469,
	0x6E657320,
	0x666F7220,
	0x7374616E,
	0x64617264,
	0x20432072,
	0x6F757469,
	0x6E65732E,
	0x202A2F00,
	0x23646566,
	0x696E6520,
	0x434F4E53,
	0x4F4C4520,
	0x30002369,
	0x666E6465,
	0x66205355,
	0x4E002364,
	0x6566696E,
	0x65207374,
	0x64657272,
	0x20434F4E,
	0x534F4C45,
	0x00236465,
	0x66696E65,
	0x20454F46,
	0x20282D31,
	0x29002365,
	0x6E646966,
	0x202F2A20,
	0x53554E20,
	0x2A2F0000,
	0x23696E63,
	0x6C756465,
	0x20226275,
	0x662E6322,
	0x00006368,
	0x61722A20,
	0x6F757462,
	0x7566203D,
	0x20303B00,
	0x00696E74,
	0x20676574,
	0x63686172,
	0x2829007B,
	0x20737461,
	0x74696320,
	0x63686172,
	0x202A6275,
	0x6670203D,
	0x20427566,
	0x3B002020,
	0x73746174,
	0x69632069,
	0x6E74206E,
	0x203D2042,
	0x75666C65,
	0x6E3B0023,
	0x69666465,
	0x66205445,
	0x53540020,
	0x20696620,
	0x28206E20,
	0x3D3D2030,
	0x2029207B,
	0x2020202F,
	0x2A206275,
	0x66666572,
	0x20697320,
	0x656D7074,
	0x79202A2F,
	0x00202020,
	0x206E203D,
	0x20737472,
	0x746F6C20,
	0x28206275,
	0x66702C20,
	0x26627566,
	0x702C2031,
	0x3020293B,
	0x202F2A20,
	0x72656164,
	0x20636861,
	0x72207369,
	0x7A652066,
	0x726F6D20,
	0x31737420,
	0x73747269,
	0x6E672E20,
	0x2A2F0020,
	0x2020207D,
	0x0023656E,
	0x64696620,
	0x54455354,
	0x00202072,
	0x65747572,
	0x6E202820,
	0x2D2D6E20,
	0x3E3D2030,
	0x2029203F,
	0x2028756E,
	0x7369676E,
	0x65642063,
	0x68617229,
	0x202A6275,
	0x66702B2B,
	0x203A2045,
	0x4F463B00,
	0x7D202000,
	0x002F2A76,
	0x6F696420,
	0x70757463,
	0x68617220,
	0x28206329,
	0x00202063,
	0x68617220,
	0x633B007B,
	0x20002020,
	0x66707269,
	0x6E746628,
	0x73746465,
	0x72722C22,
	0x70757463,
	0x6861723A,
	0x2063203D,
	0x20257820,
	0x5C6E222C,
	0x2063293B,
	0x0020202A,
	0x6F757462,
	0x75662B2B,
	0x203D2063,
	0x3B007D00,
	0x202A2F00,
	0x2369666E,
	0x64656620,
	0x53554E00,
	0x766F6964,
	0x20657869,
	0x74282078,
	0x20290020,
	0x20696E74,
	0x20783B00,
	0x7B002020,
	0x66707269,
	0x6E746620,
	0x28737464,
	0x6572722C,
	0x20226578,
	0x69742830,
	0x78257829,
	0x5C6E222C,
	0x2078293B,
	0x00236966,
	0x64656620,
	0x58494E55,
	0x00202075,
	0x73657272,
	0x65742829,
	0x3B202020,
	0x20202020,
	0x20202020,
	0x20202020,
	0x2F2A204D,
	0x75737420,
	0x6C696E6B,
	0x20776974,
	0x68205849,
	0x4E553F20,
	0x2A2F0023,
	0x656E6469,
	0x66202F2A,
	0x2058494E,
	0x55202A2F,
	0x007D0020,
	0x00696E74,
	0x20707574,
	0x63282064,
	0x65762C20,
	0x20632920,
	0x20202F2A,
	0x20707574,
	0x63206465,
	0x66696E65,
	0x64206275,
	0x2058494E,
	0x552E202A,
	0x2F002020,
	0x696E7420,
	0x6465763B,
	0x00202063,
	0x68617220,
	0x633B007B,
	0x002F2A20,
	0x69662028,
	0x64657620,
	0x3D3D2043,
	0x4F4E534F,
	0x4C452920,
	0x202A2F00,
	0x7D002365,
	0x6E646966,
	0x202F2A20,
	0x53554E20,
	0x2A2F0078,
	0x66660078,
	0x66660078,
	0x66660078,
	0x66660078,
	0x66660078,
	0x66660078,
	0x66660078,
	0x66660000
}; 

unsigned int compress_10519Xrcs_ident[6] = { 
	0x48656164,
	0x65723A20,
	0x636F6D70,
	0x72657373,
	0x2E632C76,
	0x20000000
}; 

unsigned int do_decomp[1] = { 
	0x00000000
}; 

unsigned int quiet[1] = { 
	0x00000001
}; 

unsigned int nomagic[1] = { 
	0x00000000
}; 

unsigned int block_compress[1] = { 
	0x00000080
}; 

unsigned int zcat_flg[1] = { 
	0x00000000
}; 

unsigned int maxbits[1] = { 
	0x0000000C
}; 

unsigned int maxmaxcode[1] = { 
	0x00001000
}; 

unsigned int hsize[1] = { 
	0x0000138B
}; 

unsigned int magic_header[1] = { 
	0x1F9D0000
}; 

unsigned int free_ent[1] = { 
	0x00000000
}; 

unsigned int checkpoint[1] = { 
	0x00002710
}; 

unsigned int in_count[1] = { 
	0x00000001
}; 

unsigned int ratio[1] = { 
	0x00000000
}; 

unsigned int clear_flg[1] = { 
	0x00000000
}; 

unsigned int out_count[1] = { 
	0x00000000
}; 

unsigned int exit_stat[1] = { 
	0x00000000
}; 

unsigned int lmask[3] = { 
	0xFFFEFCF8,
	0xF0E0C080,
	0x00000000
}; 

unsigned int rmask[3] = { 
	0x00010307,
	0x0F1F3F7F,
	0xFF000000
}; 

unsigned int force[1] = { 
	0x00000000
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


extern unsigned int __vex_main(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(__vex_main);  sim_gprof_enter(&sim_gprof_idx,"__vex_main");

  sim_ta_init(1); /* enable cache simulation */
  reg_r0_1 = sim_create_stack(1048576,reg_r0_1); 

  sim_check_stack(reg_r0_1, -64); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (107 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(0 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 19 */
   __MOV(reg_r0_5, (unsigned int) 9); /* line 20 */
   __MOV(reg_r0_3, (unsigned int) _X1PACKETX4); /* line 21 */
} /* line 21 */
  sim_icache_fetch(4 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_1, (unsigned int) 16); /* line 23 */
   __ADD(reg_r0_4, reg_r0_1, (unsigned int) 28); /* line 24 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_l0_0); /* line 25 */
} /* line 25 */
		 /* line 26 */
  sim_icache_fetch(7 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_4); /* line 29 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_2); /* line 30 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_bcopy);
   reg_l0_0 = (107 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _bcopy;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 30 */
l_lr_1: ;/* line 30 */
__LABEL(l_lr_1);
  sim_icache_fetch(11 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), 0); /* line 32 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 33 */
   __MOV(reg_r0_6, (unsigned int) 800); /* line 34 */
   __MOV(reg_r0_5, (unsigned int) compress_10519XBuf); /* line 35 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 36 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 37 */
} /* line 37 */
  sim_icache_fetch(20 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 39 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_6); /* line 40 */
} /* line 40 */
		 /* line 41 */
  sim_icache_fetch(24 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_2); /* line 43 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Compress);
   reg_l0_0 = (107 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) Compress;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 44 */
l_lr_3: ;/* line 44 */
__LABEL(l_lr_3);
		 /* line 45 */
  sim_icache_fetch(27 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 48 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (107 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 48 */
l_lr_5: ;/* line 48 */
__LABEL(l_lr_5);
  sim_icache_fetch(31 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 50 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 51 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 52 */
   __ADD_CYCLES(1);
} /* line 52 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 55 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 102: goto l_lr_1;
    case 104: goto l_lr_3;
    case 106: goto l_lr_5;
    case 107:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern  Usage(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(Usage);  sim_gprof_enter(&sim_gprof_idx,"Usage");

  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (110 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(35 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 106 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX2); /* line 107 */
} /* line 107 */
		 /* line 108 */
  sim_icache_fetch(38 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 111 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (110 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 111 */
l_lr_8: ;/* line 111 */
__LABEL(l_lr_8);
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 113 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 114 */
   __ADD_CYCLES(1);
} /* line 114 */
  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Usage);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 117 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 109: goto l_lr_8;
    case 110:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int rindex( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(rindex);  sim_gprof_enter(&sim_gprof_idx,"rindex");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (144 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_25, reg_r0_3, (unsigned int) 15); /* line 178 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 14); /* line 179 */
   __ADD(reg_r0_23, reg_r0_3, (unsigned int) 13); /* line 180 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 12); /* line 181 */
   __ADD(reg_r0_21, reg_r0_3, (unsigned int) 11); /* line 182 */
} /* line 182 */
  sim_icache_fetch(49 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 10); /* line 184 */
   __ADD(reg_r0_19, reg_r0_3, (unsigned int) 9); /* line 185 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 8); /* line 186 */
   __ADD(reg_r0_17, reg_r0_3, (unsigned int) 7); /* line 187 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 6); /* line 188 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 189 */
} /* line 189 */
  sim_icache_fetch(55 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SXTB(reg_r0_4, reg_r0_4); /* line 191 */
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 192 */
   __MOV(reg_r0_5, 0); /* line 193 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 194 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 195 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 196 */
} /* line 196 */
  sim_icache_fetch(61 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_3); /* line 198 */
} /* line 198 */
l_L0X3: ;/* line 201 */
__LABEL(l_L0X3);
  sim_icache_fetch(62 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 202 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 203 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 204 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_10,0,1)); /* line 205 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_12,0,1)); /* line 206 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_14,0,1)); /* line 207 */
} /* line 207 */
  sim_icache_fetch(68 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBs(reg_r0_26, mem_trace_ld(reg_r0_16,0,1)); /* line 209 */
   __LDBs(reg_r0_27, mem_trace_ld(reg_r0_17,0,1)); /* line 210 */
   __LDBs(reg_r0_28, mem_trace_ld(reg_r0_18,0,1)); /* line 211 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_19,0,1)); /* line 212 */
   __LDBs(reg_r0_30, mem_trace_ld(reg_r0_20,0,1)); /* line 213 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_21,0,1)); /* line 214 */
} /* line 214 */
  sim_icache_fetch(74 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 216 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 217 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 218 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 219 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 220 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 221 */
} /* line 221 */
  sim_icache_fetch(80 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 223 */
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 224 */
   __CMPEQ(reg_b0_1, reg_r0_11, reg_r0_4); /* line 225 */
   __CMPNE(reg_b0_6, reg_r0_13, 0); /* line 226 */
   __CMPEQ(reg_b0_7, reg_r0_13, reg_r0_4); /* line 227 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 228 */
  sim_icache_fetch(86 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_6, reg_r0_3); /* line 230 */
   __CMPNE(reg_b0_2, reg_r0_15, 0); /* line 231 */
   __CMPEQ(reg_b0_3, reg_r0_15, reg_r0_4); /* line 232 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_22,0,1)); /* line 233 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_23,0,1)); /* line 234 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 235 */
  sim_icache_fetch(92 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_3, reg_b0_5, reg_r0_8, reg_r0_7); /* line 237 */
   __CMPNE(reg_b0_4, reg_r0_26, 0); /* line 238 */
   __CMPEQ(reg_b0_5, reg_r0_26, reg_r0_4); /* line 239 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_24,0,1)); /* line 240 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_25,0,1)); /* line 241 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 242 */
  sim_icache_fetch(98 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_10, reg_r0_3); /* line 244 */
   __CMPNE(reg_b0_0, reg_r0_27, 0); /* line 245 */
   __CMPEQ(reg_b0_1, reg_r0_27, reg_r0_4); /* line 246 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 247 */
   __ADD(reg_r0_26, reg_r0_24, (unsigned int) 16); /* line 248 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 249 */
  sim_icache_fetch(104 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_3, reg_b0_7, reg_r0_12, reg_r0_7); /* line 251 */
   __CMPNE(reg_b0_6, reg_r0_28, 0); /* line 252 */
   __CMPEQ(reg_b0_7, reg_r0_28, reg_r0_4); /* line 253 */
   __ADD(reg_r0_27, reg_r0_23, (unsigned int) 16); /* line 254 */
   __ADD(reg_r0_28, reg_r0_22, (unsigned int) 16); /* line 255 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 256 */
  sim_icache_fetch(110 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_14, reg_r0_3); /* line 258 */
   __CMPNE(reg_b0_2, reg_r0_29, 0); /* line 259 */
   __CMPEQ(reg_b0_3, reg_r0_29, reg_r0_4); /* line 260 */
   __ADD(reg_r0_29, reg_r0_21, (unsigned int) 16); /* line 261 */
   __ADD(reg_r0_32, reg_r0_20, (unsigned int) 16); /* line 262 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 263 */
  sim_icache_fetch(116 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_3, reg_b0_5, reg_r0_16, reg_r0_7); /* line 265 */
   __CMPNE(reg_b0_4, reg_r0_30, 0); /* line 266 */
   __CMPEQ(reg_b0_5, reg_r0_30, reg_r0_4); /* line 267 */
   __ADD(reg_r0_30, reg_r0_19, (unsigned int) 16); /* line 268 */
   __ADD(reg_r0_33, reg_r0_18, (unsigned int) 16); /* line 269 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 270 */
  sim_icache_fetch(122 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_17, reg_r0_3); /* line 272 */
   __CMPNE(reg_b0_0, reg_r0_31, 0); /* line 273 */
   __CMPEQ(reg_b0_1, reg_r0_31, reg_r0_4); /* line 274 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 275 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 276 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 277 */
  sim_icache_fetch(128 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_18, reg_b0_7, reg_r0_18, reg_r0_7); /* line 279 */
   __CMPNE(reg_b0_6, reg_r0_9, 0); /* line 280 */
   __CMPEQ(reg_b0_7, reg_r0_9, reg_r0_4); /* line 281 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 282 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 283 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 284 */
  sim_icache_fetch(134 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_19, reg_b0_3, reg_r0_19, reg_r0_18); /* line 286 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 287 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 288 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 289 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 290 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 291 */
  sim_icache_fetch(140 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_20, reg_b0_5, reg_r0_20, reg_r0_19); /* line 293 */
   __CMPNE(reg_b0_4, reg_r0_13, 0); /* line 294 */
   __CMPEQ(reg_b0_5, reg_r0_13, reg_r0_4); /* line 295 */
   __ADD(reg_r0_3, reg_r0_25, (unsigned int) 16); /* line 296 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 297 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 298 */
  sim_icache_fetch(146 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_21, reg_b0_1, reg_r0_21, reg_r0_20); /* line 300 */
   __CMPNE(reg_b0_0, reg_r0_15, 0); /* line 301 */
   __CMPEQ(reg_b0_1, reg_r0_15, reg_r0_4); /* line 302 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_2,0,1)); /* line 303 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_6,0,1)); /* line 304 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 305 */
  sim_icache_fetch(152 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_22, reg_b0_7, reg_r0_22, reg_r0_21); /* line 307 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_8,0,1)); /* line 308 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_10,0,1)); /* line 309 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_12,0,1)); /* line 310 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_14,0,1)); /* line 311 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 312 */
  sim_icache_fetch(158 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_23, reg_b0_3, reg_r0_23, reg_r0_22); /* line 314 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 315 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 316 */
   __CMPNE(reg_b0_6, reg_r0_9, 0); /* line 317 */
   __CMPEQ(reg_b0_7, reg_r0_9, reg_r0_4); /* line 318 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 319 */
  sim_icache_fetch(164 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_24, reg_b0_5, reg_r0_24, reg_r0_23); /* line 321 */
   __CMPNE(reg_b0_4, reg_r0_11, 0); /* line 322 */
   __CMPEQ(reg_b0_5, reg_r0_11, reg_r0_4); /* line 323 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_16,0,1)); /* line 324 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_17,0,1)); /* line 325 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 326 */
  sim_icache_fetch(170 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_5, reg_b0_1, reg_r0_25, reg_r0_24); /* line 328 */
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 329 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 330 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_33,0,1)); /* line 331 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_30,0,1)); /* line 332 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 333 */
  sim_icache_fetch(176 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_34, reg_b0_3, reg_r0_2, reg_r0_5); /* line 335 */
   __CMPNE(reg_b0_2, reg_r0_15, 0); /* line 336 */
   __CMPEQ(reg_b0_3, reg_r0_15, reg_r0_4); /* line 337 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_32,0,1)); /* line 338 */
   __LDBs(reg_r0_35, mem_trace_ld(reg_r0_29,0,1)); /* line 339 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 340 */
  sim_icache_fetch(182 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_36, reg_b0_7, reg_r0_6, reg_r0_34); /* line 342 */
   __CMPNE(reg_b0_6, reg_r0_31, 0); /* line 343 */
   __CMPEQ(reg_b0_7, reg_r0_31, reg_r0_4); /* line 344 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_28,0,1)); /* line 345 */
   __LDBs(reg_r0_37, mem_trace_ld(reg_r0_27,0,1)); /* line 346 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 347 */
  sim_icache_fetch(188 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_34, reg_b0_5, reg_r0_8, reg_r0_36); /* line 349 */
   __CMPNE(reg_b0_4, reg_r0_7, 0); /* line 350 */
   __CMPEQ(reg_b0_5, reg_r0_7, reg_r0_4); /* line 351 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_26,0,1)); /* line 352 */
   __LDBs(reg_r0_38, mem_trace_ld(reg_r0_3,0,1)); /* line 353 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 354 */
  sim_icache_fetch(194 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_36, reg_b0_1, reg_r0_10, reg_r0_34); /* line 356 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 357 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_4); /* line 358 */
   __ADD(reg_r0_9, reg_r0_12, (unsigned int) 16); /* line 359 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 360 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 361 */
  sim_icache_fetch(200 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_12, reg_b0_3, reg_r0_12, reg_r0_36); /* line 363 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 364 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 365 */
   __ADD(reg_r0_19, reg_r0_30, (unsigned int) 16); /* line 366 */
   __ADD(reg_r0_11, reg_r0_14, (unsigned int) 16); /* line 367 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 368 */
  sim_icache_fetch(206 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_14, reg_b0_7, reg_r0_14, reg_r0_12); /* line 370 */
   __CMPNE(reg_b0_6, reg_r0_13, 0); /* line 371 */
   __CMPEQ(reg_b0_7, reg_r0_13, reg_r0_4); /* line 372 */
   __ADD(reg_r0_21, reg_r0_29, (unsigned int) 16); /* line 373 */
   __ADD(reg_r0_20, reg_r0_32, (unsigned int) 16); /* line 374 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 375 */
  sim_icache_fetch(212 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_13, reg_b0_5, reg_r0_16, reg_r0_14); /* line 377 */
   __CMPNE(reg_b0_4, reg_r0_15, 0); /* line 378 */
   __CMPEQ(reg_b0_5, reg_r0_15, reg_r0_4); /* line 379 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 380 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 381 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 382 */
  sim_icache_fetch(218 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_15, reg_b0_1, reg_r0_17, reg_r0_13); /* line 384 */
   __CMPNE(reg_b0_0, reg_r0_35, 0); /* line 385 */
   __CMPEQ(reg_b0_1, reg_r0_35, reg_r0_4); /* line 386 */
   __ADD(reg_r0_18, reg_r0_33, (unsigned int) 16); /* line 387 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 388 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 389 */
  sim_icache_fetch(224 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_33, reg_b0_3, reg_r0_33, reg_r0_15); /* line 391 */
   __CMPNE(reg_b0_2, reg_r0_31, 0); /* line 392 */
   __CMPEQ(reg_b0_3, reg_r0_31, reg_r0_4); /* line 393 */
   __ADD(reg_r0_23, reg_r0_27, (unsigned int) 16); /* line 394 */
   __ADD(reg_r0_22, reg_r0_28, (unsigned int) 16); /* line 395 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 396 */
  sim_icache_fetch(230 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_30, reg_b0_7, reg_r0_30, reg_r0_33); /* line 398 */
   __CMPNE(reg_b0_6, reg_r0_37, 0); /* line 399 */
   __CMPEQ(reg_b0_7, reg_r0_37, reg_r0_4); /* line 400 */
   __ADD(reg_r0_24, reg_r0_26, (unsigned int) 16); /* line 401 */
   __ADD(reg_r0_25, reg_r0_3, (unsigned int) 16); /* line 402 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 403 */
  sim_icache_fetch(236 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_32, reg_b0_5, reg_r0_32, reg_r0_30); /* line 405 */
   __CMPNE(reg_b0_4, reg_r0_7, 0); /* line 406 */
   __CMPEQ(reg_b0_5, reg_r0_7, reg_r0_4); /* line 407 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 408 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 409 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 410 */
  sim_icache_fetch(242 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_29, reg_b0_1, reg_r0_29, reg_r0_32); /* line 412 */
   __CMPNE(reg_b0_0, reg_r0_38, 0); /* line 413 */
   __CMPEQ(reg_b0_1, reg_r0_38, reg_r0_4); /* line 414 */
   __MOV(reg_r0_12, reg_r0_9); /* line 415 */
   __MOV(reg_r0_14, reg_r0_11); /* line 416 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 417 */
  sim_icache_fetch(248 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_28, reg_b0_3, reg_r0_28, reg_r0_29); /* line 419 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 420 */
  sim_icache_fetch(250 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_27, reg_b0_7, reg_r0_27, reg_r0_28); /* line 422 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 423 */
  sim_icache_fetch(252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_26, reg_b0_5, reg_r0_26, reg_r0_27); /* line 425 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 426 */
  sim_icache_fetch(254 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_1, reg_r0_3, reg_r0_26); /* line 428 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 430 */
  sim_icache_fetch(256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 432 */
l_L32X3: ;/* line 435 */
__LABEL(l_L32X3);
  sim_icache_fetch(257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_26); /* line 437 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 438 */
l_L31X3: ;/* line 441 */
__LABEL(l_L31X3);
  sim_icache_fetch(259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_27); /* line 443 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 444 */
l_L30X3: ;/* line 447 */
__LABEL(l_L30X3);
  sim_icache_fetch(261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_28); /* line 448 */
} /* line 448 */
l_L14X3: ;/* line 451 */
__LABEL(l_L14X3);
  sim_icache_fetch(262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_22); /* line 453 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 454 */
l_L29X3: ;/* line 457 */
__LABEL(l_L29X3);
  sim_icache_fetch(264 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_29); /* line 459 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 460 */
l_L28X3: ;/* line 463 */
__LABEL(l_L28X3);
  sim_icache_fetch(266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_32); /* line 465 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 466 */
l_L27X3: ;/* line 469 */
__LABEL(l_L27X3);
  sim_icache_fetch(268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_19, reg_r0_30); /* line 470 */
} /* line 470 */
l_L11X3: ;/* line 473 */
__LABEL(l_L11X3);
  sim_icache_fetch(269 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_19); /* line 475 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 476 */
l_L26X3: ;/* line 479 */
__LABEL(l_L26X3);
  sim_icache_fetch(271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_33); /* line 480 */
} /* line 480 */
l_L10X3: ;/* line 483 */
__LABEL(l_L10X3);
  sim_icache_fetch(272 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_18); /* line 485 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 486 */
l_L25X3: ;/* line 489 */
__LABEL(l_L25X3);
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_15); /* line 490 */
} /* line 490 */
l_L9X3: ;/* line 493 */
__LABEL(l_L9X3);
  sim_icache_fetch(275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 495 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 496 */
l_L24X3: ;/* line 499 */
__LABEL(l_L24X3);
  sim_icache_fetch(277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_13); /* line 500 */
} /* line 500 */
l_L8X3: ;/* line 503 */
__LABEL(l_L8X3);
  sim_icache_fetch(278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 506 */
l_L23X3: ;/* line 509 */
__LABEL(l_L23X3);
  sim_icache_fetch(279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_14); /* line 510 */
} /* line 510 */
l_L7X3: ;/* line 513 */
__LABEL(l_L7X3);
  sim_icache_fetch(280 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 515 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 516 */
l_L22X3: ;/* line 519 */
__LABEL(l_L22X3);
  sim_icache_fetch(282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_12); /* line 520 */
} /* line 520 */
l_L6X3: ;/* line 523 */
__LABEL(l_L6X3);
  sim_icache_fetch(283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 526 */
l_L21X3: ;/* line 529 */
__LABEL(l_L21X3);
  sim_icache_fetch(284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_36); /* line 530 */
} /* line 530 */
l_L5X3: ;/* line 533 */
__LABEL(l_L5X3);
  sim_icache_fetch(285 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 535 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 536 */
l_L20X3: ;/* line 539 */
__LABEL(l_L20X3);
  sim_icache_fetch(287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_34); /* line 540 */
} /* line 540 */
l_L4X3: ;/* line 543 */
__LABEL(l_L4X3);
  sim_icache_fetch(288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 546 */
l_L19X3: ;/* line 549 */
__LABEL(l_L19X3);
  sim_icache_fetch(289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_36); /* line 551 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 552 */
l_L18X3: ;/* line 555 */
__LABEL(l_L18X3);
  sim_icache_fetch(291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_34); /* line 557 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 558 */
l_L17X3: ;/* line 561 */
__LABEL(l_L17X3);
  sim_icache_fetch(293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 561 */
l_L1X3: ;/* line 564 */
__LABEL(l_L1X3);
  sim_icache_fetch(294 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 566 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 567 */
l_L16X3: ;/* line 570 */
__LABEL(l_L16X3);
  sim_icache_fetch(296 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_24); /* line 572 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 573 */
l_L15X3: ;/* line 576 */
__LABEL(l_L15X3);
  sim_icache_fetch(298 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_23); /* line 578 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 579 */
l_L13X3: ;/* line 582 */
__LABEL(l_L13X3);
  sim_icache_fetch(300 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_21); /* line 584 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 585 */
l_L12X3: ;/* line 588 */
__LABEL(l_L12X3);
  sim_icache_fetch(302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_20); /* line 590 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 591 */
l_L3X3: ;/* line 594 */
__LABEL(l_L3X3);
  sim_icache_fetch(304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 596 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 597 */
l_L2X3: ;/* line 600 */
__LABEL(l_L2X3);
  sim_icache_fetch(306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 603 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 111: goto l_L0X3;
    case 112: goto l_L32X3;
    case 113: goto l_L31X3;
    case 114: goto l_L30X3;
    case 115: goto l_L14X3;
    case 116: goto l_L29X3;
    case 117: goto l_L28X3;
    case 118: goto l_L27X3;
    case 119: goto l_L11X3;
    case 120: goto l_L26X3;
    case 121: goto l_L10X3;
    case 122: goto l_L25X3;
    case 123: goto l_L9X3;
    case 124: goto l_L24X3;
    case 125: goto l_L8X3;
    case 126: goto l_L23X3;
    case 127: goto l_L7X3;
    case 128: goto l_L22X3;
    case 129: goto l_L6X3;
    case 130: goto l_L21X3;
    case 131: goto l_L5X3;
    case 132: goto l_L20X3;
    case 133: goto l_L4X3;
    case 134: goto l_L19X3;
    case 135: goto l_L18X3;
    case 136: goto l_L17X3;
    case 137: goto l_L1X3;
    case 138: goto l_L16X3;
    case 139: goto l_L15X3;
    case 140: goto l_L13X3;
    case 141: goto l_L12X3;
    case 142: goto l_L3X3;
    case 143: goto l_L2X3;
    case 144:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int Compress( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(Compress);  sim_gprof_enter(&sim_gprof_idx,"Compress");

  sim_check_stack(reg_r0_1, -64); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (211 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(307 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 619 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 620 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 621 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 622 */
} /* line 622 */
  sim_icache_fetch(314 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 624 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 625 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 626 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 627 */
} /* line 627 */
  sim_icache_fetch(319 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 629 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 630 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 631 */
} /* line 631 */
		 /* line 632 */
  sim_icache_fetch(322 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 634 */
l_lr_45: ;/* line 634 */
__LABEL(l_lr_45);
  sim_icache_fetch(324 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 636 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 637 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 638 */
   __ADD_CYCLES(1);
} /* line 638 */
  sim_icache_fetch(327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 640 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 641 */
} /* line 641 */
l_L33X3: ;/* line 644 */
__LABEL(l_L33X3);
  sim_icache_fetch(329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 645 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 646 */
} /* line 646 */
  sim_icache_fetch(331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 648 */
  sim_icache_fetch(332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 650 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 651 */
   __ADD_CYCLES(1);
} /* line 651 */
  sim_icache_fetch(334 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 653 */
} /* line 653 */
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 655 */
l_L36X3: ;/* line 658 */
__LABEL(l_L36X3);
  sim_icache_fetch(336 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 659 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 660 */
   __ADD_CYCLES(1);
} /* line 660 */
  sim_icache_fetch(338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 662 */
} /* line 662 */
  sim_icache_fetch(339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 664 */
} /* line 664 */
  sim_icache_fetch(340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 666 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 667 */
   __ADD_CYCLES(1);
} /* line 667 */
  sim_icache_fetch(342 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 669 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 670 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 671 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 672 */
} /* line 672 */
  sim_icache_fetch(347 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 674 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 675 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 676 */
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 678 */
  sim_icache_fetch(351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 679 */
  sim_icache_fetch(352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 681 */
l__X1XCompressXTAGX0X0: ;/* line 683 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(353 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 684 */
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 685 */
l__X1XCompressXTAGX0X7: ;/* line 688 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(356 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 689 */
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 690 */
l__X1XCompressXTAGX0X6: ;/* line 693 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 694 */
} /* line 694 */
  sim_icache_fetch(360 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 696 */
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 697 */
l__X1XCompressXTAGX0X5: ;/* line 700 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(363 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 701 */
} /* line 701 */
  sim_icache_fetch(364 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 703 */
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 704 */
l__X1XCompressXTAGX0X4: ;/* line 707 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 708 */
} /* line 708 */
  sim_icache_fetch(368 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 710 */
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 711 */
l__X1XCompressXTAGX0X3: ;/* line 714 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 715 */
} /* line 715 */
  sim_icache_fetch(372 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 717 */
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 718 */
l__X1XCompressXTAGX0X2: ;/* line 721 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 722 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 723 */
   __ADD_CYCLES(1);
} /* line 723 */
  sim_icache_fetch(377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 725 */
} /* line 725 */
  sim_icache_fetch(378 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 727 */
} /* line 727 */
  sim_icache_fetch(379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 729 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 730 */
   __ADD_CYCLES(1);
} /* line 730 */
  sim_icache_fetch(381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 732 */
} /* line 732 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L39X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 734 */
l_L35X3: ;/* line 736 */
__LABEL(l_L35X3);
  sim_icache_fetch(383 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 737 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 738 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 739 */
l_L39X3: ;/* line 742 */
__LABEL(l_L39X3);
  sim_icache_fetch(386 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 743 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 744 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 745 */
} /* line 745 */
  sim_icache_fetch(389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 747 */
} /* line 747 */
  sim_icache_fetch(390 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 749 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 750 */
  sim_icache_fetch(392 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 753 */
  sim_icache_fetch(393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L35X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L35X3;
} /* line 755 */
l_L40X3: ;/* line 758 */
__LABEL(l_L40X3);
		 /* line 758 */
  sim_icache_fetch(394 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 761 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (211 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 761 */
l_lr_59: ;/* line 761 */
__LABEL(l_lr_59);
		 /* line 762 */
  sim_icache_fetch(398 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (211 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 764 */
l_lr_61: ;/* line 764 */
__LABEL(l_lr_61);
  sim_icache_fetch(400 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 766 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 767 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 768 */
   __ADD_CYCLES(1);
} /* line 768 */
  sim_icache_fetch(403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 771 */
l__X1XCompressXTAGX0X1: ;/* line 774 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 774 */
  sim_icache_fetch(404 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 777 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 778 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 778 */
l_lr_64: ;/* line 778 */
__LABEL(l_lr_64);
  sim_icache_fetch(408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 780 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 781 */
} /* line 781 */
  sim_icache_fetch(410 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 783 */
l_L38X3: ;/* line 786 */
__LABEL(l_L38X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 787 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 787 */
  sim_icache_fetch(411 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 790 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (211 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 790 */
l_lr_68: ;/* line 790 */
__LABEL(l_lr_68);
		 /* line 791 */
  sim_icache_fetch(415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (211 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 793 */
l_lr_70: ;/* line 793 */
__LABEL(l_lr_70);
  sim_icache_fetch(417 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 795 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 796 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 797 */
   __ADD_CYCLES(1);
} /* line 797 */
  sim_icache_fetch(420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 800 */
l_L37X3: ;/* line 803 */
__LABEL(l_L37X3);
  sim_icache_fetch(421 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L35X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L35X3;
} /* line 804 */
l_L34X3: ;/* line 807 */
__LABEL(l_L34X3);
  sim_icache_fetch(422 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 808 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 809 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 810 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 811 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 812 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 813 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 814 */
   __ADD_CYCLES(1);
} /* line 814 */
  sim_icache_fetch(432 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 816 */
   __CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 4096); /* line 817 */
} /* line 817 */
  sim_icache_fetch(435 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 819 */
  sim_icache_fetch(436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 821 */
} /* line 821 */
l_L42X3: ;/* line 823 */
__LABEL(l_L42X3);
  sim_icache_fetch(438 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 824 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 825 */
   __ADD_CYCLES(1);
} /* line 825 */
  sim_icache_fetch(441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 827 */
} /* line 827 */
  sim_icache_fetch(442 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L43X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 829 */
  sim_icache_fetch(443 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 831 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 832 */
} /* line 832 */
l_L44X3: ;/* line 834 */
__LABEL(l_L44X3);
  sim_icache_fetch(447 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 835 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 836 */
   __ADD_CYCLES(1);
} /* line 836 */
  sim_icache_fetch(450 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 838 */
} /* line 838 */
  sim_icache_fetch(451 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 840 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 841 */
		 /* line 842 */
  sim_icache_fetch(454 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 844 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 845 */
l_lr_76: ;/* line 845 */
__LABEL(l_lr_76);
l_L46X3: ;/* line 847 */
__LABEL(l_L46X3);
  sim_icache_fetch(458 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 848 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 849 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 850 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 851 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 852 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 853 */
} /* line 853 */
  sim_icache_fetch(470 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 855 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 856 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 857 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 858 */
} /* line 858 */
  sim_icache_fetch(478 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 860 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 861 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 862 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 863 */
} /* line 863 */
  sim_icache_fetch(483 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 865 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 866 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L47X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 867 */
  sim_icache_fetch(486 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 869 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 870 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 871 */
  sim_icache_fetch(490 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 873 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 874 */
l_L50X3: ;/* line 876 */
__LABEL(l_L50X3);
		 /* line 876 */
  sim_icache_fetch(493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (211 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 878 */
l_lr_80: ;/* line 878 */
__LABEL(l_lr_80);
  sim_icache_fetch(495 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 880 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 881 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 882 */
   __ADD_CYCLES(1);
} /* line 882 */
  sim_icache_fetch(498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 885 */
l_L49X3: ;/* line 888 */
__LABEL(l_L49X3);
  sim_icache_fetch(499 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 889 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 890 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 891 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 892 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 893 */
   __ADD_CYCLES(1);
} /* line 893 */
  sim_icache_fetch(508 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 895 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 896 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 897 */
} /* line 897 */
  sim_icache_fetch(511 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 899 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 900 */
} /* line 900 */
  sim_icache_fetch(514 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L51X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 902 */
  sim_icache_fetch(515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 904 */
} /* line 904 */
  sim_icache_fetch(517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 906 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 907 */
   __ADD_CYCLES(1);
} /* line 907 */
  sim_icache_fetch(519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 909 */
} /* line 909 */
l_L52X3: ;/* line 911 */
__LABEL(l_L52X3);
  sim_icache_fetch(520 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 912 */
} /* line 912 */
  sim_icache_fetch(521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L53X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 915 */
  sim_icache_fetch(522 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L50X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L50X3;
} /* line 917 */
l_L53X3: ;/* line 920 */
__LABEL(l_L53X3);
  sim_icache_fetch(523 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 921 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 922 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 923 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 924 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 925 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 926 */
   __ADD_CYCLES(1);
} /* line 926 */
  sim_icache_fetch(533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 928 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 929 */
} /* line 929 */
  sim_icache_fetch(535 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 931 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 932 */
} /* line 932 */
  sim_icache_fetch(538 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 934 */
  sim_icache_fetch(539 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 936 */
} /* line 936 */
  sim_icache_fetch(541 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 938 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 939 */
   __ADD_CYCLES(1);
} /* line 939 */
  sim_icache_fetch(543 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 941 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 942 */
} /* line 942 */
l_L55X3: ;/* line 944 */
__LABEL(l_L55X3);
  sim_icache_fetch(546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 945 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 946 */
} /* line 946 */
  sim_icache_fetch(548 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 948 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 949 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 950 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 951 */
} /* line 951 */
  sim_icache_fetch(554 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 953 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L47X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 954 */
		 /* line 955 */
  sim_icache_fetch(557 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (211 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 957 */
l_lr_86: ;/* line 957 */
__LABEL(l_lr_86);
  sim_icache_fetch(559 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 959 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 960 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 961 */
   __ADD_CYCLES(1);
} /* line 961 */
  sim_icache_fetch(562 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 964 */
l_L47X3: ;/* line 967 */
__LABEL(l_L47X3);
		 /* line 967 */
  sim_icache_fetch(563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 969 */
l_lr_89: ;/* line 969 */
__LABEL(l_lr_89);
  sim_icache_fetch(565 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 971 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 972 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 973 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 974 */
   __ADD_CYCLES(1);
} /* line 974 */
  sim_icache_fetch(569 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 977 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 978 */
l_L54X3: ;/* line 981 */
__LABEL(l_L54X3);
  sim_icache_fetch(572 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 982 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 983 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 984 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 985 */
} /* line 985 */
  sim_icache_fetch(578 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 987 */
   __GOTO(l_L55X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L55X3;
} /* line 988 */
l_L51X3: ;/* line 991 */
__LABEL(l_L51X3);
  sim_icache_fetch(581 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 992 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 993 */
   __GOTO(l_L52X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L52X3;
} /* line 994 */
l_L48X3: ;/* line 997 */
__LABEL(l_L48X3);
  sim_icache_fetch(585 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 998 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 999 */
} /* line 999 */
  sim_icache_fetch(588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1001 */
} /* line 1001 */
  sim_icache_fetch(589 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1004 */
  sim_icache_fetch(590 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L50X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L50X3;
} /* line 1006 */
l_L45X3: ;/* line 1009 */
__LABEL(l_L45X3);
  sim_icache_fetch(591 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1010 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1011 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1012 */
   __ADD_CYCLES(1);
} /* line 1012 */
  sim_icache_fetch(596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1014 */
} /* line 1014 */
  sim_icache_fetch(598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1016 */
		 /* line 1017 */
  sim_icache_fetch(599 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1019 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1020 */
l_lr_95: ;/* line 1020 */
__LABEL(l_lr_95);
  sim_icache_fetch(603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L46X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L46X3;
} /* line 1022 */
l_L56X3: ;/* line 1025 */
__LABEL(l_L56X3);
  sim_icache_fetch(604 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1026 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1027 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1028 */
   __ADD_CYCLES(1);
} /* line 1028 */
  sim_icache_fetch(609 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1030 */
} /* line 1030 */
  sim_icache_fetch(611 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1032 */
		 /* line 1033 */
  sim_icache_fetch(612 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1035 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1036 */
l_lr_98: ;/* line 1036 */
__LABEL(l_lr_98);
  sim_icache_fetch(616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L46X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L46X3;
} /* line 1038 */
l_L57X3: ;/* line 1041 */
__LABEL(l_L57X3);
  sim_icache_fetch(617 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1042 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1043 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1044 */
   __ADD_CYCLES(1);
} /* line 1044 */
  sim_icache_fetch(622 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1046 */
} /* line 1046 */
  sim_icache_fetch(624 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1048 */
		 /* line 1049 */
  sim_icache_fetch(625 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1051 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1052 */
l_lr_101: ;/* line 1052 */
__LABEL(l_lr_101);
  sim_icache_fetch(629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L46X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L46X3;
} /* line 1054 */
l_L58X3: ;/* line 1057 */
__LABEL(l_L58X3);
  sim_icache_fetch(630 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1058 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1059 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1060 */
   __ADD_CYCLES(1);
} /* line 1060 */
  sim_icache_fetch(635 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1062 */
} /* line 1062 */
  sim_icache_fetch(637 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1064 */
		 /* line 1065 */
  sim_icache_fetch(638 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1067 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1068 */
l_lr_104: ;/* line 1068 */
__LABEL(l_lr_104);
  sim_icache_fetch(642 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L46X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L46X3;
} /* line 1070 */
l_L59X3: ;/* line 1073 */
__LABEL(l_L59X3);
		 /* line 1073 */
  sim_icache_fetch(643 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (211 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1075 */
l_lr_107: ;/* line 1075 */
__LABEL(l_lr_107);
  sim_icache_fetch(645 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L46X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L46X3;
} /* line 1077 */
l_L43X3: ;/* line 1080 */
__LABEL(l_L43X3);
  sim_icache_fetch(646 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1081 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1082 */
} /* line 1082 */
  sim_icache_fetch(649 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1084 */
   __GOTO(l_L44X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L44X3;
} /* line 1085 */
l_L41X3: ;/* line 1088 */
__LABEL(l_L41X3);
  sim_icache_fetch(652 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1089 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1090 */
   __GOTO(l_L42X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L42X3;
} /* line 1091 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 146: goto l_lr_45;
    case 147: goto l_L33X3;
    case 148: goto l_L36X3;
    case 149: goto l__X1XCompressXTAGX0X0;
    case 150: goto l__X1XCompressXTAGX0X7;
    case 151: goto l__X1XCompressXTAGX0X6;
    case 152: goto l__X1XCompressXTAGX0X5;
    case 153: goto l__X1XCompressXTAGX0X4;
    case 154: goto l__X1XCompressXTAGX0X3;
    case 155: goto l__X1XCompressXTAGX0X2;
    case 156: goto l_L35X3;
    case 157: goto l_L39X3;
    case 158: goto l_L40X3;
    case 160: goto l_lr_59;
    case 162: goto l_lr_61;
    case 163: goto l__X1XCompressXTAGX0X1;
    case 165: goto l_lr_64;
    case 166: goto l_L38X3;
    case 167: goto l__X1XCompressXTAGX0XDEFAULT;
    case 169: goto l_lr_68;
    case 171: goto l_lr_70;
    case 172: goto l_L37X3;
    case 173: goto l_L34X3;
    case 174: goto l_L42X3;
    case 175: goto l_L44X3;
    case 177: goto l_lr_76;
    case 178: goto l_L46X3;
    case 179: goto l_L50X3;
    case 181: goto l_lr_80;
    case 182: goto l_L49X3;
    case 183: goto l_L52X3;
    case 184: goto l_L53X3;
    case 185: goto l_L55X3;
    case 187: goto l_lr_86;
    case 188: goto l_L47X3;
    case 190: goto l_lr_89;
    case 191: goto l_L54X3;
    case 192: goto l_L51X3;
    case 193: goto l_L48X3;
    case 194: goto l_L45X3;
    case 196: goto l_lr_95;
    case 197: goto l_L56X3;
    case 199: goto l_lr_98;
    case 200: goto l_L57X3;
    case 202: goto l_lr_101;
    case 203: goto l_L58X3;
    case 205: goto l_lr_104;
    case 206: goto l_L59X3;
    case 208: goto l_lr_107;
    case 209: goto l_L43X3;
    case 210: goto l_L41X3;
    case 211:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int compressf(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(compressf);  sim_gprof_enter(&sim_gprof_idx,"compressf");

  sim_check_stack(reg_r0_1, -64); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (330 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(655 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1229 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1230 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1231 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1232 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1233 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1234 */
} /* line 1234 */
  sim_icache_fetch(663 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1236 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1237 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1238 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1239 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1240 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1241 */
} /* line 1241 */
  sim_icache_fetch(674 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1243 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1244 */
   __MOV(reg_r0_4, 0); /* line 1245 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1246 */
} /* line 1246 */
  sim_icache_fetch(680 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 1248 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1249 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 1); /* line 1250 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1251 */
l_L61X3: ;/* line 1253 */
__LABEL(l_L61X3);
  sim_icache_fetch(684 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((unsigned int) compress_10519Xoffset,0,4), 0); /* line 1254 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1255 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1256 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1257 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, (unsigned int) 256); /* line 1258 */
   __CMPGE(reg_b0_1, reg_r0_13, 0); /* line 1259 */
} /* line 1259 */
  sim_icache_fetch(695 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1261 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1262 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1263 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1264 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1265 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1266 */
} /* line 1266 */
  sim_icache_fetch(707 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1268 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1269 */
  sim_icache_fetch(710 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 1271 */
} /* line 1271 */
  sim_icache_fetch(712 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1273 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1274 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1275 */
   __ADD_CYCLES(1);
} /* line 1275 */
  sim_icache_fetch(715 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1277 */
} /* line 1277 */
l_L63X3: ;/* line 1279 */
__LABEL(l_L63X3);
  sim_icache_fetch(716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1280 */
} /* line 1280 */
l_L64X3: ;/* line 1283 */
__LABEL(l_L64X3);
  sim_icache_fetch(717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1284 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1285 */
} /* line 1285 */
  sim_icache_fetch(719 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1287 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1288 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1289 */
  sim_icache_fetch(722 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1291 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1292 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1293 */
  sim_icache_fetch(725 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1295 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1296 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1297 */
  sim_icache_fetch(728 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1299 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1300 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1301 */
  sim_icache_fetch(731 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1303 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1304 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1305 */
  sim_icache_fetch(734 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1307 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1308 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1309 */
  sim_icache_fetch(737 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1311 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1312 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1313 */
  sim_icache_fetch(740 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1315 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1316 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1317 */
  sim_icache_fetch(743 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1319 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1320 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1321 */
  sim_icache_fetch(746 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1323 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1324 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1325 */
  sim_icache_fetch(749 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1327 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1328 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1329 */
  sim_icache_fetch(752 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1331 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1332 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1333 */
  sim_icache_fetch(755 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1335 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1336 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1337 */
  sim_icache_fetch(758 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1339 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1340 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1341 */
  sim_icache_fetch(761 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1343 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1344 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1345 */
  sim_icache_fetch(764 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1347 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1348 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1349 */
  sim_icache_fetch(767 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1351 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1352 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1353 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1354 */
  sim_icache_fetch(771 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1356 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1357 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1358 */
  sim_icache_fetch(774 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1360 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1361 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1362 */
  sim_icache_fetch(777 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1364 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1365 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1366 */
  sim_icache_fetch(780 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1368 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1369 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1370 */
  sim_icache_fetch(783 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1372 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1373 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1374 */
  sim_icache_fetch(786 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1376 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1377 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1378 */
  sim_icache_fetch(789 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1380 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1381 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1382 */
  sim_icache_fetch(792 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1384 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1385 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1386 */
  sim_icache_fetch(795 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1388 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1389 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1390 */
  sim_icache_fetch(798 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1392 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1393 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1394 */
  sim_icache_fetch(801 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1396 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1397 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1398 */
  sim_icache_fetch(804 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1400 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1401 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1402 */
  sim_icache_fetch(807 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1404 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1405 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1406 */
  sim_icache_fetch(810 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1408 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1409 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1410 */
  sim_icache_fetch(813 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1412 */
  sim_icache_fetch(814 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1414 */
   __GOTO(l_L64X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L64X3;
} /* line 1415 */
l_L80X3: ;/* line 1418 */
__LABEL(l_L80X3);
  sim_icache_fetch(816 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1419 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1420 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1421 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1422 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1423 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 1424 */
l_L82X3: ;/* line 1427 */
__LABEL(l_L82X3);
  sim_icache_fetch(823 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1428 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1429 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1430 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1431 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1432 */
   __ADD_CYCLES(1);
} /* line 1432 */
  sim_icache_fetch(832 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1434 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1435 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1436 */
} /* line 1436 */
  sim_icache_fetch(835 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1438 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1439 */
} /* line 1439 */
  sim_icache_fetch(838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1441 */
  sim_icache_fetch(839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1443 */
} /* line 1443 */
  sim_icache_fetch(841 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1445 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1446 */
   __ADD_CYCLES(1);
} /* line 1446 */
  sim_icache_fetch(843 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1448 */
} /* line 1448 */
l_L84X3: ;/* line 1450 */
__LABEL(l_L84X3);
  sim_icache_fetch(844 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1451 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1452 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1453 */
} /* line 1453 */
  sim_icache_fetch(847 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1455 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1456 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L85X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1457 */
  sim_icache_fetch(850 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1459 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1460 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1461 */
} /* line 1461 */
  sim_icache_fetch(856 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1463 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1464 */
   __ADD_CYCLES(1);
} /* line 1464 */
  sim_icache_fetch(858 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(859 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1468 */
  sim_icache_fetch(860 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1470 */
} /* line 1470 */
  sim_icache_fetch(861 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1472 */
l_L86X3: ;/* line 1475 */
__LABEL(l_L86X3);
  sim_icache_fetch(862 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1476 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1477 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1478 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1479 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1480 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1481 */
} /* line 1481 */
  sim_icache_fetch(869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1483 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1484 */
   __ADD_CYCLES(1);
} /* line 1484 */
  sim_icache_fetch(871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1486 */
} /* line 1486 */
  sim_icache_fetch(872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1488 */
l_L88X3: ;/* line 1490 */
__LABEL(l_L88X3);
		 /* line 1490 */
  sim_icache_fetch(873 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (330 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1492 */
l_lr_120: ;/* line 1492 */
__LABEL(l_lr_120);
  sim_icache_fetch(875 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1494 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1495 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1496 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1497 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1498 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1499 */
} /* line 1499 */
  sim_icache_fetch(884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1501 */
} /* line 1501 */
  sim_icache_fetch(885 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1503 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1504 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1505 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1506 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1507 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1508 */
} /* line 1508 */
  sim_icache_fetch(893 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1510 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1511 */
  sim_icache_fetch(896 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1513 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1514 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1515 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1516 */
l_L89X3: ;/* line 1519 */
__LABEL(l_L89X3);
  sim_icache_fetch(901 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1520 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1521 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1522 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1523 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1524 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1525 */
   __ADD_CYCLES(1);
} /* line 1525 */
  sim_icache_fetch(910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1527 */
} /* line 1527 */
  sim_icache_fetch(911 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1529 */
} /* line 1529 */
  sim_icache_fetch(912 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1531 */
		 /* line 1532 */
  sim_icache_fetch(913 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (330 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1534 */
l_lr_123: ;/* line 1534 */
__LABEL(l_lr_123);
  sim_icache_fetch(915 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1536 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1537 */
} /* line 1537 */
  sim_icache_fetch(917 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1539 */
l_L90X3: ;/* line 1542 */
__LABEL(l_L90X3);
  sim_icache_fetch(918 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1543 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1544 */
} /* line 1544 */
  sim_icache_fetch(920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1546 */
l_L87X3: ;/* line 1549 */
__LABEL(l_L87X3);
  sim_icache_fetch(921 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1550 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1551 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1552 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1553 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1554 */
   __ADD_CYCLES(1);
} /* line 1554 */
  sim_icache_fetch(926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1556 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1557 */
} /* line 1557 */
  sim_icache_fetch(928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1559 */
} /* line 1559 */
l_L91X3: ;/* line 1562 */
__LABEL(l_L91X3);
  sim_icache_fetch(929 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1563 */
} /* line 1563 */
  sim_icache_fetch(930 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1565 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1566 */
} /* line 1566 */
  sim_icache_fetch(932 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1568 */
} /* line 1568 */
  sim_icache_fetch(933 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1570 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1571 */
} /* line 1571 */
  sim_icache_fetch(936 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1573 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1574 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1575 */
} /* line 1575 */
  sim_icache_fetch(939 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1577 */
} /* line 1577 */
  sim_icache_fetch(940 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1579 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1580 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1581 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1582 */
} /* line 1582 */
  sim_icache_fetch(945 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1584 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1585 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1586 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1587 */
  sim_icache_fetch(949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1589 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1590 */
  sim_icache_fetch(951 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1592 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1593 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1594 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1595 */
} /* line 1595 */
  sim_icache_fetch(956 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1597 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1598 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1599 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1600 */
  sim_icache_fetch(960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1602 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1603 */
  sim_icache_fetch(962 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1605 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1606 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1607 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1608 */
} /* line 1608 */
  sim_icache_fetch(967 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1610 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1611 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1612 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1613 */
  sim_icache_fetch(971 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1615 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1616 */
  sim_icache_fetch(973 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1618 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1619 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1620 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1621 */
} /* line 1621 */
  sim_icache_fetch(978 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1623 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1624 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1625 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1626 */
  sim_icache_fetch(982 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1628 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1629 */
  sim_icache_fetch(984 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1631 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1632 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1633 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1634 */
} /* line 1634 */
  sim_icache_fetch(989 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1636 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1637 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1638 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1639 */
  sim_icache_fetch(993 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1641 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1642 */
  sim_icache_fetch(995 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1644 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1645 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1646 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1647 */
} /* line 1647 */
  sim_icache_fetch(1000 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1649 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1650 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1651 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1652 */
  sim_icache_fetch(1004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1654 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1655 */
  sim_icache_fetch(1006 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1657 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1658 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1659 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1660 */
} /* line 1660 */
  sim_icache_fetch(1011 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1662 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1663 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1664 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1665 */
  sim_icache_fetch(1015 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1667 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1668 */
  sim_icache_fetch(1017 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1670 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1671 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1672 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1673 */
} /* line 1673 */
  sim_icache_fetch(1022 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1675 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1676 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1677 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1678 */
  sim_icache_fetch(1026 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1680 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1681 */
  sim_icache_fetch(1028 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1683 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1684 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1685 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1686 */
} /* line 1686 */
  sim_icache_fetch(1033 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1688 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1689 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1690 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1691 */
  sim_icache_fetch(1037 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1693 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1694 */
  sim_icache_fetch(1039 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1696 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1697 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1698 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1699 */
} /* line 1699 */
  sim_icache_fetch(1044 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1701 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1702 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1703 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1704 */
  sim_icache_fetch(1048 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1706 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1707 */
  sim_icache_fetch(1050 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1709 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1710 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1711 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1712 */
} /* line 1712 */
  sim_icache_fetch(1055 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1714 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1715 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1716 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1717 */
  sim_icache_fetch(1059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1719 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1720 */
  sim_icache_fetch(1061 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1722 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1723 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1724 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1725 */
} /* line 1725 */
  sim_icache_fetch(1066 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1727 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1728 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1729 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1730 */
  sim_icache_fetch(1070 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1732 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1733 */
  sim_icache_fetch(1072 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1735 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1736 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1737 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1738 */
} /* line 1738 */
  sim_icache_fetch(1077 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1740 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1741 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1742 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1743 */
  sim_icache_fetch(1081 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1745 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1746 */
  sim_icache_fetch(1083 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1748 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1749 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1750 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1751 */
} /* line 1751 */
  sim_icache_fetch(1088 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1753 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1754 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1755 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1756 */
  sim_icache_fetch(1092 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1758 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1759 */
  sim_icache_fetch(1094 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1761 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1762 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1763 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1764 */
} /* line 1764 */
  sim_icache_fetch(1099 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1766 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1767 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1768 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1769 */
  sim_icache_fetch(1103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1771 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1772 */
  sim_icache_fetch(1105 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1774 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1775 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1776 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1777 */
} /* line 1777 */
  sim_icache_fetch(1110 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1779 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1780 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1781 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1782 */
  sim_icache_fetch(1114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1784 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1785 */
  sim_icache_fetch(1116 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1787 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1788 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1789 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1790 */
} /* line 1790 */
  sim_icache_fetch(1121 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1792 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1793 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1794 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1795 */
  sim_icache_fetch(1125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1797 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1798 */
  sim_icache_fetch(1127 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1800 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1801 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1802 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1803 */
} /* line 1803 */
  sim_icache_fetch(1132 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1805 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1806 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1807 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1808 */
  sim_icache_fetch(1136 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1810 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1811 */
  sim_icache_fetch(1138 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1813 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1814 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1815 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1816 */
} /* line 1816 */
  sim_icache_fetch(1143 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1818 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1819 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1820 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1821 */
  sim_icache_fetch(1147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1823 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1824 */
  sim_icache_fetch(1149 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1826 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1827 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1828 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1829 */
} /* line 1829 */
  sim_icache_fetch(1154 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1831 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1832 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1833 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1834 */
  sim_icache_fetch(1158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1836 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1837 */
  sim_icache_fetch(1160 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1839 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1840 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1841 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1842 */
} /* line 1842 */
  sim_icache_fetch(1165 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1844 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1845 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1846 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1847 */
  sim_icache_fetch(1169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1849 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1850 */
  sim_icache_fetch(1171 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1852 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1853 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1854 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1855 */
} /* line 1855 */
  sim_icache_fetch(1176 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1857 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1858 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1859 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1860 */
  sim_icache_fetch(1180 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1862 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1863 */
  sim_icache_fetch(1182 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1865 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1866 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1867 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1868 */
} /* line 1868 */
  sim_icache_fetch(1187 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1870 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1871 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1872 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1873 */
  sim_icache_fetch(1191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1875 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1876 */
  sim_icache_fetch(1193 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1878 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1879 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1880 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1881 */
} /* line 1881 */
  sim_icache_fetch(1198 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1883 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1884 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1885 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1886 */
  sim_icache_fetch(1202 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1888 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1889 */
  sim_icache_fetch(1204 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1891 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1892 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1893 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1894 */
} /* line 1894 */
  sim_icache_fetch(1209 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1896 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1897 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1898 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1899 */
  sim_icache_fetch(1213 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1901 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1902 */
  sim_icache_fetch(1215 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1904 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1905 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1906 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1907 */
} /* line 1907 */
  sim_icache_fetch(1220 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1909 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1910 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1911 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1912 */
  sim_icache_fetch(1224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1914 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1915 */
  sim_icache_fetch(1226 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1917 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1918 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1919 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1920 */
} /* line 1920 */
  sim_icache_fetch(1231 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1922 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1923 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1924 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1925 */
  sim_icache_fetch(1235 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1927 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1928 */
  sim_icache_fetch(1237 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1930 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1931 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1932 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1933 */
} /* line 1933 */
  sim_icache_fetch(1242 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1935 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1936 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1937 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1938 */
  sim_icache_fetch(1246 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1940 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1941 */
  sim_icache_fetch(1248 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1943 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1944 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1945 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1946 */
} /* line 1946 */
  sim_icache_fetch(1253 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1948 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1949 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1950 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1951 */
  sim_icache_fetch(1257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1953 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1954 */
  sim_icache_fetch(1259 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1956 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1957 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1958 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1959 */
} /* line 1959 */
  sim_icache_fetch(1264 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1961 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1962 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1963 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1964 */
  sim_icache_fetch(1268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1966 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1967 */
  sim_icache_fetch(1270 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1969 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1970 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1971 */
} /* line 1971 */
  sim_icache_fetch(1274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1973 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1974 */
  sim_icache_fetch(1276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1976 */
  sim_icache_fetch(1277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1978 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1979 */
} /* line 1979 */
  sim_icache_fetch(1279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L154X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1981 */
  sim_icache_fetch(1280 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L155X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1984 */
  sim_icache_fetch(1281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L91X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L91X3;
} /* line 1986 */
l_L155X3: ;/* line 1989 */
__LABEL(l_L155X3);
  sim_icache_fetch(1282 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1990 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1991 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1992 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1993 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 1994 */
l_L154X3: ;/* line 1998 */
__LABEL(l_L154X3);
  sim_icache_fetch(1287 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 1999 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2000 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2001 */
l_L153X3: ;/* line 2004 */
__LABEL(l_L153X3);
  sim_icache_fetch(1290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2005 */
} /* line 2005 */
l_L121X3: ;/* line 2008 */
__LABEL(l_L121X3);
  sim_icache_fetch(1291 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2009 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2010 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2011 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2012 */
} /* line 2012 */
  sim_icache_fetch(1295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2014 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2015 */
l_L152X3: ;/* line 2018 */
__LABEL(l_L152X3);
  sim_icache_fetch(1297 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2019 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2020 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2021 */
l_L151X3: ;/* line 2024 */
__LABEL(l_L151X3);
  sim_icache_fetch(1300 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2025 */
} /* line 2025 */
l_L119X3: ;/* line 2028 */
__LABEL(l_L119X3);
  sim_icache_fetch(1301 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2029 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2030 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2031 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2032 */
} /* line 2032 */
  sim_icache_fetch(1305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2034 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2035 */
l_L150X3: ;/* line 2038 */
__LABEL(l_L150X3);
  sim_icache_fetch(1307 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2039 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2040 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2041 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2042 */
l_L149X3: ;/* line 2045 */
__LABEL(l_L149X3);
  sim_icache_fetch(1311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2046 */
} /* line 2046 */
l_L117X3: ;/* line 2049 */
__LABEL(l_L117X3);
  sim_icache_fetch(1312 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2050 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2051 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2052 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2053 */
} /* line 2053 */
  sim_icache_fetch(1316 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2055 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2056 */
l_L148X3: ;/* line 2059 */
__LABEL(l_L148X3);
  sim_icache_fetch(1318 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2060 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2061 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2062 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2063 */
l_L147X3: ;/* line 2066 */
__LABEL(l_L147X3);
  sim_icache_fetch(1322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2067 */
} /* line 2067 */
l_L115X3: ;/* line 2070 */
__LABEL(l_L115X3);
  sim_icache_fetch(1323 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2071 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2072 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2073 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2074 */
} /* line 2074 */
  sim_icache_fetch(1327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2076 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2077 */
l_L146X3: ;/* line 2080 */
__LABEL(l_L146X3);
  sim_icache_fetch(1329 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2081 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2082 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2083 */
l_L145X3: ;/* line 2086 */
__LABEL(l_L145X3);
  sim_icache_fetch(1332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2087 */
} /* line 2087 */
l_L113X3: ;/* line 2090 */
__LABEL(l_L113X3);
  sim_icache_fetch(1333 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2091 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2092 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2093 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2094 */
} /* line 2094 */
  sim_icache_fetch(1337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2096 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2097 */
l_L144X3: ;/* line 2100 */
__LABEL(l_L144X3);
  sim_icache_fetch(1339 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2101 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2102 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2103 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2104 */
l_L143X3: ;/* line 2107 */
__LABEL(l_L143X3);
  sim_icache_fetch(1343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2108 */
} /* line 2108 */
l_L111X3: ;/* line 2111 */
__LABEL(l_L111X3);
  sim_icache_fetch(1344 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2112 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2113 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2114 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2115 */
} /* line 2115 */
  sim_icache_fetch(1348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2117 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2118 */
l_L142X3: ;/* line 2121 */
__LABEL(l_L142X3);
  sim_icache_fetch(1350 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2122 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2123 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2124 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2125 */
l_L141X3: ;/* line 2128 */
__LABEL(l_L141X3);
  sim_icache_fetch(1354 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2129 */
} /* line 2129 */
l_L109X3: ;/* line 2132 */
__LABEL(l_L109X3);
  sim_icache_fetch(1355 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2133 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2134 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2135 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2136 */
} /* line 2136 */
  sim_icache_fetch(1359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2138 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2139 */
l_L140X3: ;/* line 2142 */
__LABEL(l_L140X3);
  sim_icache_fetch(1361 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2143 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2144 */
   __GOTO(l_L159X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L159X3;
} /* line 2145 */
l_L139X3: ;/* line 2148 */
__LABEL(l_L139X3);
  sim_icache_fetch(1364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2149 */
} /* line 2149 */
l_L107X3: ;/* line 2152 */
__LABEL(l_L107X3);
  sim_icache_fetch(1365 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2153 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2154 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2155 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2156 */
} /* line 2156 */
  sim_icache_fetch(1369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2158 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2159 */
l_L138X3: ;/* line 2162 */
__LABEL(l_L138X3);
  sim_icache_fetch(1371 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2163 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2164 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2165 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2166 */
l_L137X3: ;/* line 2169 */
__LABEL(l_L137X3);
  sim_icache_fetch(1375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2170 */
} /* line 2170 */
l_L105X3: ;/* line 2173 */
__LABEL(l_L105X3);
  sim_icache_fetch(1376 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2174 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2175 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2176 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2177 */
} /* line 2177 */
  sim_icache_fetch(1380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2179 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2180 */
l_L136X3: ;/* line 2183 */
__LABEL(l_L136X3);
  sim_icache_fetch(1382 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2184 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2185 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2186 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2187 */
l_L135X3: ;/* line 2190 */
__LABEL(l_L135X3);
  sim_icache_fetch(1386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2191 */
} /* line 2191 */
l_L103X3: ;/* line 2194 */
__LABEL(l_L103X3);
  sim_icache_fetch(1387 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2195 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2196 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2197 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2198 */
} /* line 2198 */
  sim_icache_fetch(1391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2200 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2201 */
l_L134X3: ;/* line 2204 */
__LABEL(l_L134X3);
  sim_icache_fetch(1393 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2205 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2206 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2207 */
l_L133X3: ;/* line 2210 */
__LABEL(l_L133X3);
  sim_icache_fetch(1396 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2211 */
} /* line 2211 */
l_L101X3: ;/* line 2214 */
__LABEL(l_L101X3);
  sim_icache_fetch(1397 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2215 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2216 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2217 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2218 */
} /* line 2218 */
  sim_icache_fetch(1401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2220 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2221 */
l_L132X3: ;/* line 2224 */
__LABEL(l_L132X3);
  sim_icache_fetch(1403 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2225 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2226 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2227 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2228 */
l_L131X3: ;/* line 2231 */
__LABEL(l_L131X3);
  sim_icache_fetch(1407 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2232 */
} /* line 2232 */
l_L99X3: ;/* line 2235 */
__LABEL(l_L99X3);
  sim_icache_fetch(1408 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2236 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2237 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2238 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2239 */
} /* line 2239 */
  sim_icache_fetch(1412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2241 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2242 */
l_L130X3: ;/* line 2245 */
__LABEL(l_L130X3);
  sim_icache_fetch(1414 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2246 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2247 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2248 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2249 */
l_L129X3: ;/* line 2252 */
__LABEL(l_L129X3);
  sim_icache_fetch(1418 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2253 */
} /* line 2253 */
l_L97X3: ;/* line 2256 */
__LABEL(l_L97X3);
  sim_icache_fetch(1419 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2257 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2258 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2259 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2260 */
} /* line 2260 */
  sim_icache_fetch(1423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2262 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2263 */
l_L128X3: ;/* line 2266 */
__LABEL(l_L128X3);
  sim_icache_fetch(1425 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2267 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2268 */
   __GOTO(l_L161X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L161X3;
} /* line 2269 */
l_L127X3: ;/* line 2272 */
__LABEL(l_L127X3);
  sim_icache_fetch(1428 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2273 */
} /* line 2273 */
l_L95X3: ;/* line 2276 */
__LABEL(l_L95X3);
  sim_icache_fetch(1429 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2277 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2278 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2279 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2280 */
} /* line 2280 */
  sim_icache_fetch(1433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2282 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2283 */
l_L126X3: ;/* line 2286 */
__LABEL(l_L126X3);
  sim_icache_fetch(1435 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2287 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2288 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2289 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2290 */
l_L125X3: ;/* line 2293 */
__LABEL(l_L125X3);
  sim_icache_fetch(1439 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2294 */
} /* line 2294 */
l_L93X3: ;/* line 2298 */
__LABEL(l_L93X3);
  sim_icache_fetch(1440 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2299 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2300 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2301 */
} /* line 2301 */
  sim_icache_fetch(1443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2303 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2304 */
l_L124X3: ;/* line 2307 */
__LABEL(l_L124X3);
  sim_icache_fetch(1445 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2308 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2309 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2310 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2311 */
l_L123X3: ;/* line 2314 */
__LABEL(l_L123X3);
  sim_icache_fetch(1449 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2315 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2316 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2317 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2318 */
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 2319 */
l_L122X3: ;/* line 2323 */
__LABEL(l_L122X3);
  sim_icache_fetch(1454 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2324 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2325 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2326 */
l_L120X3: ;/* line 2329 */
__LABEL(l_L120X3);
  sim_icache_fetch(1457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2330 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2331 */
} /* line 2331 */
l_L157X3: ;/* line 2333 */
__LABEL(l_L157X3);
  sim_icache_fetch(1459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2334 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2335 */
l_L118X3: ;/* line 2338 */
__LABEL(l_L118X3);
  sim_icache_fetch(1461 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2339 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2340 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2341 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2342 */
l_L116X3: ;/* line 2345 */
__LABEL(l_L116X3);
  sim_icache_fetch(1465 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2346 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2347 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2348 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2349 */
l_L114X3: ;/* line 2352 */
__LABEL(l_L114X3);
  sim_icache_fetch(1469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2353 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2354 */
} /* line 2354 */
l_L158X3: ;/* line 2356 */
__LABEL(l_L158X3);
  sim_icache_fetch(1471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2357 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2358 */
l_L112X3: ;/* line 2361 */
__LABEL(l_L112X3);
  sim_icache_fetch(1473 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2362 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2363 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2364 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2365 */
l_L110X3: ;/* line 2368 */
__LABEL(l_L110X3);
  sim_icache_fetch(1477 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2369 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2370 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2371 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2372 */
l_L108X3: ;/* line 2375 */
__LABEL(l_L108X3);
  sim_icache_fetch(1481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2376 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2377 */
} /* line 2377 */
l_L159X3: ;/* line 2379 */
__LABEL(l_L159X3);
  sim_icache_fetch(1483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2380 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2381 */
l_L106X3: ;/* line 2384 */
__LABEL(l_L106X3);
  sim_icache_fetch(1485 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2385 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2386 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2387 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2388 */
l_L104X3: ;/* line 2391 */
__LABEL(l_L104X3);
  sim_icache_fetch(1489 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2392 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2393 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2394 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2395 */
l_L102X3: ;/* line 2398 */
__LABEL(l_L102X3);
  sim_icache_fetch(1493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2399 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2400 */
} /* line 2400 */
l_L160X3: ;/* line 2402 */
__LABEL(l_L160X3);
  sim_icache_fetch(1495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2403 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2404 */
l_L100X3: ;/* line 2407 */
__LABEL(l_L100X3);
  sim_icache_fetch(1497 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2408 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2409 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2410 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2411 */
l_L98X3: ;/* line 2414 */
__LABEL(l_L98X3);
  sim_icache_fetch(1501 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2415 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2416 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2417 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2418 */
l_L96X3: ;/* line 2421 */
__LABEL(l_L96X3);
  sim_icache_fetch(1505 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2422 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2423 */
} /* line 2423 */
l_L161X3: ;/* line 2425 */
__LABEL(l_L161X3);
  sim_icache_fetch(1507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2426 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2427 */
l_L94X3: ;/* line 2430 */
__LABEL(l_L94X3);
  sim_icache_fetch(1509 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2431 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2432 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2433 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2434 */
l_L92X3: ;/* line 2438 */
__LABEL(l_L92X3);
  sim_icache_fetch(1513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2439 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2440 */
} /* line 2440 */
l_L156X3: ;/* line 2442 */
__LABEL(l_L156X3);
  sim_icache_fetch(1515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2443 */
} /* line 2443 */
  sim_icache_fetch(1517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2445 */
} /* line 2445 */
  sim_icache_fetch(1518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2447 */
l_L85X3: ;/* line 2450 */
__LABEL(l_L85X3);
		 /* line 2450 */
  sim_icache_fetch(1519 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2453 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (330 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2453 */
l_lr_199: ;/* line 2453 */
__LABEL(l_lr_199);
  sim_icache_fetch(1522 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2455 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2456 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2457 */
   __ADD_CYCLES(1);
} /* line 2457 */
  sim_icache_fetch(1526 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2459 */
} /* line 2459 */
		 /* line 2460 */
  sim_icache_fetch(1527 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2462 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (330 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2463 */
l_lr_201: ;/* line 2463 */
__LABEL(l_lr_201);
  sim_icache_fetch(1531 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2465 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2466 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2467 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2468 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2469 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2470 */
} /* line 2470 */
  sim_icache_fetch(1541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 2472 */
} /* line 2472 */
  sim_icache_fetch(1542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2474 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2475 */
} /* line 2475 */
  sim_icache_fetch(1544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L162X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2477 */
l_L163X3: ;/* line 2479 */
__LABEL(l_L163X3);
  sim_icache_fetch(1545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L164X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2480 */
  sim_icache_fetch(1546 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2482 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2483 */
} /* line 2483 */
l_L165X3: ;/* line 2485 */
__LABEL(l_L165X3);
  sim_icache_fetch(1549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2487 */
l_L164X3: ;/* line 2490 */
__LABEL(l_L164X3);
  sim_icache_fetch(1550 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2491 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2492 */
   __GOTO(l_L165X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L165X3;
} /* line 2493 */
l_L162X3: ;/* line 2496 */
__LABEL(l_L162X3);
  sim_icache_fetch(1553 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2497 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2498 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2499 */
   __ADD_CYCLES(1);
} /* line 2499 */
		 /* line 2500 */
  sim_icache_fetch(1558 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2502 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (330 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2503 */
l_lr_207: ;/* line 2503 */
__LABEL(l_lr_207);
  sim_icache_fetch(1561 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2505 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2506 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2507 */
   __MOV(reg_r0_3, 0); /* line 2508 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2509 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2510 */
   __ADD_CYCLES(1);
} /* line 2510 */
  sim_icache_fetch(1569 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2512 */
   __GOTO(l_L163X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L163X3;
} /* line 2513 */
l_L83X3: ;/* line 2516 */
__LABEL(l_L83X3);
  sim_icache_fetch(1571 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2517 */
   __GOTO(l_L84X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L84X3;
} /* line 2518 */
l_L79X3: ;/* line 2521 */
__LABEL(l_L79X3);
  sim_icache_fetch(1573 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2522 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2523 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2524 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2525 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2526 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2527 */
l_L78X3: ;/* line 2530 */
__LABEL(l_L78X3);
  sim_icache_fetch(1580 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2531 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2532 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2533 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2534 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2535 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2536 */
l_L77X3: ;/* line 2539 */
__LABEL(l_L77X3);
  sim_icache_fetch(1587 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2540 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2541 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2542 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2543 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2544 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2545 */
l_L76X3: ;/* line 2548 */
__LABEL(l_L76X3);
  sim_icache_fetch(1594 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2549 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2550 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2551 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2552 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2553 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2554 */
l_L75X3: ;/* line 2557 */
__LABEL(l_L75X3);
  sim_icache_fetch(1601 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2558 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2559 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2560 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2561 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2562 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2563 */
l_L74X3: ;/* line 2566 */
__LABEL(l_L74X3);
  sim_icache_fetch(1608 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2567 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2568 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2569 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2570 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2571 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2572 */
l_L73X3: ;/* line 2575 */
__LABEL(l_L73X3);
  sim_icache_fetch(1615 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2576 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2577 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2578 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2579 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2580 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2581 */
l_L72X3: ;/* line 2584 */
__LABEL(l_L72X3);
  sim_icache_fetch(1622 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2585 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2586 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2587 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2588 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2589 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2590 */
l_L71X3: ;/* line 2593 */
__LABEL(l_L71X3);
  sim_icache_fetch(1629 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2594 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2595 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2596 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2597 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2598 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2599 */
l_L70X3: ;/* line 2602 */
__LABEL(l_L70X3);
  sim_icache_fetch(1636 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2603 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2604 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2605 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2606 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2607 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2608 */
l_L69X3: ;/* line 2611 */
__LABEL(l_L69X3);
  sim_icache_fetch(1643 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2612 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2613 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2614 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2615 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2616 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2617 */
l_L68X3: ;/* line 2620 */
__LABEL(l_L68X3);
  sim_icache_fetch(1650 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2621 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2622 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2623 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2624 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2625 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2626 */
l_L67X3: ;/* line 2629 */
__LABEL(l_L67X3);
  sim_icache_fetch(1657 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2630 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2631 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2632 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2633 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2634 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2635 */
l_L66X3: ;/* line 2638 */
__LABEL(l_L66X3);
  sim_icache_fetch(1664 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2639 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2640 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2641 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2642 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2643 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2644 */
l_L65X3: ;/* line 2648 */
__LABEL(l_L65X3);
  sim_icache_fetch(1671 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2649 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2650 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2651 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2652 */
} /* line 2652 */
l_L81X3: ;/* line 2654 */
__LABEL(l_L81X3);
  sim_icache_fetch(1676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2655 */
} /* line 2655 */
		 /* line 2656 */
  sim_icache_fetch(1677 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2659 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2660 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2661 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (330 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2661 */
l_lr_226: ;/* line 2661 */
__LABEL(l_lr_226);
  sim_icache_fetch(1682 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2663 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2664 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2665 */
} /* line 2665 */
  sim_icache_fetch(1685 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2667 */
l_L62X3: ;/* line 2670 */
__LABEL(l_L62X3);
  sim_icache_fetch(1686 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2671 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2672 */
} /* line 2672 */
  sim_icache_fetch(1688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L63X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L63X3;
} /* line 2674 */
l_L60X3: ;/* line 2677 */
__LABEL(l_L60X3);
  sim_icache_fetch(1689 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2678 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2679 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2680 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2681 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2682 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2683 */
   __ADD_CYCLES(1);
} /* line 2683 */
  sim_icache_fetch(1697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_11, (unsigned int) 1); /* line 2685 */
} /* line 2685 */
  sim_icache_fetch(1698 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_16); /* line 2687 */
} /* line 2687 */
  sim_icache_fetch(1700 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2689 */
} /* line 2689 */
  sim_icache_fetch(1701 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2691 */
   __LDBU(reg_r0_15, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2692 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2693 */
   __ADD_CYCLES(1);
} /* line 2693 */
  sim_icache_fetch(1706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_11, (unsigned int) 1); /* line 2695 */
} /* line 2695 */
  sim_icache_fetch(1707 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_16); /* line 2697 */
} /* line 2697 */
  sim_icache_fetch(1709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2699 */
} /* line 2699 */
  sim_icache_fetch(1710 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2701 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2702 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2703 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2704 */
   __ADD_CYCLES(1);
} /* line 2704 */
  sim_icache_fetch(1717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_17, reg_r0_11, (unsigned int) 1); /* line 2706 */
   __OR(reg_r0_15, reg_r0_15, reg_r0_16); /* line 2707 */
} /* line 2707 */
  sim_icache_fetch(1719 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_17); /* line 2709 */
} /* line 2709 */
  sim_icache_fetch(1721 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2711 */
} /* line 2711 */
  sim_icache_fetch(1722 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2713 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2714 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2715 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2716 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2717 */
   __ADD_CYCLES(1);
} /* line 2717 */
  sim_icache_fetch(1731 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 2719 */
   __ADD(reg_r0_13, reg_r0_15, (unsigned int) -1); /* line 2720 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 1); /* line 2721 */
   __GOTO(l_L61X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L61X3;
} /* line 2722 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 212: goto l_L61X3;
    case 213: goto l_L63X3;
    case 214: goto l_L64X3;
    case 215: goto l_L80X3;
    case 216: goto l_L82X3;
    case 217: goto l_L84X3;
    case 218: goto l_L86X3;
    case 219: goto l_L88X3;
    case 221: goto l_lr_120;
    case 222: goto l_L89X3;
    case 224: goto l_lr_123;
    case 225: goto l_L90X3;
    case 226: goto l_L87X3;
    case 227: goto l_L91X3;
    case 228: goto l_L155X3;
    case 229: goto l_L154X3;
    case 230: goto l_L153X3;
    case 231: goto l_L121X3;
    case 232: goto l_L152X3;
    case 233: goto l_L151X3;
    case 234: goto l_L119X3;
    case 235: goto l_L150X3;
    case 236: goto l_L149X3;
    case 237: goto l_L117X3;
    case 238: goto l_L148X3;
    case 239: goto l_L147X3;
    case 240: goto l_L115X3;
    case 241: goto l_L146X3;
    case 242: goto l_L145X3;
    case 243: goto l_L113X3;
    case 244: goto l_L144X3;
    case 245: goto l_L143X3;
    case 246: goto l_L111X3;
    case 247: goto l_L142X3;
    case 248: goto l_L141X3;
    case 249: goto l_L109X3;
    case 250: goto l_L140X3;
    case 251: goto l_L139X3;
    case 252: goto l_L107X3;
    case 253: goto l_L138X3;
    case 254: goto l_L137X3;
    case 255: goto l_L105X3;
    case 256: goto l_L136X3;
    case 257: goto l_L135X3;
    case 258: goto l_L103X3;
    case 259: goto l_L134X3;
    case 260: goto l_L133X3;
    case 261: goto l_L101X3;
    case 262: goto l_L132X3;
    case 263: goto l_L131X3;
    case 264: goto l_L99X3;
    case 265: goto l_L130X3;
    case 266: goto l_L129X3;
    case 267: goto l_L97X3;
    case 268: goto l_L128X3;
    case 269: goto l_L127X3;
    case 270: goto l_L95X3;
    case 271: goto l_L126X3;
    case 272: goto l_L125X3;
    case 273: goto l_L93X3;
    case 274: goto l_L124X3;
    case 275: goto l_L123X3;
    case 276: goto l_L122X3;
    case 277: goto l_L120X3;
    case 278: goto l_L157X3;
    case 279: goto l_L118X3;
    case 280: goto l_L116X3;
    case 281: goto l_L114X3;
    case 282: goto l_L158X3;
    case 283: goto l_L112X3;
    case 284: goto l_L110X3;
    case 285: goto l_L108X3;
    case 286: goto l_L159X3;
    case 287: goto l_L106X3;
    case 288: goto l_L104X3;
    case 289: goto l_L102X3;
    case 290: goto l_L160X3;
    case 291: goto l_L100X3;
    case 292: goto l_L98X3;
    case 293: goto l_L96X3;
    case 294: goto l_L161X3;
    case 295: goto l_L94X3;
    case 296: goto l_L92X3;
    case 297: goto l_L156X3;
    case 298: goto l_L85X3;
    case 300: goto l_lr_199;
    case 302: goto l_lr_201;
    case 303: goto l_L163X3;
    case 304: goto l_L165X3;
    case 305: goto l_L164X3;
    case 306: goto l_L162X3;
    case 308: goto l_lr_207;
    case 309: goto l_L83X3;
    case 310: goto l_L79X3;
    case 311: goto l_L78X3;
    case 312: goto l_L77X3;
    case 313: goto l_L76X3;
    case 314: goto l_L75X3;
    case 315: goto l_L74X3;
    case 316: goto l_L73X3;
    case 317: goto l_L72X3;
    case 318: goto l_L71X3;
    case 319: goto l_L70X3;
    case 320: goto l_L69X3;
    case 321: goto l_L68X3;
    case 322: goto l_L67X3;
    case 323: goto l_L66X3;
    case 324: goto l_L65X3;
    case 325: goto l_L81X3;
    case 327: goto l_lr_226;
    case 328: goto l_L62X3;
    case 329: goto l_L60X3;
    case 330:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern  output( unsigned int arg0 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(output);  sim_gprof_enter(&sim_gprof_idx,"output");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_l0_0 = (362 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1735 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 2741 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2742 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2743 */
} /* line 2743 */
  sim_icache_fetch(1740 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2745 */
  sim_icache_fetch(1741 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2747 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2748 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2749 */
} /* line 2749 */
  sim_icache_fetch(1744 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_10519Xbuf); /* line 2751 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_10519Xbuf),0,1)); /* line 2752 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2753 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2754 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2755 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2756 */
} /* line 2756 */
  sim_icache_fetch(1754 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_10519Xbuf + (unsigned int) 1)); /* line 2758 */
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2759 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2760 */
} /* line 2760 */
  sim_icache_fetch(1758 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2762 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2763 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2764 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2765 */
} /* line 2765 */
  sim_icache_fetch(1762 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2767 */
} /* line 2767 */
  sim_icache_fetch(1763 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_10519Xbuf),0,1), reg_r0_2); /* line 2769 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2770 */
  sim_icache_fetch(1766 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2772 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2773 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2774 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2775 */
} /* line 2775 */
l_L167X3: ;/* line 2777 */
__LABEL(l_L167X3);
  sim_icache_fetch(1770 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2778 */
   __MOV(reg_r0_3, (unsigned int) compress_10519Xbuf); /* line 2779 */
} /* line 2779 */
  sim_icache_fetch(1773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2781 */
  sim_icache_fetch(1774 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2783 */
} /* line 2783 */
l_L168X3: ;/* line 2785 */
__LABEL(l_L168X3);
  sim_icache_fetch(1775 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 2786 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2787 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2788 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2789 */
   __ADD_CYCLES(1);
} /* line 2789 */
  sim_icache_fetch(1782 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2791 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2792 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2793 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2794 */
} /* line 2794 */
  sim_icache_fetch(1786 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_10519Xoffset,0,4), reg_r0_2); /* line 2796 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2797 */
} /* line 2797 */
  sim_icache_fetch(1789 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L169X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2799 */
  sim_icache_fetch(1790 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2801 */
} /* line 2801 */
l_L170X3: ;/* line 2804 */
__LABEL(l_L170X3);
  sim_icache_fetch(1792 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2805 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2806 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2807 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2808 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2809 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2810 */
} /* line 2810 */
  sim_icache_fetch(1799 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2812 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2813 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2814 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2815 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -16); /* line 2816 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 16); /* line 2817 */
} /* line 2817 */
  sim_icache_fetch(1805 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2819 */
} /* line 2819 */
  sim_icache_fetch(1806 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2821 */
} /* line 2821 */
  sim_icache_fetch(1808 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2823 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2824 */
  sim_icache_fetch(1810 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2826 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2827 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2828 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2829 */
   __ADD_CYCLES(1);
} /* line 2829 */
  sim_icache_fetch(1815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2831 */
} /* line 2831 */
  sim_icache_fetch(1816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2833 */
} /* line 2833 */
  sim_icache_fetch(1818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2835 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2836 */
  sim_icache_fetch(1820 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2838 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2839 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2840 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2841 */
   __ADD_CYCLES(1);
} /* line 2841 */
  sim_icache_fetch(1825 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2843 */
} /* line 2843 */
  sim_icache_fetch(1826 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2845 */
} /* line 2845 */
  sim_icache_fetch(1828 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2847 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2848 */
  sim_icache_fetch(1830 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2850 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2851 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2852 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2853 */
   __ADD_CYCLES(1);
} /* line 2853 */
  sim_icache_fetch(1835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2855 */
} /* line 2855 */
  sim_icache_fetch(1836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2857 */
} /* line 2857 */
  sim_icache_fetch(1838 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2859 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2860 */
  sim_icache_fetch(1840 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2862 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2863 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2864 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2865 */
   __ADD_CYCLES(1);
} /* line 2865 */
  sim_icache_fetch(1845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2867 */
} /* line 2867 */
  sim_icache_fetch(1846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2869 */
} /* line 2869 */
  sim_icache_fetch(1848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2871 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2872 */
  sim_icache_fetch(1850 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2874 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2875 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2876 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2877 */
   __ADD_CYCLES(1);
} /* line 2877 */
  sim_icache_fetch(1855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2879 */
} /* line 2879 */
  sim_icache_fetch(1856 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2881 */
} /* line 2881 */
  sim_icache_fetch(1858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2883 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2884 */
  sim_icache_fetch(1860 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2886 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2887 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2888 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2889 */
   __ADD_CYCLES(1);
} /* line 2889 */
  sim_icache_fetch(1865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2891 */
} /* line 2891 */
  sim_icache_fetch(1866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2893 */
} /* line 2893 */
  sim_icache_fetch(1868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2895 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2896 */
  sim_icache_fetch(1870 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2898 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2899 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2900 */
   __ADD(reg_r0_5, reg_r0_7, (unsigned int) -16); /* line 2901 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2902 */
   __ADD_CYCLES(1);
} /* line 2902 */
  sim_icache_fetch(1876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2904 */
} /* line 2904 */
  sim_icache_fetch(1877 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2906 */
} /* line 2906 */
  sim_icache_fetch(1879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2908 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2909 */
  sim_icache_fetch(1881 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2911 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2912 */
   __CMPEQ(reg_b0_7, reg_r0_7, 0); /* line 2913 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2914 */
   __ADD_CYCLES(1);
} /* line 2914 */
  sim_icache_fetch(1886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2916 */
} /* line 2916 */
  sim_icache_fetch(1887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2918 */
} /* line 2918 */
  sim_icache_fetch(1889 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2920 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2921 */
  sim_icache_fetch(1891 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2923 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2924 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2925 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2926 */
   __ADD_CYCLES(1);
} /* line 2926 */
  sim_icache_fetch(1896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2928 */
} /* line 2928 */
  sim_icache_fetch(1897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2930 */
} /* line 2930 */
  sim_icache_fetch(1899 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2932 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2933 */
  sim_icache_fetch(1901 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 2935 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2936 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2937 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2938 */
   __ADD_CYCLES(1);
} /* line 2938 */
  sim_icache_fetch(1906 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2940 */
} /* line 2940 */
  sim_icache_fetch(1907 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2942 */
} /* line 2942 */
  sim_icache_fetch(1909 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2944 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2945 */
  sim_icache_fetch(1911 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 2947 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2948 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2949 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2950 */
   __ADD_CYCLES(1);
} /* line 2950 */
  sim_icache_fetch(1916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2952 */
} /* line 2952 */
  sim_icache_fetch(1917 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2954 */
} /* line 2954 */
  sim_icache_fetch(1919 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2956 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2957 */
  sim_icache_fetch(1921 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 2959 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2960 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 4); /* line 2961 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2962 */
   __ADD_CYCLES(1);
} /* line 2962 */
  sim_icache_fetch(1926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2964 */
} /* line 2964 */
  sim_icache_fetch(1927 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2966 */
} /* line 2966 */
  sim_icache_fetch(1929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2968 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2969 */
  sim_icache_fetch(1931 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 2971 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2972 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 5); /* line 2973 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2974 */
   __ADD_CYCLES(1);
} /* line 2974 */
  sim_icache_fetch(1936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2976 */
} /* line 2976 */
  sim_icache_fetch(1937 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2978 */
} /* line 2978 */
  sim_icache_fetch(1939 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2980 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2981 */
  sim_icache_fetch(1941 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 2983 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2984 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 6); /* line 2985 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2986 */
   __ADD_CYCLES(1);
} /* line 2986 */
  sim_icache_fetch(1946 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2988 */
} /* line 2988 */
  sim_icache_fetch(1947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2990 */
} /* line 2990 */
  sim_icache_fetch(1949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2992 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2993 */
  sim_icache_fetch(1951 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 2995 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2996 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 7); /* line 2997 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2998 */
   __ADD_CYCLES(1);
} /* line 2998 */
  sim_icache_fetch(1956 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3000 */
} /* line 3000 */
  sim_icache_fetch(1957 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3002 */
} /* line 3002 */
  sim_icache_fetch(1959 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3004 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3005 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3006 */
  sim_icache_fetch(1962 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 3008 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3009 */
   __CMPEQ(reg_b0_7, reg_r0_7, (unsigned int) 8); /* line 3010 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) 16); /* line 3011 */
   __MFB(reg_r0_8, t__i32_0); /* line 3012 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3013 */
   __ADD_CYCLES(1);
} /* line 3013 */
  sim_icache_fetch(1969 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3015 */
} /* line 3015 */
  sim_icache_fetch(1970 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3017 */
} /* line 3017 */
  sim_icache_fetch(1972 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3019 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3020 */
  sim_icache_fetch(1974 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 3022 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3023 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 9); /* line 3024 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3025 */
   __ADD_CYCLES(1);
} /* line 3025 */
  sim_icache_fetch(1979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3027 */
} /* line 3027 */
  sim_icache_fetch(1980 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3029 */
} /* line 3029 */
  sim_icache_fetch(1982 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3031 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3032 */
  sim_icache_fetch(1984 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 2),0,1)); /* line 3034 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3035 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 10); /* line 3036 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3037 */
   __ADD_CYCLES(1);
} /* line 3037 */
  sim_icache_fetch(1989 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3039 */
} /* line 3039 */
  sim_icache_fetch(1990 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3041 */
} /* line 3041 */
  sim_icache_fetch(1992 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3043 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3044 */
  sim_icache_fetch(1994 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 3),0,1)); /* line 3046 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3047 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 11); /* line 3048 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3049 */
   __ADD_CYCLES(1);
} /* line 3049 */
  sim_icache_fetch(1999 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3051 */
} /* line 3051 */
  sim_icache_fetch(2000 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3053 */
} /* line 3053 */
  sim_icache_fetch(2002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3055 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3056 */
  sim_icache_fetch(2004 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 4),0,1)); /* line 3058 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3059 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 12); /* line 3060 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3061 */
   __ADD_CYCLES(1);
} /* line 3061 */
  sim_icache_fetch(2009 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3063 */
} /* line 3063 */
  sim_icache_fetch(2010 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3065 */
} /* line 3065 */
  sim_icache_fetch(2012 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3067 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3068 */
  sim_icache_fetch(2014 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 5),0,1)); /* line 3070 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3071 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 13); /* line 3072 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3073 */
   __ADD_CYCLES(1);
} /* line 3073 */
  sim_icache_fetch(2019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3075 */
} /* line 3075 */
  sim_icache_fetch(2020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3077 */
} /* line 3077 */
  sim_icache_fetch(2022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3079 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3080 */
  sim_icache_fetch(2024 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 6),0,1)); /* line 3082 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3083 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 14); /* line 3084 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3085 */
   __ADD_CYCLES(1);
} /* line 3085 */
  sim_icache_fetch(2029 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3087 */
} /* line 3087 */
  sim_icache_fetch(2030 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3089 */
} /* line 3089 */
  sim_icache_fetch(2032 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3091 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3092 */
  sim_icache_fetch(2034 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 7),0,1)); /* line 3094 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3095 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 15); /* line 3096 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3097 */
   __ADD_CYCLES(1);
} /* line 3097 */
  sim_icache_fetch(2039 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3099 */
} /* line 3099 */
  sim_icache_fetch(2040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3101 */
} /* line 3101 */
  sim_icache_fetch(2042 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3103 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3104 */
  sim_icache_fetch(2044 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 8),0,1)); /* line 3106 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3107 */
   __MTB(reg_b0_7, reg_r0_8); /* line 3108 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3109 */
   __ADD_CYCLES(1);
} /* line 3109 */
  sim_icache_fetch(2049 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3111 */
} /* line 3111 */
  sim_icache_fetch(2050 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3113 */
} /* line 3113 */
  sim_icache_fetch(2052 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3115 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3116 */
  sim_icache_fetch(2054 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 9),0,1)); /* line 3118 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3119 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3120 */
   __ADD_CYCLES(1);
} /* line 3120 */
  sim_icache_fetch(2058 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3122 */
} /* line 3122 */
  sim_icache_fetch(2059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3124 */
} /* line 3124 */
  sim_icache_fetch(2061 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3126 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3127 */
  sim_icache_fetch(2063 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 10),0,1)); /* line 3129 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3130 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3131 */
   __ADD_CYCLES(1);
} /* line 3131 */
  sim_icache_fetch(2067 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3133 */
} /* line 3133 */
  sim_icache_fetch(2068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3135 */
} /* line 3135 */
  sim_icache_fetch(2070 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3137 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3138 */
  sim_icache_fetch(2072 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 11),0,1)); /* line 3140 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3141 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3142 */
   __ADD_CYCLES(1);
} /* line 3142 */
  sim_icache_fetch(2076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3144 */
} /* line 3144 */
  sim_icache_fetch(2077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3146 */
} /* line 3146 */
  sim_icache_fetch(2079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3148 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3149 */
  sim_icache_fetch(2081 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 12),0,1)); /* line 3151 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3152 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3153 */
   __ADD_CYCLES(1);
} /* line 3153 */
  sim_icache_fetch(2085 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3155 */
} /* line 3155 */
  sim_icache_fetch(2086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3157 */
} /* line 3157 */
  sim_icache_fetch(2088 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3159 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3160 */
  sim_icache_fetch(2090 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 13),0,1)); /* line 3162 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3163 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3164 */
   __ADD_CYCLES(1);
} /* line 3164 */
  sim_icache_fetch(2094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3166 */
} /* line 3166 */
  sim_icache_fetch(2095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3168 */
} /* line 3168 */
  sim_icache_fetch(2097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3170 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3171 */
  sim_icache_fetch(2099 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 14),0,1)); /* line 3173 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3174 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3175 */
   __ADD_CYCLES(1);
} /* line 3175 */
  sim_icache_fetch(2103 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3177 */
} /* line 3177 */
  sim_icache_fetch(2104 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3179 */
} /* line 3179 */
  sim_icache_fetch(2106 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3181 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3182 */
  sim_icache_fetch(2108 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 15),0,1)); /* line 3184 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3185 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3186 */
   __ADD_CYCLES(1);
} /* line 3186 */
  sim_icache_fetch(2112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3188 */
} /* line 3188 */
  sim_icache_fetch(2113 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3190 */
} /* line 3190 */
  sim_icache_fetch(2115 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 3192 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3194 */
  sim_icache_fetch(2117 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L170X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L170X3;
} /* line 3196 */
l_L171X3: ;/* line 3199 */
__LABEL(l_L171X3);
  sim_icache_fetch(2118 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_10519Xoffset,0,4), 0); /* line 3200 */
} /* line 3200 */
l_L169X3: ;/* line 3203 */
__LABEL(l_L169X3);
  sim_icache_fetch(2120 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3204 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3205 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3206 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3207 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3208 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3209 */
} /* line 3209 */
  sim_icache_fetch(2130 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3211 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3212 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3213 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3214 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3215 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3216 */
} /* line 3216 */
  sim_icache_fetch(2136 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3218 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3219 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3220 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3221 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3222 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3223 */
} /* line 3223 */
  sim_icache_fetch(2142 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3225 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3226 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3227 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3228 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3229 */
   __MOV(reg_r0_5, (unsigned int) compress_10519Xbuf); /* line 3230 */
} /* line 3230 */
  sim_icache_fetch(2149 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 3232 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3233 */
  sim_icache_fetch(2151 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3235 */
l_L174X3: ;/* line 3238 */
__LABEL(l_L174X3);
  sim_icache_fetch(2152 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3239 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3240 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3241 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3242 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3243 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3244 */
} /* line 3244 */
  sim_icache_fetch(2160 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3246 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3247 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3248 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3249 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3250 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3251 */
} /* line 3251 */
  sim_icache_fetch(2166 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3253 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3254 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3255 */
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3256 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3257 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3258 */
} /* line 3258 */
  sim_icache_fetch(2172 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3260 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3261 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3262 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3263 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3264 */
  sim_icache_fetch(2177 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3266 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3267 */
} /* line 3267 */
  sim_icache_fetch(2180 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3269 */
} /* line 3269 */
  sim_icache_fetch(2181 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3271 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3272 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3273 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3274 */
   __ADD_CYCLES(1);
} /* line 3274 */
  sim_icache_fetch(2187 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 3276 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3277 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3278 */
} /* line 3278 */
  sim_icache_fetch(2190 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3280 */
  sim_icache_fetch(2191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3282 */
} /* line 3282 */
  sim_icache_fetch(2193 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3284 */
} /* line 3284 */
  sim_icache_fetch(2194 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3286 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3287 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3288 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3289 */
   __ADD_CYCLES(1);
} /* line 3289 */
  sim_icache_fetch(2200 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 3291 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3292 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3293 */
} /* line 3293 */
  sim_icache_fetch(2203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3295 */
  sim_icache_fetch(2204 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3297 */
} /* line 3297 */
  sim_icache_fetch(2206 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3299 */
} /* line 3299 */
  sim_icache_fetch(2207 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3301 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3302 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3303 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3304 */
   __ADD_CYCLES(1);
} /* line 3304 */
  sim_icache_fetch(2213 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 3306 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3307 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3308 */
} /* line 3308 */
  sim_icache_fetch(2216 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3310 */
  sim_icache_fetch(2217 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3312 */
} /* line 3312 */
  sim_icache_fetch(2219 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3314 */
} /* line 3314 */
  sim_icache_fetch(2220 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3316 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3317 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3318 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3319 */
   __ADD_CYCLES(1);
} /* line 3319 */
  sim_icache_fetch(2226 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 3321 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3322 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3323 */
} /* line 3323 */
  sim_icache_fetch(2229 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3325 */
  sim_icache_fetch(2230 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3327 */
} /* line 3327 */
  sim_icache_fetch(2232 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3329 */
} /* line 3329 */
  sim_icache_fetch(2233 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3331 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3332 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3333 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3334 */
   __ADD_CYCLES(1);
} /* line 3334 */
  sim_icache_fetch(2239 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 3336 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3337 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3338 */
} /* line 3338 */
  sim_icache_fetch(2242 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3340 */
  sim_icache_fetch(2243 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3342 */
} /* line 3342 */
  sim_icache_fetch(2245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3344 */
} /* line 3344 */
  sim_icache_fetch(2246 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3346 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3347 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3348 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3349 */
   __ADD_CYCLES(1);
} /* line 3349 */
  sim_icache_fetch(2252 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 3351 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3352 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3353 */
} /* line 3353 */
  sim_icache_fetch(2255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3355 */
  sim_icache_fetch(2256 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3357 */
} /* line 3357 */
  sim_icache_fetch(2258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3359 */
} /* line 3359 */
  sim_icache_fetch(2259 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3361 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3362 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3363 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3364 */
   __ADD_CYCLES(1);
} /* line 3364 */
  sim_icache_fetch(2265 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 3366 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3367 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3368 */
} /* line 3368 */
  sim_icache_fetch(2268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3370 */
  sim_icache_fetch(2269 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3372 */
} /* line 3372 */
  sim_icache_fetch(2271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3374 */
} /* line 3374 */
  sim_icache_fetch(2272 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3376 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3377 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3378 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3379 */
   __ADD_CYCLES(1);
} /* line 3379 */
  sim_icache_fetch(2278 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 3381 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3382 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3383 */
} /* line 3383 */
  sim_icache_fetch(2281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3385 */
  sim_icache_fetch(2282 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3387 */
} /* line 3387 */
  sim_icache_fetch(2284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3389 */
} /* line 3389 */
  sim_icache_fetch(2285 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3391 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3392 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3393 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3394 */
   __ADD_CYCLES(1);
} /* line 3394 */
  sim_icache_fetch(2291 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 3396 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3397 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3398 */
} /* line 3398 */
  sim_icache_fetch(2294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3400 */
  sim_icache_fetch(2295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3402 */
} /* line 3402 */
  sim_icache_fetch(2297 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3404 */
} /* line 3404 */
  sim_icache_fetch(2298 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3406 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3407 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3408 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3409 */
   __ADD_CYCLES(1);
} /* line 3409 */
  sim_icache_fetch(2304 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 3411 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3412 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3413 */
} /* line 3413 */
  sim_icache_fetch(2307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3415 */
  sim_icache_fetch(2308 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3417 */
} /* line 3417 */
  sim_icache_fetch(2310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3419 */
} /* line 3419 */
  sim_icache_fetch(2311 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3421 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3422 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3423 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3424 */
   __ADD_CYCLES(1);
} /* line 3424 */
  sim_icache_fetch(2317 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 3426 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3427 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3428 */
} /* line 3428 */
  sim_icache_fetch(2320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3430 */
  sim_icache_fetch(2321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3432 */
} /* line 3432 */
  sim_icache_fetch(2323 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3434 */
} /* line 3434 */
  sim_icache_fetch(2324 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3436 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3437 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3438 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3439 */
   __ADD_CYCLES(1);
} /* line 3439 */
  sim_icache_fetch(2330 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 3441 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3442 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3443 */
} /* line 3443 */
  sim_icache_fetch(2333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3445 */
  sim_icache_fetch(2334 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3447 */
} /* line 3447 */
  sim_icache_fetch(2336 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3449 */
} /* line 3449 */
  sim_icache_fetch(2337 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3451 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3452 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3453 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3454 */
   __ADD_CYCLES(1);
} /* line 3454 */
  sim_icache_fetch(2343 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 3456 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3457 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3458 */
} /* line 3458 */
  sim_icache_fetch(2346 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3460 */
  sim_icache_fetch(2347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3462 */
} /* line 3462 */
  sim_icache_fetch(2349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3464 */
} /* line 3464 */
  sim_icache_fetch(2350 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3466 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3467 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3468 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3469 */
   __ADD_CYCLES(1);
} /* line 3469 */
  sim_icache_fetch(2356 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_2); /* line 3471 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3472 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3473 */
} /* line 3473 */
  sim_icache_fetch(2359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3475 */
  sim_icache_fetch(2360 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3477 */
} /* line 3477 */
  sim_icache_fetch(2362 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3479 */
} /* line 3479 */
  sim_icache_fetch(2363 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3481 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3482 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3483 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3484 */
   __ADD_CYCLES(1);
} /* line 3484 */
  sim_icache_fetch(2369 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_2); /* line 3486 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3487 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3488 */
} /* line 3488 */
  sim_icache_fetch(2372 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3490 */
  sim_icache_fetch(2373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3492 */
} /* line 3492 */
  sim_icache_fetch(2375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_5); /* line 3494 */
} /* line 3494 */
  sim_icache_fetch(2376 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3496 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_37,0,1)); /* line 3497 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3498 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3499 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3500 */
   __ADD_CYCLES(1);
} /* line 3500 */
  sim_icache_fetch(2383 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3502 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3503 */
   __MOV(reg_r0_3, reg_r0_38); /* line 3504 */
} /* line 3504 */
  sim_icache_fetch(2386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3506 */
  sim_icache_fetch(2387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3508 */
} /* line 3508 */
  sim_icache_fetch(2389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3510 */
} /* line 3510 */
  sim_icache_fetch(2390 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3512 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3513 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3514 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3515 */
   __ADD_CYCLES(1);
} /* line 3515 */
  sim_icache_fetch(2396 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3517 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3518 */
} /* line 3518 */
  sim_icache_fetch(2398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3520 */
  sim_icache_fetch(2399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3522 */
} /* line 3522 */
  sim_icache_fetch(2401 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3524 */
} /* line 3524 */
  sim_icache_fetch(2402 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3526 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3527 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3528 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3529 */
   __ADD_CYCLES(1);
} /* line 3529 */
  sim_icache_fetch(2408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3531 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3532 */
} /* line 3532 */
  sim_icache_fetch(2410 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3534 */
  sim_icache_fetch(2411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3536 */
} /* line 3536 */
  sim_icache_fetch(2413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3538 */
} /* line 3538 */
  sim_icache_fetch(2414 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3540 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3541 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3542 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3543 */
   __ADD_CYCLES(1);
} /* line 3543 */
  sim_icache_fetch(2420 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3545 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3546 */
} /* line 3546 */
  sim_icache_fetch(2422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3548 */
  sim_icache_fetch(2423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3550 */
} /* line 3550 */
  sim_icache_fetch(2425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3552 */
} /* line 3552 */
  sim_icache_fetch(2426 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3554 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3555 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3556 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3557 */
   __ADD_CYCLES(1);
} /* line 3557 */
  sim_icache_fetch(2432 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3559 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3560 */
} /* line 3560 */
  sim_icache_fetch(2434 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3562 */
  sim_icache_fetch(2435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3564 */
} /* line 3564 */
  sim_icache_fetch(2437 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3566 */
} /* line 3566 */
  sim_icache_fetch(2438 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3568 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3569 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3570 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3571 */
   __ADD_CYCLES(1);
} /* line 3571 */
  sim_icache_fetch(2444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3573 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3574 */
} /* line 3574 */
  sim_icache_fetch(2446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3576 */
  sim_icache_fetch(2447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3578 */
} /* line 3578 */
  sim_icache_fetch(2449 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3580 */
} /* line 3580 */
  sim_icache_fetch(2450 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3582 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3583 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3584 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3585 */
   __ADD_CYCLES(1);
} /* line 3585 */
  sim_icache_fetch(2456 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3587 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3588 */
} /* line 3588 */
  sim_icache_fetch(2458 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3590 */
  sim_icache_fetch(2459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3592 */
} /* line 3592 */
  sim_icache_fetch(2461 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3594 */
} /* line 3594 */
  sim_icache_fetch(2462 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3596 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3597 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3598 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3599 */
   __ADD_CYCLES(1);
} /* line 3599 */
  sim_icache_fetch(2468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3601 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3602 */
} /* line 3602 */
  sim_icache_fetch(2470 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3604 */
  sim_icache_fetch(2471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3606 */
} /* line 3606 */
  sim_icache_fetch(2473 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3608 */
} /* line 3608 */
  sim_icache_fetch(2474 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3610 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3611 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3612 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3613 */
   __ADD_CYCLES(1);
} /* line 3613 */
  sim_icache_fetch(2480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3615 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3616 */
} /* line 3616 */
  sim_icache_fetch(2482 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3618 */
  sim_icache_fetch(2483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3620 */
} /* line 3620 */
  sim_icache_fetch(2485 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3622 */
} /* line 3622 */
  sim_icache_fetch(2486 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3624 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3625 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3626 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3627 */
   __ADD_CYCLES(1);
} /* line 3627 */
  sim_icache_fetch(2492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3629 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3630 */
} /* line 3630 */
  sim_icache_fetch(2494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3632 */
  sim_icache_fetch(2495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3634 */
} /* line 3634 */
  sim_icache_fetch(2497 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3636 */
} /* line 3636 */
  sim_icache_fetch(2498 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3638 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3639 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3640 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3641 */
   __ADD_CYCLES(1);
} /* line 3641 */
  sim_icache_fetch(2504 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3643 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3644 */
} /* line 3644 */
  sim_icache_fetch(2506 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3646 */
  sim_icache_fetch(2507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3648 */
} /* line 3648 */
  sim_icache_fetch(2509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3650 */
} /* line 3650 */
  sim_icache_fetch(2510 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3652 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3653 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3654 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3655 */
   __ADD_CYCLES(1);
} /* line 3655 */
  sim_icache_fetch(2516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3657 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3658 */
} /* line 3658 */
  sim_icache_fetch(2518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3660 */
  sim_icache_fetch(2519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3662 */
} /* line 3662 */
  sim_icache_fetch(2521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3664 */
} /* line 3664 */
  sim_icache_fetch(2522 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3666 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3667 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3668 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3669 */
   __ADD_CYCLES(1);
} /* line 3669 */
  sim_icache_fetch(2528 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3671 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3672 */
} /* line 3672 */
  sim_icache_fetch(2530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3674 */
  sim_icache_fetch(2531 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3676 */
} /* line 3676 */
  sim_icache_fetch(2533 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3678 */
} /* line 3678 */
  sim_icache_fetch(2534 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3680 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3681 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3682 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3683 */
   __ADD_CYCLES(1);
} /* line 3683 */
  sim_icache_fetch(2540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3685 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3686 */
} /* line 3686 */
  sim_icache_fetch(2542 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3688 */
  sim_icache_fetch(2543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3690 */
} /* line 3690 */
  sim_icache_fetch(2545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3692 */
} /* line 3692 */
  sim_icache_fetch(2546 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3694 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3695 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3696 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3697 */
   __ADD_CYCLES(1);
} /* line 3697 */
  sim_icache_fetch(2552 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3699 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3700 */
} /* line 3700 */
  sim_icache_fetch(2554 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3702 */
  sim_icache_fetch(2555 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3704 */
} /* line 3704 */
  sim_icache_fetch(2557 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3706 */
} /* line 3706 */
  sim_icache_fetch(2558 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3708 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3709 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3710 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3711 */
   __ADD_CYCLES(1);
} /* line 3711 */
  sim_icache_fetch(2564 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3713 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3714 */
} /* line 3714 */
  sim_icache_fetch(2566 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3716 */
  sim_icache_fetch(2567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3718 */
} /* line 3718 */
  sim_icache_fetch(2569 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3720 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 3721 */
l_L175X3: ;/* line 3724 */
__LABEL(l_L175X3);
  sim_icache_fetch(2571 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3725 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3726 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3727 */
   __ADD_CYCLES(1);
} /* line 3727 */
  sim_icache_fetch(2576 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3729 */
} /* line 3729 */
  sim_icache_fetch(2577 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3731 */
} /* line 3731 */
l_L173X3: ;/* line 3734 */
__LABEL(l_L173X3);
  sim_icache_fetch(2579 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_10519Xoffset,0,4), 0); /* line 3735 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3736 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3737 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3738 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3739 */
   __ADD_CYCLES(1);
} /* line 3739 */
  sim_icache_fetch(2587 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3741 */
} /* line 3741 */
  sim_icache_fetch(2588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L176X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3743 */
  sim_icache_fetch(2589 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3746 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3747 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3748 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3749 */
l_L176X3: ;/* line 3752 */
__LABEL(l_L176X3);
  sim_icache_fetch(2596 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3753 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3754 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3755 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3756 */
   __ADD_CYCLES(1);
} /* line 3756 */
  sim_icache_fetch(2603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3758 */
} /* line 3758 */
  sim_icache_fetch(2604 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3760 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3761 */
} /* line 3761 */
  sim_icache_fetch(2607 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L177X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3763 */
  sim_icache_fetch(2608 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3766 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3767 */
l_L177X3: ;/* line 3770 */
__LABEL(l_L177X3);
  sim_icache_fetch(2611 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3771 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3772 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3773 */
   __ADD_CYCLES(1);
} /* line 3773 */
  sim_icache_fetch(2615 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3775 */
} /* line 3775 */
  sim_icache_fetch(2616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3777 */
} /* line 3777 */
  sim_icache_fetch(2617 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3780 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3781 */
l_L172X3: ;/* line 3784 */
__LABEL(l_L172X3);
  sim_icache_fetch(2620 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3786 */
l_L166X3: ;/* line 3789 */
__LABEL(l_L166X3);
  sim_icache_fetch(2621 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3790 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3791 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3792 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3793 */
   __ADD_CYCLES(1);
} /* line 3793 */
  sim_icache_fetch(2628 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3795 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3796 */
} /* line 3796 */
  sim_icache_fetch(2630 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3798 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3799 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L178X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3800 */
l_L179X3: ;/* line 3802 */
__LABEL(l_L179X3);
  sim_icache_fetch(2633 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3803 */
   __STW(mem_trace_st((unsigned int) compress_10519Xoffset,0,4), 0); /* line 3804 */
} /* line 3804 */
  sim_icache_fetch(2636 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3806 */
} /* line 3806 */
  sim_icache_fetch(2637 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(2638 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3811 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3812 */
l_L178X3: ;/* line 3815 */
__LABEL(l_L178X3);
  sim_icache_fetch(2641 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3816 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3817 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3818 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3819 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3820 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3821 */
} /* line 3821 */
  sim_icache_fetch(2647 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3823 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3824 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3825 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3826 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3827 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3828 */
} /* line 3828 */
  sim_icache_fetch(2653 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3830 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3831 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3832 */
   __MOV(reg_r0_5, (unsigned int) compress_10519Xbuf); /* line 3833 */
   __MOV(reg_r0_3, 0); /* line 3834 */
} /* line 3834 */
l_L180X3: ;/* line 3837 */
__LABEL(l_L180X3);
  sim_icache_fetch(2659 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3838 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3839 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3840 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3841 */
   __ADD_CYCLES(1);
} /* line 3841 */
  sim_icache_fetch(2665 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3843 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3844 */
} /* line 3844 */
  sim_icache_fetch(2667 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3846 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3847 */
} /* line 3847 */
  sim_icache_fetch(2669 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3849 */
} /* line 3849 */
  sim_icache_fetch(2670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3851 */
} /* line 3851 */
  sim_icache_fetch(2671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3853 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3854 */
} /* line 3854 */
  sim_icache_fetch(2673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L181X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3856 */
  sim_icache_fetch(2674 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3858 */
} /* line 3858 */
  sim_icache_fetch(2676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3860 */
} /* line 3860 */
  sim_icache_fetch(2677 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3862 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3863 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3864 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3865 */
   __ADD_CYCLES(1);
} /* line 3865 */
  sim_icache_fetch(2683 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3867 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3868 */
} /* line 3868 */
  sim_icache_fetch(2685 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3870 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3871 */
} /* line 3871 */
  sim_icache_fetch(2687 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3873 */
} /* line 3873 */
  sim_icache_fetch(2688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3875 */
} /* line 3875 */
  sim_icache_fetch(2689 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3877 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3878 */
} /* line 3878 */
  sim_icache_fetch(2691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L182X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3880 */
  sim_icache_fetch(2692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3882 */
} /* line 3882 */
  sim_icache_fetch(2694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3884 */
} /* line 3884 */
  sim_icache_fetch(2695 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3886 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3887 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3888 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3889 */
   __ADD_CYCLES(1);
} /* line 3889 */
  sim_icache_fetch(2701 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3891 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3892 */
} /* line 3892 */
  sim_icache_fetch(2703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3894 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3895 */
} /* line 3895 */
  sim_icache_fetch(2705 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3897 */
} /* line 3897 */
  sim_icache_fetch(2706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3899 */
} /* line 3899 */
  sim_icache_fetch(2707 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3901 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3902 */
} /* line 3902 */
  sim_icache_fetch(2709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L183X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3904 */
  sim_icache_fetch(2710 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3906 */
} /* line 3906 */
  sim_icache_fetch(2712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3908 */
} /* line 3908 */
  sim_icache_fetch(2713 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3910 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3911 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3912 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3913 */
   __ADD_CYCLES(1);
} /* line 3913 */
  sim_icache_fetch(2719 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3915 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3916 */
} /* line 3916 */
  sim_icache_fetch(2721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3918 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3919 */
} /* line 3919 */
  sim_icache_fetch(2723 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3921 */
} /* line 3921 */
  sim_icache_fetch(2724 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3923 */
} /* line 3923 */
  sim_icache_fetch(2725 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3925 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3926 */
} /* line 3926 */
  sim_icache_fetch(2727 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L184X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3928 */
  sim_icache_fetch(2728 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3930 */
} /* line 3930 */
  sim_icache_fetch(2730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3932 */
} /* line 3932 */
  sim_icache_fetch(2731 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3934 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3935 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3936 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3937 */
   __ADD_CYCLES(1);
} /* line 3937 */
  sim_icache_fetch(2737 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3939 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3940 */
} /* line 3940 */
  sim_icache_fetch(2739 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3942 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3943 */
} /* line 3943 */
  sim_icache_fetch(2741 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3945 */
} /* line 3945 */
  sim_icache_fetch(2742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3947 */
} /* line 3947 */
  sim_icache_fetch(2743 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 3949 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3950 */
} /* line 3950 */
  sim_icache_fetch(2745 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L185X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3952 */
  sim_icache_fetch(2746 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3954 */
} /* line 3954 */
  sim_icache_fetch(2748 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3956 */
} /* line 3956 */
  sim_icache_fetch(2749 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3958 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3959 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3960 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3961 */
   __ADD_CYCLES(1);
} /* line 3961 */
  sim_icache_fetch(2755 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3963 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3964 */
} /* line 3964 */
  sim_icache_fetch(2757 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3966 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3967 */
} /* line 3967 */
  sim_icache_fetch(2759 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3969 */
} /* line 3969 */
  sim_icache_fetch(2760 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3971 */
} /* line 3971 */
  sim_icache_fetch(2761 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 3973 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3974 */
} /* line 3974 */
  sim_icache_fetch(2763 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L186X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3976 */
  sim_icache_fetch(2764 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3978 */
} /* line 3978 */
  sim_icache_fetch(2766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3980 */
} /* line 3980 */
  sim_icache_fetch(2767 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 3982 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3983 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3984 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3985 */
   __ADD_CYCLES(1);
} /* line 3985 */
  sim_icache_fetch(2773 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3987 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3988 */
} /* line 3988 */
  sim_icache_fetch(2775 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3990 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3991 */
} /* line 3991 */
  sim_icache_fetch(2777 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3993 */
} /* line 3993 */
  sim_icache_fetch(2778 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3995 */
} /* line 3995 */
  sim_icache_fetch(2779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 3997 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 3998 */
} /* line 3998 */
  sim_icache_fetch(2781 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L187X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4000 */
  sim_icache_fetch(2782 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4002 */
} /* line 4002 */
  sim_icache_fetch(2784 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4004 */
} /* line 4004 */
  sim_icache_fetch(2785 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4006 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4007 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4008 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4009 */
   __ADD_CYCLES(1);
} /* line 4009 */
  sim_icache_fetch(2791 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4011 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4012 */
} /* line 4012 */
  sim_icache_fetch(2793 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4014 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4015 */
} /* line 4015 */
  sim_icache_fetch(2795 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4017 */
} /* line 4017 */
  sim_icache_fetch(2796 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4019 */
} /* line 4019 */
  sim_icache_fetch(2797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4021 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4022 */
} /* line 4022 */
  sim_icache_fetch(2799 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L188X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4024 */
  sim_icache_fetch(2800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4026 */
} /* line 4026 */
  sim_icache_fetch(2802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4028 */
} /* line 4028 */
  sim_icache_fetch(2803 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4030 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4031 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4032 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4033 */
   __ADD_CYCLES(1);
} /* line 4033 */
  sim_icache_fetch(2809 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4035 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4036 */
} /* line 4036 */
  sim_icache_fetch(2811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4038 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4039 */
} /* line 4039 */
  sim_icache_fetch(2813 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4041 */
} /* line 4041 */
  sim_icache_fetch(2814 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4043 */
} /* line 4043 */
  sim_icache_fetch(2815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4045 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4046 */
} /* line 4046 */
  sim_icache_fetch(2817 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L189X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4048 */
  sim_icache_fetch(2818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4050 */
} /* line 4050 */
  sim_icache_fetch(2820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4052 */
} /* line 4052 */
  sim_icache_fetch(2821 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4054 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4055 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4056 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4057 */
   __ADD_CYCLES(1);
} /* line 4057 */
  sim_icache_fetch(2827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4059 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4060 */
} /* line 4060 */
  sim_icache_fetch(2829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4062 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4063 */
} /* line 4063 */
  sim_icache_fetch(2831 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4065 */
} /* line 4065 */
  sim_icache_fetch(2832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4067 */
} /* line 4067 */
  sim_icache_fetch(2833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4069 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4070 */
} /* line 4070 */
  sim_icache_fetch(2835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L190X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4072 */
  sim_icache_fetch(2836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4074 */
} /* line 4074 */
  sim_icache_fetch(2838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4076 */
} /* line 4076 */
  sim_icache_fetch(2839 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4078 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4079 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4080 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4081 */
   __ADD_CYCLES(1);
} /* line 4081 */
  sim_icache_fetch(2845 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4083 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4084 */
} /* line 4084 */
  sim_icache_fetch(2847 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4086 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4087 */
} /* line 4087 */
  sim_icache_fetch(2849 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4089 */
} /* line 4089 */
  sim_icache_fetch(2850 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4091 */
} /* line 4091 */
  sim_icache_fetch(2851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4093 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4094 */
} /* line 4094 */
  sim_icache_fetch(2853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L191X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4096 */
  sim_icache_fetch(2854 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4098 */
} /* line 4098 */
  sim_icache_fetch(2856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4100 */
} /* line 4100 */
  sim_icache_fetch(2857 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4102 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4103 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4104 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4105 */
   __ADD_CYCLES(1);
} /* line 4105 */
  sim_icache_fetch(2863 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4107 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4108 */
} /* line 4108 */
  sim_icache_fetch(2865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4110 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4111 */
} /* line 4111 */
  sim_icache_fetch(2867 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4113 */
} /* line 4113 */
  sim_icache_fetch(2868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4115 */
} /* line 4115 */
  sim_icache_fetch(2869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4117 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4118 */
} /* line 4118 */
  sim_icache_fetch(2871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L192X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4120 */
  sim_icache_fetch(2872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4122 */
} /* line 4122 */
  sim_icache_fetch(2874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4124 */
} /* line 4124 */
  sim_icache_fetch(2875 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4126 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4127 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4128 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4129 */
   __ADD_CYCLES(1);
} /* line 4129 */
  sim_icache_fetch(2881 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4131 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4132 */
} /* line 4132 */
  sim_icache_fetch(2883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4134 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4135 */
} /* line 4135 */
  sim_icache_fetch(2885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4137 */
} /* line 4137 */
  sim_icache_fetch(2886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4139 */
} /* line 4139 */
  sim_icache_fetch(2887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4141 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4142 */
} /* line 4142 */
  sim_icache_fetch(2889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L193X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4144 */
  sim_icache_fetch(2890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4146 */
} /* line 4146 */
  sim_icache_fetch(2892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4148 */
} /* line 4148 */
  sim_icache_fetch(2893 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4150 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4151 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4152 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4153 */
   __ADD_CYCLES(1);
} /* line 4153 */
  sim_icache_fetch(2899 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4155 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4156 */
} /* line 4156 */
  sim_icache_fetch(2901 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4158 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4159 */
} /* line 4159 */
  sim_icache_fetch(2903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4161 */
} /* line 4161 */
  sim_icache_fetch(2904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4163 */
} /* line 4163 */
  sim_icache_fetch(2905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4165 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4166 */
} /* line 4166 */
  sim_icache_fetch(2907 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L194X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4168 */
  sim_icache_fetch(2908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4170 */
} /* line 4170 */
  sim_icache_fetch(2910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4172 */
} /* line 4172 */
  sim_icache_fetch(2911 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4174 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4175 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4176 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4177 */
   __ADD_CYCLES(1);
} /* line 4177 */
  sim_icache_fetch(2917 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4179 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4180 */
} /* line 4180 */
  sim_icache_fetch(2919 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4182 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4183 */
} /* line 4183 */
  sim_icache_fetch(2921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4185 */
} /* line 4185 */
  sim_icache_fetch(2922 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4187 */
} /* line 4187 */
  sim_icache_fetch(2923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4189 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4190 */
} /* line 4190 */
  sim_icache_fetch(2925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L195X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4192 */
  sim_icache_fetch(2926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4194 */
} /* line 4194 */
  sim_icache_fetch(2928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4196 */
} /* line 4196 */
  sim_icache_fetch(2929 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4198 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4199 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4200 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4201 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4202 */
   __ADD_CYCLES(1);
} /* line 4202 */
  sim_icache_fetch(2936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4204 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4205 */
} /* line 4205 */
  sim_icache_fetch(2938 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4207 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4208 */
} /* line 4208 */
  sim_icache_fetch(2940 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4210 */
} /* line 4210 */
  sim_icache_fetch(2941 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4212 */
} /* line 4212 */
  sim_icache_fetch(2942 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4214 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4215 */
} /* line 4215 */
  sim_icache_fetch(2944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L196X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4217 */
  sim_icache_fetch(2945 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4219 */
} /* line 4219 */
  sim_icache_fetch(2947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4221 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4222 */
l_L196X3: ;/* line 4225 */
__LABEL(l_L196X3);
  sim_icache_fetch(2949 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4226 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4227 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4228 */
   __ADD_CYCLES(1);
} /* line 4228 */
  sim_icache_fetch(2954 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4230 */
} /* line 4230 */
  sim_icache_fetch(2955 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4232 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4233 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4234 */
l_L195X3: ;/* line 4237 */
__LABEL(l_L195X3);
  sim_icache_fetch(2958 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4238 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4239 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4240 */
   __ADD_CYCLES(1);
} /* line 4240 */
  sim_icache_fetch(2963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4242 */
} /* line 4242 */
  sim_icache_fetch(2964 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4244 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4245 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4246 */
l_L194X3: ;/* line 4249 */
__LABEL(l_L194X3);
  sim_icache_fetch(2967 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4250 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4251 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4252 */
   __ADD_CYCLES(1);
} /* line 4252 */
  sim_icache_fetch(2972 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4254 */
} /* line 4254 */
  sim_icache_fetch(2973 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4256 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4257 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4258 */
l_L193X3: ;/* line 4261 */
__LABEL(l_L193X3);
  sim_icache_fetch(2976 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4262 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4263 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4264 */
   __ADD_CYCLES(1);
} /* line 4264 */
  sim_icache_fetch(2981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4266 */
} /* line 4266 */
  sim_icache_fetch(2982 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4268 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4269 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4270 */
l_L192X3: ;/* line 4273 */
__LABEL(l_L192X3);
  sim_icache_fetch(2985 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4274 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4275 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4276 */
   __ADD_CYCLES(1);
} /* line 4276 */
  sim_icache_fetch(2990 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4278 */
} /* line 4278 */
  sim_icache_fetch(2991 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4280 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4281 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4282 */
l_L191X3: ;/* line 4285 */
__LABEL(l_L191X3);
  sim_icache_fetch(2994 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4286 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4287 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4288 */
   __ADD_CYCLES(1);
} /* line 4288 */
  sim_icache_fetch(2999 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4290 */
} /* line 4290 */
  sim_icache_fetch(3000 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4292 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4293 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4294 */
l_L190X3: ;/* line 4297 */
__LABEL(l_L190X3);
  sim_icache_fetch(3003 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4298 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4299 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4300 */
   __ADD_CYCLES(1);
} /* line 4300 */
  sim_icache_fetch(3008 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4302 */
} /* line 4302 */
  sim_icache_fetch(3009 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4304 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4305 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4306 */
l_L189X3: ;/* line 4309 */
__LABEL(l_L189X3);
  sim_icache_fetch(3012 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4310 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4311 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4312 */
   __ADD_CYCLES(1);
} /* line 4312 */
  sim_icache_fetch(3017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4314 */
} /* line 4314 */
  sim_icache_fetch(3018 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4316 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4317 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4318 */
l_L188X3: ;/* line 4321 */
__LABEL(l_L188X3);
  sim_icache_fetch(3021 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4322 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4323 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4324 */
   __ADD_CYCLES(1);
} /* line 4324 */
  sim_icache_fetch(3026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4326 */
} /* line 4326 */
  sim_icache_fetch(3027 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4328 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4329 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4330 */
l_L187X3: ;/* line 4333 */
__LABEL(l_L187X3);
  sim_icache_fetch(3030 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4334 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4335 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4336 */
   __ADD_CYCLES(1);
} /* line 4336 */
  sim_icache_fetch(3035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4338 */
} /* line 4338 */
  sim_icache_fetch(3036 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4340 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4341 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4342 */
l_L186X3: ;/* line 4345 */
__LABEL(l_L186X3);
  sim_icache_fetch(3039 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4346 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4347 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4348 */
   __ADD_CYCLES(1);
} /* line 4348 */
  sim_icache_fetch(3044 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4350 */
} /* line 4350 */
  sim_icache_fetch(3045 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4352 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4353 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4354 */
l_L185X3: ;/* line 4357 */
__LABEL(l_L185X3);
  sim_icache_fetch(3048 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4358 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4359 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4360 */
   __ADD_CYCLES(1);
} /* line 4360 */
  sim_icache_fetch(3053 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4362 */
} /* line 4362 */
  sim_icache_fetch(3054 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4364 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4365 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4366 */
l_L184X3: ;/* line 4369 */
__LABEL(l_L184X3);
  sim_icache_fetch(3057 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4370 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4371 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4372 */
   __ADD_CYCLES(1);
} /* line 4372 */
  sim_icache_fetch(3062 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4374 */
} /* line 4374 */
  sim_icache_fetch(3063 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4376 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4377 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4378 */
l_L183X3: ;/* line 4381 */
__LABEL(l_L183X3);
  sim_icache_fetch(3066 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4382 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4383 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4384 */
   __ADD_CYCLES(1);
} /* line 4384 */
  sim_icache_fetch(3071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4386 */
} /* line 4386 */
  sim_icache_fetch(3072 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4388 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4389 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4390 */
l_L182X3: ;/* line 4393 */
__LABEL(l_L182X3);
  sim_icache_fetch(3075 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4394 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4395 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4396 */
   __ADD_CYCLES(1);
} /* line 4396 */
  sim_icache_fetch(3080 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4398 */
} /* line 4398 */
  sim_icache_fetch(3081 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4400 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4401 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4402 */
l_L181X3: ;/* line 4405 */
__LABEL(l_L181X3);
  sim_icache_fetch(3084 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4406 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10519Xoffset,0,4)); /* line 4407 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4408 */
   __ADD_CYCLES(1);
} /* line 4408 */
  sim_icache_fetch(3089 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4410 */
} /* line 4410 */
  sim_icache_fetch(3090 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4412 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4413 */
   __GOTO(l_L179X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L179X3;
} /* line 4414 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 331: goto l_L167X3;
    case 332: goto l_L168X3;
    case 333: goto l_L170X3;
    case 334: goto l_L171X3;
    case 335: goto l_L169X3;
    case 336: goto l_L174X3;
    case 337: goto l_L175X3;
    case 338: goto l_L173X3;
    case 339: goto l_L176X3;
    case 340: goto l_L177X3;
    case 341: goto l_L172X3;
    case 342: goto l_L166X3;
    case 343: goto l_L179X3;
    case 344: goto l_L178X3;
    case 345: goto l_L180X3;
    case 346: goto l_L196X3;
    case 347: goto l_L195X3;
    case 348: goto l_L194X3;
    case 349: goto l_L193X3;
    case 350: goto l_L192X3;
    case 351: goto l_L191X3;
    case 352: goto l_L190X3;
    case 353: goto l_L189X3;
    case 354: goto l_L188X3;
    case 355: goto l_L187X3;
    case 356: goto l_L186X3;
    case 357: goto l_L185X3;
    case 358: goto l_L184X3;
    case 359: goto l_L183X3;
    case 360: goto l_L182X3;
    case 361: goto l_L181X3;
    case 362:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int decompress(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(decompress);  sim_gprof_enter(&sim_gprof_idx,"decompress");

  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (416 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3093 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4430 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4431 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4432 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4433 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4434 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4435 */
} /* line 4435 */
  sim_icache_fetch(3100 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4437 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4438 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4439 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4440 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4441 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4442 */
} /* line 4442 */
  sim_icache_fetch(3106 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4444 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4445 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4446 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4447 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4448 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4449 */
} /* line 4449 */
  sim_icache_fetch(3112 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4451 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4452 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4453 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4454 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4455 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4456 */
} /* line 4456 */
  sim_icache_fetch(3121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4458 */
} /* line 4458 */
l_L197X3: ;/* line 4461 */
__LABEL(l_L197X3);
  sim_icache_fetch(3123 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4462 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4463 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4464 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4465 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4466 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4467 */
} /* line 4467 */
  sim_icache_fetch(3129 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4469 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4470 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4471 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4472 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4473 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L198X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4474 */
  sim_icache_fetch(3135 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4476 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4477 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4478 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4479 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4480 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4481 */
} /* line 4481 */
  sim_icache_fetch(3141 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4483 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4484 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4485 */
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4486 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4487 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4488 */
} /* line 4488 */
  sim_icache_fetch(3147 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4490 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4491 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4492 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4493 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4494 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4495 */
} /* line 4495 */
  sim_icache_fetch(3153 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4497 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4498 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4499 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4500 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4501 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4502 */
} /* line 4502 */
  sim_icache_fetch(3159 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4504 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4505 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4506 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4507 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4508 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4509 */
} /* line 4509 */
  sim_icache_fetch(3165 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4511 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4512 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4513 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4514 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4515 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4516 */
} /* line 4516 */
  sim_icache_fetch(3171 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4518 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4519 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4520 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4521 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4522 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4523 */
} /* line 4523 */
  sim_icache_fetch(3177 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4525 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4526 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4527 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4528 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4529 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4530 */
} /* line 4530 */
  sim_icache_fetch(3183 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4532 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4533 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4534 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4535 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4536 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4537 */
} /* line 4537 */
  sim_icache_fetch(3189 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4539 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4540 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4541 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4542 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4543 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4544 */
} /* line 4544 */
  sim_icache_fetch(3195 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4546 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4547 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4548 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4549 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4550 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4551 */
} /* line 4551 */
  sim_icache_fetch(3201 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4553 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4554 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4555 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4556 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4557 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4558 */
} /* line 4558 */
  sim_icache_fetch(3207 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4560 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4561 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4562 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4563 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4564 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4565 */
} /* line 4565 */
  sim_icache_fetch(3213 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4567 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4568 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4569 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4570 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4571 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4572 */
} /* line 4572 */
  sim_icache_fetch(3219 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4574 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4575 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4576 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4577 */
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4578 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4580 */
} /* line 4580 */
  sim_icache_fetch(3225 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L197X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L197X3;
} /* line 4582 */
l_L198X3: ;/* line 4585 */
__LABEL(l_L198X3);
  sim_icache_fetch(3226 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4586 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4587 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4588 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4589 */
   __ADD_CYCLES(1);
} /* line 4589 */
  sim_icache_fetch(3232 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4591 */
} /* line 4591 */
  sim_icache_fetch(3233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4593 */
} /* line 4593 */
		 /* line 4594 */
  sim_icache_fetch(3235 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4596 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (416 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4597 */
l_lr_265: ;/* line 4597 */
__LABEL(l_lr_265);
  sim_icache_fetch(3239 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_2, t__i32_0); /* line 4599 */
   __MOV(reg_r0_4, t__i32_0); /* line 4600 */
   __CMPEQ(reg_b0_0, t__i32_0, (unsigned int) -1); /* line 4601 */
   __MOV(reg_r0_3, 0); /* line 4602 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4603 */
   __MOV(reg_r0_5, t__i32_0); /* line 4604 */
} /* line 4604 */
  sim_icache_fetch(3245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L199X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4606 */
  sim_icache_fetch(3246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4609 */
l_L199X3: ;/* line 4612 */
__LABEL(l_L199X3);
  sim_icache_fetch(3247 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4613 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4614 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4615 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4616 */
} /* line 4616 */
  sim_icache_fetch(3252 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4618 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4619 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4620 */
} /* line 4620 */
  sim_icache_fetch(3256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4622 */
} /* line 4622 */
  sim_icache_fetch(3257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4624 */
} /* line 4624 */
  sim_icache_fetch(3259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4626 */
} /* line 4626 */
l_L200X3: ;/* line 4629 */
__LABEL(l_L200X3);
		 /* line 4629 */
  sim_icache_fetch(3260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (416 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4631 */
l_lr_269: ;/* line 4631 */
__LABEL(l_lr_269);
  sim_icache_fetch(3262 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4633 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4634 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4635 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4636 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4637 */
} /* line 4637 */
  sim_icache_fetch(3269 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4639 */
  sim_icache_fetch(3270 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4641 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4642 */
} /* line 4642 */
  sim_icache_fetch(3273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L202X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4644 */
l_L203X3: ;/* line 4647 */
__LABEL(l_L203X3);
  sim_icache_fetch(3274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4648 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4649 */
} /* line 4649 */
  sim_icache_fetch(3276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4651 */
  sim_icache_fetch(3277 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4653 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4654 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4655 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4656 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4657 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4658 */
} /* line 4658 */
  sim_icache_fetch(3283 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4660 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4661 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4662 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4663 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4664 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4665 */
} /* line 4665 */
  sim_icache_fetch(3289 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4667 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4668 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4669 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4670 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4671 */
   __GOTO(l_L203X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L203X3;
} /* line 4672 */
l_L204X3: ;/* line 4675 */
__LABEL(l_L204X3);
  sim_icache_fetch(3295 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4676 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4677 */
} /* line 4677 */
		 /* line 4678 */
  sim_icache_fetch(3298 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4680 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4681 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (416 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4682 */
l_lr_273: ;/* line 4682 */
__LABEL(l_lr_273);
  sim_icache_fetch(3304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4684 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4685 */
} /* line 4685 */
  sim_icache_fetch(3306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4687 */
l_L202X3: ;/* line 4690 */
__LABEL(l_L202X3);
  sim_icache_fetch(3307 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4691 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4692 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4693 */
   __ADD_CYCLES(1);
} /* line 4693 */
  sim_icache_fetch(3311 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4695 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4696 */
} /* line 4696 */
  sim_icache_fetch(3313 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4698 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L205X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4699 */
  sim_icache_fetch(3316 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4701 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4702 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4703 */
} /* line 4703 */
l_L206X3: ;/* line 4706 */
__LABEL(l_L206X3);
  sim_icache_fetch(3319 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4707 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4708 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4709 */
} /* line 4709 */
  sim_icache_fetch(3324 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4711 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4712 */
  sim_icache_fetch(3326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4714 */
} /* line 4714 */
  sim_icache_fetch(3327 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4716 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4717 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4718 */
} /* line 4718 */
  sim_icache_fetch(3332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4720 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4721 */
  sim_icache_fetch(3334 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4723 */
} /* line 4723 */
  sim_icache_fetch(3335 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4725 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4726 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4727 */
} /* line 4727 */
  sim_icache_fetch(3340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4729 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4730 */
  sim_icache_fetch(3342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4732 */
} /* line 4732 */
  sim_icache_fetch(3343 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4734 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4735 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4736 */
} /* line 4736 */
  sim_icache_fetch(3348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4738 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4739 */
  sim_icache_fetch(3350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4741 */
} /* line 4741 */
  sim_icache_fetch(3351 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4743 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4744 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4745 */
} /* line 4745 */
  sim_icache_fetch(3356 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4747 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4748 */
  sim_icache_fetch(3358 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4750 */
} /* line 4750 */
  sim_icache_fetch(3359 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4752 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4753 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4754 */
} /* line 4754 */
  sim_icache_fetch(3364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4756 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4757 */
  sim_icache_fetch(3366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4759 */
} /* line 4759 */
  sim_icache_fetch(3367 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4761 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4762 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4763 */
} /* line 4763 */
  sim_icache_fetch(3372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4765 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4766 */
  sim_icache_fetch(3374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4768 */
} /* line 4768 */
  sim_icache_fetch(3375 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4770 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4771 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4772 */
} /* line 4772 */
  sim_icache_fetch(3380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4774 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4775 */
  sim_icache_fetch(3382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4777 */
} /* line 4777 */
  sim_icache_fetch(3383 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4779 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4780 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4781 */
} /* line 4781 */
  sim_icache_fetch(3388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4783 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4784 */
  sim_icache_fetch(3390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4786 */
} /* line 4786 */
  sim_icache_fetch(3391 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4788 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4789 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4790 */
} /* line 4790 */
  sim_icache_fetch(3396 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4792 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4793 */
  sim_icache_fetch(3398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4795 */
} /* line 4795 */
  sim_icache_fetch(3399 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4797 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4798 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4799 */
} /* line 4799 */
  sim_icache_fetch(3404 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4801 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4802 */
  sim_icache_fetch(3406 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4804 */
} /* line 4804 */
  sim_icache_fetch(3407 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4806 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4807 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4808 */
} /* line 4808 */
  sim_icache_fetch(3412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4810 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4811 */
  sim_icache_fetch(3414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4813 */
} /* line 4813 */
  sim_icache_fetch(3415 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4815 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4816 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4817 */
} /* line 4817 */
  sim_icache_fetch(3420 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4819 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4820 */
  sim_icache_fetch(3422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4822 */
} /* line 4822 */
  sim_icache_fetch(3423 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4824 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4825 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4826 */
} /* line 4826 */
  sim_icache_fetch(3428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4828 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4829 */
  sim_icache_fetch(3430 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4831 */
} /* line 4831 */
  sim_icache_fetch(3431 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4833 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4834 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4835 */
} /* line 4835 */
  sim_icache_fetch(3436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4837 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4838 */
  sim_icache_fetch(3438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4840 */
} /* line 4840 */
  sim_icache_fetch(3439 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4842 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4843 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4844 */
} /* line 4844 */
  sim_icache_fetch(3444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4846 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4847 */
  sim_icache_fetch(3446 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4849 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4850 */
   __GOTO(l_L206X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L206X3;
} /* line 4851 */
l_L222X3: ;/* line 4854 */
__LABEL(l_L222X3);
  sim_icache_fetch(3449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4855 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4856 */
} /* line 4856 */
  sim_icache_fetch(3451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4858 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 4859 */
l_L224X3: ;/* line 4862 */
__LABEL(l_L224X3);
  sim_icache_fetch(3453 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_5, reg_r0_3); /* line 4863 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4864 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4865 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4866 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4867 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4868 */
} /* line 4868 */
  sim_icache_fetch(3463 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4870 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4871 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4872 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4873 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4874 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4875 */
} /* line 4875 */
  sim_icache_fetch(3474 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4877 */
   __ADD(reg_r0_23, reg_r0_19, (unsigned int) -16); /* line 4878 */
   __ADD(reg_r0_24, reg_r0_18, (unsigned int) -16); /* line 4879 */
   __ADD(reg_r0_25, reg_r0_17, (unsigned int) -16); /* line 4880 */
   __ADD(reg_r0_26, reg_r0_16, (unsigned int) -16); /* line 4881 */
   __ADD(reg_r0_27, reg_r0_15, (unsigned int) -16); /* line 4882 */
} /* line 4882 */
  sim_icache_fetch(3480 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_28, reg_r0_14, (unsigned int) -16); /* line 4884 */
   __ADD(reg_r0_29, reg_r0_13, (unsigned int) -16); /* line 4885 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4886 */
   __ADD(reg_r0_31, reg_r0_11, (unsigned int) -16); /* line 4887 */
   __ADD(reg_r0_32, reg_r0_10, (unsigned int) -16); /* line 4888 */
   __ADD(reg_r0_33, reg_r0_9, (unsigned int) -16); /* line 4889 */
} /* line 4889 */
  sim_icache_fetch(3486 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_38, reg_r0_20); /* line 4891 */
   __ADD(reg_r0_34, reg_r0_8, (unsigned int) -16); /* line 4892 */
   __ADD(reg_r0_35, reg_r0_7, (unsigned int) -16); /* line 4893 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) -16); /* line 4894 */
   __ADD(reg_r0_37, reg_r0_20, (unsigned int) -16); /* line 4895 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 4896 */
} /* line 4896 */
  sim_icache_fetch(3492 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4898 */
   __MOV(reg_r0_40, reg_r0_37); /* line 4899 */
} /* line 4899 */
  sim_icache_fetch(3495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4901 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4902 */
  sim_icache_fetch(3497 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4904 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4905 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4906 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4907 */
   __ADD_CYCLES(1);
} /* line 4907 */
  sim_icache_fetch(3503 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4909 */
} /* line 4909 */
  sim_icache_fetch(3504 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4911 */
} /* line 4911 */
  sim_icache_fetch(3506 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4913 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4914 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4915 */
  sim_icache_fetch(3510 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4917 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4918 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4919 */
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) -16); /* line 4920 */
   __MFB(reg_r0_4, t__i32_0); /* line 4921 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4922 */
   __ADD_CYCLES(1);
} /* line 4922 */
  sim_icache_fetch(3518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4924 */
} /* line 4924 */
  sim_icache_fetch(3519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4926 */
} /* line 4926 */
  sim_icache_fetch(3521 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4928 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4929 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4930 */
  sim_icache_fetch(3524 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4932 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4933 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4934 */
   __ADD(reg_r0_7, reg_r0_35, (unsigned int) -16); /* line 4935 */
   __MFB(reg_r0_4, t__i32_0); /* line 4936 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4937 */
   __ADD_CYCLES(1);
} /* line 4937 */
  sim_icache_fetch(3532 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4939 */
} /* line 4939 */
  sim_icache_fetch(3533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4941 */
} /* line 4941 */
  sim_icache_fetch(3535 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4943 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4944 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4945 */
  sim_icache_fetch(3538 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4947 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4948 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4949 */
   __ADD(reg_r0_8, reg_r0_34, (unsigned int) -16); /* line 4950 */
   __MFB(reg_r0_4, t__i32_0); /* line 4951 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4952 */
   __ADD_CYCLES(1);
} /* line 4952 */
  sim_icache_fetch(3546 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4954 */
} /* line 4954 */
  sim_icache_fetch(3547 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4956 */
} /* line 4956 */
  sim_icache_fetch(3549 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 4958 */
   __MTB(reg_b0_4, reg_r0_4); /* line 4959 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4960 */
  sim_icache_fetch(3552 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 4962 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4963 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 4964 */
   __ADD(reg_r0_9, reg_r0_33, (unsigned int) -16); /* line 4965 */
   __MFB(reg_r0_4, t__i32_0); /* line 4966 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4967 */
   __ADD_CYCLES(1);
} /* line 4967 */
  sim_icache_fetch(3560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4969 */
} /* line 4969 */
  sim_icache_fetch(3561 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4971 */
} /* line 4971 */
  sim_icache_fetch(3563 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 4973 */
   __MTB(reg_b0_5, reg_r0_4); /* line 4974 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4975 */
  sim_icache_fetch(3566 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 4977 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4978 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 4979 */
   __ADD(reg_r0_10, reg_r0_32, (unsigned int) -16); /* line 4980 */
   __MFB(reg_r0_4, t__i32_0); /* line 4981 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4982 */
   __ADD_CYCLES(1);
} /* line 4982 */
  sim_icache_fetch(3574 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4984 */
} /* line 4984 */
  sim_icache_fetch(3575 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4986 */
} /* line 4986 */
  sim_icache_fetch(3577 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 4988 */
   __MTB(reg_b0_6, reg_r0_4); /* line 4989 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4990 */
  sim_icache_fetch(3580 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 4992 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4993 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 4994 */
   __ADD(reg_r0_11, reg_r0_31, (unsigned int) -16); /* line 4995 */
   __MFB(reg_r0_4, t__i32_0); /* line 4996 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4997 */
   __ADD_CYCLES(1);
} /* line 4997 */
  sim_icache_fetch(3588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4999 */
} /* line 4999 */
  sim_icache_fetch(3589 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5001 */
} /* line 5001 */
  sim_icache_fetch(3591 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 5003 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5004 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5005 */
  sim_icache_fetch(3594 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5007 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5008 */
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 5009 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 5010 */
   __MFB(reg_r0_4, t__i32_0); /* line 5011 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5012 */
   __ADD_CYCLES(1);
} /* line 5012 */
  sim_icache_fetch(3602 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5014 */
} /* line 5014 */
  sim_icache_fetch(3603 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5016 */
} /* line 5016 */
  sim_icache_fetch(3605 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5018 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5019 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5020 */
  sim_icache_fetch(3608 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5022 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5023 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5024 */
   __ADD(reg_r0_13, reg_r0_29, (unsigned int) -16); /* line 5025 */
   __MFB(reg_r0_4, t__i32_0); /* line 5026 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5027 */
   __ADD_CYCLES(1);
} /* line 5027 */
  sim_icache_fetch(3616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5029 */
} /* line 5029 */
  sim_icache_fetch(3617 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5031 */
} /* line 5031 */
  sim_icache_fetch(3619 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5033 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5034 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5035 */
  sim_icache_fetch(3622 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5037 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5038 */
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 5039 */
   __ADD(reg_r0_14, reg_r0_28, (unsigned int) -16); /* line 5040 */
   __MFB(reg_r0_4, t__i32_0); /* line 5041 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5042 */
   __ADD_CYCLES(1);
} /* line 5042 */
  sim_icache_fetch(3630 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5044 */
} /* line 5044 */
  sim_icache_fetch(3631 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5046 */
} /* line 5046 */
  sim_icache_fetch(3633 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5048 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5049 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5050 */
  sim_icache_fetch(3636 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5052 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5053 */
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5054 */
   __ADD(reg_r0_15, reg_r0_27, (unsigned int) -16); /* line 5055 */
   __MFB(reg_r0_4, t__i32_0); /* line 5056 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5057 */
   __ADD_CYCLES(1);
} /* line 5057 */
  sim_icache_fetch(3644 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5059 */
} /* line 5059 */
  sim_icache_fetch(3645 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5061 */
} /* line 5061 */
  sim_icache_fetch(3647 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5063 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5064 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5065 */
  sim_icache_fetch(3650 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5067 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5068 */
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5069 */
   __ADD(reg_r0_16, reg_r0_26, (unsigned int) -16); /* line 5070 */
   __MFB(reg_r0_4, t__i32_0); /* line 5071 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5072 */
   __ADD_CYCLES(1);
} /* line 5072 */
  sim_icache_fetch(3658 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5074 */
} /* line 5074 */
  sim_icache_fetch(3659 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5076 */
} /* line 5076 */
  sim_icache_fetch(3661 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5078 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5079 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5080 */
  sim_icache_fetch(3664 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5082 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5083 */
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5084 */
   __ADD(reg_r0_17, reg_r0_25, (unsigned int) -16); /* line 5085 */
   __MFB(reg_r0_4, t__i32_0); /* line 5086 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5087 */
   __ADD_CYCLES(1);
} /* line 5087 */
  sim_icache_fetch(3672 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5089 */
} /* line 5089 */
  sim_icache_fetch(3673 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5091 */
} /* line 5091 */
  sim_icache_fetch(3675 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5093 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5094 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5095 */
  sim_icache_fetch(3678 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5097 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5098 */
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5099 */
   __ADD(reg_r0_18, reg_r0_24, (unsigned int) -16); /* line 5100 */
   __MFB(reg_r0_4, t__i32_0); /* line 5101 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5102 */
   __ADD_CYCLES(1);
} /* line 5102 */
  sim_icache_fetch(3686 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5104 */
} /* line 5104 */
  sim_icache_fetch(3687 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5106 */
} /* line 5106 */
  sim_icache_fetch(3689 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5108 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5109 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5110 */
  sim_icache_fetch(3692 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5112 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5113 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5114 */
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5115 */
   __ADD(reg_r0_19, reg_r0_23, (unsigned int) -16); /* line 5116 */
   __MFB(reg_r0_4, t__i32_0); /* line 5117 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5118 */
   __ADD_CYCLES(1);
} /* line 5118 */
  sim_icache_fetch(3701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5120 */
} /* line 5120 */
  sim_icache_fetch(3702 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5122 */
} /* line 5122 */
  sim_icache_fetch(3704 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5124 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5125 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5126 */
  sim_icache_fetch(3707 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_5, reg_r0_3); /* line 5128 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5129 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5130 */
   __CMPLEU(reg_b0_7, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5131 */
   __ADD(reg_r0_20, reg_r0_37, (unsigned int) -16); /* line 5132 */
   __MFB(reg_r0_22, t__i32_0); /* line 5133 */
} /* line 5133 */
  sim_icache_fetch(3715 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_39); /* line 5135 */
} /* line 5135 */
  sim_icache_fetch(3716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5137 */
} /* line 5137 */
  sim_icache_fetch(3717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5139 */
} /* line 5139 */
  sim_icache_fetch(3719 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5141 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5142 */
  sim_icache_fetch(3721 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5144 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5145 */
   __CMPLEU(reg_b0_0, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5146 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5147 */
   __ADD_CYCLES(1);
} /* line 5147 */
  sim_icache_fetch(3727 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5149 */
} /* line 5149 */
  sim_icache_fetch(3728 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5151 */
} /* line 5151 */
  sim_icache_fetch(3730 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5153 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5154 */
  sim_icache_fetch(3732 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5156 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5157 */
   __CMPLEU(reg_b0_1, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5158 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5159 */
   __ADD_CYCLES(1);
} /* line 5159 */
  sim_icache_fetch(3738 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5161 */
} /* line 5161 */
  sim_icache_fetch(3739 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5163 */
} /* line 5163 */
  sim_icache_fetch(3741 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5165 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5166 */
  sim_icache_fetch(3743 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5168 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5169 */
   __CMPLEU(reg_b0_2, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5170 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5171 */
   __ADD_CYCLES(1);
} /* line 5171 */
  sim_icache_fetch(3749 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5173 */
} /* line 5173 */
  sim_icache_fetch(3750 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5175 */
} /* line 5175 */
  sim_icache_fetch(3752 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5177 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5178 */
  sim_icache_fetch(3754 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5180 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5181 */
   __CMPLEU(reg_b0_3, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5182 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5183 */
   __ADD_CYCLES(1);
} /* line 5183 */
  sim_icache_fetch(3760 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5185 */
} /* line 5185 */
  sim_icache_fetch(3761 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5187 */
} /* line 5187 */
  sim_icache_fetch(3763 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5189 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5190 */
  sim_icache_fetch(3765 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5192 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5193 */
   __CMPLEU(reg_b0_4, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5194 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5195 */
   __ADD_CYCLES(1);
} /* line 5195 */
  sim_icache_fetch(3771 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5197 */
} /* line 5197 */
  sim_icache_fetch(3772 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5199 */
} /* line 5199 */
  sim_icache_fetch(3774 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5201 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5202 */
  sim_icache_fetch(3776 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5204 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5205 */
   __CMPLEU(reg_b0_5, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5206 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5207 */
   __ADD_CYCLES(1);
} /* line 5207 */
  sim_icache_fetch(3782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5209 */
} /* line 5209 */
  sim_icache_fetch(3783 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5211 */
} /* line 5211 */
  sim_icache_fetch(3785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5213 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5214 */
  sim_icache_fetch(3787 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5216 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5217 */
   __CMPLEU(reg_b0_6, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5218 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5219 */
   __ADD_CYCLES(1);
} /* line 5219 */
  sim_icache_fetch(3793 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5221 */
} /* line 5221 */
  sim_icache_fetch(3794 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5223 */
} /* line 5223 */
  sim_icache_fetch(3796 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5225 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5226 */
  sim_icache_fetch(3798 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5228 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5229 */
   __MTB(reg_b0_7, reg_r0_22); /* line 5230 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5231 */
   __ADD_CYCLES(1);
} /* line 5231 */
  sim_icache_fetch(3803 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5233 */
} /* line 5233 */
  sim_icache_fetch(3804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5235 */
} /* line 5235 */
  sim_icache_fetch(3806 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5237 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5238 */
  sim_icache_fetch(3808 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5240 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5241 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5242 */
   __ADD_CYCLES(1);
} /* line 5242 */
  sim_icache_fetch(3812 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5244 */
} /* line 5244 */
  sim_icache_fetch(3813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5246 */
} /* line 5246 */
  sim_icache_fetch(3815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5248 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5249 */
  sim_icache_fetch(3817 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5251 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5252 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5253 */
   __ADD_CYCLES(1);
} /* line 5253 */
  sim_icache_fetch(3821 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5255 */
} /* line 5255 */
  sim_icache_fetch(3822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5257 */
} /* line 5257 */
  sim_icache_fetch(3824 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5259 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5260 */
  sim_icache_fetch(3826 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5262 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5263 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5264 */
   __ADD_CYCLES(1);
} /* line 5264 */
  sim_icache_fetch(3830 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5266 */
} /* line 5266 */
  sim_icache_fetch(3831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5268 */
} /* line 5268 */
  sim_icache_fetch(3833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5270 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5271 */
  sim_icache_fetch(3835 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5273 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5274 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5275 */
   __ADD_CYCLES(1);
} /* line 5275 */
  sim_icache_fetch(3839 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5277 */
} /* line 5277 */
  sim_icache_fetch(3840 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5279 */
} /* line 5279 */
  sim_icache_fetch(3842 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5281 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5282 */
  sim_icache_fetch(3844 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5284 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5285 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5286 */
   __ADD_CYCLES(1);
} /* line 5286 */
  sim_icache_fetch(3848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5288 */
} /* line 5288 */
  sim_icache_fetch(3849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5290 */
} /* line 5290 */
  sim_icache_fetch(3851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5292 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5293 */
  sim_icache_fetch(3853 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5295 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5296 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5297 */
   __ADD_CYCLES(1);
} /* line 5297 */
  sim_icache_fetch(3857 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5299 */
} /* line 5299 */
  sim_icache_fetch(3858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5301 */
} /* line 5301 */
  sim_icache_fetch(3860 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5303 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5304 */
  sim_icache_fetch(3862 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5306 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5307 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5308 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5309 */
   __ADD_CYCLES(1);
} /* line 5309 */
  sim_icache_fetch(3867 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5311 */
} /* line 5311 */
  sim_icache_fetch(3868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5313 */
} /* line 5313 */
  sim_icache_fetch(3870 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5315 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5317 */
  sim_icache_fetch(3872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5319 */
l_L240X3: ;/* line 5322 */
__LABEL(l_L240X3);
  sim_icache_fetch(3873 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5323 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5324 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5325 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5326 */
l_L243X3: ;/* line 5329 */
__LABEL(l_L243X3);
  sim_icache_fetch(3879 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5330 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5331 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5332 */
} /* line 5332 */
  sim_icache_fetch(3884 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5334 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5335 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5336 */
l_L239X3: ;/* line 5339 */
__LABEL(l_L239X3);
  sim_icache_fetch(3888 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5340 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5341 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5342 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5343 */
l_L238X3: ;/* line 5346 */
__LABEL(l_L238X3);
  sim_icache_fetch(3894 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5347 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5348 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5349 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5350 */
l_L237X3: ;/* line 5353 */
__LABEL(l_L237X3);
  sim_icache_fetch(3900 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5354 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5355 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5356 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5357 */
l_L236X3: ;/* line 5360 */
__LABEL(l_L236X3);
  sim_icache_fetch(3906 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5361 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5362 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5363 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5364 */
l_L235X3: ;/* line 5367 */
__LABEL(l_L235X3);
  sim_icache_fetch(3912 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5368 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5369 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5370 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5371 */
l_L234X3: ;/* line 5374 */
__LABEL(l_L234X3);
  sim_icache_fetch(3918 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5375 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5376 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5377 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5378 */
l_L233X3: ;/* line 5381 */
__LABEL(l_L233X3);
  sim_icache_fetch(3924 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5382 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5383 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5384 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5385 */
l_L232X3: ;/* line 5388 */
__LABEL(l_L232X3);
  sim_icache_fetch(3930 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5389 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5390 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5391 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5392 */
l_L231X3: ;/* line 5395 */
__LABEL(l_L231X3);
  sim_icache_fetch(3936 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5396 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5397 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5398 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5399 */
l_L230X3: ;/* line 5402 */
__LABEL(l_L230X3);
  sim_icache_fetch(3942 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5403 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5404 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5405 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5406 */
l_L229X3: ;/* line 5409 */
__LABEL(l_L229X3);
  sim_icache_fetch(3948 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5410 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5411 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5412 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5413 */
l_L228X3: ;/* line 5416 */
__LABEL(l_L228X3);
  sim_icache_fetch(3954 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5417 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5418 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5419 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5420 */
l_L227X3: ;/* line 5423 */
__LABEL(l_L227X3);
  sim_icache_fetch(3960 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5424 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5425 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5426 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5427 */
l_L226X3: ;/* line 5430 */
__LABEL(l_L226X3);
  sim_icache_fetch(3966 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5431 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5432 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5433 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 5434 */
l_L225X3: ;/* line 5437 */
__LABEL(l_L225X3);
  sim_icache_fetch(3972 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5438 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5439 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5440 */
} /* line 5440 */
l_L241X3: ;/* line 5442 */
__LABEL(l_L241X3);
  sim_icache_fetch(3977 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5442 */
  sim_icache_fetch(3978 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5444 */
} /* line 5444 */
  sim_icache_fetch(3979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L243X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5446 */
l_L242X3: ;/* line 5448 */
__LABEL(l_L242X3);
  sim_icache_fetch(3980 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5449 */
   __GOTO(l_L200X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L200X3;
} /* line 5450 */
l_L221X3: ;/* line 5453 */
__LABEL(l_L221X3);
  sim_icache_fetch(3982 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5454 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5455 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5456 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5457 */
l_L220X3: ;/* line 5460 */
__LABEL(l_L220X3);
  sim_icache_fetch(3986 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5461 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5462 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5463 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5464 */
l_L219X3: ;/* line 5467 */
__LABEL(l_L219X3);
  sim_icache_fetch(3990 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5468 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5469 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5470 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5471 */
l_L218X3: ;/* line 5474 */
__LABEL(l_L218X3);
  sim_icache_fetch(3994 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5475 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5476 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5477 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5478 */
l_L217X3: ;/* line 5481 */
__LABEL(l_L217X3);
  sim_icache_fetch(3998 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5482 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5483 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5484 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5485 */
l_L216X3: ;/* line 5488 */
__LABEL(l_L216X3);
  sim_icache_fetch(4002 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5489 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5490 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5491 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5492 */
l_L215X3: ;/* line 5495 */
__LABEL(l_L215X3);
  sim_icache_fetch(4006 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5496 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5497 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5498 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5499 */
l_L214X3: ;/* line 5502 */
__LABEL(l_L214X3);
  sim_icache_fetch(4010 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5503 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5504 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5505 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5506 */
l_L213X3: ;/* line 5509 */
__LABEL(l_L213X3);
  sim_icache_fetch(4014 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5510 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5511 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5512 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5513 */
l_L212X3: ;/* line 5516 */
__LABEL(l_L212X3);
  sim_icache_fetch(4018 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5517 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5518 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5519 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5520 */
l_L211X3: ;/* line 5523 */
__LABEL(l_L211X3);
  sim_icache_fetch(4022 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5524 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5525 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5526 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5527 */
l_L210X3: ;/* line 5530 */
__LABEL(l_L210X3);
  sim_icache_fetch(4026 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5531 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5532 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5533 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5534 */
l_L209X3: ;/* line 5537 */
__LABEL(l_L209X3);
  sim_icache_fetch(4030 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5538 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5539 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5540 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5541 */
l_L208X3: ;/* line 5544 */
__LABEL(l_L208X3);
  sim_icache_fetch(4034 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5545 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5546 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5547 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5548 */
l_L207X3: ;/* line 5553 */
__LABEL(l_L207X3);
  sim_icache_fetch(4038 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5554 */
} /* line 5554 */
l_L223X3: ;/* line 5556 */
__LABEL(l_L223X3);
  sim_icache_fetch(4039 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5557 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5558 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5559 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5560 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5561 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5562 */
} /* line 5562 */
  sim_icache_fetch(4046 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5564 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5565 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5566 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5567 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5568 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5569 */
} /* line 5569 */
  sim_icache_fetch(4052 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5571 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5572 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5573 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5574 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5575 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5576 */
} /* line 5576 */
  sim_icache_fetch(4058 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5578 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5579 */
l_L205X3: ;/* line 5582 */
__LABEL(l_L205X3);
  sim_icache_fetch(4060 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5583 */
   __GOTO(l_L206X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L206X3;
} /* line 5584 */
l_L201X3: ;/* line 5587 */
__LABEL(l_L201X3);
  sim_icache_fetch(4062 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5588 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5589 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5590 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5591 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5592 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5593 */
   __ADD_CYCLES(1);
} /* line 5593 */
  sim_icache_fetch(4068 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5596 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 363: goto l_L197X3;
    case 364: goto l_L198X3;
    case 366: goto l_lr_265;
    case 367: goto l_L199X3;
    case 368: goto l_L200X3;
    case 370: goto l_lr_269;
    case 371: goto l_L203X3;
    case 372: goto l_L204X3;
    case 374: goto l_lr_273;
    case 375: goto l_L202X3;
    case 376: goto l_L206X3;
    case 377: goto l_L222X3;
    case 378: goto l_L224X3;
    case 379: goto l_L240X3;
    case 380: goto l_L243X3;
    case 381: goto l_L239X3;
    case 382: goto l_L238X3;
    case 383: goto l_L237X3;
    case 384: goto l_L236X3;
    case 385: goto l_L235X3;
    case 386: goto l_L234X3;
    case 387: goto l_L233X3;
    case 388: goto l_L232X3;
    case 389: goto l_L231X3;
    case 390: goto l_L230X3;
    case 391: goto l_L229X3;
    case 392: goto l_L228X3;
    case 393: goto l_L227X3;
    case 394: goto l_L226X3;
    case 395: goto l_L225X3;
    case 396: goto l_L241X3;
    case 397: goto l_L242X3;
    case 398: goto l_L221X3;
    case 399: goto l_L220X3;
    case 400: goto l_L219X3;
    case 401: goto l_L218X3;
    case 402: goto l_L217X3;
    case 403: goto l_L216X3;
    case 404: goto l_L215X3;
    case 405: goto l_L214X3;
    case 406: goto l_L213X3;
    case 407: goto l_L212X3;
    case 408: goto l_L211X3;
    case 409: goto l_L210X3;
    case 410: goto l_L209X3;
    case 411: goto l_L208X3;
    case 412: goto l_L207X3;
    case 413: goto l_L223X3;
    case 414: goto l_L205X3;
    case 415: goto l_L201X3;
    case 416:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int compressgetcode(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(compressgetcode);  sim_gprof_enter(&sim_gprof_idx,"compressgetcode");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (444 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4069 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5615 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5616 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5617 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5618 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5619 */
} /* line 5619 */
  sim_icache_fetch(4079 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5621 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5622 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5623 */
} /* line 5623 */
  sim_icache_fetch(4085 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5625 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5626 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5627 */
} /* line 5627 */
  sim_icache_fetch(4088 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_r0_5, reg_r0_7, reg_r0_8); /* line 5629 */
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5630 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5631 */
} /* line 5631 */
  sim_icache_fetch(4091 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_1, reg_r0_4, reg_r0_5); /* line 5633 */
   __CMPEQ(reg_b0_2, reg_r0_9, reg_r0_2); /* line 5634 */
} /* line 5634 */
  sim_icache_fetch(4093 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5636 */
  sim_icache_fetch(4094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5638 */
  sim_icache_fetch(4095 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5640 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5641 */
  sim_icache_fetch(4098 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5643 */
} /* line 5643 */
l_L245X3: ;/* line 5646 */
__LABEL(l_L245X3);
  sim_icache_fetch(4100 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5647 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5648 */
   __MOV(reg_r0_5, 0); /* line 5649 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5650 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5651 */
   __ADD_CYCLES(1);
} /* line 5651 */
  sim_icache_fetch(4107 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5653 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5654 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5655 */
} /* line 5655 */
  sim_icache_fetch(4110 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5657 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5658 */
l_L248X3: ;/* line 5661 */
__LABEL(l_L248X3);
  sim_icache_fetch(4112 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5662 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5663 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5664 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5665 */
} /* line 5665 */
  sim_icache_fetch(4118 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5667 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5668 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5669 */
  sim_icache_fetch(4121 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5671 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5672 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5673 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5674 */
} /* line 5674 */
  sim_icache_fetch(4125 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5676 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5677 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5678 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5679 */
} /* line 5679 */
  sim_icache_fetch(4130 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5681 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5682 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5683 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5684 */
  sim_icache_fetch(4135 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5686 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5687 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5688 */
} /* line 5688 */
  sim_icache_fetch(4139 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5690 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5691 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5692 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5693 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5694 */
} /* line 5694 */
  sim_icache_fetch(4145 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5696 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5697 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5698 */
} /* line 5698 */
  sim_icache_fetch(4148 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5700 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5701 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5702 */
} /* line 5702 */
l_L251X3: ;/* line 5704 */
__LABEL(l_L251X3);
  sim_icache_fetch(4151 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5705 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5706 */
} /* line 5706 */
  sim_icache_fetch(4154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5708 */
} /* line 5708 */
  sim_icache_fetch(4155 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5710 */
} /* line 5710 */
  sim_icache_fetch(4156 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5712 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5713 */
  sim_icache_fetch(4158 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5715 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5716 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5717 */
  sim_icache_fetch(4161 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5719 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5720 */
  sim_icache_fetch(4164 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5722 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5723 */
} /* line 5723 */
  sim_icache_fetch(4168 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5725 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5726 */
} /* line 5726 */
  sim_icache_fetch(4171 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5728 */
} /* line 5728 */
  sim_icache_fetch(4172 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5730 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5731 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5732 */
} /* line 5732 */
l_L254X3: ;/* line 5734 */
__LABEL(l_L254X3);
  sim_icache_fetch(4175 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5735 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5736 */
} /* line 5736 */
  sim_icache_fetch(4178 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5738 */
} /* line 5738 */
  sim_icache_fetch(4179 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5740 */
} /* line 5740 */
  sim_icache_fetch(4180 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5742 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5743 */
  sim_icache_fetch(4182 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5745 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5746 */
  sim_icache_fetch(4184 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5748 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L255X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5749 */
  sim_icache_fetch(4187 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5751 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5752 */
} /* line 5752 */
  sim_icache_fetch(4191 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5754 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5755 */
} /* line 5755 */
  sim_icache_fetch(4194 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5757 */
} /* line 5757 */
  sim_icache_fetch(4195 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5759 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5760 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5761 */
} /* line 5761 */
l_L256X3: ;/* line 5763 */
__LABEL(l_L256X3);
  sim_icache_fetch(4198 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5764 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5765 */
} /* line 5765 */
  sim_icache_fetch(4201 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5767 */
} /* line 5767 */
  sim_icache_fetch(4202 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5769 */
  sim_icache_fetch(4203 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5771 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5772 */
  sim_icache_fetch(4205 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5774 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L257X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5775 */
  sim_icache_fetch(4208 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5777 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5778 */
} /* line 5778 */
  sim_icache_fetch(4212 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5780 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5781 */
} /* line 5781 */
  sim_icache_fetch(4215 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5783 */
} /* line 5783 */
  sim_icache_fetch(4216 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5785 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5786 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5787 */
} /* line 5787 */
l_L258X3: ;/* line 5789 */
__LABEL(l_L258X3);
  sim_icache_fetch(4219 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5790 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5791 */
} /* line 5791 */
  sim_icache_fetch(4222 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5793 */
} /* line 5793 */
  sim_icache_fetch(4223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5795 */
  sim_icache_fetch(4224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5797 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5798 */
  sim_icache_fetch(4226 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5800 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L259X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5801 */
  sim_icache_fetch(4229 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5803 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5804 */
} /* line 5804 */
  sim_icache_fetch(4233 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5806 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5807 */
} /* line 5807 */
  sim_icache_fetch(4236 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5809 */
} /* line 5809 */
  sim_icache_fetch(4237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5811 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5812 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5813 */
} /* line 5813 */
l_L260X3: ;/* line 5815 */
__LABEL(l_L260X3);
  sim_icache_fetch(4240 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5816 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5817 */
} /* line 5817 */
  sim_icache_fetch(4243 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5819 */
} /* line 5819 */
  sim_icache_fetch(4244 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5821 */
  sim_icache_fetch(4245 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5823 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5824 */
  sim_icache_fetch(4247 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5826 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L261X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5827 */
  sim_icache_fetch(4250 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5829 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5830 */
} /* line 5830 */
  sim_icache_fetch(4254 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5832 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5833 */
} /* line 5833 */
  sim_icache_fetch(4257 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5835 */
} /* line 5835 */
  sim_icache_fetch(4258 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5837 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5838 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5839 */
} /* line 5839 */
l_L262X3: ;/* line 5841 */
__LABEL(l_L262X3);
  sim_icache_fetch(4261 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5842 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5843 */
} /* line 5843 */
  sim_icache_fetch(4264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5845 */
} /* line 5845 */
  sim_icache_fetch(4265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5847 */
  sim_icache_fetch(4266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5849 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5850 */
  sim_icache_fetch(4268 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5852 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L263X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5853 */
  sim_icache_fetch(4271 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5855 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5856 */
} /* line 5856 */
  sim_icache_fetch(4275 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5858 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5859 */
} /* line 5859 */
  sim_icache_fetch(4278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5861 */
} /* line 5861 */
  sim_icache_fetch(4279 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5863 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5864 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5865 */
} /* line 5865 */
l_L264X3: ;/* line 5867 */
__LABEL(l_L264X3);
  sim_icache_fetch(4282 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5868 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5869 */
} /* line 5869 */
  sim_icache_fetch(4285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5871 */
} /* line 5871 */
  sim_icache_fetch(4286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5873 */
  sim_icache_fetch(4287 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5875 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5876 */
  sim_icache_fetch(4289 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5878 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L265X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5879 */
  sim_icache_fetch(4292 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5881 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5882 */
} /* line 5882 */
  sim_icache_fetch(4296 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5884 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5885 */
} /* line 5885 */
  sim_icache_fetch(4299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5887 */
} /* line 5887 */
  sim_icache_fetch(4300 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5889 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5890 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5891 */
} /* line 5891 */
l_L266X3: ;/* line 5893 */
__LABEL(l_L266X3);
  sim_icache_fetch(4303 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5894 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5895 */
} /* line 5895 */
  sim_icache_fetch(4306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5897 */
} /* line 5897 */
  sim_icache_fetch(4307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5899 */
  sim_icache_fetch(4308 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5901 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5902 */
  sim_icache_fetch(4310 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5904 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L267X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5905 */
  sim_icache_fetch(4313 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5907 */
} /* line 5907 */
  sim_icache_fetch(4315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5909 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5910 */
   __ADD_CYCLES(1);
} /* line 5910 */
  sim_icache_fetch(4317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5912 */
} /* line 5912 */
l_L268X3: ;/* line 5914 */
__LABEL(l_L268X3);
  sim_icache_fetch(4318 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5915 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5916 */
} /* line 5916 */
  sim_icache_fetch(4321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5918 */
} /* line 5918 */
  sim_icache_fetch(4322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5920 */
  sim_icache_fetch(4323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5922 */
   __GOTO(l_L248X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L248X3;
} /* line 5923 */
l_L252X3: ;/* line 5926 */
__LABEL(l_L252X3);
  sim_icache_fetch(4325 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5927 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5928 */
   __GOTO(l_L269X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L269X3;
} /* line 5929 */
l_L270X3: ;/* line 5932 */
__LABEL(l_L270X3);
  sim_icache_fetch(4328 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5933 */
   __MOV(reg_r0_7, 0); /* line 5934 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5935 */
} /* line 5935 */
  sim_icache_fetch(4332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5937 */
} /* line 5937 */
  sim_icache_fetch(4333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5939 */
} /* line 5939 */
l_L244X3: ;/* line 5942 */
__LABEL(l_L244X3);
  sim_icache_fetch(4334 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5943 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5944 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5945 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5946 */
} /* line 5946 */
  sim_icache_fetch(4340 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5948 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5949 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5950 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5951 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5952 */
} /* line 5952 */
  sim_icache_fetch(4348 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 5954 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 5955 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 5956 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 5957 */
} /* line 5957 */
  sim_icache_fetch(4352 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 5959 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 5960 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 5961 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 5962 */
} /* line 5962 */
  sim_icache_fetch(4357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 5964 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 5965 */
} /* line 5965 */
  sim_icache_fetch(4359 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5967 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 5968 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 5969 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 5970 */
} /* line 5970 */
  sim_icache_fetch(4363 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 5972 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5973 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 5974 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5975 */
   __ADD_CYCLES(1);
} /* line 5975 */
  sim_icache_fetch(4368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 5977 */
} /* line 5977 */
  sim_icache_fetch(4369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 5979 */
} /* line 5979 */
  sim_icache_fetch(4370 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 5982 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5983 */
l_L267X3: ;/* line 5986 */
__LABEL(l_L267X3);
  sim_icache_fetch(4372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5987 */
   __GOTO(l_L268X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L268X3;
} /* line 5988 */
l_L249X3: ;/* line 5991 */
__LABEL(l_L249X3);
  sim_icache_fetch(4374 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 5992 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5993 */
} /* line 5993 */
l_L269X3: ;/* line 5995 */
__LABEL(l_L269X3);
  sim_icache_fetch(4376 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 5996 */
} /* line 5996 */
  sim_icache_fetch(4377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L270X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5998 */
  sim_icache_fetch(4378 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 6001 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 6002 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6003 */
l_L265X3: ;/* line 6006 */
__LABEL(l_L265X3);
  sim_icache_fetch(4383 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6007 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6008 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6009 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6010 */
   __ADD_CYCLES(1);
} /* line 6010 */
  sim_icache_fetch(4389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6012 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6013 */
} /* line 6013 */
  sim_icache_fetch(4391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6015 */
   __GOTO(l_L266X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L266X3;
} /* line 6016 */
l_L263X3: ;/* line 6019 */
__LABEL(l_L263X3);
  sim_icache_fetch(4393 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6020 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6021 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6022 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6023 */
   __ADD_CYCLES(1);
} /* line 6023 */
  sim_icache_fetch(4399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6025 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6026 */
} /* line 6026 */
  sim_icache_fetch(4401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6028 */
   __GOTO(l_L264X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L264X3;
} /* line 6029 */
l_L261X3: ;/* line 6032 */
__LABEL(l_L261X3);
  sim_icache_fetch(4403 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6033 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6034 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6035 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6036 */
   __ADD_CYCLES(1);
} /* line 6036 */
  sim_icache_fetch(4409 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6038 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6039 */
} /* line 6039 */
  sim_icache_fetch(4411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6041 */
   __GOTO(l_L262X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L262X3;
} /* line 6042 */
l_L259X3: ;/* line 6045 */
__LABEL(l_L259X3);
  sim_icache_fetch(4413 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6046 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6047 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6048 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6049 */
   __ADD_CYCLES(1);
} /* line 6049 */
  sim_icache_fetch(4419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6051 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6052 */
} /* line 6052 */
  sim_icache_fetch(4421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6054 */
   __GOTO(l_L260X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L260X3;
} /* line 6055 */
l_L257X3: ;/* line 6058 */
__LABEL(l_L257X3);
  sim_icache_fetch(4423 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6059 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6060 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6061 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6062 */
   __ADD_CYCLES(1);
} /* line 6062 */
  sim_icache_fetch(4429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6064 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6065 */
} /* line 6065 */
  sim_icache_fetch(4431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6067 */
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6068 */
l_L255X3: ;/* line 6071 */
__LABEL(l_L255X3);
  sim_icache_fetch(4433 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6072 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6073 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6074 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6075 */
   __ADD_CYCLES(1);
} /* line 6075 */
  sim_icache_fetch(4439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6077 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6078 */
} /* line 6078 */
  sim_icache_fetch(4441 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6080 */
   __GOTO(l_L256X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L256X3;
} /* line 6081 */
l_L253X3: ;/* line 6084 */
__LABEL(l_L253X3);
  sim_icache_fetch(4443 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6085 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6086 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6087 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6088 */
   __ADD_CYCLES(1);
} /* line 6088 */
  sim_icache_fetch(4449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6090 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6091 */
} /* line 6091 */
  sim_icache_fetch(4451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6093 */
   __GOTO(l_L254X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L254X3;
} /* line 6094 */
l_L250X3: ;/* line 6097 */
__LABEL(l_L250X3);
  sim_icache_fetch(4453 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6098 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6099 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6100 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6101 */
} /* line 6101 */
  sim_icache_fetch(4458 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6103 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6104 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6105 */
} /* line 6105 */
  sim_icache_fetch(4461 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6107 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6108 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6109 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6110 */
} /* line 6110 */
  sim_icache_fetch(4465 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6112 */
   __GOTO(l_L251X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L251X3;
} /* line 6113 */
l_L247X3: ;/* line 6116 */
__LABEL(l_L247X3);
  sim_icache_fetch(4467 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6117 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6118 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6119 */
} /* line 6119 */
  sim_icache_fetch(4472 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6121 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6122 */
} /* line 6122 */
  sim_icache_fetch(4476 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6124 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6125 */
   __ADD_CYCLES(1);
} /* line 6125 */
  sim_icache_fetch(4479 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6127 */
} /* line 6127 */
  sim_icache_fetch(4480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6129 */
   __GOTO(l_L248X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L248X3;
} /* line 6130 */
l_L246X3: ;/* line 6133 */
__LABEL(l_L246X3);
  sim_icache_fetch(4482 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6134 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6135 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6136 */
   __ADD_CYCLES(1);
} /* line 6136 */
  sim_icache_fetch(4486 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6138 */
} /* line 6138 */
  sim_icache_fetch(4487 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6140 */
} /* line 6140 */
  sim_icache_fetch(4488 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6142 */
   __GOTO(l_L245X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L245X3;
} /* line 6143 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 417: goto l_L245X3;
    case 418: goto l_L248X3;
    case 419: goto l_L251X3;
    case 420: goto l_L254X3;
    case 421: goto l_L256X3;
    case 422: goto l_L258X3;
    case 423: goto l_L260X3;
    case 424: goto l_L262X3;
    case 425: goto l_L264X3;
    case 426: goto l_L266X3;
    case 427: goto l_L268X3;
    case 428: goto l_L252X3;
    case 429: goto l_L270X3;
    case 430: goto l_L244X3;
    case 431: goto l_L267X3;
    case 432: goto l_L249X3;
    case 433: goto l_L269X3;
    case 434: goto l_L265X3;
    case 435: goto l_L263X3;
    case 436: goto l_L261X3;
    case 437: goto l_L259X3;
    case 438: goto l_L257X3;
    case 439: goto l_L255X3;
    case 440: goto l_L253X3;
    case 441: goto l_L250X3;
    case 442: goto l_L247X3;
    case 443: goto l_L246X3;
    case 444:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int writeerr(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(writeerr);  sim_gprof_enter(&sim_gprof_idx,"writeerr");

  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (447 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4491 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6165 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6166 */
} /* line 6166 */
		 /* line 6167 */
  sim_icache_fetch(4494 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6170 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (447 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6170 */
l_lr_345: ;/* line 6170 */
__LABEL(l_lr_345);
  sim_icache_fetch(4497 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6172 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6173 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6174 */
   __ADD_CYCLES(1);
} /* line 6174 */
  sim_icache_fetch(4500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6177 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 446: goto l_lr_345;
    case 447:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int foreground(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(foreground);  sim_gprof_enter(&sim_gprof_idx,"foreground");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (449 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4501 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6223 */
   __MOV(reg_r0_3, 0); /* line 6224 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6225 */
   __ADD_CYCLES(1);
} /* line 6225 */
  sim_icache_fetch(4505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6227 */
} /* line 6227 */
  sim_icache_fetch(4506 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L271X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6229 */
  sim_icache_fetch(4507 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6232 */
l_L271X3: ;/* line 6235 */
__LABEL(l_L271X3);
  sim_icache_fetch(4508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6238 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6238 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 448: goto l_L271X3;
    case 449:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int onintr(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(onintr);  sim_gprof_enter(&sim_gprof_idx,"onintr");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (450 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6254 */
} /* line 6254 */
  sim_icache_fetch(4511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6257 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 450:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int oops(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(oops);  sim_gprof_enter(&sim_gprof_idx,"oops");

  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (454 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4512 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6272 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6273 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6274 */
} /* line 6274 */
  sim_icache_fetch(4517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6276 */
} /* line 6276 */
  sim_icache_fetch(4518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6278 */
} /* line 6278 */
  sim_icache_fetch(4519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L272X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6280 */
		 /* line 6281 */
  sim_icache_fetch(4520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (454 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6283 */
l_lr_351: ;/* line 6283 */
__LABEL(l_lr_351);
l_L272X3: ;/* line 6285 */
__LABEL(l_L272X3);
  sim_icache_fetch(4522 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6286 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6287 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6288 */
   __ADD_CYCLES(1);
} /* line 6288 */
  sim_icache_fetch(4525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6291 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 452: goto l_lr_351;
    case 453: goto l_L272X3;
    case 454:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int cl_block(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(cl_block);  sim_gprof_enter(&sim_gprof_idx,"cl_block");

  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (467 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4526 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6337 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6338 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6339 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6340 */
} /* line 6340 */
  sim_icache_fetch(4533 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6342 */
} /* line 6342 */
  sim_icache_fetch(4534 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6344 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6345 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6346 */
} /* line 6346 */
  sim_icache_fetch(4539 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6348 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6349 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L273X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6350 */
  sim_icache_fetch(4543 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6352 */
l_L275X3: ;/* line 6355 */
__LABEL(l_L275X3);
  sim_icache_fetch(4544 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6356 */
   __MOV(reg_r0_3, 0); /* line 6357 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6358 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6359 */
   __ADD_CYCLES(1);
} /* line 6359 */
  sim_icache_fetch(4549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6361 */
} /* line 6361 */
  sim_icache_fetch(4550 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L276X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6363 */
  sim_icache_fetch(4551 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6366 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6367 */
l_L276X3: ;/* line 6370 */
__LABEL(l_L276X3);
  sim_icache_fetch(4554 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6371 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6372 */
} /* line 6372 */
		 /* line 6373 */
  sim_icache_fetch(4558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (467 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6375 */
l_lr_357: ;/* line 6375 */
__LABEL(l_lr_357);
  sim_icache_fetch(4560 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6377 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6378 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6379 */
} /* line 6379 */
		 /* line 6380 */
  sim_icache_fetch(4565 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6382 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6383 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (467 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6384 */
l_lr_359: ;/* line 6384 */
__LABEL(l_lr_359);
  sim_icache_fetch(4571 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6386 */
   __MOV(reg_r0_3, 0); /* line 6387 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6388 */
   __ADD_CYCLES(1);
} /* line 6388 */
  sim_icache_fetch(4574 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6391 */
l_L274X3: ;/* line 6394 */
__LABEL(l_L274X3);
  sim_icache_fetch(4575 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6395 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6396 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6397 */
   __ADD_CYCLES(1);
} /* line 6397 */
		 /* line 6398 */
  sim_icache_fetch(4579 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6401 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (467 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6401 */
l_lr_362: ;/* line 6401 */
__LABEL(l_lr_362);
  sim_icache_fetch(4582 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6403 */
   __GOTO(l_L275X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L275X3;
} /* line 6404 */
l_L273X3: ;/* line 6407 */
__LABEL(l_L273X3);
  sim_icache_fetch(4584 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6408 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6409 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6410 */
   __ADD_CYCLES(1);
} /* line 6410 */
		 /* line 6411 */
  sim_icache_fetch(4589 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6413 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (467 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6414 */
l_lr_365: ;/* line 6414 */
__LABEL(l_lr_365);
  sim_icache_fetch(4592 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6416 */
   __GOTO(l_L275X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L275X3;
} /* line 6417 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 455: goto l_L275X3;
    case 456: goto l_L276X3;
    case 458: goto l_lr_357;
    case 460: goto l_lr_359;
    case 461: goto l_L274X3;
    case 463: goto l_lr_362;
    case 464: goto l_L273X3;
    case 466: goto l_lr_365;
    case 467:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern  cl_hash( unsigned int arg0 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(cl_hash);  sim_gprof_enter(&sim_gprof_idx,"cl_hash");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_l0_0 = (485 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4594 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6436 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6437 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6438 */
} /* line 6438 */
  sim_icache_fetch(4598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6440 */
} /* line 6440 */
l_L277X3: ;/* line 6443 */
__LABEL(l_L277X3);
  sim_icache_fetch(4599 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_3, reg_r0_2); /* line 6444 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6445 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6446 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6447 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6448 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6449 */
} /* line 6449 */
  sim_icache_fetch(4605 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6451 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6452 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6453 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6454 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6455 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6456 */
} /* line 6456 */
  sim_icache_fetch(4611 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6458 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6459 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6460 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6461 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6462 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6463 */
} /* line 6463 */
  sim_icache_fetch(4617 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6465 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6466 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6467 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6468 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6469 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6470 */
} /* line 6470 */
  sim_icache_fetch(4623 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6472 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6473 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6474 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L278X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6475 */
  sim_icache_fetch(4627 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6477 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6478 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6479 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6480 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6481 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6482 */
} /* line 6482 */
  sim_icache_fetch(4633 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6484 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6485 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6486 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6487 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6488 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6489 */
} /* line 6489 */
  sim_icache_fetch(4639 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6491 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6492 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6493 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6494 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6495 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6496 */
  sim_icache_fetch(4645 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6498 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6499 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6500 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6501 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6502 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6503 */
} /* line 6503 */
  sim_icache_fetch(4651 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6506 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6507 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6508 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6509 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6510 */
} /* line 6510 */
  sim_icache_fetch(4657 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6512 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6513 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6514 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6515 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6516 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6517 */
  sim_icache_fetch(4663 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6519 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6520 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6521 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6522 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6523 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6524 */
} /* line 6524 */
  sim_icache_fetch(4669 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6527 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6528 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6529 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6531 */
} /* line 6531 */
  sim_icache_fetch(4675 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6533 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6534 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6535 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6536 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6537 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6538 */
  sim_icache_fetch(4681 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6540 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6541 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6542 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6543 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6544 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6545 */
} /* line 6545 */
  sim_icache_fetch(4687 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6547 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6548 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6549 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6550 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6551 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6552 */
} /* line 6552 */
  sim_icache_fetch(4693 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6554 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6555 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6556 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6557 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6558 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6559 */
} /* line 6559 */
  sim_icache_fetch(4699 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6561 */
  sim_icache_fetch(4700 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6564 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6565 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6567 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6568 */
} /* line 6568 */
  sim_icache_fetch(4712 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6570 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6571 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6572 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6573 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6574 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6575 */
} /* line 6575 */
  sim_icache_fetch(4724 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6577 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6578 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6579 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6580 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6581 */
  sim_icache_fetch(4733 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6583 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6584 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6588 */
} /* line 6588 */
  sim_icache_fetch(4745 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6590 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6591 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6592 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6593 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6594 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6595 */
} /* line 6595 */
  sim_icache_fetch(4757 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6597 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6600 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6601 */
  sim_icache_fetch(4766 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6604 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6605 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6606 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6608 */
} /* line 6608 */
  sim_icache_fetch(4778 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6610 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6611 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6612 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6613 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6614 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6615 */
} /* line 6615 */
  sim_icache_fetch(4790 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6617 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6620 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6621 */
  sim_icache_fetch(4799 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6623 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6624 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6625 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6626 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6627 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6628 */
} /* line 6628 */
  sim_icache_fetch(4811 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6630 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6631 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6632 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6633 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6634 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6635 */
} /* line 6635 */
  sim_icache_fetch(4823 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6637 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6639 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6640 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6641 */
  sim_icache_fetch(4832 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6644 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6645 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6646 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6647 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6648 */
} /* line 6648 */
  sim_icache_fetch(4844 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6651 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6652 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6653 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6654 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6655 */
} /* line 6655 */
  sim_icache_fetch(4856 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6658 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6659 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6660 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L287X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6661 */
  sim_icache_fetch(4865 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6664 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6665 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6666 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6667 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6668 */
} /* line 6668 */
  sim_icache_fetch(4877 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6670 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6671 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6672 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6673 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6674 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6675 */
} /* line 6675 */
  sim_icache_fetch(4889 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6677 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6678 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6679 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6680 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6681 */
  sim_icache_fetch(4898 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6683 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6684 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6685 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6686 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6687 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6688 */
} /* line 6688 */
  sim_icache_fetch(4910 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6690 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6691 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6692 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6693 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6694 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6695 */
} /* line 6695 */
  sim_icache_fetch(4922 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6697 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6698 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6699 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6700 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6701 */
  sim_icache_fetch(4931 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6703 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6704 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6705 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6706 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6707 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6708 */
} /* line 6708 */
  sim_icache_fetch(4942 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6710 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6711 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6712 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6713 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6714 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6715 */
} /* line 6715 */
  sim_icache_fetch(4953 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6717 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6718 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6719 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6720 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6721 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6722 */
} /* line 6722 */
  sim_icache_fetch(4965 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6724 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6725 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6727 */
  sim_icache_fetch(4970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L277X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L277X3;
} /* line 6729 */
l_L290X3: ;/* line 6732 */
__LABEL(l_L290X3);
  sim_icache_fetch(4971 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6733 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6734 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6735 */
l_L292X3: ;/* line 6738 */
__LABEL(l_L292X3);
  sim_icache_fetch(4975 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6739 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6740 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6741 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6742 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 4); /* line 6743 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6744 */
} /* line 6744 */
  sim_icache_fetch(4981 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 5); /* line 6746 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 6); /* line 6747 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 7); /* line 6748 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 8); /* line 6749 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6750 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6751 */
  sim_icache_fetch(4987 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6753 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6754 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6755 */
  sim_icache_fetch(4990 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6757 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6758 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6759 */
  sim_icache_fetch(4993 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6761 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6762 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6763 */
  sim_icache_fetch(4996 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6765 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6766 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6767 */
  sim_icache_fetch(4999 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6769 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 12); /* line 6770 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6771 */
  sim_icache_fetch(5002 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6773 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 13); /* line 6774 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6775 */
  sim_icache_fetch(5005 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6777 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 14); /* line 6778 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6779 */
  sim_icache_fetch(5008 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6781 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 15); /* line 6782 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6783 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6784 */
  sim_icache_fetch(5012 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6786 */
   __CMPGT(reg_b0_7, reg_r0_5, 0); /* line 6787 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6788 */
  sim_icache_fetch(5015 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6790 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6791 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6792 */
  sim_icache_fetch(5018 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6794 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6795 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6796 */
  sim_icache_fetch(5021 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6798 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6799 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6800 */
  sim_icache_fetch(5024 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6802 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 4); /* line 6803 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6804 */
  sim_icache_fetch(5027 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6806 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 5); /* line 6807 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6808 */
  sim_icache_fetch(5030 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6810 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 6811 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6812 */
  sim_icache_fetch(5033 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6814 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 6815 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6816 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6817 */
  sim_icache_fetch(5037 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6819 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 6820 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6821 */
  sim_icache_fetch(5040 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6823 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6824 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6825 */
  sim_icache_fetch(5043 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6827 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6828 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6829 */
  sim_icache_fetch(5046 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6831 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6832 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6833 */
  sim_icache_fetch(5049 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6835 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 12); /* line 6836 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6837 */
  sim_icache_fetch(5052 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6839 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 13); /* line 6840 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6841 */
  sim_icache_fetch(5055 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6843 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 6844 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6845 */
  sim_icache_fetch(5058 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6847 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 6848 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6849 */
  sim_icache_fetch(5061 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6851 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6852 */
  sim_icache_fetch(5063 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6854 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6855 */
  sim_icache_fetch(5065 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6857 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6858 */
  sim_icache_fetch(5067 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6860 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6861 */
  sim_icache_fetch(5069 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6863 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6864 */
  sim_icache_fetch(5071 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6866 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6867 */
  sim_icache_fetch(5073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6869 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L293X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6870 */
  sim_icache_fetch(5075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6872 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6873 */
l_L293X3: ;/* line 6876 */
__LABEL(l_L293X3);
  sim_icache_fetch(5077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6878 */
l_L289X3: ;/* line 6881 */
__LABEL(l_L289X3);
  sim_icache_fetch(5078 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6882 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6883 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6884 */
l_L288X3: ;/* line 6887 */
__LABEL(l_L288X3);
  sim_icache_fetch(5082 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6888 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6889 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6890 */
l_L287X3: ;/* line 6893 */
__LABEL(l_L287X3);
  sim_icache_fetch(5086 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6894 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6895 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6896 */
l_L286X3: ;/* line 6899 */
__LABEL(l_L286X3);
  sim_icache_fetch(5090 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6900 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6901 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6902 */
l_L285X3: ;/* line 6905 */
__LABEL(l_L285X3);
  sim_icache_fetch(5094 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6906 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6907 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6908 */
l_L284X3: ;/* line 6911 */
__LABEL(l_L284X3);
  sim_icache_fetch(5098 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6912 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6913 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6914 */
l_L283X3: ;/* line 6917 */
__LABEL(l_L283X3);
  sim_icache_fetch(5102 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6918 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6919 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6920 */
l_L282X3: ;/* line 6923 */
__LABEL(l_L282X3);
  sim_icache_fetch(5106 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6924 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6925 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6926 */
l_L281X3: ;/* line 6929 */
__LABEL(l_L281X3);
  sim_icache_fetch(5110 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6930 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6931 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6932 */
l_L280X3: ;/* line 6935 */
__LABEL(l_L280X3);
  sim_icache_fetch(5113 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6936 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6937 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6938 */
l_L279X3: ;/* line 6941 */
__LABEL(l_L279X3);
  sim_icache_fetch(5116 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6942 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6943 */
   __GOTO(l_L291X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L291X3;
} /* line 6944 */
l_L278X3: ;/* line 6947 */
__LABEL(l_L278X3);
  sim_icache_fetch(5119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6948 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6949 */
} /* line 6949 */
l_L291X3: ;/* line 6951 */
__LABEL(l_L291X3);
  sim_icache_fetch(5121 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6952 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6953 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6954 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 468: goto l_L277X3;
    case 469: goto l_L290X3;
    case 470: goto l_L292X3;
    case 471: goto l_L293X3;
    case 472: goto l_L289X3;
    case 473: goto l_L288X3;
    case 474: goto l_L287X3;
    case 475: goto l_L286X3;
    case 476: goto l_L285X3;
    case 477: goto l_L284X3;
    case 478: goto l_L283X3;
    case 479: goto l_L282X3;
    case 480: goto l_L281X3;
    case 481: goto l_L280X3;
    case 482: goto l_L279X3;
    case 483: goto l_L278X3;
    case 484: goto l_L291X3;
    case 485:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int prratio( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(prratio);  sim_gprof_enter(&sim_gprof_idx,"prratio");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (486 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5124 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6970 */
} /* line 6970 */
  sim_icache_fetch(5125 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6973 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 486:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int version(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(version);  sim_gprof_enter(&sim_gprof_idx,"version");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (487 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5126 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6989 */
} /* line 6989 */
  sim_icache_fetch(5127 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6992 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 487:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 5136, 0, 0, 0, 2};

