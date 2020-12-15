/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/17_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_15137Xoffset[1];
unsigned int compress_15137Xbuf[3];
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
unsigned int compress_15137XBuf[216]; 
unsigned int compress_15137Xrcs_ident[6]; 
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

unsigned int compress_15137XBuf[216] = { 
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

unsigned int compress_15137Xrcs_ident[6] = { 
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
   __MOV(reg_r0_5, (unsigned int) compress_15137XBuf); /* line 35 */
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

  sim_icache_fetch(44 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 177 */
   __SXTB(reg_r0_4, reg_r0_4); /* line 178 */
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 179 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 180 */
   __ADD(reg_r0_34, reg_r0_3, (unsigned int) 15); /* line 181 */
   __ADD(reg_r0_32, reg_r0_3, (unsigned int) 14); /* line 182 */
   __ADD(reg_r0_30, reg_r0_3, (unsigned int) 13); /* line 183 */
   __ADD(reg_r0_28, reg_r0_3, (unsigned int) 12); /* line 184 */
   __ADD(reg_r0_26, reg_r0_3, (unsigned int) 11); /* line 185 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 10); /* line 186 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 9); /* line 187 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 8); /* line 188 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 7); /* line 189 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 6); /* line 190 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 191 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 192 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 193 */
} /* line 193 */
  sim_icache_fetch(61 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_5, 0); /* line 195 */
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
  sim_icache_fetch(69 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
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
} /* line 222 */
  sim_icache_fetch(86 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(16);
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
   __ADD(reg_r0_50, reg_r0_34, (unsigned int) 16); /* line 237 */
   __ADD(reg_r0_51, reg_r0_2, (unsigned int) 16); /* line 238 */
   __LDBs(reg_r0_52, mem_trace_ld(reg_r0_36,0,1)); /* line 239 */
} /* line 239 */
  sim_icache_fetch(102 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 241 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 242 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 243 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 244 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 245 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 246 */
   __CMPNE(reg_b0_6, reg_r0_11, 0); /* line 247 */
   __CMPEQ(reg_b0_7, reg_r0_11, reg_r0_4); /* line 248 */
   __LDBs(reg_r0_3, mem_trace_ld(reg_r0_51,0,1)); /* line 249 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_49,0,1)); /* line 250 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_48,0,1)); /* line 251 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_47,0,1)); /* line 252 */
   __LDBs(reg_r0_53, mem_trace_ld(reg_r0_46,0,1)); /* line 253 */
   __LDBs(reg_r0_54, mem_trace_ld(reg_r0_45,0,1)); /* line 254 */
   __LDBs(reg_r0_55, mem_trace_ld(reg_r0_44,0,1)); /* line 255 */
   __LDBs(reg_r0_56, mem_trace_ld(reg_r0_43,0,1)); /* line 256 */
   __LDBs(reg_r0_57, mem_trace_ld(reg_r0_42,0,1)); /* line 257 */
} /* line 257 */
  sim_icache_fetch(119 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SLCT(reg_r0_2, reg_b0_1, reg_r0_2, reg_r0_5); /* line 259 */
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 260 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 261 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_41,0,1)); /* line 262 */
   __LDBs(reg_r0_58, mem_trace_ld(reg_r0_40,0,1)); /* line 263 */
   __LDBs(reg_r0_59, mem_trace_ld(reg_r0_39,0,1)); /* line 264 */
   __LDBs(reg_r0_60, mem_trace_ld(reg_r0_38,0,1)); /* line 265 */
   __LDBs(reg_r0_61, mem_trace_ld(reg_r0_37,0,1)); /* line 266 */
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
   __CMPNE(reg_b0_2, reg_r0_53, 0); /* line 367 */
   __CMPEQ(reg_b0_3, reg_r0_53, reg_r0_4); /* line 368 */
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
   __CMPNE(reg_b0_4, reg_r0_54, 0); /* line 372 */
   __CMPEQ(reg_b0_5, reg_r0_54, reg_r0_4); /* line 373 */
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
   __CMPNE(reg_b0_6, reg_r0_55, 0); /* line 377 */
   __CMPEQ(reg_b0_7, reg_r0_55, reg_r0_4); /* line 378 */
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
   __CMPNE(reg_b0_0, reg_r0_56, 0); /* line 382 */
   __CMPEQ(reg_b0_1, reg_r0_56, reg_r0_4); /* line 383 */
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
   __CMPNE(reg_b0_2, reg_r0_57, 0); /* line 387 */
   __CMPEQ(reg_b0_3, reg_r0_57, reg_r0_4); /* line 388 */
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
   __CMPNE(reg_b0_4, reg_r0_13, 0); /* line 392 */
   __CMPEQ(reg_b0_5, reg_r0_13, reg_r0_4); /* line 393 */
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
  sim_icache_fetch(263 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_32); /* line 442 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 443 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 444 */
l_L31X3: ;/* line 447 */
__LABEL(l_L31X3);
  sim_icache_fetch(266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_30, reg_r0_38); /* line 448 */
} /* line 448 */
l_L15X3: ;/* line 451 */
__LABEL(l_L15X3);
  sim_icache_fetch(267 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_30); /* line 452 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 453 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 454 */
l_L30X3: ;/* line 457 */
__LABEL(l_L30X3);
  sim_icache_fetch(270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_28, reg_r0_39); /* line 458 */
} /* line 458 */
l_L14X3: ;/* line 461 */
__LABEL(l_L14X3);
  sim_icache_fetch(271 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_28); /* line 462 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 463 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 464 */
l_L29X3: ;/* line 467 */
__LABEL(l_L29X3);
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_26, reg_r0_40); /* line 468 */
} /* line 468 */
l_L13X3: ;/* line 471 */
__LABEL(l_L13X3);
  sim_icache_fetch(275 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_26); /* line 472 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 473 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 474 */
l_L28X3: ;/* line 477 */
__LABEL(l_L28X3);
  sim_icache_fetch(278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_24, reg_r0_41); /* line 478 */
} /* line 478 */
l_L12X3: ;/* line 481 */
__LABEL(l_L12X3);
  sim_icache_fetch(279 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_24); /* line 482 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 483 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 484 */
l_L27X3: ;/* line 487 */
__LABEL(l_L27X3);
  sim_icache_fetch(282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_42); /* line 488 */
} /* line 488 */
l_L11X3: ;/* line 491 */
__LABEL(l_L11X3);
  sim_icache_fetch(283 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_22); /* line 492 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 493 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 494 */
l_L26X3: ;/* line 497 */
__LABEL(l_L26X3);
  sim_icache_fetch(286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_20, reg_r0_43); /* line 498 */
} /* line 498 */
l_L10X3: ;/* line 501 */
__LABEL(l_L10X3);
  sim_icache_fetch(287 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_20); /* line 502 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 503 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 504 */
l_L25X3: ;/* line 507 */
__LABEL(l_L25X3);
  sim_icache_fetch(290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_44); /* line 508 */
} /* line 508 */
l_L9X3: ;/* line 511 */
__LABEL(l_L9X3);
  sim_icache_fetch(291 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_18); /* line 512 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 513 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 514 */
l_L24X3: ;/* line 517 */
__LABEL(l_L24X3);
  sim_icache_fetch(294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, reg_r0_45); /* line 518 */
} /* line 518 */
l_L8X3: ;/* line 521 */
__LABEL(l_L8X3);
  sim_icache_fetch(295 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_16); /* line 522 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 523 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 524 */
l_L23X3: ;/* line 527 */
__LABEL(l_L23X3);
  sim_icache_fetch(298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_14, reg_r0_46); /* line 528 */
} /* line 528 */
l_L7X3: ;/* line 531 */
__LABEL(l_L7X3);
  sim_icache_fetch(299 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_14); /* line 532 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 533 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 534 */
l_L22X3: ;/* line 537 */
__LABEL(l_L22X3);
  sim_icache_fetch(302 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, reg_r0_47); /* line 538 */
} /* line 538 */
l_L6X3: ;/* line 541 */
__LABEL(l_L6X3);
  sim_icache_fetch(303 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_12); /* line 542 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 543 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 544 */
l_L21X3: ;/* line 547 */
__LABEL(l_L21X3);
  sim_icache_fetch(306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_10, reg_r0_48); /* line 548 */
} /* line 548 */
l_L5X3: ;/* line 551 */
__LABEL(l_L5X3);
  sim_icache_fetch(307 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_10); /* line 552 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 553 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 554 */
l_L20X3: ;/* line 557 */
__LABEL(l_L20X3);
  sim_icache_fetch(310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_49); /* line 558 */
} /* line 558 */
l_L4X3: ;/* line 561 */
__LABEL(l_L4X3);
  sim_icache_fetch(311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_8); /* line 562 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 563 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 564 */
l_L19X3: ;/* line 567 */
__LABEL(l_L19X3);
  sim_icache_fetch(314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_36); /* line 568 */
} /* line 568 */
l_L3X3: ;/* line 571 */
__LABEL(l_L3X3);
  sim_icache_fetch(315 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_6); /* line 572 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 573 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 574 */
l_L18X3: ;/* line 577 */
__LABEL(l_L18X3);
  sim_icache_fetch(318 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_51); /* line 578 */
} /* line 578 */
l_L2X3: ;/* line 581 */
__LABEL(l_L2X3);
  sim_icache_fetch(319 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_2); /* line 582 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 583 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 584 */
l_L17X3: ;/* line 587 */
__LABEL(l_L17X3);
  sim_icache_fetch(322 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_5); /* line 588 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 589 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 590 */
