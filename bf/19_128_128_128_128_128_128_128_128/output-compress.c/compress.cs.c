/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/19_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_15983Xoffset[1];
unsigned int compress_15983Xbuf[3];
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
unsigned int compress_15983XBuf[216]; 
unsigned int compress_15983Xrcs_ident[6]; 
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

unsigned int compress_15983XBuf[216] = { 
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

unsigned int compress_15983Xrcs_ident[6] = { 
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
   __MOV(reg_r0_5, (unsigned int) compress_15983XBuf); /* line 35 */
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

  sim_icache_fetch(44 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 177 */
   __SXTB(reg_r0_4, reg_r0_4); /* line 178 */
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 179 */
   __MOV(reg_r0_5, 0); /* line 180 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 181 */
   __ADD(reg_r0_34, reg_r0_3, (unsigned int) 15); /* line 182 */
   __ADD(reg_r0_32, reg_r0_3, (unsigned int) 14); /* line 183 */
   __ADD(reg_r0_30, reg_r0_3, (unsigned int) 13); /* line 184 */
   __ADD(reg_r0_28, reg_r0_3, (unsigned int) 12); /* line 185 */
   __ADD(reg_r0_26, reg_r0_3, (unsigned int) 11); /* line 186 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 10); /* line 187 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 9); /* line 188 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 8); /* line 189 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 7); /* line 190 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 6); /* line 191 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 192 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 193 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 194 */
   __MOV(reg_r0_2, reg_r0_3); /* line 195 */
} /* line 195 */
  sim_icache_fetch(63 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st(reg_r0_1,0,4), reg_r0_57); /* line 197 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 4),0,4), reg_r0_58); /* line 198 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 8),0,4), reg_r0_59); /* line 199 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 12),0,4), reg_r0_60); /* line 200 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_61); /* line 201 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_62); /* line 202 */
} /* line 202 */
l_L0X3: ;/* line 205 */
__LABEL(l_L0X3);
  sim_icache_fetch(69 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
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
   __LDBs(reg_r0_35, mem_trace_ld(reg_r0_34,0,1)); /* line 221 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) 16); /* line 222 */
   __ADD(reg_r0_37, reg_r0_32, (unsigned int) 16); /* line 223 */
   __ADD(reg_r0_38, reg_r0_30, (unsigned int) 16); /* line 224 */
} /* line 224 */
  sim_icache_fetch(88 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(16);
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
   __ADD(reg_r0_50, reg_r0_34, (unsigned int) 16); /* line 237 */
   __ADD(reg_r0_51, reg_r0_2, (unsigned int) 16); /* line 238 */
   __LDBs(reg_r0_52, mem_trace_ld(reg_r0_36,0,1)); /* line 239 */
   __LDBs(reg_r0_53, mem_trace_ld(reg_r0_38,0,1)); /* line 240 */
   __LDBs(reg_r0_54, mem_trace_ld(reg_r0_37,0,1)); /* line 241 */
} /* line 241 */
  sim_icache_fetch(104 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 243 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 244 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 245 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 246 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 247 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 248 */
   __CMPNE(reg_b0_6, reg_r0_11, 0); /* line 249 */
   __CMPEQ(reg_b0_7, reg_r0_11, reg_r0_4); /* line 250 */
   __LDBs(reg_r0_3, mem_trace_ld(reg_r0_51,0,1)); /* line 251 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_49,0,1)); /* line 252 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_48,0,1)); /* line 253 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_47,0,1)); /* line 254 */
   __LDBs(reg_r0_55, mem_trace_ld(reg_r0_46,0,1)); /* line 255 */
   __LDBs(reg_r0_56, mem_trace_ld(reg_r0_45,0,1)); /* line 256 */
   __LDBs(reg_r0_57, mem_trace_ld(reg_r0_44,0,1)); /* line 257 */
   __LDBs(reg_r0_58, mem_trace_ld(reg_r0_43,0,1)); /* line 258 */
   __LDBs(reg_r0_59, mem_trace_ld(reg_r0_42,0,1)); /* line 259 */
   __LDBs(reg_r0_60, mem_trace_ld(reg_r0_41,0,1)); /* line 260 */
   __LDBs(reg_r0_61, mem_trace_ld(reg_r0_40,0,1)); /* line 261 */
} /* line 261 */
  sim_icache_fetch(123 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_2, reg_b0_1, reg_r0_2, reg_r0_5); /* line 263 */
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 264 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 265 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_39,0,1)); /* line 266 */
   __LDBs(reg_r0_62, mem_trace_ld(reg_r0_50,0,1)); /* line 267 */
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
   __ADD(reg_r0_2, reg_r0_51, (unsigned int) 16); /* line 278 */
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
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 336 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 337 */
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
   __CMPNE(reg_b0_2, reg_r0_52, 0); /* line 342 */
   __CMPEQ(reg_b0_3, reg_r0_52, reg_r0_4); /* line 343 */
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
   __CMPNE(reg_b0_4, reg_r0_7, 0); /* line 348 */
   __CMPEQ(reg_b0_5, reg_r0_7, reg_r0_4); /* line 349 */
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
   __CMPNE(reg_b0_6, reg_r0_9, 0); /* line 354 */
   __CMPEQ(reg_b0_7, reg_r0_9, reg_r0_4); /* line 355 */
   __ADD(reg_r0_30, reg_r0_38, (unsigned int) 16); /* line 356 */
   __ADD(reg_r0_34, reg_r0_50, (unsigned int) 16); /* line 357 */
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
   __SLCT(reg_r0_51, reg_b0_1, reg_r0_51, reg_r0_5); /* line 360 */
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 361 */
   __CMPEQ(reg_b0_1, reg_r0_11, reg_r0_4); /* line 362 */
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
   __SLCT(reg_r0_36, reg_b0_3, reg_r0_36, reg_r0_51); /* line 366 */
   __CMPNE(reg_b0_2, reg_r0_55, 0); /* line 367 */
   __CMPEQ(reg_b0_3, reg_r0_55, reg_r0_4); /* line 368 */
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
   __CMPNE(reg_b0_4, reg_r0_56, 0); /* line 372 */
   __CMPEQ(reg_b0_5, reg_r0_56, reg_r0_4); /* line 373 */
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
   __CMPNE(reg_b0_6, reg_r0_57, 0); /* line 377 */
   __CMPEQ(reg_b0_7, reg_r0_57, reg_r0_4); /* line 378 */
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
   __CMPNE(reg_b0_0, reg_r0_58, 0); /* line 382 */
   __CMPEQ(reg_b0_1, reg_r0_58, reg_r0_4); /* line 383 */
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
   __CMPNE(reg_b0_2, reg_r0_59, 0); /* line 387 */
   __CMPEQ(reg_b0_3, reg_r0_59, reg_r0_4); /* line 388 */
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
   __CMPNE(reg_b0_4, reg_r0_60, 0); /* line 392 */
   __CMPEQ(reg_b0_5, reg_r0_60, reg_r0_4); /* line 393 */
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
   __CMPNE(reg_b0_6, reg_r0_61, 0); /* line 397 */
   __CMPEQ(reg_b0_7, reg_r0_61, reg_r0_4); /* line 398 */
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
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 402 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 403 */
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
   __CMPNE(reg_b0_2, reg_r0_53, 0); /* line 407 */
   __CMPEQ(reg_b0_3, reg_r0_53, reg_r0_4); /* line 408 */
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
   __CMPNE(reg_b0_4, reg_r0_54, 0); /* line 412 */
   __CMPEQ(reg_b0_5, reg_r0_54, reg_r0_4); /* line 413 */
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
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_50, reg_r0_37); /* line 430 */
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
  sim_icache_fetch(263 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_32); /* line 442 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 443 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 444 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 445 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 446 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 447 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 448 */
l_L31X3: ;/* line 451 */
__LABEL(l_L31X3);
  sim_icache_fetch(270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_30, reg_r0_38); /* line 452 */
} /* line 452 */
l_L15X3: ;/* line 455 */
__LABEL(l_L15X3);
  sim_icache_fetch(271 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_30); /* line 456 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 457 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 458 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 459 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 460 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 461 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 462 */
l_L30X3: ;/* line 465 */
__LABEL(l_L30X3);
  sim_icache_fetch(278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_28, reg_r0_39); /* line 466 */
} /* line 466 */
l_L14X3: ;/* line 469 */
__LABEL(l_L14X3);
  sim_icache_fetch(279 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_28); /* line 470 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 471 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 472 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 473 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 474 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 475 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 476 */
l_L29X3: ;/* line 479 */
__LABEL(l_L29X3);
  sim_icache_fetch(286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_26, reg_r0_40); /* line 480 */
} /* line 480 */
l_L13X3: ;/* line 483 */
__LABEL(l_L13X3);
  sim_icache_fetch(287 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_26); /* line 484 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 485 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 486 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 487 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 488 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 489 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 490 */
l_L28X3: ;/* line 493 */
__LABEL(l_L28X3);
  sim_icache_fetch(294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_24, reg_r0_41); /* line 494 */
} /* line 494 */
l_L12X3: ;/* line 497 */
__LABEL(l_L12X3);
  sim_icache_fetch(295 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_24); /* line 498 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 499 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 500 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 501 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 502 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 503 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 504 */
l_L27X3: ;/* line 507 */
__LABEL(l_L27X3);
  sim_icache_fetch(302 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_42); /* line 508 */
} /* line 508 */
l_L11X3: ;/* line 511 */
__LABEL(l_L11X3);
  sim_icache_fetch(303 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_22); /* line 512 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 513 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 514 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 515 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 516 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 517 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 518 */
l_L26X3: ;/* line 521 */
__LABEL(l_L26X3);
  sim_icache_fetch(310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_20, reg_r0_43); /* line 522 */
} /* line 522 */
l_L10X3: ;/* line 525 */
__LABEL(l_L10X3);
  sim_icache_fetch(311 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_20); /* line 526 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 527 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 528 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 529 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 530 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 531 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 532 */
l_L25X3: ;/* line 535 */
__LABEL(l_L25X3);
  sim_icache_fetch(318 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_44); /* line 536 */
} /* line 536 */
l_L9X3: ;/* line 539 */
__LABEL(l_L9X3);
  sim_icache_fetch(319 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_18); /* line 540 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 541 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 542 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 543 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 544 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 545 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 546 */
l_L24X3: ;/* line 549 */
__LABEL(l_L24X3);
  sim_icache_fetch(326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, reg_r0_45); /* line 550 */
} /* line 550 */
l_L8X3: ;/* line 553 */
__LABEL(l_L8X3);
  sim_icache_fetch(327 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_16); /* line 554 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 555 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 556 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 557 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 558 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 559 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 560 */
l_L23X3: ;/* line 563 */
__LABEL(l_L23X3);
  sim_icache_fetch(334 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_14, reg_r0_46); /* line 564 */
} /* line 564 */
l_L7X3: ;/* line 567 */
__LABEL(l_L7X3);
  sim_icache_fetch(335 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_14); /* line 568 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 569 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 570 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 571 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 572 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 573 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 574 */
l_L22X3: ;/* line 577 */
__LABEL(l_L22X3);
  sim_icache_fetch(342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, reg_r0_47); /* line 578 */
} /* line 578 */
l_L6X3: ;/* line 581 */
__LABEL(l_L6X3);
  sim_icache_fetch(343 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_12); /* line 582 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 583 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 584 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 585 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 586 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 587 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 588 */
l_L21X3: ;/* line 591 */
__LABEL(l_L21X3);
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_10, reg_r0_48); /* line 592 */
} /* line 592 */
l_L5X3: ;/* line 595 */
__LABEL(l_L5X3);
  sim_icache_fetch(351 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_10); /* line 596 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 597 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 598 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 599 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 600 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 601 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 602 */
l_L20X3: ;/* line 605 */
__LABEL(l_L20X3);
  sim_icache_fetch(358 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_49); /* line 606 */
} /* line 606 */
l_L4X3: ;/* line 609 */
__LABEL(l_L4X3);
  sim_icache_fetch(359 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_8); /* line 610 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 611 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 612 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 613 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 614 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 615 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 616 */
l_L19X3: ;/* line 619 */
__LABEL(l_L19X3);
  sim_icache_fetch(366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_36); /* line 620 */
} /* line 620 */
l_L3X3: ;/* line 623 */
__LABEL(l_L3X3);
  sim_icache_fetch(367 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_6); /* line 624 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 625 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 626 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 627 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 628 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 629 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 630 */
l_L18X3: ;/* line 633 */
__LABEL(l_L18X3);
  sim_icache_fetch(374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_51); /* line 634 */
} /* line 634 */
l_L2X3: ;/* line 637 */
__LABEL(l_L2X3);
  sim_icache_fetch(375 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_2); /* line 638 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 639 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 640 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 641 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 642 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 643 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 644 */
l_L17X3: ;/* line 647 */
__LABEL(l_L17X3);
  sim_icache_fetch(382 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_5); /* line 648 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 649 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 650 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 651 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 652 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 653 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 654 */
