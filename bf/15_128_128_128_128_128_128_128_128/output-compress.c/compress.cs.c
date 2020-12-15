/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/15_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_14293Xoffset[1];
unsigned int compress_14293Xbuf[3];
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
unsigned int compress_14293XBuf[216]; 
unsigned int compress_14293Xrcs_ident[6]; 
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
	(150 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(164 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(156 << 5),
	(155 << 5),
	(154 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(153 << 5),
	(168 << 5),
	(168 << 5),
	(152 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(168 << 5),
	(151 << 5)
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

unsigned int compress_14293XBuf[216] = { 
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

unsigned int compress_14293Xrcs_ident[6] = { 
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
   __MOV(reg_r0_5, (unsigned int) compress_14293XBuf); /* line 35 */
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

  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (145 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 177 */
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 178 */
   __ADD(reg_r0_34, reg_r0_3, (unsigned int) 15); /* line 179 */
   __ADD(reg_r0_32, reg_r0_3, (unsigned int) 14); /* line 180 */
   __ADD(reg_r0_30, reg_r0_3, (unsigned int) 13); /* line 181 */
   __ADD(reg_r0_28, reg_r0_3, (unsigned int) 12); /* line 182 */
   __ADD(reg_r0_26, reg_r0_3, (unsigned int) 11); /* line 183 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 10); /* line 184 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 9); /* line 185 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 8); /* line 186 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 7); /* line 187 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 6); /* line 188 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 189 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 190 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 191 */
} /* line 191 */
  sim_icache_fetch(59 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SXTB(reg_r0_4, reg_r0_4); /* line 193 */
   __MOV(reg_r0_5, 0); /* line 194 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 195 */
   __STW(mem_trace_st(reg_r0_1,0,4), reg_r0_57); /* line 196 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 4),0,4), reg_r0_58); /* line 197 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 8),0,4), reg_r0_59); /* line 198 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 12),0,4), reg_r0_60); /* line 199 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_61); /* line 200 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_62); /* line 201 */
   __MOV(reg_r0_2, reg_r0_3); /* line 202 */
} /* line 202 */
l_L0X3: ;/* line 205 */
__LABEL(l_L0X3);
  sim_icache_fetch(69 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 206 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 207 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 208 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_10,0,1)); /* line 209 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_12,0,1)); /* line 210 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_14,0,1)); /* line 211 */
   __LDBs(reg_r0_17, mem_trace_ld(reg_r0_16,0,1)); /* line 212 */
   __LDBs(reg_r0_19, mem_trace_ld(reg_r0_18,0,1)); /* line 213 */
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_20,0,1)); /* line 214 */
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_22,0,1)); /* line 215 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_24,0,1)); /* line 216 */
   __LDBs(reg_r0_27, mem_trace_ld(reg_r0_26,0,1)); /* line 217 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_28,0,1)); /* line 218 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_30,0,1)); /* line 219 */
   __LDBs(reg_r0_33, mem_trace_ld(reg_r0_32,0,1)); /* line 220 */
} /* line 220 */
  sim_icache_fetch(84 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __LDBs(reg_r0_35, mem_trace_ld(reg_r0_34,0,1)); /* line 222 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) 16); /* line 223 */
   __ADD(reg_r0_37, reg_r0_32, (unsigned int) 16); /* line 224 */
   __ADD(reg_r0_38, reg_r0_30, (unsigned int) 16); /* line 225 */
   __ADD(reg_r0_39, reg_r0_28, (unsigned int) 16); /* line 226 */
   __ADD(reg_r0_40, reg_r0_26, (unsigned int) 16); /* line 227 */
   __ADD(reg_r0_41, reg_r0_24, (unsigned int) 16); /* line 228 */
   __ADD(reg_r0_42, reg_r0_22, (unsigned int) 16); /* line 229 */
   __ADD(reg_r0_43, reg_r0_20, (unsigned int) 16); /* line 230 */
   __ADD(reg_r0_44, reg_r0_18, (unsigned int) 16); /* line 231 */
   __ADD(reg_r0_45, reg_r0_16, (unsigned int) 16); /* line 232 */
   __ADD(reg_r0_46, reg_r0_14, (unsigned int) 16); /* line 233 */
   __ADD(reg_r0_47, reg_r0_12, (unsigned int) 16); /* line 234 */
   __ADD(reg_r0_48, reg_r0_10, (unsigned int) 16); /* line 235 */
   __ADD(reg_r0_49, reg_r0_8, (unsigned int) 16); /* line 236 */
} /* line 236 */
  sim_icache_fetch(99 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 238 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 239 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 240 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 241 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 242 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 243 */
   __CMPNE(reg_b0_6, reg_r0_11, 0); /* line 244 */
   __CMPEQ(reg_b0_7, reg_r0_11, reg_r0_4); /* line 245 */
   __ADD(reg_r0_3, reg_r0_34, (unsigned int) 16); /* line 246 */
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 16); /* line 247 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_36,0,1)); /* line 248 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_49,0,1)); /* line 249 */
   __LDBs(reg_r0_50, mem_trace_ld(reg_r0_48,0,1)); /* line 250 */
   __LDBs(reg_r0_51, mem_trace_ld(reg_r0_47,0,1)); /* line 251 */
   __LDBs(reg_r0_52, mem_trace_ld(reg_r0_46,0,1)); /* line 252 */
} /* line 252 */
  sim_icache_fetch(114 + t_thisfile.offset, 15);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __SLCT(reg_r0_2, reg_b0_1, reg_r0_2, reg_r0_5); /* line 254 */
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 255 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 256 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_7,0,1)); /* line 257 */
   __LDBs(reg_r0_53, mem_trace_ld(reg_r0_45,0,1)); /* line 258 */
   __LDBs(reg_r0_54, mem_trace_ld(reg_r0_44,0,1)); /* line 259 */
   __LDBs(reg_r0_55, mem_trace_ld(reg_r0_43,0,1)); /* line 260 */
   __LDBs(reg_r0_56, mem_trace_ld(reg_r0_42,0,1)); /* line 261 */
   __LDBs(reg_r0_57, mem_trace_ld(reg_r0_41,0,1)); /* line 262 */
   __LDBs(reg_r0_58, mem_trace_ld(reg_r0_40,0,1)); /* line 263 */
   __LDBs(reg_r0_59, mem_trace_ld(reg_r0_39,0,1)); /* line 264 */
   __LDBs(reg_r0_60, mem_trace_ld(reg_r0_38,0,1)); /* line 265 */
   __LDBs(reg_r0_61, mem_trace_ld(reg_r0_37,0,1)); /* line 266 */
   __LDBs(reg_r0_62, mem_trace_ld(reg_r0_3,0,1)); /* line 267 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 268 */
  sim_icache_fetch(129 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_6, reg_b0_3, reg_r0_6, reg_r0_2); /* line 270 */
   __CMPNE(reg_b0_2, reg_r0_15, 0); /* line 271 */
   __CMPEQ(reg_b0_3, reg_r0_15, reg_r0_4); /* line 272 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 273 */
  sim_icache_fetch(133 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_8, reg_b0_5, reg_r0_8, reg_r0_6); /* line 275 */
   __CMPNE(reg_b0_4, reg_r0_17, 0); /* line 276 */
   __CMPEQ(reg_b0_5, reg_r0_17, reg_r0_4); /* line 277 */
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) 16); /* line 278 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 279 */
  sim_icache_fetch(138 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_10, reg_b0_7, reg_r0_10, reg_r0_8); /* line 281 */
   __CMPNE(reg_b0_6, reg_r0_19, 0); /* line 282 */
   __CMPEQ(reg_b0_7, reg_r0_19, reg_r0_4); /* line 283 */
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) 16); /* line 284 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 285 */
  sim_icache_fetch(143 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, reg_r0_10); /* line 287 */
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 288 */
   __CMPEQ(reg_b0_1, reg_r0_21, reg_r0_4); /* line 289 */
   __ADD(reg_r0_8, reg_r0_49, (unsigned int) 16); /* line 290 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 291 */
  sim_icache_fetch(148 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_14, reg_b0_3, reg_r0_14, reg_r0_12); /* line 293 */
   __CMPNE(reg_b0_2, reg_r0_23, 0); /* line 294 */
   __CMPEQ(reg_b0_3, reg_r0_23, reg_r0_4); /* line 295 */
   __ADD(reg_r0_10, reg_r0_48, (unsigned int) 16); /* line 296 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 297 */
  sim_icache_fetch(153 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_16, reg_b0_5, reg_r0_16, reg_r0_14); /* line 299 */
   __CMPNE(reg_b0_4, reg_r0_25, 0); /* line 300 */
   __CMPEQ(reg_b0_5, reg_r0_25, reg_r0_4); /* line 301 */
   __ADD(reg_r0_12, reg_r0_47, (unsigned int) 16); /* line 302 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 303 */
  sim_icache_fetch(158 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_18, reg_b0_7, reg_r0_18, reg_r0_16); /* line 305 */
   __CMPNE(reg_b0_6, reg_r0_27, 0); /* line 306 */
   __CMPEQ(reg_b0_7, reg_r0_27, reg_r0_4); /* line 307 */
   __ADD(reg_r0_14, reg_r0_46, (unsigned int) 16); /* line 308 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 309 */
  sim_icache_fetch(163 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_20, reg_b0_1, reg_r0_20, reg_r0_18); /* line 311 */
   __CMPNE(reg_b0_0, reg_r0_29, 0); /* line 312 */
   __CMPEQ(reg_b0_1, reg_r0_29, reg_r0_4); /* line 313 */
   __ADD(reg_r0_16, reg_r0_45, (unsigned int) 16); /* line 314 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 315 */
  sim_icache_fetch(168 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_22, reg_b0_3, reg_r0_22, reg_r0_20); /* line 317 */
   __CMPNE(reg_b0_2, reg_r0_31, 0); /* line 318 */
   __CMPEQ(reg_b0_3, reg_r0_31, reg_r0_4); /* line 319 */
   __ADD(reg_r0_18, reg_r0_44, (unsigned int) 16); /* line 320 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 321 */
  sim_icache_fetch(173 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_24, reg_b0_5, reg_r0_24, reg_r0_22); /* line 323 */
   __CMPNE(reg_b0_4, reg_r0_33, 0); /* line 324 */
   __CMPEQ(reg_b0_5, reg_r0_33, reg_r0_4); /* line 325 */
   __ADD(reg_r0_20, reg_r0_43, (unsigned int) 16); /* line 326 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 327 */
  sim_icache_fetch(178 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_26, reg_b0_7, reg_r0_26, reg_r0_24); /* line 329 */
   __CMPNE(reg_b0_6, reg_r0_35, 0); /* line 330 */
   __CMPEQ(reg_b0_7, reg_r0_35, reg_r0_4); /* line 331 */
   __ADD(reg_r0_22, reg_r0_42, (unsigned int) 16); /* line 332 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 333 */
  sim_icache_fetch(183 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_28, reg_b0_1, reg_r0_28, reg_r0_26); /* line 335 */
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 336 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 337 */
   __ADD(reg_r0_24, reg_r0_41, (unsigned int) 16); /* line 338 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 339 */
  sim_icache_fetch(188 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_30, reg_b0_3, reg_r0_30, reg_r0_28); /* line 341 */
   __CMPNE(reg_b0_2, reg_r0_9, 0); /* line 342 */
   __CMPEQ(reg_b0_3, reg_r0_9, reg_r0_4); /* line 343 */
   __ADD(reg_r0_26, reg_r0_40, (unsigned int) 16); /* line 344 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 345 */
  sim_icache_fetch(193 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_32, reg_b0_5, reg_r0_32, reg_r0_30); /* line 347 */
   __CMPNE(reg_b0_4, reg_r0_11, 0); /* line 348 */
   __CMPEQ(reg_b0_5, reg_r0_11, reg_r0_4); /* line 349 */
   __ADD(reg_r0_28, reg_r0_39, (unsigned int) 16); /* line 350 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 351 */
  sim_icache_fetch(198 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_34, reg_r0_32); /* line 353 */
   __CMPNE(reg_b0_6, reg_r0_50, 0); /* line 354 */
   __CMPEQ(reg_b0_7, reg_r0_50, reg_r0_4); /* line 355 */
   __ADD(reg_r0_30, reg_r0_38, (unsigned int) 16); /* line 356 */
   __ADD(reg_r0_34, reg_r0_3, (unsigned int) 16); /* line 357 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 358 */
  sim_icache_fetch(204 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_7, reg_r0_5); /* line 360 */
   __CMPNE(reg_b0_0, reg_r0_51, 0); /* line 361 */
   __CMPEQ(reg_b0_1, reg_r0_51, reg_r0_4); /* line 362 */
   __ADD(reg_r0_32, reg_r0_37, (unsigned int) 16); /* line 363 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 364 */
  sim_icache_fetch(209 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_36, reg_b0_3, reg_r0_36, reg_r0_7); /* line 366 */
   __CMPNE(reg_b0_2, reg_r0_52, 0); /* line 367 */
   __CMPEQ(reg_b0_3, reg_r0_52, reg_r0_4); /* line 368 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 369 */
  sim_icache_fetch(213 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_49, reg_b0_5, reg_r0_49, reg_r0_36); /* line 371 */
   __CMPNE(reg_b0_4, reg_r0_53, 0); /* line 372 */
   __CMPEQ(reg_b0_5, reg_r0_53, reg_r0_4); /* line 373 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 374 */
  sim_icache_fetch(217 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_48, reg_b0_7, reg_r0_48, reg_r0_49); /* line 376 */
   __CMPNE(reg_b0_6, reg_r0_54, 0); /* line 377 */
   __CMPEQ(reg_b0_7, reg_r0_54, reg_r0_4); /* line 378 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 379 */
  sim_icache_fetch(221 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_47, reg_b0_1, reg_r0_47, reg_r0_48); /* line 381 */
   __CMPNE(reg_b0_0, reg_r0_55, 0); /* line 382 */
   __CMPEQ(reg_b0_1, reg_r0_55, reg_r0_4); /* line 383 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 384 */
  sim_icache_fetch(225 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_46, reg_b0_3, reg_r0_46, reg_r0_47); /* line 386 */
   __CMPNE(reg_b0_2, reg_r0_56, 0); /* line 387 */
   __CMPEQ(reg_b0_3, reg_r0_56, reg_r0_4); /* line 388 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 389 */
  sim_icache_fetch(229 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_45, reg_b0_5, reg_r0_45, reg_r0_46); /* line 391 */
   __CMPNE(reg_b0_4, reg_r0_57, 0); /* line 392 */
   __CMPEQ(reg_b0_5, reg_r0_57, reg_r0_4); /* line 393 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 394 */
  sim_icache_fetch(233 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_44, reg_b0_7, reg_r0_44, reg_r0_45); /* line 396 */
   __CMPNE(reg_b0_6, reg_r0_58, 0); /* line 397 */
   __CMPEQ(reg_b0_7, reg_r0_58, reg_r0_4); /* line 398 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 399 */
  sim_icache_fetch(237 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_43, reg_b0_1, reg_r0_43, reg_r0_44); /* line 401 */
   __CMPNE(reg_b0_0, reg_r0_59, 0); /* line 402 */
   __CMPEQ(reg_b0_1, reg_r0_59, reg_r0_4); /* line 403 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 404 */
  sim_icache_fetch(241 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_42, reg_b0_3, reg_r0_42, reg_r0_43); /* line 406 */
   __CMPNE(reg_b0_2, reg_r0_60, 0); /* line 407 */
   __CMPEQ(reg_b0_3, reg_r0_60, reg_r0_4); /* line 408 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 409 */
  sim_icache_fetch(245 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_41, reg_b0_5, reg_r0_41, reg_r0_42); /* line 411 */
   __CMPNE(reg_b0_4, reg_r0_61, 0); /* line 412 */
   __CMPEQ(reg_b0_5, reg_r0_61, reg_r0_4); /* line 413 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 414 */
  sim_icache_fetch(249 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_40, reg_b0_7, reg_r0_40, reg_r0_41); /* line 416 */
   __CMPNE(reg_b0_6, reg_r0_62, 0); /* line 417 */
   __CMPEQ(reg_b0_7, reg_r0_62, reg_r0_4); /* line 418 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 419 */
  sim_icache_fetch(253 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_39, reg_b0_1, reg_r0_39, reg_r0_40); /* line 421 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 422 */
  sim_icache_fetch(255 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_38, reg_b0_3, reg_r0_38, reg_r0_39); /* line 424 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 425 */
  sim_icache_fetch(257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_37, reg_b0_5, reg_r0_37, reg_r0_38); /* line 427 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 428 */
  sim_icache_fetch(259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_3, reg_r0_37); /* line 430 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 432 */
  sim_icache_fetch(261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 434 */
l_L32X3: ;/* line 437 */
__LABEL(l_L32X3);
  sim_icache_fetch(262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_32, reg_r0_37); /* line 438 */
} /* line 438 */
l_L16X3: ;/* line 441 */
__LABEL(l_L16X3);
  sim_icache_fetch(263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_32); /* line 442 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 443 */
l_L31X3: ;/* line 446 */
__LABEL(l_L31X3);
  sim_icache_fetch(265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_30, reg_r0_38); /* line 447 */
} /* line 447 */
l_L15X3: ;/* line 450 */
__LABEL(l_L15X3);
  sim_icache_fetch(266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_30); /* line 451 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 452 */
l_L30X3: ;/* line 455 */
__LABEL(l_L30X3);
  sim_icache_fetch(268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_28, reg_r0_39); /* line 456 */
} /* line 456 */
l_L14X3: ;/* line 459 */
__LABEL(l_L14X3);
  sim_icache_fetch(269 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_28); /* line 460 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 461 */
l_L29X3: ;/* line 464 */
__LABEL(l_L29X3);
  sim_icache_fetch(271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_26, reg_r0_40); /* line 465 */
} /* line 465 */
l_L13X3: ;/* line 468 */
__LABEL(l_L13X3);
  sim_icache_fetch(272 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_26); /* line 469 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 470 */
l_L28X3: ;/* line 473 */
__LABEL(l_L28X3);
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_24, reg_r0_41); /* line 474 */
} /* line 474 */
l_L12X3: ;/* line 477 */
__LABEL(l_L12X3);
  sim_icache_fetch(275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_24); /* line 478 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 479 */
l_L27X3: ;/* line 482 */
__LABEL(l_L27X3);
  sim_icache_fetch(277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_42); /* line 483 */
} /* line 483 */
l_L11X3: ;/* line 486 */
__LABEL(l_L11X3);
  sim_icache_fetch(278 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_22); /* line 487 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 488 */
l_L26X3: ;/* line 491 */
__LABEL(l_L26X3);
  sim_icache_fetch(280 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_20, reg_r0_43); /* line 492 */
} /* line 492 */
l_L10X3: ;/* line 495 */
__LABEL(l_L10X3);
  sim_icache_fetch(281 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_20); /* line 496 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 497 */
l_L25X3: ;/* line 500 */
__LABEL(l_L25X3);
  sim_icache_fetch(283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_44); /* line 501 */
} /* line 501 */
l_L9X3: ;/* line 504 */
__LABEL(l_L9X3);
  sim_icache_fetch(284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_18); /* line 505 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 506 */
l_L24X3: ;/* line 509 */
__LABEL(l_L24X3);
  sim_icache_fetch(286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, reg_r0_45); /* line 510 */
} /* line 510 */
l_L8X3: ;/* line 513 */
__LABEL(l_L8X3);
  sim_icache_fetch(287 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_16); /* line 514 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 515 */
l_L23X3: ;/* line 518 */
__LABEL(l_L23X3);
  sim_icache_fetch(289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_14, reg_r0_46); /* line 519 */
} /* line 519 */
l_L7X3: ;/* line 522 */
__LABEL(l_L7X3);
  sim_icache_fetch(290 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_14); /* line 523 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 524 */
l_L22X3: ;/* line 527 */
__LABEL(l_L22X3);
  sim_icache_fetch(292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, reg_r0_47); /* line 528 */
} /* line 528 */
l_L6X3: ;/* line 531 */
__LABEL(l_L6X3);
  sim_icache_fetch(293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_12); /* line 532 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 533 */
l_L21X3: ;/* line 536 */
__LABEL(l_L21X3);
  sim_icache_fetch(295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_10, reg_r0_48); /* line 537 */
} /* line 537 */
l_L5X3: ;/* line 540 */
__LABEL(l_L5X3);
  sim_icache_fetch(296 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 541 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 542 */
l_L20X3: ;/* line 545 */
__LABEL(l_L20X3);
  sim_icache_fetch(298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_49); /* line 546 */
} /* line 546 */
l_L4X3: ;/* line 549 */
__LABEL(l_L4X3);
  sim_icache_fetch(299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_8); /* line 550 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 551 */
