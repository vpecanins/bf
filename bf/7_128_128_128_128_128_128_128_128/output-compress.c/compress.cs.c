/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/7_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_10939Xoffset[1];
unsigned int compress_10939Xbuf[3];
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
unsigned int compress_10939XBuf[216]; 
unsigned int compress_10939Xrcs_ident[6]; 
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

unsigned int compress_10939XBuf[216] = { 
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

unsigned int compress_10939Xrcs_ident[6] = { 
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
   __MOV(reg_r0_5, (unsigned int) compress_10939XBuf); /* line 35 */
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
  reg_l0_0 = (145 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_26, reg_r0_3, (unsigned int) 15); /* line 178 */
   __ADD(reg_r0_25, reg_r0_3, (unsigned int) 14); /* line 179 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 13); /* line 180 */
   __ADD(reg_r0_23, reg_r0_3, (unsigned int) 12); /* line 181 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 11); /* line 182 */
   __ADD(reg_r0_21, reg_r0_3, (unsigned int) 10); /* line 183 */
} /* line 183 */
  sim_icache_fetch(50 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 185 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 9); /* line 186 */
   __ADD(reg_r0_19, reg_r0_3, (unsigned int) 8); /* line 187 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 7); /* line 188 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 6); /* line 189 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 190 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 191 */
} /* line 191 */
  sim_icache_fetch(57 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SXTB(reg_r0_4, reg_r0_4); /* line 193 */
   __MOV(reg_r0_5, 0); /* line 194 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 195 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 196 */
   __MOV(reg_r0_2, reg_r0_3); /* line 197 */
} /* line 197 */
l_L0X3: ;/* line 200 */
__LABEL(l_L0X3);
  sim_icache_fetch(62 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 201 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 202 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 203 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_10,0,1)); /* line 204 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_12,0,1)); /* line 205 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_14,0,1)); /* line 206 */
   __LDBs(reg_r0_17, mem_trace_ld(reg_r0_16,0,1)); /* line 207 */
} /* line 207 */
  sim_icache_fetch(69 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDBs(reg_r0_27, mem_trace_ld(reg_r0_18,0,1)); /* line 209 */
   __LDBs(reg_r0_28, mem_trace_ld(reg_r0_19,0,1)); /* line 210 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_20,0,1)); /* line 211 */
   __LDBs(reg_r0_30, mem_trace_ld(reg_r0_21,0,1)); /* line 212 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_22,0,1)); /* line 213 */
   __LDBs(reg_r0_32, mem_trace_ld(reg_r0_23,0,1)); /* line 214 */
   __LDBs(reg_r0_33, mem_trace_ld(reg_r0_24,0,1)); /* line 215 */
} /* line 215 */
  sim_icache_fetch(76 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 217 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 218 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 219 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 220 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 221 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 222 */
   __CMPNE(reg_b0_6, reg_r0_11, 0); /* line 223 */
} /* line 223 */
  sim_icache_fetch(83 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 225 */
   __CMPEQ(reg_b0_0, reg_r0_11, reg_r0_4); /* line 226 */
   __CMPNE(reg_b0_1, reg_r0_13, 0); /* line 227 */
   __CMPEQ(reg_b0_7, reg_r0_13, reg_r0_4); /* line 228 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_25,0,1)); /* line 229 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_26,0,1)); /* line 230 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 231 */
  sim_icache_fetch(90 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_11, reg_b0_3, reg_r0_6, reg_r0_3); /* line 233 */
   __CMPNE(reg_b0_2, reg_r0_15, 0); /* line 234 */
   __CMPEQ(reg_b0_3, reg_r0_15, reg_r0_4); /* line 235 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 236 */
   __ADD(reg_r0_13, reg_r0_25, (unsigned int) 16); /* line 237 */
   __ADD(reg_r0_15, reg_r0_24, (unsigned int) 16); /* line 238 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 239 */
  sim_icache_fetch(97 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_3, reg_b0_5, reg_r0_8, reg_r0_11); /* line 241 */
   __CMPNE(reg_b0_4, reg_r0_17, 0); /* line 242 */
   __CMPEQ(reg_b0_5, reg_r0_17, reg_r0_4); /* line 243 */
   __ADD(reg_r0_17, reg_r0_23, (unsigned int) 16); /* line 244 */
   __ADD(reg_r0_34, reg_r0_22, (unsigned int) 16); /* line 245 */
   __ADD(reg_r0_35, reg_r0_21, (unsigned int) 16); /* line 246 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 247 */
  sim_icache_fetch(104 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_10, reg_r0_3); /* line 249 */
   __CMPNE(reg_b0_0, reg_r0_27, 0); /* line 250 */
   __CMPEQ(reg_b0_6, reg_r0_27, reg_r0_4); /* line 251 */
   __ADD(reg_r0_27, reg_r0_20, (unsigned int) 16); /* line 252 */
   __ADD(reg_r0_36, reg_r0_19, (unsigned int) 16); /* line 253 */
   __ADD(reg_r0_37, reg_r0_18, (unsigned int) 16); /* line 254 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 255 */
  sim_icache_fetch(111 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_3, reg_b0_7, reg_r0_12, reg_r0_11); /* line 257 */
   __CMPNE(reg_b0_1, reg_r0_28, 0); /* line 258 */
   __CMPEQ(reg_b0_7, reg_r0_28, reg_r0_4); /* line 259 */
   __ADD(reg_r0_28, reg_r0_16, (unsigned int) 16); /* line 260 */
   __ADD(reg_r0_38, reg_r0_14, (unsigned int) 16); /* line 261 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 262 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 263 */
  sim_icache_fetch(118 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_14, reg_b0_3, reg_r0_14, reg_r0_3); /* line 265 */
   __CMPNE(reg_b0_2, reg_r0_29, 0); /* line 266 */
   __CMPEQ(reg_b0_3, reg_r0_29, reg_r0_4); /* line 267 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 268 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 269 */
   __ADD(reg_r0_11, reg_r0_26, (unsigned int) 16); /* line 270 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 271 */
  sim_icache_fetch(125 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_16, reg_b0_5, reg_r0_16, reg_r0_14); /* line 273 */
   __CMPNE(reg_b0_4, reg_r0_30, 0); /* line 274 */
   __CMPEQ(reg_b0_5, reg_r0_30, reg_r0_4); /* line 275 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 276 */
   __LDBs(reg_r0_3, mem_trace_ld(reg_r0_6,0,1)); /* line 277 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_8,0,1)); /* line 278 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 279 */
  sim_icache_fetch(132 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_18, reg_b0_6, reg_r0_18, reg_r0_16); /* line 281 */
   __CMPNE(reg_b0_0, reg_r0_31, 0); /* line 282 */
   __CMPEQ(reg_b0_6, reg_r0_31, reg_r0_4); /* line 283 */
   __LDBs(reg_r0_30, mem_trace_ld(reg_r0_2,0,1)); /* line 284 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_10,0,1)); /* line 285 */
   __LDBs(reg_r0_39, mem_trace_ld(reg_r0_12,0,1)); /* line 286 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 287 */
  sim_icache_fetch(139 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_19, reg_b0_7, reg_r0_19, reg_r0_18); /* line 289 */
   __CMPNE(reg_b0_1, reg_r0_32, 0); /* line 290 */
   __CMPEQ(reg_b0_7, reg_r0_32, reg_r0_4); /* line 291 */
   __LDBs(reg_r0_32, mem_trace_ld(reg_r0_38,0,1)); /* line 292 */
   __LDBs(reg_r0_40, mem_trace_ld(reg_r0_28,0,1)); /* line 293 */
   __LDBs(reg_r0_41, mem_trace_ld(reg_r0_37,0,1)); /* line 294 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 295 */
  sim_icache_fetch(146 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_20, reg_b0_3, reg_r0_20, reg_r0_19); /* line 297 */
   __CMPNE(reg_b0_2, reg_r0_33, 0); /* line 298 */
   __CMPEQ(reg_b0_3, reg_r0_33, reg_r0_4); /* line 299 */
   __LDBs(reg_r0_33, mem_trace_ld(reg_r0_36,0,1)); /* line 300 */
   __LDBs(reg_r0_42, mem_trace_ld(reg_r0_27,0,1)); /* line 301 */
   __LDBs(reg_r0_43, mem_trace_ld(reg_r0_35,0,1)); /* line 302 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 303 */
  sim_icache_fetch(153 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_21, reg_b0_5, reg_r0_21, reg_r0_20); /* line 305 */
   __CMPNE(reg_b0_4, reg_r0_7, 0); /* line 306 */
   __CMPEQ(reg_b0_5, reg_r0_7, reg_r0_4); /* line 307 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_34,0,1)); /* line 308 */
   __LDBs(reg_r0_44, mem_trace_ld(reg_r0_17,0,1)); /* line 309 */
   __LDBs(reg_r0_45, mem_trace_ld(reg_r0_15,0,1)); /* line 310 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 311 */
  sim_icache_fetch(160 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_22, reg_b0_6, reg_r0_22, reg_r0_21); /* line 313 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 314 */
   __CMPEQ(reg_b0_6, reg_r0_9, reg_r0_4); /* line 315 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_13,0,1)); /* line 316 */
   __LDBs(reg_r0_46, mem_trace_ld(reg_r0_11,0,1)); /* line 317 */
   __ADD(reg_r0_47, reg_r0_8, (unsigned int) 16); /* line 318 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 319 */
  sim_icache_fetch(167 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_23, reg_b0_7, reg_r0_23, reg_r0_22); /* line 321 */
   __CMPNE(reg_b0_1, reg_r0_30, 0); /* line 322 */
   __CMPEQ(reg_b0_7, reg_r0_30, reg_r0_4); /* line 323 */
   __ADD(reg_r0_20, reg_r0_27, (unsigned int) 16); /* line 324 */
   __ADD(reg_r0_14, reg_r0_38, (unsigned int) 16); /* line 325 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) 16); /* line 326 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 327 */
  sim_icache_fetch(174 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_24, reg_b0_3, reg_r0_24, reg_r0_23); /* line 329 */
   __CMPNE(reg_b0_2, reg_r0_3, 0); /* line 330 */
   __CMPEQ(reg_b0_3, reg_r0_3, reg_r0_4); /* line 331 */
   __ADD(reg_r0_22, reg_r0_34, (unsigned int) 16); /* line 332 */
   __ADD(reg_r0_21, reg_r0_35, (unsigned int) 16); /* line 333 */
   __ADD(reg_r0_16, reg_r0_28, (unsigned int) 16); /* line 334 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 335 */
  sim_icache_fetch(181 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_25, reg_b0_5, reg_r0_25, reg_r0_24); /* line 337 */
   __CMPNE(reg_b0_4, reg_r0_29, 0); /* line 338 */
   __CMPEQ(reg_b0_5, reg_r0_29, reg_r0_4); /* line 339 */
   __ADD(reg_r0_19, reg_r0_36, (unsigned int) 16); /* line 340 */
   __ADD(reg_r0_18, reg_r0_37, (unsigned int) 16); /* line 341 */
   __ADD(reg_r0_3, reg_r0_10, (unsigned int) 16); /* line 342 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 343 */
  sim_icache_fetch(188 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_5, reg_b0_6, reg_r0_26, reg_r0_25); /* line 345 */
   __CMPNE(reg_b0_0, reg_r0_31, 0); /* line 346 */
   __CMPEQ(reg_b0_6, reg_r0_31, reg_r0_4); /* line 347 */
   __ADD(reg_r0_24, reg_r0_15, (unsigned int) 16); /* line 348 */
   __ADD(reg_r0_23, reg_r0_17, (unsigned int) 16); /* line 349 */
   __ADD(reg_r0_26, reg_r0_11, (unsigned int) 16); /* line 350 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 351 */
  sim_icache_fetch(195 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_29, reg_b0_7, reg_r0_2, reg_r0_5); /* line 353 */
   __CMPNE(reg_b0_1, reg_r0_39, 0); /* line 354 */
   __CMPEQ(reg_b0_7, reg_r0_39, reg_r0_4); /* line 355 */
   __ADD(reg_r0_31, reg_r0_6, (unsigned int) 16); /* line 356 */
   __ADD(reg_r0_25, reg_r0_13, (unsigned int) 16); /* line 357 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 358 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 359 */
  sim_icache_fetch(202 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_6, reg_b0_3, reg_r0_6, reg_r0_29); /* line 361 */
   __CMPNE(reg_b0_2, reg_r0_32, 0); /* line 362 */
   __CMPEQ(reg_b0_3, reg_r0_32, reg_r0_4); /* line 363 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 364 */
  sim_icache_fetch(206 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_8, reg_b0_5, reg_r0_8, reg_r0_6); /* line 366 */
   __CMPNE(reg_b0_4, reg_r0_40, 0); /* line 367 */
   __CMPEQ(reg_b0_5, reg_r0_40, reg_r0_4); /* line 368 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 369 */
  sim_icache_fetch(210 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_10, reg_b0_6, reg_r0_10, reg_r0_8); /* line 371 */
   __CMPNE(reg_b0_0, reg_r0_41, 0); /* line 372 */
   __CMPEQ(reg_b0_6, reg_r0_41, reg_r0_4); /* line 373 */
   __MOV(reg_r0_6, reg_r0_31); /* line 374 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 375 */
  sim_icache_fetch(215 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_12, reg_b0_7, reg_r0_12, reg_r0_10); /* line 377 */
   __CMPNE(reg_b0_1, reg_r0_33, 0); /* line 378 */
   __CMPEQ(reg_b0_7, reg_r0_33, reg_r0_4); /* line 379 */
   __MOV(reg_r0_8, reg_r0_47); /* line 380 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 381 */
  sim_icache_fetch(220 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_38, reg_b0_3, reg_r0_38, reg_r0_12); /* line 383 */
   __CMPNE(reg_b0_2, reg_r0_42, 0); /* line 384 */
   __CMPEQ(reg_b0_3, reg_r0_42, reg_r0_4); /* line 385 */
   __MOV(reg_r0_10, reg_r0_3); /* line 386 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 387 */
  sim_icache_fetch(225 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_28, reg_b0_5, reg_r0_28, reg_r0_38); /* line 389 */
   __CMPNE(reg_b0_4, reg_r0_43, 0); /* line 390 */
   __CMPEQ(reg_b0_5, reg_r0_43, reg_r0_4); /* line 391 */
   __MOV(reg_r0_12, reg_r0_30); /* line 392 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 393 */
  sim_icache_fetch(230 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_37, reg_b0_6, reg_r0_37, reg_r0_28); /* line 395 */
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 396 */
   __CMPEQ(reg_b0_6, reg_r0_7, reg_r0_4); /* line 397 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 398 */
  sim_icache_fetch(234 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_36, reg_b0_7, reg_r0_36, reg_r0_37); /* line 400 */
   __CMPNE(reg_b0_1, reg_r0_44, 0); /* line 401 */
   __CMPEQ(reg_b0_7, reg_r0_44, reg_r0_4); /* line 402 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 403 */
  sim_icache_fetch(238 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_27, reg_b0_3, reg_r0_27, reg_r0_36); /* line 405 */
   __CMPNE(reg_b0_2, reg_r0_45, 0); /* line 406 */
   __CMPEQ(reg_b0_3, reg_r0_45, reg_r0_4); /* line 407 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 408 */
  sim_icache_fetch(242 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_35, reg_b0_5, reg_r0_35, reg_r0_27); /* line 410 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 411 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 412 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 413 */
  sim_icache_fetch(246 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_34, reg_b0_6, reg_r0_34, reg_r0_35); /* line 415 */
   __CMPNE(reg_b0_0, reg_r0_46, 0); /* line 416 */
   __CMPEQ(reg_b0_6, reg_r0_46, reg_r0_4); /* line 417 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 418 */
  sim_icache_fetch(250 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_17, reg_b0_7, reg_r0_17, reg_r0_34); /* line 420 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 421 */
  sim_icache_fetch(252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_15, reg_b0_3, reg_r0_15, reg_r0_17); /* line 423 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 424 */
  sim_icache_fetch(254 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_13, reg_b0_5, reg_r0_13, reg_r0_15); /* line 426 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 427 */
  sim_icache_fetch(256 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_6, reg_r0_11, reg_r0_13); /* line 429 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 431 */
  sim_icache_fetch(258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 433 */
l_L32X3: ;/* line 436 */
__LABEL(l_L32X3);
  sim_icache_fetch(259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_25, reg_r0_13); /* line 437 */
} /* line 437 */
l_L16X3: ;/* line 440 */
__LABEL(l_L16X3);
  sim_icache_fetch(260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_25); /* line 442 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 443 */
l_L31X3: ;/* line 446 */
__LABEL(l_L31X3);
  sim_icache_fetch(262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_24, reg_r0_15); /* line 447 */
} /* line 447 */
l_L15X3: ;/* line 450 */
__LABEL(l_L15X3);
  sim_icache_fetch(263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_24); /* line 452 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 453 */
l_L30X3: ;/* line 456 */
__LABEL(l_L30X3);
  sim_icache_fetch(265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_23, reg_r0_17); /* line 457 */
} /* line 457 */
l_L14X3: ;/* line 460 */
__LABEL(l_L14X3);
  sim_icache_fetch(266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_23); /* line 462 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 463 */
l_L29X3: ;/* line 466 */
__LABEL(l_L29X3);
  sim_icache_fetch(268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_34); /* line 467 */
} /* line 467 */
l_L13X3: ;/* line 470 */
__LABEL(l_L13X3);
  sim_icache_fetch(269 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_22); /* line 472 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 473 */
l_L28X3: ;/* line 476 */
__LABEL(l_L28X3);
  sim_icache_fetch(271 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_35); /* line 478 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 479 */
l_L27X3: ;/* line 482 */
__LABEL(l_L27X3);
  sim_icache_fetch(273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_27); /* line 484 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 485 */
l_L26X3: ;/* line 488 */
__LABEL(l_L26X3);
  sim_icache_fetch(275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_36); /* line 490 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 491 */
l_L25X3: ;/* line 494 */
__LABEL(l_L25X3);
  sim_icache_fetch(277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_37); /* line 496 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 497 */
l_L24X3: ;/* line 500 */
__LABEL(l_L24X3);
  sim_icache_fetch(279 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_28); /* line 502 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 503 */
l_L23X3: ;/* line 506 */
__LABEL(l_L23X3);
  sim_icache_fetch(281 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, reg_r0_38); /* line 507 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 508 */
l_L22X3: ;/* line 511 */
__LABEL(l_L22X3);
  sim_icache_fetch(283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_12); /* line 512 */
} /* line 512 */
l_L6X3: ;/* line 515 */
__LABEL(l_L6X3);
  sim_icache_fetch(284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 518 */
l_L21X3: ;/* line 521 */
__LABEL(l_L21X3);
  sim_icache_fetch(285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_11, reg_r0_10); /* line 522 */
} /* line 522 */
l_L5X3: ;/* line 525 */
__LABEL(l_L5X3);
  sim_icache_fetch(286 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_11); /* line 527 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 528 */
l_L20X3: ;/* line 531 */
__LABEL(l_L20X3);
  sim_icache_fetch(288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_8); /* line 532 */
} /* line 532 */
l_L4X3: ;/* line 535 */
__LABEL(l_L4X3);
  sim_icache_fetch(289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 538 */
l_L19X3: ;/* line 541 */
__LABEL(l_L19X3);
  sim_icache_fetch(290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_11, reg_r0_6); /* line 542 */
} /* line 542 */
l_L3X3: ;/* line 545 */
__LABEL(l_L3X3);
  sim_icache_fetch(291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_11); /* line 547 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 548 */