l_L1X3: ;/* line 657 */
__LABEL(l_L1X3);
  sim_icache_fetch(389 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_3, reg_r0_5); /* line 658 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 659 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 660 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 661 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 662 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 663 */
} /* line 663 */
l_L33X3: ;/* line 665 */
__LABEL(l_L33X3);
  sim_icache_fetch(395 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 666 */
} /* line 666 */
  sim_icache_fetch(396 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 669 */
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

  sim_icache_fetch(397 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 686 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 687 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 688 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 689 */
} /* line 689 */
  sim_icache_fetch(404 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 691 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 692 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 693 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 694 */
} /* line 694 */
  sim_icache_fetch(409 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 696 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 697 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 698 */
} /* line 698 */
		 /* line 699 */
  sim_icache_fetch(412 + t_thisfile.offset, 2);
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
} /* line 701 */
l_lr_46: ;/* line 701 */
__LABEL(l_lr_46);
  sim_icache_fetch(414 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 703 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 704 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 705 */
   __ADD_CYCLES(1);
} /* line 705 */
  sim_icache_fetch(417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 707 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 708 */
} /* line 708 */
l_L34X3: ;/* line 711 */
__LABEL(l_L34X3);
  sim_icache_fetch(419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 712 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 713 */
} /* line 713 */
  sim_icache_fetch(421 + t_thisfile.offset, 1);
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
} /* line 715 */
  sim_icache_fetch(422 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 717 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 718 */
   __ADD_CYCLES(1);
} /* line 718 */
  sim_icache_fetch(424 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 720 */
} /* line 720 */
  sim_icache_fetch(425 + t_thisfile.offset, 1);
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
} /* line 722 */
l_L37X3: ;/* line 725 */
__LABEL(l_L37X3);
  sim_icache_fetch(426 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 726 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 727 */
   __ADD_CYCLES(1);
} /* line 727 */
  sim_icache_fetch(428 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 729 */
} /* line 729 */
  sim_icache_fetch(429 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 731 */
} /* line 731 */
  sim_icache_fetch(430 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 733 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 734 */
   __ADD_CYCLES(1);
} /* line 734 */
  sim_icache_fetch(432 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 736 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 737 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 738 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 739 */
} /* line 739 */
  sim_icache_fetch(437 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 741 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 742 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 743 */
  sim_icache_fetch(440 + t_thisfile.offset, 1);
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
} /* line 745 */
  sim_icache_fetch(441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 746 */
  sim_icache_fetch(442 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 748 */
l__X1XCompressXTAGX0X0: ;/* line 750 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(443 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 751 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 752 */
l__X1XCompressXTAGX0X7: ;/* line 755 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(446 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 756 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 757 */
l__X1XCompressXTAGX0X6: ;/* line 760 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(449 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 761 */
} /* line 761 */
  sim_icache_fetch(450 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 763 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 764 */
l__X1XCompressXTAGX0X5: ;/* line 767 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(453 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 768 */
} /* line 768 */
  sim_icache_fetch(454 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 770 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 771 */
l__X1XCompressXTAGX0X4: ;/* line 774 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(457 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 775 */
} /* line 775 */
  sim_icache_fetch(458 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 777 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 778 */
l__X1XCompressXTAGX0X3: ;/* line 781 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(461 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 782 */
} /* line 782 */
  sim_icache_fetch(462 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 784 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 785 */
l__X1XCompressXTAGX0X2: ;/* line 788 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(465 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 789 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 790 */
   __ADD_CYCLES(1);
} /* line 790 */
  sim_icache_fetch(467 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 792 */
} /* line 792 */
  sim_icache_fetch(468 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 794 */
} /* line 794 */
  sim_icache_fetch(469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 796 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 797 */
   __ADD_CYCLES(1);
} /* line 797 */
  sim_icache_fetch(471 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 799 */
} /* line 799 */
  sim_icache_fetch(472 + t_thisfile.offset, 1);
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
} /* line 801 */
l_L36X3: ;/* line 803 */
__LABEL(l_L36X3);
  sim_icache_fetch(473 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 804 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 805 */
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 806 */
l_L40X3: ;/* line 809 */
__LABEL(l_L40X3);
  sim_icache_fetch(476 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 810 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 811 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 812 */
} /* line 812 */
  sim_icache_fetch(479 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 814 */
} /* line 814 */
  sim_icache_fetch(480 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 816 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 817 */
  sim_icache_fetch(482 + t_thisfile.offset, 1);
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
} /* line 820 */
  sim_icache_fetch(483 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 822 */
l_L41X3: ;/* line 825 */
__LABEL(l_L41X3);
		 /* line 825 */
  sim_icache_fetch(484 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 828 */
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
} /* line 828 */
l_lr_60: ;/* line 828 */
__LABEL(l_lr_60);
		 /* line 829 */
  sim_icache_fetch(488 + t_thisfile.offset, 2);
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
} /* line 831 */
l_lr_62: ;/* line 831 */
__LABEL(l_lr_62);
  sim_icache_fetch(490 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 833 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 834 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 835 */
   __ADD_CYCLES(1);
} /* line 835 */
  sim_icache_fetch(493 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 838 */
l__X1XCompressXTAGX0X1: ;/* line 841 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 841 */
  sim_icache_fetch(494 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 844 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 845 */
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
} /* line 845 */
l_lr_65: ;/* line 845 */
__LABEL(l_lr_65);
  sim_icache_fetch(498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 847 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 848 */
} /* line 848 */
  sim_icache_fetch(500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 850 */
l_L39X3: ;/* line 853 */
__LABEL(l_L39X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 854 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 854 */
  sim_icache_fetch(501 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 857 */
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
} /* line 857 */
l_lr_69: ;/* line 857 */
__LABEL(l_lr_69);
		 /* line 858 */
  sim_icache_fetch(505 + t_thisfile.offset, 2);
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
} /* line 860 */
l_lr_71: ;/* line 860 */
__LABEL(l_lr_71);
  sim_icache_fetch(507 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 862 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 863 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 864 */
   __ADD_CYCLES(1);
} /* line 864 */
  sim_icache_fetch(510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 867 */
l_L38X3: ;/* line 870 */
__LABEL(l_L38X3);
  sim_icache_fetch(511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 871 */
l_L35X3: ;/* line 874 */
__LABEL(l_L35X3);
  sim_icache_fetch(512 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 875 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 876 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 877 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 878 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 879 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 880 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 881 */
   __ADD_CYCLES(1);
} /* line 881 */
  sim_icache_fetch(522 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 883 */
   __CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 4096); /* line 884 */
} /* line 884 */
  sim_icache_fetch(525 + t_thisfile.offset, 1);
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
} /* line 886 */
  sim_icache_fetch(526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 888 */
} /* line 888 */
l_L43X3: ;/* line 890 */
__LABEL(l_L43X3);
  sim_icache_fetch(528 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 891 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 892 */
   __ADD_CYCLES(1);
} /* line 892 */
  sim_icache_fetch(531 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 894 */
} /* line 894 */
  sim_icache_fetch(532 + t_thisfile.offset, 1);
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
} /* line 896 */
  sim_icache_fetch(533 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 898 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 899 */
} /* line 899 */
l_L45X3: ;/* line 901 */
__LABEL(l_L45X3);
  sim_icache_fetch(537 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 902 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 903 */
   __ADD_CYCLES(1);
} /* line 903 */
  sim_icache_fetch(540 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 905 */
} /* line 905 */
  sim_icache_fetch(541 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 907 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L46X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 908 */
		 /* line 909 */
  sim_icache_fetch(544 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 911 */
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
} /* line 912 */
l_lr_77: ;/* line 912 */
__LABEL(l_lr_77);
l_L47X3: ;/* line 914 */
__LABEL(l_L47X3);
  sim_icache_fetch(548 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 915 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 916 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 917 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 918 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 919 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 920 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 921 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 922 */
} /* line 922 */
  sim_icache_fetch(564 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 924 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 925 */
} /* line 925 */
  sim_icache_fetch(568 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 927 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 928 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 929 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 930 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 931 */
} /* line 931 */
  sim_icache_fetch(574 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 933 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 934 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 935 */
  sim_icache_fetch(577 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 937 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 938 */
  sim_icache_fetch(580 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 940 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 941 */
l_L51X3: ;/* line 943 */
__LABEL(l_L51X3);
		 /* line 943 */
  sim_icache_fetch(583 + t_thisfile.offset, 2);
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
} /* line 945 */
l_lr_81: ;/* line 945 */
__LABEL(l_lr_81);
  sim_icache_fetch(585 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 947 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 948 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 949 */
   __ADD_CYCLES(1);
} /* line 949 */
  sim_icache_fetch(588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 952 */
l_L50X3: ;/* line 955 */
__LABEL(l_L50X3);
  sim_icache_fetch(589 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 956 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 957 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 958 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 959 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 960 */
   __ADD_CYCLES(1);
} /* line 960 */
  sim_icache_fetch(598 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 962 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 963 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 964 */
} /* line 964 */
  sim_icache_fetch(601 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 966 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 967 */
} /* line 967 */
  sim_icache_fetch(604 + t_thisfile.offset, 1);
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
} /* line 969 */
  sim_icache_fetch(605 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 971 */
} /* line 971 */
  sim_icache_fetch(607 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 973 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 974 */
   __ADD_CYCLES(1);
} /* line 974 */
  sim_icache_fetch(609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 976 */
} /* line 976 */
l_L53X3: ;/* line 978 */
__LABEL(l_L53X3);
  sim_icache_fetch(610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 979 */
} /* line 979 */
  sim_icache_fetch(611 + t_thisfile.offset, 1);
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
} /* line 982 */
  sim_icache_fetch(612 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 984 */
l_L54X3: ;/* line 987 */
__LABEL(l_L54X3);
  sim_icache_fetch(613 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 988 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 989 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 990 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 991 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 992 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 993 */
   __ADD_CYCLES(1);
} /* line 993 */
  sim_icache_fetch(623 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 995 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 996 */
} /* line 996 */
  sim_icache_fetch(625 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 998 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 999 */
} /* line 999 */
  sim_icache_fetch(628 + t_thisfile.offset, 1);
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
} /* line 1001 */
  sim_icache_fetch(629 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 1003 */
} /* line 1003 */
  sim_icache_fetch(631 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 1005 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1006 */
   __ADD_CYCLES(1);
} /* line 1006 */
  sim_icache_fetch(633 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 1008 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 1009 */
} /* line 1009 */
l_L56X3: ;/* line 1011 */
__LABEL(l_L56X3);
  sim_icache_fetch(636 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 1012 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 1013 */
} /* line 1013 */
  sim_icache_fetch(638 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 1015 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 1016 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 1017 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 1018 */
} /* line 1018 */
  sim_icache_fetch(644 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 1020 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1021 */
		 /* line 1022 */
  sim_icache_fetch(647 + t_thisfile.offset, 2);
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
} /* line 1024 */
l_lr_87: ;/* line 1024 */
__LABEL(l_lr_87);
  sim_icache_fetch(649 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1026 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1027 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1028 */
   __ADD_CYCLES(1);
} /* line 1028 */
  sim_icache_fetch(652 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1031 */
l_L48X3: ;/* line 1034 */
__LABEL(l_L48X3);
		 /* line 1034 */
  sim_icache_fetch(653 + t_thisfile.offset, 2);
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
} /* line 1036 */
l_lr_90: ;/* line 1036 */
__LABEL(l_lr_90);
  sim_icache_fetch(655 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 1038 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1039 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1040 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1041 */
   __ADD_CYCLES(1);
} /* line 1041 */
  sim_icache_fetch(659 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 1044 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1045 */
l_L55X3: ;/* line 1048 */
__LABEL(l_L55X3);
  sim_icache_fetch(662 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 1049 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 1050 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 1051 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 1052 */
} /* line 1052 */
  sim_icache_fetch(668 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 1054 */
   __GOTO(l_L56X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L56X3;
} /* line 1055 */
l_L52X3: ;/* line 1058 */
__LABEL(l_L52X3);
  sim_icache_fetch(671 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 1059 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1060 */
   __GOTO(l_L53X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L53X3;
} /* line 1061 */
l_L49X3: ;/* line 1064 */
__LABEL(l_L49X3);
  sim_icache_fetch(675 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 1065 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1066 */
} /* line 1066 */
  sim_icache_fetch(678 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1068 */
} /* line 1068 */
  sim_icache_fetch(679 + t_thisfile.offset, 1);
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
} /* line 1071 */
  sim_icache_fetch(680 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 1073 */
l_L46X3: ;/* line 1076 */
__LABEL(l_L46X3);
  sim_icache_fetch(681 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1077 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1078 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1079 */
   __ADD_CYCLES(1);
} /* line 1079 */
  sim_icache_fetch(686 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1081 */
} /* line 1081 */
  sim_icache_fetch(688 + t_thisfile.offset, 1);
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
} /* line 1083 */
		 /* line 1084 */
  sim_icache_fetch(689 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1086 */
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
} /* line 1087 */
l_lr_96: ;/* line 1087 */
__LABEL(l_lr_96);
  sim_icache_fetch(693 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1089 */
l_L57X3: ;/* line 1092 */
__LABEL(l_L57X3);
  sim_icache_fetch(694 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1093 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1094 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1095 */
   __ADD_CYCLES(1);
} /* line 1095 */
  sim_icache_fetch(699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1097 */
} /* line 1097 */
  sim_icache_fetch(701 + t_thisfile.offset, 1);
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
} /* line 1099 */
		 /* line 1100 */
  sim_icache_fetch(702 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1102 */
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
} /* line 1103 */
l_lr_99: ;/* line 1103 */
__LABEL(l_lr_99);
  sim_icache_fetch(706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1105 */
l_L58X3: ;/* line 1108 */
__LABEL(l_L58X3);
  sim_icache_fetch(707 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1109 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1110 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1111 */
   __ADD_CYCLES(1);
} /* line 1111 */
  sim_icache_fetch(712 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1113 */
} /* line 1113 */
  sim_icache_fetch(714 + t_thisfile.offset, 1);
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
} /* line 1115 */
		 /* line 1116 */
  sim_icache_fetch(715 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1118 */
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
} /* line 1119 */
l_lr_102: ;/* line 1119 */
__LABEL(l_lr_102);
  sim_icache_fetch(719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1121 */
l_L59X3: ;/* line 1124 */
__LABEL(l_L59X3);
  sim_icache_fetch(720 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1125 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1126 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1127 */
   __ADD_CYCLES(1);
} /* line 1127 */
  sim_icache_fetch(725 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1129 */
} /* line 1129 */
  sim_icache_fetch(727 + t_thisfile.offset, 1);
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
} /* line 1131 */
		 /* line 1132 */
  sim_icache_fetch(728 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1134 */
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
} /* line 1135 */
l_lr_105: ;/* line 1135 */
__LABEL(l_lr_105);
  sim_icache_fetch(732 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1137 */
l_L60X3: ;/* line 1140 */
__LABEL(l_L60X3);
		 /* line 1140 */
  sim_icache_fetch(733 + t_thisfile.offset, 2);
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
} /* line 1142 */
l_lr_108: ;/* line 1142 */
__LABEL(l_lr_108);
  sim_icache_fetch(735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1144 */
l_L44X3: ;/* line 1147 */
__LABEL(l_L44X3);
  sim_icache_fetch(736 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1148 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1149 */
} /* line 1149 */
  sim_icache_fetch(739 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1151 */
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 1152 */
l_L42X3: ;/* line 1155 */
__LABEL(l_L42X3);
  sim_icache_fetch(742 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1156 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1157 */
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1158 */
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

  sim_icache_fetch(745 + t_thisfile.offset, 23);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1296 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1297 */
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1298 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1299 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1300 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1301 */
   __MOV(reg_r0_4, 0); /* line 1302 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1303 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1304 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1305 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1306 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1307 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1308 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1309 */
} /* line 1309 */
  sim_icache_fetch(768 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1311 */
} /* line 1311 */
  sim_icache_fetch(769 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1313 */
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 1314 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1315 */
   __ADD(reg_r0_15, reg_r0_14, (unsigned int) 1); /* line 1316 */
} /* line 1316 */
  sim_icache_fetch(773 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, (unsigned int) 256); /* line 1318 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 1319 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1320 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1321 */
l_L62X3: ;/* line 1323 */
__LABEL(l_L62X3);
  sim_icache_fetch(778 + t_thisfile.offset, 23);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __STW(mem_trace_st((unsigned int) compress_15983Xoffset,0,4), 0); /* line 1324 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1325 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1326 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1327 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1328 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1329 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1330 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1331 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1332 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1333 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1334 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1335 */
  sim_icache_fetch(801 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 1337 */
} /* line 1337 */
  sim_icache_fetch(803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1339 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1340 */
   __ADD_CYCLES(1);
} /* line 1340 */
  sim_icache_fetch(805 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1342 */
} /* line 1342 */
l_L64X3: ;/* line 1344 */
__LABEL(l_L64X3);
  sim_icache_fetch(806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1345 */
} /* line 1345 */
l_L65X3: ;/* line 1348 */
__LABEL(l_L65X3);
  sim_icache_fetch(807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1349 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1350 */
} /* line 1350 */
  sim_icache_fetch(809 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1352 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1353 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1354 */
  sim_icache_fetch(812 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1358 */
  sim_icache_fetch(815 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1362 */
  sim_icache_fetch(818 + t_thisfile.offset, 3);
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
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1366 */
  sim_icache_fetch(821 + t_thisfile.offset, 3);
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
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1370 */
  sim_icache_fetch(824 + t_thisfile.offset, 3);
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
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1374 */
  sim_icache_fetch(827 + t_thisfile.offset, 3);
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
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1378 */
  sim_icache_fetch(830 + t_thisfile.offset, 3);
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
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1382 */
  sim_icache_fetch(833 + t_thisfile.offset, 3);
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
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1386 */
  sim_icache_fetch(836 + t_thisfile.offset, 3);
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
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1390 */
  sim_icache_fetch(839 + t_thisfile.offset, 3);
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
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1394 */
  sim_icache_fetch(842 + t_thisfile.offset, 3);
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
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1398 */
  sim_icache_fetch(845 + t_thisfile.offset, 3);
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
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1402 */
  sim_icache_fetch(848 + t_thisfile.offset, 3);
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
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1406 */
  sim_icache_fetch(851 + t_thisfile.offset, 3);
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
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1410 */
  sim_icache_fetch(854 + t_thisfile.offset, 3);
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
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1414 */
  sim_icache_fetch(857 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1416 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1417 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1418 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1419 */
  sim_icache_fetch(861 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1421 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1422 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1423 */
  sim_icache_fetch(864 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1425 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1426 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1427 */
  sim_icache_fetch(867 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1429 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1430 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1431 */
  sim_icache_fetch(870 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1433 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1434 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1435 */
  sim_icache_fetch(873 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1437 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1438 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1439 */
  sim_icache_fetch(876 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1441 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1442 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1443 */
  sim_icache_fetch(879 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1445 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1446 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1447 */
  sim_icache_fetch(882 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1449 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1450 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1451 */
  sim_icache_fetch(885 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1453 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1454 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1455 */
  sim_icache_fetch(888 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1457 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1458 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1459 */
  sim_icache_fetch(891 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1461 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1462 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1463 */
  sim_icache_fetch(894 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1465 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1466 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1467 */
  sim_icache_fetch(897 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1469 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1470 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1471 */
  sim_icache_fetch(900 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1473 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1474 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1475 */
  sim_icache_fetch(903 + t_thisfile.offset, 1);
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
} /* line 1477 */
  sim_icache_fetch(904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1479 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 1480 */
l_L81X3: ;/* line 1483 */
__LABEL(l_L81X3);
  sim_icache_fetch(906 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1484 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1485 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1486 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1487 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1488 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1489 */
l_L83X3: ;/* line 1492 */
__LABEL(l_L83X3);
  sim_icache_fetch(913 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1493 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1494 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1495 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1496 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1497 */
   __ADD_CYCLES(1);
} /* line 1497 */
  sim_icache_fetch(922 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1499 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1500 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1501 */
} /* line 1501 */
  sim_icache_fetch(925 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1503 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1504 */
} /* line 1504 */
  sim_icache_fetch(928 + t_thisfile.offset, 1);
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
} /* line 1506 */
  sim_icache_fetch(929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1508 */
} /* line 1508 */
  sim_icache_fetch(931 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1510 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1511 */
   __ADD_CYCLES(1);
} /* line 1511 */
  sim_icache_fetch(933 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1513 */
} /* line 1513 */
l_L85X3: ;/* line 1515 */
__LABEL(l_L85X3);
  sim_icache_fetch(934 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1516 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1517 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1518 */
} /* line 1518 */
  sim_icache_fetch(937 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1520 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1521 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1522 */
  sim_icache_fetch(940 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1524 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1525 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1526 */
} /* line 1526 */
  sim_icache_fetch(946 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1528 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1529 */
   __ADD_CYCLES(1);
} /* line 1529 */
  sim_icache_fetch(948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1531 */
} /* line 1531 */
  sim_icache_fetch(949 + t_thisfile.offset, 1);
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
} /* line 1533 */
  sim_icache_fetch(950 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1535 */
} /* line 1535 */
  sim_icache_fetch(951 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1537 */
l_L87X3: ;/* line 1540 */
__LABEL(l_L87X3);
  sim_icache_fetch(952 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1541 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1542 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1543 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1544 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1545 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1546 */
} /* line 1546 */
  sim_icache_fetch(959 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1548 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1549 */
   __ADD_CYCLES(1);
} /* line 1549 */
  sim_icache_fetch(961 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1551 */
} /* line 1551 */
  sim_icache_fetch(962 + t_thisfile.offset, 1);
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
} /* line 1553 */
l_L89X3: ;/* line 1555 */
__LABEL(l_L89X3);
		 /* line 1555 */
  sim_icache_fetch(963 + t_thisfile.offset, 2);
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
} /* line 1557 */
l_lr_121: ;/* line 1557 */
__LABEL(l_lr_121);
  sim_icache_fetch(965 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1559 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1560 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1561 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1562 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1563 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1564 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1565 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1566 */
   __ADD_CYCLES(1);
} /* line 1566 */
  sim_icache_fetch(976 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1568 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1569 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1570 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1571 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1572 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1573 */
} /* line 1573 */
  sim_icache_fetch(984 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1575 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1576 */
  sim_icache_fetch(987 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1578 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1579 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1580 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1581 */
l_L90X3: ;/* line 1584 */
__LABEL(l_L90X3);
  sim_icache_fetch(992 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1585 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1586 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1587 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1588 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1589 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1590 */
   __ADD_CYCLES(1);
} /* line 1590 */
  sim_icache_fetch(1001 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1592 */
} /* line 1592 */
  sim_icache_fetch(1002 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1594 */
} /* line 1594 */
  sim_icache_fetch(1003 + t_thisfile.offset, 1);
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
} /* line 1596 */
		 /* line 1597 */
  sim_icache_fetch(1004 + t_thisfile.offset, 2);
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
} /* line 1599 */
l_lr_124: ;/* line 1599 */
__LABEL(l_lr_124);
  sim_icache_fetch(1006 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1601 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1602 */
} /* line 1602 */
  sim_icache_fetch(1008 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1604 */
l_L91X3: ;/* line 1607 */
__LABEL(l_L91X3);
  sim_icache_fetch(1009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1608 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1609 */
} /* line 1609 */
  sim_icache_fetch(1011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1611 */
l_L88X3: ;/* line 1614 */
__LABEL(l_L88X3);
  sim_icache_fetch(1012 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1615 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1616 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1617 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1618 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1619 */
   __ADD_CYCLES(1);
} /* line 1619 */
  sim_icache_fetch(1017 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1621 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1622 */
} /* line 1622 */
  sim_icache_fetch(1019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1624 */
} /* line 1624 */
l_L92X3: ;/* line 1627 */
__LABEL(l_L92X3);
  sim_icache_fetch(1020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1628 */
} /* line 1628 */
  sim_icache_fetch(1021 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1630 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1631 */
} /* line 1631 */
  sim_icache_fetch(1023 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1633 */
} /* line 1633 */
  sim_icache_fetch(1024 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1635 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1636 */
} /* line 1636 */
  sim_icache_fetch(1027 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1638 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1639 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1640 */
} /* line 1640 */
  sim_icache_fetch(1030 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1642 */
} /* line 1642 */
  sim_icache_fetch(1031 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1644 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1645 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1646 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1647 */
} /* line 1647 */
  sim_icache_fetch(1036 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1649 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1650 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1651 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1652 */
  sim_icache_fetch(1040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1654 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1655 */
  sim_icache_fetch(1042 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1657 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1658 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1659 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1660 */
} /* line 1660 */
  sim_icache_fetch(1047 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1662 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1663 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1664 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1665 */
  sim_icache_fetch(1051 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1667 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1668 */
  sim_icache_fetch(1053 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1670 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1671 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1672 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1673 */
} /* line 1673 */
  sim_icache_fetch(1058 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1675 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1676 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1677 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1678 */
  sim_icache_fetch(1062 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1680 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1681 */
  sim_icache_fetch(1064 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1683 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1684 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1685 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1686 */
} /* line 1686 */
  sim_icache_fetch(1069 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1688 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1689 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1690 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1691 */
  sim_icache_fetch(1073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1693 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1694 */
  sim_icache_fetch(1075 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1696 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1697 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1698 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1699 */
} /* line 1699 */
  sim_icache_fetch(1080 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1701 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1702 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1703 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1704 */
  sim_icache_fetch(1084 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1706 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1707 */
  sim_icache_fetch(1086 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1709 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1710 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1711 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1712 */
} /* line 1712 */
  sim_icache_fetch(1091 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1714 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1715 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1716 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1717 */
  sim_icache_fetch(1095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1719 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1720 */
  sim_icache_fetch(1097 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1722 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1723 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1724 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1725 */
} /* line 1725 */
  sim_icache_fetch(1102 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1727 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1728 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1729 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1730 */
  sim_icache_fetch(1106 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1732 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1733 */
  sim_icache_fetch(1108 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1735 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1736 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1737 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1738 */
} /* line 1738 */
  sim_icache_fetch(1113 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1740 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1741 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1742 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1743 */
  sim_icache_fetch(1117 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1745 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1746 */
  sim_icache_fetch(1119 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1748 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1749 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1750 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1751 */
} /* line 1751 */
  sim_icache_fetch(1124 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1753 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1754 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1755 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1756 */
  sim_icache_fetch(1128 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1758 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1759 */
  sim_icache_fetch(1130 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1761 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1762 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1763 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1764 */
} /* line 1764 */
  sim_icache_fetch(1135 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1766 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1767 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1768 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1769 */
  sim_icache_fetch(1139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1771 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1772 */
  sim_icache_fetch(1141 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1774 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1775 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1776 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1777 */
} /* line 1777 */
  sim_icache_fetch(1146 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1779 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1780 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1781 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1782 */
  sim_icache_fetch(1150 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1784 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1785 */
  sim_icache_fetch(1152 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1787 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1788 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1789 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1790 */
} /* line 1790 */
  sim_icache_fetch(1157 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1792 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1793 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1794 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1795 */
  sim_icache_fetch(1161 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1797 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1798 */
  sim_icache_fetch(1163 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1800 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1801 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1802 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1803 */
} /* line 1803 */
  sim_icache_fetch(1168 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1805 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1806 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1807 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1808 */
  sim_icache_fetch(1172 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1810 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1811 */
  sim_icache_fetch(1174 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1813 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1814 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1815 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1816 */
} /* line 1816 */
  sim_icache_fetch(1179 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1818 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1819 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1820 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1821 */
  sim_icache_fetch(1183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1823 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1824 */
  sim_icache_fetch(1185 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1826 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1827 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1828 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1829 */
} /* line 1829 */
  sim_icache_fetch(1190 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1831 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1832 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1833 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1834 */
  sim_icache_fetch(1194 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1836 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1837 */
  sim_icache_fetch(1196 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1839 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1840 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1841 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1842 */
} /* line 1842 */
  sim_icache_fetch(1201 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1844 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1845 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1846 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1847 */
  sim_icache_fetch(1205 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1849 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1850 */
  sim_icache_fetch(1207 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1852 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1853 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1854 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1855 */
} /* line 1855 */
  sim_icache_fetch(1212 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1857 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1858 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1859 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1860 */
  sim_icache_fetch(1216 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1862 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1863 */
  sim_icache_fetch(1218 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1865 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1866 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1867 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1868 */
} /* line 1868 */
  sim_icache_fetch(1223 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1870 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1871 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1872 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1873 */
  sim_icache_fetch(1227 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1875 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1876 */
  sim_icache_fetch(1229 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1878 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1879 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1880 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1881 */
} /* line 1881 */
  sim_icache_fetch(1234 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1883 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1884 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1885 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1886 */
  sim_icache_fetch(1238 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1888 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1889 */
  sim_icache_fetch(1240 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1891 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1892 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1893 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1894 */
} /* line 1894 */
  sim_icache_fetch(1245 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1896 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1897 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1898 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1899 */
  sim_icache_fetch(1249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1901 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1902 */
  sim_icache_fetch(1251 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1904 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1905 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1906 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1907 */
} /* line 1907 */
  sim_icache_fetch(1256 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1909 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1910 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1911 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1912 */
  sim_icache_fetch(1260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1914 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1915 */
  sim_icache_fetch(1262 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1917 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1918 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1919 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1920 */
} /* line 1920 */
  sim_icache_fetch(1267 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1922 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1923 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1924 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1925 */
  sim_icache_fetch(1271 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1927 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1928 */
  sim_icache_fetch(1273 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1930 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1931 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1932 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1933 */
} /* line 1933 */
  sim_icache_fetch(1278 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1935 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1936 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1937 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1938 */
  sim_icache_fetch(1282 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1940 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1941 */
  sim_icache_fetch(1284 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1943 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1944 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1945 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1946 */
} /* line 1946 */
  sim_icache_fetch(1289 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1948 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1949 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1950 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1951 */
  sim_icache_fetch(1293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1953 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1954 */
  sim_icache_fetch(1295 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1956 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1957 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1958 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1959 */
} /* line 1959 */
  sim_icache_fetch(1300 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1961 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1962 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1963 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1964 */
  sim_icache_fetch(1304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1966 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1967 */
  sim_icache_fetch(1306 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1969 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1970 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1971 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1972 */
} /* line 1972 */
  sim_icache_fetch(1311 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1974 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1975 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1976 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1977 */
  sim_icache_fetch(1315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1979 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1980 */
  sim_icache_fetch(1317 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1982 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1983 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1984 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1985 */
} /* line 1985 */
  sim_icache_fetch(1322 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1987 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1988 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1989 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1990 */
  sim_icache_fetch(1326 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1992 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1993 */
  sim_icache_fetch(1328 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1995 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1996 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1997 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1998 */
} /* line 1998 */
  sim_icache_fetch(1333 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2000 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2001 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 2002 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2003 */
  sim_icache_fetch(1337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 2005 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2006 */
  sim_icache_fetch(1339 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2008 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2009 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2010 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 2011 */
} /* line 2011 */
  sim_icache_fetch(1344 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2013 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 2014 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 2015 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2016 */
  sim_icache_fetch(1348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 2018 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2019 */
  sim_icache_fetch(1350 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2021 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2022 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 2023 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 2024 */
} /* line 2024 */
  sim_icache_fetch(1355 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2026 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2027 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 2028 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2029 */
  sim_icache_fetch(1359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 2031 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2032 */
  sim_icache_fetch(1361 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2034 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2035 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 2036 */
} /* line 2036 */
  sim_icache_fetch(1365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2038 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2039 */
  sim_icache_fetch(1367 + t_thisfile.offset, 1);
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
} /* line 2041 */
  sim_icache_fetch(1368 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2043 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2044 */
} /* line 2044 */
  sim_icache_fetch(1370 + t_thisfile.offset, 1);
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
} /* line 2046 */
  sim_icache_fetch(1371 + t_thisfile.offset, 1);
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
} /* line 2049 */
  sim_icache_fetch(1372 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L92X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L92X3;
} /* line 2051 */
l_L156X3: ;/* line 2054 */
__LABEL(l_L156X3);
  sim_icache_fetch(1373 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2055 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2056 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2057 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2058 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2059 */
l_L155X3: ;/* line 2063 */
__LABEL(l_L155X3);
  sim_icache_fetch(1378 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2064 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2065 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2066 */
l_L154X3: ;/* line 2069 */
__LABEL(l_L154X3);
  sim_icache_fetch(1381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2070 */
} /* line 2070 */
l_L122X3: ;/* line 2073 */
__LABEL(l_L122X3);
  sim_icache_fetch(1382 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2074 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2075 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2076 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2077 */
} /* line 2077 */
  sim_icache_fetch(1386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2079 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2080 */
l_L153X3: ;/* line 2083 */
__LABEL(l_L153X3);
  sim_icache_fetch(1388 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2084 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2085 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2086 */
l_L152X3: ;/* line 2089 */
__LABEL(l_L152X3);
  sim_icache_fetch(1391 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2090 */
} /* line 2090 */
l_L120X3: ;/* line 2093 */
__LABEL(l_L120X3);
  sim_icache_fetch(1392 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2094 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2095 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2096 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2097 */
} /* line 2097 */
  sim_icache_fetch(1396 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2099 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2100 */
l_L151X3: ;/* line 2103 */
__LABEL(l_L151X3);
  sim_icache_fetch(1398 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2104 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2105 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2106 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2107 */
l_L150X3: ;/* line 2110 */
__LABEL(l_L150X3);
  sim_icache_fetch(1402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2111 */
} /* line 2111 */
l_L118X3: ;/* line 2114 */
__LABEL(l_L118X3);
  sim_icache_fetch(1403 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2115 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2116 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2117 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2118 */
} /* line 2118 */
  sim_icache_fetch(1407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2120 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2121 */
l_L149X3: ;/* line 2124 */
__LABEL(l_L149X3);
  sim_icache_fetch(1409 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2125 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2126 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2127 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2128 */
l_L148X3: ;/* line 2131 */
__LABEL(l_L148X3);
  sim_icache_fetch(1413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2132 */
} /* line 2132 */
l_L116X3: ;/* line 2135 */
__LABEL(l_L116X3);
  sim_icache_fetch(1414 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2136 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2137 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2138 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2139 */
} /* line 2139 */
  sim_icache_fetch(1418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2141 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2142 */
l_L147X3: ;/* line 2145 */
__LABEL(l_L147X3);
  sim_icache_fetch(1420 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2146 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2147 */
   __GOTO(l_L159X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L159X3;
} /* line 2148 */
l_L146X3: ;/* line 2151 */
__LABEL(l_L146X3);
  sim_icache_fetch(1423 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2152 */
} /* line 2152 */
l_L114X3: ;/* line 2155 */
__LABEL(l_L114X3);
  sim_icache_fetch(1424 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2156 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2157 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2158 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2159 */
} /* line 2159 */
  sim_icache_fetch(1428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2161 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2162 */
l_L145X3: ;/* line 2165 */
__LABEL(l_L145X3);
  sim_icache_fetch(1430 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2166 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2167 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2168 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2169 */
l_L144X3: ;/* line 2172 */
__LABEL(l_L144X3);
  sim_icache_fetch(1434 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2173 */
} /* line 2173 */
l_L112X3: ;/* line 2176 */
__LABEL(l_L112X3);
  sim_icache_fetch(1435 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2177 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2178 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2179 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2180 */
} /* line 2180 */
  sim_icache_fetch(1439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2182 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2183 */
l_L143X3: ;/* line 2186 */
__LABEL(l_L143X3);
  sim_icache_fetch(1441 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2187 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2188 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2189 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2190 */
l_L142X3: ;/* line 2193 */
__LABEL(l_L142X3);
  sim_icache_fetch(1445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2194 */
} /* line 2194 */
l_L110X3: ;/* line 2197 */
__LABEL(l_L110X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2198 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2199 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2200 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2201 */
} /* line 2201 */
  sim_icache_fetch(1450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2203 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2204 */
l_L141X3: ;/* line 2207 */
__LABEL(l_L141X3);
  sim_icache_fetch(1452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2208 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2209 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2210 */
l_L140X3: ;/* line 2213 */
__LABEL(l_L140X3);
  sim_icache_fetch(1455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2214 */
} /* line 2214 */
l_L108X3: ;/* line 2217 */
__LABEL(l_L108X3);
  sim_icache_fetch(1456 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2218 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2219 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2220 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2221 */
} /* line 2221 */
  sim_icache_fetch(1460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2223 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2224 */
l_L139X3: ;/* line 2227 */
__LABEL(l_L139X3);
  sim_icache_fetch(1462 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2228 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2229 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2230 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2231 */
l_L138X3: ;/* line 2234 */
__LABEL(l_L138X3);
  sim_icache_fetch(1466 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2235 */
} /* line 2235 */
l_L106X3: ;/* line 2238 */
__LABEL(l_L106X3);
  sim_icache_fetch(1467 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2239 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2240 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2241 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2242 */
} /* line 2242 */
  sim_icache_fetch(1471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2244 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2245 */
l_L137X3: ;/* line 2248 */
__LABEL(l_L137X3);
  sim_icache_fetch(1473 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2249 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2250 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2251 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2252 */
l_L136X3: ;/* line 2255 */
__LABEL(l_L136X3);
  sim_icache_fetch(1477 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2256 */
} /* line 2256 */
l_L104X3: ;/* line 2259 */
__LABEL(l_L104X3);
  sim_icache_fetch(1478 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2260 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2261 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2262 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2263 */
} /* line 2263 */
  sim_icache_fetch(1482 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2265 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2266 */
l_L135X3: ;/* line 2269 */
__LABEL(l_L135X3);
  sim_icache_fetch(1484 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2270 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2271 */
   __GOTO(l_L161X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L161X3;
} /* line 2272 */
l_L134X3: ;/* line 2275 */
__LABEL(l_L134X3);
  sim_icache_fetch(1487 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2276 */
} /* line 2276 */
l_L102X3: ;/* line 2279 */
__LABEL(l_L102X3);
  sim_icache_fetch(1488 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2280 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2281 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2282 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2283 */
} /* line 2283 */
  sim_icache_fetch(1492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2285 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2286 */
l_L133X3: ;/* line 2289 */
__LABEL(l_L133X3);
  sim_icache_fetch(1494 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2290 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2291 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2292 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2293 */
l_L132X3: ;/* line 2296 */
__LABEL(l_L132X3);
  sim_icache_fetch(1498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2297 */
} /* line 2297 */
l_L100X3: ;/* line 2300 */
__LABEL(l_L100X3);
  sim_icache_fetch(1499 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2301 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2302 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2303 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2304 */
} /* line 2304 */
  sim_icache_fetch(1503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2306 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2307 */
l_L131X3: ;/* line 2310 */
__LABEL(l_L131X3);
  sim_icache_fetch(1505 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2311 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2312 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2313 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2314 */
l_L130X3: ;/* line 2317 */
__LABEL(l_L130X3);
  sim_icache_fetch(1509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2318 */
} /* line 2318 */
l_L98X3: ;/* line 2321 */
__LABEL(l_L98X3);
  sim_icache_fetch(1510 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2322 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2323 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2324 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2325 */
} /* line 2325 */
  sim_icache_fetch(1514 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2327 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2328 */
l_L129X3: ;/* line 2331 */
__LABEL(l_L129X3);
  sim_icache_fetch(1516 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2332 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2333 */
   __GOTO(l_L162X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L162X3;
} /* line 2334 */
l_L128X3: ;/* line 2337 */
__LABEL(l_L128X3);
  sim_icache_fetch(1519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2338 */
} /* line 2338 */
l_L96X3: ;/* line 2341 */
__LABEL(l_L96X3);
  sim_icache_fetch(1520 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2342 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2343 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2344 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2345 */
} /* line 2345 */
  sim_icache_fetch(1524 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2347 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2348 */
l_L127X3: ;/* line 2351 */
__LABEL(l_L127X3);
  sim_icache_fetch(1526 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2352 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2353 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2354 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2355 */
l_L126X3: ;/* line 2358 */
__LABEL(l_L126X3);
  sim_icache_fetch(1530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2359 */
} /* line 2359 */
l_L94X3: ;/* line 2363 */
__LABEL(l_L94X3);
  sim_icache_fetch(1531 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2364 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2365 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2366 */
} /* line 2366 */
  sim_icache_fetch(1534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2368 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2369 */
l_L125X3: ;/* line 2372 */
__LABEL(l_L125X3);
  sim_icache_fetch(1536 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2373 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2374 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2375 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2376 */
l_L124X3: ;/* line 2379 */
__LABEL(l_L124X3);
  sim_icache_fetch(1540 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2380 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2381 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2382 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2383 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2384 */
l_L123X3: ;/* line 2388 */
__LABEL(l_L123X3);
  sim_icache_fetch(1545 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2389 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2390 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2391 */
l_L121X3: ;/* line 2394 */
__LABEL(l_L121X3);
  sim_icache_fetch(1548 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2395 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2396 */
} /* line 2396 */
l_L158X3: ;/* line 2398 */
__LABEL(l_L158X3);
  sim_icache_fetch(1550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2399 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2400 */
l_L119X3: ;/* line 2403 */
__LABEL(l_L119X3);
  sim_icache_fetch(1552 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2404 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2405 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2406 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2407 */
l_L117X3: ;/* line 2410 */
__LABEL(l_L117X3);
  sim_icache_fetch(1556 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2411 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2412 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2413 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2414 */
l_L115X3: ;/* line 2417 */
__LABEL(l_L115X3);
  sim_icache_fetch(1560 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2418 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2419 */
} /* line 2419 */
l_L159X3: ;/* line 2421 */
__LABEL(l_L159X3);
  sim_icache_fetch(1562 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2422 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2423 */
l_L113X3: ;/* line 2426 */
__LABEL(l_L113X3);
  sim_icache_fetch(1564 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2427 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2428 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2429 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2430 */
l_L111X3: ;/* line 2433 */
__LABEL(l_L111X3);
  sim_icache_fetch(1568 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2434 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2435 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2436 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2437 */
l_L109X3: ;/* line 2440 */
__LABEL(l_L109X3);
  sim_icache_fetch(1572 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2441 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2442 */
} /* line 2442 */
l_L160X3: ;/* line 2444 */
__LABEL(l_L160X3);
  sim_icache_fetch(1574 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2445 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2446 */
l_L107X3: ;/* line 2449 */
__LABEL(l_L107X3);
  sim_icache_fetch(1576 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2450 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2451 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2452 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2453 */
l_L105X3: ;/* line 2456 */
__LABEL(l_L105X3);
  sim_icache_fetch(1580 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2457 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2458 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2459 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2460 */
l_L103X3: ;/* line 2463 */
__LABEL(l_L103X3);
  sim_icache_fetch(1584 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2464 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2465 */
} /* line 2465 */
l_L161X3: ;/* line 2467 */
__LABEL(l_L161X3);
  sim_icache_fetch(1586 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2468 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2469 */
l_L101X3: ;/* line 2472 */
__LABEL(l_L101X3);
  sim_icache_fetch(1588 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2473 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2474 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2475 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2476 */
l_L99X3: ;/* line 2479 */
__LABEL(l_L99X3);
  sim_icache_fetch(1592 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2480 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2481 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2482 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2483 */
l_L97X3: ;/* line 2486 */
__LABEL(l_L97X3);
  sim_icache_fetch(1596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2487 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2488 */
} /* line 2488 */
l_L162X3: ;/* line 2490 */
__LABEL(l_L162X3);
  sim_icache_fetch(1598 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2491 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2492 */
l_L95X3: ;/* line 2495 */
__LABEL(l_L95X3);
  sim_icache_fetch(1600 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2496 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2497 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2498 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2499 */
l_L93X3: ;/* line 2503 */
__LABEL(l_L93X3);
  sim_icache_fetch(1604 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2504 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2505 */
} /* line 2505 */
l_L157X3: ;/* line 2507 */
__LABEL(l_L157X3);
  sim_icache_fetch(1606 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2508 */
} /* line 2508 */
  sim_icache_fetch(1608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2510 */
} /* line 2510 */
  sim_icache_fetch(1609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2512 */
l_L86X3: ;/* line 2515 */
__LABEL(l_L86X3);
		 /* line 2515 */
  sim_icache_fetch(1610 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2518 */
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
} /* line 2518 */
l_lr_200: ;/* line 2518 */
__LABEL(l_lr_200);
  sim_icache_fetch(1613 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2520 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2521 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2522 */
   __ADD_CYCLES(1);
} /* line 2522 */
  sim_icache_fetch(1617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2524 */
} /* line 2524 */
		 /* line 2525 */
  sim_icache_fetch(1618 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2527 */
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
} /* line 2528 */
l_lr_202: ;/* line 2528 */
__LABEL(l_lr_202);
  sim_icache_fetch(1622 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2530 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2531 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2532 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2533 */
   __MOV(reg_r0_3, 0); /* line 2534 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2535 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2536 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2537 */
   __ADD_CYCLES(1);
} /* line 2537 */
  sim_icache_fetch(1634 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2539 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2540 */
} /* line 2540 */
  sim_icache_fetch(1636 + t_thisfile.offset, 1);
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
} /* line 2542 */
l_L164X3: ;/* line 2544 */
__LABEL(l_L164X3);
  sim_icache_fetch(1637 + t_thisfile.offset, 1);
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
} /* line 2545 */
  sim_icache_fetch(1638 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2547 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2548 */
} /* line 2548 */
l_L166X3: ;/* line 2550 */
__LABEL(l_L166X3);
  sim_icache_fetch(1641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2552 */
l_L165X3: ;/* line 2555 */
__LABEL(l_L165X3);
  sim_icache_fetch(1642 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2556 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2557 */
   __GOTO(l_L166X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L166X3;
} /* line 2558 */
l_L163X3: ;/* line 2561 */
__LABEL(l_L163X3);
  sim_icache_fetch(1645 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2562 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2563 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2564 */
   __ADD_CYCLES(1);
} /* line 2564 */
		 /* line 2565 */
  sim_icache_fetch(1650 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2567 */
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
} /* line 2568 */
l_lr_208: ;/* line 2568 */
__LABEL(l_lr_208);
  sim_icache_fetch(1653 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2570 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2571 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2572 */
   __MOV(reg_r0_3, 0); /* line 2573 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2574 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2575 */
   __ADD_CYCLES(1);
} /* line 2575 */
  sim_icache_fetch(1661 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2577 */
   __GOTO(l_L164X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L164X3;
} /* line 2578 */
l_L84X3: ;/* line 2581 */
__LABEL(l_L84X3);
  sim_icache_fetch(1663 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2582 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2583 */
l_L80X3: ;/* line 2586 */
__LABEL(l_L80X3);
  sim_icache_fetch(1665 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2587 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2588 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2589 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2590 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2591 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2592 */
l_L79X3: ;/* line 2595 */
__LABEL(l_L79X3);
  sim_icache_fetch(1672 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2596 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2597 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2598 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2599 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2600 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2601 */
l_L78X3: ;/* line 2604 */
__LABEL(l_L78X3);
  sim_icache_fetch(1679 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2605 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2606 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2607 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2608 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2609 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2610 */
l_L77X3: ;/* line 2613 */
__LABEL(l_L77X3);
  sim_icache_fetch(1686 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2614 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2615 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2616 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2617 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2618 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2619 */
l_L76X3: ;/* line 2622 */
__LABEL(l_L76X3);
  sim_icache_fetch(1693 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2623 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2624 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2625 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2626 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2627 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2628 */
l_L75X3: ;/* line 2631 */
__LABEL(l_L75X3);
  sim_icache_fetch(1700 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2632 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2633 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2634 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2635 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2636 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2637 */
l_L74X3: ;/* line 2640 */
__LABEL(l_L74X3);
  sim_icache_fetch(1707 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2641 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2642 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2643 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2644 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2645 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2646 */
l_L73X3: ;/* line 2649 */
__LABEL(l_L73X3);
  sim_icache_fetch(1714 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2650 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2651 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2652 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2653 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2654 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2655 */
l_L72X3: ;/* line 2658 */
__LABEL(l_L72X3);
  sim_icache_fetch(1721 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2659 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2660 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2661 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2662 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2663 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2664 */
l_L71X3: ;/* line 2667 */
__LABEL(l_L71X3);
  sim_icache_fetch(1728 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2668 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2669 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2670 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2671 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2672 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2673 */
l_L70X3: ;/* line 2676 */
__LABEL(l_L70X3);
  sim_icache_fetch(1735 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2677 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2678 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2679 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2680 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2681 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2682 */
l_L69X3: ;/* line 2685 */
__LABEL(l_L69X3);
  sim_icache_fetch(1742 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2686 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2687 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2688 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2689 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2690 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2691 */
l_L68X3: ;/* line 2694 */
__LABEL(l_L68X3);
  sim_icache_fetch(1749 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2695 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2696 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2697 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2698 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2699 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2700 */
l_L67X3: ;/* line 2703 */
__LABEL(l_L67X3);
  sim_icache_fetch(1756 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2704 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2705 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2706 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2707 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2708 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2709 */
l_L66X3: ;/* line 2713 */
__LABEL(l_L66X3);
  sim_icache_fetch(1763 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2714 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2715 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2716 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2717 */
} /* line 2717 */
l_L82X3: ;/* line 2719 */
__LABEL(l_L82X3);
  sim_icache_fetch(1768 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2720 */
} /* line 2720 */
		 /* line 2721 */
  sim_icache_fetch(1769 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2724 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2725 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2726 */
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
} /* line 2726 */
l_lr_227: ;/* line 2726 */
__LABEL(l_lr_227);
  sim_icache_fetch(1774 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2728 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2729 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2730 */
} /* line 2730 */
  sim_icache_fetch(1777 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2732 */
l_L63X3: ;/* line 2735 */
__LABEL(l_L63X3);
  sim_icache_fetch(1778 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2736 */
   __GOTO(l_L64X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L64X3;
} /* line 2737 */
l_L61X3: ;/* line 2740 */
__LABEL(l_L61X3);
  sim_icache_fetch(1780 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_16, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2741 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2742 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2743 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2744 */
   __MOV(reg_r0_17, (unsigned int) 257); /* line 2745 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2746 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2747 */
   __ADD_CYCLES(1);
} /* line 2747 */
  sim_icache_fetch(1790 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2749 */
} /* line 2749 */
  sim_icache_fetch(1791 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2751 */
} /* line 2751 */
  sim_icache_fetch(1793 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2753 */
} /* line 2753 */
  sim_icache_fetch(1794 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2755 */
   __LDBU(reg_r0_16, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2756 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2757 */
   __ADD_CYCLES(1);
} /* line 2757 */
  sim_icache_fetch(1799 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2759 */
} /* line 2759 */
  sim_icache_fetch(1800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2761 */
} /* line 2761 */
  sim_icache_fetch(1802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2763 */
} /* line 2763 */
  sim_icache_fetch(1803 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2765 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2766 */
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2767 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2768 */
   __ADD_CYCLES(1);
} /* line 2768 */
  sim_icache_fetch(1810 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_11, (unsigned int) 1); /* line 2770 */
   __OR(reg_r0_16, reg_r0_16, reg_r0_18); /* line 2771 */
} /* line 2771 */
  sim_icache_fetch(1812 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_19); /* line 2773 */
} /* line 2773 */
  sim_icache_fetch(1814 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2775 */
} /* line 2775 */
  sim_icache_fetch(1815 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2777 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2778 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2779 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2780 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2781 */
   __ADD_CYCLES(1);
} /* line 2781 */
  sim_icache_fetch(1824 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 2783 */
   __ADD(reg_r0_13, reg_r0_16, (unsigned int) -1); /* line 2784 */
   __ADD(reg_r0_15, reg_r0_14, (unsigned int) 1); /* line 2785 */
} /* line 2785 */
  sim_icache_fetch(1827 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_17, (unsigned int) 256); /* line 2787 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 2788 */
   __GOTO(l_L62X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L62X3;
} /* line 2789 */
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

  sim_icache_fetch(1831 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 2808 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2809 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2810 */
} /* line 2810 */
  sim_icache_fetch(1836 + t_thisfile.offset, 1);
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
} /* line 2812 */
  sim_icache_fetch(1837 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2814 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2815 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2816 */
} /* line 2816 */
  sim_icache_fetch(1840 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_15983Xbuf); /* line 2818 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_15983Xbuf),0,1)); /* line 2819 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_15983Xbuf + (unsigned int) 1)); /* line 2820 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2821 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2822 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2823 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2824 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2825 */
} /* line 2825 */
  sim_icache_fetch(1853 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2827 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2828 */
} /* line 2828 */
  sim_icache_fetch(1855 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2830 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2831 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2832 */
} /* line 2832 */
  sim_icache_fetch(1858 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2834 */
} /* line 2834 */
  sim_icache_fetch(1859 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_15983Xbuf),0,1), reg_r0_2); /* line 2836 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2837 */
  sim_icache_fetch(1862 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2839 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2840 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2841 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2842 */
} /* line 2842 */
l_L168X3: ;/* line 2844 */
__LABEL(l_L168X3);
  sim_icache_fetch(1866 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2845 */
   __MOV(reg_r0_3, (unsigned int) compress_15983Xbuf); /* line 2846 */
} /* line 2846 */
  sim_icache_fetch(1869 + t_thisfile.offset, 1);
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
} /* line 2848 */
  sim_icache_fetch(1870 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2850 */
} /* line 2850 */
l_L169X3: ;/* line 2852 */
__LABEL(l_L169X3);
  sim_icache_fetch(1871 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 2853 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2854 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2855 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2856 */
   __ADD_CYCLES(1);
} /* line 2856 */
  sim_icache_fetch(1878 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2858 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2859 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2860 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2861 */
} /* line 2861 */
  sim_icache_fetch(1882 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_15983Xoffset,0,4), reg_r0_2); /* line 2863 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2864 */
} /* line 2864 */
  sim_icache_fetch(1885 + t_thisfile.offset, 1);
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
} /* line 2866 */
  sim_icache_fetch(1886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2868 */
} /* line 2868 */
l_L171X3: ;/* line 2871 */
__LABEL(l_L171X3);
  sim_icache_fetch(1888 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2872 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2873 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2874 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2875 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2876 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2877 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2878 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2879 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2880 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2881 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -16); /* line 2882 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 16); /* line 2883 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2884 */
   __ADD_CYCLES(1);
} /* line 2884 */
  sim_icache_fetch(1902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2886 */
} /* line 2886 */
  sim_icache_fetch(1903 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2888 */
} /* line 2888 */
  sim_icache_fetch(1905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2890 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2891 */
  sim_icache_fetch(1907 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2893 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2894 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2895 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2896 */
   __ADD_CYCLES(1);
} /* line 2896 */
  sim_icache_fetch(1912 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2898 */
} /* line 2898 */
  sim_icache_fetch(1913 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2900 */
} /* line 2900 */
  sim_icache_fetch(1915 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2902 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2903 */
  sim_icache_fetch(1917 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2905 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2906 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2907 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2908 */
   __ADD_CYCLES(1);
} /* line 2908 */
  sim_icache_fetch(1922 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2910 */
} /* line 2910 */
  sim_icache_fetch(1923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2912 */
} /* line 2912 */
  sim_icache_fetch(1925 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2914 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2915 */
  sim_icache_fetch(1927 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2917 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2918 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2919 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2920 */
   __ADD_CYCLES(1);
} /* line 2920 */
  sim_icache_fetch(1932 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2922 */
} /* line 2922 */
  sim_icache_fetch(1933 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2924 */
} /* line 2924 */
  sim_icache_fetch(1935 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2926 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2927 */
  sim_icache_fetch(1937 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2929 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2930 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2931 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2932 */
   __ADD_CYCLES(1);
} /* line 2932 */
  sim_icache_fetch(1942 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2934 */
} /* line 2934 */
  sim_icache_fetch(1943 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2936 */
} /* line 2936 */
  sim_icache_fetch(1945 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2938 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2939 */
  sim_icache_fetch(1947 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2941 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2942 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2943 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2944 */
   __ADD_CYCLES(1);
} /* line 2944 */
  sim_icache_fetch(1952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2946 */
} /* line 2946 */
  sim_icache_fetch(1953 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2948 */
} /* line 2948 */
  sim_icache_fetch(1955 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2950 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2951 */
  sim_icache_fetch(1957 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2953 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2954 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2955 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2956 */
   __ADD_CYCLES(1);
} /* line 2956 */
  sim_icache_fetch(1962 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2958 */
} /* line 2958 */
  sim_icache_fetch(1963 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2960 */
} /* line 2960 */
  sim_icache_fetch(1965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2962 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2963 */
  sim_icache_fetch(1967 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2965 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2966 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2967 */
   __ADD(reg_r0_5, reg_r0_7, (unsigned int) -16); /* line 2968 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2969 */
   __ADD_CYCLES(1);
} /* line 2969 */
  sim_icache_fetch(1973 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2971 */
} /* line 2971 */
  sim_icache_fetch(1974 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2973 */
} /* line 2973 */
  sim_icache_fetch(1976 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2975 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2976 */
  sim_icache_fetch(1978 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2978 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2979 */
   __CMPEQ(reg_b0_7, reg_r0_7, 0); /* line 2980 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2981 */
   __ADD_CYCLES(1);
} /* line 2981 */
  sim_icache_fetch(1983 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2983 */
} /* line 2983 */
  sim_icache_fetch(1984 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2985 */
} /* line 2985 */
  sim_icache_fetch(1986 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2987 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2988 */
  sim_icache_fetch(1988 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2990 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2991 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2992 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2993 */
   __ADD_CYCLES(1);
} /* line 2993 */
  sim_icache_fetch(1993 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2995 */
} /* line 2995 */
  sim_icache_fetch(1994 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2997 */
} /* line 2997 */
  sim_icache_fetch(1996 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2999 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3000 */
  sim_icache_fetch(1998 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 3002 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3003 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 3004 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3005 */
   __ADD_CYCLES(1);
} /* line 3005 */
  sim_icache_fetch(2003 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3007 */
} /* line 3007 */
  sim_icache_fetch(2004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3009 */
} /* line 3009 */
  sim_icache_fetch(2006 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3011 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3012 */
  sim_icache_fetch(2008 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 3014 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3015 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 3016 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3017 */
   __ADD_CYCLES(1);
} /* line 3017 */
  sim_icache_fetch(2013 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3019 */
} /* line 3019 */
  sim_icache_fetch(2014 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3021 */
} /* line 3021 */
  sim_icache_fetch(2016 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3023 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3024 */
  sim_icache_fetch(2018 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 3026 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3027 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 4); /* line 3028 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3029 */
   __ADD_CYCLES(1);
} /* line 3029 */
  sim_icache_fetch(2023 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3031 */
} /* line 3031 */
  sim_icache_fetch(2024 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3033 */
} /* line 3033 */
  sim_icache_fetch(2026 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3035 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3036 */
  sim_icache_fetch(2028 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 3038 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3039 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 5); /* line 3040 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3041 */
   __ADD_CYCLES(1);
} /* line 3041 */
  sim_icache_fetch(2033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3043 */
} /* line 3043 */
  sim_icache_fetch(2034 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3045 */
} /* line 3045 */
  sim_icache_fetch(2036 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3047 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3048 */
  sim_icache_fetch(2038 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 3050 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3051 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 6); /* line 3052 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3053 */
   __ADD_CYCLES(1);
} /* line 3053 */
  sim_icache_fetch(2043 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3055 */
} /* line 3055 */
  sim_icache_fetch(2044 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3057 */
} /* line 3057 */
  sim_icache_fetch(2046 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3059 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3060 */
  sim_icache_fetch(2048 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 3062 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3063 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 7); /* line 3064 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3065 */
   __ADD_CYCLES(1);
} /* line 3065 */
  sim_icache_fetch(2053 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3067 */
} /* line 3067 */
  sim_icache_fetch(2054 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3069 */
} /* line 3069 */
  sim_icache_fetch(2056 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3071 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3072 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3073 */
  sim_icache_fetch(2059 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 3075 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3076 */
   __CMPEQ(reg_b0_7, reg_r0_7, (unsigned int) 8); /* line 3077 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) 16); /* line 3078 */
   __MFB(reg_r0_8, t__i32_0); /* line 3079 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3080 */
   __ADD_CYCLES(1);
} /* line 3080 */
  sim_icache_fetch(2066 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3082 */
} /* line 3082 */
  sim_icache_fetch(2067 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3084 */
} /* line 3084 */
  sim_icache_fetch(2069 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3086 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3087 */
  sim_icache_fetch(2071 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 3089 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3090 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 9); /* line 3091 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3092 */
   __ADD_CYCLES(1);
} /* line 3092 */
  sim_icache_fetch(2076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3094 */
} /* line 3094 */
  sim_icache_fetch(2077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3096 */
} /* line 3096 */
  sim_icache_fetch(2079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3098 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3099 */
  sim_icache_fetch(2081 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 2),0,1)); /* line 3101 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3102 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 10); /* line 3103 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3104 */
   __ADD_CYCLES(1);
} /* line 3104 */
  sim_icache_fetch(2086 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3106 */
} /* line 3106 */
  sim_icache_fetch(2087 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3108 */
} /* line 3108 */
  sim_icache_fetch(2089 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3110 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3111 */
  sim_icache_fetch(2091 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 3),0,1)); /* line 3113 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3114 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 11); /* line 3115 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3116 */
   __ADD_CYCLES(1);
} /* line 3116 */
  sim_icache_fetch(2096 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3118 */
} /* line 3118 */
  sim_icache_fetch(2097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3120 */
} /* line 3120 */
  sim_icache_fetch(2099 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3122 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3123 */
  sim_icache_fetch(2101 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 4),0,1)); /* line 3125 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3126 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 12); /* line 3127 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3128 */
   __ADD_CYCLES(1);
} /* line 3128 */
  sim_icache_fetch(2106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3130 */
} /* line 3130 */
  sim_icache_fetch(2107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3132 */
} /* line 3132 */
  sim_icache_fetch(2109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3134 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3135 */
  sim_icache_fetch(2111 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 5),0,1)); /* line 3137 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3138 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 13); /* line 3139 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3140 */
   __ADD_CYCLES(1);
} /* line 3140 */
  sim_icache_fetch(2116 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3142 */
} /* line 3142 */
  sim_icache_fetch(2117 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3144 */
} /* line 3144 */
  sim_icache_fetch(2119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3146 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3147 */
  sim_icache_fetch(2121 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 6),0,1)); /* line 3149 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3150 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 14); /* line 3151 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3152 */
   __ADD_CYCLES(1);
} /* line 3152 */
  sim_icache_fetch(2126 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3154 */
} /* line 3154 */
  sim_icache_fetch(2127 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3156 */
} /* line 3156 */
  sim_icache_fetch(2129 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3158 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3159 */
  sim_icache_fetch(2131 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 7),0,1)); /* line 3161 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3162 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 15); /* line 3163 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3164 */
   __ADD_CYCLES(1);
} /* line 3164 */
  sim_icache_fetch(2136 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3166 */
} /* line 3166 */
  sim_icache_fetch(2137 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3168 */
} /* line 3168 */
  sim_icache_fetch(2139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3170 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3171 */
  sim_icache_fetch(2141 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 8),0,1)); /* line 3173 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3174 */
   __MTB(reg_b0_7, reg_r0_8); /* line 3175 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3176 */
   __ADD_CYCLES(1);
} /* line 3176 */
  sim_icache_fetch(2146 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3178 */
} /* line 3178 */
  sim_icache_fetch(2147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3180 */
} /* line 3180 */
  sim_icache_fetch(2149 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3182 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3183 */
  sim_icache_fetch(2151 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 9),0,1)); /* line 3185 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3186 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3187 */
   __ADD_CYCLES(1);
} /* line 3187 */
  sim_icache_fetch(2155 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3189 */
} /* line 3189 */
  sim_icache_fetch(2156 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3191 */
} /* line 3191 */
  sim_icache_fetch(2158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3193 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3194 */
  sim_icache_fetch(2160 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 10),0,1)); /* line 3196 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3197 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3198 */
   __ADD_CYCLES(1);
} /* line 3198 */
  sim_icache_fetch(2164 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3200 */
} /* line 3200 */
  sim_icache_fetch(2165 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3202 */
} /* line 3202 */
  sim_icache_fetch(2167 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3204 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3205 */
  sim_icache_fetch(2169 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 11),0,1)); /* line 3207 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3208 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3209 */
   __ADD_CYCLES(1);
} /* line 3209 */
  sim_icache_fetch(2173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3211 */
} /* line 3211 */
  sim_icache_fetch(2174 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3213 */
} /* line 3213 */
  sim_icache_fetch(2176 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3215 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3216 */
  sim_icache_fetch(2178 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 12),0,1)); /* line 3218 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3219 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3220 */
   __ADD_CYCLES(1);
} /* line 3220 */
  sim_icache_fetch(2182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3222 */
} /* line 3222 */
  sim_icache_fetch(2183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3224 */
} /* line 3224 */
  sim_icache_fetch(2185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3226 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3227 */
  sim_icache_fetch(2187 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 13),0,1)); /* line 3229 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3230 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3231 */
   __ADD_CYCLES(1);
} /* line 3231 */
  sim_icache_fetch(2191 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3233 */
} /* line 3233 */
  sim_icache_fetch(2192 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3235 */
} /* line 3235 */
  sim_icache_fetch(2194 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3237 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3238 */
  sim_icache_fetch(2196 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 14),0,1)); /* line 3240 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3241 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3242 */
   __ADD_CYCLES(1);
} /* line 3242 */
  sim_icache_fetch(2200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3244 */
} /* line 3244 */
  sim_icache_fetch(2201 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3246 */
} /* line 3246 */
  sim_icache_fetch(2203 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3248 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3249 */
  sim_icache_fetch(2205 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 15),0,1)); /* line 3251 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3252 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3253 */
   __ADD_CYCLES(1);
} /* line 3253 */
  sim_icache_fetch(2209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3255 */
} /* line 3255 */
  sim_icache_fetch(2210 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3257 */
} /* line 3257 */
  sim_icache_fetch(2212 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 3259 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3261 */
  sim_icache_fetch(2214 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L171X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L171X3;
} /* line 3263 */
l_L172X3: ;/* line 3266 */
__LABEL(l_L172X3);
  sim_icache_fetch(2215 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_15983Xoffset,0,4), 0); /* line 3267 */
} /* line 3267 */
l_L170X3: ;/* line 3270 */
__LABEL(l_L170X3);
  sim_icache_fetch(2217 + t_thisfile.offset, 23);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3271 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3272 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3273 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 3274 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3275 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3276 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3277 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3278 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3279 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3280 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3281 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3282 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3283 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3284 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3285 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3286 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3287 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3288 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3289 */
} /* line 3289 */
  sim_icache_fetch(2240 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) compress_15983Xbuf); /* line 3291 */
   __MOV(reg_r0_3, 0); /* line 3292 */
} /* line 3292 */
  sim_icache_fetch(2243 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3294 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3295 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3296 */
} /* line 3296 */
  sim_icache_fetch(2246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3298 */
} /* line 3298 */
  sim_icache_fetch(2247 + t_thisfile.offset, 1);
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
} /* line 3300 */
  sim_icache_fetch(2248 + t_thisfile.offset, 1);
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
} /* line 3302 */
l_L175X3: ;/* line 3305 */
__LABEL(l_L175X3);
  sim_icache_fetch(2249 + t_thisfile.offset, 21);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3306 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3307 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3308 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3309 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3310 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3311 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3312 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3313 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3314 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3315 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3316 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3317 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3318 */
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3319 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3320 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3321 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3322 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3323 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3324 */
} /* line 3324 */
  sim_icache_fetch(2270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3326 */
} /* line 3326 */
  sim_icache_fetch(2271 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3328 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3329 */
   __ADD(reg_r0_3, reg_r0_38, (unsigned int) 16); /* line 3330 */
} /* line 3330 */
  sim_icache_fetch(2274 + t_thisfile.offset, 1);
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
} /* line 3332 */
  sim_icache_fetch(2275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3334 */
} /* line 3334 */
  sim_icache_fetch(2277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3336 */
} /* line 3336 */
  sim_icache_fetch(2278 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3338 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3339 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3340 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3341 */
   __ADD_CYCLES(1);
} /* line 3341 */
  sim_icache_fetch(2284 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 3343 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3344 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3345 */
} /* line 3345 */
  sim_icache_fetch(2287 + t_thisfile.offset, 1);
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
} /* line 3347 */
  sim_icache_fetch(2288 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3349 */
} /* line 3349 */
  sim_icache_fetch(2290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3351 */
} /* line 3351 */
  sim_icache_fetch(2291 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3353 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3354 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3355 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3356 */
   __ADD_CYCLES(1);
} /* line 3356 */
  sim_icache_fetch(2297 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 3358 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3359 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3360 */
} /* line 3360 */
  sim_icache_fetch(2300 + t_thisfile.offset, 1);
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
} /* line 3362 */
  sim_icache_fetch(2301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3364 */
} /* line 3364 */
  sim_icache_fetch(2303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3366 */
} /* line 3366 */
  sim_icache_fetch(2304 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3368 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3369 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3370 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3371 */
   __ADD_CYCLES(1);
} /* line 3371 */
  sim_icache_fetch(2310 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 3373 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3374 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3375 */
} /* line 3375 */
  sim_icache_fetch(2313 + t_thisfile.offset, 1);
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
} /* line 3377 */
  sim_icache_fetch(2314 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3379 */
} /* line 3379 */
  sim_icache_fetch(2316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3381 */
} /* line 3381 */
  sim_icache_fetch(2317 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3383 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3384 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3385 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3386 */
   __ADD_CYCLES(1);
} /* line 3386 */
  sim_icache_fetch(2323 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 3388 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3389 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3390 */
} /* line 3390 */
  sim_icache_fetch(2326 + t_thisfile.offset, 1);
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
} /* line 3392 */
  sim_icache_fetch(2327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3394 */
} /* line 3394 */
  sim_icache_fetch(2329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3396 */
} /* line 3396 */
  sim_icache_fetch(2330 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3398 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3399 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3400 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3401 */
   __ADD_CYCLES(1);
} /* line 3401 */
  sim_icache_fetch(2336 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 3403 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3404 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3405 */
} /* line 3405 */
  sim_icache_fetch(2339 + t_thisfile.offset, 1);
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
} /* line 3407 */
  sim_icache_fetch(2340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3409 */
} /* line 3409 */
  sim_icache_fetch(2342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3411 */
} /* line 3411 */
  sim_icache_fetch(2343 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3413 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3414 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3415 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3416 */
   __ADD_CYCLES(1);
} /* line 3416 */
  sim_icache_fetch(2349 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 3418 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3419 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3420 */
} /* line 3420 */
  sim_icache_fetch(2352 + t_thisfile.offset, 1);
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
} /* line 3422 */
  sim_icache_fetch(2353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3424 */
} /* line 3424 */
  sim_icache_fetch(2355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3426 */
} /* line 3426 */
  sim_icache_fetch(2356 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3428 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3429 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3430 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3431 */
   __ADD_CYCLES(1);
} /* line 3431 */
  sim_icache_fetch(2362 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 3433 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3434 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3435 */
} /* line 3435 */
  sim_icache_fetch(2365 + t_thisfile.offset, 1);
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
} /* line 3437 */
  sim_icache_fetch(2366 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3439 */
} /* line 3439 */
  sim_icache_fetch(2368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3441 */
} /* line 3441 */
  sim_icache_fetch(2369 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3443 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3444 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3445 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3446 */
   __ADD_CYCLES(1);
} /* line 3446 */
  sim_icache_fetch(2375 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 3448 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3449 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3450 */
} /* line 3450 */
  sim_icache_fetch(2378 + t_thisfile.offset, 1);
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
} /* line 3452 */
  sim_icache_fetch(2379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3454 */
} /* line 3454 */
  sim_icache_fetch(2381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3456 */
} /* line 3456 */
  sim_icache_fetch(2382 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3458 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3459 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3460 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3461 */
   __ADD_CYCLES(1);
} /* line 3461 */
  sim_icache_fetch(2388 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 3463 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3464 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3465 */
} /* line 3465 */
  sim_icache_fetch(2391 + t_thisfile.offset, 1);
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
} /* line 3467 */
  sim_icache_fetch(2392 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3469 */
} /* line 3469 */
  sim_icache_fetch(2394 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3471 */
} /* line 3471 */
  sim_icache_fetch(2395 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3473 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3474 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3475 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3476 */
   __ADD_CYCLES(1);
} /* line 3476 */
  sim_icache_fetch(2401 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 3478 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3479 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3480 */
} /* line 3480 */
  sim_icache_fetch(2404 + t_thisfile.offset, 1);
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
} /* line 3482 */
  sim_icache_fetch(2405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3484 */
} /* line 3484 */
  sim_icache_fetch(2407 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3486 */
} /* line 3486 */
  sim_icache_fetch(2408 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3488 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3489 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3490 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3491 */
   __ADD_CYCLES(1);
} /* line 3491 */
  sim_icache_fetch(2414 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 3493 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3494 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3495 */
} /* line 3495 */
  sim_icache_fetch(2417 + t_thisfile.offset, 1);
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
} /* line 3497 */
  sim_icache_fetch(2418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3499 */
} /* line 3499 */
  sim_icache_fetch(2420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3501 */
} /* line 3501 */
  sim_icache_fetch(2421 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3503 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3504 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3505 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3506 */
   __ADD_CYCLES(1);
} /* line 3506 */
  sim_icache_fetch(2427 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 3508 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3509 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3510 */
} /* line 3510 */
  sim_icache_fetch(2430 + t_thisfile.offset, 1);
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
} /* line 3512 */
  sim_icache_fetch(2431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3514 */
} /* line 3514 */
  sim_icache_fetch(2433 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3516 */
} /* line 3516 */
  sim_icache_fetch(2434 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3518 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3519 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3520 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3521 */
   __ADD_CYCLES(1);
} /* line 3521 */
  sim_icache_fetch(2440 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 3523 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3524 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3525 */
} /* line 3525 */
  sim_icache_fetch(2443 + t_thisfile.offset, 1);
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
} /* line 3527 */
  sim_icache_fetch(2444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3529 */
} /* line 3529 */
  sim_icache_fetch(2446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3531 */
} /* line 3531 */
  sim_icache_fetch(2447 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3533 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3534 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3535 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3536 */
   __ADD_CYCLES(1);
} /* line 3536 */
  sim_icache_fetch(2453 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_2); /* line 3538 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3539 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3540 */
} /* line 3540 */
  sim_icache_fetch(2456 + t_thisfile.offset, 1);
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
} /* line 3542 */
  sim_icache_fetch(2457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3544 */
} /* line 3544 */
  sim_icache_fetch(2459 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3546 */
} /* line 3546 */
  sim_icache_fetch(2460 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3548 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3549 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3550 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3551 */
   __ADD_CYCLES(1);
} /* line 3551 */
  sim_icache_fetch(2466 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_2); /* line 3553 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3554 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3555 */
} /* line 3555 */
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
} /* line 3557 */
  sim_icache_fetch(2470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3559 */
} /* line 3559 */
  sim_icache_fetch(2472 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_5); /* line 3561 */
} /* line 3561 */
  sim_icache_fetch(2473 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3563 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_37,0,1)); /* line 3564 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3565 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3566 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3567 */
   __ADD_CYCLES(1);
} /* line 3567 */
  sim_icache_fetch(2480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_38, reg_r0_2); /* line 3569 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3570 */
} /* line 3570 */
  sim_icache_fetch(2482 + t_thisfile.offset, 1);
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
} /* line 3572 */
  sim_icache_fetch(2483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3574 */
} /* line 3574 */
  sim_icache_fetch(2485 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3576 */
} /* line 3576 */
  sim_icache_fetch(2486 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3578 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3579 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3580 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3581 */
   __ADD_CYCLES(1);
} /* line 3581 */
  sim_icache_fetch(2492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3583 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3584 */
} /* line 3584 */
  sim_icache_fetch(2494 + t_thisfile.offset, 1);
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
} /* line 3586 */
  sim_icache_fetch(2495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3588 */
} /* line 3588 */
  sim_icache_fetch(2497 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3590 */
} /* line 3590 */
  sim_icache_fetch(2498 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3592 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3593 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3594 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3595 */
   __ADD_CYCLES(1);
} /* line 3595 */
  sim_icache_fetch(2504 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3597 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3598 */
} /* line 3598 */
  sim_icache_fetch(2506 + t_thisfile.offset, 1);
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
} /* line 3600 */
  sim_icache_fetch(2507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3602 */
} /* line 3602 */
  sim_icache_fetch(2509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3604 */
} /* line 3604 */
  sim_icache_fetch(2510 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3606 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3607 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3608 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3609 */
   __ADD_CYCLES(1);
} /* line 3609 */
  sim_icache_fetch(2516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3611 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3612 */
} /* line 3612 */
  sim_icache_fetch(2518 + t_thisfile.offset, 1);
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
} /* line 3614 */
  sim_icache_fetch(2519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3616 */
} /* line 3616 */
  sim_icache_fetch(2521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3618 */
} /* line 3618 */
  sim_icache_fetch(2522 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3620 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3621 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3622 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3623 */
   __ADD_CYCLES(1);
} /* line 3623 */
  sim_icache_fetch(2528 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3625 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3626 */
} /* line 3626 */
  sim_icache_fetch(2530 + t_thisfile.offset, 1);
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
} /* line 3628 */
  sim_icache_fetch(2531 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3630 */
} /* line 3630 */
  sim_icache_fetch(2533 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3632 */
} /* line 3632 */
  sim_icache_fetch(2534 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3634 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3635 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3636 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3637 */
   __ADD_CYCLES(1);
} /* line 3637 */
  sim_icache_fetch(2540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3639 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3640 */
} /* line 3640 */
  sim_icache_fetch(2542 + t_thisfile.offset, 1);
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
} /* line 3642 */
  sim_icache_fetch(2543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3644 */
} /* line 3644 */
  sim_icache_fetch(2545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3646 */
} /* line 3646 */
  sim_icache_fetch(2546 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3648 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3649 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3650 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3651 */
   __ADD_CYCLES(1);
} /* line 3651 */
  sim_icache_fetch(2552 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3653 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3654 */
} /* line 3654 */
  sim_icache_fetch(2554 + t_thisfile.offset, 1);
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
} /* line 3656 */
  sim_icache_fetch(2555 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3658 */
} /* line 3658 */
  sim_icache_fetch(2557 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3660 */
} /* line 3660 */
  sim_icache_fetch(2558 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3662 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3663 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3664 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3665 */
   __ADD_CYCLES(1);
} /* line 3665 */
  sim_icache_fetch(2564 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3667 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3668 */
} /* line 3668 */
  sim_icache_fetch(2566 + t_thisfile.offset, 1);
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
} /* line 3670 */
  sim_icache_fetch(2567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3672 */
} /* line 3672 */
  sim_icache_fetch(2569 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3674 */
} /* line 3674 */
  sim_icache_fetch(2570 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3676 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3677 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3678 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3679 */
   __ADD_CYCLES(1);
} /* line 3679 */
  sim_icache_fetch(2576 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3681 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3682 */
} /* line 3682 */
  sim_icache_fetch(2578 + t_thisfile.offset, 1);
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
} /* line 3684 */
  sim_icache_fetch(2579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3686 */
} /* line 3686 */
  sim_icache_fetch(2581 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3688 */
} /* line 3688 */
  sim_icache_fetch(2582 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3690 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3691 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3692 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3693 */
   __ADD_CYCLES(1);
} /* line 3693 */
  sim_icache_fetch(2588 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3695 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3696 */
} /* line 3696 */
  sim_icache_fetch(2590 + t_thisfile.offset, 1);
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
} /* line 3698 */
  sim_icache_fetch(2591 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3700 */
} /* line 3700 */
  sim_icache_fetch(2593 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3702 */
} /* line 3702 */
  sim_icache_fetch(2594 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3704 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3705 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3706 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3707 */
   __ADD_CYCLES(1);
} /* line 3707 */
  sim_icache_fetch(2600 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3709 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3710 */
} /* line 3710 */
  sim_icache_fetch(2602 + t_thisfile.offset, 1);
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
} /* line 3712 */
  sim_icache_fetch(2603 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3714 */
} /* line 3714 */
  sim_icache_fetch(2605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3716 */
} /* line 3716 */
  sim_icache_fetch(2606 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3718 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3719 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3720 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3721 */
   __ADD_CYCLES(1);
} /* line 3721 */
  sim_icache_fetch(2612 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3723 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3724 */
} /* line 3724 */
  sim_icache_fetch(2614 + t_thisfile.offset, 1);
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
} /* line 3726 */
  sim_icache_fetch(2615 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3728 */
} /* line 3728 */
  sim_icache_fetch(2617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3730 */
} /* line 3730 */
  sim_icache_fetch(2618 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3732 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3733 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3734 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3735 */
   __ADD_CYCLES(1);
} /* line 3735 */
  sim_icache_fetch(2624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3737 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3738 */
} /* line 3738 */
  sim_icache_fetch(2626 + t_thisfile.offset, 1);
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
} /* line 3740 */
  sim_icache_fetch(2627 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3742 */
} /* line 3742 */
  sim_icache_fetch(2629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3744 */
} /* line 3744 */
  sim_icache_fetch(2630 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3746 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3747 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3748 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3749 */
   __ADD_CYCLES(1);
} /* line 3749 */
  sim_icache_fetch(2636 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3751 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3752 */
} /* line 3752 */
  sim_icache_fetch(2638 + t_thisfile.offset, 1);
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
} /* line 3754 */
  sim_icache_fetch(2639 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3756 */
} /* line 3756 */
  sim_icache_fetch(2641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3758 */
} /* line 3758 */
  sim_icache_fetch(2642 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3760 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3761 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3762 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3763 */
   __ADD_CYCLES(1);
} /* line 3763 */
  sim_icache_fetch(2648 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3765 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3766 */
} /* line 3766 */
  sim_icache_fetch(2650 + t_thisfile.offset, 1);
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
} /* line 3768 */
  sim_icache_fetch(2651 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3770 */
} /* line 3770 */
  sim_icache_fetch(2653 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3772 */
} /* line 3772 */
  sim_icache_fetch(2654 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3774 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3775 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3776 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3777 */
   __ADD_CYCLES(1);
} /* line 3777 */
  sim_icache_fetch(2660 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3779 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3780 */
} /* line 3780 */
  sim_icache_fetch(2662 + t_thisfile.offset, 1);
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
} /* line 3782 */
  sim_icache_fetch(2663 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3784 */
} /* line 3784 */
  sim_icache_fetch(2665 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3786 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 3787 */
l_L176X3: ;/* line 3790 */
__LABEL(l_L176X3);
  sim_icache_fetch(2667 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3791 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3792 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3793 */
   __ADD_CYCLES(1);
} /* line 3793 */
  sim_icache_fetch(2672 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3795 */
} /* line 3795 */
  sim_icache_fetch(2673 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3797 */
} /* line 3797 */
l_L174X3: ;/* line 3800 */
__LABEL(l_L174X3);
  sim_icache_fetch(2675 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_15983Xoffset,0,4), 0); /* line 3801 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3802 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3803 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3804 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3805 */
   __ADD_CYCLES(1);
} /* line 3805 */
  sim_icache_fetch(2683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3807 */
} /* line 3807 */
  sim_icache_fetch(2684 + t_thisfile.offset, 1);
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
} /* line 3809 */
  sim_icache_fetch(2685 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3812 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3813 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3814 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3815 */
l_L177X3: ;/* line 3818 */
__LABEL(l_L177X3);
  sim_icache_fetch(2692 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3819 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3820 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3821 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3822 */
   __ADD_CYCLES(1);
} /* line 3822 */
  sim_icache_fetch(2699 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3824 */
} /* line 3824 */
  sim_icache_fetch(2700 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3826 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3827 */
} /* line 3827 */
  sim_icache_fetch(2703 + t_thisfile.offset, 1);
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
} /* line 3829 */
  sim_icache_fetch(2704 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3832 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3833 */
l_L178X3: ;/* line 3836 */
__LABEL(l_L178X3);
  sim_icache_fetch(2707 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3837 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3838 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3839 */
   __ADD_CYCLES(1);
} /* line 3839 */
  sim_icache_fetch(2711 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3841 */
} /* line 3841 */
  sim_icache_fetch(2712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3843 */
} /* line 3843 */
  sim_icache_fetch(2713 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3846 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3847 */
l_L173X3: ;/* line 3850 */
__LABEL(l_L173X3);
  sim_icache_fetch(2716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3852 */
l_L167X3: ;/* line 3855 */
__LABEL(l_L167X3);
  sim_icache_fetch(2717 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 3856 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3857 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 3858 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3859 */
   __ADD_CYCLES(1);
} /* line 3859 */
  sim_icache_fetch(2724 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3861 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3862 */
} /* line 3862 */
  sim_icache_fetch(2726 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3864 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3865 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3866 */
l_L180X3: ;/* line 3868 */
__LABEL(l_L180X3);
  sim_icache_fetch(2729 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3869 */
   __STW(mem_trace_st((unsigned int) compress_15983Xoffset,0,4), 0); /* line 3870 */
} /* line 3870 */
  sim_icache_fetch(2732 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3872 */
} /* line 3872 */
  sim_icache_fetch(2733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3874 */
} /* line 3874 */
  sim_icache_fetch(2734 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3877 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3878 */
l_L179X3: ;/* line 3881 */
__LABEL(l_L179X3);
  sim_icache_fetch(2737 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3882 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3883 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3884 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3885 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3886 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3887 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3888 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3889 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3890 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3891 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3892 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3893 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3894 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3895 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3896 */
   __MOV(reg_r0_5, (unsigned int) compress_15983Xbuf); /* line 3897 */
   __MOV(reg_r0_3, 0); /* line 3898 */
} /* line 3898 */
l_L181X3: ;/* line 3901 */
__LABEL(l_L181X3);
  sim_icache_fetch(2755 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 3902 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3903 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3904 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3905 */
   __ADD_CYCLES(1);
} /* line 3905 */
  sim_icache_fetch(2761 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3907 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3908 */
} /* line 3908 */
  sim_icache_fetch(2763 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3910 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3911 */
} /* line 3911 */
  sim_icache_fetch(2765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3913 */
} /* line 3913 */
  sim_icache_fetch(2766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3915 */
} /* line 3915 */
  sim_icache_fetch(2767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3917 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3918 */
} /* line 3918 */
  sim_icache_fetch(2769 + t_thisfile.offset, 1);
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
} /* line 3920 */
  sim_icache_fetch(2770 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3922 */
} /* line 3922 */
  sim_icache_fetch(2772 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3924 */
} /* line 3924 */
  sim_icache_fetch(2773 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 3926 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3927 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3928 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3929 */
   __ADD_CYCLES(1);
} /* line 3929 */
  sim_icache_fetch(2779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3931 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3932 */
} /* line 3932 */
  sim_icache_fetch(2781 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3934 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3935 */
} /* line 3935 */
  sim_icache_fetch(2783 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3937 */
} /* line 3937 */
  sim_icache_fetch(2784 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3939 */
} /* line 3939 */
  sim_icache_fetch(2785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3941 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3942 */
} /* line 3942 */
  sim_icache_fetch(2787 + t_thisfile.offset, 1);
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
} /* line 3944 */
  sim_icache_fetch(2788 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3946 */
} /* line 3946 */
  sim_icache_fetch(2790 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3948 */
} /* line 3948 */
  sim_icache_fetch(2791 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 3950 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3951 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3952 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3953 */
   __ADD_CYCLES(1);
} /* line 3953 */
  sim_icache_fetch(2797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3955 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3956 */
} /* line 3956 */
  sim_icache_fetch(2799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3958 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3959 */
} /* line 3959 */
  sim_icache_fetch(2801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3961 */
} /* line 3961 */
  sim_icache_fetch(2802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3963 */
} /* line 3963 */
  sim_icache_fetch(2803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3965 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3966 */
} /* line 3966 */
  sim_icache_fetch(2805 + t_thisfile.offset, 1);
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
} /* line 3968 */
  sim_icache_fetch(2806 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3970 */
} /* line 3970 */
  sim_icache_fetch(2808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3972 */
} /* line 3972 */
  sim_icache_fetch(2809 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 3974 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3975 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3976 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3977 */
   __ADD_CYCLES(1);
} /* line 3977 */
  sim_icache_fetch(2815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3979 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3980 */
} /* line 3980 */
  sim_icache_fetch(2817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3982 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3983 */
} /* line 3983 */
  sim_icache_fetch(2819 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3985 */
} /* line 3985 */
  sim_icache_fetch(2820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3987 */
} /* line 3987 */
  sim_icache_fetch(2821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3989 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3990 */
} /* line 3990 */
  sim_icache_fetch(2823 + t_thisfile.offset, 1);
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
} /* line 3992 */
  sim_icache_fetch(2824 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3994 */
} /* line 3994 */
  sim_icache_fetch(2826 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3996 */
} /* line 3996 */
  sim_icache_fetch(2827 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 3998 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3999 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4000 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4001 */
   __ADD_CYCLES(1);
} /* line 4001 */
  sim_icache_fetch(2833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4003 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4004 */
} /* line 4004 */
  sim_icache_fetch(2835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4006 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4007 */
} /* line 4007 */
  sim_icache_fetch(2837 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4009 */
} /* line 4009 */
  sim_icache_fetch(2838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4011 */
} /* line 4011 */
  sim_icache_fetch(2839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 4013 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 4014 */
} /* line 4014 */
  sim_icache_fetch(2841 + t_thisfile.offset, 1);
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
} /* line 4016 */
  sim_icache_fetch(2842 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4018 */
} /* line 4018 */
  sim_icache_fetch(2844 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4020 */
} /* line 4020 */
  sim_icache_fetch(2845 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4022 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 4023 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4024 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4025 */
   __ADD_CYCLES(1);
} /* line 4025 */
  sim_icache_fetch(2851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4027 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4028 */
} /* line 4028 */
  sim_icache_fetch(2853 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4030 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4031 */
} /* line 4031 */
  sim_icache_fetch(2855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4033 */
} /* line 4033 */
  sim_icache_fetch(2856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4035 */
} /* line 4035 */
  sim_icache_fetch(2857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 4037 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 4038 */
} /* line 4038 */
  sim_icache_fetch(2859 + t_thisfile.offset, 1);
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
} /* line 4040 */
  sim_icache_fetch(2860 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4042 */
} /* line 4042 */
  sim_icache_fetch(2862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4044 */
} /* line 4044 */
  sim_icache_fetch(2863 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4046 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 4047 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4048 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4049 */
   __ADD_CYCLES(1);
} /* line 4049 */
  sim_icache_fetch(2869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4051 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4052 */
} /* line 4052 */
  sim_icache_fetch(2871 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4054 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4055 */
} /* line 4055 */
  sim_icache_fetch(2873 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4057 */
} /* line 4057 */
  sim_icache_fetch(2874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4059 */
} /* line 4059 */
  sim_icache_fetch(2875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 4061 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 4062 */
} /* line 4062 */
  sim_icache_fetch(2877 + t_thisfile.offset, 1);
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
} /* line 4064 */
  sim_icache_fetch(2878 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4066 */
} /* line 4066 */
  sim_icache_fetch(2880 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4068 */
} /* line 4068 */
  sim_icache_fetch(2881 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4070 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4071 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4072 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4073 */
   __ADD_CYCLES(1);
} /* line 4073 */
  sim_icache_fetch(2887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4075 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4076 */
} /* line 4076 */
  sim_icache_fetch(2889 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4078 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4079 */
} /* line 4079 */
  sim_icache_fetch(2891 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4081 */
} /* line 4081 */
  sim_icache_fetch(2892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4083 */
} /* line 4083 */
  sim_icache_fetch(2893 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4085 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4086 */
} /* line 4086 */
  sim_icache_fetch(2895 + t_thisfile.offset, 1);
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
} /* line 4088 */
  sim_icache_fetch(2896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4090 */
} /* line 4090 */
  sim_icache_fetch(2898 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4092 */
} /* line 4092 */
  sim_icache_fetch(2899 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4094 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4095 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4096 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4097 */
   __ADD_CYCLES(1);
} /* line 4097 */
  sim_icache_fetch(2905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4099 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4100 */
} /* line 4100 */
  sim_icache_fetch(2907 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4102 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4103 */
} /* line 4103 */
  sim_icache_fetch(2909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4105 */
} /* line 4105 */
  sim_icache_fetch(2910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4107 */
} /* line 4107 */
  sim_icache_fetch(2911 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4109 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4110 */
} /* line 4110 */
  sim_icache_fetch(2913 + t_thisfile.offset, 1);
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
} /* line 4112 */
  sim_icache_fetch(2914 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4114 */
} /* line 4114 */
  sim_icache_fetch(2916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4116 */
} /* line 4116 */
  sim_icache_fetch(2917 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4118 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4119 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4120 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4121 */
   __ADD_CYCLES(1);
} /* line 4121 */
  sim_icache_fetch(2923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4123 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4124 */
} /* line 4124 */
  sim_icache_fetch(2925 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4126 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4127 */
} /* line 4127 */
  sim_icache_fetch(2927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4129 */
} /* line 4129 */
  sim_icache_fetch(2928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4131 */
} /* line 4131 */
  sim_icache_fetch(2929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4133 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4134 */
} /* line 4134 */
  sim_icache_fetch(2931 + t_thisfile.offset, 1);
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
} /* line 4136 */
  sim_icache_fetch(2932 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4138 */
} /* line 4138 */
  sim_icache_fetch(2934 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4140 */
} /* line 4140 */
  sim_icache_fetch(2935 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4142 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4143 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4144 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4145 */
   __ADD_CYCLES(1);
} /* line 4145 */
  sim_icache_fetch(2941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4147 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4148 */
} /* line 4148 */
  sim_icache_fetch(2943 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4150 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4151 */
} /* line 4151 */
  sim_icache_fetch(2945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4153 */
} /* line 4153 */
  sim_icache_fetch(2946 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4155 */
} /* line 4155 */
  sim_icache_fetch(2947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4157 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4158 */
} /* line 4158 */
  sim_icache_fetch(2949 + t_thisfile.offset, 1);
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
} /* line 4160 */
  sim_icache_fetch(2950 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4162 */
} /* line 4162 */
  sim_icache_fetch(2952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4164 */
} /* line 4164 */
  sim_icache_fetch(2953 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4166 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4167 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4168 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4169 */
   __ADD_CYCLES(1);
} /* line 4169 */
  sim_icache_fetch(2959 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4171 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4172 */
} /* line 4172 */
  sim_icache_fetch(2961 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4174 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4175 */
} /* line 4175 */
  sim_icache_fetch(2963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4177 */
} /* line 4177 */
  sim_icache_fetch(2964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4179 */
} /* line 4179 */
  sim_icache_fetch(2965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4181 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4182 */
} /* line 4182 */
  sim_icache_fetch(2967 + t_thisfile.offset, 1);
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
} /* line 4184 */
  sim_icache_fetch(2968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4186 */
} /* line 4186 */
  sim_icache_fetch(2970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4188 */
} /* line 4188 */
  sim_icache_fetch(2971 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4190 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4191 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4192 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4193 */
   __ADD_CYCLES(1);
} /* line 4193 */
  sim_icache_fetch(2977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4195 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4196 */
} /* line 4196 */
  sim_icache_fetch(2979 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4198 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4199 */
} /* line 4199 */
  sim_icache_fetch(2981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4201 */
} /* line 4201 */
  sim_icache_fetch(2982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4203 */
} /* line 4203 */
  sim_icache_fetch(2983 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4205 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4206 */
} /* line 4206 */
  sim_icache_fetch(2985 + t_thisfile.offset, 1);
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
} /* line 4208 */
  sim_icache_fetch(2986 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4210 */
} /* line 4210 */
  sim_icache_fetch(2988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4212 */
} /* line 4212 */
  sim_icache_fetch(2989 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4214 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4215 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4216 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4217 */
   __ADD_CYCLES(1);
} /* line 4217 */
  sim_icache_fetch(2995 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4219 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4220 */
} /* line 4220 */
  sim_icache_fetch(2997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4222 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4223 */
} /* line 4223 */
  sim_icache_fetch(2999 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4225 */
} /* line 4225 */
  sim_icache_fetch(3000 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4227 */
} /* line 4227 */
  sim_icache_fetch(3001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4229 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4230 */
} /* line 4230 */
  sim_icache_fetch(3003 + t_thisfile.offset, 1);
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
} /* line 4232 */
  sim_icache_fetch(3004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4234 */
} /* line 4234 */
  sim_icache_fetch(3006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4236 */
} /* line 4236 */
  sim_icache_fetch(3007 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4238 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4239 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4240 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4241 */
   __ADD_CYCLES(1);
} /* line 4241 */
  sim_icache_fetch(3013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4243 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4244 */
} /* line 4244 */
  sim_icache_fetch(3015 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4246 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4247 */
} /* line 4247 */
  sim_icache_fetch(3017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4249 */
} /* line 4249 */
  sim_icache_fetch(3018 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4251 */
} /* line 4251 */
  sim_icache_fetch(3019 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4253 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4254 */
} /* line 4254 */
  sim_icache_fetch(3021 + t_thisfile.offset, 1);
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
} /* line 4256 */
  sim_icache_fetch(3022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4258 */
} /* line 4258 */
  sim_icache_fetch(3024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4260 */
} /* line 4260 */
  sim_icache_fetch(3025 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4262 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4263 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4264 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4265 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4266 */
   __ADD_CYCLES(1);
} /* line 4266 */
  sim_icache_fetch(3032 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4268 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4269 */
} /* line 4269 */
  sim_icache_fetch(3034 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4271 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4272 */
} /* line 4272 */
  sim_icache_fetch(3036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4274 */
} /* line 4274 */
  sim_icache_fetch(3037 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4276 */
} /* line 4276 */
  sim_icache_fetch(3038 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4278 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4279 */
} /* line 4279 */
  sim_icache_fetch(3040 + t_thisfile.offset, 1);
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
} /* line 4281 */
  sim_icache_fetch(3041 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4283 */
} /* line 4283 */
  sim_icache_fetch(3043 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4285 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4286 */
l_L197X3: ;/* line 4289 */
__LABEL(l_L197X3);
  sim_icache_fetch(3045 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4290 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4291 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4292 */
   __ADD_CYCLES(1);
} /* line 4292 */
  sim_icache_fetch(3050 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4294 */
} /* line 4294 */
  sim_icache_fetch(3051 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4296 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4297 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4298 */
l_L196X3: ;/* line 4301 */
__LABEL(l_L196X3);
  sim_icache_fetch(3054 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4302 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4303 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4304 */
   __ADD_CYCLES(1);
} /* line 4304 */
  sim_icache_fetch(3059 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4306 */
} /* line 4306 */
  sim_icache_fetch(3060 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4308 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4309 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4310 */
l_L195X3: ;/* line 4313 */
__LABEL(l_L195X3);
  sim_icache_fetch(3063 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4314 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4315 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4316 */
   __ADD_CYCLES(1);
} /* line 4316 */
  sim_icache_fetch(3068 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4318 */
} /* line 4318 */
  sim_icache_fetch(3069 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4320 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4321 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4322 */
l_L194X3: ;/* line 4325 */
__LABEL(l_L194X3);
  sim_icache_fetch(3072 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4326 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4327 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4328 */
   __ADD_CYCLES(1);
} /* line 4328 */
  sim_icache_fetch(3077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4330 */
} /* line 4330 */
  sim_icache_fetch(3078 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4332 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4333 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4334 */
l_L193X3: ;/* line 4337 */
__LABEL(l_L193X3);
  sim_icache_fetch(3081 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4338 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4339 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4340 */
   __ADD_CYCLES(1);
} /* line 4340 */
  sim_icache_fetch(3086 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4342 */
} /* line 4342 */
  sim_icache_fetch(3087 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4344 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4345 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4346 */
l_L192X3: ;/* line 4349 */
__LABEL(l_L192X3);
  sim_icache_fetch(3090 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4350 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4351 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4352 */
   __ADD_CYCLES(1);
} /* line 4352 */
  sim_icache_fetch(3095 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4354 */
} /* line 4354 */
  sim_icache_fetch(3096 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4356 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4357 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4358 */
l_L191X3: ;/* line 4361 */
__LABEL(l_L191X3);
  sim_icache_fetch(3099 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4362 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4363 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4364 */
   __ADD_CYCLES(1);
} /* line 4364 */
  sim_icache_fetch(3104 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4366 */
} /* line 4366 */
  sim_icache_fetch(3105 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4368 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4369 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4370 */
l_L190X3: ;/* line 4373 */
__LABEL(l_L190X3);
  sim_icache_fetch(3108 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4374 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4375 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4376 */
   __ADD_CYCLES(1);
} /* line 4376 */
  sim_icache_fetch(3113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4378 */
} /* line 4378 */
  sim_icache_fetch(3114 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4380 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4381 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4382 */
l_L189X3: ;/* line 4385 */
__LABEL(l_L189X3);
  sim_icache_fetch(3117 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4386 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4387 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4388 */
   __ADD_CYCLES(1);
} /* line 4388 */
  sim_icache_fetch(3122 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4390 */
} /* line 4390 */
  sim_icache_fetch(3123 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4392 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4393 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4394 */
l_L188X3: ;/* line 4397 */
__LABEL(l_L188X3);
  sim_icache_fetch(3126 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4398 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4399 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4400 */
   __ADD_CYCLES(1);
} /* line 4400 */
  sim_icache_fetch(3131 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4402 */
} /* line 4402 */
  sim_icache_fetch(3132 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4404 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4405 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4406 */
l_L187X3: ;/* line 4409 */
__LABEL(l_L187X3);
  sim_icache_fetch(3135 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4410 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4411 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4412 */
   __ADD_CYCLES(1);
} /* line 4412 */
  sim_icache_fetch(3140 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4414 */
} /* line 4414 */
  sim_icache_fetch(3141 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4416 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4417 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4418 */
l_L186X3: ;/* line 4421 */
__LABEL(l_L186X3);
  sim_icache_fetch(3144 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4422 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4423 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4424 */
   __ADD_CYCLES(1);
} /* line 4424 */
  sim_icache_fetch(3149 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4426 */
} /* line 4426 */
  sim_icache_fetch(3150 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4428 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4429 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4430 */
l_L185X3: ;/* line 4433 */
__LABEL(l_L185X3);
  sim_icache_fetch(3153 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4434 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4435 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4436 */
   __ADD_CYCLES(1);
} /* line 4436 */
  sim_icache_fetch(3158 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4438 */
} /* line 4438 */
  sim_icache_fetch(3159 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4440 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4441 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4442 */
l_L184X3: ;/* line 4445 */
__LABEL(l_L184X3);
  sim_icache_fetch(3162 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4446 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4447 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4448 */
   __ADD_CYCLES(1);
} /* line 4448 */
  sim_icache_fetch(3167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4450 */
} /* line 4450 */
  sim_icache_fetch(3168 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4452 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4453 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4454 */
l_L183X3: ;/* line 4457 */
__LABEL(l_L183X3);
  sim_icache_fetch(3171 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4458 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4459 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4460 */
   __ADD_CYCLES(1);
} /* line 4460 */
  sim_icache_fetch(3176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4462 */
} /* line 4462 */
  sim_icache_fetch(3177 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4464 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4465 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4466 */
l_L182X3: ;/* line 4469 */
__LABEL(l_L182X3);
  sim_icache_fetch(3180 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4470 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15983Xoffset,0,4)); /* line 4471 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4472 */
   __ADD_CYCLES(1);
} /* line 4472 */
  sim_icache_fetch(3185 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4474 */
} /* line 4474 */
  sim_icache_fetch(3186 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4476 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4477 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4478 */
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

  sim_icache_fetch(3189 + t_thisfile.offset, 21);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4494 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4495 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4496 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4497 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4498 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4499 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4500 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4501 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4502 */
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4503 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4504 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4505 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4506 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4507 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4508 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4509 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4510 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4511 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4512 */
} /* line 4512 */
  sim_icache_fetch(3210 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4514 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4515 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4516 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4517 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4518 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4519 */
} /* line 4519 */
l_L198X3: ;/* line 4522 */
__LABEL(l_L198X3);
  sim_icache_fetch(3219 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4523 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4524 */
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4525 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4526 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4527 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4528 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4529 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4530 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4531 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4532 */
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4533 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4534 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4535 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4536 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4537 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4538 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4539 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4540 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4541 */
} /* line 4541 */
  sim_icache_fetch(3238 + t_thisfile.offset, 1);
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
} /* line 4543 */
  sim_icache_fetch(3239 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4545 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4546 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4547 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4548 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4549 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4550 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4551 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4552 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4553 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4554 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4555 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4556 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4557 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4558 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4559 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4560 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4561 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4562 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4563 */
} /* line 4563 */
  sim_icache_fetch(3258 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4565 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4566 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4567 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4568 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4569 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4570 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4571 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4572 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4573 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4574 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4575 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4576 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4577 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4578 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4579 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4580 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4581 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4582 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4583 */
} /* line 4583 */
  sim_icache_fetch(3277 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4585 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4586 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4587 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4588 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4589 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4590 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4591 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4592 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4593 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4594 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4595 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4596 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4597 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4598 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4599 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4600 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4601 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4602 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4603 */
} /* line 4603 */
  sim_icache_fetch(3296 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4605 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4606 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4607 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4608 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4609 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4610 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4611 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4612 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4613 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4614 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4615 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4616 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4617 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4618 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4619 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4620 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4621 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4622 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4623 */
} /* line 4623 */
  sim_icache_fetch(3315 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4625 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4626 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4627 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4628 */
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4629 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4630 */
   __GOTO(l_L198X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L198X3;
} /* line 4631 */
l_L199X3: ;/* line 4634 */
__LABEL(l_L199X3);
  sim_icache_fetch(3322 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4635 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4636 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4637 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4638 */
   __ADD_CYCLES(1);
} /* line 4638 */
  sim_icache_fetch(3328 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4640 */
} /* line 4640 */
  sim_icache_fetch(3329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4642 */
} /* line 4642 */
		 /* line 4643 */
  sim_icache_fetch(3331 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4645 */
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
} /* line 4646 */
l_lr_266: ;/* line 4646 */
__LABEL(l_lr_266);
  sim_icache_fetch(3335 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_2, t__i32_0); /* line 4648 */
   __MOV(reg_r0_4, t__i32_0); /* line 4649 */
   __CMPEQ(reg_b0_0, t__i32_0, (unsigned int) -1); /* line 4650 */
   __MOV(reg_r0_3, 0); /* line 4651 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4652 */
   __MOV(reg_r0_5, t__i32_0); /* line 4653 */
} /* line 4653 */
  sim_icache_fetch(3341 + t_thisfile.offset, 1);
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
} /* line 4655 */
  sim_icache_fetch(3342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4658 */
l_L200X3: ;/* line 4661 */
__LABEL(l_L200X3);
  sim_icache_fetch(3343 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4662 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4663 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4664 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4665 */
} /* line 4665 */
  sim_icache_fetch(3348 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4667 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4668 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4669 */
} /* line 4669 */
  sim_icache_fetch(3352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4671 */
} /* line 4671 */
  sim_icache_fetch(3353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4673 */
} /* line 4673 */
  sim_icache_fetch(3355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4675 */
} /* line 4675 */
l_L201X3: ;/* line 4678 */
__LABEL(l_L201X3);
		 /* line 4678 */
  sim_icache_fetch(3356 + t_thisfile.offset, 2);
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
} /* line 4680 */
l_lr_270: ;/* line 4680 */
__LABEL(l_lr_270);
  sim_icache_fetch(3358 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4682 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4683 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4684 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4685 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4686 */
} /* line 4686 */
  sim_icache_fetch(3365 + t_thisfile.offset, 1);
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
} /* line 4688 */
  sim_icache_fetch(3366 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4690 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4691 */
} /* line 4691 */
  sim_icache_fetch(3369 + t_thisfile.offset, 1);
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
} /* line 4693 */
l_L204X3: ;/* line 4696 */
__LABEL(l_L204X3);
  sim_icache_fetch(3370 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4697 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4698 */
} /* line 4698 */
  sim_icache_fetch(3372 + t_thisfile.offset, 1);
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
} /* line 4700 */
  sim_icache_fetch(3373 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(18);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4702 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4703 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4704 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4705 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4706 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4707 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4708 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4709 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4710 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4711 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4712 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4713 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4714 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4715 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4716 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4717 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4718 */
   __GOTO(l_L204X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L204X3;
} /* line 4719 */
l_L205X3: ;/* line 4722 */
__LABEL(l_L205X3);
  sim_icache_fetch(3391 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4723 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4724 */
} /* line 4724 */
		 /* line 4725 */
  sim_icache_fetch(3394 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4727 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4728 */
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
} /* line 4729 */
l_lr_274: ;/* line 4729 */
__LABEL(l_lr_274);
  sim_icache_fetch(3400 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4731 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4732 */
} /* line 4732 */
  sim_icache_fetch(3402 + t_thisfile.offset, 1);
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
} /* line 4734 */
l_L203X3: ;/* line 4737 */
__LABEL(l_L203X3);
  sim_icache_fetch(3403 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4738 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4739 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4740 */
   __ADD_CYCLES(1);
} /* line 4740 */
  sim_icache_fetch(3407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4742 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4743 */
} /* line 4743 */
  sim_icache_fetch(3409 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4745 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4746 */
  sim_icache_fetch(3412 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4748 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4749 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4750 */
} /* line 4750 */
l_L207X3: ;/* line 4753 */
__LABEL(l_L207X3);
  sim_icache_fetch(3415 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4754 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4755 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4756 */
} /* line 4756 */
  sim_icache_fetch(3420 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4758 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4759 */
  sim_icache_fetch(3422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4761 */
} /* line 4761 */
  sim_icache_fetch(3423 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4763 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4764 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4765 */
} /* line 4765 */
  sim_icache_fetch(3428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4767 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4768 */
  sim_icache_fetch(3430 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4770 */
} /* line 4770 */
  sim_icache_fetch(3431 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4772 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4773 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4774 */
} /* line 4774 */
  sim_icache_fetch(3436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4776 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4777 */
  sim_icache_fetch(3438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4779 */
} /* line 4779 */
  sim_icache_fetch(3439 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4781 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4782 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4783 */
} /* line 4783 */
  sim_icache_fetch(3444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4785 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4786 */
  sim_icache_fetch(3446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4788 */
} /* line 4788 */
  sim_icache_fetch(3447 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4790 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4791 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4792 */
} /* line 4792 */
  sim_icache_fetch(3452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4794 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4795 */
  sim_icache_fetch(3454 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4797 */
} /* line 4797 */
  sim_icache_fetch(3455 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4799 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4800 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4801 */
} /* line 4801 */
  sim_icache_fetch(3460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4803 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4804 */
  sim_icache_fetch(3462 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4806 */
} /* line 4806 */
  sim_icache_fetch(3463 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4808 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4809 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4810 */
} /* line 4810 */
  sim_icache_fetch(3468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4812 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4813 */
  sim_icache_fetch(3470 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4815 */
} /* line 4815 */
  sim_icache_fetch(3471 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4817 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4818 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4819 */
} /* line 4819 */
  sim_icache_fetch(3476 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4821 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4822 */
  sim_icache_fetch(3478 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4824 */
} /* line 4824 */
  sim_icache_fetch(3479 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4826 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4827 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4828 */
} /* line 4828 */
  sim_icache_fetch(3484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4830 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4831 */
  sim_icache_fetch(3486 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4833 */
} /* line 4833 */
  sim_icache_fetch(3487 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4835 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4836 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4837 */
} /* line 4837 */
  sim_icache_fetch(3492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4839 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4840 */
  sim_icache_fetch(3494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4842 */
} /* line 4842 */
  sim_icache_fetch(3495 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4844 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4845 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4846 */
} /* line 4846 */
  sim_icache_fetch(3500 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4848 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4849 */
  sim_icache_fetch(3502 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4851 */
} /* line 4851 */
  sim_icache_fetch(3503 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4853 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4854 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4855 */
} /* line 4855 */
  sim_icache_fetch(3508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4857 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4858 */
  sim_icache_fetch(3510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4860 */
} /* line 4860 */
  sim_icache_fetch(3511 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4862 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4863 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4864 */
} /* line 4864 */
  sim_icache_fetch(3516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4866 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4867 */
  sim_icache_fetch(3518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4869 */
} /* line 4869 */
  sim_icache_fetch(3519 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4871 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4872 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4873 */
} /* line 4873 */
  sim_icache_fetch(3524 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4875 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4876 */
  sim_icache_fetch(3526 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4878 */
} /* line 4878 */
  sim_icache_fetch(3527 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4880 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4881 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4882 */
} /* line 4882 */
  sim_icache_fetch(3532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4884 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4885 */
  sim_icache_fetch(3534 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4887 */
} /* line 4887 */
  sim_icache_fetch(3535 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4889 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4890 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4891 */
} /* line 4891 */
  sim_icache_fetch(3540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4893 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4894 */
  sim_icache_fetch(3542 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4896 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4897 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 4898 */
l_L223X3: ;/* line 4901 */
__LABEL(l_L223X3);
  sim_icache_fetch(3545 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4902 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4903 */
} /* line 4903 */
  sim_icache_fetch(3547 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4905 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 4906 */
l_L225X3: ;/* line 4909 */
__LABEL(l_L225X3);
  sim_icache_fetch(3549 + t_thisfile.offset, 28);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __MOV(reg_r0_5, reg_r0_3); /* line 4910 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4911 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4912 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4913 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4914 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4915 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4916 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4917 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4918 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4919 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4920 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4921 */
   __ADD(reg_r0_22, reg_r0_19, (unsigned int) -16); /* line 4922 */
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) -16); /* line 4923 */
   __ADD(reg_r0_24, reg_r0_17, (unsigned int) -16); /* line 4924 */
   __ADD(reg_r0_25, reg_r0_16, (unsigned int) -16); /* line 4925 */
   __ADD(reg_r0_26, reg_r0_15, (unsigned int) -16); /* line 4926 */
   __ADD(reg_r0_27, reg_r0_14, (unsigned int) -16); /* line 4927 */
   __ADD(reg_r0_28, reg_r0_13, (unsigned int) -16); /* line 4928 */
} /* line 4928 */
  sim_icache_fetch(3577 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __MOV(reg_r0_37, reg_r0_20); /* line 4930 */
   __ADD(reg_r0_29, reg_r0_12, (unsigned int) -16); /* line 4931 */
   __ADD(reg_r0_30, reg_r0_11, (unsigned int) -16); /* line 4932 */
   __ADD(reg_r0_31, reg_r0_10, (unsigned int) -16); /* line 4933 */
   __ADD(reg_r0_32, reg_r0_9, (unsigned int) -16); /* line 4934 */
   __ADD(reg_r0_33, reg_r0_8, (unsigned int) -16); /* line 4935 */
   __ADD(reg_r0_34, reg_r0_7, (unsigned int) -16); /* line 4936 */
   __ADD(reg_r0_35, reg_r0_6, (unsigned int) -16); /* line 4937 */
   __ADD(reg_r0_36, reg_r0_20, (unsigned int) -16); /* line 4938 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) -16); /* line 4939 */
} /* line 4939 */
  sim_icache_fetch(3587 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4941 */
   __MOV(reg_r0_40, reg_r0_36); /* line 4942 */
} /* line 4942 */
  sim_icache_fetch(3589 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4944 */
} /* line 4944 */
  sim_icache_fetch(3591 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4946 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4947 */
  sim_icache_fetch(3593 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4949 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4950 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4951 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4952 */
   __ADD_CYCLES(1);
} /* line 4952 */
  sim_icache_fetch(3599 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4954 */
} /* line 4954 */
  sim_icache_fetch(3600 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4956 */
} /* line 4956 */
  sim_icache_fetch(3602 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4958 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4959 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4960 */
  sim_icache_fetch(3606 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4962 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4963 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4964 */
   __ADD(reg_r0_6, reg_r0_35, (unsigned int) -16); /* line 4965 */
   __MFB(reg_r0_4, t__i32_0); /* line 4966 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4967 */
   __ADD_CYCLES(1);
} /* line 4967 */
  sim_icache_fetch(3614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4969 */
} /* line 4969 */
  sim_icache_fetch(3615 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4971 */
} /* line 4971 */
  sim_icache_fetch(3617 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4973 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4974 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4975 */
  sim_icache_fetch(3620 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4977 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4978 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4979 */
   __ADD(reg_r0_7, reg_r0_34, (unsigned int) -16); /* line 4980 */
   __MFB(reg_r0_4, t__i32_0); /* line 4981 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4982 */
   __ADD_CYCLES(1);
} /* line 4982 */
  sim_icache_fetch(3628 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4984 */
} /* line 4984 */
  sim_icache_fetch(3629 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4986 */
} /* line 4986 */
  sim_icache_fetch(3631 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4988 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4989 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4990 */
  sim_icache_fetch(3634 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4992 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4993 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4994 */
   __ADD(reg_r0_8, reg_r0_33, (unsigned int) -16); /* line 4995 */
   __MFB(reg_r0_4, t__i32_0); /* line 4996 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4997 */
   __ADD_CYCLES(1);
} /* line 4997 */
  sim_icache_fetch(3642 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4999 */
} /* line 4999 */
  sim_icache_fetch(3643 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 5001 */
} /* line 5001 */
  sim_icache_fetch(3645 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 5003 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5004 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5005 */
  sim_icache_fetch(3648 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 5007 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5008 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 5009 */
   __ADD(reg_r0_9, reg_r0_32, (unsigned int) -16); /* line 5010 */
   __MFB(reg_r0_4, t__i32_0); /* line 5011 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5012 */
   __ADD_CYCLES(1);
} /* line 5012 */
  sim_icache_fetch(3656 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 5014 */
} /* line 5014 */
  sim_icache_fetch(3657 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 5016 */
} /* line 5016 */
  sim_icache_fetch(3659 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 5018 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5019 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5020 */
  sim_icache_fetch(3662 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 5022 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5023 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 5024 */
   __ADD(reg_r0_10, reg_r0_31, (unsigned int) -16); /* line 5025 */
   __MFB(reg_r0_4, t__i32_0); /* line 5026 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5027 */
   __ADD_CYCLES(1);
} /* line 5027 */
  sim_icache_fetch(3670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 5029 */
} /* line 5029 */
  sim_icache_fetch(3671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 5031 */
} /* line 5031 */
  sim_icache_fetch(3673 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 5033 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5034 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5035 */
  sim_icache_fetch(3676 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 5037 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5038 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 5039 */
   __ADD(reg_r0_11, reg_r0_30, (unsigned int) -16); /* line 5040 */
   __MFB(reg_r0_4, t__i32_0); /* line 5041 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5042 */
   __ADD_CYCLES(1);
} /* line 5042 */
  sim_icache_fetch(3684 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 5044 */
} /* line 5044 */
  sim_icache_fetch(3685 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 5046 */
} /* line 5046 */
  sim_icache_fetch(3687 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 5048 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5049 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5050 */
  sim_icache_fetch(3690 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5052 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5053 */
   __CMPLEU(reg_b0_7, reg_r0_37, ((unsigned int) htab + (unsigned int) 4096)); /* line 5054 */
   __ADD(reg_r0_12, reg_r0_29, (unsigned int) -16); /* line 5055 */
   __MFB(reg_r0_4, t__i32_0); /* line 5056 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5057 */
   __ADD_CYCLES(1);
} /* line 5057 */
  sim_icache_fetch(3698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5059 */
} /* line 5059 */
  sim_icache_fetch(3699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5061 */
} /* line 5061 */
  sim_icache_fetch(3701 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5063 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5064 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5065 */
  sim_icache_fetch(3704 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5067 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5068 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5069 */
   __ADD(reg_r0_13, reg_r0_28, (unsigned int) -16); /* line 5070 */
   __MFB(reg_r0_4, t__i32_0); /* line 5071 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5072 */
   __ADD_CYCLES(1);
} /* line 5072 */
  sim_icache_fetch(3712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5074 */
} /* line 5074 */
  sim_icache_fetch(3713 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5076 */
} /* line 5076 */
  sim_icache_fetch(3715 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5078 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5079 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5080 */
  sim_icache_fetch(3718 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5082 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5083 */
   __CMPLEU(reg_b0_1, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5084 */
   __ADD(reg_r0_14, reg_r0_27, (unsigned int) -16); /* line 5085 */
   __MFB(reg_r0_4, t__i32_0); /* line 5086 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5087 */
   __ADD_CYCLES(1);
} /* line 5087 */
  sim_icache_fetch(3726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5089 */
} /* line 5089 */
  sim_icache_fetch(3727 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5091 */
} /* line 5091 */
  sim_icache_fetch(3729 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5093 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5094 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5095 */
  sim_icache_fetch(3732 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5097 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5098 */
   __CMPLEU(reg_b0_2, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5099 */
   __ADD(reg_r0_15, reg_r0_26, (unsigned int) -16); /* line 5100 */
   __MFB(reg_r0_4, t__i32_0); /* line 5101 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5102 */
   __ADD_CYCLES(1);
} /* line 5102 */
  sim_icache_fetch(3740 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5104 */
} /* line 5104 */
  sim_icache_fetch(3741 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5106 */
} /* line 5106 */
  sim_icache_fetch(3743 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5108 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5109 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5110 */
  sim_icache_fetch(3746 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5112 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5113 */
   __CMPLEU(reg_b0_3, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5114 */
   __ADD(reg_r0_16, reg_r0_25, (unsigned int) -16); /* line 5115 */
   __MFB(reg_r0_4, t__i32_0); /* line 5116 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5117 */
   __ADD_CYCLES(1);
} /* line 5117 */
  sim_icache_fetch(3754 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5119 */
} /* line 5119 */
  sim_icache_fetch(3755 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5121 */
} /* line 5121 */
  sim_icache_fetch(3757 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5123 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5124 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5125 */
  sim_icache_fetch(3760 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5127 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5128 */
   __CMPLEU(reg_b0_4, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5129 */
   __ADD(reg_r0_17, reg_r0_24, (unsigned int) -16); /* line 5130 */
   __MFB(reg_r0_4, t__i32_0); /* line 5131 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5132 */
   __ADD_CYCLES(1);
} /* line 5132 */
  sim_icache_fetch(3768 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5134 */
} /* line 5134 */
  sim_icache_fetch(3769 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5136 */
} /* line 5136 */
  sim_icache_fetch(3771 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5138 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5139 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5140 */
  sim_icache_fetch(3774 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5142 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5143 */
   __CMPLEU(reg_b0_5, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5144 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) -16); /* line 5145 */
   __MFB(reg_r0_4, t__i32_0); /* line 5146 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5147 */
   __ADD_CYCLES(1);
} /* line 5147 */
  sim_icache_fetch(3782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5149 */
} /* line 5149 */
  sim_icache_fetch(3783 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5151 */
} /* line 5151 */
  sim_icache_fetch(3785 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5153 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5154 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5155 */
  sim_icache_fetch(3788 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5157 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5158 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5159 */
   __CMPLEU(reg_b0_6, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5160 */
   __ADD(reg_r0_19, reg_r0_22, (unsigned int) -16); /* line 5161 */
   __MFB(reg_r0_4, t__i32_0); /* line 5162 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5163 */
   __ADD_CYCLES(1);
} /* line 5163 */
  sim_icache_fetch(3797 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5165 */
} /* line 5165 */
  sim_icache_fetch(3798 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5167 */
} /* line 5167 */
  sim_icache_fetch(3800 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5169 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5170 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5171 */
  sim_icache_fetch(3803 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_5, reg_r0_3); /* line 5173 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5174 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5175 */
   __CMPLEU(reg_b0_7, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5176 */
   __ADD(reg_r0_20, reg_r0_36, (unsigned int) -16); /* line 5177 */
   __MOV(reg_r0_3, reg_r0_38); /* line 5178 */
   __MFB(reg_r0_37, t__i32_0); /* line 5179 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5180 */
   __ADD_CYCLES(1);
} /* line 5180 */
  sim_icache_fetch(3813 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5182 */
} /* line 5182 */
  sim_icache_fetch(3814 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5184 */
} /* line 5184 */
  sim_icache_fetch(3816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5186 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5187 */
  sim_icache_fetch(3818 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5189 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5190 */
   __CMPLEU(reg_b0_0, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5191 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5192 */
   __ADD_CYCLES(1);
} /* line 5192 */
  sim_icache_fetch(3824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5194 */
} /* line 5194 */
  sim_icache_fetch(3825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5196 */
} /* line 5196 */
  sim_icache_fetch(3827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5198 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5199 */
  sim_icache_fetch(3829 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5201 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5202 */
   __CMPLEU(reg_b0_1, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5203 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5204 */
   __ADD_CYCLES(1);
} /* line 5204 */
  sim_icache_fetch(3835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5206 */
} /* line 5206 */
  sim_icache_fetch(3836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5208 */
} /* line 5208 */
  sim_icache_fetch(3838 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5210 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5211 */
  sim_icache_fetch(3840 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5213 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5214 */
   __CMPLEU(reg_b0_2, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5215 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5216 */
   __ADD_CYCLES(1);
} /* line 5216 */
  sim_icache_fetch(3846 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5218 */
} /* line 5218 */
  sim_icache_fetch(3847 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5220 */
} /* line 5220 */
  sim_icache_fetch(3849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5222 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5223 */
  sim_icache_fetch(3851 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5225 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5226 */
   __CMPLEU(reg_b0_3, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5227 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5228 */
   __ADD_CYCLES(1);
} /* line 5228 */
  sim_icache_fetch(3857 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5230 */
} /* line 5230 */
  sim_icache_fetch(3858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5232 */
} /* line 5232 */
  sim_icache_fetch(3860 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5234 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5235 */
  sim_icache_fetch(3862 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5237 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5238 */
   __CMPLEU(reg_b0_4, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5239 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5240 */
   __ADD_CYCLES(1);
} /* line 5240 */
  sim_icache_fetch(3868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5242 */
} /* line 5242 */
  sim_icache_fetch(3869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5244 */
} /* line 5244 */
  sim_icache_fetch(3871 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5246 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5247 */
  sim_icache_fetch(3873 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5249 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5250 */
   __CMPLEU(reg_b0_5, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5251 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5252 */
   __ADD_CYCLES(1);
} /* line 5252 */
  sim_icache_fetch(3879 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5254 */
} /* line 5254 */
  sim_icache_fetch(3880 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5256 */
} /* line 5256 */
  sim_icache_fetch(3882 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5258 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5259 */
  sim_icache_fetch(3884 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5261 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5262 */
   __CMPLEU(reg_b0_6, reg_r0_22, ((unsigned int) htab + (unsigned int) 4096)); /* line 5263 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5264 */
   __ADD_CYCLES(1);
} /* line 5264 */
  sim_icache_fetch(3890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5266 */
} /* line 5266 */
  sim_icache_fetch(3891 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5268 */
} /* line 5268 */
  sim_icache_fetch(3893 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5270 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5271 */
  sim_icache_fetch(3895 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5273 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5274 */
   __MTB(reg_b0_7, reg_r0_37); /* line 5275 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5276 */
   __ADD_CYCLES(1);
} /* line 5276 */
  sim_icache_fetch(3900 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5278 */
} /* line 5278 */
  sim_icache_fetch(3901 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5280 */
} /* line 5280 */
  sim_icache_fetch(3903 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5282 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5283 */
  sim_icache_fetch(3905 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5285 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5286 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5287 */
   __ADD_CYCLES(1);
} /* line 5287 */
  sim_icache_fetch(3909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5289 */
} /* line 5289 */
  sim_icache_fetch(3910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5291 */
} /* line 5291 */
  sim_icache_fetch(3912 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5293 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5294 */
  sim_icache_fetch(3914 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5296 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5297 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5298 */
   __ADD_CYCLES(1);
} /* line 5298 */
  sim_icache_fetch(3918 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5300 */
} /* line 5300 */
  sim_icache_fetch(3919 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5302 */
} /* line 5302 */
  sim_icache_fetch(3921 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5304 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5305 */
  sim_icache_fetch(3923 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5307 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5308 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5309 */
   __ADD_CYCLES(1);
} /* line 5309 */
  sim_icache_fetch(3927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5311 */
} /* line 5311 */
  sim_icache_fetch(3928 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5313 */
} /* line 5313 */
  sim_icache_fetch(3930 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5315 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5316 */
  sim_icache_fetch(3932 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5318 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5319 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5320 */
   __ADD_CYCLES(1);
} /* line 5320 */
  sim_icache_fetch(3936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5322 */
} /* line 5322 */
  sim_icache_fetch(3937 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5324 */
} /* line 5324 */
  sim_icache_fetch(3939 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5326 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5327 */
  sim_icache_fetch(3941 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5329 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5330 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5331 */
   __ADD_CYCLES(1);
} /* line 5331 */
  sim_icache_fetch(3945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5333 */
} /* line 5333 */
  sim_icache_fetch(3946 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5335 */
} /* line 5335 */
  sim_icache_fetch(3948 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5337 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5338 */
  sim_icache_fetch(3950 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_22, mem_trace_ld(reg_r0_22,0,1)); /* line 5340 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5341 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5342 */
   __ADD_CYCLES(1);
} /* line 5342 */
  sim_icache_fetch(3954 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5344 */
} /* line 5344 */
  sim_icache_fetch(3955 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5346 */
} /* line 5346 */
  sim_icache_fetch(3957 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_22); /* line 5348 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5349 */
  sim_icache_fetch(3959 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5351 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5352 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5353 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5354 */
   __ADD_CYCLES(1);
} /* line 5354 */
  sim_icache_fetch(3964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5356 */
} /* line 5356 */
  sim_icache_fetch(3965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5358 */
} /* line 5358 */
  sim_icache_fetch(3967 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5360 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5362 */
  sim_icache_fetch(3969 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5364 */
l_L241X3: ;/* line 5367 */
__LABEL(l_L241X3);
  sim_icache_fetch(3970 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5368 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5369 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5370 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5371 */
l_L244X3: ;/* line 5374 */
__LABEL(l_L244X3);
  sim_icache_fetch(3976 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5375 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5376 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5377 */
} /* line 5377 */
  sim_icache_fetch(3981 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5379 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5380 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5381 */
l_L240X3: ;/* line 5384 */
__LABEL(l_L240X3);
  sim_icache_fetch(3985 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5385 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5386 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5387 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5388 */
l_L239X3: ;/* line 5391 */
__LABEL(l_L239X3);
  sim_icache_fetch(3991 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5392 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5393 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5394 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5395 */
l_L238X3: ;/* line 5398 */
__LABEL(l_L238X3);
  sim_icache_fetch(3997 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5399 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5400 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5401 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5402 */
l_L237X3: ;/* line 5405 */
__LABEL(l_L237X3);
  sim_icache_fetch(4003 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5406 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5407 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5408 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5409 */
l_L236X3: ;/* line 5412 */
__LABEL(l_L236X3);
  sim_icache_fetch(4009 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5413 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5414 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5415 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5416 */
l_L235X3: ;/* line 5419 */
__LABEL(l_L235X3);
  sim_icache_fetch(4015 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5420 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5421 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5422 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5423 */
l_L234X3: ;/* line 5426 */
__LABEL(l_L234X3);
  sim_icache_fetch(4021 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5427 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5428 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5429 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5430 */
l_L233X3: ;/* line 5433 */
__LABEL(l_L233X3);
  sim_icache_fetch(4027 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5434 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5435 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5436 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5437 */
l_L232X3: ;/* line 5440 */
__LABEL(l_L232X3);
  sim_icache_fetch(4033 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5441 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5442 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5443 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5444 */
l_L231X3: ;/* line 5447 */
__LABEL(l_L231X3);
  sim_icache_fetch(4039 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5448 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5449 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5450 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5451 */
l_L230X3: ;/* line 5454 */
__LABEL(l_L230X3);
  sim_icache_fetch(4045 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5455 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5456 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5457 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5458 */
l_L229X3: ;/* line 5461 */
__LABEL(l_L229X3);
  sim_icache_fetch(4051 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5462 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5463 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5464 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5465 */
l_L228X3: ;/* line 5468 */
__LABEL(l_L228X3);
  sim_icache_fetch(4057 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5469 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5470 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5471 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5472 */
l_L227X3: ;/* line 5475 */
__LABEL(l_L227X3);
  sim_icache_fetch(4063 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5476 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5477 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5478 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5479 */
l_L226X3: ;/* line 5482 */
__LABEL(l_L226X3);
  sim_icache_fetch(4069 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5483 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5484 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5485 */
} /* line 5485 */
l_L242X3: ;/* line 5487 */
__LABEL(l_L242X3);
  sim_icache_fetch(4074 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5487 */
  sim_icache_fetch(4075 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5489 */
} /* line 5489 */
  sim_icache_fetch(4076 + t_thisfile.offset, 1);
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
} /* line 5491 */
l_L243X3: ;/* line 5493 */
__LABEL(l_L243X3);
  sim_icache_fetch(4077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5494 */
   __GOTO(l_L201X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L201X3;
} /* line 5495 */
l_L222X3: ;/* line 5498 */
__LABEL(l_L222X3);
  sim_icache_fetch(4079 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5499 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5500 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5501 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5502 */
l_L221X3: ;/* line 5505 */
__LABEL(l_L221X3);
  sim_icache_fetch(4083 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5506 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5507 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5508 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5509 */
l_L220X3: ;/* line 5512 */
__LABEL(l_L220X3);
  sim_icache_fetch(4087 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5513 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5514 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5515 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5516 */
l_L219X3: ;/* line 5519 */
__LABEL(l_L219X3);
  sim_icache_fetch(4091 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5520 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5521 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5522 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5523 */
l_L218X3: ;/* line 5526 */
__LABEL(l_L218X3);
  sim_icache_fetch(4095 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5527 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5528 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5529 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5530 */
l_L217X3: ;/* line 5533 */
__LABEL(l_L217X3);
  sim_icache_fetch(4099 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5534 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5535 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5536 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5537 */
l_L216X3: ;/* line 5540 */
__LABEL(l_L216X3);
  sim_icache_fetch(4103 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5541 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5542 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5543 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5544 */
l_L215X3: ;/* line 5547 */
__LABEL(l_L215X3);
  sim_icache_fetch(4107 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5548 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5549 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5550 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5551 */
l_L214X3: ;/* line 5554 */
__LABEL(l_L214X3);
  sim_icache_fetch(4111 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5555 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5556 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5557 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5558 */
l_L213X3: ;/* line 5561 */
__LABEL(l_L213X3);
  sim_icache_fetch(4115 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5562 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5563 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5564 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5565 */
l_L212X3: ;/* line 5568 */
__LABEL(l_L212X3);
  sim_icache_fetch(4119 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5569 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5570 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5571 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5572 */
l_L211X3: ;/* line 5575 */
__LABEL(l_L211X3);
  sim_icache_fetch(4123 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5576 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5577 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5578 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5579 */
l_L210X3: ;/* line 5582 */
__LABEL(l_L210X3);
  sim_icache_fetch(4127 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5583 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5584 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5585 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5586 */
l_L209X3: ;/* line 5589 */
__LABEL(l_L209X3);
  sim_icache_fetch(4131 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5590 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5591 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5592 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5593 */
l_L208X3: ;/* line 5598 */
__LABEL(l_L208X3);
  sim_icache_fetch(4135 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5599 */
} /* line 5599 */
l_L224X3: ;/* line 5601 */
__LABEL(l_L224X3);
  sim_icache_fetch(4136 + t_thisfile.offset, 20);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(18);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5602 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5603 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5604 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5605 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5606 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5607 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5608 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5609 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5610 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5611 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5612 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5613 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5614 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5615 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5616 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5617 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5618 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5619 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5620 */
   __ADD_CYCLES(1);
} /* line 5620 */
  sim_icache_fetch(4156 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5622 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5623 */
l_L206X3: ;/* line 5626 */
__LABEL(l_L206X3);
  sim_icache_fetch(4158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5627 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 5628 */
l_L202X3: ;/* line 5631 */
__LABEL(l_L202X3);
  sim_icache_fetch(4160 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5632 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5633 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5634 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5635 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5636 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5637 */
   __ADD_CYCLES(1);
} /* line 5637 */
  sim_icache_fetch(4166 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5640 */
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

  sim_icache_fetch(4167 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5659 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5660 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5661 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5662 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5663 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5664 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5665 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5666 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5667 */
   __ADD_CYCLES(1);
} /* line 5667 */
  sim_icache_fetch(4184 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGE(reg_r0_11, reg_r0_7, reg_r0_8); /* line 5669 */
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5670 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5671 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5672 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5673 */
} /* line 5673 */
  sim_icache_fetch(4189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5675 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_2); /* line 5676 */
} /* line 5676 */
  sim_icache_fetch(4191 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_2, reg_r0_4, reg_r0_11); /* line 5678 */
} /* line 5678 */
  sim_icache_fetch(4192 + t_thisfile.offset, 1);
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
} /* line 5680 */
  sim_icache_fetch(4193 + t_thisfile.offset, 1);
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
} /* line 5682 */
  sim_icache_fetch(4194 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5684 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5685 */
  sim_icache_fetch(4197 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5687 */
} /* line 5687 */
l_L246X3: ;/* line 5690 */
__LABEL(l_L246X3);
  sim_icache_fetch(4199 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5691 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5692 */
   __MOV(reg_r0_5, 0); /* line 5693 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5694 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5695 */
   __ADD_CYCLES(1);
} /* line 5695 */
  sim_icache_fetch(4206 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5697 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5698 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5699 */
} /* line 5699 */
  sim_icache_fetch(4209 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5701 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5702 */
l_L249X3: ;/* line 5705 */
__LABEL(l_L249X3);
  sim_icache_fetch(4211 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5706 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5707 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5708 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5709 */
} /* line 5709 */
  sim_icache_fetch(4217 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5711 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5712 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5713 */
  sim_icache_fetch(4220 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5715 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5716 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5717 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5718 */
} /* line 5718 */
  sim_icache_fetch(4224 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5720 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5721 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5722 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5723 */
} /* line 5723 */
  sim_icache_fetch(4229 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5725 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5726 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5727 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5728 */
  sim_icache_fetch(4234 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5730 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5731 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5732 */
} /* line 5732 */
  sim_icache_fetch(4238 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5734 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5735 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5736 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5737 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5738 */
} /* line 5738 */
  sim_icache_fetch(4244 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5740 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5741 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5742 */
} /* line 5742 */
  sim_icache_fetch(4247 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5744 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5745 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5746 */
} /* line 5746 */
l_L252X3: ;/* line 5748 */
__LABEL(l_L252X3);
  sim_icache_fetch(4250 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5749 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5750 */
} /* line 5750 */
  sim_icache_fetch(4253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5752 */
} /* line 5752 */
  sim_icache_fetch(4254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5754 */
} /* line 5754 */
  sim_icache_fetch(4255 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5756 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5757 */
  sim_icache_fetch(4257 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5759 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5760 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5761 */
  sim_icache_fetch(4260 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5763 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5764 */
  sim_icache_fetch(4263 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5766 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5767 */
} /* line 5767 */
  sim_icache_fetch(4267 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5769 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5770 */
} /* line 5770 */
  sim_icache_fetch(4270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5772 */
} /* line 5772 */
  sim_icache_fetch(4271 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5774 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5775 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5776 */
} /* line 5776 */
l_L255X3: ;/* line 5778 */
__LABEL(l_L255X3);
  sim_icache_fetch(4274 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5779 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5780 */
} /* line 5780 */
  sim_icache_fetch(4277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5782 */
} /* line 5782 */
  sim_icache_fetch(4278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5784 */
} /* line 5784 */
  sim_icache_fetch(4279 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5786 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5787 */
  sim_icache_fetch(4281 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5789 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5790 */
  sim_icache_fetch(4283 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5792 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L256X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5793 */
  sim_icache_fetch(4286 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5795 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5796 */
} /* line 5796 */
  sim_icache_fetch(4290 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5798 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5799 */
} /* line 5799 */
  sim_icache_fetch(4293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5801 */
} /* line 5801 */
  sim_icache_fetch(4294 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5803 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5804 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5805 */
} /* line 5805 */
l_L257X3: ;/* line 5807 */
__LABEL(l_L257X3);
  sim_icache_fetch(4297 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5808 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5809 */
} /* line 5809 */
  sim_icache_fetch(4300 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5811 */
} /* line 5811 */
  sim_icache_fetch(4301 + t_thisfile.offset, 1);
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
} /* line 5813 */
  sim_icache_fetch(4302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5815 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5816 */
  sim_icache_fetch(4304 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5818 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L258X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5819 */
  sim_icache_fetch(4307 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5821 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5822 */
} /* line 5822 */
  sim_icache_fetch(4311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5824 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5825 */
} /* line 5825 */
  sim_icache_fetch(4314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5827 */
} /* line 5827 */
  sim_icache_fetch(4315 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5829 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5830 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5831 */
} /* line 5831 */
l_L259X3: ;/* line 5833 */
__LABEL(l_L259X3);
  sim_icache_fetch(4318 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5834 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5835 */
} /* line 5835 */
  sim_icache_fetch(4321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5837 */
} /* line 5837 */
  sim_icache_fetch(4322 + t_thisfile.offset, 1);
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
} /* line 5839 */
  sim_icache_fetch(4323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5841 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5842 */
  sim_icache_fetch(4325 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5844 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L260X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5845 */
  sim_icache_fetch(4328 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5847 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5848 */
} /* line 5848 */
  sim_icache_fetch(4332 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5850 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5851 */
} /* line 5851 */
  sim_icache_fetch(4335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5853 */
} /* line 5853 */
  sim_icache_fetch(4336 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5855 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5856 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5857 */
} /* line 5857 */
l_L261X3: ;/* line 5859 */
__LABEL(l_L261X3);
  sim_icache_fetch(4339 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5860 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5861 */
} /* line 5861 */
  sim_icache_fetch(4342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5863 */
} /* line 5863 */
  sim_icache_fetch(4343 + t_thisfile.offset, 1);
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
} /* line 5865 */
  sim_icache_fetch(4344 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5867 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5868 */
  sim_icache_fetch(4346 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5870 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5871 */
  sim_icache_fetch(4349 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5873 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5874 */
} /* line 5874 */
  sim_icache_fetch(4353 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5876 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5877 */
} /* line 5877 */
  sim_icache_fetch(4356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5879 */
} /* line 5879 */
  sim_icache_fetch(4357 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5881 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5882 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5883 */
} /* line 5883 */
l_L263X3: ;/* line 5885 */
__LABEL(l_L263X3);
  sim_icache_fetch(4360 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5886 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5887 */
} /* line 5887 */
  sim_icache_fetch(4363 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5889 */
} /* line 5889 */
  sim_icache_fetch(4364 + t_thisfile.offset, 1);
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
} /* line 5891 */
  sim_icache_fetch(4365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5893 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5894 */
  sim_icache_fetch(4367 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5896 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L264X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5897 */
  sim_icache_fetch(4370 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5899 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5900 */
} /* line 5900 */
  sim_icache_fetch(4374 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5902 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5903 */
} /* line 5903 */
  sim_icache_fetch(4377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5905 */
} /* line 5905 */
  sim_icache_fetch(4378 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5907 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5908 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5909 */
} /* line 5909 */
l_L265X3: ;/* line 5911 */
__LABEL(l_L265X3);
  sim_icache_fetch(4381 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5912 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5913 */
} /* line 5913 */
  sim_icache_fetch(4384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5915 */
} /* line 5915 */
  sim_icache_fetch(4385 + t_thisfile.offset, 1);
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
} /* line 5917 */
  sim_icache_fetch(4386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5919 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5920 */
  sim_icache_fetch(4388 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5922 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L266X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5923 */
  sim_icache_fetch(4391 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5925 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5926 */
} /* line 5926 */
  sim_icache_fetch(4395 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5928 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5929 */
} /* line 5929 */
  sim_icache_fetch(4398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5931 */
} /* line 5931 */
  sim_icache_fetch(4399 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5933 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5934 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5935 */
} /* line 5935 */
l_L267X3: ;/* line 5937 */
__LABEL(l_L267X3);
  sim_icache_fetch(4402 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5938 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5939 */
} /* line 5939 */
  sim_icache_fetch(4405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5941 */
} /* line 5941 */
  sim_icache_fetch(4406 + t_thisfile.offset, 1);
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
} /* line 5943 */
  sim_icache_fetch(4407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5945 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5946 */
  sim_icache_fetch(4409 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5948 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5949 */
  sim_icache_fetch(4412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5951 */
} /* line 5951 */
  sim_icache_fetch(4414 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5953 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5954 */
   __ADD_CYCLES(1);
} /* line 5954 */
  sim_icache_fetch(4416 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5956 */
} /* line 5956 */
l_L269X3: ;/* line 5958 */
__LABEL(l_L269X3);
  sim_icache_fetch(4417 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5959 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5960 */
} /* line 5960 */
  sim_icache_fetch(4420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5962 */
} /* line 5962 */
  sim_icache_fetch(4421 + t_thisfile.offset, 1);
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
} /* line 5964 */
  sim_icache_fetch(4422 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5966 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 5967 */
l_L253X3: ;/* line 5970 */
__LABEL(l_L253X3);
  sim_icache_fetch(4424 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5971 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5972 */
   __GOTO(l_L270X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L270X3;
} /* line 5973 */
l_L271X3: ;/* line 5976 */
__LABEL(l_L271X3);
  sim_icache_fetch(4427 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5977 */
   __MOV(reg_r0_7, 0); /* line 5978 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5979 */
} /* line 5979 */
  sim_icache_fetch(4431 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5981 */
} /* line 5981 */
  sim_icache_fetch(4432 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5983 */
} /* line 5983 */
l_L245X3: ;/* line 5986 */
__LABEL(l_L245X3);
  sim_icache_fetch(4433 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5987 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5988 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5989 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5990 */
} /* line 5990 */
  sim_icache_fetch(4439 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5992 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5993 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5994 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5995 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5996 */
} /* line 5996 */
  sim_icache_fetch(4447 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 5998 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 5999 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 6000 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 6001 */
} /* line 6001 */
  sim_icache_fetch(4451 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 6003 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 6004 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 6005 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 6006 */
} /* line 6006 */
  sim_icache_fetch(4456 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 6008 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 6009 */
} /* line 6009 */
  sim_icache_fetch(4458 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 6011 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 6012 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 6013 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 6014 */
} /* line 6014 */
  sim_icache_fetch(4462 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 6016 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 6017 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 6018 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6019 */
   __ADD_CYCLES(1);
} /* line 6019 */
  sim_icache_fetch(4467 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 6021 */
} /* line 6021 */
  sim_icache_fetch(4468 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 6023 */
} /* line 6023 */
  sim_icache_fetch(4469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 6026 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6027 */
l_L268X3: ;/* line 6030 */
__LABEL(l_L268X3);
  sim_icache_fetch(4471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6031 */
   __GOTO(l_L269X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L269X3;
} /* line 6032 */
l_L250X3: ;/* line 6035 */
__LABEL(l_L250X3);
  sim_icache_fetch(4473 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 6036 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6037 */
} /* line 6037 */
l_L270X3: ;/* line 6039 */
__LABEL(l_L270X3);
  sim_icache_fetch(4475 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 6040 */
} /* line 6040 */
  sim_icache_fetch(4476 + t_thisfile.offset, 1);
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
} /* line 6042 */
  sim_icache_fetch(4477 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 6045 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 6046 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6047 */
l_L266X3: ;/* line 6050 */
__LABEL(l_L266X3);
  sim_icache_fetch(4482 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6051 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6052 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6053 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6054 */
   __ADD_CYCLES(1);
} /* line 6054 */
  sim_icache_fetch(4488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6056 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6057 */
} /* line 6057 */
  sim_icache_fetch(4490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6059 */
   __GOTO(l_L267X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L267X3;
} /* line 6060 */
l_L264X3: ;/* line 6063 */
__LABEL(l_L264X3);
  sim_icache_fetch(4492 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6064 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6065 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6066 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6067 */
   __ADD_CYCLES(1);
} /* line 6067 */
  sim_icache_fetch(4498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6069 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6070 */
} /* line 6070 */
  sim_icache_fetch(4500 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6072 */
   __GOTO(l_L265X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L265X3;
} /* line 6073 */
l_L262X3: ;/* line 6076 */
__LABEL(l_L262X3);
  sim_icache_fetch(4502 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6077 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6078 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6079 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6080 */
   __ADD_CYCLES(1);
} /* line 6080 */
  sim_icache_fetch(4508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6082 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6083 */
} /* line 6083 */
  sim_icache_fetch(4510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6085 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 6086 */
l_L260X3: ;/* line 6089 */
__LABEL(l_L260X3);
  sim_icache_fetch(4512 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6090 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6091 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6092 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6093 */
   __ADD_CYCLES(1);
} /* line 6093 */
  sim_icache_fetch(4518 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6095 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6096 */
} /* line 6096 */
  sim_icache_fetch(4520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6098 */
   __GOTO(l_L261X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L261X3;
} /* line 6099 */
l_L258X3: ;/* line 6102 */
__LABEL(l_L258X3);
  sim_icache_fetch(4522 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6103 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6104 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6105 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6106 */
   __ADD_CYCLES(1);
} /* line 6106 */
  sim_icache_fetch(4528 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6108 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6109 */
} /* line 6109 */
  sim_icache_fetch(4530 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6111 */
   __GOTO(l_L259X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L259X3;
} /* line 6112 */
l_L256X3: ;/* line 6115 */
__LABEL(l_L256X3);
  sim_icache_fetch(4532 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6116 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6117 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6118 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6119 */
   __ADD_CYCLES(1);
} /* line 6119 */
  sim_icache_fetch(4538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6121 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6122 */
} /* line 6122 */
  sim_icache_fetch(4540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6124 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 6125 */
l_L254X3: ;/* line 6128 */
__LABEL(l_L254X3);
  sim_icache_fetch(4542 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6129 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6130 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6131 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6132 */
   __ADD_CYCLES(1);
} /* line 6132 */
  sim_icache_fetch(4548 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6134 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6135 */
} /* line 6135 */
  sim_icache_fetch(4550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6137 */
   __GOTO(l_L255X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L255X3;
} /* line 6138 */
l_L251X3: ;/* line 6141 */
__LABEL(l_L251X3);
  sim_icache_fetch(4552 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6142 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6143 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6144 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6145 */
} /* line 6145 */
  sim_icache_fetch(4557 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6147 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6148 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6149 */
} /* line 6149 */
  sim_icache_fetch(4560 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6151 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6152 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6153 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6154 */
} /* line 6154 */
  sim_icache_fetch(4564 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6156 */
   __GOTO(l_L252X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L252X3;
} /* line 6157 */
l_L248X3: ;/* line 6160 */
__LABEL(l_L248X3);
  sim_icache_fetch(4566 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6161 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6162 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6163 */
} /* line 6163 */
  sim_icache_fetch(4571 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6165 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6166 */
} /* line 6166 */
  sim_icache_fetch(4575 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6168 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6169 */
   __ADD_CYCLES(1);
} /* line 6169 */
  sim_icache_fetch(4578 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6171 */
} /* line 6171 */
  sim_icache_fetch(4579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6173 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 6174 */
l_L247X3: ;/* line 6177 */
__LABEL(l_L247X3);
  sim_icache_fetch(4581 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6178 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6179 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6180 */
   __ADD_CYCLES(1);
} /* line 6180 */
  sim_icache_fetch(4585 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6182 */
} /* line 6182 */
  sim_icache_fetch(4586 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6184 */
} /* line 6184 */
  sim_icache_fetch(4587 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6186 */
   __GOTO(l_L246X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L246X3;
} /* line 6187 */
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

  sim_icache_fetch(4590 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6209 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6210 */
} /* line 6210 */
		 /* line 6211 */
  sim_icache_fetch(4593 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6214 */
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
} /* line 6214 */
l_lr_346: ;/* line 6214 */
__LABEL(l_lr_346);
  sim_icache_fetch(4596 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6216 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6217 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6218 */
   __ADD_CYCLES(1);
} /* line 6218 */
  sim_icache_fetch(4599 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6221 */
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

  sim_icache_fetch(4600 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6267 */
   __MOV(reg_r0_3, 0); /* line 6268 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6269 */
   __ADD_CYCLES(1);
} /* line 6269 */
  sim_icache_fetch(4604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6271 */
} /* line 6271 */
  sim_icache_fetch(4605 + t_thisfile.offset, 1);
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
} /* line 6273 */
  sim_icache_fetch(4606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6276 */
l_L272X3: ;/* line 6279 */
__LABEL(l_L272X3);
  sim_icache_fetch(4607 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6282 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6282 */
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

  sim_icache_fetch(4609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6298 */
} /* line 6298 */
  sim_icache_fetch(4610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6301 */
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

  sim_icache_fetch(4611 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6316 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6317 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6318 */
} /* line 6318 */
  sim_icache_fetch(4616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6320 */
} /* line 6320 */
  sim_icache_fetch(4617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6322 */
} /* line 6322 */
  sim_icache_fetch(4618 + t_thisfile.offset, 1);
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
} /* line 6324 */
		 /* line 6325 */
  sim_icache_fetch(4619 + t_thisfile.offset, 2);
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
} /* line 6327 */
l_lr_352: ;/* line 6327 */
__LABEL(l_lr_352);
l_L273X3: ;/* line 6329 */
__LABEL(l_L273X3);
  sim_icache_fetch(4621 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6330 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6331 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6332 */
   __ADD_CYCLES(1);
} /* line 6332 */
  sim_icache_fetch(4624 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6335 */
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

  sim_icache_fetch(4625 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6381 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6382 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6383 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6384 */
} /* line 6384 */
  sim_icache_fetch(4632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6386 */
} /* line 6386 */
  sim_icache_fetch(4633 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6388 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6389 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6390 */
} /* line 6390 */
  sim_icache_fetch(4638 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6392 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6393 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6394 */
  sim_icache_fetch(4642 + t_thisfile.offset, 1);
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
} /* line 6396 */
l_L276X3: ;/* line 6399 */
__LABEL(l_L276X3);
  sim_icache_fetch(4643 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6400 */
   __MOV(reg_r0_3, 0); /* line 6401 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6402 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6403 */
   __ADD_CYCLES(1);
} /* line 6403 */
  sim_icache_fetch(4648 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6405 */
} /* line 6405 */
  sim_icache_fetch(4649 + t_thisfile.offset, 1);
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
} /* line 6407 */
  sim_icache_fetch(4650 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6410 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6411 */
l_L277X3: ;/* line 6414 */
__LABEL(l_L277X3);
  sim_icache_fetch(4653 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6415 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6416 */
} /* line 6416 */
		 /* line 6417 */
  sim_icache_fetch(4657 + t_thisfile.offset, 2);
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
} /* line 6419 */
l_lr_358: ;/* line 6419 */
__LABEL(l_lr_358);
  sim_icache_fetch(4659 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6421 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6422 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6423 */
} /* line 6423 */
		 /* line 6424 */
  sim_icache_fetch(4664 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6426 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6427 */
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
} /* line 6428 */
l_lr_360: ;/* line 6428 */
__LABEL(l_lr_360);
  sim_icache_fetch(4670 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6430 */
   __MOV(reg_r0_3, 0); /* line 6431 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6432 */
   __ADD_CYCLES(1);
} /* line 6432 */
  sim_icache_fetch(4673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6435 */
l_L275X3: ;/* line 6438 */
__LABEL(l_L275X3);
  sim_icache_fetch(4674 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6439 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6440 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6441 */
   __ADD_CYCLES(1);
} /* line 6441 */
		 /* line 6442 */
  sim_icache_fetch(4678 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6445 */
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
} /* line 6445 */
l_lr_363: ;/* line 6445 */
__LABEL(l_lr_363);
  sim_icache_fetch(4681 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6447 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6448 */
l_L274X3: ;/* line 6451 */
__LABEL(l_L274X3);
  sim_icache_fetch(4683 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6452 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6453 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6454 */
   __ADD_CYCLES(1);
} /* line 6454 */
		 /* line 6455 */
  sim_icache_fetch(4688 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6457 */
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
} /* line 6458 */
l_lr_366: ;/* line 6458 */
__LABEL(l_lr_366);
  sim_icache_fetch(4691 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6460 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6461 */
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

  sim_icache_fetch(4693 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6480 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6481 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6482 */
} /* line 6482 */
  sim_icache_fetch(4697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6484 */
} /* line 6484 */
l_L278X3: ;/* line 6487 */
__LABEL(l_L278X3);
  sim_icache_fetch(4698 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __MOV(reg_r0_3, reg_r0_2); /* line 6488 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6489 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6490 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6491 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6492 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6493 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6494 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6495 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6496 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6497 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6498 */
} /* line 6498 */
  sim_icache_fetch(4709 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6500 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6501 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6502 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6503 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6504 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6506 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6507 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6508 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6509 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6510 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6511 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6512 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6513 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6514 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6515 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6516 */
  sim_icache_fetch(4726 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(18);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6518 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6519 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6520 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6521 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6522 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6523 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6525 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6527 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6528 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6529 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6531 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6532 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6533 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6534 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6535 */
  sim_icache_fetch(4744 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(18);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6537 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6538 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6539 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6540 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6541 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6542 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6543 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6544 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6545 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6546 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6547 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6548 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6549 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6550 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6551 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6552 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6553 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6554 */
  sim_icache_fetch(4762 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(18);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6556 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6557 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6558 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6559 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6560 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6561 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6562 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6564 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6565 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6567 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6568 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6569 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6570 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6571 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6572 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6573 */
  sim_icache_fetch(4780 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6575 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6576 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6577 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6578 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6579 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6580 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6581 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6582 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6583 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6584 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6588 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6589 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6590 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6591 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6592 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6593 */
  sim_icache_fetch(4799 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6595 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6596 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6597 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6600 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6601 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6602 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6604 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6605 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6606 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6608 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6610 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6611 */
  sim_icache_fetch(4832 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6613 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6614 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6615 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6616 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6617 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6620 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6621 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6622 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6623 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6624 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6625 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6626 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6627 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6628 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6629 */
  sim_icache_fetch(4865 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6631 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6632 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6633 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6634 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6635 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6636 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6637 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6639 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6640 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6641 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6642 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6644 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6645 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6646 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6647 */
  sim_icache_fetch(4898 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6651 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6652 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6653 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6654 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6655 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6656 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6658 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6659 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6660 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6661 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6662 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6664 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L287X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6665 */
  sim_icache_fetch(4931 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6667 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6668 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6669 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6670 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6671 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6672 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6673 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6674 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6675 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6676 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6677 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6678 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6679 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6680 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6681 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6682 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6683 */
  sim_icache_fetch(4964 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6685 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6686 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6687 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6688 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6689 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6690 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6691 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6692 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6693 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6694 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6695 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6696 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6697 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6698 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6699 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6700 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6701 */
  sim_icache_fetch(4997 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6703 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6704 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6705 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6706 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6707 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6708 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6709 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6710 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6711 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6712 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6713 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6714 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6715 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6716 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6717 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6718 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6719 */
  sim_icache_fetch(5030 + t_thisfile.offset, 37);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6721 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6722 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6723 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6724 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6725 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6726 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6727 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6728 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6729 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6730 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6731 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6732 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6733 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6734 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6735 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6736 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6737 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6738 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6739 */
} /* line 6739 */
  sim_icache_fetch(5067 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6741 */
} /* line 6741 */
  sim_icache_fetch(5068 + t_thisfile.offset, 1);
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
} /* line 6744 */
  sim_icache_fetch(5069 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L278X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L278X3;
} /* line 6746 */
l_L291X3: ;/* line 6749 */
__LABEL(l_L291X3);
  sim_icache_fetch(5070 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6750 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6751 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6752 */
l_L293X3: ;/* line 6755 */
__LABEL(l_L293X3);
  sim_icache_fetch(5074 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6756 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6757 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6758 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6759 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 4); /* line 6760 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 5); /* line 6761 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 6); /* line 6762 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 7); /* line 6763 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6764 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6765 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6766 */
} /* line 6766 */
  sim_icache_fetch(5085 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 6768 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6769 */
  sim_icache_fetch(5087 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6771 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6772 */
  sim_icache_fetch(5089 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6774 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6775 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6776 */
  sim_icache_fetch(5092 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6778 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6779 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6780 */
  sim_icache_fetch(5095 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6782 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6783 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6784 */
  sim_icache_fetch(5098 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6786 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 12); /* line 6787 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6788 */
  sim_icache_fetch(5101 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6790 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 13); /* line 6791 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6792 */
  sim_icache_fetch(5104 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6794 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 14); /* line 6795 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6796 */
  sim_icache_fetch(5107 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6798 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 15); /* line 6799 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6800 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6801 */
  sim_icache_fetch(5111 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6803 */
   __CMPGT(reg_b0_0, reg_r0_5, 0); /* line 6804 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6805 */
  sim_icache_fetch(5114 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6807 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6808 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6809 */
  sim_icache_fetch(5117 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6811 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6812 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6813 */
  sim_icache_fetch(5120 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6815 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6816 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6817 */
  sim_icache_fetch(5123 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6819 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 4); /* line 6820 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6821 */
  sim_icache_fetch(5126 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6823 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 5); /* line 6824 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6825 */
  sim_icache_fetch(5129 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6827 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 6); /* line 6828 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6829 */
  sim_icache_fetch(5132 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6831 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 7); /* line 6832 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6833 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6834 */
  sim_icache_fetch(5136 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6836 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 8); /* line 6837 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6838 */
  sim_icache_fetch(5139 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6840 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6841 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6842 */
  sim_icache_fetch(5142 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6844 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6845 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6846 */
  sim_icache_fetch(5145 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6848 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6849 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6850 */
  sim_icache_fetch(5148 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6852 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 12); /* line 6853 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6854 */
  sim_icache_fetch(5151 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6856 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 13); /* line 6857 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6858 */
  sim_icache_fetch(5154 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6860 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 14); /* line 6861 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6862 */
  sim_icache_fetch(5157 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6864 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 15); /* line 6865 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6866 */
  sim_icache_fetch(5160 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6868 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6869 */
  sim_icache_fetch(5162 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6871 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6872 */
  sim_icache_fetch(5164 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6874 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6875 */
  sim_icache_fetch(5166 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6877 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6878 */
  sim_icache_fetch(5168 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6880 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6881 */
  sim_icache_fetch(5170 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6883 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6884 */
  sim_icache_fetch(5172 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6886 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6887 */
  sim_icache_fetch(5174 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6889 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6890 */
l_L294X3: ;/* line 6893 */
__LABEL(l_L294X3);
  sim_icache_fetch(5176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6895 */
l_L290X3: ;/* line 6898 */
__LABEL(l_L290X3);
  sim_icache_fetch(5177 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6899 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6900 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6901 */
l_L289X3: ;/* line 6904 */
__LABEL(l_L289X3);
  sim_icache_fetch(5181 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6905 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6906 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6907 */
l_L288X3: ;/* line 6910 */
__LABEL(l_L288X3);
  sim_icache_fetch(5185 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6911 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6912 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6913 */
l_L287X3: ;/* line 6916 */
__LABEL(l_L287X3);
  sim_icache_fetch(5189 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6917 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6918 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6919 */
l_L286X3: ;/* line 6922 */
__LABEL(l_L286X3);
  sim_icache_fetch(5193 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6923 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6924 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6925 */
l_L285X3: ;/* line 6928 */
__LABEL(l_L285X3);
  sim_icache_fetch(5197 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6929 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6930 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6931 */
l_L284X3: ;/* line 6934 */
__LABEL(l_L284X3);
  sim_icache_fetch(5201 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6935 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6936 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6937 */
l_L283X3: ;/* line 6940 */
__LABEL(l_L283X3);
  sim_icache_fetch(5205 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6941 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6942 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6943 */
l_L282X3: ;/* line 6946 */
__LABEL(l_L282X3);
  sim_icache_fetch(5209 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6947 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6948 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6949 */
l_L281X3: ;/* line 6952 */
__LABEL(l_L281X3);
  sim_icache_fetch(5212 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6953 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6954 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6955 */
l_L280X3: ;/* line 6958 */
__LABEL(l_L280X3);
  sim_icache_fetch(5215 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6959 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6960 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6961 */
l_L279X3: ;/* line 6964 */
__LABEL(l_L279X3);
  sim_icache_fetch(5218 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6965 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6966 */
} /* line 6966 */
l_L292X3: ;/* line 6968 */
__LABEL(l_L292X3);
  sim_icache_fetch(5220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6969 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6970 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6971 */
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

  sim_icache_fetch(5223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6987 */
} /* line 6987 */
  sim_icache_fetch(5224 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6990 */
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

  sim_icache_fetch(5225 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7006 */
} /* line 7006 */
  sim_icache_fetch(5226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7009 */
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


static sim_fileinfo_t t_thisfile = {"compress.s", 5232, 0, 0, 0, 2};

