/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/5_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_10102Xoffset[1];
unsigned int compress_10102Xbuf[3];
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
unsigned int compress_10102XBuf[216]; 
unsigned int compress_10102Xrcs_ident[6]; 
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
	(144 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(158 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(150 << 5),
	(149 << 5),
	(148 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(147 << 5),
	(162 << 5),
	(162 << 5),
	(146 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(162 << 5),
	(145 << 5)
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

unsigned int compress_10102XBuf[216] = { 
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

unsigned int compress_10102Xrcs_ident[6] = { 
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
  sim_icache_fetch(11 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 32 */
   __MOV(reg_r0_6, (unsigned int) 800); /* line 33 */
   __MOV(reg_r0_5, (unsigned int) compress_10102XBuf); /* line 34 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 35 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 36 */
} /* line 36 */
  sim_icache_fetch(18 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), 0); /* line 38 */
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
  reg_l0_0 = (139 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 15); /* line 178 */
   __ADD(reg_r0_23, reg_r0_3, (unsigned int) 14); /* line 179 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 13); /* line 180 */
   __ADD(reg_r0_21, reg_r0_3, (unsigned int) 12); /* line 181 */
} /* line 181 */
  sim_icache_fetch(48 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 11); /* line 183 */
   __ADD(reg_r0_19, reg_r0_3, (unsigned int) 10); /* line 184 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 9); /* line 185 */
   __ADD(reg_r0_17, reg_r0_3, (unsigned int) 8); /* line 186 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 7); /* line 187 */
} /* line 187 */
  sim_icache_fetch(53 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 189 */
   __ADD(reg_r0_15, reg_r0_3, (unsigned int) 6); /* line 190 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 191 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 192 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 193 */
} /* line 193 */
  sim_icache_fetch(58 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SXTB(reg_r0_4, reg_r0_4); /* line 195 */
   __MOV(reg_r0_5, 0); /* line 196 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 197 */
   __MOV(reg_r0_2, reg_r0_3); /* line 198 */
} /* line 198 */
l_L0X3: ;/* line 201 */
__LABEL(l_L0X3);
  sim_icache_fetch(62 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 202 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 203 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 204 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_10,0,1)); /* line 205 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_12,0,1)); /* line 206 */
} /* line 206 */
  sim_icache_fetch(67 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_14,0,1)); /* line 208 */
   __LDBs(reg_r0_26, mem_trace_ld(reg_r0_15,0,1)); /* line 209 */
   __LDBs(reg_r0_27, mem_trace_ld(reg_r0_16,0,1)); /* line 210 */
   __LDBs(reg_r0_28, mem_trace_ld(reg_r0_17,0,1)); /* line 211 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_18,0,1)); /* line 212 */
} /* line 212 */
  sim_icache_fetch(72 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 214 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 215 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 216 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 217 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 218 */
} /* line 218 */
  sim_icache_fetch(77 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 220 */
   __CMPEQ(reg_b0_0, reg_r0_9, reg_r0_4); /* line 221 */
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 222 */
   __CMPEQ(reg_b0_5, reg_r0_11, reg_r0_4); /* line 223 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 224 */
  sim_icache_fetch(82 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_6, reg_r0_3); /* line 226 */
   __CMPNE(reg_b0_2, reg_r0_13, 0); /* line 227 */
   __CMPEQ(reg_b0_3, reg_r0_13, reg_r0_4); /* line 228 */
   __CMPNE(reg_b0_6, reg_r0_25, 0); /* line 229 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 230 */
  sim_icache_fetch(87 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_8, reg_r0_7); /* line 232 */
   __CMPEQ(reg_b0_0, reg_r0_25, reg_r0_4); /* line 233 */
   __CMPNE(reg_b0_4, reg_r0_26, 0); /* line 234 */
   __CMPEQ(reg_b0_7, reg_r0_26, reg_r0_4); /* line 235 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 236 */
  sim_icache_fetch(92 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_5, reg_r0_10, reg_r0_3); /* line 238 */
   __CMPNE(reg_b0_1, reg_r0_27, 0); /* line 239 */
   __CMPEQ(reg_b0_5, reg_r0_27, reg_r0_4); /* line 240 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_19,0,1)); /* line 241 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 242 */
  sim_icache_fetch(97 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_3, reg_r0_12, reg_r0_7); /* line 244 */
   __CMPNE(reg_b0_2, reg_r0_28, 0); /* line 245 */
   __CMPEQ(reg_b0_3, reg_r0_28, reg_r0_4); /* line 246 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_20,0,1)); /* line 247 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 248 */
  sim_icache_fetch(102 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_14, reg_r0_3); /* line 250 */
   __CMPNE(reg_b0_0, reg_r0_29, 0); /* line 251 */
   __CMPEQ(reg_b0_6, reg_r0_29, reg_r0_4); /* line 252 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_21,0,1)); /* line 253 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 254 */
  sim_icache_fetch(107 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_7, reg_r0_15, reg_r0_7); /* line 256 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 257 */
   __CMPEQ(reg_b0_7, reg_r0_9, reg_r0_4); /* line 258 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_22,0,1)); /* line 259 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 260 */
  sim_icache_fetch(112 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_5, reg_r0_16, reg_r0_3); /* line 262 */
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 263 */
   __CMPEQ(reg_b0_5, reg_r0_11, reg_r0_4); /* line 264 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_23,0,1)); /* line 265 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 266 */
  sim_icache_fetch(117 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_3, reg_r0_17, reg_r0_7); /* line 268 */
   __CMPNE(reg_b0_2, reg_r0_13, 0); /* line 269 */
   __CMPEQ(reg_b0_3, reg_r0_13, reg_r0_4); /* line 270 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_24,0,1)); /* line 271 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 272 */
  sim_icache_fetch(122 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_6, reg_r0_18, reg_r0_3); /* line 274 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 275 */
   __CMPEQ(reg_b0_6, reg_r0_9, reg_r0_4); /* line 276 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 277 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 278 */
  sim_icache_fetch(127 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_7, reg_r0_19, reg_r0_7); /* line 280 */
   __CMPNE(reg_b0_4, reg_r0_11, 0); /* line 281 */
   __CMPEQ(reg_b0_7, reg_r0_11, reg_r0_4); /* line 282 */
   __ADD(reg_r0_9, reg_r0_23, (unsigned int) 16); /* line 283 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 284 */
  sim_icache_fetch(132 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_5, reg_r0_20, reg_r0_3); /* line 286 */
   __CMPNE(reg_b0_1, reg_r0_13, 0); /* line 287 */
   __CMPEQ(reg_b0_5, reg_r0_13, reg_r0_4); /* line 288 */
   __ADD(reg_r0_11, reg_r0_22, (unsigned int) 16); /* line 289 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 290 */
  sim_icache_fetch(137 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_3, reg_r0_21, reg_r0_7); /* line 292 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 293 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 294 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 295 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 296 */
  sim_icache_fetch(142 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_22, reg_b0_6, reg_r0_22, reg_r0_3); /* line 298 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 299 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 300 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 301 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 302 */
  sim_icache_fetch(147 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_23, reg_b0_7, reg_r0_23, reg_r0_22); /* line 304 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 305 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 306 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 307 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 308 */
  sim_icache_fetch(152 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_5, reg_b0_5, reg_r0_24, reg_r0_23); /* line 310 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 311 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 312 */
   __ADD(reg_r0_24, reg_r0_24, (unsigned int) 16); /* line 313 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 314 */
  sim_icache_fetch(157 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 316 */
   __LDBs(reg_r0_3, mem_trace_ld(reg_r0_6,0,1)); /* line 317 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_8,0,1)); /* line 318 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_10,0,1)); /* line 319 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_12,0,1)); /* line 320 */
} /* line 320 */
  sim_icache_fetch(162 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_26, mem_trace_ld(reg_r0_2,0,1)); /* line 322 */
   __LDBs(reg_r0_27, mem_trace_ld(reg_r0_14,0,1)); /* line 323 */
   __LDBs(reg_r0_28, mem_trace_ld(reg_r0_15,0,1)); /* line 324 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_16,0,1)); /* line 325 */
   __LDBs(reg_r0_30, mem_trace_ld(reg_r0_17,0,1)); /* line 326 */
} /* line 326 */
  sim_icache_fetch(167 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 328 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 329 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 330 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 331 */
   __CMPNE(reg_b0_4, reg_r0_13, 0); /* line 332 */
} /* line 332 */
  sim_icache_fetch(172 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPNE(reg_b0_5, reg_r0_26, 0); /* line 334 */
   __CMPEQ(reg_b0_6, reg_r0_26, reg_r0_4); /* line 335 */
   __CMPEQ(reg_b0_7, reg_r0_13, reg_r0_4); /* line 336 */
   __LDBs(reg_r0_3, mem_trace_ld(reg_r0_18,0,1)); /* line 337 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_19,0,1)); /* line 338 */
} /* line 338 */
  sim_icache_fetch(177 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_13, reg_b0_6, reg_r0_2, reg_r0_5); /* line 340 */
   __CMPNE(reg_b0_5, reg_r0_25, 0); /* line 341 */
   __CMPEQ(reg_b0_6, reg_r0_25, reg_r0_4); /* line 342 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_20,0,1)); /* line 343 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 344 */
  sim_icache_fetch(182 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_26, reg_b0_1, reg_r0_6, reg_r0_13); /* line 346 */
   __CMPNE(reg_b0_0, reg_r0_27, 0); /* line 347 */
   __CMPEQ(reg_b0_1, reg_r0_27, reg_r0_4); /* line 348 */
   __LDBs(reg_r0_27, mem_trace_ld(reg_r0_21,0,1)); /* line 349 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 350 */
  sim_icache_fetch(187 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_13, reg_b0_3, reg_r0_8, reg_r0_26); /* line 352 */
   __CMPNE(reg_b0_2, reg_r0_28, 0); /* line 353 */
   __CMPEQ(reg_b0_3, reg_r0_28, reg_r0_4); /* line 354 */
   __LDBs(reg_r0_28, mem_trace_ld(reg_r0_11,0,1)); /* line 355 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 356 */
  sim_icache_fetch(192 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_26, reg_b0_7, reg_r0_10, reg_r0_13); /* line 358 */
   __CMPNE(reg_b0_4, reg_r0_29, 0); /* line 359 */
   __CMPEQ(reg_b0_7, reg_r0_29, reg_r0_4); /* line 360 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_9,0,1)); /* line 361 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 362 */
  sim_icache_fetch(197 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_13, reg_b0_6, reg_r0_12, reg_r0_26); /* line 364 */
   __CMPNE(reg_b0_5, reg_r0_30, 0); /* line 365 */
   __CMPEQ(reg_b0_6, reg_r0_30, reg_r0_4); /* line 366 */
   __LDBs(reg_r0_30, mem_trace_ld(reg_r0_24,0,1)); /* line 367 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 368 */
  sim_icache_fetch(202 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_26, reg_b0_1, reg_r0_14, reg_r0_13); /* line 370 */
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 371 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 372 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 373 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 374 */
  sim_icache_fetch(207 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_3, reg_r0_15, reg_r0_26); /* line 376 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 377 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 378 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 379 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 380 */
  sim_icache_fetch(212 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_7, reg_r0_16, reg_r0_3); /* line 382 */
   __CMPNE(reg_b0_4, reg_r0_25, 0); /* line 383 */
   __CMPEQ(reg_b0_7, reg_r0_25, reg_r0_4); /* line 384 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 385 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 386 */
  sim_icache_fetch(217 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_6, reg_r0_17, reg_r0_7); /* line 388 */
   __CMPNE(reg_b0_5, reg_r0_27, 0); /* line 389 */
   __CMPEQ(reg_b0_6, reg_r0_27, reg_r0_4); /* line 390 */
   __ADD(reg_r0_13, reg_r0_18, (unsigned int) 16); /* line 391 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 392 */
  sim_icache_fetch(222 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_18, reg_r0_3); /* line 394 */
   __CMPNE(reg_b0_0, reg_r0_28, 0); /* line 395 */
   __CMPEQ(reg_b0_1, reg_r0_28, reg_r0_4); /* line 396 */
   __ADD(reg_r0_25, reg_r0_19, (unsigned int) 16); /* line 397 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 398 */
  sim_icache_fetch(227 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_3, reg_r0_19, reg_r0_7); /* line 400 */
   __CMPNE(reg_b0_2, reg_r0_29, 0); /* line 401 */
   __CMPEQ(reg_b0_3, reg_r0_29, reg_r0_4); /* line 402 */
   __ADD(reg_r0_26, reg_r0_20, (unsigned int) 16); /* line 403 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 404 */
  sim_icache_fetch(232 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_7, reg_r0_20, reg_r0_3); /* line 406 */
   __CMPNE(reg_b0_4, reg_r0_30, 0); /* line 407 */
   __CMPEQ(reg_b0_7, reg_r0_30, reg_r0_4); /* line 408 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 409 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 410 */
  sim_icache_fetch(237 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_6, reg_r0_21, reg_r0_7); /* line 412 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 413 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 414 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 415 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 416 */
  sim_icache_fetch(242 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_11, reg_r0_3); /* line 418 */
   __ADD(reg_r0_23, reg_r0_9, (unsigned int) 16); /* line 419 */
   __ADD(reg_r0_22, reg_r0_11, (unsigned int) 16); /* line 420 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 421 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 422 */
  sim_icache_fetch(247 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_9, reg_b0_3, reg_r0_9, reg_r0_7); /* line 424 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 425 */
   __ADD(reg_r0_3, reg_r0_24, (unsigned int) 16); /* line 426 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 427 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 428 */
  sim_icache_fetch(252 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_24, reg_r0_9); /* line 430 */
   __MOV(reg_r0_19, reg_r0_25); /* line 431 */
   __MOV(reg_r0_20, reg_r0_26); /* line 432 */
   __MOV(reg_r0_24, reg_r0_3); /* line 433 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 434 */
  sim_icache_fetch(257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_18, reg_r0_13); /* line 436 */
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 437 */
l_L27X3: ;/* line 440 */
__LABEL(l_L27X3);
  sim_icache_fetch(259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_23, reg_r0_9); /* line 441 */
} /* line 441 */
l_L16X3: ;/* line 444 */
__LABEL(l_L16X3);
  sim_icache_fetch(260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_23); /* line 446 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 447 */
l_L26X3: ;/* line 450 */
__LABEL(l_L26X3);
  sim_icache_fetch(262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_7); /* line 451 */
} /* line 451 */
l_L15X3: ;/* line 454 */
__LABEL(l_L15X3);
  sim_icache_fetch(263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_22); /* line 456 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 457 */