l_L1X3: ;/* line 593 */
__LABEL(l_L1X3);
  sim_icache_fetch(325 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 594 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 595 */
} /* line 595 */
l_L33X3: ;/* line 597 */
__LABEL(l_L33X3);
  sim_icache_fetch(327 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 598 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 599 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 600 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 601 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 602 */
} /* line 602 */
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 605 */
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

  sim_icache_fetch(333 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 622 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 623 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 624 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 625 */
} /* line 625 */
  sim_icache_fetch(340 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 627 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 628 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 629 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 630 */
} /* line 630 */
  sim_icache_fetch(345 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 632 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 633 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 634 */
} /* line 634 */
		 /* line 635 */
  sim_icache_fetch(348 + t_thisfile.offset, 2);
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
} /* line 637 */
l_lr_46: ;/* line 637 */
__LABEL(l_lr_46);
  sim_icache_fetch(350 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 639 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 640 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 641 */
   __ADD_CYCLES(1);
} /* line 641 */
  sim_icache_fetch(353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 643 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 644 */
} /* line 644 */
l_L34X3: ;/* line 647 */
__LABEL(l_L34X3);
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 648 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 649 */
} /* line 649 */
  sim_icache_fetch(357 + t_thisfile.offset, 1);
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
} /* line 651 */
  sim_icache_fetch(358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 653 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 654 */
   __ADD_CYCLES(1);
} /* line 654 */
  sim_icache_fetch(360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 656 */
} /* line 656 */
  sim_icache_fetch(361 + t_thisfile.offset, 1);
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
} /* line 658 */
l_L37X3: ;/* line 661 */
__LABEL(l_L37X3);
  sim_icache_fetch(362 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 662 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 663 */
   __ADD_CYCLES(1);
} /* line 663 */
  sim_icache_fetch(364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 665 */
} /* line 665 */
  sim_icache_fetch(365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 667 */
} /* line 667 */
  sim_icache_fetch(366 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 669 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 670 */
   __ADD_CYCLES(1);
} /* line 670 */
  sim_icache_fetch(368 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 672 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 673 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 674 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 675 */
} /* line 675 */
  sim_icache_fetch(373 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 677 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 678 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 679 */
  sim_icache_fetch(376 + t_thisfile.offset, 1);
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
} /* line 681 */
  sim_icache_fetch(377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 682 */
  sim_icache_fetch(378 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 684 */
l__X1XCompressXTAGX0X0: ;/* line 686 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(379 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 687 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 688 */
l__X1XCompressXTAGX0X7: ;/* line 691 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(382 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 692 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 693 */
l__X1XCompressXTAGX0X6: ;/* line 696 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 697 */
} /* line 697 */
  sim_icache_fetch(386 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 699 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 700 */
l__X1XCompressXTAGX0X5: ;/* line 703 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 704 */
} /* line 704 */
  sim_icache_fetch(390 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 706 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 707 */
l__X1XCompressXTAGX0X4: ;/* line 710 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 711 */
} /* line 711 */
  sim_icache_fetch(394 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 713 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 714 */
l__X1XCompressXTAGX0X3: ;/* line 717 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 718 */
} /* line 718 */
  sim_icache_fetch(398 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 720 */
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 721 */
l__X1XCompressXTAGX0X2: ;/* line 724 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 725 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 726 */
   __ADD_CYCLES(1);
} /* line 726 */
  sim_icache_fetch(403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 728 */
} /* line 728 */
  sim_icache_fetch(404 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 730 */
} /* line 730 */
  sim_icache_fetch(405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 732 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 733 */
   __ADD_CYCLES(1);
} /* line 733 */
  sim_icache_fetch(407 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 735 */
} /* line 735 */
  sim_icache_fetch(408 + t_thisfile.offset, 1);
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
} /* line 737 */
l_L36X3: ;/* line 739 */
__LABEL(l_L36X3);
  sim_icache_fetch(409 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 740 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 741 */
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 742 */
l_L40X3: ;/* line 745 */
__LABEL(l_L40X3);
  sim_icache_fetch(412 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 746 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 747 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 748 */
} /* line 748 */
  sim_icache_fetch(415 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 750 */
} /* line 750 */
  sim_icache_fetch(416 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 752 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 753 */
  sim_icache_fetch(418 + t_thisfile.offset, 1);
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
} /* line 756 */
  sim_icache_fetch(419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 758 */
l_L41X3: ;/* line 761 */
__LABEL(l_L41X3);
		 /* line 761 */
  sim_icache_fetch(420 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 764 */
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
} /* line 764 */
l_lr_60: ;/* line 764 */
__LABEL(l_lr_60);
		 /* line 765 */
  sim_icache_fetch(424 + t_thisfile.offset, 2);
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
} /* line 767 */
l_lr_62: ;/* line 767 */
__LABEL(l_lr_62);
  sim_icache_fetch(426 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 769 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 770 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 771 */
   __ADD_CYCLES(1);
} /* line 771 */
  sim_icache_fetch(429 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 774 */
l__X1XCompressXTAGX0X1: ;/* line 777 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 777 */
  sim_icache_fetch(430 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 780 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 781 */
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
} /* line 781 */
l_lr_65: ;/* line 781 */
__LABEL(l_lr_65);
  sim_icache_fetch(434 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 783 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 784 */
} /* line 784 */
  sim_icache_fetch(436 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 786 */
l_L39X3: ;/* line 789 */
__LABEL(l_L39X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 790 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 790 */
  sim_icache_fetch(437 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 793 */
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
} /* line 793 */
l_lr_69: ;/* line 793 */
__LABEL(l_lr_69);
		 /* line 794 */
  sim_icache_fetch(441 + t_thisfile.offset, 2);
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
} /* line 796 */
l_lr_71: ;/* line 796 */
__LABEL(l_lr_71);
  sim_icache_fetch(443 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 798 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 799 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 800 */
   __ADD_CYCLES(1);
} /* line 800 */
  sim_icache_fetch(446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 803 */
l_L38X3: ;/* line 806 */
__LABEL(l_L38X3);
  sim_icache_fetch(447 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 807 */
l_L35X3: ;/* line 810 */
__LABEL(l_L35X3);
  sim_icache_fetch(448 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 811 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 812 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 813 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 814 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 815 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 816 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 817 */
   __ADD_CYCLES(1);
} /* line 817 */
  sim_icache_fetch(458 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 819 */
   __CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 4096); /* line 820 */
} /* line 820 */
  sim_icache_fetch(461 + t_thisfile.offset, 1);
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
} /* line 822 */
  sim_icache_fetch(462 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 824 */
} /* line 824 */
l_L43X3: ;/* line 826 */
__LABEL(l_L43X3);
  sim_icache_fetch(464 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 827 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 828 */
   __ADD_CYCLES(1);
} /* line 828 */
  sim_icache_fetch(467 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 830 */
} /* line 830 */
  sim_icache_fetch(468 + t_thisfile.offset, 1);
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
} /* line 832 */
  sim_icache_fetch(469 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 834 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 835 */
} /* line 835 */
l_L45X3: ;/* line 837 */
__LABEL(l_L45X3);
  sim_icache_fetch(473 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 838 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 839 */
   __ADD_CYCLES(1);
} /* line 839 */
  sim_icache_fetch(476 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 841 */
} /* line 841 */
  sim_icache_fetch(477 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 843 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L46X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 844 */
		 /* line 845 */
  sim_icache_fetch(480 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 847 */
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
} /* line 848 */
l_lr_77: ;/* line 848 */
__LABEL(l_lr_77);
l_L47X3: ;/* line 850 */
__LABEL(l_L47X3);
  sim_icache_fetch(484 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 851 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 852 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 853 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 854 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 855 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 856 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 857 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 858 */
} /* line 858 */
  sim_icache_fetch(500 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 860 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 861 */
} /* line 861 */
  sim_icache_fetch(504 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 863 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 864 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 865 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 866 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 867 */
} /* line 867 */
  sim_icache_fetch(510 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 869 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 870 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 871 */
  sim_icache_fetch(513 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 873 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 874 */
  sim_icache_fetch(516 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 876 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 877 */
l_L51X3: ;/* line 879 */
__LABEL(l_L51X3);
		 /* line 879 */
  sim_icache_fetch(519 + t_thisfile.offset, 2);
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
} /* line 881 */
l_lr_81: ;/* line 881 */
__LABEL(l_lr_81);
  sim_icache_fetch(521 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 883 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 884 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 885 */
   __ADD_CYCLES(1);
} /* line 885 */
  sim_icache_fetch(524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 888 */
l_L50X3: ;/* line 891 */
__LABEL(l_L50X3);
  sim_icache_fetch(525 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 892 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 893 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 894 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 895 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 896 */
   __ADD_CYCLES(1);
} /* line 896 */
  sim_icache_fetch(534 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 898 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 899 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 900 */
} /* line 900 */
  sim_icache_fetch(537 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 902 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 903 */
} /* line 903 */
  sim_icache_fetch(540 + t_thisfile.offset, 1);
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
} /* line 905 */
  sim_icache_fetch(541 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 907 */
} /* line 907 */
  sim_icache_fetch(543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 909 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 910 */
   __ADD_CYCLES(1);
} /* line 910 */
  sim_icache_fetch(545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 912 */
} /* line 912 */
l_L53X3: ;/* line 914 */
__LABEL(l_L53X3);
  sim_icache_fetch(546 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 915 */
} /* line 915 */
  sim_icache_fetch(547 + t_thisfile.offset, 1);
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
} /* line 918 */
  sim_icache_fetch(548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 920 */
l_L54X3: ;/* line 923 */
__LABEL(l_L54X3);
  sim_icache_fetch(549 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 924 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 925 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 926 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 927 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 928 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 929 */
   __ADD_CYCLES(1);
} /* line 929 */
  sim_icache_fetch(559 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 931 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 932 */
} /* line 932 */
  sim_icache_fetch(561 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 934 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 935 */
} /* line 935 */
  sim_icache_fetch(564 + t_thisfile.offset, 1);
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
} /* line 937 */
  sim_icache_fetch(565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 939 */
} /* line 939 */
  sim_icache_fetch(567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 941 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 942 */
   __ADD_CYCLES(1);
} /* line 942 */
  sim_icache_fetch(569 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 944 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 945 */
} /* line 945 */
l_L56X3: ;/* line 947 */
__LABEL(l_L56X3);
  sim_icache_fetch(572 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 948 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 949 */
} /* line 949 */
  sim_icache_fetch(574 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 951 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 952 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 953 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 954 */
} /* line 954 */
  sim_icache_fetch(580 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 956 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 957 */
		 /* line 958 */
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
} /* line 960 */
l_lr_87: ;/* line 960 */
__LABEL(l_lr_87);
  sim_icache_fetch(585 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 962 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 963 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 964 */
   __ADD_CYCLES(1);
} /* line 964 */
  sim_icache_fetch(588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 967 */
l_L48X3: ;/* line 970 */
__LABEL(l_L48X3);
		 /* line 970 */
  sim_icache_fetch(589 + t_thisfile.offset, 2);
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
} /* line 972 */
l_lr_90: ;/* line 972 */
__LABEL(l_lr_90);
  sim_icache_fetch(591 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 974 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 975 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 976 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 977 */
   __ADD_CYCLES(1);
} /* line 977 */
  sim_icache_fetch(595 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 980 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 981 */
l_L55X3: ;/* line 984 */
__LABEL(l_L55X3);
  sim_icache_fetch(598 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 985 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 986 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 987 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 988 */
} /* line 988 */
  sim_icache_fetch(604 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 990 */
   __GOTO(l_L56X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L56X3;
} /* line 991 */
l_L52X3: ;/* line 994 */
__LABEL(l_L52X3);
  sim_icache_fetch(607 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 995 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 996 */
   __GOTO(l_L53X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L53X3;
} /* line 997 */
l_L49X3: ;/* line 1000 */
__LABEL(l_L49X3);
  sim_icache_fetch(611 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 1001 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1002 */
} /* line 1002 */
  sim_icache_fetch(614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1004 */
} /* line 1004 */
  sim_icache_fetch(615 + t_thisfile.offset, 1);
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
} /* line 1007 */
  sim_icache_fetch(616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 1009 */
l_L46X3: ;/* line 1012 */
__LABEL(l_L46X3);
  sim_icache_fetch(617 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1013 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1014 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1015 */
   __ADD_CYCLES(1);
} /* line 1015 */
  sim_icache_fetch(622 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1017 */
} /* line 1017 */
  sim_icache_fetch(624 + t_thisfile.offset, 1);
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
} /* line 1019 */
		 /* line 1020 */
  sim_icache_fetch(625 + t_thisfile.offset, 4);
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
l_lr_96: ;/* line 1023 */
__LABEL(l_lr_96);
  sim_icache_fetch(629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1025 */
l_L57X3: ;/* line 1028 */
__LABEL(l_L57X3);
  sim_icache_fetch(630 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1029 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1030 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1031 */
   __ADD_CYCLES(1);
} /* line 1031 */
  sim_icache_fetch(635 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1033 */
} /* line 1033 */
  sim_icache_fetch(637 + t_thisfile.offset, 1);
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
} /* line 1035 */
		 /* line 1036 */
  sim_icache_fetch(638 + t_thisfile.offset, 4);
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
l_lr_99: ;/* line 1039 */
__LABEL(l_lr_99);
  sim_icache_fetch(642 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1041 */
l_L58X3: ;/* line 1044 */
__LABEL(l_L58X3);
  sim_icache_fetch(643 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1045 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1046 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1047 */
   __ADD_CYCLES(1);
} /* line 1047 */
  sim_icache_fetch(648 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1049 */
} /* line 1049 */
  sim_icache_fetch(650 + t_thisfile.offset, 1);
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
} /* line 1051 */
		 /* line 1052 */
  sim_icache_fetch(651 + t_thisfile.offset, 4);
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
l_lr_102: ;/* line 1055 */
__LABEL(l_lr_102);
  sim_icache_fetch(655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1057 */
l_L59X3: ;/* line 1060 */
__LABEL(l_L59X3);
  sim_icache_fetch(656 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1061 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1062 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1063 */
   __ADD_CYCLES(1);
} /* line 1063 */
  sim_icache_fetch(661 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1065 */
} /* line 1065 */
  sim_icache_fetch(663 + t_thisfile.offset, 1);
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
} /* line 1067 */
		 /* line 1068 */
  sim_icache_fetch(664 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1070 */
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
} /* line 1071 */
l_lr_105: ;/* line 1071 */
__LABEL(l_lr_105);
  sim_icache_fetch(668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1073 */
l_L60X3: ;/* line 1076 */
__LABEL(l_L60X3);
		 /* line 1076 */
  sim_icache_fetch(669 + t_thisfile.offset, 2);
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
} /* line 1078 */
l_lr_108: ;/* line 1078 */
__LABEL(l_lr_108);
  sim_icache_fetch(671 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 1080 */
l_L44X3: ;/* line 1083 */
__LABEL(l_L44X3);
  sim_icache_fetch(672 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1084 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(675 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1087 */
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 1088 */
l_L42X3: ;/* line 1091 */
__LABEL(l_L42X3);
  sim_icache_fetch(678 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1092 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1093 */
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1094 */
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

  sim_icache_fetch(681 + t_thisfile.offset, 23);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1232 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1233 */
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1234 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1235 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1236 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1237 */
   __MOV(reg_r0_4, 0); /* line 1238 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1239 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1240 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1241 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1242 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1243 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1244 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1245 */
} /* line 1245 */
  sim_icache_fetch(704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1247 */
} /* line 1247 */
  sim_icache_fetch(705 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1249 */
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 1250 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1251 */
   __ADD(reg_r0_15, reg_r0_14, (unsigned int) 1); /* line 1252 */
} /* line 1252 */
  sim_icache_fetch(709 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, (unsigned int) 256); /* line 1254 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 1255 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1256 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1257 */
l_L62X3: ;/* line 1259 */
__LABEL(l_L62X3);
  sim_icache_fetch(714 + t_thisfile.offset, 23);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __STW(mem_trace_st((unsigned int) compress_15137Xoffset,0,4), 0); /* line 1260 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1261 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1262 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1263 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1264 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1265 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1266 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1267 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1268 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1269 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1270 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1271 */
  sim_icache_fetch(737 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 1273 */
} /* line 1273 */
  sim_icache_fetch(739 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1275 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1276 */
   __ADD_CYCLES(1);
} /* line 1276 */
  sim_icache_fetch(741 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1278 */
} /* line 1278 */
l_L64X3: ;/* line 1280 */
__LABEL(l_L64X3);
  sim_icache_fetch(742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1281 */
} /* line 1281 */
l_L65X3: ;/* line 1284 */
__LABEL(l_L65X3);
  sim_icache_fetch(743 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1285 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1286 */
} /* line 1286 */
  sim_icache_fetch(745 + t_thisfile.offset, 3);
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
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1290 */
  sim_icache_fetch(748 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1294 */
  sim_icache_fetch(751 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1298 */
  sim_icache_fetch(754 + t_thisfile.offset, 3);
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
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1302 */
  sim_icache_fetch(757 + t_thisfile.offset, 3);
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
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1306 */
  sim_icache_fetch(760 + t_thisfile.offset, 3);
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
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1310 */
  sim_icache_fetch(763 + t_thisfile.offset, 3);
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
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1314 */
  sim_icache_fetch(766 + t_thisfile.offset, 3);
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
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1318 */
  sim_icache_fetch(769 + t_thisfile.offset, 3);
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
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1322 */
  sim_icache_fetch(772 + t_thisfile.offset, 3);
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
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1326 */
  sim_icache_fetch(775 + t_thisfile.offset, 3);
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
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1330 */
  sim_icache_fetch(778 + t_thisfile.offset, 3);
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
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1334 */
  sim_icache_fetch(781 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1336 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1337 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1338 */
  sim_icache_fetch(784 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1340 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1341 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1342 */
  sim_icache_fetch(787 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1344 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1345 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1346 */
  sim_icache_fetch(790 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1348 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1349 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1350 */
  sim_icache_fetch(793 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1352 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1353 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1354 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1355 */
  sim_icache_fetch(797 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1359 */
  sim_icache_fetch(800 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1363 */
  sim_icache_fetch(803 + t_thisfile.offset, 3);
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
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1367 */
  sim_icache_fetch(806 + t_thisfile.offset, 3);
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
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1371 */
  sim_icache_fetch(809 + t_thisfile.offset, 3);
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
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1375 */
  sim_icache_fetch(812 + t_thisfile.offset, 3);
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
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1379 */
  sim_icache_fetch(815 + t_thisfile.offset, 3);
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
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1383 */
  sim_icache_fetch(818 + t_thisfile.offset, 3);
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
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1387 */
  sim_icache_fetch(821 + t_thisfile.offset, 3);
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
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1391 */
  sim_icache_fetch(824 + t_thisfile.offset, 3);
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
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1395 */
  sim_icache_fetch(827 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1397 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1398 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1399 */
  sim_icache_fetch(830 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1401 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1402 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1403 */
  sim_icache_fetch(833 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1405 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1406 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1407 */
  sim_icache_fetch(836 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1409 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1410 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1411 */
  sim_icache_fetch(839 + t_thisfile.offset, 1);
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
} /* line 1413 */
  sim_icache_fetch(840 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1415 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 1416 */
l_L81X3: ;/* line 1419 */
__LABEL(l_L81X3);
  sim_icache_fetch(842 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1420 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1421 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1422 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1423 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1424 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 1425 */
l_L83X3: ;/* line 1428 */
__LABEL(l_L83X3);
  sim_icache_fetch(849 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1429 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1430 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1431 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1432 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1433 */
   __ADD_CYCLES(1);
} /* line 1433 */
  sim_icache_fetch(858 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1435 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1436 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1437 */
} /* line 1437 */
  sim_icache_fetch(861 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1439 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1440 */
} /* line 1440 */
  sim_icache_fetch(864 + t_thisfile.offset, 1);
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
} /* line 1442 */
  sim_icache_fetch(865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1444 */
} /* line 1444 */
  sim_icache_fetch(867 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1446 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1447 */
   __ADD_CYCLES(1);
} /* line 1447 */
  sim_icache_fetch(869 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1449 */
} /* line 1449 */
l_L85X3: ;/* line 1451 */
__LABEL(l_L85X3);
  sim_icache_fetch(870 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1452 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1453 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1454 */
} /* line 1454 */
  sim_icache_fetch(873 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1456 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1457 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1458 */
  sim_icache_fetch(876 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1460 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1461 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1462 */
} /* line 1462 */
  sim_icache_fetch(882 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1464 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1465 */
   __ADD_CYCLES(1);
} /* line 1465 */
  sim_icache_fetch(884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1467 */
} /* line 1467 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
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
} /* line 1469 */
  sim_icache_fetch(886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1471 */
} /* line 1471 */
  sim_icache_fetch(887 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1473 */
l_L87X3: ;/* line 1476 */
__LABEL(l_L87X3);
  sim_icache_fetch(888 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1477 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1478 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1479 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1480 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1481 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1482 */
} /* line 1482 */
  sim_icache_fetch(895 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1484 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1485 */
   __ADD_CYCLES(1);
} /* line 1485 */
  sim_icache_fetch(897 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1487 */
} /* line 1487 */
  sim_icache_fetch(898 + t_thisfile.offset, 1);
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
} /* line 1489 */
l_L89X3: ;/* line 1491 */
__LABEL(l_L89X3);
		 /* line 1491 */
  sim_icache_fetch(899 + t_thisfile.offset, 2);
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
} /* line 1493 */
l_lr_121: ;/* line 1493 */
__LABEL(l_lr_121);
  sim_icache_fetch(901 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1495 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1496 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1497 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1498 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1499 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1500 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1501 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1502 */
   __ADD_CYCLES(1);
} /* line 1502 */
  sim_icache_fetch(912 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1504 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1505 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1506 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1507 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1508 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1509 */
} /* line 1509 */
  sim_icache_fetch(920 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1511 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1512 */
  sim_icache_fetch(923 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1514 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1515 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1516 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1517 */
l_L90X3: ;/* line 1520 */
__LABEL(l_L90X3);
  sim_icache_fetch(928 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1521 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1522 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1523 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1524 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1525 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1526 */
   __ADD_CYCLES(1);
} /* line 1526 */
  sim_icache_fetch(937 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1528 */
} /* line 1528 */
  sim_icache_fetch(938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1530 */
} /* line 1530 */
  sim_icache_fetch(939 + t_thisfile.offset, 1);
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
} /* line 1532 */
		 /* line 1533 */
  sim_icache_fetch(940 + t_thisfile.offset, 2);
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
} /* line 1535 */
l_lr_124: ;/* line 1535 */
__LABEL(l_lr_124);
  sim_icache_fetch(942 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1537 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1538 */
} /* line 1538 */
  sim_icache_fetch(944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1540 */
l_L91X3: ;/* line 1543 */
__LABEL(l_L91X3);
  sim_icache_fetch(945 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1544 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1545 */
} /* line 1545 */
  sim_icache_fetch(947 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1547 */
l_L88X3: ;/* line 1550 */
__LABEL(l_L88X3);
  sim_icache_fetch(948 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1551 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1552 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1553 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1554 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1555 */
   __ADD_CYCLES(1);
} /* line 1555 */
  sim_icache_fetch(953 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1557 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1558 */
} /* line 1558 */
  sim_icache_fetch(955 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1560 */
} /* line 1560 */
l_L92X3: ;/* line 1563 */
__LABEL(l_L92X3);
  sim_icache_fetch(956 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1564 */
} /* line 1564 */
  sim_icache_fetch(957 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1566 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1567 */
} /* line 1567 */
  sim_icache_fetch(959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1569 */
} /* line 1569 */
  sim_icache_fetch(960 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1571 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1572 */
} /* line 1572 */
  sim_icache_fetch(963 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1574 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1575 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1576 */
} /* line 1576 */
  sim_icache_fetch(966 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1578 */
} /* line 1578 */
  sim_icache_fetch(967 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1580 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1581 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1582 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1583 */
} /* line 1583 */
  sim_icache_fetch(972 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1585 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1586 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1587 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1588 */
  sim_icache_fetch(976 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1590 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1591 */
  sim_icache_fetch(978 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1593 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1594 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1595 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1596 */
} /* line 1596 */
  sim_icache_fetch(983 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1598 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1599 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1600 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1601 */
  sim_icache_fetch(987 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1603 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1604 */
  sim_icache_fetch(989 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1606 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1607 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1608 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1609 */
} /* line 1609 */
  sim_icache_fetch(994 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1611 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1612 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1613 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1614 */
  sim_icache_fetch(998 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1616 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1617 */
  sim_icache_fetch(1000 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1619 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1620 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1621 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1622 */
} /* line 1622 */
  sim_icache_fetch(1005 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1624 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1625 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1626 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1627 */
  sim_icache_fetch(1009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1629 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1630 */
  sim_icache_fetch(1011 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1632 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1633 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1634 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1635 */
} /* line 1635 */
  sim_icache_fetch(1016 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1637 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1638 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1639 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1640 */
  sim_icache_fetch(1020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1642 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1643 */
  sim_icache_fetch(1022 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1645 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1646 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1647 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1648 */
} /* line 1648 */
  sim_icache_fetch(1027 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1650 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1651 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1652 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1653 */
  sim_icache_fetch(1031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1655 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1656 */
  sim_icache_fetch(1033 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1658 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1659 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1660 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1661 */
} /* line 1661 */
  sim_icache_fetch(1038 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1663 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1664 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1665 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1666 */
  sim_icache_fetch(1042 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1668 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1669 */
  sim_icache_fetch(1044 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1671 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1672 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1673 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1674 */
} /* line 1674 */
  sim_icache_fetch(1049 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1676 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1677 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1678 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1679 */
  sim_icache_fetch(1053 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1681 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1682 */
  sim_icache_fetch(1055 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1684 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1685 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1686 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1687 */
} /* line 1687 */
  sim_icache_fetch(1060 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1689 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1690 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1691 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1692 */
  sim_icache_fetch(1064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1694 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1695 */
  sim_icache_fetch(1066 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1697 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1698 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1699 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1700 */
} /* line 1700 */
  sim_icache_fetch(1071 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1702 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1703 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1704 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1705 */
  sim_icache_fetch(1075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1707 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1708 */
  sim_icache_fetch(1077 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1710 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1711 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1712 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1713 */
} /* line 1713 */
  sim_icache_fetch(1082 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1715 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1716 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1717 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1718 */
  sim_icache_fetch(1086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1720 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1721 */
  sim_icache_fetch(1088 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1723 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1724 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1725 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1726 */
} /* line 1726 */
  sim_icache_fetch(1093 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1728 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1729 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1730 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1731 */
  sim_icache_fetch(1097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1733 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1734 */
  sim_icache_fetch(1099 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1736 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1737 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1738 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1739 */
} /* line 1739 */
  sim_icache_fetch(1104 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1741 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1742 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1743 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1744 */
  sim_icache_fetch(1108 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1746 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1747 */
  sim_icache_fetch(1110 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1749 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1750 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1751 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1752 */
} /* line 1752 */
  sim_icache_fetch(1115 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1754 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1755 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1756 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1757 */
  sim_icache_fetch(1119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1759 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1760 */
  sim_icache_fetch(1121 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1762 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1763 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1764 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1765 */
} /* line 1765 */
  sim_icache_fetch(1126 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1767 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1768 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1769 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1770 */
  sim_icache_fetch(1130 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1772 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1773 */
  sim_icache_fetch(1132 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1775 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1776 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1777 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1778 */
} /* line 1778 */
  sim_icache_fetch(1137 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1780 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1781 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1782 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1783 */
  sim_icache_fetch(1141 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1785 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1786 */
  sim_icache_fetch(1143 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1788 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1789 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1790 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1791 */
} /* line 1791 */
  sim_icache_fetch(1148 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1793 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1794 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1795 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1796 */
  sim_icache_fetch(1152 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1798 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1799 */
  sim_icache_fetch(1154 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1801 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1802 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1803 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1804 */
} /* line 1804 */
  sim_icache_fetch(1159 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1806 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1807 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1808 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1809 */
  sim_icache_fetch(1163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1811 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1812 */
  sim_icache_fetch(1165 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1814 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1815 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1816 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1817 */
} /* line 1817 */
  sim_icache_fetch(1170 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1819 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1820 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1821 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1822 */
  sim_icache_fetch(1174 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1824 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1825 */
  sim_icache_fetch(1176 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1827 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1828 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1829 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1830 */
} /* line 1830 */
  sim_icache_fetch(1181 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1832 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1833 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1834 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1835 */
  sim_icache_fetch(1185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1837 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1838 */
  sim_icache_fetch(1187 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1840 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1841 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1842 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1843 */
} /* line 1843 */
  sim_icache_fetch(1192 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1845 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1846 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1847 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1848 */
  sim_icache_fetch(1196 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1850 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1851 */
  sim_icache_fetch(1198 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1853 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1854 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1855 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1856 */
} /* line 1856 */
  sim_icache_fetch(1203 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1858 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1859 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1860 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1861 */
  sim_icache_fetch(1207 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1863 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1864 */
  sim_icache_fetch(1209 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1866 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1867 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1868 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1869 */
} /* line 1869 */
  sim_icache_fetch(1214 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1871 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1872 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1873 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1874 */
  sim_icache_fetch(1218 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1876 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1877 */
  sim_icache_fetch(1220 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1879 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1880 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1881 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1882 */
} /* line 1882 */
  sim_icache_fetch(1225 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1884 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1885 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1886 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1887 */
  sim_icache_fetch(1229 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1889 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1890 */
  sim_icache_fetch(1231 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1892 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1893 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1894 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1895 */
} /* line 1895 */
  sim_icache_fetch(1236 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1897 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1898 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1899 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1900 */
  sim_icache_fetch(1240 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1902 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1903 */
  sim_icache_fetch(1242 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1905 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1906 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1907 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1908 */
} /* line 1908 */
  sim_icache_fetch(1247 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1910 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1911 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1912 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1913 */
  sim_icache_fetch(1251 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1915 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1916 */
  sim_icache_fetch(1253 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1918 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1919 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1920 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1921 */
} /* line 1921 */
  sim_icache_fetch(1258 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1923 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1924 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1925 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1926 */
  sim_icache_fetch(1262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1928 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1929 */
  sim_icache_fetch(1264 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1931 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1932 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1933 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1934 */
} /* line 1934 */
  sim_icache_fetch(1269 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1936 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1937 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1938 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1939 */
  sim_icache_fetch(1273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1941 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1942 */
  sim_icache_fetch(1275 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1944 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1945 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1946 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1947 */
} /* line 1947 */
  sim_icache_fetch(1280 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1949 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1950 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1951 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1952 */
  sim_icache_fetch(1284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1954 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1955 */
  sim_icache_fetch(1286 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1957 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1958 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1959 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1960 */
} /* line 1960 */
  sim_icache_fetch(1291 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1962 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1963 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1964 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1965 */
  sim_icache_fetch(1295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1967 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1968 */
  sim_icache_fetch(1297 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1970 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1971 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1972 */
} /* line 1972 */
  sim_icache_fetch(1301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1974 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1975 */
  sim_icache_fetch(1303 + t_thisfile.offset, 1);
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
} /* line 1977 */
  sim_icache_fetch(1304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1979 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1980 */
} /* line 1980 */
  sim_icache_fetch(1306 + t_thisfile.offset, 1);
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
} /* line 1982 */
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
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
} /* line 1985 */
  sim_icache_fetch(1308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L92X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L92X3;
} /* line 1987 */
l_L156X3: ;/* line 1990 */
__LABEL(l_L156X3);
  sim_icache_fetch(1309 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1991 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1992 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1993 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1994 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 1995 */
l_L155X3: ;/* line 1999 */
__LABEL(l_L155X3);
  sim_icache_fetch(1314 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2000 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2001 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2002 */
l_L154X3: ;/* line 2005 */
__LABEL(l_L154X3);
  sim_icache_fetch(1317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2006 */
} /* line 2006 */
l_L122X3: ;/* line 2009 */
__LABEL(l_L122X3);
  sim_icache_fetch(1318 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2010 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2011 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2012 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2013 */
} /* line 2013 */
  sim_icache_fetch(1322 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2015 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2016 */
l_L153X3: ;/* line 2019 */
__LABEL(l_L153X3);
  sim_icache_fetch(1324 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2020 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2021 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2022 */
l_L152X3: ;/* line 2025 */
__LABEL(l_L152X3);
  sim_icache_fetch(1327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2026 */
} /* line 2026 */
l_L120X3: ;/* line 2029 */
__LABEL(l_L120X3);
  sim_icache_fetch(1328 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2030 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2031 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2032 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2033 */
} /* line 2033 */
  sim_icache_fetch(1332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2035 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2036 */
l_L151X3: ;/* line 2039 */
__LABEL(l_L151X3);
  sim_icache_fetch(1334 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2040 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2041 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2042 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2043 */
l_L150X3: ;/* line 2046 */
__LABEL(l_L150X3);
  sim_icache_fetch(1338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2047 */
} /* line 2047 */
l_L118X3: ;/* line 2050 */
__LABEL(l_L118X3);
  sim_icache_fetch(1339 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2051 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2052 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2053 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2054 */
} /* line 2054 */
  sim_icache_fetch(1343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2056 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2057 */
l_L149X3: ;/* line 2060 */
__LABEL(l_L149X3);
  sim_icache_fetch(1345 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2061 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2062 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2063 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2064 */
l_L148X3: ;/* line 2067 */
__LABEL(l_L148X3);
  sim_icache_fetch(1349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2068 */
} /* line 2068 */
l_L116X3: ;/* line 2071 */
__LABEL(l_L116X3);
  sim_icache_fetch(1350 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2072 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2073 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2074 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2075 */
} /* line 2075 */
  sim_icache_fetch(1354 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2077 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2078 */
l_L147X3: ;/* line 2081 */
__LABEL(l_L147X3);
  sim_icache_fetch(1356 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2082 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2083 */
   __GOTO(l_L159X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L159X3;
} /* line 2084 */
l_L146X3: ;/* line 2087 */
__LABEL(l_L146X3);
  sim_icache_fetch(1359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2088 */
} /* line 2088 */
l_L114X3: ;/* line 2091 */
__LABEL(l_L114X3);
  sim_icache_fetch(1360 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2092 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2093 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2094 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2095 */
} /* line 2095 */
  sim_icache_fetch(1364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2097 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2098 */
l_L145X3: ;/* line 2101 */
__LABEL(l_L145X3);
  sim_icache_fetch(1366 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2102 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2103 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2104 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2105 */
l_L144X3: ;/* line 2108 */
__LABEL(l_L144X3);
  sim_icache_fetch(1370 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2109 */
} /* line 2109 */
l_L112X3: ;/* line 2112 */
__LABEL(l_L112X3);
  sim_icache_fetch(1371 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2113 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2114 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2115 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2116 */
} /* line 2116 */
  sim_icache_fetch(1375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2118 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2119 */
l_L143X3: ;/* line 2122 */
__LABEL(l_L143X3);
  sim_icache_fetch(1377 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2123 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2124 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2125 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2126 */
l_L142X3: ;/* line 2129 */
__LABEL(l_L142X3);
  sim_icache_fetch(1381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2130 */
} /* line 2130 */
l_L110X3: ;/* line 2133 */
__LABEL(l_L110X3);
  sim_icache_fetch(1382 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2134 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2135 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2136 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2137 */
} /* line 2137 */
  sim_icache_fetch(1386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2139 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2140 */
l_L141X3: ;/* line 2143 */
__LABEL(l_L141X3);
  sim_icache_fetch(1388 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2144 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2145 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2146 */
l_L140X3: ;/* line 2149 */
__LABEL(l_L140X3);
  sim_icache_fetch(1391 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2150 */
} /* line 2150 */
l_L108X3: ;/* line 2153 */
__LABEL(l_L108X3);
  sim_icache_fetch(1392 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2154 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2155 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2156 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2157 */
} /* line 2157 */
  sim_icache_fetch(1396 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2159 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2160 */
l_L139X3: ;/* line 2163 */
__LABEL(l_L139X3);
  sim_icache_fetch(1398 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2164 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2165 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2166 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2167 */
l_L138X3: ;/* line 2170 */
__LABEL(l_L138X3);
  sim_icache_fetch(1402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2171 */
} /* line 2171 */
l_L106X3: ;/* line 2174 */
__LABEL(l_L106X3);
  sim_icache_fetch(1403 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2175 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2176 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2177 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2178 */
} /* line 2178 */
  sim_icache_fetch(1407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2180 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2181 */
l_L137X3: ;/* line 2184 */
__LABEL(l_L137X3);
  sim_icache_fetch(1409 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2185 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2186 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2187 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2188 */
l_L136X3: ;/* line 2191 */
__LABEL(l_L136X3);
  sim_icache_fetch(1413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2192 */
} /* line 2192 */
l_L104X3: ;/* line 2195 */
__LABEL(l_L104X3);
  sim_icache_fetch(1414 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2196 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2197 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2198 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2199 */
} /* line 2199 */
  sim_icache_fetch(1418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2201 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2202 */
l_L135X3: ;/* line 2205 */
__LABEL(l_L135X3);
  sim_icache_fetch(1420 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2206 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2207 */
   __GOTO(l_L161X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L161X3;
} /* line 2208 */
l_L134X3: ;/* line 2211 */
__LABEL(l_L134X3);
  sim_icache_fetch(1423 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2212 */
} /* line 2212 */
l_L102X3: ;/* line 2215 */
__LABEL(l_L102X3);
  sim_icache_fetch(1424 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2216 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2217 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2218 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2219 */
} /* line 2219 */
  sim_icache_fetch(1428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2221 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2222 */
l_L133X3: ;/* line 2225 */
__LABEL(l_L133X3);
  sim_icache_fetch(1430 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2226 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2227 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2228 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2229 */
l_L132X3: ;/* line 2232 */
__LABEL(l_L132X3);
  sim_icache_fetch(1434 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2233 */
} /* line 2233 */
l_L100X3: ;/* line 2236 */
__LABEL(l_L100X3);
  sim_icache_fetch(1435 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2237 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2238 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2239 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2240 */
} /* line 2240 */
  sim_icache_fetch(1439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2242 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2243 */
l_L131X3: ;/* line 2246 */
__LABEL(l_L131X3);
  sim_icache_fetch(1441 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2247 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2248 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2249 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2250 */
l_L130X3: ;/* line 2253 */
__LABEL(l_L130X3);
  sim_icache_fetch(1445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2254 */
} /* line 2254 */
l_L98X3: ;/* line 2257 */
__LABEL(l_L98X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2258 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2259 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2260 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2261 */
} /* line 2261 */
  sim_icache_fetch(1450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2263 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2264 */
l_L129X3: ;/* line 2267 */
__LABEL(l_L129X3);
  sim_icache_fetch(1452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2268 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2269 */
   __GOTO(l_L162X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L162X3;
} /* line 2270 */
l_L128X3: ;/* line 2273 */
__LABEL(l_L128X3);
  sim_icache_fetch(1455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2274 */
} /* line 2274 */
l_L96X3: ;/* line 2277 */
__LABEL(l_L96X3);
  sim_icache_fetch(1456 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2278 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2279 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2280 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2281 */
} /* line 2281 */
  sim_icache_fetch(1460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2283 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2284 */
l_L127X3: ;/* line 2287 */
__LABEL(l_L127X3);
  sim_icache_fetch(1462 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2288 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2289 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2290 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2291 */
l_L126X3: ;/* line 2294 */
__LABEL(l_L126X3);
  sim_icache_fetch(1466 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2295 */
} /* line 2295 */
l_L94X3: ;/* line 2299 */
__LABEL(l_L94X3);
  sim_icache_fetch(1467 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2300 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2301 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2302 */
} /* line 2302 */
  sim_icache_fetch(1470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2304 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2305 */
l_L125X3: ;/* line 2308 */
__LABEL(l_L125X3);
  sim_icache_fetch(1472 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2309 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2310 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2311 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2312 */
l_L124X3: ;/* line 2315 */
__LABEL(l_L124X3);
  sim_icache_fetch(1476 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2316 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2317 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2318 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2319 */
   __GOTO(l_L89X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L89X3;
} /* line 2320 */
l_L123X3: ;/* line 2324 */
__LABEL(l_L123X3);
  sim_icache_fetch(1481 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2325 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2326 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2327 */
l_L121X3: ;/* line 2330 */
__LABEL(l_L121X3);
  sim_icache_fetch(1484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2331 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2332 */
} /* line 2332 */
l_L158X3: ;/* line 2334 */
__LABEL(l_L158X3);
  sim_icache_fetch(1486 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2335 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2336 */
l_L119X3: ;/* line 2339 */
__LABEL(l_L119X3);
  sim_icache_fetch(1488 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2340 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2341 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2342 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2343 */
l_L117X3: ;/* line 2346 */
__LABEL(l_L117X3);
  sim_icache_fetch(1492 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2347 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2348 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2349 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2350 */
l_L115X3: ;/* line 2353 */
__LABEL(l_L115X3);
  sim_icache_fetch(1496 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2354 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2355 */
} /* line 2355 */
l_L159X3: ;/* line 2357 */
__LABEL(l_L159X3);
  sim_icache_fetch(1498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2358 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2359 */
l_L113X3: ;/* line 2362 */
__LABEL(l_L113X3);
  sim_icache_fetch(1500 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2363 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2364 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2365 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2366 */
l_L111X3: ;/* line 2369 */
__LABEL(l_L111X3);
  sim_icache_fetch(1504 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2370 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2371 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2372 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2373 */
l_L109X3: ;/* line 2376 */
__LABEL(l_L109X3);
  sim_icache_fetch(1508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2377 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2378 */
} /* line 2378 */
l_L160X3: ;/* line 2380 */
__LABEL(l_L160X3);
  sim_icache_fetch(1510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2381 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2382 */
l_L107X3: ;/* line 2385 */
__LABEL(l_L107X3);
  sim_icache_fetch(1512 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2386 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2387 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2388 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2389 */
l_L105X3: ;/* line 2392 */
__LABEL(l_L105X3);
  sim_icache_fetch(1516 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2393 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2394 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2395 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2396 */
l_L103X3: ;/* line 2399 */
__LABEL(l_L103X3);
  sim_icache_fetch(1520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2400 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2401 */
} /* line 2401 */
l_L161X3: ;/* line 2403 */
__LABEL(l_L161X3);
  sim_icache_fetch(1522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2404 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2405 */
l_L101X3: ;/* line 2408 */
__LABEL(l_L101X3);
  sim_icache_fetch(1524 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2409 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2410 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2411 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2412 */
l_L99X3: ;/* line 2415 */
__LABEL(l_L99X3);
  sim_icache_fetch(1528 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2416 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2417 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2418 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2419 */
l_L97X3: ;/* line 2422 */
__LABEL(l_L97X3);
  sim_icache_fetch(1532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2423 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2424 */
} /* line 2424 */
l_L162X3: ;/* line 2426 */
__LABEL(l_L162X3);
  sim_icache_fetch(1534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2427 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2428 */
l_L95X3: ;/* line 2431 */
__LABEL(l_L95X3);
  sim_icache_fetch(1536 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2432 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2433 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2434 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2435 */
l_L93X3: ;/* line 2439 */
__LABEL(l_L93X3);
  sim_icache_fetch(1540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2440 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2441 */
} /* line 2441 */
l_L157X3: ;/* line 2443 */
__LABEL(l_L157X3);
  sim_icache_fetch(1542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2444 */
} /* line 2444 */
  sim_icache_fetch(1544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2446 */
} /* line 2446 */
  sim_icache_fetch(1545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2448 */
l_L86X3: ;/* line 2451 */
__LABEL(l_L86X3);
		 /* line 2451 */
  sim_icache_fetch(1546 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2454 */
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
} /* line 2454 */
l_lr_200: ;/* line 2454 */
__LABEL(l_lr_200);
  sim_icache_fetch(1549 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2456 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2457 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2458 */
   __ADD_CYCLES(1);
} /* line 2458 */
  sim_icache_fetch(1553 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2460 */
} /* line 2460 */
		 /* line 2461 */
  sim_icache_fetch(1554 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2463 */
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
} /* line 2464 */
l_lr_202: ;/* line 2464 */
__LABEL(l_lr_202);
  sim_icache_fetch(1558 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2466 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2467 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2468 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2469 */
   __MOV(reg_r0_3, 0); /* line 2470 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2471 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2472 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2473 */
   __ADD_CYCLES(1);
} /* line 2473 */
  sim_icache_fetch(1570 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2475 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2476 */
} /* line 2476 */
  sim_icache_fetch(1572 + t_thisfile.offset, 1);
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
} /* line 2478 */
l_L164X3: ;/* line 2480 */
__LABEL(l_L164X3);
  sim_icache_fetch(1573 + t_thisfile.offset, 1);
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
} /* line 2481 */
  sim_icache_fetch(1574 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2483 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2484 */
} /* line 2484 */
l_L166X3: ;/* line 2486 */
__LABEL(l_L166X3);
  sim_icache_fetch(1577 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2488 */
l_L165X3: ;/* line 2491 */
__LABEL(l_L165X3);
  sim_icache_fetch(1578 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2492 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2493 */
   __GOTO(l_L166X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L166X3;
} /* line 2494 */
l_L163X3: ;/* line 2497 */
__LABEL(l_L163X3);
  sim_icache_fetch(1581 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2498 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2499 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2500 */
   __ADD_CYCLES(1);
} /* line 2500 */
		 /* line 2501 */
  sim_icache_fetch(1586 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2503 */
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
} /* line 2504 */
l_lr_208: ;/* line 2504 */
__LABEL(l_lr_208);
  sim_icache_fetch(1589 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2506 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2507 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2508 */
   __MOV(reg_r0_3, 0); /* line 2509 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2510 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2511 */
   __ADD_CYCLES(1);
} /* line 2511 */
  sim_icache_fetch(1597 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2513 */
   __GOTO(l_L164X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L164X3;
} /* line 2514 */
l_L84X3: ;/* line 2517 */
__LABEL(l_L84X3);
  sim_icache_fetch(1599 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2518 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2519 */
l_L80X3: ;/* line 2522 */
__LABEL(l_L80X3);
  sim_icache_fetch(1601 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2523 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2524 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2525 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2526 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2527 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2528 */
l_L79X3: ;/* line 2531 */
__LABEL(l_L79X3);
  sim_icache_fetch(1608 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2532 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2533 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2534 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2535 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2536 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2537 */
l_L78X3: ;/* line 2540 */
__LABEL(l_L78X3);
  sim_icache_fetch(1615 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2541 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2542 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2543 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2544 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2545 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2546 */
l_L77X3: ;/* line 2549 */
__LABEL(l_L77X3);
  sim_icache_fetch(1622 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2550 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2551 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2552 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2553 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2554 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2555 */
l_L76X3: ;/* line 2558 */
__LABEL(l_L76X3);
  sim_icache_fetch(1629 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2559 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2560 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2561 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2562 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2563 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2564 */
l_L75X3: ;/* line 2567 */
__LABEL(l_L75X3);
  sim_icache_fetch(1636 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2568 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2569 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2570 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2571 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2572 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2573 */
l_L74X3: ;/* line 2576 */
__LABEL(l_L74X3);
  sim_icache_fetch(1643 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2577 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2578 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2579 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2580 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2581 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2582 */
l_L73X3: ;/* line 2585 */
__LABEL(l_L73X3);
  sim_icache_fetch(1650 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2586 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2587 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2588 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2589 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2590 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2591 */
l_L72X3: ;/* line 2594 */
__LABEL(l_L72X3);
  sim_icache_fetch(1657 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2595 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2596 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2597 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2598 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2599 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2600 */
l_L71X3: ;/* line 2603 */
__LABEL(l_L71X3);
  sim_icache_fetch(1664 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2604 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2605 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2606 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2607 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2608 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2609 */
l_L70X3: ;/* line 2612 */
__LABEL(l_L70X3);
  sim_icache_fetch(1671 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2613 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2614 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2615 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2616 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2617 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2618 */
l_L69X3: ;/* line 2621 */
__LABEL(l_L69X3);
  sim_icache_fetch(1678 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2622 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2623 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2624 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2625 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2626 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2627 */
l_L68X3: ;/* line 2630 */
__LABEL(l_L68X3);
  sim_icache_fetch(1685 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2631 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2632 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2633 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2634 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2635 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2636 */
l_L67X3: ;/* line 2639 */
__LABEL(l_L67X3);
  sim_icache_fetch(1692 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2640 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2641 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2642 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2643 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2644 */
   __GOTO(l_L82X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L82X3;
} /* line 2645 */
l_L66X3: ;/* line 2649 */
__LABEL(l_L66X3);
  sim_icache_fetch(1699 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2650 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2651 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2652 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2653 */
} /* line 2653 */
l_L82X3: ;/* line 2655 */
__LABEL(l_L82X3);
  sim_icache_fetch(1704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2656 */
} /* line 2656 */
		 /* line 2657 */
  sim_icache_fetch(1705 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2660 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2661 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2662 */
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
} /* line 2662 */
l_lr_227: ;/* line 2662 */
__LABEL(l_lr_227);
  sim_icache_fetch(1710 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2664 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2665 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2666 */
} /* line 2666 */
  sim_icache_fetch(1713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2668 */
l_L63X3: ;/* line 2671 */
__LABEL(l_L63X3);
  sim_icache_fetch(1714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2672 */
   __GOTO(l_L64X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L64X3;
} /* line 2673 */
l_L61X3: ;/* line 2676 */
__LABEL(l_L61X3);
  sim_icache_fetch(1716 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_16, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2677 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2678 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2679 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2680 */
   __MOV(reg_r0_17, (unsigned int) 257); /* line 2681 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2682 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2683 */
   __ADD_CYCLES(1);
} /* line 2683 */
  sim_icache_fetch(1726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2685 */
} /* line 2685 */
  sim_icache_fetch(1727 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2687 */
} /* line 2687 */
  sim_icache_fetch(1729 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2689 */
} /* line 2689 */
  sim_icache_fetch(1730 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2691 */
   __LDBU(reg_r0_16, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2692 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2693 */
   __ADD_CYCLES(1);
} /* line 2693 */
  sim_icache_fetch(1735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2695 */
} /* line 2695 */
  sim_icache_fetch(1736 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2697 */
} /* line 2697 */
  sim_icache_fetch(1738 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2699 */
} /* line 2699 */
  sim_icache_fetch(1739 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2701 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2702 */
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2703 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2704 */
   __ADD_CYCLES(1);
} /* line 2704 */
  sim_icache_fetch(1746 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_11, (unsigned int) 1); /* line 2706 */
   __OR(reg_r0_16, reg_r0_16, reg_r0_18); /* line 2707 */
} /* line 2707 */
  sim_icache_fetch(1748 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_19); /* line 2709 */
} /* line 2709 */
  sim_icache_fetch(1750 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2711 */
} /* line 2711 */
  sim_icache_fetch(1751 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2713 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2714 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2715 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2716 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2717 */
   __ADD_CYCLES(1);
} /* line 2717 */
  sim_icache_fetch(1760 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 2719 */
   __ADD(reg_r0_13, reg_r0_16, (unsigned int) -1); /* line 2720 */
   __ADD(reg_r0_15, reg_r0_14, (unsigned int) 1); /* line 2721 */
} /* line 2721 */
  sim_icache_fetch(1763 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_17, (unsigned int) 256); /* line 2723 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 2724 */
   __GOTO(l_L62X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L62X3;
} /* line 2725 */
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

  sim_icache_fetch(1767 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 2744 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2745 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2746 */
} /* line 2746 */
  sim_icache_fetch(1772 + t_thisfile.offset, 1);
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
} /* line 2748 */
  sim_icache_fetch(1773 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2750 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2751 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2752 */
} /* line 2752 */
  sim_icache_fetch(1776 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_15137Xbuf); /* line 2754 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_15137Xbuf),0,1)); /* line 2755 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_15137Xbuf + (unsigned int) 1)); /* line 2756 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2757 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2758 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2759 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2760 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2761 */
} /* line 2761 */
  sim_icache_fetch(1789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2763 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2764 */
} /* line 2764 */
  sim_icache_fetch(1791 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2766 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2767 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2768 */
} /* line 2768 */
  sim_icache_fetch(1794 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2770 */
} /* line 2770 */
  sim_icache_fetch(1795 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_15137Xbuf),0,1), reg_r0_2); /* line 2772 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2773 */
  sim_icache_fetch(1798 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2775 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2776 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2777 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2778 */
} /* line 2778 */
l_L168X3: ;/* line 2780 */
__LABEL(l_L168X3);
  sim_icache_fetch(1802 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2781 */
   __MOV(reg_r0_3, (unsigned int) compress_15137Xbuf); /* line 2782 */
} /* line 2782 */
  sim_icache_fetch(1805 + t_thisfile.offset, 1);
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
} /* line 2784 */
  sim_icache_fetch(1806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2786 */
} /* line 2786 */
l_L169X3: ;/* line 2788 */
__LABEL(l_L169X3);
  sim_icache_fetch(1807 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 2789 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2790 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2791 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2792 */
   __ADD_CYCLES(1);
} /* line 2792 */
  sim_icache_fetch(1814 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2794 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2795 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2796 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2797 */
} /* line 2797 */
  sim_icache_fetch(1818 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_15137Xoffset,0,4), reg_r0_2); /* line 2799 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2800 */
} /* line 2800 */
  sim_icache_fetch(1821 + t_thisfile.offset, 1);
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
} /* line 2802 */
  sim_icache_fetch(1822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2804 */
} /* line 2804 */
l_L171X3: ;/* line 2807 */
__LABEL(l_L171X3);
  sim_icache_fetch(1824 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2808 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2809 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2810 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2811 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2812 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2813 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2814 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2815 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2816 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2817 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -16); /* line 2818 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 16); /* line 2819 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2820 */
   __ADD_CYCLES(1);
} /* line 2820 */
  sim_icache_fetch(1838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2822 */
} /* line 2822 */
  sim_icache_fetch(1839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2824 */
} /* line 2824 */
  sim_icache_fetch(1841 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2826 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2827 */
  sim_icache_fetch(1843 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2829 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2830 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2831 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2832 */
   __ADD_CYCLES(1);
} /* line 2832 */
  sim_icache_fetch(1848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2834 */
} /* line 2834 */
  sim_icache_fetch(1849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2836 */
} /* line 2836 */
  sim_icache_fetch(1851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2838 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2839 */
  sim_icache_fetch(1853 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2841 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2842 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2843 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2844 */
   __ADD_CYCLES(1);
} /* line 2844 */
  sim_icache_fetch(1858 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2846 */
} /* line 2846 */
  sim_icache_fetch(1859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2848 */
} /* line 2848 */
  sim_icache_fetch(1861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2850 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2851 */
  sim_icache_fetch(1863 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2853 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2854 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2855 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2856 */
   __ADD_CYCLES(1);
} /* line 2856 */
  sim_icache_fetch(1868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2858 */
} /* line 2858 */
  sim_icache_fetch(1869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2860 */
} /* line 2860 */
  sim_icache_fetch(1871 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2862 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2863 */
  sim_icache_fetch(1873 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2865 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2866 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2867 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2868 */
   __ADD_CYCLES(1);
} /* line 2868 */
  sim_icache_fetch(1878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2870 */
} /* line 2870 */
  sim_icache_fetch(1879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2872 */
} /* line 2872 */
  sim_icache_fetch(1881 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2874 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2875 */
  sim_icache_fetch(1883 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2877 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2878 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2879 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2880 */
   __ADD_CYCLES(1);
} /* line 2880 */
  sim_icache_fetch(1888 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2882 */
} /* line 2882 */
  sim_icache_fetch(1889 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2884 */
} /* line 2884 */
  sim_icache_fetch(1891 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2886 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2887 */
  sim_icache_fetch(1893 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2889 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2890 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2891 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2892 */
   __ADD_CYCLES(1);
} /* line 2892 */
  sim_icache_fetch(1898 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2894 */
} /* line 2894 */
  sim_icache_fetch(1899 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2896 */
} /* line 2896 */
  sim_icache_fetch(1901 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2898 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2899 */
  sim_icache_fetch(1903 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2901 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2902 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2903 */
   __ADD(reg_r0_5, reg_r0_7, (unsigned int) -16); /* line 2904 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2905 */
   __ADD_CYCLES(1);
} /* line 2905 */
  sim_icache_fetch(1909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2907 */
} /* line 2907 */
  sim_icache_fetch(1910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2909 */
} /* line 2909 */
  sim_icache_fetch(1912 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2911 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2912 */
  sim_icache_fetch(1914 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2914 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2915 */
   __CMPEQ(reg_b0_7, reg_r0_7, 0); /* line 2916 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2917 */
   __ADD_CYCLES(1);
} /* line 2917 */
  sim_icache_fetch(1919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2919 */
} /* line 2919 */
  sim_icache_fetch(1920 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2921 */
} /* line 2921 */
  sim_icache_fetch(1922 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2923 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2924 */
  sim_icache_fetch(1924 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2926 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2927 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2928 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2929 */
   __ADD_CYCLES(1);
} /* line 2929 */
  sim_icache_fetch(1929 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2931 */
} /* line 2931 */
  sim_icache_fetch(1930 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2933 */
} /* line 2933 */
  sim_icache_fetch(1932 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2935 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2936 */
  sim_icache_fetch(1934 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 2938 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2939 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2940 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2941 */
   __ADD_CYCLES(1);
} /* line 2941 */
  sim_icache_fetch(1939 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2943 */
} /* line 2943 */
  sim_icache_fetch(1940 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2945 */
} /* line 2945 */
  sim_icache_fetch(1942 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2947 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2948 */
  sim_icache_fetch(1944 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 2950 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2951 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2952 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2953 */
   __ADD_CYCLES(1);
} /* line 2953 */
  sim_icache_fetch(1949 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2955 */
} /* line 2955 */
  sim_icache_fetch(1950 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2957 */
} /* line 2957 */
  sim_icache_fetch(1952 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2959 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2960 */
  sim_icache_fetch(1954 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 2962 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2963 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 4); /* line 2964 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2965 */
   __ADD_CYCLES(1);
} /* line 2965 */
  sim_icache_fetch(1959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2967 */
} /* line 2967 */
  sim_icache_fetch(1960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2969 */
} /* line 2969 */
  sim_icache_fetch(1962 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2971 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2972 */
  sim_icache_fetch(1964 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 2974 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2975 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 5); /* line 2976 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2977 */
   __ADD_CYCLES(1);
} /* line 2977 */
  sim_icache_fetch(1969 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2979 */
} /* line 2979 */
  sim_icache_fetch(1970 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2981 */
} /* line 2981 */
  sim_icache_fetch(1972 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2983 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2984 */
  sim_icache_fetch(1974 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 2986 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2987 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 6); /* line 2988 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2989 */
   __ADD_CYCLES(1);
} /* line 2989 */
  sim_icache_fetch(1979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2991 */
} /* line 2991 */
  sim_icache_fetch(1980 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2993 */
} /* line 2993 */
  sim_icache_fetch(1982 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2995 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2996 */
  sim_icache_fetch(1984 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 2998 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2999 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 7); /* line 3000 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3001 */
   __ADD_CYCLES(1);
} /* line 3001 */
  sim_icache_fetch(1989 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3003 */
} /* line 3003 */
  sim_icache_fetch(1990 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3005 */
} /* line 3005 */
  sim_icache_fetch(1992 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3007 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3008 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3009 */
  sim_icache_fetch(1995 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 3011 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3012 */
   __CMPEQ(reg_b0_7, reg_r0_7, (unsigned int) 8); /* line 3013 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) 16); /* line 3014 */
   __MFB(reg_r0_8, t__i32_0); /* line 3015 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3016 */
   __ADD_CYCLES(1);
} /* line 3016 */
  sim_icache_fetch(2002 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3018 */
} /* line 3018 */
  sim_icache_fetch(2003 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3020 */
} /* line 3020 */
  sim_icache_fetch(2005 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3022 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3023 */
  sim_icache_fetch(2007 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 3025 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3026 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 9); /* line 3027 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3028 */
   __ADD_CYCLES(1);
} /* line 3028 */
  sim_icache_fetch(2012 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3030 */
} /* line 3030 */
  sim_icache_fetch(2013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3032 */
} /* line 3032 */
  sim_icache_fetch(2015 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3034 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3035 */
  sim_icache_fetch(2017 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 2),0,1)); /* line 3037 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3038 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 10); /* line 3039 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3040 */
   __ADD_CYCLES(1);
} /* line 3040 */
  sim_icache_fetch(2022 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3042 */
} /* line 3042 */
  sim_icache_fetch(2023 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3044 */
} /* line 3044 */
  sim_icache_fetch(2025 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3046 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3047 */
  sim_icache_fetch(2027 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 3),0,1)); /* line 3049 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3050 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 11); /* line 3051 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3052 */
   __ADD_CYCLES(1);
} /* line 3052 */
  sim_icache_fetch(2032 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3054 */
} /* line 3054 */
  sim_icache_fetch(2033 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3056 */
} /* line 3056 */
  sim_icache_fetch(2035 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3058 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3059 */
  sim_icache_fetch(2037 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 4),0,1)); /* line 3061 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3062 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 12); /* line 3063 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3064 */
   __ADD_CYCLES(1);
} /* line 3064 */
  sim_icache_fetch(2042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3066 */
} /* line 3066 */
  sim_icache_fetch(2043 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3068 */
} /* line 3068 */
  sim_icache_fetch(2045 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3070 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3071 */
  sim_icache_fetch(2047 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 5),0,1)); /* line 3073 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3074 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 13); /* line 3075 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3076 */
   __ADD_CYCLES(1);
} /* line 3076 */
  sim_icache_fetch(2052 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3078 */
} /* line 3078 */
  sim_icache_fetch(2053 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3080 */
} /* line 3080 */
  sim_icache_fetch(2055 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3082 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3083 */
  sim_icache_fetch(2057 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 6),0,1)); /* line 3085 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3086 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 14); /* line 3087 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3088 */
   __ADD_CYCLES(1);
} /* line 3088 */
  sim_icache_fetch(2062 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3090 */
} /* line 3090 */
  sim_icache_fetch(2063 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3092 */
} /* line 3092 */
  sim_icache_fetch(2065 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3094 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3095 */
  sim_icache_fetch(2067 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 7),0,1)); /* line 3097 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3098 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 15); /* line 3099 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3100 */
   __ADD_CYCLES(1);
} /* line 3100 */
  sim_icache_fetch(2072 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3102 */
} /* line 3102 */
  sim_icache_fetch(2073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3104 */
} /* line 3104 */
  sim_icache_fetch(2075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3106 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3107 */
  sim_icache_fetch(2077 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 8),0,1)); /* line 3109 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3110 */
   __MTB(reg_b0_7, reg_r0_8); /* line 3111 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3112 */
   __ADD_CYCLES(1);
} /* line 3112 */
  sim_icache_fetch(2082 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3114 */
} /* line 3114 */
  sim_icache_fetch(2083 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3116 */
} /* line 3116 */
  sim_icache_fetch(2085 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3118 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3119 */
  sim_icache_fetch(2087 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 9),0,1)); /* line 3121 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3122 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3123 */
   __ADD_CYCLES(1);
} /* line 3123 */
  sim_icache_fetch(2091 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3125 */
} /* line 3125 */
  sim_icache_fetch(2092 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3127 */
} /* line 3127 */
  sim_icache_fetch(2094 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3129 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3130 */
  sim_icache_fetch(2096 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 10),0,1)); /* line 3132 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3133 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3134 */
   __ADD_CYCLES(1);
} /* line 3134 */
  sim_icache_fetch(2100 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3136 */
} /* line 3136 */
  sim_icache_fetch(2101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3138 */
} /* line 3138 */
  sim_icache_fetch(2103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3140 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3141 */
  sim_icache_fetch(2105 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 11),0,1)); /* line 3143 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3144 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3145 */
   __ADD_CYCLES(1);
} /* line 3145 */
  sim_icache_fetch(2109 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3147 */
} /* line 3147 */
  sim_icache_fetch(2110 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3149 */
} /* line 3149 */
  sim_icache_fetch(2112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3151 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3152 */
  sim_icache_fetch(2114 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 12),0,1)); /* line 3154 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3155 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3156 */
   __ADD_CYCLES(1);
} /* line 3156 */
  sim_icache_fetch(2118 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3158 */
} /* line 3158 */
  sim_icache_fetch(2119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3160 */
} /* line 3160 */
  sim_icache_fetch(2121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3162 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3163 */
  sim_icache_fetch(2123 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 13),0,1)); /* line 3165 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3166 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3167 */
   __ADD_CYCLES(1);
} /* line 3167 */
  sim_icache_fetch(2127 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3169 */
} /* line 3169 */
  sim_icache_fetch(2128 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3171 */
} /* line 3171 */
  sim_icache_fetch(2130 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3173 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3174 */
  sim_icache_fetch(2132 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 14),0,1)); /* line 3176 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3177 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3178 */
   __ADD_CYCLES(1);
} /* line 3178 */
  sim_icache_fetch(2136 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3180 */
} /* line 3180 */
  sim_icache_fetch(2137 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3182 */
} /* line 3182 */
  sim_icache_fetch(2139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3184 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3185 */
  sim_icache_fetch(2141 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 15),0,1)); /* line 3187 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3188 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3189 */
   __ADD_CYCLES(1);
} /* line 3189 */
  sim_icache_fetch(2145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3191 */
} /* line 3191 */
  sim_icache_fetch(2146 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3193 */
} /* line 3193 */
  sim_icache_fetch(2148 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 3195 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3197 */
  sim_icache_fetch(2150 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L171X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L171X3;
} /* line 3199 */
l_L172X3: ;/* line 3202 */
__LABEL(l_L172X3);
  sim_icache_fetch(2151 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_15137Xoffset,0,4), 0); /* line 3203 */
} /* line 3203 */
l_L170X3: ;/* line 3206 */
__LABEL(l_L170X3);
  sim_icache_fetch(2153 + t_thisfile.offset, 21);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3207 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3208 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3209 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3210 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3211 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3212 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3213 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3214 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3215 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3216 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3217 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3218 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3219 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3220 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3221 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3222 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3223 */
} /* line 3223 */
  sim_icache_fetch(2174 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3225 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3226 */
   __MOV(reg_r0_5, (unsigned int) compress_15137Xbuf); /* line 3227 */
   __MOV(reg_r0_3, 0); /* line 3228 */
} /* line 3228 */
  sim_icache_fetch(2179 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3230 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3231 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3232 */
} /* line 3232 */
  sim_icache_fetch(2182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3234 */
} /* line 3234 */
  sim_icache_fetch(2183 + t_thisfile.offset, 1);
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
} /* line 3236 */
  sim_icache_fetch(2184 + t_thisfile.offset, 1);
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
} /* line 3238 */
l_L175X3: ;/* line 3241 */
__LABEL(l_L175X3);
  sim_icache_fetch(2185 + t_thisfile.offset, 19);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3242 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3243 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3244 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3245 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3246 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3247 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3248 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3249 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3250 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3251 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3252 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3253 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3254 */
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3255 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3256 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3257 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3258 */
} /* line 3258 */
  sim_icache_fetch(2204 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3260 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3261 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3262 */
} /* line 3262 */
  sim_icache_fetch(2207 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3264 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3265 */
   __ADD(reg_r0_3, reg_r0_38, (unsigned int) 16); /* line 3266 */
} /* line 3266 */
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
} /* line 3268 */
  sim_icache_fetch(2211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3270 */
} /* line 3270 */
  sim_icache_fetch(2213 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3272 */
} /* line 3272 */
  sim_icache_fetch(2214 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3274 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3275 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3276 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3277 */
   __ADD_CYCLES(1);
} /* line 3277 */
  sim_icache_fetch(2220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 3279 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3280 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3281 */
} /* line 3281 */
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
} /* line 3283 */
  sim_icache_fetch(2224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3285 */
} /* line 3285 */
  sim_icache_fetch(2226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3287 */
} /* line 3287 */
  sim_icache_fetch(2227 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3289 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3290 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3291 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3292 */
   __ADD_CYCLES(1);
} /* line 3292 */
  sim_icache_fetch(2233 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 3294 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3295 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3296 */
} /* line 3296 */
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
} /* line 3298 */
  sim_icache_fetch(2237 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3300 */
} /* line 3300 */
  sim_icache_fetch(2239 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3302 */
} /* line 3302 */
  sim_icache_fetch(2240 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3304 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3305 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3306 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3307 */
   __ADD_CYCLES(1);
} /* line 3307 */
  sim_icache_fetch(2246 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 3309 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3310 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3311 */
} /* line 3311 */
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
} /* line 3313 */
  sim_icache_fetch(2250 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3315 */
} /* line 3315 */
  sim_icache_fetch(2252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3317 */
} /* line 3317 */
  sim_icache_fetch(2253 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3319 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3320 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3321 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3322 */
   __ADD_CYCLES(1);
} /* line 3322 */
  sim_icache_fetch(2259 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 3324 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3325 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3326 */
} /* line 3326 */
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
} /* line 3328 */
  sim_icache_fetch(2263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3330 */
} /* line 3330 */
  sim_icache_fetch(2265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3332 */
} /* line 3332 */
  sim_icache_fetch(2266 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3334 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3335 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3336 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3337 */
   __ADD_CYCLES(1);
} /* line 3337 */
  sim_icache_fetch(2272 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 3339 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3340 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3341 */
} /* line 3341 */
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
} /* line 3343 */
  sim_icache_fetch(2276 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3345 */
} /* line 3345 */
  sim_icache_fetch(2278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3347 */
} /* line 3347 */
  sim_icache_fetch(2279 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3349 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3350 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3351 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3352 */
   __ADD_CYCLES(1);
} /* line 3352 */
  sim_icache_fetch(2285 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 3354 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3355 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3356 */
} /* line 3356 */
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
} /* line 3358 */
  sim_icache_fetch(2289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3360 */
} /* line 3360 */
  sim_icache_fetch(2291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3362 */
} /* line 3362 */
  sim_icache_fetch(2292 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3364 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3365 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3366 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3367 */
   __ADD_CYCLES(1);
} /* line 3367 */
  sim_icache_fetch(2298 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 3369 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3370 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3371 */
} /* line 3371 */
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
} /* line 3373 */
  sim_icache_fetch(2302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3375 */
} /* line 3375 */
  sim_icache_fetch(2304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3377 */
} /* line 3377 */
  sim_icache_fetch(2305 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3379 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3380 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3381 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3382 */
   __ADD_CYCLES(1);
} /* line 3382 */
  sim_icache_fetch(2311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 3384 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3385 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3386 */
} /* line 3386 */
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
} /* line 3388 */
  sim_icache_fetch(2315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3390 */
} /* line 3390 */
  sim_icache_fetch(2317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3392 */
} /* line 3392 */
  sim_icache_fetch(2318 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3394 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3395 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3396 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3397 */
   __ADD_CYCLES(1);
} /* line 3397 */
  sim_icache_fetch(2324 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 3399 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3400 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3401 */
} /* line 3401 */
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
} /* line 3403 */
  sim_icache_fetch(2328 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3405 */
} /* line 3405 */
  sim_icache_fetch(2330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3407 */
} /* line 3407 */
  sim_icache_fetch(2331 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3409 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3410 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3411 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3412 */
   __ADD_CYCLES(1);
} /* line 3412 */
  sim_icache_fetch(2337 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 3414 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3415 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3416 */
} /* line 3416 */
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
} /* line 3418 */
  sim_icache_fetch(2341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3420 */
} /* line 3420 */
  sim_icache_fetch(2343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3422 */
} /* line 3422 */
  sim_icache_fetch(2344 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3424 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3425 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3426 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3427 */
   __ADD_CYCLES(1);
} /* line 3427 */
  sim_icache_fetch(2350 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 3429 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3430 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3431 */
} /* line 3431 */
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
} /* line 3433 */
  sim_icache_fetch(2354 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3435 */
} /* line 3435 */
  sim_icache_fetch(2356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3437 */
} /* line 3437 */
  sim_icache_fetch(2357 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3439 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3440 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3441 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3442 */
   __ADD_CYCLES(1);
} /* line 3442 */
  sim_icache_fetch(2363 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 3444 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3445 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3446 */
} /* line 3446 */
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
} /* line 3448 */
  sim_icache_fetch(2367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3450 */
} /* line 3450 */
  sim_icache_fetch(2369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3452 */
} /* line 3452 */
  sim_icache_fetch(2370 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3454 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3455 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3456 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3457 */
   __ADD_CYCLES(1);
} /* line 3457 */
  sim_icache_fetch(2376 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 3459 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3460 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3461 */
} /* line 3461 */
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
} /* line 3463 */
  sim_icache_fetch(2380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3465 */
} /* line 3465 */
  sim_icache_fetch(2382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3467 */
} /* line 3467 */
  sim_icache_fetch(2383 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3469 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3470 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3471 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3472 */
   __ADD_CYCLES(1);
} /* line 3472 */
  sim_icache_fetch(2389 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_2); /* line 3474 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3475 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3476 */
} /* line 3476 */
  sim_icache_fetch(2392 + t_thisfile.offset, 1);
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
} /* line 3478 */
  sim_icache_fetch(2393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3480 */
} /* line 3480 */
  sim_icache_fetch(2395 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3482 */
} /* line 3482 */
  sim_icache_fetch(2396 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3484 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3485 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3486 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3487 */
   __ADD_CYCLES(1);
} /* line 3487 */
  sim_icache_fetch(2402 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_2); /* line 3489 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3490 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3491 */
} /* line 3491 */
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
} /* line 3493 */
  sim_icache_fetch(2406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3495 */
} /* line 3495 */
  sim_icache_fetch(2408 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_5); /* line 3497 */
} /* line 3497 */
  sim_icache_fetch(2409 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3499 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_37,0,1)); /* line 3500 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3501 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3502 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3503 */
   __ADD_CYCLES(1);
} /* line 3503 */
  sim_icache_fetch(2416 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_38, reg_r0_2); /* line 3505 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3506 */
} /* line 3506 */
  sim_icache_fetch(2418 + t_thisfile.offset, 1);
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
} /* line 3508 */
  sim_icache_fetch(2419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3510 */
} /* line 3510 */
  sim_icache_fetch(2421 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3512 */
} /* line 3512 */
  sim_icache_fetch(2422 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3514 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3515 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3516 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3517 */
   __ADD_CYCLES(1);
} /* line 3517 */
  sim_icache_fetch(2428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3519 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3520 */
} /* line 3520 */
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
} /* line 3522 */
  sim_icache_fetch(2431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3524 */
} /* line 3524 */
  sim_icache_fetch(2433 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3526 */
} /* line 3526 */
  sim_icache_fetch(2434 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3528 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3529 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3530 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3531 */
   __ADD_CYCLES(1);
} /* line 3531 */
  sim_icache_fetch(2440 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3533 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3534 */
} /* line 3534 */
  sim_icache_fetch(2442 + t_thisfile.offset, 1);
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
} /* line 3536 */
  sim_icache_fetch(2443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3538 */
} /* line 3538 */
  sim_icache_fetch(2445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3540 */
} /* line 3540 */
  sim_icache_fetch(2446 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3542 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3543 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3544 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3545 */
   __ADD_CYCLES(1);
} /* line 3545 */
  sim_icache_fetch(2452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3547 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3548 */
} /* line 3548 */
  sim_icache_fetch(2454 + t_thisfile.offset, 1);
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
} /* line 3550 */
  sim_icache_fetch(2455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3552 */
} /* line 3552 */
  sim_icache_fetch(2457 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3554 */
} /* line 3554 */
  sim_icache_fetch(2458 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3556 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3557 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3558 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3559 */
   __ADD_CYCLES(1);
} /* line 3559 */
  sim_icache_fetch(2464 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3561 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3562 */
} /* line 3562 */
  sim_icache_fetch(2466 + t_thisfile.offset, 1);
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
} /* line 3564 */
  sim_icache_fetch(2467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3566 */
} /* line 3566 */
  sim_icache_fetch(2469 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3568 */
} /* line 3568 */
  sim_icache_fetch(2470 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3570 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3571 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3572 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3573 */
   __ADD_CYCLES(1);
} /* line 3573 */
  sim_icache_fetch(2476 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3575 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3576 */
} /* line 3576 */
  sim_icache_fetch(2478 + t_thisfile.offset, 1);
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
} /* line 3578 */
  sim_icache_fetch(2479 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3580 */
} /* line 3580 */
  sim_icache_fetch(2481 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3582 */
} /* line 3582 */
  sim_icache_fetch(2482 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3584 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3585 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3586 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3587 */
   __ADD_CYCLES(1);
} /* line 3587 */
  sim_icache_fetch(2488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3589 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3590 */
} /* line 3590 */
  sim_icache_fetch(2490 + t_thisfile.offset, 1);
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
} /* line 3592 */
  sim_icache_fetch(2491 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3594 */
} /* line 3594 */
  sim_icache_fetch(2493 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3596 */
} /* line 3596 */
  sim_icache_fetch(2494 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3598 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3599 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3600 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3601 */
   __ADD_CYCLES(1);
} /* line 3601 */
  sim_icache_fetch(2500 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3603 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3604 */
} /* line 3604 */
  sim_icache_fetch(2502 + t_thisfile.offset, 1);
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
} /* line 3606 */
  sim_icache_fetch(2503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3608 */
} /* line 3608 */
  sim_icache_fetch(2505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3610 */
} /* line 3610 */
  sim_icache_fetch(2506 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3612 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3613 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3614 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3615 */
   __ADD_CYCLES(1);
} /* line 3615 */
  sim_icache_fetch(2512 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3617 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3618 */
} /* line 3618 */
  sim_icache_fetch(2514 + t_thisfile.offset, 1);
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
} /* line 3620 */
  sim_icache_fetch(2515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3622 */
} /* line 3622 */
  sim_icache_fetch(2517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3624 */
} /* line 3624 */
  sim_icache_fetch(2518 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3626 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3627 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3628 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3629 */
   __ADD_CYCLES(1);
} /* line 3629 */
  sim_icache_fetch(2524 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3631 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3632 */
} /* line 3632 */
  sim_icache_fetch(2526 + t_thisfile.offset, 1);
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
} /* line 3634 */
  sim_icache_fetch(2527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3636 */
} /* line 3636 */
  sim_icache_fetch(2529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3638 */
} /* line 3638 */
  sim_icache_fetch(2530 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3640 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3641 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3642 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3643 */
   __ADD_CYCLES(1);
} /* line 3643 */
  sim_icache_fetch(2536 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3645 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3646 */
} /* line 3646 */
  sim_icache_fetch(2538 + t_thisfile.offset, 1);
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
} /* line 3648 */
  sim_icache_fetch(2539 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3650 */
} /* line 3650 */
  sim_icache_fetch(2541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3652 */
} /* line 3652 */
  sim_icache_fetch(2542 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3654 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3655 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3656 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3657 */
   __ADD_CYCLES(1);
} /* line 3657 */
  sim_icache_fetch(2548 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3659 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3660 */
} /* line 3660 */
  sim_icache_fetch(2550 + t_thisfile.offset, 1);
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
} /* line 3662 */
  sim_icache_fetch(2551 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3664 */
} /* line 3664 */
  sim_icache_fetch(2553 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3666 */
} /* line 3666 */
  sim_icache_fetch(2554 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3668 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3669 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3670 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3671 */
   __ADD_CYCLES(1);
} /* line 3671 */
  sim_icache_fetch(2560 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3673 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3674 */
} /* line 3674 */
  sim_icache_fetch(2562 + t_thisfile.offset, 1);
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
} /* line 3676 */
  sim_icache_fetch(2563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3678 */
} /* line 3678 */
  sim_icache_fetch(2565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3680 */
} /* line 3680 */
  sim_icache_fetch(2566 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3682 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3683 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3684 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3685 */
   __ADD_CYCLES(1);
} /* line 3685 */
  sim_icache_fetch(2572 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3687 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3688 */
} /* line 3688 */
  sim_icache_fetch(2574 + t_thisfile.offset, 1);
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
} /* line 3690 */
  sim_icache_fetch(2575 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3692 */
} /* line 3692 */
  sim_icache_fetch(2577 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3694 */
} /* line 3694 */
  sim_icache_fetch(2578 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3696 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3697 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3698 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3699 */
   __ADD_CYCLES(1);
} /* line 3699 */
  sim_icache_fetch(2584 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3701 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3702 */
} /* line 3702 */
  sim_icache_fetch(2586 + t_thisfile.offset, 1);
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
} /* line 3704 */
  sim_icache_fetch(2587 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3706 */
} /* line 3706 */
  sim_icache_fetch(2589 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3708 */
} /* line 3708 */
  sim_icache_fetch(2590 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3710 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3711 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3712 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3713 */
   __ADD_CYCLES(1);
} /* line 3713 */
  sim_icache_fetch(2596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3715 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3716 */
} /* line 3716 */
  sim_icache_fetch(2598 + t_thisfile.offset, 1);
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
} /* line 3718 */
  sim_icache_fetch(2599 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3720 */
} /* line 3720 */
  sim_icache_fetch(2601 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3722 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 3723 */
l_L176X3: ;/* line 3726 */
__LABEL(l_L176X3);
  sim_icache_fetch(2603 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3727 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3728 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3729 */
   __ADD_CYCLES(1);
} /* line 3729 */
  sim_icache_fetch(2608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3731 */
} /* line 3731 */
  sim_icache_fetch(2609 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3733 */
} /* line 3733 */
l_L174X3: ;/* line 3736 */
__LABEL(l_L174X3);
  sim_icache_fetch(2611 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_15137Xoffset,0,4), 0); /* line 3737 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3738 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3739 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3740 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3741 */
   __ADD_CYCLES(1);
} /* line 3741 */
  sim_icache_fetch(2619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3743 */
} /* line 3743 */
  sim_icache_fetch(2620 + t_thisfile.offset, 1);
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
} /* line 3745 */
  sim_icache_fetch(2621 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3748 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3749 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3750 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3751 */
l_L177X3: ;/* line 3754 */
__LABEL(l_L177X3);
  sim_icache_fetch(2628 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3755 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3756 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3757 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3758 */
   __ADD_CYCLES(1);
} /* line 3758 */
  sim_icache_fetch(2635 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3760 */
} /* line 3760 */
  sim_icache_fetch(2636 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3762 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3763 */
} /* line 3763 */
  sim_icache_fetch(2639 + t_thisfile.offset, 1);
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
} /* line 3765 */
  sim_icache_fetch(2640 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3768 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3769 */
l_L178X3: ;/* line 3772 */
__LABEL(l_L178X3);
  sim_icache_fetch(2643 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3773 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3774 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3775 */
   __ADD_CYCLES(1);
} /* line 3775 */
  sim_icache_fetch(2647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3777 */
} /* line 3777 */
  sim_icache_fetch(2648 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3779 */
} /* line 3779 */
  sim_icache_fetch(2649 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3782 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3783 */
l_L173X3: ;/* line 3786 */
__LABEL(l_L173X3);
  sim_icache_fetch(2652 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3788 */
l_L167X3: ;/* line 3791 */
__LABEL(l_L167X3);
  sim_icache_fetch(2653 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3792 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3793 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3794 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3795 */
   __ADD_CYCLES(1);
} /* line 3795 */
  sim_icache_fetch(2660 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3797 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3798 */
} /* line 3798 */
  sim_icache_fetch(2662 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3800 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3801 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3802 */
l_L180X3: ;/* line 3804 */
__LABEL(l_L180X3);
  sim_icache_fetch(2665 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3805 */
   __STW(mem_trace_st((unsigned int) compress_15137Xoffset,0,4), 0); /* line 3806 */
} /* line 3806 */
  sim_icache_fetch(2668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(2669 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3810 */
} /* line 3810 */
  sim_icache_fetch(2670 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3813 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3814 */
l_L179X3: ;/* line 3817 */
__LABEL(l_L179X3);
  sim_icache_fetch(2673 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3818 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3819 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3820 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3821 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3822 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3823 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3824 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3825 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3826 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3827 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3828 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3829 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3830 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3831 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3832 */
   __MOV(reg_r0_5, (unsigned int) compress_15137Xbuf); /* line 3833 */
   __MOV(reg_r0_3, 0); /* line 3834 */
} /* line 3834 */
l_L181X3: ;/* line 3837 */
__LABEL(l_L181X3);
  sim_icache_fetch(2691 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3838 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3839 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3840 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3841 */
   __ADD_CYCLES(1);
} /* line 3841 */
  sim_icache_fetch(2697 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3843 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3844 */
} /* line 3844 */
  sim_icache_fetch(2699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3846 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3847 */
} /* line 3847 */
  sim_icache_fetch(2701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3849 */
} /* line 3849 */
  sim_icache_fetch(2702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3851 */
} /* line 3851 */
  sim_icache_fetch(2703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3853 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3854 */
} /* line 3854 */
  sim_icache_fetch(2705 + t_thisfile.offset, 1);
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
} /* line 3856 */
  sim_icache_fetch(2706 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3858 */
} /* line 3858 */
  sim_icache_fetch(2708 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3860 */
} /* line 3860 */
  sim_icache_fetch(2709 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3862 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3863 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3864 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3865 */
   __ADD_CYCLES(1);
} /* line 3865 */
  sim_icache_fetch(2715 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3867 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3868 */
} /* line 3868 */
  sim_icache_fetch(2717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3870 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3871 */
} /* line 3871 */
  sim_icache_fetch(2719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3873 */
} /* line 3873 */
  sim_icache_fetch(2720 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3875 */
} /* line 3875 */
  sim_icache_fetch(2721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3877 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3878 */
} /* line 3878 */
  sim_icache_fetch(2723 + t_thisfile.offset, 1);
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
} /* line 3880 */
  sim_icache_fetch(2724 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3882 */
} /* line 3882 */
  sim_icache_fetch(2726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3884 */
} /* line 3884 */
  sim_icache_fetch(2727 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3886 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3887 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3888 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3889 */
   __ADD_CYCLES(1);
} /* line 3889 */
  sim_icache_fetch(2733 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3891 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3892 */
} /* line 3892 */
  sim_icache_fetch(2735 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3894 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3895 */
} /* line 3895 */
  sim_icache_fetch(2737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3897 */
} /* line 3897 */
  sim_icache_fetch(2738 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3899 */
} /* line 3899 */
  sim_icache_fetch(2739 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3901 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3902 */
} /* line 3902 */
  sim_icache_fetch(2741 + t_thisfile.offset, 1);
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
} /* line 3904 */
  sim_icache_fetch(2742 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3906 */
} /* line 3906 */
  sim_icache_fetch(2744 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3908 */
} /* line 3908 */
  sim_icache_fetch(2745 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3910 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3911 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3912 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3913 */
   __ADD_CYCLES(1);
} /* line 3913 */
  sim_icache_fetch(2751 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3915 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3916 */
} /* line 3916 */
  sim_icache_fetch(2753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3918 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3919 */
} /* line 3919 */
  sim_icache_fetch(2755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3921 */
} /* line 3921 */
  sim_icache_fetch(2756 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3923 */
} /* line 3923 */
  sim_icache_fetch(2757 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3925 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3926 */
} /* line 3926 */
  sim_icache_fetch(2759 + t_thisfile.offset, 1);
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
} /* line 3928 */
  sim_icache_fetch(2760 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3930 */
} /* line 3930 */
  sim_icache_fetch(2762 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3932 */
} /* line 3932 */
  sim_icache_fetch(2763 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3934 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3935 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3936 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3937 */
   __ADD_CYCLES(1);
} /* line 3937 */
  sim_icache_fetch(2769 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3939 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3940 */
} /* line 3940 */
  sim_icache_fetch(2771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3942 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3943 */
} /* line 3943 */
  sim_icache_fetch(2773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3945 */
} /* line 3945 */
  sim_icache_fetch(2774 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3947 */
} /* line 3947 */
  sim_icache_fetch(2775 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 3949 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3950 */
} /* line 3950 */
  sim_icache_fetch(2777 + t_thisfile.offset, 1);
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
} /* line 3952 */
  sim_icache_fetch(2778 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3954 */
} /* line 3954 */
  sim_icache_fetch(2780 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3956 */
} /* line 3956 */
  sim_icache_fetch(2781 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3958 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3959 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3960 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3961 */
   __ADD_CYCLES(1);
} /* line 3961 */
  sim_icache_fetch(2787 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3963 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3964 */
} /* line 3964 */
  sim_icache_fetch(2789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3966 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3967 */
} /* line 3967 */
  sim_icache_fetch(2791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3969 */
} /* line 3969 */
  sim_icache_fetch(2792 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3971 */
} /* line 3971 */
  sim_icache_fetch(2793 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 3973 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3974 */
} /* line 3974 */
  sim_icache_fetch(2795 + t_thisfile.offset, 1);
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
} /* line 3976 */
  sim_icache_fetch(2796 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3978 */
} /* line 3978 */
  sim_icache_fetch(2798 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3980 */
} /* line 3980 */
  sim_icache_fetch(2799 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 3982 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3983 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3984 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3985 */
   __ADD_CYCLES(1);
} /* line 3985 */
  sim_icache_fetch(2805 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3987 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3988 */
} /* line 3988 */
  sim_icache_fetch(2807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3990 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3991 */
} /* line 3991 */
  sim_icache_fetch(2809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3993 */
} /* line 3993 */
  sim_icache_fetch(2810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3995 */
} /* line 3995 */
  sim_icache_fetch(2811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 3997 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 3998 */
} /* line 3998 */
  sim_icache_fetch(2813 + t_thisfile.offset, 1);
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
} /* line 4000 */
  sim_icache_fetch(2814 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4002 */
} /* line 4002 */
  sim_icache_fetch(2816 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4004 */
} /* line 4004 */
  sim_icache_fetch(2817 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4006 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4007 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4008 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4009 */
   __ADD_CYCLES(1);
} /* line 4009 */
  sim_icache_fetch(2823 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4011 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4012 */
} /* line 4012 */
  sim_icache_fetch(2825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4014 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4015 */
} /* line 4015 */
  sim_icache_fetch(2827 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4017 */
} /* line 4017 */
  sim_icache_fetch(2828 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4019 */
} /* line 4019 */
  sim_icache_fetch(2829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4021 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4022 */
} /* line 4022 */
  sim_icache_fetch(2831 + t_thisfile.offset, 1);
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
} /* line 4024 */
  sim_icache_fetch(2832 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4026 */
} /* line 4026 */
  sim_icache_fetch(2834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4028 */
} /* line 4028 */
  sim_icache_fetch(2835 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4030 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4031 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4032 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4033 */
   __ADD_CYCLES(1);
} /* line 4033 */
  sim_icache_fetch(2841 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4035 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4036 */
} /* line 4036 */
  sim_icache_fetch(2843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4038 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4039 */
} /* line 4039 */
  sim_icache_fetch(2845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4041 */
} /* line 4041 */
  sim_icache_fetch(2846 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4043 */
} /* line 4043 */
  sim_icache_fetch(2847 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4045 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4046 */
} /* line 4046 */
  sim_icache_fetch(2849 + t_thisfile.offset, 1);
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
} /* line 4048 */
  sim_icache_fetch(2850 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4050 */
} /* line 4050 */
  sim_icache_fetch(2852 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4052 */
} /* line 4052 */
  sim_icache_fetch(2853 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4054 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4055 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4056 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4057 */
   __ADD_CYCLES(1);
} /* line 4057 */
  sim_icache_fetch(2859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4059 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4060 */
} /* line 4060 */
  sim_icache_fetch(2861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4062 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4063 */
} /* line 4063 */
  sim_icache_fetch(2863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4065 */
} /* line 4065 */
  sim_icache_fetch(2864 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4067 */
} /* line 4067 */
  sim_icache_fetch(2865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4069 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4070 */
} /* line 4070 */
  sim_icache_fetch(2867 + t_thisfile.offset, 1);
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
} /* line 4072 */
  sim_icache_fetch(2868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4074 */
} /* line 4074 */
  sim_icache_fetch(2870 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4076 */
} /* line 4076 */
  sim_icache_fetch(2871 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4078 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4079 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4080 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4081 */
   __ADD_CYCLES(1);
} /* line 4081 */
  sim_icache_fetch(2877 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4083 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4084 */
} /* line 4084 */
  sim_icache_fetch(2879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4086 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4087 */
} /* line 4087 */
  sim_icache_fetch(2881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4089 */
} /* line 4089 */
  sim_icache_fetch(2882 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4091 */
} /* line 4091 */
  sim_icache_fetch(2883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4093 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4094 */
} /* line 4094 */
  sim_icache_fetch(2885 + t_thisfile.offset, 1);
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
} /* line 4096 */
  sim_icache_fetch(2886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4098 */
} /* line 4098 */
  sim_icache_fetch(2888 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4100 */
} /* line 4100 */
  sim_icache_fetch(2889 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4102 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4103 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4104 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4105 */
   __ADD_CYCLES(1);
} /* line 4105 */
  sim_icache_fetch(2895 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4107 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4108 */
} /* line 4108 */
  sim_icache_fetch(2897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4110 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4111 */
} /* line 4111 */
  sim_icache_fetch(2899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4113 */
} /* line 4113 */
  sim_icache_fetch(2900 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4115 */
} /* line 4115 */
  sim_icache_fetch(2901 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4117 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4118 */
} /* line 4118 */
  sim_icache_fetch(2903 + t_thisfile.offset, 1);
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
} /* line 4120 */
  sim_icache_fetch(2904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4122 */
} /* line 4122 */
  sim_icache_fetch(2906 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4124 */
} /* line 4124 */
  sim_icache_fetch(2907 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4126 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4127 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4128 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4129 */
   __ADD_CYCLES(1);
} /* line 4129 */
  sim_icache_fetch(2913 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4131 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4132 */
} /* line 4132 */
  sim_icache_fetch(2915 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4134 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4135 */
} /* line 4135 */
  sim_icache_fetch(2917 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4137 */
} /* line 4137 */
  sim_icache_fetch(2918 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4139 */
} /* line 4139 */
  sim_icache_fetch(2919 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4141 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4142 */
} /* line 4142 */
  sim_icache_fetch(2921 + t_thisfile.offset, 1);
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
} /* line 4144 */
  sim_icache_fetch(2922 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4146 */
} /* line 4146 */
  sim_icache_fetch(2924 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4148 */
} /* line 4148 */
  sim_icache_fetch(2925 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4150 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4151 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4152 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4153 */
   __ADD_CYCLES(1);
} /* line 4153 */
  sim_icache_fetch(2931 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4155 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4156 */
} /* line 4156 */
  sim_icache_fetch(2933 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4158 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4159 */
} /* line 4159 */
  sim_icache_fetch(2935 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4161 */
} /* line 4161 */
  sim_icache_fetch(2936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4163 */
} /* line 4163 */
  sim_icache_fetch(2937 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4165 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4166 */
} /* line 4166 */
  sim_icache_fetch(2939 + t_thisfile.offset, 1);
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
} /* line 4168 */
  sim_icache_fetch(2940 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4170 */
} /* line 4170 */
  sim_icache_fetch(2942 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4172 */
} /* line 4172 */
  sim_icache_fetch(2943 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4174 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4175 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4176 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4177 */
   __ADD_CYCLES(1);
} /* line 4177 */
  sim_icache_fetch(2949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4179 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4180 */
} /* line 4180 */
  sim_icache_fetch(2951 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4182 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4183 */
} /* line 4183 */
  sim_icache_fetch(2953 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4185 */
} /* line 4185 */
  sim_icache_fetch(2954 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4187 */
} /* line 4187 */
  sim_icache_fetch(2955 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4189 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4190 */
} /* line 4190 */
  sim_icache_fetch(2957 + t_thisfile.offset, 1);
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
} /* line 4192 */
  sim_icache_fetch(2958 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4194 */
} /* line 4194 */
  sim_icache_fetch(2960 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4196 */
} /* line 4196 */
  sim_icache_fetch(2961 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4198 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4199 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4200 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4201 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4202 */
   __ADD_CYCLES(1);
} /* line 4202 */
  sim_icache_fetch(2968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4204 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4205 */
} /* line 4205 */
  sim_icache_fetch(2970 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4207 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4208 */
} /* line 4208 */
  sim_icache_fetch(2972 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4210 */
} /* line 4210 */
  sim_icache_fetch(2973 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4212 */
} /* line 4212 */
  sim_icache_fetch(2974 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4214 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4215 */
} /* line 4215 */
  sim_icache_fetch(2976 + t_thisfile.offset, 1);
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
} /* line 4217 */
  sim_icache_fetch(2977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4219 */
} /* line 4219 */
  sim_icache_fetch(2979 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4221 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4222 */
l_L197X3: ;/* line 4225 */
__LABEL(l_L197X3);
  sim_icache_fetch(2981 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4226 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4227 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4228 */
   __ADD_CYCLES(1);
} /* line 4228 */
  sim_icache_fetch(2986 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4230 */
} /* line 4230 */
  sim_icache_fetch(2987 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4232 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4233 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4234 */
l_L196X3: ;/* line 4237 */
__LABEL(l_L196X3);
  sim_icache_fetch(2990 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4238 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4239 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4240 */
   __ADD_CYCLES(1);
} /* line 4240 */
  sim_icache_fetch(2995 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4242 */
} /* line 4242 */
  sim_icache_fetch(2996 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4244 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4245 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4246 */
l_L195X3: ;/* line 4249 */
__LABEL(l_L195X3);
  sim_icache_fetch(2999 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4250 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4251 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4252 */
   __ADD_CYCLES(1);
} /* line 4252 */
  sim_icache_fetch(3004 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4254 */
} /* line 4254 */
  sim_icache_fetch(3005 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4256 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4257 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4258 */
l_L194X3: ;/* line 4261 */
__LABEL(l_L194X3);
  sim_icache_fetch(3008 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4262 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4263 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4264 */
   __ADD_CYCLES(1);
} /* line 4264 */
  sim_icache_fetch(3013 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4266 */
} /* line 4266 */
  sim_icache_fetch(3014 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4268 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4269 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4270 */
l_L193X3: ;/* line 4273 */
__LABEL(l_L193X3);
  sim_icache_fetch(3017 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4274 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4275 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4276 */
   __ADD_CYCLES(1);
} /* line 4276 */
  sim_icache_fetch(3022 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4278 */
} /* line 4278 */
  sim_icache_fetch(3023 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4280 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4281 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4282 */
l_L192X3: ;/* line 4285 */
__LABEL(l_L192X3);
  sim_icache_fetch(3026 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4286 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4287 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4288 */
   __ADD_CYCLES(1);
} /* line 4288 */
  sim_icache_fetch(3031 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4290 */
} /* line 4290 */
  sim_icache_fetch(3032 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4292 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4293 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4294 */
l_L191X3: ;/* line 4297 */
__LABEL(l_L191X3);
  sim_icache_fetch(3035 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4298 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4299 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4300 */
   __ADD_CYCLES(1);
} /* line 4300 */
  sim_icache_fetch(3040 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4302 */
} /* line 4302 */
  sim_icache_fetch(3041 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4304 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4305 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4306 */
l_L190X3: ;/* line 4309 */
__LABEL(l_L190X3);
  sim_icache_fetch(3044 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4310 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4311 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4312 */
   __ADD_CYCLES(1);
} /* line 4312 */
  sim_icache_fetch(3049 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4314 */
} /* line 4314 */
  sim_icache_fetch(3050 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4316 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4317 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4318 */
l_L189X3: ;/* line 4321 */
__LABEL(l_L189X3);
  sim_icache_fetch(3053 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4322 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4323 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4324 */
   __ADD_CYCLES(1);
} /* line 4324 */
  sim_icache_fetch(3058 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4326 */
} /* line 4326 */
  sim_icache_fetch(3059 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4328 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4329 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4330 */
l_L188X3: ;/* line 4333 */
__LABEL(l_L188X3);
  sim_icache_fetch(3062 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4334 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4335 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4336 */
   __ADD_CYCLES(1);
} /* line 4336 */
  sim_icache_fetch(3067 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4338 */
} /* line 4338 */
  sim_icache_fetch(3068 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4340 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4341 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4342 */
l_L187X3: ;/* line 4345 */
__LABEL(l_L187X3);
  sim_icache_fetch(3071 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4346 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4347 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4348 */
   __ADD_CYCLES(1);
} /* line 4348 */
  sim_icache_fetch(3076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4350 */
} /* line 4350 */
  sim_icache_fetch(3077 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4352 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4353 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4354 */
l_L186X3: ;/* line 4357 */
__LABEL(l_L186X3);
  sim_icache_fetch(3080 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4358 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4359 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4360 */
   __ADD_CYCLES(1);
} /* line 4360 */
  sim_icache_fetch(3085 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4362 */
} /* line 4362 */
  sim_icache_fetch(3086 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4364 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4365 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4366 */
l_L185X3: ;/* line 4369 */
__LABEL(l_L185X3);
  sim_icache_fetch(3089 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4370 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4371 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4372 */
   __ADD_CYCLES(1);
} /* line 4372 */
  sim_icache_fetch(3094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4374 */
} /* line 4374 */
  sim_icache_fetch(3095 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4376 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4377 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4378 */
l_L184X3: ;/* line 4381 */
__LABEL(l_L184X3);
  sim_icache_fetch(3098 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4382 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4383 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4384 */
   __ADD_CYCLES(1);
} /* line 4384 */
  sim_icache_fetch(3103 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4386 */
} /* line 4386 */
  sim_icache_fetch(3104 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4388 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4389 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4390 */
l_L183X3: ;/* line 4393 */
__LABEL(l_L183X3);
  sim_icache_fetch(3107 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4394 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4395 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4396 */
   __ADD_CYCLES(1);
} /* line 4396 */
  sim_icache_fetch(3112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4398 */
} /* line 4398 */
  sim_icache_fetch(3113 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4400 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4401 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4402 */
l_L182X3: ;/* line 4405 */
__LABEL(l_L182X3);
  sim_icache_fetch(3116 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4406 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_15137Xoffset,0,4)); /* line 4407 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4408 */
   __ADD_CYCLES(1);
} /* line 4408 */
  sim_icache_fetch(3121 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4410 */
} /* line 4410 */
  sim_icache_fetch(3122 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4412 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4413 */
   __GOTO(l_L180X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L180X3;
} /* line 4414 */
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

  sim_icache_fetch(3125 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4430 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4431 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4432 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4433 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4434 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4435 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4436 */
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4437 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4438 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4439 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4440 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4441 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4442 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4443 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4444 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4445 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4446 */
} /* line 4446 */
  sim_icache_fetch(3143 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4448 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4449 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4450 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4451 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4452 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4453 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4454 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4455 */
} /* line 4455 */
l_L198X3: ;/* line 4458 */
__LABEL(l_L198X3);
  sim_icache_fetch(3155 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4459 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4460 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4461 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4462 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4463 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4464 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4465 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4466 */
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4467 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4468 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4469 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4470 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4471 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4472 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4473 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4474 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4475 */
} /* line 4475 */
  sim_icache_fetch(3172 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4477 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4478 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L199X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4479 */
  sim_icache_fetch(3175 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4481 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4482 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4483 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4484 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4485 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4486 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4487 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4488 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4489 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4490 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4491 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4492 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4493 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4494 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4495 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4496 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4497 */
} /* line 4497 */
  sim_icache_fetch(3192 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4499 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4500 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4501 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4502 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4503 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4504 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4505 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4506 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4507 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4508 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4509 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4510 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4511 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4512 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4513 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4514 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4515 */
} /* line 4515 */
  sim_icache_fetch(3209 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4517 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4518 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4519 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4520 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4521 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4522 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4523 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4524 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4525 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4526 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4527 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4528 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4529 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4530 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4531 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4532 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4533 */
} /* line 4533 */
  sim_icache_fetch(3226 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4535 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4536 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4537 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4538 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4539 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4540 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4541 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4542 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4543 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4544 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4545 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4546 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4547 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4548 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4549 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4550 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4551 */
} /* line 4551 */
  sim_icache_fetch(3243 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4553 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4554 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4555 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4556 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4557 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4558 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4559 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4560 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4561 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4562 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4563 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4564 */
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4565 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4566 */
   __GOTO(l_L198X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L198X3;
} /* line 4567 */
l_L199X3: ;/* line 4570 */
__LABEL(l_L199X3);
  sim_icache_fetch(3258 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4571 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4572 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4573 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4574 */
   __ADD_CYCLES(1);
} /* line 4574 */
  sim_icache_fetch(3264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4576 */
} /* line 4576 */
  sim_icache_fetch(3265 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4578 */
} /* line 4578 */
		 /* line 4579 */
  sim_icache_fetch(3267 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4581 */
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
} /* line 4582 */
l_lr_266: ;/* line 4582 */
__LABEL(l_lr_266);
  sim_icache_fetch(3271 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_2, t__i32_0); /* line 4584 */
   __MOV(reg_r0_4, t__i32_0); /* line 4585 */
   __CMPEQ(reg_b0_0, t__i32_0, (unsigned int) -1); /* line 4586 */
   __MOV(reg_r0_3, 0); /* line 4587 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4588 */
   __MOV(reg_r0_5, t__i32_0); /* line 4589 */
} /* line 4589 */
  sim_icache_fetch(3277 + t_thisfile.offset, 1);
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
} /* line 4591 */
  sim_icache_fetch(3278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4594 */
l_L200X3: ;/* line 4597 */
__LABEL(l_L200X3);
  sim_icache_fetch(3279 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4598 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4599 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4600 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4601 */
} /* line 4601 */
  sim_icache_fetch(3284 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4603 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4604 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4605 */
} /* line 4605 */
  sim_icache_fetch(3288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4607 */
} /* line 4607 */
  sim_icache_fetch(3289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4609 */
} /* line 4609 */
  sim_icache_fetch(3291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4611 */
} /* line 4611 */
l_L201X3: ;/* line 4614 */
__LABEL(l_L201X3);
		 /* line 4614 */
  sim_icache_fetch(3292 + t_thisfile.offset, 2);
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
} /* line 4616 */
l_lr_270: ;/* line 4616 */
__LABEL(l_lr_270);
  sim_icache_fetch(3294 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4618 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4619 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4620 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4621 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4622 */
} /* line 4622 */
  sim_icache_fetch(3301 + t_thisfile.offset, 1);
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
} /* line 4624 */
  sim_icache_fetch(3302 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4626 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4627 */
} /* line 4627 */
  sim_icache_fetch(3305 + t_thisfile.offset, 1);
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
} /* line 4629 */
l_L204X3: ;/* line 4632 */
__LABEL(l_L204X3);
  sim_icache_fetch(3306 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4633 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4634 */
} /* line 4634 */
  sim_icache_fetch(3308 + t_thisfile.offset, 1);
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
} /* line 4636 */
  sim_icache_fetch(3309 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4638 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4639 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4640 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4641 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4642 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4643 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4644 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4645 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4646 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4647 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4648 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4649 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4650 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4651 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4652 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4653 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4655 */
} /* line 4655 */
  sim_icache_fetch(3326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L204X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L204X3;
} /* line 4657 */
l_L205X3: ;/* line 4660 */
__LABEL(l_L205X3);
  sim_icache_fetch(3327 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4661 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4662 */
} /* line 4662 */
		 /* line 4663 */
  sim_icache_fetch(3330 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4665 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4666 */
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
} /* line 4667 */
l_lr_274: ;/* line 4667 */
__LABEL(l_lr_274);
  sim_icache_fetch(3336 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4669 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4670 */
} /* line 4670 */
  sim_icache_fetch(3338 + t_thisfile.offset, 1);
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
} /* line 4672 */
l_L203X3: ;/* line 4675 */
__LABEL(l_L203X3);
  sim_icache_fetch(3339 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4676 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4677 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4678 */
   __ADD_CYCLES(1);
} /* line 4678 */
  sim_icache_fetch(3343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4680 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4681 */
} /* line 4681 */
  sim_icache_fetch(3345 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4683 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4684 */
  sim_icache_fetch(3348 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4686 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4687 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4688 */
} /* line 4688 */
l_L207X3: ;/* line 4691 */
__LABEL(l_L207X3);
  sim_icache_fetch(3351 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4692 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4693 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4694 */
} /* line 4694 */
  sim_icache_fetch(3356 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4696 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4697 */
  sim_icache_fetch(3358 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4699 */
} /* line 4699 */
  sim_icache_fetch(3359 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4701 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4702 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4703 */
} /* line 4703 */
  sim_icache_fetch(3364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4705 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4706 */
  sim_icache_fetch(3366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4708 */
} /* line 4708 */
  sim_icache_fetch(3367 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4710 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4711 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4712 */
} /* line 4712 */
  sim_icache_fetch(3372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4714 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4715 */
  sim_icache_fetch(3374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4717 */
} /* line 4717 */
  sim_icache_fetch(3375 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4719 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4720 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4721 */
} /* line 4721 */
  sim_icache_fetch(3380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4723 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4724 */
  sim_icache_fetch(3382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4726 */
} /* line 4726 */
  sim_icache_fetch(3383 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4728 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4729 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4730 */
} /* line 4730 */
  sim_icache_fetch(3388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4732 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4733 */
  sim_icache_fetch(3390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4735 */
} /* line 4735 */
  sim_icache_fetch(3391 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4737 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4738 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4739 */
} /* line 4739 */
  sim_icache_fetch(3396 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4741 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4742 */
  sim_icache_fetch(3398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4744 */
} /* line 4744 */
  sim_icache_fetch(3399 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4746 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4747 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4748 */
} /* line 4748 */
  sim_icache_fetch(3404 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4750 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4751 */
  sim_icache_fetch(3406 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4753 */
} /* line 4753 */
  sim_icache_fetch(3407 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4755 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4756 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4757 */
} /* line 4757 */
  sim_icache_fetch(3412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4759 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4760 */
  sim_icache_fetch(3414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4762 */
} /* line 4762 */
  sim_icache_fetch(3415 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4764 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4765 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4766 */
} /* line 4766 */
  sim_icache_fetch(3420 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4768 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4769 */
  sim_icache_fetch(3422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4771 */
} /* line 4771 */
  sim_icache_fetch(3423 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4773 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4774 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4775 */
} /* line 4775 */
  sim_icache_fetch(3428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4777 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4778 */
  sim_icache_fetch(3430 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4780 */
} /* line 4780 */
  sim_icache_fetch(3431 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4782 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4783 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4784 */
} /* line 4784 */
  sim_icache_fetch(3436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4786 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4787 */
  sim_icache_fetch(3438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4789 */
} /* line 4789 */
  sim_icache_fetch(3439 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4791 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4792 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4793 */
} /* line 4793 */
  sim_icache_fetch(3444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4795 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4796 */
  sim_icache_fetch(3446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4798 */
} /* line 4798 */
  sim_icache_fetch(3447 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4800 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4801 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4802 */
} /* line 4802 */
  sim_icache_fetch(3452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4804 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4805 */
  sim_icache_fetch(3454 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4807 */
} /* line 4807 */
  sim_icache_fetch(3455 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4809 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4810 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4811 */
} /* line 4811 */
  sim_icache_fetch(3460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4813 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4814 */
  sim_icache_fetch(3462 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4816 */
} /* line 4816 */
  sim_icache_fetch(3463 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4818 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4819 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4820 */
} /* line 4820 */
  sim_icache_fetch(3468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4822 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4823 */
  sim_icache_fetch(3470 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4825 */
} /* line 4825 */
  sim_icache_fetch(3471 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4827 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4828 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4829 */
} /* line 4829 */
  sim_icache_fetch(3476 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4831 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4832 */
  sim_icache_fetch(3478 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4834 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4835 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 4836 */
l_L223X3: ;/* line 4839 */
__LABEL(l_L223X3);
  sim_icache_fetch(3481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4840 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4841 */
} /* line 4841 */
  sim_icache_fetch(3483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4843 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 4844 */
l_L225X3: ;/* line 4847 */
__LABEL(l_L225X3);
  sim_icache_fetch(3485 + t_thisfile.offset, 26);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __MOV(reg_r0_5, reg_r0_3); /* line 4848 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4849 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4850 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4851 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4852 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4853 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4854 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4855 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4856 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4857 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4858 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4859 */
   __ADD(reg_r0_22, reg_r0_19, (unsigned int) -16); /* line 4860 */
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) -16); /* line 4861 */
   __ADD(reg_r0_24, reg_r0_17, (unsigned int) -16); /* line 4862 */
   __ADD(reg_r0_25, reg_r0_16, (unsigned int) -16); /* line 4863 */
   __ADD(reg_r0_26, reg_r0_15, (unsigned int) -16); /* line 4864 */
} /* line 4864 */
  sim_icache_fetch(3511 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __MOV(reg_r0_37, reg_r0_20); /* line 4866 */
   __ADD(reg_r0_27, reg_r0_14, (unsigned int) -16); /* line 4867 */
   __ADD(reg_r0_28, reg_r0_13, (unsigned int) -16); /* line 4868 */
   __ADD(reg_r0_29, reg_r0_12, (unsigned int) -16); /* line 4869 */
   __ADD(reg_r0_30, reg_r0_11, (unsigned int) -16); /* line 4870 */
   __ADD(reg_r0_31, reg_r0_10, (unsigned int) -16); /* line 4871 */
   __ADD(reg_r0_32, reg_r0_9, (unsigned int) -16); /* line 4872 */
   __ADD(reg_r0_33, reg_r0_8, (unsigned int) -16); /* line 4873 */
   __ADD(reg_r0_34, reg_r0_7, (unsigned int) -16); /* line 4874 */
   __ADD(reg_r0_35, reg_r0_6, (unsigned int) -16); /* line 4875 */
   __ADD(reg_r0_36, reg_r0_20, (unsigned int) -16); /* line 4876 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) -16); /* line 4877 */
} /* line 4877 */
  sim_icache_fetch(3523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4879 */
   __MOV(reg_r0_40, reg_r0_36); /* line 4880 */
} /* line 4880 */
  sim_icache_fetch(3525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4882 */
} /* line 4882 */
  sim_icache_fetch(3527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4884 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4885 */
  sim_icache_fetch(3529 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4887 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4888 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4889 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4890 */
   __ADD_CYCLES(1);
} /* line 4890 */
  sim_icache_fetch(3535 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4892 */
} /* line 4892 */
  sim_icache_fetch(3536 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4894 */
} /* line 4894 */
  sim_icache_fetch(3538 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4896 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4897 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4898 */
  sim_icache_fetch(3542 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4900 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4901 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4902 */
   __ADD(reg_r0_6, reg_r0_35, (unsigned int) -16); /* line 4903 */
   __MFB(reg_r0_4, t__i32_0); /* line 4904 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4905 */
   __ADD_CYCLES(1);
} /* line 4905 */
  sim_icache_fetch(3550 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4907 */
} /* line 4907 */
  sim_icache_fetch(3551 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4909 */
} /* line 4909 */
  sim_icache_fetch(3553 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4911 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4912 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4913 */
  sim_icache_fetch(3556 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4915 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4916 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4917 */
   __ADD(reg_r0_7, reg_r0_34, (unsigned int) -16); /* line 4918 */
   __MFB(reg_r0_4, t__i32_0); /* line 4919 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4920 */
   __ADD_CYCLES(1);
} /* line 4920 */
  sim_icache_fetch(3564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4922 */
} /* line 4922 */
  sim_icache_fetch(3565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4924 */
} /* line 4924 */
  sim_icache_fetch(3567 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4926 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4927 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4928 */
  sim_icache_fetch(3570 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4930 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4931 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4932 */
   __ADD(reg_r0_8, reg_r0_33, (unsigned int) -16); /* line 4933 */
   __MFB(reg_r0_4, t__i32_0); /* line 4934 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4935 */
   __ADD_CYCLES(1);
} /* line 4935 */
  sim_icache_fetch(3578 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4937 */
} /* line 4937 */
  sim_icache_fetch(3579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4939 */
} /* line 4939 */
  sim_icache_fetch(3581 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 4941 */
   __MTB(reg_b0_4, reg_r0_4); /* line 4942 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4943 */
  sim_icache_fetch(3584 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 4945 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4946 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 4947 */
   __ADD(reg_r0_9, reg_r0_32, (unsigned int) -16); /* line 4948 */
   __MFB(reg_r0_4, t__i32_0); /* line 4949 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4950 */
   __ADD_CYCLES(1);
} /* line 4950 */
  sim_icache_fetch(3592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4952 */
} /* line 4952 */
  sim_icache_fetch(3593 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4954 */
} /* line 4954 */
  sim_icache_fetch(3595 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 4956 */
   __MTB(reg_b0_5, reg_r0_4); /* line 4957 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4958 */
  sim_icache_fetch(3598 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 4960 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4961 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 4962 */
   __ADD(reg_r0_10, reg_r0_31, (unsigned int) -16); /* line 4963 */
   __MFB(reg_r0_4, t__i32_0); /* line 4964 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4965 */
   __ADD_CYCLES(1);
} /* line 4965 */
  sim_icache_fetch(3606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4967 */
} /* line 4967 */
  sim_icache_fetch(3607 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4969 */
} /* line 4969 */
  sim_icache_fetch(3609 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 4971 */
   __MTB(reg_b0_6, reg_r0_4); /* line 4972 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4973 */
  sim_icache_fetch(3612 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 4975 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4976 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 4977 */
   __ADD(reg_r0_11, reg_r0_30, (unsigned int) -16); /* line 4978 */
   __MFB(reg_r0_4, t__i32_0); /* line 4979 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4980 */
   __ADD_CYCLES(1);
} /* line 4980 */
  sim_icache_fetch(3620 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_2, (unsigned int) 1); /* line 4982 */
} /* line 4982 */
  sim_icache_fetch(3621 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_39); /* line 4984 */
} /* line 4984 */
  sim_icache_fetch(3623 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 4986 */
   __MTB(reg_b0_7, reg_r0_4); /* line 4987 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4988 */
  sim_icache_fetch(3626 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 4990 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4991 */
   __CMPLEU(reg_b0_7, reg_r0_37, ((unsigned int) htab + (unsigned int) 4096)); /* line 4992 */
   __ADD(reg_r0_12, reg_r0_29, (unsigned int) -16); /* line 4993 */
   __MFB(reg_r0_4, t__i32_0); /* line 4994 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4995 */
   __ADD_CYCLES(1);
} /* line 4995 */
  sim_icache_fetch(3634 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 4997 */
} /* line 4997 */
  sim_icache_fetch(3635 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 4999 */
} /* line 4999 */
  sim_icache_fetch(3637 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5001 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5002 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5003 */
  sim_icache_fetch(3640 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5005 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5006 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5007 */
   __ADD(reg_r0_13, reg_r0_28, (unsigned int) -16); /* line 5008 */
   __MFB(reg_r0_4, t__i32_0); /* line 5009 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5010 */
   __ADD_CYCLES(1);
} /* line 5010 */
  sim_icache_fetch(3648 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5012 */
} /* line 5012 */
  sim_icache_fetch(3649 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5014 */
} /* line 5014 */
  sim_icache_fetch(3651 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5016 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5017 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5018 */
  sim_icache_fetch(3654 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5020 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5021 */
   __CMPLEU(reg_b0_1, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5022 */
   __ADD(reg_r0_14, reg_r0_27, (unsigned int) -16); /* line 5023 */
   __MFB(reg_r0_4, t__i32_0); /* line 5024 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5025 */
   __ADD_CYCLES(1);
} /* line 5025 */
  sim_icache_fetch(3662 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5027 */
} /* line 5027 */
  sim_icache_fetch(3663 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5029 */
} /* line 5029 */
  sim_icache_fetch(3665 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5031 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5032 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5033 */
  sim_icache_fetch(3668 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5035 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5036 */
   __CMPLEU(reg_b0_2, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5037 */
   __ADD(reg_r0_15, reg_r0_26, (unsigned int) -16); /* line 5038 */
   __MFB(reg_r0_4, t__i32_0); /* line 5039 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5040 */
   __ADD_CYCLES(1);
} /* line 5040 */
  sim_icache_fetch(3676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5042 */
} /* line 5042 */
  sim_icache_fetch(3677 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5044 */
} /* line 5044 */
  sim_icache_fetch(3679 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5046 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5047 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5048 */
  sim_icache_fetch(3682 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5050 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5051 */
   __CMPLEU(reg_b0_3, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5052 */
   __ADD(reg_r0_16, reg_r0_25, (unsigned int) -16); /* line 5053 */
   __MFB(reg_r0_4, t__i32_0); /* line 5054 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5055 */
   __ADD_CYCLES(1);
} /* line 5055 */
  sim_icache_fetch(3690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5057 */
} /* line 5057 */
  sim_icache_fetch(3691 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5059 */
} /* line 5059 */
  sim_icache_fetch(3693 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5061 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5062 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5063 */
  sim_icache_fetch(3696 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5065 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5066 */
   __CMPLEU(reg_b0_4, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5067 */
   __ADD(reg_r0_17, reg_r0_24, (unsigned int) -16); /* line 5068 */
   __MFB(reg_r0_4, t__i32_0); /* line 5069 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5070 */
   __ADD_CYCLES(1);
} /* line 5070 */
  sim_icache_fetch(3704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5072 */
} /* line 5072 */
  sim_icache_fetch(3705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5074 */
} /* line 5074 */
  sim_icache_fetch(3707 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5076 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5077 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5078 */
  sim_icache_fetch(3710 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5080 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5081 */
   __CMPLEU(reg_b0_5, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5082 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) -16); /* line 5083 */
   __MFB(reg_r0_4, t__i32_0); /* line 5084 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5085 */
   __ADD_CYCLES(1);
} /* line 5085 */
  sim_icache_fetch(3718 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5087 */
} /* line 5087 */
  sim_icache_fetch(3719 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5089 */
} /* line 5089 */
  sim_icache_fetch(3721 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5091 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5092 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5093 */
  sim_icache_fetch(3724 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5095 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5096 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5097 */
   __CMPLEU(reg_b0_6, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5098 */
   __ADD(reg_r0_19, reg_r0_22, (unsigned int) -16); /* line 5099 */
   __MFB(reg_r0_4, t__i32_0); /* line 5100 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5101 */
   __ADD_CYCLES(1);
} /* line 5101 */
  sim_icache_fetch(3733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_2, (unsigned int) 1); /* line 5103 */
} /* line 5103 */
  sim_icache_fetch(3734 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_37); /* line 5105 */
} /* line 5105 */
  sim_icache_fetch(3736 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5107 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5108 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5109 */
  sim_icache_fetch(3739 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_5, reg_r0_3); /* line 5111 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5112 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5113 */
   __CMPLEU(reg_b0_7, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5114 */
   __ADD(reg_r0_20, reg_r0_36, (unsigned int) -16); /* line 5115 */
   __MOV(reg_r0_3, reg_r0_38); /* line 5116 */
   __MFB(reg_r0_37, t__i32_0); /* line 5117 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5118 */
   __ADD_CYCLES(1);
} /* line 5118 */
  sim_icache_fetch(3749 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5120 */
} /* line 5120 */
  sim_icache_fetch(3750 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5122 */
} /* line 5122 */
  sim_icache_fetch(3752 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5124 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5125 */
  sim_icache_fetch(3754 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5127 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5128 */
   __CMPLEU(reg_b0_0, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5129 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5130 */
   __ADD_CYCLES(1);
} /* line 5130 */
  sim_icache_fetch(3760 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5132 */
} /* line 5132 */
  sim_icache_fetch(3761 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5134 */
} /* line 5134 */
  sim_icache_fetch(3763 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5136 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5137 */
  sim_icache_fetch(3765 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5139 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5140 */
   __CMPLEU(reg_b0_1, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5141 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5142 */
   __ADD_CYCLES(1);
} /* line 5142 */
  sim_icache_fetch(3771 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5144 */
} /* line 5144 */
  sim_icache_fetch(3772 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5146 */
} /* line 5146 */
  sim_icache_fetch(3774 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5148 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5149 */
  sim_icache_fetch(3776 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5151 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5152 */
   __CMPLEU(reg_b0_2, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5153 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5154 */
   __ADD_CYCLES(1);
} /* line 5154 */
  sim_icache_fetch(3782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5156 */
} /* line 5156 */
  sim_icache_fetch(3783 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5158 */
} /* line 5158 */
  sim_icache_fetch(3785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5160 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5161 */
  sim_icache_fetch(3787 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5163 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5164 */
   __CMPLEU(reg_b0_3, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5165 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5166 */
   __ADD_CYCLES(1);
} /* line 5166 */
  sim_icache_fetch(3793 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5168 */
} /* line 5168 */
  sim_icache_fetch(3794 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5170 */
} /* line 5170 */
  sim_icache_fetch(3796 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5172 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5173 */
  sim_icache_fetch(3798 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5175 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5176 */
   __CMPLEU(reg_b0_4, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5177 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5178 */
   __ADD_CYCLES(1);
} /* line 5178 */
  sim_icache_fetch(3804 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5180 */
} /* line 5180 */
  sim_icache_fetch(3805 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5182 */
} /* line 5182 */
  sim_icache_fetch(3807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5184 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5185 */
  sim_icache_fetch(3809 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5187 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5188 */
   __CMPLEU(reg_b0_5, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5189 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5190 */
   __ADD_CYCLES(1);
} /* line 5190 */
  sim_icache_fetch(3815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5192 */
} /* line 5192 */
  sim_icache_fetch(3816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5194 */
} /* line 5194 */
  sim_icache_fetch(3818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5196 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5197 */
  sim_icache_fetch(3820 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5199 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5200 */
   __CMPLEU(reg_b0_6, reg_r0_22, ((unsigned int) htab + (unsigned int) 4096)); /* line 5201 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5202 */
   __ADD_CYCLES(1);
} /* line 5202 */
  sim_icache_fetch(3826 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5204 */
} /* line 5204 */
  sim_icache_fetch(3827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5206 */
} /* line 5206 */
  sim_icache_fetch(3829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5208 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5209 */
  sim_icache_fetch(3831 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5211 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5212 */
   __MTB(reg_b0_7, reg_r0_37); /* line 5213 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5214 */
   __ADD_CYCLES(1);
} /* line 5214 */
  sim_icache_fetch(3836 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5216 */
} /* line 5216 */
  sim_icache_fetch(3837 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5218 */
} /* line 5218 */
  sim_icache_fetch(3839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5220 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5221 */
  sim_icache_fetch(3841 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5223 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5224 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5225 */
   __ADD_CYCLES(1);
} /* line 5225 */
  sim_icache_fetch(3845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5227 */
} /* line 5227 */
  sim_icache_fetch(3846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5229 */
} /* line 5229 */
  sim_icache_fetch(3848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5231 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5232 */
  sim_icache_fetch(3850 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5234 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5235 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5236 */
   __ADD_CYCLES(1);
} /* line 5236 */
  sim_icache_fetch(3854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5238 */
} /* line 5238 */
  sim_icache_fetch(3855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5240 */
} /* line 5240 */
  sim_icache_fetch(3857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5242 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5243 */
  sim_icache_fetch(3859 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5245 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5246 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5247 */
   __ADD_CYCLES(1);
} /* line 5247 */
  sim_icache_fetch(3863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5249 */
} /* line 5249 */
  sim_icache_fetch(3864 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5251 */
} /* line 5251 */
  sim_icache_fetch(3866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5253 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5254 */
  sim_icache_fetch(3868 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5256 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5257 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5258 */
   __ADD_CYCLES(1);
} /* line 5258 */
  sim_icache_fetch(3872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5260 */
} /* line 5260 */
  sim_icache_fetch(3873 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5262 */
} /* line 5262 */
  sim_icache_fetch(3875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5264 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5265 */
  sim_icache_fetch(3877 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5267 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5268 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5269 */
   __ADD_CYCLES(1);
} /* line 5269 */
  sim_icache_fetch(3881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5271 */
} /* line 5271 */
  sim_icache_fetch(3882 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5273 */
} /* line 5273 */
  sim_icache_fetch(3884 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5275 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5276 */
  sim_icache_fetch(3886 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_22, mem_trace_ld(reg_r0_22,0,1)); /* line 5278 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5279 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5280 */
   __ADD_CYCLES(1);
} /* line 5280 */
  sim_icache_fetch(3890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5282 */
} /* line 5282 */
  sim_icache_fetch(3891 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5284 */
} /* line 5284 */
  sim_icache_fetch(3893 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_22); /* line 5286 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5287 */
  sim_icache_fetch(3895 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5289 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5290 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5291 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5292 */
   __ADD_CYCLES(1);
} /* line 5292 */
  sim_icache_fetch(3900 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5294 */
} /* line 5294 */
  sim_icache_fetch(3901 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5296 */
} /* line 5296 */
  sim_icache_fetch(3903 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5298 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5300 */
  sim_icache_fetch(3905 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5302 */
l_L241X3: ;/* line 5305 */
__LABEL(l_L241X3);
  sim_icache_fetch(3906 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5306 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5307 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5308 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5309 */
l_L244X3: ;/* line 5312 */
__LABEL(l_L244X3);
  sim_icache_fetch(3912 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5313 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5314 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5315 */
} /* line 5315 */
  sim_icache_fetch(3917 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5317 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5318 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5319 */
l_L240X3: ;/* line 5322 */
__LABEL(l_L240X3);
  sim_icache_fetch(3921 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5323 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5324 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5325 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5326 */
l_L239X3: ;/* line 5329 */
__LABEL(l_L239X3);
  sim_icache_fetch(3927 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5330 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5331 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5332 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5333 */
l_L238X3: ;/* line 5336 */
__LABEL(l_L238X3);
  sim_icache_fetch(3933 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5337 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5338 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5339 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5340 */
l_L237X3: ;/* line 5343 */
__LABEL(l_L237X3);
  sim_icache_fetch(3939 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5344 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5345 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5346 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5347 */
l_L236X3: ;/* line 5350 */
__LABEL(l_L236X3);
  sim_icache_fetch(3945 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5351 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5352 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5353 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5354 */
l_L235X3: ;/* line 5357 */
__LABEL(l_L235X3);
  sim_icache_fetch(3951 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5358 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5359 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5360 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5361 */
l_L234X3: ;/* line 5364 */
__LABEL(l_L234X3);
  sim_icache_fetch(3957 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5365 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5366 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5367 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5368 */
l_L233X3: ;/* line 5371 */
__LABEL(l_L233X3);
  sim_icache_fetch(3963 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5372 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5373 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5374 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5375 */
l_L232X3: ;/* line 5378 */
__LABEL(l_L232X3);
  sim_icache_fetch(3969 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5379 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5380 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5381 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5382 */
l_L231X3: ;/* line 5385 */
__LABEL(l_L231X3);
  sim_icache_fetch(3975 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5386 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5387 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5388 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5389 */
l_L230X3: ;/* line 5392 */
__LABEL(l_L230X3);
  sim_icache_fetch(3981 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5393 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5394 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5395 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5396 */
l_L229X3: ;/* line 5399 */
__LABEL(l_L229X3);
  sim_icache_fetch(3987 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5400 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5401 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5402 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5403 */
l_L228X3: ;/* line 5406 */
__LABEL(l_L228X3);
  sim_icache_fetch(3993 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5407 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5408 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5409 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5410 */
l_L227X3: ;/* line 5413 */
__LABEL(l_L227X3);
  sim_icache_fetch(3999 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5414 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5415 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5416 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 5417 */
l_L226X3: ;/* line 5420 */
__LABEL(l_L226X3);
  sim_icache_fetch(4005 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5421 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5422 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5423 */
} /* line 5423 */
l_L242X3: ;/* line 5425 */
__LABEL(l_L242X3);
  sim_icache_fetch(4010 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5425 */
  sim_icache_fetch(4011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5427 */
} /* line 5427 */
  sim_icache_fetch(4012 + t_thisfile.offset, 1);
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
} /* line 5429 */
l_L243X3: ;/* line 5431 */
__LABEL(l_L243X3);
  sim_icache_fetch(4013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5432 */
   __GOTO(l_L201X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L201X3;
} /* line 5433 */
l_L222X3: ;/* line 5436 */
__LABEL(l_L222X3);
  sim_icache_fetch(4015 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5437 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5438 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5439 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5440 */
l_L221X3: ;/* line 5443 */
__LABEL(l_L221X3);
  sim_icache_fetch(4019 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5444 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5445 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5446 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5447 */
l_L220X3: ;/* line 5450 */
__LABEL(l_L220X3);
  sim_icache_fetch(4023 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5451 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5452 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5453 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5454 */
l_L219X3: ;/* line 5457 */
__LABEL(l_L219X3);
  sim_icache_fetch(4027 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5458 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5459 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5460 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5461 */
l_L218X3: ;/* line 5464 */
__LABEL(l_L218X3);
  sim_icache_fetch(4031 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5465 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5466 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5467 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5468 */
l_L217X3: ;/* line 5471 */
__LABEL(l_L217X3);
  sim_icache_fetch(4035 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5472 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5473 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5474 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5475 */
l_L216X3: ;/* line 5478 */
__LABEL(l_L216X3);
  sim_icache_fetch(4039 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5479 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5480 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5481 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5482 */
l_L215X3: ;/* line 5485 */
__LABEL(l_L215X3);
  sim_icache_fetch(4043 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5486 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5487 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5488 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5489 */
l_L214X3: ;/* line 5492 */
__LABEL(l_L214X3);
  sim_icache_fetch(4047 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5493 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5494 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5495 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5496 */
l_L213X3: ;/* line 5499 */
__LABEL(l_L213X3);
  sim_icache_fetch(4051 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5500 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5501 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5502 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5503 */
l_L212X3: ;/* line 5506 */
__LABEL(l_L212X3);
  sim_icache_fetch(4055 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5507 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5508 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5509 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5510 */
l_L211X3: ;/* line 5513 */
__LABEL(l_L211X3);
  sim_icache_fetch(4059 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5514 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5515 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5516 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5517 */
l_L210X3: ;/* line 5520 */
__LABEL(l_L210X3);
  sim_icache_fetch(4063 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5521 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5522 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5523 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5524 */
l_L209X3: ;/* line 5527 */
__LABEL(l_L209X3);
  sim_icache_fetch(4067 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5528 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5529 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5530 */
   __GOTO(l_L224X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L224X3;
} /* line 5531 */
l_L208X3: ;/* line 5536 */
__LABEL(l_L208X3);
  sim_icache_fetch(4071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5537 */
} /* line 5537 */
l_L224X3: ;/* line 5539 */
__LABEL(l_L224X3);
  sim_icache_fetch(4072 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5540 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5541 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5542 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5543 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5544 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5545 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5546 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5547 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5548 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5549 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5550 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5551 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5552 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5553 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5554 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5555 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5556 */
} /* line 5556 */
  sim_icache_fetch(4090 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 5558 */
} /* line 5558 */
  sim_icache_fetch(4091 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5560 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5561 */
l_L206X3: ;/* line 5564 */
__LABEL(l_L206X3);
  sim_icache_fetch(4093 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5565 */
   __GOTO(l_L207X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L207X3;
} /* line 5566 */
l_L202X3: ;/* line 5569 */
__LABEL(l_L202X3);
  sim_icache_fetch(4095 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5570 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5571 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5572 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5573 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5574 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5575 */
   __ADD_CYCLES(1);
} /* line 5575 */
  sim_icache_fetch(4101 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5578 */
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

  sim_icache_fetch(4102 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5597 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5598 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5599 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5600 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5601 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5602 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5603 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5604 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5605 */
   __ADD_CYCLES(1);
} /* line 5605 */
  sim_icache_fetch(4119 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGE(reg_r0_11, reg_r0_7, reg_r0_8); /* line 5607 */
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5608 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5609 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5610 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5611 */
} /* line 5611 */
  sim_icache_fetch(4124 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5613 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_2); /* line 5614 */
} /* line 5614 */
  sim_icache_fetch(4126 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_2, reg_r0_4, reg_r0_11); /* line 5616 */
} /* line 5616 */
  sim_icache_fetch(4127 + t_thisfile.offset, 1);
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
} /* line 5618 */
  sim_icache_fetch(4128 + t_thisfile.offset, 1);
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
} /* line 5620 */
  sim_icache_fetch(4129 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5622 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5623 */
  sim_icache_fetch(4132 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5625 */
} /* line 5625 */
l_L246X3: ;/* line 5628 */
__LABEL(l_L246X3);
  sim_icache_fetch(4134 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5629 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5630 */
   __MOV(reg_r0_5, 0); /* line 5631 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5632 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5633 */
   __ADD_CYCLES(1);
} /* line 5633 */
  sim_icache_fetch(4141 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5635 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5636 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5637 */
} /* line 5637 */
  sim_icache_fetch(4144 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5639 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5640 */
l_L249X3: ;/* line 5643 */
__LABEL(l_L249X3);
  sim_icache_fetch(4146 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5644 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5645 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5646 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5647 */
} /* line 5647 */
  sim_icache_fetch(4152 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5649 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5650 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5651 */
  sim_icache_fetch(4155 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5653 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5654 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5655 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5656 */
} /* line 5656 */
  sim_icache_fetch(4159 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5658 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5659 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5660 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5661 */
} /* line 5661 */
  sim_icache_fetch(4164 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5663 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5664 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5665 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5666 */
  sim_icache_fetch(4169 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5668 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5669 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5670 */
} /* line 5670 */
  sim_icache_fetch(4173 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5672 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5673 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5674 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5675 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5676 */
} /* line 5676 */
  sim_icache_fetch(4179 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5678 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5679 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5680 */
} /* line 5680 */
  sim_icache_fetch(4182 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5682 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5683 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5684 */
} /* line 5684 */
l_L252X3: ;/* line 5686 */
__LABEL(l_L252X3);
  sim_icache_fetch(4185 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5687 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5688 */
} /* line 5688 */
  sim_icache_fetch(4188 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5690 */
} /* line 5690 */
  sim_icache_fetch(4189 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5692 */
} /* line 5692 */
  sim_icache_fetch(4190 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5694 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5695 */
  sim_icache_fetch(4192 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5697 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5698 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5699 */
  sim_icache_fetch(4195 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5701 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5702 */
  sim_icache_fetch(4198 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5704 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5705 */
} /* line 5705 */
  sim_icache_fetch(4202 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5707 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5708 */
} /* line 5708 */
  sim_icache_fetch(4205 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5710 */
} /* line 5710 */
  sim_icache_fetch(4206 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5712 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5713 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5714 */
} /* line 5714 */
l_L255X3: ;/* line 5716 */
__LABEL(l_L255X3);
  sim_icache_fetch(4209 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5717 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5718 */
} /* line 5718 */
  sim_icache_fetch(4212 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5720 */
} /* line 5720 */
  sim_icache_fetch(4213 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5722 */
} /* line 5722 */
  sim_icache_fetch(4214 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5724 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5725 */
  sim_icache_fetch(4216 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5727 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5728 */
  sim_icache_fetch(4218 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5730 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L256X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5731 */
  sim_icache_fetch(4221 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5733 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5734 */
} /* line 5734 */
  sim_icache_fetch(4225 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5736 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5737 */
} /* line 5737 */
  sim_icache_fetch(4228 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5739 */
} /* line 5739 */
  sim_icache_fetch(4229 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5741 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5742 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5743 */
} /* line 5743 */
l_L257X3: ;/* line 5745 */
__LABEL(l_L257X3);
  sim_icache_fetch(4232 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5746 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5747 */
} /* line 5747 */
  sim_icache_fetch(4235 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5749 */
} /* line 5749 */
  sim_icache_fetch(4236 + t_thisfile.offset, 1);
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
} /* line 5751 */
  sim_icache_fetch(4237 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5753 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5754 */
  sim_icache_fetch(4239 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5756 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L258X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5757 */
  sim_icache_fetch(4242 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5759 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5760 */
} /* line 5760 */
  sim_icache_fetch(4246 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5762 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5763 */
} /* line 5763 */
  sim_icache_fetch(4249 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5765 */
} /* line 5765 */
  sim_icache_fetch(4250 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5767 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5768 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5769 */
} /* line 5769 */
l_L259X3: ;/* line 5771 */
__LABEL(l_L259X3);
  sim_icache_fetch(4253 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5772 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5773 */
} /* line 5773 */
  sim_icache_fetch(4256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5775 */
} /* line 5775 */
  sim_icache_fetch(4257 + t_thisfile.offset, 1);
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
} /* line 5777 */
  sim_icache_fetch(4258 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5779 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5780 */
  sim_icache_fetch(4260 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5782 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L260X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5783 */
  sim_icache_fetch(4263 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5785 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5786 */
} /* line 5786 */
  sim_icache_fetch(4267 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5788 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5789 */
} /* line 5789 */
  sim_icache_fetch(4270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5791 */
} /* line 5791 */
  sim_icache_fetch(4271 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5793 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5794 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5795 */
} /* line 5795 */
l_L261X3: ;/* line 5797 */
__LABEL(l_L261X3);
  sim_icache_fetch(4274 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5798 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5799 */
} /* line 5799 */
  sim_icache_fetch(4277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5801 */
} /* line 5801 */
  sim_icache_fetch(4278 + t_thisfile.offset, 1);
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
} /* line 5803 */
  sim_icache_fetch(4279 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5805 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5806 */
  sim_icache_fetch(4281 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5808 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5809 */
  sim_icache_fetch(4284 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5811 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5812 */
} /* line 5812 */
  sim_icache_fetch(4288 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5814 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5815 */
} /* line 5815 */
  sim_icache_fetch(4291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5817 */
} /* line 5817 */
  sim_icache_fetch(4292 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5819 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5820 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5821 */
} /* line 5821 */
l_L263X3: ;/* line 5823 */
__LABEL(l_L263X3);
  sim_icache_fetch(4295 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5824 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5825 */
} /* line 5825 */
  sim_icache_fetch(4298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5827 */
} /* line 5827 */
  sim_icache_fetch(4299 + t_thisfile.offset, 1);
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
} /* line 5829 */
  sim_icache_fetch(4300 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5831 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5832 */
  sim_icache_fetch(4302 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5834 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L264X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5835 */
  sim_icache_fetch(4305 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5837 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5838 */
} /* line 5838 */
  sim_icache_fetch(4309 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5840 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5841 */
} /* line 5841 */
  sim_icache_fetch(4312 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5843 */
} /* line 5843 */
  sim_icache_fetch(4313 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5845 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5846 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5847 */
} /* line 5847 */
l_L265X3: ;/* line 5849 */
__LABEL(l_L265X3);
  sim_icache_fetch(4316 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5850 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5851 */
} /* line 5851 */
  sim_icache_fetch(4319 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5853 */
} /* line 5853 */
  sim_icache_fetch(4320 + t_thisfile.offset, 1);
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
} /* line 5855 */
  sim_icache_fetch(4321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5857 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5858 */
  sim_icache_fetch(4323 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5860 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L266X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5861 */
  sim_icache_fetch(4326 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5863 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5864 */
} /* line 5864 */
  sim_icache_fetch(4330 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5866 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5867 */
} /* line 5867 */
  sim_icache_fetch(4333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5869 */
} /* line 5869 */
  sim_icache_fetch(4334 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5871 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5872 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5873 */
} /* line 5873 */
l_L267X3: ;/* line 5875 */
__LABEL(l_L267X3);
  sim_icache_fetch(4337 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5876 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5877 */
} /* line 5877 */
  sim_icache_fetch(4340 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5879 */
} /* line 5879 */
  sim_icache_fetch(4341 + t_thisfile.offset, 1);
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
} /* line 5881 */
  sim_icache_fetch(4342 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5883 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5884 */
  sim_icache_fetch(4344 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5886 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5887 */
  sim_icache_fetch(4347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5889 */
} /* line 5889 */
  sim_icache_fetch(4349 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5891 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5892 */
   __ADD_CYCLES(1);
} /* line 5892 */
  sim_icache_fetch(4351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5894 */
} /* line 5894 */
l_L269X3: ;/* line 5896 */
__LABEL(l_L269X3);
  sim_icache_fetch(4352 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5897 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5898 */
} /* line 5898 */
  sim_icache_fetch(4355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5900 */
} /* line 5900 */
  sim_icache_fetch(4356 + t_thisfile.offset, 1);
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
} /* line 5902 */
  sim_icache_fetch(4357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5904 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 5905 */
l_L253X3: ;/* line 5908 */
__LABEL(l_L253X3);
  sim_icache_fetch(4359 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5909 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5910 */
   __GOTO(l_L270X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L270X3;
} /* line 5911 */
l_L271X3: ;/* line 5914 */
__LABEL(l_L271X3);
  sim_icache_fetch(4362 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5915 */
   __MOV(reg_r0_7, 0); /* line 5916 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5917 */
} /* line 5917 */
  sim_icache_fetch(4366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5919 */
} /* line 5919 */
  sim_icache_fetch(4367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5921 */
} /* line 5921 */
l_L245X3: ;/* line 5924 */
__LABEL(l_L245X3);
  sim_icache_fetch(4368 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5925 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5926 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5927 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5928 */
} /* line 5928 */
  sim_icache_fetch(4374 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5930 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5931 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5932 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5933 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5934 */
} /* line 5934 */
  sim_icache_fetch(4382 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 5936 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 5937 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 5938 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 5939 */
} /* line 5939 */
  sim_icache_fetch(4386 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 5941 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 5942 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 5943 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 5944 */
} /* line 5944 */
  sim_icache_fetch(4391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 5946 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 5947 */
} /* line 5947 */
  sim_icache_fetch(4393 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5949 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 5950 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 5951 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 5952 */
} /* line 5952 */
  sim_icache_fetch(4397 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 5954 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5955 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 5956 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5957 */
   __ADD_CYCLES(1);
} /* line 5957 */
  sim_icache_fetch(4402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 5959 */
} /* line 5959 */
  sim_icache_fetch(4403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 5961 */
} /* line 5961 */
  sim_icache_fetch(4404 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 5964 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5965 */
l_L268X3: ;/* line 5968 */
__LABEL(l_L268X3);
  sim_icache_fetch(4406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5969 */
   __GOTO(l_L269X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L269X3;
} /* line 5970 */
l_L250X3: ;/* line 5973 */
__LABEL(l_L250X3);
  sim_icache_fetch(4408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 5974 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5975 */
} /* line 5975 */
l_L270X3: ;/* line 5977 */
__LABEL(l_L270X3);
  sim_icache_fetch(4410 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 5978 */
} /* line 5978 */
  sim_icache_fetch(4411 + t_thisfile.offset, 1);
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
} /* line 5980 */
  sim_icache_fetch(4412 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 5983 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 5984 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5985 */
l_L266X3: ;/* line 5988 */
__LABEL(l_L266X3);
  sim_icache_fetch(4417 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 5989 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5990 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5991 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5992 */
   __ADD_CYCLES(1);
} /* line 5992 */
  sim_icache_fetch(4423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 5994 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5995 */
} /* line 5995 */
  sim_icache_fetch(4425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5997 */
   __GOTO(l_L267X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L267X3;
} /* line 5998 */
l_L264X3: ;/* line 6001 */
__LABEL(l_L264X3);
  sim_icache_fetch(4427 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6002 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6003 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6004 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6005 */
   __ADD_CYCLES(1);
} /* line 6005 */
  sim_icache_fetch(4433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6007 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6008 */
} /* line 6008 */
  sim_icache_fetch(4435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6010 */
   __GOTO(l_L265X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L265X3;
} /* line 6011 */
l_L262X3: ;/* line 6014 */
__LABEL(l_L262X3);
  sim_icache_fetch(4437 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6015 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6016 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6017 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6018 */
   __ADD_CYCLES(1);
} /* line 6018 */
  sim_icache_fetch(4443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6020 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6021 */
} /* line 6021 */
  sim_icache_fetch(4445 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6023 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 6024 */
l_L260X3: ;/* line 6027 */
__LABEL(l_L260X3);
  sim_icache_fetch(4447 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6028 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6029 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6030 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6031 */
   __ADD_CYCLES(1);
} /* line 6031 */
  sim_icache_fetch(4453 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6033 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6034 */
} /* line 6034 */
  sim_icache_fetch(4455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6036 */
   __GOTO(l_L261X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L261X3;
} /* line 6037 */
l_L258X3: ;/* line 6040 */
__LABEL(l_L258X3);
  sim_icache_fetch(4457 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6041 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6042 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6043 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6044 */
   __ADD_CYCLES(1);
} /* line 6044 */
  sim_icache_fetch(4463 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6046 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6047 */
} /* line 6047 */
  sim_icache_fetch(4465 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6049 */
   __GOTO(l_L259X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L259X3;
} /* line 6050 */
l_L256X3: ;/* line 6053 */
__LABEL(l_L256X3);
  sim_icache_fetch(4467 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6054 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6055 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6056 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6057 */
   __ADD_CYCLES(1);
} /* line 6057 */
  sim_icache_fetch(4473 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6059 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6060 */
} /* line 6060 */
  sim_icache_fetch(4475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6062 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 6063 */
l_L254X3: ;/* line 6066 */
__LABEL(l_L254X3);
  sim_icache_fetch(4477 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6067 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6068 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6069 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6070 */
   __ADD_CYCLES(1);
} /* line 6070 */
  sim_icache_fetch(4483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6072 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6073 */
} /* line 6073 */
  sim_icache_fetch(4485 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6075 */
   __GOTO(l_L255X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L255X3;
} /* line 6076 */
l_L251X3: ;/* line 6079 */
__LABEL(l_L251X3);
  sim_icache_fetch(4487 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6080 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6081 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6082 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6083 */
} /* line 6083 */
  sim_icache_fetch(4492 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6085 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6086 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6087 */
} /* line 6087 */
  sim_icache_fetch(4495 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6089 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6090 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6091 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6092 */
} /* line 6092 */
  sim_icache_fetch(4499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6094 */
   __GOTO(l_L252X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L252X3;
} /* line 6095 */
l_L248X3: ;/* line 6098 */
__LABEL(l_L248X3);
  sim_icache_fetch(4501 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6099 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6100 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6101 */
} /* line 6101 */
  sim_icache_fetch(4506 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6103 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6104 */
} /* line 6104 */
  sim_icache_fetch(4510 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6106 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6107 */
   __ADD_CYCLES(1);
} /* line 6107 */
  sim_icache_fetch(4513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6109 */
} /* line 6109 */
  sim_icache_fetch(4514 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6111 */
   __GOTO(l_L249X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L249X3;
} /* line 6112 */
l_L247X3: ;/* line 6115 */
__LABEL(l_L247X3);
  sim_icache_fetch(4516 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6116 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6117 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6118 */
   __ADD_CYCLES(1);
} /* line 6118 */
  sim_icache_fetch(4520 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6120 */
} /* line 6120 */
  sim_icache_fetch(4521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6122 */
} /* line 6122 */
  sim_icache_fetch(4522 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6124 */
   __GOTO(l_L246X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L246X3;
} /* line 6125 */
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

  sim_icache_fetch(4525 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6147 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6148 */
} /* line 6148 */
		 /* line 6149 */
  sim_icache_fetch(4528 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6152 */
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
} /* line 6152 */
l_lr_346: ;/* line 6152 */
__LABEL(l_lr_346);
  sim_icache_fetch(4531 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6154 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6155 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6156 */
   __ADD_CYCLES(1);
} /* line 6156 */
  sim_icache_fetch(4534 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6159 */
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

  sim_icache_fetch(4535 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6205 */
   __MOV(reg_r0_3, 0); /* line 6206 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6207 */
   __ADD_CYCLES(1);
} /* line 6207 */
  sim_icache_fetch(4539 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6209 */
} /* line 6209 */
  sim_icache_fetch(4540 + t_thisfile.offset, 1);
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
} /* line 6211 */
  sim_icache_fetch(4541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6214 */
l_L272X3: ;/* line 6217 */
__LABEL(l_L272X3);
  sim_icache_fetch(4542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6220 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6220 */
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

  sim_icache_fetch(4544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6236 */
} /* line 6236 */
  sim_icache_fetch(4545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6239 */
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

  sim_icache_fetch(4546 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6254 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6255 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6256 */
} /* line 6256 */
  sim_icache_fetch(4551 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6258 */
} /* line 6258 */
  sim_icache_fetch(4552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6260 */
} /* line 6260 */
  sim_icache_fetch(4553 + t_thisfile.offset, 1);
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
} /* line 6262 */
		 /* line 6263 */
  sim_icache_fetch(4554 + t_thisfile.offset, 2);
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
} /* line 6265 */
l_lr_352: ;/* line 6265 */
__LABEL(l_lr_352);
l_L273X3: ;/* line 6267 */
__LABEL(l_L273X3);
  sim_icache_fetch(4556 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6268 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6269 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6270 */
   __ADD_CYCLES(1);
} /* line 6270 */
  sim_icache_fetch(4559 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6273 */
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

  sim_icache_fetch(4560 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6319 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6320 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6321 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6322 */
} /* line 6322 */
  sim_icache_fetch(4567 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6324 */
} /* line 6324 */
  sim_icache_fetch(4568 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6326 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6327 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6328 */
} /* line 6328 */
  sim_icache_fetch(4573 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6330 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6331 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6332 */
  sim_icache_fetch(4577 + t_thisfile.offset, 1);
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
} /* line 6334 */
l_L276X3: ;/* line 6337 */
__LABEL(l_L276X3);
  sim_icache_fetch(4578 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6338 */
   __MOV(reg_r0_3, 0); /* line 6339 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6340 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6341 */
   __ADD_CYCLES(1);
} /* line 6341 */
  sim_icache_fetch(4583 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6343 */
} /* line 6343 */
  sim_icache_fetch(4584 + t_thisfile.offset, 1);
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
} /* line 6345 */
  sim_icache_fetch(4585 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6348 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6349 */
l_L277X3: ;/* line 6352 */
__LABEL(l_L277X3);
  sim_icache_fetch(4588 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6353 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6354 */
} /* line 6354 */
		 /* line 6355 */
  sim_icache_fetch(4592 + t_thisfile.offset, 2);
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
} /* line 6357 */
l_lr_358: ;/* line 6357 */
__LABEL(l_lr_358);
  sim_icache_fetch(4594 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6359 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6360 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6361 */
} /* line 6361 */
		 /* line 6362 */
  sim_icache_fetch(4599 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6364 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6365 */
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
} /* line 6366 */
l_lr_360: ;/* line 6366 */
__LABEL(l_lr_360);
  sim_icache_fetch(4605 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6368 */
   __MOV(reg_r0_3, 0); /* line 6369 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6370 */
   __ADD_CYCLES(1);
} /* line 6370 */
  sim_icache_fetch(4608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6373 */
l_L275X3: ;/* line 6376 */
__LABEL(l_L275X3);
  sim_icache_fetch(4609 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6377 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6378 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6379 */
   __ADD_CYCLES(1);
} /* line 6379 */
		 /* line 6380 */
  sim_icache_fetch(4613 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6383 */
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
} /* line 6383 */
l_lr_363: ;/* line 6383 */
__LABEL(l_lr_363);
  sim_icache_fetch(4616 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6385 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6386 */
l_L274X3: ;/* line 6389 */
__LABEL(l_L274X3);
  sim_icache_fetch(4618 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6390 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6391 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6392 */
   __ADD_CYCLES(1);
} /* line 6392 */
		 /* line 6393 */
  sim_icache_fetch(4623 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6395 */
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
} /* line 6396 */
l_lr_366: ;/* line 6396 */
__LABEL(l_lr_366);
  sim_icache_fetch(4626 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6398 */
   __GOTO(l_L276X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L276X3;
} /* line 6399 */
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

  sim_icache_fetch(4628 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6418 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6419 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6420 */
} /* line 6420 */
  sim_icache_fetch(4632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6422 */
} /* line 6422 */
l_L278X3: ;/* line 6425 */
__LABEL(l_L278X3);
  sim_icache_fetch(4633 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __MOV(reg_r0_3, reg_r0_2); /* line 6426 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6427 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6428 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6429 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6430 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6431 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6432 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6433 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6434 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6435 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6436 */
} /* line 6436 */
  sim_icache_fetch(4644 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6438 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6439 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6440 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6441 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6442 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6443 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6444 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6445 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6446 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6447 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6448 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6449 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6450 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6451 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6452 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6453 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6454 */
  sim_icache_fetch(4661 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6456 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6457 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6458 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6459 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6460 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6461 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6462 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6463 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6464 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6465 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6466 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6467 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6468 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6469 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6470 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6471 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6472 */
} /* line 6472 */
  sim_icache_fetch(4678 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6474 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6475 */
  sim_icache_fetch(4680 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6477 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6478 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6479 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6480 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6481 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6482 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6483 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6484 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6485 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6486 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6487 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6488 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6489 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6490 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6491 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6492 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6493 */
  sim_icache_fetch(4697 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6495 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6496 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6497 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6498 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6499 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6500 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6501 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6502 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6503 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6504 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6506 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6507 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6508 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6509 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6510 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6511 */
} /* line 6511 */
  sim_icache_fetch(4714 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6513 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6514 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6515 */
  sim_icache_fetch(4717 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6517 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6518 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6519 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6520 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6521 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6522 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6523 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6525 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6527 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6528 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6529 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6531 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6532 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6533 */
  sim_icache_fetch(4734 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6535 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6536 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6537 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6538 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6539 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6540 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6541 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6542 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6543 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6544 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6545 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6546 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6547 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6548 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6549 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6550 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6551 */
  sim_icache_fetch(4767 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6553 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6554 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6555 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6556 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6557 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6558 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6559 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6560 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6561 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6562 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6564 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6565 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6567 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6568 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6569 */
  sim_icache_fetch(4800 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6571 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6572 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6573 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6574 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6575 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6576 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6577 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6578 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6579 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6580 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6581 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6582 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6583 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6584 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6586 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6587 */
  sim_icache_fetch(4833 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6589 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6590 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6591 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6592 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6593 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6594 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6595 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6596 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6597 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6600 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6601 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6602 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6604 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L287X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6605 */
  sim_icache_fetch(4866 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6608 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6610 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6611 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6612 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6613 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6614 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6615 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6616 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6617 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6620 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6621 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6622 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6623 */
  sim_icache_fetch(4899 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6625 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6626 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6627 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6628 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6629 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6630 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6631 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6632 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6633 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6634 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6635 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6636 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6637 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6639 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6640 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6641 */
  sim_icache_fetch(4932 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6644 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6645 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6646 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6647 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6648 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6651 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6652 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6653 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6654 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6655 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6656 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6658 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6659 */
  sim_icache_fetch(4965 + t_thisfile.offset, 33);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6661 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6662 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6664 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6665 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6666 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6667 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6668 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6669 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6670 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6671 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6672 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6673 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6674 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6675 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6676 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6677 */
} /* line 6677 */
  sim_icache_fetch(4998 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6679 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6680 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6681 */
} /* line 6681 */
  sim_icache_fetch(5003 + t_thisfile.offset, 1);
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
} /* line 6684 */
  sim_icache_fetch(5004 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L278X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L278X3;
} /* line 6686 */
l_L291X3: ;/* line 6689 */
__LABEL(l_L291X3);
  sim_icache_fetch(5005 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6690 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6691 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6692 */
l_L293X3: ;/* line 6695 */
__LABEL(l_L293X3);
  sim_icache_fetch(5009 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6696 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6697 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6698 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6699 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 4); /* line 6700 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 5); /* line 6701 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 6); /* line 6702 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 7); /* line 6703 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6704 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6705 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6706 */
} /* line 6706 */
  sim_icache_fetch(5020 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 6708 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6709 */
  sim_icache_fetch(5022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6711 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6712 */
  sim_icache_fetch(5024 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6714 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6715 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6716 */
  sim_icache_fetch(5027 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6718 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6719 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6720 */
  sim_icache_fetch(5030 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6722 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6723 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6724 */
  sim_icache_fetch(5033 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6726 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 12); /* line 6727 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6728 */
  sim_icache_fetch(5036 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6730 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 13); /* line 6731 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6732 */
  sim_icache_fetch(5039 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6734 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 14); /* line 6735 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6736 */
  sim_icache_fetch(5042 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6738 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 15); /* line 6739 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6740 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6741 */
  sim_icache_fetch(5046 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6743 */
   __CMPGT(reg_b0_0, reg_r0_5, 0); /* line 6744 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6745 */
  sim_icache_fetch(5049 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6747 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6748 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6749 */
  sim_icache_fetch(5052 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6751 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6752 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6753 */
  sim_icache_fetch(5055 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6755 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6756 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6757 */
  sim_icache_fetch(5058 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6759 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 4); /* line 6760 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6761 */
  sim_icache_fetch(5061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6763 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 5); /* line 6764 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6765 */
  sim_icache_fetch(5064 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6767 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 6); /* line 6768 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6769 */
  sim_icache_fetch(5067 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6771 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 7); /* line 6772 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6773 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6774 */
  sim_icache_fetch(5071 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6776 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 8); /* line 6777 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6778 */
  sim_icache_fetch(5074 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6780 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6781 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6782 */
  sim_icache_fetch(5077 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6784 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6785 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6786 */
  sim_icache_fetch(5080 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6788 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6789 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6790 */
  sim_icache_fetch(5083 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6792 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 12); /* line 6793 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6794 */
  sim_icache_fetch(5086 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6796 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 13); /* line 6797 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6798 */
  sim_icache_fetch(5089 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6800 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 14); /* line 6801 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6802 */
  sim_icache_fetch(5092 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6804 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 15); /* line 6805 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6806 */
  sim_icache_fetch(5095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6808 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6809 */
  sim_icache_fetch(5097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6811 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6812 */
  sim_icache_fetch(5099 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6814 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6815 */
  sim_icache_fetch(5101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6817 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6818 */
  sim_icache_fetch(5103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6820 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6821 */
  sim_icache_fetch(5105 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6823 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6824 */
  sim_icache_fetch(5107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6826 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L294X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6827 */
  sim_icache_fetch(5109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6829 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6830 */
l_L294X3: ;/* line 6833 */
__LABEL(l_L294X3);
  sim_icache_fetch(5111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6835 */
l_L290X3: ;/* line 6838 */
__LABEL(l_L290X3);
  sim_icache_fetch(5112 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6839 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6840 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6841 */
l_L289X3: ;/* line 6844 */
__LABEL(l_L289X3);
  sim_icache_fetch(5116 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6845 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6846 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6847 */
l_L288X3: ;/* line 6850 */
__LABEL(l_L288X3);
  sim_icache_fetch(5120 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6851 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6852 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6853 */
l_L287X3: ;/* line 6856 */
__LABEL(l_L287X3);
  sim_icache_fetch(5124 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6857 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6858 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6859 */
l_L286X3: ;/* line 6862 */
__LABEL(l_L286X3);
  sim_icache_fetch(5128 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6863 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6864 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6865 */
l_L285X3: ;/* line 6868 */
__LABEL(l_L285X3);
  sim_icache_fetch(5132 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6869 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6870 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6871 */
l_L284X3: ;/* line 6874 */
__LABEL(l_L284X3);
  sim_icache_fetch(5136 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6875 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6876 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6877 */
l_L283X3: ;/* line 6880 */
__LABEL(l_L283X3);
  sim_icache_fetch(5140 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6881 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6882 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6883 */
l_L282X3: ;/* line 6886 */
__LABEL(l_L282X3);
  sim_icache_fetch(5144 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6887 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6888 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6889 */
l_L281X3: ;/* line 6892 */
__LABEL(l_L281X3);
  sim_icache_fetch(5147 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6893 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6894 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6895 */
l_L280X3: ;/* line 6898 */
__LABEL(l_L280X3);
  sim_icache_fetch(5150 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6899 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6900 */
   __GOTO(l_L292X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L292X3;
} /* line 6901 */
l_L279X3: ;/* line 6904 */
__LABEL(l_L279X3);
  sim_icache_fetch(5153 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6905 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6906 */
} /* line 6906 */
l_L292X3: ;/* line 6908 */
__LABEL(l_L292X3);
  sim_icache_fetch(5155 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6909 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6910 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6911 */
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

  sim_icache_fetch(5158 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6927 */
} /* line 6927 */
  sim_icache_fetch(5159 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6930 */
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

  sim_icache_fetch(5160 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6946 */
} /* line 6946 */
  sim_icache_fetch(5161 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6949 */
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


static sim_fileinfo_t t_thisfile = {"compress.s", 5168, 0, 0, 0, 2};