l_L18X3: ;/* line 551 */
__LABEL(l_L18X3);
  sim_icache_fetch(293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_29); /* line 552 */
} /* line 552 */
l_L2X3: ;/* line 555 */
__LABEL(l_L2X3);
  sim_icache_fetch(294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 558 */
l_L17X3: ;/* line 561 */
__LABEL(l_L17X3);
  sim_icache_fetch(295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 563 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 564 */
l_L12X3: ;/* line 567 */
__LABEL(l_L12X3);
  sim_icache_fetch(297 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_21); /* line 569 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 570 */
l_L11X3: ;/* line 573 */
__LABEL(l_L11X3);
  sim_icache_fetch(299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_20); /* line 575 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 576 */
l_L10X3: ;/* line 579 */
__LABEL(l_L10X3);
  sim_icache_fetch(301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_19); /* line 581 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 582 */
l_L9X3: ;/* line 585 */
__LABEL(l_L9X3);
  sim_icache_fetch(303 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_18); /* line 587 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 588 */
l_L8X3: ;/* line 591 */
__LABEL(l_L8X3);
  sim_icache_fetch(305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_16); /* line 593 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 594 */
l_L7X3: ;/* line 597 */
__LABEL(l_L7X3);
  sim_icache_fetch(307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 597 */
l_L33X3: ;/* line 599 */
__LABEL(l_L33X3);
  sim_icache_fetch(308 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_14); /* line 601 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 602 */
l_L1X3: ;/* line 605 */
__LABEL(l_L1X3);
  sim_icache_fetch(310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 607 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 608 */
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
    case 121: goto l_L27X3;
    case 122: goto l_L26X3;
    case 123: goto l_L25X3;
    case 124: goto l_L24X3;
    case 125: goto l_L23X3;
    case 126: goto l_L22X3;
    case 127: goto l_L6X3;
    case 128: goto l_L21X3;
    case 129: goto l_L5X3;
    case 130: goto l_L20X3;
    case 131: goto l_L4X3;
    case 132: goto l_L19X3;
    case 133: goto l_L3X3;
    case 134: goto l_L18X3;
    case 135: goto l_L2X3;
    case 136: goto l_L17X3;
    case 137: goto l_L12X3;
    case 138: goto l_L11X3;
    case 139: goto l_L10X3;
    case 140: goto l_L9X3;
    case 141: goto l_L8X3;
    case 142: goto l_L7X3;
    case 143: goto l_L33X3;
    case 144: goto l_L1X3;
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

  sim_icache_fetch(312 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 624 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 625 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 626 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 627 */
} /* line 627 */
  sim_icache_fetch(319 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 629 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 630 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 631 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 632 */
} /* line 632 */
  sim_icache_fetch(324 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 634 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 635 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 636 */
} /* line 636 */
		 /* line 637 */
  sim_icache_fetch(327 + t_thisfile.offset, 2);
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
} /* line 639 */
l_lr_46: ;/* line 639 */
__LABEL(l_lr_46);
  sim_icache_fetch(329 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 641 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 642 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 643 */
   __ADD_CYCLES(1);
} /* line 643 */
  sim_icache_fetch(332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 645 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 646 */
} /* line 646 */
l_L34X3: ;/* line 649 */
__LABEL(l_L34X3);
  sim_icache_fetch(334 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 650 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 651 */
} /* line 651 */
  sim_icache_fetch(336 + t_thisfile.offset, 1);
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
} /* line 653 */
  sim_icache_fetch(337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 655 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 656 */
   __ADD_CYCLES(1);
} /* line 656 */
  sim_icache_fetch(339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 658 */
} /* line 658 */
  sim_icache_fetch(340 + t_thisfile.offset, 1);
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
} /* line 660 */
l_L37X3: ;/* line 663 */
__LABEL(l_L37X3);
  sim_icache_fetch(341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 664 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 665 */
   __ADD_CYCLES(1);
} /* line 665 */
  sim_icache_fetch(343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 667 */
} /* line 667 */
  sim_icache_fetch(344 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 669 */
} /* line 669 */
  sim_icache_fetch(345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 671 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 672 */
   __ADD_CYCLES(1);
} /* line 672 */
  sim_icache_fetch(347 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 674 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 675 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 676 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 677 */
} /* line 677 */
  sim_icache_fetch(352 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 679 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 680 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 681 */
  sim_icache_fetch(355 + t_thisfile.offset, 1);
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
} /* line 683 */
  sim_icache_fetch(356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 684 */
  sim_icache_fetch(357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 686 */
l__X1XCompressXTAGX0X0: ;/* line 688 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(358 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 689 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 690 */
l__X1XCompressXTAGX0X7: ;/* line 693 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(361 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 694 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 695 */
l__X1XCompressXTAGX0X6: ;/* line 698 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 699 */
} /* line 699 */
  sim_icache_fetch(365 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 701 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 702 */
l__X1XCompressXTAGX0X5: ;/* line 705 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 706 */
} /* line 706 */
  sim_icache_fetch(369 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 708 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 709 */
l__X1XCompressXTAGX0X4: ;/* line 712 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(372 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 713 */
} /* line 713 */
  sim_icache_fetch(373 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 715 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 716 */
l__X1XCompressXTAGX0X3: ;/* line 719 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(376 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 720 */
} /* line 720 */
  sim_icache_fetch(377 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 722 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 723 */
l__X1XCompressXTAGX0X2: ;/* line 726 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 727 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 728 */
   __ADD_CYCLES(1);
} /* line 728 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 730 */
} /* line 730 */
  sim_icache_fetch(383 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 732 */
} /* line 732 */
  sim_icache_fetch(384 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 734 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 735 */
   __ADD_CYCLES(1);
} /* line 735 */
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 737 */
} /* line 737 */
  sim_icache_fetch(387 + t_thisfile.offset, 1);
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
} /* line 739 */
l_L36X3: ;/* line 741 */
__LABEL(l_L36X3);
  sim_icache_fetch(388 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 742 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 743 */
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 744 */
l_L40X3: ;/* line 747 */
__LABEL(l_L40X3);
  sim_icache_fetch(391 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 748 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 749 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 750 */
} /* line 750 */
  sim_icache_fetch(394 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 752 */
} /* line 752 */
  sim_icache_fetch(395 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 754 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 755 */
  sim_icache_fetch(397 + t_thisfile.offset, 1);
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
} /* line 758 */
  sim_icache_fetch(398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 760 */
l_L41X3: ;/* line 763 */
__LABEL(l_L41X3);
		 /* line 763 */
  sim_icache_fetch(399 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 766 */
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
} /* line 766 */
l_lr_60: ;/* line 766 */
__LABEL(l_lr_60);
		 /* line 767 */
  sim_icache_fetch(403 + t_thisfile.offset, 2);
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
} /* line 769 */
l_lr_62: ;/* line 769 */
__LABEL(l_lr_62);
  sim_icache_fetch(405 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 771 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 772 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 773 */
   __ADD_CYCLES(1);
} /* line 773 */
  sim_icache_fetch(408 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 776 */
l__X1XCompressXTAGX0X1: ;/* line 779 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 779 */
  sim_icache_fetch(409 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 782 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 783 */
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
} /* line 783 */
l_lr_65: ;/* line 783 */
__LABEL(l_lr_65);
  sim_icache_fetch(413 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 785 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 786 */
} /* line 786 */
  sim_icache_fetch(415 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 788 */
l_L39X3: ;/* line 791 */
__LABEL(l_L39X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 792 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 792 */
  sim_icache_fetch(416 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 795 */
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
} /* line 795 */
l_lr_69: ;/* line 795 */
__LABEL(l_lr_69);
		 /* line 796 */
  sim_icache_fetch(420 + t_thisfile.offset, 2);
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
} /* line 798 */
l_lr_71: ;/* line 798 */
__LABEL(l_lr_71);
  sim_icache_fetch(422 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 800 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 801 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 802 */
   __ADD_CYCLES(1);
} /* line 802 */
  sim_icache_fetch(425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 805 */
l_L38X3: ;/* line 808 */
__LABEL(l_L38X3);
  sim_icache_fetch(426 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 809 */
l_L35X3: ;/* line 812 */
__LABEL(l_L35X3);
  sim_icache_fetch(427 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 813 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 814 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 815 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 816 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 817 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 818 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 819 */
   __ADD_CYCLES(1);
} /* line 819 */
  sim_icache_fetch(437 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 821 */
   __CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 4096); /* line 822 */
} /* line 822 */
  sim_icache_fetch(440 + t_thisfile.offset, 1);
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
} /* line 824 */
  sim_icache_fetch(441 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 826 */
} /* line 826 */
l_L43X3: ;/* line 828 */
__LABEL(l_L43X3);
  sim_icache_fetch(443 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 829 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 830 */
   __ADD_CYCLES(1);
} /* line 830 */
  sim_icache_fetch(446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 832 */
} /* line 832 */
  sim_icache_fetch(447 + t_thisfile.offset, 1);
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
} /* line 834 */
  sim_icache_fetch(448 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 836 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 837 */
} /* line 837 */
l_L45X3: ;/* line 839 */
__LABEL(l_L45X3);
  sim_icache_fetch(452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 840 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 841 */
   __ADD_CYCLES(1);
} /* line 841 */
  sim_icache_fetch(455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 843 */
} /* line 843 */
  sim_icache_fetch(456 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 845 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L46X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 846 */
		 /* line 847 */
  sim_icache_fetch(459 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 849 */
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
} /* line 850 */
l_lr_77: ;/* line 850 */
__LABEL(l_lr_77);
l_L47X3: ;/* line 852 */
__LABEL(l_L47X3);
  sim_icache_fetch(463 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 853 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 854 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 855 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 856 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 857 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 858 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 859 */
} /* line 859 */
  sim_icache_fetch(477 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 861 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 862 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 863 */
} /* line 863 */
  sim_icache_fetch(483 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 865 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 866 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 867 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 868 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 869 */
} /* line 869 */
  sim_icache_fetch(489 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 871 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 872 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 873 */
  sim_icache_fetch(492 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 875 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 876 */
  sim_icache_fetch(495 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 878 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 879 */
l_L51X3: ;/* line 881 */
__LABEL(l_L51X3);
		 /* line 881 */
  sim_icache_fetch(498 + t_thisfile.offset, 2);
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
} /* line 883 */
l_lr_81: ;/* line 883 */
__LABEL(l_lr_81);
  sim_icache_fetch(500 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 885 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 886 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 887 */
   __ADD_CYCLES(1);
} /* line 887 */
  sim_icache_fetch(503 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 890 */
l_L50X3: ;/* line 893 */
__LABEL(l_L50X3);
  sim_icache_fetch(504 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 894 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 895 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 896 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 897 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 898 */
   __ADD_CYCLES(1);
} /* line 898 */
  sim_icache_fetch(513 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 900 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 901 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 902 */
} /* line 902 */
  sim_icache_fetch(516 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 904 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 905 */
} /* line 905 */
  sim_icache_fetch(519 + t_thisfile.offset, 1);
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
} /* line 907 */
  sim_icache_fetch(520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 909 */
} /* line 909 */
  sim_icache_fetch(522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 911 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 912 */
   __ADD_CYCLES(1);
} /* line 912 */
  sim_icache_fetch(524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 914 */
} /* line 914 */
l_L53X3: ;/* line 916 */
__LABEL(l_L53X3);
  sim_icache_fetch(525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 917 */
} /* line 917 */
  sim_icache_fetch(526 + t_thisfile.offset, 1);
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
} /* line 920 */
  sim_icache_fetch(527 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 922 */
l_L54X3: ;/* line 925 */
__LABEL(l_L54X3);
  sim_icache_fetch(528 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 926 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 927 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 928 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 929 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 930 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 931 */
   __ADD_CYCLES(1);
} /* line 931 */
  sim_icache_fetch(538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 933 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 934 */
} /* line 934 */
  sim_icache_fetch(540 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 936 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 937 */
} /* line 937 */
  sim_icache_fetch(543 + t_thisfile.offset, 1);
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
} /* line 939 */
  sim_icache_fetch(544 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 941 */
} /* line 941 */
  sim_icache_fetch(546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 943 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 944 */
   __ADD_CYCLES(1);
} /* line 944 */
  sim_icache_fetch(548 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 946 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 947 */
} /* line 947 */
l_L56X3: ;/* line 949 */
__LABEL(l_L56X3);
  sim_icache_fetch(551 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 950 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 951 */
} /* line 951 */
  sim_icache_fetch(553 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 953 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 954 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 955 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 956 */
} /* line 956 */
  sim_icache_fetch(559 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 958 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 959 */
		 /* line 960 */
  sim_icache_fetch(562 + t_thisfile.offset, 2);
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
} /* line 962 */
l_lr_87: ;/* line 962 */
__LABEL(l_lr_87);
  sim_icache_fetch(564 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 964 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 965 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 966 */
   __ADD_CYCLES(1);
} /* line 966 */
  sim_icache_fetch(567 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 969 */
l_L48X3: ;/* line 972 */
__LABEL(l_L48X3);
		 /* line 972 */
  sim_icache_fetch(568 + t_thisfile.offset, 2);
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
} /* line 974 */
l_lr_90: ;/* line 974 */
__LABEL(l_lr_90);
  sim_icache_fetch(570 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 976 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 977 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 978 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 979 */
   __ADD_CYCLES(1);
} /* line 979 */
  sim_icache_fetch(574 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 982 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 983 */
l_L55X3: ;/* line 986 */
__LABEL(l_L55X3);
  sim_icache_fetch(577 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 987 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 988 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 989 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 990 */
} /* line 990 */
  sim_icache_fetch(583 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 992 */
   __GOTO(l_L56X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L56X3;
} /* line 993 */
l_L52X3: ;/* line 996 */
__LABEL(l_L52X3);
  sim_icache_fetch(586 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 997 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 998 */
   __GOTO(l_L53X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L53X3;
} /* line 999 */
l_L49X3: ;/* line 1002 */
__LABEL(l_L49X3);
  sim_icache_fetch(590 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 1003 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1004 */
} /* line 1004 */
  sim_icache_fetch(593 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1006 */
} /* line 1006 */
  sim_icache_fetch(594 + t_thisfile.offset, 1);
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
} /* line 1009 */
  sim_icache_fetch(595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 1011 */
l_L46X3: ;/* line 1014 */
__LABEL(l_L46X3);
  sim_icache_fetch(596 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1015 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1016 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1017 */
   __ADD_CYCLES(1);
} /* line 1017 */
  sim_icache_fetch(601 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1019 */
} /* line 1019 */
  sim_icache_fetch(603 + t_thisfile.offset, 1);
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
} /* line 1021 */
		 /* line 1022 */
  sim_icache_fetch(604 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1024 */
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
} /* line 1025 */
l_lr_96: ;/* line 1025 */
__LABEL(l_lr_96);
  sim_icache_fetch(608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1027 */
l_L57X3: ;/* line 1030 */
__LABEL(l_L57X3);
  sim_icache_fetch(609 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1031 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1032 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1033 */
   __ADD_CYCLES(1);
} /* line 1033 */
  sim_icache_fetch(614 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1035 */
} /* line 1035 */
  sim_icache_fetch(616 + t_thisfile.offset, 1);
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
} /* line 1037 */
		 /* line 1038 */
  sim_icache_fetch(617 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1040 */
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
} /* line 1041 */
l_lr_99: ;/* line 1041 */
__LABEL(l_lr_99);
  sim_icache_fetch(621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1043 */
l_L58X3: ;/* line 1046 */
__LABEL(l_L58X3);
  sim_icache_fetch(622 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1047 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1048 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1049 */
   __ADD_CYCLES(1);
} /* line 1049 */
  sim_icache_fetch(627 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1051 */
} /* line 1051 */
  sim_icache_fetch(629 + t_thisfile.offset, 1);
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
} /* line 1053 */
		 /* line 1054 */
  sim_icache_fetch(630 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1056 */
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
} /* line 1057 */
l_lr_102: ;/* line 1057 */
__LABEL(l_lr_102);
  sim_icache_fetch(634 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1059 */
l_L59X3: ;/* line 1062 */
__LABEL(l_L59X3);
  sim_icache_fetch(635 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1063 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1064 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1065 */
   __ADD_CYCLES(1);
} /* line 1065 */
  sim_icache_fetch(640 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1067 */
} /* line 1067 */
  sim_icache_fetch(642 + t_thisfile.offset, 1);
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
} /* line 1069 */
		 /* line 1070 */
  sim_icache_fetch(643 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1072 */
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
} /* line 1073 */
l_lr_105: ;/* line 1073 */
__LABEL(l_lr_105);
  sim_icache_fetch(647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1075 */
l_L60X3: ;/* line 1078 */
__LABEL(l_L60X3);
		 /* line 1078 */
  sim_icache_fetch(648 + t_thisfile.offset, 2);
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
} /* line 1080 */
l_lr_108: ;/* line 1080 */
__LABEL(l_lr_108);
  sim_icache_fetch(650 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1082 */
l_L44X3: ;/* line 1085 */
__LABEL(l_L44X3);
  sim_icache_fetch(651 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1086 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1087 */
} /* line 1087 */
  sim_icache_fetch(654 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1089 */
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 1090 */
l_L42X3: ;/* line 1093 */
__LABEL(l_L42X3);
  sim_icache_fetch(657 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1094 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1095 */
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1096 */
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

  sim_icache_fetch(660 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1234 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1235 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1236 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1237 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1238 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1239 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1240 */
} /* line 1240 */
  sim_icache_fetch(670 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1242 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1243 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1244 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1245 */
   __MOV(reg_r0_4, 0); /* line 1246 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1247 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1248 */
} /* line 1248 */
  sim_icache_fetch(682 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1250 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1251 */
} /* line 1251 */
  sim_icache_fetch(685 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 1253 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1254 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 1); /* line 1255 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1256 */
l_L62X3: ;/* line 1258 */
__LABEL(l_L62X3);
  sim_icache_fetch(689 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((unsigned int) compress_10939Xoffset,0,4), 0); /* line 1259 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1260 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1261 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1262 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1263 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, (unsigned int) 256); /* line 1264 */
   __CMPGE(reg_b0_1, reg_r0_13, 0); /* line 1265 */
} /* line 1265 */
  sim_icache_fetch(702 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1267 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1268 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1269 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1270 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1271 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1272 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1273 */
  sim_icache_fetch(715 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 1275 */
} /* line 1275 */
  sim_icache_fetch(717 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1277 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1278 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1279 */
   __ADD_CYCLES(1);
} /* line 1279 */
  sim_icache_fetch(720 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1281 */
} /* line 1281 */
l_L64X3: ;/* line 1283 */
__LABEL(l_L64X3);
  sim_icache_fetch(721 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1284 */
} /* line 1284 */
l_L65X3: ;/* line 1287 */
__LABEL(l_L65X3);
  sim_icache_fetch(722 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1288 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1289 */
} /* line 1289 */
  sim_icache_fetch(724 + t_thisfile.offset, 3);
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
  sim_icache_fetch(727 + t_thisfile.offset, 3);
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
  sim_icache_fetch(730 + t_thisfile.offset, 3);
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
  sim_icache_fetch(733 + t_thisfile.offset, 3);
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
  sim_icache_fetch(736 + t_thisfile.offset, 3);
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
  sim_icache_fetch(739 + t_thisfile.offset, 3);
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
  sim_icache_fetch(742 + t_thisfile.offset, 3);
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
  sim_icache_fetch(745 + t_thisfile.offset, 3);
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
  sim_icache_fetch(748 + t_thisfile.offset, 3);
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
  sim_icache_fetch(751 + t_thisfile.offset, 3);
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
  sim_icache_fetch(754 + t_thisfile.offset, 3);
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
  sim_icache_fetch(757 + t_thisfile.offset, 3);
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
  sim_icache_fetch(760 + t_thisfile.offset, 3);
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
  sim_icache_fetch(763 + t_thisfile.offset, 3);
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
  sim_icache_fetch(766 + t_thisfile.offset, 3);
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
  sim_icache_fetch(769 + t_thisfile.offset, 3);
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
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1353 */
  sim_icache_fetch(772 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1355 */
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
  sim_icache_fetch(776 + t_thisfile.offset, 3);
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
  sim_icache_fetch(779 + t_thisfile.offset, 3);
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
  sim_icache_fetch(782 + t_thisfile.offset, 3);
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
  sim_icache_fetch(785 + t_thisfile.offset, 3);
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
  sim_icache_fetch(788 + t_thisfile.offset, 3);
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
  sim_icache_fetch(791 + t_thisfile.offset, 3);
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
  sim_icache_fetch(794 + t_thisfile.offset, 3);
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
  sim_icache_fetch(797 + t_thisfile.offset, 3);
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
  sim_icache_fetch(800 + t_thisfile.offset, 3);
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
  sim_icache_fetch(803 + t_thisfile.offset, 3);
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
  sim_icache_fetch(806 + t_thisfile.offset, 3);
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
  sim_icache_fetch(809 + t_thisfile.offset, 3);
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
  sim_icache_fetch(812 + t_thisfile.offset, 3);
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
  sim_icache_fetch(815 + t_thisfile.offset, 3);
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
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1414 */
  sim_icache_fetch(818 + t_thisfile.offset, 1);
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
} /* line 1416 */
  sim_icache_fetch(819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1418 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 1419 */
l_L81X3: ;/* line 1422 */
__LABEL(l_L81X3);
  sim_icache_fetch(821 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1423 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1424 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1425 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1426 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1427 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1428 */
l_L83X3: ;/* line 1431 */
__LABEL(l_L83X3);
  sim_icache_fetch(828 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1432 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1433 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1434 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1435 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1436 */
   __ADD_CYCLES(1);
} /* line 1436 */
  sim_icache_fetch(837 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1438 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1439 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1440 */
} /* line 1440 */
  sim_icache_fetch(840 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1442 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1443 */
} /* line 1443 */
  sim_icache_fetch(843 + t_thisfile.offset, 1);
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
} /* line 1445 */
  sim_icache_fetch(844 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1447 */
} /* line 1447 */
  sim_icache_fetch(846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1449 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1450 */
   __ADD_CYCLES(1);
} /* line 1450 */
  sim_icache_fetch(848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1452 */
} /* line 1452 */
l_L85X3: ;/* line 1454 */
__LABEL(l_L85X3);
  sim_icache_fetch(849 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1455 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1456 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1457 */
} /* line 1457 */
  sim_icache_fetch(852 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1459 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1460 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1461 */
  sim_icache_fetch(855 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1463 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1464 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1465 */
} /* line 1465 */
  sim_icache_fetch(861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1467 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1468 */
   __ADD_CYCLES(1);
} /* line 1468 */
  sim_icache_fetch(863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1470 */
} /* line 1470 */
  sim_icache_fetch(864 + t_thisfile.offset, 1);
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
} /* line 1472 */
  sim_icache_fetch(865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1474 */
} /* line 1474 */
  sim_icache_fetch(866 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1476 */
l_L87X3: ;/* line 1479 */
__LABEL(l_L87X3);
  sim_icache_fetch(867 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1480 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1481 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1482 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1483 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1484 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1485 */
} /* line 1485 */
  sim_icache_fetch(874 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1487 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1488 */
   __ADD_CYCLES(1);
} /* line 1488 */
  sim_icache_fetch(876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1490 */
} /* line 1490 */
  sim_icache_fetch(877 + t_thisfile.offset, 1);
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
} /* line 1492 */
l_L89X3: ;/* line 1494 */
__LABEL(l_L89X3);
		 /* line 1494 */
  sim_icache_fetch(878 + t_thisfile.offset, 2);
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
} /* line 1496 */
l_lr_121: ;/* line 1496 */
__LABEL(l_lr_121);
  sim_icache_fetch(880 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1498 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1499 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1500 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1501 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1502 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1503 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1504 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1505 */
   __ADD_CYCLES(1);
} /* line 1505 */
  sim_icache_fetch(891 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1507 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1508 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1509 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1510 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1511 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1512 */
} /* line 1512 */
  sim_icache_fetch(899 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1514 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1515 */
  sim_icache_fetch(902 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1517 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1518 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1519 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1520 */
l_L90X3: ;/* line 1523 */
__LABEL(l_L90X3);
  sim_icache_fetch(907 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1524 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1525 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1526 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1527 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1528 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1529 */
   __ADD_CYCLES(1);
} /* line 1529 */
  sim_icache_fetch(916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1531 */
} /* line 1531 */
  sim_icache_fetch(917 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1533 */
} /* line 1533 */
  sim_icache_fetch(918 + t_thisfile.offset, 1);
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
} /* line 1535 */
		 /* line 1536 */
  sim_icache_fetch(919 + t_thisfile.offset, 2);
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
} /* line 1538 */
l_lr_124: ;/* line 1538 */
__LABEL(l_lr_124);
  sim_icache_fetch(921 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1540 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1541 */
} /* line 1541 */
  sim_icache_fetch(923 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1543 */
l_L91X3: ;/* line 1546 */
__LABEL(l_L91X3);
  sim_icache_fetch(924 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1547 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1548 */
} /* line 1548 */
  sim_icache_fetch(926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1550 */
l_L88X3: ;/* line 1553 */
__LABEL(l_L88X3);
  sim_icache_fetch(927 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1554 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1555 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1556 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1557 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1558 */
   __ADD_CYCLES(1);
} /* line 1558 */
  sim_icache_fetch(932 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1560 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1561 */
} /* line 1561 */
  sim_icache_fetch(934 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1563 */
} /* line 1563 */
l_L92X3: ;/* line 1566 */
__LABEL(l_L92X3);
  sim_icache_fetch(935 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1567 */
} /* line 1567 */
  sim_icache_fetch(936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1569 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1570 */
} /* line 1570 */
  sim_icache_fetch(938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1572 */
} /* line 1572 */
  sim_icache_fetch(939 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1574 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1575 */
} /* line 1575 */
  sim_icache_fetch(942 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1577 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1578 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1579 */
} /* line 1579 */
  sim_icache_fetch(945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1581 */
} /* line 1581 */
  sim_icache_fetch(946 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1583 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1584 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1585 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1586 */
} /* line 1586 */
  sim_icache_fetch(951 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1588 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1589 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1590 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1591 */
  sim_icache_fetch(955 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1593 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1594 */
  sim_icache_fetch(957 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1596 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1597 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1598 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1599 */
} /* line 1599 */
  sim_icache_fetch(962 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1601 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1602 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1603 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1604 */
  sim_icache_fetch(966 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1606 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1607 */
  sim_icache_fetch(968 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1609 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1610 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1611 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1612 */
} /* line 1612 */
  sim_icache_fetch(973 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1614 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1615 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1616 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1617 */
  sim_icache_fetch(977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1619 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1620 */
  sim_icache_fetch(979 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1622 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1623 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1624 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1625 */
} /* line 1625 */
  sim_icache_fetch(984 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1627 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1628 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1629 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1630 */
  sim_icache_fetch(988 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1632 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1633 */
  sim_icache_fetch(990 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1635 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1636 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1637 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1638 */
} /* line 1638 */
  sim_icache_fetch(995 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1640 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1641 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1642 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1643 */
  sim_icache_fetch(999 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1645 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1646 */
  sim_icache_fetch(1001 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1648 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1649 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1650 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1651 */
} /* line 1651 */
  sim_icache_fetch(1006 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1653 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1654 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1655 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1656 */
  sim_icache_fetch(1010 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1658 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1659 */
  sim_icache_fetch(1012 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1661 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1662 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1663 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1664 */
} /* line 1664 */
  sim_icache_fetch(1017 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1666 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1667 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1668 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1669 */
  sim_icache_fetch(1021 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1671 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1672 */
  sim_icache_fetch(1023 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1674 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1675 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1676 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1677 */
} /* line 1677 */
  sim_icache_fetch(1028 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1679 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1680 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1681 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1682 */
  sim_icache_fetch(1032 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1684 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1685 */
  sim_icache_fetch(1034 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1687 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1688 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1689 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1690 */
} /* line 1690 */
  sim_icache_fetch(1039 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1692 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1693 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1694 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1695 */
  sim_icache_fetch(1043 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1697 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1698 */
  sim_icache_fetch(1045 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1700 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1701 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1702 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1703 */
} /* line 1703 */
  sim_icache_fetch(1050 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1705 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1706 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1707 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1708 */
  sim_icache_fetch(1054 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1710 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1711 */
  sim_icache_fetch(1056 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1713 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1714 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1715 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1716 */
} /* line 1716 */
  sim_icache_fetch(1061 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1718 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1719 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1720 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1721 */
  sim_icache_fetch(1065 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1723 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1724 */
  sim_icache_fetch(1067 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1726 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1727 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1728 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1729 */
} /* line 1729 */
  sim_icache_fetch(1072 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1731 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1732 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1733 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1734 */
  sim_icache_fetch(1076 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1736 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1737 */
  sim_icache_fetch(1078 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1739 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1740 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1741 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1742 */
} /* line 1742 */
  sim_icache_fetch(1083 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1744 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1745 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1746 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1747 */
  sim_icache_fetch(1087 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1749 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1750 */
  sim_icache_fetch(1089 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1752 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1753 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1754 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1755 */
} /* line 1755 */
  sim_icache_fetch(1094 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1757 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1758 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1759 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1760 */
  sim_icache_fetch(1098 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1762 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1763 */
  sim_icache_fetch(1100 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1765 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1766 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1767 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1768 */
} /* line 1768 */
  sim_icache_fetch(1105 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1770 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1771 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1772 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1773 */
  sim_icache_fetch(1109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1775 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1776 */
  sim_icache_fetch(1111 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1778 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1779 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1780 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1781 */
} /* line 1781 */
  sim_icache_fetch(1116 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1783 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1784 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1785 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1786 */
  sim_icache_fetch(1120 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1788 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1789 */
  sim_icache_fetch(1122 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1791 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1792 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1793 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1794 */
} /* line 1794 */
  sim_icache_fetch(1127 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1796 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1797 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1798 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1799 */
  sim_icache_fetch(1131 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1801 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1802 */
  sim_icache_fetch(1133 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1804 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1805 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1806 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1807 */
} /* line 1807 */
  sim_icache_fetch(1138 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1809 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1810 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1811 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1812 */
  sim_icache_fetch(1142 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1814 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1815 */
  sim_icache_fetch(1144 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1817 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1818 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1819 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1820 */
} /* line 1820 */
  sim_icache_fetch(1149 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1822 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1823 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1824 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1825 */
  sim_icache_fetch(1153 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1827 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1828 */
  sim_icache_fetch(1155 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1830 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1831 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1832 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1833 */
} /* line 1833 */
  sim_icache_fetch(1160 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1835 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1836 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1837 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1838 */
  sim_icache_fetch(1164 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1840 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1841 */
  sim_icache_fetch(1166 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1843 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1844 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1845 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1846 */
} /* line 1846 */
  sim_icache_fetch(1171 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1848 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1849 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1850 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1851 */
  sim_icache_fetch(1175 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1853 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1854 */
  sim_icache_fetch(1177 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1856 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1857 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1858 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1859 */
} /* line 1859 */
  sim_icache_fetch(1182 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1861 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1862 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1863 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1864 */
  sim_icache_fetch(1186 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1866 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1867 */
  sim_icache_fetch(1188 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1869 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1870 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1871 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1872 */
} /* line 1872 */
  sim_icache_fetch(1193 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1874 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1875 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1876 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1877 */
  sim_icache_fetch(1197 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1879 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1880 */
  sim_icache_fetch(1199 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1882 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1883 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1884 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1885 */
} /* line 1885 */
  sim_icache_fetch(1204 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1887 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1888 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1889 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1890 */
  sim_icache_fetch(1208 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1892 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1893 */
  sim_icache_fetch(1210 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1895 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1896 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1897 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1898 */
} /* line 1898 */
  sim_icache_fetch(1215 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1900 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1901 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1902 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1903 */
  sim_icache_fetch(1219 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1905 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1906 */
  sim_icache_fetch(1221 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1908 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1909 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1910 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1911 */
} /* line 1911 */
  sim_icache_fetch(1226 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1913 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1914 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1915 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1916 */
  sim_icache_fetch(1230 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1918 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1919 */
  sim_icache_fetch(1232 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1921 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1922 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1923 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1924 */
} /* line 1924 */
  sim_icache_fetch(1237 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1926 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1927 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1928 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1929 */
  sim_icache_fetch(1241 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1931 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1932 */
  sim_icache_fetch(1243 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1934 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1935 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1936 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1937 */
} /* line 1937 */
  sim_icache_fetch(1248 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1939 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1940 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1941 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1942 */
  sim_icache_fetch(1252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1944 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1945 */
  sim_icache_fetch(1254 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1947 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1948 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1949 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1950 */
} /* line 1950 */
  sim_icache_fetch(1259 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1952 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1953 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1954 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1955 */
  sim_icache_fetch(1263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1957 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1958 */
  sim_icache_fetch(1265 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1960 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1961 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1962 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1963 */
} /* line 1963 */
  sim_icache_fetch(1270 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1965 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1966 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1967 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1968 */
  sim_icache_fetch(1274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1970 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1971 */
  sim_icache_fetch(1276 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1973 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1974 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1975 */
} /* line 1975 */
  sim_icache_fetch(1280 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1977 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1978 */
  sim_icache_fetch(1282 + t_thisfile.offset, 1);
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
} /* line 1980 */
  sim_icache_fetch(1283 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1982 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1983 */
} /* line 1983 */
  sim_icache_fetch(1285 + t_thisfile.offset, 1);
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
} /* line 1985 */
  sim_icache_fetch(1286 + t_thisfile.offset, 1);
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
} /* line 1988 */
  sim_icache_fetch(1287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L92X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L92X3;
} /* line 1990 */
l_L156X3: ;/* line 1993 */
__LABEL(l_L156X3);
  sim_icache_fetch(1288 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1994 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1995 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1996 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1997 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 1998 */
l_L155X3: ;/* line 2002 */
__LABEL(l_L155X3);
  sim_icache_fetch(1293 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2003 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2004 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2005 */
l_L154X3: ;/* line 2008 */
__LABEL(l_L154X3);
  sim_icache_fetch(1296 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2009 */
} /* line 2009 */
l_L122X3: ;/* line 2012 */
__LABEL(l_L122X3);
  sim_icache_fetch(1297 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2013 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2014 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2015 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2016 */
} /* line 2016 */
  sim_icache_fetch(1301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2018 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2019 */
l_L153X3: ;/* line 2022 */
__LABEL(l_L153X3);
  sim_icache_fetch(1303 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2023 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2024 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2025 */
l_L152X3: ;/* line 2028 */
__LABEL(l_L152X3);
  sim_icache_fetch(1306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2029 */
} /* line 2029 */
l_L120X3: ;/* line 2032 */
__LABEL(l_L120X3);
  sim_icache_fetch(1307 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2033 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2034 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2035 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2036 */
} /* line 2036 */
  sim_icache_fetch(1311 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2038 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2039 */
l_L151X3: ;/* line 2042 */
__LABEL(l_L151X3);
  sim_icache_fetch(1313 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2043 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2044 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2045 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2046 */
l_L150X3: ;/* line 2049 */
__LABEL(l_L150X3);
  sim_icache_fetch(1317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2050 */
} /* line 2050 */
l_L118X3: ;/* line 2053 */
__LABEL(l_L118X3);
  sim_icache_fetch(1318 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2054 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2055 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2056 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2057 */
} /* line 2057 */
  sim_icache_fetch(1322 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2059 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2060 */
l_L149X3: ;/* line 2063 */
__LABEL(l_L149X3);
  sim_icache_fetch(1324 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2064 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2065 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2066 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2067 */
l_L148X3: ;/* line 2070 */
__LABEL(l_L148X3);
  sim_icache_fetch(1328 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2071 */
} /* line 2071 */
l_L116X3: ;/* line 2074 */
__LABEL(l_L116X3);
  sim_icache_fetch(1329 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2075 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2076 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2077 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2078 */
} /* line 2078 */
  sim_icache_fetch(1333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2080 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2081 */
l_L147X3: ;/* line 2084 */
__LABEL(l_L147X3);
  sim_icache_fetch(1335 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2085 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2086 */
   __GOTO(l_L159X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L159X3;
} /* line 2087 */
l_L146X3: ;/* line 2090 */
__LABEL(l_L146X3);
  sim_icache_fetch(1338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2091 */
} /* line 2091 */
l_L114X3: ;/* line 2094 */
__LABEL(l_L114X3);
  sim_icache_fetch(1339 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2095 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2096 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2097 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2098 */
} /* line 2098 */
  sim_icache_fetch(1343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2100 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2101 */
l_L145X3: ;/* line 2104 */
__LABEL(l_L145X3);
  sim_icache_fetch(1345 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2105 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2106 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2107 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2108 */
l_L144X3: ;/* line 2111 */
__LABEL(l_L144X3);
  sim_icache_fetch(1349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2112 */
} /* line 2112 */
l_L112X3: ;/* line 2115 */
__LABEL(l_L112X3);
  sim_icache_fetch(1350 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2116 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2117 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2118 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2119 */
} /* line 2119 */
  sim_icache_fetch(1354 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2121 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2122 */
l_L143X3: ;/* line 2125 */
__LABEL(l_L143X3);
  sim_icache_fetch(1356 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2126 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2127 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2128 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2129 */
l_L142X3: ;/* line 2132 */
__LABEL(l_L142X3);
  sim_icache_fetch(1360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2133 */
} /* line 2133 */
l_L110X3: ;/* line 2136 */
__LABEL(l_L110X3);
  sim_icache_fetch(1361 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2137 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2138 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2139 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2140 */
} /* line 2140 */
  sim_icache_fetch(1365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2142 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2143 */
l_L141X3: ;/* line 2146 */
__LABEL(l_L141X3);
  sim_icache_fetch(1367 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2147 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2148 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2149 */
l_L140X3: ;/* line 2152 */
__LABEL(l_L140X3);
  sim_icache_fetch(1370 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2153 */
} /* line 2153 */
l_L108X3: ;/* line 2156 */
__LABEL(l_L108X3);
  sim_icache_fetch(1371 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2157 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2158 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2159 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2160 */
} /* line 2160 */
  sim_icache_fetch(1375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2162 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2163 */
l_L139X3: ;/* line 2166 */
__LABEL(l_L139X3);
  sim_icache_fetch(1377 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2167 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2168 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2169 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2170 */
l_L138X3: ;/* line 2173 */
__LABEL(l_L138X3);
  sim_icache_fetch(1381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2174 */
} /* line 2174 */
l_L106X3: ;/* line 2177 */
__LABEL(l_L106X3);
  sim_icache_fetch(1382 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2178 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2179 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2180 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2181 */
} /* line 2181 */
  sim_icache_fetch(1386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2183 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2184 */
l_L137X3: ;/* line 2187 */
__LABEL(l_L137X3);
  sim_icache_fetch(1388 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2188 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2189 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2190 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2191 */
l_L136X3: ;/* line 2194 */
__LABEL(l_L136X3);
  sim_icache_fetch(1392 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2195 */
} /* line 2195 */
l_L104X3: ;/* line 2198 */
__LABEL(l_L104X3);
  sim_icache_fetch(1393 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2199 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2200 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2201 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2202 */
} /* line 2202 */
  sim_icache_fetch(1397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2204 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2205 */
l_L135X3: ;/* line 2208 */
__LABEL(l_L135X3);
  sim_icache_fetch(1399 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2209 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2210 */
   __GOTO(l_L161X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L161X3;
} /* line 2211 */
l_L134X3: ;/* line 2214 */
__LABEL(l_L134X3);
  sim_icache_fetch(1402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2215 */
} /* line 2215 */
l_L102X3: ;/* line 2218 */
__LABEL(l_L102X3);
  sim_icache_fetch(1403 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2219 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2220 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2221 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2222 */
} /* line 2222 */
  sim_icache_fetch(1407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2224 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2225 */
l_L133X3: ;/* line 2228 */
__LABEL(l_L133X3);
  sim_icache_fetch(1409 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2229 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2230 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2231 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2232 */
l_L132X3: ;/* line 2235 */
__LABEL(l_L132X3);
  sim_icache_fetch(1413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2236 */
} /* line 2236 */
l_L100X3: ;/* line 2239 */
__LABEL(l_L100X3);
  sim_icache_fetch(1414 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2240 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2241 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2242 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2243 */
} /* line 2243 */
  sim_icache_fetch(1418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2245 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2246 */
l_L131X3: ;/* line 2249 */
__LABEL(l_L131X3);
  sim_icache_fetch(1420 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2250 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2251 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2252 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2253 */
l_L130X3: ;/* line 2256 */
__LABEL(l_L130X3);
  sim_icache_fetch(1424 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2257 */
} /* line 2257 */
l_L98X3: ;/* line 2260 */
__LABEL(l_L98X3);
  sim_icache_fetch(1425 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2261 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2262 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2263 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2264 */
} /* line 2264 */
  sim_icache_fetch(1429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2266 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2267 */
l_L129X3: ;/* line 2270 */
__LABEL(l_L129X3);
  sim_icache_fetch(1431 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2271 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2272 */
   __GOTO(l_L162X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L162X3;
} /* line 2273 */
l_L128X3: ;/* line 2276 */
__LABEL(l_L128X3);
  sim_icache_fetch(1434 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2277 */
} /* line 2277 */
l_L96X3: ;/* line 2280 */
__LABEL(l_L96X3);
  sim_icache_fetch(1435 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2281 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2282 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2283 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2284 */
} /* line 2284 */
  sim_icache_fetch(1439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2286 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2287 */
l_L127X3: ;/* line 2290 */
__LABEL(l_L127X3);
  sim_icache_fetch(1441 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2291 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2292 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2293 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2294 */
l_L126X3: ;/* line 2297 */
__LABEL(l_L126X3);
  sim_icache_fetch(1445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2298 */
} /* line 2298 */
l_L94X3: ;/* line 2302 */
__LABEL(l_L94X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2303 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2304 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2305 */
} /* line 2305 */
  sim_icache_fetch(1449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2307 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2308 */
l_L125X3: ;/* line 2311 */
__LABEL(l_L125X3);
  sim_icache_fetch(1451 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2312 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2313 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2314 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2315 */
l_L124X3: ;/* line 2318 */
__LABEL(l_L124X3);
  sim_icache_fetch(1455 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2319 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2320 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2321 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2322 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2323 */
l_L123X3: ;/* line 2327 */
__LABEL(l_L123X3);
  sim_icache_fetch(1460 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2328 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2329 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2330 */
l_L121X3: ;/* line 2333 */
__LABEL(l_L121X3);
  sim_icache_fetch(1463 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2334 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2335 */
} /* line 2335 */
l_L158X3: ;/* line 2337 */
__LABEL(l_L158X3);
  sim_icache_fetch(1465 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2338 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2339 */
l_L119X3: ;/* line 2342 */
__LABEL(l_L119X3);
  sim_icache_fetch(1467 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2343 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2344 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2345 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2346 */
l_L117X3: ;/* line 2349 */
__LABEL(l_L117X3);
  sim_icache_fetch(1471 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2350 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2351 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2352 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2353 */
l_L115X3: ;/* line 2356 */
__LABEL(l_L115X3);
  sim_icache_fetch(1475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2357 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2358 */
} /* line 2358 */
l_L159X3: ;/* line 2360 */
__LABEL(l_L159X3);
  sim_icache_fetch(1477 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2361 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2362 */
l_L113X3: ;/* line 2365 */
__LABEL(l_L113X3);
  sim_icache_fetch(1479 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2366 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2367 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2368 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2369 */
l_L111X3: ;/* line 2372 */
__LABEL(l_L111X3);
  sim_icache_fetch(1483 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2373 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2374 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2375 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2376 */
l_L109X3: ;/* line 2379 */
__LABEL(l_L109X3);
  sim_icache_fetch(1487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2380 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2381 */
} /* line 2381 */
l_L160X3: ;/* line 2383 */
__LABEL(l_L160X3);
  sim_icache_fetch(1489 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2384 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2385 */
l_L107X3: ;/* line 2388 */
__LABEL(l_L107X3);
  sim_icache_fetch(1491 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2389 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2390 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2391 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2392 */
l_L105X3: ;/* line 2395 */
__LABEL(l_L105X3);
  sim_icache_fetch(1495 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2396 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2397 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2398 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2399 */
l_L103X3: ;/* line 2402 */
__LABEL(l_L103X3);
  sim_icache_fetch(1499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2403 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2404 */
} /* line 2404 */
l_L161X3: ;/* line 2406 */
__LABEL(l_L161X3);
  sim_icache_fetch(1501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2407 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2408 */
l_L101X3: ;/* line 2411 */
__LABEL(l_L101X3);
  sim_icache_fetch(1503 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2412 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2413 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2414 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2415 */
l_L99X3: ;/* line 2418 */
__LABEL(l_L99X3);
  sim_icache_fetch(1507 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2419 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2420 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2421 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2422 */
l_L97X3: ;/* line 2425 */
__LABEL(l_L97X3);
  sim_icache_fetch(1511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2426 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2427 */
} /* line 2427 */
l_L162X3: ;/* line 2429 */
__LABEL(l_L162X3);
  sim_icache_fetch(1513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2430 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2431 */
l_L95X3: ;/* line 2434 */
__LABEL(l_L95X3);
  sim_icache_fetch(1515 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2435 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2436 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2437 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2438 */
l_L93X3: ;/* line 2442 */
__LABEL(l_L93X3);
  sim_icache_fetch(1519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2443 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2444 */
} /* line 2444 */
l_L157X3: ;/* line 2446 */
__LABEL(l_L157X3);
  sim_icache_fetch(1521 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2447 */
} /* line 2447 */
  sim_icache_fetch(1523 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2449 */
} /* line 2449 */
  sim_icache_fetch(1524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2451 */
l_L86X3: ;/* line 2454 */
__LABEL(l_L86X3);
		 /* line 2454 */
  sim_icache_fetch(1525 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2457 */
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
} /* line 2457 */
l_lr_200: ;/* line 2457 */
__LABEL(l_lr_200);
  sim_icache_fetch(1528 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2459 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2460 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2461 */
   __ADD_CYCLES(1);
} /* line 2461 */
  sim_icache_fetch(1532 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2463 */
} /* line 2463 */
		 /* line 2464 */
  sim_icache_fetch(1533 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2466 */
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
} /* line 2467 */
l_lr_202: ;/* line 2467 */
__LABEL(l_lr_202);
  sim_icache_fetch(1537 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2469 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2470 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2471 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2472 */
   __MOV(reg_r0_3, 0); /* line 2473 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2474 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2475 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2476 */
   __ADD_CYCLES(1);
} /* line 2476 */
  sim_icache_fetch(1549 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2478 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2479 */
} /* line 2479 */
  sim_icache_fetch(1551 + t_thisfile.offset, 1);
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
} /* line 2481 */
l_L164X3: ;/* line 2483 */
__LABEL(l_L164X3);
  sim_icache_fetch(1552 + t_thisfile.offset, 1);
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
} /* line 2484 */
  sim_icache_fetch(1553 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2486 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2487 */
} /* line 2487 */
l_L166X3: ;/* line 2489 */
__LABEL(l_L166X3);
  sim_icache_fetch(1556 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2491 */
l_L165X3: ;/* line 2494 */
__LABEL(l_L165X3);
  sim_icache_fetch(1557 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2495 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2496 */
   __GOTO(l_L166X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L166X3;
} /* line 2497 */
l_L163X3: ;/* line 2500 */
__LABEL(l_L163X3);
  sim_icache_fetch(1560 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2501 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2502 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2503 */
   __ADD_CYCLES(1);
} /* line 2503 */
		 /* line 2504 */
  sim_icache_fetch(1565 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2506 */
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
} /* line 2507 */
l_lr_208: ;/* line 2507 */
__LABEL(l_lr_208);
  sim_icache_fetch(1568 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2509 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2510 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2511 */
   __MOV(reg_r0_3, 0); /* line 2512 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2513 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2514 */
   __ADD_CYCLES(1);
} /* line 2514 */
  sim_icache_fetch(1576 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2516 */
   __GOTO(l_L164X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L164X3;
} /* line 2517 */
l_L84X3: ;/* line 2520 */
__LABEL(l_L84X3);
  sim_icache_fetch(1578 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2521 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2522 */
l_L80X3: ;/* line 2525 */
__LABEL(l_L80X3);
  sim_icache_fetch(1580 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2526 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2527 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2528 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2529 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2530 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2531 */
l_L79X3: ;/* line 2534 */
__LABEL(l_L79X3);
  sim_icache_fetch(1587 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2535 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2536 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2537 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2538 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2539 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2540 */
l_L78X3: ;/* line 2543 */
__LABEL(l_L78X3);
  sim_icache_fetch(1594 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2544 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2545 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2546 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2547 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2548 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2549 */
l_L77X3: ;/* line 2552 */
__LABEL(l_L77X3);
  sim_icache_fetch(1601 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2553 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2554 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2555 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2556 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2557 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2558 */
l_L76X3: ;/* line 2561 */
__LABEL(l_L76X3);
  sim_icache_fetch(1608 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2562 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2563 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2564 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2565 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2566 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2567 */
l_L75X3: ;/* line 2570 */
__LABEL(l_L75X3);
  sim_icache_fetch(1615 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2571 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2572 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2573 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2574 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2575 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2576 */
l_L74X3: ;/* line 2579 */
__LABEL(l_L74X3);
  sim_icache_fetch(1622 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2580 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2581 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2582 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2583 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2584 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2585 */
l_L73X3: ;/* line 2588 */
__LABEL(l_L73X3);
  sim_icache_fetch(1629 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2589 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2590 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2591 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2592 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2593 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2594 */
l_L72X3: ;/* line 2597 */
__LABEL(l_L72X3);
  sim_icache_fetch(1636 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2598 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2599 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2600 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2601 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2602 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2603 */
l_L71X3: ;/* line 2606 */
__LABEL(l_L71X3);
  sim_icache_fetch(1643 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2607 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2608 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2609 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2610 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2611 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2612 */
l_L70X3: ;/* line 2615 */
__LABEL(l_L70X3);
  sim_icache_fetch(1650 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2616 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2617 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2618 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2619 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2620 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2621 */
l_L69X3: ;/* line 2624 */
__LABEL(l_L69X3);
  sim_icache_fetch(1657 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2625 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2626 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2627 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2628 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2629 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2630 */
l_L68X3: ;/* line 2633 */
__LABEL(l_L68X3);
  sim_icache_fetch(1664 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2634 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2635 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2636 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2637 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2638 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2639 */
l_L67X3: ;/* line 2642 */
__LABEL(l_L67X3);
  sim_icache_fetch(1671 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2643 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2644 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2645 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2646 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2647 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2648 */
l_L66X3: ;/* line 2652 */
__LABEL(l_L66X3);
  sim_icache_fetch(1678 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2653 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2654 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2655 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2656 */
} /* line 2656 */
l_L82X3: ;/* line 2658 */
__LABEL(l_L82X3);
  sim_icache_fetch(1683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2659 */
} /* line 2659 */
		 /* line 2660 */
  sim_icache_fetch(1684 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2663 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2664 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2665 */
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
} /* line 2665 */
l_lr_227: ;/* line 2665 */
__LABEL(l_lr_227);
  sim_icache_fetch(1689 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2667 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2668 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2669 */
} /* line 2669 */
  sim_icache_fetch(1692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2671 */
l_L63X3: ;/* line 2674 */
__LABEL(l_L63X3);
  sim_icache_fetch(1693 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2675 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2676 */
} /* line 2676 */
  sim_icache_fetch(1695 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L64X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L64X3;
} /* line 2678 */
l_L61X3: ;/* line 2681 */
__LABEL(l_L61X3);
  sim_icache_fetch(1696 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2682 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2683 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2684 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2685 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2686 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2687 */
   __ADD_CYCLES(1);
} /* line 2687 */
  sim_icache_fetch(1704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_11, (unsigned int) 1); /* line 2689 */
} /* line 2689 */
  sim_icache_fetch(1705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_16); /* line 2691 */
} /* line 2691 */
  sim_icache_fetch(1707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2693 */
} /* line 2693 */
  sim_icache_fetch(1708 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2695 */
   __LDBU(reg_r0_15, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2696 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2697 */
   __ADD_CYCLES(1);
} /* line 2697 */
  sim_icache_fetch(1713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_11, (unsigned int) 1); /* line 2699 */
} /* line 2699 */
  sim_icache_fetch(1714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_16); /* line 2701 */
} /* line 2701 */
  sim_icache_fetch(1716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2703 */
} /* line 2703 */
  sim_icache_fetch(1717 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2705 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2706 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2707 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2708 */
   __ADD_CYCLES(1);
} /* line 2708 */
  sim_icache_fetch(1724 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_17, reg_r0_11, (unsigned int) 1); /* line 2710 */
   __OR(reg_r0_15, reg_r0_15, reg_r0_16); /* line 2711 */
} /* line 2711 */
  sim_icache_fetch(1726 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_17); /* line 2713 */
} /* line 2713 */
  sim_icache_fetch(1728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2715 */
} /* line 2715 */
  sim_icache_fetch(1729 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2717 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2718 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2719 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2720 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2721 */
   __ADD_CYCLES(1);
} /* line 2721 */
  sim_icache_fetch(1738 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 2723 */
   __ADD(reg_r0_13, reg_r0_15, (unsigned int) -1); /* line 2724 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 1); /* line 2725 */
   __GOTO(l_L62X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L62X3;
} /* line 2726 */
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

  sim_icache_fetch(1742 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 2745 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2746 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2747 */
} /* line 2747 */
  sim_icache_fetch(1747 + t_thisfile.offset, 1);
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
} /* line 2749 */
  sim_icache_fetch(1748 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2751 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2752 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2753 */
} /* line 2753 */
  sim_icache_fetch(1751 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_10939Xbuf); /* line 2755 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_10939Xbuf),0,1)); /* line 2756 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_10939Xbuf + (unsigned int) 1)); /* line 2757 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2758 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2759 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2760 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2761 */
} /* line 2761 */
  sim_icache_fetch(1763 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2763 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2764 */
} /* line 2764 */
  sim_icache_fetch(1765 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2766 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2767 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2768 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2769 */
} /* line 2769 */
  sim_icache_fetch(1769 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2771 */
} /* line 2771 */
  sim_icache_fetch(1770 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_10939Xbuf),0,1), reg_r0_2); /* line 2773 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2774 */
  sim_icache_fetch(1773 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2776 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2777 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2778 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2779 */
} /* line 2779 */
l_L168X3: ;/* line 2781 */
__LABEL(l_L168X3);
  sim_icache_fetch(1777 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2782 */
   __MOV(reg_r0_3, (unsigned int) compress_10939Xbuf); /* line 2783 */
} /* line 2783 */
  sim_icache_fetch(1780 + t_thisfile.offset, 1);
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
} /* line 2785 */
  sim_icache_fetch(1781 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2787 */
} /* line 2787 */
l_L169X3: ;/* line 2789 */
__LABEL(l_L169X3);
  sim_icache_fetch(1782 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 2790 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2791 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2792 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2793 */
   __ADD_CYCLES(1);
} /* line 2793 */
  sim_icache_fetch(1789 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2795 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2796 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2797 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2798 */
} /* line 2798 */
  sim_icache_fetch(1793 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_10939Xoffset,0,4), reg_r0_2); /* line 2800 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2801 */
} /* line 2801 */
  sim_icache_fetch(1796 + t_thisfile.offset, 1);
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
} /* line 2803 */
  sim_icache_fetch(1797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2805 */
} /* line 2805 */
l_L171X3: ;/* line 2808 */
__LABEL(l_L171X3);
  sim_icache_fetch(1799 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2809 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2810 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2811 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2812 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2813 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2814 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2815 */
} /* line 2815 */
  sim_icache_fetch(1807 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2817 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2818 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2819 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -16); /* line 2820 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 16); /* line 2821 */
} /* line 2821 */
  sim_icache_fetch(1812 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2823 */
} /* line 2823 */
  sim_icache_fetch(1813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2825 */
} /* line 2825 */
  sim_icache_fetch(1815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2827 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2828 */
  sim_icache_fetch(1817 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2830 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2831 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2832 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2833 */
   __ADD_CYCLES(1);
} /* line 2833 */
  sim_icache_fetch(1822 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2835 */
} /* line 2835 */
  sim_icache_fetch(1823 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2837 */
} /* line 2837 */
  sim_icache_fetch(1825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2839 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2840 */
  sim_icache_fetch(1827 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2842 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2843 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2844 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2845 */
   __ADD_CYCLES(1);
} /* line 2845 */
  sim_icache_fetch(1832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2847 */
} /* line 2847 */
  sim_icache_fetch(1833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2849 */
} /* line 2849 */
  sim_icache_fetch(1835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2851 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2852 */
  sim_icache_fetch(1837 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2854 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2855 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2856 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2857 */
   __ADD_CYCLES(1);
} /* line 2857 */
  sim_icache_fetch(1842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2859 */
} /* line 2859 */
  sim_icache_fetch(1843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2861 */
} /* line 2861 */
  sim_icache_fetch(1845 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2863 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2864 */
  sim_icache_fetch(1847 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2866 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2867 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2868 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2869 */
   __ADD_CYCLES(1);
} /* line 2869 */
  sim_icache_fetch(1852 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2871 */
} /* line 2871 */
  sim_icache_fetch(1853 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2873 */
} /* line 2873 */
  sim_icache_fetch(1855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2875 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2876 */
  sim_icache_fetch(1857 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2878 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2879 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2880 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2881 */
   __ADD_CYCLES(1);
} /* line 2881 */
  sim_icache_fetch(1862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2883 */
} /* line 2883 */
  sim_icache_fetch(1863 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2885 */
} /* line 2885 */
  sim_icache_fetch(1865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2887 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2888 */
  sim_icache_fetch(1867 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2890 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2891 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2892 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2893 */
   __ADD_CYCLES(1);
} /* line 2893 */
  sim_icache_fetch(1872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2895 */
} /* line 2895 */
  sim_icache_fetch(1873 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2897 */
} /* line 2897 */
  sim_icache_fetch(1875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2899 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2900 */
  sim_icache_fetch(1877 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2902 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2903 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2904 */
   __ADD(reg_r0_5, reg_r0_7, (unsigned int) -16); /* line 2905 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2906 */
   __ADD_CYCLES(1);
} /* line 2906 */
  sim_icache_fetch(1883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2908 */
} /* line 2908 */
  sim_icache_fetch(1884 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2910 */
} /* line 2910 */
  sim_icache_fetch(1886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2912 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2913 */
  sim_icache_fetch(1888 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2915 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2916 */
   __CMPEQ(reg_b0_7, reg_r0_7, 0); /* line 2917 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2918 */
   __ADD_CYCLES(1);
} /* line 2918 */
  sim_icache_fetch(1893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2920 */
} /* line 2920 */
  sim_icache_fetch(1894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2922 */
} /* line 2922 */
  sim_icache_fetch(1896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2924 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2925 */
  sim_icache_fetch(1898 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2927 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2928 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2929 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2930 */
   __ADD_CYCLES(1);
} /* line 2930 */
  sim_icache_fetch(1903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2932 */
} /* line 2932 */
  sim_icache_fetch(1904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2934 */
} /* line 2934 */
  sim_icache_fetch(1906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2936 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2937 */
  sim_icache_fetch(1908 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 2939 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2940 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2941 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2942 */
   __ADD_CYCLES(1);
} /* line 2942 */
  sim_icache_fetch(1913 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2944 */
} /* line 2944 */
  sim_icache_fetch(1914 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2946 */
} /* line 2946 */
  sim_icache_fetch(1916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2948 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2949 */
  sim_icache_fetch(1918 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 2951 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2952 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2953 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2954 */
   __ADD_CYCLES(1);
} /* line 2954 */
  sim_icache_fetch(1923 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2956 */
} /* line 2956 */
  sim_icache_fetch(1924 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2958 */
} /* line 2958 */
  sim_icache_fetch(1926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2960 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2961 */
  sim_icache_fetch(1928 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 2963 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2964 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 4); /* line 2965 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2966 */
   __ADD_CYCLES(1);
} /* line 2966 */
  sim_icache_fetch(1933 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2968 */
} /* line 2968 */
  sim_icache_fetch(1934 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2970 */
} /* line 2970 */
  sim_icache_fetch(1936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2972 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2973 */
  sim_icache_fetch(1938 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 2975 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2976 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 5); /* line 2977 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2978 */
   __ADD_CYCLES(1);
} /* line 2978 */
  sim_icache_fetch(1943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2980 */
} /* line 2980 */
  sim_icache_fetch(1944 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2982 */
} /* line 2982 */
  sim_icache_fetch(1946 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2984 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2985 */
  sim_icache_fetch(1948 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 2987 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2988 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 6); /* line 2989 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2990 */
   __ADD_CYCLES(1);
} /* line 2990 */
  sim_icache_fetch(1953 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2992 */
} /* line 2992 */
  sim_icache_fetch(1954 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2994 */
} /* line 2994 */
  sim_icache_fetch(1956 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2996 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2997 */
  sim_icache_fetch(1958 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 2999 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3000 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 7); /* line 3001 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3002 */
   __ADD_CYCLES(1);
} /* line 3002 */
  sim_icache_fetch(1963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3004 */
} /* line 3004 */
  sim_icache_fetch(1964 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3006 */
} /* line 3006 */
  sim_icache_fetch(1966 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3008 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3009 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3010 */
  sim_icache_fetch(1969 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 3012 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3013 */
   __CMPEQ(reg_b0_7, reg_r0_7, (unsigned int) 8); /* line 3014 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) 16); /* line 3015 */
   __MFB(reg_r0_8, t__i32_0); /* line 3016 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3017 */
   __ADD_CYCLES(1);
} /* line 3017 */
  sim_icache_fetch(1976 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3019 */
} /* line 3019 */
  sim_icache_fetch(1977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3021 */
} /* line 3021 */
  sim_icache_fetch(1979 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3023 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3024 */
  sim_icache_fetch(1981 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 3026 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3027 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 9); /* line 3028 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3029 */
   __ADD_CYCLES(1);
} /* line 3029 */
  sim_icache_fetch(1986 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3031 */
} /* line 3031 */
  sim_icache_fetch(1987 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3033 */
} /* line 3033 */
  sim_icache_fetch(1989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3035 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3036 */
  sim_icache_fetch(1991 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 2),0,1)); /* line 3038 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3039 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 10); /* line 3040 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3041 */
   __ADD_CYCLES(1);
} /* line 3041 */
  sim_icache_fetch(1996 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3043 */
} /* line 3043 */
  sim_icache_fetch(1997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3045 */
} /* line 3045 */
  sim_icache_fetch(1999 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3047 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3048 */
  sim_icache_fetch(2001 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 3),0,1)); /* line 3050 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3051 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 11); /* line 3052 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3053 */
   __ADD_CYCLES(1);
} /* line 3053 */
  sim_icache_fetch(2006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3055 */
} /* line 3055 */
  sim_icache_fetch(2007 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3057 */
} /* line 3057 */
  sim_icache_fetch(2009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3059 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3060 */
  sim_icache_fetch(2011 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 4),0,1)); /* line 3062 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3063 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 12); /* line 3064 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3065 */
   __ADD_CYCLES(1);
} /* line 3065 */
  sim_icache_fetch(2016 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3067 */
} /* line 3067 */
  sim_icache_fetch(2017 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3069 */
} /* line 3069 */
  sim_icache_fetch(2019 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3071 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3072 */
  sim_icache_fetch(2021 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 5),0,1)); /* line 3074 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3075 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 13); /* line 3076 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3077 */
   __ADD_CYCLES(1);
} /* line 3077 */
  sim_icache_fetch(2026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3079 */
} /* line 3079 */
  sim_icache_fetch(2027 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3081 */
} /* line 3081 */
  sim_icache_fetch(2029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3083 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3084 */
  sim_icache_fetch(2031 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 6),0,1)); /* line 3086 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3087 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 14); /* line 3088 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3089 */
   __ADD_CYCLES(1);
} /* line 3089 */
  sim_icache_fetch(2036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3091 */
} /* line 3091 */
  sim_icache_fetch(2037 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3093 */
} /* line 3093 */
  sim_icache_fetch(2039 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3095 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3096 */
  sim_icache_fetch(2041 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 7),0,1)); /* line 3098 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3099 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 15); /* line 3100 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3101 */
   __ADD_CYCLES(1);
} /* line 3101 */
  sim_icache_fetch(2046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3103 */
} /* line 3103 */
  sim_icache_fetch(2047 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3105 */
} /* line 3105 */
  sim_icache_fetch(2049 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3107 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3108 */
  sim_icache_fetch(2051 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 8),0,1)); /* line 3110 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3111 */
   __MTB(reg_b0_7, reg_r0_8); /* line 3112 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3113 */
   __ADD_CYCLES(1);
} /* line 3113 */
  sim_icache_fetch(2056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3115 */
} /* line 3115 */
  sim_icache_fetch(2057 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3117 */
} /* line 3117 */
  sim_icache_fetch(2059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3119 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3120 */
  sim_icache_fetch(2061 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 9),0,1)); /* line 3122 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3123 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3124 */
   __ADD_CYCLES(1);
} /* line 3124 */
  sim_icache_fetch(2065 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3126 */
} /* line 3126 */
  sim_icache_fetch(2066 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3128 */
} /* line 3128 */
  sim_icache_fetch(2068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3130 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3131 */
  sim_icache_fetch(2070 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 10),0,1)); /* line 3133 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3134 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3135 */
   __ADD_CYCLES(1);
} /* line 3135 */
  sim_icache_fetch(2074 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3137 */
} /* line 3137 */
  sim_icache_fetch(2075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3139 */
} /* line 3139 */
  sim_icache_fetch(2077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3141 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3142 */
  sim_icache_fetch(2079 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 11),0,1)); /* line 3144 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3145 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3146 */
   __ADD_CYCLES(1);
} /* line 3146 */
  sim_icache_fetch(2083 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3148 */
} /* line 3148 */
  sim_icache_fetch(2084 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3150 */
} /* line 3150 */
  sim_icache_fetch(2086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3152 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3153 */
  sim_icache_fetch(2088 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 12),0,1)); /* line 3155 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3156 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3157 */
   __ADD_CYCLES(1);
} /* line 3157 */
  sim_icache_fetch(2092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3159 */
} /* line 3159 */
  sim_icache_fetch(2093 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3161 */
} /* line 3161 */
  sim_icache_fetch(2095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3163 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3164 */
  sim_icache_fetch(2097 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 13),0,1)); /* line 3166 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3167 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3168 */
   __ADD_CYCLES(1);
} /* line 3168 */
  sim_icache_fetch(2101 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3170 */
} /* line 3170 */
  sim_icache_fetch(2102 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3172 */
} /* line 3172 */
  sim_icache_fetch(2104 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3174 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3175 */
  sim_icache_fetch(2106 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 14),0,1)); /* line 3177 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3178 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3179 */
   __ADD_CYCLES(1);
} /* line 3179 */
  sim_icache_fetch(2110 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3181 */
} /* line 3181 */
  sim_icache_fetch(2111 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3183 */
} /* line 3183 */
  sim_icache_fetch(2113 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3185 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3186 */
  sim_icache_fetch(2115 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 15),0,1)); /* line 3188 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3189 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3190 */
   __ADD_CYCLES(1);
} /* line 3190 */
  sim_icache_fetch(2119 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3192 */
} /* line 3192 */
  sim_icache_fetch(2120 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3194 */
} /* line 3194 */
  sim_icache_fetch(2122 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 3196 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3198 */
  sim_icache_fetch(2124 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L171X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L171X3;
} /* line 3200 */
l_L172X3: ;/* line 3203 */
__LABEL(l_L172X3);
  sim_icache_fetch(2125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_10939Xoffset,0,4), 0); /* line 3204 */
} /* line 3204 */
l_L170X3: ;/* line 3207 */
__LABEL(l_L170X3);
  sim_icache_fetch(2127 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3208 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3209 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3210 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3211 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3212 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3213 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3214 */
} /* line 3214 */
  sim_icache_fetch(2138 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3216 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3217 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3218 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3219 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3220 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3221 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3222 */
} /* line 3222 */
  sim_icache_fetch(2145 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3224 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3225 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3226 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3227 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3228 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3229 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3230 */
} /* line 3230 */
  sim_icache_fetch(2152 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3232 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3233 */
   __MOV(reg_r0_5, (unsigned int) compress_10939Xbuf); /* line 3234 */
   __MOV(reg_r0_3, 0); /* line 3235 */
} /* line 3235 */
  sim_icache_fetch(2157 + t_thisfile.offset, 1);
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
} /* line 3237 */
  sim_icache_fetch(2158 + t_thisfile.offset, 1);
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
} /* line 3239 */
l_L175X3: ;/* line 3242 */
__LABEL(l_L175X3);
  sim_icache_fetch(2159 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3243 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3244 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3245 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3246 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3247 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3248 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3249 */
} /* line 3249 */
  sim_icache_fetch(2168 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3251 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3252 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3253 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3254 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3255 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3256 */
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3257 */
} /* line 3257 */
  sim_icache_fetch(2175 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3259 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3260 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3261 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3262 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3263 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3264 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3265 */
} /* line 3265 */
  sim_icache_fetch(2182 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3267 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L176X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3268 */
  sim_icache_fetch(2184 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3270 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3271 */
} /* line 3271 */
  sim_icache_fetch(2187 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3273 */
} /* line 3273 */
  sim_icache_fetch(2188 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3275 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3276 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3277 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3278 */
   __ADD_CYCLES(1);
} /* line 3278 */
  sim_icache_fetch(2194 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 3280 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3281 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3282 */
} /* line 3282 */
  sim_icache_fetch(2197 + t_thisfile.offset, 1);
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
} /* line 3284 */
  sim_icache_fetch(2198 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3286 */
} /* line 3286 */
  sim_icache_fetch(2200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3288 */
} /* line 3288 */
  sim_icache_fetch(2201 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3290 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3291 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3292 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3293 */
   __ADD_CYCLES(1);
} /* line 3293 */
  sim_icache_fetch(2207 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 3295 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3296 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3297 */
} /* line 3297 */
  sim_icache_fetch(2210 + t_thisfile.offset, 1);
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
} /* line 3299 */
  sim_icache_fetch(2211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3301 */
} /* line 3301 */
  sim_icache_fetch(2213 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3303 */
} /* line 3303 */
  sim_icache_fetch(2214 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3305 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3306 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3307 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3308 */
   __ADD_CYCLES(1);
} /* line 3308 */
  sim_icache_fetch(2220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 3310 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3311 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3312 */
} /* line 3312 */
  sim_icache_fetch(2223 + t_thisfile.offset, 1);
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
} /* line 3314 */
  sim_icache_fetch(2224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3316 */
} /* line 3316 */
  sim_icache_fetch(2226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3318 */
} /* line 3318 */
  sim_icache_fetch(2227 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3320 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3321 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3322 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3323 */
   __ADD_CYCLES(1);
} /* line 3323 */
  sim_icache_fetch(2233 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 3325 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3326 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3327 */
} /* line 3327 */
  sim_icache_fetch(2236 + t_thisfile.offset, 1);
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
} /* line 3329 */
  sim_icache_fetch(2237 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3331 */
} /* line 3331 */
  sim_icache_fetch(2239 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3333 */
} /* line 3333 */
  sim_icache_fetch(2240 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3335 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3336 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3337 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3338 */
   __ADD_CYCLES(1);
} /* line 3338 */
  sim_icache_fetch(2246 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 3340 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3341 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3342 */
} /* line 3342 */
  sim_icache_fetch(2249 + t_thisfile.offset, 1);
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
} /* line 3344 */
  sim_icache_fetch(2250 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3346 */
} /* line 3346 */
  sim_icache_fetch(2252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3348 */
} /* line 3348 */
  sim_icache_fetch(2253 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3350 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3351 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3352 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3353 */
   __ADD_CYCLES(1);
} /* line 3353 */
  sim_icache_fetch(2259 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 3355 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3356 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3357 */
} /* line 3357 */
  sim_icache_fetch(2262 + t_thisfile.offset, 1);
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
} /* line 3359 */
  sim_icache_fetch(2263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3361 */
} /* line 3361 */
  sim_icache_fetch(2265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3363 */
} /* line 3363 */
  sim_icache_fetch(2266 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3365 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3366 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3367 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3368 */
   __ADD_CYCLES(1);
} /* line 3368 */
  sim_icache_fetch(2272 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 3370 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3371 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3372 */
} /* line 3372 */
  sim_icache_fetch(2275 + t_thisfile.offset, 1);
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
} /* line 3374 */
  sim_icache_fetch(2276 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3376 */
} /* line 3376 */
  sim_icache_fetch(2278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3378 */
} /* line 3378 */
  sim_icache_fetch(2279 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3380 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3381 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3382 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3383 */
   __ADD_CYCLES(1);
} /* line 3383 */
  sim_icache_fetch(2285 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 3385 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3386 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3387 */
} /* line 3387 */
  sim_icache_fetch(2288 + t_thisfile.offset, 1);
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
} /* line 3389 */
  sim_icache_fetch(2289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3391 */
} /* line 3391 */
  sim_icache_fetch(2291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3393 */
} /* line 3393 */
  sim_icache_fetch(2292 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3395 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3396 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3397 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3398 */
   __ADD_CYCLES(1);
} /* line 3398 */
  sim_icache_fetch(2298 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 3400 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3401 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3402 */
} /* line 3402 */
  sim_icache_fetch(2301 + t_thisfile.offset, 1);
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
} /* line 3404 */
  sim_icache_fetch(2302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3406 */
} /* line 3406 */
  sim_icache_fetch(2304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3408 */
} /* line 3408 */
  sim_icache_fetch(2305 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3410 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3411 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3412 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3413 */
   __ADD_CYCLES(1);
} /* line 3413 */
  sim_icache_fetch(2311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 3415 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3416 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3417 */
} /* line 3417 */
  sim_icache_fetch(2314 + t_thisfile.offset, 1);
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
} /* line 3419 */
  sim_icache_fetch(2315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3421 */
} /* line 3421 */
  sim_icache_fetch(2317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3423 */
} /* line 3423 */
  sim_icache_fetch(2318 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3425 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3426 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3427 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3428 */
   __ADD_CYCLES(1);
} /* line 3428 */
  sim_icache_fetch(2324 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 3430 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3431 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3432 */
} /* line 3432 */
  sim_icache_fetch(2327 + t_thisfile.offset, 1);
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
} /* line 3434 */
  sim_icache_fetch(2328 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3436 */
} /* line 3436 */
  sim_icache_fetch(2330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3438 */
} /* line 3438 */
  sim_icache_fetch(2331 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3440 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3441 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3442 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3443 */
   __ADD_CYCLES(1);
} /* line 3443 */
  sim_icache_fetch(2337 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 3445 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3446 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3447 */
} /* line 3447 */
  sim_icache_fetch(2340 + t_thisfile.offset, 1);
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
} /* line 3449 */
  sim_icache_fetch(2341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3451 */
} /* line 3451 */
  sim_icache_fetch(2343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3453 */
} /* line 3453 */
  sim_icache_fetch(2344 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3455 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3456 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3457 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3458 */
   __ADD_CYCLES(1);
} /* line 3458 */
  sim_icache_fetch(2350 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 3460 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3461 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3462 */
} /* line 3462 */
  sim_icache_fetch(2353 + t_thisfile.offset, 1);
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
} /* line 3464 */
  sim_icache_fetch(2354 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3466 */
} /* line 3466 */
  sim_icache_fetch(2356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3468 */
} /* line 3468 */
  sim_icache_fetch(2357 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3470 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3471 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3472 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3473 */
   __ADD_CYCLES(1);
} /* line 3473 */
  sim_icache_fetch(2363 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_2); /* line 3475 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3476 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3477 */
} /* line 3477 */
  sim_icache_fetch(2366 + t_thisfile.offset, 1);
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
} /* line 3479 */
  sim_icache_fetch(2367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3481 */
} /* line 3481 */
  sim_icache_fetch(2369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3483 */
} /* line 3483 */
  sim_icache_fetch(2370 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3485 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3486 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3487 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3488 */
   __ADD_CYCLES(1);
} /* line 3488 */
  sim_icache_fetch(2376 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_2); /* line 3490 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3491 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3492 */
} /* line 3492 */
  sim_icache_fetch(2379 + t_thisfile.offset, 1);
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
} /* line 3494 */
  sim_icache_fetch(2380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3496 */
} /* line 3496 */
  sim_icache_fetch(2382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_5); /* line 3498 */
} /* line 3498 */
  sim_icache_fetch(2383 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3500 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_37,0,1)); /* line 3501 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3502 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3503 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3504 */
   __ADD_CYCLES(1);
} /* line 3504 */
  sim_icache_fetch(2390 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3506 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3507 */
   __MOV(reg_r0_3, reg_r0_38); /* line 3508 */
} /* line 3508 */
  sim_icache_fetch(2393 + t_thisfile.offset, 1);
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
  sim_icache_fetch(2394 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3512 */
} /* line 3512 */
  sim_icache_fetch(2396 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3514 */
} /* line 3514 */
  sim_icache_fetch(2397 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3516 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3517 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3518 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3519 */
   __ADD_CYCLES(1);
} /* line 3519 */
  sim_icache_fetch(2403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3521 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3522 */
} /* line 3522 */
  sim_icache_fetch(2405 + t_thisfile.offset, 1);
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
} /* line 3524 */
  sim_icache_fetch(2406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3526 */
} /* line 3526 */
  sim_icache_fetch(2408 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3528 */
} /* line 3528 */
  sim_icache_fetch(2409 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3530 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3531 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3532 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3533 */
   __ADD_CYCLES(1);
} /* line 3533 */
  sim_icache_fetch(2415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3535 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3536 */
} /* line 3536 */
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
} /* line 3538 */
  sim_icache_fetch(2418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3540 */
} /* line 3540 */
  sim_icache_fetch(2420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3542 */
} /* line 3542 */
  sim_icache_fetch(2421 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3544 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3545 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3546 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3547 */
   __ADD_CYCLES(1);
} /* line 3547 */
  sim_icache_fetch(2427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3549 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3550 */
} /* line 3550 */
  sim_icache_fetch(2429 + t_thisfile.offset, 1);
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
} /* line 3552 */
  sim_icache_fetch(2430 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3554 */
} /* line 3554 */
  sim_icache_fetch(2432 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3556 */
} /* line 3556 */
  sim_icache_fetch(2433 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3558 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3559 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3560 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3561 */
   __ADD_CYCLES(1);
} /* line 3561 */
  sim_icache_fetch(2439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3563 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3564 */
} /* line 3564 */
  sim_icache_fetch(2441 + t_thisfile.offset, 1);
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
} /* line 3566 */
  sim_icache_fetch(2442 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3568 */
} /* line 3568 */
  sim_icache_fetch(2444 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3570 */
} /* line 3570 */
  sim_icache_fetch(2445 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3572 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3573 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3574 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3575 */
   __ADD_CYCLES(1);
} /* line 3575 */
  sim_icache_fetch(2451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3577 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3578 */
} /* line 3578 */
  sim_icache_fetch(2453 + t_thisfile.offset, 1);
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
} /* line 3580 */
  sim_icache_fetch(2454 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3582 */
} /* line 3582 */
  sim_icache_fetch(2456 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3584 */
} /* line 3584 */
  sim_icache_fetch(2457 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3586 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3587 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3588 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3589 */
   __ADD_CYCLES(1);
} /* line 3589 */
  sim_icache_fetch(2463 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3591 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3592 */
} /* line 3592 */
  sim_icache_fetch(2465 + t_thisfile.offset, 1);
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
} /* line 3594 */
  sim_icache_fetch(2466 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3596 */
} /* line 3596 */
  sim_icache_fetch(2468 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3598 */
} /* line 3598 */
  sim_icache_fetch(2469 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3600 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3601 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3602 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3603 */
   __ADD_CYCLES(1);
} /* line 3603 */
  sim_icache_fetch(2475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3605 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3606 */
} /* line 3606 */
  sim_icache_fetch(2477 + t_thisfile.offset, 1);
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
} /* line 3608 */
  sim_icache_fetch(2478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3610 */
} /* line 3610 */
  sim_icache_fetch(2480 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3612 */
} /* line 3612 */
  sim_icache_fetch(2481 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3614 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3615 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3616 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3617 */
   __ADD_CYCLES(1);
} /* line 3617 */
  sim_icache_fetch(2487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3619 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3620 */
} /* line 3620 */
  sim_icache_fetch(2489 + t_thisfile.offset, 1);
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
} /* line 3622 */
  sim_icache_fetch(2490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3624 */
} /* line 3624 */
  sim_icache_fetch(2492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3626 */
} /* line 3626 */
  sim_icache_fetch(2493 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3628 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3629 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3630 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3631 */
   __ADD_CYCLES(1);
} /* line 3631 */
  sim_icache_fetch(2499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3633 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3634 */
} /* line 3634 */
  sim_icache_fetch(2501 + t_thisfile.offset, 1);
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
} /* line 3636 */
  sim_icache_fetch(2502 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3638 */
} /* line 3638 */
  sim_icache_fetch(2504 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3640 */
} /* line 3640 */
  sim_icache_fetch(2505 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3642 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3643 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3644 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3645 */
   __ADD_CYCLES(1);
} /* line 3645 */
  sim_icache_fetch(2511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3647 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3648 */
} /* line 3648 */
  sim_icache_fetch(2513 + t_thisfile.offset, 1);
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
} /* line 3650 */
  sim_icache_fetch(2514 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3652 */
} /* line 3652 */
  sim_icache_fetch(2516 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3654 */
} /* line 3654 */
  sim_icache_fetch(2517 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3656 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3657 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3658 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3659 */
   __ADD_CYCLES(1);
} /* line 3659 */
  sim_icache_fetch(2523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3661 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3662 */
} /* line 3662 */
  sim_icache_fetch(2525 + t_thisfile.offset, 1);
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
} /* line 3664 */
  sim_icache_fetch(2526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3666 */
} /* line 3666 */
  sim_icache_fetch(2528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3668 */
} /* line 3668 */
  sim_icache_fetch(2529 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3670 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3671 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3672 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3673 */
   __ADD_CYCLES(1);
} /* line 3673 */
  sim_icache_fetch(2535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3675 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3676 */
} /* line 3676 */
  sim_icache_fetch(2537 + t_thisfile.offset, 1);
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
} /* line 3678 */
  sim_icache_fetch(2538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3680 */
} /* line 3680 */
  sim_icache_fetch(2540 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3682 */
} /* line 3682 */
  sim_icache_fetch(2541 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3684 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3685 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3686 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3687 */
   __ADD_CYCLES(1);
} /* line 3687 */
  sim_icache_fetch(2547 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3689 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3690 */
} /* line 3690 */
  sim_icache_fetch(2549 + t_thisfile.offset, 1);
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
} /* line 3692 */
  sim_icache_fetch(2550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3694 */
} /* line 3694 */
  sim_icache_fetch(2552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3696 */
} /* line 3696 */
  sim_icache_fetch(2553 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3698 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3699 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3700 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3701 */
   __ADD_CYCLES(1);
} /* line 3701 */
  sim_icache_fetch(2559 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3703 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3704 */
} /* line 3704 */
  sim_icache_fetch(2561 + t_thisfile.offset, 1);
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
} /* line 3706 */
  sim_icache_fetch(2562 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3708 */
} /* line 3708 */
  sim_icache_fetch(2564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3710 */
} /* line 3710 */
  sim_icache_fetch(2565 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3712 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3713 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3714 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3715 */
   __ADD_CYCLES(1);
} /* line 3715 */
  sim_icache_fetch(2571 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3717 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3718 */
} /* line 3718 */
  sim_icache_fetch(2573 + t_thisfile.offset, 1);
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
} /* line 3720 */
  sim_icache_fetch(2574 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3722 */
} /* line 3722 */
  sim_icache_fetch(2576 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3724 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 3725 */
l_L176X3: ;/* line 3728 */
__LABEL(l_L176X3);
  sim_icache_fetch(2578 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3729 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3730 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3731 */
   __ADD_CYCLES(1);
} /* line 3731 */
  sim_icache_fetch(2583 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3733 */
} /* line 3733 */
  sim_icache_fetch(2584 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3735 */
} /* line 3735 */
l_L174X3: ;/* line 3738 */
__LABEL(l_L174X3);
  sim_icache_fetch(2586 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_10939Xoffset,0,4), 0); /* line 3739 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3740 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3741 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3742 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3743 */
   __ADD_CYCLES(1);
} /* line 3743 */
  sim_icache_fetch(2594 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3745 */
} /* line 3745 */
  sim_icache_fetch(2595 + t_thisfile.offset, 1);
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
} /* line 3747 */
  sim_icache_fetch(2596 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3750 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3751 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3752 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3753 */
l_L177X3: ;/* line 3756 */
__LABEL(l_L177X3);
  sim_icache_fetch(2603 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3757 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3758 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3759 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3760 */
   __ADD_CYCLES(1);
} /* line 3760 */
  sim_icache_fetch(2610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3762 */
} /* line 3762 */
  sim_icache_fetch(2611 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3764 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3765 */
} /* line 3765 */
  sim_icache_fetch(2614 + t_thisfile.offset, 1);
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
} /* line 3767 */
  sim_icache_fetch(2615 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3770 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3771 */
l_L178X3: ;/* line 3774 */
__LABEL(l_L178X3);
  sim_icache_fetch(2618 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3775 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3776 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3777 */
   __ADD_CYCLES(1);
} /* line 3777 */
  sim_icache_fetch(2622 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3779 */
} /* line 3779 */
  sim_icache_fetch(2623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3781 */
} /* line 3781 */
  sim_icache_fetch(2624 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3784 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3785 */
l_L173X3: ;/* line 3788 */
__LABEL(l_L173X3);
  sim_icache_fetch(2627 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3790 */
l_L167X3: ;/* line 3793 */
__LABEL(l_L167X3);
  sim_icache_fetch(2628 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3794 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3795 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3796 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3797 */
   __ADD_CYCLES(1);
} /* line 3797 */
  sim_icache_fetch(2635 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3799 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3800 */
} /* line 3800 */
  sim_icache_fetch(2637 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3802 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3803 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3804 */
l_L180X3: ;/* line 3806 */
__LABEL(l_L180X3);
  sim_icache_fetch(2640 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3807 */
   __STW(mem_trace_st((unsigned int) compress_10939Xoffset,0,4), 0); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(2643 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3810 */
} /* line 3810 */
  sim_icache_fetch(2644 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3812 */
} /* line 3812 */
  sim_icache_fetch(2645 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3815 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3816 */
l_L179X3: ;/* line 3819 */
__LABEL(l_L179X3);
  sim_icache_fetch(2648 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3820 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3821 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3822 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3823 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3824 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3825 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3826 */
} /* line 3826 */
  sim_icache_fetch(2655 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3828 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3829 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3830 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3831 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3832 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3833 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3834 */
} /* line 3834 */
  sim_icache_fetch(2662 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3836 */
   __MOV(reg_r0_5, (unsigned int) compress_10939Xbuf); /* line 3837 */
   __MOV(reg_r0_3, 0); /* line 3838 */
} /* line 3838 */
l_L181X3: ;/* line 3841 */
__LABEL(l_L181X3);
  sim_icache_fetch(2666 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3842 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3843 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3844 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3845 */
   __ADD_CYCLES(1);
} /* line 3845 */
  sim_icache_fetch(2672 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3847 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3848 */
} /* line 3848 */
  sim_icache_fetch(2674 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3850 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3851 */
} /* line 3851 */
  sim_icache_fetch(2676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3853 */
} /* line 3853 */
  sim_icache_fetch(2677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3855 */
} /* line 3855 */
  sim_icache_fetch(2678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3857 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3858 */
} /* line 3858 */
  sim_icache_fetch(2680 + t_thisfile.offset, 1);
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
} /* line 3860 */
  sim_icache_fetch(2681 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3862 */
} /* line 3862 */
  sim_icache_fetch(2683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3864 */
} /* line 3864 */
  sim_icache_fetch(2684 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3866 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3867 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3868 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3869 */
   __ADD_CYCLES(1);
} /* line 3869 */
  sim_icache_fetch(2690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3871 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3872 */
} /* line 3872 */
  sim_icache_fetch(2692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3874 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3875 */
} /* line 3875 */
  sim_icache_fetch(2694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3877 */
} /* line 3877 */
  sim_icache_fetch(2695 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3879 */
} /* line 3879 */
  sim_icache_fetch(2696 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3881 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3882 */
} /* line 3882 */
  sim_icache_fetch(2698 + t_thisfile.offset, 1);
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
} /* line 3884 */
  sim_icache_fetch(2699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3886 */
} /* line 3886 */
  sim_icache_fetch(2701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3888 */
} /* line 3888 */
  sim_icache_fetch(2702 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3890 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3891 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3892 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3893 */
   __ADD_CYCLES(1);
} /* line 3893 */
  sim_icache_fetch(2708 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3895 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3896 */
} /* line 3896 */
  sim_icache_fetch(2710 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3898 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3899 */
} /* line 3899 */
  sim_icache_fetch(2712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3901 */
} /* line 3901 */
  sim_icache_fetch(2713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3903 */
} /* line 3903 */
  sim_icache_fetch(2714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3905 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3906 */
} /* line 3906 */
  sim_icache_fetch(2716 + t_thisfile.offset, 1);
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
} /* line 3908 */
  sim_icache_fetch(2717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3910 */
} /* line 3910 */
  sim_icache_fetch(2719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3912 */
} /* line 3912 */
  sim_icache_fetch(2720 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3914 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3915 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3916 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3917 */
   __ADD_CYCLES(1);
} /* line 3917 */
  sim_icache_fetch(2726 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3919 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3920 */
} /* line 3920 */
  sim_icache_fetch(2728 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3922 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3923 */
} /* line 3923 */
  sim_icache_fetch(2730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3925 */
} /* line 3925 */
  sim_icache_fetch(2731 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3927 */
} /* line 3927 */
  sim_icache_fetch(2732 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3929 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3930 */
} /* line 3930 */
  sim_icache_fetch(2734 + t_thisfile.offset, 1);
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
} /* line 3932 */
  sim_icache_fetch(2735 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3934 */
} /* line 3934 */
  sim_icache_fetch(2737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3936 */
} /* line 3936 */
  sim_icache_fetch(2738 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3938 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3939 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3940 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3941 */
   __ADD_CYCLES(1);
} /* line 3941 */
  sim_icache_fetch(2744 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3943 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3944 */
} /* line 3944 */
  sim_icache_fetch(2746 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3946 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3947 */
} /* line 3947 */
  sim_icache_fetch(2748 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3949 */
} /* line 3949 */
  sim_icache_fetch(2749 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3951 */
} /* line 3951 */
  sim_icache_fetch(2750 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 3953 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3954 */
} /* line 3954 */
  sim_icache_fetch(2752 + t_thisfile.offset, 1);
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
} /* line 3956 */
  sim_icache_fetch(2753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3958 */
} /* line 3958 */
  sim_icache_fetch(2755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3960 */
} /* line 3960 */
  sim_icache_fetch(2756 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3962 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3963 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3964 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3965 */
   __ADD_CYCLES(1);
} /* line 3965 */
  sim_icache_fetch(2762 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3967 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3968 */
} /* line 3968 */
  sim_icache_fetch(2764 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3970 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3971 */
} /* line 3971 */
  sim_icache_fetch(2766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3973 */
} /* line 3973 */
  sim_icache_fetch(2767 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3975 */
} /* line 3975 */
  sim_icache_fetch(2768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 3977 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3978 */
} /* line 3978 */
  sim_icache_fetch(2770 + t_thisfile.offset, 1);
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
} /* line 3980 */
  sim_icache_fetch(2771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3982 */
} /* line 3982 */
  sim_icache_fetch(2773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3984 */
} /* line 3984 */
  sim_icache_fetch(2774 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 3986 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3987 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3988 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3989 */
   __ADD_CYCLES(1);
} /* line 3989 */
  sim_icache_fetch(2780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3991 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3992 */
} /* line 3992 */
  sim_icache_fetch(2782 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3994 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3995 */
} /* line 3995 */
  sim_icache_fetch(2784 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3997 */
} /* line 3997 */
  sim_icache_fetch(2785 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3999 */
} /* line 3999 */
  sim_icache_fetch(2786 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 4001 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 4002 */
} /* line 4002 */
  sim_icache_fetch(2788 + t_thisfile.offset, 1);
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
} /* line 4004 */
  sim_icache_fetch(2789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4006 */
} /* line 4006 */
  sim_icache_fetch(2791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4008 */
} /* line 4008 */
  sim_icache_fetch(2792 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4010 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4011 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4012 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4013 */
   __ADD_CYCLES(1);
} /* line 4013 */
  sim_icache_fetch(2798 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4015 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4016 */
} /* line 4016 */
  sim_icache_fetch(2800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4018 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4019 */
} /* line 4019 */
  sim_icache_fetch(2802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4021 */
} /* line 4021 */
  sim_icache_fetch(2803 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4023 */
} /* line 4023 */
  sim_icache_fetch(2804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4025 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4026 */
} /* line 4026 */
  sim_icache_fetch(2806 + t_thisfile.offset, 1);
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
} /* line 4028 */
  sim_icache_fetch(2807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4030 */
} /* line 4030 */
  sim_icache_fetch(2809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4032 */
} /* line 4032 */
  sim_icache_fetch(2810 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4034 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4035 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4036 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4037 */
   __ADD_CYCLES(1);
} /* line 4037 */
  sim_icache_fetch(2816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4039 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4040 */
} /* line 4040 */
  sim_icache_fetch(2818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4042 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4043 */
} /* line 4043 */
  sim_icache_fetch(2820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4045 */
} /* line 4045 */
  sim_icache_fetch(2821 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4047 */
} /* line 4047 */
  sim_icache_fetch(2822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4049 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4050 */
} /* line 4050 */
  sim_icache_fetch(2824 + t_thisfile.offset, 1);
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
} /* line 4052 */
  sim_icache_fetch(2825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4054 */
} /* line 4054 */
  sim_icache_fetch(2827 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4056 */
} /* line 4056 */
  sim_icache_fetch(2828 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4058 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4059 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4060 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4061 */
   __ADD_CYCLES(1);
} /* line 4061 */
  sim_icache_fetch(2834 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4063 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4064 */
} /* line 4064 */
  sim_icache_fetch(2836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4066 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4067 */
} /* line 4067 */
  sim_icache_fetch(2838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4069 */
} /* line 4069 */
  sim_icache_fetch(2839 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4071 */
} /* line 4071 */
  sim_icache_fetch(2840 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4073 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4074 */
} /* line 4074 */
  sim_icache_fetch(2842 + t_thisfile.offset, 1);
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
} /* line 4076 */
  sim_icache_fetch(2843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4078 */
} /* line 4078 */
  sim_icache_fetch(2845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4080 */
} /* line 4080 */
  sim_icache_fetch(2846 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4082 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4083 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4084 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4085 */
   __ADD_CYCLES(1);
} /* line 4085 */
  sim_icache_fetch(2852 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4087 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4088 */
} /* line 4088 */
  sim_icache_fetch(2854 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4090 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4091 */
} /* line 4091 */
  sim_icache_fetch(2856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4093 */
} /* line 4093 */
  sim_icache_fetch(2857 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4095 */
} /* line 4095 */
  sim_icache_fetch(2858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4097 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4098 */
} /* line 4098 */
  sim_icache_fetch(2860 + t_thisfile.offset, 1);
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
} /* line 4100 */
  sim_icache_fetch(2861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4102 */
} /* line 4102 */
  sim_icache_fetch(2863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4104 */
} /* line 4104 */
  sim_icache_fetch(2864 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4106 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4107 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4108 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4109 */
   __ADD_CYCLES(1);
} /* line 4109 */
  sim_icache_fetch(2870 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4111 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4112 */
} /* line 4112 */
  sim_icache_fetch(2872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4114 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4115 */
} /* line 4115 */
  sim_icache_fetch(2874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4117 */
} /* line 4117 */
  sim_icache_fetch(2875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4119 */
} /* line 4119 */
  sim_icache_fetch(2876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4121 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4122 */
} /* line 4122 */
  sim_icache_fetch(2878 + t_thisfile.offset, 1);
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
} /* line 4124 */
  sim_icache_fetch(2879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4126 */
} /* line 4126 */
  sim_icache_fetch(2881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4128 */
} /* line 4128 */
  sim_icache_fetch(2882 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4130 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4131 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4132 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4133 */
   __ADD_CYCLES(1);
} /* line 4133 */
  sim_icache_fetch(2888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4135 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4136 */
} /* line 4136 */
  sim_icache_fetch(2890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4138 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4139 */
} /* line 4139 */
  sim_icache_fetch(2892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4141 */
} /* line 4141 */
  sim_icache_fetch(2893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4143 */
} /* line 4143 */
  sim_icache_fetch(2894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4145 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4146 */
} /* line 4146 */
  sim_icache_fetch(2896 + t_thisfile.offset, 1);
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
} /* line 4148 */
  sim_icache_fetch(2897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4150 */
} /* line 4150 */
  sim_icache_fetch(2899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4152 */
} /* line 4152 */
  sim_icache_fetch(2900 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4154 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4155 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4156 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4157 */
   __ADD_CYCLES(1);
} /* line 4157 */
  sim_icache_fetch(2906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4159 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4160 */
} /* line 4160 */
  sim_icache_fetch(2908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4162 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4163 */
} /* line 4163 */
  sim_icache_fetch(2910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4165 */
} /* line 4165 */
  sim_icache_fetch(2911 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4167 */
} /* line 4167 */
  sim_icache_fetch(2912 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4169 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4170 */
} /* line 4170 */
  sim_icache_fetch(2914 + t_thisfile.offset, 1);
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
} /* line 4172 */
  sim_icache_fetch(2915 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4174 */
} /* line 4174 */
  sim_icache_fetch(2917 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4176 */
} /* line 4176 */
  sim_icache_fetch(2918 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4178 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4179 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4180 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4181 */
   __ADD_CYCLES(1);
} /* line 4181 */
  sim_icache_fetch(2924 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4183 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4184 */
} /* line 4184 */
  sim_icache_fetch(2926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4186 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4187 */
} /* line 4187 */
  sim_icache_fetch(2928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4189 */
} /* line 4189 */
  sim_icache_fetch(2929 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4191 */
} /* line 4191 */
  sim_icache_fetch(2930 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4193 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4194 */
} /* line 4194 */
  sim_icache_fetch(2932 + t_thisfile.offset, 1);
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
} /* line 4196 */
  sim_icache_fetch(2933 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4198 */
} /* line 4198 */
  sim_icache_fetch(2935 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4200 */
} /* line 4200 */
  sim_icache_fetch(2936 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4202 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4203 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4204 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4205 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4206 */
   __ADD_CYCLES(1);
} /* line 4206 */
  sim_icache_fetch(2943 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4208 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4209 */
} /* line 4209 */
  sim_icache_fetch(2945 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4211 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4212 */
} /* line 4212 */
  sim_icache_fetch(2947 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4214 */
} /* line 4214 */
  sim_icache_fetch(2948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4216 */
} /* line 4216 */
  sim_icache_fetch(2949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4218 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4219 */
} /* line 4219 */
  sim_icache_fetch(2951 + t_thisfile.offset, 1);
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
} /* line 4221 */
  sim_icache_fetch(2952 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4223 */
} /* line 4223 */
  sim_icache_fetch(2954 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4225 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4226 */
l_L197X3: ;/* line 4229 */
__LABEL(l_L197X3);
  sim_icache_fetch(2956 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4230 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4231 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4232 */
   __ADD_CYCLES(1);
} /* line 4232 */
  sim_icache_fetch(2961 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4234 */
} /* line 4234 */
  sim_icache_fetch(2962 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4236 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4237 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4238 */
l_L196X3: ;/* line 4241 */
__LABEL(l_L196X3);
  sim_icache_fetch(2965 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4242 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4243 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4244 */
   __ADD_CYCLES(1);
} /* line 4244 */
  sim_icache_fetch(2970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4246 */
} /* line 4246 */
  sim_icache_fetch(2971 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4248 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4249 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4250 */
l_L195X3: ;/* line 4253 */
__LABEL(l_L195X3);
  sim_icache_fetch(2974 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4254 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4255 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4256 */
   __ADD_CYCLES(1);
} /* line 4256 */
  sim_icache_fetch(2979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4258 */
} /* line 4258 */
  sim_icache_fetch(2980 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4260 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4261 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4262 */
l_L194X3: ;/* line 4265 */
__LABEL(l_L194X3);
  sim_icache_fetch(2983 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4266 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4267 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4268 */
   __ADD_CYCLES(1);
} /* line 4268 */
  sim_icache_fetch(2988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4270 */
} /* line 4270 */
  sim_icache_fetch(2989 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4272 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4273 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4274 */
l_L193X3: ;/* line 4277 */
__LABEL(l_L193X3);
  sim_icache_fetch(2992 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4278 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4279 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4280 */
   __ADD_CYCLES(1);
} /* line 4280 */
  sim_icache_fetch(2997 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4282 */
} /* line 4282 */
  sim_icache_fetch(2998 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4284 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4285 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4286 */
l_L192X3: ;/* line 4289 */
__LABEL(l_L192X3);
  sim_icache_fetch(3001 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4290 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4291 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4292 */
   __ADD_CYCLES(1);
} /* line 4292 */
  sim_icache_fetch(3006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4294 */
} /* line 4294 */
  sim_icache_fetch(3007 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4296 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4297 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4298 */
l_L191X3: ;/* line 4301 */
__LABEL(l_L191X3);
  sim_icache_fetch(3010 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4302 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4303 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4304 */
   __ADD_CYCLES(1);
} /* line 4304 */
  sim_icache_fetch(3015 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4306 */
} /* line 4306 */
  sim_icache_fetch(3016 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4308 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4309 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4310 */
l_L190X3: ;/* line 4313 */
__LABEL(l_L190X3);
  sim_icache_fetch(3019 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4314 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4315 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4316 */
   __ADD_CYCLES(1);
} /* line 4316 */
  sim_icache_fetch(3024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4318 */
} /* line 4318 */
  sim_icache_fetch(3025 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4320 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4321 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4322 */
l_L189X3: ;/* line 4325 */
__LABEL(l_L189X3);
  sim_icache_fetch(3028 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4326 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4327 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4328 */
   __ADD_CYCLES(1);
} /* line 4328 */
  sim_icache_fetch(3033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4330 */
} /* line 4330 */
  sim_icache_fetch(3034 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4332 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4333 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4334 */
l_L188X3: ;/* line 4337 */
__LABEL(l_L188X3);
  sim_icache_fetch(3037 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4338 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4339 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4340 */
   __ADD_CYCLES(1);
} /* line 4340 */
  sim_icache_fetch(3042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4342 */
} /* line 4342 */
  sim_icache_fetch(3043 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4344 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4345 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4346 */
l_L187X3: ;/* line 4349 */
__LABEL(l_L187X3);
  sim_icache_fetch(3046 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4350 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4351 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4352 */
   __ADD_CYCLES(1);
} /* line 4352 */
  sim_icache_fetch(3051 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4354 */
} /* line 4354 */
  sim_icache_fetch(3052 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4356 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4357 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4358 */
l_L186X3: ;/* line 4361 */
__LABEL(l_L186X3);
  sim_icache_fetch(3055 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4362 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4363 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4364 */
   __ADD_CYCLES(1);
} /* line 4364 */
  sim_icache_fetch(3060 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4366 */
} /* line 4366 */
  sim_icache_fetch(3061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4368 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4369 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4370 */
l_L185X3: ;/* line 4373 */
__LABEL(l_L185X3);
  sim_icache_fetch(3064 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4374 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4375 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4376 */
   __ADD_CYCLES(1);
} /* line 4376 */
  sim_icache_fetch(3069 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4378 */
} /* line 4378 */
  sim_icache_fetch(3070 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4380 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4381 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4382 */
l_L184X3: ;/* line 4385 */
__LABEL(l_L184X3);
  sim_icache_fetch(3073 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4386 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4387 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4388 */
   __ADD_CYCLES(1);
} /* line 4388 */
  sim_icache_fetch(3078 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4390 */
} /* line 4390 */
  sim_icache_fetch(3079 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4392 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4393 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4394 */
l_L183X3: ;/* line 4397 */
__LABEL(l_L183X3);
  sim_icache_fetch(3082 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4398 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4399 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4400 */
   __ADD_CYCLES(1);
} /* line 4400 */
  sim_icache_fetch(3087 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4402 */
} /* line 4402 */
  sim_icache_fetch(3088 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4404 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4405 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4406 */
l_L182X3: ;/* line 4409 */
__LABEL(l_L182X3);
  sim_icache_fetch(3091 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4410 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10939Xoffset,0,4)); /* line 4411 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4412 */
   __ADD_CYCLES(1);
} /* line 4412 */
  sim_icache_fetch(3096 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4414 */
} /* line 4414 */
  sim_icache_fetch(3097 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4416 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4417 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4418 */
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

  sim_icache_fetch(3100 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4434 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4435 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4436 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4437 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4438 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4439 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4440 */
} /* line 4440 */
  sim_icache_fetch(3108 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4442 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4443 */
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4444 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4445 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4446 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4447 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4448 */
} /* line 4448 */
  sim_icache_fetch(3115 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4450 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4451 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4452 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4453 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4454 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4455 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4456 */
} /* line 4456 */
  sim_icache_fetch(3124 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4458 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4459 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4460 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4461 */
} /* line 4461 */
l_L198X3: ;/* line 4464 */
__LABEL(l_L198X3);
  sim_icache_fetch(3130 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4465 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4466 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4467 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4468 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4469 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4470 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4471 */
} /* line 4471 */
  sim_icache_fetch(3137 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4473 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4474 */
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4475 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4476 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4477 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4478 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L199X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4479 */
  sim_icache_fetch(3144 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4481 */
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4482 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4483 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4484 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4485 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4486 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4487 */
} /* line 4487 */
  sim_icache_fetch(3151 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4489 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4490 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4491 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4492 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4493 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4494 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4495 */
} /* line 4495 */
  sim_icache_fetch(3158 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4497 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4498 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4499 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4500 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4501 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4502 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4503 */
} /* line 4503 */
  sim_icache_fetch(3165 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4505 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4506 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4507 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4508 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4509 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4510 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4511 */
} /* line 4511 */
  sim_icache_fetch(3172 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4513 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4514 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4515 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4516 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4517 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4518 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4519 */
} /* line 4519 */
  sim_icache_fetch(3179 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4521 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4522 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4523 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4524 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4525 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4526 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4527 */
} /* line 4527 */
  sim_icache_fetch(3186 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4529 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4530 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4531 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4532 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4533 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4534 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4535 */
} /* line 4535 */
  sim_icache_fetch(3193 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4537 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4538 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4539 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4540 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4541 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4542 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4543 */
} /* line 4543 */
  sim_icache_fetch(3200 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4545 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4546 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4547 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4548 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4549 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4550 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4551 */
} /* line 4551 */
  sim_icache_fetch(3207 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4553 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4554 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4555 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4556 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4557 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4558 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4559 */
} /* line 4559 */
  sim_icache_fetch(3214 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4561 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4562 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4563 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4564 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4565 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4566 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4567 */
} /* line 4567 */
  sim_icache_fetch(3221 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4569 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4570 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4571 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4572 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4573 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4574 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4575 */
} /* line 4575 */
  sim_icache_fetch(3228 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4577 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4578 */
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4579 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4580 */
   __GOTO(l_L198X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L198X3;
} /* line 4581 */
l_L199X3: ;/* line 4584 */
__LABEL(l_L199X3);
  sim_icache_fetch(3233 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4585 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4586 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4587 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4588 */
   __ADD_CYCLES(1);
} /* line 4588 */
  sim_icache_fetch(3239 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4590 */
} /* line 4590 */
  sim_icache_fetch(3240 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4592 */
} /* line 4592 */
		 /* line 4593 */
  sim_icache_fetch(3242 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4595 */
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
} /* line 4596 */
l_lr_266: ;/* line 4596 */
__LABEL(l_lr_266);
  sim_icache_fetch(3246 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_2, t__i32_0); /* line 4598 */
   __MOV(reg_r0_4, t__i32_0); /* line 4599 */
   __CMPEQ(reg_b0_0, t__i32_0, (unsigned int) -1); /* line 4600 */
   __MOV(reg_r0_3, 0); /* line 4601 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4602 */
   __MOV(reg_r0_5, t__i32_0); /* line 4603 */
} /* line 4603 */
  sim_icache_fetch(3252 + t_thisfile.offset, 1);
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
} /* line 4605 */
  sim_icache_fetch(3253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4608 */
l_L200X3: ;/* line 4611 */
__LABEL(l_L200X3);
  sim_icache_fetch(3254 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4612 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4613 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4614 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4615 */
} /* line 4615 */
  sim_icache_fetch(3259 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4617 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4618 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4619 */
} /* line 4619 */
  sim_icache_fetch(3263 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4621 */
} /* line 4621 */
  sim_icache_fetch(3264 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4623 */
} /* line 4623 */
  sim_icache_fetch(3266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4625 */
} /* line 4625 */
l_L201X3: ;/* line 4628 */
__LABEL(l_L201X3);
		 /* line 4628 */
  sim_icache_fetch(3267 + t_thisfile.offset, 2);
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
} /* line 4630 */
l_lr_270: ;/* line 4630 */
__LABEL(l_lr_270);
  sim_icache_fetch(3269 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4632 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4633 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4634 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4635 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4636 */
} /* line 4636 */
  sim_icache_fetch(3276 + t_thisfile.offset, 1);
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
} /* line 4638 */
  sim_icache_fetch(3277 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4640 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4641 */
} /* line 4641 */
  sim_icache_fetch(3280 + t_thisfile.offset, 1);
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
} /* line 4643 */
l_L204X3: ;/* line 4646 */
__LABEL(l_L204X3);
  sim_icache_fetch(3281 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4647 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4648 */
} /* line 4648 */
  sim_icache_fetch(3283 + t_thisfile.offset, 1);
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
} /* line 4650 */
  sim_icache_fetch(3284 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4652 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4653 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4654 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4655 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4656 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4657 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4658 */
} /* line 4658 */
  sim_icache_fetch(3291 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4660 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4661 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4662 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4663 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4664 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4665 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4666 */
} /* line 4666 */
  sim_icache_fetch(3298 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4668 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4669 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4670 */
   __GOTO(l_L204X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L204X3;
} /* line 4671 */
l_L205X3: ;/* line 4674 */
__LABEL(l_L205X3);
  sim_icache_fetch(3302 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4675 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4676 */
} /* line 4676 */
		 /* line 4677 */
  sim_icache_fetch(3305 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4679 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4680 */
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
} /* line 4681 */
l_lr_274: ;/* line 4681 */
__LABEL(l_lr_274);
  sim_icache_fetch(3311 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4683 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4684 */
} /* line 4684 */
  sim_icache_fetch(3313 + t_thisfile.offset, 1);
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
} /* line 4686 */
l_L203X3: ;/* line 4689 */
__LABEL(l_L203X3);
  sim_icache_fetch(3314 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4690 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4691 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4692 */
   __ADD_CYCLES(1);
} /* line 4692 */
  sim_icache_fetch(3318 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4694 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4695 */
} /* line 4695 */
  sim_icache_fetch(3320 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4697 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4698 */
  sim_icache_fetch(3323 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4700 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4701 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4702 */
} /* line 4702 */
l_L207X3: ;/* line 4705 */
__LABEL(l_L207X3);
  sim_icache_fetch(3326 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4706 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4707 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4708 */
} /* line 4708 */
  sim_icache_fetch(3331 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4710 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4711 */
  sim_icache_fetch(3333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4713 */
} /* line 4713 */
  sim_icache_fetch(3334 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4715 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4716 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4717 */
} /* line 4717 */
  sim_icache_fetch(3339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4719 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4720 */
  sim_icache_fetch(3341 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4722 */
} /* line 4722 */
  sim_icache_fetch(3342 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4724 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4725 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4726 */
} /* line 4726 */
  sim_icache_fetch(3347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4728 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4729 */
  sim_icache_fetch(3349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4731 */
} /* line 4731 */
  sim_icache_fetch(3350 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4733 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4734 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4735 */
} /* line 4735 */
  sim_icache_fetch(3355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4737 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4738 */
  sim_icache_fetch(3357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4740 */
} /* line 4740 */
  sim_icache_fetch(3358 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4742 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4743 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4744 */
} /* line 4744 */
  sim_icache_fetch(3363 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4746 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4747 */
  sim_icache_fetch(3365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4749 */
} /* line 4749 */
  sim_icache_fetch(3366 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4751 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4752 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4753 */
} /* line 4753 */
  sim_icache_fetch(3371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4755 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4756 */
  sim_icache_fetch(3373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4758 */
} /* line 4758 */
  sim_icache_fetch(3374 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4760 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4761 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4762 */
} /* line 4762 */
  sim_icache_fetch(3379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4764 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4765 */
  sim_icache_fetch(3381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4767 */
} /* line 4767 */
  sim_icache_fetch(3382 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4769 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4770 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4771 */
} /* line 4771 */
  sim_icache_fetch(3387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4773 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4774 */
  sim_icache_fetch(3389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4776 */
} /* line 4776 */
  sim_icache_fetch(3390 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4778 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4779 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4780 */
} /* line 4780 */
  sim_icache_fetch(3395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4782 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4783 */
  sim_icache_fetch(3397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4785 */
} /* line 4785 */
  sim_icache_fetch(3398 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4787 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4788 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4789 */
} /* line 4789 */
  sim_icache_fetch(3403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4791 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4792 */
  sim_icache_fetch(3405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4794 */
} /* line 4794 */
  sim_icache_fetch(3406 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4796 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4797 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4798 */
} /* line 4798 */
  sim_icache_fetch(3411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4800 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4801 */
  sim_icache_fetch(3413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4803 */
} /* line 4803 */
  sim_icache_fetch(3414 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4805 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4806 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4807 */
} /* line 4807 */
  sim_icache_fetch(3419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4809 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4810 */
  sim_icache_fetch(3421 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4812 */
} /* line 4812 */
  sim_icache_fetch(3422 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4814 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4815 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4816 */
} /* line 4816 */
  sim_icache_fetch(3427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4818 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4819 */
  sim_icache_fetch(3429 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4821 */
} /* line 4821 */
  sim_icache_fetch(3430 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4823 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4824 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4825 */
} /* line 4825 */
  sim_icache_fetch(3435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4827 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4828 */
  sim_icache_fetch(3437 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4830 */
} /* line 4830 */
  sim_icache_fetch(3438 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4832 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4833 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4834 */
} /* line 4834 */
  sim_icache_fetch(3443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4836 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4837 */
  sim_icache_fetch(3445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4839 */
} /* line 4839 */
  sim_icache_fetch(3446 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4841 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4842 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4843 */
} /* line 4843 */
  sim_icache_fetch(3451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4845 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4846 */
  sim_icache_fetch(3453 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4848 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4849 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 4850 */
l_L223X3: ;/* line 4853 */
__LABEL(l_L223X3);
  sim_icache_fetch(3456 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4854 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4855 */
} /* line 4855 */
  sim_icache_fetch(3458 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4857 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 4858 */
l_L225X3: ;/* line 4861 */
__LABEL(l_L225X3);
  sim_icache_fetch(3460 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_5, reg_r0_3); /* line 4862 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4863 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4864 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4865 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4866 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4867 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4868 */
} /* line 4868 */
  sim_icache_fetch(3472 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4870 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4871 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4872 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4873 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4874 */
   __ADD(reg_r0_22, reg_r0_19, (unsigned int) -16); /* line 4875 */
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) -16); /* line 4876 */
} /* line 4876 */
  sim_icache_fetch(3483 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 4878 */
   __ADD(reg_r0_25, reg_r0_17, (unsigned int) -16); /* line 4879 */
   __ADD(reg_r0_26, reg_r0_16, (unsigned int) -16); /* line 4880 */
   __ADD(reg_r0_27, reg_r0_15, (unsigned int) -16); /* line 4881 */
   __ADD(reg_r0_28, reg_r0_14, (unsigned int) -16); /* line 4882 */
   __ADD(reg_r0_29, reg_r0_13, (unsigned int) -16); /* line 4883 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4884 */
} /* line 4884 */
  sim_icache_fetch(3490 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_31, reg_r0_11, (unsigned int) -16); /* line 4886 */
   __ADD(reg_r0_32, reg_r0_10, (unsigned int) -16); /* line 4887 */
   __ADD(reg_r0_33, reg_r0_9, (unsigned int) -16); /* line 4888 */
   __ADD(reg_r0_34, reg_r0_8, (unsigned int) -16); /* line 4889 */
   __ADD(reg_r0_35, reg_r0_7, (unsigned int) -16); /* line 4890 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) -16); /* line 4891 */
   __ADD(reg_r0_37, reg_r0_20, (unsigned int) -16); /* line 4892 */
} /* line 4892 */
  sim_icache_fetch(3497 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 4894 */
   __MOV(reg_r0_38, reg_r0_20); /* line 4895 */
   __MOV(reg_r0_40, reg_r0_37); /* line 4896 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 4897 */
} /* line 4897 */
  sim_icache_fetch(3502 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4899 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4900 */
  sim_icache_fetch(3504 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4902 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4903 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4904 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4905 */
   __ADD_CYCLES(1);
} /* line 4905 */
  sim_icache_fetch(3510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4907 */
} /* line 4907 */
  sim_icache_fetch(3511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4909 */
} /* line 4909 */
  sim_icache_fetch(3513 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4911 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4912 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4913 */
  sim_icache_fetch(3517 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4915 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4916 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4917 */
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) -16); /* line 4918 */
   __MFB(reg_r0_4, t__i32_0); /* line 4919 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4920 */
   __ADD_CYCLES(1);
} /* line 4920 */
  sim_icache_fetch(3525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 4922 */
} /* line 4922 */
  sim_icache_fetch(3526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 4924 */
} /* line 4924 */
  sim_icache_fetch(3528 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4926 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4927 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4928 */
  sim_icache_fetch(3531 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4930 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4931 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4932 */
   __ADD(reg_r0_7, reg_r0_35, (unsigned int) -16); /* line 4933 */
   __MFB(reg_r0_4, t__i32_0); /* line 4934 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4935 */
   __ADD_CYCLES(1);
} /* line 4935 */
  sim_icache_fetch(3539 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 4937 */
} /* line 4937 */
  sim_icache_fetch(3540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 4939 */
} /* line 4939 */
  sim_icache_fetch(3542 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4941 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4942 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4943 */
  sim_icache_fetch(3545 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4945 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4946 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4947 */
   __ADD(reg_r0_8, reg_r0_34, (unsigned int) -16); /* line 4948 */
   __MFB(reg_r0_4, t__i32_0); /* line 4949 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4950 */
   __ADD_CYCLES(1);
} /* line 4950 */
  sim_icache_fetch(3553 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 4952 */
} /* line 4952 */
  sim_icache_fetch(3554 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 4954 */
} /* line 4954 */
  sim_icache_fetch(3556 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 4956 */
   __MTB(reg_b0_4, reg_r0_4); /* line 4957 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4958 */
  sim_icache_fetch(3559 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 4960 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4961 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 4962 */
   __ADD(reg_r0_9, reg_r0_33, (unsigned int) -16); /* line 4963 */
   __MFB(reg_r0_4, t__i32_0); /* line 4964 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4965 */
   __ADD_CYCLES(1);
} /* line 4965 */
  sim_icache_fetch(3567 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 4967 */
} /* line 4967 */
  sim_icache_fetch(3568 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 4969 */
} /* line 4969 */
  sim_icache_fetch(3570 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 4971 */
   __MTB(reg_b0_5, reg_r0_4); /* line 4972 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4973 */
  sim_icache_fetch(3573 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 4975 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4976 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 4977 */
   __ADD(reg_r0_10, reg_r0_32, (unsigned int) -16); /* line 4978 */
   __MFB(reg_r0_4, t__i32_0); /* line 4979 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4980 */
   __ADD_CYCLES(1);
} /* line 4980 */
  sim_icache_fetch(3581 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 4982 */
} /* line 4982 */
  sim_icache_fetch(3582 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 4984 */
} /* line 4984 */
  sim_icache_fetch(3584 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 4986 */
   __MTB(reg_b0_6, reg_r0_4); /* line 4987 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4988 */
  sim_icache_fetch(3587 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 4990 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4991 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 4992 */
   __ADD(reg_r0_11, reg_r0_31, (unsigned int) -16); /* line 4993 */
   __MFB(reg_r0_4, t__i32_0); /* line 4994 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4995 */
   __ADD_CYCLES(1);
} /* line 4995 */
  sim_icache_fetch(3595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 4997 */
} /* line 4997 */
  sim_icache_fetch(3596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 4999 */
} /* line 4999 */
  sim_icache_fetch(3598 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 5001 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5002 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5003 */
  sim_icache_fetch(3601 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5005 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5006 */
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 5007 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 5008 */
   __MFB(reg_r0_4, t__i32_0); /* line 5009 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5010 */
   __ADD_CYCLES(1);
} /* line 5010 */
  sim_icache_fetch(3609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 5012 */
} /* line 5012 */
  sim_icache_fetch(3610 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 5014 */
} /* line 5014 */
  sim_icache_fetch(3612 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5016 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5017 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5018 */
  sim_icache_fetch(3615 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5020 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5021 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5022 */
   __ADD(reg_r0_13, reg_r0_29, (unsigned int) -16); /* line 5023 */
   __MFB(reg_r0_4, t__i32_0); /* line 5024 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5025 */
   __ADD_CYCLES(1);
} /* line 5025 */
  sim_icache_fetch(3623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 5027 */
} /* line 5027 */
  sim_icache_fetch(3624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 5029 */
} /* line 5029 */
  sim_icache_fetch(3626 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5031 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5032 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5033 */
  sim_icache_fetch(3629 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5035 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5036 */
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 5037 */
   __ADD(reg_r0_14, reg_r0_28, (unsigned int) -16); /* line 5038 */
   __MFB(reg_r0_4, t__i32_0); /* line 5039 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5040 */
   __ADD_CYCLES(1);
} /* line 5040 */
  sim_icache_fetch(3637 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 5042 */
} /* line 5042 */
  sim_icache_fetch(3638 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 5044 */
} /* line 5044 */
  sim_icache_fetch(3640 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5046 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5047 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5048 */
  sim_icache_fetch(3643 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5050 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5051 */
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5052 */
   __ADD(reg_r0_15, reg_r0_27, (unsigned int) -16); /* line 5053 */
   __MFB(reg_r0_4, t__i32_0); /* line 5054 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5055 */
   __ADD_CYCLES(1);
} /* line 5055 */
  sim_icache_fetch(3651 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 5057 */
} /* line 5057 */
  sim_icache_fetch(3652 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 5059 */
} /* line 5059 */
  sim_icache_fetch(3654 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5061 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5062 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5063 */
  sim_icache_fetch(3657 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5065 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5066 */
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5067 */
   __ADD(reg_r0_16, reg_r0_26, (unsigned int) -16); /* line 5068 */
   __MFB(reg_r0_4, t__i32_0); /* line 5069 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5070 */
   __ADD_CYCLES(1);
} /* line 5070 */
  sim_icache_fetch(3665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 5072 */
} /* line 5072 */
  sim_icache_fetch(3666 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 5074 */
} /* line 5074 */
  sim_icache_fetch(3668 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5076 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5077 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5078 */
  sim_icache_fetch(3671 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5080 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5081 */
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5082 */
   __ADD(reg_r0_17, reg_r0_25, (unsigned int) -16); /* line 5083 */
   __MFB(reg_r0_4, t__i32_0); /* line 5084 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5085 */
   __ADD_CYCLES(1);
} /* line 5085 */
  sim_icache_fetch(3679 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 5087 */
} /* line 5087 */
  sim_icache_fetch(3680 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 5089 */
} /* line 5089 */
  sim_icache_fetch(3682 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5091 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5092 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5093 */
  sim_icache_fetch(3685 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5095 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5096 */
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5097 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) -16); /* line 5098 */
   __MFB(reg_r0_4, t__i32_0); /* line 5099 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5100 */
   __ADD_CYCLES(1);
} /* line 5100 */
  sim_icache_fetch(3693 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 5102 */
} /* line 5102 */
  sim_icache_fetch(3694 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 5104 */
} /* line 5104 */
  sim_icache_fetch(3696 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5106 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5107 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5108 */
  sim_icache_fetch(3699 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5110 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5111 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5112 */
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5113 */
   __ADD(reg_r0_19, reg_r0_22, (unsigned int) -16); /* line 5114 */
   __MFB(reg_r0_4, t__i32_0); /* line 5115 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5116 */
   __ADD_CYCLES(1);
} /* line 5116 */
  sim_icache_fetch(3708 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_2, (unsigned int) 1); /* line 5118 */
} /* line 5118 */
  sim_icache_fetch(3709 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_24); /* line 5120 */
} /* line 5120 */
  sim_icache_fetch(3711 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5122 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5123 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5124 */
  sim_icache_fetch(3714 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_5, reg_r0_3); /* line 5126 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5127 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5128 */
   __CMPLEU(reg_b0_7, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5129 */
   __ADD(reg_r0_20, reg_r0_37, (unsigned int) -16); /* line 5130 */
   __MOV(reg_r0_3, reg_r0_39); /* line 5131 */
   __MFB(reg_r0_24, t__i32_0); /* line 5132 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5133 */
   __ADD_CYCLES(1);
} /* line 5133 */
  sim_icache_fetch(3724 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5135 */
} /* line 5135 */
  sim_icache_fetch(3725 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5137 */
} /* line 5137 */
  sim_icache_fetch(3727 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5139 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5140 */
  sim_icache_fetch(3729 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5142 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5143 */
   __CMPLEU(reg_b0_0, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5144 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5145 */
   __ADD_CYCLES(1);
} /* line 5145 */
  sim_icache_fetch(3735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5147 */
} /* line 5147 */
  sim_icache_fetch(3736 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5149 */
} /* line 5149 */
  sim_icache_fetch(3738 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5151 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5152 */
  sim_icache_fetch(3740 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5154 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5155 */
   __CMPLEU(reg_b0_1, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5156 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5157 */
   __ADD_CYCLES(1);
} /* line 5157 */
  sim_icache_fetch(3746 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5159 */
} /* line 5159 */
  sim_icache_fetch(3747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5161 */
} /* line 5161 */
  sim_icache_fetch(3749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5163 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5164 */
  sim_icache_fetch(3751 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5166 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5167 */
   __CMPLEU(reg_b0_2, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5168 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5169 */
   __ADD_CYCLES(1);
} /* line 5169 */
  sim_icache_fetch(3757 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5171 */
} /* line 5171 */
  sim_icache_fetch(3758 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5173 */
} /* line 5173 */
  sim_icache_fetch(3760 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5175 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5176 */
  sim_icache_fetch(3762 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5178 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5179 */
   __CMPLEU(reg_b0_3, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5180 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5181 */
   __ADD_CYCLES(1);
} /* line 5181 */
  sim_icache_fetch(3768 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5183 */
} /* line 5183 */
  sim_icache_fetch(3769 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5185 */
} /* line 5185 */
  sim_icache_fetch(3771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5187 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5188 */
  sim_icache_fetch(3773 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5190 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5191 */
   __CMPLEU(reg_b0_4, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5192 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5193 */
   __ADD_CYCLES(1);
} /* line 5193 */
  sim_icache_fetch(3779 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5195 */
} /* line 5195 */
  sim_icache_fetch(3780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5197 */
} /* line 5197 */
  sim_icache_fetch(3782 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5199 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5200 */
  sim_icache_fetch(3784 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5202 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5203 */
   __CMPLEU(reg_b0_5, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5204 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5205 */
   __ADD_CYCLES(1);
} /* line 5205 */
  sim_icache_fetch(3790 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5207 */
} /* line 5207 */
  sim_icache_fetch(3791 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5209 */
} /* line 5209 */
  sim_icache_fetch(3793 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5211 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5212 */
  sim_icache_fetch(3795 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5214 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5215 */
   __CMPLEU(reg_b0_6, reg_r0_22, ((unsigned int) htab + (unsigned int) 4096)); /* line 5216 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5217 */
   __ADD_CYCLES(1);
} /* line 5217 */
  sim_icache_fetch(3801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5219 */
} /* line 5219 */
  sim_icache_fetch(3802 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5221 */
} /* line 5221 */
  sim_icache_fetch(3804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5223 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5224 */
  sim_icache_fetch(3806 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5226 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5227 */
   __MTB(reg_b0_7, reg_r0_24); /* line 5228 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5229 */
   __ADD_CYCLES(1);
} /* line 5229 */
  sim_icache_fetch(3811 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5231 */
} /* line 5231 */
  sim_icache_fetch(3812 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5233 */
} /* line 5233 */
  sim_icache_fetch(3814 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5235 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5236 */
  sim_icache_fetch(3816 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5238 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5239 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5240 */
   __ADD_CYCLES(1);
} /* line 5240 */
  sim_icache_fetch(3820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5242 */
} /* line 5242 */
  sim_icache_fetch(3821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5244 */
} /* line 5244 */
  sim_icache_fetch(3823 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5246 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5247 */
  sim_icache_fetch(3825 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5249 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5250 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5251 */
   __ADD_CYCLES(1);
} /* line 5251 */
  sim_icache_fetch(3829 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5253 */
} /* line 5253 */
  sim_icache_fetch(3830 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5255 */
} /* line 5255 */
  sim_icache_fetch(3832 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5257 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5258 */
  sim_icache_fetch(3834 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5260 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5261 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5262 */
   __ADD_CYCLES(1);
} /* line 5262 */
  sim_icache_fetch(3838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5264 */
} /* line 5264 */
  sim_icache_fetch(3839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5266 */
} /* line 5266 */
  sim_icache_fetch(3841 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5268 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5269 */
  sim_icache_fetch(3843 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5271 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5272 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5273 */
   __ADD_CYCLES(1);
} /* line 5273 */
  sim_icache_fetch(3847 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5275 */
} /* line 5275 */
  sim_icache_fetch(3848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5277 */
} /* line 5277 */
  sim_icache_fetch(3850 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5279 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5280 */
  sim_icache_fetch(3852 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5282 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5283 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5284 */
   __ADD_CYCLES(1);
} /* line 5284 */
  sim_icache_fetch(3856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5286 */
} /* line 5286 */
  sim_icache_fetch(3857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5288 */
} /* line 5288 */
  sim_icache_fetch(3859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5290 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5291 */
  sim_icache_fetch(3861 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_22, mem_trace_ld(reg_r0_22,0,1)); /* line 5293 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5294 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5295 */
   __ADD_CYCLES(1);
} /* line 5295 */
  sim_icache_fetch(3865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5297 */
} /* line 5297 */
  sim_icache_fetch(3866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5299 */
} /* line 5299 */
  sim_icache_fetch(3868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_22); /* line 5301 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5302 */
  sim_icache_fetch(3870 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5304 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5305 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5306 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5307 */
   __ADD_CYCLES(1);
} /* line 5307 */
  sim_icache_fetch(3875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5309 */
} /* line 5309 */
  sim_icache_fetch(3876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5311 */
} /* line 5311 */
  sim_icache_fetch(3878 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5313 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5315 */
  sim_icache_fetch(3880 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5317 */
l_L241X3: ;/* line 5320 */
__LABEL(l_L241X3);
  sim_icache_fetch(3881 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5321 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5322 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5323 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5324 */
l_L244X3: ;/* line 5327 */
__LABEL(l_L244X3);
  sim_icache_fetch(3887 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5328 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5329 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5330 */
} /* line 5330 */
  sim_icache_fetch(3892 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5332 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5333 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5334 */
l_L240X3: ;/* line 5337 */
__LABEL(l_L240X3);
  sim_icache_fetch(3896 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5338 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5339 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5340 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5341 */
l_L239X3: ;/* line 5344 */
__LABEL(l_L239X3);
  sim_icache_fetch(3902 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5345 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5346 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5347 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5348 */
l_L238X3: ;/* line 5351 */
__LABEL(l_L238X3);
  sim_icache_fetch(3908 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5352 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5353 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5354 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5355 */
l_L237X3: ;/* line 5358 */
__LABEL(l_L237X3);
  sim_icache_fetch(3914 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5359 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5360 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5361 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5362 */
l_L236X3: ;/* line 5365 */
__LABEL(l_L236X3);
  sim_icache_fetch(3920 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5366 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5367 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5368 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5369 */
l_L235X3: ;/* line 5372 */
__LABEL(l_L235X3);
  sim_icache_fetch(3926 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5373 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5374 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5375 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5376 */
l_L234X3: ;/* line 5379 */
__LABEL(l_L234X3);
  sim_icache_fetch(3932 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5380 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5381 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5382 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5383 */
l_L233X3: ;/* line 5386 */
__LABEL(l_L233X3);
  sim_icache_fetch(3938 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5387 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5388 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5389 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5390 */
l_L232X3: ;/* line 5393 */
__LABEL(l_L232X3);
  sim_icache_fetch(3944 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5394 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5395 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5396 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5397 */
l_L231X3: ;/* line 5400 */
__LABEL(l_L231X3);
  sim_icache_fetch(3950 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5401 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5402 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5403 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5404 */
l_L230X3: ;/* line 5407 */
__LABEL(l_L230X3);
  sim_icache_fetch(3956 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5408 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5409 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5410 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5411 */
l_L229X3: ;/* line 5414 */
__LABEL(l_L229X3);
  sim_icache_fetch(3962 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5415 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5416 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5417 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5418 */
l_L228X3: ;/* line 5421 */
__LABEL(l_L228X3);
  sim_icache_fetch(3968 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5422 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5423 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5424 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5425 */
l_L227X3: ;/* line 5428 */
__LABEL(l_L227X3);
  sim_icache_fetch(3974 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5429 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5430 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5431 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5432 */
l_L226X3: ;/* line 5435 */
__LABEL(l_L226X3);
  sim_icache_fetch(3980 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5436 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5437 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5438 */
} /* line 5438 */
l_L242X3: ;/* line 5440 */
__LABEL(l_L242X3);
  sim_icache_fetch(3985 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5440 */
  sim_icache_fetch(3986 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5442 */
} /* line 5442 */
  sim_icache_fetch(3987 + t_thisfile.offset, 1);
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
} /* line 5444 */
l_L243X3: ;/* line 5446 */
__LABEL(l_L243X3);
  sim_icache_fetch(3988 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5447 */
   __GOTO(l_L201X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L201X3;
} /* line 5448 */
l_L222X3: ;/* line 5451 */
__LABEL(l_L222X3);
  sim_icache_fetch(3990 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5452 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5453 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5454 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5455 */
l_L221X3: ;/* line 5458 */
__LABEL(l_L221X3);
  sim_icache_fetch(3994 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5459 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5460 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5461 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5462 */
l_L220X3: ;/* line 5465 */
__LABEL(l_L220X3);
  sim_icache_fetch(3998 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5466 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5467 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5468 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5469 */
l_L219X3: ;/* line 5472 */
__LABEL(l_L219X3);
  sim_icache_fetch(4002 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5473 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5474 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5475 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5476 */
l_L218X3: ;/* line 5479 */
__LABEL(l_L218X3);
  sim_icache_fetch(4006 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5480 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5481 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5482 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5483 */
l_L217X3: ;/* line 5486 */
__LABEL(l_L217X3);
  sim_icache_fetch(4010 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5487 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5488 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5489 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5490 */
l_L216X3: ;/* line 5493 */
__LABEL(l_L216X3);
  sim_icache_fetch(4014 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5494 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5495 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5496 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5497 */
l_L215X3: ;/* line 5500 */
__LABEL(l_L215X3);
  sim_icache_fetch(4018 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5501 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5502 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5503 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5504 */
l_L214X3: ;/* line 5507 */
__LABEL(l_L214X3);
  sim_icache_fetch(4022 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5508 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5509 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5510 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5511 */
l_L213X3: ;/* line 5514 */
__LABEL(l_L213X3);
  sim_icache_fetch(4026 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5515 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5516 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5517 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5518 */
l_L212X3: ;/* line 5521 */
__LABEL(l_L212X3);
  sim_icache_fetch(4030 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5522 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5523 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5524 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5525 */
l_L211X3: ;/* line 5528 */
__LABEL(l_L211X3);
  sim_icache_fetch(4034 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5529 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5530 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5531 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5532 */
l_L210X3: ;/* line 5535 */
__LABEL(l_L210X3);
  sim_icache_fetch(4038 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5536 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5537 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5538 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5539 */
l_L209X3: ;/* line 5542 */
__LABEL(l_L209X3);
  sim_icache_fetch(4042 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5543 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5544 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5545 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5546 */
l_L208X3: ;/* line 5551 */
__LABEL(l_L208X3);
  sim_icache_fetch(4046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5552 */
} /* line 5552 */
l_L224X3: ;/* line 5554 */
__LABEL(l_L224X3);
  sim_icache_fetch(4047 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5555 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5556 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5557 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5558 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5559 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5560 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5561 */
} /* line 5561 */
  sim_icache_fetch(4055 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5563 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5564 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5565 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5566 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5567 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5568 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5569 */
} /* line 5569 */
  sim_icache_fetch(4062 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5571 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5572 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5573 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5574 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5575 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5576 */
l_L206X3: ;/* line 5579 */
__LABEL(l_L206X3);
  sim_icache_fetch(4068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5580 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 5581 */
l_L202X3: ;/* line 5584 */
__LABEL(l_L202X3);
  sim_icache_fetch(4070 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5585 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5586 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5587 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5588 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5589 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5590 */
   __ADD_CYCLES(1);
} /* line 5590 */
  sim_icache_fetch(4076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5593 */
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

  sim_icache_fetch(4077 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5612 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5613 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5614 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5615 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5616 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5617 */
} /* line 5617 */
  sim_icache_fetch(4089 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5619 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5620 */
} /* line 5620 */
  sim_icache_fetch(4093 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5622 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5623 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5624 */
} /* line 5624 */
  sim_icache_fetch(4096 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_r0_5, reg_r0_7, reg_r0_8); /* line 5626 */
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5627 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5628 */
} /* line 5628 */
  sim_icache_fetch(4099 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_1, reg_r0_4, reg_r0_5); /* line 5630 */
   __CMPEQ(reg_b0_2, reg_r0_9, reg_r0_2); /* line 5631 */
} /* line 5631 */
  sim_icache_fetch(4101 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5633 */
  sim_icache_fetch(4102 + t_thisfile.offset, 1);
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
} /* line 5635 */
  sim_icache_fetch(4103 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5637 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5638 */
  sim_icache_fetch(4106 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5640 */
} /* line 5640 */
l_L246X3: ;/* line 5643 */
__LABEL(l_L246X3);
  sim_icache_fetch(4108 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5644 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5645 */
   __MOV(reg_r0_5, 0); /* line 5646 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5647 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5648 */
   __ADD_CYCLES(1);
} /* line 5648 */
  sim_icache_fetch(4115 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5650 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5651 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5652 */
} /* line 5652 */
  sim_icache_fetch(4118 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5654 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5655 */
l_L249X3: ;/* line 5658 */
__LABEL(l_L249X3);
  sim_icache_fetch(4120 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5659 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5660 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5661 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5662 */
} /* line 5662 */
  sim_icache_fetch(4126 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5664 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5665 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5666 */
  sim_icache_fetch(4129 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5668 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5669 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5670 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5671 */
} /* line 5671 */
  sim_icache_fetch(4133 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5673 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5674 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5675 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5676 */
} /* line 5676 */
  sim_icache_fetch(4138 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5678 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5679 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5680 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5681 */
  sim_icache_fetch(4143 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5683 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5684 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5685 */
} /* line 5685 */
  sim_icache_fetch(4147 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5687 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5688 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5689 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5690 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5691 */
} /* line 5691 */
  sim_icache_fetch(4153 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5693 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5694 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5695 */
} /* line 5695 */
  sim_icache_fetch(4156 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5697 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5698 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5699 */
} /* line 5699 */
l_L252X3: ;/* line 5701 */
__LABEL(l_L252X3);
  sim_icache_fetch(4159 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5702 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5703 */
} /* line 5703 */
  sim_icache_fetch(4162 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5705 */
} /* line 5705 */
  sim_icache_fetch(4163 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5707 */
} /* line 5707 */
  sim_icache_fetch(4164 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5709 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5710 */
  sim_icache_fetch(4166 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5712 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5713 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5714 */
  sim_icache_fetch(4169 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5716 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5717 */
  sim_icache_fetch(4172 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5719 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5720 */
} /* line 5720 */
  sim_icache_fetch(4176 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5722 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5723 */
} /* line 5723 */
  sim_icache_fetch(4179 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5725 */
} /* line 5725 */
  sim_icache_fetch(4180 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5727 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5728 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5729 */
} /* line 5729 */
l_L255X3: ;/* line 5731 */
__LABEL(l_L255X3);
  sim_icache_fetch(4183 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5732 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5733 */
} /* line 5733 */
  sim_icache_fetch(4186 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5735 */
} /* line 5735 */
  sim_icache_fetch(4187 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5737 */
} /* line 5737 */
  sim_icache_fetch(4188 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5739 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5740 */
  sim_icache_fetch(4190 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5742 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5743 */
  sim_icache_fetch(4192 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5745 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L256X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5746 */
  sim_icache_fetch(4195 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5748 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5749 */
} /* line 5749 */
  sim_icache_fetch(4199 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5751 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5752 */
} /* line 5752 */
  sim_icache_fetch(4202 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5754 */
} /* line 5754 */
  sim_icache_fetch(4203 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5756 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5757 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5758 */
} /* line 5758 */
l_L257X3: ;/* line 5760 */
__LABEL(l_L257X3);
  sim_icache_fetch(4206 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5761 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5762 */
} /* line 5762 */
  sim_icache_fetch(4209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5764 */
} /* line 5764 */
  sim_icache_fetch(4210 + t_thisfile.offset, 1);
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
} /* line 5766 */
  sim_icache_fetch(4211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5768 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5769 */
  sim_icache_fetch(4213 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5771 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L258X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5772 */
  sim_icache_fetch(4216 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5774 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5775 */
} /* line 5775 */
  sim_icache_fetch(4220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5777 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5778 */
} /* line 5778 */
  sim_icache_fetch(4223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5780 */
} /* line 5780 */
  sim_icache_fetch(4224 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5782 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5783 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5784 */
} /* line 5784 */
l_L259X3: ;/* line 5786 */
__LABEL(l_L259X3);
  sim_icache_fetch(4227 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5787 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5788 */
} /* line 5788 */
  sim_icache_fetch(4230 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5790 */
} /* line 5790 */
  sim_icache_fetch(4231 + t_thisfile.offset, 1);
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
} /* line 5792 */
  sim_icache_fetch(4232 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5794 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5795 */
  sim_icache_fetch(4234 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5797 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L260X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5798 */
  sim_icache_fetch(4237 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5800 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5801 */
} /* line 5801 */
  sim_icache_fetch(4241 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5803 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5804 */
} /* line 5804 */
  sim_icache_fetch(4244 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5806 */
} /* line 5806 */
  sim_icache_fetch(4245 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5808 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5809 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5810 */
} /* line 5810 */
l_L261X3: ;/* line 5812 */
__LABEL(l_L261X3);
  sim_icache_fetch(4248 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5813 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5814 */
} /* line 5814 */
  sim_icache_fetch(4251 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5816 */
} /* line 5816 */
  sim_icache_fetch(4252 + t_thisfile.offset, 1);
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
} /* line 5818 */
  sim_icache_fetch(4253 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5820 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5821 */
  sim_icache_fetch(4255 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5823 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5824 */
  sim_icache_fetch(4258 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5826 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5827 */
} /* line 5827 */
  sim_icache_fetch(4262 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5829 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5830 */
} /* line 5830 */
  sim_icache_fetch(4265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5832 */
} /* line 5832 */
  sim_icache_fetch(4266 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5834 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5835 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5836 */
} /* line 5836 */
l_L263X3: ;/* line 5838 */
__LABEL(l_L263X3);
  sim_icache_fetch(4269 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5839 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5840 */
} /* line 5840 */
  sim_icache_fetch(4272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5842 */
} /* line 5842 */
  sim_icache_fetch(4273 + t_thisfile.offset, 1);
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
} /* line 5844 */
  sim_icache_fetch(4274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5846 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5847 */
  sim_icache_fetch(4276 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5849 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L264X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5850 */
  sim_icache_fetch(4279 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5852 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5853 */
} /* line 5853 */
  sim_icache_fetch(4283 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5855 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5856 */
} /* line 5856 */
  sim_icache_fetch(4286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5858 */
} /* line 5858 */
  sim_icache_fetch(4287 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5860 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5861 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5862 */
} /* line 5862 */
l_L265X3: ;/* line 5864 */
__LABEL(l_L265X3);
  sim_icache_fetch(4290 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5865 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5866 */
} /* line 5866 */
  sim_icache_fetch(4293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5868 */
} /* line 5868 */
  sim_icache_fetch(4294 + t_thisfile.offset, 1);
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
} /* line 5870 */
  sim_icache_fetch(4295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5872 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5873 */
  sim_icache_fetch(4297 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5875 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L266X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5876 */
  sim_icache_fetch(4300 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5878 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5879 */
} /* line 5879 */
  sim_icache_fetch(4304 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5881 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5882 */
} /* line 5882 */
  sim_icache_fetch(4307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5884 */
} /* line 5884 */
  sim_icache_fetch(4308 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5886 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5887 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5888 */
} /* line 5888 */
l_L267X3: ;/* line 5890 */
__LABEL(l_L267X3);
  sim_icache_fetch(4311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5891 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5892 */
} /* line 5892 */
  sim_icache_fetch(4314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5894 */
} /* line 5894 */
  sim_icache_fetch(4315 + t_thisfile.offset, 1);
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
} /* line 5896 */
  sim_icache_fetch(4316 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5898 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5899 */
  sim_icache_fetch(4318 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5901 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5902 */
  sim_icache_fetch(4321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5904 */
} /* line 5904 */
  sim_icache_fetch(4323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5906 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5907 */
   __ADD_CYCLES(1);
} /* line 5907 */
  sim_icache_fetch(4325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5909 */
} /* line 5909 */
l_L269X3: ;/* line 5911 */
__LABEL(l_L269X3);
  sim_icache_fetch(4326 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5912 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5913 */
} /* line 5913 */
  sim_icache_fetch(4329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5915 */
} /* line 5915 */
  sim_icache_fetch(4330 + t_thisfile.offset, 1);
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
} /* line 5917 */
  sim_icache_fetch(4331 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5919 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 5920 */
l_L253X3: ;/* line 5923 */
__LABEL(l_L253X3);
  sim_icache_fetch(4333 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5924 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5925 */
   __GOTO(l_L270X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L270X3;
} /* line 5926 */
l_L271X3: ;/* line 5929 */
__LABEL(l_L271X3);
  sim_icache_fetch(4336 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5930 */
   __MOV(reg_r0_7, 0); /* line 5931 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5932 */
} /* line 5932 */
  sim_icache_fetch(4340 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5934 */
} /* line 5934 */
  sim_icache_fetch(4341 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5936 */
} /* line 5936 */
l_L245X3: ;/* line 5939 */
__LABEL(l_L245X3);
  sim_icache_fetch(4342 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5940 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5941 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5942 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5943 */
} /* line 5943 */
  sim_icache_fetch(4348 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5945 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5946 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5947 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5948 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5949 */
} /* line 5949 */
  sim_icache_fetch(4356 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 5951 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 5952 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 5953 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 5954 */
} /* line 5954 */
  sim_icache_fetch(4360 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 5956 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 5957 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 5958 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 5959 */
} /* line 5959 */
  sim_icache_fetch(4365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 5961 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 5962 */
} /* line 5962 */
  sim_icache_fetch(4367 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5964 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 5965 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 5966 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 5967 */
} /* line 5967 */
  sim_icache_fetch(4371 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 5969 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5970 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 5971 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5972 */
   __ADD_CYCLES(1);
} /* line 5972 */
  sim_icache_fetch(4376 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 5974 */
} /* line 5974 */
  sim_icache_fetch(4377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 5976 */
} /* line 5976 */
  sim_icache_fetch(4378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 5979 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5980 */
l_L268X3: ;/* line 5983 */
__LABEL(l_L268X3);
  sim_icache_fetch(4380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5984 */
   __GOTO(l_L269X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L269X3;
} /* line 5985 */
l_L250X3: ;/* line 5988 */
__LABEL(l_L250X3);
  sim_icache_fetch(4382 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 5989 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5990 */
} /* line 5990 */
l_L270X3: ;/* line 5992 */
__LABEL(l_L270X3);
  sim_icache_fetch(4384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 5993 */
} /* line 5993 */
  sim_icache_fetch(4385 + t_thisfile.offset, 1);
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
} /* line 5995 */
  sim_icache_fetch(4386 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 5998 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 5999 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6000 */
l_L266X3: ;/* line 6003 */
__LABEL(l_L266X3);
  sim_icache_fetch(4391 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6004 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6005 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6006 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6007 */
   __ADD_CYCLES(1);
} /* line 6007 */
  sim_icache_fetch(4397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6009 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6010 */
} /* line 6010 */
  sim_icache_fetch(4399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6012 */
   __GOTO(l_L267X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L267X3;
} /* line 6013 */
l_L264X3: ;/* line 6016 */
__LABEL(l_L264X3);
  sim_icache_fetch(4401 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6017 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6018 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6019 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6020 */
   __ADD_CYCLES(1);
} /* line 6020 */
  sim_icache_fetch(4407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6022 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6023 */
} /* line 6023 */
  sim_icache_fetch(4409 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6025 */
   __GOTO(l_L265X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L265X3;
} /* line 6026 */
l_L262X3: ;/* line 6029 */
__LABEL(l_L262X3);
  sim_icache_fetch(4411 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6030 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6031 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6032 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6033 */
   __ADD_CYCLES(1);
} /* line 6033 */
  sim_icache_fetch(4417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6035 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6036 */
} /* line 6036 */
  sim_icache_fetch(4419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6038 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 6039 */
l_L260X3: ;/* line 6042 */
__LABEL(l_L260X3);
  sim_icache_fetch(4421 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6043 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6044 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6045 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6046 */
   __ADD_CYCLES(1);
} /* line 6046 */
  sim_icache_fetch(4427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6048 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6049 */
} /* line 6049 */
  sim_icache_fetch(4429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6051 */
   __GOTO(l_L261X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L261X3;
} /* line 6052 */
l_L258X3: ;/* line 6055 */
__LABEL(l_L258X3);
  sim_icache_fetch(4431 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6056 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6057 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6058 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6059 */
   __ADD_CYCLES(1);
} /* line 6059 */
  sim_icache_fetch(4437 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6061 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6062 */
} /* line 6062 */
  sim_icache_fetch(4439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6064 */
   __GOTO(l_L259X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L259X3;
} /* line 6065 */
l_L256X3: ;/* line 6068 */
__LABEL(l_L256X3);
  sim_icache_fetch(4441 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6069 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6070 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6071 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6072 */
   __ADD_CYCLES(1);
} /* line 6072 */
  sim_icache_fetch(4447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6074 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6075 */
} /* line 6075 */
  sim_icache_fetch(4449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6077 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 6078 */
l_L254X3: ;/* line 6081 */
__LABEL(l_L254X3);
  sim_icache_fetch(4451 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6082 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6083 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6084 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6085 */
   __ADD_CYCLES(1);
} /* line 6085 */
  sim_icache_fetch(4457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6087 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6088 */
} /* line 6088 */
  sim_icache_fetch(4459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6090 */
   __GOTO(l_L255X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L255X3;
} /* line 6091 */
l_L251X3: ;/* line 6094 */
__LABEL(l_L251X3);
  sim_icache_fetch(4461 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6095 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6096 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6097 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6098 */
} /* line 6098 */
  sim_icache_fetch(4466 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6100 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6101 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6102 */
} /* line 6102 */
  sim_icache_fetch(4469 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6104 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6105 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6106 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6107 */
} /* line 6107 */
  sim_icache_fetch(4473 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6109 */
   __GOTO(l_L252X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L252X3;
} /* line 6110 */
l_L248X3: ;/* line 6113 */
__LABEL(l_L248X3);
  sim_icache_fetch(4475 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6114 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6115 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6116 */
} /* line 6116 */
  sim_icache_fetch(4480 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6118 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6119 */
} /* line 6119 */
  sim_icache_fetch(4484 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6121 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6122 */
   __ADD_CYCLES(1);
} /* line 6122 */
  sim_icache_fetch(4487 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6124 */
} /* line 6124 */
  sim_icache_fetch(4488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6126 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 6127 */
l_L247X3: ;/* line 6130 */
__LABEL(l_L247X3);
  sim_icache_fetch(4490 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6131 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6132 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6133 */
   __ADD_CYCLES(1);
} /* line 6133 */
  sim_icache_fetch(4494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6135 */
} /* line 6135 */
  sim_icache_fetch(4495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6137 */
} /* line 6137 */
  sim_icache_fetch(4496 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6139 */
   __GOTO(l_L246X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L246X3;
} /* line 6140 */
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

  sim_icache_fetch(4499 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6162 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6163 */
} /* line 6163 */
		 /* line 6164 */
  sim_icache_fetch(4502 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6167 */
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
} /* line 6167 */
l_lr_346: ;/* line 6167 */
__LABEL(l_lr_346);
  sim_icache_fetch(4505 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6169 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6170 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6171 */
   __ADD_CYCLES(1);
} /* line 6171 */
  sim_icache_fetch(4508 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6174 */
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

  sim_icache_fetch(4509 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6220 */
   __MOV(reg_r0_3, 0); /* line 6221 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6222 */
   __ADD_CYCLES(1);
} /* line 6222 */
  sim_icache_fetch(4513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6224 */
} /* line 6224 */
  sim_icache_fetch(4514 + t_thisfile.offset, 1);
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
} /* line 6226 */
  sim_icache_fetch(4515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6229 */
l_L272X3: ;/* line 6232 */
__LABEL(l_L272X3);
  sim_icache_fetch(4516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6235 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6235 */
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

  sim_icache_fetch(4518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6251 */
} /* line 6251 */
  sim_icache_fetch(4519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6254 */
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

  sim_icache_fetch(4520 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6269 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6270 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6271 */
} /* line 6271 */
  sim_icache_fetch(4525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6273 */
} /* line 6273 */
  sim_icache_fetch(4526 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6275 */
} /* line 6275 */
  sim_icache_fetch(4527 + t_thisfile.offset, 1);
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
} /* line 6277 */
		 /* line 6278 */
  sim_icache_fetch(4528 + t_thisfile.offset, 2);
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
} /* line 6280 */
l_lr_352: ;/* line 6280 */
__LABEL(l_lr_352);
l_L273X3: ;/* line 6282 */
__LABEL(l_L273X3);
  sim_icache_fetch(4530 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6283 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6284 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6285 */
   __ADD_CYCLES(1);
} /* line 6285 */
  sim_icache_fetch(4533 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6288 */
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

  sim_icache_fetch(4534 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6334 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6335 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6336 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6337 */
} /* line 6337 */
  sim_icache_fetch(4541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6339 */
} /* line 6339 */
  sim_icache_fetch(4542 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6341 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6342 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6343 */
} /* line 6343 */
  sim_icache_fetch(4547 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6345 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6346 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6347 */
  sim_icache_fetch(4551 + t_thisfile.offset, 1);
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
} /* line 6349 */
l_L276X3: ;/* line 6352 */
__LABEL(l_L276X3);
  sim_icache_fetch(4552 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6353 */
   __MOV(reg_r0_3, 0); /* line 6354 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6355 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6356 */
   __ADD_CYCLES(1);
} /* line 6356 */
  sim_icache_fetch(4557 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6358 */
} /* line 6358 */
  sim_icache_fetch(4558 + t_thisfile.offset, 1);
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
} /* line 6360 */
  sim_icache_fetch(4559 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6363 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6364 */
l_L277X3: ;/* line 6367 */
__LABEL(l_L277X3);
  sim_icache_fetch(4562 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6368 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6369 */
} /* line 6369 */
		 /* line 6370 */
  sim_icache_fetch(4566 + t_thisfile.offset, 2);
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
} /* line 6372 */
l_lr_358: ;/* line 6372 */
__LABEL(l_lr_358);
  sim_icache_fetch(4568 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6374 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6375 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6376 */
} /* line 6376 */
		 /* line 6377 */
  sim_icache_fetch(4573 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6379 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6380 */
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
} /* line 6381 */
l_lr_360: ;/* line 6381 */
__LABEL(l_lr_360);
  sim_icache_fetch(4579 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6383 */
   __MOV(reg_r0_3, 0); /* line 6384 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6385 */
   __ADD_CYCLES(1);
} /* line 6385 */
  sim_icache_fetch(4582 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6388 */
l_L275X3: ;/* line 6391 */
__LABEL(l_L275X3);
  sim_icache_fetch(4583 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6392 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6393 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6394 */
   __ADD_CYCLES(1);
} /* line 6394 */
		 /* line 6395 */
  sim_icache_fetch(4587 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6398 */
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
} /* line 6398 */
l_lr_363: ;/* line 6398 */
__LABEL(l_lr_363);
  sim_icache_fetch(4590 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6400 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6401 */
l_L274X3: ;/* line 6404 */
__LABEL(l_L274X3);
  sim_icache_fetch(4592 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6405 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6406 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6407 */
   __ADD_CYCLES(1);
} /* line 6407 */
		 /* line 6408 */
  sim_icache_fetch(4597 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6410 */
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
} /* line 6411 */
l_lr_366: ;/* line 6411 */
__LABEL(l_lr_366);
  sim_icache_fetch(4600 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6413 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6414 */
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

  sim_icache_fetch(4602 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6433 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6434 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6435 */
} /* line 6435 */
  sim_icache_fetch(4606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6437 */
} /* line 6437 */
l_L278X3: ;/* line 6440 */
__LABEL(l_L278X3);
  sim_icache_fetch(4607 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_2); /* line 6441 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6442 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6443 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6444 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6445 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6446 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6447 */
} /* line 6447 */
  sim_icache_fetch(4614 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6449 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6450 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6451 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6452 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6453 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6454 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6455 */
} /* line 6455 */
  sim_icache_fetch(4621 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6457 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6458 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6459 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6460 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6461 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6462 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6463 */
} /* line 6463 */
  sim_icache_fetch(4628 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6465 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6466 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6467 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6468 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6469 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6470 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6471 */
  sim_icache_fetch(4635 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6473 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6474 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6475 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6476 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6477 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6478 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6479 */
} /* line 6479 */
  sim_icache_fetch(4642 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6481 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6482 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6483 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6484 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6485 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6486 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6487 */
} /* line 6487 */
  sim_icache_fetch(4649 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6489 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6490 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6491 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6492 */
  sim_icache_fetch(4653 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6494 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6495 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6496 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6497 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6498 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6499 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6500 */
} /* line 6500 */
  sim_icache_fetch(4660 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6502 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6503 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6504 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6506 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6507 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6508 */
} /* line 6508 */
  sim_icache_fetch(4667 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6510 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6511 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6512 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6513 */
  sim_icache_fetch(4671 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6515 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6516 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6517 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6518 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6519 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6520 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6521 */
} /* line 6521 */
  sim_icache_fetch(4678 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6523 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6525 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6527 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6528 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6529 */
} /* line 6529 */
  sim_icache_fetch(4685 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6531 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6532 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6533 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6534 */
  sim_icache_fetch(4689 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6536 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6537 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6538 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6539 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6540 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6541 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6542 */
} /* line 6542 */
  sim_icache_fetch(4696 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6544 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6545 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6546 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6547 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6548 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6549 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6550 */
} /* line 6550 */
  sim_icache_fetch(4703 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6552 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6553 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6554 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6555 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6556 */
  sim_icache_fetch(4708 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6558 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6559 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6560 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6561 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6562 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6564 */
} /* line 6564 */
  sim_icache_fetch(4722 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6567 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6568 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6569 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6570 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6571 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6572 */
} /* line 6572 */
  sim_icache_fetch(4736 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6574 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6575 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6576 */
  sim_icache_fetch(4741 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6578 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6579 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6580 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6581 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6582 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6583 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6584 */
} /* line 6584 */
  sim_icache_fetch(4755 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6588 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6589 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6590 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6591 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6592 */
} /* line 6592 */
  sim_icache_fetch(4769 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
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
  sim_icache_fetch(4774 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6600 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6601 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6602 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6604 */
} /* line 6604 */
  sim_icache_fetch(4788 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6606 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6608 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6610 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6611 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6612 */
} /* line 6612 */
  sim_icache_fetch(4802 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6614 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6615 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6616 */
  sim_icache_fetch(4807 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6620 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6621 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6622 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6623 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6624 */
} /* line 6624 */
  sim_icache_fetch(4821 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6626 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6627 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6628 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6629 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6630 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6631 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6632 */
} /* line 6632 */
  sim_icache_fetch(4835 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6634 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6635 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L287X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6636 */
  sim_icache_fetch(4840 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6639 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6640 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6641 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6642 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6644 */
} /* line 6644 */
  sim_icache_fetch(4854 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6646 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6647 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6648 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6651 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6652 */
} /* line 6652 */
  sim_icache_fetch(4868 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6654 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6655 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6656 */
  sim_icache_fetch(4873 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6658 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6659 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6660 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6661 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6662 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6664 */
} /* line 6664 */
  sim_icache_fetch(4887 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6666 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6667 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6668 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6669 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6670 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6671 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6672 */
} /* line 6672 */
  sim_icache_fetch(4901 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6674 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6675 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6676 */
  sim_icache_fetch(4906 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6678 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6679 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6680 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6681 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6682 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6683 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6684 */
} /* line 6684 */
  sim_icache_fetch(4920 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6686 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6687 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6688 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6689 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6690 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6691 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6692 */
} /* line 6692 */
  sim_icache_fetch(4934 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6694 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6695 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6696 */
  sim_icache_fetch(4939 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6698 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6699 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6700 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6701 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6702 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6703 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6704 */
} /* line 6704 */
  sim_icache_fetch(4952 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6706 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6707 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6708 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6709 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6710 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6711 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6712 */
} /* line 6712 */
  sim_icache_fetch(4965 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6714 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6715 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6716 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6717 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6718 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6719 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L291X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6721 */
  sim_icache_fetch(4978 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L278X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L278X3;
} /* line 6723 */
l_L291X3: ;/* line 6726 */
__LABEL(l_L291X3);
  sim_icache_fetch(4979 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6727 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6728 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6729 */
l_L293X3: ;/* line 6732 */
__LABEL(l_L293X3);
  sim_icache_fetch(4983 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6733 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6734 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6735 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6736 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 4); /* line 6737 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 5); /* line 6738 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6739 */
} /* line 6739 */
  sim_icache_fetch(4990 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 6); /* line 6741 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 7); /* line 6742 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 8); /* line 6743 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6744 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6745 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6746 */
  sim_icache_fetch(4996 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6748 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6749 */
  sim_icache_fetch(4998 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6751 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6752 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6753 */
  sim_icache_fetch(5001 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6755 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6756 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6757 */
  sim_icache_fetch(5004 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6759 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6760 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6761 */
  sim_icache_fetch(5007 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6763 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 12); /* line 6764 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6765 */
  sim_icache_fetch(5010 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6767 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 13); /* line 6768 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6769 */
  sim_icache_fetch(5013 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6771 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 14); /* line 6772 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6773 */
  sim_icache_fetch(5016 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6775 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 15); /* line 6776 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6777 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6778 */
  sim_icache_fetch(5020 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6780 */
   __CMPGT(reg_b0_7, reg_r0_5, 0); /* line 6781 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6782 */
  sim_icache_fetch(5023 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6784 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6785 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6786 */
  sim_icache_fetch(5026 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6788 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6789 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6790 */
  sim_icache_fetch(5029 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6792 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6793 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6794 */
  sim_icache_fetch(5032 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6796 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 4); /* line 6797 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6798 */
  sim_icache_fetch(5035 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6800 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 5); /* line 6801 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6802 */
  sim_icache_fetch(5038 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6804 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 6); /* line 6805 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6806 */
  sim_icache_fetch(5041 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6808 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 6809 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6810 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6811 */
  sim_icache_fetch(5045 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6813 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 6814 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6815 */
  sim_icache_fetch(5048 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6817 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6818 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6819 */
  sim_icache_fetch(5051 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6821 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6822 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6823 */
  sim_icache_fetch(5054 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6825 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6826 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6827 */
  sim_icache_fetch(5057 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6829 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 12); /* line 6830 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6831 */
  sim_icache_fetch(5060 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6833 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 13); /* line 6834 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6835 */
  sim_icache_fetch(5063 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6837 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 14); /* line 6838 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6839 */
  sim_icache_fetch(5066 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6841 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 6842 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6843 */
  sim_icache_fetch(5069 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6845 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6846 */
  sim_icache_fetch(5071 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6848 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6849 */
  sim_icache_fetch(5073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6851 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6852 */
  sim_icache_fetch(5075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6854 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6855 */
  sim_icache_fetch(5077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6857 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6858 */
  sim_icache_fetch(5079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6860 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6861 */
  sim_icache_fetch(5081 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6863 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6864 */
  sim_icache_fetch(5083 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6866 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6867 */
l_L294X3: ;/* line 6870 */
__LABEL(l_L294X3);
  sim_icache_fetch(5085 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6872 */
l_L290X3: ;/* line 6875 */
__LABEL(l_L290X3);
  sim_icache_fetch(5086 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6876 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6877 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6878 */
l_L289X3: ;/* line 6881 */
__LABEL(l_L289X3);
  sim_icache_fetch(5090 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6882 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6883 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6884 */
l_L288X3: ;/* line 6887 */
__LABEL(l_L288X3);
  sim_icache_fetch(5094 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6888 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6889 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6890 */
l_L287X3: ;/* line 6893 */
__LABEL(l_L287X3);
  sim_icache_fetch(5098 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6894 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6895 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6896 */
l_L286X3: ;/* line 6899 */
__LABEL(l_L286X3);
  sim_icache_fetch(5102 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6900 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6901 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6902 */
l_L285X3: ;/* line 6905 */
__LABEL(l_L285X3);
  sim_icache_fetch(5106 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6906 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6907 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6908 */
l_L284X3: ;/* line 6911 */
__LABEL(l_L284X3);
  sim_icache_fetch(5110 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6912 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6913 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6914 */
l_L283X3: ;/* line 6917 */
__LABEL(l_L283X3);
  sim_icache_fetch(5114 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6918 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6919 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6920 */
l_L282X3: ;/* line 6923 */
__LABEL(l_L282X3);
  sim_icache_fetch(5118 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6924 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6925 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6926 */
l_L281X3: ;/* line 6929 */
__LABEL(l_L281X3);
  sim_icache_fetch(5121 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6930 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6931 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6932 */
l_L280X3: ;/* line 6935 */
__LABEL(l_L280X3);
  sim_icache_fetch(5124 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6936 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6937 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6938 */
l_L279X3: ;/* line 6941 */
__LABEL(l_L279X3);
  sim_icache_fetch(5127 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6942 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6943 */
} /* line 6943 */
l_L292X3: ;/* line 6945 */
__LABEL(l_L292X3);
  sim_icache_fetch(5129 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6946 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6947 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6948 */
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

  sim_icache_fetch(5132 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6964 */
} /* line 6964 */
  sim_icache_fetch(5133 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6967 */
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

  sim_icache_fetch(5134 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6983 */
} /* line 6983 */
  sim_icache_fetch(5135 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6986 */
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


static sim_fileinfo_t t_thisfile = {"compress.s", 5136, 0, 0, 0, 2};

