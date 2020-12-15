/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/10_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_12192Xoffset[1];
unsigned int compress_12192Xbuf[3];
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
unsigned int compress_12192XBuf[216]; 
unsigned int compress_12192Xrcs_ident[6]; 
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

unsigned int compress_12192XBuf[216] = { 
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

unsigned int compress_12192Xrcs_ident[6] = { 
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
   __MOV(reg_r0_5, (unsigned int) compress_12192XBuf); /* line 35 */
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

  sim_icache_fetch(44 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 177 */
   __ADD(reg_r0_29, reg_r0_3, (unsigned int) 15); /* line 178 */
   __ADD(reg_r0_28, reg_r0_3, (unsigned int) 14); /* line 179 */
   __ADD(reg_r0_27, reg_r0_3, (unsigned int) 13); /* line 180 */
   __ADD(reg_r0_26, reg_r0_3, (unsigned int) 12); /* line 181 */
   __ADD(reg_r0_25, reg_r0_3, (unsigned int) 11); /* line 182 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 10); /* line 183 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 9); /* line 184 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 8); /* line 185 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 7); /* line 186 */
} /* line 186 */
  sim_icache_fetch(54 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SXTB(reg_r0_4, reg_r0_4); /* line 188 */
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 189 */
   __MOV(reg_r0_5, 0); /* line 190 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 191 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 6); /* line 192 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 193 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 194 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 195 */
   __STW(mem_trace_st(reg_r0_1,0,4), reg_r0_57); /* line 196 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 4),0,4), reg_r0_58); /* line 197 */
} /* line 197 */
  sim_icache_fetch(64 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_3); /* line 199 */
} /* line 199 */
l_L0X3: ;/* line 202 */
__LABEL(l_L0X3);
  sim_icache_fetch(65 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 203 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 204 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 205 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_10,0,1)); /* line 206 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_12,0,1)); /* line 207 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_14,0,1)); /* line 208 */
   __LDBs(reg_r0_17, mem_trace_ld(reg_r0_16,0,1)); /* line 209 */
   __LDBs(reg_r0_19, mem_trace_ld(reg_r0_18,0,1)); /* line 210 */
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_20,0,1)); /* line 211 */
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_22,0,1)); /* line 212 */
} /* line 212 */
  sim_icache_fetch(75 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __LDBs(reg_r0_30, mem_trace_ld(reg_r0_24,0,1)); /* line 214 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_25,0,1)); /* line 215 */
   __LDBs(reg_r0_32, mem_trace_ld(reg_r0_26,0,1)); /* line 216 */
   __LDBs(reg_r0_33, mem_trace_ld(reg_r0_27,0,1)); /* line 217 */
   __LDBs(reg_r0_34, mem_trace_ld(reg_r0_28,0,1)); /* line 218 */
   __LDBs(reg_r0_35, mem_trace_ld(reg_r0_29,0,1)); /* line 219 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) 16); /* line 220 */
   __ADD(reg_r0_37, reg_r0_28, (unsigned int) 16); /* line 221 */
   __ADD(reg_r0_38, reg_r0_27, (unsigned int) 16); /* line 222 */
   __ADD(reg_r0_39, reg_r0_26, (unsigned int) 16); /* line 223 */
} /* line 223 */
  sim_icache_fetch(85 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 225 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 226 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 227 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 228 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 229 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 230 */
   __CMPNE(reg_b0_6, reg_r0_11, 0); /* line 231 */
   __CMPEQ(reg_b0_7, reg_r0_11, reg_r0_4); /* line 232 */
   __ADD(reg_r0_3, reg_r0_25, (unsigned int) 16); /* line 233 */
   __ADD(reg_r0_7, reg_r0_24, (unsigned int) 16); /* line 234 */
} /* line 234 */
  sim_icache_fetch(95 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SLCT(reg_r0_9, reg_b0_1, reg_r0_2, reg_r0_5); /* line 236 */
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 237 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 238 */
   __ADD(reg_r0_11, reg_r0_22, (unsigned int) 16); /* line 239 */
   __ADD(reg_r0_13, reg_r0_20, (unsigned int) 16); /* line 240 */
   __ADD(reg_r0_40, reg_r0_18, (unsigned int) 16); /* line 241 */
   __ADD(reg_r0_41, reg_r0_16, (unsigned int) 16); /* line 242 */
   __ADD(reg_r0_42, reg_r0_14, (unsigned int) 16); /* line 243 */
   __ADD(reg_r0_43, reg_r0_12, (unsigned int) 16); /* line 244 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 245 */
  sim_icache_fetch(105 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SLCT(reg_r0_6, reg_b0_3, reg_r0_6, reg_r0_9); /* line 247 */
   __CMPNE(reg_b0_2, reg_r0_15, 0); /* line 248 */
   __CMPEQ(reg_b0_3, reg_r0_15, reg_r0_4); /* line 249 */
   __ADD(reg_r0_15, reg_r0_10, (unsigned int) 16); /* line 250 */
   __ADD(reg_r0_44, reg_r0_8, (unsigned int) 16); /* line 251 */
   __ADD(reg_r0_45, reg_r0_29, (unsigned int) 16); /* line 252 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 253 */
   __LDBs(reg_r0_46, mem_trace_ld(reg_r0_36,0,1)); /* line 254 */
   __LDBs(reg_r0_47, mem_trace_ld(reg_r0_43,0,1)); /* line 255 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 256 */
  sim_icache_fetch(115 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SLCT(reg_r0_8, reg_b0_5, reg_r0_8, reg_r0_6); /* line 258 */
   __CMPNE(reg_b0_4, reg_r0_17, 0); /* line 259 */
   __CMPEQ(reg_b0_5, reg_r0_17, reg_r0_4); /* line 260 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_2,0,1)); /* line 261 */
   __LDBs(reg_r0_17, mem_trace_ld(reg_r0_44,0,1)); /* line 262 */
   __LDBs(reg_r0_48, mem_trace_ld(reg_r0_15,0,1)); /* line 263 */
   __LDBs(reg_r0_49, mem_trace_ld(reg_r0_42,0,1)); /* line 264 */
   __LDBs(reg_r0_50, mem_trace_ld(reg_r0_41,0,1)); /* line 265 */
   __LDBs(reg_r0_51, mem_trace_ld(reg_r0_40,0,1)); /* line 266 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 267 */
  sim_icache_fetch(125 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SLCT(reg_r0_10, reg_b0_7, reg_r0_10, reg_r0_8); /* line 269 */
   __CMPNE(reg_b0_6, reg_r0_19, 0); /* line 270 */
   __CMPEQ(reg_b0_7, reg_r0_19, reg_r0_4); /* line 271 */
   __LDBs(reg_r0_19, mem_trace_ld(reg_r0_13,0,1)); /* line 272 */
   __LDBs(reg_r0_52, mem_trace_ld(reg_r0_11,0,1)); /* line 273 */
   __LDBs(reg_r0_53, mem_trace_ld(reg_r0_7,0,1)); /* line 274 */
   __LDBs(reg_r0_54, mem_trace_ld(reg_r0_3,0,1)); /* line 275 */
   __LDBs(reg_r0_55, mem_trace_ld(reg_r0_39,0,1)); /* line 276 */
   __LDBs(reg_r0_56, mem_trace_ld(reg_r0_38,0,1)); /* line 277 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 278 */
  sim_icache_fetch(135 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, reg_r0_10); /* line 280 */
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 281 */
   __CMPEQ(reg_b0_1, reg_r0_21, reg_r0_4); /* line 282 */
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_37,0,1)); /* line 283 */
   __LDBs(reg_r0_57, mem_trace_ld(reg_r0_45,0,1)); /* line 284 */
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) 16); /* line 285 */
   __ADD(reg_r0_8, reg_r0_44, (unsigned int) 16); /* line 286 */
   __ADD(reg_r0_58, reg_r0_2, (unsigned int) 16); /* line 287 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 288 */
  sim_icache_fetch(144 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_14, reg_b0_3, reg_r0_14, reg_r0_12); /* line 290 */
   __CMPNE(reg_b0_2, reg_r0_23, 0); /* line 291 */
   __CMPEQ(reg_b0_3, reg_r0_23, reg_r0_4); /* line 292 */
   __ADD(reg_r0_10, reg_r0_15, (unsigned int) 16); /* line 293 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 294 */
  sim_icache_fetch(149 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_16, reg_b0_5, reg_r0_16, reg_r0_14); /* line 296 */
   __CMPNE(reg_b0_4, reg_r0_30, 0); /* line 297 */
   __CMPEQ(reg_b0_5, reg_r0_30, reg_r0_4); /* line 298 */
   __ADD(reg_r0_12, reg_r0_43, (unsigned int) 16); /* line 299 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 300 */
  sim_icache_fetch(154 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_18, reg_b0_7, reg_r0_18, reg_r0_16); /* line 302 */
   __CMPNE(reg_b0_6, reg_r0_31, 0); /* line 303 */
   __CMPEQ(reg_b0_7, reg_r0_31, reg_r0_4); /* line 304 */
   __ADD(reg_r0_14, reg_r0_42, (unsigned int) 16); /* line 305 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 306 */
  sim_icache_fetch(159 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_20, reg_b0_1, reg_r0_20, reg_r0_18); /* line 308 */
   __CMPNE(reg_b0_0, reg_r0_32, 0); /* line 309 */
   __CMPEQ(reg_b0_1, reg_r0_32, reg_r0_4); /* line 310 */
   __ADD(reg_r0_16, reg_r0_41, (unsigned int) 16); /* line 311 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 312 */
  sim_icache_fetch(164 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_22, reg_b0_3, reg_r0_22, reg_r0_20); /* line 314 */
   __CMPNE(reg_b0_2, reg_r0_33, 0); /* line 315 */
   __CMPEQ(reg_b0_3, reg_r0_33, reg_r0_4); /* line 316 */
   __ADD(reg_r0_18, reg_r0_40, (unsigned int) 16); /* line 317 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 318 */
  sim_icache_fetch(169 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_24, reg_b0_5, reg_r0_24, reg_r0_22); /* line 320 */
   __CMPNE(reg_b0_4, reg_r0_34, 0); /* line 321 */
   __CMPEQ(reg_b0_5, reg_r0_34, reg_r0_4); /* line 322 */
   __ADD(reg_r0_20, reg_r0_13, (unsigned int) 16); /* line 323 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 324 */
  sim_icache_fetch(174 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_25, reg_b0_7, reg_r0_25, reg_r0_24); /* line 326 */
   __CMPNE(reg_b0_6, reg_r0_35, 0); /* line 327 */
   __CMPEQ(reg_b0_7, reg_r0_35, reg_r0_4); /* line 328 */
   __ADD(reg_r0_22, reg_r0_11, (unsigned int) 16); /* line 329 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 330 */
  sim_icache_fetch(179 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_26, reg_b0_1, reg_r0_26, reg_r0_25); /* line 332 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 333 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_4); /* line 334 */
   __ADD(reg_r0_24, reg_r0_7, (unsigned int) 16); /* line 335 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 336 */
  sim_icache_fetch(184 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_27, reg_b0_3, reg_r0_27, reg_r0_26); /* line 338 */
   __CMPNE(reg_b0_2, reg_r0_46, 0); /* line 339 */
   __CMPEQ(reg_b0_3, reg_r0_46, reg_r0_4); /* line 340 */
   __ADD(reg_r0_25, reg_r0_3, (unsigned int) 16); /* line 341 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 342 */
  sim_icache_fetch(189 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_28, reg_b0_5, reg_r0_28, reg_r0_27); /* line 344 */
   __CMPNE(reg_b0_4, reg_r0_17, 0); /* line 345 */
   __CMPEQ(reg_b0_5, reg_r0_17, reg_r0_4); /* line 346 */
   __ADD(reg_r0_26, reg_r0_39, (unsigned int) 16); /* line 347 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 348 */
  sim_icache_fetch(194 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_29, reg_r0_28); /* line 350 */
   __CMPNE(reg_b0_6, reg_r0_48, 0); /* line 351 */
   __CMPEQ(reg_b0_7, reg_r0_48, reg_r0_4); /* line 352 */
   __ADD(reg_r0_27, reg_r0_38, (unsigned int) 16); /* line 353 */
   __ADD(reg_r0_29, reg_r0_45, (unsigned int) 16); /* line 354 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 355 */
  sim_icache_fetch(200 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_9, reg_b0_1, reg_r0_2, reg_r0_5); /* line 357 */
   __CMPNE(reg_b0_0, reg_r0_47, 0); /* line 358 */
   __CMPEQ(reg_b0_1, reg_r0_47, reg_r0_4); /* line 359 */
   __ADD(reg_r0_28, reg_r0_37, (unsigned int) 16); /* line 360 */
   __MOV(reg_r0_2, reg_r0_58); /* line 361 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 362 */
  sim_icache_fetch(206 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_36, reg_b0_3, reg_r0_36, reg_r0_9); /* line 364 */
   __CMPNE(reg_b0_2, reg_r0_49, 0); /* line 365 */
   __CMPEQ(reg_b0_3, reg_r0_49, reg_r0_4); /* line 366 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 367 */
  sim_icache_fetch(210 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_44, reg_b0_5, reg_r0_44, reg_r0_36); /* line 369 */
   __CMPNE(reg_b0_4, reg_r0_50, 0); /* line 370 */
   __CMPEQ(reg_b0_5, reg_r0_50, reg_r0_4); /* line 371 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 372 */
  sim_icache_fetch(214 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_15, reg_b0_7, reg_r0_15, reg_r0_44); /* line 374 */
   __CMPNE(reg_b0_6, reg_r0_51, 0); /* line 375 */
   __CMPEQ(reg_b0_7, reg_r0_51, reg_r0_4); /* line 376 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 377 */
  sim_icache_fetch(218 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_43, reg_b0_1, reg_r0_43, reg_r0_15); /* line 379 */
   __CMPNE(reg_b0_0, reg_r0_19, 0); /* line 380 */
   __CMPEQ(reg_b0_1, reg_r0_19, reg_r0_4); /* line 381 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 382 */
  sim_icache_fetch(222 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_42, reg_b0_3, reg_r0_42, reg_r0_43); /* line 384 */
   __CMPNE(reg_b0_2, reg_r0_52, 0); /* line 385 */
   __CMPEQ(reg_b0_3, reg_r0_52, reg_r0_4); /* line 386 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 387 */
  sim_icache_fetch(226 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_41, reg_b0_5, reg_r0_41, reg_r0_42); /* line 389 */
   __CMPNE(reg_b0_4, reg_r0_53, 0); /* line 390 */
   __CMPEQ(reg_b0_5, reg_r0_53, reg_r0_4); /* line 391 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 392 */
  sim_icache_fetch(230 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_40, reg_b0_7, reg_r0_40, reg_r0_41); /* line 394 */
   __CMPNE(reg_b0_6, reg_r0_54, 0); /* line 395 */
   __CMPEQ(reg_b0_7, reg_r0_54, reg_r0_4); /* line 396 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 397 */
  sim_icache_fetch(234 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_13, reg_b0_1, reg_r0_13, reg_r0_40); /* line 399 */
   __CMPNE(reg_b0_0, reg_r0_55, 0); /* line 400 */
   __CMPEQ(reg_b0_1, reg_r0_55, reg_r0_4); /* line 401 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 402 */
  sim_icache_fetch(238 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_11, reg_b0_3, reg_r0_11, reg_r0_13); /* line 404 */
   __CMPNE(reg_b0_2, reg_r0_56, 0); /* line 405 */
   __CMPEQ(reg_b0_3, reg_r0_56, reg_r0_4); /* line 406 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 407 */
  sim_icache_fetch(242 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_5, reg_r0_7, reg_r0_11); /* line 409 */
   __CMPNE(reg_b0_4, reg_r0_21, 0); /* line 410 */
   __CMPEQ(reg_b0_5, reg_r0_21, reg_r0_4); /* line 411 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 412 */
  sim_icache_fetch(246 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_7, reg_r0_3, reg_r0_7); /* line 414 */
   __CMPNE(reg_b0_6, reg_r0_57, 0); /* line 415 */
   __CMPEQ(reg_b0_7, reg_r0_57, reg_r0_4); /* line 416 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 417 */
  sim_icache_fetch(250 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_39, reg_b0_1, reg_r0_39, reg_r0_3); /* line 419 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 420 */
  sim_icache_fetch(252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_38, reg_b0_3, reg_r0_38, reg_r0_39); /* line 422 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 423 */
  sim_icache_fetch(254 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_37, reg_b0_5, reg_r0_37, reg_r0_38); /* line 425 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 426 */
  sim_icache_fetch(256 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_45, reg_r0_37); /* line 428 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 430 */
  sim_icache_fetch(258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 432 */
l_L31X3: ;/* line 435 */
__LABEL(l_L31X3);
  sim_icache_fetch(259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_28, reg_r0_37); /* line 436 */
} /* line 436 */
l_L16X3: ;/* line 439 */
__LABEL(l_L16X3);
  sim_icache_fetch(260 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_28); /* line 440 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 441 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 442 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 443 */
l_L30X3: ;/* line 446 */
__LABEL(l_L30X3);
  sim_icache_fetch(264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_27, reg_r0_38); /* line 447 */
} /* line 447 */
l_L15X3: ;/* line 450 */
__LABEL(l_L15X3);
  sim_icache_fetch(265 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_27); /* line 451 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 452 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 453 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 454 */
l_L29X3: ;/* line 457 */
__LABEL(l_L29X3);
  sim_icache_fetch(269 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_26, reg_r0_39); /* line 458 */
} /* line 458 */
l_L14X3: ;/* line 461 */
__LABEL(l_L14X3);
  sim_icache_fetch(270 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_26); /* line 462 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 463 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 464 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 465 */
l_L28X3: ;/* line 468 */
__LABEL(l_L28X3);
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_25, reg_r0_3); /* line 469 */
} /* line 469 */
l_L13X3: ;/* line 472 */
__LABEL(l_L13X3);
  sim_icache_fetch(275 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_25); /* line 473 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 474 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 475 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 476 */
l_L27X3: ;/* line 479 */
__LABEL(l_L27X3);
  sim_icache_fetch(279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_24, reg_r0_7); /* line 480 */
} /* line 480 */
l_L12X3: ;/* line 483 */
__LABEL(l_L12X3);
  sim_icache_fetch(280 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_24); /* line 484 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 485 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 486 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 487 */
l_L26X3: ;/* line 490 */
__LABEL(l_L26X3);
  sim_icache_fetch(284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_11); /* line 491 */
} /* line 491 */
l_L11X3: ;/* line 494 */
__LABEL(l_L11X3);
  sim_icache_fetch(285 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_22); /* line 495 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 496 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 497 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 498 */
l_L25X3: ;/* line 501 */
__LABEL(l_L25X3);
  sim_icache_fetch(289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_20, reg_r0_13); /* line 502 */
} /* line 502 */
l_L10X3: ;/* line 505 */
__LABEL(l_L10X3);
  sim_icache_fetch(290 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_20); /* line 506 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 507 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 508 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 509 */
l_L24X3: ;/* line 512 */
__LABEL(l_L24X3);
  sim_icache_fetch(294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_40); /* line 513 */
} /* line 513 */
l_L9X3: ;/* line 516 */
__LABEL(l_L9X3);
  sim_icache_fetch(295 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_18); /* line 517 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 518 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 519 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 520 */
l_L23X3: ;/* line 523 */
__LABEL(l_L23X3);
  sim_icache_fetch(299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, reg_r0_41); /* line 524 */
} /* line 524 */
l_L8X3: ;/* line 527 */
__LABEL(l_L8X3);
  sim_icache_fetch(300 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_16); /* line 528 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 529 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 530 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 531 */
l_L22X3: ;/* line 534 */
__LABEL(l_L22X3);
  sim_icache_fetch(304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_14, reg_r0_42); /* line 535 */
} /* line 535 */
l_L7X3: ;/* line 538 */
__LABEL(l_L7X3);
  sim_icache_fetch(305 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_14); /* line 539 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 540 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 541 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 542 */
l_L21X3: ;/* line 545 */
__LABEL(l_L21X3);
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, reg_r0_43); /* line 546 */
} /* line 546 */
l_L6X3: ;/* line 549 */
__LABEL(l_L6X3);
  sim_icache_fetch(310 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_12); /* line 550 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 551 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 552 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 553 */
l_L20X3: ;/* line 556 */
__LABEL(l_L20X3);
  sim_icache_fetch(314 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_15); /* line 557 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 558 */
l_L19X3: ;/* line 561 */
__LABEL(l_L19X3);
  sim_icache_fetch(316 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_44); /* line 562 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 563 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 564 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 565 */
l_L18X3: ;/* line 568 */
__LABEL(l_L18X3);
  sim_icache_fetch(320 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_36); /* line 569 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 570 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 571 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 572 */
l_L17X3: ;/* line 575 */
__LABEL(l_L17X3);
  sim_icache_fetch(324 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_9); /* line 576 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 577 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 578 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 579 */