l_L19X3: ;/* line 554 */
__LABEL(l_L19X3);
  sim_icache_fetch(301 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_36); /* line 555 */
} /* line 555 */
l_L3X3: ;/* line 558 */
__LABEL(l_L3X3);
  sim_icache_fetch(302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 559 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 560 */
l_L18X3: ;/* line 563 */
__LABEL(l_L18X3);
  sim_icache_fetch(304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 564 */
} /* line 564 */
l_L2X3: ;/* line 567 */
__LABEL(l_L2X3);
  sim_icache_fetch(305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 568 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 569 */
l_L17X3: ;/* line 572 */
__LABEL(l_L17X3);
  sim_icache_fetch(307 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 573 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 574 */
l_L1X3: ;/* line 577 */
__LABEL(l_L1X3);
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 578 */
} /* line 578 */
l_L33X3: ;/* line 580 */
__LABEL(l_L33X3);
  sim_icache_fetch(310 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 581 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 582 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 583 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 584 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 585 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 586 */
} /* line 586 */
  sim_icache_fetch(316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 589 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 111: goto l_L0X3;
    case 112: goto l_L32X3;
    case 113: goto l_L16X3;
    case 114: goto l_L31X3;
    case 115: goto l_L15X3;
    case 116: goto l_L30X3;
    case 117: goto l_L14X3;
    case 118: goto l_L29X3;
    case 119: goto l_L13X3;
    case 120: goto l_L28X3;
    case 121: goto l_L12X3;
    case 122: goto l_L27X3;
    case 123: goto l_L11X3;
    case 124: goto l_L26X3;
    case 125: goto l_L10X3;
    case 126: goto l_L25X3;
    case 127: goto l_L9X3;
    case 128: goto l_L24X3;
    case 129: goto l_L8X3;
    case 130: goto l_L23X3;
    case 131: goto l_L7X3;
    case 132: goto l_L22X3;
    case 133: goto l_L6X3;
    case 134: goto l_L21X3;
    case 135: goto l_L5X3;
    case 136: goto l_L20X3;
    case 137: goto l_L4X3;
    case 138: goto l_L19X3;
    case 139: goto l_L3X3;
    case 140: goto l_L18X3;
    case 141: goto l_L2X3;
    case 142: goto l_L17X3;
    case 143: goto l_L1X3;
    case 144: goto l_L33X3;
    case 145:
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
  reg_l0_0 = (212 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(317 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 606 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 607 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 608 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 609 */
} /* line 609 */
  sim_icache_fetch(324 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 611 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 612 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 613 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 614 */
} /* line 614 */
  sim_icache_fetch(329 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 616 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 617 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 618 */
} /* line 618 */
		 /* line 619 */
  sim_icache_fetch(332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 621 */
l_lr_46: ;/* line 621 */
__LABEL(l_lr_46);
  sim_icache_fetch(334 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 623 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 624 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 625 */
   __ADD_CYCLES(1);
} /* line 625 */
  sim_icache_fetch(337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 627 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 628 */
} /* line 628 */
l_L34X3: ;/* line 631 */
__LABEL(l_L34X3);
  sim_icache_fetch(339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 632 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 633 */
} /* line 633 */
  sim_icache_fetch(341 + t_thisfile.offset, 1);
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
} /* line 635 */
  sim_icache_fetch(342 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 637 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 638 */
   __ADD_CYCLES(1);
} /* line 638 */
  sim_icache_fetch(344 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 640 */
} /* line 640 */
  sim_icache_fetch(345 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 642 */
l_L37X3: ;/* line 645 */
__LABEL(l_L37X3);
  sim_icache_fetch(346 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 646 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 647 */
   __ADD_CYCLES(1);
} /* line 647 */
  sim_icache_fetch(348 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 649 */
} /* line 649 */
  sim_icache_fetch(349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 651 */
} /* line 651 */
  sim_icache_fetch(350 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 653 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 654 */
   __ADD_CYCLES(1);
} /* line 654 */
  sim_icache_fetch(352 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 656 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 657 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 658 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 659 */
} /* line 659 */
  sim_icache_fetch(357 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 661 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 662 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 663 */
  sim_icache_fetch(360 + t_thisfile.offset, 1);
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
} /* line 665 */
  sim_icache_fetch(361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 666 */
  sim_icache_fetch(362 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 668 */
l__X1XCompressXTAGX0X0: ;/* line 670 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(363 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 671 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 672 */
l__X1XCompressXTAGX0X7: ;/* line 675 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(366 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 676 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 677 */
l__X1XCompressXTAGX0X6: ;/* line 680 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 681 */
} /* line 681 */
  sim_icache_fetch(370 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 683 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 684 */
l__X1XCompressXTAGX0X5: ;/* line 687 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 688 */
} /* line 688 */
  sim_icache_fetch(374 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 690 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 691 */
l__X1XCompressXTAGX0X4: ;/* line 694 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 695 */
} /* line 695 */
  sim_icache_fetch(378 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 697 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 698 */
l__X1XCompressXTAGX0X3: ;/* line 701 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 702 */
} /* line 702 */
  sim_icache_fetch(382 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 704 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 705 */
l__X1XCompressXTAGX0X2: ;/* line 708 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 709 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 710 */
   __ADD_CYCLES(1);
} /* line 710 */
  sim_icache_fetch(387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 712 */
} /* line 712 */
  sim_icache_fetch(388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 714 */
} /* line 714 */
  sim_icache_fetch(389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 716 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 717 */
   __ADD_CYCLES(1);
} /* line 717 */
  sim_icache_fetch(391 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 719 */
} /* line 719 */
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
} /* line 721 */
l_L36X3: ;/* line 723 */
__LABEL(l_L36X3);
  sim_icache_fetch(393 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 724 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 725 */
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 726 */
l_L40X3: ;/* line 729 */
__LABEL(l_L40X3);
  sim_icache_fetch(396 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 730 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 731 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 732 */
} /* line 732 */
  sim_icache_fetch(399 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 734 */
} /* line 734 */
  sim_icache_fetch(400 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 736 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 737 */
  sim_icache_fetch(402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 740 */
  sim_icache_fetch(403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 742 */
l_L41X3: ;/* line 745 */
__LABEL(l_L41X3);
		 /* line 745 */
  sim_icache_fetch(404 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 748 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (212 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 748 */
l_lr_60: ;/* line 748 */
__LABEL(l_lr_60);
		 /* line 749 */
  sim_icache_fetch(408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (212 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 751 */
l_lr_62: ;/* line 751 */
__LABEL(l_lr_62);
  sim_icache_fetch(410 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 753 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 754 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 755 */
   __ADD_CYCLES(1);
} /* line 755 */
  sim_icache_fetch(413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 758 */
l__X1XCompressXTAGX0X1: ;/* line 761 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 761 */
  sim_icache_fetch(414 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 764 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 765 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 765 */
l_lr_65: ;/* line 765 */
__LABEL(l_lr_65);
  sim_icache_fetch(418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 767 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 768 */
} /* line 768 */
  sim_icache_fetch(420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 770 */
l_L39X3: ;/* line 773 */
__LABEL(l_L39X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 774 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 774 */
  sim_icache_fetch(421 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 777 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (212 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 777 */
l_lr_69: ;/* line 777 */
__LABEL(l_lr_69);
		 /* line 778 */
  sim_icache_fetch(425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (212 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 780 */
l_lr_71: ;/* line 780 */
__LABEL(l_lr_71);
  sim_icache_fetch(427 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 782 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 783 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 784 */
   __ADD_CYCLES(1);
} /* line 784 */
  sim_icache_fetch(430 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 787 */
l_L38X3: ;/* line 790 */
__LABEL(l_L38X3);
  sim_icache_fetch(431 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 791 */
l_L35X3: ;/* line 794 */
__LABEL(l_L35X3);
  sim_icache_fetch(432 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 795 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 796 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 797 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 798 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 799 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 800 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 801 */
   __ADD_CYCLES(1);
} /* line 801 */
  sim_icache_fetch(442 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 803 */
   __CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 4096); /* line 804 */
} /* line 804 */
  sim_icache_fetch(445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 806 */
  sim_icache_fetch(446 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 808 */
} /* line 808 */
l_L43X3: ;/* line 810 */
__LABEL(l_L43X3);
  sim_icache_fetch(448 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 811 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 812 */
   __ADD_CYCLES(1);
} /* line 812 */
  sim_icache_fetch(451 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 814 */
} /* line 814 */
  sim_icache_fetch(452 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 816 */
  sim_icache_fetch(453 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 818 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 819 */
} /* line 819 */
l_L45X3: ;/* line 821 */
__LABEL(l_L45X3);
  sim_icache_fetch(457 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 822 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 823 */
   __ADD_CYCLES(1);
} /* line 823 */
  sim_icache_fetch(460 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 825 */
} /* line 825 */
  sim_icache_fetch(461 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 827 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L46X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 828 */
		 /* line 829 */
  sim_icache_fetch(464 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 831 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 832 */
l_lr_77: ;/* line 832 */
__LABEL(l_lr_77);
l_L47X3: ;/* line 834 */
__LABEL(l_L47X3);
  sim_icache_fetch(468 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 835 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 836 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 837 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 838 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 839 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 840 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 841 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 842 */
} /* line 842 */
  sim_icache_fetch(484 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 844 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 845 */
} /* line 845 */
  sim_icache_fetch(488 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 847 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 848 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 849 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 850 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 851 */
} /* line 851 */
  sim_icache_fetch(494 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 853 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 854 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 855 */
  sim_icache_fetch(497 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 857 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 858 */
  sim_icache_fetch(500 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 860 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 861 */
l_L51X3: ;/* line 863 */
__LABEL(l_L51X3);
		 /* line 863 */
  sim_icache_fetch(503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (212 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 865 */
l_lr_81: ;/* line 865 */
__LABEL(l_lr_81);
  sim_icache_fetch(505 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 867 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 868 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 869 */
   __ADD_CYCLES(1);
} /* line 869 */
  sim_icache_fetch(508 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 872 */
l_L50X3: ;/* line 875 */
__LABEL(l_L50X3);
  sim_icache_fetch(509 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 876 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 877 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 878 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 879 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 880 */
   __ADD_CYCLES(1);
} /* line 880 */
  sim_icache_fetch(518 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 882 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 883 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 884 */
} /* line 884 */
  sim_icache_fetch(521 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 886 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 887 */
} /* line 887 */
  sim_icache_fetch(524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 889 */
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 891 */
} /* line 891 */
  sim_icache_fetch(527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 893 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 894 */
   __ADD_CYCLES(1);
} /* line 894 */
  sim_icache_fetch(529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 896 */
} /* line 896 */
l_L53X3: ;/* line 898 */
__LABEL(l_L53X3);
  sim_icache_fetch(530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 899 */
} /* line 899 */
  sim_icache_fetch(531 + t_thisfile.offset, 1);
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
} /* line 902 */
  sim_icache_fetch(532 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 904 */
l_L54X3: ;/* line 907 */
__LABEL(l_L54X3);
  sim_icache_fetch(533 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 908 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 909 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 910 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 911 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 912 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 913 */
   __ADD_CYCLES(1);
} /* line 913 */
  sim_icache_fetch(543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 915 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 916 */
} /* line 916 */
  sim_icache_fetch(545 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 918 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 919 */
} /* line 919 */
  sim_icache_fetch(548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L55X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 921 */
  sim_icache_fetch(549 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 923 */
} /* line 923 */
  sim_icache_fetch(551 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 925 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 926 */
   __ADD_CYCLES(1);
} /* line 926 */
  sim_icache_fetch(553 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 928 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 929 */
} /* line 929 */
l_L56X3: ;/* line 931 */
__LABEL(l_L56X3);
  sim_icache_fetch(556 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 932 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 933 */
} /* line 933 */
  sim_icache_fetch(558 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 935 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 936 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 937 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 938 */
} /* line 938 */
  sim_icache_fetch(564 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 940 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 941 */
		 /* line 942 */
  sim_icache_fetch(567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (212 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 944 */
l_lr_87: ;/* line 944 */
__LABEL(l_lr_87);
  sim_icache_fetch(569 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 946 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 947 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 948 */
   __ADD_CYCLES(1);
} /* line 948 */
  sim_icache_fetch(572 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 951 */
l_L48X3: ;/* line 954 */
__LABEL(l_L48X3);
		 /* line 954 */
  sim_icache_fetch(573 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 956 */
l_lr_90: ;/* line 956 */
__LABEL(l_lr_90);
  sim_icache_fetch(575 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 958 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 959 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 960 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 961 */
   __ADD_CYCLES(1);
} /* line 961 */
  sim_icache_fetch(579 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 964 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 965 */
l_L55X3: ;/* line 968 */
__LABEL(l_L55X3);
  sim_icache_fetch(582 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 969 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 970 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 971 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 972 */
} /* line 972 */
  sim_icache_fetch(588 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 974 */
   __GOTO(l_L56X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L56X3;
} /* line 975 */
l_L52X3: ;/* line 978 */
__LABEL(l_L52X3);
  sim_icache_fetch(591 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 979 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 980 */
   __GOTO(l_L53X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L53X3;
} /* line 981 */
l_L49X3: ;/* line 984 */
__LABEL(l_L49X3);
  sim_icache_fetch(595 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 985 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 986 */
} /* line 986 */
  sim_icache_fetch(598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 988 */
} /* line 988 */
  sim_icache_fetch(599 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 991 */
  sim_icache_fetch(600 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 993 */
l_L46X3: ;/* line 996 */
__LABEL(l_L46X3);
  sim_icache_fetch(601 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 997 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 998 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 999 */
   __ADD_CYCLES(1);
} /* line 999 */
  sim_icache_fetch(606 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1001 */
} /* line 1001 */
  sim_icache_fetch(608 + t_thisfile.offset, 1);
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
} /* line 1003 */
		 /* line 1004 */
  sim_icache_fetch(609 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1006 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1007 */
l_lr_96: ;/* line 1007 */
__LABEL(l_lr_96);
  sim_icache_fetch(613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1009 */
l_L57X3: ;/* line 1012 */
__LABEL(l_L57X3);
  sim_icache_fetch(614 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1013 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1014 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1015 */
   __ADD_CYCLES(1);
} /* line 1015 */
  sim_icache_fetch(619 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1017 */
} /* line 1017 */
  sim_icache_fetch(621 + t_thisfile.offset, 1);
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
} /* line 1019 */
		 /* line 1020 */
  sim_icache_fetch(622 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1022 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1023 */
l_lr_99: ;/* line 1023 */
__LABEL(l_lr_99);
  sim_icache_fetch(626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1025 */
l_L58X3: ;/* line 1028 */
__LABEL(l_L58X3);
  sim_icache_fetch(627 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1029 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1030 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1031 */
   __ADD_CYCLES(1);
} /* line 1031 */
  sim_icache_fetch(632 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1033 */
} /* line 1033 */
  sim_icache_fetch(634 + t_thisfile.offset, 1);
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
} /* line 1035 */
		 /* line 1036 */
  sim_icache_fetch(635 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1038 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1039 */
l_lr_102: ;/* line 1039 */
__LABEL(l_lr_102);
  sim_icache_fetch(639 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1041 */
l_L59X3: ;/* line 1044 */
__LABEL(l_L59X3);
  sim_icache_fetch(640 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1045 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1046 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1047 */
   __ADD_CYCLES(1);
} /* line 1047 */
  sim_icache_fetch(645 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1049 */
} /* line 1049 */
  sim_icache_fetch(647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1051 */
		 /* line 1052 */
  sim_icache_fetch(648 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1054 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1055 */
l_lr_105: ;/* line 1055 */
__LABEL(l_lr_105);
  sim_icache_fetch(652 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1057 */
l_L60X3: ;/* line 1060 */
__LABEL(l_L60X3);
		 /* line 1060 */
  sim_icache_fetch(653 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (212 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1062 */
l_lr_108: ;/* line 1062 */
__LABEL(l_lr_108);
  sim_icache_fetch(655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1064 */
l_L44X3: ;/* line 1067 */
__LABEL(l_L44X3);
  sim_icache_fetch(656 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1068 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1069 */
} /* line 1069 */
  sim_icache_fetch(659 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1071 */
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 1072 */
l_L42X3: ;/* line 1075 */
__LABEL(l_L42X3);
  sim_icache_fetch(662 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1076 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1077 */
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1078 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 147: goto l_lr_46;
    case 148: goto l_L34X3;
    case 149: goto l_L37X3;
    case 150: goto l__X1XCompressXTAGX0X0;
    case 151: goto l__X1XCompressXTAGX0X7;
    case 152: goto l__X1XCompressXTAGX0X6;
    case 153: goto l__X1XCompressXTAGX0X5;
    case 154: goto l__X1XCompressXTAGX0X4;
    case 155: goto l__X1XCompressXTAGX0X3;
    case 156: goto l__X1XCompressXTAGX0X2;
    case 157: goto l_L36X3;
    case 158: goto l_L40X3;
    case 159: goto l_L41X3;
    case 161: goto l_lr_60;
    case 163: goto l_lr_62;
    case 164: goto l__X1XCompressXTAGX0X1;
    case 166: goto l_lr_65;
    case 167: goto l_L39X3;
    case 168: goto l__X1XCompressXTAGX0XDEFAULT;
    case 170: goto l_lr_69;
    case 172: goto l_lr_71;
    case 173: goto l_L38X3;
    case 174: goto l_L35X3;
    case 175: goto l_L43X3;
    case 176: goto l_L45X3;
    case 178: goto l_lr_77;
    case 179: goto l_L47X3;
    case 180: goto l_L51X3;
    case 182: goto l_lr_81;
    case 183: goto l_L50X3;
    case 184: goto l_L53X3;
    case 185: goto l_L54X3;
    case 186: goto l_L56X3;
    case 188: goto l_lr_87;
    case 189: goto l_L48X3;
    case 191: goto l_lr_90;
    case 192: goto l_L55X3;
    case 193: goto l_L52X3;
    case 194: goto l_L49X3;
    case 195: goto l_L46X3;
    case 197: goto l_lr_96;
    case 198: goto l_L57X3;
    case 200: goto l_lr_99;
    case 201: goto l_L58X3;
    case 203: goto l_lr_102;
    case 204: goto l_L59X3;
    case 206: goto l_lr_105;
    case 207: goto l_L60X3;
    case 209: goto l_lr_108;
    case 210: goto l_L44X3;
    case 211: goto l_L42X3;
    case 212:
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
  reg_l0_0 = (331 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(665 + t_thisfile.offset, 23);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1216 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1217 */
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1218 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1219 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1220 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1221 */
   __MOV(reg_r0_4, 0); /* line 1222 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1223 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1224 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1225 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1226 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1227 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1228 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1229 */
} /* line 1229 */
  sim_icache_fetch(688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1231 */
} /* line 1231 */
  sim_icache_fetch(689 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1233 */
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 1234 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1235 */
   __ADD(reg_r0_15, reg_r0_14, (unsigned int) 1); /* line 1236 */
} /* line 1236 */
  sim_icache_fetch(693 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, (unsigned int) 256); /* line 1238 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 1239 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1240 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1241 */
l_L62X3: ;/* line 1243 */
__LABEL(l_L62X3);
  sim_icache_fetch(698 + t_thisfile.offset, 23);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __STW(mem_trace_st((unsigned int) compress_14293Xoffset,0,4), 0); /* line 1244 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1245 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1246 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1247 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1248 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1249 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1250 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1251 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1252 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1253 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1254 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1255 */
  sim_icache_fetch(721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 1257 */
} /* line 1257 */
  sim_icache_fetch(723 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1259 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1260 */
   __ADD_CYCLES(1);
} /* line 1260 */
  sim_icache_fetch(725 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1262 */
} /* line 1262 */
l_L64X3: ;/* line 1264 */
__LABEL(l_L64X3);
  sim_icache_fetch(726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1265 */
} /* line 1265 */
l_L65X3: ;/* line 1268 */
__LABEL(l_L65X3);
  sim_icache_fetch(727 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1269 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1270 */
} /* line 1270 */
  sim_icache_fetch(729 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1272 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1273 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1274 */
  sim_icache_fetch(732 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1276 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1277 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1278 */
  sim_icache_fetch(735 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1280 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1281 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1282 */
  sim_icache_fetch(738 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1284 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1285 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1286 */
  sim_icache_fetch(741 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1288 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1289 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1290 */
  sim_icache_fetch(744 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1292 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1293 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1294 */
  sim_icache_fetch(747 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1296 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1297 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1298 */
  sim_icache_fetch(750 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1300 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1301 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1302 */
  sim_icache_fetch(753 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1304 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1305 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1306 */
  sim_icache_fetch(756 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1308 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1309 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1310 */
  sim_icache_fetch(759 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1312 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1313 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1314 */
  sim_icache_fetch(762 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1316 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1317 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1318 */
  sim_icache_fetch(765 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1320 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1321 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1322 */
  sim_icache_fetch(768 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1324 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1325 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1326 */
  sim_icache_fetch(771 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1328 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1329 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1330 */
  sim_icache_fetch(774 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1332 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1333 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1334 */
  sim_icache_fetch(777 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1336 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1337 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1338 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1339 */
  sim_icache_fetch(781 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1341 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1342 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1343 */
  sim_icache_fetch(784 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1345 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1346 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1347 */
  sim_icache_fetch(787 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1349 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1350 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1351 */
  sim_icache_fetch(790 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1353 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1354 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1355 */
  sim_icache_fetch(793 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1357 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1358 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1359 */
  sim_icache_fetch(796 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1361 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1362 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1363 */
  sim_icache_fetch(799 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1365 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1366 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1367 */
  sim_icache_fetch(802 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1369 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1370 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1371 */
  sim_icache_fetch(805 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1373 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1374 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1375 */
  sim_icache_fetch(808 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1377 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1378 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1379 */
  sim_icache_fetch(811 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1381 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1382 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1383 */
  sim_icache_fetch(814 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1385 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1386 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1387 */
  sim_icache_fetch(817 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1389 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1390 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1391 */
  sim_icache_fetch(820 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1393 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1394 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1395 */
  sim_icache_fetch(823 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1397 */
  sim_icache_fetch(824 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1399 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 1400 */
l_L81X3: ;/* line 1403 */
__LABEL(l_L81X3);
  sim_icache_fetch(826 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1404 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1405 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1406 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1407 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1408 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1409 */
l_L83X3: ;/* line 1412 */
__LABEL(l_L83X3);
  sim_icache_fetch(833 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1413 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1414 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1415 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1416 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1417 */
   __ADD_CYCLES(1);
} /* line 1417 */
  sim_icache_fetch(842 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1419 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1420 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1421 */
} /* line 1421 */
  sim_icache_fetch(845 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1423 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1424 */
} /* line 1424 */
  sim_icache_fetch(848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1426 */
  sim_icache_fetch(849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1428 */
} /* line 1428 */
  sim_icache_fetch(851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1430 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1431 */
   __ADD_CYCLES(1);
} /* line 1431 */
  sim_icache_fetch(853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1433 */
} /* line 1433 */
l_L85X3: ;/* line 1435 */
__LABEL(l_L85X3);
  sim_icache_fetch(854 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1436 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1437 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1438 */
} /* line 1438 */
  sim_icache_fetch(857 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1440 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1441 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1442 */
  sim_icache_fetch(860 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1444 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1445 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1446 */
} /* line 1446 */
  sim_icache_fetch(866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1448 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1449 */
   __ADD_CYCLES(1);
} /* line 1449 */
  sim_icache_fetch(868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1451 */
} /* line 1451 */
  sim_icache_fetch(869 + t_thisfile.offset, 1);
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
} /* line 1453 */
  sim_icache_fetch(870 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1455 */
} /* line 1455 */
  sim_icache_fetch(871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1457 */
l_L87X3: ;/* line 1460 */
__LABEL(l_L87X3);
  sim_icache_fetch(872 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1461 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1462 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1463 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1464 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1465 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1468 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1469 */
   __ADD_CYCLES(1);
} /* line 1469 */
  sim_icache_fetch(881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1471 */
} /* line 1471 */
  sim_icache_fetch(882 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1473 */
l_L89X3: ;/* line 1475 */
__LABEL(l_L89X3);
		 /* line 1475 */
  sim_icache_fetch(883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (331 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1477 */
l_lr_121: ;/* line 1477 */
__LABEL(l_lr_121);
  sim_icache_fetch(885 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1479 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1480 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1481 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1482 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1483 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1484 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1485 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1486 */
   __ADD_CYCLES(1);
} /* line 1486 */
  sim_icache_fetch(896 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1488 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1489 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1490 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1491 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1492 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1493 */
} /* line 1493 */
  sim_icache_fetch(904 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1495 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1496 */
  sim_icache_fetch(907 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1498 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1499 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1500 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1501 */
l_L90X3: ;/* line 1504 */
__LABEL(l_L90X3);
  sim_icache_fetch(912 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1505 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1506 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1507 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1508 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1509 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1510 */
   __ADD_CYCLES(1);
} /* line 1510 */
  sim_icache_fetch(921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1512 */
} /* line 1512 */
  sim_icache_fetch(922 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1514 */
} /* line 1514 */
  sim_icache_fetch(923 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1516 */
		 /* line 1517 */
  sim_icache_fetch(924 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (331 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1519 */
l_lr_124: ;/* line 1519 */
__LABEL(l_lr_124);
  sim_icache_fetch(926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1521 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1522 */
} /* line 1522 */
  sim_icache_fetch(928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1524 */
l_L91X3: ;/* line 1527 */
__LABEL(l_L91X3);
  sim_icache_fetch(929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1528 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1529 */
} /* line 1529 */
  sim_icache_fetch(931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1531 */
l_L88X3: ;/* line 1534 */
__LABEL(l_L88X3);
  sim_icache_fetch(932 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1535 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1536 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1537 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1538 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1539 */
   __ADD_CYCLES(1);
} /* line 1539 */
  sim_icache_fetch(937 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1541 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1542 */
} /* line 1542 */
  sim_icache_fetch(939 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1544 */
} /* line 1544 */
l_L92X3: ;/* line 1547 */
__LABEL(l_L92X3);
  sim_icache_fetch(940 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1548 */
} /* line 1548 */
  sim_icache_fetch(941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1550 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1551 */
} /* line 1551 */
  sim_icache_fetch(943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1553 */
} /* line 1553 */
  sim_icache_fetch(944 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1555 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1556 */
} /* line 1556 */
  sim_icache_fetch(947 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1558 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1559 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1560 */
} /* line 1560 */
  sim_icache_fetch(950 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1562 */
} /* line 1562 */
  sim_icache_fetch(951 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1564 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1565 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1566 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1567 */
} /* line 1567 */
  sim_icache_fetch(956 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1569 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1570 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1571 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1572 */
  sim_icache_fetch(960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1574 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1575 */
  sim_icache_fetch(962 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1577 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1578 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1579 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1580 */
} /* line 1580 */
  sim_icache_fetch(967 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1582 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1583 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1584 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1585 */
  sim_icache_fetch(971 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1587 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1588 */
  sim_icache_fetch(973 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1590 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1591 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1592 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(978 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1595 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1596 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1597 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1598 */
  sim_icache_fetch(982 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1600 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1601 */
  sim_icache_fetch(984 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1603 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1604 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1605 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1606 */
} /* line 1606 */
  sim_icache_fetch(989 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1608 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1609 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1610 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1611 */
  sim_icache_fetch(993 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1613 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1614 */
  sim_icache_fetch(995 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1616 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1617 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1618 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1619 */
} /* line 1619 */
  sim_icache_fetch(1000 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1621 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1622 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1623 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1624 */
  sim_icache_fetch(1004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1626 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1627 */
  sim_icache_fetch(1006 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1629 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1630 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1631 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1632 */
} /* line 1632 */
  sim_icache_fetch(1011 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1634 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1635 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1636 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1637 */
  sim_icache_fetch(1015 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1639 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1640 */
  sim_icache_fetch(1017 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1642 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1643 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1644 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1645 */
} /* line 1645 */
  sim_icache_fetch(1022 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1647 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1648 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1649 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1650 */
  sim_icache_fetch(1026 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1652 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1653 */
  sim_icache_fetch(1028 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1655 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1656 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1657 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1658 */
} /* line 1658 */
  sim_icache_fetch(1033 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1660 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1661 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1662 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1663 */
  sim_icache_fetch(1037 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1665 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1666 */
  sim_icache_fetch(1039 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1668 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1669 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1670 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1671 */
} /* line 1671 */
  sim_icache_fetch(1044 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1673 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1674 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1675 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1676 */
  sim_icache_fetch(1048 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1678 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1679 */
  sim_icache_fetch(1050 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1681 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1682 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1683 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1684 */
} /* line 1684 */
  sim_icache_fetch(1055 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1686 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1687 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1688 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1689 */
  sim_icache_fetch(1059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1691 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1692 */
  sim_icache_fetch(1061 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1694 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1695 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1696 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1697 */
} /* line 1697 */
  sim_icache_fetch(1066 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1699 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1700 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1701 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1702 */
  sim_icache_fetch(1070 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1704 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1705 */
  sim_icache_fetch(1072 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1707 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1708 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1709 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1710 */
} /* line 1710 */
  sim_icache_fetch(1077 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1712 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1713 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1714 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1715 */
  sim_icache_fetch(1081 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1717 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1718 */
  sim_icache_fetch(1083 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1720 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1721 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1722 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1723 */
} /* line 1723 */
  sim_icache_fetch(1088 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1725 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1726 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1727 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1728 */
  sim_icache_fetch(1092 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1730 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1731 */
  sim_icache_fetch(1094 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1733 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1734 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1735 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1736 */
} /* line 1736 */
  sim_icache_fetch(1099 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1738 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1739 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1740 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1741 */
  sim_icache_fetch(1103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1743 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1744 */
  sim_icache_fetch(1105 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1746 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1747 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1748 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1749 */
} /* line 1749 */
  sim_icache_fetch(1110 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1751 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1752 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1753 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1754 */
  sim_icache_fetch(1114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1756 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1757 */
  sim_icache_fetch(1116 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1759 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1760 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1761 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1762 */
} /* line 1762 */
  sim_icache_fetch(1121 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1764 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1765 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1766 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1767 */
  sim_icache_fetch(1125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1769 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1770 */
  sim_icache_fetch(1127 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1772 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1773 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1774 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1775 */
} /* line 1775 */
  sim_icache_fetch(1132 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1777 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1778 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1779 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1780 */
  sim_icache_fetch(1136 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1782 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1783 */
  sim_icache_fetch(1138 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1785 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1786 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1787 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1788 */
} /* line 1788 */
  sim_icache_fetch(1143 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1790 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1791 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1792 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1793 */
  sim_icache_fetch(1147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1795 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1796 */
  sim_icache_fetch(1149 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1798 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1799 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1800 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1801 */
} /* line 1801 */
  sim_icache_fetch(1154 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1803 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1804 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1805 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1806 */
  sim_icache_fetch(1158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1808 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1809 */
  sim_icache_fetch(1160 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1811 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1812 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1813 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1814 */
} /* line 1814 */
  sim_icache_fetch(1165 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1816 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1817 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1818 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1819 */
  sim_icache_fetch(1169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1821 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1822 */
  sim_icache_fetch(1171 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1824 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1825 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1826 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1827 */
} /* line 1827 */
  sim_icache_fetch(1176 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1829 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1830 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1831 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1832 */
  sim_icache_fetch(1180 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1834 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1835 */
  sim_icache_fetch(1182 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1837 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1838 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1839 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1840 */
} /* line 1840 */
  sim_icache_fetch(1187 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1842 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1843 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1844 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1845 */
  sim_icache_fetch(1191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1847 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1848 */
  sim_icache_fetch(1193 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1850 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1851 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1852 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1853 */
} /* line 1853 */
  sim_icache_fetch(1198 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1855 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1856 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1857 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1858 */
  sim_icache_fetch(1202 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1860 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1861 */
  sim_icache_fetch(1204 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1863 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1864 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1865 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1866 */
} /* line 1866 */
  sim_icache_fetch(1209 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1868 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1869 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1870 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1871 */
  sim_icache_fetch(1213 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1873 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1874 */
  sim_icache_fetch(1215 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1876 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1877 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1878 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1879 */
} /* line 1879 */
  sim_icache_fetch(1220 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1881 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1882 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1883 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1884 */
  sim_icache_fetch(1224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1886 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1887 */
  sim_icache_fetch(1226 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1889 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1890 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1891 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1892 */
} /* line 1892 */
  sim_icache_fetch(1231 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1894 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1895 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1896 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1897 */
  sim_icache_fetch(1235 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1899 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1900 */
  sim_icache_fetch(1237 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1902 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1903 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1904 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1905 */
} /* line 1905 */
  sim_icache_fetch(1242 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1907 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1908 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1909 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1910 */
  sim_icache_fetch(1246 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1912 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1913 */
  sim_icache_fetch(1248 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1915 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1916 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1917 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1918 */
} /* line 1918 */
  sim_icache_fetch(1253 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1920 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1921 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1922 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1923 */
  sim_icache_fetch(1257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1925 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1926 */
  sim_icache_fetch(1259 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1928 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1929 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1930 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1931 */
} /* line 1931 */
  sim_icache_fetch(1264 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1933 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1934 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1935 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1936 */
  sim_icache_fetch(1268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1938 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1939 */
  sim_icache_fetch(1270 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1941 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1942 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1943 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1944 */
} /* line 1944 */
  sim_icache_fetch(1275 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1946 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1947 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1948 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1949 */
  sim_icache_fetch(1279 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1951 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1952 */
  sim_icache_fetch(1281 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1954 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1955 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1956 */
} /* line 1956 */
  sim_icache_fetch(1285 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1958 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1959 */
  sim_icache_fetch(1287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L154X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1961 */
  sim_icache_fetch(1288 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1963 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1964 */
} /* line 1964 */
  sim_icache_fetch(1290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L155X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1966 */
  sim_icache_fetch(1291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L156X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1969 */
  sim_icache_fetch(1292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L92X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L92X3;
} /* line 1971 */
l_L156X3: ;/* line 1974 */
__LABEL(l_L156X3);
  sim_icache_fetch(1293 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1975 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1976 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1977 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1978 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 1979 */
l_L155X3: ;/* line 1983 */
__LABEL(l_L155X3);
  sim_icache_fetch(1298 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 1984 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1985 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 1986 */
l_L154X3: ;/* line 1989 */
__LABEL(l_L154X3);
  sim_icache_fetch(1301 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 1990 */
} /* line 1990 */
l_L122X3: ;/* line 1993 */
__LABEL(l_L122X3);
  sim_icache_fetch(1302 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 1994 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1995 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1996 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1997 */
} /* line 1997 */
  sim_icache_fetch(1306 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1999 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2000 */
l_L153X3: ;/* line 2003 */
__LABEL(l_L153X3);
  sim_icache_fetch(1308 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2004 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2005 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2006 */
l_L152X3: ;/* line 2009 */
__LABEL(l_L152X3);
  sim_icache_fetch(1311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2010 */
} /* line 2010 */
l_L120X3: ;/* line 2013 */
__LABEL(l_L120X3);
  sim_icache_fetch(1312 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2014 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2015 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2016 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2017 */
} /* line 2017 */
  sim_icache_fetch(1316 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2019 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2020 */
l_L151X3: ;/* line 2023 */
__LABEL(l_L151X3);
  sim_icache_fetch(1318 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2024 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2025 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2026 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2027 */
l_L150X3: ;/* line 2030 */
__LABEL(l_L150X3);
  sim_icache_fetch(1322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2031 */
} /* line 2031 */
l_L118X3: ;/* line 2034 */
__LABEL(l_L118X3);
  sim_icache_fetch(1323 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2035 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2036 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2037 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2038 */
} /* line 2038 */
  sim_icache_fetch(1327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2040 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2041 */
l_L149X3: ;/* line 2044 */
__LABEL(l_L149X3);
  sim_icache_fetch(1329 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2045 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2046 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2047 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2048 */
l_L148X3: ;/* line 2051 */
__LABEL(l_L148X3);
  sim_icache_fetch(1333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2052 */
} /* line 2052 */
l_L116X3: ;/* line 2055 */
__LABEL(l_L116X3);
  sim_icache_fetch(1334 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2056 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2057 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2058 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2059 */
} /* line 2059 */
  sim_icache_fetch(1338 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2061 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2062 */
l_L147X3: ;/* line 2065 */
__LABEL(l_L147X3);
  sim_icache_fetch(1340 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2066 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2067 */
   __GOTO(l_L159X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L159X3;
} /* line 2068 */
l_L146X3: ;/* line 2071 */
__LABEL(l_L146X3);
  sim_icache_fetch(1343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2072 */
} /* line 2072 */
l_L114X3: ;/* line 2075 */
__LABEL(l_L114X3);
  sim_icache_fetch(1344 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2076 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2077 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2078 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2079 */
} /* line 2079 */
  sim_icache_fetch(1348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2081 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2082 */
l_L145X3: ;/* line 2085 */
__LABEL(l_L145X3);
  sim_icache_fetch(1350 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2086 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2087 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2088 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2089 */
l_L144X3: ;/* line 2092 */
__LABEL(l_L144X3);
  sim_icache_fetch(1354 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2093 */
} /* line 2093 */
l_L112X3: ;/* line 2096 */
__LABEL(l_L112X3);
  sim_icache_fetch(1355 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2097 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2098 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2099 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2100 */
} /* line 2100 */
  sim_icache_fetch(1359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2102 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2103 */
l_L143X3: ;/* line 2106 */
__LABEL(l_L143X3);
  sim_icache_fetch(1361 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2107 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2108 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2109 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2110 */
l_L142X3: ;/* line 2113 */
__LABEL(l_L142X3);
  sim_icache_fetch(1365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2114 */
} /* line 2114 */
l_L110X3: ;/* line 2117 */
__LABEL(l_L110X3);
  sim_icache_fetch(1366 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2118 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2119 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2120 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2121 */
} /* line 2121 */
  sim_icache_fetch(1370 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2123 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2124 */
l_L141X3: ;/* line 2127 */
__LABEL(l_L141X3);
  sim_icache_fetch(1372 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2128 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2129 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2130 */
l_L140X3: ;/* line 2133 */
__LABEL(l_L140X3);
  sim_icache_fetch(1375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2134 */
} /* line 2134 */
l_L108X3: ;/* line 2137 */
__LABEL(l_L108X3);
  sim_icache_fetch(1376 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2138 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2139 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2140 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2141 */
} /* line 2141 */
  sim_icache_fetch(1380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2143 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2144 */
l_L139X3: ;/* line 2147 */
__LABEL(l_L139X3);
  sim_icache_fetch(1382 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2148 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2149 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2150 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2151 */
l_L138X3: ;/* line 2154 */
__LABEL(l_L138X3);
  sim_icache_fetch(1386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2155 */
} /* line 2155 */
l_L106X3: ;/* line 2158 */
__LABEL(l_L106X3);
  sim_icache_fetch(1387 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2159 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2160 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2161 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2162 */
} /* line 2162 */
  sim_icache_fetch(1391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2164 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2165 */
l_L137X3: ;/* line 2168 */
__LABEL(l_L137X3);
  sim_icache_fetch(1393 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2169 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2170 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2171 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2172 */
l_L136X3: ;/* line 2175 */
__LABEL(l_L136X3);
  sim_icache_fetch(1397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2176 */
} /* line 2176 */
l_L104X3: ;/* line 2179 */
__LABEL(l_L104X3);
  sim_icache_fetch(1398 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2180 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2181 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2182 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2183 */
} /* line 2183 */
  sim_icache_fetch(1402 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2185 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2186 */
l_L135X3: ;/* line 2189 */
__LABEL(l_L135X3);
  sim_icache_fetch(1404 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2190 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2191 */
   __GOTO(l_L161X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L161X3;
} /* line 2192 */
l_L134X3: ;/* line 2195 */
__LABEL(l_L134X3);
  sim_icache_fetch(1407 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2196 */
} /* line 2196 */
l_L102X3: ;/* line 2199 */
__LABEL(l_L102X3);
  sim_icache_fetch(1408 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2200 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2201 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2202 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2203 */
} /* line 2203 */
  sim_icache_fetch(1412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2205 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2206 */
l_L133X3: ;/* line 2209 */
__LABEL(l_L133X3);
  sim_icache_fetch(1414 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2210 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2211 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2212 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2213 */
l_L132X3: ;/* line 2216 */
__LABEL(l_L132X3);
  sim_icache_fetch(1418 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2217 */
} /* line 2217 */
l_L100X3: ;/* line 2220 */
__LABEL(l_L100X3);
  sim_icache_fetch(1419 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2221 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2222 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2223 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2224 */
} /* line 2224 */
  sim_icache_fetch(1423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2226 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2227 */
l_L131X3: ;/* line 2230 */
__LABEL(l_L131X3);
  sim_icache_fetch(1425 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2231 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2232 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2233 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2234 */
l_L130X3: ;/* line 2237 */
__LABEL(l_L130X3);
  sim_icache_fetch(1429 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2238 */
} /* line 2238 */
l_L98X3: ;/* line 2241 */
__LABEL(l_L98X3);
  sim_icache_fetch(1430 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2242 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2243 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2244 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2245 */
} /* line 2245 */
  sim_icache_fetch(1434 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2247 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2248 */
l_L129X3: ;/* line 2251 */
__LABEL(l_L129X3);
  sim_icache_fetch(1436 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2252 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2253 */
   __GOTO(l_L162X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L162X3;
} /* line 2254 */
l_L128X3: ;/* line 2257 */
__LABEL(l_L128X3);
  sim_icache_fetch(1439 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2258 */
} /* line 2258 */
l_L96X3: ;/* line 2261 */
__LABEL(l_L96X3);
  sim_icache_fetch(1440 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2262 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2263 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2264 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2265 */
} /* line 2265 */
  sim_icache_fetch(1444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2267 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2268 */
l_L127X3: ;/* line 2271 */
__LABEL(l_L127X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2272 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2273 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2274 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2275 */
l_L126X3: ;/* line 2278 */
__LABEL(l_L126X3);
  sim_icache_fetch(1450 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2279 */
} /* line 2279 */
l_L94X3: ;/* line 2283 */
__LABEL(l_L94X3);
  sim_icache_fetch(1451 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2284 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2285 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2286 */
} /* line 2286 */
  sim_icache_fetch(1454 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2288 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2289 */
l_L125X3: ;/* line 2292 */
__LABEL(l_L125X3);
  sim_icache_fetch(1456 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2293 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2294 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2295 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2296 */
l_L124X3: ;/* line 2299 */
__LABEL(l_L124X3);
  sim_icache_fetch(1460 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2300 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2301 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2302 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2303 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2304 */
l_L123X3: ;/* line 2308 */
__LABEL(l_L123X3);
  sim_icache_fetch(1465 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2309 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2310 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2311 */
l_L121X3: ;/* line 2314 */
__LABEL(l_L121X3);
  sim_icache_fetch(1468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2315 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2316 */
} /* line 2316 */
l_L158X3: ;/* line 2318 */
__LABEL(l_L158X3);
  sim_icache_fetch(1470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2319 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2320 */
l_L119X3: ;/* line 2323 */
__LABEL(l_L119X3);
  sim_icache_fetch(1472 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2324 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2325 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2326 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2327 */
l_L117X3: ;/* line 2330 */
__LABEL(l_L117X3);
  sim_icache_fetch(1476 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2331 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2332 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2333 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2334 */
l_L115X3: ;/* line 2337 */
__LABEL(l_L115X3);
  sim_icache_fetch(1480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2338 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2339 */
} /* line 2339 */
l_L159X3: ;/* line 2341 */
__LABEL(l_L159X3);
  sim_icache_fetch(1482 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2342 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2343 */
l_L113X3: ;/* line 2346 */
__LABEL(l_L113X3);
  sim_icache_fetch(1484 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2347 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2348 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2349 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2350 */
l_L111X3: ;/* line 2353 */
__LABEL(l_L111X3);
  sim_icache_fetch(1488 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2354 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2355 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2356 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2357 */
l_L109X3: ;/* line 2360 */
__LABEL(l_L109X3);
  sim_icache_fetch(1492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2361 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2362 */
} /* line 2362 */
l_L160X3: ;/* line 2364 */
__LABEL(l_L160X3);
  sim_icache_fetch(1494 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2365 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2366 */
l_L107X3: ;/* line 2369 */
__LABEL(l_L107X3);
  sim_icache_fetch(1496 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2370 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2371 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2372 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2373 */
l_L105X3: ;/* line 2376 */
__LABEL(l_L105X3);
  sim_icache_fetch(1500 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2377 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2378 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2379 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2380 */
l_L103X3: ;/* line 2383 */
__LABEL(l_L103X3);
  sim_icache_fetch(1504 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2384 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2385 */
} /* line 2385 */
l_L161X3: ;/* line 2387 */
__LABEL(l_L161X3);
  sim_icache_fetch(1506 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2388 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2389 */
l_L101X3: ;/* line 2392 */
__LABEL(l_L101X3);
  sim_icache_fetch(1508 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2393 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2394 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2395 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2396 */
l_L99X3: ;/* line 2399 */
__LABEL(l_L99X3);
  sim_icache_fetch(1512 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2400 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2401 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2402 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2403 */
l_L97X3: ;/* line 2406 */
__LABEL(l_L97X3);
  sim_icache_fetch(1516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2407 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2408 */
} /* line 2408 */
l_L162X3: ;/* line 2410 */
__LABEL(l_L162X3);
  sim_icache_fetch(1518 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2411 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2412 */
l_L95X3: ;/* line 2415 */
__LABEL(l_L95X3);
  sim_icache_fetch(1520 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2416 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2417 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2418 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2419 */
l_L93X3: ;/* line 2423 */
__LABEL(l_L93X3);
  sim_icache_fetch(1524 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2424 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2425 */
} /* line 2425 */
l_L157X3: ;/* line 2427 */
__LABEL(l_L157X3);
  sim_icache_fetch(1526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2428 */
} /* line 2428 */
  sim_icache_fetch(1528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2430 */
} /* line 2430 */
  sim_icache_fetch(1529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2432 */
l_L86X3: ;/* line 2435 */
__LABEL(l_L86X3);
		 /* line 2435 */
  sim_icache_fetch(1530 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2438 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (331 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2438 */
l_lr_200: ;/* line 2438 */
__LABEL(l_lr_200);
  sim_icache_fetch(1533 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2440 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2441 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2442 */
   __ADD_CYCLES(1);
} /* line 2442 */
  sim_icache_fetch(1537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2444 */
} /* line 2444 */
		 /* line 2445 */
  sim_icache_fetch(1538 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2447 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (331 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2448 */
l_lr_202: ;/* line 2448 */
__LABEL(l_lr_202);
  sim_icache_fetch(1542 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2450 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2451 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2452 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2453 */
   __MOV(reg_r0_3, 0); /* line 2454 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2455 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2456 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2457 */
   __ADD_CYCLES(1);
} /* line 2457 */
  sim_icache_fetch(1554 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2459 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2460 */
} /* line 2460 */
  sim_icache_fetch(1556 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L163X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2462 */
l_L164X3: ;/* line 2464 */
__LABEL(l_L164X3);
  sim_icache_fetch(1557 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L165X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2465 */
  sim_icache_fetch(1558 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2467 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2468 */
} /* line 2468 */
l_L166X3: ;/* line 2470 */
__LABEL(l_L166X3);
  sim_icache_fetch(1561 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2472 */
l_L165X3: ;/* line 2475 */
__LABEL(l_L165X3);
  sim_icache_fetch(1562 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2476 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2477 */
   __GOTO(l_L166X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L166X3;
} /* line 2478 */
l_L163X3: ;/* line 2481 */
__LABEL(l_L163X3);
  sim_icache_fetch(1565 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2482 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2483 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2484 */
   __ADD_CYCLES(1);
} /* line 2484 */
		 /* line 2485 */
  sim_icache_fetch(1570 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2487 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (331 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2488 */
l_lr_208: ;/* line 2488 */
__LABEL(l_lr_208);
  sim_icache_fetch(1573 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2490 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2491 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2492 */
   __MOV(reg_r0_3, 0); /* line 2493 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2494 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2495 */
   __ADD_CYCLES(1);
} /* line 2495 */
  sim_icache_fetch(1581 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2497 */
   __GOTO(l_L164X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L164X3;
} /* line 2498 */
l_L84X3: ;/* line 2501 */
__LABEL(l_L84X3);
  sim_icache_fetch(1583 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2502 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2503 */
l_L80X3: ;/* line 2506 */
__LABEL(l_L80X3);
  sim_icache_fetch(1585 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2507 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2508 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2509 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2510 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2511 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2512 */
l_L79X3: ;/* line 2515 */
__LABEL(l_L79X3);
  sim_icache_fetch(1592 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2516 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2517 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2518 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2519 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2520 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2521 */
l_L78X3: ;/* line 2524 */
__LABEL(l_L78X3);
  sim_icache_fetch(1599 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2525 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2526 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2527 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2528 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2529 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2530 */
l_L77X3: ;/* line 2533 */
__LABEL(l_L77X3);
  sim_icache_fetch(1606 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2534 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2535 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2536 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2537 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2538 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2539 */
l_L76X3: ;/* line 2542 */
__LABEL(l_L76X3);
  sim_icache_fetch(1613 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2543 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2544 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2545 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2546 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2547 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2548 */
l_L75X3: ;/* line 2551 */
__LABEL(l_L75X3);
  sim_icache_fetch(1620 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2552 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2553 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2554 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2555 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2556 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2557 */
l_L74X3: ;/* line 2560 */
__LABEL(l_L74X3);
  sim_icache_fetch(1627 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2561 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2562 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2563 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2564 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2565 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2566 */
l_L73X3: ;/* line 2569 */
__LABEL(l_L73X3);
  sim_icache_fetch(1634 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2570 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2571 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2572 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2573 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2574 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2575 */
l_L72X3: ;/* line 2578 */
__LABEL(l_L72X3);
  sim_icache_fetch(1641 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2579 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2580 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2581 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2582 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2583 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2584 */
l_L71X3: ;/* line 2587 */
__LABEL(l_L71X3);
  sim_icache_fetch(1648 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2588 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2589 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2590 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2591 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2592 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2593 */
l_L70X3: ;/* line 2596 */
__LABEL(l_L70X3);
  sim_icache_fetch(1655 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2597 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2598 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2599 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2600 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2601 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2602 */
l_L69X3: ;/* line 2605 */
__LABEL(l_L69X3);
  sim_icache_fetch(1662 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2606 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2607 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2608 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2609 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2610 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2611 */
l_L68X3: ;/* line 2614 */
__LABEL(l_L68X3);
  sim_icache_fetch(1669 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2615 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2616 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2617 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2618 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2619 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2620 */
l_L67X3: ;/* line 2623 */
__LABEL(l_L67X3);
  sim_icache_fetch(1676 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2624 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2625 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2626 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2627 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2628 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2629 */
l_L66X3: ;/* line 2633 */
__LABEL(l_L66X3);
  sim_icache_fetch(1683 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2634 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2635 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2636 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2637 */
} /* line 2637 */
l_L82X3: ;/* line 2639 */
__LABEL(l_L82X3);
  sim_icache_fetch(1688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2640 */
} /* line 2640 */
		 /* line 2641 */
  sim_icache_fetch(1689 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2644 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2645 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2646 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (331 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2646 */
l_lr_227: ;/* line 2646 */
__LABEL(l_lr_227);
  sim_icache_fetch(1694 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2648 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2649 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2650 */
} /* line 2650 */
  sim_icache_fetch(1697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2652 */
l_L63X3: ;/* line 2655 */
__LABEL(l_L63X3);
  sim_icache_fetch(1698 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2656 */
   __GOTO(l_L64X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L64X3;
} /* line 2657 */
l_L61X3: ;/* line 2660 */
__LABEL(l_L61X3);
  sim_icache_fetch(1700 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_16, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2661 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2662 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2663 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2664 */
   __MOV(reg_r0_17, (unsigned int) 257); /* line 2665 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2666 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2667 */
   __ADD_CYCLES(1);
} /* line 2667 */
  sim_icache_fetch(1710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2669 */
} /* line 2669 */
  sim_icache_fetch(1711 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2671 */
} /* line 2671 */
  sim_icache_fetch(1713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2673 */
} /* line 2673 */
  sim_icache_fetch(1714 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2675 */
   __LDBU(reg_r0_16, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2676 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2677 */
   __ADD_CYCLES(1);
} /* line 2677 */
  sim_icache_fetch(1719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2679 */
} /* line 2679 */
  sim_icache_fetch(1720 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2681 */
} /* line 2681 */
  sim_icache_fetch(1722 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2683 */
} /* line 2683 */
  sim_icache_fetch(1723 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2685 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2686 */
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2687 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2688 */
   __ADD_CYCLES(1);
} /* line 2688 */
  sim_icache_fetch(1730 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_11, (unsigned int) 1); /* line 2690 */
   __OR(reg_r0_16, reg_r0_16, reg_r0_18); /* line 2691 */
} /* line 2691 */
  sim_icache_fetch(1732 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_19); /* line 2693 */
} /* line 2693 */
  sim_icache_fetch(1734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2695 */
} /* line 2695 */
  sim_icache_fetch(1735 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2697 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2698 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2699 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2700 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2701 */
   __ADD_CYCLES(1);
} /* line 2701 */
  sim_icache_fetch(1744 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 2703 */
   __ADD(reg_r0_13, reg_r0_16, (unsigned int) -1); /* line 2704 */
   __ADD(reg_r0_15, reg_r0_14, (unsigned int) 1); /* line 2705 */
} /* line 2705 */
  sim_icache_fetch(1747 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_17, (unsigned int) 256); /* line 2707 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 2708 */
   __GOTO(l_L62X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L62X3;
} /* line 2709 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 213: goto l_L62X3;
    case 214: goto l_L64X3;
    case 215: goto l_L65X3;
    case 216: goto l_L81X3;
    case 217: goto l_L83X3;
    case 218: goto l_L85X3;
    case 219: goto l_L87X3;
    case 220: goto l_L89X3;
    case 222: goto l_lr_121;
    case 223: goto l_L90X3;
    case 225: goto l_lr_124;
    case 226: goto l_L91X3;
    case 227: goto l_L88X3;
    case 228: goto l_L92X3;
    case 229: goto l_L156X3;
    case 230: goto l_L155X3;
    case 231: goto l_L154X3;
    case 232: goto l_L122X3;
    case 233: goto l_L153X3;
    case 234: goto l_L152X3;
    case 235: goto l_L120X3;
    case 236: goto l_L151X3;
    case 237: goto l_L150X3;
    case 238: goto l_L118X3;
    case 239: goto l_L149X3;
    case 240: goto l_L148X3;
    case 241: goto l_L116X3;
    case 242: goto l_L147X3;
    case 243: goto l_L146X3;
    case 244: goto l_L114X3;
    case 245: goto l_L145X3;
    case 246: goto l_L144X3;
    case 247: goto l_L112X3;
    case 248: goto l_L143X3;
    case 249: goto l_L142X3;
    case 250: goto l_L110X3;
    case 251: goto l_L141X3;
    case 252: goto l_L140X3;
    case 253: goto l_L108X3;
    case 254: goto l_L139X3;
    case 255: goto l_L138X3;
    case 256: goto l_L106X3;
    case 257: goto l_L137X3;
    case 258: goto l_L136X3;
    case 259: goto l_L104X3;
    case 260: goto l_L135X3;
    case 261: goto l_L134X3;
    case 262: goto l_L102X3;
    case 263: goto l_L133X3;
    case 264: goto l_L132X3;
    case 265: goto l_L100X3;
    case 266: goto l_L131X3;
    case 267: goto l_L130X3;
    case 268: goto l_L98X3;
    case 269: goto l_L129X3;
    case 270: goto l_L128X3;
    case 271: goto l_L96X3;
    case 272: goto l_L127X3;
    case 273: goto l_L126X3;
    case 274: goto l_L94X3;
    case 275: goto l_L125X3;
    case 276: goto l_L124X3;
    case 277: goto l_L123X3;
    case 278: goto l_L121X3;
    case 279: goto l_L158X3;
    case 280: goto l_L119X3;
    case 281: goto l_L117X3;
    case 282: goto l_L115X3;
    case 283: goto l_L159X3;
    case 284: goto l_L113X3;
    case 285: goto l_L111X3;
    case 286: goto l_L109X3;
    case 287: goto l_L160X3;
    case 288: goto l_L107X3;
    case 289: goto l_L105X3;
    case 290: goto l_L103X3;
    case 291: goto l_L161X3;
    case 292: goto l_L101X3;
    case 293: goto l_L99X3;
    case 294: goto l_L97X3;
    case 295: goto l_L162X3;
    case 296: goto l_L95X3;
    case 297: goto l_L93X3;
    case 298: goto l_L157X3;
    case 299: goto l_L86X3;
    case 301: goto l_lr_200;
    case 303: goto l_lr_202;
    case 304: goto l_L164X3;
    case 305: goto l_L166X3;
    case 306: goto l_L165X3;
    case 307: goto l_L163X3;
    case 309: goto l_lr_208;
    case 310: goto l_L84X3;
    case 311: goto l_L80X3;
    case 312: goto l_L79X3;
    case 313: goto l_L78X3;
    case 314: goto l_L77X3;
    case 315: goto l_L76X3;
    case 316: goto l_L75X3;
    case 317: goto l_L74X3;
    case 318: goto l_L73X3;
    case 319: goto l_L72X3;
    case 320: goto l_L71X3;
    case 321: goto l_L70X3;
    case 322: goto l_L69X3;
    case 323: goto l_L68X3;
    case 324: goto l_L67X3;
    case 325: goto l_L66X3;
    case 326: goto l_L82X3;
    case 328: goto l_lr_227;
    case 329: goto l_L63X3;
    case 330: goto l_L61X3;
    case 331:
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
  reg_l0_0 = (363 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1751 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 2728 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2729 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2730 */
} /* line 2730 */
  sim_icache_fetch(1756 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2732 */
  sim_icache_fetch(1757 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2734 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2735 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2736 */
} /* line 2736 */
  sim_icache_fetch(1760 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_14293Xbuf); /* line 2738 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_14293Xbuf),0,1)); /* line 2739 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_14293Xbuf + (unsigned int) 1)); /* line 2740 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2741 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2742 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2743 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2744 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2745 */
} /* line 2745 */
  sim_icache_fetch(1773 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2747 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2748 */
} /* line 2748 */
  sim_icache_fetch(1775 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2750 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2751 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2752 */
} /* line 2752 */
  sim_icache_fetch(1778 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2754 */
} /* line 2754 */
  sim_icache_fetch(1779 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_14293Xbuf),0,1), reg_r0_2); /* line 2756 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2757 */
  sim_icache_fetch(1782 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2759 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2760 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2761 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2762 */
} /* line 2762 */
l_L168X3: ;/* line 2764 */
__LABEL(l_L168X3);
  sim_icache_fetch(1786 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2765 */
   __MOV(reg_r0_3, (unsigned int) compress_14293Xbuf); /* line 2766 */
} /* line 2766 */
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
} /* line 2768 */
  sim_icache_fetch(1790 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2770 */
} /* line 2770 */
l_L169X3: ;/* line 2772 */
__LABEL(l_L169X3);
  sim_icache_fetch(1791 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 2773 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2774 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2775 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2776 */
   __ADD_CYCLES(1);
} /* line 2776 */
  sim_icache_fetch(1798 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2778 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2779 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2780 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2781 */
} /* line 2781 */
  sim_icache_fetch(1802 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_14293Xoffset,0,4), reg_r0_2); /* line 2783 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2784 */
} /* line 2784 */
  sim_icache_fetch(1805 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L170X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2786 */
  sim_icache_fetch(1806 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2788 */
} /* line 2788 */
l_L171X3: ;/* line 2791 */
__LABEL(l_L171X3);
  sim_icache_fetch(1808 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2792 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2793 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2794 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2795 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2796 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2797 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2798 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2799 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2800 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2801 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -16); /* line 2802 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 16); /* line 2803 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2804 */
   __ADD_CYCLES(1);
} /* line 2804 */
  sim_icache_fetch(1822 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2806 */
} /* line 2806 */
  sim_icache_fetch(1823 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2808 */
} /* line 2808 */
  sim_icache_fetch(1825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2810 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2811 */
  sim_icache_fetch(1827 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2813 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2814 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2815 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2816 */
   __ADD_CYCLES(1);
} /* line 2816 */
  sim_icache_fetch(1832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2818 */
} /* line 2818 */
  sim_icache_fetch(1833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2820 */
} /* line 2820 */
  sim_icache_fetch(1835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2822 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2823 */
  sim_icache_fetch(1837 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2825 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2826 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2827 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2828 */
   __ADD_CYCLES(1);
} /* line 2828 */
  sim_icache_fetch(1842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2830 */
} /* line 2830 */
  sim_icache_fetch(1843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2832 */
} /* line 2832 */
  sim_icache_fetch(1845 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2834 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2835 */
  sim_icache_fetch(1847 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2837 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2838 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2839 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2840 */
   __ADD_CYCLES(1);
} /* line 2840 */
  sim_icache_fetch(1852 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2842 */
} /* line 2842 */
  sim_icache_fetch(1853 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2844 */
} /* line 2844 */
  sim_icache_fetch(1855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2846 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2847 */
  sim_icache_fetch(1857 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2849 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2850 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2851 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2852 */
   __ADD_CYCLES(1);
} /* line 2852 */
  sim_icache_fetch(1862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2854 */
} /* line 2854 */
  sim_icache_fetch(1863 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2856 */
} /* line 2856 */
  sim_icache_fetch(1865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2858 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2859 */
  sim_icache_fetch(1867 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2861 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2862 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2863 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2864 */
   __ADD_CYCLES(1);
} /* line 2864 */
  sim_icache_fetch(1872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2866 */
} /* line 2866 */
  sim_icache_fetch(1873 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2868 */
} /* line 2868 */
  sim_icache_fetch(1875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2870 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2871 */
  sim_icache_fetch(1877 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2873 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2874 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2875 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2876 */
   __ADD_CYCLES(1);
} /* line 2876 */
  sim_icache_fetch(1882 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2878 */
} /* line 2878 */
  sim_icache_fetch(1883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2880 */
} /* line 2880 */
  sim_icache_fetch(1885 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2882 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2883 */
  sim_icache_fetch(1887 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2885 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2886 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2887 */
   __ADD(reg_r0_5, reg_r0_7, (unsigned int) -16); /* line 2888 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2889 */
   __ADD_CYCLES(1);
} /* line 2889 */
  sim_icache_fetch(1893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2891 */
} /* line 2891 */
  sim_icache_fetch(1894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2893 */
} /* line 2893 */
  sim_icache_fetch(1896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2895 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2896 */
  sim_icache_fetch(1898 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2898 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2899 */
   __CMPEQ(reg_b0_7, reg_r0_7, 0); /* line 2900 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2901 */
   __ADD_CYCLES(1);
} /* line 2901 */
  sim_icache_fetch(1903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2903 */
} /* line 2903 */
  sim_icache_fetch(1904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2905 */
} /* line 2905 */
  sim_icache_fetch(1906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2907 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2908 */
  sim_icache_fetch(1908 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2910 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2911 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2912 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2913 */
   __ADD_CYCLES(1);
} /* line 2913 */
  sim_icache_fetch(1913 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2915 */
} /* line 2915 */
  sim_icache_fetch(1914 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2917 */
} /* line 2917 */
  sim_icache_fetch(1916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2919 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2920 */
  sim_icache_fetch(1918 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 2922 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2923 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2924 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2925 */
   __ADD_CYCLES(1);
} /* line 2925 */
  sim_icache_fetch(1923 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2927 */
} /* line 2927 */
  sim_icache_fetch(1924 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2929 */
} /* line 2929 */
  sim_icache_fetch(1926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2931 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2932 */
  sim_icache_fetch(1928 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 2934 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2935 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2936 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2937 */
   __ADD_CYCLES(1);
} /* line 2937 */
  sim_icache_fetch(1933 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2939 */
} /* line 2939 */
  sim_icache_fetch(1934 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2941 */
} /* line 2941 */
  sim_icache_fetch(1936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2943 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2944 */
  sim_icache_fetch(1938 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 2946 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2947 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 4); /* line 2948 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2949 */
   __ADD_CYCLES(1);
} /* line 2949 */
  sim_icache_fetch(1943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2951 */
} /* line 2951 */
  sim_icache_fetch(1944 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2953 */
} /* line 2953 */
  sim_icache_fetch(1946 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2955 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2956 */
  sim_icache_fetch(1948 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 2958 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2959 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 5); /* line 2960 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2961 */
   __ADD_CYCLES(1);
} /* line 2961 */
  sim_icache_fetch(1953 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2963 */
} /* line 2963 */
  sim_icache_fetch(1954 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2965 */
} /* line 2965 */
  sim_icache_fetch(1956 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2967 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2968 */
  sim_icache_fetch(1958 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 2970 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2971 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 6); /* line 2972 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2973 */
   __ADD_CYCLES(1);
} /* line 2973 */
  sim_icache_fetch(1963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2975 */
} /* line 2975 */
  sim_icache_fetch(1964 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2977 */
} /* line 2977 */
  sim_icache_fetch(1966 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2979 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2980 */
  sim_icache_fetch(1968 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 2982 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2983 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 7); /* line 2984 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2985 */
   __ADD_CYCLES(1);
} /* line 2985 */
  sim_icache_fetch(1973 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 2987 */
} /* line 2987 */
  sim_icache_fetch(1974 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 2989 */
} /* line 2989 */
  sim_icache_fetch(1976 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2991 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 2992 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2993 */
  sim_icache_fetch(1979 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 2995 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2996 */
   __CMPEQ(reg_b0_7, reg_r0_7, (unsigned int) 8); /* line 2997 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) 16); /* line 2998 */
   __MFB(reg_r0_8, t__i32_0); /* line 2999 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3000 */
   __ADD_CYCLES(1);
} /* line 3000 */
  sim_icache_fetch(1986 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3002 */
} /* line 3002 */
  sim_icache_fetch(1987 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3004 */
} /* line 3004 */
  sim_icache_fetch(1989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3006 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3007 */
  sim_icache_fetch(1991 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 3009 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3010 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 9); /* line 3011 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3012 */
   __ADD_CYCLES(1);
} /* line 3012 */
  sim_icache_fetch(1996 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3014 */
} /* line 3014 */
  sim_icache_fetch(1997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3016 */
} /* line 3016 */
  sim_icache_fetch(1999 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3018 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3019 */
  sim_icache_fetch(2001 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 2),0,1)); /* line 3021 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3022 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 10); /* line 3023 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3024 */
   __ADD_CYCLES(1);
} /* line 3024 */
  sim_icache_fetch(2006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3026 */
} /* line 3026 */
  sim_icache_fetch(2007 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3028 */
} /* line 3028 */
  sim_icache_fetch(2009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3030 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3031 */
  sim_icache_fetch(2011 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 3),0,1)); /* line 3033 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3034 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 11); /* line 3035 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3036 */
   __ADD_CYCLES(1);
} /* line 3036 */
  sim_icache_fetch(2016 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3038 */
} /* line 3038 */
  sim_icache_fetch(2017 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3040 */
} /* line 3040 */
  sim_icache_fetch(2019 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3042 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3043 */
  sim_icache_fetch(2021 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 4),0,1)); /* line 3045 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3046 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 12); /* line 3047 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3048 */
   __ADD_CYCLES(1);
} /* line 3048 */
  sim_icache_fetch(2026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3050 */
} /* line 3050 */
  sim_icache_fetch(2027 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3052 */
} /* line 3052 */
  sim_icache_fetch(2029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3054 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3055 */
  sim_icache_fetch(2031 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 5),0,1)); /* line 3057 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3058 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 13); /* line 3059 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3060 */
   __ADD_CYCLES(1);
} /* line 3060 */
  sim_icache_fetch(2036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3062 */
} /* line 3062 */
  sim_icache_fetch(2037 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3064 */
} /* line 3064 */
  sim_icache_fetch(2039 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3066 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3067 */
  sim_icache_fetch(2041 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 6),0,1)); /* line 3069 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3070 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 14); /* line 3071 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3072 */
   __ADD_CYCLES(1);
} /* line 3072 */
  sim_icache_fetch(2046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3074 */
} /* line 3074 */
  sim_icache_fetch(2047 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3076 */
} /* line 3076 */
  sim_icache_fetch(2049 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3078 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3079 */
  sim_icache_fetch(2051 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 7),0,1)); /* line 3081 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3082 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 15); /* line 3083 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3084 */
   __ADD_CYCLES(1);
} /* line 3084 */
  sim_icache_fetch(2056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3086 */
} /* line 3086 */
  sim_icache_fetch(2057 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3088 */
} /* line 3088 */
  sim_icache_fetch(2059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3090 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3091 */
  sim_icache_fetch(2061 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 8),0,1)); /* line 3093 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3094 */
   __MTB(reg_b0_7, reg_r0_8); /* line 3095 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3096 */
   __ADD_CYCLES(1);
} /* line 3096 */
  sim_icache_fetch(2066 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3098 */
} /* line 3098 */
  sim_icache_fetch(2067 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3100 */
} /* line 3100 */
  sim_icache_fetch(2069 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3102 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3103 */
  sim_icache_fetch(2071 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 9),0,1)); /* line 3105 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3106 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3107 */
   __ADD_CYCLES(1);
} /* line 3107 */
  sim_icache_fetch(2075 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3109 */
} /* line 3109 */
  sim_icache_fetch(2076 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3111 */
} /* line 3111 */
  sim_icache_fetch(2078 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3113 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3114 */
  sim_icache_fetch(2080 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 10),0,1)); /* line 3116 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3117 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3118 */
   __ADD_CYCLES(1);
} /* line 3118 */
  sim_icache_fetch(2084 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3120 */
} /* line 3120 */
  sim_icache_fetch(2085 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3122 */
} /* line 3122 */
  sim_icache_fetch(2087 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3124 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3125 */
  sim_icache_fetch(2089 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 11),0,1)); /* line 3127 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3128 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3129 */
   __ADD_CYCLES(1);
} /* line 3129 */
  sim_icache_fetch(2093 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3131 */
} /* line 3131 */
  sim_icache_fetch(2094 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3133 */
} /* line 3133 */
  sim_icache_fetch(2096 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3135 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3136 */
  sim_icache_fetch(2098 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 12),0,1)); /* line 3138 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3139 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3140 */
   __ADD_CYCLES(1);
} /* line 3140 */
  sim_icache_fetch(2102 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3142 */
} /* line 3142 */
  sim_icache_fetch(2103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3144 */
} /* line 3144 */
  sim_icache_fetch(2105 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3146 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3147 */
  sim_icache_fetch(2107 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 13),0,1)); /* line 3149 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3150 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3151 */
   __ADD_CYCLES(1);
} /* line 3151 */
  sim_icache_fetch(2111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3153 */
} /* line 3153 */
  sim_icache_fetch(2112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3155 */
} /* line 3155 */
  sim_icache_fetch(2114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3157 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3158 */
  sim_icache_fetch(2116 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 14),0,1)); /* line 3160 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3161 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3162 */
   __ADD_CYCLES(1);
} /* line 3162 */
  sim_icache_fetch(2120 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3164 */
} /* line 3164 */
  sim_icache_fetch(2121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3166 */
} /* line 3166 */
  sim_icache_fetch(2123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3168 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3169 */
  sim_icache_fetch(2125 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 15),0,1)); /* line 3171 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3172 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3173 */
   __ADD_CYCLES(1);
} /* line 3173 */
  sim_icache_fetch(2129 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3175 */
} /* line 3175 */
  sim_icache_fetch(2130 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3177 */
} /* line 3177 */
  sim_icache_fetch(2132 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 3179 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3181 */
  sim_icache_fetch(2134 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L171X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L171X3;
} /* line 3183 */
l_L172X3: ;/* line 3186 */
__LABEL(l_L172X3);
  sim_icache_fetch(2135 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_14293Xoffset,0,4), 0); /* line 3187 */
} /* line 3187 */
l_L170X3: ;/* line 3190 */
__LABEL(l_L170X3);
  sim_icache_fetch(2137 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3191 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3192 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3193 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3194 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3195 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3196 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3197 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3198 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3199 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3200 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3201 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3202 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3203 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3204 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3205 */
} /* line 3205 */
  sim_icache_fetch(2156 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3207 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3208 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3209 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3210 */
   __MOV(reg_r0_5, (unsigned int) compress_14293Xbuf); /* line 3211 */
   __MOV(reg_r0_3, 0); /* line 3212 */
} /* line 3212 */
  sim_icache_fetch(2163 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3214 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3215 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3216 */
} /* line 3216 */
  sim_icache_fetch(2166 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3218 */
} /* line 3218 */
  sim_icache_fetch(2167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3220 */
  sim_icache_fetch(2168 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L174X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3222 */
l_L175X3: ;/* line 3225 */
__LABEL(l_L175X3);
  sim_icache_fetch(2169 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3226 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3227 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3228 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3229 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3230 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3231 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3232 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3233 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3234 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3235 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3236 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3237 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3238 */
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3239 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3240 */
} /* line 3240 */
  sim_icache_fetch(2186 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3242 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3243 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3244 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3245 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3246 */
} /* line 3246 */
  sim_icache_fetch(2191 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3248 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3249 */
   __ADD(reg_r0_3, reg_r0_38, (unsigned int) 16); /* line 3250 */
} /* line 3250 */
  sim_icache_fetch(2194 + t_thisfile.offset, 1);
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
} /* line 3252 */
  sim_icache_fetch(2195 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3254 */
} /* line 3254 */
  sim_icache_fetch(2197 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3256 */
} /* line 3256 */
  sim_icache_fetch(2198 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3258 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3259 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3260 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3261 */
   __ADD_CYCLES(1);
} /* line 3261 */
  sim_icache_fetch(2204 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 3263 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3264 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3265 */
} /* line 3265 */
  sim_icache_fetch(2207 + t_thisfile.offset, 1);
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
} /* line 3267 */
  sim_icache_fetch(2208 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3269 */
} /* line 3269 */
  sim_icache_fetch(2210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3271 */
} /* line 3271 */
  sim_icache_fetch(2211 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3273 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3274 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3275 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3276 */
   __ADD_CYCLES(1);
} /* line 3276 */
  sim_icache_fetch(2217 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 3278 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3279 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3280 */
} /* line 3280 */
  sim_icache_fetch(2220 + t_thisfile.offset, 1);
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
} /* line 3282 */
  sim_icache_fetch(2221 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3284 */
} /* line 3284 */
  sim_icache_fetch(2223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3286 */
} /* line 3286 */
  sim_icache_fetch(2224 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3288 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3289 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3290 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3291 */
   __ADD_CYCLES(1);
} /* line 3291 */
  sim_icache_fetch(2230 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 3293 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3294 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3295 */
} /* line 3295 */
  sim_icache_fetch(2233 + t_thisfile.offset, 1);
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
} /* line 3297 */
  sim_icache_fetch(2234 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3299 */
} /* line 3299 */
  sim_icache_fetch(2236 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3301 */
} /* line 3301 */
  sim_icache_fetch(2237 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3303 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3304 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3305 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3306 */
   __ADD_CYCLES(1);
} /* line 3306 */
  sim_icache_fetch(2243 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 3308 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3309 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3310 */
} /* line 3310 */
  sim_icache_fetch(2246 + t_thisfile.offset, 1);
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
} /* line 3312 */
  sim_icache_fetch(2247 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3314 */
} /* line 3314 */
  sim_icache_fetch(2249 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3316 */
} /* line 3316 */
  sim_icache_fetch(2250 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3318 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3319 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3320 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3321 */
   __ADD_CYCLES(1);
} /* line 3321 */
  sim_icache_fetch(2256 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 3323 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3324 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3325 */
} /* line 3325 */
  sim_icache_fetch(2259 + t_thisfile.offset, 1);
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
} /* line 3327 */
  sim_icache_fetch(2260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3329 */
} /* line 3329 */
  sim_icache_fetch(2262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3331 */
} /* line 3331 */
  sim_icache_fetch(2263 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3333 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3334 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3335 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3336 */
   __ADD_CYCLES(1);
} /* line 3336 */
  sim_icache_fetch(2269 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 3338 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3339 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3340 */
} /* line 3340 */
  sim_icache_fetch(2272 + t_thisfile.offset, 1);
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
} /* line 3342 */
  sim_icache_fetch(2273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3344 */
} /* line 3344 */
  sim_icache_fetch(2275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3346 */
} /* line 3346 */
  sim_icache_fetch(2276 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3348 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3349 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3350 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3351 */
   __ADD_CYCLES(1);
} /* line 3351 */
  sim_icache_fetch(2282 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 3353 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3354 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3355 */
} /* line 3355 */
  sim_icache_fetch(2285 + t_thisfile.offset, 1);
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
} /* line 3357 */
  sim_icache_fetch(2286 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3359 */
} /* line 3359 */
  sim_icache_fetch(2288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3361 */
} /* line 3361 */
  sim_icache_fetch(2289 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3363 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3364 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3365 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3366 */
   __ADD_CYCLES(1);
} /* line 3366 */
  sim_icache_fetch(2295 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 3368 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3369 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3370 */
} /* line 3370 */
  sim_icache_fetch(2298 + t_thisfile.offset, 1);
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
} /* line 3372 */
  sim_icache_fetch(2299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3374 */
} /* line 3374 */
  sim_icache_fetch(2301 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3376 */
} /* line 3376 */
  sim_icache_fetch(2302 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3378 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3379 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3380 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3381 */
   __ADD_CYCLES(1);
} /* line 3381 */
  sim_icache_fetch(2308 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 3383 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3384 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3385 */
} /* line 3385 */
  sim_icache_fetch(2311 + t_thisfile.offset, 1);
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
} /* line 3387 */
  sim_icache_fetch(2312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3389 */
} /* line 3389 */
  sim_icache_fetch(2314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3391 */
} /* line 3391 */
  sim_icache_fetch(2315 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3393 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3394 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3395 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3396 */
   __ADD_CYCLES(1);
} /* line 3396 */
  sim_icache_fetch(2321 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 3398 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3399 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3400 */
} /* line 3400 */
  sim_icache_fetch(2324 + t_thisfile.offset, 1);
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
} /* line 3402 */
  sim_icache_fetch(2325 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3404 */
} /* line 3404 */
  sim_icache_fetch(2327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3406 */
} /* line 3406 */
  sim_icache_fetch(2328 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3408 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3409 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3410 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3411 */
   __ADD_CYCLES(1);
} /* line 3411 */
  sim_icache_fetch(2334 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 3413 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3414 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3415 */
} /* line 3415 */
  sim_icache_fetch(2337 + t_thisfile.offset, 1);
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
} /* line 3417 */
  sim_icache_fetch(2338 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3419 */
} /* line 3419 */
  sim_icache_fetch(2340 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3421 */
} /* line 3421 */
  sim_icache_fetch(2341 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3423 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3424 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3425 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3426 */
   __ADD_CYCLES(1);
} /* line 3426 */
  sim_icache_fetch(2347 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 3428 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3429 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3430 */
} /* line 3430 */
  sim_icache_fetch(2350 + t_thisfile.offset, 1);
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
} /* line 3432 */
  sim_icache_fetch(2351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3434 */
} /* line 3434 */
  sim_icache_fetch(2353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3436 */
} /* line 3436 */
  sim_icache_fetch(2354 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3438 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3439 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3440 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3441 */
   __ADD_CYCLES(1);
} /* line 3441 */
  sim_icache_fetch(2360 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 3443 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3444 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3445 */
} /* line 3445 */
  sim_icache_fetch(2363 + t_thisfile.offset, 1);
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
} /* line 3447 */
  sim_icache_fetch(2364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3449 */
} /* line 3449 */
  sim_icache_fetch(2366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3451 */
} /* line 3451 */
  sim_icache_fetch(2367 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3453 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3454 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3455 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3456 */
   __ADD_CYCLES(1);
} /* line 3456 */
  sim_icache_fetch(2373 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_2); /* line 3458 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3459 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3460 */
} /* line 3460 */
  sim_icache_fetch(2376 + t_thisfile.offset, 1);
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
} /* line 3462 */
  sim_icache_fetch(2377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3464 */
} /* line 3464 */
  sim_icache_fetch(2379 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3466 */
} /* line 3466 */
  sim_icache_fetch(2380 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3468 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3469 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3470 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3471 */
   __ADD_CYCLES(1);
} /* line 3471 */
  sim_icache_fetch(2386 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_2); /* line 3473 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3474 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3475 */
} /* line 3475 */
  sim_icache_fetch(2389 + t_thisfile.offset, 1);
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
} /* line 3477 */
  sim_icache_fetch(2390 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3479 */
} /* line 3479 */
  sim_icache_fetch(2392 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_5); /* line 3481 */
} /* line 3481 */
  sim_icache_fetch(2393 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3483 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_37,0,1)); /* line 3484 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3485 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3486 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3487 */
   __ADD_CYCLES(1);
} /* line 3487 */
  sim_icache_fetch(2400 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_38, reg_r0_2); /* line 3489 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3490 */
} /* line 3490 */
  sim_icache_fetch(2402 + t_thisfile.offset, 1);
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
} /* line 3492 */
  sim_icache_fetch(2403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3494 */
} /* line 3494 */
  sim_icache_fetch(2405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3496 */
} /* line 3496 */
  sim_icache_fetch(2406 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3498 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3499 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3500 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3501 */
   __ADD_CYCLES(1);
} /* line 3501 */
  sim_icache_fetch(2412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3503 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3504 */
} /* line 3504 */
  sim_icache_fetch(2414 + t_thisfile.offset, 1);
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
} /* line 3506 */
  sim_icache_fetch(2415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3508 */
} /* line 3508 */
  sim_icache_fetch(2417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3510 */
} /* line 3510 */
  sim_icache_fetch(2418 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3512 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3513 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3514 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3515 */
   __ADD_CYCLES(1);
} /* line 3515 */
  sim_icache_fetch(2424 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3517 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3518 */
} /* line 3518 */
  sim_icache_fetch(2426 + t_thisfile.offset, 1);
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
} /* line 3520 */
  sim_icache_fetch(2427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3522 */
} /* line 3522 */
  sim_icache_fetch(2429 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3524 */
} /* line 3524 */
  sim_icache_fetch(2430 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3526 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3527 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3528 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3529 */
   __ADD_CYCLES(1);
} /* line 3529 */
  sim_icache_fetch(2436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3531 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3532 */
} /* line 3532 */
  sim_icache_fetch(2438 + t_thisfile.offset, 1);
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
} /* line 3534 */
  sim_icache_fetch(2439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3536 */
} /* line 3536 */
  sim_icache_fetch(2441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3538 */
} /* line 3538 */
  sim_icache_fetch(2442 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3540 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3541 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3542 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3543 */
   __ADD_CYCLES(1);
} /* line 3543 */
  sim_icache_fetch(2448 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3545 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3546 */
} /* line 3546 */
  sim_icache_fetch(2450 + t_thisfile.offset, 1);
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
} /* line 3548 */
  sim_icache_fetch(2451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3550 */
} /* line 3550 */
  sim_icache_fetch(2453 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3552 */
} /* line 3552 */
  sim_icache_fetch(2454 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3554 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3555 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3556 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3557 */
   __ADD_CYCLES(1);
} /* line 3557 */
  sim_icache_fetch(2460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3559 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3560 */
} /* line 3560 */
  sim_icache_fetch(2462 + t_thisfile.offset, 1);
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
} /* line 3562 */
  sim_icache_fetch(2463 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3564 */
} /* line 3564 */
  sim_icache_fetch(2465 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3566 */
} /* line 3566 */
  sim_icache_fetch(2466 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3568 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3569 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3570 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3571 */
   __ADD_CYCLES(1);
} /* line 3571 */
  sim_icache_fetch(2472 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3573 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3574 */
} /* line 3574 */
  sim_icache_fetch(2474 + t_thisfile.offset, 1);
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
} /* line 3576 */
  sim_icache_fetch(2475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3578 */
} /* line 3578 */
  sim_icache_fetch(2477 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3580 */
} /* line 3580 */
  sim_icache_fetch(2478 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3582 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3583 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3584 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3585 */
   __ADD_CYCLES(1);
} /* line 3585 */
  sim_icache_fetch(2484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3587 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3588 */
} /* line 3588 */
  sim_icache_fetch(2486 + t_thisfile.offset, 1);
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
} /* line 3590 */
  sim_icache_fetch(2487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3592 */
} /* line 3592 */
  sim_icache_fetch(2489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3594 */
} /* line 3594 */
  sim_icache_fetch(2490 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3596 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3597 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3598 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3599 */
   __ADD_CYCLES(1);
} /* line 3599 */
  sim_icache_fetch(2496 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3601 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3602 */
} /* line 3602 */
  sim_icache_fetch(2498 + t_thisfile.offset, 1);
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
} /* line 3604 */
  sim_icache_fetch(2499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3606 */
} /* line 3606 */
  sim_icache_fetch(2501 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3608 */
} /* line 3608 */
  sim_icache_fetch(2502 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3610 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3611 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3612 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3613 */
   __ADD_CYCLES(1);
} /* line 3613 */
  sim_icache_fetch(2508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3615 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3616 */
} /* line 3616 */
  sim_icache_fetch(2510 + t_thisfile.offset, 1);
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
} /* line 3618 */
  sim_icache_fetch(2511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3620 */
} /* line 3620 */
  sim_icache_fetch(2513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3622 */
} /* line 3622 */
  sim_icache_fetch(2514 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3624 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3625 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3626 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3627 */
   __ADD_CYCLES(1);
} /* line 3627 */
  sim_icache_fetch(2520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3629 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3630 */
} /* line 3630 */
  sim_icache_fetch(2522 + t_thisfile.offset, 1);
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
} /* line 3632 */
  sim_icache_fetch(2523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3634 */
} /* line 3634 */
  sim_icache_fetch(2525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3636 */
} /* line 3636 */
  sim_icache_fetch(2526 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3638 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3639 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3640 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3641 */
   __ADD_CYCLES(1);
} /* line 3641 */
  sim_icache_fetch(2532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3643 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3644 */
} /* line 3644 */
  sim_icache_fetch(2534 + t_thisfile.offset, 1);
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
} /* line 3646 */
  sim_icache_fetch(2535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3648 */
} /* line 3648 */
  sim_icache_fetch(2537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3650 */
} /* line 3650 */
  sim_icache_fetch(2538 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3652 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3653 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3654 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3655 */
   __ADD_CYCLES(1);
} /* line 3655 */
  sim_icache_fetch(2544 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3657 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3658 */
} /* line 3658 */
  sim_icache_fetch(2546 + t_thisfile.offset, 1);
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
} /* line 3660 */
  sim_icache_fetch(2547 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3662 */
} /* line 3662 */
  sim_icache_fetch(2549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3664 */
} /* line 3664 */
  sim_icache_fetch(2550 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3666 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3667 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3668 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3669 */
   __ADD_CYCLES(1);
} /* line 3669 */
  sim_icache_fetch(2556 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3671 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3672 */
} /* line 3672 */
  sim_icache_fetch(2558 + t_thisfile.offset, 1);
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
} /* line 3674 */
  sim_icache_fetch(2559 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3676 */
} /* line 3676 */
  sim_icache_fetch(2561 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3678 */
} /* line 3678 */
  sim_icache_fetch(2562 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3680 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3681 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3682 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3683 */
   __ADD_CYCLES(1);
} /* line 3683 */
  sim_icache_fetch(2568 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3685 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3686 */
} /* line 3686 */
  sim_icache_fetch(2570 + t_thisfile.offset, 1);
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
} /* line 3688 */
  sim_icache_fetch(2571 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3690 */
} /* line 3690 */
  sim_icache_fetch(2573 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3692 */
} /* line 3692 */
  sim_icache_fetch(2574 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3694 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3695 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3696 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3697 */
   __ADD_CYCLES(1);
} /* line 3697 */
  sim_icache_fetch(2580 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3699 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3700 */
} /* line 3700 */
  sim_icache_fetch(2582 + t_thisfile.offset, 1);
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
} /* line 3702 */
  sim_icache_fetch(2583 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3704 */
} /* line 3704 */
  sim_icache_fetch(2585 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3706 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 3707 */
l_L176X3: ;/* line 3710 */
__LABEL(l_L176X3);
  sim_icache_fetch(2587 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3711 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3712 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3713 */
   __ADD_CYCLES(1);
} /* line 3713 */
  sim_icache_fetch(2592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3715 */
} /* line 3715 */
  sim_icache_fetch(2593 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3717 */
} /* line 3717 */
l_L174X3: ;/* line 3720 */
__LABEL(l_L174X3);
  sim_icache_fetch(2595 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_14293Xoffset,0,4), 0); /* line 3721 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3722 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3723 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3724 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3725 */
   __ADD_CYCLES(1);
} /* line 3725 */
  sim_icache_fetch(2603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3727 */
} /* line 3727 */
  sim_icache_fetch(2604 + t_thisfile.offset, 1);
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
} /* line 3729 */
  sim_icache_fetch(2605 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3732 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3733 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3734 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3735 */
l_L177X3: ;/* line 3738 */
__LABEL(l_L177X3);
  sim_icache_fetch(2612 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3739 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3740 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3741 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3742 */
   __ADD_CYCLES(1);
} /* line 3742 */
  sim_icache_fetch(2619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3744 */
} /* line 3744 */
  sim_icache_fetch(2620 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3746 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3747 */
} /* line 3747 */
  sim_icache_fetch(2623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L178X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3749 */
  sim_icache_fetch(2624 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3752 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3753 */
l_L178X3: ;/* line 3756 */
__LABEL(l_L178X3);
  sim_icache_fetch(2627 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3757 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3758 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3759 */
   __ADD_CYCLES(1);
} /* line 3759 */
  sim_icache_fetch(2631 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3761 */
} /* line 3761 */
  sim_icache_fetch(2632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3763 */
} /* line 3763 */
  sim_icache_fetch(2633 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3766 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3767 */
l_L173X3: ;/* line 3770 */
__LABEL(l_L173X3);
  sim_icache_fetch(2636 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3772 */
l_L167X3: ;/* line 3775 */
__LABEL(l_L167X3);
  sim_icache_fetch(2637 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3776 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3777 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3778 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3779 */
   __ADD_CYCLES(1);
} /* line 3779 */
  sim_icache_fetch(2644 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3781 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3782 */
} /* line 3782 */
  sim_icache_fetch(2646 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3784 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3785 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3786 */
l_L180X3: ;/* line 3788 */
__LABEL(l_L180X3);
  sim_icache_fetch(2649 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3789 */
   __STW(mem_trace_st((unsigned int) compress_14293Xoffset,0,4), 0); /* line 3790 */
} /* line 3790 */
  sim_icache_fetch(2652 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3792 */
} /* line 3792 */
  sim_icache_fetch(2653 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3794 */
} /* line 3794 */
  sim_icache_fetch(2654 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3797 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3798 */
l_L179X3: ;/* line 3801 */
__LABEL(l_L179X3);
  sim_icache_fetch(2657 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3802 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3803 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3804 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3805 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3806 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3807 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3808 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3809 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3810 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3811 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3812 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3813 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3814 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3815 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3816 */
} /* line 3816 */
  sim_icache_fetch(2672 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) compress_14293Xbuf); /* line 3818 */
   __MOV(reg_r0_3, 0); /* line 3819 */
} /* line 3819 */
l_L181X3: ;/* line 3822 */
__LABEL(l_L181X3);
  sim_icache_fetch(2675 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3823 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3824 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3825 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3826 */
   __ADD_CYCLES(1);
} /* line 3826 */
  sim_icache_fetch(2681 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3828 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3829 */
} /* line 3829 */
  sim_icache_fetch(2683 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3831 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3832 */
} /* line 3832 */
  sim_icache_fetch(2685 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3834 */
} /* line 3834 */
  sim_icache_fetch(2686 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3836 */
} /* line 3836 */
  sim_icache_fetch(2687 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3838 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3839 */
} /* line 3839 */
  sim_icache_fetch(2689 + t_thisfile.offset, 1);
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
} /* line 3841 */
  sim_icache_fetch(2690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3843 */
} /* line 3843 */
  sim_icache_fetch(2692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3845 */
} /* line 3845 */
  sim_icache_fetch(2693 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3847 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3848 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3849 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3850 */
   __ADD_CYCLES(1);
} /* line 3850 */
  sim_icache_fetch(2699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3852 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3853 */
} /* line 3853 */
  sim_icache_fetch(2701 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3855 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3856 */
} /* line 3856 */
  sim_icache_fetch(2703 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3858 */
} /* line 3858 */
  sim_icache_fetch(2704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3860 */
} /* line 3860 */
  sim_icache_fetch(2705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3862 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3863 */
} /* line 3863 */
  sim_icache_fetch(2707 + t_thisfile.offset, 1);
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
} /* line 3865 */
  sim_icache_fetch(2708 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3867 */
} /* line 3867 */
  sim_icache_fetch(2710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3869 */
} /* line 3869 */
  sim_icache_fetch(2711 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3871 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3872 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3873 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3874 */
   __ADD_CYCLES(1);
} /* line 3874 */
  sim_icache_fetch(2717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3876 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3877 */
} /* line 3877 */
  sim_icache_fetch(2719 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3879 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3880 */
} /* line 3880 */
  sim_icache_fetch(2721 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3882 */
} /* line 3882 */
  sim_icache_fetch(2722 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3884 */
} /* line 3884 */
  sim_icache_fetch(2723 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3886 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3887 */
} /* line 3887 */
  sim_icache_fetch(2725 + t_thisfile.offset, 1);
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
} /* line 3889 */
  sim_icache_fetch(2726 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3891 */
} /* line 3891 */
  sim_icache_fetch(2728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3893 */
} /* line 3893 */
  sim_icache_fetch(2729 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3895 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3896 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3897 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3898 */
   __ADD_CYCLES(1);
} /* line 3898 */
  sim_icache_fetch(2735 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3900 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3901 */
} /* line 3901 */
  sim_icache_fetch(2737 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3903 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3904 */
} /* line 3904 */
  sim_icache_fetch(2739 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3906 */
} /* line 3906 */
  sim_icache_fetch(2740 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3908 */
} /* line 3908 */
  sim_icache_fetch(2741 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3910 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3911 */
} /* line 3911 */
  sim_icache_fetch(2743 + t_thisfile.offset, 1);
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
} /* line 3913 */
  sim_icache_fetch(2744 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3915 */
} /* line 3915 */
  sim_icache_fetch(2746 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3917 */
} /* line 3917 */
  sim_icache_fetch(2747 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3919 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3920 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3921 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3922 */
   __ADD_CYCLES(1);
} /* line 3922 */
  sim_icache_fetch(2753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3924 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3925 */
} /* line 3925 */
  sim_icache_fetch(2755 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3927 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3928 */
} /* line 3928 */
  sim_icache_fetch(2757 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3930 */
} /* line 3930 */
  sim_icache_fetch(2758 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3932 */
} /* line 3932 */
  sim_icache_fetch(2759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 3934 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3935 */
} /* line 3935 */
  sim_icache_fetch(2761 + t_thisfile.offset, 1);
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
} /* line 3937 */
  sim_icache_fetch(2762 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3939 */
} /* line 3939 */
  sim_icache_fetch(2764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3941 */
} /* line 3941 */
  sim_icache_fetch(2765 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3943 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3944 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3945 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3946 */
   __ADD_CYCLES(1);
} /* line 3946 */
  sim_icache_fetch(2771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3948 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3949 */
} /* line 3949 */
  sim_icache_fetch(2773 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3951 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3952 */
} /* line 3952 */
  sim_icache_fetch(2775 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3954 */
} /* line 3954 */
  sim_icache_fetch(2776 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3956 */
} /* line 3956 */
  sim_icache_fetch(2777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 3958 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3959 */
} /* line 3959 */
  sim_icache_fetch(2779 + t_thisfile.offset, 1);
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
} /* line 3961 */
  sim_icache_fetch(2780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3963 */
} /* line 3963 */
  sim_icache_fetch(2782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3965 */
} /* line 3965 */
  sim_icache_fetch(2783 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3967 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3968 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3969 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3970 */
   __ADD_CYCLES(1);
} /* line 3970 */
  sim_icache_fetch(2789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3972 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3973 */
} /* line 3973 */
  sim_icache_fetch(2791 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3975 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3976 */
} /* line 3976 */
  sim_icache_fetch(2793 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3978 */
} /* line 3978 */
  sim_icache_fetch(2794 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3980 */
} /* line 3980 */
  sim_icache_fetch(2795 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 3982 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 3983 */
} /* line 3983 */
  sim_icache_fetch(2797 + t_thisfile.offset, 1);
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
} /* line 3985 */
  sim_icache_fetch(2798 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3987 */
} /* line 3987 */
  sim_icache_fetch(2800 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3989 */
} /* line 3989 */
  sim_icache_fetch(2801 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 3991 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3992 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3993 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3994 */
   __ADD_CYCLES(1);
} /* line 3994 */
  sim_icache_fetch(2807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3996 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3997 */
} /* line 3997 */
  sim_icache_fetch(2809 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3999 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4000 */
} /* line 4000 */
  sim_icache_fetch(2811 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4002 */
} /* line 4002 */
  sim_icache_fetch(2812 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4004 */
} /* line 4004 */
  sim_icache_fetch(2813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4006 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4007 */
} /* line 4007 */
  sim_icache_fetch(2815 + t_thisfile.offset, 1);
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
} /* line 4009 */
  sim_icache_fetch(2816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4011 */
} /* line 4011 */
  sim_icache_fetch(2818 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4013 */
} /* line 4013 */
  sim_icache_fetch(2819 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4015 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4016 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4017 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4018 */
   __ADD_CYCLES(1);
} /* line 4018 */
  sim_icache_fetch(2825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4020 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4021 */
} /* line 4021 */
  sim_icache_fetch(2827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4023 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4024 */
} /* line 4024 */
  sim_icache_fetch(2829 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4026 */
} /* line 4026 */
  sim_icache_fetch(2830 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4028 */
} /* line 4028 */
  sim_icache_fetch(2831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4030 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4031 */
} /* line 4031 */
  sim_icache_fetch(2833 + t_thisfile.offset, 1);
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
} /* line 4033 */
  sim_icache_fetch(2834 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4035 */
} /* line 4035 */
  sim_icache_fetch(2836 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4037 */
} /* line 4037 */
  sim_icache_fetch(2837 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4039 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4040 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4041 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4042 */
   __ADD_CYCLES(1);
} /* line 4042 */
  sim_icache_fetch(2843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4044 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4045 */
} /* line 4045 */
  sim_icache_fetch(2845 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4047 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4048 */
} /* line 4048 */
  sim_icache_fetch(2847 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4050 */
} /* line 4050 */
  sim_icache_fetch(2848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4052 */
} /* line 4052 */
  sim_icache_fetch(2849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4054 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4055 */
} /* line 4055 */
  sim_icache_fetch(2851 + t_thisfile.offset, 1);
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
} /* line 4057 */
  sim_icache_fetch(2852 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4059 */
} /* line 4059 */
  sim_icache_fetch(2854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4061 */
} /* line 4061 */
  sim_icache_fetch(2855 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4063 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4064 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4065 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4066 */
   __ADD_CYCLES(1);
} /* line 4066 */
  sim_icache_fetch(2861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4068 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4069 */
} /* line 4069 */
  sim_icache_fetch(2863 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4071 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4072 */
} /* line 4072 */
  sim_icache_fetch(2865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4074 */
} /* line 4074 */
  sim_icache_fetch(2866 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4076 */
} /* line 4076 */
  sim_icache_fetch(2867 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4078 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4079 */
} /* line 4079 */
  sim_icache_fetch(2869 + t_thisfile.offset, 1);
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
} /* line 4081 */
  sim_icache_fetch(2870 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4083 */
} /* line 4083 */
  sim_icache_fetch(2872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4085 */
} /* line 4085 */
  sim_icache_fetch(2873 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4087 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4088 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4089 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4090 */
   __ADD_CYCLES(1);
} /* line 4090 */
  sim_icache_fetch(2879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4092 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4093 */
} /* line 4093 */
  sim_icache_fetch(2881 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4095 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4096 */
} /* line 4096 */
  sim_icache_fetch(2883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4098 */
} /* line 4098 */
  sim_icache_fetch(2884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4100 */
} /* line 4100 */
  sim_icache_fetch(2885 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4102 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4103 */
} /* line 4103 */
  sim_icache_fetch(2887 + t_thisfile.offset, 1);
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
} /* line 4105 */
  sim_icache_fetch(2888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4107 */
} /* line 4107 */
  sim_icache_fetch(2890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4109 */
} /* line 4109 */
  sim_icache_fetch(2891 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4111 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4112 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4113 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4114 */
   __ADD_CYCLES(1);
} /* line 4114 */
  sim_icache_fetch(2897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4116 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4117 */
} /* line 4117 */
  sim_icache_fetch(2899 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4119 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4120 */
} /* line 4120 */
  sim_icache_fetch(2901 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4122 */
} /* line 4122 */
  sim_icache_fetch(2902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4124 */
} /* line 4124 */
  sim_icache_fetch(2903 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4126 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4127 */
} /* line 4127 */
  sim_icache_fetch(2905 + t_thisfile.offset, 1);
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
} /* line 4129 */
  sim_icache_fetch(2906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4131 */
} /* line 4131 */
  sim_icache_fetch(2908 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4133 */
} /* line 4133 */
  sim_icache_fetch(2909 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4135 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4136 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4137 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4138 */
   __ADD_CYCLES(1);
} /* line 4138 */
  sim_icache_fetch(2915 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4140 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4141 */
} /* line 4141 */
  sim_icache_fetch(2917 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4143 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4144 */
} /* line 4144 */
  sim_icache_fetch(2919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4146 */
} /* line 4146 */
  sim_icache_fetch(2920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4148 */
} /* line 4148 */
  sim_icache_fetch(2921 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4150 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4151 */
} /* line 4151 */
  sim_icache_fetch(2923 + t_thisfile.offset, 1);
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
} /* line 4153 */
  sim_icache_fetch(2924 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4155 */
} /* line 4155 */
  sim_icache_fetch(2926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4157 */
} /* line 4157 */
  sim_icache_fetch(2927 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4159 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4160 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4161 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4162 */
   __ADD_CYCLES(1);
} /* line 4162 */
  sim_icache_fetch(2933 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4164 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4165 */
} /* line 4165 */
  sim_icache_fetch(2935 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4167 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4168 */
} /* line 4168 */
  sim_icache_fetch(2937 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4170 */
} /* line 4170 */
  sim_icache_fetch(2938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4172 */
} /* line 4172 */
  sim_icache_fetch(2939 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4174 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4175 */
} /* line 4175 */
  sim_icache_fetch(2941 + t_thisfile.offset, 1);
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
} /* line 4177 */
  sim_icache_fetch(2942 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4179 */
} /* line 4179 */
  sim_icache_fetch(2944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4181 */
} /* line 4181 */
  sim_icache_fetch(2945 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4183 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4184 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4185 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4186 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4187 */
   __ADD_CYCLES(1);
} /* line 4187 */
  sim_icache_fetch(2952 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4189 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4190 */
} /* line 4190 */
  sim_icache_fetch(2954 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4192 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4193 */
} /* line 4193 */
  sim_icache_fetch(2956 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4195 */
} /* line 4195 */
  sim_icache_fetch(2957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4197 */
} /* line 4197 */
  sim_icache_fetch(2958 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4199 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4200 */
} /* line 4200 */
  sim_icache_fetch(2960 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L197X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4202 */
  sim_icache_fetch(2961 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4204 */
} /* line 4204 */
  sim_icache_fetch(2963 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4206 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4207 */
l_L197X3: ;/* line 4210 */
__LABEL(l_L197X3);
  sim_icache_fetch(2965 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4211 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4212 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4213 */
   __ADD_CYCLES(1);
} /* line 4213 */
  sim_icache_fetch(2970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4215 */
} /* line 4215 */
  sim_icache_fetch(2971 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4217 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4218 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4219 */
l_L196X3: ;/* line 4222 */
__LABEL(l_L196X3);
  sim_icache_fetch(2974 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4223 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4224 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4225 */
   __ADD_CYCLES(1);
} /* line 4225 */
  sim_icache_fetch(2979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4227 */
} /* line 4227 */
  sim_icache_fetch(2980 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4229 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4230 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4231 */
l_L195X3: ;/* line 4234 */
__LABEL(l_L195X3);
  sim_icache_fetch(2983 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4235 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4236 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4237 */
   __ADD_CYCLES(1);
} /* line 4237 */
  sim_icache_fetch(2988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4239 */
} /* line 4239 */
  sim_icache_fetch(2989 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4241 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4242 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4243 */
l_L194X3: ;/* line 4246 */
__LABEL(l_L194X3);
  sim_icache_fetch(2992 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4247 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4248 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4249 */
   __ADD_CYCLES(1);
} /* line 4249 */
  sim_icache_fetch(2997 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4251 */
} /* line 4251 */
  sim_icache_fetch(2998 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4253 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4254 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4255 */
l_L193X3: ;/* line 4258 */
__LABEL(l_L193X3);
  sim_icache_fetch(3001 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4259 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4260 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4261 */
   __ADD_CYCLES(1);
} /* line 4261 */
  sim_icache_fetch(3006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4263 */
} /* line 4263 */
  sim_icache_fetch(3007 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4265 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4266 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4267 */
l_L192X3: ;/* line 4270 */
__LABEL(l_L192X3);
  sim_icache_fetch(3010 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4271 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4272 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4273 */
   __ADD_CYCLES(1);
} /* line 4273 */
  sim_icache_fetch(3015 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4275 */
} /* line 4275 */
  sim_icache_fetch(3016 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4277 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4278 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4279 */
l_L191X3: ;/* line 4282 */
__LABEL(l_L191X3);
  sim_icache_fetch(3019 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4283 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4284 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4285 */
   __ADD_CYCLES(1);
} /* line 4285 */
  sim_icache_fetch(3024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4287 */
} /* line 4287 */
  sim_icache_fetch(3025 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4289 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4290 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4291 */
l_L190X3: ;/* line 4294 */
__LABEL(l_L190X3);
  sim_icache_fetch(3028 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4295 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4296 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4297 */
   __ADD_CYCLES(1);
} /* line 4297 */
  sim_icache_fetch(3033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4299 */
} /* line 4299 */
  sim_icache_fetch(3034 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4301 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4302 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4303 */
l_L189X3: ;/* line 4306 */
__LABEL(l_L189X3);
  sim_icache_fetch(3037 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4307 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4308 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4309 */
   __ADD_CYCLES(1);
} /* line 4309 */
  sim_icache_fetch(3042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4311 */
} /* line 4311 */
  sim_icache_fetch(3043 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4313 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4314 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4315 */
l_L188X3: ;/* line 4318 */
__LABEL(l_L188X3);
  sim_icache_fetch(3046 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4319 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4320 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4321 */
   __ADD_CYCLES(1);
} /* line 4321 */
  sim_icache_fetch(3051 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4323 */
} /* line 4323 */
  sim_icache_fetch(3052 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4325 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4326 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4327 */
l_L187X3: ;/* line 4330 */
__LABEL(l_L187X3);
  sim_icache_fetch(3055 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4331 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4332 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4333 */
   __ADD_CYCLES(1);
} /* line 4333 */
  sim_icache_fetch(3060 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4335 */
} /* line 4335 */
  sim_icache_fetch(3061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4337 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4338 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4339 */
l_L186X3: ;/* line 4342 */
__LABEL(l_L186X3);
  sim_icache_fetch(3064 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4343 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4344 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4345 */
   __ADD_CYCLES(1);
} /* line 4345 */
  sim_icache_fetch(3069 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4347 */
} /* line 4347 */
  sim_icache_fetch(3070 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4349 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4350 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4351 */
l_L185X3: ;/* line 4354 */
__LABEL(l_L185X3);
  sim_icache_fetch(3073 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4355 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4356 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4357 */
   __ADD_CYCLES(1);
} /* line 4357 */
  sim_icache_fetch(3078 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4359 */
} /* line 4359 */
  sim_icache_fetch(3079 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4361 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4362 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4363 */
l_L184X3: ;/* line 4366 */
__LABEL(l_L184X3);
  sim_icache_fetch(3082 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4367 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4368 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4369 */
   __ADD_CYCLES(1);
} /* line 4369 */
  sim_icache_fetch(3087 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4371 */
} /* line 4371 */
  sim_icache_fetch(3088 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4373 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4374 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4375 */
l_L183X3: ;/* line 4378 */
__LABEL(l_L183X3);
  sim_icache_fetch(3091 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4379 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4380 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4381 */
   __ADD_CYCLES(1);
} /* line 4381 */
  sim_icache_fetch(3096 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4383 */
} /* line 4383 */
  sim_icache_fetch(3097 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4385 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4386 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4387 */
l_L182X3: ;/* line 4390 */
__LABEL(l_L182X3);
  sim_icache_fetch(3100 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4391 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_14293Xoffset,0,4)); /* line 4392 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4393 */
   __ADD_CYCLES(1);
} /* line 4393 */
  sim_icache_fetch(3105 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4395 */
} /* line 4395 */
  sim_icache_fetch(3106 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4397 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4398 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4399 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 332: goto l_L168X3;
    case 333: goto l_L169X3;
    case 334: goto l_L171X3;
    case 335: goto l_L172X3;
    case 336: goto l_L170X3;
    case 337: goto l_L175X3;
    case 338: goto l_L176X3;
    case 339: goto l_L174X3;
    case 340: goto l_L177X3;
    case 341: goto l_L178X3;
    case 342: goto l_L173X3;
    case 343: goto l_L167X3;
    case 344: goto l_L180X3;
    case 345: goto l_L179X3;
    case 346: goto l_L181X3;
    case 347: goto l_L197X3;
    case 348: goto l_L196X3;
    case 349: goto l_L195X3;
    case 350: goto l_L194X3;
    case 351: goto l_L193X3;
    case 352: goto l_L192X3;
    case 353: goto l_L191X3;
    case 354: goto l_L190X3;
    case 355: goto l_L189X3;
    case 356: goto l_L188X3;
    case 357: goto l_L187X3;
    case 358: goto l_L186X3;
    case 359: goto l_L185X3;
    case 360: goto l_L184X3;
    case 361: goto l_L183X3;
    case 362: goto l_L182X3;
    case 363:
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
  reg_l0_0 = (417 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3109 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4415 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4416 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4417 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4418 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4419 */
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4420 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4421 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4422 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4423 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4424 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4425 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4426 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4427 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4428 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4429 */
} /* line 4429 */
  sim_icache_fetch(3125 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4431 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4432 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4433 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4434 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4435 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4436 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4437 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4438 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4439 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4440 */
} /* line 4440 */
l_L198X3: ;/* line 4443 */
__LABEL(l_L198X3);
  sim_icache_fetch(3139 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4444 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4445 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4446 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4447 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4448 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4449 */
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4450 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4451 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4452 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4453 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4454 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4455 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4456 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4457 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4458 */
} /* line 4458 */
  sim_icache_fetch(3154 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4460 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4461 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4462 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4463 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L199X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4464 */
  sim_icache_fetch(3159 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4466 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4467 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4468 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4469 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4470 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4471 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4472 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4473 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4474 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4475 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4476 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4477 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4478 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4479 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4480 */
} /* line 4480 */
  sim_icache_fetch(3174 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4482 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4483 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4484 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4485 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4486 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4487 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4488 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4489 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4490 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4491 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4492 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4493 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4494 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4495 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4496 */
} /* line 4496 */
  sim_icache_fetch(3189 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4498 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4499 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4500 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4501 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4502 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4503 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4504 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4505 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4506 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4507 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4508 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4509 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4510 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4511 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4512 */
} /* line 4512 */
  sim_icache_fetch(3204 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4514 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4515 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4516 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4517 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4518 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4519 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4520 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4521 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4522 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4523 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4524 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4525 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4526 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4527 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4528 */
} /* line 4528 */
  sim_icache_fetch(3219 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4530 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4531 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4532 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4533 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4534 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4535 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4536 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4537 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4538 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4539 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4540 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4541 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4542 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4543 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4544 */
} /* line 4544 */
  sim_icache_fetch(3234 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4546 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4547 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4548 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4549 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4550 */
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4551 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4552 */
   __GOTO(l_L198X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L198X3;
} /* line 4553 */
l_L199X3: ;/* line 4556 */
__LABEL(l_L199X3);
  sim_icache_fetch(3242 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4557 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4558 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4559 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4560 */
   __ADD_CYCLES(1);
} /* line 4560 */
  sim_icache_fetch(3248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4562 */
} /* line 4562 */
  sim_icache_fetch(3249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4564 */
} /* line 4564 */
		 /* line 4565 */
  sim_icache_fetch(3251 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4567 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (417 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4568 */
l_lr_266: ;/* line 4568 */
__LABEL(l_lr_266);
  sim_icache_fetch(3255 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_2, t__i32_0); /* line 4570 */
   __MOV(reg_r0_4, t__i32_0); /* line 4571 */
   __CMPEQ(reg_b0_0, t__i32_0, (unsigned int) -1); /* line 4572 */
   __MOV(reg_r0_3, 0); /* line 4573 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4574 */
   __MOV(reg_r0_5, t__i32_0); /* line 4575 */
} /* line 4575 */
  sim_icache_fetch(3261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L200X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4577 */
  sim_icache_fetch(3262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4580 */
l_L200X3: ;/* line 4583 */
__LABEL(l_L200X3);
  sim_icache_fetch(3263 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4584 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4585 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4586 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4587 */
} /* line 4587 */
  sim_icache_fetch(3268 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4589 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4590 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4591 */
} /* line 4591 */
  sim_icache_fetch(3272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4593 */
} /* line 4593 */
  sim_icache_fetch(3273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4595 */
} /* line 4595 */
  sim_icache_fetch(3275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4597 */
} /* line 4597 */
l_L201X3: ;/* line 4600 */
__LABEL(l_L201X3);
		 /* line 4600 */
  sim_icache_fetch(3276 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (417 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4602 */
l_lr_270: ;/* line 4602 */
__LABEL(l_lr_270);
  sim_icache_fetch(3278 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4604 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4605 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4606 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4607 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4608 */
} /* line 4608 */
  sim_icache_fetch(3285 + t_thisfile.offset, 1);
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
} /* line 4610 */
  sim_icache_fetch(3286 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4612 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4613 */
} /* line 4613 */
  sim_icache_fetch(3289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L203X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4615 */
l_L204X3: ;/* line 4618 */
__LABEL(l_L204X3);
  sim_icache_fetch(3290 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4619 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4620 */
} /* line 4620 */
  sim_icache_fetch(3292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L205X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4622 */
  sim_icache_fetch(3293 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4624 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4625 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4626 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4627 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4628 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4629 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4630 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4631 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4632 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4633 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4634 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4635 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4636 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4637 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4638 */
} /* line 4638 */
  sim_icache_fetch(3308 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4640 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4641 */
   __GOTO(l_L204X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L204X3;
} /* line 4642 */
l_L205X3: ;/* line 4645 */
__LABEL(l_L205X3);
  sim_icache_fetch(3311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4646 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4647 */
} /* line 4647 */
		 /* line 4648 */
  sim_icache_fetch(3314 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4650 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4651 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (417 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4652 */
l_lr_274: ;/* line 4652 */
__LABEL(l_lr_274);
  sim_icache_fetch(3320 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4654 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4655 */
} /* line 4655 */
  sim_icache_fetch(3322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L202X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4657 */
l_L203X3: ;/* line 4660 */
__LABEL(l_L203X3);
  sim_icache_fetch(3323 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4661 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4662 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4663 */
   __ADD_CYCLES(1);
} /* line 4663 */
  sim_icache_fetch(3327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4665 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4666 */
} /* line 4666 */
  sim_icache_fetch(3329 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4668 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4669 */
  sim_icache_fetch(3332 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4671 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4672 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4673 */
} /* line 4673 */
l_L207X3: ;/* line 4676 */
__LABEL(l_L207X3);
  sim_icache_fetch(3335 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4677 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4678 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4679 */
} /* line 4679 */
  sim_icache_fetch(3340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4681 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4682 */
  sim_icache_fetch(3342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4684 */
} /* line 4684 */
  sim_icache_fetch(3343 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4686 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4687 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4688 */
} /* line 4688 */
  sim_icache_fetch(3348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4690 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4691 */
  sim_icache_fetch(3350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4693 */
} /* line 4693 */
  sim_icache_fetch(3351 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4695 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4696 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4697 */
} /* line 4697 */
  sim_icache_fetch(3356 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4699 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4700 */
  sim_icache_fetch(3358 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4702 */
} /* line 4702 */
  sim_icache_fetch(3359 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4704 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4705 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4706 */
} /* line 4706 */
  sim_icache_fetch(3364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4708 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4709 */
  sim_icache_fetch(3366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4711 */
} /* line 4711 */
  sim_icache_fetch(3367 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4713 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4714 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4715 */
} /* line 4715 */
  sim_icache_fetch(3372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4717 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4718 */
  sim_icache_fetch(3374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4720 */
} /* line 4720 */
  sim_icache_fetch(3375 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4722 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4723 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4724 */
} /* line 4724 */
  sim_icache_fetch(3380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4726 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4727 */
  sim_icache_fetch(3382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4729 */
} /* line 4729 */
  sim_icache_fetch(3383 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4731 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4732 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4733 */
} /* line 4733 */
  sim_icache_fetch(3388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4735 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4736 */
  sim_icache_fetch(3390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4738 */
} /* line 4738 */
  sim_icache_fetch(3391 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4740 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4741 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4742 */
} /* line 4742 */
  sim_icache_fetch(3396 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4744 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4745 */
  sim_icache_fetch(3398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4747 */
} /* line 4747 */
  sim_icache_fetch(3399 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4749 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4750 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4751 */
} /* line 4751 */
  sim_icache_fetch(3404 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4753 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4754 */
  sim_icache_fetch(3406 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4756 */
} /* line 4756 */
  sim_icache_fetch(3407 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4758 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4759 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4760 */
} /* line 4760 */
  sim_icache_fetch(3412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4762 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4763 */
  sim_icache_fetch(3414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4765 */
} /* line 4765 */
  sim_icache_fetch(3415 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4767 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4768 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4769 */
} /* line 4769 */
  sim_icache_fetch(3420 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4771 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4772 */
  sim_icache_fetch(3422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4774 */
} /* line 4774 */
  sim_icache_fetch(3423 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4776 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4777 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4778 */
} /* line 4778 */
  sim_icache_fetch(3428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4780 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4781 */
  sim_icache_fetch(3430 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4783 */
} /* line 4783 */
  sim_icache_fetch(3431 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4785 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4786 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4787 */
} /* line 4787 */
  sim_icache_fetch(3436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4789 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4790 */
  sim_icache_fetch(3438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4792 */
} /* line 4792 */
  sim_icache_fetch(3439 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4794 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4795 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4796 */
} /* line 4796 */
  sim_icache_fetch(3444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4798 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4799 */
  sim_icache_fetch(3446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4801 */
} /* line 4801 */
  sim_icache_fetch(3447 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4803 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4804 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4805 */
} /* line 4805 */
  sim_icache_fetch(3452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4807 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4808 */
  sim_icache_fetch(3454 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4810 */
} /* line 4810 */
  sim_icache_fetch(3455 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4812 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4813 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4814 */
} /* line 4814 */
  sim_icache_fetch(3460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4816 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4817 */
  sim_icache_fetch(3462 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4819 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4820 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 4821 */
l_L223X3: ;/* line 4824 */
__LABEL(l_L223X3);
  sim_icache_fetch(3465 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4825 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4826 */
} /* line 4826 */
  sim_icache_fetch(3467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4828 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 4829 */
l_L225X3: ;/* line 4832 */
__LABEL(l_L225X3);
  sim_icache_fetch(3469 + t_thisfile.offset, 24);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __MOV(reg_r0_5, reg_r0_3); /* line 4833 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4834 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4835 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4836 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4837 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4838 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4839 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4840 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4841 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4842 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4843 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4844 */
   __ADD(reg_r0_22, reg_r0_19, (unsigned int) -16); /* line 4845 */
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) -16); /* line 4846 */
   __ADD(reg_r0_24, reg_r0_17, (unsigned int) -16); /* line 4847 */
} /* line 4847 */
  sim_icache_fetch(3493 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __MOV(reg_r0_37, reg_r0_20); /* line 4849 */
   __ADD(reg_r0_25, reg_r0_16, (unsigned int) -16); /* line 4850 */
   __ADD(reg_r0_26, reg_r0_15, (unsigned int) -16); /* line 4851 */
   __ADD(reg_r0_27, reg_r0_14, (unsigned int) -16); /* line 4852 */
   __ADD(reg_r0_28, reg_r0_13, (unsigned int) -16); /* line 4853 */
   __ADD(reg_r0_29, reg_r0_12, (unsigned int) -16); /* line 4854 */
   __ADD(reg_r0_30, reg_r0_11, (unsigned int) -16); /* line 4855 */
   __ADD(reg_r0_31, reg_r0_10, (unsigned int) -16); /* line 4856 */
   __ADD(reg_r0_32, reg_r0_9, (unsigned int) -16); /* line 4857 */
   __ADD(reg_r0_33, reg_r0_8, (unsigned int) -16); /* line 4858 */
   __ADD(reg_r0_34, reg_r0_7, (unsigned int) -16); /* line 4859 */
   __ADD(reg_r0_35, reg_r0_6, (unsigned int) -16); /* line 4860 */
   __ADD(reg_r0_36, reg_r0_20, (unsigned int) -16); /* line 4861 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) -16); /* line 4862 */
} /* line 4862 */
  sim_icache_fetch(3507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4864 */
   __MOV(reg_r0_40, reg_r0_36); /* line 4865 */
} /* line 4865 */
  sim_icache_fetch(3509 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4867 */
} /* line 4867 */
  sim_icache_fetch(3511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4869 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4870 */
  sim_icache_fetch(3513 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4872 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4873 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4874 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4875 */
   __ADD_CYCLES(1);
} /* line 4875 */
  sim_icache_fetch(3519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4877 */
} /* line 4877 */
  sim_icache_fetch(3520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4879 */
} /* line 4879 */
  sim_icache_fetch(3522 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4881 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4882 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4883 */
  sim_icache_fetch(3526 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4885 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4886 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4887 */
   __ADD(reg_r0_6, reg_r0_35, (unsigned int) -16); /* line 4888 */
   __MFB(reg_r0_4, t__i32_0); /* line 4889 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4890 */
   __ADD_CYCLES(1);
} /* line 4890 */
  sim_icache_fetch(3534 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4892 */
} /* line 4892 */
  sim_icache_fetch(3535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4894 */
} /* line 4894 */
  sim_icache_fetch(3537 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4896 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4897 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4898 */
  sim_icache_fetch(3540 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4900 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4901 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4902 */
   __ADD(reg_r0_7, reg_r0_34, (unsigned int) -16); /* line 4903 */
   __MFB(reg_r0_4, t__i32_0); /* line 4904 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4905 */
   __ADD_CYCLES(1);
} /* line 4905 */
  sim_icache_fetch(3548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4907 */
} /* line 4907 */
  sim_icache_fetch(3549 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4909 */
} /* line 4909 */
  sim_icache_fetch(3551 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4911 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4912 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4913 */
  sim_icache_fetch(3554 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4915 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4916 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4917 */
   __ADD(reg_r0_8, reg_r0_33, (unsigned int) -16); /* line 4918 */
   __MFB(reg_r0_4, t__i32_0); /* line 4919 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4920 */
   __ADD_CYCLES(1);
} /* line 4920 */
  sim_icache_fetch(3562 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4922 */
} /* line 4922 */
  sim_icache_fetch(3563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4924 */
} /* line 4924 */
  sim_icache_fetch(3565 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 4926 */
   __MTB(reg_b0_4, reg_r0_4); /* line 4927 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4928 */
  sim_icache_fetch(3568 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 4930 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4931 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 4932 */
   __ADD(reg_r0_9, reg_r0_32, (unsigned int) -16); /* line 4933 */
   __MFB(reg_r0_4, t__i32_0); /* line 4934 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4935 */
   __ADD_CYCLES(1);
} /* line 4935 */
  sim_icache_fetch(3576 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4937 */
} /* line 4937 */
  sim_icache_fetch(3577 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4939 */
} /* line 4939 */
  sim_icache_fetch(3579 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 4941 */
   __MTB(reg_b0_5, reg_r0_4); /* line 4942 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4943 */
  sim_icache_fetch(3582 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 4945 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4946 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 4947 */
   __ADD(reg_r0_10, reg_r0_31, (unsigned int) -16); /* line 4948 */
   __MFB(reg_r0_4, t__i32_0); /* line 4949 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4950 */
   __ADD_CYCLES(1);
} /* line 4950 */
  sim_icache_fetch(3590 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4952 */
} /* line 4952 */
  sim_icache_fetch(3591 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4954 */
} /* line 4954 */
  sim_icache_fetch(3593 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 4956 */
   __MTB(reg_b0_6, reg_r0_4); /* line 4957 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4958 */
  sim_icache_fetch(3596 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 4960 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4961 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 4962 */
   __ADD(reg_r0_11, reg_r0_30, (unsigned int) -16); /* line 4963 */
   __MFB(reg_r0_4, t__i32_0); /* line 4964 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4965 */
   __ADD_CYCLES(1);
} /* line 4965 */
  sim_icache_fetch(3604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4967 */
} /* line 4967 */
  sim_icache_fetch(3605 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4969 */
} /* line 4969 */
  sim_icache_fetch(3607 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 4971 */
   __MTB(reg_b0_7, reg_r0_4); /* line 4972 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4973 */
  sim_icache_fetch(3610 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 4975 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4976 */
   __CMPLEU(reg_b0_7, reg_r0_37, ((unsigned int) htab + (unsigned int) 4096)); /* line 4977 */
   __ADD(reg_r0_12, reg_r0_29, (unsigned int) -16); /* line 4978 */
   __MFB(reg_r0_4, t__i32_0); /* line 4979 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4980 */
   __ADD_CYCLES(1);
} /* line 4980 */
  sim_icache_fetch(3618 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 4982 */
} /* line 4982 */
  sim_icache_fetch(3619 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 4984 */
} /* line 4984 */
  sim_icache_fetch(3621 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 4986 */
   __MTB(reg_b0_0, reg_r0_4); /* line 4987 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4988 */
  sim_icache_fetch(3624 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 4990 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4991 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4992 */
   __ADD(reg_r0_13, reg_r0_28, (unsigned int) -16); /* line 4993 */
   __MFB(reg_r0_4, t__i32_0); /* line 4994 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4995 */
   __ADD_CYCLES(1);
} /* line 4995 */
  sim_icache_fetch(3632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 4997 */
} /* line 4997 */
  sim_icache_fetch(3633 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 4999 */
} /* line 4999 */
  sim_icache_fetch(3635 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5001 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5002 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5003 */
  sim_icache_fetch(3638 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5005 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5006 */
   __CMPLEU(reg_b0_1, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5007 */
   __ADD(reg_r0_14, reg_r0_27, (unsigned int) -16); /* line 5008 */
   __MFB(reg_r0_4, t__i32_0); /* line 5009 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5010 */
   __ADD_CYCLES(1);
} /* line 5010 */
  sim_icache_fetch(3646 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5012 */
} /* line 5012 */
  sim_icache_fetch(3647 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5014 */
} /* line 5014 */
  sim_icache_fetch(3649 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5016 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5017 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5018 */
  sim_icache_fetch(3652 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5020 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5021 */
   __CMPLEU(reg_b0_2, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5022 */
   __ADD(reg_r0_15, reg_r0_26, (unsigned int) -16); /* line 5023 */
   __MFB(reg_r0_4, t__i32_0); /* line 5024 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5025 */
   __ADD_CYCLES(1);
} /* line 5025 */
  sim_icache_fetch(3660 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5027 */
} /* line 5027 */
  sim_icache_fetch(3661 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5029 */
} /* line 5029 */
  sim_icache_fetch(3663 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5031 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5032 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5033 */
  sim_icache_fetch(3666 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5035 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5036 */
   __CMPLEU(reg_b0_3, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5037 */
   __ADD(reg_r0_16, reg_r0_25, (unsigned int) -16); /* line 5038 */
   __MFB(reg_r0_4, t__i32_0); /* line 5039 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5040 */
   __ADD_CYCLES(1);
} /* line 5040 */
  sim_icache_fetch(3674 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5042 */
} /* line 5042 */
  sim_icache_fetch(3675 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5044 */
} /* line 5044 */
  sim_icache_fetch(3677 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5046 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5047 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5048 */
  sim_icache_fetch(3680 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5050 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5051 */
   __CMPLEU(reg_b0_4, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5052 */
   __ADD(reg_r0_17, reg_r0_24, (unsigned int) -16); /* line 5053 */
   __MFB(reg_r0_4, t__i32_0); /* line 5054 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5055 */
   __ADD_CYCLES(1);
} /* line 5055 */
  sim_icache_fetch(3688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5057 */
} /* line 5057 */
  sim_icache_fetch(3689 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5059 */
} /* line 5059 */
  sim_icache_fetch(3691 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5061 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5062 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5063 */
  sim_icache_fetch(3694 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5065 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5066 */
   __CMPLEU(reg_b0_5, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5067 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) -16); /* line 5068 */
   __MFB(reg_r0_4, t__i32_0); /* line 5069 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5070 */
   __ADD_CYCLES(1);
} /* line 5070 */
  sim_icache_fetch(3702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5072 */
} /* line 5072 */
  sim_icache_fetch(3703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5074 */
} /* line 5074 */
  sim_icache_fetch(3705 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5076 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5077 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5078 */
  sim_icache_fetch(3708 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5080 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5081 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5082 */
   __CMPLEU(reg_b0_6, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5083 */
   __ADD(reg_r0_19, reg_r0_22, (unsigned int) -16); /* line 5084 */
   __MFB(reg_r0_4, t__i32_0); /* line 5085 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5086 */
   __ADD_CYCLES(1);
} /* line 5086 */
  sim_icache_fetch(3717 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5088 */
} /* line 5088 */
  sim_icache_fetch(3718 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5090 */
} /* line 5090 */
  sim_icache_fetch(3720 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5092 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5093 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5094 */
  sim_icache_fetch(3723 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_5, reg_r0_3); /* line 5096 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5097 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5098 */
   __CMPLEU(reg_b0_7, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5099 */
   __ADD(reg_r0_20, reg_r0_36, (unsigned int) -16); /* line 5100 */
   __MOV(reg_r0_3, reg_r0_38); /* line 5101 */
   __MFB(reg_r0_37, t__i32_0); /* line 5102 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5103 */
   __ADD_CYCLES(1);
} /* line 5103 */
  sim_icache_fetch(3733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5105 */
} /* line 5105 */
  sim_icache_fetch(3734 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5107 */
} /* line 5107 */
  sim_icache_fetch(3736 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5109 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5110 */
  sim_icache_fetch(3738 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5112 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5113 */
   __CMPLEU(reg_b0_0, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5114 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5115 */
   __ADD_CYCLES(1);
} /* line 5115 */
  sim_icache_fetch(3744 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5117 */
} /* line 5117 */
  sim_icache_fetch(3745 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5119 */
} /* line 5119 */
  sim_icache_fetch(3747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5121 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5122 */
  sim_icache_fetch(3749 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5124 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5125 */
   __CMPLEU(reg_b0_1, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5126 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5127 */
   __ADD_CYCLES(1);
} /* line 5127 */
  sim_icache_fetch(3755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5129 */
} /* line 5129 */
  sim_icache_fetch(3756 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5131 */
} /* line 5131 */
  sim_icache_fetch(3758 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5133 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5134 */
  sim_icache_fetch(3760 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5136 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5137 */
   __CMPLEU(reg_b0_2, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5138 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5139 */
   __ADD_CYCLES(1);
} /* line 5139 */
  sim_icache_fetch(3766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5141 */
} /* line 5141 */
  sim_icache_fetch(3767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5143 */
} /* line 5143 */
  sim_icache_fetch(3769 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5145 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5146 */
  sim_icache_fetch(3771 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5148 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5149 */
   __CMPLEU(reg_b0_3, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5150 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5151 */
   __ADD_CYCLES(1);
} /* line 5151 */
  sim_icache_fetch(3777 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5153 */
} /* line 5153 */
  sim_icache_fetch(3778 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5155 */
} /* line 5155 */
  sim_icache_fetch(3780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5157 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5158 */
  sim_icache_fetch(3782 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5160 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5161 */
   __CMPLEU(reg_b0_4, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5162 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5163 */
   __ADD_CYCLES(1);
} /* line 5163 */
  sim_icache_fetch(3788 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5165 */
} /* line 5165 */
  sim_icache_fetch(3789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5167 */
} /* line 5167 */
  sim_icache_fetch(3791 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5169 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5170 */
  sim_icache_fetch(3793 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5172 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5173 */
   __CMPLEU(reg_b0_5, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5174 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5175 */
   __ADD_CYCLES(1);
} /* line 5175 */
  sim_icache_fetch(3799 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5177 */
} /* line 5177 */
  sim_icache_fetch(3800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5179 */
} /* line 5179 */
  sim_icache_fetch(3802 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5181 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5182 */
  sim_icache_fetch(3804 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5184 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5185 */
   __CMPLEU(reg_b0_6, reg_r0_22, ((unsigned int) htab + (unsigned int) 4096)); /* line 5186 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5187 */
   __ADD_CYCLES(1);
} /* line 5187 */
  sim_icache_fetch(3810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5189 */
} /* line 5189 */
  sim_icache_fetch(3811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5191 */
} /* line 5191 */
  sim_icache_fetch(3813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5193 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5194 */
  sim_icache_fetch(3815 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5196 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5197 */
   __MTB(reg_b0_7, reg_r0_37); /* line 5198 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5199 */
   __ADD_CYCLES(1);
} /* line 5199 */
  sim_icache_fetch(3820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5201 */
} /* line 5201 */
  sim_icache_fetch(3821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5203 */
} /* line 5203 */
  sim_icache_fetch(3823 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5205 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5206 */
  sim_icache_fetch(3825 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5208 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5209 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5210 */
   __ADD_CYCLES(1);
} /* line 5210 */
  sim_icache_fetch(3829 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5212 */
} /* line 5212 */
  sim_icache_fetch(3830 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5214 */
} /* line 5214 */
  sim_icache_fetch(3832 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5216 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5217 */
  sim_icache_fetch(3834 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5219 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5220 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5221 */
   __ADD_CYCLES(1);
} /* line 5221 */
  sim_icache_fetch(3838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5223 */
} /* line 5223 */
  sim_icache_fetch(3839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5225 */
} /* line 5225 */
  sim_icache_fetch(3841 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5227 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5228 */
  sim_icache_fetch(3843 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5230 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5231 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5232 */
   __ADD_CYCLES(1);
} /* line 5232 */
  sim_icache_fetch(3847 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5234 */
} /* line 5234 */
  sim_icache_fetch(3848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5236 */
} /* line 5236 */
  sim_icache_fetch(3850 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5238 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5239 */
  sim_icache_fetch(3852 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5241 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5242 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5243 */
   __ADD_CYCLES(1);
} /* line 5243 */
  sim_icache_fetch(3856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5245 */
} /* line 5245 */
  sim_icache_fetch(3857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5247 */
} /* line 5247 */
  sim_icache_fetch(3859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5249 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5250 */
  sim_icache_fetch(3861 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5252 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5253 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5254 */
   __ADD_CYCLES(1);
} /* line 5254 */
  sim_icache_fetch(3865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5256 */
} /* line 5256 */
  sim_icache_fetch(3866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5258 */
} /* line 5258 */
  sim_icache_fetch(3868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5260 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5261 */
  sim_icache_fetch(3870 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_22, mem_trace_ld(reg_r0_22,0,1)); /* line 5263 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5264 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5265 */
   __ADD_CYCLES(1);
} /* line 5265 */
  sim_icache_fetch(3874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5267 */
} /* line 5267 */
  sim_icache_fetch(3875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5269 */
} /* line 5269 */
  sim_icache_fetch(3877 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_22); /* line 5271 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5272 */
  sim_icache_fetch(3879 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5274 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5275 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5276 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5277 */
   __ADD_CYCLES(1);
} /* line 5277 */
  sim_icache_fetch(3884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5279 */
} /* line 5279 */
  sim_icache_fetch(3885 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5281 */
} /* line 5281 */
  sim_icache_fetch(3887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5283 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5285 */
  sim_icache_fetch(3889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5287 */
l_L241X3: ;/* line 5290 */
__LABEL(l_L241X3);
  sim_icache_fetch(3890 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5291 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5292 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5293 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5294 */
l_L244X3: ;/* line 5297 */
__LABEL(l_L244X3);
  sim_icache_fetch(3896 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5298 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5299 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5300 */
} /* line 5300 */
  sim_icache_fetch(3901 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5302 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5303 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5304 */
l_L240X3: ;/* line 5307 */
__LABEL(l_L240X3);
  sim_icache_fetch(3905 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5308 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5309 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5310 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5311 */
l_L239X3: ;/* line 5314 */
__LABEL(l_L239X3);
  sim_icache_fetch(3911 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5315 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5316 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5317 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5318 */
l_L238X3: ;/* line 5321 */
__LABEL(l_L238X3);
  sim_icache_fetch(3917 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5322 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5323 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5324 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5325 */
l_L237X3: ;/* line 5328 */
__LABEL(l_L237X3);
  sim_icache_fetch(3923 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5329 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5330 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5331 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5332 */
l_L236X3: ;/* line 5335 */
__LABEL(l_L236X3);
  sim_icache_fetch(3929 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5336 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5337 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5338 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5339 */
l_L235X3: ;/* line 5342 */
__LABEL(l_L235X3);
  sim_icache_fetch(3935 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5343 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5344 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5345 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5346 */
l_L234X3: ;/* line 5349 */
__LABEL(l_L234X3);
  sim_icache_fetch(3941 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5350 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5351 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5352 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5353 */
l_L233X3: ;/* line 5356 */
__LABEL(l_L233X3);
  sim_icache_fetch(3947 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5357 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5358 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5359 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5360 */
l_L232X3: ;/* line 5363 */
__LABEL(l_L232X3);
  sim_icache_fetch(3953 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5364 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5365 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5366 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5367 */
l_L231X3: ;/* line 5370 */
__LABEL(l_L231X3);
  sim_icache_fetch(3959 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5371 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5372 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5373 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5374 */
l_L230X3: ;/* line 5377 */
__LABEL(l_L230X3);
  sim_icache_fetch(3965 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5378 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5379 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5380 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5381 */
l_L229X3: ;/* line 5384 */
__LABEL(l_L229X3);
  sim_icache_fetch(3971 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5385 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5386 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5387 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5388 */
l_L228X3: ;/* line 5391 */
__LABEL(l_L228X3);
  sim_icache_fetch(3977 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5392 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5393 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5394 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5395 */
l_L227X3: ;/* line 5398 */
__LABEL(l_L227X3);
  sim_icache_fetch(3983 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5399 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5400 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5401 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5402 */
l_L226X3: ;/* line 5405 */
__LABEL(l_L226X3);
  sim_icache_fetch(3989 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5406 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5407 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5408 */
} /* line 5408 */
l_L242X3: ;/* line 5410 */
__LABEL(l_L242X3);
  sim_icache_fetch(3994 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5410 */
  sim_icache_fetch(3995 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5412 */
} /* line 5412 */
  sim_icache_fetch(3996 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5414 */
l_L243X3: ;/* line 5416 */
__LABEL(l_L243X3);
  sim_icache_fetch(3997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5417 */
   __GOTO(l_L201X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L201X3;
} /* line 5418 */
l_L222X3: ;/* line 5421 */
__LABEL(l_L222X3);
  sim_icache_fetch(3999 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5422 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5423 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5424 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5425 */
l_L221X3: ;/* line 5428 */
__LABEL(l_L221X3);
  sim_icache_fetch(4003 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5429 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5430 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5431 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5432 */
l_L220X3: ;/* line 5435 */
__LABEL(l_L220X3);
  sim_icache_fetch(4007 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5436 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5437 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5438 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5439 */
l_L219X3: ;/* line 5442 */
__LABEL(l_L219X3);
  sim_icache_fetch(4011 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5443 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5444 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5445 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5446 */
l_L218X3: ;/* line 5449 */
__LABEL(l_L218X3);
  sim_icache_fetch(4015 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5450 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5451 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5452 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5453 */
l_L217X3: ;/* line 5456 */
__LABEL(l_L217X3);
  sim_icache_fetch(4019 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5457 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5458 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5459 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5460 */
l_L216X3: ;/* line 5463 */
__LABEL(l_L216X3);
  sim_icache_fetch(4023 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5464 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5465 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5466 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5467 */
l_L215X3: ;/* line 5470 */
__LABEL(l_L215X3);
  sim_icache_fetch(4027 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5471 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5472 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5473 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5474 */
l_L214X3: ;/* line 5477 */
__LABEL(l_L214X3);
  sim_icache_fetch(4031 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5478 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5479 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5480 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5481 */
l_L213X3: ;/* line 5484 */
__LABEL(l_L213X3);
  sim_icache_fetch(4035 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5485 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5486 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5487 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5488 */
l_L212X3: ;/* line 5491 */
__LABEL(l_L212X3);
  sim_icache_fetch(4039 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5492 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5493 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5494 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5495 */
l_L211X3: ;/* line 5498 */
__LABEL(l_L211X3);
  sim_icache_fetch(4043 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5499 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5500 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5501 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5502 */
l_L210X3: ;/* line 5505 */
__LABEL(l_L210X3);
  sim_icache_fetch(4047 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5506 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5507 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5508 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5509 */
l_L209X3: ;/* line 5512 */
__LABEL(l_L209X3);
  sim_icache_fetch(4051 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5513 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5514 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5515 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5516 */
l_L208X3: ;/* line 5521 */
__LABEL(l_L208X3);
  sim_icache_fetch(4055 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5522 */
} /* line 5522 */
l_L224X3: ;/* line 5524 */
__LABEL(l_L224X3);
  sim_icache_fetch(4056 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5525 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5526 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5527 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5528 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5529 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5530 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5531 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5532 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5533 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5534 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5535 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5536 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5537 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5538 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5539 */
} /* line 5539 */
  sim_icache_fetch(4072 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_5); /* line 5541 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5542 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5543 */
} /* line 5543 */
  sim_icache_fetch(4075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5545 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5546 */
l_L206X3: ;/* line 5549 */
__LABEL(l_L206X3);
  sim_icache_fetch(4077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5550 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 5551 */
l_L202X3: ;/* line 5554 */
__LABEL(l_L202X3);
  sim_icache_fetch(4079 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5555 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5556 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5557 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5558 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5559 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5560 */
   __ADD_CYCLES(1);
} /* line 5560 */
  sim_icache_fetch(4085 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5563 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 364: goto l_L198X3;
    case 365: goto l_L199X3;
    case 367: goto l_lr_266;
    case 368: goto l_L200X3;
    case 369: goto l_L201X3;
    case 371: goto l_lr_270;
    case 372: goto l_L204X3;
    case 373: goto l_L205X3;
    case 375: goto l_lr_274;
    case 376: goto l_L203X3;
    case 377: goto l_L207X3;
    case 378: goto l_L223X3;
    case 379: goto l_L225X3;
    case 380: goto l_L241X3;
    case 381: goto l_L244X3;
    case 382: goto l_L240X3;
    case 383: goto l_L239X3;
    case 384: goto l_L238X3;
    case 385: goto l_L237X3;
    case 386: goto l_L236X3;
    case 387: goto l_L235X3;
    case 388: goto l_L234X3;
    case 389: goto l_L233X3;
    case 390: goto l_L232X3;
    case 391: goto l_L231X3;
    case 392: goto l_L230X3;
    case 393: goto l_L229X3;
    case 394: goto l_L228X3;
    case 395: goto l_L227X3;
    case 396: goto l_L226X3;
    case 397: goto l_L242X3;
    case 398: goto l_L243X3;
    case 399: goto l_L222X3;
    case 400: goto l_L221X3;
    case 401: goto l_L220X3;
    case 402: goto l_L219X3;
    case 403: goto l_L218X3;
    case 404: goto l_L217X3;
    case 405: goto l_L216X3;
    case 406: goto l_L215X3;
    case 407: goto l_L214X3;
    case 408: goto l_L213X3;
    case 409: goto l_L212X3;
    case 410: goto l_L211X3;
    case 411: goto l_L210X3;
    case 412: goto l_L209X3;
    case 413: goto l_L208X3;
    case 414: goto l_L224X3;
    case 415: goto l_L206X3;
    case 416: goto l_L202X3;
    case 417:
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
  reg_l0_0 = (445 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4086 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5582 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5583 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5584 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5585 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5586 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5587 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5588 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5589 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5590 */
   __ADD_CYCLES(1);
} /* line 5590 */
  sim_icache_fetch(4103 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGE(reg_r0_11, reg_r0_7, reg_r0_8); /* line 5592 */
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5593 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5594 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5595 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5596 */
} /* line 5596 */
  sim_icache_fetch(4108 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5598 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_2); /* line 5599 */
} /* line 5599 */
  sim_icache_fetch(4110 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_2, reg_r0_4, reg_r0_11); /* line 5601 */
} /* line 5601 */
  sim_icache_fetch(4111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5603 */
  sim_icache_fetch(4112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5605 */
  sim_icache_fetch(4113 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5607 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5608 */
  sim_icache_fetch(4116 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5610 */
} /* line 5610 */
l_L246X3: ;/* line 5613 */
__LABEL(l_L246X3);
  sim_icache_fetch(4118 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5614 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5615 */
   __MOV(reg_r0_5, 0); /* line 5616 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5617 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5618 */
   __ADD_CYCLES(1);
} /* line 5618 */
  sim_icache_fetch(4125 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5620 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5621 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5622 */
} /* line 5622 */
  sim_icache_fetch(4128 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5624 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5625 */
l_L249X3: ;/* line 5628 */
__LABEL(l_L249X3);
  sim_icache_fetch(4130 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5629 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5630 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5631 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5632 */
} /* line 5632 */
  sim_icache_fetch(4136 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5634 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5635 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5636 */
  sim_icache_fetch(4139 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5638 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5639 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5640 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5641 */
} /* line 5641 */
  sim_icache_fetch(4143 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5643 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5644 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5645 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5646 */
} /* line 5646 */
  sim_icache_fetch(4148 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5648 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5649 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5650 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5651 */
  sim_icache_fetch(4153 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5653 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5654 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5655 */
} /* line 5655 */
  sim_icache_fetch(4157 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5657 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5658 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5659 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5660 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5661 */
} /* line 5661 */
  sim_icache_fetch(4163 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5663 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5664 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5665 */
} /* line 5665 */
  sim_icache_fetch(4166 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5667 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5668 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5669 */
} /* line 5669 */
l_L252X3: ;/* line 5671 */
__LABEL(l_L252X3);
  sim_icache_fetch(4169 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5672 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5673 */
} /* line 5673 */
  sim_icache_fetch(4172 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5675 */
} /* line 5675 */
  sim_icache_fetch(4173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5677 */
} /* line 5677 */
  sim_icache_fetch(4174 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5679 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5680 */
  sim_icache_fetch(4176 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5682 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5683 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5684 */
  sim_icache_fetch(4179 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5686 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5687 */
  sim_icache_fetch(4182 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5689 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5690 */
} /* line 5690 */
  sim_icache_fetch(4186 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5692 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5693 */
} /* line 5693 */
  sim_icache_fetch(4189 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5695 */
} /* line 5695 */
  sim_icache_fetch(4190 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5697 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5698 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5699 */
} /* line 5699 */
l_L255X3: ;/* line 5701 */
__LABEL(l_L255X3);
  sim_icache_fetch(4193 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5702 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5703 */
} /* line 5703 */
  sim_icache_fetch(4196 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5705 */
} /* line 5705 */
  sim_icache_fetch(4197 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5707 */
} /* line 5707 */
  sim_icache_fetch(4198 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5709 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5710 */
  sim_icache_fetch(4200 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5712 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5713 */
  sim_icache_fetch(4202 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5715 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L256X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5716 */
  sim_icache_fetch(4205 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5718 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5719 */
} /* line 5719 */
  sim_icache_fetch(4209 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5721 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5722 */
} /* line 5722 */
  sim_icache_fetch(4212 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5724 */
} /* line 5724 */
  sim_icache_fetch(4213 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5726 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5727 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5728 */
} /* line 5728 */
l_L257X3: ;/* line 5730 */
__LABEL(l_L257X3);
  sim_icache_fetch(4216 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5731 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5732 */
} /* line 5732 */
  sim_icache_fetch(4219 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5734 */
} /* line 5734 */
  sim_icache_fetch(4220 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5736 */
  sim_icache_fetch(4221 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5738 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5739 */
  sim_icache_fetch(4223 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5741 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L258X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5742 */
  sim_icache_fetch(4226 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5744 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5745 */
} /* line 5745 */
  sim_icache_fetch(4230 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5747 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5748 */
} /* line 5748 */
  sim_icache_fetch(4233 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5750 */
} /* line 5750 */
  sim_icache_fetch(4234 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5752 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5753 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5754 */
} /* line 5754 */
l_L259X3: ;/* line 5756 */
__LABEL(l_L259X3);
  sim_icache_fetch(4237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5757 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5758 */
} /* line 5758 */
  sim_icache_fetch(4240 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5760 */
} /* line 5760 */
  sim_icache_fetch(4241 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5762 */
  sim_icache_fetch(4242 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5764 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5765 */
  sim_icache_fetch(4244 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5767 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L260X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5768 */
  sim_icache_fetch(4247 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5770 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5771 */
} /* line 5771 */
  sim_icache_fetch(4251 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5773 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5774 */
} /* line 5774 */
  sim_icache_fetch(4254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5776 */
} /* line 5776 */
  sim_icache_fetch(4255 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5778 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5779 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5780 */
} /* line 5780 */
l_L261X3: ;/* line 5782 */
__LABEL(l_L261X3);
  sim_icache_fetch(4258 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5783 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5784 */
} /* line 5784 */
  sim_icache_fetch(4261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5786 */
} /* line 5786 */
  sim_icache_fetch(4262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5788 */
  sim_icache_fetch(4263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5790 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5791 */
  sim_icache_fetch(4265 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5793 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5794 */
  sim_icache_fetch(4268 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5796 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5797 */
} /* line 5797 */
  sim_icache_fetch(4272 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5799 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5800 */
} /* line 5800 */
  sim_icache_fetch(4275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5802 */
} /* line 5802 */
  sim_icache_fetch(4276 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5804 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5805 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5806 */
} /* line 5806 */
l_L263X3: ;/* line 5808 */
__LABEL(l_L263X3);
  sim_icache_fetch(4279 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5809 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5810 */
} /* line 5810 */
  sim_icache_fetch(4282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5812 */
} /* line 5812 */
  sim_icache_fetch(4283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5814 */
  sim_icache_fetch(4284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5816 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5817 */
  sim_icache_fetch(4286 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5819 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L264X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5820 */
  sim_icache_fetch(4289 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5822 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5823 */
} /* line 5823 */
  sim_icache_fetch(4293 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5825 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5826 */
} /* line 5826 */
  sim_icache_fetch(4296 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5828 */
} /* line 5828 */
  sim_icache_fetch(4297 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5830 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5831 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5832 */
} /* line 5832 */
l_L265X3: ;/* line 5834 */
__LABEL(l_L265X3);
  sim_icache_fetch(4300 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5835 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5836 */
} /* line 5836 */
  sim_icache_fetch(4303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5838 */
} /* line 5838 */
  sim_icache_fetch(4304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5840 */
  sim_icache_fetch(4305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5842 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5843 */
  sim_icache_fetch(4307 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5845 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L266X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5846 */
  sim_icache_fetch(4310 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5848 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5849 */
} /* line 5849 */
  sim_icache_fetch(4314 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5851 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5852 */
} /* line 5852 */
  sim_icache_fetch(4317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5854 */
} /* line 5854 */
  sim_icache_fetch(4318 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5856 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5857 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5858 */
} /* line 5858 */
l_L267X3: ;/* line 5860 */
__LABEL(l_L267X3);
  sim_icache_fetch(4321 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5861 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5862 */
} /* line 5862 */
  sim_icache_fetch(4324 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5864 */
} /* line 5864 */
  sim_icache_fetch(4325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5866 */
  sim_icache_fetch(4326 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5868 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5869 */
  sim_icache_fetch(4328 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5871 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5872 */
  sim_icache_fetch(4331 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5874 */
} /* line 5874 */
  sim_icache_fetch(4333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5876 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5877 */
   __ADD_CYCLES(1);
} /* line 5877 */
  sim_icache_fetch(4335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5879 */
} /* line 5879 */
l_L269X3: ;/* line 5881 */
__LABEL(l_L269X3);
  sim_icache_fetch(4336 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5882 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5883 */
} /* line 5883 */
  sim_icache_fetch(4339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5885 */
} /* line 5885 */
  sim_icache_fetch(4340 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5887 */
  sim_icache_fetch(4341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5889 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 5890 */
l_L253X3: ;/* line 5893 */
__LABEL(l_L253X3);
  sim_icache_fetch(4343 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5894 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5895 */
   __GOTO(l_L270X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L270X3;
} /* line 5896 */
l_L271X3: ;/* line 5899 */
__LABEL(l_L271X3);
  sim_icache_fetch(4346 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5900 */
   __MOV(reg_r0_7, 0); /* line 5901 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5902 */
} /* line 5902 */
  sim_icache_fetch(4350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5904 */
} /* line 5904 */
  sim_icache_fetch(4351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5906 */
} /* line 5906 */
l_L245X3: ;/* line 5909 */
__LABEL(l_L245X3);
  sim_icache_fetch(4352 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5910 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5911 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5912 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5913 */
} /* line 5913 */
  sim_icache_fetch(4358 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5915 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5916 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5917 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5918 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5919 */
} /* line 5919 */
  sim_icache_fetch(4366 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 5921 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 5922 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 5923 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 5924 */
} /* line 5924 */
  sim_icache_fetch(4370 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 5926 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 5927 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 5928 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 5929 */
} /* line 5929 */
  sim_icache_fetch(4375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 5931 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 5932 */
} /* line 5932 */
  sim_icache_fetch(4377 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5934 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 5935 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 5936 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 5937 */
} /* line 5937 */
  sim_icache_fetch(4381 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 5939 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5940 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 5941 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5942 */
   __ADD_CYCLES(1);
} /* line 5942 */
  sim_icache_fetch(4386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 5944 */
} /* line 5944 */
  sim_icache_fetch(4387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 5946 */
} /* line 5946 */
  sim_icache_fetch(4388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 5949 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5950 */
l_L268X3: ;/* line 5953 */
__LABEL(l_L268X3);
  sim_icache_fetch(4390 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5954 */
   __GOTO(l_L269X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L269X3;
} /* line 5955 */
l_L250X3: ;/* line 5958 */
__LABEL(l_L250X3);
  sim_icache_fetch(4392 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 5959 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5960 */
} /* line 5960 */
l_L270X3: ;/* line 5962 */
__LABEL(l_L270X3);
  sim_icache_fetch(4394 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 5963 */
} /* line 5963 */
  sim_icache_fetch(4395 + t_thisfile.offset, 1);
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
} /* line 5965 */
  sim_icache_fetch(4396 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 5968 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 5969 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5970 */
l_L266X3: ;/* line 5973 */
__LABEL(l_L266X3);
  sim_icache_fetch(4401 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 5974 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5975 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5976 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5977 */
   __ADD_CYCLES(1);
} /* line 5977 */
  sim_icache_fetch(4407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 5979 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5980 */
} /* line 5980 */
  sim_icache_fetch(4409 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5982 */
   __GOTO(l_L267X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L267X3;
} /* line 5983 */
l_L264X3: ;/* line 5986 */
__LABEL(l_L264X3);
  sim_icache_fetch(4411 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5987 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5988 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5989 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5990 */
   __ADD_CYCLES(1);
} /* line 5990 */
  sim_icache_fetch(4417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 5992 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5993 */
} /* line 5993 */
  sim_icache_fetch(4419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5995 */
   __GOTO(l_L265X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L265X3;
} /* line 5996 */
l_L262X3: ;/* line 5999 */
__LABEL(l_L262X3);
  sim_icache_fetch(4421 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6000 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6001 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6002 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6003 */
   __ADD_CYCLES(1);
} /* line 6003 */
  sim_icache_fetch(4427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6005 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6006 */
} /* line 6006 */
  sim_icache_fetch(4429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6008 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 6009 */
l_L260X3: ;/* line 6012 */
__LABEL(l_L260X3);
  sim_icache_fetch(4431 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6013 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6014 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6015 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6016 */
   __ADD_CYCLES(1);
} /* line 6016 */
  sim_icache_fetch(4437 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6018 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6019 */
} /* line 6019 */
  sim_icache_fetch(4439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6021 */
   __GOTO(l_L261X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L261X3;
} /* line 6022 */
l_L258X3: ;/* line 6025 */
__LABEL(l_L258X3);
  sim_icache_fetch(4441 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6026 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6027 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6028 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6029 */
   __ADD_CYCLES(1);
} /* line 6029 */
  sim_icache_fetch(4447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6031 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6032 */
} /* line 6032 */
  sim_icache_fetch(4449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6034 */
   __GOTO(l_L259X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L259X3;
} /* line 6035 */
l_L256X3: ;/* line 6038 */
__LABEL(l_L256X3);
  sim_icache_fetch(4451 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6039 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6040 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6041 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6042 */
   __ADD_CYCLES(1);
} /* line 6042 */
  sim_icache_fetch(4457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6044 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6045 */
} /* line 6045 */
  sim_icache_fetch(4459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6047 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 6048 */
l_L254X3: ;/* line 6051 */
__LABEL(l_L254X3);
  sim_icache_fetch(4461 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6052 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6053 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6054 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6055 */
   __ADD_CYCLES(1);
} /* line 6055 */
  sim_icache_fetch(4467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6057 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6058 */
} /* line 6058 */
  sim_icache_fetch(4469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6060 */
   __GOTO(l_L255X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L255X3;
} /* line 6061 */
l_L251X3: ;/* line 6064 */
__LABEL(l_L251X3);
  sim_icache_fetch(4471 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6065 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6066 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6067 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6068 */
} /* line 6068 */
  sim_icache_fetch(4476 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6070 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6071 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6072 */
} /* line 6072 */
  sim_icache_fetch(4479 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6074 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6075 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6076 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6077 */
} /* line 6077 */
  sim_icache_fetch(4483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6079 */
   __GOTO(l_L252X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L252X3;
} /* line 6080 */
l_L248X3: ;/* line 6083 */
__LABEL(l_L248X3);
  sim_icache_fetch(4485 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6084 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6085 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6086 */
} /* line 6086 */
  sim_icache_fetch(4490 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6088 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6089 */
} /* line 6089 */
  sim_icache_fetch(4494 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6091 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6092 */
   __ADD_CYCLES(1);
} /* line 6092 */
  sim_icache_fetch(4497 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6094 */
} /* line 6094 */
  sim_icache_fetch(4498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6096 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 6097 */
l_L247X3: ;/* line 6100 */
__LABEL(l_L247X3);
  sim_icache_fetch(4500 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6101 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6102 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6103 */
   __ADD_CYCLES(1);
} /* line 6103 */
  sim_icache_fetch(4504 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6105 */
} /* line 6105 */
  sim_icache_fetch(4505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6107 */
} /* line 6107 */
  sim_icache_fetch(4506 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6109 */
   __GOTO(l_L246X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L246X3;
} /* line 6110 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 418: goto l_L246X3;
    case 419: goto l_L249X3;
    case 420: goto l_L252X3;
    case 421: goto l_L255X3;
    case 422: goto l_L257X3;
    case 423: goto l_L259X3;
    case 424: goto l_L261X3;
    case 425: goto l_L263X3;
    case 426: goto l_L265X3;
    case 427: goto l_L267X3;
    case 428: goto l_L269X3;
    case 429: goto l_L253X3;
    case 430: goto l_L271X3;
    case 431: goto l_L245X3;
    case 432: goto l_L268X3;
    case 433: goto l_L250X3;
    case 434: goto l_L270X3;
    case 435: goto l_L266X3;
    case 436: goto l_L264X3;
    case 437: goto l_L262X3;
    case 438: goto l_L260X3;
    case 439: goto l_L258X3;
    case 440: goto l_L256X3;
    case 441: goto l_L254X3;
    case 442: goto l_L251X3;
    case 443: goto l_L248X3;
    case 444: goto l_L247X3;
    case 445:
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
  reg_l0_0 = (448 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4509 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6132 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6133 */
} /* line 6133 */
		 /* line 6134 */
  sim_icache_fetch(4512 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6137 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (448 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6137 */
l_lr_346: ;/* line 6137 */
__LABEL(l_lr_346);
  sim_icache_fetch(4515 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6139 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6140 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6141 */
   __ADD_CYCLES(1);
} /* line 6141 */
  sim_icache_fetch(4518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6144 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 447: goto l_lr_346;
    case 448:
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
  reg_l0_0 = (450 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4519 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6190 */
   __MOV(reg_r0_3, 0); /* line 6191 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6192 */
   __ADD_CYCLES(1);
} /* line 6192 */
  sim_icache_fetch(4523 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6194 */
} /* line 6194 */
  sim_icache_fetch(4524 + t_thisfile.offset, 1);
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
} /* line 6196 */
  sim_icache_fetch(4525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6199 */
l_L272X3: ;/* line 6202 */
__LABEL(l_L272X3);
  sim_icache_fetch(4526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6205 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6205 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 449: goto l_L272X3;
    case 450:
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
  reg_l0_0 = (451 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6221 */
} /* line 6221 */
  sim_icache_fetch(4529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6224 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 451:
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
  reg_l0_0 = (455 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4530 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6239 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6240 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6241 */
} /* line 6241 */
  sim_icache_fetch(4535 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6243 */
} /* line 6243 */
  sim_icache_fetch(4536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6245 */
} /* line 6245 */
  sim_icache_fetch(4537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L273X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6247 */
		 /* line 6248 */
  sim_icache_fetch(4538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (455 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6250 */
l_lr_352: ;/* line 6250 */
__LABEL(l_lr_352);
l_L273X3: ;/* line 6252 */
__LABEL(l_L273X3);
  sim_icache_fetch(4540 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6253 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6254 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6255 */
   __ADD_CYCLES(1);
} /* line 6255 */
  sim_icache_fetch(4543 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6258 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 453: goto l_lr_352;
    case 454: goto l_L273X3;
    case 455:
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
  reg_l0_0 = (468 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4544 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6304 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6305 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6306 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6307 */
} /* line 6307 */
  sim_icache_fetch(4551 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6309 */
} /* line 6309 */
  sim_icache_fetch(4552 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6311 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6312 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6313 */
} /* line 6313 */
  sim_icache_fetch(4557 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6315 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6316 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6317 */
  sim_icache_fetch(4561 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L275X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6319 */
l_L276X3: ;/* line 6322 */
__LABEL(l_L276X3);
  sim_icache_fetch(4562 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6323 */
   __MOV(reg_r0_3, 0); /* line 6324 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6325 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6326 */
   __ADD_CYCLES(1);
} /* line 6326 */
  sim_icache_fetch(4567 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6328 */
} /* line 6328 */
  sim_icache_fetch(4568 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L277X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6330 */
  sim_icache_fetch(4569 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6333 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6334 */
l_L277X3: ;/* line 6337 */
__LABEL(l_L277X3);
  sim_icache_fetch(4572 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6338 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6339 */
} /* line 6339 */
		 /* line 6340 */
  sim_icache_fetch(4576 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (468 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6342 */
l_lr_358: ;/* line 6342 */
__LABEL(l_lr_358);
  sim_icache_fetch(4578 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6344 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6345 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6346 */
} /* line 6346 */
		 /* line 6347 */
  sim_icache_fetch(4583 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6349 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6350 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (468 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6351 */
l_lr_360: ;/* line 6351 */
__LABEL(l_lr_360);
  sim_icache_fetch(4589 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6353 */
   __MOV(reg_r0_3, 0); /* line 6354 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6355 */
   __ADD_CYCLES(1);
} /* line 6355 */
  sim_icache_fetch(4592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6358 */
l_L275X3: ;/* line 6361 */
__LABEL(l_L275X3);
  sim_icache_fetch(4593 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6362 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6363 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6364 */
   __ADD_CYCLES(1);
} /* line 6364 */
		 /* line 6365 */
  sim_icache_fetch(4597 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6368 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (468 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6368 */
l_lr_363: ;/* line 6368 */
__LABEL(l_lr_363);
  sim_icache_fetch(4600 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6370 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6371 */
l_L274X3: ;/* line 6374 */
__LABEL(l_L274X3);
  sim_icache_fetch(4602 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6375 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6376 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6377 */
   __ADD_CYCLES(1);
} /* line 6377 */
		 /* line 6378 */
  sim_icache_fetch(4607 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6380 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (468 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6381 */
l_lr_366: ;/* line 6381 */
__LABEL(l_lr_366);
  sim_icache_fetch(4610 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6383 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6384 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 456: goto l_L276X3;
    case 457: goto l_L277X3;
    case 459: goto l_lr_358;
    case 461: goto l_lr_360;
    case 462: goto l_L275X3;
    case 464: goto l_lr_363;
    case 465: goto l_L274X3;
    case 467: goto l_lr_366;
    case 468:
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
  reg_l0_0 = (486 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4612 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6403 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6404 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6405 */
} /* line 6405 */
  sim_icache_fetch(4616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6407 */
} /* line 6407 */
l_L278X3: ;/* line 6410 */
__LABEL(l_L278X3);
  sim_icache_fetch(4617 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __MOV(reg_r0_3, reg_r0_2); /* line 6411 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6412 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6413 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6414 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6415 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6416 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6417 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6418 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6419 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6420 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6421 */
} /* line 6421 */
  sim_icache_fetch(4628 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6423 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6424 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6425 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6426 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6427 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6428 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6429 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6430 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6431 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6432 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6433 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6434 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6435 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6436 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6437 */
} /* line 6437 */
  sim_icache_fetch(4643 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6439 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6440 */
  sim_icache_fetch(4645 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6442 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6443 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6444 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6445 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6446 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6447 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6448 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6449 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6450 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6451 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6452 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6453 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6454 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6455 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6456 */
} /* line 6456 */
  sim_icache_fetch(4660 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6458 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6459 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6460 */
  sim_icache_fetch(4663 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6462 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6463 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6464 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6465 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6466 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6467 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6468 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6469 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6470 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6471 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6472 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6473 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6474 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6475 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6476 */
} /* line 6476 */
  sim_icache_fetch(4678 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6478 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6479 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6480 */
  sim_icache_fetch(4681 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6482 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6483 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6484 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6485 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6486 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6487 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6488 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6489 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6490 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6491 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6492 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6493 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6494 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6495 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6496 */
} /* line 6496 */
  sim_icache_fetch(4696 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6498 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6499 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6500 */
  sim_icache_fetch(4699 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6502 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6503 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6504 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6506 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6507 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6508 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6509 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6510 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6511 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6512 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6513 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6514 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6515 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6516 */
} /* line 6516 */
  sim_icache_fetch(4714 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6518 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6519 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6520 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6521 */
  sim_icache_fetch(4718 + t_thisfile.offset, 30);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6523 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6525 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6527 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6528 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6529 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6531 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6532 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6533 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6534 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6535 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6536 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6537 */
} /* line 6537 */
  sim_icache_fetch(4748 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6539 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6540 */
  sim_icache_fetch(4751 + t_thisfile.offset, 30);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6542 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6543 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6544 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6545 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6546 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6547 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6548 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6549 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6550 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6551 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6552 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6553 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6554 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6555 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6556 */
} /* line 6556 */
  sim_icache_fetch(4781 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6558 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6559 */
  sim_icache_fetch(4784 + t_thisfile.offset, 30);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6561 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6562 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6564 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6565 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6567 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6568 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6569 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6570 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6571 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6572 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6573 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6574 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6575 */
} /* line 6575 */
  sim_icache_fetch(4814 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6577 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6578 */
  sim_icache_fetch(4817 + t_thisfile.offset, 30);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6580 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6581 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6582 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6583 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6584 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6588 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6589 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6590 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6591 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6592 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6593 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6594 */
} /* line 6594 */
  sim_icache_fetch(4847 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6596 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L287X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6597 */
  sim_icache_fetch(4850 + t_thisfile.offset, 30);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6600 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6601 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6602 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6604 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6605 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6606 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6608 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6610 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6611 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6612 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6613 */
} /* line 6613 */
  sim_icache_fetch(4880 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6615 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6616 */
  sim_icache_fetch(4883 + t_thisfile.offset, 30);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6620 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6621 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6622 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6623 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6624 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6625 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6626 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6627 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6628 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6629 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6630 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6631 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6632 */
} /* line 6632 */
  sim_icache_fetch(4913 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6634 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6635 */
  sim_icache_fetch(4916 + t_thisfile.offset, 30);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6637 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6639 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6640 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6641 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6642 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6644 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6645 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6646 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6647 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6648 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6651 */
} /* line 6651 */
  sim_icache_fetch(4946 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6653 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6654 */
  sim_icache_fetch(4949 + t_thisfile.offset, 29);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6656 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6658 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6659 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6660 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6661 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6662 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6664 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6665 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6666 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6667 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6668 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6669 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6670 */
} /* line 6670 */
  sim_icache_fetch(4978 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6672 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6673 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6674 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6675 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6676 */
} /* line 6676 */
  sim_icache_fetch(4987 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L291X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6679 */
  sim_icache_fetch(4988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L278X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L278X3;
} /* line 6681 */
l_L291X3: ;/* line 6684 */
__LABEL(l_L291X3);
  sim_icache_fetch(4989 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6685 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6686 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6687 */
l_L293X3: ;/* line 6690 */
__LABEL(l_L293X3);
  sim_icache_fetch(4993 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6691 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6692 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6693 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6694 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 4); /* line 6695 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 5); /* line 6696 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 6); /* line 6697 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 7); /* line 6698 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6699 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6700 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6701 */
} /* line 6701 */
  sim_icache_fetch(5004 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 6703 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6704 */
  sim_icache_fetch(5006 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6706 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6707 */
  sim_icache_fetch(5008 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6709 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6710 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6711 */
  sim_icache_fetch(5011 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6713 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6714 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6715 */
  sim_icache_fetch(5014 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6717 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6718 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6719 */
  sim_icache_fetch(5017 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6721 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 12); /* line 6722 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6723 */
  sim_icache_fetch(5020 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6725 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 13); /* line 6726 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6727 */
  sim_icache_fetch(5023 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6729 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 14); /* line 6730 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6731 */
  sim_icache_fetch(5026 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6733 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 15); /* line 6734 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6735 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6736 */
  sim_icache_fetch(5030 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6738 */
   __CMPGT(reg_b0_0, reg_r0_5, 0); /* line 6739 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6740 */
  sim_icache_fetch(5033 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6742 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6743 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6744 */
  sim_icache_fetch(5036 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6746 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6747 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6748 */
  sim_icache_fetch(5039 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6750 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6751 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6752 */
  sim_icache_fetch(5042 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6754 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 4); /* line 6755 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6756 */
  sim_icache_fetch(5045 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6758 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 5); /* line 6759 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6760 */
  sim_icache_fetch(5048 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6762 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 6); /* line 6763 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6764 */
  sim_icache_fetch(5051 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6766 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 7); /* line 6767 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6768 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6769 */
  sim_icache_fetch(5055 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6771 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 8); /* line 6772 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6773 */
  sim_icache_fetch(5058 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6775 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6776 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6777 */
  sim_icache_fetch(5061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6779 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6780 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6781 */
  sim_icache_fetch(5064 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6783 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6784 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6785 */
  sim_icache_fetch(5067 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6787 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 12); /* line 6788 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6789 */
  sim_icache_fetch(5070 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6791 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 13); /* line 6792 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6793 */
  sim_icache_fetch(5073 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6795 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 14); /* line 6796 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6797 */
  sim_icache_fetch(5076 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6799 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 15); /* line 6800 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6801 */
  sim_icache_fetch(5079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6803 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6804 */
  sim_icache_fetch(5081 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6806 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6807 */
  sim_icache_fetch(5083 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6809 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6810 */
  sim_icache_fetch(5085 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6812 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6813 */
  sim_icache_fetch(5087 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6815 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6816 */
  sim_icache_fetch(5089 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6818 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6819 */
  sim_icache_fetch(5091 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6821 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6822 */
  sim_icache_fetch(5093 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6824 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6825 */
l_L294X3: ;/* line 6828 */
__LABEL(l_L294X3);
  sim_icache_fetch(5095 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6830 */
l_L290X3: ;/* line 6833 */
__LABEL(l_L290X3);
  sim_icache_fetch(5096 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6834 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6835 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6836 */
l_L289X3: ;/* line 6839 */
__LABEL(l_L289X3);
  sim_icache_fetch(5100 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6840 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6841 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6842 */
l_L288X3: ;/* line 6845 */
__LABEL(l_L288X3);
  sim_icache_fetch(5104 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6846 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6847 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6848 */
l_L287X3: ;/* line 6851 */
__LABEL(l_L287X3);
  sim_icache_fetch(5108 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6852 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6853 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6854 */
l_L286X3: ;/* line 6857 */
__LABEL(l_L286X3);
  sim_icache_fetch(5112 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6858 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6859 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6860 */
l_L285X3: ;/* line 6863 */
__LABEL(l_L285X3);
  sim_icache_fetch(5116 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6864 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6865 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6866 */
l_L284X3: ;/* line 6869 */
__LABEL(l_L284X3);
  sim_icache_fetch(5120 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6870 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6871 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6872 */
l_L283X3: ;/* line 6875 */
__LABEL(l_L283X3);
  sim_icache_fetch(5124 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6876 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6877 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6878 */
l_L282X3: ;/* line 6881 */
__LABEL(l_L282X3);
  sim_icache_fetch(5128 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6882 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6883 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6884 */
l_L281X3: ;/* line 6887 */
__LABEL(l_L281X3);
  sim_icache_fetch(5131 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6888 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6889 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6890 */
l_L280X3: ;/* line 6893 */
__LABEL(l_L280X3);
  sim_icache_fetch(5134 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6894 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6895 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6896 */
l_L279X3: ;/* line 6899 */
__LABEL(l_L279X3);
  sim_icache_fetch(5137 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6900 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6901 */
} /* line 6901 */
l_L292X3: ;/* line 6903 */
__LABEL(l_L292X3);
  sim_icache_fetch(5139 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6904 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6905 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6906 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 469: goto l_L278X3;
    case 470: goto l_L291X3;
    case 471: goto l_L293X3;
    case 472: goto l_L294X3;
    case 473: goto l_L290X3;
    case 474: goto l_L289X3;
    case 475: goto l_L288X3;
    case 476: goto l_L287X3;
    case 477: goto l_L286X3;
    case 478: goto l_L285X3;
    case 479: goto l_L284X3;
    case 480: goto l_L283X3;
    case 481: goto l_L282X3;
    case 482: goto l_L281X3;
    case 483: goto l_L280X3;
    case 484: goto l_L279X3;
    case 485: goto l_L292X3;
    case 486:
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
  reg_l0_0 = (487 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5142 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6922 */
} /* line 6922 */
  sim_icache_fetch(5143 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6925 */
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

extern unsigned int version(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(version);  sim_gprof_enter(&sim_gprof_idx,"version");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (488 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5144 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6941 */
} /* line 6941 */
  sim_icache_fetch(5145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6944 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 488:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 5152, 0, 0, 0, 2};