l_L14X3: ;/* line 460 */
__LABEL(l_L14X3);
  sim_icache_fetch(265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 463 */
l_L13X3: ;/* line 466 */
__LABEL(l_L13X3);
  sim_icache_fetch(266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 468 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 469 */
l_L12X3: ;/* line 472 */
__LABEL(l_L12X3);
  sim_icache_fetch(268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 475 */
l_L11X3: ;/* line 478 */
__LABEL(l_L11X3);
  sim_icache_fetch(269 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 480 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 481 */
l_L10X3: ;/* line 484 */
__LABEL(l_L10X3);
  sim_icache_fetch(271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 487 */
l_L25X3: ;/* line 490 */
__LABEL(l_L25X3);
  sim_icache_fetch(272 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 492 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 493 */
l_L24X3: ;/* line 496 */
__LABEL(l_L24X3);
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 499 */
l_L23X3: ;/* line 502 */
__LABEL(l_L23X3);
  sim_icache_fetch(275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_26); /* line 504 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 505 */
l_L22X3: ;/* line 508 */
__LABEL(l_L22X3);
  sim_icache_fetch(277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_13); /* line 510 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 511 */
l_L21X3: ;/* line 514 */
__LABEL(l_L21X3);
  sim_icache_fetch(279 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_26); /* line 516 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 517 */
l_L20X3: ;/* line 520 */
__LABEL(l_L20X3);
  sim_icache_fetch(281 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_13); /* line 522 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 523 */
l_L19X3: ;/* line 526 */
__LABEL(l_L19X3);
  sim_icache_fetch(283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_26); /* line 527 */
} /* line 527 */
l_L3X3: ;/* line 530 */
__LABEL(l_L3X3);
  sim_icache_fetch(284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 532 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 533 */
l_L18X3: ;/* line 536 */
__LABEL(l_L18X3);
  sim_icache_fetch(286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_13); /* line 537 */
} /* line 537 */
l_L2X3: ;/* line 540 */
__LABEL(l_L2X3);
  sim_icache_fetch(287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 543 */
l_L17X3: ;/* line 546 */
__LABEL(l_L17X3);
  sim_icache_fetch(288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 546 */
l_L1X3: ;/* line 549 */
__LABEL(l_L1X3);
  sim_icache_fetch(289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 551 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 552 */
l_L9X3: ;/* line 555 */
__LABEL(l_L9X3);
  sim_icache_fetch(291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 557 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 558 */
l_L8X3: ;/* line 561 */
__LABEL(l_L8X3);
  sim_icache_fetch(293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 564 */
l_L7X3: ;/* line 567 */
__LABEL(l_L7X3);
  sim_icache_fetch(294 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 569 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 570 */
l_L6X3: ;/* line 573 */
__LABEL(l_L6X3);
  sim_icache_fetch(296 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 576 */
l_L5X3: ;/* line 579 */
__LABEL(l_L5X3);
  sim_icache_fetch(297 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 581 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 582 */
l_L4X3: ;/* line 585 */
__LABEL(l_L4X3);
  sim_icache_fetch(299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 588 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 111: goto l_L0X3;
    case 112: goto l_L27X3;
    case 113: goto l_L16X3;
    case 114: goto l_L26X3;
    case 115: goto l_L15X3;
    case 116: goto l_L14X3;
    case 117: goto l_L13X3;
    case 118: goto l_L12X3;
    case 119: goto l_L11X3;
    case 120: goto l_L10X3;
    case 121: goto l_L25X3;
    case 122: goto l_L24X3;
    case 123: goto l_L23X3;
    case 124: goto l_L22X3;
    case 125: goto l_L21X3;
    case 126: goto l_L20X3;
    case 127: goto l_L19X3;
    case 128: goto l_L3X3;
    case 129: goto l_L18X3;
    case 130: goto l_L2X3;
    case 131: goto l_L17X3;
    case 132: goto l_L1X3;
    case 133: goto l_L9X3;
    case 134: goto l_L8X3;
    case 135: goto l_L7X3;
    case 136: goto l_L6X3;
    case 137: goto l_L5X3;
    case 138: goto l_L4X3;
    case 139:
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
  reg_l0_0 = (206 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(300 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 604 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 605 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 606 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 607 */
} /* line 607 */
  sim_icache_fetch(307 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 609 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 610 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 611 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 612 */
} /* line 612 */
  sim_icache_fetch(312 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 614 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 615 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 616 */
} /* line 616 */
		 /* line 617 */
  sim_icache_fetch(315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 619 */
l_lr_40: ;/* line 619 */
__LABEL(l_lr_40);
  sim_icache_fetch(317 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 621 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 622 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 623 */
   __ADD_CYCLES(1);
} /* line 623 */
  sim_icache_fetch(320 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 625 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 626 */
} /* line 626 */
l_L28X3: ;/* line 629 */
__LABEL(l_L28X3);
  sim_icache_fetch(322 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 630 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 631 */
} /* line 631 */
  sim_icache_fetch(324 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 633 */
  sim_icache_fetch(325 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 635 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 636 */
   __ADD_CYCLES(1);
} /* line 636 */
  sim_icache_fetch(327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 638 */
} /* line 638 */
  sim_icache_fetch(328 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 640 */
l_L31X3: ;/* line 643 */
__LABEL(l_L31X3);
  sim_icache_fetch(329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 644 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 645 */
   __ADD_CYCLES(1);
} /* line 645 */
  sim_icache_fetch(331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 647 */
} /* line 647 */
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 649 */
} /* line 649 */
  sim_icache_fetch(333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 651 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 652 */
   __ADD_CYCLES(1);
} /* line 652 */
  sim_icache_fetch(335 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 654 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 655 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 656 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 657 */
} /* line 657 */
  sim_icache_fetch(340 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 659 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 660 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 661 */
  sim_icache_fetch(343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L33X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 663 */
  sim_icache_fetch(344 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 664 */
  sim_icache_fetch(345 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 666 */
l__X1XCompressXTAGX0X0: ;/* line 668 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(346 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 669 */
   __GOTO(l_L31X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L31X3;
} /* line 670 */
l__X1XCompressXTAGX0X7: ;/* line 673 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(349 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 674 */
   __GOTO(l_L31X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L31X3;
} /* line 675 */
l__X1XCompressXTAGX0X6: ;/* line 678 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 679 */
} /* line 679 */
  sim_icache_fetch(353 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 681 */
   __GOTO(l_L31X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L31X3;
} /* line 682 */
l__X1XCompressXTAGX0X5: ;/* line 685 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 686 */
} /* line 686 */
  sim_icache_fetch(357 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 688 */
   __GOTO(l_L31X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L31X3;
} /* line 689 */
l__X1XCompressXTAGX0X4: ;/* line 692 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 693 */
} /* line 693 */
  sim_icache_fetch(361 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 695 */
   __GOTO(l_L31X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L31X3;
} /* line 696 */
l__X1XCompressXTAGX0X3: ;/* line 699 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 700 */
} /* line 700 */
  sim_icache_fetch(365 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 702 */
   __GOTO(l_L31X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L31X3;
} /* line 703 */
l__X1XCompressXTAGX0X2: ;/* line 706 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(368 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 707 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 708 */
   __ADD_CYCLES(1);
} /* line 708 */
  sim_icache_fetch(370 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 710 */
} /* line 710 */
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 712 */
} /* line 712 */
  sim_icache_fetch(372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 714 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 715 */
   __ADD_CYCLES(1);
} /* line 715 */
  sim_icache_fetch(374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 717 */
} /* line 717 */
  sim_icache_fetch(375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 719 */
l_L30X3: ;/* line 721 */
__LABEL(l_L30X3);
  sim_icache_fetch(376 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 722 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 723 */
   __GOTO(l_L28X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L28X3;
} /* line 724 */
l_L34X3: ;/* line 727 */
__LABEL(l_L34X3);
  sim_icache_fetch(379 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 728 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 729 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 730 */
} /* line 730 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 732 */
} /* line 732 */
  sim_icache_fetch(383 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 734 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 735 */
  sim_icache_fetch(385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 738 */
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 740 */
l_L35X3: ;/* line 743 */
__LABEL(l_L35X3);
		 /* line 743 */
  sim_icache_fetch(387 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 746 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (206 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 746 */
l_lr_54: ;/* line 746 */
__LABEL(l_lr_54);
		 /* line 747 */
  sim_icache_fetch(391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (206 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 749 */
l_lr_56: ;/* line 749 */
__LABEL(l_lr_56);
  sim_icache_fetch(393 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 751 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 752 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 753 */
   __ADD_CYCLES(1);
} /* line 753 */
  sim_icache_fetch(396 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 756 */
l__X1XCompressXTAGX0X1: ;/* line 759 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 759 */
  sim_icache_fetch(397 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 762 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 763 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 763 */
l_lr_59: ;/* line 763 */
__LABEL(l_lr_59);
  sim_icache_fetch(401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 765 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 766 */
} /* line 766 */
  sim_icache_fetch(403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L31X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L31X3;
} /* line 768 */
l_L33X3: ;/* line 771 */
__LABEL(l_L33X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 772 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 772 */
  sim_icache_fetch(404 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 775 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (206 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 775 */
l_lr_63: ;/* line 775 */
__LABEL(l_lr_63);
		 /* line 776 */
  sim_icache_fetch(408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (206 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 778 */
l_lr_65: ;/* line 778 */
__LABEL(l_lr_65);
  sim_icache_fetch(410 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 780 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 781 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 782 */
   __ADD_CYCLES(1);
} /* line 782 */
  sim_icache_fetch(413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 785 */
l_L32X3: ;/* line 788 */
__LABEL(l_L32X3);
  sim_icache_fetch(414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 789 */
l_L29X3: ;/* line 792 */
__LABEL(l_L29X3);
  sim_icache_fetch(415 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 793 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 794 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 795 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 796 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 797 */
} /* line 797 */
  sim_icache_fetch(422 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 799 */
} /* line 799 */
  sim_icache_fetch(424 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 801 */
} /* line 801 */
  sim_icache_fetch(425 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 4096); /* line 803 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 804 */
  sim_icache_fetch(428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 806 */
} /* line 806 */
l_L37X3: ;/* line 808 */
__LABEL(l_L37X3);
  sim_icache_fetch(430 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 809 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 810 */
   __ADD_CYCLES(1);
} /* line 810 */
  sim_icache_fetch(433 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 12); /* line 812 */
} /* line 812 */
  sim_icache_fetch(434 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 814 */
  sim_icache_fetch(435 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 816 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 817 */
} /* line 817 */
l_L39X3: ;/* line 819 */
__LABEL(l_L39X3);
  sim_icache_fetch(439 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 820 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 821 */
   __ADD_CYCLES(1);
} /* line 821 */
  sim_icache_fetch(442 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 823 */
} /* line 823 */
  sim_icache_fetch(443 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 825 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 826 */
		 /* line 827 */
  sim_icache_fetch(446 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 829 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 830 */
l_lr_71: ;/* line 830 */
__LABEL(l_lr_71);
l_L41X3: ;/* line 832 */
__LABEL(l_L41X3);
  sim_icache_fetch(450 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 833 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 834 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 835 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 836 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 837 */
} /* line 837 */
  sim_icache_fetch(460 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 839 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 840 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 841 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 842 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 843 */
} /* line 843 */
  sim_icache_fetch(470 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 845 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 846 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 847 */
} /* line 847 */
  sim_icache_fetch(474 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 849 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 850 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 851 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 852 */
  sim_icache_fetch(478 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 854 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 855 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L43X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 856 */
  sim_icache_fetch(482 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 858 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 859 */
l_L45X3: ;/* line 861 */
__LABEL(l_L45X3);
		 /* line 861 */
  sim_icache_fetch(485 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (206 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 863 */
l_lr_75: ;/* line 863 */
__LABEL(l_lr_75);
  sim_icache_fetch(487 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 865 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 866 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 867 */
   __ADD_CYCLES(1);
} /* line 867 */
  sim_icache_fetch(490 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 870 */
l_L44X3: ;/* line 873 */
__LABEL(l_L44X3);
  sim_icache_fetch(491 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 874 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 875 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 876 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 877 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 878 */
   __ADD_CYCLES(1);
} /* line 878 */
  sim_icache_fetch(500 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 880 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 881 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 882 */
} /* line 882 */
  sim_icache_fetch(503 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 884 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 885 */
} /* line 885 */
  sim_icache_fetch(506 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L46X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 887 */
  sim_icache_fetch(507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 889 */
} /* line 889 */
  sim_icache_fetch(509 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 891 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 892 */
   __ADD_CYCLES(1);
} /* line 892 */
  sim_icache_fetch(511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 894 */
} /* line 894 */
l_L47X3: ;/* line 896 */
__LABEL(l_L47X3);
  sim_icache_fetch(512 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 897 */
} /* line 897 */
  sim_icache_fetch(513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 900 */
  sim_icache_fetch(514 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 902 */
l_L48X3: ;/* line 905 */
__LABEL(l_L48X3);
  sim_icache_fetch(515 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 906 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 907 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 908 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 909 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 910 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 911 */
   __ADD_CYCLES(1);
} /* line 911 */
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 913 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 914 */
} /* line 914 */
  sim_icache_fetch(527 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 916 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 917 */
} /* line 917 */
  sim_icache_fetch(530 + t_thisfile.offset, 1);
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
} /* line 919 */
  sim_icache_fetch(531 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 921 */
} /* line 921 */
  sim_icache_fetch(533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 923 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 924 */
   __ADD_CYCLES(1);
} /* line 924 */
  sim_icache_fetch(535 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 926 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 927 */
} /* line 927 */
l_L50X3: ;/* line 929 */
__LABEL(l_L50X3);
  sim_icache_fetch(538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 930 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 931 */
} /* line 931 */
  sim_icache_fetch(540 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 933 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 934 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 935 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 936 */
} /* line 936 */
  sim_icache_fetch(546 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 938 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 939 */
		 /* line 940 */
  sim_icache_fetch(549 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (206 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 942 */
l_lr_81: ;/* line 942 */
__LABEL(l_lr_81);
  sim_icache_fetch(551 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 944 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 945 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 946 */
   __ADD_CYCLES(1);
} /* line 946 */
  sim_icache_fetch(554 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 949 */
l_L42X3: ;/* line 952 */
__LABEL(l_L42X3);
		 /* line 952 */
  sim_icache_fetch(555 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 954 */
l_lr_84: ;/* line 954 */
__LABEL(l_lr_84);
  sim_icache_fetch(557 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 956 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 957 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 958 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 959 */
   __ADD_CYCLES(1);
} /* line 959 */
  sim_icache_fetch(561 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 962 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 963 */
l_L49X3: ;/* line 966 */
__LABEL(l_L49X3);
  sim_icache_fetch(564 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 967 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 968 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 969 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 970 */
} /* line 970 */
  sim_icache_fetch(570 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 972 */
   __GOTO(l_L50X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L50X3;
} /* line 973 */
l_L46X3: ;/* line 976 */
__LABEL(l_L46X3);
  sim_icache_fetch(573 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 977 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 978 */
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 979 */
l_L43X3: ;/* line 982 */
__LABEL(l_L43X3);
  sim_icache_fetch(577 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 983 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 984 */
} /* line 984 */
  sim_icache_fetch(580 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 986 */
} /* line 986 */
  sim_icache_fetch(581 + t_thisfile.offset, 1);
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
} /* line 989 */
  sim_icache_fetch(582 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 991 */
l_L40X3: ;/* line 994 */
__LABEL(l_L40X3);
  sim_icache_fetch(583 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 995 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 996 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 997 */
   __ADD_CYCLES(1);
} /* line 997 */
  sim_icache_fetch(588 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 999 */
} /* line 999 */
  sim_icache_fetch(590 + t_thisfile.offset, 1);
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
} /* line 1001 */
		 /* line 1002 */
  sim_icache_fetch(591 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1004 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1005 */
l_lr_90: ;/* line 1005 */
__LABEL(l_lr_90);
  sim_icache_fetch(595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 1007 */
l_L51X3: ;/* line 1010 */
__LABEL(l_L51X3);
  sim_icache_fetch(596 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1011 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1012 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1013 */
   __ADD_CYCLES(1);
} /* line 1013 */
  sim_icache_fetch(601 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1015 */
} /* line 1015 */
  sim_icache_fetch(603 + t_thisfile.offset, 1);
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
} /* line 1017 */
		 /* line 1018 */
  sim_icache_fetch(604 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1020 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1021 */
l_lr_93: ;/* line 1021 */
__LABEL(l_lr_93);
  sim_icache_fetch(608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 1023 */
l_L52X3: ;/* line 1026 */
__LABEL(l_L52X3);
  sim_icache_fetch(609 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1027 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1028 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1029 */
   __ADD_CYCLES(1);
} /* line 1029 */
  sim_icache_fetch(614 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1031 */
} /* line 1031 */
  sim_icache_fetch(616 + t_thisfile.offset, 1);
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
} /* line 1033 */
		 /* line 1034 */
  sim_icache_fetch(617 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1036 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1037 */
l_lr_96: ;/* line 1037 */
__LABEL(l_lr_96);
  sim_icache_fetch(621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 1039 */
l_L53X3: ;/* line 1042 */
__LABEL(l_L53X3);
  sim_icache_fetch(622 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1043 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1044 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1045 */
   __ADD_CYCLES(1);
} /* line 1045 */
  sim_icache_fetch(627 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1047 */
} /* line 1047 */
  sim_icache_fetch(629 + t_thisfile.offset, 1);
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
} /* line 1049 */
		 /* line 1050 */
  sim_icache_fetch(630 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1052 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1053 */
l_lr_99: ;/* line 1053 */
__LABEL(l_lr_99);
  sim_icache_fetch(634 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 1055 */
l_L54X3: ;/* line 1058 */
__LABEL(l_L54X3);
		 /* line 1058 */
  sim_icache_fetch(635 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (206 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1060 */
l_lr_102: ;/* line 1060 */
__LABEL(l_lr_102);
  sim_icache_fetch(637 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 1062 */
l_L38X3: ;/* line 1065 */
__LABEL(l_L38X3);
  sim_icache_fetch(638 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1066 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1067 */
} /* line 1067 */
  sim_icache_fetch(641 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1069 */
   __GOTO(l_L39X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L39X3;
} /* line 1070 */
l_L36X3: ;/* line 1073 */
__LABEL(l_L36X3);
  sim_icache_fetch(644 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1074 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1075 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 1076 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 141: goto l_lr_40;
    case 142: goto l_L28X3;
    case 143: goto l_L31X3;
    case 144: goto l__X1XCompressXTAGX0X0;
    case 145: goto l__X1XCompressXTAGX0X7;
    case 146: goto l__X1XCompressXTAGX0X6;
    case 147: goto l__X1XCompressXTAGX0X5;
    case 148: goto l__X1XCompressXTAGX0X4;
    case 149: goto l__X1XCompressXTAGX0X3;
    case 150: goto l__X1XCompressXTAGX0X2;
    case 151: goto l_L30X3;
    case 152: goto l_L34X3;
    case 153: goto l_L35X3;
    case 155: goto l_lr_54;
    case 157: goto l_lr_56;
    case 158: goto l__X1XCompressXTAGX0X1;
    case 160: goto l_lr_59;
    case 161: goto l_L33X3;
    case 162: goto l__X1XCompressXTAGX0XDEFAULT;
    case 164: goto l_lr_63;
    case 166: goto l_lr_65;
    case 167: goto l_L32X3;
    case 168: goto l_L29X3;
    case 169: goto l_L37X3;
    case 170: goto l_L39X3;
    case 172: goto l_lr_71;
    case 173: goto l_L41X3;
    case 174: goto l_L45X3;
    case 176: goto l_lr_75;
    case 177: goto l_L44X3;
    case 178: goto l_L47X3;
    case 179: goto l_L48X3;
    case 180: goto l_L50X3;
    case 182: goto l_lr_81;
    case 183: goto l_L42X3;
    case 185: goto l_lr_84;
    case 186: goto l_L49X3;
    case 187: goto l_L46X3;
    case 188: goto l_L43X3;
    case 189: goto l_L40X3;
    case 191: goto l_lr_90;
    case 192: goto l_L51X3;
    case 194: goto l_lr_93;
    case 195: goto l_L52X3;
    case 197: goto l_lr_96;
    case 198: goto l_L53X3;
    case 200: goto l_lr_99;
    case 201: goto l_L54X3;
    case 203: goto l_lr_102;
    case 204: goto l_L38X3;
    case 205: goto l_L36X3;
    case 206:
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
  reg_l0_0 = (325 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(647 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1214 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1215 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1216 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1217 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1218 */
} /* line 1218 */
  sim_icache_fetch(654 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1220 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1221 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1222 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1223 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1224 */
} /* line 1224 */
  sim_icache_fetch(662 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1226 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1227 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1228 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1229 */
   __MOV(reg_r0_4, 0); /* line 1230 */
} /* line 1230 */
  sim_icache_fetch(670 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 1232 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1233 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1234 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L55X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1235 */
l_L56X3: ;/* line 1237 */
__LABEL(l_L56X3);
  sim_icache_fetch(675 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) compress_10102Xoffset,0,4), 0); /* line 1238 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1239 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, (unsigned int) 256); /* line 1240 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1241 */
   __ADD(reg_r0_11, reg_r0_14, (unsigned int) 1); /* line 1242 */
} /* line 1242 */
  sim_icache_fetch(683 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1244 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1245 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1246 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1247 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 1248 */
} /* line 1248 */
  sim_icache_fetch(692 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1250 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1251 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1252 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1253 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1254 */
} /* line 1254 */
  sim_icache_fetch(702 + t_thisfile.offset, 1);
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
} /* line 1256 */
  sim_icache_fetch(703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1258 */
} /* line 1258 */
  sim_icache_fetch(705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1260 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1261 */
   __ADD_CYCLES(1);
} /* line 1261 */
  sim_icache_fetch(707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1263 */
} /* line 1263 */
l_L58X3: ;/* line 1265 */
__LABEL(l_L58X3);
  sim_icache_fetch(708 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1266 */
} /* line 1266 */
l_L59X3: ;/* line 1269 */
__LABEL(l_L59X3);
  sim_icache_fetch(709 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1270 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1271 */
} /* line 1271 */
  sim_icache_fetch(711 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1273 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1274 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1275 */
  sim_icache_fetch(714 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1277 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1278 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1279 */
  sim_icache_fetch(717 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1281 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1282 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1283 */
  sim_icache_fetch(720 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1285 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1286 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1287 */
  sim_icache_fetch(723 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1289 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1290 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1291 */
  sim_icache_fetch(726 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1293 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1294 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1295 */
  sim_icache_fetch(729 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1297 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1298 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1299 */
  sim_icache_fetch(732 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1301 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1302 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1303 */
  sim_icache_fetch(735 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1305 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1306 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1307 */
  sim_icache_fetch(738 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1309 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1310 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1311 */
  sim_icache_fetch(741 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1313 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1314 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1315 */
  sim_icache_fetch(744 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1317 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1318 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1319 */
  sim_icache_fetch(747 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1321 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1322 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1323 */
  sim_icache_fetch(750 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1325 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1326 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1327 */
  sim_icache_fetch(753 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1329 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1330 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1331 */
  sim_icache_fetch(756 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1333 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1334 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1335 */
  sim_icache_fetch(759 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1337 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1338 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1339 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1340 */
  sim_icache_fetch(763 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1342 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1343 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1344 */
  sim_icache_fetch(766 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1346 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1347 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1348 */
  sim_icache_fetch(769 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1350 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1351 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1352 */
  sim_icache_fetch(772 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1354 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1355 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1356 */
  sim_icache_fetch(775 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1358 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1359 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1360 */
  sim_icache_fetch(778 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1362 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1363 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1364 */
  sim_icache_fetch(781 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1366 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1367 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1368 */
  sim_icache_fetch(784 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1370 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1371 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1372 */
  sim_icache_fetch(787 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1374 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1375 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1376 */
  sim_icache_fetch(790 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1378 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1379 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1380 */
  sim_icache_fetch(793 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1382 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1383 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1384 */
  sim_icache_fetch(796 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1386 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1387 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1388 */
  sim_icache_fetch(799 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1390 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1391 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1392 */
  sim_icache_fetch(802 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1394 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1395 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1396 */
  sim_icache_fetch(805 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1398 */
  sim_icache_fetch(806 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1400 */
   __GOTO(l_L59X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L59X3;
} /* line 1401 */
l_L75X3: ;/* line 1404 */
__LABEL(l_L75X3);
  sim_icache_fetch(808 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1405 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1406 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1407 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1408 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1410 */
} /* line 1410 */
  sim_icache_fetch(814 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 1412 */
l_L77X3: ;/* line 1415 */
__LABEL(l_L77X3);
  sim_icache_fetch(815 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1416 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1417 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1418 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1419 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1420 */
   __ADD_CYCLES(1);
} /* line 1420 */
  sim_icache_fetch(824 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1422 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1423 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1424 */
} /* line 1424 */
  sim_icache_fetch(827 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1426 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1427 */
} /* line 1427 */
  sim_icache_fetch(830 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1429 */
  sim_icache_fetch(831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1431 */
} /* line 1431 */
  sim_icache_fetch(833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1433 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1434 */
   __ADD_CYCLES(1);
} /* line 1434 */
  sim_icache_fetch(835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1436 */
} /* line 1436 */
l_L79X3: ;/* line 1438 */
__LABEL(l_L79X3);
  sim_icache_fetch(836 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1439 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1440 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1441 */
} /* line 1441 */
  sim_icache_fetch(839 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1443 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1444 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1445 */
  sim_icache_fetch(842 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1447 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1448 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1449 */
} /* line 1449 */
  sim_icache_fetch(848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1451 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1452 */
   __ADD_CYCLES(1);
} /* line 1452 */
  sim_icache_fetch(850 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1454 */
} /* line 1454 */
  sim_icache_fetch(851 + t_thisfile.offset, 1);
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
} /* line 1456 */
  sim_icache_fetch(852 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1458 */
} /* line 1458 */
  sim_icache_fetch(853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L77X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L77X3;
} /* line 1460 */
l_L81X3: ;/* line 1463 */
__LABEL(l_L81X3);
  sim_icache_fetch(854 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1464 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1465 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1466 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1467 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1468 */
} /* line 1468 */
  sim_icache_fetch(860 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1470 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1471 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1472 */
   __ADD_CYCLES(1);
} /* line 1472 */
  sim_icache_fetch(863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1474 */
} /* line 1474 */
  sim_icache_fetch(864 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1476 */
l_L83X3: ;/* line 1478 */
__LABEL(l_L83X3);
		 /* line 1478 */
  sim_icache_fetch(865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (325 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1480 */
l_lr_115: ;/* line 1480 */
__LABEL(l_lr_115);
  sim_icache_fetch(867 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1482 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1483 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1484 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1485 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1486 */
} /* line 1486 */
  sim_icache_fetch(875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1488 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1489 */
} /* line 1489 */
  sim_icache_fetch(877 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1491 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1492 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1493 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1494 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1495 */
} /* line 1495 */
  sim_icache_fetch(883 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1497 */
   __SH2ADD(reg_r0_2, reg_r0_2, (unsigned int) htab); /* line 1498 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1499 */
  sim_icache_fetch(888 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1501 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1502 */
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_5); /* line 1503 */
   __GOTO(l_L77X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L77X3;
} /* line 1504 */
l_L84X3: ;/* line 1507 */
__LABEL(l_L84X3);
  sim_icache_fetch(893 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1508 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1509 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1510 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1511 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1512 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1513 */
   __ADD_CYCLES(1);
} /* line 1513 */
  sim_icache_fetch(902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1515 */
} /* line 1515 */
  sim_icache_fetch(903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1517 */
} /* line 1517 */
  sim_icache_fetch(904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L85X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1519 */
		 /* line 1520 */
  sim_icache_fetch(905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (325 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1522 */
l_lr_118: ;/* line 1522 */
__LABEL(l_lr_118);
  sim_icache_fetch(907 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1524 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1525 */
} /* line 1525 */
  sim_icache_fetch(909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L77X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L77X3;
} /* line 1527 */
l_L85X3: ;/* line 1530 */
__LABEL(l_L85X3);
  sim_icache_fetch(910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1531 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1532 */
} /* line 1532 */
  sim_icache_fetch(912 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L77X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L77X3;
} /* line 1534 */
l_L82X3: ;/* line 1537 */
__LABEL(l_L82X3);
  sim_icache_fetch(913 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1538 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1539 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1540 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1541 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1542 */
   __ADD_CYCLES(1);
} /* line 1542 */
  sim_icache_fetch(918 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1544 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1545 */
} /* line 1545 */
  sim_icache_fetch(920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1547 */
} /* line 1547 */
l_L86X3: ;/* line 1550 */
__LABEL(l_L86X3);
  sim_icache_fetch(921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1551 */
} /* line 1551 */
  sim_icache_fetch(922 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1553 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1554 */
} /* line 1554 */
  sim_icache_fetch(924 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1556 */
} /* line 1556 */
  sim_icache_fetch(925 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1558 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1559 */
} /* line 1559 */
  sim_icache_fetch(928 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1561 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1562 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1563 */
} /* line 1563 */
  sim_icache_fetch(931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1565 */
} /* line 1565 */
  sim_icache_fetch(932 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1567 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1568 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1569 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1570 */
} /* line 1570 */
  sim_icache_fetch(937 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1572 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1573 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1574 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1575 */
  sim_icache_fetch(941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1577 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1578 */
  sim_icache_fetch(943 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1580 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1581 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1582 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1583 */
} /* line 1583 */
  sim_icache_fetch(948 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1585 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1586 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1587 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1588 */
  sim_icache_fetch(952 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1590 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1591 */
  sim_icache_fetch(954 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1593 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1594 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1595 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1596 */
} /* line 1596 */
  sim_icache_fetch(959 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1598 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1599 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1600 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1601 */
  sim_icache_fetch(963 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1603 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1604 */
  sim_icache_fetch(965 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1606 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1607 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1608 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1609 */
} /* line 1609 */
  sim_icache_fetch(970 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1611 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1612 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1613 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1614 */
  sim_icache_fetch(974 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1616 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1617 */
  sim_icache_fetch(976 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1619 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1620 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1621 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1622 */
} /* line 1622 */
  sim_icache_fetch(981 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1624 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1625 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1626 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1627 */
  sim_icache_fetch(985 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1629 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1630 */
  sim_icache_fetch(987 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1632 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1633 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1634 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1635 */
} /* line 1635 */
  sim_icache_fetch(992 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1637 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1638 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1639 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1640 */
  sim_icache_fetch(996 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1642 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1643 */
  sim_icache_fetch(998 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1645 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1646 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1647 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1648 */
} /* line 1648 */
  sim_icache_fetch(1003 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1650 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1651 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1652 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1653 */
  sim_icache_fetch(1007 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1655 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1656 */
  sim_icache_fetch(1009 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1658 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1659 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1660 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1661 */
} /* line 1661 */
  sim_icache_fetch(1014 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1663 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1664 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1665 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1666 */
  sim_icache_fetch(1018 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1668 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1669 */
  sim_icache_fetch(1020 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1671 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1672 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1673 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1674 */
} /* line 1674 */
  sim_icache_fetch(1025 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1676 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1677 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1678 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1679 */
  sim_icache_fetch(1029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1681 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1682 */
  sim_icache_fetch(1031 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1684 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1685 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1686 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1687 */
} /* line 1687 */
  sim_icache_fetch(1036 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1689 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1690 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1691 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1692 */
  sim_icache_fetch(1040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1694 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1695 */
  sim_icache_fetch(1042 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1697 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1698 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1699 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1700 */
} /* line 1700 */
  sim_icache_fetch(1047 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1702 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1703 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1704 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1705 */
  sim_icache_fetch(1051 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1707 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1708 */
  sim_icache_fetch(1053 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1710 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1711 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1712 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1713 */
} /* line 1713 */
  sim_icache_fetch(1058 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1715 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1716 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1717 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1718 */
  sim_icache_fetch(1062 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1720 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1721 */
  sim_icache_fetch(1064 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1723 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1724 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1725 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1726 */
} /* line 1726 */
  sim_icache_fetch(1069 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1728 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1729 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1730 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1731 */
  sim_icache_fetch(1073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1733 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1734 */
  sim_icache_fetch(1075 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1736 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1737 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1738 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1739 */
} /* line 1739 */
  sim_icache_fetch(1080 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1741 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1742 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1743 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1744 */
  sim_icache_fetch(1084 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1746 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1747 */
  sim_icache_fetch(1086 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1749 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1750 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1751 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1752 */
} /* line 1752 */
  sim_icache_fetch(1091 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1754 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1755 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1756 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1757 */
  sim_icache_fetch(1095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1759 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1760 */
  sim_icache_fetch(1097 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1762 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1763 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1764 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1765 */
} /* line 1765 */
  sim_icache_fetch(1102 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1767 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1768 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1769 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1770 */
  sim_icache_fetch(1106 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1772 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1773 */
  sim_icache_fetch(1108 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1775 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1776 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1777 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1778 */
} /* line 1778 */
  sim_icache_fetch(1113 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1780 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1781 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1782 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1783 */
  sim_icache_fetch(1117 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1785 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1786 */
  sim_icache_fetch(1119 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1788 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1789 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1790 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1791 */
} /* line 1791 */
  sim_icache_fetch(1124 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1793 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1794 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1795 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1796 */
  sim_icache_fetch(1128 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1798 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1799 */
  sim_icache_fetch(1130 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1801 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1802 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1803 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1804 */
} /* line 1804 */
  sim_icache_fetch(1135 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1806 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1807 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1808 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1809 */
  sim_icache_fetch(1139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1811 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1812 */
  sim_icache_fetch(1141 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1814 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1815 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1816 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1817 */
} /* line 1817 */
  sim_icache_fetch(1146 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1819 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1820 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1821 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1822 */
  sim_icache_fetch(1150 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1824 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1825 */
  sim_icache_fetch(1152 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1827 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1828 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1829 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1830 */
} /* line 1830 */
  sim_icache_fetch(1157 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1832 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1833 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1834 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1835 */
  sim_icache_fetch(1161 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1837 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1838 */
  sim_icache_fetch(1163 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1840 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1841 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1842 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1843 */
} /* line 1843 */
  sim_icache_fetch(1168 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1845 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1846 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1847 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1848 */
  sim_icache_fetch(1172 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1850 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1851 */
  sim_icache_fetch(1174 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1853 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1854 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1855 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1856 */
} /* line 1856 */
  sim_icache_fetch(1179 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1858 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1859 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1860 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1861 */
  sim_icache_fetch(1183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1863 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1864 */
  sim_icache_fetch(1185 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1866 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1867 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1868 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1869 */
} /* line 1869 */
  sim_icache_fetch(1190 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1871 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1872 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1873 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1874 */
  sim_icache_fetch(1194 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1876 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1877 */
  sim_icache_fetch(1196 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1879 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1880 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1881 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1882 */
} /* line 1882 */
  sim_icache_fetch(1201 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1884 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1885 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1886 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1887 */
  sim_icache_fetch(1205 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1889 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1890 */
  sim_icache_fetch(1207 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1892 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1893 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1894 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1895 */
} /* line 1895 */
  sim_icache_fetch(1212 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1897 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1898 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1899 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1900 */
  sim_icache_fetch(1216 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1902 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1903 */
  sim_icache_fetch(1218 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1905 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1906 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1907 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1908 */
} /* line 1908 */
  sim_icache_fetch(1223 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1910 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1911 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1912 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1913 */
  sim_icache_fetch(1227 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1915 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1916 */
  sim_icache_fetch(1229 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1918 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1919 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1920 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1921 */
} /* line 1921 */
  sim_icache_fetch(1234 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1923 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1924 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1925 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1926 */
  sim_icache_fetch(1238 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1928 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1929 */
  sim_icache_fetch(1240 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1931 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1932 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1933 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1934 */
} /* line 1934 */
  sim_icache_fetch(1245 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1936 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1937 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1938 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1939 */
  sim_icache_fetch(1249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1941 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1942 */
  sim_icache_fetch(1251 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1944 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1945 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1946 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1947 */
} /* line 1947 */
  sim_icache_fetch(1256 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1949 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1950 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1951 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1952 */
  sim_icache_fetch(1260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1954 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1955 */
  sim_icache_fetch(1262 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1957 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1958 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1959 */
} /* line 1959 */
  sim_icache_fetch(1266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1961 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1962 */
  sim_icache_fetch(1268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1964 */
  sim_icache_fetch(1269 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1966 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1967 */
} /* line 1967 */
  sim_icache_fetch(1271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1969 */
  sim_icache_fetch(1272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1972 */
  sim_icache_fetch(1273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L86X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L86X3;
} /* line 1974 */
l_L150X3: ;/* line 1977 */
__LABEL(l_L150X3);
  sim_icache_fetch(1274 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1978 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1979 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1980 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1981 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1982 */
l_L149X3: ;/* line 1986 */
__LABEL(l_L149X3);
  sim_icache_fetch(1279 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 1987 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1988 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 1989 */
l_L148X3: ;/* line 1992 */
__LABEL(l_L148X3);
  sim_icache_fetch(1282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 1993 */
} /* line 1993 */
l_L116X3: ;/* line 1996 */
__LABEL(l_L116X3);
  sim_icache_fetch(1283 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 1997 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1998 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1999 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2000 */
} /* line 2000 */
  sim_icache_fetch(1287 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2002 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2003 */
l_L147X3: ;/* line 2006 */
__LABEL(l_L147X3);
  sim_icache_fetch(1289 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2007 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2008 */
   __GOTO(l_L152X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L152X3;
} /* line 2009 */
l_L146X3: ;/* line 2012 */
__LABEL(l_L146X3);
  sim_icache_fetch(1292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2013 */
} /* line 2013 */
l_L114X3: ;/* line 2016 */
__LABEL(l_L114X3);
  sim_icache_fetch(1293 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2017 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2018 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2019 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2020 */
} /* line 2020 */
  sim_icache_fetch(1297 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2022 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2023 */
l_L145X3: ;/* line 2026 */
__LABEL(l_L145X3);
  sim_icache_fetch(1299 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2027 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2028 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2029 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2030 */
l_L144X3: ;/* line 2033 */
__LABEL(l_L144X3);
  sim_icache_fetch(1303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2034 */
} /* line 2034 */
l_L112X3: ;/* line 2037 */
__LABEL(l_L112X3);
  sim_icache_fetch(1304 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2038 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2039 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2040 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2041 */
} /* line 2041 */
  sim_icache_fetch(1308 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2043 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2044 */
l_L143X3: ;/* line 2047 */
__LABEL(l_L143X3);
  sim_icache_fetch(1310 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2048 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2049 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2050 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2051 */
l_L142X3: ;/* line 2054 */
__LABEL(l_L142X3);
  sim_icache_fetch(1314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2055 */
} /* line 2055 */
l_L110X3: ;/* line 2058 */
__LABEL(l_L110X3);
  sim_icache_fetch(1315 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2059 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2060 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2061 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2062 */
} /* line 2062 */
  sim_icache_fetch(1319 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2064 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2065 */
l_L141X3: ;/* line 2068 */
__LABEL(l_L141X3);
  sim_icache_fetch(1321 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2069 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2070 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2071 */
l_L140X3: ;/* line 2074 */
__LABEL(l_L140X3);
  sim_icache_fetch(1324 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2075 */
} /* line 2075 */
l_L108X3: ;/* line 2078 */
__LABEL(l_L108X3);
  sim_icache_fetch(1325 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2079 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2080 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2081 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2082 */
} /* line 2082 */
  sim_icache_fetch(1329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2084 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2085 */
l_L139X3: ;/* line 2088 */
__LABEL(l_L139X3);
  sim_icache_fetch(1331 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2089 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2090 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2091 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2092 */
l_L138X3: ;/* line 2095 */
__LABEL(l_L138X3);
  sim_icache_fetch(1335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2096 */
} /* line 2096 */
l_L106X3: ;/* line 2099 */
__LABEL(l_L106X3);
  sim_icache_fetch(1336 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2100 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2101 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2102 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2103 */
} /* line 2103 */
  sim_icache_fetch(1340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2105 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2106 */
l_L137X3: ;/* line 2109 */
__LABEL(l_L137X3);
  sim_icache_fetch(1342 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2110 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2111 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2112 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2113 */
l_L136X3: ;/* line 2116 */
__LABEL(l_L136X3);
  sim_icache_fetch(1346 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2117 */
} /* line 2117 */
l_L104X3: ;/* line 2120 */
__LABEL(l_L104X3);
  sim_icache_fetch(1347 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2121 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2122 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2123 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2124 */
} /* line 2124 */
  sim_icache_fetch(1351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2126 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2127 */
l_L135X3: ;/* line 2130 */
__LABEL(l_L135X3);
  sim_icache_fetch(1353 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2131 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2132 */
   __GOTO(l_L154X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L154X3;
} /* line 2133 */
l_L134X3: ;/* line 2136 */
__LABEL(l_L134X3);
  sim_icache_fetch(1356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2137 */
} /* line 2137 */
l_L102X3: ;/* line 2140 */
__LABEL(l_L102X3);
  sim_icache_fetch(1357 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2141 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2142 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2143 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2144 */
} /* line 2144 */
  sim_icache_fetch(1361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2146 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2147 */
l_L133X3: ;/* line 2150 */
__LABEL(l_L133X3);
  sim_icache_fetch(1363 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2151 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2152 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2153 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2154 */
l_L132X3: ;/* line 2157 */
__LABEL(l_L132X3);
  sim_icache_fetch(1367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2158 */
} /* line 2158 */
l_L100X3: ;/* line 2161 */
__LABEL(l_L100X3);
  sim_icache_fetch(1368 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2162 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2163 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2164 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2165 */
} /* line 2165 */
  sim_icache_fetch(1372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2167 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2168 */
l_L131X3: ;/* line 2171 */
__LABEL(l_L131X3);
  sim_icache_fetch(1374 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2172 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2173 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2174 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2175 */
l_L130X3: ;/* line 2178 */
__LABEL(l_L130X3);
  sim_icache_fetch(1378 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2179 */
} /* line 2179 */
l_L98X3: ;/* line 2182 */
__LABEL(l_L98X3);
  sim_icache_fetch(1379 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2183 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2184 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2185 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2186 */
} /* line 2186 */
  sim_icache_fetch(1383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2188 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2189 */
l_L129X3: ;/* line 2192 */
__LABEL(l_L129X3);
  sim_icache_fetch(1385 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2193 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2194 */
   __GOTO(l_L155X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L155X3;
} /* line 2195 */
l_L128X3: ;/* line 2198 */
__LABEL(l_L128X3);
  sim_icache_fetch(1388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2199 */
} /* line 2199 */
l_L96X3: ;/* line 2202 */
__LABEL(l_L96X3);
  sim_icache_fetch(1389 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2203 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2204 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2205 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2206 */
} /* line 2206 */
  sim_icache_fetch(1393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2208 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2209 */
l_L127X3: ;/* line 2212 */
__LABEL(l_L127X3);
  sim_icache_fetch(1395 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2213 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2214 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2215 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2216 */
l_L126X3: ;/* line 2219 */
__LABEL(l_L126X3);
  sim_icache_fetch(1399 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2220 */
} /* line 2220 */
l_L94X3: ;/* line 2223 */
__LABEL(l_L94X3);
  sim_icache_fetch(1400 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2224 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2225 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2226 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2227 */
} /* line 2227 */
  sim_icache_fetch(1404 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2229 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2230 */
l_L125X3: ;/* line 2233 */
__LABEL(l_L125X3);
  sim_icache_fetch(1406 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2234 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2235 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2236 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2237 */
l_L124X3: ;/* line 2240 */
__LABEL(l_L124X3);
  sim_icache_fetch(1410 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2241 */
} /* line 2241 */
l_L92X3: ;/* line 2244 */
__LABEL(l_L92X3);
  sim_icache_fetch(1411 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2245 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2246 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2247 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2248 */
} /* line 2248 */
  sim_icache_fetch(1415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2250 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2251 */
l_L123X3: ;/* line 2254 */
__LABEL(l_L123X3);
  sim_icache_fetch(1417 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2255 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2256 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2257 */
l_L122X3: ;/* line 2260 */
__LABEL(l_L122X3);
  sim_icache_fetch(1420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2261 */
} /* line 2261 */
l_L90X3: ;/* line 2264 */
__LABEL(l_L90X3);
  sim_icache_fetch(1421 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2265 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2266 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2267 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2268 */
} /* line 2268 */
  sim_icache_fetch(1425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2270 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2271 */
l_L121X3: ;/* line 2274 */
__LABEL(l_L121X3);
  sim_icache_fetch(1427 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2275 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2276 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2277 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2278 */
l_L120X3: ;/* line 2281 */
__LABEL(l_L120X3);
  sim_icache_fetch(1431 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2282 */
} /* line 2282 */
l_L88X3: ;/* line 2286 */
__LABEL(l_L88X3);
  sim_icache_fetch(1432 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2287 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2288 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2289 */
} /* line 2289 */
  sim_icache_fetch(1435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2291 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2292 */
l_L119X3: ;/* line 2295 */
__LABEL(l_L119X3);
  sim_icache_fetch(1437 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2296 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2297 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2298 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2299 */
l_L118X3: ;/* line 2302 */
__LABEL(l_L118X3);
  sim_icache_fetch(1441 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2303 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2304 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2305 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2306 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2307 */
l_L117X3: ;/* line 2311 */
__LABEL(l_L117X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2312 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2313 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2314 */
l_L115X3: ;/* line 2317 */
__LABEL(l_L115X3);
  sim_icache_fetch(1449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2318 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2319 */
} /* line 2319 */
l_L152X3: ;/* line 2321 */
__LABEL(l_L152X3);
  sim_icache_fetch(1451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2322 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2323 */
l_L113X3: ;/* line 2326 */
__LABEL(l_L113X3);
  sim_icache_fetch(1453 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2327 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2328 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2329 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2330 */
l_L111X3: ;/* line 2333 */
__LABEL(l_L111X3);
  sim_icache_fetch(1457 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2334 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2335 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2336 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2337 */
l_L109X3: ;/* line 2340 */
__LABEL(l_L109X3);
  sim_icache_fetch(1461 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2341 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2342 */
} /* line 2342 */
l_L153X3: ;/* line 2344 */
__LABEL(l_L153X3);
  sim_icache_fetch(1463 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2345 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2346 */
l_L107X3: ;/* line 2349 */
__LABEL(l_L107X3);
  sim_icache_fetch(1465 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2350 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2351 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2352 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2353 */
l_L105X3: ;/* line 2356 */
__LABEL(l_L105X3);
  sim_icache_fetch(1469 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2357 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2358 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2359 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2360 */
l_L103X3: ;/* line 2363 */
__LABEL(l_L103X3);
  sim_icache_fetch(1473 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2364 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2365 */
} /* line 2365 */
l_L154X3: ;/* line 2367 */
__LABEL(l_L154X3);
  sim_icache_fetch(1475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2368 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2369 */
l_L101X3: ;/* line 2372 */
__LABEL(l_L101X3);
  sim_icache_fetch(1477 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2373 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2374 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2375 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2376 */
l_L99X3: ;/* line 2379 */
__LABEL(l_L99X3);
  sim_icache_fetch(1481 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2380 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2381 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2382 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2383 */
l_L97X3: ;/* line 2386 */
__LABEL(l_L97X3);
  sim_icache_fetch(1485 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2387 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2388 */
} /* line 2388 */
l_L155X3: ;/* line 2390 */
__LABEL(l_L155X3);
  sim_icache_fetch(1487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2391 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2392 */
l_L95X3: ;/* line 2395 */
__LABEL(l_L95X3);
  sim_icache_fetch(1489 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2396 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2397 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2398 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2399 */
l_L93X3: ;/* line 2402 */
__LABEL(l_L93X3);
  sim_icache_fetch(1493 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2403 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2404 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2405 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2406 */
l_L91X3: ;/* line 2409 */
__LABEL(l_L91X3);
  sim_icache_fetch(1497 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2410 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2411 */
} /* line 2411 */
l_L156X3: ;/* line 2413 */
__LABEL(l_L156X3);
  sim_icache_fetch(1499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2414 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2415 */
l_L89X3: ;/* line 2418 */
__LABEL(l_L89X3);
  sim_icache_fetch(1501 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2419 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2420 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2421 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2422 */
l_L87X3: ;/* line 2426 */
__LABEL(l_L87X3);
  sim_icache_fetch(1505 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2427 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2428 */
} /* line 2428 */
l_L151X3: ;/* line 2430 */
__LABEL(l_L151X3);
  sim_icache_fetch(1507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2431 */
} /* line 2431 */
  sim_icache_fetch(1509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2433 */
} /* line 2433 */
  sim_icache_fetch(1510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L77X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L77X3;
} /* line 2435 */
l_L80X3: ;/* line 2438 */
__LABEL(l_L80X3);
		 /* line 2438 */
  sim_icache_fetch(1511 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2441 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (325 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2441 */
l_lr_194: ;/* line 2441 */
__LABEL(l_lr_194);
  sim_icache_fetch(1514 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2443 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2444 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2445 */
   __ADD_CYCLES(1);
} /* line 2445 */
  sim_icache_fetch(1518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2447 */
} /* line 2447 */
		 /* line 2448 */
  sim_icache_fetch(1519 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2450 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (325 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2451 */
l_lr_196: ;/* line 2451 */
__LABEL(l_lr_196);
  sim_icache_fetch(1523 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2453 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2454 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2455 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2456 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2457 */
} /* line 2457 */
  sim_icache_fetch(1532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 2459 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2460 */
} /* line 2460 */
  sim_icache_fetch(1534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2462 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2463 */
} /* line 2463 */
  sim_icache_fetch(1536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L157X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2465 */
l_L158X3: ;/* line 2467 */
__LABEL(l_L158X3);
  sim_icache_fetch(1537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2468 */
  sim_icache_fetch(1538 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2470 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2471 */
} /* line 2471 */
l_L160X3: ;/* line 2473 */
__LABEL(l_L160X3);
  sim_icache_fetch(1541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2475 */
l_L159X3: ;/* line 2478 */
__LABEL(l_L159X3);
  sim_icache_fetch(1542 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2479 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2480 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2481 */
l_L157X3: ;/* line 2484 */
__LABEL(l_L157X3);
  sim_icache_fetch(1545 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2485 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2486 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2487 */
   __ADD_CYCLES(1);
} /* line 2487 */
		 /* line 2488 */
  sim_icache_fetch(1550 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2490 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (325 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2491 */
l_lr_202: ;/* line 2491 */
__LABEL(l_lr_202);
  sim_icache_fetch(1553 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2493 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2494 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2495 */
   __MOV(reg_r0_3, 0); /* line 2496 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2497 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2498 */
   __ADD_CYCLES(1);
} /* line 2498 */
  sim_icache_fetch(1561 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2500 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2501 */
l_L78X3: ;/* line 2504 */
__LABEL(l_L78X3);
  sim_icache_fetch(1563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2505 */
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 2506 */
l_L74X3: ;/* line 2509 */
__LABEL(l_L74X3);
  sim_icache_fetch(1565 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2510 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2511 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2512 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2513 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2515 */
} /* line 2515 */
  sim_icache_fetch(1571 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2517 */
l_L73X3: ;/* line 2520 */
__LABEL(l_L73X3);
  sim_icache_fetch(1572 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2521 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2522 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2523 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2524 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2526 */
} /* line 2526 */
  sim_icache_fetch(1578 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2528 */
l_L72X3: ;/* line 2531 */
__LABEL(l_L72X3);
  sim_icache_fetch(1579 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2532 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2533 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2534 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2535 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2537 */
} /* line 2537 */
  sim_icache_fetch(1585 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2539 */
l_L71X3: ;/* line 2542 */
__LABEL(l_L71X3);
  sim_icache_fetch(1586 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2543 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2544 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2545 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2546 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2548 */
} /* line 2548 */
  sim_icache_fetch(1592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2550 */
l_L70X3: ;/* line 2553 */
__LABEL(l_L70X3);
  sim_icache_fetch(1593 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2554 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2555 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2556 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2557 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2559 */
} /* line 2559 */
  sim_icache_fetch(1599 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2561 */
l_L69X3: ;/* line 2564 */
__LABEL(l_L69X3);
  sim_icache_fetch(1600 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2565 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2566 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2567 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2568 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2570 */
} /* line 2570 */
  sim_icache_fetch(1606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2572 */
l_L68X3: ;/* line 2575 */
__LABEL(l_L68X3);
  sim_icache_fetch(1607 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2576 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2577 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2578 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2579 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2581 */
} /* line 2581 */
  sim_icache_fetch(1613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2583 */
l_L67X3: ;/* line 2586 */
__LABEL(l_L67X3);
  sim_icache_fetch(1614 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2587 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2588 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2589 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2590 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2592 */
} /* line 2592 */
  sim_icache_fetch(1620 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2594 */
l_L66X3: ;/* line 2597 */
__LABEL(l_L66X3);
  sim_icache_fetch(1621 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2598 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2599 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2600 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2601 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2603 */
} /* line 2603 */
  sim_icache_fetch(1627 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2605 */
l_L65X3: ;/* line 2608 */
__LABEL(l_L65X3);
  sim_icache_fetch(1628 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2609 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2610 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2611 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2612 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2614 */
} /* line 2614 */
  sim_icache_fetch(1634 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2616 */
l_L64X3: ;/* line 2619 */
__LABEL(l_L64X3);
  sim_icache_fetch(1635 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2620 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2621 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2622 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2623 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2625 */
} /* line 2625 */
  sim_icache_fetch(1641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2627 */
l_L63X3: ;/* line 2630 */
__LABEL(l_L63X3);
  sim_icache_fetch(1642 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2631 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2632 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2633 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2634 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2636 */
} /* line 2636 */
  sim_icache_fetch(1648 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2638 */
l_L62X3: ;/* line 2641 */
__LABEL(l_L62X3);
  sim_icache_fetch(1649 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2642 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2643 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2644 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2645 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2647 */
} /* line 2647 */
  sim_icache_fetch(1655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2649 */
l_L61X3: ;/* line 2652 */
__LABEL(l_L61X3);
  sim_icache_fetch(1656 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2653 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2654 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2655 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2656 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2658 */
} /* line 2658 */
  sim_icache_fetch(1662 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2660 */
l_L60X3: ;/* line 2664 */
__LABEL(l_L60X3);
  sim_icache_fetch(1663 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2665 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2666 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2667 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2668 */
} /* line 2668 */
l_L76X3: ;/* line 2670 */
__LABEL(l_L76X3);
  sim_icache_fetch(1668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2671 */
} /* line 2671 */
		 /* line 2672 */
  sim_icache_fetch(1669 + t_thisfile.offset, 5);
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
   reg_l0_0 = (325 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2677 */
l_lr_221: ;/* line 2677 */
__LABEL(l_lr_221);
  sim_icache_fetch(1674 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2679 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2680 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2681 */
} /* line 2681 */
  sim_icache_fetch(1677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L77X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L77X3;
} /* line 2683 */
l_L57X3: ;/* line 2686 */
__LABEL(l_L57X3);
  sim_icache_fetch(1678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2687 */
   __GOTO(l_L58X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L58X3;
} /* line 2688 */
l_L55X3: ;/* line 2691 */
__LABEL(l_L55X3);
  sim_icache_fetch(1680 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2692 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2693 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2694 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2695 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2696 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2697 */
   __ADD_CYCLES(1);
} /* line 2697 */
  sim_icache_fetch(1688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_11, (unsigned int) 1); /* line 2699 */
} /* line 2699 */
  sim_icache_fetch(1689 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_16); /* line 2701 */
} /* line 2701 */
  sim_icache_fetch(1691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2703 */
} /* line 2703 */
  sim_icache_fetch(1692 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2705 */
   __LDBU(reg_r0_15, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2706 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2707 */
   __ADD_CYCLES(1);
} /* line 2707 */
  sim_icache_fetch(1697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_11, (unsigned int) 1); /* line 2709 */
} /* line 2709 */
  sim_icache_fetch(1698 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_16); /* line 2711 */
} /* line 2711 */
  sim_icache_fetch(1700 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2713 */
} /* line 2713 */
  sim_icache_fetch(1701 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2715 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2716 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2717 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2718 */
   __ADD_CYCLES(1);
} /* line 2718 */
  sim_icache_fetch(1708 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_17, reg_r0_11, (unsigned int) 1); /* line 2720 */
   __OR(reg_r0_15, reg_r0_15, reg_r0_16); /* line 2721 */
} /* line 2721 */
  sim_icache_fetch(1710 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_17); /* line 2723 */
} /* line 2723 */
  sim_icache_fetch(1712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2725 */
} /* line 2725 */
  sim_icache_fetch(1713 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2727 */
   __LDW(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2728 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2729 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2730 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2731 */
   __ADD_CYCLES(1);
} /* line 2731 */
  sim_icache_fetch(1722 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 2733 */
   __GOTO(l_L56X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L56X3;
} /* line 2734 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 207: goto l_L56X3;
    case 208: goto l_L58X3;
    case 209: goto l_L59X3;
    case 210: goto l_L75X3;
    case 211: goto l_L77X3;
    case 212: goto l_L79X3;
    case 213: goto l_L81X3;
    case 214: goto l_L83X3;
    case 216: goto l_lr_115;
    case 217: goto l_L84X3;
    case 219: goto l_lr_118;
    case 220: goto l_L85X3;
    case 221: goto l_L82X3;
    case 222: goto l_L86X3;
    case 223: goto l_L150X3;
    case 224: goto l_L149X3;
    case 225: goto l_L148X3;
    case 226: goto l_L116X3;
    case 227: goto l_L147X3;
    case 228: goto l_L146X3;
    case 229: goto l_L114X3;
    case 230: goto l_L145X3;
    case 231: goto l_L144X3;
    case 232: goto l_L112X3;
    case 233: goto l_L143X3;
    case 234: goto l_L142X3;
    case 235: goto l_L110X3;
    case 236: goto l_L141X3;
    case 237: goto l_L140X3;
    case 238: goto l_L108X3;
    case 239: goto l_L139X3;
    case 240: goto l_L138X3;
    case 241: goto l_L106X3;
    case 242: goto l_L137X3;
    case 243: goto l_L136X3;
    case 244: goto l_L104X3;
    case 245: goto l_L135X3;
    case 246: goto l_L134X3;
    case 247: goto l_L102X3;
    case 248: goto l_L133X3;
    case 249: goto l_L132X3;
    case 250: goto l_L100X3;
    case 251: goto l_L131X3;
    case 252: goto l_L130X3;
    case 253: goto l_L98X3;
    case 254: goto l_L129X3;
    case 255: goto l_L128X3;
    case 256: goto l_L96X3;
    case 257: goto l_L127X3;
    case 258: goto l_L126X3;
    case 259: goto l_L94X3;
    case 260: goto l_L125X3;
    case 261: goto l_L124X3;
    case 262: goto l_L92X3;
    case 263: goto l_L123X3;
    case 264: goto l_L122X3;
    case 265: goto l_L90X3;
    case 266: goto l_L121X3;
    case 267: goto l_L120X3;
    case 268: goto l_L88X3;
    case 269: goto l_L119X3;
    case 270: goto l_L118X3;
    case 271: goto l_L117X3;
    case 272: goto l_L115X3;
    case 273: goto l_L152X3;
    case 274: goto l_L113X3;
    case 275: goto l_L111X3;
    case 276: goto l_L109X3;
    case 277: goto l_L153X3;
    case 278: goto l_L107X3;
    case 279: goto l_L105X3;
    case 280: goto l_L103X3;
    case 281: goto l_L154X3;
    case 282: goto l_L101X3;
    case 283: goto l_L99X3;
    case 284: goto l_L97X3;
    case 285: goto l_L155X3;
    case 286: goto l_L95X3;
    case 287: goto l_L93X3;
    case 288: goto l_L91X3;
    case 289: goto l_L156X3;
    case 290: goto l_L89X3;
    case 291: goto l_L87X3;
    case 292: goto l_L151X3;
    case 293: goto l_L80X3;
    case 295: goto l_lr_194;
    case 297: goto l_lr_196;
    case 298: goto l_L158X3;
    case 299: goto l_L160X3;
    case 300: goto l_L159X3;
    case 301: goto l_L157X3;
    case 303: goto l_lr_202;
    case 304: goto l_L78X3;
    case 305: goto l_L74X3;
    case 306: goto l_L73X3;
    case 307: goto l_L72X3;
    case 308: goto l_L71X3;
    case 309: goto l_L70X3;
    case 310: goto l_L69X3;
    case 311: goto l_L68X3;
    case 312: goto l_L67X3;
    case 313: goto l_L66X3;
    case 314: goto l_L65X3;
    case 315: goto l_L64X3;
    case 316: goto l_L63X3;
    case 317: goto l_L62X3;
    case 318: goto l_L61X3;
    case 319: goto l_L60X3;
    case 320: goto l_L76X3;
    case 322: goto l_lr_221;
    case 323: goto l_L57X3;
    case 324: goto l_L55X3;
    case 325:
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
  reg_l0_0 = (357 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1724 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 2753 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2754 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2755 */
} /* line 2755 */
  sim_icache_fetch(1729 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L161X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2757 */
  sim_icache_fetch(1730 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2759 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2760 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2761 */
} /* line 2761 */
  sim_icache_fetch(1733 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_10102Xbuf),0,1)); /* line 2763 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2764 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2765 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2766 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2767 */
} /* line 2767 */
  sim_icache_fetch(1741 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_10102Xbuf); /* line 2769 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_10102Xbuf + (unsigned int) 1)); /* line 2770 */
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2771 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2772 */
} /* line 2772 */
  sim_icache_fetch(1747 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2774 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2775 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2776 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2777 */
} /* line 2777 */
  sim_icache_fetch(1751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2779 */
} /* line 2779 */
  sim_icache_fetch(1752 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_10102Xbuf),0,1), reg_r0_2); /* line 2781 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L162X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2782 */
  sim_icache_fetch(1755 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2784 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2785 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2786 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2787 */
} /* line 2787 */
l_L162X3: ;/* line 2789 */
__LABEL(l_L162X3);
  sim_icache_fetch(1759 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2790 */
   __MOV(reg_r0_3, (unsigned int) compress_10102Xbuf); /* line 2791 */
} /* line 2791 */
  sim_icache_fetch(1762 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L163X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2793 */
  sim_icache_fetch(1763 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2795 */
} /* line 2795 */
l_L163X3: ;/* line 2797 */
__LABEL(l_L163X3);
  sim_icache_fetch(1764 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 2798 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2799 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2800 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2801 */
   __ADD_CYCLES(1);
} /* line 2801 */
  sim_icache_fetch(1771 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2803 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2804 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2805 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2806 */
} /* line 2806 */
  sim_icache_fetch(1775 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_10102Xoffset,0,4), reg_r0_2); /* line 2808 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2809 */
} /* line 2809 */
  sim_icache_fetch(1778 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L164X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2811 */
  sim_icache_fetch(1779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2813 */
} /* line 2813 */
l_L165X3: ;/* line 2816 */
__LABEL(l_L165X3);
  sim_icache_fetch(1781 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2817 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2818 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2819 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2820 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2821 */
} /* line 2821 */
  sim_icache_fetch(1787 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2823 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2824 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2825 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2826 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2827 */
} /* line 2827 */
  sim_icache_fetch(1792 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2829 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -16); /* line 2830 */
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) 16); /* line 2831 */
} /* line 2831 */
  sim_icache_fetch(1795 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2833 */
} /* line 2833 */
  sim_icache_fetch(1797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2835 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2836 */
  sim_icache_fetch(1799 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2838 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2839 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2840 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2841 */
   __ADD_CYCLES(1);
} /* line 2841 */
  sim_icache_fetch(1804 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2843 */
} /* line 2843 */
  sim_icache_fetch(1805 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2845 */
} /* line 2845 */
  sim_icache_fetch(1807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2847 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2848 */
  sim_icache_fetch(1809 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2850 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2851 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2852 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2853 */
   __ADD_CYCLES(1);
} /* line 2853 */
  sim_icache_fetch(1814 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2855 */
} /* line 2855 */
  sim_icache_fetch(1815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2857 */
} /* line 2857 */
  sim_icache_fetch(1817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2859 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2860 */
  sim_icache_fetch(1819 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2862 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2863 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2864 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2865 */
   __ADD_CYCLES(1);
} /* line 2865 */
  sim_icache_fetch(1824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2867 */
} /* line 2867 */
  sim_icache_fetch(1825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2869 */
} /* line 2869 */
  sim_icache_fetch(1827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2871 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2872 */
  sim_icache_fetch(1829 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2874 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2875 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2876 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2877 */
   __ADD_CYCLES(1);
} /* line 2877 */
  sim_icache_fetch(1834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2879 */
} /* line 2879 */
  sim_icache_fetch(1835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2881 */
} /* line 2881 */
  sim_icache_fetch(1837 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2883 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2884 */
  sim_icache_fetch(1839 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2886 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2887 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2888 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2889 */
   __ADD_CYCLES(1);
} /* line 2889 */
  sim_icache_fetch(1844 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2891 */
} /* line 2891 */
  sim_icache_fetch(1845 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2893 */
} /* line 2893 */
  sim_icache_fetch(1847 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2895 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2896 */
  sim_icache_fetch(1849 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2898 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2899 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2900 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2901 */
   __ADD_CYCLES(1);
} /* line 2901 */
  sim_icache_fetch(1854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2903 */
} /* line 2903 */
  sim_icache_fetch(1855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2905 */
} /* line 2905 */
  sim_icache_fetch(1857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2907 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2908 */
  sim_icache_fetch(1859 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2910 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2911 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2912 */
   __ADD(reg_r0_5, reg_r0_8, (unsigned int) -16); /* line 2913 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2914 */
   __ADD_CYCLES(1);
} /* line 2914 */
  sim_icache_fetch(1865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2916 */
} /* line 2916 */
  sim_icache_fetch(1866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2918 */
} /* line 2918 */
  sim_icache_fetch(1868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2920 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2921 */
  sim_icache_fetch(1870 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2923 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2924 */
   __CMPEQ(reg_b0_7, reg_r0_8, 0); /* line 2925 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2926 */
   __ADD_CYCLES(1);
} /* line 2926 */
  sim_icache_fetch(1875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2928 */
} /* line 2928 */
  sim_icache_fetch(1876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2930 */
} /* line 2930 */
  sim_icache_fetch(1878 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2932 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2933 */
  sim_icache_fetch(1880 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2935 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2936 */
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 2937 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2938 */
   __ADD_CYCLES(1);
} /* line 2938 */
  sim_icache_fetch(1885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2940 */
} /* line 2940 */
  sim_icache_fetch(1886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2942 */
} /* line 2942 */
  sim_icache_fetch(1888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2944 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2945 */
  sim_icache_fetch(1890 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 2947 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2948 */
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 2); /* line 2949 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2950 */
   __ADD_CYCLES(1);
} /* line 2950 */
  sim_icache_fetch(1895 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2952 */
} /* line 2952 */
  sim_icache_fetch(1896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2954 */
} /* line 2954 */
  sim_icache_fetch(1898 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2956 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2957 */
  sim_icache_fetch(1900 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 2959 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2960 */
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 3); /* line 2961 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2962 */
   __ADD_CYCLES(1);
} /* line 2962 */
  sim_icache_fetch(1905 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2964 */
} /* line 2964 */
  sim_icache_fetch(1906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2966 */
} /* line 2966 */
  sim_icache_fetch(1908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2968 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2969 */
  sim_icache_fetch(1910 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 2971 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2972 */
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 4); /* line 2973 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2974 */
   __ADD_CYCLES(1);
} /* line 2974 */
  sim_icache_fetch(1915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2976 */
} /* line 2976 */
  sim_icache_fetch(1916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2978 */
} /* line 2978 */
  sim_icache_fetch(1918 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2980 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2981 */
  sim_icache_fetch(1920 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 2983 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2984 */
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 5); /* line 2985 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2986 */
   __ADD_CYCLES(1);
} /* line 2986 */
  sim_icache_fetch(1925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2988 */
} /* line 2988 */
  sim_icache_fetch(1926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2990 */
} /* line 2990 */
  sim_icache_fetch(1928 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2992 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2993 */
  sim_icache_fetch(1930 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 2995 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2996 */
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 6); /* line 2997 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2998 */
   __ADD_CYCLES(1);
} /* line 2998 */
  sim_icache_fetch(1935 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3000 */
} /* line 3000 */
  sim_icache_fetch(1936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3002 */
} /* line 3002 */
  sim_icache_fetch(1938 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3004 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3005 */
  sim_icache_fetch(1940 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 3007 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3008 */
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 7); /* line 3009 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3010 */
   __ADD_CYCLES(1);
} /* line 3010 */
  sim_icache_fetch(1945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3012 */
} /* line 3012 */
  sim_icache_fetch(1946 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3014 */
} /* line 3014 */
  sim_icache_fetch(1948 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3016 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3017 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3018 */
  sim_icache_fetch(1951 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_7,0,1)); /* line 3020 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3021 */
   __CMPEQ(reg_b0_7, reg_r0_8, (unsigned int) 8); /* line 3022 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) 16); /* line 3023 */
   __MFB(reg_r0_6, t__i32_0); /* line 3024 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3025 */
   __ADD_CYCLES(1);
} /* line 3025 */
  sim_icache_fetch(1958 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3027 */
} /* line 3027 */
  sim_icache_fetch(1959 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3029 */
} /* line 3029 */
  sim_icache_fetch(1961 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3031 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3032 */
  sim_icache_fetch(1963 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 1),0,1)); /* line 3034 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3035 */
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 9); /* line 3036 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3037 */
   __ADD_CYCLES(1);
} /* line 3037 */
  sim_icache_fetch(1968 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3039 */
} /* line 3039 */
  sim_icache_fetch(1969 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3041 */
} /* line 3041 */
  sim_icache_fetch(1971 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3043 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3044 */
  sim_icache_fetch(1973 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,1)); /* line 3046 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3047 */
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 10); /* line 3048 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3049 */
   __ADD_CYCLES(1);
} /* line 3049 */
  sim_icache_fetch(1978 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3051 */
} /* line 3051 */
  sim_icache_fetch(1979 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3053 */
} /* line 3053 */
  sim_icache_fetch(1981 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3055 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3056 */
  sim_icache_fetch(1983 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 3),0,1)); /* line 3058 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3059 */
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 11); /* line 3060 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3061 */
   __ADD_CYCLES(1);
} /* line 3061 */
  sim_icache_fetch(1988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3063 */
} /* line 3063 */
  sim_icache_fetch(1989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3065 */
} /* line 3065 */
  sim_icache_fetch(1991 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3067 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3068 */
  sim_icache_fetch(1993 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,1)); /* line 3070 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3071 */
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 12); /* line 3072 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3073 */
   __ADD_CYCLES(1);
} /* line 3073 */
  sim_icache_fetch(1998 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3075 */
} /* line 3075 */
  sim_icache_fetch(1999 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3077 */
} /* line 3077 */
  sim_icache_fetch(2001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3079 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3080 */
  sim_icache_fetch(2003 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 5),0,1)); /* line 3082 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3083 */
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 13); /* line 3084 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3085 */
   __ADD_CYCLES(1);
} /* line 3085 */
  sim_icache_fetch(2008 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3087 */
} /* line 3087 */
  sim_icache_fetch(2009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3089 */
} /* line 3089 */
  sim_icache_fetch(2011 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3091 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3092 */
  sim_icache_fetch(2013 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 6),0,1)); /* line 3094 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3095 */
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 14); /* line 3096 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3097 */
   __ADD_CYCLES(1);
} /* line 3097 */
  sim_icache_fetch(2018 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3099 */
} /* line 3099 */
  sim_icache_fetch(2019 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3101 */
} /* line 3101 */
  sim_icache_fetch(2021 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3103 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3104 */
  sim_icache_fetch(2023 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 7),0,1)); /* line 3106 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3107 */
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 15); /* line 3108 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3109 */
   __ADD_CYCLES(1);
} /* line 3109 */
  sim_icache_fetch(2028 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3111 */
} /* line 3111 */
  sim_icache_fetch(2029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3113 */
} /* line 3113 */
  sim_icache_fetch(2031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3115 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3116 */
  sim_icache_fetch(2033 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 8),0,1)); /* line 3118 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3119 */
   __MTB(reg_b0_7, reg_r0_6); /* line 3120 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3121 */
   __ADD_CYCLES(1);
} /* line 3121 */
  sim_icache_fetch(2038 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3123 */
} /* line 3123 */
  sim_icache_fetch(2039 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3125 */
} /* line 3125 */
  sim_icache_fetch(2041 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3127 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3128 */
  sim_icache_fetch(2043 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 9),0,1)); /* line 3130 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3131 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3132 */
   __ADD_CYCLES(1);
} /* line 3132 */
  sim_icache_fetch(2047 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3134 */
} /* line 3134 */
  sim_icache_fetch(2048 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3136 */
} /* line 3136 */
  sim_icache_fetch(2050 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3138 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3139 */
  sim_icache_fetch(2052 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 10),0,1)); /* line 3141 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3142 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3143 */
   __ADD_CYCLES(1);
} /* line 3143 */
  sim_icache_fetch(2056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3145 */
} /* line 3145 */
  sim_icache_fetch(2057 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3147 */
} /* line 3147 */
  sim_icache_fetch(2059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3149 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3150 */
  sim_icache_fetch(2061 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 11),0,1)); /* line 3152 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3153 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3154 */
   __ADD_CYCLES(1);
} /* line 3154 */
  sim_icache_fetch(2065 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3156 */
} /* line 3156 */
  sim_icache_fetch(2066 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3158 */
} /* line 3158 */
  sim_icache_fetch(2068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3160 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3161 */
  sim_icache_fetch(2070 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,1)); /* line 3163 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3164 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3165 */
   __ADD_CYCLES(1);
} /* line 3165 */
  sim_icache_fetch(2074 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3167 */
} /* line 3167 */
  sim_icache_fetch(2075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3169 */
} /* line 3169 */
  sim_icache_fetch(2077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3171 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3172 */
  sim_icache_fetch(2079 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 13),0,1)); /* line 3174 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3175 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3176 */
   __ADD_CYCLES(1);
} /* line 3176 */
  sim_icache_fetch(2083 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3178 */
} /* line 3178 */
  sim_icache_fetch(2084 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3180 */
} /* line 3180 */
  sim_icache_fetch(2086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3182 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3183 */
  sim_icache_fetch(2088 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 14),0,1)); /* line 3185 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3186 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3187 */
   __ADD_CYCLES(1);
} /* line 3187 */
  sim_icache_fetch(2092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3189 */
} /* line 3189 */
  sim_icache_fetch(2093 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3191 */
} /* line 3191 */
  sim_icache_fetch(2095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3193 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3194 */
  sim_icache_fetch(2097 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_7, mem_trace_ld((reg_r0_7 + (unsigned int) 15),0,1)); /* line 3196 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3197 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3198 */
   __ADD_CYCLES(1);
} /* line 3198 */
  sim_icache_fetch(2101 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3200 */
} /* line 3200 */
  sim_icache_fetch(2102 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3202 */
} /* line 3202 */
  sim_icache_fetch(2104 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 3204 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3206 */
  sim_icache_fetch(2106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L165X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L165X3;
} /* line 3208 */
l_L166X3: ;/* line 3211 */
__LABEL(l_L166X3);
  sim_icache_fetch(2107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_10102Xoffset,0,4), 0); /* line 3212 */
} /* line 3212 */
l_L164X3: ;/* line 3215 */
__LABEL(l_L164X3);
  sim_icache_fetch(2109 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3216 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3217 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3218 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3219 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3220 */
} /* line 3220 */
  sim_icache_fetch(2118 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3222 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3223 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3224 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3225 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3226 */
} /* line 3226 */
  sim_icache_fetch(2123 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3228 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3229 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3230 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3231 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3232 */
} /* line 3232 */
  sim_icache_fetch(2128 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3234 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3235 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3236 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3237 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3238 */
} /* line 3238 */
  sim_icache_fetch(2133 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3240 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3241 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3242 */
   __MOV(reg_r0_5, (unsigned int) compress_10102Xbuf); /* line 3243 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3244 */
  sim_icache_fetch(2139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 3246 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3247 */
l_L169X3: ;/* line 3250 */
__LABEL(l_L169X3);
  sim_icache_fetch(2141 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3251 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3252 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3253 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3254 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3255 */
} /* line 3255 */
  sim_icache_fetch(2148 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3257 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3258 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3259 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3260 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3261 */
} /* line 3261 */
  sim_icache_fetch(2153 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3263 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3264 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3265 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3266 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3267 */
} /* line 3267 */
  sim_icache_fetch(2158 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3269 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3270 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3271 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3272 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L170X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3273 */
  sim_icache_fetch(2163 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3275 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3276 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3277 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3278 */
} /* line 3278 */
  sim_icache_fetch(2168 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3280 */
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 16); /* line 3281 */
} /* line 3281 */
  sim_icache_fetch(2170 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3283 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3284 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3285 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3286 */
   __ADD_CYCLES(1);
} /* line 3286 */
  sim_icache_fetch(2176 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_4); /* line 3288 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3289 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3290 */
} /* line 3290 */
  sim_icache_fetch(2179 + t_thisfile.offset, 1);
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
} /* line 3292 */
  sim_icache_fetch(2180 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3294 */
} /* line 3294 */
  sim_icache_fetch(2182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3296 */
} /* line 3296 */
  sim_icache_fetch(2183 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3298 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3299 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3300 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3301 */
   __ADD_CYCLES(1);
} /* line 3301 */
  sim_icache_fetch(2189 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_4); /* line 3303 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3304 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3305 */
} /* line 3305 */
  sim_icache_fetch(2192 + t_thisfile.offset, 1);
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
} /* line 3307 */
  sim_icache_fetch(2193 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3309 */
} /* line 3309 */
  sim_icache_fetch(2195 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3311 */
} /* line 3311 */
  sim_icache_fetch(2196 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3313 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3314 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3315 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3316 */
   __ADD_CYCLES(1);
} /* line 3316 */
  sim_icache_fetch(2202 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_4); /* line 3318 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3319 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3320 */
} /* line 3320 */
  sim_icache_fetch(2205 + t_thisfile.offset, 1);
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
} /* line 3322 */
  sim_icache_fetch(2206 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3324 */
} /* line 3324 */
  sim_icache_fetch(2208 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3326 */
} /* line 3326 */
  sim_icache_fetch(2209 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3328 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3329 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3330 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3331 */
   __ADD_CYCLES(1);
} /* line 3331 */
  sim_icache_fetch(2215 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_4); /* line 3333 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3334 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3335 */
} /* line 3335 */
  sim_icache_fetch(2218 + t_thisfile.offset, 1);
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
} /* line 3337 */
  sim_icache_fetch(2219 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3339 */
} /* line 3339 */
  sim_icache_fetch(2221 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3341 */
} /* line 3341 */
  sim_icache_fetch(2222 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3343 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3344 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3345 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3346 */
   __ADD_CYCLES(1);
} /* line 3346 */
  sim_icache_fetch(2228 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_4); /* line 3348 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3349 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3350 */
} /* line 3350 */
  sim_icache_fetch(2231 + t_thisfile.offset, 1);
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
} /* line 3352 */
  sim_icache_fetch(2232 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3354 */
} /* line 3354 */
  sim_icache_fetch(2234 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3356 */
} /* line 3356 */
  sim_icache_fetch(2235 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3358 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3359 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3360 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3361 */
   __ADD_CYCLES(1);
} /* line 3361 */
  sim_icache_fetch(2241 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_4); /* line 3363 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3364 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3365 */
} /* line 3365 */
  sim_icache_fetch(2244 + t_thisfile.offset, 1);
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
} /* line 3367 */
  sim_icache_fetch(2245 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3369 */
} /* line 3369 */
  sim_icache_fetch(2247 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3371 */
} /* line 3371 */
  sim_icache_fetch(2248 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3373 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3374 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3375 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3376 */
   __ADD_CYCLES(1);
} /* line 3376 */
  sim_icache_fetch(2254 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_4); /* line 3378 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3379 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3380 */
} /* line 3380 */
  sim_icache_fetch(2257 + t_thisfile.offset, 1);
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
} /* line 3382 */
  sim_icache_fetch(2258 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3384 */
} /* line 3384 */
  sim_icache_fetch(2260 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3386 */
} /* line 3386 */
  sim_icache_fetch(2261 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3388 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3389 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3390 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3391 */
   __ADD_CYCLES(1);
} /* line 3391 */
  sim_icache_fetch(2267 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_4); /* line 3393 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3394 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3395 */
} /* line 3395 */
  sim_icache_fetch(2270 + t_thisfile.offset, 1);
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
} /* line 3397 */
  sim_icache_fetch(2271 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3399 */
} /* line 3399 */
  sim_icache_fetch(2273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3401 */
} /* line 3401 */
  sim_icache_fetch(2274 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3403 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3404 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3405 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3406 */
   __ADD_CYCLES(1);
} /* line 3406 */
  sim_icache_fetch(2280 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_4); /* line 3408 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3409 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3410 */
} /* line 3410 */
  sim_icache_fetch(2283 + t_thisfile.offset, 1);
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
} /* line 3412 */
  sim_icache_fetch(2284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3414 */
} /* line 3414 */
  sim_icache_fetch(2286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3416 */
} /* line 3416 */
  sim_icache_fetch(2287 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3418 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3419 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3420 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3421 */
   __ADD_CYCLES(1);
} /* line 3421 */
  sim_icache_fetch(2293 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_4); /* line 3423 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3424 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3425 */
} /* line 3425 */
  sim_icache_fetch(2296 + t_thisfile.offset, 1);
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
} /* line 3427 */
  sim_icache_fetch(2297 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3429 */
} /* line 3429 */
  sim_icache_fetch(2299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3431 */
} /* line 3431 */
  sim_icache_fetch(2300 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3433 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3434 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3435 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3436 */
   __ADD_CYCLES(1);
} /* line 3436 */
  sim_icache_fetch(2306 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_4); /* line 3438 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3439 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3440 */
} /* line 3440 */
  sim_icache_fetch(2309 + t_thisfile.offset, 1);
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
} /* line 3442 */
  sim_icache_fetch(2310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3444 */
} /* line 3444 */
  sim_icache_fetch(2312 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3446 */
} /* line 3446 */
  sim_icache_fetch(2313 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3448 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3449 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3450 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3451 */
   __ADD_CYCLES(1);
} /* line 3451 */
  sim_icache_fetch(2319 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_4); /* line 3453 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3454 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3455 */
} /* line 3455 */
  sim_icache_fetch(2322 + t_thisfile.offset, 1);
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
} /* line 3457 */
  sim_icache_fetch(2323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3459 */
} /* line 3459 */
  sim_icache_fetch(2325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3461 */
} /* line 3461 */
  sim_icache_fetch(2326 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3463 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3464 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3465 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3466 */
   __ADD_CYCLES(1);
} /* line 3466 */
  sim_icache_fetch(2332 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_4); /* line 3468 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3469 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3470 */
} /* line 3470 */
  sim_icache_fetch(2335 + t_thisfile.offset, 1);
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
} /* line 3472 */
  sim_icache_fetch(2336 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3474 */
} /* line 3474 */
  sim_icache_fetch(2338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3476 */
} /* line 3476 */
  sim_icache_fetch(2339 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3478 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3479 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3480 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3481 */
   __ADD_CYCLES(1);
} /* line 3481 */
  sim_icache_fetch(2345 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_4); /* line 3483 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3484 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3485 */
} /* line 3485 */
  sim_icache_fetch(2348 + t_thisfile.offset, 1);
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
} /* line 3487 */
  sim_icache_fetch(2349 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3489 */
} /* line 3489 */
  sim_icache_fetch(2351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3491 */
} /* line 3491 */
  sim_icache_fetch(2352 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3493 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3494 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3495 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3496 */
   __ADD_CYCLES(1);
} /* line 3496 */
  sim_icache_fetch(2358 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_4); /* line 3498 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3499 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3500 */
} /* line 3500 */
  sim_icache_fetch(2361 + t_thisfile.offset, 1);
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
} /* line 3502 */
  sim_icache_fetch(2362 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3504 */
} /* line 3504 */
  sim_icache_fetch(2364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_5); /* line 3506 */
} /* line 3506 */
  sim_icache_fetch(2365 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3508 */
   __LDBs(reg_r0_38, mem_trace_ld(reg_r0_37,0,1)); /* line 3509 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3510 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3511 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3512 */
   __ADD_CYCLES(1);
} /* line 3512 */
  sim_icache_fetch(2372 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 3514 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3515 */
   __MOV(reg_r0_3, reg_r0_2); /* line 3516 */
} /* line 3516 */
  sim_icache_fetch(2375 + t_thisfile.offset, 1);
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
} /* line 3518 */
  sim_icache_fetch(2376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3520 */
} /* line 3520 */
  sim_icache_fetch(2378 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3522 */
} /* line 3522 */
  sim_icache_fetch(2379 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3524 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3525 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3526 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3527 */
   __ADD_CYCLES(1);
} /* line 3527 */
  sim_icache_fetch(2385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3529 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3530 */
} /* line 3530 */
  sim_icache_fetch(2387 + t_thisfile.offset, 1);
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
} /* line 3532 */
  sim_icache_fetch(2388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3534 */
} /* line 3534 */
  sim_icache_fetch(2390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3536 */
} /* line 3536 */
  sim_icache_fetch(2391 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3538 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3539 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3540 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3541 */
   __ADD_CYCLES(1);
} /* line 3541 */
  sim_icache_fetch(2397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3543 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3544 */
} /* line 3544 */
  sim_icache_fetch(2399 + t_thisfile.offset, 1);
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
} /* line 3546 */
  sim_icache_fetch(2400 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3548 */
} /* line 3548 */
  sim_icache_fetch(2402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3550 */
} /* line 3550 */
  sim_icache_fetch(2403 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3552 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3553 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3554 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3555 */
   __ADD_CYCLES(1);
} /* line 3555 */
  sim_icache_fetch(2409 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3557 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3558 */
} /* line 3558 */
  sim_icache_fetch(2411 + t_thisfile.offset, 1);
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
} /* line 3560 */
  sim_icache_fetch(2412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3562 */
} /* line 3562 */
  sim_icache_fetch(2414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3564 */
} /* line 3564 */
  sim_icache_fetch(2415 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3566 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3567 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3568 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3569 */
   __ADD_CYCLES(1);
} /* line 3569 */
  sim_icache_fetch(2421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3571 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3572 */
} /* line 3572 */
  sim_icache_fetch(2423 + t_thisfile.offset, 1);
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
} /* line 3574 */
  sim_icache_fetch(2424 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3576 */
} /* line 3576 */
  sim_icache_fetch(2426 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3578 */
} /* line 3578 */
  sim_icache_fetch(2427 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3580 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3581 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3582 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3583 */
   __ADD_CYCLES(1);
} /* line 3583 */
  sim_icache_fetch(2433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3585 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3586 */
} /* line 3586 */
  sim_icache_fetch(2435 + t_thisfile.offset, 1);
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
} /* line 3588 */
  sim_icache_fetch(2436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3590 */
} /* line 3590 */
  sim_icache_fetch(2438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3592 */
} /* line 3592 */
  sim_icache_fetch(2439 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3594 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3595 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3596 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3597 */
   __ADD_CYCLES(1);
} /* line 3597 */
  sim_icache_fetch(2445 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3599 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3600 */
} /* line 3600 */
  sim_icache_fetch(2447 + t_thisfile.offset, 1);
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
} /* line 3602 */
  sim_icache_fetch(2448 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3604 */
} /* line 3604 */
  sim_icache_fetch(2450 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3606 */
} /* line 3606 */
  sim_icache_fetch(2451 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3608 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3609 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3610 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3611 */
   __ADD_CYCLES(1);
} /* line 3611 */
  sim_icache_fetch(2457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3613 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3614 */
} /* line 3614 */
  sim_icache_fetch(2459 + t_thisfile.offset, 1);
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
} /* line 3616 */
  sim_icache_fetch(2460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3618 */
} /* line 3618 */
  sim_icache_fetch(2462 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3620 */
} /* line 3620 */
  sim_icache_fetch(2463 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3622 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3623 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3624 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3625 */
   __ADD_CYCLES(1);
} /* line 3625 */
  sim_icache_fetch(2469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3627 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3628 */
} /* line 3628 */
  sim_icache_fetch(2471 + t_thisfile.offset, 1);
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
} /* line 3630 */
  sim_icache_fetch(2472 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3632 */
} /* line 3632 */
  sim_icache_fetch(2474 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3634 */
} /* line 3634 */
  sim_icache_fetch(2475 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3636 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3637 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3638 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3639 */
   __ADD_CYCLES(1);
} /* line 3639 */
  sim_icache_fetch(2481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3641 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3642 */
} /* line 3642 */
  sim_icache_fetch(2483 + t_thisfile.offset, 1);
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
} /* line 3644 */
  sim_icache_fetch(2484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3646 */
} /* line 3646 */
  sim_icache_fetch(2486 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3648 */
} /* line 3648 */
  sim_icache_fetch(2487 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3650 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3651 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3652 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3653 */
   __ADD_CYCLES(1);
} /* line 3653 */
  sim_icache_fetch(2493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3655 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3656 */
} /* line 3656 */
  sim_icache_fetch(2495 + t_thisfile.offset, 1);
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
} /* line 3658 */
  sim_icache_fetch(2496 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3660 */
} /* line 3660 */
  sim_icache_fetch(2498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3662 */
} /* line 3662 */
  sim_icache_fetch(2499 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3664 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3665 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3666 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3667 */
   __ADD_CYCLES(1);
} /* line 3667 */
  sim_icache_fetch(2505 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3669 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3670 */
} /* line 3670 */
  sim_icache_fetch(2507 + t_thisfile.offset, 1);
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
} /* line 3672 */
  sim_icache_fetch(2508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3674 */
} /* line 3674 */
  sim_icache_fetch(2510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3676 */
} /* line 3676 */
  sim_icache_fetch(2511 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3678 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3679 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3680 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3681 */
   __ADD_CYCLES(1);
} /* line 3681 */
  sim_icache_fetch(2517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3683 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3684 */
} /* line 3684 */
  sim_icache_fetch(2519 + t_thisfile.offset, 1);
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
} /* line 3686 */
  sim_icache_fetch(2520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3688 */
} /* line 3688 */
  sim_icache_fetch(2522 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3690 */
} /* line 3690 */
  sim_icache_fetch(2523 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3692 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3693 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3694 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3695 */
   __ADD_CYCLES(1);
} /* line 3695 */
  sim_icache_fetch(2529 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3697 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3698 */
} /* line 3698 */
  sim_icache_fetch(2531 + t_thisfile.offset, 1);
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
} /* line 3700 */
  sim_icache_fetch(2532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3702 */
} /* line 3702 */
  sim_icache_fetch(2534 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3704 */
} /* line 3704 */
  sim_icache_fetch(2535 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3706 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3707 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3708 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3709 */
   __ADD_CYCLES(1);
} /* line 3709 */
  sim_icache_fetch(2541 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3711 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3712 */
} /* line 3712 */
  sim_icache_fetch(2543 + t_thisfile.offset, 1);
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
} /* line 3714 */
  sim_icache_fetch(2544 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3716 */
} /* line 3716 */
  sim_icache_fetch(2546 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3718 */
} /* line 3718 */
  sim_icache_fetch(2547 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3720 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3721 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3722 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3723 */
   __ADD_CYCLES(1);
} /* line 3723 */
  sim_icache_fetch(2553 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3725 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3726 */
} /* line 3726 */
  sim_icache_fetch(2555 + t_thisfile.offset, 1);
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
} /* line 3728 */
  sim_icache_fetch(2556 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3730 */
} /* line 3730 */
  sim_icache_fetch(2558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3732 */
   __GOTO(l_L169X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L169X3;
} /* line 3733 */
l_L170X3: ;/* line 3736 */
__LABEL(l_L170X3);
  sim_icache_fetch(2560 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3737 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3738 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3739 */
   __ADD_CYCLES(1);
} /* line 3739 */
  sim_icache_fetch(2565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3741 */
} /* line 3741 */
  sim_icache_fetch(2566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3743 */
} /* line 3743 */
l_L168X3: ;/* line 3746 */
__LABEL(l_L168X3);
  sim_icache_fetch(2568 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_10102Xoffset,0,4), 0); /* line 3747 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3748 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3749 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3750 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3751 */
   __ADD_CYCLES(1);
} /* line 3751 */
  sim_icache_fetch(2576 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3753 */
} /* line 3753 */
  sim_icache_fetch(2577 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3755 */
  sim_icache_fetch(2578 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3758 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3759 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3760 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3761 */
l_L171X3: ;/* line 3764 */
__LABEL(l_L171X3);
  sim_icache_fetch(2585 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3765 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3766 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3767 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3768 */
   __ADD_CYCLES(1);
} /* line 3768 */
  sim_icache_fetch(2592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3770 */
} /* line 3770 */
  sim_icache_fetch(2593 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3772 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3773 */
} /* line 3773 */
  sim_icache_fetch(2596 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3775 */
  sim_icache_fetch(2597 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3778 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3779 */
l_L172X3: ;/* line 3782 */
__LABEL(l_L172X3);
  sim_icache_fetch(2600 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3783 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3784 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3785 */
   __ADD_CYCLES(1);
} /* line 3785 */
  sim_icache_fetch(2604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3787 */
} /* line 3787 */
  sim_icache_fetch(2605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3789 */
} /* line 3789 */
  sim_icache_fetch(2606 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3792 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3793 */
l_L167X3: ;/* line 3796 */
__LABEL(l_L167X3);
  sim_icache_fetch(2609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3798 */
l_L161X3: ;/* line 3801 */
__LABEL(l_L161X3);
  sim_icache_fetch(2610 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3802 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3803 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3804 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3805 */
   __ADD_CYCLES(1);
} /* line 3805 */
  sim_icache_fetch(2617 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3807 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(2619 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3810 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3811 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3812 */
l_L174X3: ;/* line 3814 */
__LABEL(l_L174X3);
  sim_icache_fetch(2622 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3815 */
   __STW(mem_trace_st((unsigned int) compress_10102Xoffset,0,4), 0); /* line 3816 */
} /* line 3816 */
  sim_icache_fetch(2625 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3818 */
} /* line 3818 */
  sim_icache_fetch(2626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3820 */
} /* line 3820 */
  sim_icache_fetch(2627 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3823 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3824 */
l_L173X3: ;/* line 3827 */
__LABEL(l_L173X3);
  sim_icache_fetch(2630 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3828 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3829 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3830 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3831 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3832 */
} /* line 3832 */
  sim_icache_fetch(2635 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3834 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3835 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3836 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3837 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3838 */
} /* line 3838 */
  sim_icache_fetch(2640 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3840 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3841 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3842 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3843 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3844 */
} /* line 3844 */
  sim_icache_fetch(2645 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) compress_10102Xbuf); /* line 3846 */
   __MOV(reg_r0_3, 0); /* line 3847 */
} /* line 3847 */
l_L175X3: ;/* line 3850 */
__LABEL(l_L175X3);
  sim_icache_fetch(2648 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3851 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3852 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3853 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3854 */
   __ADD_CYCLES(1);
} /* line 3854 */
  sim_icache_fetch(2654 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3856 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3857 */
} /* line 3857 */
  sim_icache_fetch(2656 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3859 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3860 */
} /* line 3860 */
  sim_icache_fetch(2658 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3862 */
} /* line 3862 */
  sim_icache_fetch(2659 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3864 */
} /* line 3864 */
  sim_icache_fetch(2660 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3866 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3867 */
} /* line 3867 */
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
} /* line 3869 */
  sim_icache_fetch(2663 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3871 */
} /* line 3871 */
  sim_icache_fetch(2665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3873 */
} /* line 3873 */
  sim_icache_fetch(2666 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3875 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3876 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3877 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3878 */
   __ADD_CYCLES(1);
} /* line 3878 */
  sim_icache_fetch(2672 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3880 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3881 */
} /* line 3881 */
  sim_icache_fetch(2674 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3883 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3884 */
} /* line 3884 */
  sim_icache_fetch(2676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3886 */
} /* line 3886 */
  sim_icache_fetch(2677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3888 */
} /* line 3888 */
  sim_icache_fetch(2678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3890 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3891 */
} /* line 3891 */
  sim_icache_fetch(2680 + t_thisfile.offset, 1);
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
} /* line 3893 */
  sim_icache_fetch(2681 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3895 */
} /* line 3895 */
  sim_icache_fetch(2683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3897 */
} /* line 3897 */
  sim_icache_fetch(2684 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3899 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3900 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3901 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3902 */
   __ADD_CYCLES(1);
} /* line 3902 */
  sim_icache_fetch(2690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3904 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3905 */
} /* line 3905 */
  sim_icache_fetch(2692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3907 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3908 */
} /* line 3908 */
  sim_icache_fetch(2694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3910 */
} /* line 3910 */
  sim_icache_fetch(2695 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3912 */
} /* line 3912 */
  sim_icache_fetch(2696 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3914 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3915 */
} /* line 3915 */
  sim_icache_fetch(2698 + t_thisfile.offset, 1);
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
} /* line 3917 */
  sim_icache_fetch(2699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3919 */
} /* line 3919 */
  sim_icache_fetch(2701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3921 */
} /* line 3921 */
  sim_icache_fetch(2702 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3923 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3924 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3925 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3926 */
   __ADD_CYCLES(1);
} /* line 3926 */
  sim_icache_fetch(2708 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3928 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3929 */
} /* line 3929 */
  sim_icache_fetch(2710 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3931 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3932 */
} /* line 3932 */
  sim_icache_fetch(2712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3934 */
} /* line 3934 */
  sim_icache_fetch(2713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3936 */
} /* line 3936 */
  sim_icache_fetch(2714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3938 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3939 */
} /* line 3939 */
  sim_icache_fetch(2716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3941 */
  sim_icache_fetch(2717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3943 */
} /* line 3943 */
  sim_icache_fetch(2719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3945 */
} /* line 3945 */
  sim_icache_fetch(2720 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3947 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3948 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3949 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3950 */
   __ADD_CYCLES(1);
} /* line 3950 */
  sim_icache_fetch(2726 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3952 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3953 */
} /* line 3953 */
  sim_icache_fetch(2728 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3955 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3956 */
} /* line 3956 */
  sim_icache_fetch(2730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3958 */
} /* line 3958 */
  sim_icache_fetch(2731 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3960 */
} /* line 3960 */
  sim_icache_fetch(2732 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 3962 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3963 */
} /* line 3963 */
  sim_icache_fetch(2734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L180X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3965 */
  sim_icache_fetch(2735 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3967 */
} /* line 3967 */
  sim_icache_fetch(2737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3969 */
} /* line 3969 */
  sim_icache_fetch(2738 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3971 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3972 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3973 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3974 */
   __ADD_CYCLES(1);
} /* line 3974 */
  sim_icache_fetch(2744 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3976 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3977 */
} /* line 3977 */
  sim_icache_fetch(2746 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3979 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3980 */
} /* line 3980 */
  sim_icache_fetch(2748 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3982 */
} /* line 3982 */
  sim_icache_fetch(2749 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3984 */
} /* line 3984 */
  sim_icache_fetch(2750 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 3986 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3987 */
} /* line 3987 */
  sim_icache_fetch(2752 + t_thisfile.offset, 1);
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
} /* line 3989 */
  sim_icache_fetch(2753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3991 */
} /* line 3991 */
  sim_icache_fetch(2755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3993 */
} /* line 3993 */
  sim_icache_fetch(2756 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 3995 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3996 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3997 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3998 */
   __ADD_CYCLES(1);
} /* line 3998 */
  sim_icache_fetch(2762 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4000 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4001 */
} /* line 4001 */
  sim_icache_fetch(2764 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4003 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4004 */
} /* line 4004 */
  sim_icache_fetch(2766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4006 */
} /* line 4006 */
  sim_icache_fetch(2767 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4008 */
} /* line 4008 */
  sim_icache_fetch(2768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 4010 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 4011 */
} /* line 4011 */
  sim_icache_fetch(2770 + t_thisfile.offset, 1);
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
} /* line 4013 */
  sim_icache_fetch(2771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4015 */
} /* line 4015 */
  sim_icache_fetch(2773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4017 */
} /* line 4017 */
  sim_icache_fetch(2774 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4019 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4020 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4021 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4022 */
   __ADD_CYCLES(1);
} /* line 4022 */
  sim_icache_fetch(2780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4024 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4025 */
} /* line 4025 */
  sim_icache_fetch(2782 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4027 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4028 */
} /* line 4028 */
  sim_icache_fetch(2784 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4030 */
} /* line 4030 */
  sim_icache_fetch(2785 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4032 */
} /* line 4032 */
  sim_icache_fetch(2786 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4034 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4035 */
} /* line 4035 */
  sim_icache_fetch(2788 + t_thisfile.offset, 1);
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
} /* line 4037 */
  sim_icache_fetch(2789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4039 */
} /* line 4039 */
  sim_icache_fetch(2791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4041 */
} /* line 4041 */
  sim_icache_fetch(2792 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4043 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4044 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4045 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4046 */
   __ADD_CYCLES(1);
} /* line 4046 */
  sim_icache_fetch(2798 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4048 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4049 */
} /* line 4049 */
  sim_icache_fetch(2800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4051 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4052 */
} /* line 4052 */
  sim_icache_fetch(2802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4054 */
} /* line 4054 */
  sim_icache_fetch(2803 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4056 */
} /* line 4056 */
  sim_icache_fetch(2804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4058 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4059 */
} /* line 4059 */
  sim_icache_fetch(2806 + t_thisfile.offset, 1);
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
} /* line 4061 */
  sim_icache_fetch(2807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4063 */
} /* line 4063 */
  sim_icache_fetch(2809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4065 */
} /* line 4065 */
  sim_icache_fetch(2810 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4067 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4068 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4069 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4070 */
   __ADD_CYCLES(1);
} /* line 4070 */
  sim_icache_fetch(2816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4072 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4073 */
} /* line 4073 */
  sim_icache_fetch(2818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4075 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4076 */
} /* line 4076 */
  sim_icache_fetch(2820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4078 */
} /* line 4078 */
  sim_icache_fetch(2821 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4080 */
} /* line 4080 */
  sim_icache_fetch(2822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4082 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4083 */
} /* line 4083 */
  sim_icache_fetch(2824 + t_thisfile.offset, 1);
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
} /* line 4085 */
  sim_icache_fetch(2825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4087 */
} /* line 4087 */
  sim_icache_fetch(2827 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4089 */
} /* line 4089 */
  sim_icache_fetch(2828 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4091 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4092 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4093 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4094 */
   __ADD_CYCLES(1);
} /* line 4094 */
  sim_icache_fetch(2834 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4096 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4097 */
} /* line 4097 */
  sim_icache_fetch(2836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4099 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4100 */
} /* line 4100 */
  sim_icache_fetch(2838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4102 */
} /* line 4102 */
  sim_icache_fetch(2839 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4104 */
} /* line 4104 */
  sim_icache_fetch(2840 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4106 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4107 */
} /* line 4107 */
  sim_icache_fetch(2842 + t_thisfile.offset, 1);
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
} /* line 4109 */
  sim_icache_fetch(2843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4111 */
} /* line 4111 */
  sim_icache_fetch(2845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4113 */
} /* line 4113 */
  sim_icache_fetch(2846 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4115 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4116 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4117 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4118 */
   __ADD_CYCLES(1);
} /* line 4118 */
  sim_icache_fetch(2852 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4120 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4121 */
} /* line 4121 */
  sim_icache_fetch(2854 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4123 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4124 */
} /* line 4124 */
  sim_icache_fetch(2856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4126 */
} /* line 4126 */
  sim_icache_fetch(2857 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4128 */
} /* line 4128 */
  sim_icache_fetch(2858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4130 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4131 */
} /* line 4131 */
  sim_icache_fetch(2860 + t_thisfile.offset, 1);
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
} /* line 4133 */
  sim_icache_fetch(2861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4135 */
} /* line 4135 */
  sim_icache_fetch(2863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4137 */
} /* line 4137 */
  sim_icache_fetch(2864 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4139 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4140 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4141 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4142 */
   __ADD_CYCLES(1);
} /* line 4142 */
  sim_icache_fetch(2870 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4144 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4145 */
} /* line 4145 */
  sim_icache_fetch(2872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4147 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4148 */
} /* line 4148 */
  sim_icache_fetch(2874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4150 */
} /* line 4150 */
  sim_icache_fetch(2875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4152 */
} /* line 4152 */
  sim_icache_fetch(2876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4154 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4155 */
} /* line 4155 */
  sim_icache_fetch(2878 + t_thisfile.offset, 1);
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
} /* line 4157 */
  sim_icache_fetch(2879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4159 */
} /* line 4159 */
  sim_icache_fetch(2881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4161 */
} /* line 4161 */
  sim_icache_fetch(2882 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4163 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4164 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4165 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4166 */
   __ADD_CYCLES(1);
} /* line 4166 */
  sim_icache_fetch(2888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4168 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4169 */
} /* line 4169 */
  sim_icache_fetch(2890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4171 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4172 */
} /* line 4172 */
  sim_icache_fetch(2892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4174 */
} /* line 4174 */
  sim_icache_fetch(2893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4176 */
} /* line 4176 */
  sim_icache_fetch(2894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4178 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4179 */
} /* line 4179 */
  sim_icache_fetch(2896 + t_thisfile.offset, 1);
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
} /* line 4181 */
  sim_icache_fetch(2897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4183 */
} /* line 4183 */
  sim_icache_fetch(2899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4185 */
} /* line 4185 */
  sim_icache_fetch(2900 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4187 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4188 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4189 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4190 */
   __ADD_CYCLES(1);
} /* line 4190 */
  sim_icache_fetch(2906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4192 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4193 */
} /* line 4193 */
  sim_icache_fetch(2908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4195 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4196 */
} /* line 4196 */
  sim_icache_fetch(2910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4198 */
} /* line 4198 */
  sim_icache_fetch(2911 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4200 */
} /* line 4200 */
  sim_icache_fetch(2912 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4202 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4203 */
} /* line 4203 */
  sim_icache_fetch(2914 + t_thisfile.offset, 1);
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
} /* line 4205 */
  sim_icache_fetch(2915 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4207 */
} /* line 4207 */
  sim_icache_fetch(2917 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4209 */
} /* line 4209 */
  sim_icache_fetch(2918 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4211 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4212 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4213 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4214 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4215 */
   __ADD_CYCLES(1);
} /* line 4215 */
  sim_icache_fetch(2925 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4217 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4218 */
} /* line 4218 */
  sim_icache_fetch(2927 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4220 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4221 */
} /* line 4221 */
  sim_icache_fetch(2929 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4223 */
} /* line 4223 */
  sim_icache_fetch(2930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4225 */
} /* line 4225 */
  sim_icache_fetch(2931 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4227 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4228 */
} /* line 4228 */
  sim_icache_fetch(2933 + t_thisfile.offset, 1);
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
} /* line 4230 */
  sim_icache_fetch(2934 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4232 */
} /* line 4232 */
  sim_icache_fetch(2936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4234 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4235 */
l_L191X3: ;/* line 4238 */
__LABEL(l_L191X3);
  sim_icache_fetch(2938 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4239 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4240 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4241 */
   __ADD_CYCLES(1);
} /* line 4241 */
  sim_icache_fetch(2943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4243 */
} /* line 4243 */
  sim_icache_fetch(2944 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4245 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4246 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4247 */
l_L190X3: ;/* line 4250 */
__LABEL(l_L190X3);
  sim_icache_fetch(2947 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4251 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4252 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4253 */
   __ADD_CYCLES(1);
} /* line 4253 */
  sim_icache_fetch(2952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4255 */
} /* line 4255 */
  sim_icache_fetch(2953 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4257 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4258 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4259 */
l_L189X3: ;/* line 4262 */
__LABEL(l_L189X3);
  sim_icache_fetch(2956 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4263 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4264 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4265 */
   __ADD_CYCLES(1);
} /* line 4265 */
  sim_icache_fetch(2961 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4267 */
} /* line 4267 */
  sim_icache_fetch(2962 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4269 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4270 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4271 */
l_L188X3: ;/* line 4274 */
__LABEL(l_L188X3);
  sim_icache_fetch(2965 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4275 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4276 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4277 */
   __ADD_CYCLES(1);
} /* line 4277 */
  sim_icache_fetch(2970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4279 */
} /* line 4279 */
  sim_icache_fetch(2971 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4281 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4282 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4283 */
l_L187X3: ;/* line 4286 */
__LABEL(l_L187X3);
  sim_icache_fetch(2974 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4287 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4288 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4289 */
   __ADD_CYCLES(1);
} /* line 4289 */
  sim_icache_fetch(2979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4291 */
} /* line 4291 */
  sim_icache_fetch(2980 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4293 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4294 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4295 */
l_L186X3: ;/* line 4298 */
__LABEL(l_L186X3);
  sim_icache_fetch(2983 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4299 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4300 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4301 */
   __ADD_CYCLES(1);
} /* line 4301 */
  sim_icache_fetch(2988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4303 */
} /* line 4303 */
  sim_icache_fetch(2989 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4305 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4306 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4307 */
l_L185X3: ;/* line 4310 */
__LABEL(l_L185X3);
  sim_icache_fetch(2992 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4311 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4312 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4313 */
   __ADD_CYCLES(1);
} /* line 4313 */
  sim_icache_fetch(2997 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4315 */
} /* line 4315 */
  sim_icache_fetch(2998 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4317 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4318 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4319 */
l_L184X3: ;/* line 4322 */
__LABEL(l_L184X3);
  sim_icache_fetch(3001 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4323 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4324 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4325 */
   __ADD_CYCLES(1);
} /* line 4325 */
  sim_icache_fetch(3006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4327 */
} /* line 4327 */
  sim_icache_fetch(3007 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4329 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4330 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4331 */
l_L183X3: ;/* line 4334 */
__LABEL(l_L183X3);
  sim_icache_fetch(3010 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4335 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4336 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4337 */
   __ADD_CYCLES(1);
} /* line 4337 */
  sim_icache_fetch(3015 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4339 */
} /* line 4339 */
  sim_icache_fetch(3016 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4341 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4342 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4343 */
l_L182X3: ;/* line 4346 */
__LABEL(l_L182X3);
  sim_icache_fetch(3019 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4347 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4348 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4349 */
   __ADD_CYCLES(1);
} /* line 4349 */
  sim_icache_fetch(3024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4351 */
} /* line 4351 */
  sim_icache_fetch(3025 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4353 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4354 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4355 */
l_L181X3: ;/* line 4358 */
__LABEL(l_L181X3);
  sim_icache_fetch(3028 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4359 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4360 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4361 */
   __ADD_CYCLES(1);
} /* line 4361 */
  sim_icache_fetch(3033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4363 */
} /* line 4363 */
  sim_icache_fetch(3034 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4365 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4366 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4367 */
l_L180X3: ;/* line 4370 */
__LABEL(l_L180X3);
  sim_icache_fetch(3037 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4371 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4372 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4373 */
   __ADD_CYCLES(1);
} /* line 4373 */
  sim_icache_fetch(3042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4375 */
} /* line 4375 */
  sim_icache_fetch(3043 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4377 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4378 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4379 */
l_L179X3: ;/* line 4382 */
__LABEL(l_L179X3);
  sim_icache_fetch(3046 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4383 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4384 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4385 */
   __ADD_CYCLES(1);
} /* line 4385 */
  sim_icache_fetch(3051 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4387 */
} /* line 4387 */
  sim_icache_fetch(3052 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4389 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4390 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4391 */
l_L178X3: ;/* line 4394 */
__LABEL(l_L178X3);
  sim_icache_fetch(3055 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4395 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4396 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4397 */
   __ADD_CYCLES(1);
} /* line 4397 */
  sim_icache_fetch(3060 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4399 */
} /* line 4399 */
  sim_icache_fetch(3061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4401 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4402 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4403 */
l_L177X3: ;/* line 4406 */
__LABEL(l_L177X3);
  sim_icache_fetch(3064 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4407 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4408 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4409 */
   __ADD_CYCLES(1);
} /* line 4409 */
  sim_icache_fetch(3069 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4411 */
} /* line 4411 */
  sim_icache_fetch(3070 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4413 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4414 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4415 */
l_L176X3: ;/* line 4418 */
__LABEL(l_L176X3);
  sim_icache_fetch(3073 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4419 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_10102Xoffset,0,4)); /* line 4420 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4421 */
   __ADD_CYCLES(1);
} /* line 4421 */
  sim_icache_fetch(3078 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4423 */
} /* line 4423 */
  sim_icache_fetch(3079 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4425 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4426 */
   __GOTO(l_L174X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L174X3;
} /* line 4427 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 326: goto l_L162X3;
    case 327: goto l_L163X3;
    case 328: goto l_L165X3;
    case 329: goto l_L166X3;
    case 330: goto l_L164X3;
    case 331: goto l_L169X3;
    case 332: goto l_L170X3;
    case 333: goto l_L168X3;
    case 334: goto l_L171X3;
    case 335: goto l_L172X3;
    case 336: goto l_L167X3;
    case 337: goto l_L161X3;
    case 338: goto l_L174X3;
    case 339: goto l_L173X3;
    case 340: goto l_L175X3;
    case 341: goto l_L191X3;
    case 342: goto l_L190X3;
    case 343: goto l_L189X3;
    case 344: goto l_L188X3;
    case 345: goto l_L187X3;
    case 346: goto l_L186X3;
    case 347: goto l_L185X3;
    case 348: goto l_L184X3;
    case 349: goto l_L183X3;
    case 350: goto l_L182X3;
    case 351: goto l_L181X3;
    case 352: goto l_L180X3;
    case 353: goto l_L179X3;
    case 354: goto l_L178X3;
    case 355: goto l_L177X3;
    case 356: goto l_L176X3;
    case 357:
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
  reg_l0_0 = (411 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3082 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4443 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4444 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4445 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4446 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4447 */
} /* line 4447 */
  sim_icache_fetch(3088 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4449 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4450 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4451 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4452 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4453 */
} /* line 4453 */
  sim_icache_fetch(3093 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4455 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4456 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4457 */
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4458 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4459 */
} /* line 4459 */
  sim_icache_fetch(3098 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4461 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4462 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4463 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4464 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4465 */
} /* line 4465 */
  sim_icache_fetch(3104 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4467 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4468 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4469 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4470 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4471 */
} /* line 4471 */
l_L192X3: ;/* line 4474 */
__LABEL(l_L192X3);
  sim_icache_fetch(3112 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4475 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4476 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4477 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4478 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4479 */
} /* line 4479 */
  sim_icache_fetch(3117 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4481 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4482 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4483 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4484 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L193X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4485 */
  sim_icache_fetch(3122 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4487 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4488 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4489 */
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4490 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4491 */
} /* line 4491 */
  sim_icache_fetch(3127 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4493 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4494 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4495 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4496 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4497 */
} /* line 4497 */
  sim_icache_fetch(3132 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4499 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4500 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4501 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4502 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4503 */
} /* line 4503 */
  sim_icache_fetch(3137 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4505 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4506 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4507 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4508 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4509 */
} /* line 4509 */
  sim_icache_fetch(3142 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4511 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4512 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4513 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4514 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4515 */
} /* line 4515 */
  sim_icache_fetch(3147 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4517 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4518 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4519 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4520 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4521 */
} /* line 4521 */
  sim_icache_fetch(3152 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4523 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4524 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4525 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4526 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4527 */
} /* line 4527 */
  sim_icache_fetch(3157 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4529 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4530 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4531 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4532 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4533 */
} /* line 4533 */
  sim_icache_fetch(3162 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4535 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4536 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4537 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4538 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4539 */
} /* line 4539 */
  sim_icache_fetch(3167 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4541 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4542 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4543 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4544 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4545 */
} /* line 4545 */
  sim_icache_fetch(3172 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4547 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4548 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4549 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4550 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4551 */
} /* line 4551 */
  sim_icache_fetch(3177 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4553 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4554 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4555 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4556 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4557 */
} /* line 4557 */
  sim_icache_fetch(3182 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4559 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4560 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4561 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4562 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4563 */
} /* line 4563 */
  sim_icache_fetch(3187 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4565 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4566 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4567 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4568 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4569 */
} /* line 4569 */
  sim_icache_fetch(3192 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4571 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4572 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4573 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4574 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4575 */
} /* line 4575 */
  sim_icache_fetch(3197 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4577 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4578 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4579 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4580 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4581 */
} /* line 4581 */
  sim_icache_fetch(3202 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4583 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4584 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4585 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4586 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4587 */
} /* line 4587 */
  sim_icache_fetch(3207 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4589 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4590 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4591 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4592 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4593 */
} /* line 4593 */
  sim_icache_fetch(3212 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4595 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4596 */
   __GOTO(l_L192X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L192X3;
} /* line 4597 */
l_L193X3: ;/* line 4600 */
__LABEL(l_L193X3);
  sim_icache_fetch(3215 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4601 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4602 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4603 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4604 */
   __ADD_CYCLES(1);
} /* line 4604 */
  sim_icache_fetch(3221 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4606 */
} /* line 4606 */
  sim_icache_fetch(3222 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4608 */
} /* line 4608 */
		 /* line 4609 */
  sim_icache_fetch(3224 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4611 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (411 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4612 */
l_lr_260: ;/* line 4612 */
__LABEL(l_lr_260);
  sim_icache_fetch(3228 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_2, reg_r0_3); /* line 4614 */
   __MOV(reg_r0_4, reg_r0_3); /* line 4615 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4616 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4617 */
   __MOV(reg_r0_5, reg_r0_3); /* line 4618 */
} /* line 4618 */
  sim_icache_fetch(3233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 4620 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L194X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4621 */
  sim_icache_fetch(3235 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4624 */
l_L194X3: ;/* line 4627 */
__LABEL(l_L194X3);
  sim_icache_fetch(3236 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4628 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4629 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4630 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4631 */
} /* line 4631 */
  sim_icache_fetch(3241 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4633 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4634 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4635 */
} /* line 4635 */
  sim_icache_fetch(3245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4637 */
} /* line 4637 */
  sim_icache_fetch(3246 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4639 */
} /* line 4639 */
  sim_icache_fetch(3248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4641 */
} /* line 4641 */
l_L195X3: ;/* line 4644 */
__LABEL(l_L195X3);
		 /* line 4644 */
  sim_icache_fetch(3249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (411 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4646 */
l_lr_264: ;/* line 4646 */
__LABEL(l_lr_264);
  sim_icache_fetch(3251 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4648 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4649 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4650 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4651 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4652 */
} /* line 4652 */
  sim_icache_fetch(3258 + t_thisfile.offset, 1);
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
} /* line 4654 */
  sim_icache_fetch(3259 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4656 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4657 */
} /* line 4657 */
  sim_icache_fetch(3262 + t_thisfile.offset, 1);
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
} /* line 4659 */
l_L198X3: ;/* line 4662 */
__LABEL(l_L198X3);
  sim_icache_fetch(3263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4663 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4664 */
} /* line 4664 */
  sim_icache_fetch(3265 + t_thisfile.offset, 1);
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
} /* line 4666 */
  sim_icache_fetch(3266 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4668 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4669 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4670 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4671 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4672 */
} /* line 4672 */
  sim_icache_fetch(3271 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4674 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4675 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4676 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4677 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4678 */
} /* line 4678 */
  sim_icache_fetch(3276 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4680 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4681 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4682 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4683 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4684 */
} /* line 4684 */
  sim_icache_fetch(3281 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4686 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4687 */
   __GOTO(l_L198X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L198X3;
} /* line 4688 */
l_L199X3: ;/* line 4691 */
__LABEL(l_L199X3);
  sim_icache_fetch(3284 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4692 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4693 */
} /* line 4693 */
		 /* line 4694 */
  sim_icache_fetch(3287 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4696 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4697 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (411 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4698 */
l_lr_268: ;/* line 4698 */
__LABEL(l_lr_268);
  sim_icache_fetch(3293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4700 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4701 */
} /* line 4701 */
  sim_icache_fetch(3295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L196X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4703 */
l_L197X3: ;/* line 4706 */
__LABEL(l_L197X3);
  sim_icache_fetch(3296 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4707 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4708 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4709 */
   __ADD_CYCLES(1);
} /* line 4709 */
  sim_icache_fetch(3300 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4711 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4712 */
} /* line 4712 */
  sim_icache_fetch(3302 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4714 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L200X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4715 */
  sim_icache_fetch(3305 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4717 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4718 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4719 */
} /* line 4719 */
l_L201X3: ;/* line 4722 */
__LABEL(l_L201X3);
  sim_icache_fetch(3308 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4723 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4724 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4725 */
} /* line 4725 */
  sim_icache_fetch(3313 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4727 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L202X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4728 */
  sim_icache_fetch(3315 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4730 */
} /* line 4730 */
  sim_icache_fetch(3316 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4732 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4733 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4734 */
} /* line 4734 */
  sim_icache_fetch(3321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4736 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L203X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4737 */
  sim_icache_fetch(3323 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4739 */
} /* line 4739 */
  sim_icache_fetch(3324 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4741 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4742 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4743 */
} /* line 4743 */
  sim_icache_fetch(3329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4745 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4746 */
  sim_icache_fetch(3331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4748 */
} /* line 4748 */
  sim_icache_fetch(3332 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4750 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4751 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4752 */
} /* line 4752 */
  sim_icache_fetch(3337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4754 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L205X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4755 */
  sim_icache_fetch(3339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4757 */
} /* line 4757 */
  sim_icache_fetch(3340 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4759 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4760 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4761 */
} /* line 4761 */
  sim_icache_fetch(3345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4763 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4764 */
  sim_icache_fetch(3347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4766 */
} /* line 4766 */
  sim_icache_fetch(3348 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4768 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4769 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4770 */
} /* line 4770 */
  sim_icache_fetch(3353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4772 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4773 */
  sim_icache_fetch(3355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4775 */
} /* line 4775 */
  sim_icache_fetch(3356 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4777 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4778 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4779 */
} /* line 4779 */
  sim_icache_fetch(3361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4781 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4782 */
  sim_icache_fetch(3363 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4784 */
} /* line 4784 */
  sim_icache_fetch(3364 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4786 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4787 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4788 */
} /* line 4788 */
  sim_icache_fetch(3369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4790 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4791 */
  sim_icache_fetch(3371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4793 */
} /* line 4793 */
  sim_icache_fetch(3372 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4795 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4796 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4797 */
} /* line 4797 */
  sim_icache_fetch(3377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4799 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4800 */
  sim_icache_fetch(3379 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4802 */
} /* line 4802 */
  sim_icache_fetch(3380 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4804 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4805 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4806 */
} /* line 4806 */
  sim_icache_fetch(3385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4808 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4809 */
  sim_icache_fetch(3387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4811 */
} /* line 4811 */
  sim_icache_fetch(3388 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4813 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4814 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4815 */
} /* line 4815 */
  sim_icache_fetch(3393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4817 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4818 */
  sim_icache_fetch(3395 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4820 */
} /* line 4820 */
  sim_icache_fetch(3396 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4822 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4823 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4824 */
} /* line 4824 */
  sim_icache_fetch(3401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4826 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4827 */
  sim_icache_fetch(3403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4829 */
} /* line 4829 */
  sim_icache_fetch(3404 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4831 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4832 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4833 */
} /* line 4833 */
  sim_icache_fetch(3409 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4835 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4836 */
  sim_icache_fetch(3411 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4838 */
} /* line 4838 */
  sim_icache_fetch(3412 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4840 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4841 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4842 */
} /* line 4842 */
  sim_icache_fetch(3417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4844 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4845 */
  sim_icache_fetch(3419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4847 */
} /* line 4847 */
  sim_icache_fetch(3420 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4849 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4850 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4851 */
} /* line 4851 */
  sim_icache_fetch(3425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4853 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4854 */
  sim_icache_fetch(3427 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4856 */
} /* line 4856 */
  sim_icache_fetch(3428 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4858 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4859 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4860 */
} /* line 4860 */
  sim_icache_fetch(3433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4862 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4863 */
  sim_icache_fetch(3435 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4865 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4866 */
   __GOTO(l_L201X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L201X3;
} /* line 4867 */
l_L217X3: ;/* line 4870 */
__LABEL(l_L217X3);
  sim_icache_fetch(3438 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4871 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4872 */
} /* line 4872 */
  sim_icache_fetch(3440 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4874 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 4875 */
l_L219X3: ;/* line 4878 */
__LABEL(l_L219X3);
  sim_icache_fetch(3442 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_5, reg_r0_3); /* line 4879 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4880 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4881 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4882 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4883 */
} /* line 4883 */
  sim_icache_fetch(3450 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4885 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4886 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4887 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4888 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4889 */
} /* line 4889 */
  sim_icache_fetch(3460 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4891 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4892 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4893 */
   __ADD(reg_r0_23, reg_r0_19, (unsigned int) -16); /* line 4894 */
   __ADD(reg_r0_24, reg_r0_18, (unsigned int) -16); /* line 4895 */
} /* line 4895 */
  sim_icache_fetch(3466 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_25, reg_r0_17, (unsigned int) -16); /* line 4897 */
   __ADD(reg_r0_26, reg_r0_16, (unsigned int) -16); /* line 4898 */
   __ADD(reg_r0_27, reg_r0_15, (unsigned int) -16); /* line 4899 */
   __ADD(reg_r0_28, reg_r0_14, (unsigned int) -16); /* line 4900 */
   __ADD(reg_r0_29, reg_r0_13, (unsigned int) -16); /* line 4901 */
} /* line 4901 */
  sim_icache_fetch(3471 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4903 */
   __ADD(reg_r0_31, reg_r0_11, (unsigned int) -16); /* line 4904 */
   __ADD(reg_r0_32, reg_r0_10, (unsigned int) -16); /* line 4905 */
   __ADD(reg_r0_33, reg_r0_9, (unsigned int) -16); /* line 4906 */
   __ADD(reg_r0_34, reg_r0_8, (unsigned int) -16); /* line 4907 */
} /* line 4907 */
  sim_icache_fetch(3476 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_38, reg_r0_20); /* line 4909 */
   __ADD(reg_r0_35, reg_r0_7, (unsigned int) -16); /* line 4910 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) -16); /* line 4911 */
   __ADD(reg_r0_37, reg_r0_20, (unsigned int) -16); /* line 4912 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 4913 */
} /* line 4913 */
  sim_icache_fetch(3481 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4915 */
   __MOV(reg_r0_40, reg_r0_37); /* line 4916 */
} /* line 4916 */
  sim_icache_fetch(3484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4918 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4919 */
  sim_icache_fetch(3486 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4921 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4922 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4923 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4924 */
   __ADD_CYCLES(1);
} /* line 4924 */
  sim_icache_fetch(3492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4926 */
} /* line 4926 */
  sim_icache_fetch(3493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4928 */
} /* line 4928 */
  sim_icache_fetch(3495 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4930 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4931 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4932 */
  sim_icache_fetch(3499 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4934 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4935 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4936 */
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) -16); /* line 4937 */
   __MFB(reg_r0_4, t__i32_0); /* line 4938 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4939 */
   __ADD_CYCLES(1);
} /* line 4939 */
  sim_icache_fetch(3507 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4941 */
} /* line 4941 */
  sim_icache_fetch(3508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4943 */
} /* line 4943 */
  sim_icache_fetch(3510 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4945 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4946 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4947 */
  sim_icache_fetch(3513 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4949 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4950 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4951 */
   __ADD(reg_r0_7, reg_r0_35, (unsigned int) -16); /* line 4952 */
   __MFB(reg_r0_4, t__i32_0); /* line 4953 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4954 */
   __ADD_CYCLES(1);
} /* line 4954 */
  sim_icache_fetch(3521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4956 */
} /* line 4956 */
  sim_icache_fetch(3522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4958 */
} /* line 4958 */
  sim_icache_fetch(3524 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4960 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4961 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4962 */
  sim_icache_fetch(3527 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4964 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4965 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4966 */
   __ADD(reg_r0_8, reg_r0_34, (unsigned int) -16); /* line 4967 */
   __MFB(reg_r0_4, t__i32_0); /* line 4968 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4969 */
   __ADD_CYCLES(1);
} /* line 4969 */
  sim_icache_fetch(3535 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4971 */
} /* line 4971 */
  sim_icache_fetch(3536 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4973 */
} /* line 4973 */
  sim_icache_fetch(3538 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 4975 */
   __MTB(reg_b0_4, reg_r0_4); /* line 4976 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4977 */
  sim_icache_fetch(3541 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 4979 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4980 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 4981 */
   __ADD(reg_r0_9, reg_r0_33, (unsigned int) -16); /* line 4982 */
   __MFB(reg_r0_4, t__i32_0); /* line 4983 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4984 */
   __ADD_CYCLES(1);
} /* line 4984 */
  sim_icache_fetch(3549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4986 */
} /* line 4986 */
  sim_icache_fetch(3550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4988 */
} /* line 4988 */
  sim_icache_fetch(3552 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 4990 */
   __MTB(reg_b0_5, reg_r0_4); /* line 4991 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4992 */
  sim_icache_fetch(3555 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 4994 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4995 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 4996 */
   __ADD(reg_r0_10, reg_r0_32, (unsigned int) -16); /* line 4997 */
   __MFB(reg_r0_4, t__i32_0); /* line 4998 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4999 */
   __ADD_CYCLES(1);
} /* line 4999 */
  sim_icache_fetch(3563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5001 */
} /* line 5001 */
  sim_icache_fetch(3564 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5003 */
} /* line 5003 */
  sim_icache_fetch(3566 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 5005 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5006 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5007 */
  sim_icache_fetch(3569 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 5009 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5010 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 5011 */
   __ADD(reg_r0_11, reg_r0_31, (unsigned int) -16); /* line 5012 */
   __MFB(reg_r0_4, t__i32_0); /* line 5013 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5014 */
   __ADD_CYCLES(1);
} /* line 5014 */
  sim_icache_fetch(3577 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5016 */
} /* line 5016 */
  sim_icache_fetch(3578 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5018 */
} /* line 5018 */
  sim_icache_fetch(3580 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 5020 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5021 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5022 */
  sim_icache_fetch(3583 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5024 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5025 */
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 5026 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 5027 */
   __MFB(reg_r0_4, t__i32_0); /* line 5028 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5029 */
   __ADD_CYCLES(1);
} /* line 5029 */
  sim_icache_fetch(3591 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5031 */
} /* line 5031 */
  sim_icache_fetch(3592 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5033 */
} /* line 5033 */
  sim_icache_fetch(3594 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5035 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5036 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5037 */
  sim_icache_fetch(3597 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5039 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5040 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5041 */
   __ADD(reg_r0_13, reg_r0_29, (unsigned int) -16); /* line 5042 */
   __MFB(reg_r0_4, t__i32_0); /* line 5043 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5044 */
   __ADD_CYCLES(1);
} /* line 5044 */
  sim_icache_fetch(3605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5046 */
} /* line 5046 */
  sim_icache_fetch(3606 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5048 */
} /* line 5048 */
  sim_icache_fetch(3608 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5050 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5051 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5052 */
  sim_icache_fetch(3611 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5054 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5055 */
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 5056 */
   __ADD(reg_r0_14, reg_r0_28, (unsigned int) -16); /* line 5057 */
   __MFB(reg_r0_4, t__i32_0); /* line 5058 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5059 */
   __ADD_CYCLES(1);
} /* line 5059 */
  sim_icache_fetch(3619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5061 */
} /* line 5061 */
  sim_icache_fetch(3620 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5063 */
} /* line 5063 */
  sim_icache_fetch(3622 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5065 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5066 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5067 */
  sim_icache_fetch(3625 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5069 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5070 */
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5071 */
   __ADD(reg_r0_15, reg_r0_27, (unsigned int) -16); /* line 5072 */
   __MFB(reg_r0_4, t__i32_0); /* line 5073 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5074 */
   __ADD_CYCLES(1);
} /* line 5074 */
  sim_icache_fetch(3633 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5076 */
} /* line 5076 */
  sim_icache_fetch(3634 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5078 */
} /* line 5078 */
  sim_icache_fetch(3636 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5080 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5081 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5082 */
  sim_icache_fetch(3639 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5084 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5085 */
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5086 */
   __ADD(reg_r0_16, reg_r0_26, (unsigned int) -16); /* line 5087 */
   __MFB(reg_r0_4, t__i32_0); /* line 5088 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5089 */
   __ADD_CYCLES(1);
} /* line 5089 */
  sim_icache_fetch(3647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5091 */
} /* line 5091 */
  sim_icache_fetch(3648 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5093 */
} /* line 5093 */
  sim_icache_fetch(3650 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5095 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5096 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5097 */
  sim_icache_fetch(3653 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5099 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5100 */
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5101 */
   __ADD(reg_r0_17, reg_r0_25, (unsigned int) -16); /* line 5102 */
   __MFB(reg_r0_4, t__i32_0); /* line 5103 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5104 */
   __ADD_CYCLES(1);
} /* line 5104 */
  sim_icache_fetch(3661 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5106 */
} /* line 5106 */
  sim_icache_fetch(3662 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5108 */
} /* line 5108 */
  sim_icache_fetch(3664 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5110 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5111 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5112 */
  sim_icache_fetch(3667 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5114 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5115 */
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5116 */
   __ADD(reg_r0_18, reg_r0_24, (unsigned int) -16); /* line 5117 */
   __MFB(reg_r0_4, t__i32_0); /* line 5118 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5119 */
   __ADD_CYCLES(1);
} /* line 5119 */
  sim_icache_fetch(3675 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5121 */
} /* line 5121 */
  sim_icache_fetch(3676 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5123 */
} /* line 5123 */
  sim_icache_fetch(3678 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5125 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5126 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5127 */
  sim_icache_fetch(3681 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5129 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5130 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5131 */
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5132 */
   __MFB(reg_r0_4, t__i32_0); /* line 5133 */
} /* line 5133 */
  sim_icache_fetch(3688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_23, (unsigned int) -16); /* line 5135 */
} /* line 5135 */
  sim_icache_fetch(3689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5137 */
} /* line 5137 */
  sim_icache_fetch(3690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5139 */
} /* line 5139 */
  sim_icache_fetch(3692 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5141 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5142 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5143 */
  sim_icache_fetch(3695 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_5, reg_r0_3); /* line 5145 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5146 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5147 */
   __CMPLEU(reg_b0_7, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5148 */
   __MFB(reg_r0_22, t__i32_0); /* line 5149 */
} /* line 5149 */
  sim_icache_fetch(3702 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_20, reg_r0_37, (unsigned int) -16); /* line 5151 */
   __MOV(reg_r0_3, reg_r0_39); /* line 5152 */
} /* line 5152 */
  sim_icache_fetch(3704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5154 */
} /* line 5154 */
  sim_icache_fetch(3705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5156 */
} /* line 5156 */
  sim_icache_fetch(3707 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5158 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5159 */
  sim_icache_fetch(3709 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5161 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5162 */
   __CMPLEU(reg_b0_0, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5163 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5164 */
   __ADD_CYCLES(1);
} /* line 5164 */
  sim_icache_fetch(3715 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5166 */
} /* line 5166 */
  sim_icache_fetch(3716 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5168 */
} /* line 5168 */
  sim_icache_fetch(3718 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5170 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5171 */
  sim_icache_fetch(3720 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5173 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5174 */
   __CMPLEU(reg_b0_1, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5175 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5176 */
   __ADD_CYCLES(1);
} /* line 5176 */
  sim_icache_fetch(3726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5178 */
} /* line 5178 */
  sim_icache_fetch(3727 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5180 */
} /* line 5180 */
  sim_icache_fetch(3729 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5182 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5183 */
  sim_icache_fetch(3731 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5185 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5186 */
   __CMPLEU(reg_b0_2, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5187 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5188 */
   __ADD_CYCLES(1);
} /* line 5188 */
  sim_icache_fetch(3737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5190 */
} /* line 5190 */
  sim_icache_fetch(3738 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5192 */
} /* line 5192 */
  sim_icache_fetch(3740 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5194 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5195 */
  sim_icache_fetch(3742 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5197 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5198 */
   __CMPLEU(reg_b0_3, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5199 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5200 */
   __ADD_CYCLES(1);
} /* line 5200 */
  sim_icache_fetch(3748 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5202 */
} /* line 5202 */
  sim_icache_fetch(3749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5204 */
} /* line 5204 */
  sim_icache_fetch(3751 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5206 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5207 */
  sim_icache_fetch(3753 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5209 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5210 */
   __CMPLEU(reg_b0_4, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5211 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5212 */
   __ADD_CYCLES(1);
} /* line 5212 */
  sim_icache_fetch(3759 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5214 */
} /* line 5214 */
  sim_icache_fetch(3760 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5216 */
} /* line 5216 */
  sim_icache_fetch(3762 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5218 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5219 */
  sim_icache_fetch(3764 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5221 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5222 */
   __CMPLEU(reg_b0_5, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5223 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5224 */
   __ADD_CYCLES(1);
} /* line 5224 */
  sim_icache_fetch(3770 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5226 */
} /* line 5226 */
  sim_icache_fetch(3771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5228 */
} /* line 5228 */
  sim_icache_fetch(3773 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5230 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5231 */
  sim_icache_fetch(3775 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5233 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5234 */
   __CMPLEU(reg_b0_6, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5235 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5236 */
   __ADD_CYCLES(1);
} /* line 5236 */
  sim_icache_fetch(3781 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5238 */
} /* line 5238 */
  sim_icache_fetch(3782 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5240 */
} /* line 5240 */
  sim_icache_fetch(3784 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5242 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5243 */
  sim_icache_fetch(3786 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5245 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5246 */
   __MTB(reg_b0_7, reg_r0_22); /* line 5247 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5248 */
   __ADD_CYCLES(1);
} /* line 5248 */
  sim_icache_fetch(3791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5250 */
} /* line 5250 */
  sim_icache_fetch(3792 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5252 */
} /* line 5252 */
  sim_icache_fetch(3794 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5254 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5255 */
  sim_icache_fetch(3796 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5257 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5258 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5259 */
   __ADD_CYCLES(1);
} /* line 5259 */
  sim_icache_fetch(3800 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5261 */
} /* line 5261 */
  sim_icache_fetch(3801 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5263 */
} /* line 5263 */
  sim_icache_fetch(3803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5265 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5266 */
  sim_icache_fetch(3805 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5268 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5269 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5270 */
   __ADD_CYCLES(1);
} /* line 5270 */
  sim_icache_fetch(3809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5272 */
} /* line 5272 */
  sim_icache_fetch(3810 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5274 */
} /* line 5274 */
  sim_icache_fetch(3812 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5276 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5277 */
  sim_icache_fetch(3814 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5279 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5280 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5281 */
   __ADD_CYCLES(1);
} /* line 5281 */
  sim_icache_fetch(3818 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5283 */
} /* line 5283 */
  sim_icache_fetch(3819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5285 */
} /* line 5285 */
  sim_icache_fetch(3821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5287 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5288 */
  sim_icache_fetch(3823 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5290 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5291 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5292 */
   __ADD_CYCLES(1);
} /* line 5292 */
  sim_icache_fetch(3827 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5294 */
} /* line 5294 */
  sim_icache_fetch(3828 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5296 */
} /* line 5296 */
  sim_icache_fetch(3830 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5298 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5299 */
  sim_icache_fetch(3832 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5301 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5302 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5303 */
   __ADD_CYCLES(1);
} /* line 5303 */
  sim_icache_fetch(3836 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5305 */
} /* line 5305 */
  sim_icache_fetch(3837 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5307 */
} /* line 5307 */
  sim_icache_fetch(3839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5309 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5310 */
  sim_icache_fetch(3841 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5312 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5313 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5314 */
   __ADD_CYCLES(1);
} /* line 5314 */
  sim_icache_fetch(3845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5316 */
} /* line 5316 */
  sim_icache_fetch(3846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5318 */
} /* line 5318 */
  sim_icache_fetch(3848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5320 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5321 */
  sim_icache_fetch(3850 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5323 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5324 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5325 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5326 */
   __ADD_CYCLES(1);
} /* line 5326 */
  sim_icache_fetch(3855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5328 */
} /* line 5328 */
  sim_icache_fetch(3856 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5330 */
} /* line 5330 */
  sim_icache_fetch(3858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5332 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5334 */
  sim_icache_fetch(3860 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5336 */
l_L235X3: ;/* line 5339 */
__LABEL(l_L235X3);
  sim_icache_fetch(3861 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5340 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5341 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5342 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5343 */
l_L238X3: ;/* line 5346 */
__LABEL(l_L238X3);
  sim_icache_fetch(3867 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5347 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5348 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5349 */
} /* line 5349 */
  sim_icache_fetch(3872 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5351 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5352 */
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5353 */
l_L234X3: ;/* line 5356 */
__LABEL(l_L234X3);
  sim_icache_fetch(3876 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5357 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5358 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5359 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5360 */
l_L233X3: ;/* line 5363 */
__LABEL(l_L233X3);
  sim_icache_fetch(3882 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5364 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5365 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5366 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5367 */
l_L232X3: ;/* line 5370 */
__LABEL(l_L232X3);
  sim_icache_fetch(3888 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5371 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5372 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5373 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5374 */
l_L231X3: ;/* line 5377 */
__LABEL(l_L231X3);
  sim_icache_fetch(3894 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5378 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5379 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5380 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5381 */
l_L230X3: ;/* line 5384 */
__LABEL(l_L230X3);
  sim_icache_fetch(3900 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5385 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5386 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5387 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5388 */
l_L229X3: ;/* line 5391 */
__LABEL(l_L229X3);
  sim_icache_fetch(3906 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5392 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5393 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5394 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5395 */
l_L228X3: ;/* line 5398 */
__LABEL(l_L228X3);
  sim_icache_fetch(3912 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5399 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5400 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5401 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5402 */
l_L227X3: ;/* line 5405 */
__LABEL(l_L227X3);
  sim_icache_fetch(3918 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5406 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5407 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5408 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5409 */
l_L226X3: ;/* line 5412 */
__LABEL(l_L226X3);
  sim_icache_fetch(3924 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5413 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5414 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5415 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5416 */
l_L225X3: ;/* line 5419 */
__LABEL(l_L225X3);
  sim_icache_fetch(3930 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5420 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5421 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5422 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5423 */
l_L224X3: ;/* line 5426 */
__LABEL(l_L224X3);
  sim_icache_fetch(3936 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5427 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5428 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5429 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5430 */
l_L223X3: ;/* line 5433 */
__LABEL(l_L223X3);
  sim_icache_fetch(3942 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5434 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5435 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5436 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5437 */
l_L222X3: ;/* line 5440 */
__LABEL(l_L222X3);
  sim_icache_fetch(3948 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5441 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5442 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5443 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5444 */
l_L221X3: ;/* line 5447 */
__LABEL(l_L221X3);
  sim_icache_fetch(3954 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5448 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5449 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5450 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5451 */
l_L220X3: ;/* line 5454 */
__LABEL(l_L220X3);
  sim_icache_fetch(3960 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5455 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5456 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5457 */
} /* line 5457 */
l_L236X3: ;/* line 5459 */
__LABEL(l_L236X3);
  sim_icache_fetch(3965 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5459 */
  sim_icache_fetch(3966 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5461 */
} /* line 5461 */
  sim_icache_fetch(3967 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5463 */
l_L237X3: ;/* line 5465 */
__LABEL(l_L237X3);
  sim_icache_fetch(3968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5466 */
   __GOTO(l_L195X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L195X3;
} /* line 5467 */
l_L216X3: ;/* line 5470 */
__LABEL(l_L216X3);
  sim_icache_fetch(3970 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5471 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5472 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5473 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5474 */
l_L215X3: ;/* line 5477 */
__LABEL(l_L215X3);
  sim_icache_fetch(3974 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5478 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5479 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5480 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5481 */
l_L214X3: ;/* line 5484 */
__LABEL(l_L214X3);
  sim_icache_fetch(3978 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5485 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5486 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5487 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5488 */
l_L213X3: ;/* line 5491 */
__LABEL(l_L213X3);
  sim_icache_fetch(3982 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5492 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5493 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5494 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5495 */
l_L212X3: ;/* line 5498 */
__LABEL(l_L212X3);
  sim_icache_fetch(3986 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5499 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5500 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5501 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5502 */
l_L211X3: ;/* line 5505 */
__LABEL(l_L211X3);
  sim_icache_fetch(3990 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5506 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5507 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5508 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5509 */
l_L210X3: ;/* line 5512 */
__LABEL(l_L210X3);
  sim_icache_fetch(3994 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5513 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5514 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5515 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5516 */
l_L209X3: ;/* line 5519 */
__LABEL(l_L209X3);
  sim_icache_fetch(3998 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5520 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5521 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5522 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5523 */
l_L208X3: ;/* line 5526 */
__LABEL(l_L208X3);
  sim_icache_fetch(4002 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5527 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5528 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5529 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5530 */
l_L207X3: ;/* line 5533 */
__LABEL(l_L207X3);
  sim_icache_fetch(4006 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5534 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5535 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5536 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5537 */
l_L206X3: ;/* line 5540 */
__LABEL(l_L206X3);
  sim_icache_fetch(4010 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5541 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5542 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5543 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5544 */
l_L205X3: ;/* line 5547 */
__LABEL(l_L205X3);
  sim_icache_fetch(4014 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5548 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5549 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5550 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5551 */
l_L204X3: ;/* line 5554 */
__LABEL(l_L204X3);
  sim_icache_fetch(4018 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5555 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5556 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5557 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5558 */
l_L203X3: ;/* line 5561 */
__LABEL(l_L203X3);
  sim_icache_fetch(4022 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5562 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5563 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5564 */
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 5565 */
l_L202X3: ;/* line 5570 */
__LABEL(l_L202X3);
  sim_icache_fetch(4026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5571 */
} /* line 5571 */
l_L218X3: ;/* line 5573 */
__LABEL(l_L218X3);
  sim_icache_fetch(4027 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5574 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5575 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5576 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5577 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5578 */
} /* line 5578 */
  sim_icache_fetch(4033 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5580 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5581 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5582 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5583 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5584 */
} /* line 5584 */
  sim_icache_fetch(4038 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5586 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5587 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5588 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5589 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5590 */
} /* line 5590 */
  sim_icache_fetch(4043 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5592 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5593 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5594 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5595 */
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5596 */
l_L200X3: ;/* line 5599 */
__LABEL(l_L200X3);
  sim_icache_fetch(4048 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5600 */
   __GOTO(l_L201X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L201X3;
} /* line 5601 */
l_L196X3: ;/* line 5604 */
__LABEL(l_L196X3);
  sim_icache_fetch(4050 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5605 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5606 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5607 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5608 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5609 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5610 */
   __ADD_CYCLES(1);
} /* line 5610 */
  sim_icache_fetch(4056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5613 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 358: goto l_L192X3;
    case 359: goto l_L193X3;
    case 361: goto l_lr_260;
    case 362: goto l_L194X3;
    case 363: goto l_L195X3;
    case 365: goto l_lr_264;
    case 366: goto l_L198X3;
    case 367: goto l_L199X3;
    case 369: goto l_lr_268;
    case 370: goto l_L197X3;
    case 371: goto l_L201X3;
    case 372: goto l_L217X3;
    case 373: goto l_L219X3;
    case 374: goto l_L235X3;
    case 375: goto l_L238X3;
    case 376: goto l_L234X3;
    case 377: goto l_L233X3;
    case 378: goto l_L232X3;
    case 379: goto l_L231X3;
    case 380: goto l_L230X3;
    case 381: goto l_L229X3;
    case 382: goto l_L228X3;
    case 383: goto l_L227X3;
    case 384: goto l_L226X3;
    case 385: goto l_L225X3;
    case 386: goto l_L224X3;
    case 387: goto l_L223X3;
    case 388: goto l_L222X3;
    case 389: goto l_L221X3;
    case 390: goto l_L220X3;
    case 391: goto l_L236X3;
    case 392: goto l_L237X3;
    case 393: goto l_L216X3;
    case 394: goto l_L215X3;
    case 395: goto l_L214X3;
    case 396: goto l_L213X3;
    case 397: goto l_L212X3;
    case 398: goto l_L211X3;
    case 399: goto l_L210X3;
    case 400: goto l_L209X3;
    case 401: goto l_L208X3;
    case 402: goto l_L207X3;
    case 403: goto l_L206X3;
    case 404: goto l_L205X3;
    case 405: goto l_L204X3;
    case 406: goto l_L203X3;
    case 407: goto l_L202X3;
    case 408: goto l_L218X3;
    case 409: goto l_L200X3;
    case 410: goto l_L196X3;
    case 411:
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
  reg_l0_0 = (439 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4057 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5632 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5633 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5634 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5635 */
} /* line 5635 */
  sim_icache_fetch(4065 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5637 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5638 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5639 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5640 */
} /* line 5640 */
  sim_icache_fetch(4073 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5642 */
} /* line 5642 */
  sim_icache_fetch(4074 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_r0_11, reg_r0_7, reg_r0_8); /* line 5644 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5645 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5646 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5647 */
} /* line 5647 */
  sim_icache_fetch(4078 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5649 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_2); /* line 5650 */
} /* line 5650 */
  sim_icache_fetch(4080 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_2, reg_r0_4, reg_r0_11); /* line 5652 */
} /* line 5652 */
  sim_icache_fetch(4081 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5654 */
  sim_icache_fetch(4082 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5656 */
  sim_icache_fetch(4083 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5658 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5659 */
  sim_icache_fetch(4086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5661 */
} /* line 5661 */
l_L240X3: ;/* line 5664 */
__LABEL(l_L240X3);
  sim_icache_fetch(4088 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5665 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5666 */
   __MOV(reg_r0_5, 0); /* line 5667 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5668 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5669 */
   __ADD_CYCLES(1);
} /* line 5669 */
  sim_icache_fetch(4095 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5671 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5672 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5673 */
} /* line 5673 */
  sim_icache_fetch(4098 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5675 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L242X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5676 */
l_L243X3: ;/* line 5679 */
__LABEL(l_L243X3);
  sim_icache_fetch(4100 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5680 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5681 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5682 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5683 */
} /* line 5683 */
  sim_icache_fetch(4106 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5685 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5686 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5687 */
  sim_icache_fetch(4109 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5689 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5690 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5691 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5692 */
} /* line 5692 */
  sim_icache_fetch(4113 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5694 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5695 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5696 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5697 */
} /* line 5697 */
  sim_icache_fetch(4118 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5699 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5700 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5701 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5702 */
  sim_icache_fetch(4123 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5704 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5705 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5706 */
} /* line 5706 */
  sim_icache_fetch(4127 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5708 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5709 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5710 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5711 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5712 */
} /* line 5712 */
  sim_icache_fetch(4133 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5714 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5715 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5716 */
} /* line 5716 */
  sim_icache_fetch(4136 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5718 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5719 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5720 */
} /* line 5720 */
l_L246X3: ;/* line 5722 */
__LABEL(l_L246X3);
  sim_icache_fetch(4139 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5723 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5724 */
} /* line 5724 */
  sim_icache_fetch(4142 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5726 */
} /* line 5726 */
  sim_icache_fetch(4143 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5728 */
} /* line 5728 */
  sim_icache_fetch(4144 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5730 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5731 */
  sim_icache_fetch(4146 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5733 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5734 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5735 */
  sim_icache_fetch(4149 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5737 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5738 */
  sim_icache_fetch(4152 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5740 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5741 */
} /* line 5741 */
  sim_icache_fetch(4156 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5743 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5744 */
} /* line 5744 */
  sim_icache_fetch(4159 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5746 */
} /* line 5746 */
  sim_icache_fetch(4160 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5748 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5749 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5750 */
} /* line 5750 */
l_L249X3: ;/* line 5752 */
__LABEL(l_L249X3);
  sim_icache_fetch(4163 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5753 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5754 */
} /* line 5754 */
  sim_icache_fetch(4166 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5756 */
} /* line 5756 */
  sim_icache_fetch(4167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5758 */
} /* line 5758 */
  sim_icache_fetch(4168 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5760 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5761 */
  sim_icache_fetch(4170 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5763 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5764 */
  sim_icache_fetch(4172 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5766 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5767 */
  sim_icache_fetch(4175 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5769 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5770 */
} /* line 5770 */
  sim_icache_fetch(4179 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5772 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5773 */
} /* line 5773 */
  sim_icache_fetch(4182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5775 */
} /* line 5775 */
  sim_icache_fetch(4183 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5777 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5778 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5779 */
} /* line 5779 */
l_L251X3: ;/* line 5781 */
__LABEL(l_L251X3);
  sim_icache_fetch(4186 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5782 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5783 */
} /* line 5783 */
  sim_icache_fetch(4189 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5785 */
} /* line 5785 */
  sim_icache_fetch(4190 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5787 */
  sim_icache_fetch(4191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5789 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5790 */
  sim_icache_fetch(4193 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5792 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5793 */
  sim_icache_fetch(4196 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5795 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5796 */
} /* line 5796 */
  sim_icache_fetch(4200 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5798 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5799 */
} /* line 5799 */
  sim_icache_fetch(4203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5801 */
} /* line 5801 */
  sim_icache_fetch(4204 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5803 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5804 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5805 */
} /* line 5805 */
l_L253X3: ;/* line 5807 */
__LABEL(l_L253X3);
  sim_icache_fetch(4207 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5808 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5809 */
} /* line 5809 */
  sim_icache_fetch(4210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5811 */
} /* line 5811 */
  sim_icache_fetch(4211 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5813 */
  sim_icache_fetch(4212 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5815 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5816 */
  sim_icache_fetch(4214 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5818 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5819 */
  sim_icache_fetch(4217 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5821 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5822 */
} /* line 5822 */
  sim_icache_fetch(4221 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5824 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5825 */
} /* line 5825 */
  sim_icache_fetch(4224 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5827 */
} /* line 5827 */
  sim_icache_fetch(4225 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5829 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5830 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5831 */
} /* line 5831 */
l_L255X3: ;/* line 5833 */
__LABEL(l_L255X3);
  sim_icache_fetch(4228 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5834 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5835 */
} /* line 5835 */
  sim_icache_fetch(4231 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5837 */
} /* line 5837 */
  sim_icache_fetch(4232 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5839 */
  sim_icache_fetch(4233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5841 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5842 */
  sim_icache_fetch(4235 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5844 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L256X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5845 */
  sim_icache_fetch(4238 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5847 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5848 */
} /* line 5848 */
  sim_icache_fetch(4242 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5850 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5851 */
} /* line 5851 */
  sim_icache_fetch(4245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5853 */
} /* line 5853 */
  sim_icache_fetch(4246 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5855 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5856 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5857 */
} /* line 5857 */
l_L257X3: ;/* line 5859 */
__LABEL(l_L257X3);
  sim_icache_fetch(4249 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5860 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5861 */
} /* line 5861 */
  sim_icache_fetch(4252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5863 */
} /* line 5863 */
  sim_icache_fetch(4253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5865 */
  sim_icache_fetch(4254 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5867 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5868 */
  sim_icache_fetch(4256 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5870 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L258X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5871 */
  sim_icache_fetch(4259 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5873 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5874 */
} /* line 5874 */
  sim_icache_fetch(4263 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5876 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5877 */
} /* line 5877 */
  sim_icache_fetch(4266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5879 */
} /* line 5879 */
  sim_icache_fetch(4267 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5881 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5882 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5883 */
} /* line 5883 */
l_L259X3: ;/* line 5885 */
__LABEL(l_L259X3);
  sim_icache_fetch(4270 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5886 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5887 */
} /* line 5887 */
  sim_icache_fetch(4273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5889 */
} /* line 5889 */
  sim_icache_fetch(4274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5891 */
  sim_icache_fetch(4275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5893 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5894 */
  sim_icache_fetch(4277 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5896 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L260X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5897 */
  sim_icache_fetch(4280 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5899 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5900 */
} /* line 5900 */
  sim_icache_fetch(4284 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5902 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5903 */
} /* line 5903 */
  sim_icache_fetch(4287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5905 */
} /* line 5905 */
  sim_icache_fetch(4288 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5907 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5908 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5909 */
} /* line 5909 */
l_L261X3: ;/* line 5911 */
__LABEL(l_L261X3);
  sim_icache_fetch(4291 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5912 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5913 */
} /* line 5913 */
  sim_icache_fetch(4294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5915 */
} /* line 5915 */
  sim_icache_fetch(4295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5917 */
  sim_icache_fetch(4296 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5919 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5920 */
  sim_icache_fetch(4298 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5922 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5923 */
  sim_icache_fetch(4301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5925 */
} /* line 5925 */
  sim_icache_fetch(4303 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5927 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5928 */
   __ADD_CYCLES(1);
} /* line 5928 */
  sim_icache_fetch(4305 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5930 */
} /* line 5930 */
l_L263X3: ;/* line 5932 */
__LABEL(l_L263X3);
  sim_icache_fetch(4306 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5933 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5934 */
} /* line 5934 */
  sim_icache_fetch(4309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5936 */
} /* line 5936 */
  sim_icache_fetch(4310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5938 */
  sim_icache_fetch(4311 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5940 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5941 */
l_L247X3: ;/* line 5944 */
__LABEL(l_L247X3);
  sim_icache_fetch(4313 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5945 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5946 */
   __GOTO(l_L264X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L264X3;
} /* line 5947 */
l_L265X3: ;/* line 5950 */
__LABEL(l_L265X3);
  sim_icache_fetch(4316 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5951 */
   __MOV(reg_r0_7, 0); /* line 5952 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5953 */
} /* line 5953 */
  sim_icache_fetch(4320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5955 */
} /* line 5955 */
  sim_icache_fetch(4321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5957 */
} /* line 5957 */
l_L239X3: ;/* line 5960 */
__LABEL(l_L239X3);
  sim_icache_fetch(4322 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5961 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5962 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5963 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5964 */
} /* line 5964 */
  sim_icache_fetch(4328 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5966 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5967 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5968 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5969 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5970 */
} /* line 5970 */
  sim_icache_fetch(4336 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 5972 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 5973 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 5974 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 5975 */
} /* line 5975 */
  sim_icache_fetch(4340 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 5977 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 5978 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 5979 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 5980 */
} /* line 5980 */
  sim_icache_fetch(4345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 5982 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 5983 */
} /* line 5983 */
  sim_icache_fetch(4347 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5985 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 5986 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 5987 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 5988 */
} /* line 5988 */
  sim_icache_fetch(4351 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 5990 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5991 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 5992 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5993 */
   __ADD_CYCLES(1);
} /* line 5993 */
  sim_icache_fetch(4356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 5995 */
} /* line 5995 */
  sim_icache_fetch(4357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 5997 */
} /* line 5997 */
  sim_icache_fetch(4358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 6000 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6001 */
l_L262X3: ;/* line 6004 */
__LABEL(l_L262X3);
  sim_icache_fetch(4360 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6005 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 6006 */
l_L244X3: ;/* line 6009 */
__LABEL(l_L244X3);
  sim_icache_fetch(4362 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 6010 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6011 */
} /* line 6011 */
l_L264X3: ;/* line 6013 */
__LABEL(l_L264X3);
  sim_icache_fetch(4364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 6014 */
} /* line 6014 */
  sim_icache_fetch(4365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L265X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6016 */
  sim_icache_fetch(4366 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 6019 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 6020 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6021 */
l_L260X3: ;/* line 6024 */
__LABEL(l_L260X3);
  sim_icache_fetch(4371 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6025 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6026 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6027 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6028 */
   __ADD_CYCLES(1);
} /* line 6028 */
  sim_icache_fetch(4377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6030 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6031 */
} /* line 6031 */
  sim_icache_fetch(4379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6033 */
   __GOTO(l_L261X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L261X3;
} /* line 6034 */
l_L258X3: ;/* line 6037 */
__LABEL(l_L258X3);
  sim_icache_fetch(4381 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6038 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6039 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6040 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6041 */
   __ADD_CYCLES(1);
} /* line 6041 */
  sim_icache_fetch(4387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6043 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6044 */
} /* line 6044 */
  sim_icache_fetch(4389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6046 */
   __GOTO(l_L259X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L259X3;
} /* line 6047 */
l_L256X3: ;/* line 6050 */
__LABEL(l_L256X3);
  sim_icache_fetch(4391 + t_thisfile.offset, 6);
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
  sim_icache_fetch(4397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6056 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6057 */
} /* line 6057 */
  sim_icache_fetch(4399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6059 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 6060 */
l_L254X3: ;/* line 6063 */
__LABEL(l_L254X3);
  sim_icache_fetch(4401 + t_thisfile.offset, 6);
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
  sim_icache_fetch(4407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6069 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6070 */
} /* line 6070 */
  sim_icache_fetch(4409 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6072 */
   __GOTO(l_L255X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L255X3;
} /* line 6073 */
l_L252X3: ;/* line 6076 */
__LABEL(l_L252X3);
  sim_icache_fetch(4411 + t_thisfile.offset, 6);
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
  sim_icache_fetch(4417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6082 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6083 */
} /* line 6083 */
  sim_icache_fetch(4419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6085 */
   __GOTO(l_L253X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L253X3;
} /* line 6086 */
l_L250X3: ;/* line 6089 */
__LABEL(l_L250X3);
  sim_icache_fetch(4421 + t_thisfile.offset, 6);
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
  sim_icache_fetch(4427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6095 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6096 */
} /* line 6096 */
  sim_icache_fetch(4429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6098 */
   __GOTO(l_L251X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L251X3;
} /* line 6099 */
l_L248X3: ;/* line 6102 */
__LABEL(l_L248X3);
  sim_icache_fetch(4431 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6103 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6104 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6105 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6106 */
   __ADD_CYCLES(1);
} /* line 6106 */
  sim_icache_fetch(4437 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6108 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6109 */
} /* line 6109 */
  sim_icache_fetch(4439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6111 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 6112 */
l_L245X3: ;/* line 6115 */
__LABEL(l_L245X3);
  sim_icache_fetch(4441 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6116 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6117 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6118 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6119 */
} /* line 6119 */
  sim_icache_fetch(4446 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6121 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6122 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6123 */
} /* line 6123 */
  sim_icache_fetch(4449 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6125 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6126 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6127 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6128 */
} /* line 6128 */
  sim_icache_fetch(4453 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6130 */
   __GOTO(l_L246X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L246X3;
} /* line 6131 */
l_L242X3: ;/* line 6134 */
__LABEL(l_L242X3);
  sim_icache_fetch(4455 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6135 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6136 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6137 */
} /* line 6137 */
  sim_icache_fetch(4460 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6139 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6140 */
} /* line 6140 */
  sim_icache_fetch(4464 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6142 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6143 */
   __ADD_CYCLES(1);
} /* line 6143 */
  sim_icache_fetch(4467 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6145 */
} /* line 6145 */
  sim_icache_fetch(4468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6147 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 6148 */
l_L241X3: ;/* line 6151 */
__LABEL(l_L241X3);
  sim_icache_fetch(4470 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6152 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6153 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6154 */
   __ADD_CYCLES(1);
} /* line 6154 */
  sim_icache_fetch(4474 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6156 */
} /* line 6156 */
  sim_icache_fetch(4475 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6158 */
} /* line 6158 */
  sim_icache_fetch(4476 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6160 */
   __GOTO(l_L240X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L240X3;
} /* line 6161 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 412: goto l_L240X3;
    case 413: goto l_L243X3;
    case 414: goto l_L246X3;
    case 415: goto l_L249X3;
    case 416: goto l_L251X3;
    case 417: goto l_L253X3;
    case 418: goto l_L255X3;
    case 419: goto l_L257X3;
    case 420: goto l_L259X3;
    case 421: goto l_L261X3;
    case 422: goto l_L263X3;
    case 423: goto l_L247X3;
    case 424: goto l_L265X3;
    case 425: goto l_L239X3;
    case 426: goto l_L262X3;
    case 427: goto l_L244X3;
    case 428: goto l_L264X3;
    case 429: goto l_L260X3;
    case 430: goto l_L258X3;
    case 431: goto l_L256X3;
    case 432: goto l_L254X3;
    case 433: goto l_L252X3;
    case 434: goto l_L250X3;
    case 435: goto l_L248X3;
    case 436: goto l_L245X3;
    case 437: goto l_L242X3;
    case 438: goto l_L241X3;
    case 439:
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
  reg_l0_0 = (442 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4479 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6183 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6184 */
} /* line 6184 */
		 /* line 6185 */
  sim_icache_fetch(4482 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6188 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (442 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6188 */
l_lr_340: ;/* line 6188 */
__LABEL(l_lr_340);
  sim_icache_fetch(4485 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6190 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6191 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6192 */
   __ADD_CYCLES(1);
} /* line 6192 */
  sim_icache_fetch(4488 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6195 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 441: goto l_lr_340;
    case 442:
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
  reg_l0_0 = (444 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4489 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6241 */
   __MOV(reg_r0_3, 0); /* line 6242 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6243 */
   __ADD_CYCLES(1);
} /* line 6243 */
  sim_icache_fetch(4493 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6245 */
} /* line 6245 */
  sim_icache_fetch(4494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L266X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6247 */
  sim_icache_fetch(4495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6250 */
l_L266X3: ;/* line 6253 */
__LABEL(l_L266X3);
  sim_icache_fetch(4496 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6256 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6256 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 443: goto l_L266X3;
    case 444:
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
  reg_l0_0 = (445 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6272 */
} /* line 6272 */
  sim_icache_fetch(4499 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6275 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 445:
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
  reg_l0_0 = (449 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4500 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6290 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6291 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6292 */
} /* line 6292 */
  sim_icache_fetch(4505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6294 */
} /* line 6294 */
  sim_icache_fetch(4506 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6296 */
} /* line 6296 */
  sim_icache_fetch(4507 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L267X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6298 */
		 /* line 6299 */
  sim_icache_fetch(4508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (449 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6301 */
l_lr_346: ;/* line 6301 */
__LABEL(l_lr_346);
l_L267X3: ;/* line 6303 */
__LABEL(l_L267X3);
  sim_icache_fetch(4510 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6304 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6305 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6306 */
   __ADD_CYCLES(1);
} /* line 6306 */
  sim_icache_fetch(4513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6309 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 447: goto l_lr_346;
    case 448: goto l_L267X3;
    case 449:
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
  reg_l0_0 = (462 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4514 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6355 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6356 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6357 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6358 */
} /* line 6358 */
  sim_icache_fetch(4521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6360 */
} /* line 6360 */
  sim_icache_fetch(4522 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6362 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6363 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6364 */
} /* line 6364 */
  sim_icache_fetch(4527 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6366 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6367 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6368 */
  sim_icache_fetch(4531 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L269X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6370 */
l_L270X3: ;/* line 6373 */
__LABEL(l_L270X3);
  sim_icache_fetch(4532 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6374 */
   __MOV(reg_r0_3, 0); /* line 6375 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6376 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6377 */
   __ADD_CYCLES(1);
} /* line 6377 */
  sim_icache_fetch(4537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6379 */
} /* line 6379 */
  sim_icache_fetch(4538 + t_thisfile.offset, 1);
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
} /* line 6381 */
  sim_icache_fetch(4539 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6384 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6385 */
l_L271X3: ;/* line 6388 */
__LABEL(l_L271X3);
  sim_icache_fetch(4542 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6389 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6390 */
} /* line 6390 */
		 /* line 6391 */
  sim_icache_fetch(4546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (462 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6393 */
l_lr_352: ;/* line 6393 */
__LABEL(l_lr_352);
  sim_icache_fetch(4548 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6395 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6396 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6397 */
} /* line 6397 */
		 /* line 6398 */
  sim_icache_fetch(4553 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6400 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6401 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (462 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6402 */
l_lr_354: ;/* line 6402 */
__LABEL(l_lr_354);
  sim_icache_fetch(4559 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6404 */
   __MOV(reg_r0_3, 0); /* line 6405 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6406 */
   __ADD_CYCLES(1);
} /* line 6406 */
  sim_icache_fetch(4562 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6409 */
l_L269X3: ;/* line 6412 */
__LABEL(l_L269X3);
  sim_icache_fetch(4563 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6413 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6414 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6415 */
   __ADD_CYCLES(1);
} /* line 6415 */
		 /* line 6416 */
  sim_icache_fetch(4567 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6419 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (462 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6419 */
l_lr_357: ;/* line 6419 */
__LABEL(l_lr_357);
  sim_icache_fetch(4570 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6421 */
   __GOTO(l_L270X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L270X3;
} /* line 6422 */
l_L268X3: ;/* line 6425 */
__LABEL(l_L268X3);
  sim_icache_fetch(4572 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6426 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6427 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6428 */
   __ADD_CYCLES(1);
} /* line 6428 */
		 /* line 6429 */
  sim_icache_fetch(4577 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6431 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (462 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6432 */
l_lr_360: ;/* line 6432 */
__LABEL(l_lr_360);
  sim_icache_fetch(4580 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6434 */
   __GOTO(l_L270X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L270X3;
} /* line 6435 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 450: goto l_L270X3;
    case 451: goto l_L271X3;
    case 453: goto l_lr_352;
    case 455: goto l_lr_354;
    case 456: goto l_L269X3;
    case 458: goto l_lr_357;
    case 459: goto l_L268X3;
    case 461: goto l_lr_360;
    case 462:
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
  reg_l0_0 = (480 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4582 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6454 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6455 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6456 */
} /* line 6456 */
  sim_icache_fetch(4586 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6458 */
} /* line 6458 */
l_L272X3: ;/* line 6461 */
__LABEL(l_L272X3);
  sim_icache_fetch(4587 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, reg_r0_2); /* line 6462 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6463 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6464 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6465 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6466 */
} /* line 6466 */
  sim_icache_fetch(4592 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6468 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6469 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6470 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6471 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6472 */
} /* line 6472 */
  sim_icache_fetch(4597 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6474 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6475 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6476 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6477 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6478 */
} /* line 6478 */
  sim_icache_fetch(4602 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6480 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6481 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6482 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6483 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6484 */
} /* line 6484 */
  sim_icache_fetch(4607 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6486 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6487 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6488 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6489 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6490 */
} /* line 6490 */
  sim_icache_fetch(4612 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6492 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6493 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L273X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6494 */
  sim_icache_fetch(4615 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6496 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6497 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6498 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6499 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6500 */
} /* line 6500 */
  sim_icache_fetch(4620 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6502 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6503 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6504 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6506 */
} /* line 6506 */
  sim_icache_fetch(4625 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6508 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6509 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6510 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6511 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6512 */
} /* line 6512 */
  sim_icache_fetch(4630 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6514 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6515 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6516 */
  sim_icache_fetch(4633 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6518 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6519 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6520 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6521 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6522 */
} /* line 6522 */
  sim_icache_fetch(4638 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6525 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6527 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6528 */
} /* line 6528 */
  sim_icache_fetch(4643 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6531 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6532 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6533 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6534 */
} /* line 6534 */
  sim_icache_fetch(4648 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6536 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6537 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L275X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6538 */
  sim_icache_fetch(4651 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6540 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6541 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6542 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6543 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6544 */
} /* line 6544 */
  sim_icache_fetch(4656 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6546 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6547 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6548 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6549 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6550 */
} /* line 6550 */
  sim_icache_fetch(4661 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6552 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6553 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6554 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6555 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6556 */
} /* line 6556 */
  sim_icache_fetch(4666 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6558 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6559 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L276X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6560 */
  sim_icache_fetch(4669 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6562 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6564 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6565 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6566 */
} /* line 6566 */
  sim_icache_fetch(4674 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6568 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6569 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6570 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6571 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6572 */
} /* line 6572 */
  sim_icache_fetch(4679 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6574 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6575 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6576 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6577 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6578 */
} /* line 6578 */
  sim_icache_fetch(4684 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6580 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6581 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6582 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L277X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6583 */
  sim_icache_fetch(4688 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6588 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6589 */
} /* line 6589 */
  sim_icache_fetch(4698 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6591 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6592 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6593 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6594 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6595 */
} /* line 6595 */
  sim_icache_fetch(4708 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6597 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6600 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6601 */
} /* line 6601 */
  sim_icache_fetch(4718 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6603 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L278X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6604 */
  sim_icache_fetch(4721 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6606 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6608 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6610 */
} /* line 6610 */
  sim_icache_fetch(4731 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6612 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6613 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6614 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6615 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6616 */
} /* line 6616 */
  sim_icache_fetch(4741 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6620 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6621 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6622 */
} /* line 6622 */
  sim_icache_fetch(4751 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6624 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6625 */
  sim_icache_fetch(4754 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6627 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6628 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6629 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6630 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6631 */
} /* line 6631 */
  sim_icache_fetch(4764 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6633 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6634 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6635 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6636 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6637 */
} /* line 6637 */
  sim_icache_fetch(4774 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6639 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6640 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6641 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6642 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6643 */
} /* line 6643 */
  sim_icache_fetch(4784 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6645 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6646 */
  sim_icache_fetch(4787 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6648 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6651 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6652 */
} /* line 6652 */
  sim_icache_fetch(4797 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6654 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6655 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6656 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6658 */
} /* line 6658 */
  sim_icache_fetch(4807 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6660 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6661 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6662 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6664 */
} /* line 6664 */
  sim_icache_fetch(4817 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6666 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6667 */
  sim_icache_fetch(4820 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6669 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6670 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6671 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6672 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6673 */
} /* line 6673 */
  sim_icache_fetch(4830 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6675 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6676 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6677 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6678 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6679 */
} /* line 6679 */
  sim_icache_fetch(4840 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6681 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6682 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6683 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6684 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6685 */
} /* line 6685 */
  sim_icache_fetch(4850 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6687 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6688 */
  sim_icache_fetch(4853 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6690 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6691 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6692 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6693 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6694 */
} /* line 6694 */
  sim_icache_fetch(4863 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6696 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6697 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6698 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6699 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6700 */
} /* line 6700 */
  sim_icache_fetch(4873 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6702 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6703 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6704 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6705 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6706 */
} /* line 6706 */
  sim_icache_fetch(4883 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6708 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6709 */
  sim_icache_fetch(4886 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6711 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6712 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6713 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6714 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6715 */
} /* line 6715 */
  sim_icache_fetch(4896 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6717 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6718 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6719 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6720 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6721 */
} /* line 6721 */
  sim_icache_fetch(4906 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6723 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6724 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6725 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6726 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6727 */
} /* line 6727 */
  sim_icache_fetch(4916 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6729 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6730 */
  sim_icache_fetch(4919 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6732 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6733 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6734 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6735 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6736 */
} /* line 6736 */
  sim_icache_fetch(4928 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6738 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6739 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6740 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6741 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6742 */
} /* line 6742 */
  sim_icache_fetch(4937 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6744 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6745 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6746 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6747 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6748 */
} /* line 6748 */
  sim_icache_fetch(4947 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6750 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6751 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6752 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6753 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6754 */
} /* line 6754 */
  sim_icache_fetch(4957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6757 */
  sim_icache_fetch(4958 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L272X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L272X3;
} /* line 6759 */
l_L285X3: ;/* line 6762 */
__LABEL(l_L285X3);
  sim_icache_fetch(4959 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6763 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6764 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6765 */
l_L287X3: ;/* line 6768 */
__LABEL(l_L287X3);
  sim_icache_fetch(4963 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6769 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6770 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6771 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6772 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6773 */
} /* line 6773 */
  sim_icache_fetch(4968 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 4); /* line 6775 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 5); /* line 6776 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 6); /* line 6777 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 7); /* line 6778 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6779 */
  sim_icache_fetch(4973 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6781 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 8); /* line 6782 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6783 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6784 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6785 */
  sim_icache_fetch(4978 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6787 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6788 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6789 */
  sim_icache_fetch(4981 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6791 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6792 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6793 */
  sim_icache_fetch(4984 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6795 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6796 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6797 */
  sim_icache_fetch(4987 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6799 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 6800 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6801 */
  sim_icache_fetch(4990 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6803 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 13); /* line 6804 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6805 */
  sim_icache_fetch(4993 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6807 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 14); /* line 6808 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6809 */
  sim_icache_fetch(4996 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6811 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 15); /* line 6812 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6813 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6814 */
  sim_icache_fetch(5000 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6816 */
   __CMPGT(reg_b0_7, reg_r0_5, 0); /* line 6817 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6818 */
  sim_icache_fetch(5003 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6820 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6821 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6822 */
  sim_icache_fetch(5006 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6824 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6825 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6826 */
  sim_icache_fetch(5009 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6828 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6829 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6830 */
  sim_icache_fetch(5012 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6832 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 4); /* line 6833 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6834 */
  sim_icache_fetch(5015 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6836 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 6837 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6838 */
  sim_icache_fetch(5018 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6840 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 6841 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6842 */
  sim_icache_fetch(5021 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6844 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 6845 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6846 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6847 */
  sim_icache_fetch(5025 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6849 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 6850 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6851 */
  sim_icache_fetch(5028 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6853 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6854 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6855 */
  sim_icache_fetch(5031 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6857 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6858 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6859 */
  sim_icache_fetch(5034 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6861 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6862 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6863 */
  sim_icache_fetch(5037 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6865 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 12); /* line 6866 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6867 */
  sim_icache_fetch(5040 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6869 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 6870 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6871 */
  sim_icache_fetch(5043 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6873 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 6874 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6875 */
  sim_icache_fetch(5046 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6877 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 6878 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6879 */
  sim_icache_fetch(5049 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6881 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6882 */
  sim_icache_fetch(5051 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6884 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6885 */
  sim_icache_fetch(5053 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6887 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6888 */
  sim_icache_fetch(5055 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6890 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6891 */
  sim_icache_fetch(5057 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6893 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6894 */
  sim_icache_fetch(5059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6896 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6897 */
  sim_icache_fetch(5061 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6899 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6900 */
  sim_icache_fetch(5063 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6902 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 6903 */
l_L288X3: ;/* line 6906 */
__LABEL(l_L288X3);
  sim_icache_fetch(5065 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6908 */
l_L284X3: ;/* line 6911 */
__LABEL(l_L284X3);
  sim_icache_fetch(5066 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6912 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6913 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6914 */
l_L283X3: ;/* line 6917 */
__LABEL(l_L283X3);
  sim_icache_fetch(5070 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6918 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6919 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6920 */
l_L282X3: ;/* line 6923 */
__LABEL(l_L282X3);
  sim_icache_fetch(5074 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6924 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6925 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6926 */
l_L281X3: ;/* line 6929 */
__LABEL(l_L281X3);
  sim_icache_fetch(5078 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6930 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6931 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6932 */
l_L280X3: ;/* line 6935 */
__LABEL(l_L280X3);
  sim_icache_fetch(5082 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6936 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6937 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6938 */
l_L279X3: ;/* line 6941 */
__LABEL(l_L279X3);
  sim_icache_fetch(5086 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6942 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6943 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6944 */
l_L278X3: ;/* line 6947 */
__LABEL(l_L278X3);
  sim_icache_fetch(5090 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6948 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6949 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6950 */
l_L277X3: ;/* line 6953 */
__LABEL(l_L277X3);
  sim_icache_fetch(5094 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6954 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6955 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6956 */
l_L276X3: ;/* line 6959 */
__LABEL(l_L276X3);
  sim_icache_fetch(5098 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6960 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6961 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6962 */
l_L275X3: ;/* line 6965 */
__LABEL(l_L275X3);
  sim_icache_fetch(5101 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6966 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6967 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6968 */
l_L274X3: ;/* line 6971 */
__LABEL(l_L274X3);
  sim_icache_fetch(5104 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6972 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6973 */
   __GOTO(l_L286X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L286X3;
} /* line 6974 */
l_L273X3: ;/* line 6977 */
__LABEL(l_L273X3);
  sim_icache_fetch(5107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6978 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6979 */
} /* line 6979 */
l_L286X3: ;/* line 6981 */
__LABEL(l_L286X3);
  sim_icache_fetch(5109 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6982 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6983 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 6984 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 463: goto l_L272X3;
    case 464: goto l_L285X3;
    case 465: goto l_L287X3;
    case 466: goto l_L288X3;
    case 467: goto l_L284X3;
    case 468: goto l_L283X3;
    case 469: goto l_L282X3;
    case 470: goto l_L281X3;
    case 471: goto l_L280X3;
    case 472: goto l_L279X3;
    case 473: goto l_L278X3;
    case 474: goto l_L277X3;
    case 475: goto l_L276X3;
    case 476: goto l_L275X3;
    case 477: goto l_L274X3;
    case 478: goto l_L273X3;
    case 479: goto l_L286X3;
    case 480:
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
  reg_l0_0 = (481 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7000 */
} /* line 7000 */
  sim_icache_fetch(5113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7003 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 481:
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
  reg_l0_0 = (482 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5114 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7019 */
} /* line 7019 */
  sim_icache_fetch(5115 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7022 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 482:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 5120, 0, 0, 0, 2};