l_L1X3: ;/* line 582 */
__LABEL(l_L1X3);
  sim_icache_fetch(328 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_5); /* line 583 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 584 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 585 */
} /* line 585 */
l_L32X3: ;/* line 587 */
__LABEL(l_L32X3);
  sim_icache_fetch(331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 589 */
l_L5X3: ;/* line 592 */
__LABEL(l_L5X3);
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_10); /* line 593 */
} /* line 593 */
l_L33X3: ;/* line 595 */
__LABEL(l_L33X3);
  sim_icache_fetch(333 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 596 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 597 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 598 */
l_L4X3: ;/* line 601 */
__LABEL(l_L4X3);
  sim_icache_fetch(336 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_8); /* line 602 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 603 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 604 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 605 */
l_L3X3: ;/* line 608 */
__LABEL(l_L3X3);
  sim_icache_fetch(340 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_6); /* line 609 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 610 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 611 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 612 */
l_L2X3: ;/* line 615 */
__LABEL(l_L2X3);
  sim_icache_fetch(344 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_9); /* line 616 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 617 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 618 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 619 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 111: goto l_L0X3;
    case 112: goto l_L31X3;
    case 113: goto l_L16X3;
    case 114: goto l_L30X3;
    case 115: goto l_L15X3;
    case 116: goto l_L29X3;
    case 117: goto l_L14X3;
    case 118: goto l_L28X3;
    case 119: goto l_L13X3;
    case 120: goto l_L27X3;
    case 121: goto l_L12X3;
    case 122: goto l_L26X3;
    case 123: goto l_L11X3;
    case 124: goto l_L25X3;
    case 125: goto l_L10X3;
    case 126: goto l_L24X3;
    case 127: goto l_L9X3;
    case 128: goto l_L23X3;
    case 129: goto l_L8X3;
    case 130: goto l_L22X3;
    case 131: goto l_L7X3;
    case 132: goto l_L21X3;
    case 133: goto l_L6X3;
    case 134: goto l_L20X3;
    case 135: goto l_L19X3;
    case 136: goto l_L18X3;
    case 137: goto l_L17X3;
    case 138: goto l_L1X3;
    case 139: goto l_L32X3;
    case 140: goto l_L5X3;
    case 141: goto l_L33X3;
    case 142: goto l_L4X3;
    case 143: goto l_L3X3;
    case 144: goto l_L2X3;
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

  sim_icache_fetch(348 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 636 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 637 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 638 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 639 */
} /* line 639 */
  sim_icache_fetch(355 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 641 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 642 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 643 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 644 */
} /* line 644 */
  sim_icache_fetch(360 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 646 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 647 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 648 */
} /* line 648 */
		 /* line 649 */
  sim_icache_fetch(363 + t_thisfile.offset, 2);
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
} /* line 651 */
l_lr_46: ;/* line 651 */
__LABEL(l_lr_46);
  sim_icache_fetch(365 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 653 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 654 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 655 */
   __ADD_CYCLES(1);
} /* line 655 */
  sim_icache_fetch(368 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 657 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 658 */
} /* line 658 */
l_L34X3: ;/* line 661 */
__LABEL(l_L34X3);
  sim_icache_fetch(370 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 662 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 663 */
} /* line 663 */
  sim_icache_fetch(372 + t_thisfile.offset, 1);
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
} /* line 665 */
  sim_icache_fetch(373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 667 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 668 */
   __ADD_CYCLES(1);
} /* line 668 */
  sim_icache_fetch(375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 670 */
} /* line 670 */
  sim_icache_fetch(376 + t_thisfile.offset, 1);
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
} /* line 672 */
l_L37X3: ;/* line 675 */
__LABEL(l_L37X3);
  sim_icache_fetch(377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 676 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 677 */
   __ADD_CYCLES(1);
} /* line 677 */
  sim_icache_fetch(379 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 679 */
} /* line 679 */
  sim_icache_fetch(380 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 681 */
} /* line 681 */
  sim_icache_fetch(381 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 683 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 684 */
   __ADD_CYCLES(1);
} /* line 684 */
  sim_icache_fetch(383 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 686 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 687 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 688 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 689 */
} /* line 689 */
  sim_icache_fetch(388 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 691 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 692 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 693 */
  sim_icache_fetch(391 + t_thisfile.offset, 1);
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
} /* line 695 */
  sim_icache_fetch(392 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 696 */
  sim_icache_fetch(393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 698 */
l__X1XCompressXTAGX0X0: ;/* line 700 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(394 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 701 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 702 */
l__X1XCompressXTAGX0X7: ;/* line 705 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(397 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 706 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 707 */
l__X1XCompressXTAGX0X6: ;/* line 710 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(400 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 711 */
} /* line 711 */
  sim_icache_fetch(401 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 713 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 714 */
l__X1XCompressXTAGX0X5: ;/* line 717 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(404 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 718 */
} /* line 718 */
  sim_icache_fetch(405 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 720 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 721 */
l__X1XCompressXTAGX0X4: ;/* line 724 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(408 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 725 */
} /* line 725 */
  sim_icache_fetch(409 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 727 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 728 */
l__X1XCompressXTAGX0X3: ;/* line 731 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(412 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 732 */
} /* line 732 */
  sim_icache_fetch(413 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 734 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 735 */
l__X1XCompressXTAGX0X2: ;/* line 738 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(416 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 739 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 740 */
   __ADD_CYCLES(1);
} /* line 740 */
  sim_icache_fetch(418 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 742 */
} /* line 742 */
  sim_icache_fetch(419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 744 */
} /* line 744 */
  sim_icache_fetch(420 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 746 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 747 */
   __ADD_CYCLES(1);
} /* line 747 */
  sim_icache_fetch(422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 749 */
} /* line 749 */
  sim_icache_fetch(423 + t_thisfile.offset, 1);
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
} /* line 751 */
l_L36X3: ;/* line 753 */
__LABEL(l_L36X3);
  sim_icache_fetch(424 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 754 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 755 */
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 756 */
l_L40X3: ;/* line 759 */
__LABEL(l_L40X3);
  sim_icache_fetch(427 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 760 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 761 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 762 */
} /* line 762 */
  sim_icache_fetch(430 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 764 */
} /* line 764 */
  sim_icache_fetch(431 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 766 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 767 */
  sim_icache_fetch(433 + t_thisfile.offset, 1);
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
} /* line 770 */
  sim_icache_fetch(434 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 772 */
l_L41X3: ;/* line 775 */
__LABEL(l_L41X3);
		 /* line 775 */
  sim_icache_fetch(435 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 778 */
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
} /* line 778 */
l_lr_60: ;/* line 778 */
__LABEL(l_lr_60);
		 /* line 779 */
  sim_icache_fetch(439 + t_thisfile.offset, 2);
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
} /* line 781 */
l_lr_62: ;/* line 781 */
__LABEL(l_lr_62);
  sim_icache_fetch(441 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 783 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 784 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 785 */
   __ADD_CYCLES(1);
} /* line 785 */
  sim_icache_fetch(444 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 788 */
l__X1XCompressXTAGX0X1: ;/* line 791 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 791 */
  sim_icache_fetch(445 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 794 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 795 */
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
} /* line 795 */
l_lr_65: ;/* line 795 */
__LABEL(l_lr_65);
  sim_icache_fetch(449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 797 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 798 */
} /* line 798 */
  sim_icache_fetch(451 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 800 */
l_L39X3: ;/* line 803 */
__LABEL(l_L39X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 804 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 804 */
  sim_icache_fetch(452 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 807 */
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
} /* line 807 */
l_lr_69: ;/* line 807 */
__LABEL(l_lr_69);
		 /* line 808 */
  sim_icache_fetch(456 + t_thisfile.offset, 2);
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
} /* line 810 */
l_lr_71: ;/* line 810 */
__LABEL(l_lr_71);
  sim_icache_fetch(458 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 812 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 813 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 814 */
   __ADD_CYCLES(1);
} /* line 814 */
  sim_icache_fetch(461 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 817 */
l_L38X3: ;/* line 820 */
__LABEL(l_L38X3);
  sim_icache_fetch(462 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 821 */
l_L35X3: ;/* line 824 */
__LABEL(l_L35X3);
  sim_icache_fetch(463 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 825 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 826 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 827 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 828 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 829 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 830 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 831 */
   __ADD_CYCLES(1);
} /* line 831 */
  sim_icache_fetch(473 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 833 */
   __CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 4096); /* line 834 */
} /* line 834 */
  sim_icache_fetch(476 + t_thisfile.offset, 1);
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
} /* line 836 */
  sim_icache_fetch(477 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 838 */
} /* line 838 */
l_L43X3: ;/* line 840 */
__LABEL(l_L43X3);
  sim_icache_fetch(479 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 841 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 842 */
   __ADD_CYCLES(1);
} /* line 842 */
  sim_icache_fetch(482 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 844 */
} /* line 844 */
  sim_icache_fetch(483 + t_thisfile.offset, 1);
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
} /* line 846 */
  sim_icache_fetch(484 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 848 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 849 */
} /* line 849 */
l_L45X3: ;/* line 851 */
__LABEL(l_L45X3);
  sim_icache_fetch(488 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 852 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 853 */
   __ADD_CYCLES(1);
} /* line 853 */
  sim_icache_fetch(491 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 855 */
} /* line 855 */
  sim_icache_fetch(492 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 857 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L46X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 858 */
		 /* line 859 */
  sim_icache_fetch(495 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 861 */
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
} /* line 862 */
l_lr_77: ;/* line 862 */
__LABEL(l_lr_77);
l_L47X3: ;/* line 864 */
__LABEL(l_L47X3);
  sim_icache_fetch(499 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 865 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 866 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 867 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 868 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 869 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 870 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 871 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 872 */
} /* line 872 */
  sim_icache_fetch(515 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 874 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 875 */
} /* line 875 */
  sim_icache_fetch(519 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 877 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 878 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 879 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 880 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 881 */
} /* line 881 */
  sim_icache_fetch(525 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 883 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 884 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 885 */
  sim_icache_fetch(528 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 887 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 888 */
  sim_icache_fetch(531 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 890 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 891 */
l_L51X3: ;/* line 893 */
__LABEL(l_L51X3);
		 /* line 893 */
  sim_icache_fetch(534 + t_thisfile.offset, 2);
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
} /* line 895 */
l_lr_81: ;/* line 895 */
__LABEL(l_lr_81);
  sim_icache_fetch(536 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 897 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 898 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 899 */
   __ADD_CYCLES(1);
} /* line 899 */
  sim_icache_fetch(539 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 902 */
l_L50X3: ;/* line 905 */
__LABEL(l_L50X3);
  sim_icache_fetch(540 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 906 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 907 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 908 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 909 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 910 */
   __ADD_CYCLES(1);
} /* line 910 */
  sim_icache_fetch(549 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 912 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 913 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 914 */
} /* line 914 */
  sim_icache_fetch(552 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 916 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 917 */
} /* line 917 */
  sim_icache_fetch(555 + t_thisfile.offset, 1);
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
} /* line 919 */
  sim_icache_fetch(556 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 921 */
} /* line 921 */
  sim_icache_fetch(558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 923 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 924 */
   __ADD_CYCLES(1);
} /* line 924 */
  sim_icache_fetch(560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 926 */
} /* line 926 */
l_L53X3: ;/* line 928 */
__LABEL(l_L53X3);
  sim_icache_fetch(561 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 929 */
} /* line 929 */
  sim_icache_fetch(562 + t_thisfile.offset, 1);
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
} /* line 932 */
  sim_icache_fetch(563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 934 */
l_L54X3: ;/* line 937 */
__LABEL(l_L54X3);
  sim_icache_fetch(564 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 938 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 939 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 940 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 941 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 942 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 943 */
   __ADD_CYCLES(1);
} /* line 943 */
  sim_icache_fetch(574 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 945 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 946 */
} /* line 946 */
  sim_icache_fetch(576 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 948 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 949 */
} /* line 949 */
  sim_icache_fetch(579 + t_thisfile.offset, 1);
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
} /* line 951 */
  sim_icache_fetch(580 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 953 */
} /* line 953 */
  sim_icache_fetch(582 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 955 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 956 */
   __ADD_CYCLES(1);
} /* line 956 */
  sim_icache_fetch(584 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 958 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 959 */
} /* line 959 */
l_L56X3: ;/* line 961 */
__LABEL(l_L56X3);
  sim_icache_fetch(587 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 962 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 963 */
} /* line 963 */
  sim_icache_fetch(589 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 965 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 966 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 967 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 968 */
} /* line 968 */
  sim_icache_fetch(595 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 970 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 971 */
		 /* line 972 */
  sim_icache_fetch(598 + t_thisfile.offset, 2);
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
} /* line 974 */
l_lr_87: ;/* line 974 */
__LABEL(l_lr_87);
  sim_icache_fetch(600 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 976 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 977 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 978 */
   __ADD_CYCLES(1);
} /* line 978 */
  sim_icache_fetch(603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 981 */
l_L48X3: ;/* line 984 */
__LABEL(l_L48X3);
		 /* line 984 */
  sim_icache_fetch(604 + t_thisfile.offset, 2);
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
} /* line 986 */
l_lr_90: ;/* line 986 */
__LABEL(l_lr_90);
  sim_icache_fetch(606 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 988 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 989 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 990 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 991 */
   __ADD_CYCLES(1);
} /* line 991 */
  sim_icache_fetch(610 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 994 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 995 */
l_L55X3: ;/* line 998 */
__LABEL(l_L55X3);
  sim_icache_fetch(613 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 999 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 1000 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 1001 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 1002 */
} /* line 1002 */
  sim_icache_fetch(619 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 1004 */
   __GOTO(l_L56X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L56X3;
} /* line 1005 */
l_L52X3: ;/* line 1008 */
__LABEL(l_L52X3);
  sim_icache_fetch(622 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 1009 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1010 */
   __GOTO(l_L53X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L53X3;
} /* line 1011 */
l_L49X3: ;/* line 1014 */
__LABEL(l_L49X3);
  sim_icache_fetch(626 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 1015 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1016 */
} /* line 1016 */
  sim_icache_fetch(629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1018 */
} /* line 1018 */
  sim_icache_fetch(630 + t_thisfile.offset, 1);
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
} /* line 1021 */
  sim_icache_fetch(631 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 1023 */
l_L46X3: ;/* line 1026 */
__LABEL(l_L46X3);
  sim_icache_fetch(632 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1027 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1028 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1029 */
   __ADD_CYCLES(1);
} /* line 1029 */
  sim_icache_fetch(637 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1031 */
} /* line 1031 */
  sim_icache_fetch(639 + t_thisfile.offset, 1);
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
} /* line 1033 */
		 /* line 1034 */
  sim_icache_fetch(640 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1036 */
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
} /* line 1037 */
l_lr_96: ;/* line 1037 */
__LABEL(l_lr_96);
  sim_icache_fetch(644 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1039 */
l_L57X3: ;/* line 1042 */
__LABEL(l_L57X3);
  sim_icache_fetch(645 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1043 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1044 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1045 */
   __ADD_CYCLES(1);
} /* line 1045 */
  sim_icache_fetch(650 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1047 */
} /* line 1047 */
  sim_icache_fetch(652 + t_thisfile.offset, 1);
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
} /* line 1049 */
		 /* line 1050 */
  sim_icache_fetch(653 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1052 */
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
} /* line 1053 */
l_lr_99: ;/* line 1053 */
__LABEL(l_lr_99);
  sim_icache_fetch(657 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1055 */
l_L58X3: ;/* line 1058 */
__LABEL(l_L58X3);
  sim_icache_fetch(658 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1059 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1060 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1061 */
   __ADD_CYCLES(1);
} /* line 1061 */
  sim_icache_fetch(663 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1063 */
} /* line 1063 */
  sim_icache_fetch(665 + t_thisfile.offset, 1);
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
} /* line 1065 */
		 /* line 1066 */
  sim_icache_fetch(666 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1068 */
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
} /* line 1069 */
l_lr_102: ;/* line 1069 */
__LABEL(l_lr_102);
  sim_icache_fetch(670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1071 */
l_L59X3: ;/* line 1074 */
__LABEL(l_L59X3);
  sim_icache_fetch(671 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1075 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1076 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1077 */
   __ADD_CYCLES(1);
} /* line 1077 */
  sim_icache_fetch(676 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(678 + t_thisfile.offset, 1);
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
} /* line 1081 */
		 /* line 1082 */
  sim_icache_fetch(679 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1084 */
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
} /* line 1085 */
l_lr_105: ;/* line 1085 */
__LABEL(l_lr_105);
  sim_icache_fetch(683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1087 */
l_L60X3: ;/* line 1090 */
__LABEL(l_L60X3);
		 /* line 1090 */
  sim_icache_fetch(684 + t_thisfile.offset, 2);
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
} /* line 1092 */
l_lr_108: ;/* line 1092 */
__LABEL(l_lr_108);
  sim_icache_fetch(686 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1094 */
l_L44X3: ;/* line 1097 */
__LABEL(l_L44X3);
  sim_icache_fetch(687 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1098 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1099 */
} /* line 1099 */
  sim_icache_fetch(690 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1101 */
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 1102 */
l_L42X3: ;/* line 1105 */
__LABEL(l_L42X3);
  sim_icache_fetch(693 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1106 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1107 */
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1108 */
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

  sim_icache_fetch(696 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1246 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1247 */
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1248 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1249 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1250 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1251 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1252 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1253 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1254 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1255 */
} /* line 1255 */
  sim_icache_fetch(712 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1257 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1258 */
   __MOV(reg_r0_4, 0); /* line 1259 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1260 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1261 */
} /* line 1261 */
  sim_icache_fetch(720 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1263 */
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 1264 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1265 */
} /* line 1265 */
  sim_icache_fetch(723 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, (unsigned int) 256); /* line 1267 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 1268 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 1); /* line 1269 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1270 */
l_L62X3: ;/* line 1272 */
__LABEL(l_L62X3);
  sim_icache_fetch(728 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((unsigned int) compress_12192Xoffset,0,4), 0); /* line 1273 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1274 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1275 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1276 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1277 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1278 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1279 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1280 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1281 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1282 */
} /* line 1282 */
  sim_icache_fetch(748 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1284 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1285 */
  sim_icache_fetch(751 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 1287 */
} /* line 1287 */
  sim_icache_fetch(753 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1289 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1290 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1291 */
   __ADD_CYCLES(1);
} /* line 1291 */
  sim_icache_fetch(756 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1293 */
} /* line 1293 */
l_L64X3: ;/* line 1295 */
__LABEL(l_L64X3);
  sim_icache_fetch(757 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1296 */
} /* line 1296 */
l_L65X3: ;/* line 1299 */
__LABEL(l_L65X3);
  sim_icache_fetch(758 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1300 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1301 */
} /* line 1301 */
  sim_icache_fetch(760 + t_thisfile.offset, 3);
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
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1305 */
  sim_icache_fetch(763 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1309 */
  sim_icache_fetch(766 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1313 */
  sim_icache_fetch(769 + t_thisfile.offset, 3);
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
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1317 */
  sim_icache_fetch(772 + t_thisfile.offset, 3);
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
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1321 */
  sim_icache_fetch(775 + t_thisfile.offset, 3);
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
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1325 */
  sim_icache_fetch(778 + t_thisfile.offset, 3);
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
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1329 */
  sim_icache_fetch(781 + t_thisfile.offset, 3);
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
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1333 */
  sim_icache_fetch(784 + t_thisfile.offset, 3);
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
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1337 */
  sim_icache_fetch(787 + t_thisfile.offset, 3);
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
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1341 */
  sim_icache_fetch(790 + t_thisfile.offset, 3);
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
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1345 */
  sim_icache_fetch(793 + t_thisfile.offset, 3);
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
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1349 */
  sim_icache_fetch(796 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1351 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1352 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1353 */
  sim_icache_fetch(799 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1355 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1356 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1357 */
  sim_icache_fetch(802 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1359 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1360 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1361 */
  sim_icache_fetch(805 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1363 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1364 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1365 */
  sim_icache_fetch(808 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1367 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1368 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1369 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1370 */
  sim_icache_fetch(812 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1374 */
  sim_icache_fetch(815 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1378 */
  sim_icache_fetch(818 + t_thisfile.offset, 3);
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
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1382 */
  sim_icache_fetch(821 + t_thisfile.offset, 3);
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
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1386 */
  sim_icache_fetch(824 + t_thisfile.offset, 3);
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
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1390 */
  sim_icache_fetch(827 + t_thisfile.offset, 3);
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
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1394 */
  sim_icache_fetch(830 + t_thisfile.offset, 3);
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
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1398 */
  sim_icache_fetch(833 + t_thisfile.offset, 3);
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
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1402 */
  sim_icache_fetch(836 + t_thisfile.offset, 3);
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
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1406 */
  sim_icache_fetch(839 + t_thisfile.offset, 3);
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
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1410 */
  sim_icache_fetch(842 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1412 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1413 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1414 */
  sim_icache_fetch(845 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1416 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1417 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1418 */
  sim_icache_fetch(848 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1420 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1421 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1422 */
  sim_icache_fetch(851 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1424 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1425 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1426 */
  sim_icache_fetch(854 + t_thisfile.offset, 1);
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
} /* line 1428 */
  sim_icache_fetch(855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1430 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 1431 */
l_L81X3: ;/* line 1434 */
__LABEL(l_L81X3);
  sim_icache_fetch(857 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1435 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1436 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1437 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1438 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1439 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1440 */
l_L83X3: ;/* line 1443 */
__LABEL(l_L83X3);
  sim_icache_fetch(864 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1444 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1445 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1446 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1447 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1448 */
   __ADD_CYCLES(1);
} /* line 1448 */
  sim_icache_fetch(873 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1450 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1451 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1452 */
} /* line 1452 */
  sim_icache_fetch(876 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1454 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1455 */
} /* line 1455 */
  sim_icache_fetch(879 + t_thisfile.offset, 1);
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
} /* line 1457 */
  sim_icache_fetch(880 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1459 */
} /* line 1459 */
  sim_icache_fetch(882 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1461 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1462 */
   __ADD_CYCLES(1);
} /* line 1462 */
  sim_icache_fetch(884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1464 */
} /* line 1464 */
l_L85X3: ;/* line 1466 */
__LABEL(l_L85X3);
  sim_icache_fetch(885 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1467 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1468 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1469 */
} /* line 1469 */
  sim_icache_fetch(888 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1471 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1472 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1473 */
  sim_icache_fetch(891 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1475 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1476 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1477 */
} /* line 1477 */
  sim_icache_fetch(897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1479 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1480 */
   __ADD_CYCLES(1);
} /* line 1480 */
  sim_icache_fetch(899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1482 */
} /* line 1482 */
  sim_icache_fetch(900 + t_thisfile.offset, 1);
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
} /* line 1484 */
  sim_icache_fetch(901 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1486 */
} /* line 1486 */
  sim_icache_fetch(902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1488 */
l_L87X3: ;/* line 1491 */
__LABEL(l_L87X3);
  sim_icache_fetch(903 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1492 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1493 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1494 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1495 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1496 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1497 */
} /* line 1497 */
  sim_icache_fetch(910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1499 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1500 */
   __ADD_CYCLES(1);
} /* line 1500 */
  sim_icache_fetch(912 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1502 */
} /* line 1502 */
  sim_icache_fetch(913 + t_thisfile.offset, 1);
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
} /* line 1504 */
l_L89X3: ;/* line 1506 */
__LABEL(l_L89X3);
		 /* line 1506 */
  sim_icache_fetch(914 + t_thisfile.offset, 2);
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
} /* line 1508 */
l_lr_121: ;/* line 1508 */
__LABEL(l_lr_121);
  sim_icache_fetch(916 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1510 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1511 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1512 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1513 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1514 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1515 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1516 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1517 */
   __ADD_CYCLES(1);
} /* line 1517 */
  sim_icache_fetch(927 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1519 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1520 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1521 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1522 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1523 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1524 */
} /* line 1524 */
  sim_icache_fetch(935 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1526 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1527 */
  sim_icache_fetch(938 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1529 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1530 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1531 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1532 */
l_L90X3: ;/* line 1535 */
__LABEL(l_L90X3);
  sim_icache_fetch(943 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1536 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1537 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1538 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1539 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1540 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1541 */
   __ADD_CYCLES(1);
} /* line 1541 */
  sim_icache_fetch(952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1543 */
} /* line 1543 */
  sim_icache_fetch(953 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1545 */
} /* line 1545 */
  sim_icache_fetch(954 + t_thisfile.offset, 1);
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
} /* line 1547 */
		 /* line 1548 */
  sim_icache_fetch(955 + t_thisfile.offset, 2);
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
} /* line 1550 */
l_lr_124: ;/* line 1550 */
__LABEL(l_lr_124);
  sim_icache_fetch(957 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1552 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1553 */
} /* line 1553 */
  sim_icache_fetch(959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1555 */
l_L91X3: ;/* line 1558 */
__LABEL(l_L91X3);
  sim_icache_fetch(960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1559 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1560 */
} /* line 1560 */
  sim_icache_fetch(962 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1562 */
l_L88X3: ;/* line 1565 */
__LABEL(l_L88X3);
  sim_icache_fetch(963 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1566 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1567 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1568 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1569 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1570 */
   __ADD_CYCLES(1);
} /* line 1570 */
  sim_icache_fetch(968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1572 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1573 */
} /* line 1573 */
  sim_icache_fetch(970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1575 */
} /* line 1575 */
l_L92X3: ;/* line 1578 */
__LABEL(l_L92X3);
  sim_icache_fetch(971 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1579 */
} /* line 1579 */
  sim_icache_fetch(972 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1581 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1582 */
} /* line 1582 */
  sim_icache_fetch(974 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1584 */
} /* line 1584 */
  sim_icache_fetch(975 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1586 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1587 */
} /* line 1587 */
  sim_icache_fetch(978 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1589 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1590 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1591 */
} /* line 1591 */
  sim_icache_fetch(981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(982 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1595 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1596 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1597 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1598 */
} /* line 1598 */
  sim_icache_fetch(987 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1600 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1601 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1602 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1603 */
  sim_icache_fetch(991 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1605 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1606 */
  sim_icache_fetch(993 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1608 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1609 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1610 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1611 */
} /* line 1611 */
  sim_icache_fetch(998 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1613 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1614 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1615 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1616 */
  sim_icache_fetch(1002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1618 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1619 */
  sim_icache_fetch(1004 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1621 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1622 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1623 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1624 */
} /* line 1624 */
  sim_icache_fetch(1009 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1626 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1627 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1628 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1629 */
  sim_icache_fetch(1013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1631 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1632 */
  sim_icache_fetch(1015 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1634 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1635 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1636 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1637 */
} /* line 1637 */
  sim_icache_fetch(1020 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1639 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1640 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1641 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1642 */
  sim_icache_fetch(1024 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1644 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1645 */
  sim_icache_fetch(1026 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1647 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1648 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1649 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1650 */
} /* line 1650 */
  sim_icache_fetch(1031 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1652 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1653 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1654 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1655 */
  sim_icache_fetch(1035 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1657 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1658 */
  sim_icache_fetch(1037 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1660 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1661 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1662 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1663 */
} /* line 1663 */
  sim_icache_fetch(1042 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1665 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1666 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1667 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1668 */
  sim_icache_fetch(1046 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1670 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1671 */
  sim_icache_fetch(1048 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1673 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1674 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1675 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1676 */
} /* line 1676 */
  sim_icache_fetch(1053 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1678 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1679 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1680 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1681 */
  sim_icache_fetch(1057 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1683 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1684 */
  sim_icache_fetch(1059 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1686 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1687 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1688 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1689 */
} /* line 1689 */
  sim_icache_fetch(1064 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1691 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1692 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1693 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1694 */
  sim_icache_fetch(1068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1696 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1697 */
  sim_icache_fetch(1070 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1699 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1700 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1701 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1702 */
} /* line 1702 */
  sim_icache_fetch(1075 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1704 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1705 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1706 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1707 */
  sim_icache_fetch(1079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1709 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1710 */
  sim_icache_fetch(1081 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1712 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1713 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1714 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1715 */
} /* line 1715 */
  sim_icache_fetch(1086 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1717 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1718 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1719 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1720 */
  sim_icache_fetch(1090 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1722 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1723 */
  sim_icache_fetch(1092 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1725 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1726 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1727 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1728 */
} /* line 1728 */
  sim_icache_fetch(1097 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1730 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1731 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1732 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1733 */
  sim_icache_fetch(1101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1735 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1736 */
  sim_icache_fetch(1103 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1738 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1739 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1740 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1741 */
} /* line 1741 */
  sim_icache_fetch(1108 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1743 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1744 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1745 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1746 */
  sim_icache_fetch(1112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1748 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1749 */
  sim_icache_fetch(1114 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1751 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1752 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1753 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1754 */
} /* line 1754 */
  sim_icache_fetch(1119 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1756 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1757 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1758 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1759 */
  sim_icache_fetch(1123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1761 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1762 */
  sim_icache_fetch(1125 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1764 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1765 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1766 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1767 */
} /* line 1767 */
  sim_icache_fetch(1130 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1769 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1770 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1771 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1772 */
  sim_icache_fetch(1134 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1774 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1775 */
  sim_icache_fetch(1136 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1777 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1778 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1779 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1780 */
} /* line 1780 */
  sim_icache_fetch(1141 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1782 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1783 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1784 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1785 */
  sim_icache_fetch(1145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1787 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1788 */
  sim_icache_fetch(1147 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1790 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1791 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1792 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1793 */
} /* line 1793 */
  sim_icache_fetch(1152 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1795 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1796 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1797 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1798 */
  sim_icache_fetch(1156 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1800 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1801 */
  sim_icache_fetch(1158 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1803 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1804 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1805 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1806 */
} /* line 1806 */
  sim_icache_fetch(1163 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1808 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1809 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1810 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1811 */
  sim_icache_fetch(1167 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1813 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1814 */
  sim_icache_fetch(1169 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1816 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1817 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1818 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1819 */
} /* line 1819 */
  sim_icache_fetch(1174 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1821 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1822 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1823 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1824 */
  sim_icache_fetch(1178 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1826 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1827 */
  sim_icache_fetch(1180 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1829 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1830 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1831 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1832 */
} /* line 1832 */
  sim_icache_fetch(1185 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1834 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1835 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1836 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1837 */
  sim_icache_fetch(1189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1839 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1840 */
  sim_icache_fetch(1191 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1842 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1843 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1844 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1845 */
} /* line 1845 */
  sim_icache_fetch(1196 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1847 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1848 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1849 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1850 */
  sim_icache_fetch(1200 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1852 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1853 */
  sim_icache_fetch(1202 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1855 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1856 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1857 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1858 */
} /* line 1858 */
  sim_icache_fetch(1207 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1860 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1861 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1862 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1863 */
  sim_icache_fetch(1211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1865 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1866 */
  sim_icache_fetch(1213 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1868 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1869 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1870 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1871 */
} /* line 1871 */
  sim_icache_fetch(1218 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1873 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1874 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1875 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1876 */
  sim_icache_fetch(1222 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1878 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1879 */
  sim_icache_fetch(1224 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1881 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1882 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1883 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1884 */
} /* line 1884 */
  sim_icache_fetch(1229 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1886 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1887 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1888 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1889 */
  sim_icache_fetch(1233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1891 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1892 */
  sim_icache_fetch(1235 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1894 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1895 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1896 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1897 */
} /* line 1897 */
  sim_icache_fetch(1240 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1899 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1900 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1901 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1902 */
  sim_icache_fetch(1244 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1904 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1905 */
  sim_icache_fetch(1246 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1907 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1908 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1909 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1910 */
} /* line 1910 */
  sim_icache_fetch(1251 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1912 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1913 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1914 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1915 */
  sim_icache_fetch(1255 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1917 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1918 */
  sim_icache_fetch(1257 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1920 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1921 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1922 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1923 */
} /* line 1923 */
  sim_icache_fetch(1262 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1925 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1926 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1927 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1928 */
  sim_icache_fetch(1266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1930 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1931 */
  sim_icache_fetch(1268 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1933 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1934 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1935 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1936 */
} /* line 1936 */
  sim_icache_fetch(1273 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1938 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1939 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1940 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1941 */
  sim_icache_fetch(1277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1943 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1944 */
  sim_icache_fetch(1279 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1946 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1947 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1948 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1949 */
} /* line 1949 */
  sim_icache_fetch(1284 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1951 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1952 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1953 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1954 */
  sim_icache_fetch(1288 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1956 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1957 */
  sim_icache_fetch(1290 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1959 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1960 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1961 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1962 */
} /* line 1962 */
  sim_icache_fetch(1295 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1964 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1965 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1966 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1967 */
  sim_icache_fetch(1299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1969 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1970 */
  sim_icache_fetch(1301 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1972 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1973 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1974 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1975 */
} /* line 1975 */
  sim_icache_fetch(1306 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1977 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1978 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1979 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1980 */
  sim_icache_fetch(1310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1982 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1983 */
  sim_icache_fetch(1312 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1985 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1986 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1987 */
} /* line 1987 */
  sim_icache_fetch(1316 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1989 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1990 */
  sim_icache_fetch(1318 + t_thisfile.offset, 1);
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
} /* line 1992 */
  sim_icache_fetch(1319 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1994 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1995 */
} /* line 1995 */
  sim_icache_fetch(1321 + t_thisfile.offset, 1);
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
} /* line 1997 */
  sim_icache_fetch(1322 + t_thisfile.offset, 1);
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
} /* line 2000 */
  sim_icache_fetch(1323 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L92X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L92X3;
} /* line 2002 */
l_L156X3: ;/* line 2005 */
__LABEL(l_L156X3);
  sim_icache_fetch(1324 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2006 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2007 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2008 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2009 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2010 */
l_L155X3: ;/* line 2014 */
__LABEL(l_L155X3);
  sim_icache_fetch(1329 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2015 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2016 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2017 */
l_L154X3: ;/* line 2020 */
__LABEL(l_L154X3);
  sim_icache_fetch(1332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2021 */
} /* line 2021 */
l_L122X3: ;/* line 2024 */
__LABEL(l_L122X3);
  sim_icache_fetch(1333 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2025 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2026 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2027 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2028 */
} /* line 2028 */
  sim_icache_fetch(1337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2030 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2031 */
l_L153X3: ;/* line 2034 */
__LABEL(l_L153X3);
  sim_icache_fetch(1339 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2035 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2036 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2037 */
l_L152X3: ;/* line 2040 */
__LABEL(l_L152X3);
  sim_icache_fetch(1342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2041 */
} /* line 2041 */
l_L120X3: ;/* line 2044 */
__LABEL(l_L120X3);
  sim_icache_fetch(1343 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2045 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2046 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2047 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2048 */
} /* line 2048 */
  sim_icache_fetch(1347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2050 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2051 */
l_L151X3: ;/* line 2054 */
__LABEL(l_L151X3);
  sim_icache_fetch(1349 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2055 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2056 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2057 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2058 */
l_L150X3: ;/* line 2061 */
__LABEL(l_L150X3);
  sim_icache_fetch(1353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2062 */
} /* line 2062 */
l_L118X3: ;/* line 2065 */
__LABEL(l_L118X3);
  sim_icache_fetch(1354 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2066 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2067 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2068 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2069 */
} /* line 2069 */
  sim_icache_fetch(1358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2071 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2072 */
l_L149X3: ;/* line 2075 */
__LABEL(l_L149X3);
  sim_icache_fetch(1360 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2076 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2077 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2078 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2079 */
l_L148X3: ;/* line 2082 */
__LABEL(l_L148X3);
  sim_icache_fetch(1364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2083 */
} /* line 2083 */
l_L116X3: ;/* line 2086 */
__LABEL(l_L116X3);
  sim_icache_fetch(1365 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2087 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2088 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2089 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2090 */
} /* line 2090 */
  sim_icache_fetch(1369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2092 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2093 */
l_L147X3: ;/* line 2096 */
__LABEL(l_L147X3);
  sim_icache_fetch(1371 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2097 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2098 */
   __GOTO(l_L159X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L159X3;
} /* line 2099 */
l_L146X3: ;/* line 2102 */
__LABEL(l_L146X3);
  sim_icache_fetch(1374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2103 */
} /* line 2103 */
l_L114X3: ;/* line 2106 */
__LABEL(l_L114X3);
  sim_icache_fetch(1375 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2107 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2108 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2109 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2110 */
} /* line 2110 */
  sim_icache_fetch(1379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2112 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2113 */
l_L145X3: ;/* line 2116 */
__LABEL(l_L145X3);
  sim_icache_fetch(1381 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2117 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2118 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2119 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2120 */
l_L144X3: ;/* line 2123 */
__LABEL(l_L144X3);
  sim_icache_fetch(1385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2124 */
} /* line 2124 */
l_L112X3: ;/* line 2127 */
__LABEL(l_L112X3);
  sim_icache_fetch(1386 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2128 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2129 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2130 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2131 */
} /* line 2131 */
  sim_icache_fetch(1390 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2133 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2134 */
l_L143X3: ;/* line 2137 */
__LABEL(l_L143X3);
  sim_icache_fetch(1392 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2138 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2139 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2140 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2141 */
l_L142X3: ;/* line 2144 */
__LABEL(l_L142X3);
  sim_icache_fetch(1396 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2145 */
} /* line 2145 */
l_L110X3: ;/* line 2148 */
__LABEL(l_L110X3);
  sim_icache_fetch(1397 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2149 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2150 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2151 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2152 */
} /* line 2152 */
  sim_icache_fetch(1401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2154 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2155 */
l_L141X3: ;/* line 2158 */
__LABEL(l_L141X3);
  sim_icache_fetch(1403 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2159 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2160 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2161 */
l_L140X3: ;/* line 2164 */
__LABEL(l_L140X3);
  sim_icache_fetch(1406 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2165 */
} /* line 2165 */
l_L108X3: ;/* line 2168 */
__LABEL(l_L108X3);
  sim_icache_fetch(1407 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2169 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2170 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2171 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2172 */
} /* line 2172 */
  sim_icache_fetch(1411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2174 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2175 */
l_L139X3: ;/* line 2178 */
__LABEL(l_L139X3);
  sim_icache_fetch(1413 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2179 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2180 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2181 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2182 */
l_L138X3: ;/* line 2185 */
__LABEL(l_L138X3);
  sim_icache_fetch(1417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2186 */
} /* line 2186 */
l_L106X3: ;/* line 2189 */
__LABEL(l_L106X3);
  sim_icache_fetch(1418 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2190 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2191 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2192 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2193 */
} /* line 2193 */
  sim_icache_fetch(1422 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2195 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2196 */
l_L137X3: ;/* line 2199 */
__LABEL(l_L137X3);
  sim_icache_fetch(1424 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2200 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2201 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2202 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2203 */
l_L136X3: ;/* line 2206 */
__LABEL(l_L136X3);
  sim_icache_fetch(1428 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2207 */
} /* line 2207 */
l_L104X3: ;/* line 2210 */
__LABEL(l_L104X3);
  sim_icache_fetch(1429 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2211 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2212 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2213 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2214 */
} /* line 2214 */
  sim_icache_fetch(1433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2216 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2217 */
l_L135X3: ;/* line 2220 */
__LABEL(l_L135X3);
  sim_icache_fetch(1435 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2221 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2222 */
   __GOTO(l_L161X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L161X3;
} /* line 2223 */
l_L134X3: ;/* line 2226 */
__LABEL(l_L134X3);
  sim_icache_fetch(1438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2227 */
} /* line 2227 */
l_L102X3: ;/* line 2230 */
__LABEL(l_L102X3);
  sim_icache_fetch(1439 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2231 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2232 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2233 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2234 */
} /* line 2234 */
  sim_icache_fetch(1443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2236 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2237 */
l_L133X3: ;/* line 2240 */
__LABEL(l_L133X3);
  sim_icache_fetch(1445 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2241 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2242 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2243 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2244 */
l_L132X3: ;/* line 2247 */
__LABEL(l_L132X3);
  sim_icache_fetch(1449 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2248 */
} /* line 2248 */
l_L100X3: ;/* line 2251 */
__LABEL(l_L100X3);
  sim_icache_fetch(1450 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2252 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2253 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2254 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2255 */
} /* line 2255 */
  sim_icache_fetch(1454 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2257 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2258 */
l_L131X3: ;/* line 2261 */
__LABEL(l_L131X3);
  sim_icache_fetch(1456 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2262 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2263 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2264 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2265 */
l_L130X3: ;/* line 2268 */
__LABEL(l_L130X3);
  sim_icache_fetch(1460 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2269 */
} /* line 2269 */
l_L98X3: ;/* line 2272 */
__LABEL(l_L98X3);
  sim_icache_fetch(1461 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2273 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2274 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2275 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2276 */
} /* line 2276 */
  sim_icache_fetch(1465 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2278 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2279 */
l_L129X3: ;/* line 2282 */
__LABEL(l_L129X3);
  sim_icache_fetch(1467 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2283 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2284 */
   __GOTO(l_L162X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L162X3;
} /* line 2285 */
l_L128X3: ;/* line 2288 */
__LABEL(l_L128X3);
  sim_icache_fetch(1470 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2289 */
} /* line 2289 */
l_L96X3: ;/* line 2292 */
__LABEL(l_L96X3);
  sim_icache_fetch(1471 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2293 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2294 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2295 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2296 */
} /* line 2296 */
  sim_icache_fetch(1475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2298 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2299 */
l_L127X3: ;/* line 2302 */
__LABEL(l_L127X3);
  sim_icache_fetch(1477 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2303 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2304 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2305 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2306 */
l_L126X3: ;/* line 2309 */
__LABEL(l_L126X3);
  sim_icache_fetch(1481 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2310 */
} /* line 2310 */
l_L94X3: ;/* line 2314 */
__LABEL(l_L94X3);
  sim_icache_fetch(1482 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2315 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2316 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2317 */
} /* line 2317 */
  sim_icache_fetch(1485 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2319 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2320 */
l_L125X3: ;/* line 2323 */
__LABEL(l_L125X3);
  sim_icache_fetch(1487 + t_thisfile.offset, 4);
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
l_L124X3: ;/* line 2330 */
__LABEL(l_L124X3);
  sim_icache_fetch(1491 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2331 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2332 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2333 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2334 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2335 */
l_L123X3: ;/* line 2339 */
__LABEL(l_L123X3);
  sim_icache_fetch(1496 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2340 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2341 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2342 */
l_L121X3: ;/* line 2345 */
__LABEL(l_L121X3);
  sim_icache_fetch(1499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2346 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2347 */
} /* line 2347 */
l_L158X3: ;/* line 2349 */
__LABEL(l_L158X3);
  sim_icache_fetch(1501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2350 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2351 */
l_L119X3: ;/* line 2354 */
__LABEL(l_L119X3);
  sim_icache_fetch(1503 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2355 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2356 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2357 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2358 */
l_L117X3: ;/* line 2361 */
__LABEL(l_L117X3);
  sim_icache_fetch(1507 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2362 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2363 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2364 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2365 */
l_L115X3: ;/* line 2368 */
__LABEL(l_L115X3);
  sim_icache_fetch(1511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2369 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2370 */
} /* line 2370 */
l_L159X3: ;/* line 2372 */
__LABEL(l_L159X3);
  sim_icache_fetch(1513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2373 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2374 */
l_L113X3: ;/* line 2377 */
__LABEL(l_L113X3);
  sim_icache_fetch(1515 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2378 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2379 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2380 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2381 */
l_L111X3: ;/* line 2384 */
__LABEL(l_L111X3);
  sim_icache_fetch(1519 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2385 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2386 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2387 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2388 */
l_L109X3: ;/* line 2391 */
__LABEL(l_L109X3);
  sim_icache_fetch(1523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2392 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2393 */
} /* line 2393 */
l_L160X3: ;/* line 2395 */
__LABEL(l_L160X3);
  sim_icache_fetch(1525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2396 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2397 */
l_L107X3: ;/* line 2400 */
__LABEL(l_L107X3);
  sim_icache_fetch(1527 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2401 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2402 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2403 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2404 */
l_L105X3: ;/* line 2407 */
__LABEL(l_L105X3);
  sim_icache_fetch(1531 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2408 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2409 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2410 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2411 */
l_L103X3: ;/* line 2414 */
__LABEL(l_L103X3);
  sim_icache_fetch(1535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2415 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2416 */
} /* line 2416 */
l_L161X3: ;/* line 2418 */
__LABEL(l_L161X3);
  sim_icache_fetch(1537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2419 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2420 */
l_L101X3: ;/* line 2423 */
__LABEL(l_L101X3);
  sim_icache_fetch(1539 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2424 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2425 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2426 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2427 */
l_L99X3: ;/* line 2430 */
__LABEL(l_L99X3);
  sim_icache_fetch(1543 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2431 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2432 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2433 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2434 */
l_L97X3: ;/* line 2437 */
__LABEL(l_L97X3);
  sim_icache_fetch(1547 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2438 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2439 */
} /* line 2439 */
l_L162X3: ;/* line 2441 */
__LABEL(l_L162X3);
  sim_icache_fetch(1549 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2442 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2443 */
l_L95X3: ;/* line 2446 */
__LABEL(l_L95X3);
  sim_icache_fetch(1551 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2447 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2448 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2449 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2450 */
l_L93X3: ;/* line 2454 */
__LABEL(l_L93X3);
  sim_icache_fetch(1555 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2455 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2456 */
} /* line 2456 */
l_L157X3: ;/* line 2458 */
__LABEL(l_L157X3);
  sim_icache_fetch(1557 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2459 */
} /* line 2459 */
  sim_icache_fetch(1559 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2461 */
} /* line 2461 */
  sim_icache_fetch(1560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2463 */
l_L86X3: ;/* line 2466 */
__LABEL(l_L86X3);
		 /* line 2466 */
  sim_icache_fetch(1561 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2469 */
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
} /* line 2469 */
l_lr_200: ;/* line 2469 */
__LABEL(l_lr_200);
  sim_icache_fetch(1564 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2471 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2472 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2473 */
   __ADD_CYCLES(1);
} /* line 2473 */
  sim_icache_fetch(1568 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2475 */
} /* line 2475 */
		 /* line 2476 */
  sim_icache_fetch(1569 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2478 */
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
} /* line 2479 */
l_lr_202: ;/* line 2479 */
__LABEL(l_lr_202);
  sim_icache_fetch(1573 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2481 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2482 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2483 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2484 */
   __MOV(reg_r0_3, 0); /* line 2485 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2486 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2487 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2488 */
   __ADD_CYCLES(1);
} /* line 2488 */
  sim_icache_fetch(1585 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2490 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2491 */
} /* line 2491 */
  sim_icache_fetch(1587 + t_thisfile.offset, 1);
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
} /* line 2493 */
l_L164X3: ;/* line 2495 */
__LABEL(l_L164X3);
  sim_icache_fetch(1588 + t_thisfile.offset, 1);
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
} /* line 2496 */
  sim_icache_fetch(1589 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2498 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2499 */
} /* line 2499 */
l_L166X3: ;/* line 2501 */
__LABEL(l_L166X3);
  sim_icache_fetch(1592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2503 */
l_L165X3: ;/* line 2506 */
__LABEL(l_L165X3);
  sim_icache_fetch(1593 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2507 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2508 */
   __GOTO(l_L166X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L166X3;
} /* line 2509 */
l_L163X3: ;/* line 2512 */
__LABEL(l_L163X3);
  sim_icache_fetch(1596 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2513 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2514 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2515 */
   __ADD_CYCLES(1);
} /* line 2515 */
		 /* line 2516 */
  sim_icache_fetch(1601 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2518 */
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
} /* line 2519 */
l_lr_208: ;/* line 2519 */
__LABEL(l_lr_208);
  sim_icache_fetch(1604 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2521 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2522 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2523 */
   __MOV(reg_r0_3, 0); /* line 2524 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2525 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2526 */
   __ADD_CYCLES(1);
} /* line 2526 */
  sim_icache_fetch(1612 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2528 */
   __GOTO(l_L164X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L164X3;
} /* line 2529 */
l_L84X3: ;/* line 2532 */
__LABEL(l_L84X3);
  sim_icache_fetch(1614 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2533 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2534 */
l_L80X3: ;/* line 2537 */
__LABEL(l_L80X3);
  sim_icache_fetch(1616 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2538 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2539 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2540 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2541 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2542 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2543 */
l_L79X3: ;/* line 2546 */
__LABEL(l_L79X3);
  sim_icache_fetch(1623 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2547 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2548 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2549 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2550 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2551 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2552 */
l_L78X3: ;/* line 2555 */
__LABEL(l_L78X3);
  sim_icache_fetch(1630 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2556 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2557 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2558 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2559 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2560 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2561 */
l_L77X3: ;/* line 2564 */
__LABEL(l_L77X3);
  sim_icache_fetch(1637 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2565 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2566 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2567 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2568 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2569 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2570 */
l_L76X3: ;/* line 2573 */
__LABEL(l_L76X3);
  sim_icache_fetch(1644 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2574 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2575 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2576 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2577 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2578 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2579 */
l_L75X3: ;/* line 2582 */
__LABEL(l_L75X3);
  sim_icache_fetch(1651 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2583 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2584 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2585 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2586 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2587 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2588 */
l_L74X3: ;/* line 2591 */
__LABEL(l_L74X3);
  sim_icache_fetch(1658 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2592 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2593 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2594 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2595 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2596 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2597 */
l_L73X3: ;/* line 2600 */
__LABEL(l_L73X3);
  sim_icache_fetch(1665 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2601 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2602 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2603 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2604 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2605 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2606 */
l_L72X3: ;/* line 2609 */
__LABEL(l_L72X3);
  sim_icache_fetch(1672 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2610 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2611 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2612 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2613 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2614 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2615 */
l_L71X3: ;/* line 2618 */
__LABEL(l_L71X3);
  sim_icache_fetch(1679 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2619 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2620 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2621 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2622 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2623 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2624 */
l_L70X3: ;/* line 2627 */
__LABEL(l_L70X3);
  sim_icache_fetch(1686 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2628 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2629 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2630 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2631 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2632 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2633 */
l_L69X3: ;/* line 2636 */
__LABEL(l_L69X3);
  sim_icache_fetch(1693 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2637 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2638 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2639 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2640 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2641 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2642 */
l_L68X3: ;/* line 2645 */
__LABEL(l_L68X3);
  sim_icache_fetch(1700 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2646 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2647 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2648 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2649 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2650 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2651 */
l_L67X3: ;/* line 2654 */
__LABEL(l_L67X3);
  sim_icache_fetch(1707 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2655 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2656 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2657 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2658 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2659 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2660 */
l_L66X3: ;/* line 2664 */
__LABEL(l_L66X3);
  sim_icache_fetch(1714 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2665 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2666 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2667 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2668 */
} /* line 2668 */
l_L82X3: ;/* line 2670 */
__LABEL(l_L82X3);
  sim_icache_fetch(1719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2671 */
} /* line 2671 */
		 /* line 2672 */
  sim_icache_fetch(1720 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2675 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2676 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2677 */
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
} /* line 2677 */
l_lr_227: ;/* line 2677 */
__LABEL(l_lr_227);
  sim_icache_fetch(1725 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2679 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2680 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2681 */
} /* line 2681 */
  sim_icache_fetch(1728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2683 */
l_L63X3: ;/* line 2686 */
__LABEL(l_L63X3);
  sim_icache_fetch(1729 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2687 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2688 */
} /* line 2688 */
  sim_icache_fetch(1731 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L64X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L64X3;
} /* line 2690 */
l_L61X3: ;/* line 2693 */
__LABEL(l_L61X3);
  sim_icache_fetch(1732 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_15, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2694 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2695 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2696 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2697 */
   __MOV(reg_r0_16, (unsigned int) 257); /* line 2698 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2699 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2700 */
   __ADD_CYCLES(1);
} /* line 2700 */
  sim_icache_fetch(1742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_11, (unsigned int) 1); /* line 2702 */
} /* line 2702 */
  sim_icache_fetch(1743 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_17); /* line 2704 */
} /* line 2704 */
  sim_icache_fetch(1745 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2706 */
} /* line 2706 */
  sim_icache_fetch(1746 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2708 */
   __LDBU(reg_r0_15, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2709 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2710 */
   __ADD_CYCLES(1);
} /* line 2710 */
  sim_icache_fetch(1751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_11, (unsigned int) 1); /* line 2712 */
} /* line 2712 */
  sim_icache_fetch(1752 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_17); /* line 2714 */
} /* line 2714 */
  sim_icache_fetch(1754 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2716 */
} /* line 2716 */
  sim_icache_fetch(1755 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2718 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2719 */
   __LDW(reg_r0_17, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2720 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2721 */
   __ADD_CYCLES(1);
} /* line 2721 */
  sim_icache_fetch(1762 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2723 */
   __OR(reg_r0_15, reg_r0_15, reg_r0_17); /* line 2724 */
} /* line 2724 */
  sim_icache_fetch(1764 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2726 */
} /* line 2726 */
  sim_icache_fetch(1766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2728 */
} /* line 2728 */
  sim_icache_fetch(1767 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2730 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2731 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2732 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2733 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2734 */
   __ADD_CYCLES(1);
} /* line 2734 */
  sim_icache_fetch(1776 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 2736 */
   __ADD(reg_r0_13, reg_r0_15, (unsigned int) -1); /* line 2737 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 1); /* line 2738 */
} /* line 2738 */
  sim_icache_fetch(1779 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_16, (unsigned int) 256); /* line 2740 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 2741 */
   __GOTO(l_L62X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L62X3;
} /* line 2742 */
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

  sim_icache_fetch(1783 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 2761 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2762 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2763 */
} /* line 2763 */
  sim_icache_fetch(1788 + t_thisfile.offset, 1);
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
} /* line 2765 */
  sim_icache_fetch(1789 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2767 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2768 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2769 */
} /* line 2769 */
  sim_icache_fetch(1792 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_12192Xbuf); /* line 2771 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_12192Xbuf),0,1)); /* line 2772 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_12192Xbuf + (unsigned int) 1)); /* line 2773 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2774 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2775 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2776 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2777 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2778 */
} /* line 2778 */
  sim_icache_fetch(1805 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2780 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2781 */
} /* line 2781 */
  sim_icache_fetch(1807 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2783 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2784 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2785 */
} /* line 2785 */
  sim_icache_fetch(1810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2787 */
} /* line 2787 */
  sim_icache_fetch(1811 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_12192Xbuf),0,1), reg_r0_2); /* line 2789 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2790 */
  sim_icache_fetch(1814 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2792 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2793 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2794 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2795 */
} /* line 2795 */
l_L168X3: ;/* line 2797 */
__LABEL(l_L168X3);
  sim_icache_fetch(1818 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2798 */
   __MOV(reg_r0_3, (unsigned int) compress_12192Xbuf); /* line 2799 */
} /* line 2799 */
  sim_icache_fetch(1821 + t_thisfile.offset, 1);
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
} /* line 2801 */
  sim_icache_fetch(1822 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2803 */
} /* line 2803 */
l_L169X3: ;/* line 2805 */
__LABEL(l_L169X3);
  sim_icache_fetch(1823 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 2806 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2807 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2808 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2809 */
   __ADD_CYCLES(1);
} /* line 2809 */
  sim_icache_fetch(1830 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2811 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2812 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2813 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2814 */
} /* line 2814 */
  sim_icache_fetch(1834 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_12192Xoffset,0,4), reg_r0_2); /* line 2816 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2817 */
} /* line 2817 */
  sim_icache_fetch(1837 + t_thisfile.offset, 1);
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
} /* line 2819 */
  sim_icache_fetch(1838 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2821 */
} /* line 2821 */
l_L171X3: ;/* line 2824 */
__LABEL(l_L171X3);
  sim_icache_fetch(1840 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2825 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2826 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2827 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2828 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2829 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2830 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2831 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2832 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2833 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2834 */
} /* line 2834 */
  sim_icache_fetch(1851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -16); /* line 2836 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 16); /* line 2837 */
} /* line 2837 */
  sim_icache_fetch(1853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2839 */
} /* line 2839 */
  sim_icache_fetch(1854 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2841 */
} /* line 2841 */
  sim_icache_fetch(1856 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2843 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2844 */
  sim_icache_fetch(1858 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2846 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2847 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2848 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2849 */
   __ADD_CYCLES(1);
} /* line 2849 */
  sim_icache_fetch(1863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2851 */
} /* line 2851 */
  sim_icache_fetch(1864 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2853 */
} /* line 2853 */
  sim_icache_fetch(1866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2855 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2856 */
  sim_icache_fetch(1868 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2858 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2859 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2860 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2861 */
   __ADD_CYCLES(1);
} /* line 2861 */
  sim_icache_fetch(1873 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2863 */
} /* line 2863 */
  sim_icache_fetch(1874 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2865 */
} /* line 2865 */
  sim_icache_fetch(1876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2867 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2868 */
  sim_icache_fetch(1878 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2870 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2871 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2872 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2873 */
   __ADD_CYCLES(1);
} /* line 2873 */
  sim_icache_fetch(1883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2875 */
} /* line 2875 */
  sim_icache_fetch(1884 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2877 */
} /* line 2877 */
  sim_icache_fetch(1886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2879 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2880 */
  sim_icache_fetch(1888 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2882 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2883 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2884 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2885 */
   __ADD_CYCLES(1);
} /* line 2885 */
  sim_icache_fetch(1893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2887 */
} /* line 2887 */
  sim_icache_fetch(1894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2889 */
} /* line 2889 */
  sim_icache_fetch(1896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2891 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2892 */
  sim_icache_fetch(1898 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2894 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2895 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2896 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2897 */
   __ADD_CYCLES(1);
} /* line 2897 */
  sim_icache_fetch(1903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2899 */
} /* line 2899 */
  sim_icache_fetch(1904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2901 */
} /* line 2901 */
  sim_icache_fetch(1906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2903 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2904 */
  sim_icache_fetch(1908 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2906 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2907 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2908 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2909 */
   __ADD_CYCLES(1);
} /* line 2909 */
  sim_icache_fetch(1913 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2911 */
} /* line 2911 */
  sim_icache_fetch(1914 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2913 */
} /* line 2913 */
  sim_icache_fetch(1916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2915 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2916 */
  sim_icache_fetch(1918 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2918 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2919 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2920 */
   __ADD(reg_r0_5, reg_r0_7, (unsigned int) -16); /* line 2921 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2922 */
   __ADD_CYCLES(1);
} /* line 2922 */
  sim_icache_fetch(1924 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2924 */
} /* line 2924 */
  sim_icache_fetch(1925 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2926 */
} /* line 2926 */
  sim_icache_fetch(1927 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2928 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2929 */
  sim_icache_fetch(1929 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2931 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2932 */
   __CMPEQ(reg_b0_7, reg_r0_7, 0); /* line 2933 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2934 */
   __ADD_CYCLES(1);
} /* line 2934 */
  sim_icache_fetch(1934 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2936 */
} /* line 2936 */
  sim_icache_fetch(1935 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2938 */
} /* line 2938 */
  sim_icache_fetch(1937 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2940 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2941 */
  sim_icache_fetch(1939 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2943 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2944 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2945 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2946 */
   __ADD_CYCLES(1);
} /* line 2946 */
  sim_icache_fetch(1944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2948 */
} /* line 2948 */
  sim_icache_fetch(1945 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2950 */
} /* line 2950 */
  sim_icache_fetch(1947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2952 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2953 */
  sim_icache_fetch(1949 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 2955 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2956 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2957 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2958 */
   __ADD_CYCLES(1);
} /* line 2958 */
  sim_icache_fetch(1954 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2960 */
} /* line 2960 */
  sim_icache_fetch(1955 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2962 */
} /* line 2962 */
  sim_icache_fetch(1957 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2964 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2965 */
  sim_icache_fetch(1959 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 2967 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2968 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2969 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2970 */
   __ADD_CYCLES(1);
} /* line 2970 */
  sim_icache_fetch(1964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2972 */
} /* line 2972 */
  sim_icache_fetch(1965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2974 */
} /* line 2974 */
  sim_icache_fetch(1967 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2976 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2977 */
  sim_icache_fetch(1969 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 2979 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2980 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 4); /* line 2981 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2982 */
   __ADD_CYCLES(1);
} /* line 2982 */
  sim_icache_fetch(1974 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2984 */
} /* line 2984 */
  sim_icache_fetch(1975 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2986 */
} /* line 2986 */
  sim_icache_fetch(1977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2988 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2989 */
  sim_icache_fetch(1979 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 2991 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2992 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 5); /* line 2993 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2994 */
   __ADD_CYCLES(1);
} /* line 2994 */
  sim_icache_fetch(1984 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2996 */
} /* line 2996 */
  sim_icache_fetch(1985 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2998 */
} /* line 2998 */
  sim_icache_fetch(1987 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3000 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3001 */
  sim_icache_fetch(1989 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 3003 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3004 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 6); /* line 3005 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3006 */
   __ADD_CYCLES(1);
} /* line 3006 */
  sim_icache_fetch(1994 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3008 */
} /* line 3008 */
  sim_icache_fetch(1995 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3010 */
} /* line 3010 */
  sim_icache_fetch(1997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3012 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3013 */
  sim_icache_fetch(1999 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 3015 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3016 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 7); /* line 3017 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3018 */
   __ADD_CYCLES(1);
} /* line 3018 */
  sim_icache_fetch(2004 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3020 */
} /* line 3020 */
  sim_icache_fetch(2005 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3022 */
} /* line 3022 */
  sim_icache_fetch(2007 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3024 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3025 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3026 */
  sim_icache_fetch(2010 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 3028 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3029 */
   __CMPEQ(reg_b0_7, reg_r0_7, (unsigned int) 8); /* line 3030 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) 16); /* line 3031 */
   __MFB(reg_r0_8, t__i32_0); /* line 3032 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3033 */
   __ADD_CYCLES(1);
} /* line 3033 */
  sim_icache_fetch(2017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3035 */
} /* line 3035 */
  sim_icache_fetch(2018 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3037 */
} /* line 3037 */
  sim_icache_fetch(2020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3039 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3040 */
  sim_icache_fetch(2022 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 3042 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3043 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 9); /* line 3044 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3045 */
   __ADD_CYCLES(1);
} /* line 3045 */
  sim_icache_fetch(2027 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3047 */
} /* line 3047 */
  sim_icache_fetch(2028 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3049 */
} /* line 3049 */
  sim_icache_fetch(2030 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3051 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3052 */
  sim_icache_fetch(2032 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 2),0,1)); /* line 3054 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3055 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 10); /* line 3056 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3057 */
   __ADD_CYCLES(1);
} /* line 3057 */
  sim_icache_fetch(2037 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3059 */
} /* line 3059 */
  sim_icache_fetch(2038 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3061 */
} /* line 3061 */
  sim_icache_fetch(2040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3063 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3064 */
  sim_icache_fetch(2042 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 3),0,1)); /* line 3066 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3067 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 11); /* line 3068 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3069 */
   __ADD_CYCLES(1);
} /* line 3069 */
  sim_icache_fetch(2047 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3071 */
} /* line 3071 */
  sim_icache_fetch(2048 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3073 */
} /* line 3073 */
  sim_icache_fetch(2050 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3075 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3076 */
  sim_icache_fetch(2052 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 4),0,1)); /* line 3078 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3079 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 12); /* line 3080 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3081 */
   __ADD_CYCLES(1);
} /* line 3081 */
  sim_icache_fetch(2057 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3083 */
} /* line 3083 */
  sim_icache_fetch(2058 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3085 */
} /* line 3085 */
  sim_icache_fetch(2060 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3087 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3088 */
  sim_icache_fetch(2062 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 5),0,1)); /* line 3090 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3091 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 13); /* line 3092 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3093 */
   __ADD_CYCLES(1);
} /* line 3093 */
  sim_icache_fetch(2067 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3095 */
} /* line 3095 */
  sim_icache_fetch(2068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3097 */
} /* line 3097 */
  sim_icache_fetch(2070 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3099 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3100 */
  sim_icache_fetch(2072 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 6),0,1)); /* line 3102 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3103 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 14); /* line 3104 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3105 */
   __ADD_CYCLES(1);
} /* line 3105 */
  sim_icache_fetch(2077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3107 */
} /* line 3107 */
  sim_icache_fetch(2078 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3109 */
} /* line 3109 */
  sim_icache_fetch(2080 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3111 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3112 */
  sim_icache_fetch(2082 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 7),0,1)); /* line 3114 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3115 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 15); /* line 3116 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3117 */
   __ADD_CYCLES(1);
} /* line 3117 */
  sim_icache_fetch(2087 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3119 */
} /* line 3119 */
  sim_icache_fetch(2088 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3121 */
} /* line 3121 */
  sim_icache_fetch(2090 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3123 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3124 */
  sim_icache_fetch(2092 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 8),0,1)); /* line 3126 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3127 */
   __MTB(reg_b0_7, reg_r0_8); /* line 3128 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3129 */
   __ADD_CYCLES(1);
} /* line 3129 */
  sim_icache_fetch(2097 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3131 */
} /* line 3131 */
  sim_icache_fetch(2098 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3133 */
} /* line 3133 */
  sim_icache_fetch(2100 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3135 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3136 */
  sim_icache_fetch(2102 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 9),0,1)); /* line 3138 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3139 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3140 */
   __ADD_CYCLES(1);
} /* line 3140 */
  sim_icache_fetch(2106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3142 */
} /* line 3142 */
  sim_icache_fetch(2107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3144 */
} /* line 3144 */
  sim_icache_fetch(2109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3146 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3147 */
  sim_icache_fetch(2111 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 10),0,1)); /* line 3149 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3150 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3151 */
   __ADD_CYCLES(1);
} /* line 3151 */
  sim_icache_fetch(2115 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3153 */
} /* line 3153 */
  sim_icache_fetch(2116 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3155 */
} /* line 3155 */
  sim_icache_fetch(2118 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3157 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3158 */
  sim_icache_fetch(2120 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 11),0,1)); /* line 3160 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3161 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3162 */
   __ADD_CYCLES(1);
} /* line 3162 */
  sim_icache_fetch(2124 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3164 */
} /* line 3164 */
  sim_icache_fetch(2125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3166 */
} /* line 3166 */
  sim_icache_fetch(2127 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3168 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3169 */
  sim_icache_fetch(2129 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 12),0,1)); /* line 3171 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3172 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3173 */
   __ADD_CYCLES(1);
} /* line 3173 */
  sim_icache_fetch(2133 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3175 */
} /* line 3175 */
  sim_icache_fetch(2134 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3177 */
} /* line 3177 */
  sim_icache_fetch(2136 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3179 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3180 */
  sim_icache_fetch(2138 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 13),0,1)); /* line 3182 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3183 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3184 */
   __ADD_CYCLES(1);
} /* line 3184 */
  sim_icache_fetch(2142 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3186 */
} /* line 3186 */
  sim_icache_fetch(2143 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3188 */
} /* line 3188 */
  sim_icache_fetch(2145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3190 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3191 */
  sim_icache_fetch(2147 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 14),0,1)); /* line 3193 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3194 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3195 */
   __ADD_CYCLES(1);
} /* line 3195 */
  sim_icache_fetch(2151 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3197 */
} /* line 3197 */
  sim_icache_fetch(2152 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3199 */
} /* line 3199 */
  sim_icache_fetch(2154 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3201 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3202 */
  sim_icache_fetch(2156 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 15),0,1)); /* line 3204 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3205 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3206 */
   __ADD_CYCLES(1);
} /* line 3206 */
  sim_icache_fetch(2160 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3208 */
} /* line 3208 */
  sim_icache_fetch(2161 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3210 */
} /* line 3210 */
  sim_icache_fetch(2163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 3212 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3214 */
  sim_icache_fetch(2165 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L171X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L171X3;
} /* line 3216 */
l_L172X3: ;/* line 3219 */
__LABEL(l_L172X3);
  sim_icache_fetch(2166 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_12192Xoffset,0,4), 0); /* line 3220 */
} /* line 3220 */
l_L170X3: ;/* line 3223 */
__LABEL(l_L170X3);
  sim_icache_fetch(2168 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3224 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3225 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3226 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3227 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3228 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3229 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3230 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3231 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3232 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3233 */
} /* line 3233 */
  sim_icache_fetch(2182 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3235 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3236 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3237 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3238 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3239 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3240 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3241 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3242 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3243 */
   __MOV(reg_r0_5, (unsigned int) compress_12192Xbuf); /* line 3244 */
} /* line 3244 */
  sim_icache_fetch(2193 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3246 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3247 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3248 */
   __MOV(reg_r0_3, 0); /* line 3249 */
} /* line 3249 */
  sim_icache_fetch(2197 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3251 */
} /* line 3251 */
  sim_icache_fetch(2198 + t_thisfile.offset, 1);
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
} /* line 3253 */
  sim_icache_fetch(2199 + t_thisfile.offset, 1);
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
} /* line 3255 */
l_L175X3: ;/* line 3258 */
__LABEL(l_L175X3);
  sim_icache_fetch(2200 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3259 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3260 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3261 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3262 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3263 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3264 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3265 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3266 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3267 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3268 */
} /* line 3268 */
  sim_icache_fetch(2212 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3270 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3271 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3272 */
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3273 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3274 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3275 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3276 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3277 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3278 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3279 */
} /* line 3279 */
  sim_icache_fetch(2222 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3281 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3282 */
   __ADD(reg_r0_3, reg_r0_38, (unsigned int) 16); /* line 3283 */
} /* line 3283 */
  sim_icache_fetch(2225 + t_thisfile.offset, 1);
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
} /* line 3285 */
  sim_icache_fetch(2226 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3287 */
} /* line 3287 */
  sim_icache_fetch(2228 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3289 */
} /* line 3289 */
  sim_icache_fetch(2229 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3291 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3292 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3293 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3294 */
   __ADD_CYCLES(1);
} /* line 3294 */
  sim_icache_fetch(2235 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 3296 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3297 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3298 */
} /* line 3298 */
  sim_icache_fetch(2238 + t_thisfile.offset, 1);
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
} /* line 3300 */
  sim_icache_fetch(2239 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3302 */
} /* line 3302 */
  sim_icache_fetch(2241 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3304 */
} /* line 3304 */
  sim_icache_fetch(2242 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3306 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3307 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3308 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3309 */
   __ADD_CYCLES(1);
} /* line 3309 */
  sim_icache_fetch(2248 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 3311 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3312 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3313 */
} /* line 3313 */
  sim_icache_fetch(2251 + t_thisfile.offset, 1);
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
} /* line 3315 */
  sim_icache_fetch(2252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3317 */
} /* line 3317 */
  sim_icache_fetch(2254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3319 */
} /* line 3319 */
  sim_icache_fetch(2255 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3321 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3322 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3323 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3324 */
   __ADD_CYCLES(1);
} /* line 3324 */
  sim_icache_fetch(2261 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 3326 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3327 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3328 */
} /* line 3328 */
  sim_icache_fetch(2264 + t_thisfile.offset, 1);
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
} /* line 3330 */
  sim_icache_fetch(2265 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3332 */
} /* line 3332 */
  sim_icache_fetch(2267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3334 */
} /* line 3334 */
  sim_icache_fetch(2268 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3336 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3337 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3338 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3339 */
   __ADD_CYCLES(1);
} /* line 3339 */
  sim_icache_fetch(2274 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 3341 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3342 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3343 */
} /* line 3343 */
  sim_icache_fetch(2277 + t_thisfile.offset, 1);
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
} /* line 3345 */
  sim_icache_fetch(2278 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3347 */
} /* line 3347 */
  sim_icache_fetch(2280 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3349 */
} /* line 3349 */
  sim_icache_fetch(2281 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3351 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3352 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3353 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3354 */
   __ADD_CYCLES(1);
} /* line 3354 */
  sim_icache_fetch(2287 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 3356 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3357 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3358 */
} /* line 3358 */
  sim_icache_fetch(2290 + t_thisfile.offset, 1);
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
} /* line 3360 */
  sim_icache_fetch(2291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3362 */
} /* line 3362 */
  sim_icache_fetch(2293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3364 */
} /* line 3364 */
  sim_icache_fetch(2294 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3366 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3367 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3368 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3369 */
   __ADD_CYCLES(1);
} /* line 3369 */
  sim_icache_fetch(2300 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 3371 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3372 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3373 */
} /* line 3373 */
  sim_icache_fetch(2303 + t_thisfile.offset, 1);
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
} /* line 3375 */
  sim_icache_fetch(2304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3377 */
} /* line 3377 */
  sim_icache_fetch(2306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3379 */
} /* line 3379 */
  sim_icache_fetch(2307 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3381 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3382 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3383 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3384 */
   __ADD_CYCLES(1);
} /* line 3384 */
  sim_icache_fetch(2313 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 3386 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3387 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3388 */
} /* line 3388 */
  sim_icache_fetch(2316 + t_thisfile.offset, 1);
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
} /* line 3390 */
  sim_icache_fetch(2317 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3392 */
} /* line 3392 */
  sim_icache_fetch(2319 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3394 */
} /* line 3394 */
  sim_icache_fetch(2320 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3396 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3397 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3398 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3399 */
   __ADD_CYCLES(1);
} /* line 3399 */
  sim_icache_fetch(2326 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 3401 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3402 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3403 */
} /* line 3403 */
  sim_icache_fetch(2329 + t_thisfile.offset, 1);
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
} /* line 3405 */
  sim_icache_fetch(2330 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3407 */
} /* line 3407 */
  sim_icache_fetch(2332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3409 */
} /* line 3409 */
  sim_icache_fetch(2333 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3411 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3412 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3413 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3414 */
   __ADD_CYCLES(1);
} /* line 3414 */
  sim_icache_fetch(2339 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 3416 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3417 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3418 */
} /* line 3418 */
  sim_icache_fetch(2342 + t_thisfile.offset, 1);
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
} /* line 3420 */
  sim_icache_fetch(2343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3422 */
} /* line 3422 */
  sim_icache_fetch(2345 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3424 */
} /* line 3424 */
  sim_icache_fetch(2346 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3426 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3427 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3428 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3429 */
   __ADD_CYCLES(1);
} /* line 3429 */
  sim_icache_fetch(2352 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 3431 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3432 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3433 */
} /* line 3433 */
  sim_icache_fetch(2355 + t_thisfile.offset, 1);
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
} /* line 3435 */
  sim_icache_fetch(2356 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3437 */
} /* line 3437 */
  sim_icache_fetch(2358 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3439 */
} /* line 3439 */
  sim_icache_fetch(2359 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3441 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3442 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3443 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3444 */
   __ADD_CYCLES(1);
} /* line 3444 */
  sim_icache_fetch(2365 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 3446 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3447 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3448 */
} /* line 3448 */
  sim_icache_fetch(2368 + t_thisfile.offset, 1);
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
} /* line 3450 */
  sim_icache_fetch(2369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3452 */
} /* line 3452 */
  sim_icache_fetch(2371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3454 */
} /* line 3454 */
  sim_icache_fetch(2372 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3456 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3457 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3458 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3459 */
   __ADD_CYCLES(1);
} /* line 3459 */
  sim_icache_fetch(2378 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 3461 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3462 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3463 */
} /* line 3463 */
  sim_icache_fetch(2381 + t_thisfile.offset, 1);
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
} /* line 3465 */
  sim_icache_fetch(2382 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3467 */
} /* line 3467 */
  sim_icache_fetch(2384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3469 */
} /* line 3469 */
  sim_icache_fetch(2385 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3471 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3472 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3473 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3474 */
   __ADD_CYCLES(1);
} /* line 3474 */
  sim_icache_fetch(2391 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 3476 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3477 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3478 */
} /* line 3478 */
  sim_icache_fetch(2394 + t_thisfile.offset, 1);
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
} /* line 3480 */
  sim_icache_fetch(2395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3482 */
} /* line 3482 */
  sim_icache_fetch(2397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3484 */
} /* line 3484 */
  sim_icache_fetch(2398 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3486 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3487 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3488 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3489 */
   __ADD_CYCLES(1);
} /* line 3489 */
  sim_icache_fetch(2404 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_2); /* line 3491 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3492 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3493 */
} /* line 3493 */
  sim_icache_fetch(2407 + t_thisfile.offset, 1);
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
} /* line 3495 */
  sim_icache_fetch(2408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3497 */
} /* line 3497 */
  sim_icache_fetch(2410 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3499 */
} /* line 3499 */
  sim_icache_fetch(2411 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3501 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3502 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3503 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3504 */
   __ADD_CYCLES(1);
} /* line 3504 */
  sim_icache_fetch(2417 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_2); /* line 3506 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3507 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3508 */
} /* line 3508 */
  sim_icache_fetch(2420 + t_thisfile.offset, 1);
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
} /* line 3510 */
  sim_icache_fetch(2421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3512 */
} /* line 3512 */
  sim_icache_fetch(2423 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_5); /* line 3514 */
} /* line 3514 */
  sim_icache_fetch(2424 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3516 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_37,0,1)); /* line 3517 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3518 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3519 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3520 */
   __ADD_CYCLES(1);
} /* line 3520 */
  sim_icache_fetch(2431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_38, reg_r0_2); /* line 3522 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3523 */
} /* line 3523 */
  sim_icache_fetch(2433 + t_thisfile.offset, 1);
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
} /* line 3525 */
  sim_icache_fetch(2434 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3527 */
} /* line 3527 */
  sim_icache_fetch(2436 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3529 */
} /* line 3529 */
  sim_icache_fetch(2437 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3531 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3532 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3533 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3534 */
   __ADD_CYCLES(1);
} /* line 3534 */
  sim_icache_fetch(2443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3536 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3537 */
} /* line 3537 */
  sim_icache_fetch(2445 + t_thisfile.offset, 1);
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
} /* line 3539 */
  sim_icache_fetch(2446 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3541 */
} /* line 3541 */
  sim_icache_fetch(2448 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3543 */
} /* line 3543 */
  sim_icache_fetch(2449 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3545 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3546 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3547 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3548 */
   __ADD_CYCLES(1);
} /* line 3548 */
  sim_icache_fetch(2455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3550 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3551 */
} /* line 3551 */
  sim_icache_fetch(2457 + t_thisfile.offset, 1);
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
} /* line 3553 */
  sim_icache_fetch(2458 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3555 */
} /* line 3555 */
  sim_icache_fetch(2460 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3557 */
} /* line 3557 */
  sim_icache_fetch(2461 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3559 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3560 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3561 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3562 */
   __ADD_CYCLES(1);
} /* line 3562 */
  sim_icache_fetch(2467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3564 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3565 */
} /* line 3565 */
  sim_icache_fetch(2469 + t_thisfile.offset, 1);
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
} /* line 3567 */
  sim_icache_fetch(2470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3569 */
} /* line 3569 */
  sim_icache_fetch(2472 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3571 */
} /* line 3571 */
  sim_icache_fetch(2473 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3573 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3574 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3575 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3576 */
   __ADD_CYCLES(1);
} /* line 3576 */
  sim_icache_fetch(2479 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3578 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3579 */
} /* line 3579 */
  sim_icache_fetch(2481 + t_thisfile.offset, 1);
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
} /* line 3581 */
  sim_icache_fetch(2482 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3583 */
} /* line 3583 */
  sim_icache_fetch(2484 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3585 */
} /* line 3585 */
  sim_icache_fetch(2485 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3587 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3588 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3589 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3590 */
   __ADD_CYCLES(1);
} /* line 3590 */
  sim_icache_fetch(2491 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3592 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3593 */
} /* line 3593 */
  sim_icache_fetch(2493 + t_thisfile.offset, 1);
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
} /* line 3595 */
  sim_icache_fetch(2494 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3597 */
} /* line 3597 */
  sim_icache_fetch(2496 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3599 */
} /* line 3599 */
  sim_icache_fetch(2497 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3601 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3602 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3603 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3604 */
   __ADD_CYCLES(1);
} /* line 3604 */
  sim_icache_fetch(2503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3606 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3607 */
} /* line 3607 */
  sim_icache_fetch(2505 + t_thisfile.offset, 1);
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
} /* line 3609 */
  sim_icache_fetch(2506 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3611 */
} /* line 3611 */
  sim_icache_fetch(2508 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3613 */
} /* line 3613 */
  sim_icache_fetch(2509 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3615 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3616 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3617 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3618 */
   __ADD_CYCLES(1);
} /* line 3618 */
  sim_icache_fetch(2515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3620 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3621 */
} /* line 3621 */
  sim_icache_fetch(2517 + t_thisfile.offset, 1);
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
} /* line 3623 */
  sim_icache_fetch(2518 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3625 */
} /* line 3625 */
  sim_icache_fetch(2520 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3627 */
} /* line 3627 */
  sim_icache_fetch(2521 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3629 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3630 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3631 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3632 */
   __ADD_CYCLES(1);
} /* line 3632 */
  sim_icache_fetch(2527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3634 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3635 */
} /* line 3635 */
  sim_icache_fetch(2529 + t_thisfile.offset, 1);
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
} /* line 3637 */
  sim_icache_fetch(2530 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3639 */
} /* line 3639 */
  sim_icache_fetch(2532 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3641 */
} /* line 3641 */
  sim_icache_fetch(2533 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3643 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3644 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3645 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3646 */
   __ADD_CYCLES(1);
} /* line 3646 */
  sim_icache_fetch(2539 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3648 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3649 */
} /* line 3649 */
  sim_icache_fetch(2541 + t_thisfile.offset, 1);
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
} /* line 3651 */
  sim_icache_fetch(2542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3653 */
} /* line 3653 */
  sim_icache_fetch(2544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3655 */
} /* line 3655 */
  sim_icache_fetch(2545 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3657 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3658 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3659 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3660 */
   __ADD_CYCLES(1);
} /* line 3660 */
  sim_icache_fetch(2551 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3662 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3663 */
} /* line 3663 */
  sim_icache_fetch(2553 + t_thisfile.offset, 1);
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
} /* line 3665 */
  sim_icache_fetch(2554 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3667 */
} /* line 3667 */
  sim_icache_fetch(2556 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3669 */
} /* line 3669 */
  sim_icache_fetch(2557 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3671 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3672 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3673 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3674 */
   __ADD_CYCLES(1);
} /* line 3674 */
  sim_icache_fetch(2563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3676 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3677 */
} /* line 3677 */
  sim_icache_fetch(2565 + t_thisfile.offset, 1);
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
} /* line 3679 */
  sim_icache_fetch(2566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3681 */
} /* line 3681 */
  sim_icache_fetch(2568 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3683 */
} /* line 3683 */
  sim_icache_fetch(2569 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3685 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3686 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3687 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3688 */
   __ADD_CYCLES(1);
} /* line 3688 */
  sim_icache_fetch(2575 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3690 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3691 */
} /* line 3691 */
  sim_icache_fetch(2577 + t_thisfile.offset, 1);
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
} /* line 3693 */
  sim_icache_fetch(2578 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3695 */
} /* line 3695 */
  sim_icache_fetch(2580 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3697 */
} /* line 3697 */
  sim_icache_fetch(2581 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3699 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3700 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3701 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3702 */
   __ADD_CYCLES(1);
} /* line 3702 */
  sim_icache_fetch(2587 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3704 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3705 */
} /* line 3705 */
  sim_icache_fetch(2589 + t_thisfile.offset, 1);
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
} /* line 3707 */
  sim_icache_fetch(2590 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3709 */
} /* line 3709 */
  sim_icache_fetch(2592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3711 */
} /* line 3711 */
  sim_icache_fetch(2593 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3713 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3714 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3715 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3716 */
   __ADD_CYCLES(1);
} /* line 3716 */
  sim_icache_fetch(2599 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3718 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3719 */
} /* line 3719 */
  sim_icache_fetch(2601 + t_thisfile.offset, 1);
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
} /* line 3721 */
  sim_icache_fetch(2602 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3723 */
} /* line 3723 */
  sim_icache_fetch(2604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3725 */
} /* line 3725 */
  sim_icache_fetch(2605 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3727 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3728 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3729 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3730 */
   __ADD_CYCLES(1);
} /* line 3730 */
  sim_icache_fetch(2611 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3732 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3733 */
} /* line 3733 */
  sim_icache_fetch(2613 + t_thisfile.offset, 1);
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
} /* line 3735 */
  sim_icache_fetch(2614 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3737 */
} /* line 3737 */
  sim_icache_fetch(2616 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3739 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 3740 */
l_L176X3: ;/* line 3743 */
__LABEL(l_L176X3);
  sim_icache_fetch(2618 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3744 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3745 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3746 */
   __ADD_CYCLES(1);
} /* line 3746 */
  sim_icache_fetch(2623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3748 */
} /* line 3748 */
  sim_icache_fetch(2624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3750 */
} /* line 3750 */
l_L174X3: ;/* line 3753 */
__LABEL(l_L174X3);
  sim_icache_fetch(2626 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_12192Xoffset,0,4), 0); /* line 3754 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3755 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3756 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3757 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3758 */
   __ADD_CYCLES(1);
} /* line 3758 */
  sim_icache_fetch(2634 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3760 */
} /* line 3760 */
  sim_icache_fetch(2635 + t_thisfile.offset, 1);
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
} /* line 3762 */
  sim_icache_fetch(2636 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3765 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3766 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3767 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3768 */
l_L177X3: ;/* line 3771 */
__LABEL(l_L177X3);
  sim_icache_fetch(2643 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3772 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3773 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3774 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3775 */
   __ADD_CYCLES(1);
} /* line 3775 */
  sim_icache_fetch(2650 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3777 */
} /* line 3777 */
  sim_icache_fetch(2651 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3779 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3780 */
} /* line 3780 */
  sim_icache_fetch(2654 + t_thisfile.offset, 1);
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
} /* line 3782 */
  sim_icache_fetch(2655 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3785 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3786 */
l_L178X3: ;/* line 3789 */
__LABEL(l_L178X3);
  sim_icache_fetch(2658 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3790 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3791 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3792 */
   __ADD_CYCLES(1);
} /* line 3792 */
  sim_icache_fetch(2662 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3794 */
} /* line 3794 */
  sim_icache_fetch(2663 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3796 */
} /* line 3796 */
  sim_icache_fetch(2664 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3799 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3800 */
l_L173X3: ;/* line 3803 */
__LABEL(l_L173X3);
  sim_icache_fetch(2667 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3805 */
l_L167X3: ;/* line 3808 */
__LABEL(l_L167X3);
  sim_icache_fetch(2668 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3809 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3810 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3811 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3812 */
   __ADD_CYCLES(1);
} /* line 3812 */
  sim_icache_fetch(2675 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3814 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3815 */
} /* line 3815 */
  sim_icache_fetch(2677 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3817 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3818 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3819 */
l_L180X3: ;/* line 3821 */
__LABEL(l_L180X3);
  sim_icache_fetch(2680 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3822 */
   __STW(mem_trace_st((unsigned int) compress_12192Xoffset,0,4), 0); /* line 3823 */
} /* line 3823 */
  sim_icache_fetch(2683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3825 */
} /* line 3825 */
  sim_icache_fetch(2684 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3827 */
} /* line 3827 */
  sim_icache_fetch(2685 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3830 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3831 */
l_L179X3: ;/* line 3834 */
__LABEL(l_L179X3);
  sim_icache_fetch(2688 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3835 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3836 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3837 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3838 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3839 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3840 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3841 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3842 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3843 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3844 */
} /* line 3844 */
  sim_icache_fetch(2698 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3846 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3847 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3848 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3849 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3850 */
   __MOV(reg_r0_5, (unsigned int) compress_12192Xbuf); /* line 3851 */
   __MOV(reg_r0_3, 0); /* line 3852 */
} /* line 3852 */
l_L181X3: ;/* line 3855 */
__LABEL(l_L181X3);
  sim_icache_fetch(2706 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3856 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3857 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3858 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3859 */
   __ADD_CYCLES(1);
} /* line 3859 */
  sim_icache_fetch(2712 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3861 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3862 */
} /* line 3862 */
  sim_icache_fetch(2714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3864 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3865 */
} /* line 3865 */
  sim_icache_fetch(2716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3867 */
} /* line 3867 */
  sim_icache_fetch(2717 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3869 */
} /* line 3869 */
  sim_icache_fetch(2718 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3871 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3872 */
} /* line 3872 */
  sim_icache_fetch(2720 + t_thisfile.offset, 1);
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
} /* line 3874 */
  sim_icache_fetch(2721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3876 */
} /* line 3876 */
  sim_icache_fetch(2723 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3878 */
} /* line 3878 */
  sim_icache_fetch(2724 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3880 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3881 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3882 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3883 */
   __ADD_CYCLES(1);
} /* line 3883 */
  sim_icache_fetch(2730 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3885 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3886 */
} /* line 3886 */
  sim_icache_fetch(2732 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3888 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3889 */
} /* line 3889 */
  sim_icache_fetch(2734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3891 */
} /* line 3891 */
  sim_icache_fetch(2735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3893 */
} /* line 3893 */
  sim_icache_fetch(2736 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3895 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3896 */
} /* line 3896 */
  sim_icache_fetch(2738 + t_thisfile.offset, 1);
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
} /* line 3898 */
  sim_icache_fetch(2739 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3900 */
} /* line 3900 */
  sim_icache_fetch(2741 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3902 */
} /* line 3902 */
  sim_icache_fetch(2742 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3904 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3905 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3906 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3907 */
   __ADD_CYCLES(1);
} /* line 3907 */
  sim_icache_fetch(2748 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3909 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3910 */
} /* line 3910 */
  sim_icache_fetch(2750 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3912 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3913 */
} /* line 3913 */
  sim_icache_fetch(2752 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3915 */
} /* line 3915 */
  sim_icache_fetch(2753 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3917 */
} /* line 3917 */
  sim_icache_fetch(2754 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3919 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3920 */
} /* line 3920 */
  sim_icache_fetch(2756 + t_thisfile.offset, 1);
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
} /* line 3922 */
  sim_icache_fetch(2757 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3924 */
} /* line 3924 */
  sim_icache_fetch(2759 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3926 */
} /* line 3926 */
  sim_icache_fetch(2760 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3928 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3929 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3930 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3931 */
   __ADD_CYCLES(1);
} /* line 3931 */
  sim_icache_fetch(2766 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3933 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3934 */
} /* line 3934 */
  sim_icache_fetch(2768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3936 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3937 */
} /* line 3937 */
  sim_icache_fetch(2770 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3939 */
} /* line 3939 */
  sim_icache_fetch(2771 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3941 */
} /* line 3941 */
  sim_icache_fetch(2772 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3943 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3944 */
} /* line 3944 */
  sim_icache_fetch(2774 + t_thisfile.offset, 1);
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
} /* line 3946 */
  sim_icache_fetch(2775 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3948 */
} /* line 3948 */
  sim_icache_fetch(2777 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3950 */
} /* line 3950 */
  sim_icache_fetch(2778 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3952 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3953 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3954 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3955 */
   __ADD_CYCLES(1);
} /* line 3955 */
  sim_icache_fetch(2784 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3957 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3958 */
} /* line 3958 */
  sim_icache_fetch(2786 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3960 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3961 */
} /* line 3961 */
  sim_icache_fetch(2788 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3963 */
} /* line 3963 */
  sim_icache_fetch(2789 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3965 */
} /* line 3965 */
  sim_icache_fetch(2790 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 3967 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3968 */
} /* line 3968 */
  sim_icache_fetch(2792 + t_thisfile.offset, 1);
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
} /* line 3970 */
  sim_icache_fetch(2793 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3972 */
} /* line 3972 */
  sim_icache_fetch(2795 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3974 */
} /* line 3974 */
  sim_icache_fetch(2796 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 3976 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3977 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3978 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3979 */
   __ADD_CYCLES(1);
} /* line 3979 */
  sim_icache_fetch(2802 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3981 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3982 */
} /* line 3982 */
  sim_icache_fetch(2804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3984 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3985 */
} /* line 3985 */
  sim_icache_fetch(2806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3987 */
} /* line 3987 */
  sim_icache_fetch(2807 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3989 */
} /* line 3989 */
  sim_icache_fetch(2808 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 3991 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3992 */
} /* line 3992 */
  sim_icache_fetch(2810 + t_thisfile.offset, 1);
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
} /* line 3994 */
  sim_icache_fetch(2811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3996 */
} /* line 3996 */
  sim_icache_fetch(2813 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3998 */
} /* line 3998 */
  sim_icache_fetch(2814 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4000 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 4001 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4002 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4003 */
   __ADD_CYCLES(1);
} /* line 4003 */
  sim_icache_fetch(2820 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4005 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4006 */
} /* line 4006 */
  sim_icache_fetch(2822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4008 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4009 */
} /* line 4009 */
  sim_icache_fetch(2824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4011 */
} /* line 4011 */
  sim_icache_fetch(2825 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4013 */
} /* line 4013 */
  sim_icache_fetch(2826 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 4015 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 4016 */
} /* line 4016 */
  sim_icache_fetch(2828 + t_thisfile.offset, 1);
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
} /* line 4018 */
  sim_icache_fetch(2829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4020 */
} /* line 4020 */
  sim_icache_fetch(2831 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4022 */
} /* line 4022 */
  sim_icache_fetch(2832 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4024 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4025 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4026 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4027 */
   __ADD_CYCLES(1);
} /* line 4027 */
  sim_icache_fetch(2838 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4029 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4030 */
} /* line 4030 */
  sim_icache_fetch(2840 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4032 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4033 */
} /* line 4033 */
  sim_icache_fetch(2842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4035 */
} /* line 4035 */
  sim_icache_fetch(2843 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4037 */
} /* line 4037 */
  sim_icache_fetch(2844 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4039 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4040 */
} /* line 4040 */
  sim_icache_fetch(2846 + t_thisfile.offset, 1);
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
} /* line 4042 */
  sim_icache_fetch(2847 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4044 */
} /* line 4044 */
  sim_icache_fetch(2849 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4046 */
} /* line 4046 */
  sim_icache_fetch(2850 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4048 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4049 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4050 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4051 */
   __ADD_CYCLES(1);
} /* line 4051 */
  sim_icache_fetch(2856 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4053 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4054 */
} /* line 4054 */
  sim_icache_fetch(2858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4056 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4057 */
} /* line 4057 */
  sim_icache_fetch(2860 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4059 */
} /* line 4059 */
  sim_icache_fetch(2861 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4061 */
} /* line 4061 */
  sim_icache_fetch(2862 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4063 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4064 */
} /* line 4064 */
  sim_icache_fetch(2864 + t_thisfile.offset, 1);
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
} /* line 4066 */
  sim_icache_fetch(2865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4068 */
} /* line 4068 */
  sim_icache_fetch(2867 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4070 */
} /* line 4070 */
  sim_icache_fetch(2868 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4072 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4073 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4074 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4075 */
   __ADD_CYCLES(1);
} /* line 4075 */
  sim_icache_fetch(2874 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4077 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4078 */
} /* line 4078 */
  sim_icache_fetch(2876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4080 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4081 */
} /* line 4081 */
  sim_icache_fetch(2878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4083 */
} /* line 4083 */
  sim_icache_fetch(2879 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4085 */
} /* line 4085 */
  sim_icache_fetch(2880 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4087 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4088 */
} /* line 4088 */
  sim_icache_fetch(2882 + t_thisfile.offset, 1);
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
} /* line 4090 */
  sim_icache_fetch(2883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4092 */
} /* line 4092 */
  sim_icache_fetch(2885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4094 */
} /* line 4094 */
  sim_icache_fetch(2886 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4096 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4097 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4098 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4099 */
   __ADD_CYCLES(1);
} /* line 4099 */
  sim_icache_fetch(2892 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4101 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4102 */
} /* line 4102 */
  sim_icache_fetch(2894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4104 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4105 */
} /* line 4105 */
  sim_icache_fetch(2896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4107 */
} /* line 4107 */
  sim_icache_fetch(2897 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4109 */
} /* line 4109 */
  sim_icache_fetch(2898 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4111 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4112 */
} /* line 4112 */
  sim_icache_fetch(2900 + t_thisfile.offset, 1);
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
} /* line 4114 */
  sim_icache_fetch(2901 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4116 */
} /* line 4116 */
  sim_icache_fetch(2903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4118 */
} /* line 4118 */
  sim_icache_fetch(2904 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4120 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4121 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4122 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4123 */
   __ADD_CYCLES(1);
} /* line 4123 */
  sim_icache_fetch(2910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4125 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4126 */
} /* line 4126 */
  sim_icache_fetch(2912 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4128 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4129 */
} /* line 4129 */
  sim_icache_fetch(2914 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4131 */
} /* line 4131 */
  sim_icache_fetch(2915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4133 */
} /* line 4133 */
  sim_icache_fetch(2916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4135 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4136 */
} /* line 4136 */
  sim_icache_fetch(2918 + t_thisfile.offset, 1);
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
} /* line 4138 */
  sim_icache_fetch(2919 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4140 */
} /* line 4140 */
  sim_icache_fetch(2921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4142 */
} /* line 4142 */
  sim_icache_fetch(2922 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4144 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4145 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4146 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4147 */
   __ADD_CYCLES(1);
} /* line 4147 */
  sim_icache_fetch(2928 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4149 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4150 */
} /* line 4150 */
  sim_icache_fetch(2930 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4152 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4153 */
} /* line 4153 */
  sim_icache_fetch(2932 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4155 */
} /* line 4155 */
  sim_icache_fetch(2933 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4157 */
} /* line 4157 */
  sim_icache_fetch(2934 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4159 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4160 */
} /* line 4160 */
  sim_icache_fetch(2936 + t_thisfile.offset, 1);
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
} /* line 4162 */
  sim_icache_fetch(2937 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4164 */
} /* line 4164 */
  sim_icache_fetch(2939 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4166 */
} /* line 4166 */
  sim_icache_fetch(2940 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4168 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4169 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4170 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4171 */
   __ADD_CYCLES(1);
} /* line 4171 */
  sim_icache_fetch(2946 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4173 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4174 */
} /* line 4174 */
  sim_icache_fetch(2948 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4176 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4177 */
} /* line 4177 */
  sim_icache_fetch(2950 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4179 */
} /* line 4179 */
  sim_icache_fetch(2951 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4181 */
} /* line 4181 */
  sim_icache_fetch(2952 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4183 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4184 */
} /* line 4184 */
  sim_icache_fetch(2954 + t_thisfile.offset, 1);
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
} /* line 4186 */
  sim_icache_fetch(2955 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4188 */
} /* line 4188 */
  sim_icache_fetch(2957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4190 */
} /* line 4190 */
  sim_icache_fetch(2958 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4192 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4193 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4194 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4195 */
   __ADD_CYCLES(1);
} /* line 4195 */
  sim_icache_fetch(2964 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4197 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4198 */
} /* line 4198 */
  sim_icache_fetch(2966 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4200 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4201 */
} /* line 4201 */
  sim_icache_fetch(2968 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4203 */
} /* line 4203 */
  sim_icache_fetch(2969 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4205 */
} /* line 4205 */
  sim_icache_fetch(2970 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4207 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4208 */
} /* line 4208 */
  sim_icache_fetch(2972 + t_thisfile.offset, 1);
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
} /* line 4210 */
  sim_icache_fetch(2973 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4212 */
} /* line 4212 */
  sim_icache_fetch(2975 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4214 */
} /* line 4214 */
  sim_icache_fetch(2976 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4216 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4217 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4218 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4219 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4220 */
   __ADD_CYCLES(1);
} /* line 4220 */
  sim_icache_fetch(2983 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4222 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4223 */
} /* line 4223 */
  sim_icache_fetch(2985 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4225 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4226 */
} /* line 4226 */
  sim_icache_fetch(2987 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4228 */
} /* line 4228 */
  sim_icache_fetch(2988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4230 */
} /* line 4230 */
  sim_icache_fetch(2989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4232 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4233 */
} /* line 4233 */
  sim_icache_fetch(2991 + t_thisfile.offset, 1);
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
} /* line 4235 */
  sim_icache_fetch(2992 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4237 */
} /* line 4237 */
  sim_icache_fetch(2994 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4239 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4240 */
l_L197X3: ;/* line 4243 */
__LABEL(l_L197X3);
  sim_icache_fetch(2996 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4244 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4245 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4246 */
   __ADD_CYCLES(1);
} /* line 4246 */
  sim_icache_fetch(3001 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4248 */
} /* line 4248 */
  sim_icache_fetch(3002 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4250 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4251 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4252 */
l_L196X3: ;/* line 4255 */
__LABEL(l_L196X3);
  sim_icache_fetch(3005 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4256 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4257 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4258 */
   __ADD_CYCLES(1);
} /* line 4258 */
  sim_icache_fetch(3010 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4260 */
} /* line 4260 */
  sim_icache_fetch(3011 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4262 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4263 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4264 */
l_L195X3: ;/* line 4267 */
__LABEL(l_L195X3);
  sim_icache_fetch(3014 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4268 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4269 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4270 */
   __ADD_CYCLES(1);
} /* line 4270 */
  sim_icache_fetch(3019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4272 */
} /* line 4272 */
  sim_icache_fetch(3020 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4274 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4275 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4276 */
l_L194X3: ;/* line 4279 */
__LABEL(l_L194X3);
  sim_icache_fetch(3023 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4280 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4281 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4282 */
   __ADD_CYCLES(1);
} /* line 4282 */
  sim_icache_fetch(3028 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4284 */
} /* line 4284 */
  sim_icache_fetch(3029 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4286 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4287 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4288 */
l_L193X3: ;/* line 4291 */
__LABEL(l_L193X3);
  sim_icache_fetch(3032 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4292 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4293 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4294 */
   __ADD_CYCLES(1);
} /* line 4294 */
  sim_icache_fetch(3037 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4296 */
} /* line 4296 */
  sim_icache_fetch(3038 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4298 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4299 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4300 */
l_L192X3: ;/* line 4303 */
__LABEL(l_L192X3);
  sim_icache_fetch(3041 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4304 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4305 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4306 */
   __ADD_CYCLES(1);
} /* line 4306 */
  sim_icache_fetch(3046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4308 */
} /* line 4308 */
  sim_icache_fetch(3047 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4310 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4311 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4312 */
l_L191X3: ;/* line 4315 */
__LABEL(l_L191X3);
  sim_icache_fetch(3050 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4316 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4317 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4318 */
   __ADD_CYCLES(1);
} /* line 4318 */
  sim_icache_fetch(3055 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4320 */
} /* line 4320 */
  sim_icache_fetch(3056 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4322 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4323 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4324 */
l_L190X3: ;/* line 4327 */
__LABEL(l_L190X3);
  sim_icache_fetch(3059 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4328 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4329 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4330 */
   __ADD_CYCLES(1);
} /* line 4330 */
  sim_icache_fetch(3064 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4332 */
} /* line 4332 */
  sim_icache_fetch(3065 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4334 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4335 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4336 */
l_L189X3: ;/* line 4339 */
__LABEL(l_L189X3);
  sim_icache_fetch(3068 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4340 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4341 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4342 */
   __ADD_CYCLES(1);
} /* line 4342 */
  sim_icache_fetch(3073 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4344 */
} /* line 4344 */
  sim_icache_fetch(3074 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4346 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4347 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4348 */
l_L188X3: ;/* line 4351 */
__LABEL(l_L188X3);
  sim_icache_fetch(3077 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4352 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4353 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4354 */
   __ADD_CYCLES(1);
} /* line 4354 */
  sim_icache_fetch(3082 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4356 */
} /* line 4356 */
  sim_icache_fetch(3083 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4358 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4359 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4360 */
l_L187X3: ;/* line 4363 */
__LABEL(l_L187X3);
  sim_icache_fetch(3086 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4364 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4365 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4366 */
   __ADD_CYCLES(1);
} /* line 4366 */
  sim_icache_fetch(3091 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4368 */
} /* line 4368 */
  sim_icache_fetch(3092 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4370 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4371 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4372 */
l_L186X3: ;/* line 4375 */
__LABEL(l_L186X3);
  sim_icache_fetch(3095 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4376 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4377 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4378 */
   __ADD_CYCLES(1);
} /* line 4378 */
  sim_icache_fetch(3100 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4380 */
} /* line 4380 */
  sim_icache_fetch(3101 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4382 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4383 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4384 */
l_L185X3: ;/* line 4387 */
__LABEL(l_L185X3);
  sim_icache_fetch(3104 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4388 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4389 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4390 */
   __ADD_CYCLES(1);
} /* line 4390 */
  sim_icache_fetch(3109 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4392 */
} /* line 4392 */
  sim_icache_fetch(3110 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4394 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4395 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4396 */
l_L184X3: ;/* line 4399 */
__LABEL(l_L184X3);
  sim_icache_fetch(3113 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4400 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4401 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4402 */
   __ADD_CYCLES(1);
} /* line 4402 */
  sim_icache_fetch(3118 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4404 */
} /* line 4404 */
  sim_icache_fetch(3119 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4406 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4407 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4408 */
l_L183X3: ;/* line 4411 */
__LABEL(l_L183X3);
  sim_icache_fetch(3122 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4412 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4413 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4414 */
   __ADD_CYCLES(1);
} /* line 4414 */
  sim_icache_fetch(3127 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4416 */
} /* line 4416 */
  sim_icache_fetch(3128 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4418 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4419 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4420 */
l_L182X3: ;/* line 4423 */
__LABEL(l_L182X3);
  sim_icache_fetch(3131 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4424 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_12192Xoffset,0,4)); /* line 4425 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4426 */
   __ADD_CYCLES(1);
} /* line 4426 */
  sim_icache_fetch(3136 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4428 */
} /* line 4428 */
  sim_icache_fetch(3137 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4430 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4431 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4432 */
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

  sim_icache_fetch(3140 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4448 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4449 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4450 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4451 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4452 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4453 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4454 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4455 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4456 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4457 */
} /* line 4457 */
  sim_icache_fetch(3151 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4459 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4460 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4461 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4462 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4463 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4464 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4465 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4466 */
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4467 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4468 */
} /* line 4468 */
  sim_icache_fetch(3162 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4470 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4471 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4472 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4473 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4474 */
} /* line 4474 */
l_L198X3: ;/* line 4477 */
__LABEL(l_L198X3);
  sim_icache_fetch(3170 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4478 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4479 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4480 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4481 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4482 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4483 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4484 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4485 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4486 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4487 */
} /* line 4487 */
  sim_icache_fetch(3180 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4489 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4490 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4491 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4492 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4493 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4494 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4495 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4496 */
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4497 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L199X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4498 */
  sim_icache_fetch(3190 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4500 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4501 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4502 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4503 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4504 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4505 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4506 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4507 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4508 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4509 */
} /* line 4509 */
  sim_icache_fetch(3200 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4511 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4512 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4513 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4514 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4515 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4516 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4517 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4518 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4519 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4520 */
} /* line 4520 */
  sim_icache_fetch(3210 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4522 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4523 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4524 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4525 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4526 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4527 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4528 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4529 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4530 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4531 */
} /* line 4531 */
  sim_icache_fetch(3220 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4533 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4534 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4535 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4536 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4537 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4538 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4539 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4540 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4541 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4542 */
} /* line 4542 */
  sim_icache_fetch(3230 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4544 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4545 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4546 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4547 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4548 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4549 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4550 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4551 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4552 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4553 */
} /* line 4553 */
  sim_icache_fetch(3240 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4555 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4556 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4557 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4558 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4559 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4560 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4561 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4562 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4563 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4564 */
} /* line 4564 */
  sim_icache_fetch(3250 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4566 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4567 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4568 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4569 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4570 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4571 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4572 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4573 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4574 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4575 */
} /* line 4575 */
  sim_icache_fetch(3260 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4577 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4578 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4579 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4580 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4581 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4582 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4583 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4584 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4585 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4586 */
} /* line 4586 */
  sim_icache_fetch(3270 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4588 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4589 */
   __GOTO(l_L198X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L198X3;
} /* line 4590 */
l_L199X3: ;/* line 4593 */
__LABEL(l_L199X3);
  sim_icache_fetch(3273 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4594 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4595 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4596 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4597 */
   __ADD_CYCLES(1);
} /* line 4597 */
  sim_icache_fetch(3279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4599 */
} /* line 4599 */
  sim_icache_fetch(3280 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4601 */
} /* line 4601 */
		 /* line 4602 */
  sim_icache_fetch(3282 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4604 */
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
} /* line 4605 */
l_lr_266: ;/* line 4605 */
__LABEL(l_lr_266);
  sim_icache_fetch(3286 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_2, t__i32_0); /* line 4607 */
   __MOV(reg_r0_4, t__i32_0); /* line 4608 */
   __CMPEQ(reg_b0_0, t__i32_0, (unsigned int) -1); /* line 4609 */
   __MOV(reg_r0_3, 0); /* line 4610 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4611 */
   __MOV(reg_r0_5, t__i32_0); /* line 4612 */
} /* line 4612 */
  sim_icache_fetch(3292 + t_thisfile.offset, 1);
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
} /* line 4614 */
  sim_icache_fetch(3293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4617 */
l_L200X3: ;/* line 4620 */
__LABEL(l_L200X3);
  sim_icache_fetch(3294 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4621 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4622 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4623 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4624 */
} /* line 4624 */
  sim_icache_fetch(3299 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4626 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4627 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4628 */
} /* line 4628 */
  sim_icache_fetch(3303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4630 */
} /* line 4630 */
  sim_icache_fetch(3304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4632 */
} /* line 4632 */
  sim_icache_fetch(3306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4634 */
} /* line 4634 */
l_L201X3: ;/* line 4637 */
__LABEL(l_L201X3);
		 /* line 4637 */
  sim_icache_fetch(3307 + t_thisfile.offset, 2);
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
} /* line 4639 */
l_lr_270: ;/* line 4639 */
__LABEL(l_lr_270);
  sim_icache_fetch(3309 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4641 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4642 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4643 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4644 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4645 */
} /* line 4645 */
  sim_icache_fetch(3316 + t_thisfile.offset, 1);
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
} /* line 4647 */
  sim_icache_fetch(3317 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4649 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4650 */
} /* line 4650 */
  sim_icache_fetch(3320 + t_thisfile.offset, 1);
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
} /* line 4652 */
l_L204X3: ;/* line 4655 */
__LABEL(l_L204X3);
  sim_icache_fetch(3321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4656 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4657 */
} /* line 4657 */
  sim_icache_fetch(3323 + t_thisfile.offset, 1);
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
} /* line 4659 */
  sim_icache_fetch(3324 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4661 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4662 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4663 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4664 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4665 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4666 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4667 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4668 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4669 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4670 */
} /* line 4670 */
  sim_icache_fetch(3334 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4672 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4673 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4674 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4675 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4676 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4677 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4678 */
   __GOTO(l_L204X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L204X3;
} /* line 4679 */
l_L205X3: ;/* line 4682 */
__LABEL(l_L205X3);
  sim_icache_fetch(3342 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4683 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4684 */
} /* line 4684 */
		 /* line 4685 */
  sim_icache_fetch(3345 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4687 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4688 */
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
} /* line 4689 */
l_lr_274: ;/* line 4689 */
__LABEL(l_lr_274);
  sim_icache_fetch(3351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4691 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4692 */
} /* line 4692 */
  sim_icache_fetch(3353 + t_thisfile.offset, 1);
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
} /* line 4694 */
l_L203X3: ;/* line 4697 */
__LABEL(l_L203X3);
  sim_icache_fetch(3354 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4698 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4699 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4700 */
   __ADD_CYCLES(1);
} /* line 4700 */
  sim_icache_fetch(3358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4702 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4703 */
} /* line 4703 */
  sim_icache_fetch(3360 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4705 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4706 */
  sim_icache_fetch(3363 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4708 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4709 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4710 */
} /* line 4710 */
l_L207X3: ;/* line 4713 */
__LABEL(l_L207X3);
  sim_icache_fetch(3366 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4714 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4715 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4716 */
} /* line 4716 */
  sim_icache_fetch(3371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4718 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4719 */
  sim_icache_fetch(3373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4721 */
} /* line 4721 */
  sim_icache_fetch(3374 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4723 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4724 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4725 */
} /* line 4725 */
  sim_icache_fetch(3379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4727 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4728 */
  sim_icache_fetch(3381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4730 */
} /* line 4730 */
  sim_icache_fetch(3382 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4732 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4733 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4734 */
} /* line 4734 */
  sim_icache_fetch(3387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4736 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4737 */
  sim_icache_fetch(3389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4739 */
} /* line 4739 */
  sim_icache_fetch(3390 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4741 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4742 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4743 */
} /* line 4743 */
  sim_icache_fetch(3395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4745 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4746 */
  sim_icache_fetch(3397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4748 */
} /* line 4748 */
  sim_icache_fetch(3398 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4750 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4751 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4752 */
} /* line 4752 */
  sim_icache_fetch(3403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4754 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4755 */
  sim_icache_fetch(3405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4757 */
} /* line 4757 */
  sim_icache_fetch(3406 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4759 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4760 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4761 */
} /* line 4761 */
  sim_icache_fetch(3411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4763 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4764 */
  sim_icache_fetch(3413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4766 */
} /* line 4766 */
  sim_icache_fetch(3414 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4768 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4769 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4770 */
} /* line 4770 */
  sim_icache_fetch(3419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4772 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4773 */
  sim_icache_fetch(3421 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4775 */
} /* line 4775 */
  sim_icache_fetch(3422 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4777 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4778 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4779 */
} /* line 4779 */
  sim_icache_fetch(3427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4781 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4782 */
  sim_icache_fetch(3429 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4784 */
} /* line 4784 */
  sim_icache_fetch(3430 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4786 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4787 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4788 */
} /* line 4788 */
  sim_icache_fetch(3435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4790 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4791 */
  sim_icache_fetch(3437 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4793 */
} /* line 4793 */
  sim_icache_fetch(3438 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4795 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4796 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4797 */
} /* line 4797 */
  sim_icache_fetch(3443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4799 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4800 */
  sim_icache_fetch(3445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4802 */
} /* line 4802 */
  sim_icache_fetch(3446 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4804 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4805 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4806 */
} /* line 4806 */
  sim_icache_fetch(3451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4808 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4809 */
  sim_icache_fetch(3453 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4811 */
} /* line 4811 */
  sim_icache_fetch(3454 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4813 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4814 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4815 */
} /* line 4815 */
  sim_icache_fetch(3459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4817 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4818 */
  sim_icache_fetch(3461 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4820 */
} /* line 4820 */
  sim_icache_fetch(3462 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4822 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4823 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4824 */
} /* line 4824 */
  sim_icache_fetch(3467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4826 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4827 */
  sim_icache_fetch(3469 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4829 */
} /* line 4829 */
  sim_icache_fetch(3470 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4831 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4832 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4833 */
} /* line 4833 */
  sim_icache_fetch(3475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4835 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4836 */
  sim_icache_fetch(3477 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4838 */
} /* line 4838 */
  sim_icache_fetch(3478 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4840 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4841 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4842 */
} /* line 4842 */
  sim_icache_fetch(3483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4844 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4845 */
  sim_icache_fetch(3485 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4847 */
} /* line 4847 */
  sim_icache_fetch(3486 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4849 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4850 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4851 */
} /* line 4851 */
  sim_icache_fetch(3491 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4853 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4854 */
  sim_icache_fetch(3493 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4856 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4857 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 4858 */
l_L223X3: ;/* line 4861 */
__LABEL(l_L223X3);
  sim_icache_fetch(3496 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4862 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4863 */
} /* line 4863 */
  sim_icache_fetch(3498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4865 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 4866 */
l_L225X3: ;/* line 4869 */
__LABEL(l_L225X3);
  sim_icache_fetch(3500 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __MOV(reg_r0_5, reg_r0_3); /* line 4870 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4871 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4872 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4873 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4874 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4875 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4876 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4877 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4878 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4879 */
} /* line 4879 */
  sim_icache_fetch(3518 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4881 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4882 */
   __ADD(reg_r0_22, reg_r0_19, (unsigned int) -16); /* line 4883 */
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) -16); /* line 4884 */
   __ADD(reg_r0_24, reg_r0_17, (unsigned int) -16); /* line 4885 */
   __ADD(reg_r0_25, reg_r0_16, (unsigned int) -16); /* line 4886 */
   __ADD(reg_r0_26, reg_r0_15, (unsigned int) -16); /* line 4887 */
   __ADD(reg_r0_27, reg_r0_14, (unsigned int) -16); /* line 4888 */
   __ADD(reg_r0_28, reg_r0_13, (unsigned int) -16); /* line 4889 */
   __ADD(reg_r0_29, reg_r0_12, (unsigned int) -16); /* line 4890 */
} /* line 4890 */
  sim_icache_fetch(3529 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 4892 */
   __MOV(reg_r0_38, reg_r0_20); /* line 4893 */
   __ADD(reg_r0_31, reg_r0_11, (unsigned int) -16); /* line 4894 */
   __ADD(reg_r0_32, reg_r0_10, (unsigned int) -16); /* line 4895 */
   __ADD(reg_r0_33, reg_r0_9, (unsigned int) -16); /* line 4896 */
   __ADD(reg_r0_34, reg_r0_8, (unsigned int) -16); /* line 4897 */
   __ADD(reg_r0_35, reg_r0_7, (unsigned int) -16); /* line 4898 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) -16); /* line 4899 */
   __ADD(reg_r0_37, reg_r0_20, (unsigned int) -16); /* line 4900 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 4901 */
} /* line 4901 */
  sim_icache_fetch(3539 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 4903 */
   __MOV(reg_r0_40, reg_r0_37); /* line 4904 */
} /* line 4904 */
  sim_icache_fetch(3542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4906 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4907 */
  sim_icache_fetch(3544 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4909 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4910 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4911 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4912 */
   __ADD_CYCLES(1);
} /* line 4912 */
  sim_icache_fetch(3550 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4914 */
} /* line 4914 */
  sim_icache_fetch(3551 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4916 */
} /* line 4916 */
  sim_icache_fetch(3553 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4918 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4919 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4920 */
  sim_icache_fetch(3557 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4922 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4923 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4924 */
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) -16); /* line 4925 */
   __MFB(reg_r0_4, t__i32_0); /* line 4926 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4927 */
   __ADD_CYCLES(1);
} /* line 4927 */
  sim_icache_fetch(3565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 4929 */
} /* line 4929 */
  sim_icache_fetch(3566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 4931 */
} /* line 4931 */
  sim_icache_fetch(3568 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4933 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4934 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4935 */
  sim_icache_fetch(3571 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4937 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4938 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4939 */
   __ADD(reg_r0_7, reg_r0_35, (unsigned int) -16); /* line 4940 */
   __MFB(reg_r0_4, t__i32_0); /* line 4941 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4942 */
   __ADD_CYCLES(1);
} /* line 4942 */
  sim_icache_fetch(3579 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 4944 */
} /* line 4944 */
  sim_icache_fetch(3580 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 4946 */
} /* line 4946 */
  sim_icache_fetch(3582 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4948 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4949 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4950 */
  sim_icache_fetch(3585 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4952 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4953 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4954 */
   __ADD(reg_r0_8, reg_r0_34, (unsigned int) -16); /* line 4955 */
   __MFB(reg_r0_4, t__i32_0); /* line 4956 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4957 */
   __ADD_CYCLES(1);
} /* line 4957 */
  sim_icache_fetch(3593 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 4959 */
} /* line 4959 */
  sim_icache_fetch(3594 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 4961 */
} /* line 4961 */
  sim_icache_fetch(3596 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 4963 */
   __MTB(reg_b0_4, reg_r0_4); /* line 4964 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4965 */
  sim_icache_fetch(3599 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 4967 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4968 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 4969 */
   __ADD(reg_r0_9, reg_r0_33, (unsigned int) -16); /* line 4970 */
   __MFB(reg_r0_4, t__i32_0); /* line 4971 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4972 */
   __ADD_CYCLES(1);
} /* line 4972 */
  sim_icache_fetch(3607 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 4974 */
} /* line 4974 */
  sim_icache_fetch(3608 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 4976 */
} /* line 4976 */
  sim_icache_fetch(3610 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 4978 */
   __MTB(reg_b0_5, reg_r0_4); /* line 4979 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4980 */
  sim_icache_fetch(3613 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 4982 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4983 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 4984 */
   __ADD(reg_r0_10, reg_r0_32, (unsigned int) -16); /* line 4985 */
   __MFB(reg_r0_4, t__i32_0); /* line 4986 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4987 */
   __ADD_CYCLES(1);
} /* line 4987 */
  sim_icache_fetch(3621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 4989 */
} /* line 4989 */
  sim_icache_fetch(3622 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 4991 */
} /* line 4991 */
  sim_icache_fetch(3624 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 4993 */
   __MTB(reg_b0_6, reg_r0_4); /* line 4994 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4995 */
  sim_icache_fetch(3627 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 4997 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4998 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 4999 */
   __ADD(reg_r0_11, reg_r0_31, (unsigned int) -16); /* line 5000 */
   __MFB(reg_r0_4, t__i32_0); /* line 5001 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5002 */
   __ADD_CYCLES(1);
} /* line 5002 */
  sim_icache_fetch(3635 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5004 */
} /* line 5004 */
  sim_icache_fetch(3636 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5006 */
} /* line 5006 */
  sim_icache_fetch(3638 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 5008 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5009 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5010 */
  sim_icache_fetch(3641 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5012 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5013 */
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 5014 */
   __ADD(reg_r0_12, reg_r0_29, (unsigned int) -16); /* line 5015 */
   __MFB(reg_r0_4, t__i32_0); /* line 5016 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5017 */
   __ADD_CYCLES(1);
} /* line 5017 */
  sim_icache_fetch(3649 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5019 */
} /* line 5019 */
  sim_icache_fetch(3650 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5021 */
} /* line 5021 */
  sim_icache_fetch(3652 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5023 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5024 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5025 */
  sim_icache_fetch(3655 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5027 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5028 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5029 */
   __ADD(reg_r0_13, reg_r0_28, (unsigned int) -16); /* line 5030 */
   __MFB(reg_r0_4, t__i32_0); /* line 5031 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5032 */
   __ADD_CYCLES(1);
} /* line 5032 */
  sim_icache_fetch(3663 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5034 */
} /* line 5034 */
  sim_icache_fetch(3664 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5036 */
} /* line 5036 */
  sim_icache_fetch(3666 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5038 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5039 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5040 */
  sim_icache_fetch(3669 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5042 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5043 */
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 5044 */
   __ADD(reg_r0_14, reg_r0_27, (unsigned int) -16); /* line 5045 */
   __MFB(reg_r0_4, t__i32_0); /* line 5046 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5047 */
   __ADD_CYCLES(1);
} /* line 5047 */
  sim_icache_fetch(3677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5049 */
} /* line 5049 */
  sim_icache_fetch(3678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5051 */
} /* line 5051 */
  sim_icache_fetch(3680 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5053 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5054 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5055 */
  sim_icache_fetch(3683 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5057 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5058 */
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5059 */
   __ADD(reg_r0_15, reg_r0_26, (unsigned int) -16); /* line 5060 */
   __MFB(reg_r0_4, t__i32_0); /* line 5061 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5062 */
   __ADD_CYCLES(1);
} /* line 5062 */
  sim_icache_fetch(3691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5064 */
} /* line 5064 */
  sim_icache_fetch(3692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5066 */
} /* line 5066 */
  sim_icache_fetch(3694 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5068 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5069 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5070 */
  sim_icache_fetch(3697 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5072 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5073 */
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5074 */
   __ADD(reg_r0_16, reg_r0_25, (unsigned int) -16); /* line 5075 */
   __MFB(reg_r0_4, t__i32_0); /* line 5076 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5077 */
   __ADD_CYCLES(1);
} /* line 5077 */
  sim_icache_fetch(3705 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5079 */
} /* line 5079 */
  sim_icache_fetch(3706 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5081 */
} /* line 5081 */
  sim_icache_fetch(3708 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5083 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5084 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5085 */
  sim_icache_fetch(3711 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5087 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5088 */
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5089 */
   __ADD(reg_r0_17, reg_r0_24, (unsigned int) -16); /* line 5090 */
   __MFB(reg_r0_4, t__i32_0); /* line 5091 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5092 */
   __ADD_CYCLES(1);
} /* line 5092 */
  sim_icache_fetch(3719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5094 */
} /* line 5094 */
  sim_icache_fetch(3720 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5096 */
} /* line 5096 */
  sim_icache_fetch(3722 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5098 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5099 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5100 */
  sim_icache_fetch(3725 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5102 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5103 */
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5104 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) -16); /* line 5105 */
   __MFB(reg_r0_4, t__i32_0); /* line 5106 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5107 */
   __ADD_CYCLES(1);
} /* line 5107 */
  sim_icache_fetch(3733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5109 */
} /* line 5109 */
  sim_icache_fetch(3734 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5111 */
} /* line 5111 */
  sim_icache_fetch(3736 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5113 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5114 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5115 */
  sim_icache_fetch(3739 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5117 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5118 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5119 */
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5120 */
   __ADD(reg_r0_19, reg_r0_22, (unsigned int) -16); /* line 5121 */
   __MFB(reg_r0_4, t__i32_0); /* line 5122 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5123 */
   __ADD_CYCLES(1);
} /* line 5123 */
  sim_icache_fetch(3748 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_2, (unsigned int) 1); /* line 5125 */
} /* line 5125 */
  sim_icache_fetch(3749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_30); /* line 5127 */
} /* line 5127 */
  sim_icache_fetch(3751 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5129 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5130 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5131 */
  sim_icache_fetch(3754 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_5, reg_r0_3); /* line 5133 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5134 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5135 */
   __CMPLEU(reg_b0_7, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5136 */
   __ADD(reg_r0_20, reg_r0_37, (unsigned int) -16); /* line 5137 */
   __MOV(reg_r0_3, reg_r0_39); /* line 5138 */
   __MFB(reg_r0_30, t__i32_0); /* line 5139 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5140 */
   __ADD_CYCLES(1);
} /* line 5140 */
  sim_icache_fetch(3764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5142 */
} /* line 5142 */
  sim_icache_fetch(3765 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5144 */
} /* line 5144 */
  sim_icache_fetch(3767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5146 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5147 */
  sim_icache_fetch(3769 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5149 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5150 */
   __CMPLEU(reg_b0_0, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5151 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5152 */
   __ADD_CYCLES(1);
} /* line 5152 */
  sim_icache_fetch(3775 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5154 */
} /* line 5154 */
  sim_icache_fetch(3776 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5156 */
} /* line 5156 */
  sim_icache_fetch(3778 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5158 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5159 */
  sim_icache_fetch(3780 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5161 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5162 */
   __CMPLEU(reg_b0_1, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5163 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5164 */
   __ADD_CYCLES(1);
} /* line 5164 */
  sim_icache_fetch(3786 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5166 */
} /* line 5166 */
  sim_icache_fetch(3787 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5168 */
} /* line 5168 */
  sim_icache_fetch(3789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5170 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5171 */
  sim_icache_fetch(3791 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5173 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5174 */
   __CMPLEU(reg_b0_2, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5175 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5176 */
   __ADD_CYCLES(1);
} /* line 5176 */
  sim_icache_fetch(3797 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5178 */
} /* line 5178 */
  sim_icache_fetch(3798 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5180 */
} /* line 5180 */
  sim_icache_fetch(3800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5182 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5183 */
  sim_icache_fetch(3802 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5185 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5186 */
   __CMPLEU(reg_b0_3, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5187 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5188 */
   __ADD_CYCLES(1);
} /* line 5188 */
  sim_icache_fetch(3808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5190 */
} /* line 5190 */
  sim_icache_fetch(3809 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5192 */
} /* line 5192 */
  sim_icache_fetch(3811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5194 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5195 */
  sim_icache_fetch(3813 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5197 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5198 */
   __CMPLEU(reg_b0_4, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5199 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5200 */
   __ADD_CYCLES(1);
} /* line 5200 */
  sim_icache_fetch(3819 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5202 */
} /* line 5202 */
  sim_icache_fetch(3820 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5204 */
} /* line 5204 */
  sim_icache_fetch(3822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5206 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5207 */
  sim_icache_fetch(3824 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5209 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5210 */
   __CMPLEU(reg_b0_5, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5211 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5212 */
   __ADD_CYCLES(1);
} /* line 5212 */
  sim_icache_fetch(3830 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5214 */
} /* line 5214 */
  sim_icache_fetch(3831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5216 */
} /* line 5216 */
  sim_icache_fetch(3833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5218 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5219 */
  sim_icache_fetch(3835 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5221 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5222 */
   __CMPLEU(reg_b0_6, reg_r0_22, ((unsigned int) htab + (unsigned int) 4096)); /* line 5223 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5224 */
   __ADD_CYCLES(1);
} /* line 5224 */
  sim_icache_fetch(3841 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5226 */
} /* line 5226 */
  sim_icache_fetch(3842 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5228 */
} /* line 5228 */
  sim_icache_fetch(3844 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5230 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5231 */
  sim_icache_fetch(3846 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5233 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5234 */
   __MTB(reg_b0_7, reg_r0_30); /* line 5235 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5236 */
   __ADD_CYCLES(1);
} /* line 5236 */
  sim_icache_fetch(3851 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5238 */
} /* line 5238 */
  sim_icache_fetch(3852 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5240 */
} /* line 5240 */
  sim_icache_fetch(3854 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5242 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5243 */
  sim_icache_fetch(3856 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5245 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5246 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5247 */
   __ADD_CYCLES(1);
} /* line 5247 */
  sim_icache_fetch(3860 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5249 */
} /* line 5249 */
  sim_icache_fetch(3861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5251 */
} /* line 5251 */
  sim_icache_fetch(3863 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5253 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5254 */
  sim_icache_fetch(3865 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5256 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5257 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5258 */
   __ADD_CYCLES(1);
} /* line 5258 */
  sim_icache_fetch(3869 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5260 */
} /* line 5260 */
  sim_icache_fetch(3870 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5262 */
} /* line 5262 */
  sim_icache_fetch(3872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5264 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5265 */
  sim_icache_fetch(3874 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5267 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5268 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5269 */
   __ADD_CYCLES(1);
} /* line 5269 */
  sim_icache_fetch(3878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5271 */
} /* line 5271 */
  sim_icache_fetch(3879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5273 */
} /* line 5273 */
  sim_icache_fetch(3881 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5275 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5276 */
  sim_icache_fetch(3883 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5278 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5279 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5280 */
   __ADD_CYCLES(1);
} /* line 5280 */
  sim_icache_fetch(3887 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5282 */
} /* line 5282 */
  sim_icache_fetch(3888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5284 */
} /* line 5284 */
  sim_icache_fetch(3890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5286 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5287 */
  sim_icache_fetch(3892 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5289 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5290 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5291 */
   __ADD_CYCLES(1);
} /* line 5291 */
  sim_icache_fetch(3896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5293 */
} /* line 5293 */
  sim_icache_fetch(3897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5295 */
} /* line 5295 */
  sim_icache_fetch(3899 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5297 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5298 */
  sim_icache_fetch(3901 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_22, mem_trace_ld(reg_r0_22,0,1)); /* line 5300 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5301 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5302 */
   __ADD_CYCLES(1);
} /* line 5302 */
  sim_icache_fetch(3905 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5304 */
} /* line 5304 */
  sim_icache_fetch(3906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5306 */
} /* line 5306 */
  sim_icache_fetch(3908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_22); /* line 5308 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5309 */
  sim_icache_fetch(3910 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5311 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5312 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5313 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5314 */
   __ADD_CYCLES(1);
} /* line 5314 */
  sim_icache_fetch(3915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5316 */
} /* line 5316 */
  sim_icache_fetch(3916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5318 */
} /* line 5318 */
  sim_icache_fetch(3918 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5320 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5322 */
  sim_icache_fetch(3920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5324 */
l_L241X3: ;/* line 5327 */
__LABEL(l_L241X3);
  sim_icache_fetch(3921 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5328 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5329 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5330 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5331 */
l_L244X3: ;/* line 5334 */
__LABEL(l_L244X3);
  sim_icache_fetch(3927 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5335 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5336 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5337 */
} /* line 5337 */
  sim_icache_fetch(3932 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5339 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5340 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5341 */
l_L240X3: ;/* line 5344 */
__LABEL(l_L240X3);
  sim_icache_fetch(3936 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5345 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5346 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5347 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5348 */
l_L239X3: ;/* line 5351 */
__LABEL(l_L239X3);
  sim_icache_fetch(3942 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5352 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5353 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5354 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5355 */
l_L238X3: ;/* line 5358 */
__LABEL(l_L238X3);
  sim_icache_fetch(3948 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5359 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5360 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5361 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5362 */
l_L237X3: ;/* line 5365 */
__LABEL(l_L237X3);
  sim_icache_fetch(3954 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5366 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5367 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5368 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5369 */
l_L236X3: ;/* line 5372 */
__LABEL(l_L236X3);
  sim_icache_fetch(3960 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5373 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5374 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5375 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5376 */
l_L235X3: ;/* line 5379 */
__LABEL(l_L235X3);
  sim_icache_fetch(3966 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5380 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5381 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5382 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5383 */
l_L234X3: ;/* line 5386 */
__LABEL(l_L234X3);
  sim_icache_fetch(3972 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5387 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5388 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5389 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5390 */
l_L233X3: ;/* line 5393 */
__LABEL(l_L233X3);
  sim_icache_fetch(3978 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5394 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5395 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5396 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5397 */
l_L232X3: ;/* line 5400 */
__LABEL(l_L232X3);
  sim_icache_fetch(3984 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5401 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5402 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5403 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5404 */
l_L231X3: ;/* line 5407 */
__LABEL(l_L231X3);
  sim_icache_fetch(3990 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5408 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5409 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5410 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5411 */
l_L230X3: ;/* line 5414 */
__LABEL(l_L230X3);
  sim_icache_fetch(3996 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5415 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5416 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5417 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5418 */
l_L229X3: ;/* line 5421 */
__LABEL(l_L229X3);
  sim_icache_fetch(4002 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5422 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5423 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5424 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5425 */
l_L228X3: ;/* line 5428 */
__LABEL(l_L228X3);
  sim_icache_fetch(4008 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5429 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5430 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5431 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5432 */
l_L227X3: ;/* line 5435 */
__LABEL(l_L227X3);
  sim_icache_fetch(4014 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5436 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5437 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5438 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5439 */
l_L226X3: ;/* line 5442 */
__LABEL(l_L226X3);
  sim_icache_fetch(4020 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5443 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5444 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5445 */
} /* line 5445 */
l_L242X3: ;/* line 5447 */
__LABEL(l_L242X3);
  sim_icache_fetch(4025 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5447 */
  sim_icache_fetch(4026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5449 */
} /* line 5449 */
  sim_icache_fetch(4027 + t_thisfile.offset, 1);
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
} /* line 5451 */
l_L243X3: ;/* line 5453 */
__LABEL(l_L243X3);
  sim_icache_fetch(4028 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5454 */
   __GOTO(l_L201X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L201X3;
} /* line 5455 */
l_L222X3: ;/* line 5458 */
__LABEL(l_L222X3);
  sim_icache_fetch(4030 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5459 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5460 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5461 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5462 */
l_L221X3: ;/* line 5465 */
__LABEL(l_L221X3);
  sim_icache_fetch(4034 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5466 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5467 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5468 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5469 */
l_L220X3: ;/* line 5472 */
__LABEL(l_L220X3);
  sim_icache_fetch(4038 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5473 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5474 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5475 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5476 */
l_L219X3: ;/* line 5479 */
__LABEL(l_L219X3);
  sim_icache_fetch(4042 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5480 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5481 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5482 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5483 */
l_L218X3: ;/* line 5486 */
__LABEL(l_L218X3);
  sim_icache_fetch(4046 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5487 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5488 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5489 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5490 */
l_L217X3: ;/* line 5493 */
__LABEL(l_L217X3);
  sim_icache_fetch(4050 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5494 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5495 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5496 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5497 */
l_L216X3: ;/* line 5500 */
__LABEL(l_L216X3);
  sim_icache_fetch(4054 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5501 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5502 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5503 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5504 */
l_L215X3: ;/* line 5507 */
__LABEL(l_L215X3);
  sim_icache_fetch(4058 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5508 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5509 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5510 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5511 */
l_L214X3: ;/* line 5514 */
__LABEL(l_L214X3);
  sim_icache_fetch(4062 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5515 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5516 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5517 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5518 */
l_L213X3: ;/* line 5521 */
__LABEL(l_L213X3);
  sim_icache_fetch(4066 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5522 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5523 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5524 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5525 */
l_L212X3: ;/* line 5528 */
__LABEL(l_L212X3);
  sim_icache_fetch(4070 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5529 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5530 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5531 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5532 */
l_L211X3: ;/* line 5535 */
__LABEL(l_L211X3);
  sim_icache_fetch(4074 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5536 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5537 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5538 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5539 */
l_L210X3: ;/* line 5542 */
__LABEL(l_L210X3);
  sim_icache_fetch(4078 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5543 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5544 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5545 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5546 */
l_L209X3: ;/* line 5549 */
__LABEL(l_L209X3);
  sim_icache_fetch(4082 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5550 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5551 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5552 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5553 */
l_L208X3: ;/* line 5558 */
__LABEL(l_L208X3);
  sim_icache_fetch(4086 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5559 */
} /* line 5559 */
l_L224X3: ;/* line 5561 */
__LABEL(l_L224X3);
  sim_icache_fetch(4087 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5562 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5563 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5564 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5565 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5566 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5567 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5568 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5569 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5570 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5571 */
} /* line 5571 */
  sim_icache_fetch(4098 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5573 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5574 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5575 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5576 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5577 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5578 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5579 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5580 */
} /* line 5580 */
  sim_icache_fetch(4106 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5582 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5583 */
l_L206X3: ;/* line 5586 */
__LABEL(l_L206X3);
  sim_icache_fetch(4108 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5587 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 5588 */
l_L202X3: ;/* line 5591 */
__LABEL(l_L202X3);
  sim_icache_fetch(4110 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5592 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5593 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5594 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5595 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5596 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5597 */
   __ADD_CYCLES(1);
} /* line 5597 */
  sim_icache_fetch(4116 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5600 */
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

  sim_icache_fetch(4117 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5619 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5620 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5621 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5622 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5623 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5624 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5625 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5626 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5627 */
   __ADD_CYCLES(1);
} /* line 5627 */
  sim_icache_fetch(4134 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGE(reg_r0_11, reg_r0_7, reg_r0_8); /* line 5629 */
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5630 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5631 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5632 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5633 */
} /* line 5633 */
  sim_icache_fetch(4139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5635 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_2); /* line 5636 */
} /* line 5636 */
  sim_icache_fetch(4141 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_2, reg_r0_4, reg_r0_11); /* line 5638 */
} /* line 5638 */
  sim_icache_fetch(4142 + t_thisfile.offset, 1);
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
} /* line 5640 */
  sim_icache_fetch(4143 + t_thisfile.offset, 1);
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
} /* line 5642 */
  sim_icache_fetch(4144 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5644 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5645 */
  sim_icache_fetch(4147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5647 */
} /* line 5647 */
l_L246X3: ;/* line 5650 */
__LABEL(l_L246X3);
  sim_icache_fetch(4149 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5651 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5652 */
   __MOV(reg_r0_5, 0); /* line 5653 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5654 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5655 */
   __ADD_CYCLES(1);
} /* line 5655 */
  sim_icache_fetch(4156 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5657 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5658 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5659 */
} /* line 5659 */
  sim_icache_fetch(4159 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5661 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5662 */
l_L249X3: ;/* line 5665 */
__LABEL(l_L249X3);
  sim_icache_fetch(4161 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5666 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5667 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5668 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5669 */
} /* line 5669 */
  sim_icache_fetch(4167 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5671 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5672 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5673 */
  sim_icache_fetch(4170 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5675 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5676 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5677 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5678 */
} /* line 5678 */
  sim_icache_fetch(4174 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5680 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5681 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5682 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5683 */
} /* line 5683 */
  sim_icache_fetch(4179 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5685 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5686 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5687 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5688 */
  sim_icache_fetch(4184 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5690 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5691 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5692 */
} /* line 5692 */
  sim_icache_fetch(4188 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5694 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5695 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5696 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5697 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5698 */
} /* line 5698 */
  sim_icache_fetch(4194 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5700 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5701 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5702 */
} /* line 5702 */
  sim_icache_fetch(4197 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5704 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5705 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5706 */
} /* line 5706 */
l_L252X3: ;/* line 5708 */
__LABEL(l_L252X3);
  sim_icache_fetch(4200 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5709 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5710 */
} /* line 5710 */
  sim_icache_fetch(4203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5712 */
} /* line 5712 */
  sim_icache_fetch(4204 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5714 */
} /* line 5714 */
  sim_icache_fetch(4205 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5716 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5717 */
  sim_icache_fetch(4207 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5719 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5720 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5721 */
  sim_icache_fetch(4210 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5723 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5724 */
  sim_icache_fetch(4213 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5726 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5727 */
} /* line 5727 */
  sim_icache_fetch(4217 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5729 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5730 */
} /* line 5730 */
  sim_icache_fetch(4220 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5732 */
} /* line 5732 */
  sim_icache_fetch(4221 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5734 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5735 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5736 */
} /* line 5736 */
l_L255X3: ;/* line 5738 */
__LABEL(l_L255X3);
  sim_icache_fetch(4224 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5739 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5740 */
} /* line 5740 */
  sim_icache_fetch(4227 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5742 */
} /* line 5742 */
  sim_icache_fetch(4228 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5744 */
} /* line 5744 */
  sim_icache_fetch(4229 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5746 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5747 */
  sim_icache_fetch(4231 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5749 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5750 */
  sim_icache_fetch(4233 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5752 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L256X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5753 */
  sim_icache_fetch(4236 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5755 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5756 */
} /* line 5756 */
  sim_icache_fetch(4240 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5758 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5759 */
} /* line 5759 */
  sim_icache_fetch(4243 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5761 */
} /* line 5761 */
  sim_icache_fetch(4244 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5763 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5764 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5765 */
} /* line 5765 */
l_L257X3: ;/* line 5767 */
__LABEL(l_L257X3);
  sim_icache_fetch(4247 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5768 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5769 */
} /* line 5769 */
  sim_icache_fetch(4250 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5771 */
} /* line 5771 */
  sim_icache_fetch(4251 + t_thisfile.offset, 1);
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
} /* line 5773 */
  sim_icache_fetch(4252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5775 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5776 */
  sim_icache_fetch(4254 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5778 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L258X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5779 */
  sim_icache_fetch(4257 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5781 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5782 */
} /* line 5782 */
  sim_icache_fetch(4261 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5784 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5785 */
} /* line 5785 */
  sim_icache_fetch(4264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5787 */
} /* line 5787 */
  sim_icache_fetch(4265 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5789 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5790 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5791 */
} /* line 5791 */
l_L259X3: ;/* line 5793 */
__LABEL(l_L259X3);
  sim_icache_fetch(4268 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5794 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5795 */
} /* line 5795 */
  sim_icache_fetch(4271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5797 */
} /* line 5797 */
  sim_icache_fetch(4272 + t_thisfile.offset, 1);
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
} /* line 5799 */
  sim_icache_fetch(4273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5801 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5802 */
  sim_icache_fetch(4275 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5804 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L260X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5805 */
  sim_icache_fetch(4278 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5807 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5808 */
} /* line 5808 */
  sim_icache_fetch(4282 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5810 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5811 */
} /* line 5811 */
  sim_icache_fetch(4285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5813 */
} /* line 5813 */
  sim_icache_fetch(4286 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5815 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5816 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5817 */
} /* line 5817 */
l_L261X3: ;/* line 5819 */
__LABEL(l_L261X3);
  sim_icache_fetch(4289 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5820 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5821 */
} /* line 5821 */
  sim_icache_fetch(4292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5823 */
} /* line 5823 */
  sim_icache_fetch(4293 + t_thisfile.offset, 1);
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
} /* line 5825 */
  sim_icache_fetch(4294 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5827 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5828 */
  sim_icache_fetch(4296 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5830 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5831 */
  sim_icache_fetch(4299 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5833 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5834 */
} /* line 5834 */
  sim_icache_fetch(4303 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5836 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5837 */
} /* line 5837 */
  sim_icache_fetch(4306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5839 */
} /* line 5839 */
  sim_icache_fetch(4307 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5841 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5842 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5843 */
} /* line 5843 */
l_L263X3: ;/* line 5845 */
__LABEL(l_L263X3);
  sim_icache_fetch(4310 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5846 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5847 */
} /* line 5847 */
  sim_icache_fetch(4313 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5849 */
} /* line 5849 */
  sim_icache_fetch(4314 + t_thisfile.offset, 1);
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
} /* line 5851 */
  sim_icache_fetch(4315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5853 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5854 */
  sim_icache_fetch(4317 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5856 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L264X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5857 */
  sim_icache_fetch(4320 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5859 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5860 */
} /* line 5860 */
  sim_icache_fetch(4324 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5862 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5863 */
} /* line 5863 */
  sim_icache_fetch(4327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5865 */
} /* line 5865 */
  sim_icache_fetch(4328 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5867 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5868 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5869 */
} /* line 5869 */
l_L265X3: ;/* line 5871 */
__LABEL(l_L265X3);
  sim_icache_fetch(4331 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5872 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5873 */
} /* line 5873 */
  sim_icache_fetch(4334 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5875 */
} /* line 5875 */
  sim_icache_fetch(4335 + t_thisfile.offset, 1);
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
} /* line 5877 */
  sim_icache_fetch(4336 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5879 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5880 */
  sim_icache_fetch(4338 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5882 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L266X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5883 */
  sim_icache_fetch(4341 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5885 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5886 */
} /* line 5886 */
  sim_icache_fetch(4345 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5888 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5889 */
} /* line 5889 */
  sim_icache_fetch(4348 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5891 */
} /* line 5891 */
  sim_icache_fetch(4349 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5893 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5894 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5895 */
} /* line 5895 */
l_L267X3: ;/* line 5897 */
__LABEL(l_L267X3);
  sim_icache_fetch(4352 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5898 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5899 */
} /* line 5899 */
  sim_icache_fetch(4355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5901 */
} /* line 5901 */
  sim_icache_fetch(4356 + t_thisfile.offset, 1);
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
} /* line 5903 */
  sim_icache_fetch(4357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5905 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5906 */
  sim_icache_fetch(4359 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5908 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5909 */
  sim_icache_fetch(4362 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5911 */
} /* line 5911 */
  sim_icache_fetch(4364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5913 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5914 */
   __ADD_CYCLES(1);
} /* line 5914 */
  sim_icache_fetch(4366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5916 */
} /* line 5916 */
l_L269X3: ;/* line 5918 */
__LABEL(l_L269X3);
  sim_icache_fetch(4367 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5919 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5920 */
} /* line 5920 */
  sim_icache_fetch(4370 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5922 */
} /* line 5922 */
  sim_icache_fetch(4371 + t_thisfile.offset, 1);
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
} /* line 5924 */
  sim_icache_fetch(4372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5926 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 5927 */
l_L253X3: ;/* line 5930 */
__LABEL(l_L253X3);
  sim_icache_fetch(4374 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5931 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5932 */
   __GOTO(l_L270X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L270X3;
} /* line 5933 */
l_L271X3: ;/* line 5936 */
__LABEL(l_L271X3);
  sim_icache_fetch(4377 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5937 */
   __MOV(reg_r0_7, 0); /* line 5938 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5939 */
} /* line 5939 */
  sim_icache_fetch(4381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5941 */
} /* line 5941 */
  sim_icache_fetch(4382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5943 */
} /* line 5943 */
l_L245X3: ;/* line 5946 */
__LABEL(l_L245X3);
  sim_icache_fetch(4383 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5947 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5948 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5949 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5950 */
} /* line 5950 */
  sim_icache_fetch(4389 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5952 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5953 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5954 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5955 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5956 */
} /* line 5956 */
  sim_icache_fetch(4397 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 5958 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 5959 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 5960 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 5961 */
} /* line 5961 */
  sim_icache_fetch(4401 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 5963 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 5964 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 5965 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 5966 */
} /* line 5966 */
  sim_icache_fetch(4406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 5968 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 5969 */
} /* line 5969 */
  sim_icache_fetch(4408 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5971 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 5972 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 5973 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 5974 */
} /* line 5974 */
  sim_icache_fetch(4412 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 5976 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5977 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 5978 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5979 */
   __ADD_CYCLES(1);
} /* line 5979 */
  sim_icache_fetch(4417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 5981 */
} /* line 5981 */
  sim_icache_fetch(4418 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 5983 */
} /* line 5983 */
  sim_icache_fetch(4419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 5986 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5987 */
l_L268X3: ;/* line 5990 */
__LABEL(l_L268X3);
  sim_icache_fetch(4421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5991 */
   __GOTO(l_L269X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L269X3;
} /* line 5992 */
l_L250X3: ;/* line 5995 */
__LABEL(l_L250X3);
  sim_icache_fetch(4423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 5996 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5997 */
} /* line 5997 */
l_L270X3: ;/* line 5999 */
__LABEL(l_L270X3);
  sim_icache_fetch(4425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 6000 */
} /* line 6000 */
  sim_icache_fetch(4426 + t_thisfile.offset, 1);
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
} /* line 6002 */
  sim_icache_fetch(4427 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 6005 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 6006 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6007 */
l_L266X3: ;/* line 6010 */
__LABEL(l_L266X3);
  sim_icache_fetch(4432 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6011 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6012 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6013 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6014 */
   __ADD_CYCLES(1);
} /* line 6014 */
  sim_icache_fetch(4438 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6016 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6017 */
} /* line 6017 */
  sim_icache_fetch(4440 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6019 */
   __GOTO(l_L267X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L267X3;
} /* line 6020 */
l_L264X3: ;/* line 6023 */
__LABEL(l_L264X3);
  sim_icache_fetch(4442 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6024 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6025 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6026 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6027 */
   __ADD_CYCLES(1);
} /* line 6027 */
  sim_icache_fetch(4448 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6029 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6030 */
} /* line 6030 */
  sim_icache_fetch(4450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6032 */
   __GOTO(l_L265X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L265X3;
} /* line 6033 */
l_L262X3: ;/* line 6036 */
__LABEL(l_L262X3);
  sim_icache_fetch(4452 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6037 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6038 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6039 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6040 */
   __ADD_CYCLES(1);
} /* line 6040 */
  sim_icache_fetch(4458 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6042 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6043 */
} /* line 6043 */
  sim_icache_fetch(4460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6045 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 6046 */
l_L260X3: ;/* line 6049 */
__LABEL(l_L260X3);
  sim_icache_fetch(4462 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6050 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6051 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6052 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6053 */
   __ADD_CYCLES(1);
} /* line 6053 */
  sim_icache_fetch(4468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6055 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6056 */
} /* line 6056 */
  sim_icache_fetch(4470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6058 */
   __GOTO(l_L261X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L261X3;
} /* line 6059 */
l_L258X3: ;/* line 6062 */
__LABEL(l_L258X3);
  sim_icache_fetch(4472 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6063 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6064 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6065 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6066 */
   __ADD_CYCLES(1);
} /* line 6066 */
  sim_icache_fetch(4478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6068 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6069 */
} /* line 6069 */
  sim_icache_fetch(4480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6071 */
   __GOTO(l_L259X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L259X3;
} /* line 6072 */
l_L256X3: ;/* line 6075 */
__LABEL(l_L256X3);
  sim_icache_fetch(4482 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6076 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6077 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6078 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6079 */
   __ADD_CYCLES(1);
} /* line 6079 */
  sim_icache_fetch(4488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6081 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6082 */
} /* line 6082 */
  sim_icache_fetch(4490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6084 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 6085 */
l_L254X3: ;/* line 6088 */
__LABEL(l_L254X3);
  sim_icache_fetch(4492 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6089 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6090 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6091 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6092 */
   __ADD_CYCLES(1);
} /* line 6092 */
  sim_icache_fetch(4498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6094 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6095 */
} /* line 6095 */
  sim_icache_fetch(4500 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6097 */
   __GOTO(l_L255X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L255X3;
} /* line 6098 */
l_L251X3: ;/* line 6101 */
__LABEL(l_L251X3);
  sim_icache_fetch(4502 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6102 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6103 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6104 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6105 */
} /* line 6105 */
  sim_icache_fetch(4507 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6107 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6108 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6109 */
} /* line 6109 */
  sim_icache_fetch(4510 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6111 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6112 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6113 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6114 */
} /* line 6114 */
  sim_icache_fetch(4514 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6116 */
   __GOTO(l_L252X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L252X3;
} /* line 6117 */
l_L248X3: ;/* line 6120 */
__LABEL(l_L248X3);
  sim_icache_fetch(4516 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6121 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6122 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6123 */
} /* line 6123 */
  sim_icache_fetch(4521 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6125 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6126 */
} /* line 6126 */
  sim_icache_fetch(4525 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6128 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6129 */
   __ADD_CYCLES(1);
} /* line 6129 */
  sim_icache_fetch(4528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6131 */
} /* line 6131 */
  sim_icache_fetch(4529 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6133 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 6134 */
l_L247X3: ;/* line 6137 */
__LABEL(l_L247X3);
  sim_icache_fetch(4531 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6138 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6139 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6140 */
   __ADD_CYCLES(1);
} /* line 6140 */
  sim_icache_fetch(4535 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6142 */
} /* line 6142 */
  sim_icache_fetch(4536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6144 */
} /* line 6144 */
  sim_icache_fetch(4537 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6146 */
   __GOTO(l_L246X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L246X3;
} /* line 6147 */
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

  sim_icache_fetch(4540 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6169 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6170 */
} /* line 6170 */
		 /* line 6171 */
  sim_icache_fetch(4543 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6174 */
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
} /* line 6174 */
l_lr_346: ;/* line 6174 */
__LABEL(l_lr_346);
  sim_icache_fetch(4546 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6176 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6177 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6178 */
   __ADD_CYCLES(1);
} /* line 6178 */
  sim_icache_fetch(4549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6181 */
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

  sim_icache_fetch(4550 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6227 */
   __MOV(reg_r0_3, 0); /* line 6228 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6229 */
   __ADD_CYCLES(1);
} /* line 6229 */
  sim_icache_fetch(4554 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6231 */
} /* line 6231 */
  sim_icache_fetch(4555 + t_thisfile.offset, 1);
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
} /* line 6233 */
  sim_icache_fetch(4556 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6236 */
l_L272X3: ;/* line 6239 */
__LABEL(l_L272X3);
  sim_icache_fetch(4557 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6242 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6242 */
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

  sim_icache_fetch(4559 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6258 */
} /* line 6258 */
  sim_icache_fetch(4560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6261 */
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

  sim_icache_fetch(4561 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6276 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6277 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6278 */
} /* line 6278 */
  sim_icache_fetch(4566 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6280 */
} /* line 6280 */
  sim_icache_fetch(4567 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6282 */
} /* line 6282 */
  sim_icache_fetch(4568 + t_thisfile.offset, 1);
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
} /* line 6284 */
		 /* line 6285 */
  sim_icache_fetch(4569 + t_thisfile.offset, 2);
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
} /* line 6287 */
l_lr_352: ;/* line 6287 */
__LABEL(l_lr_352);
l_L273X3: ;/* line 6289 */
__LABEL(l_L273X3);
  sim_icache_fetch(4571 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6290 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6291 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6292 */
   __ADD_CYCLES(1);
} /* line 6292 */
  sim_icache_fetch(4574 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6295 */
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

  sim_icache_fetch(4575 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6341 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6342 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6343 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6344 */
} /* line 6344 */
  sim_icache_fetch(4582 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6346 */
} /* line 6346 */
  sim_icache_fetch(4583 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6348 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6349 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6350 */
} /* line 6350 */
  sim_icache_fetch(4588 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6352 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6353 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6354 */
  sim_icache_fetch(4592 + t_thisfile.offset, 1);
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
} /* line 6356 */
l_L276X3: ;/* line 6359 */
__LABEL(l_L276X3);
  sim_icache_fetch(4593 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6360 */
   __MOV(reg_r0_3, 0); /* line 6361 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6362 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6363 */
   __ADD_CYCLES(1);
} /* line 6363 */
  sim_icache_fetch(4598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6365 */
} /* line 6365 */
  sim_icache_fetch(4599 + t_thisfile.offset, 1);
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
} /* line 6367 */
  sim_icache_fetch(4600 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6370 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6371 */
l_L277X3: ;/* line 6374 */
__LABEL(l_L277X3);
  sim_icache_fetch(4603 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6375 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6376 */
} /* line 6376 */
		 /* line 6377 */
  sim_icache_fetch(4607 + t_thisfile.offset, 2);
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
} /* line 6379 */
l_lr_358: ;/* line 6379 */
__LABEL(l_lr_358);
  sim_icache_fetch(4609 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6381 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6382 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6383 */
} /* line 6383 */
		 /* line 6384 */
  sim_icache_fetch(4614 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6386 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6387 */
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
} /* line 6388 */
l_lr_360: ;/* line 6388 */
__LABEL(l_lr_360);
  sim_icache_fetch(4620 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6390 */
   __MOV(reg_r0_3, 0); /* line 6391 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6392 */
   __ADD_CYCLES(1);
} /* line 6392 */
  sim_icache_fetch(4623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6395 */
l_L275X3: ;/* line 6398 */
__LABEL(l_L275X3);
  sim_icache_fetch(4624 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6399 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6400 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6401 */
   __ADD_CYCLES(1);
} /* line 6401 */
		 /* line 6402 */
  sim_icache_fetch(4628 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6405 */
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
} /* line 6405 */
l_lr_363: ;/* line 6405 */
__LABEL(l_lr_363);
  sim_icache_fetch(4631 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6407 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6408 */
l_L274X3: ;/* line 6411 */
__LABEL(l_L274X3);
  sim_icache_fetch(4633 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6412 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6413 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6414 */
   __ADD_CYCLES(1);
} /* line 6414 */
		 /* line 6415 */
  sim_icache_fetch(4638 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6417 */
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
} /* line 6418 */
l_lr_366: ;/* line 6418 */
__LABEL(l_lr_366);
  sim_icache_fetch(4641 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6420 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6421 */
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

  sim_icache_fetch(4643 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6440 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6441 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6442 */
} /* line 6442 */
  sim_icache_fetch(4647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6444 */
} /* line 6444 */
l_L278X3: ;/* line 6447 */
__LABEL(l_L278X3);
  sim_icache_fetch(4648 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __MOV(reg_r0_3, reg_r0_2); /* line 6448 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6449 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6450 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6451 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6452 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6453 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6454 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6455 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6456 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6457 */
} /* line 6457 */
  sim_icache_fetch(4658 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6459 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6460 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6461 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6462 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6463 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6464 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6465 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6466 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6467 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6468 */
} /* line 6468 */
  sim_icache_fetch(4668 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6470 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6471 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6472 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6473 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6474 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6475 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6476 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6477 */
  sim_icache_fetch(4676 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6479 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6480 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6481 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6482 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6483 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6484 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6485 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6486 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6487 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6488 */
} /* line 6488 */
  sim_icache_fetch(4686 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6490 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6491 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6492 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6493 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6494 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6495 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6496 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6497 */
  sim_icache_fetch(4694 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6499 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6500 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6501 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6502 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6503 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6504 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6506 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6507 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6508 */
} /* line 6508 */
  sim_icache_fetch(4704 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6510 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6511 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6512 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6513 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6514 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6515 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6516 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6517 */
  sim_icache_fetch(4712 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6519 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6520 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6521 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6522 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6523 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6525 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6527 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6528 */
} /* line 6528 */
  sim_icache_fetch(4722 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6531 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6532 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6533 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6534 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6535 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6536 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6537 */
  sim_icache_fetch(4730 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6539 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6540 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6541 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6542 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6543 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6544 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6545 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6546 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6547 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6548 */
} /* line 6548 */
  sim_icache_fetch(4740 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6550 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6551 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6552 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6553 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6554 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6555 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6556 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6557 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6558 */
  sim_icache_fetch(4749 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6560 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6561 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6562 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6564 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6565 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6567 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6568 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6569 */
} /* line 6569 */
  sim_icache_fetch(4769 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6571 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6572 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6573 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6574 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6575 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6576 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6577 */
  sim_icache_fetch(4782 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6579 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6580 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6581 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6582 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6583 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6584 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6588 */
} /* line 6588 */
  sim_icache_fetch(4802 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6590 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6591 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6592 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6593 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6594 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6595 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6596 */
  sim_icache_fetch(4815 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6600 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6601 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6602 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6604 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6605 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6606 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6607 */
} /* line 6607 */
  sim_icache_fetch(4835 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6610 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6611 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6612 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6613 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6614 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6615 */
  sim_icache_fetch(4848 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6617 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6620 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6621 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6622 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6623 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6624 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6625 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6626 */
} /* line 6626 */
  sim_icache_fetch(4868 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6628 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6629 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6630 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6631 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6632 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6633 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L287X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6634 */
  sim_icache_fetch(4881 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6636 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6637 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6639 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6640 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6641 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6642 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6644 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6645 */
} /* line 6645 */
  sim_icache_fetch(4901 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6647 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6648 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6651 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6652 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6653 */
  sim_icache_fetch(4914 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6655 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6656 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6658 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6659 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6660 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6661 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6662 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6664 */
} /* line 6664 */
  sim_icache_fetch(4934 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6666 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6667 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6668 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6669 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6670 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6671 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6672 */
  sim_icache_fetch(4947 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6674 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6675 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6676 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6677 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6678 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6679 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6680 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6681 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6682 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6683 */
} /* line 6683 */
  sim_icache_fetch(4967 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6685 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6686 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6687 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6688 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6689 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6690 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6691 */
  sim_icache_fetch(4980 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6693 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6694 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6695 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6696 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6697 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6698 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6699 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6700 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6701 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6702 */
} /* line 6702 */
  sim_icache_fetch(4999 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6704 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6705 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6706 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6707 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6708 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6709 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6710 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6711 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6712 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6713 */
} /* line 6713 */
  sim_icache_fetch(5018 + t_thisfile.offset, 1);
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
} /* line 6716 */
  sim_icache_fetch(5019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L278X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L278X3;
} /* line 6718 */
l_L291X3: ;/* line 6721 */
__LABEL(l_L291X3);
  sim_icache_fetch(5020 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6722 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6723 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6724 */
l_L293X3: ;/* line 6727 */
__LABEL(l_L293X3);
  sim_icache_fetch(5024 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6728 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6729 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6730 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6731 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 4); /* line 6732 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 5); /* line 6733 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 6); /* line 6734 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 7); /* line 6735 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6736 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6737 */
} /* line 6737 */
  sim_icache_fetch(5034 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 6739 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6740 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6741 */
  sim_icache_fetch(5037 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6743 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6744 */
  sim_icache_fetch(5039 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6746 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6747 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6748 */
  sim_icache_fetch(5042 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6750 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6751 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6752 */
  sim_icache_fetch(5045 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6754 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6755 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6756 */
  sim_icache_fetch(5048 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6758 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 12); /* line 6759 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6760 */
  sim_icache_fetch(5051 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6762 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 13); /* line 6763 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6764 */
  sim_icache_fetch(5054 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6766 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 14); /* line 6767 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6768 */
  sim_icache_fetch(5057 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6770 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 15); /* line 6771 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6772 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6773 */
  sim_icache_fetch(5061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6775 */
   __CMPGT(reg_b0_0, reg_r0_5, 0); /* line 6776 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6777 */
  sim_icache_fetch(5064 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6779 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6780 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6781 */
  sim_icache_fetch(5067 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6783 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6784 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6785 */
  sim_icache_fetch(5070 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6787 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6788 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6789 */
  sim_icache_fetch(5073 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6791 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 4); /* line 6792 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6793 */
  sim_icache_fetch(5076 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6795 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 5); /* line 6796 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6797 */
  sim_icache_fetch(5079 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6799 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 6); /* line 6800 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6801 */
  sim_icache_fetch(5082 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6803 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 7); /* line 6804 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6805 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6806 */
  sim_icache_fetch(5086 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6808 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 8); /* line 6809 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6810 */
  sim_icache_fetch(5089 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6812 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6813 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6814 */
  sim_icache_fetch(5092 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6816 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6817 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6818 */
  sim_icache_fetch(5095 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6820 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6821 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6822 */
  sim_icache_fetch(5098 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6824 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 12); /* line 6825 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6826 */
  sim_icache_fetch(5101 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6828 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 13); /* line 6829 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6830 */
  sim_icache_fetch(5104 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6832 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 14); /* line 6833 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6834 */
  sim_icache_fetch(5107 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6836 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 15); /* line 6837 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6838 */
  sim_icache_fetch(5110 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6840 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6841 */
  sim_icache_fetch(5112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6843 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6844 */
  sim_icache_fetch(5114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6846 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6847 */
  sim_icache_fetch(5116 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6849 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6850 */
  sim_icache_fetch(5118 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6852 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6853 */
  sim_icache_fetch(5120 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6855 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6856 */
  sim_icache_fetch(5122 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6858 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6859 */
  sim_icache_fetch(5124 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6861 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6862 */
l_L294X3: ;/* line 6865 */
__LABEL(l_L294X3);
  sim_icache_fetch(5126 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6867 */
l_L290X3: ;/* line 6870 */
__LABEL(l_L290X3);
  sim_icache_fetch(5127 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6871 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6872 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6873 */
l_L289X3: ;/* line 6876 */
__LABEL(l_L289X3);
  sim_icache_fetch(5131 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6877 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6878 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6879 */
l_L288X3: ;/* line 6882 */
__LABEL(l_L288X3);
  sim_icache_fetch(5135 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6883 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6884 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6885 */
l_L287X3: ;/* line 6888 */
__LABEL(l_L287X3);
  sim_icache_fetch(5139 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6889 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6890 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6891 */
l_L286X3: ;/* line 6894 */
__LABEL(l_L286X3);
  sim_icache_fetch(5143 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6895 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6896 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6897 */
l_L285X3: ;/* line 6900 */
__LABEL(l_L285X3);
  sim_icache_fetch(5147 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6901 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6902 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6903 */
l_L284X3: ;/* line 6906 */
__LABEL(l_L284X3);
  sim_icache_fetch(5151 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6907 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6908 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6909 */
l_L283X3: ;/* line 6912 */
__LABEL(l_L283X3);
  sim_icache_fetch(5155 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6913 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6914 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6915 */
l_L282X3: ;/* line 6918 */
__LABEL(l_L282X3);
  sim_icache_fetch(5159 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6919 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6920 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6921 */
l_L281X3: ;/* line 6924 */
__LABEL(l_L281X3);
  sim_icache_fetch(5162 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6925 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6926 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6927 */
l_L280X3: ;/* line 6930 */
__LABEL(l_L280X3);
  sim_icache_fetch(5165 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6931 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6932 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6933 */
l_L279X3: ;/* line 6936 */
__LABEL(l_L279X3);
  sim_icache_fetch(5168 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6937 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6938 */
} /* line 6938 */
l_L292X3: ;/* line 6940 */
__LABEL(l_L292X3);
  sim_icache_fetch(5170 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6941 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6942 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6943 */
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

  sim_icache_fetch(5173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6959 */
} /* line 6959 */
  sim_icache_fetch(5174 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6962 */
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

  sim_icache_fetch(5175 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6978 */
} /* line 6978 */
  sim_icache_fetch(5176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6981 */
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


static sim_fileinfo_t t_thisfile = {"compress.s", 5184, 0, 0, 0, 2};

