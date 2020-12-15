/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/4_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_9680Xoffset[1];
unsigned int compress_9680Xbuf[3];
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
unsigned int compress_9680XBuf[216]; 
unsigned int compress_9680Xrcs_ident[6]; 
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
	(137 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(151 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(143 << 5),
	(142 << 5),
	(141 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(140 << 5),
	(155 << 5),
	(155 << 5),
	(139 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(155 << 5),
	(138 << 5)
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

unsigned int compress_9680XBuf[216] = { 
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

unsigned int compress_9680Xrcs_ident[6] = { 
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
  sim_icache_fetch(11 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_6, (unsigned int) 800); /* line 32 */
   __MOV(reg_r0_5, (unsigned int) compress_9680XBuf); /* line 33 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 34 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 35 */
} /* line 35 */
  sim_icache_fetch(17 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), 0); /* line 37 */
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 38 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_6); /* line 39 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 40 */
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
  reg_l0_0 = (132 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_23, reg_r0_3, (unsigned int) 15); /* line 178 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 14); /* line 179 */
   __ADD(reg_r0_21, reg_r0_3, (unsigned int) 13); /* line 180 */
} /* line 180 */
  sim_icache_fetch(47 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 12); /* line 182 */
   __ADD(reg_r0_19, reg_r0_3, (unsigned int) 11); /* line 183 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 10); /* line 184 */
   __ADD(reg_r0_17, reg_r0_3, (unsigned int) 9); /* line 185 */
} /* line 185 */
  sim_icache_fetch(51 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 8); /* line 187 */
   __ADD(reg_r0_15, reg_r0_3, (unsigned int) 7); /* line 188 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 6); /* line 189 */
   __ADD(reg_r0_13, reg_r0_3, (unsigned int) 5); /* line 190 */
} /* line 190 */
  sim_icache_fetch(55 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 192 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 193 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 194 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 195 */
} /* line 195 */
  sim_icache_fetch(59 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SXTB(reg_r0_4, reg_r0_4); /* line 197 */
   __MOV(reg_r0_5, 0); /* line 198 */
   __MOV(reg_r0_2, reg_r0_3); /* line 199 */
} /* line 199 */
l_L0X3: ;/* line 202 */
__LABEL(l_L0X3);
  sim_icache_fetch(62 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 203 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 204 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 205 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_10,0,1)); /* line 206 */
} /* line 206 */
  sim_icache_fetch(66 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_12,0,1)); /* line 208 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_13,0,1)); /* line 209 */
   __LDBs(reg_r0_26, mem_trace_ld(reg_r0_14,0,1)); /* line 210 */
   __LDBs(reg_r0_27, mem_trace_ld(reg_r0_15,0,1)); /* line 211 */
} /* line 211 */
  sim_icache_fetch(70 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 213 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 214 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 215 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 216 */
} /* line 216 */
  sim_icache_fetch(74 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 218 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 219 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_4); /* line 220 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 221 */
  sim_icache_fetch(78 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_6, reg_r0_3); /* line 223 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 224 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 225 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 226 */
  sim_icache_fetch(82 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_8, reg_r0_7); /* line 228 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 229 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 230 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 231 */
  sim_icache_fetch(86 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_10, reg_r0_3); /* line 233 */
   __CMPNE(reg_b0_2, reg_r0_25, 0); /* line 234 */
   __CMPEQ(reg_b0_3, reg_r0_25, reg_r0_4); /* line 235 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 236 */
  sim_icache_fetch(90 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_12, reg_r0_7); /* line 238 */
   __CMPNE(reg_b0_0, reg_r0_26, 0); /* line 239 */
   __CMPEQ(reg_b0_1, reg_r0_26, reg_r0_4); /* line 240 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 241 */
  sim_icache_fetch(94 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_13, reg_r0_3); /* line 243 */
   __CMPNE(reg_b0_2, reg_r0_27, 0); /* line 244 */
   __CMPEQ(reg_b0_3, reg_r0_27, reg_r0_4); /* line 245 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 246 */
  sim_icache_fetch(98 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_14, reg_r0_7); /* line 248 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_16,0,1)); /* line 249 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_17,0,1)); /* line 250 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 251 */
  sim_icache_fetch(102 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_15, reg_r0_3); /* line 253 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_18,0,1)); /* line 254 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_19,0,1)); /* line 255 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 256 */
  sim_icache_fetch(106 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 258 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_4); /* line 259 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 260 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 261 */
} /* line 261 */
  sim_icache_fetch(110 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_16, reg_r0_7); /* line 263 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 264 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 265 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 266 */
  sim_icache_fetch(114 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_17, reg_r0_3); /* line 268 */
   __CMPNE(reg_b0_2, reg_r0_25, 0); /* line 269 */
   __CMPEQ(reg_b0_3, reg_r0_25, reg_r0_4); /* line 270 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 271 */
  sim_icache_fetch(118 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_18, reg_r0_7); /* line 273 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_20,0,1)); /* line 274 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_21,0,1)); /* line 275 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 276 */
  sim_icache_fetch(122 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_19, reg_r0_3); /* line 278 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_22,0,1)); /* line 279 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_23,0,1)); /* line 280 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 281 */
  sim_icache_fetch(126 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 283 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_4); /* line 284 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 285 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 286 */
} /* line 286 */
  sim_icache_fetch(130 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_20, reg_r0_7); /* line 288 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 289 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 290 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 291 */
  sim_icache_fetch(134 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_21, reg_r0_3); /* line 293 */
   __CMPNE(reg_b0_2, reg_r0_25, 0); /* line 294 */
   __CMPEQ(reg_b0_3, reg_r0_25, reg_r0_4); /* line 295 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 296 */
  sim_icache_fetch(138 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_22, reg_r0_7); /* line 298 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 299 */
   __ADD(reg_r0_22, reg_r0_22, (unsigned int) 16); /* line 300 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 301 */
  sim_icache_fetch(142 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_3, reg_r0_23, reg_r0_3); /* line 303 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 304 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 305 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 306 */
  sim_icache_fetch(146 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 308 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 309 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 310 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 311 */
} /* line 311 */
  sim_icache_fetch(150 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 313 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 314 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 315 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 316 */
} /* line 316 */
  sim_icache_fetch(154 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 318 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 319 */
   __ADD(reg_r0_23, reg_r0_23, (unsigned int) 16); /* line 320 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 321 */
} /* line 321 */
  sim_icache_fetch(158 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 323 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 324 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 325 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_10,0,1)); /* line 326 */
} /* line 326 */
  sim_icache_fetch(162 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_12,0,1)); /* line 328 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_13,0,1)); /* line 329 */
   __LDBs(reg_r0_26, mem_trace_ld(reg_r0_14,0,1)); /* line 330 */
   __LDBs(reg_r0_27, mem_trace_ld(reg_r0_15,0,1)); /* line 331 */
} /* line 331 */
  sim_icache_fetch(166 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 333 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 334 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 335 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 336 */
} /* line 336 */
  sim_icache_fetch(170 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 338 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 339 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_4); /* line 340 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 341 */
  sim_icache_fetch(174 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_6, reg_r0_3); /* line 343 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 344 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 345 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 346 */
  sim_icache_fetch(178 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_8, reg_r0_7); /* line 348 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 349 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 350 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 351 */
  sim_icache_fetch(182 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_10, reg_r0_3); /* line 353 */
   __CMPNE(reg_b0_2, reg_r0_25, 0); /* line 354 */
   __CMPEQ(reg_b0_3, reg_r0_25, reg_r0_4); /* line 355 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 356 */
  sim_icache_fetch(186 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_12, reg_r0_7); /* line 358 */
   __CMPNE(reg_b0_0, reg_r0_26, 0); /* line 359 */
   __CMPEQ(reg_b0_1, reg_r0_26, reg_r0_4); /* line 360 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 361 */
  sim_icache_fetch(190 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_13, reg_r0_3); /* line 363 */
   __CMPNE(reg_b0_2, reg_r0_27, 0); /* line 364 */
   __CMPEQ(reg_b0_3, reg_r0_27, reg_r0_4); /* line 365 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 366 */
  sim_icache_fetch(194 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_14, reg_r0_7); /* line 368 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_16,0,1)); /* line 369 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_17,0,1)); /* line 370 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 371 */
  sim_icache_fetch(198 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_15, reg_r0_3); /* line 373 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_18,0,1)); /* line 374 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_19,0,1)); /* line 375 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 376 */
  sim_icache_fetch(202 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 378 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_4); /* line 379 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 380 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 381 */
} /* line 381 */
  sim_icache_fetch(206 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_16, reg_r0_7); /* line 383 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 384 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 385 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 386 */
  sim_icache_fetch(210 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_17, reg_r0_3); /* line 388 */
   __CMPNE(reg_b0_2, reg_r0_25, 0); /* line 389 */
   __CMPEQ(reg_b0_3, reg_r0_25, reg_r0_4); /* line 390 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 391 */
  sim_icache_fetch(214 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_18, reg_r0_7); /* line 393 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_20,0,1)); /* line 394 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_21,0,1)); /* line 395 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 396 */
  sim_icache_fetch(218 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_19, reg_r0_3); /* line 398 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_22,0,1)); /* line 399 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_23,0,1)); /* line 400 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 401 */
  sim_icache_fetch(222 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 403 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_4); /* line 404 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 405 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 406 */
} /* line 406 */
  sim_icache_fetch(226 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_20, reg_r0_7); /* line 408 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 409 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 410 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 411 */
  sim_icache_fetch(230 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_21, reg_r0_3); /* line 413 */
   __CMPNE(reg_b0_2, reg_r0_25, 0); /* line 414 */
   __CMPEQ(reg_b0_3, reg_r0_25, reg_r0_4); /* line 415 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 416 */
  sim_icache_fetch(234 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_22, reg_r0_7); /* line 418 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 419 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 420 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 421 */
  sim_icache_fetch(238 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_3, reg_r0_23, reg_r0_3); /* line 423 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 424 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 425 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 426 */
  sim_icache_fetch(242 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 428 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 429 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 430 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 431 */
} /* line 431 */
  sim_icache_fetch(246 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 433 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 434 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 435 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 436 */
} /* line 436 */
  sim_icache_fetch(250 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 438 */
   __ADD(reg_r0_22, reg_r0_22, (unsigned int) 16); /* line 439 */
   __ADD(reg_r0_23, reg_r0_23, (unsigned int) 16); /* line 440 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 442 */
} /* line 442 */
  sim_icache_fetch(254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 444 */
l_L16X3: ;/* line 447 */
__LABEL(l_L16X3);
  sim_icache_fetch(255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 450 */
l_L15X3: ;/* line 453 */
__LABEL(l_L15X3);
  sim_icache_fetch(256 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 455 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 456 */
l_L14X3: ;/* line 459 */
__LABEL(l_L14X3);
  sim_icache_fetch(258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 462 */
l_L13X3: ;/* line 465 */
__LABEL(l_L13X3);
  sim_icache_fetch(259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 467 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 468 */
l_L20X3: ;/* line 471 */
__LABEL(l_L20X3);
  sim_icache_fetch(261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 474 */
l_L19X3: ;/* line 477 */
__LABEL(l_L19X3);
  sim_icache_fetch(262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 479 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 480 */
l_L10X3: ;/* line 483 */
__LABEL(l_L10X3);
  sim_icache_fetch(264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 486 */
l_L9X3: ;/* line 489 */
__LABEL(l_L9X3);
  sim_icache_fetch(265 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 491 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 492 */
l_L18X3: ;/* line 495 */
__LABEL(l_L18X3);
  sim_icache_fetch(267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 498 */
l_L17X3: ;/* line 501 */
__LABEL(l_L17X3);
  sim_icache_fetch(268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 503 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 504 */
l_L6X3: ;/* line 507 */
__LABEL(l_L6X3);
  sim_icache_fetch(270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 510 */
l_L5X3: ;/* line 513 */
__LABEL(l_L5X3);
  sim_icache_fetch(271 + t_thisfile.offset, 2);
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
l_L4X3: ;/* line 519 */
__LABEL(l_L4X3);
  sim_icache_fetch(273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 522 */
l_L3X3: ;/* line 525 */
__LABEL(l_L3X3);
  sim_icache_fetch(274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 527 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 528 */
l_L2X3: ;/* line 531 */
__LABEL(l_L2X3);
  sim_icache_fetch(276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 534 */
l_L1X3: ;/* line 537 */
__LABEL(l_L1X3);
  sim_icache_fetch(277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 539 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 540 */
l_L12X3: ;/* line 543 */
__LABEL(l_L12X3);
  sim_icache_fetch(279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 546 */
l_L11X3: ;/* line 549 */
__LABEL(l_L11X3);
  sim_icache_fetch(280 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 551 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 552 */
l_L8X3: ;/* line 555 */
__LABEL(l_L8X3);
  sim_icache_fetch(282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 558 */
l_L7X3: ;/* line 561 */
__LABEL(l_L7X3);
  sim_icache_fetch(283 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 563 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 564 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 111: goto l_L0X3;
    case 112: goto l_L16X3;
    case 113: goto l_L15X3;
    case 114: goto l_L14X3;
    case 115: goto l_L13X3;
    case 116: goto l_L20X3;
    case 117: goto l_L19X3;
    case 118: goto l_L10X3;
    case 119: goto l_L9X3;
    case 120: goto l_L18X3;
    case 121: goto l_L17X3;
    case 122: goto l_L6X3;
    case 123: goto l_L5X3;
    case 124: goto l_L4X3;
    case 125: goto l_L3X3;
    case 126: goto l_L2X3;
    case 127: goto l_L1X3;
    case 128: goto l_L12X3;
    case 129: goto l_L11X3;
    case 130: goto l_L8X3;
    case 131: goto l_L7X3;
    case 132:
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
  reg_l0_0 = (199 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(285 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 580 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 581 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 582 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 583 */
} /* line 583 */
  sim_icache_fetch(292 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 585 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 586 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 587 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 588 */
} /* line 588 */
  sim_icache_fetch(297 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 590 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 591 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 592 */
} /* line 592 */
		 /* line 593 */
  sim_icache_fetch(300 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 595 */
l_lr_33: ;/* line 595 */
__LABEL(l_lr_33);
  sim_icache_fetch(302 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 597 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 598 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 599 */
   __ADD_CYCLES(1);
} /* line 599 */
  sim_icache_fetch(305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 601 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 602 */
} /* line 602 */
l_L21X3: ;/* line 605 */
__LABEL(l_L21X3);
  sim_icache_fetch(307 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 606 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 607 */
} /* line 607 */
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 609 */
  sim_icache_fetch(310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 611 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 612 */
   __ADD_CYCLES(1);
} /* line 612 */
  sim_icache_fetch(312 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 614 */
} /* line 614 */
  sim_icache_fetch(313 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 616 */
l_L24X3: ;/* line 619 */
__LABEL(l_L24X3);
  sim_icache_fetch(314 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 620 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 621 */
   __ADD_CYCLES(1);
} /* line 621 */
  sim_icache_fetch(316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 623 */
} /* line 623 */
  sim_icache_fetch(317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 625 */
} /* line 625 */
  sim_icache_fetch(318 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 627 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 628 */
   __ADD_CYCLES(1);
} /* line 628 */
  sim_icache_fetch(320 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 630 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 631 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 632 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 633 */
} /* line 633 */
  sim_icache_fetch(325 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 635 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 636 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 637 */
  sim_icache_fetch(328 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 639 */
  sim_icache_fetch(329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 640 */
  sim_icache_fetch(330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 642 */
l__X1XCompressXTAGX0X0: ;/* line 644 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(331 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 645 */
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 646 */
l__X1XCompressXTAGX0X7: ;/* line 649 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(334 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 650 */
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 651 */
l__X1XCompressXTAGX0X6: ;/* line 654 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(337 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 655 */
} /* line 655 */
  sim_icache_fetch(338 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 657 */
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 658 */
l__X1XCompressXTAGX0X5: ;/* line 661 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(341 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 662 */
} /* line 662 */
  sim_icache_fetch(342 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 664 */
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 665 */
l__X1XCompressXTAGX0X4: ;/* line 668 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(345 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 669 */
} /* line 669 */
  sim_icache_fetch(346 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 671 */
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 672 */
l__X1XCompressXTAGX0X3: ;/* line 675 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 676 */
} /* line 676 */
  sim_icache_fetch(350 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 678 */
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 679 */
l__X1XCompressXTAGX0X2: ;/* line 682 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 683 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 684 */
   __ADD_CYCLES(1);
} /* line 684 */
  sim_icache_fetch(355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 686 */
} /* line 686 */
  sim_icache_fetch(356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 688 */
} /* line 688 */
  sim_icache_fetch(357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 690 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 691 */
   __ADD_CYCLES(1);
} /* line 691 */
  sim_icache_fetch(359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 693 */
} /* line 693 */
  sim_icache_fetch(360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 695 */
l_L23X3: ;/* line 697 */
__LABEL(l_L23X3);
  sim_icache_fetch(361 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 698 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 699 */
   __GOTO(l_L21X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L21X3;
} /* line 700 */
l_L27X3: ;/* line 703 */
__LABEL(l_L27X3);
  sim_icache_fetch(364 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 704 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 705 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 706 */
} /* line 706 */
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 708 */
} /* line 708 */
  sim_icache_fetch(368 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 710 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 711 */
  sim_icache_fetch(370 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 714 */
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 716 */
l_L28X3: ;/* line 719 */
__LABEL(l_L28X3);
		 /* line 719 */
  sim_icache_fetch(372 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 722 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (199 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 722 */
l_lr_47: ;/* line 722 */
__LABEL(l_lr_47);
		 /* line 723 */
  sim_icache_fetch(376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (199 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 725 */
l_lr_49: ;/* line 725 */
__LABEL(l_lr_49);
  sim_icache_fetch(378 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 727 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 728 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 729 */
   __ADD_CYCLES(1);
} /* line 729 */
  sim_icache_fetch(381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 732 */
l__X1XCompressXTAGX0X1: ;/* line 735 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 735 */
  sim_icache_fetch(382 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 738 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 739 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 739 */
l_lr_52: ;/* line 739 */
__LABEL(l_lr_52);
  sim_icache_fetch(386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 741 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 742 */
} /* line 742 */
  sim_icache_fetch(388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 744 */
l_L26X3: ;/* line 747 */
__LABEL(l_L26X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 748 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 748 */
  sim_icache_fetch(389 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 751 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (199 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 751 */
l_lr_56: ;/* line 751 */
__LABEL(l_lr_56);
		 /* line 752 */
  sim_icache_fetch(393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (199 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 754 */
l_lr_58: ;/* line 754 */
__LABEL(l_lr_58);
  sim_icache_fetch(395 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 756 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 757 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 758 */
   __ADD_CYCLES(1);
} /* line 758 */
  sim_icache_fetch(398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 761 */
l_L25X3: ;/* line 764 */
__LABEL(l_L25X3);
  sim_icache_fetch(399 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 765 */
l_L22X3: ;/* line 768 */
__LABEL(l_L22X3);
  sim_icache_fetch(400 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 769 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 770 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 771 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 772 */
} /* line 772 */
  sim_icache_fetch(405 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 774 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 775 */
} /* line 775 */
  sim_icache_fetch(409 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 777 */
} /* line 777 */
  sim_icache_fetch(410 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 4096); /* line 779 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 780 */
  sim_icache_fetch(413 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 782 */
} /* line 782 */
l_L30X3: ;/* line 784 */
__LABEL(l_L30X3);
  sim_icache_fetch(415 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 785 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 786 */
   __ADD_CYCLES(1);
} /* line 786 */
  sim_icache_fetch(418 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 12); /* line 788 */
} /* line 788 */
  sim_icache_fetch(419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 790 */
  sim_icache_fetch(420 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 792 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 793 */
} /* line 793 */
l_L32X3: ;/* line 795 */
__LABEL(l_L32X3);
  sim_icache_fetch(424 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 796 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 797 */
   __ADD_CYCLES(1);
} /* line 797 */
  sim_icache_fetch(427 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 799 */
} /* line 799 */
  sim_icache_fetch(428 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 801 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L33X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 802 */
		 /* line 803 */
  sim_icache_fetch(431 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 805 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 806 */
l_lr_64: ;/* line 806 */
__LABEL(l_lr_64);
l_L34X3: ;/* line 808 */
__LABEL(l_L34X3);
  sim_icache_fetch(435 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 809 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 810 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 811 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 812 */
} /* line 812 */
  sim_icache_fetch(443 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 814 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 815 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 816 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 817 */
} /* line 817 */
  sim_icache_fetch(451 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 819 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 820 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 821 */
   __ADD(reg_r0_11, reg_r0_2, (unsigned int) -1); /* line 822 */
} /* line 822 */
  sim_icache_fetch(457 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 824 */
   __CMPGE(reg_b0_1, reg_r0_11, 0); /* line 825 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 826 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 827 */
} /* line 827 */
  sim_icache_fetch(462 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 829 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 830 */
  sim_icache_fetch(464 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_11); /* line 832 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 833 */
  sim_icache_fetch(467 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 835 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 836 */
l_L38X3: ;/* line 838 */
__LABEL(l_L38X3);
		 /* line 838 */
  sim_icache_fetch(470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (199 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 840 */
l_lr_68: ;/* line 840 */
__LABEL(l_lr_68);
  sim_icache_fetch(472 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 842 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 843 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 844 */
   __ADD_CYCLES(1);
} /* line 844 */
  sim_icache_fetch(475 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 847 */
l_L37X3: ;/* line 850 */
__LABEL(l_L37X3);
  sim_icache_fetch(476 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 851 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 852 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 853 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 854 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 855 */
   __ADD_CYCLES(1);
} /* line 855 */
  sim_icache_fetch(485 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 857 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 858 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 859 */
} /* line 859 */
  sim_icache_fetch(488 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 861 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 862 */
} /* line 862 */
  sim_icache_fetch(491 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L39X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 864 */
  sim_icache_fetch(492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 866 */
} /* line 866 */
  sim_icache_fetch(494 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 868 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 869 */
   __ADD_CYCLES(1);
} /* line 869 */
  sim_icache_fetch(496 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 871 */
} /* line 871 */
l_L40X3: ;/* line 873 */
__LABEL(l_L40X3);
  sim_icache_fetch(497 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 874 */
} /* line 874 */
  sim_icache_fetch(498 + t_thisfile.offset, 1);
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
} /* line 877 */
  sim_icache_fetch(499 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 879 */
l_L41X3: ;/* line 882 */
__LABEL(l_L41X3);
  sim_icache_fetch(500 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 883 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 884 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 885 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 886 */
} /* line 886 */
  sim_icache_fetch(507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 888 */
} /* line 888 */
  sim_icache_fetch(509 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 890 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 891 */
} /* line 891 */
  sim_icache_fetch(511 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 893 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 894 */
} /* line 894 */
  sim_icache_fetch(514 + t_thisfile.offset, 1);
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
} /* line 896 */
  sim_icache_fetch(515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 898 */
} /* line 898 */
  sim_icache_fetch(517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 900 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 901 */
   __ADD_CYCLES(1);
} /* line 901 */
  sim_icache_fetch(519 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 903 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 904 */
} /* line 904 */
l_L43X3: ;/* line 906 */
__LABEL(l_L43X3);
  sim_icache_fetch(522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 907 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 908 */
} /* line 908 */
  sim_icache_fetch(524 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 910 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 911 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 912 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 913 */
} /* line 913 */
  sim_icache_fetch(530 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 915 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 916 */
		 /* line 917 */
  sim_icache_fetch(533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (199 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 919 */
l_lr_74: ;/* line 919 */
__LABEL(l_lr_74);
  sim_icache_fetch(535 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 921 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 922 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 923 */
   __ADD_CYCLES(1);
} /* line 923 */
  sim_icache_fetch(538 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 926 */
l_L35X3: ;/* line 929 */
__LABEL(l_L35X3);
		 /* line 929 */
  sim_icache_fetch(539 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 931 */
l_lr_77: ;/* line 931 */
__LABEL(l_lr_77);
  sim_icache_fetch(541 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 933 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 934 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 935 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 936 */
   __ADD_CYCLES(1);
} /* line 936 */
  sim_icache_fetch(545 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 939 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 940 */
l_L42X3: ;/* line 943 */
__LABEL(l_L42X3);
  sim_icache_fetch(548 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 944 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 945 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 946 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 947 */
} /* line 947 */
  sim_icache_fetch(554 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 949 */
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 950 */
l_L39X3: ;/* line 953 */
__LABEL(l_L39X3);
  sim_icache_fetch(557 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 954 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 955 */
   __GOTO(l_L40X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L40X3;
} /* line 956 */
l_L36X3: ;/* line 959 */
__LABEL(l_L36X3);
  sim_icache_fetch(561 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 960 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 961 */
} /* line 961 */
  sim_icache_fetch(564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 963 */
} /* line 963 */
  sim_icache_fetch(565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 966 */
  sim_icache_fetch(566 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 968 */
l_L33X3: ;/* line 971 */
__LABEL(l_L33X3);
  sim_icache_fetch(567 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 972 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 973 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 974 */
   __ADD_CYCLES(1);
} /* line 974 */
  sim_icache_fetch(572 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 976 */
} /* line 976 */
  sim_icache_fetch(574 + t_thisfile.offset, 1);
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
} /* line 978 */
		 /* line 979 */
  sim_icache_fetch(575 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 981 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 982 */
l_lr_83: ;/* line 982 */
__LABEL(l_lr_83);
  sim_icache_fetch(579 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 984 */
l_L44X3: ;/* line 987 */
__LABEL(l_L44X3);
  sim_icache_fetch(580 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 988 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 989 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 990 */
   __ADD_CYCLES(1);
} /* line 990 */
  sim_icache_fetch(585 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 992 */
} /* line 992 */
  sim_icache_fetch(587 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 994 */
		 /* line 995 */
  sim_icache_fetch(588 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 997 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 998 */
l_lr_86: ;/* line 998 */
__LABEL(l_lr_86);
  sim_icache_fetch(592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 1000 */
l_L45X3: ;/* line 1003 */
__LABEL(l_L45X3);
  sim_icache_fetch(593 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1004 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1005 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1006 */
   __ADD_CYCLES(1);
} /* line 1006 */
  sim_icache_fetch(598 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1008 */
} /* line 1008 */
  sim_icache_fetch(600 + t_thisfile.offset, 1);
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
} /* line 1010 */
		 /* line 1011 */
  sim_icache_fetch(601 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1013 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1014 */
l_lr_89: ;/* line 1014 */
__LABEL(l_lr_89);
  sim_icache_fetch(605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 1016 */
l_L46X3: ;/* line 1019 */
__LABEL(l_L46X3);
  sim_icache_fetch(606 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1020 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1021 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1022 */
   __ADD_CYCLES(1);
} /* line 1022 */
  sim_icache_fetch(611 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1024 */
} /* line 1024 */
  sim_icache_fetch(613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L47X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1026 */
		 /* line 1027 */
  sim_icache_fetch(614 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1029 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1030 */
l_lr_92: ;/* line 1030 */
__LABEL(l_lr_92);
  sim_icache_fetch(618 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 1032 */
l_L47X3: ;/* line 1035 */
__LABEL(l_L47X3);
		 /* line 1035 */
  sim_icache_fetch(619 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (199 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1037 */
l_lr_95: ;/* line 1037 */
__LABEL(l_lr_95);
  sim_icache_fetch(621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 1039 */
l_L31X3: ;/* line 1042 */
__LABEL(l_L31X3);
  sim_icache_fetch(622 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1043 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1044 */
} /* line 1044 */
  sim_icache_fetch(625 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1046 */
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 1047 */
l_L29X3: ;/* line 1050 */
__LABEL(l_L29X3);
  sim_icache_fetch(628 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1051 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1052 */
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1053 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 134: goto l_lr_33;
    case 135: goto l_L21X3;
    case 136: goto l_L24X3;
    case 137: goto l__X1XCompressXTAGX0X0;
    case 138: goto l__X1XCompressXTAGX0X7;
    case 139: goto l__X1XCompressXTAGX0X6;
    case 140: goto l__X1XCompressXTAGX0X5;
    case 141: goto l__X1XCompressXTAGX0X4;
    case 142: goto l__X1XCompressXTAGX0X3;
    case 143: goto l__X1XCompressXTAGX0X2;
    case 144: goto l_L23X3;
    case 145: goto l_L27X3;
    case 146: goto l_L28X3;
    case 148: goto l_lr_47;
    case 150: goto l_lr_49;
    case 151: goto l__X1XCompressXTAGX0X1;
    case 153: goto l_lr_52;
    case 154: goto l_L26X3;
    case 155: goto l__X1XCompressXTAGX0XDEFAULT;
    case 157: goto l_lr_56;
    case 159: goto l_lr_58;
    case 160: goto l_L25X3;
    case 161: goto l_L22X3;
    case 162: goto l_L30X3;
    case 163: goto l_L32X3;
    case 165: goto l_lr_64;
    case 166: goto l_L34X3;
    case 167: goto l_L38X3;
    case 169: goto l_lr_68;
    case 170: goto l_L37X3;
    case 171: goto l_L40X3;
    case 172: goto l_L41X3;
    case 173: goto l_L43X3;
    case 175: goto l_lr_74;
    case 176: goto l_L35X3;
    case 178: goto l_lr_77;
    case 179: goto l_L42X3;
    case 180: goto l_L39X3;
    case 181: goto l_L36X3;
    case 182: goto l_L33X3;
    case 184: goto l_lr_83;
    case 185: goto l_L44X3;
    case 187: goto l_lr_86;
    case 188: goto l_L45X3;
    case 190: goto l_lr_89;
    case 191: goto l_L46X3;
    case 193: goto l_lr_92;
    case 194: goto l_L47X3;
    case 196: goto l_lr_95;
    case 197: goto l_L31X3;
    case 198: goto l_L29X3;
    case 199:
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
  reg_l0_0 = (318 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(631 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1191 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1192 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1193 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1194 */
} /* line 1194 */
  sim_icache_fetch(636 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1196 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1197 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1198 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1199 */
} /* line 1199 */
  sim_icache_fetch(642 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1201 */
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1202 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1203 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1204 */
} /* line 1204 */
  sim_icache_fetch(649 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1206 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1207 */
   __MOV(reg_r0_4, 0); /* line 1208 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1209 */
l_L49X3: ;/* line 1211 */
__LABEL(l_L49X3);
  sim_icache_fetch(655 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_9680Xoffset,0,4), 0); /* line 1212 */
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 1213 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1214 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1215 */
} /* line 1215 */
  sim_icache_fetch(661 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1217 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, (unsigned int) 256); /* line 1218 */
   __CMPGE(reg_b0_1, reg_r0_13, 0); /* line 1219 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) 1); /* line 1220 */
} /* line 1220 */
  sim_icache_fetch(667 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1222 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1223 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1224 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1225 */
} /* line 1225 */
  sim_icache_fetch(675 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1227 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1228 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1229 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1230 */
} /* line 1230 */
  sim_icache_fetch(683 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1232 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1233 */
  sim_icache_fetch(686 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1235 */
} /* line 1235 */
  sim_icache_fetch(688 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 1237 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1238 */
   __ADD_CYCLES(1);
} /* line 1238 */
  sim_icache_fetch(690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 1240 */
} /* line 1240 */
l_L51X3: ;/* line 1242 */
__LABEL(l_L51X3);
  sim_icache_fetch(691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_5); /* line 1243 */
} /* line 1243 */
  sim_icache_fetch(692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, reg_l0_0); /* line 1245 */
} /* line 1245 */
l_L52X3: ;/* line 1248 */
__LABEL(l_L52X3);
  sim_icache_fetch(693 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1249 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1250 */
} /* line 1250 */
  sim_icache_fetch(695 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1252 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1253 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L53X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1254 */
  sim_icache_fetch(698 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1256 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1257 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1258 */
  sim_icache_fetch(701 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1260 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1261 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L55X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1262 */
  sim_icache_fetch(704 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1264 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1265 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1266 */
  sim_icache_fetch(707 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1268 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1269 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1270 */
  sim_icache_fetch(710 + t_thisfile.offset, 3);
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
      goto l_L58X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1274 */
  sim_icache_fetch(713 + t_thisfile.offset, 3);
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
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1278 */
  sim_icache_fetch(716 + t_thisfile.offset, 3);
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
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1282 */
  sim_icache_fetch(719 + t_thisfile.offset, 3);
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
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1286 */
  sim_icache_fetch(722 + t_thisfile.offset, 3);
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
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1290 */
  sim_icache_fetch(725 + t_thisfile.offset, 3);
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
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1294 */
  sim_icache_fetch(728 + t_thisfile.offset, 3);
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
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1298 */
  sim_icache_fetch(731 + t_thisfile.offset, 3);
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
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1302 */
  sim_icache_fetch(734 + t_thisfile.offset, 3);
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
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1306 */
  sim_icache_fetch(737 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1310 */
  sim_icache_fetch(740 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1314 */
  sim_icache_fetch(743 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1316 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1317 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1318 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L53X3; 
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
      goto l_L54X3; 
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
      goto l_L55X3; 
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
      goto l_L56X3; 
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
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1335 */
  sim_icache_fetch(759 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1337 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1338 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1339 */
  sim_icache_fetch(762 + t_thisfile.offset, 3);
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
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1343 */
  sim_icache_fetch(765 + t_thisfile.offset, 3);
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
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1347 */
  sim_icache_fetch(768 + t_thisfile.offset, 3);
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
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1351 */
  sim_icache_fetch(771 + t_thisfile.offset, 3);
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
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1355 */
  sim_icache_fetch(774 + t_thisfile.offset, 3);
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
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1359 */
  sim_icache_fetch(777 + t_thisfile.offset, 3);
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
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1363 */
  sim_icache_fetch(780 + t_thisfile.offset, 3);
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
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1367 */
  sim_icache_fetch(783 + t_thisfile.offset, 3);
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
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1371 */
  sim_icache_fetch(786 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1375 */
  sim_icache_fetch(789 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1377 */
  sim_icache_fetch(790 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1379 */
   __GOTO(l_L52X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L52X3;
} /* line 1380 */
l_L68X3: ;/* line 1383 */
__LABEL(l_L68X3);
  sim_icache_fetch(792 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1384 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1385 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1386 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1387 */
} /* line 1387 */
  sim_icache_fetch(797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1389 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 1390 */
l_L70X3: ;/* line 1393 */
__LABEL(l_L70X3);
  sim_icache_fetch(799 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1394 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1395 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1396 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1397 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1398 */
   __ADD_CYCLES(1);
} /* line 1398 */
  sim_icache_fetch(808 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1400 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1401 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1402 */
} /* line 1402 */
  sim_icache_fetch(811 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1404 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1405 */
} /* line 1405 */
  sim_icache_fetch(814 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1407 */
  sim_icache_fetch(815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1409 */
} /* line 1409 */
  sim_icache_fetch(817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1411 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1412 */
   __ADD_CYCLES(1);
} /* line 1412 */
  sim_icache_fetch(819 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1414 */
} /* line 1414 */
l_L72X3: ;/* line 1416 */
__LABEL(l_L72X3);
  sim_icache_fetch(820 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1417 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1418 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1419 */
} /* line 1419 */
  sim_icache_fetch(823 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1421 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1422 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1423 */
  sim_icache_fetch(826 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1425 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1426 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1427 */
} /* line 1427 */
  sim_icache_fetch(832 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1429 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1430 */
   __ADD_CYCLES(1);
} /* line 1430 */
  sim_icache_fetch(834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1432 */
} /* line 1432 */
  sim_icache_fetch(835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1434 */
  sim_icache_fetch(836 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1436 */
} /* line 1436 */
  sim_icache_fetch(837 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L70X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L70X3;
} /* line 1438 */
l_L74X3: ;/* line 1441 */
__LABEL(l_L74X3);
  sim_icache_fetch(838 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1442 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1443 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1444 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1445 */
} /* line 1445 */
  sim_icache_fetch(842 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_2, reg_r0_2, (unsigned int) htab); /* line 1447 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1448 */
} /* line 1448 */
  sim_icache_fetch(845 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld(reg_r0_2,0,4)); /* line 1450 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1451 */
   __ADD_CYCLES(1);
} /* line 1451 */
  sim_icache_fetch(847 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1453 */
} /* line 1453 */
  sim_icache_fetch(848 + t_thisfile.offset, 1);
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
} /* line 1455 */
l_L76X3: ;/* line 1457 */
__LABEL(l_L76X3);
		 /* line 1457 */
  sim_icache_fetch(849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (318 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1459 */
l_lr_108: ;/* line 1459 */
__LABEL(l_lr_108);
  sim_icache_fetch(851 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1461 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1462 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1463 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1464 */
} /* line 1464 */
  sim_icache_fetch(858 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1466 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1467 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1468 */
} /* line 1468 */
  sim_icache_fetch(861 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1470 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1471 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1472 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1473 */
} /* line 1473 */
  sim_icache_fetch(865 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1475 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1476 */
   __SH2ADD(reg_r0_12, reg_r0_2, (unsigned int) htab); /* line 1477 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1478 */
  sim_icache_fetch(872 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1480 */
   __STH(mem_trace_st(reg_r0_10,0,2), reg_r0_7); /* line 1481 */
   __STW(mem_trace_st(reg_r0_12,0,4), reg_r0_5); /* line 1482 */
   __GOTO(l_L70X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L70X3;
} /* line 1483 */
l_L77X3: ;/* line 1486 */
__LABEL(l_L77X3);
  sim_icache_fetch(877 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1487 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1488 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1489 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1490 */
} /* line 1490 */
  sim_icache_fetch(883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1492 */
} /* line 1492 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1494 */
} /* line 1494 */
  sim_icache_fetch(886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1496 */
} /* line 1496 */
  sim_icache_fetch(887 + t_thisfile.offset, 1);
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
} /* line 1498 */
		 /* line 1499 */
  sim_icache_fetch(888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (318 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1501 */
l_lr_111: ;/* line 1501 */
__LABEL(l_lr_111);
  sim_icache_fetch(890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1503 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1504 */
} /* line 1504 */
  sim_icache_fetch(892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L70X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L70X3;
} /* line 1506 */
l_L78X3: ;/* line 1509 */
__LABEL(l_L78X3);
  sim_icache_fetch(893 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1510 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1511 */
} /* line 1511 */
  sim_icache_fetch(895 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L70X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L70X3;
} /* line 1513 */
l_L75X3: ;/* line 1516 */
__LABEL(l_L75X3);
  sim_icache_fetch(896 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1517 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1518 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1519 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1520 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1521 */
   __ADD_CYCLES(1);
} /* line 1521 */
  sim_icache_fetch(901 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1523 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1524 */
} /* line 1524 */
  sim_icache_fetch(903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1526 */
} /* line 1526 */
l_L79X3: ;/* line 1529 */
__LABEL(l_L79X3);
  sim_icache_fetch(904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1530 */
} /* line 1530 */
  sim_icache_fetch(905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1532 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1533 */
} /* line 1533 */
  sim_icache_fetch(907 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1535 */
} /* line 1535 */
  sim_icache_fetch(908 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1537 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1538 */
} /* line 1538 */
  sim_icache_fetch(911 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1540 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1541 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1542 */
} /* line 1542 */
  sim_icache_fetch(914 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1544 */
} /* line 1544 */
  sim_icache_fetch(915 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1546 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1547 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1548 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1549 */
} /* line 1549 */
  sim_icache_fetch(920 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1551 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1552 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1553 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1554 */
  sim_icache_fetch(924 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1556 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1557 */
  sim_icache_fetch(926 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1559 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1560 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1561 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1562 */
} /* line 1562 */
  sim_icache_fetch(931 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1564 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1565 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1566 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1567 */
  sim_icache_fetch(935 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1569 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1570 */
  sim_icache_fetch(937 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1572 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1573 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1574 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1575 */
} /* line 1575 */
  sim_icache_fetch(942 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1577 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1578 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1579 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1580 */
  sim_icache_fetch(946 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1582 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L85X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1583 */
  sim_icache_fetch(948 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1585 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1586 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1587 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1588 */
} /* line 1588 */
  sim_icache_fetch(953 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1590 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1591 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1592 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1593 */
  sim_icache_fetch(957 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1595 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1596 */
  sim_icache_fetch(959 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1598 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1599 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1600 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1601 */
} /* line 1601 */
  sim_icache_fetch(964 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1603 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1604 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1605 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1606 */
  sim_icache_fetch(968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1608 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1609 */
  sim_icache_fetch(970 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1611 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1612 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1613 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1614 */
} /* line 1614 */
  sim_icache_fetch(975 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1616 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1617 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1618 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1619 */
  sim_icache_fetch(979 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1621 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1622 */
  sim_icache_fetch(981 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1624 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1625 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1626 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1627 */
} /* line 1627 */
  sim_icache_fetch(986 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1629 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1630 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1631 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1632 */
  sim_icache_fetch(990 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1634 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1635 */
  sim_icache_fetch(992 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1637 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1638 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1639 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1640 */
} /* line 1640 */
  sim_icache_fetch(997 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1642 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1643 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1644 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1645 */
  sim_icache_fetch(1001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1647 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1648 */
  sim_icache_fetch(1003 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1650 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1651 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1652 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1653 */
} /* line 1653 */
  sim_icache_fetch(1008 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1655 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1656 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1657 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1658 */
  sim_icache_fetch(1012 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1660 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1661 */
  sim_icache_fetch(1014 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1663 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1664 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1665 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1666 */
} /* line 1666 */
  sim_icache_fetch(1019 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1668 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1669 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1670 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1671 */
  sim_icache_fetch(1023 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1673 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1674 */
  sim_icache_fetch(1025 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1676 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1677 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1678 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1679 */
} /* line 1679 */
  sim_icache_fetch(1030 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1681 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1682 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1683 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1684 */
  sim_icache_fetch(1034 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1686 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1687 */
  sim_icache_fetch(1036 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1689 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1690 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1691 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1692 */
} /* line 1692 */
  sim_icache_fetch(1041 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1694 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1695 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1696 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1697 */
  sim_icache_fetch(1045 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1699 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1700 */
  sim_icache_fetch(1047 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1702 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1703 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1704 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1705 */
} /* line 1705 */
  sim_icache_fetch(1052 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1707 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1708 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1709 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1710 */
  sim_icache_fetch(1056 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1712 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1713 */
  sim_icache_fetch(1058 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1715 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1716 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1717 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(1063 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1720 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1721 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1722 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1723 */
  sim_icache_fetch(1067 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1725 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1726 */
  sim_icache_fetch(1069 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1728 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1729 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1730 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1731 */
} /* line 1731 */
  sim_icache_fetch(1074 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1733 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1734 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1735 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1736 */
  sim_icache_fetch(1078 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1738 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1739 */
  sim_icache_fetch(1080 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1741 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1742 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1743 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1744 */
} /* line 1744 */
  sim_icache_fetch(1085 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1746 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1747 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1748 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1749 */
  sim_icache_fetch(1089 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1751 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1752 */
  sim_icache_fetch(1091 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1754 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1755 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1756 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(1096 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1759 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1760 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1761 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1762 */
  sim_icache_fetch(1100 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1764 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1765 */
  sim_icache_fetch(1102 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1767 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1768 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1769 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1770 */
} /* line 1770 */
  sim_icache_fetch(1107 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1772 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1773 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1774 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1775 */
  sim_icache_fetch(1111 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1777 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1778 */
  sim_icache_fetch(1113 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1780 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1781 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1782 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1783 */
} /* line 1783 */
  sim_icache_fetch(1118 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1785 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1786 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1787 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1788 */
  sim_icache_fetch(1122 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1790 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1791 */
  sim_icache_fetch(1124 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1793 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1794 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1795 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1796 */
} /* line 1796 */
  sim_icache_fetch(1129 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1798 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1799 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1800 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1801 */
  sim_icache_fetch(1133 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1803 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1804 */
  sim_icache_fetch(1135 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1806 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1807 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1808 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1809 */
} /* line 1809 */
  sim_icache_fetch(1140 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1811 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1812 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1813 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1814 */
  sim_icache_fetch(1144 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1816 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1817 */
  sim_icache_fetch(1146 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1819 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1820 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1821 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1822 */
} /* line 1822 */
  sim_icache_fetch(1151 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1824 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1825 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1826 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1827 */
  sim_icache_fetch(1155 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1829 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1830 */
  sim_icache_fetch(1157 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1832 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1833 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1834 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1835 */
} /* line 1835 */
  sim_icache_fetch(1162 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1837 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1838 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1839 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1840 */
  sim_icache_fetch(1166 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1842 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1843 */
  sim_icache_fetch(1168 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1845 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1846 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1847 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1848 */
} /* line 1848 */
  sim_icache_fetch(1173 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1850 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1851 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1852 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1853 */
  sim_icache_fetch(1177 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1855 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1856 */
  sim_icache_fetch(1179 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1858 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1859 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1860 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1861 */
} /* line 1861 */
  sim_icache_fetch(1184 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1863 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1864 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1865 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1866 */
  sim_icache_fetch(1188 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1868 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1869 */
  sim_icache_fetch(1190 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1871 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1872 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1873 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1874 */
} /* line 1874 */
  sim_icache_fetch(1195 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1876 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1877 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1878 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1879 */
  sim_icache_fetch(1199 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1881 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1882 */
  sim_icache_fetch(1201 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1884 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1885 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1886 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1887 */
} /* line 1887 */
  sim_icache_fetch(1206 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1889 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1890 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1891 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1892 */
  sim_icache_fetch(1210 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1894 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1895 */
  sim_icache_fetch(1212 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1897 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1898 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1899 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1900 */
} /* line 1900 */
  sim_icache_fetch(1217 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1902 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1903 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1904 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1905 */
  sim_icache_fetch(1221 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1907 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1908 */
  sim_icache_fetch(1223 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1910 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1911 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1912 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1913 */
} /* line 1913 */
  sim_icache_fetch(1228 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1915 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1916 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1917 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1918 */
  sim_icache_fetch(1232 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1920 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1921 */
  sim_icache_fetch(1234 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1923 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1924 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1925 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1926 */
} /* line 1926 */
  sim_icache_fetch(1239 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1928 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1929 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1930 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1931 */
  sim_icache_fetch(1243 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1933 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1934 */
  sim_icache_fetch(1245 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1936 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1937 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1938 */
} /* line 1938 */
  sim_icache_fetch(1249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1940 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1941 */
  sim_icache_fetch(1251 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1943 */
  sim_icache_fetch(1252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1945 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1946 */
} /* line 1946 */
  sim_icache_fetch(1254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1948 */
  sim_icache_fetch(1255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1951 */
  sim_icache_fetch(1256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 1953 */
l_L143X3: ;/* line 1956 */
__LABEL(l_L143X3);
  sim_icache_fetch(1257 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1957 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1958 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1959 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1961 */
} /* line 1961 */
  sim_icache_fetch(1261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 1963 */
l_L142X3: ;/* line 1967 */
__LABEL(l_L142X3);
  sim_icache_fetch(1262 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 1968 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1969 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 1970 */
l_L141X3: ;/* line 1973 */
__LABEL(l_L141X3);
  sim_icache_fetch(1265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 1974 */
} /* line 1974 */
l_L109X3: ;/* line 1977 */
__LABEL(l_L109X3);
  sim_icache_fetch(1266 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 1978 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1979 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1980 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1981 */
} /* line 1981 */
  sim_icache_fetch(1270 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1983 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 1984 */
l_L140X3: ;/* line 1987 */
__LABEL(l_L140X3);
  sim_icache_fetch(1272 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 1988 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1989 */
   __GOTO(l_L145X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L145X3;
} /* line 1990 */
l_L139X3: ;/* line 1993 */
__LABEL(l_L139X3);
  sim_icache_fetch(1275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 1994 */
} /* line 1994 */
l_L107X3: ;/* line 1997 */
__LABEL(l_L107X3);
  sim_icache_fetch(1276 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 1998 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1999 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2000 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2001 */
} /* line 2001 */
  sim_icache_fetch(1280 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2003 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2004 */
l_L138X3: ;/* line 2007 */
__LABEL(l_L138X3);
  sim_icache_fetch(1282 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2008 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2009 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2010 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2011 */
l_L137X3: ;/* line 2014 */
__LABEL(l_L137X3);
  sim_icache_fetch(1286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2015 */
} /* line 2015 */
l_L105X3: ;/* line 2018 */
__LABEL(l_L105X3);
  sim_icache_fetch(1287 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2019 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2020 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2021 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2022 */
} /* line 2022 */
  sim_icache_fetch(1291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2024 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2025 */
l_L136X3: ;/* line 2028 */
__LABEL(l_L136X3);
  sim_icache_fetch(1293 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2029 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2030 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2031 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2032 */
l_L135X3: ;/* line 2035 */
__LABEL(l_L135X3);
  sim_icache_fetch(1297 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2036 */
} /* line 2036 */
l_L103X3: ;/* line 2039 */
__LABEL(l_L103X3);
  sim_icache_fetch(1298 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2040 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2041 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2042 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2043 */
} /* line 2043 */
  sim_icache_fetch(1302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2045 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2046 */
l_L134X3: ;/* line 2049 */
__LABEL(l_L134X3);
  sim_icache_fetch(1304 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2050 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2051 */
   __GOTO(l_L146X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L146X3;
} /* line 2052 */
l_L133X3: ;/* line 2055 */
__LABEL(l_L133X3);
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2056 */
} /* line 2056 */
l_L101X3: ;/* line 2059 */
__LABEL(l_L101X3);
  sim_icache_fetch(1308 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2060 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2061 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2062 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2063 */
} /* line 2063 */
  sim_icache_fetch(1312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2065 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2066 */
l_L132X3: ;/* line 2069 */
__LABEL(l_L132X3);
  sim_icache_fetch(1314 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2070 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2071 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2072 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2073 */
l_L131X3: ;/* line 2076 */
__LABEL(l_L131X3);
  sim_icache_fetch(1318 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2077 */
} /* line 2077 */
l_L99X3: ;/* line 2080 */
__LABEL(l_L99X3);
  sim_icache_fetch(1319 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2081 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2082 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2083 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2084 */
} /* line 2084 */
  sim_icache_fetch(1323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2086 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2087 */
l_L130X3: ;/* line 2090 */
__LABEL(l_L130X3);
  sim_icache_fetch(1325 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2091 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2092 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2093 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2094 */
l_L129X3: ;/* line 2097 */
__LABEL(l_L129X3);
  sim_icache_fetch(1329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2098 */
} /* line 2098 */
l_L97X3: ;/* line 2101 */
__LABEL(l_L97X3);
  sim_icache_fetch(1330 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2102 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2103 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2104 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2105 */
} /* line 2105 */
  sim_icache_fetch(1334 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2107 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2108 */
l_L128X3: ;/* line 2111 */
__LABEL(l_L128X3);
  sim_icache_fetch(1336 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2112 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2113 */
   __GOTO(l_L147X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L147X3;
} /* line 2114 */
l_L127X3: ;/* line 2117 */
__LABEL(l_L127X3);
  sim_icache_fetch(1339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2118 */
} /* line 2118 */
l_L95X3: ;/* line 2121 */
__LABEL(l_L95X3);
  sim_icache_fetch(1340 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2122 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2123 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2124 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2125 */
} /* line 2125 */
  sim_icache_fetch(1344 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2127 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2128 */
l_L126X3: ;/* line 2131 */
__LABEL(l_L126X3);
  sim_icache_fetch(1346 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2132 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2133 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2134 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2135 */
l_L125X3: ;/* line 2138 */
__LABEL(l_L125X3);
  sim_icache_fetch(1350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2139 */
} /* line 2139 */
l_L93X3: ;/* line 2142 */
__LABEL(l_L93X3);
  sim_icache_fetch(1351 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2143 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2144 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2145 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2146 */
} /* line 2146 */
  sim_icache_fetch(1355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2148 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2149 */
l_L124X3: ;/* line 2152 */
__LABEL(l_L124X3);
  sim_icache_fetch(1357 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2153 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2154 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2155 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2156 */
l_L123X3: ;/* line 2159 */
__LABEL(l_L123X3);
  sim_icache_fetch(1361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2160 */
} /* line 2160 */
l_L91X3: ;/* line 2163 */
__LABEL(l_L91X3);
  sim_icache_fetch(1362 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2164 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2165 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2166 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2167 */
} /* line 2167 */
  sim_icache_fetch(1366 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2169 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2170 */
l_L122X3: ;/* line 2173 */
__LABEL(l_L122X3);
  sim_icache_fetch(1368 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2174 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2175 */
   __GOTO(l_L148X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L148X3;
} /* line 2176 */
l_L121X3: ;/* line 2179 */
__LABEL(l_L121X3);
  sim_icache_fetch(1371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2180 */
} /* line 2180 */
l_L89X3: ;/* line 2183 */
__LABEL(l_L89X3);
  sim_icache_fetch(1372 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2184 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2185 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2186 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2187 */
} /* line 2187 */
  sim_icache_fetch(1376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2189 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2190 */
l_L120X3: ;/* line 2193 */
__LABEL(l_L120X3);
  sim_icache_fetch(1378 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2194 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2195 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2196 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2197 */
l_L119X3: ;/* line 2200 */
__LABEL(l_L119X3);
  sim_icache_fetch(1382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2201 */
} /* line 2201 */
l_L87X3: ;/* line 2204 */
__LABEL(l_L87X3);
  sim_icache_fetch(1383 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2205 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2206 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2207 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2208 */
} /* line 2208 */
  sim_icache_fetch(1387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2210 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2211 */
l_L118X3: ;/* line 2214 */
__LABEL(l_L118X3);
  sim_icache_fetch(1389 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2215 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2216 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2217 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2218 */
l_L117X3: ;/* line 2221 */
__LABEL(l_L117X3);
  sim_icache_fetch(1393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2222 */
} /* line 2222 */
l_L85X3: ;/* line 2225 */
__LABEL(l_L85X3);
  sim_icache_fetch(1394 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2226 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2227 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2228 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2229 */
} /* line 2229 */
  sim_icache_fetch(1398 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2231 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2232 */
l_L116X3: ;/* line 2235 */
__LABEL(l_L116X3);
  sim_icache_fetch(1400 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2236 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2237 */
   __GOTO(l_L149X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L149X3;
} /* line 2238 */
l_L115X3: ;/* line 2241 */
__LABEL(l_L115X3);
  sim_icache_fetch(1403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2242 */
} /* line 2242 */
l_L83X3: ;/* line 2245 */
__LABEL(l_L83X3);
  sim_icache_fetch(1404 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2246 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2247 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2248 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2249 */
} /* line 2249 */
  sim_icache_fetch(1408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2251 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2252 */
l_L114X3: ;/* line 2255 */
__LABEL(l_L114X3);
  sim_icache_fetch(1410 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2256 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2257 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2258 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2259 */
l_L113X3: ;/* line 2262 */
__LABEL(l_L113X3);
  sim_icache_fetch(1414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2263 */
} /* line 2263 */
l_L81X3: ;/* line 2267 */
__LABEL(l_L81X3);
  sim_icache_fetch(1415 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2268 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2269 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2270 */
} /* line 2270 */
  sim_icache_fetch(1418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2272 */
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2273 */
l_L112X3: ;/* line 2276 */
__LABEL(l_L112X3);
  sim_icache_fetch(1420 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2277 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2278 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2279 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2280 */
l_L111X3: ;/* line 2283 */
__LABEL(l_L111X3);
  sim_icache_fetch(1424 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2284 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2285 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2286 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2288 */
} /* line 2288 */
  sim_icache_fetch(1428 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L76X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L76X3;
} /* line 2290 */
l_L110X3: ;/* line 2294 */
__LABEL(l_L110X3);
  sim_icache_fetch(1429 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2295 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2296 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2297 */
l_L108X3: ;/* line 2300 */
__LABEL(l_L108X3);
  sim_icache_fetch(1432 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2301 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2302 */
} /* line 2302 */
l_L145X3: ;/* line 2304 */
__LABEL(l_L145X3);
  sim_icache_fetch(1434 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2305 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2306 */
l_L106X3: ;/* line 2309 */
__LABEL(l_L106X3);
  sim_icache_fetch(1436 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2310 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2311 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2312 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2313 */
l_L104X3: ;/* line 2316 */
__LABEL(l_L104X3);
  sim_icache_fetch(1440 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2317 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2318 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2319 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2320 */
l_L102X3: ;/* line 2323 */
__LABEL(l_L102X3);
  sim_icache_fetch(1444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2324 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2325 */
} /* line 2325 */
l_L146X3: ;/* line 2327 */
__LABEL(l_L146X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2328 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2329 */
l_L100X3: ;/* line 2332 */
__LABEL(l_L100X3);
  sim_icache_fetch(1448 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2333 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2334 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2335 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2336 */
l_L98X3: ;/* line 2339 */
__LABEL(l_L98X3);
  sim_icache_fetch(1452 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2340 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2341 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2342 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2343 */
l_L96X3: ;/* line 2346 */
__LABEL(l_L96X3);
  sim_icache_fetch(1456 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2347 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2348 */
} /* line 2348 */
l_L147X3: ;/* line 2350 */
__LABEL(l_L147X3);
  sim_icache_fetch(1458 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2351 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2352 */
l_L94X3: ;/* line 2355 */
__LABEL(l_L94X3);
  sim_icache_fetch(1460 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2356 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2357 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2358 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2359 */
l_L92X3: ;/* line 2362 */
__LABEL(l_L92X3);
  sim_icache_fetch(1464 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2363 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2364 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2365 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2366 */
l_L90X3: ;/* line 2369 */
__LABEL(l_L90X3);
  sim_icache_fetch(1468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2370 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2371 */
} /* line 2371 */
l_L148X3: ;/* line 2373 */
__LABEL(l_L148X3);
  sim_icache_fetch(1470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2374 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2375 */
l_L88X3: ;/* line 2378 */
__LABEL(l_L88X3);
  sim_icache_fetch(1472 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2379 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2380 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2381 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2382 */
l_L86X3: ;/* line 2385 */
__LABEL(l_L86X3);
  sim_icache_fetch(1476 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2386 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2387 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2388 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2389 */
l_L84X3: ;/* line 2392 */
__LABEL(l_L84X3);
  sim_icache_fetch(1480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2393 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2394 */
} /* line 2394 */
l_L149X3: ;/* line 2396 */
__LABEL(l_L149X3);
  sim_icache_fetch(1482 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2397 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2398 */
l_L82X3: ;/* line 2401 */
__LABEL(l_L82X3);
  sim_icache_fetch(1484 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2402 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2403 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2404 */
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2405 */
l_L80X3: ;/* line 2409 */
__LABEL(l_L80X3);
  sim_icache_fetch(1488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2410 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2411 */
} /* line 2411 */
l_L144X3: ;/* line 2413 */
__LABEL(l_L144X3);
  sim_icache_fetch(1490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2414 */
} /* line 2414 */
  sim_icache_fetch(1492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2416 */
} /* line 2416 */
  sim_icache_fetch(1493 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L70X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L70X3;
} /* line 2418 */
l_L73X3: ;/* line 2421 */
__LABEL(l_L73X3);
		 /* line 2421 */
  sim_icache_fetch(1494 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2424 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (318 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2424 */
l_lr_187: ;/* line 2424 */
__LABEL(l_lr_187);
  sim_icache_fetch(1497 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2426 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2427 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2428 */
   __ADD_CYCLES(1);
} /* line 2428 */
  sim_icache_fetch(1501 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2430 */
} /* line 2430 */
		 /* line 2431 */
  sim_icache_fetch(1502 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2433 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (318 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2434 */
l_lr_189: ;/* line 2434 */
__LABEL(l_lr_189);
  sim_icache_fetch(1506 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2436 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2437 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2438 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2439 */
} /* line 2439 */
  sim_icache_fetch(1514 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2441 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2442 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2443 */
} /* line 2443 */
  sim_icache_fetch(1517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2445 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2446 */
} /* line 2446 */
  sim_icache_fetch(1519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2448 */
l_L151X3: ;/* line 2450 */
__LABEL(l_L151X3);
  sim_icache_fetch(1520 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2451 */
  sim_icache_fetch(1521 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2453 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2454 */
} /* line 2454 */
l_L153X3: ;/* line 2456 */
__LABEL(l_L153X3);
  sim_icache_fetch(1524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2458 */
l_L152X3: ;/* line 2461 */
__LABEL(l_L152X3);
  sim_icache_fetch(1525 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2462 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2463 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2464 */
l_L150X3: ;/* line 2467 */
__LABEL(l_L150X3);
  sim_icache_fetch(1528 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2468 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2469 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2470 */
   __ADD_CYCLES(1);
} /* line 2470 */
		 /* line 2471 */
  sim_icache_fetch(1533 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2473 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (318 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2474 */
l_lr_195: ;/* line 2474 */
__LABEL(l_lr_195);
  sim_icache_fetch(1536 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2476 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2477 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2478 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2479 */
} /* line 2479 */
  sim_icache_fetch(1542 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 2481 */
} /* line 2481 */
  sim_icache_fetch(1543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2483 */
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2484 */
l_L71X3: ;/* line 2487 */
__LABEL(l_L71X3);
  sim_icache_fetch(1545 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2488 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2489 */
l_L67X3: ;/* line 2492 */
__LABEL(l_L67X3);
  sim_icache_fetch(1547 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2493 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2494 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2495 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2496 */
} /* line 2496 */
  sim_icache_fetch(1552 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2498 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2499 */
l_L66X3: ;/* line 2502 */
__LABEL(l_L66X3);
  sim_icache_fetch(1554 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2503 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2504 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2505 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2506 */
} /* line 2506 */
  sim_icache_fetch(1559 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2508 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2509 */
l_L65X3: ;/* line 2512 */
__LABEL(l_L65X3);
  sim_icache_fetch(1561 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2513 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2514 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2515 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2516 */
} /* line 2516 */
  sim_icache_fetch(1566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2518 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2519 */
l_L64X3: ;/* line 2522 */
__LABEL(l_L64X3);
  sim_icache_fetch(1568 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2523 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2524 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2525 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2526 */
} /* line 2526 */
  sim_icache_fetch(1573 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2528 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2529 */
l_L63X3: ;/* line 2532 */
__LABEL(l_L63X3);
  sim_icache_fetch(1575 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2533 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2534 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2535 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2536 */
} /* line 2536 */
  sim_icache_fetch(1580 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2538 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2539 */
l_L62X3: ;/* line 2542 */
__LABEL(l_L62X3);
  sim_icache_fetch(1582 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2543 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2544 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2545 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2546 */
} /* line 2546 */
  sim_icache_fetch(1587 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2548 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2549 */
l_L61X3: ;/* line 2552 */
__LABEL(l_L61X3);
  sim_icache_fetch(1589 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2553 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2554 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2555 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2556 */
} /* line 2556 */
  sim_icache_fetch(1594 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2558 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2559 */
l_L60X3: ;/* line 2562 */
__LABEL(l_L60X3);
  sim_icache_fetch(1596 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2563 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2564 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2565 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2566 */
} /* line 2566 */
  sim_icache_fetch(1601 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2568 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2569 */
l_L59X3: ;/* line 2572 */
__LABEL(l_L59X3);
  sim_icache_fetch(1603 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2573 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2574 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2575 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2576 */
} /* line 2576 */
  sim_icache_fetch(1608 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2578 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2579 */
l_L58X3: ;/* line 2582 */
__LABEL(l_L58X3);
  sim_icache_fetch(1610 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2583 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2584 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2585 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2586 */
} /* line 2586 */
  sim_icache_fetch(1615 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2588 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2589 */
l_L57X3: ;/* line 2592 */
__LABEL(l_L57X3);
  sim_icache_fetch(1617 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2593 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2594 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2595 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2596 */
} /* line 2596 */
  sim_icache_fetch(1622 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2598 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2599 */
l_L56X3: ;/* line 2602 */
__LABEL(l_L56X3);
  sim_icache_fetch(1624 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2603 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2604 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2605 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2606 */
} /* line 2606 */
  sim_icache_fetch(1629 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2608 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2609 */
l_L55X3: ;/* line 2612 */
__LABEL(l_L55X3);
  sim_icache_fetch(1631 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2613 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2614 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2615 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2616 */
} /* line 2616 */
  sim_icache_fetch(1636 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2618 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2619 */
l_L54X3: ;/* line 2622 */
__LABEL(l_L54X3);
  sim_icache_fetch(1638 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2623 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2624 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2625 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2626 */
} /* line 2626 */
  sim_icache_fetch(1643 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2628 */
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2629 */
l_L53X3: ;/* line 2632 */
__LABEL(l_L53X3);
  sim_icache_fetch(1645 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2633 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2634 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2635 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2636 */
} /* line 2636 */
  sim_icache_fetch(1650 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 2638 */
l_L69X3: ;/* line 2640 */
__LABEL(l_L69X3);
  sim_icache_fetch(1651 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2641 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2642 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2643 */
} /* line 2643 */
		 /* line 2644 */
  sim_icache_fetch(1654 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2647 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (318 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2647 */
l_lr_214: ;/* line 2647 */
__LABEL(l_lr_214);
  sim_icache_fetch(1657 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2649 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2650 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2651 */
} /* line 2651 */
  sim_icache_fetch(1660 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L70X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L70X3;
} /* line 2653 */
l_L50X3: ;/* line 2656 */
__LABEL(l_L50X3);
  sim_icache_fetch(1661 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 2657 */
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 2658 */
l_L48X3: ;/* line 2661 */
__LABEL(l_L48X3);
  sim_icache_fetch(1663 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_14, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2662 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2663 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2664 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2665 */
} /* line 2665 */
  sim_icache_fetch(1669 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2667 */
} /* line 2667 */
  sim_icache_fetch(1670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 2669 */
} /* line 2669 */
  sim_icache_fetch(1671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 2671 */
} /* line 2671 */
  sim_icache_fetch(1673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_14); /* line 2673 */
} /* line 2673 */
  sim_icache_fetch(1674 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2675 */
   __LDBU(reg_r0_3, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2676 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2677 */
   __ADD_CYCLES(1);
} /* line 2677 */
  sim_icache_fetch(1679 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 1); /* line 2679 */
} /* line 2679 */
  sim_icache_fetch(1680 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 2681 */
} /* line 2681 */
  sim_icache_fetch(1682 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2683 */
} /* line 2683 */
  sim_icache_fetch(1683 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2685 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2686 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2687 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2688 */
   __ADD_CYCLES(1);
} /* line 2688 */
  sim_icache_fetch(1690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_14, reg_r0_2, (unsigned int) 1); /* line 2690 */
   __OR(reg_r0_3, reg_r0_3, reg_r0_5); /* line 2691 */
} /* line 2691 */
  sim_icache_fetch(1692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_14); /* line 2693 */
} /* line 2693 */
  sim_icache_fetch(1694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2695 */
} /* line 2695 */
  sim_icache_fetch(1695 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2697 */
   __LDW(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2698 */
} /* line 2698 */
  sim_icache_fetch(1699 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2700 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2701 */
   __GOTO(l_L49X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L49X3;
} /* line 2702 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 200: goto l_L49X3;
    case 201: goto l_L51X3;
    case 202: goto l_L52X3;
    case 203: goto l_L68X3;
    case 204: goto l_L70X3;
    case 205: goto l_L72X3;
    case 206: goto l_L74X3;
    case 207: goto l_L76X3;
    case 209: goto l_lr_108;
    case 210: goto l_L77X3;
    case 212: goto l_lr_111;
    case 213: goto l_L78X3;
    case 214: goto l_L75X3;
    case 215: goto l_L79X3;
    case 216: goto l_L143X3;
    case 217: goto l_L142X3;
    case 218: goto l_L141X3;
    case 219: goto l_L109X3;
    case 220: goto l_L140X3;
    case 221: goto l_L139X3;
    case 222: goto l_L107X3;
    case 223: goto l_L138X3;
    case 224: goto l_L137X3;
    case 225: goto l_L105X3;
    case 226: goto l_L136X3;
    case 227: goto l_L135X3;
    case 228: goto l_L103X3;
    case 229: goto l_L134X3;
    case 230: goto l_L133X3;
    case 231: goto l_L101X3;
    case 232: goto l_L132X3;
    case 233: goto l_L131X3;
    case 234: goto l_L99X3;
    case 235: goto l_L130X3;
    case 236: goto l_L129X3;
    case 237: goto l_L97X3;
    case 238: goto l_L128X3;
    case 239: goto l_L127X3;
    case 240: goto l_L95X3;
    case 241: goto l_L126X3;
    case 242: goto l_L125X3;
    case 243: goto l_L93X3;
    case 244: goto l_L124X3;
    case 245: goto l_L123X3;
    case 246: goto l_L91X3;
    case 247: goto l_L122X3;
    case 248: goto l_L121X3;
    case 249: goto l_L89X3;
    case 250: goto l_L120X3;
    case 251: goto l_L119X3;
    case 252: goto l_L87X3;
    case 253: goto l_L118X3;
    case 254: goto l_L117X3;
    case 255: goto l_L85X3;
    case 256: goto l_L116X3;
    case 257: goto l_L115X3;
    case 258: goto l_L83X3;
    case 259: goto l_L114X3;
    case 260: goto l_L113X3;
    case 261: goto l_L81X3;
    case 262: goto l_L112X3;
    case 263: goto l_L111X3;
    case 264: goto l_L110X3;
    case 265: goto l_L108X3;
    case 266: goto l_L145X3;
    case 267: goto l_L106X3;
    case 268: goto l_L104X3;
    case 269: goto l_L102X3;
    case 270: goto l_L146X3;
    case 271: goto l_L100X3;
    case 272: goto l_L98X3;
    case 273: goto l_L96X3;
    case 274: goto l_L147X3;
    case 275: goto l_L94X3;
    case 276: goto l_L92X3;
    case 277: goto l_L90X3;
    case 278: goto l_L148X3;
    case 279: goto l_L88X3;
    case 280: goto l_L86X3;
    case 281: goto l_L84X3;
    case 282: goto l_L149X3;
    case 283: goto l_L82X3;
    case 284: goto l_L80X3;
    case 285: goto l_L144X3;
    case 286: goto l_L73X3;
    case 288: goto l_lr_187;
    case 290: goto l_lr_189;
    case 291: goto l_L151X3;
    case 292: goto l_L153X3;
    case 293: goto l_L152X3;
    case 294: goto l_L150X3;
    case 296: goto l_lr_195;
    case 297: goto l_L71X3;
    case 298: goto l_L67X3;
    case 299: goto l_L66X3;
    case 300: goto l_L65X3;
    case 301: goto l_L64X3;
    case 302: goto l_L63X3;
    case 303: goto l_L62X3;
    case 304: goto l_L61X3;
    case 305: goto l_L60X3;
    case 306: goto l_L59X3;
    case 307: goto l_L58X3;
    case 308: goto l_L57X3;
    case 309: goto l_L56X3;
    case 310: goto l_L55X3;
    case 311: goto l_L54X3;
    case 312: goto l_L53X3;
    case 313: goto l_L69X3;
    case 315: goto l_lr_214;
    case 316: goto l_L50X3;
    case 317: goto l_L48X3;
    case 318:
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
  reg_l0_0 = (350 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1704 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 2721 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2722 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2723 */
} /* line 2723 */
  sim_icache_fetch(1709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L154X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2725 */
  sim_icache_fetch(1710 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2727 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2728 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2729 */
} /* line 2729 */
  sim_icache_fetch(1713 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_9680Xbuf),0,1)); /* line 2731 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2732 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2733 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2734 */
} /* line 2734 */
  sim_icache_fetch(1720 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_9680Xbuf); /* line 2736 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_9680Xbuf + (unsigned int) 1)); /* line 2737 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2738 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2739 */
} /* line 2739 */
  sim_icache_fetch(1726 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2741 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2742 */
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2743 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2744 */
} /* line 2744 */
  sim_icache_fetch(1730 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2746 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2747 */
} /* line 2747 */
  sim_icache_fetch(1732 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_9680Xbuf),0,1), reg_r0_2); /* line 2749 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L155X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2750 */
  sim_icache_fetch(1735 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2752 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2753 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2754 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2755 */
} /* line 2755 */
l_L155X3: ;/* line 2757 */
__LABEL(l_L155X3);
  sim_icache_fetch(1739 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2758 */
   __MOV(reg_r0_3, (unsigned int) compress_9680Xbuf); /* line 2759 */
} /* line 2759 */
  sim_icache_fetch(1742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L156X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2761 */
  sim_icache_fetch(1743 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2763 */
} /* line 2763 */
l_L156X3: ;/* line 2765 */
__LABEL(l_L156X3);
  sim_icache_fetch(1744 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 2766 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2767 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2768 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2769 */
   __ADD_CYCLES(1);
} /* line 2769 */
  sim_icache_fetch(1751 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2771 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2772 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2773 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2774 */
} /* line 2774 */
  sim_icache_fetch(1755 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_9680Xoffset,0,4), reg_r0_2); /* line 2776 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2777 */
} /* line 2777 */
  sim_icache_fetch(1758 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L157X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2779 */
  sim_icache_fetch(1759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2781 */
} /* line 2781 */
l_L158X3: ;/* line 2784 */
__LABEL(l_L158X3);
  sim_icache_fetch(1761 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2785 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2786 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2787 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2788 */
} /* line 2788 */
  sim_icache_fetch(1766 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2790 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2791 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2792 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2793 */
} /* line 2793 */
  sim_icache_fetch(1770 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2795 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2796 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2797 */
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) 16); /* line 2798 */
} /* line 2798 */
  sim_icache_fetch(1774 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2800 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -16); /* line 2801 */
} /* line 2801 */
  sim_icache_fetch(1777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2803 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2804 */
  sim_icache_fetch(1779 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2806 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2807 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2808 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2809 */
   __ADD_CYCLES(1);
} /* line 2809 */
  sim_icache_fetch(1784 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2811 */
} /* line 2811 */
  sim_icache_fetch(1785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2813 */
} /* line 2813 */
  sim_icache_fetch(1787 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2815 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2816 */
  sim_icache_fetch(1789 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2818 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2819 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2820 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2821 */
   __ADD_CYCLES(1);
} /* line 2821 */
  sim_icache_fetch(1794 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2823 */
} /* line 2823 */
  sim_icache_fetch(1795 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2825 */
} /* line 2825 */
  sim_icache_fetch(1797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2827 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2828 */
  sim_icache_fetch(1799 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2830 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2831 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2832 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2833 */
   __ADD_CYCLES(1);
} /* line 2833 */
  sim_icache_fetch(1804 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2835 */
} /* line 2835 */
  sim_icache_fetch(1805 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2837 */
} /* line 2837 */
  sim_icache_fetch(1807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2839 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2840 */
  sim_icache_fetch(1809 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2842 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2843 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2844 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2845 */
   __ADD_CYCLES(1);
} /* line 2845 */
  sim_icache_fetch(1814 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2847 */
} /* line 2847 */
  sim_icache_fetch(1815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2849 */
} /* line 2849 */
  sim_icache_fetch(1817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2851 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2852 */
  sim_icache_fetch(1819 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2854 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2855 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2856 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2857 */
   __ADD_CYCLES(1);
} /* line 2857 */
  sim_icache_fetch(1824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2859 */
} /* line 2859 */
  sim_icache_fetch(1825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2861 */
} /* line 2861 */
  sim_icache_fetch(1827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2863 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2864 */
  sim_icache_fetch(1829 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2866 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2867 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2868 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2869 */
   __ADD_CYCLES(1);
} /* line 2869 */
  sim_icache_fetch(1834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2871 */
} /* line 2871 */
  sim_icache_fetch(1835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2873 */
} /* line 2873 */
  sim_icache_fetch(1837 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2875 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2876 */
  sim_icache_fetch(1839 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2878 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2879 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2880 */
   __ADD(reg_r0_5, reg_r0_8, (unsigned int) -16); /* line 2881 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2882 */
   __ADD_CYCLES(1);
} /* line 2882 */
  sim_icache_fetch(1845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2884 */
} /* line 2884 */
  sim_icache_fetch(1846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2886 */
} /* line 2886 */
  sim_icache_fetch(1848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2888 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2889 */
  sim_icache_fetch(1850 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2891 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2892 */
   __CMPEQ(reg_b0_7, reg_r0_8, 0); /* line 2893 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2894 */
   __ADD_CYCLES(1);
} /* line 2894 */
  sim_icache_fetch(1855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2896 */
} /* line 2896 */
  sim_icache_fetch(1856 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2898 */
} /* line 2898 */
  sim_icache_fetch(1858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2900 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2901 */
  sim_icache_fetch(1860 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2903 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2904 */
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 2905 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2906 */
   __ADD_CYCLES(1);
} /* line 2906 */
  sim_icache_fetch(1865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2908 */
} /* line 2908 */
  sim_icache_fetch(1866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2910 */
} /* line 2910 */
  sim_icache_fetch(1868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2912 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2913 */
  sim_icache_fetch(1870 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 2915 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2916 */
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 2); /* line 2917 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2918 */
   __ADD_CYCLES(1);
} /* line 2918 */
  sim_icache_fetch(1875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2920 */
} /* line 2920 */
  sim_icache_fetch(1876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2922 */
} /* line 2922 */
  sim_icache_fetch(1878 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2924 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2925 */
  sim_icache_fetch(1880 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 2927 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2928 */
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 3); /* line 2929 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2930 */
   __ADD_CYCLES(1);
} /* line 2930 */
  sim_icache_fetch(1885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2932 */
} /* line 2932 */
  sim_icache_fetch(1886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2934 */
} /* line 2934 */
  sim_icache_fetch(1888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2936 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2937 */
  sim_icache_fetch(1890 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 2939 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2940 */
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 4); /* line 2941 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2942 */
   __ADD_CYCLES(1);
} /* line 2942 */
  sim_icache_fetch(1895 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2944 */
} /* line 2944 */
  sim_icache_fetch(1896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2946 */
} /* line 2946 */
  sim_icache_fetch(1898 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2948 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2949 */
  sim_icache_fetch(1900 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 2951 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2952 */
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 5); /* line 2953 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2954 */
   __ADD_CYCLES(1);
} /* line 2954 */
  sim_icache_fetch(1905 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2956 */
} /* line 2956 */
  sim_icache_fetch(1906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2958 */
} /* line 2958 */
  sim_icache_fetch(1908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2960 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2961 */
  sim_icache_fetch(1910 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 2963 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2964 */
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 6); /* line 2965 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2966 */
   __ADD_CYCLES(1);
} /* line 2966 */
  sim_icache_fetch(1915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2968 */
} /* line 2968 */
  sim_icache_fetch(1916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2970 */
} /* line 2970 */
  sim_icache_fetch(1918 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2972 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2973 */
  sim_icache_fetch(1920 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 2975 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2976 */
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 7); /* line 2977 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2978 */
   __ADD_CYCLES(1);
} /* line 2978 */
  sim_icache_fetch(1925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 2980 */
} /* line 2980 */
  sim_icache_fetch(1926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 2982 */
} /* line 2982 */
  sim_icache_fetch(1928 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2984 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 2985 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2986 */
  sim_icache_fetch(1931 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_7,0,1)); /* line 2988 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2989 */
   __CMPEQ(reg_b0_7, reg_r0_8, (unsigned int) 8); /* line 2990 */
   __MFB(reg_r0_6, t__i32_0); /* line 2991 */
} /* line 2991 */
  sim_icache_fetch(1936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) 16); /* line 2993 */
} /* line 2993 */
  sim_icache_fetch(1937 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 2995 */
} /* line 2995 */
  sim_icache_fetch(1938 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 2997 */
} /* line 2997 */
  sim_icache_fetch(1940 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2999 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3000 */
  sim_icache_fetch(1942 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 1),0,1)); /* line 3002 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3003 */
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 9); /* line 3004 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3005 */
   __ADD_CYCLES(1);
} /* line 3005 */
  sim_icache_fetch(1947 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3007 */
} /* line 3007 */
  sim_icache_fetch(1948 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3009 */
} /* line 3009 */
  sim_icache_fetch(1950 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3011 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3012 */
  sim_icache_fetch(1952 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,1)); /* line 3014 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3015 */
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 10); /* line 3016 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3017 */
   __ADD_CYCLES(1);
} /* line 3017 */
  sim_icache_fetch(1957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3019 */
} /* line 3019 */
  sim_icache_fetch(1958 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3021 */
} /* line 3021 */
  sim_icache_fetch(1960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3023 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3024 */
  sim_icache_fetch(1962 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 3),0,1)); /* line 3026 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3027 */
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 11); /* line 3028 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3029 */
   __ADD_CYCLES(1);
} /* line 3029 */
  sim_icache_fetch(1967 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3031 */
} /* line 3031 */
  sim_icache_fetch(1968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3033 */
} /* line 3033 */
  sim_icache_fetch(1970 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3035 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3036 */
  sim_icache_fetch(1972 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,1)); /* line 3038 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3039 */
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 12); /* line 3040 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3041 */
   __ADD_CYCLES(1);
} /* line 3041 */
  sim_icache_fetch(1977 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3043 */
} /* line 3043 */
  sim_icache_fetch(1978 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3045 */
} /* line 3045 */
  sim_icache_fetch(1980 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3047 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3048 */
  sim_icache_fetch(1982 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 5),0,1)); /* line 3050 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3051 */
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 13); /* line 3052 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3053 */
   __ADD_CYCLES(1);
} /* line 3053 */
  sim_icache_fetch(1987 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3055 */
} /* line 3055 */
  sim_icache_fetch(1988 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3057 */
} /* line 3057 */
  sim_icache_fetch(1990 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3059 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3060 */
  sim_icache_fetch(1992 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 6),0,1)); /* line 3062 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3063 */
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 14); /* line 3064 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3065 */
   __ADD_CYCLES(1);
} /* line 3065 */
  sim_icache_fetch(1997 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3067 */
} /* line 3067 */
  sim_icache_fetch(1998 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3069 */
} /* line 3069 */
  sim_icache_fetch(2000 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3071 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3072 */
  sim_icache_fetch(2002 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 7),0,1)); /* line 3074 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3075 */
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 15); /* line 3076 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3077 */
   __ADD_CYCLES(1);
} /* line 3077 */
  sim_icache_fetch(2007 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3079 */
} /* line 3079 */
  sim_icache_fetch(2008 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3081 */
} /* line 3081 */
  sim_icache_fetch(2010 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3083 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3084 */
  sim_icache_fetch(2012 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 8),0,1)); /* line 3086 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3087 */
   __MTB(reg_b0_7, reg_r0_6); /* line 3088 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3089 */
   __ADD_CYCLES(1);
} /* line 3089 */
  sim_icache_fetch(2017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3091 */
} /* line 3091 */
  sim_icache_fetch(2018 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3093 */
} /* line 3093 */
  sim_icache_fetch(2020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3095 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3096 */
  sim_icache_fetch(2022 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 9),0,1)); /* line 3098 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3099 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3100 */
   __ADD_CYCLES(1);
} /* line 3100 */
  sim_icache_fetch(2026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3102 */
} /* line 3102 */
  sim_icache_fetch(2027 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3104 */
} /* line 3104 */
  sim_icache_fetch(2029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3106 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3107 */
  sim_icache_fetch(2031 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 10),0,1)); /* line 3109 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3110 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3111 */
   __ADD_CYCLES(1);
} /* line 3111 */
  sim_icache_fetch(2035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3113 */
} /* line 3113 */
  sim_icache_fetch(2036 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3115 */
} /* line 3115 */
  sim_icache_fetch(2038 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3117 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3118 */
  sim_icache_fetch(2040 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 11),0,1)); /* line 3120 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3121 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3122 */
   __ADD_CYCLES(1);
} /* line 3122 */
  sim_icache_fetch(2044 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3124 */
} /* line 3124 */
  sim_icache_fetch(2045 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3126 */
} /* line 3126 */
  sim_icache_fetch(2047 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3128 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3129 */
  sim_icache_fetch(2049 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,1)); /* line 3131 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3132 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3133 */
   __ADD_CYCLES(1);
} /* line 3133 */
  sim_icache_fetch(2053 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3135 */
} /* line 3135 */
  sim_icache_fetch(2054 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3137 */
} /* line 3137 */
  sim_icache_fetch(2056 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3139 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3140 */
  sim_icache_fetch(2058 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 13),0,1)); /* line 3142 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3143 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3144 */
   __ADD_CYCLES(1);
} /* line 3144 */
  sim_icache_fetch(2062 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3146 */
} /* line 3146 */
  sim_icache_fetch(2063 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3148 */
} /* line 3148 */
  sim_icache_fetch(2065 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3150 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3151 */
  sim_icache_fetch(2067 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 14),0,1)); /* line 3153 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3154 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3155 */
   __ADD_CYCLES(1);
} /* line 3155 */
  sim_icache_fetch(2071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3157 */
} /* line 3157 */
  sim_icache_fetch(2072 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3159 */
} /* line 3159 */
  sim_icache_fetch(2074 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3161 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3162 */
  sim_icache_fetch(2076 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_7, mem_trace_ld((reg_r0_7 + (unsigned int) 15),0,1)); /* line 3164 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3165 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3166 */
   __ADD_CYCLES(1);
} /* line 3166 */
  sim_icache_fetch(2080 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3168 */
} /* line 3168 */
  sim_icache_fetch(2081 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3170 */
} /* line 3170 */
  sim_icache_fetch(2083 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 3172 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3174 */
  sim_icache_fetch(2085 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 3176 */
l_L159X3: ;/* line 3179 */
__LABEL(l_L159X3);
  sim_icache_fetch(2086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_9680Xoffset,0,4), 0); /* line 3180 */
} /* line 3180 */
l_L157X3: ;/* line 3183 */
__LABEL(l_L157X3);
  sim_icache_fetch(2088 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3184 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3185 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3186 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3187 */
} /* line 3187 */
  sim_icache_fetch(2096 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3189 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3190 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3191 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3192 */
} /* line 3192 */
  sim_icache_fetch(2100 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3194 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3195 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3196 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3197 */
} /* line 3197 */
  sim_icache_fetch(2104 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3199 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3200 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3201 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3202 */
} /* line 3202 */
  sim_icache_fetch(2108 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3204 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3205 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3206 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L160X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3207 */
  sim_icache_fetch(2112 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3209 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3210 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3211 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L161X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3212 */
  sim_icache_fetch(2116 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3214 */
   __MOV(reg_r0_5, (unsigned int) compress_9680Xbuf); /* line 3215 */
   __MOV(reg_r0_3, 0); /* line 3216 */
} /* line 3216 */
l_L162X3: ;/* line 3219 */
__LABEL(l_L162X3);
  sim_icache_fetch(2120 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3220 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3221 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3222 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3223 */
} /* line 3223 */
  sim_icache_fetch(2126 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3225 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3226 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3227 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3228 */
} /* line 3228 */
  sim_icache_fetch(2130 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3230 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3231 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3232 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3233 */
} /* line 3233 */
  sim_icache_fetch(2134 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3235 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3236 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3237 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L163X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3238 */
  sim_icache_fetch(2138 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3240 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3241 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3242 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3243 */
} /* line 3243 */
  sim_icache_fetch(2142 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3245 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3246 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3247 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3248 */
} /* line 3248 */
  sim_icache_fetch(2147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3250 */
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 16); /* line 3251 */
} /* line 3251 */
  sim_icache_fetch(2149 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3253 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3254 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3255 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3256 */
   __ADD_CYCLES(1);
} /* line 3256 */
  sim_icache_fetch(2155 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_4); /* line 3258 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3259 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3260 */
} /* line 3260 */
  sim_icache_fetch(2158 + t_thisfile.offset, 1);
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
} /* line 3262 */
  sim_icache_fetch(2159 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3264 */
} /* line 3264 */
  sim_icache_fetch(2161 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3266 */
} /* line 3266 */
  sim_icache_fetch(2162 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3268 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3269 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3270 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3271 */
   __ADD_CYCLES(1);
} /* line 3271 */
  sim_icache_fetch(2168 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_4); /* line 3273 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3274 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3275 */
} /* line 3275 */
  sim_icache_fetch(2171 + t_thisfile.offset, 1);
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
} /* line 3277 */
  sim_icache_fetch(2172 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3279 */
} /* line 3279 */
  sim_icache_fetch(2174 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3281 */
} /* line 3281 */
  sim_icache_fetch(2175 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3283 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3284 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3285 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3286 */
   __ADD_CYCLES(1);
} /* line 3286 */
  sim_icache_fetch(2181 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_4); /* line 3288 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3289 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3290 */
} /* line 3290 */
  sim_icache_fetch(2184 + t_thisfile.offset, 1);
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
} /* line 3292 */
  sim_icache_fetch(2185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3294 */
} /* line 3294 */
  sim_icache_fetch(2187 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3296 */
} /* line 3296 */
  sim_icache_fetch(2188 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3298 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3299 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3300 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3301 */
   __ADD_CYCLES(1);
} /* line 3301 */
  sim_icache_fetch(2194 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_4); /* line 3303 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3304 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3305 */
} /* line 3305 */
  sim_icache_fetch(2197 + t_thisfile.offset, 1);
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
} /* line 3307 */
  sim_icache_fetch(2198 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3309 */
} /* line 3309 */
  sim_icache_fetch(2200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3311 */
} /* line 3311 */
  sim_icache_fetch(2201 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3313 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3314 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3315 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3316 */
   __ADD_CYCLES(1);
} /* line 3316 */
  sim_icache_fetch(2207 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_4); /* line 3318 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3319 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3320 */
} /* line 3320 */
  sim_icache_fetch(2210 + t_thisfile.offset, 1);
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
} /* line 3322 */
  sim_icache_fetch(2211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3324 */
} /* line 3324 */
  sim_icache_fetch(2213 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3326 */
} /* line 3326 */
  sim_icache_fetch(2214 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3328 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3329 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3330 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3331 */
   __ADD_CYCLES(1);
} /* line 3331 */
  sim_icache_fetch(2220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_4); /* line 3333 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3334 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3335 */
} /* line 3335 */
  sim_icache_fetch(2223 + t_thisfile.offset, 1);
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
} /* line 3337 */
  sim_icache_fetch(2224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3339 */
} /* line 3339 */
  sim_icache_fetch(2226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3341 */
} /* line 3341 */
  sim_icache_fetch(2227 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3343 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3344 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3345 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3346 */
   __ADD_CYCLES(1);
} /* line 3346 */
  sim_icache_fetch(2233 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_4); /* line 3348 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3349 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3350 */
} /* line 3350 */
  sim_icache_fetch(2236 + t_thisfile.offset, 1);
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
} /* line 3352 */
  sim_icache_fetch(2237 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3354 */
} /* line 3354 */
  sim_icache_fetch(2239 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3356 */
} /* line 3356 */
  sim_icache_fetch(2240 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3358 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3359 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3360 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3361 */
   __ADD_CYCLES(1);
} /* line 3361 */
  sim_icache_fetch(2246 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_4); /* line 3363 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3364 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3365 */
} /* line 3365 */
  sim_icache_fetch(2249 + t_thisfile.offset, 1);
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
} /* line 3367 */
  sim_icache_fetch(2250 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3369 */
} /* line 3369 */
  sim_icache_fetch(2252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3371 */
} /* line 3371 */
  sim_icache_fetch(2253 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3373 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3374 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3375 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3376 */
   __ADD_CYCLES(1);
} /* line 3376 */
  sim_icache_fetch(2259 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_4); /* line 3378 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3379 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3380 */
} /* line 3380 */
  sim_icache_fetch(2262 + t_thisfile.offset, 1);
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
} /* line 3382 */
  sim_icache_fetch(2263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3384 */
} /* line 3384 */
  sim_icache_fetch(2265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3386 */
} /* line 3386 */
  sim_icache_fetch(2266 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3388 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3389 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3390 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3391 */
   __ADD_CYCLES(1);
} /* line 3391 */
  sim_icache_fetch(2272 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_4); /* line 3393 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3394 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3395 */
} /* line 3395 */
  sim_icache_fetch(2275 + t_thisfile.offset, 1);
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
} /* line 3397 */
  sim_icache_fetch(2276 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3399 */
} /* line 3399 */
  sim_icache_fetch(2278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3401 */
} /* line 3401 */
  sim_icache_fetch(2279 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3403 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3404 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3405 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3406 */
   __ADD_CYCLES(1);
} /* line 3406 */
  sim_icache_fetch(2285 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_4); /* line 3408 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3409 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3410 */
} /* line 3410 */
  sim_icache_fetch(2288 + t_thisfile.offset, 1);
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
} /* line 3412 */
  sim_icache_fetch(2289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3414 */
} /* line 3414 */
  sim_icache_fetch(2291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3416 */
} /* line 3416 */
  sim_icache_fetch(2292 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3418 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3419 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3420 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3421 */
   __ADD_CYCLES(1);
} /* line 3421 */
  sim_icache_fetch(2298 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_4); /* line 3423 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3424 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3425 */
} /* line 3425 */
  sim_icache_fetch(2301 + t_thisfile.offset, 1);
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
} /* line 3427 */
  sim_icache_fetch(2302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3429 */
} /* line 3429 */
  sim_icache_fetch(2304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3431 */
} /* line 3431 */
  sim_icache_fetch(2305 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3433 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3434 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3435 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3436 */
   __ADD_CYCLES(1);
} /* line 3436 */
  sim_icache_fetch(2311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_4); /* line 3438 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3439 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3440 */
} /* line 3440 */
  sim_icache_fetch(2314 + t_thisfile.offset, 1);
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
} /* line 3442 */
  sim_icache_fetch(2315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3444 */
} /* line 3444 */
  sim_icache_fetch(2317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3446 */
} /* line 3446 */
  sim_icache_fetch(2318 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3448 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3449 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3450 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3451 */
   __ADD_CYCLES(1);
} /* line 3451 */
  sim_icache_fetch(2324 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_4); /* line 3453 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3454 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3455 */
} /* line 3455 */
  sim_icache_fetch(2327 + t_thisfile.offset, 1);
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
} /* line 3457 */
  sim_icache_fetch(2328 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3459 */
} /* line 3459 */
  sim_icache_fetch(2330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3461 */
} /* line 3461 */
  sim_icache_fetch(2331 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3463 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3464 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3465 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3466 */
   __ADD_CYCLES(1);
} /* line 3466 */
  sim_icache_fetch(2337 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_4); /* line 3468 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3469 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3470 */
} /* line 3470 */
  sim_icache_fetch(2340 + t_thisfile.offset, 1);
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
} /* line 3472 */
  sim_icache_fetch(2341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3474 */
} /* line 3474 */
  sim_icache_fetch(2343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_5); /* line 3476 */
} /* line 3476 */
  sim_icache_fetch(2344 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3478 */
   __LDBs(reg_r0_38, mem_trace_ld(reg_r0_37,0,1)); /* line 3479 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3480 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3481 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3482 */
   __ADD_CYCLES(1);
} /* line 3482 */
  sim_icache_fetch(2351 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 3484 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3485 */
   __MOV(reg_r0_3, reg_r0_2); /* line 3486 */
} /* line 3486 */
  sim_icache_fetch(2354 + t_thisfile.offset, 1);
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
} /* line 3488 */
  sim_icache_fetch(2355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3490 */
} /* line 3490 */
  sim_icache_fetch(2357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3492 */
} /* line 3492 */
  sim_icache_fetch(2358 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3494 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3495 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3496 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3497 */
   __ADD_CYCLES(1);
} /* line 3497 */
  sim_icache_fetch(2364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3499 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3500 */
} /* line 3500 */
  sim_icache_fetch(2366 + t_thisfile.offset, 1);
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
} /* line 3502 */
  sim_icache_fetch(2367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3504 */
} /* line 3504 */
  sim_icache_fetch(2369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3506 */
} /* line 3506 */
  sim_icache_fetch(2370 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3508 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3509 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3510 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3511 */
   __ADD_CYCLES(1);
} /* line 3511 */
  sim_icache_fetch(2376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3513 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3514 */
} /* line 3514 */
  sim_icache_fetch(2378 + t_thisfile.offset, 1);
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
} /* line 3516 */
  sim_icache_fetch(2379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3518 */
} /* line 3518 */
  sim_icache_fetch(2381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3520 */
} /* line 3520 */
  sim_icache_fetch(2382 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3522 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3523 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3524 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3525 */
   __ADD_CYCLES(1);
} /* line 3525 */
  sim_icache_fetch(2388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3527 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3528 */
} /* line 3528 */
  sim_icache_fetch(2390 + t_thisfile.offset, 1);
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
} /* line 3530 */
  sim_icache_fetch(2391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3532 */
} /* line 3532 */
  sim_icache_fetch(2393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3534 */
} /* line 3534 */
  sim_icache_fetch(2394 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3536 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3537 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3538 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3539 */
   __ADD_CYCLES(1);
} /* line 3539 */
  sim_icache_fetch(2400 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3541 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3542 */
} /* line 3542 */
  sim_icache_fetch(2402 + t_thisfile.offset, 1);
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
} /* line 3544 */
  sim_icache_fetch(2403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3546 */
} /* line 3546 */
  sim_icache_fetch(2405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3548 */
} /* line 3548 */
  sim_icache_fetch(2406 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3550 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3551 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3552 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3553 */
   __ADD_CYCLES(1);
} /* line 3553 */
  sim_icache_fetch(2412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3555 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3556 */
} /* line 3556 */
  sim_icache_fetch(2414 + t_thisfile.offset, 1);
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
} /* line 3558 */
  sim_icache_fetch(2415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3560 */
} /* line 3560 */
  sim_icache_fetch(2417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3562 */
} /* line 3562 */
  sim_icache_fetch(2418 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3564 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3565 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3566 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3567 */
   __ADD_CYCLES(1);
} /* line 3567 */
  sim_icache_fetch(2424 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3569 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3570 */
} /* line 3570 */
  sim_icache_fetch(2426 + t_thisfile.offset, 1);
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
} /* line 3572 */
  sim_icache_fetch(2427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3574 */
} /* line 3574 */
  sim_icache_fetch(2429 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3576 */
} /* line 3576 */
  sim_icache_fetch(2430 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3578 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3579 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3580 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3581 */
   __ADD_CYCLES(1);
} /* line 3581 */
  sim_icache_fetch(2436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3583 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3584 */
} /* line 3584 */
  sim_icache_fetch(2438 + t_thisfile.offset, 1);
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
} /* line 3586 */
  sim_icache_fetch(2439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3588 */
} /* line 3588 */
  sim_icache_fetch(2441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3590 */
} /* line 3590 */
  sim_icache_fetch(2442 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3592 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3593 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3594 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3595 */
   __ADD_CYCLES(1);
} /* line 3595 */
  sim_icache_fetch(2448 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3597 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3598 */
} /* line 3598 */
  sim_icache_fetch(2450 + t_thisfile.offset, 1);
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
} /* line 3600 */
  sim_icache_fetch(2451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3602 */
} /* line 3602 */
  sim_icache_fetch(2453 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3604 */
} /* line 3604 */
  sim_icache_fetch(2454 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3606 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3607 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3608 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3609 */
   __ADD_CYCLES(1);
} /* line 3609 */
  sim_icache_fetch(2460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3611 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3612 */
} /* line 3612 */
  sim_icache_fetch(2462 + t_thisfile.offset, 1);
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
} /* line 3614 */
  sim_icache_fetch(2463 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3616 */
} /* line 3616 */
  sim_icache_fetch(2465 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3618 */
} /* line 3618 */
  sim_icache_fetch(2466 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3620 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3621 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3622 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3623 */
   __ADD_CYCLES(1);
} /* line 3623 */
  sim_icache_fetch(2472 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3625 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3626 */
} /* line 3626 */
  sim_icache_fetch(2474 + t_thisfile.offset, 1);
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
} /* line 3628 */
  sim_icache_fetch(2475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3630 */
} /* line 3630 */
  sim_icache_fetch(2477 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3632 */
} /* line 3632 */
  sim_icache_fetch(2478 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3634 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3635 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3636 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3637 */
   __ADD_CYCLES(1);
} /* line 3637 */
  sim_icache_fetch(2484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3639 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3640 */
} /* line 3640 */
  sim_icache_fetch(2486 + t_thisfile.offset, 1);
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
} /* line 3642 */
  sim_icache_fetch(2487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3644 */
} /* line 3644 */
  sim_icache_fetch(2489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3646 */
} /* line 3646 */
  sim_icache_fetch(2490 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3648 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3649 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3650 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3651 */
   __ADD_CYCLES(1);
} /* line 3651 */
  sim_icache_fetch(2496 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3653 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3654 */
} /* line 3654 */
  sim_icache_fetch(2498 + t_thisfile.offset, 1);
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
} /* line 3656 */
  sim_icache_fetch(2499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3658 */
} /* line 3658 */
  sim_icache_fetch(2501 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3660 */
} /* line 3660 */
  sim_icache_fetch(2502 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3662 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3663 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3664 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3665 */
   __ADD_CYCLES(1);
} /* line 3665 */
  sim_icache_fetch(2508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3667 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3668 */
} /* line 3668 */
  sim_icache_fetch(2510 + t_thisfile.offset, 1);
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
} /* line 3670 */
  sim_icache_fetch(2511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3672 */
} /* line 3672 */
  sim_icache_fetch(2513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3674 */
} /* line 3674 */
  sim_icache_fetch(2514 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3676 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3677 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3678 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3679 */
   __ADD_CYCLES(1);
} /* line 3679 */
  sim_icache_fetch(2520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3681 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3682 */
} /* line 3682 */
  sim_icache_fetch(2522 + t_thisfile.offset, 1);
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
} /* line 3684 */
  sim_icache_fetch(2523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3686 */
} /* line 3686 */
  sim_icache_fetch(2525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3688 */
} /* line 3688 */
  sim_icache_fetch(2526 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3690 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3691 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3692 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3693 */
   __ADD_CYCLES(1);
} /* line 3693 */
  sim_icache_fetch(2532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3695 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3696 */
} /* line 3696 */
  sim_icache_fetch(2534 + t_thisfile.offset, 1);
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
} /* line 3698 */
  sim_icache_fetch(2535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3700 */
} /* line 3700 */
  sim_icache_fetch(2537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3702 */
   __GOTO(l_L162X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L162X3;
} /* line 3703 */
l_L163X3: ;/* line 3706 */
__LABEL(l_L163X3);
  sim_icache_fetch(2539 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3707 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3708 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3709 */
   __ADD_CYCLES(1);
} /* line 3709 */
  sim_icache_fetch(2544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3711 */
} /* line 3711 */
  sim_icache_fetch(2545 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3713 */
} /* line 3713 */
l_L161X3: ;/* line 3716 */
__LABEL(l_L161X3);
  sim_icache_fetch(2547 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_9680Xoffset,0,4), 0); /* line 3717 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3718 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3719 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3720 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3721 */
   __ADD_CYCLES(1);
} /* line 3721 */
  sim_icache_fetch(2555 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3723 */
} /* line 3723 */
  sim_icache_fetch(2556 + t_thisfile.offset, 1);
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
} /* line 3725 */
  sim_icache_fetch(2557 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3728 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3729 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3730 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3731 */
l_L164X3: ;/* line 3734 */
__LABEL(l_L164X3);
  sim_icache_fetch(2564 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3735 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3736 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3737 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3738 */
   __ADD_CYCLES(1);
} /* line 3738 */
  sim_icache_fetch(2571 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3740 */
} /* line 3740 */
  sim_icache_fetch(2572 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3742 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3743 */
} /* line 3743 */
  sim_icache_fetch(2575 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L165X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3745 */
  sim_icache_fetch(2576 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3748 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3749 */
l_L165X3: ;/* line 3752 */
__LABEL(l_L165X3);
  sim_icache_fetch(2579 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3753 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3754 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3755 */
   __ADD_CYCLES(1);
} /* line 3755 */
  sim_icache_fetch(2583 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3757 */
} /* line 3757 */
  sim_icache_fetch(2584 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3759 */
} /* line 3759 */
  sim_icache_fetch(2585 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3762 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3763 */
l_L160X3: ;/* line 3766 */
__LABEL(l_L160X3);
  sim_icache_fetch(2588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3768 */
l_L154X3: ;/* line 3771 */
__LABEL(l_L154X3);
  sim_icache_fetch(2589 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3772 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3773 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3774 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3775 */
   __ADD_CYCLES(1);
} /* line 3775 */
  sim_icache_fetch(2596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3777 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3778 */
} /* line 3778 */
  sim_icache_fetch(2598 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3780 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3781 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3782 */
l_L167X3: ;/* line 3784 */
__LABEL(l_L167X3);
  sim_icache_fetch(2601 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3785 */
   __STW(mem_trace_st((unsigned int) compress_9680Xoffset,0,4), 0); /* line 3786 */
} /* line 3786 */
  sim_icache_fetch(2604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3788 */
} /* line 3788 */
  sim_icache_fetch(2605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3790 */
} /* line 3790 */
  sim_icache_fetch(2606 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3793 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3794 */
l_L166X3: ;/* line 3797 */
__LABEL(l_L166X3);
  sim_icache_fetch(2609 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3798 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3799 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3800 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3801 */
} /* line 3801 */
  sim_icache_fetch(2613 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3803 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3804 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3805 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3806 */
} /* line 3806 */
  sim_icache_fetch(2617 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3808 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3809 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3810 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3811 */
} /* line 3811 */
  sim_icache_fetch(2621 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3813 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3814 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3815 */
   __MOV(reg_r0_5, (unsigned int) compress_9680Xbuf); /* line 3816 */
} /* line 3816 */
  sim_icache_fetch(2626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 3818 */
} /* line 3818 */
l_L168X3: ;/* line 3821 */
__LABEL(l_L168X3);
  sim_icache_fetch(2627 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3822 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3823 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3824 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3825 */
   __ADD_CYCLES(1);
} /* line 3825 */
  sim_icache_fetch(2633 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3827 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3828 */
} /* line 3828 */
  sim_icache_fetch(2635 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3830 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3831 */
} /* line 3831 */
  sim_icache_fetch(2637 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3833 */
} /* line 3833 */
  sim_icache_fetch(2638 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3835 */
} /* line 3835 */
  sim_icache_fetch(2639 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3837 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3838 */
} /* line 3838 */
  sim_icache_fetch(2641 + t_thisfile.offset, 1);
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
} /* line 3840 */
  sim_icache_fetch(2642 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3842 */
} /* line 3842 */
  sim_icache_fetch(2644 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3844 */
} /* line 3844 */
  sim_icache_fetch(2645 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3846 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3847 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3848 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3849 */
   __ADD_CYCLES(1);
} /* line 3849 */
  sim_icache_fetch(2651 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3851 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3852 */
} /* line 3852 */
  sim_icache_fetch(2653 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3854 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3855 */
} /* line 3855 */
  sim_icache_fetch(2655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3857 */
} /* line 3857 */
  sim_icache_fetch(2656 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3859 */
} /* line 3859 */
  sim_icache_fetch(2657 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3861 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3862 */
} /* line 3862 */
  sim_icache_fetch(2659 + t_thisfile.offset, 1);
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
} /* line 3864 */
  sim_icache_fetch(2660 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3866 */
} /* line 3866 */
  sim_icache_fetch(2662 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3868 */
} /* line 3868 */
  sim_icache_fetch(2663 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3870 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3871 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3872 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3873 */
   __ADD_CYCLES(1);
} /* line 3873 */
  sim_icache_fetch(2669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3875 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3876 */
} /* line 3876 */
  sim_icache_fetch(2671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3878 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3879 */
} /* line 3879 */
  sim_icache_fetch(2673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3881 */
} /* line 3881 */
  sim_icache_fetch(2674 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3883 */
} /* line 3883 */
  sim_icache_fetch(2675 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3885 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3886 */
} /* line 3886 */
  sim_icache_fetch(2677 + t_thisfile.offset, 1);
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
} /* line 3888 */
  sim_icache_fetch(2678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3890 */
} /* line 3890 */
  sim_icache_fetch(2680 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3892 */
} /* line 3892 */
  sim_icache_fetch(2681 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3894 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3895 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3896 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3897 */
   __ADD_CYCLES(1);
} /* line 3897 */
  sim_icache_fetch(2687 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3899 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3900 */
} /* line 3900 */
  sim_icache_fetch(2689 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3902 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3903 */
} /* line 3903 */
  sim_icache_fetch(2691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3905 */
} /* line 3905 */
  sim_icache_fetch(2692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3907 */
} /* line 3907 */
  sim_icache_fetch(2693 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3909 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3910 */
} /* line 3910 */
  sim_icache_fetch(2695 + t_thisfile.offset, 1);
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
} /* line 3912 */
  sim_icache_fetch(2696 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3914 */
} /* line 3914 */
  sim_icache_fetch(2698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3916 */
} /* line 3916 */
  sim_icache_fetch(2699 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3918 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3919 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3920 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3921 */
   __ADD_CYCLES(1);
} /* line 3921 */
  sim_icache_fetch(2705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3923 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3924 */
} /* line 3924 */
  sim_icache_fetch(2707 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3926 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3927 */
} /* line 3927 */
  sim_icache_fetch(2709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3929 */
} /* line 3929 */
  sim_icache_fetch(2710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3931 */
} /* line 3931 */
  sim_icache_fetch(2711 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 3933 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3934 */
} /* line 3934 */
  sim_icache_fetch(2713 + t_thisfile.offset, 1);
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
} /* line 3936 */
  sim_icache_fetch(2714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3938 */
} /* line 3938 */
  sim_icache_fetch(2716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3940 */
} /* line 3940 */
  sim_icache_fetch(2717 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3942 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3943 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3944 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3945 */
   __ADD_CYCLES(1);
} /* line 3945 */
  sim_icache_fetch(2723 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3947 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3948 */
} /* line 3948 */
  sim_icache_fetch(2725 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3950 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3951 */
} /* line 3951 */
  sim_icache_fetch(2727 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3953 */
} /* line 3953 */
  sim_icache_fetch(2728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3955 */
} /* line 3955 */
  sim_icache_fetch(2729 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 3957 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3958 */
} /* line 3958 */
  sim_icache_fetch(2731 + t_thisfile.offset, 1);
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
} /* line 3960 */
  sim_icache_fetch(2732 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3962 */
} /* line 3962 */
  sim_icache_fetch(2734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3964 */
} /* line 3964 */
  sim_icache_fetch(2735 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3966 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3967 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3968 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3969 */
   __ADD_CYCLES(1);
} /* line 3969 */
  sim_icache_fetch(2741 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3971 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3972 */
} /* line 3972 */
  sim_icache_fetch(2743 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3974 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3975 */
} /* line 3975 */
  sim_icache_fetch(2745 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3977 */
} /* line 3977 */
  sim_icache_fetch(2746 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3979 */
} /* line 3979 */
  sim_icache_fetch(2747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 3981 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 3982 */
} /* line 3982 */
  sim_icache_fetch(2749 + t_thisfile.offset, 1);
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
} /* line 3984 */
  sim_icache_fetch(2750 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3986 */
} /* line 3986 */
  sim_icache_fetch(2752 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3988 */
} /* line 3988 */
  sim_icache_fetch(2753 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 3990 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3991 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3992 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3993 */
   __ADD_CYCLES(1);
} /* line 3993 */
  sim_icache_fetch(2759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3995 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3996 */
} /* line 3996 */
  sim_icache_fetch(2761 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3998 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3999 */
} /* line 3999 */
  sim_icache_fetch(2763 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4001 */
} /* line 4001 */
  sim_icache_fetch(2764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4003 */
} /* line 4003 */
  sim_icache_fetch(2765 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4005 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4006 */
} /* line 4006 */
  sim_icache_fetch(2767 + t_thisfile.offset, 1);
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
} /* line 4008 */
  sim_icache_fetch(2768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4010 */
} /* line 4010 */
  sim_icache_fetch(2770 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4012 */
} /* line 4012 */
  sim_icache_fetch(2771 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4014 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4015 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4016 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4017 */
   __ADD_CYCLES(1);
} /* line 4017 */
  sim_icache_fetch(2777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4019 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4020 */
} /* line 4020 */
  sim_icache_fetch(2779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4022 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4023 */
} /* line 4023 */
  sim_icache_fetch(2781 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4025 */
} /* line 4025 */
  sim_icache_fetch(2782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4027 */
} /* line 4027 */
  sim_icache_fetch(2783 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4029 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4030 */
} /* line 4030 */
  sim_icache_fetch(2785 + t_thisfile.offset, 1);
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
} /* line 4032 */
  sim_icache_fetch(2786 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4034 */
} /* line 4034 */
  sim_icache_fetch(2788 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4036 */
} /* line 4036 */
  sim_icache_fetch(2789 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4038 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4039 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4040 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4041 */
   __ADD_CYCLES(1);
} /* line 4041 */
  sim_icache_fetch(2795 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4043 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4044 */
} /* line 4044 */
  sim_icache_fetch(2797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4046 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4047 */
} /* line 4047 */
  sim_icache_fetch(2799 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4049 */
} /* line 4049 */
  sim_icache_fetch(2800 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4051 */
} /* line 4051 */
  sim_icache_fetch(2801 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4053 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4054 */
} /* line 4054 */
  sim_icache_fetch(2803 + t_thisfile.offset, 1);
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
} /* line 4056 */
  sim_icache_fetch(2804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4058 */
} /* line 4058 */
  sim_icache_fetch(2806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4060 */
} /* line 4060 */
  sim_icache_fetch(2807 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4062 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4063 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4064 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4065 */
   __ADD_CYCLES(1);
} /* line 4065 */
  sim_icache_fetch(2813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4067 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4068 */
} /* line 4068 */
  sim_icache_fetch(2815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4070 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4071 */
} /* line 4071 */
  sim_icache_fetch(2817 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4073 */
} /* line 4073 */
  sim_icache_fetch(2818 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4075 */
} /* line 4075 */
  sim_icache_fetch(2819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4077 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4078 */
} /* line 4078 */
  sim_icache_fetch(2821 + t_thisfile.offset, 1);
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
} /* line 4080 */
  sim_icache_fetch(2822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4082 */
} /* line 4082 */
  sim_icache_fetch(2824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4084 */
} /* line 4084 */
  sim_icache_fetch(2825 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4086 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4087 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4088 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4089 */
   __ADD_CYCLES(1);
} /* line 4089 */
  sim_icache_fetch(2831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4091 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4092 */
} /* line 4092 */
  sim_icache_fetch(2833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4094 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4095 */
} /* line 4095 */
  sim_icache_fetch(2835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4097 */
} /* line 4097 */
  sim_icache_fetch(2836 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4099 */
} /* line 4099 */
  sim_icache_fetch(2837 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4101 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4102 */
} /* line 4102 */
  sim_icache_fetch(2839 + t_thisfile.offset, 1);
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
} /* line 4104 */
  sim_icache_fetch(2840 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4106 */
} /* line 4106 */
  sim_icache_fetch(2842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4108 */
} /* line 4108 */
  sim_icache_fetch(2843 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4110 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4111 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4112 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4113 */
   __ADD_CYCLES(1);
} /* line 4113 */
  sim_icache_fetch(2849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4115 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4116 */
} /* line 4116 */
  sim_icache_fetch(2851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4118 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4119 */
} /* line 4119 */
  sim_icache_fetch(2853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4121 */
} /* line 4121 */
  sim_icache_fetch(2854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4123 */
} /* line 4123 */
  sim_icache_fetch(2855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4125 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4126 */
} /* line 4126 */
  sim_icache_fetch(2857 + t_thisfile.offset, 1);
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
} /* line 4128 */
  sim_icache_fetch(2858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4130 */
} /* line 4130 */
  sim_icache_fetch(2860 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4132 */
} /* line 4132 */
  sim_icache_fetch(2861 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4134 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4135 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4136 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4137 */
   __ADD_CYCLES(1);
} /* line 4137 */
  sim_icache_fetch(2867 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4139 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4140 */
} /* line 4140 */
  sim_icache_fetch(2869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4142 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4143 */
} /* line 4143 */
  sim_icache_fetch(2871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4145 */
} /* line 4145 */
  sim_icache_fetch(2872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4147 */
} /* line 4147 */
  sim_icache_fetch(2873 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4149 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4150 */
} /* line 4150 */
  sim_icache_fetch(2875 + t_thisfile.offset, 1);
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
} /* line 4152 */
  sim_icache_fetch(2876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4154 */
} /* line 4154 */
  sim_icache_fetch(2878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4156 */
} /* line 4156 */
  sim_icache_fetch(2879 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4158 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4159 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4160 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4161 */
   __ADD_CYCLES(1);
} /* line 4161 */
  sim_icache_fetch(2885 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4163 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4164 */
} /* line 4164 */
  sim_icache_fetch(2887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4166 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4167 */
} /* line 4167 */
  sim_icache_fetch(2889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4169 */
} /* line 4169 */
  sim_icache_fetch(2890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4171 */
} /* line 4171 */
  sim_icache_fetch(2891 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4173 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4174 */
} /* line 4174 */
  sim_icache_fetch(2893 + t_thisfile.offset, 1);
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
} /* line 4176 */
  sim_icache_fetch(2894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4178 */
} /* line 4178 */
  sim_icache_fetch(2896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4180 */
} /* line 4180 */
  sim_icache_fetch(2897 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4182 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4183 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4184 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4185 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4186 */
   __ADD_CYCLES(1);
} /* line 4186 */
  sim_icache_fetch(2904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4188 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4189 */
} /* line 4189 */
  sim_icache_fetch(2906 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4191 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4192 */
} /* line 4192 */
  sim_icache_fetch(2908 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4194 */
} /* line 4194 */
  sim_icache_fetch(2909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4196 */
} /* line 4196 */
  sim_icache_fetch(2910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4198 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4199 */
} /* line 4199 */
  sim_icache_fetch(2912 + t_thisfile.offset, 1);
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
} /* line 4201 */
  sim_icache_fetch(2913 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4203 */
} /* line 4203 */
  sim_icache_fetch(2915 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4205 */
   __GOTO(l_L168X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L168X3;
} /* line 4206 */
l_L184X3: ;/* line 4209 */
__LABEL(l_L184X3);
  sim_icache_fetch(2917 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4210 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4211 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4212 */
   __ADD_CYCLES(1);
} /* line 4212 */
  sim_icache_fetch(2922 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4214 */
} /* line 4214 */
  sim_icache_fetch(2923 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4216 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4217 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4218 */
l_L183X3: ;/* line 4221 */
__LABEL(l_L183X3);
  sim_icache_fetch(2926 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4222 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4223 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4224 */
   __ADD_CYCLES(1);
} /* line 4224 */
  sim_icache_fetch(2931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4226 */
} /* line 4226 */
  sim_icache_fetch(2932 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4228 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4229 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4230 */
l_L182X3: ;/* line 4233 */
__LABEL(l_L182X3);
  sim_icache_fetch(2935 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4234 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4235 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4236 */
   __ADD_CYCLES(1);
} /* line 4236 */
  sim_icache_fetch(2940 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4238 */
} /* line 4238 */
  sim_icache_fetch(2941 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4240 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4241 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4242 */
l_L181X3: ;/* line 4245 */
__LABEL(l_L181X3);
  sim_icache_fetch(2944 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4246 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4247 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4248 */
   __ADD_CYCLES(1);
} /* line 4248 */
  sim_icache_fetch(2949 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4250 */
} /* line 4250 */
  sim_icache_fetch(2950 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4252 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4253 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4254 */
l_L180X3: ;/* line 4257 */
__LABEL(l_L180X3);
  sim_icache_fetch(2953 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4258 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4259 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4260 */
   __ADD_CYCLES(1);
} /* line 4260 */
  sim_icache_fetch(2958 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4262 */
} /* line 4262 */
  sim_icache_fetch(2959 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4264 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4265 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4266 */
l_L179X3: ;/* line 4269 */
__LABEL(l_L179X3);
  sim_icache_fetch(2962 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4270 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4271 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4272 */
   __ADD_CYCLES(1);
} /* line 4272 */
  sim_icache_fetch(2967 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4274 */
} /* line 4274 */
  sim_icache_fetch(2968 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4276 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4277 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4278 */
l_L178X3: ;/* line 4281 */
__LABEL(l_L178X3);
  sim_icache_fetch(2971 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4282 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4283 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4284 */
   __ADD_CYCLES(1);
} /* line 4284 */
  sim_icache_fetch(2976 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4286 */
} /* line 4286 */
  sim_icache_fetch(2977 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4288 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4289 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4290 */
l_L177X3: ;/* line 4293 */
__LABEL(l_L177X3);
  sim_icache_fetch(2980 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4294 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4295 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4296 */
   __ADD_CYCLES(1);
} /* line 4296 */
  sim_icache_fetch(2985 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4298 */
} /* line 4298 */
  sim_icache_fetch(2986 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4300 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4301 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4302 */
l_L176X3: ;/* line 4305 */
__LABEL(l_L176X3);
  sim_icache_fetch(2989 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4306 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4307 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4308 */
   __ADD_CYCLES(1);
} /* line 4308 */
  sim_icache_fetch(2994 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4310 */
} /* line 4310 */
  sim_icache_fetch(2995 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4312 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4313 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4314 */
l_L175X3: ;/* line 4317 */
__LABEL(l_L175X3);
  sim_icache_fetch(2998 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4318 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4319 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4320 */
   __ADD_CYCLES(1);
} /* line 4320 */
  sim_icache_fetch(3003 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4322 */
} /* line 4322 */
  sim_icache_fetch(3004 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4324 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4325 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4326 */
l_L174X3: ;/* line 4329 */
__LABEL(l_L174X3);
  sim_icache_fetch(3007 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4330 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4331 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4332 */
   __ADD_CYCLES(1);
} /* line 4332 */
  sim_icache_fetch(3012 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4334 */
} /* line 4334 */
  sim_icache_fetch(3013 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4336 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4337 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4338 */
l_L173X3: ;/* line 4341 */
__LABEL(l_L173X3);
  sim_icache_fetch(3016 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4342 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4343 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4344 */
   __ADD_CYCLES(1);
} /* line 4344 */
  sim_icache_fetch(3021 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4346 */
} /* line 4346 */
  sim_icache_fetch(3022 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4348 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4349 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4350 */
l_L172X3: ;/* line 4353 */
__LABEL(l_L172X3);
  sim_icache_fetch(3025 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4354 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4355 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4356 */
   __ADD_CYCLES(1);
} /* line 4356 */
  sim_icache_fetch(3030 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4358 */
} /* line 4358 */
  sim_icache_fetch(3031 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4360 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4361 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4362 */
l_L171X3: ;/* line 4365 */
__LABEL(l_L171X3);
  sim_icache_fetch(3034 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4366 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4367 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4368 */
   __ADD_CYCLES(1);
} /* line 4368 */
  sim_icache_fetch(3039 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4370 */
} /* line 4370 */
  sim_icache_fetch(3040 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4372 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4373 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4374 */
l_L170X3: ;/* line 4377 */
__LABEL(l_L170X3);
  sim_icache_fetch(3043 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4378 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4379 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4380 */
   __ADD_CYCLES(1);
} /* line 4380 */
  sim_icache_fetch(3048 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4382 */
} /* line 4382 */
  sim_icache_fetch(3049 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4384 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4385 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4386 */
l_L169X3: ;/* line 4389 */
__LABEL(l_L169X3);
  sim_icache_fetch(3052 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4390 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9680Xoffset,0,4)); /* line 4391 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4392 */
   __ADD_CYCLES(1);
} /* line 4392 */
  sim_icache_fetch(3057 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4394 */
} /* line 4394 */
  sim_icache_fetch(3058 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4396 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4397 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 4398 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 319: goto l_L155X3;
    case 320: goto l_L156X3;
    case 321: goto l_L158X3;
    case 322: goto l_L159X3;
    case 323: goto l_L157X3;
    case 324: goto l_L162X3;
    case 325: goto l_L163X3;
    case 326: goto l_L161X3;
    case 327: goto l_L164X3;
    case 328: goto l_L165X3;
    case 329: goto l_L160X3;
    case 330: goto l_L154X3;
    case 331: goto l_L167X3;
    case 332: goto l_L166X3;
    case 333: goto l_L168X3;
    case 334: goto l_L184X3;
    case 335: goto l_L183X3;
    case 336: goto l_L182X3;
    case 337: goto l_L181X3;
    case 338: goto l_L180X3;
    case 339: goto l_L179X3;
    case 340: goto l_L178X3;
    case 341: goto l_L177X3;
    case 342: goto l_L176X3;
    case 343: goto l_L175X3;
    case 344: goto l_L174X3;
    case 345: goto l_L173X3;
    case 346: goto l_L172X3;
    case 347: goto l_L171X3;
    case 348: goto l_L170X3;
    case 349: goto l_L169X3;
    case 350:
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
  reg_l0_0 = (404 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3061 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4414 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4415 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4416 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4417 */
} /* line 4417 */
  sim_icache_fetch(3066 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4419 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4420 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4421 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4422 */
} /* line 4422 */
  sim_icache_fetch(3070 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4424 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4425 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4426 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4427 */
} /* line 4427 */
  sim_icache_fetch(3074 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4429 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4430 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4431 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4432 */
} /* line 4432 */
  sim_icache_fetch(3078 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4434 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4435 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4436 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4437 */
} /* line 4437 */
  sim_icache_fetch(3083 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4439 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4440 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4441 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4442 */
} /* line 4442 */
  sim_icache_fetch(3089 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4444 */
} /* line 4444 */
l_L185X3: ;/* line 4447 */
__LABEL(l_L185X3);
  sim_icache_fetch(3091 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4448 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4449 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4450 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4451 */
} /* line 4451 */
  sim_icache_fetch(3095 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4453 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4454 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4455 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L186X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4456 */
  sim_icache_fetch(3099 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4458 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4459 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4460 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4461 */
} /* line 4461 */
  sim_icache_fetch(3103 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4463 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4464 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4465 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4466 */
} /* line 4466 */
  sim_icache_fetch(3107 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4468 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4469 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4470 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4471 */
} /* line 4471 */
  sim_icache_fetch(3111 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4473 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4474 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4475 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4476 */
} /* line 4476 */
  sim_icache_fetch(3115 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4478 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4479 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4480 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4481 */
} /* line 4481 */
  sim_icache_fetch(3119 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4483 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4484 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4485 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4486 */
} /* line 4486 */
  sim_icache_fetch(3123 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4488 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4489 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4490 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4491 */
} /* line 4491 */
  sim_icache_fetch(3127 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4493 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4494 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4495 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4496 */
} /* line 4496 */
  sim_icache_fetch(3131 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4498 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4499 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4500 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4501 */
} /* line 4501 */
  sim_icache_fetch(3135 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4503 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4504 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4505 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4506 */
} /* line 4506 */
  sim_icache_fetch(3139 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4508 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4509 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4510 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4511 */
} /* line 4511 */
  sim_icache_fetch(3143 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4513 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4514 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4515 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4516 */
} /* line 4516 */
  sim_icache_fetch(3147 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4518 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4519 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4520 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4521 */
} /* line 4521 */
  sim_icache_fetch(3151 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4523 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4524 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4525 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4526 */
} /* line 4526 */
  sim_icache_fetch(3155 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4528 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4529 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4530 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4531 */
} /* line 4531 */
  sim_icache_fetch(3159 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4533 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4534 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4535 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4536 */
} /* line 4536 */
  sim_icache_fetch(3163 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4538 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4539 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4540 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4541 */
} /* line 4541 */
  sim_icache_fetch(3167 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4543 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4544 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4545 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4546 */
} /* line 4546 */
  sim_icache_fetch(3171 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4548 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4549 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4550 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4551 */
} /* line 4551 */
  sim_icache_fetch(3175 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4553 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4554 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4555 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4556 */
} /* line 4556 */
  sim_icache_fetch(3179 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4558 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4559 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4560 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4561 */
} /* line 4561 */
  sim_icache_fetch(3183 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4563 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4564 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4565 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4566 */
} /* line 4566 */
  sim_icache_fetch(3187 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4568 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4569 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4570 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4571 */
} /* line 4571 */
  sim_icache_fetch(3191 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4573 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4574 */
   __GOTO(l_L185X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L185X3;
} /* line 4575 */
l_L186X3: ;/* line 4578 */
__LABEL(l_L186X3);
  sim_icache_fetch(3194 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4579 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4580 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4581 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4582 */
   __ADD_CYCLES(1);
} /* line 4582 */
  sim_icache_fetch(3200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4584 */
} /* line 4584 */
  sim_icache_fetch(3201 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4586 */
} /* line 4586 */
		 /* line 4587 */
  sim_icache_fetch(3203 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4589 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (404 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4590 */
l_lr_253: ;/* line 4590 */
__LABEL(l_lr_253);
  sim_icache_fetch(3207 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_3); /* line 4592 */
   __MOV(reg_r0_4, reg_r0_3); /* line 4593 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4594 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4595 */
} /* line 4595 */
  sim_icache_fetch(3211 + t_thisfile.offset, 1);
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
} /* line 4597 */
  sim_icache_fetch(3212 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 4601 */
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4601 */
l_L187X3: ;/* line 4604 */
__LABEL(l_L187X3);
  sim_icache_fetch(3214 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4605 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4606 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4607 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4608 */
} /* line 4608 */
  sim_icache_fetch(3219 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4610 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4611 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4612 */
} /* line 4612 */
  sim_icache_fetch(3223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 1); /* line 4614 */
} /* line 4614 */
  sim_icache_fetch(3224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4616 */
} /* line 4616 */
  sim_icache_fetch(3226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4618 */
} /* line 4618 */
l_L188X3: ;/* line 4621 */
__LABEL(l_L188X3);
		 /* line 4621 */
  sim_icache_fetch(3227 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (404 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4623 */
l_lr_257: ;/* line 4623 */
__LABEL(l_lr_257);
  sim_icache_fetch(3229 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, reg_r0_3); /* line 4625 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4626 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4627 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4628 */
} /* line 4628 */
  sim_icache_fetch(3235 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4630 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L189X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4631 */
  sim_icache_fetch(3237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4633 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4634 */
} /* line 4634 */
  sim_icache_fetch(3240 + t_thisfile.offset, 1);
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
} /* line 4636 */
l_L191X3: ;/* line 4639 */
__LABEL(l_L191X3);
  sim_icache_fetch(3241 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4640 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4641 */
} /* line 4641 */
  sim_icache_fetch(3243 + t_thisfile.offset, 1);
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
} /* line 4643 */
  sim_icache_fetch(3244 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4645 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4646 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4647 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4648 */
} /* line 4648 */
  sim_icache_fetch(3248 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4650 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4651 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4652 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4653 */
} /* line 4653 */
  sim_icache_fetch(3252 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4655 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4656 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4657 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4658 */
} /* line 4658 */
  sim_icache_fetch(3256 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4660 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4661 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4662 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4663 */
} /* line 4663 */
  sim_icache_fetch(3260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4665 */
   __GOTO(l_L191X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L191X3;
} /* line 4666 */
l_L192X3: ;/* line 4669 */
__LABEL(l_L192X3);
  sim_icache_fetch(3262 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4670 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4671 */
} /* line 4671 */
		 /* line 4672 */
  sim_icache_fetch(3265 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4674 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4675 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (404 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4676 */
l_lr_261: ;/* line 4676 */
__LABEL(l_lr_261);
  sim_icache_fetch(3271 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4678 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4679 */
} /* line 4679 */
  sim_icache_fetch(3273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L189X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4681 */
l_L190X3: ;/* line 4684 */
__LABEL(l_L190X3);
  sim_icache_fetch(3274 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4685 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4686 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4687 */
   __ADD_CYCLES(1);
} /* line 4687 */
  sim_icache_fetch(3278 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4689 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4690 */
} /* line 4690 */
  sim_icache_fetch(3280 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4692 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L193X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4693 */
  sim_icache_fetch(3283 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4695 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4696 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4697 */
} /* line 4697 */
l_L194X3: ;/* line 4700 */
__LABEL(l_L194X3);
  sim_icache_fetch(3286 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4701 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4702 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4703 */
} /* line 4703 */
  sim_icache_fetch(3291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4705 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L195X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4706 */
  sim_icache_fetch(3293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4708 */
} /* line 4708 */
  sim_icache_fetch(3294 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4710 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4711 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4712 */
} /* line 4712 */
  sim_icache_fetch(3299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4714 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L196X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4715 */
  sim_icache_fetch(3301 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4717 */
} /* line 4717 */
  sim_icache_fetch(3302 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4719 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4720 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4721 */
} /* line 4721 */
  sim_icache_fetch(3307 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4723 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L197X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4724 */
  sim_icache_fetch(3309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4726 */
} /* line 4726 */
  sim_icache_fetch(3310 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4728 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4729 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4730 */
} /* line 4730 */
  sim_icache_fetch(3315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4732 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L198X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4733 */
  sim_icache_fetch(3317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4735 */
} /* line 4735 */
  sim_icache_fetch(3318 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4737 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4738 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4739 */
} /* line 4739 */
  sim_icache_fetch(3323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4741 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L199X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4742 */
  sim_icache_fetch(3325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4744 */
} /* line 4744 */
  sim_icache_fetch(3326 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4746 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4747 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4748 */
} /* line 4748 */
  sim_icache_fetch(3331 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4750 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L200X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4751 */
  sim_icache_fetch(3333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4753 */
} /* line 4753 */
  sim_icache_fetch(3334 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4755 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4756 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4757 */
} /* line 4757 */
  sim_icache_fetch(3339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4759 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4760 */
  sim_icache_fetch(3341 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4762 */
} /* line 4762 */
  sim_icache_fetch(3342 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4764 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4765 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4766 */
} /* line 4766 */
  sim_icache_fetch(3347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4768 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L202X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4769 */
  sim_icache_fetch(3349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4771 */
} /* line 4771 */
  sim_icache_fetch(3350 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4773 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4774 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4775 */
} /* line 4775 */
  sim_icache_fetch(3355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4777 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L203X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4778 */
  sim_icache_fetch(3357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4780 */
} /* line 4780 */
  sim_icache_fetch(3358 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4782 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4783 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4784 */
} /* line 4784 */
  sim_icache_fetch(3363 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4786 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4787 */
  sim_icache_fetch(3365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4789 */
} /* line 4789 */
  sim_icache_fetch(3366 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4791 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4792 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4793 */
} /* line 4793 */
  sim_icache_fetch(3371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4795 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L205X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4796 */
  sim_icache_fetch(3373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4798 */
} /* line 4798 */
  sim_icache_fetch(3374 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4800 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4801 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4802 */
} /* line 4802 */
  sim_icache_fetch(3379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4804 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4805 */
  sim_icache_fetch(3381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4807 */
} /* line 4807 */
  sim_icache_fetch(3382 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4809 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4810 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4811 */
} /* line 4811 */
  sim_icache_fetch(3387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4813 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4814 */
  sim_icache_fetch(3389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4816 */
} /* line 4816 */
  sim_icache_fetch(3390 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4818 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4819 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4820 */
} /* line 4820 */
  sim_icache_fetch(3395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4822 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4823 */
  sim_icache_fetch(3397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4825 */
} /* line 4825 */
  sim_icache_fetch(3398 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4827 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4828 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4829 */
} /* line 4829 */
  sim_icache_fetch(3403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4831 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4832 */
  sim_icache_fetch(3405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4834 */
} /* line 4834 */
  sim_icache_fetch(3406 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4836 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4837 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4838 */
} /* line 4838 */
  sim_icache_fetch(3411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4840 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4841 */
  sim_icache_fetch(3413 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4843 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4844 */
   __GOTO(l_L194X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L194X3;
} /* line 4845 */
l_L210X3: ;/* line 4848 */
__LABEL(l_L210X3);
  sim_icache_fetch(3416 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4849 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4850 */
} /* line 4850 */
  sim_icache_fetch(3418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4852 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 4853 */
l_L212X3: ;/* line 4856 */
__LABEL(l_L212X3);
  sim_icache_fetch(3420 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_5, reg_r0_3); /* line 4857 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4858 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4859 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4860 */
} /* line 4860 */
  sim_icache_fetch(3426 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4862 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4863 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4864 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4865 */
} /* line 4865 */
  sim_icache_fetch(3434 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4867 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4868 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4869 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4870 */
} /* line 4870 */
  sim_icache_fetch(3441 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4872 */
   __ADD(reg_r0_23, reg_r0_19, (unsigned int) -16); /* line 4873 */
   __ADD(reg_r0_24, reg_r0_18, (unsigned int) -16); /* line 4874 */
   __ADD(reg_r0_25, reg_r0_17, (unsigned int) -16); /* line 4875 */
} /* line 4875 */
  sim_icache_fetch(3445 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_26, reg_r0_16, (unsigned int) -16); /* line 4877 */
   __ADD(reg_r0_27, reg_r0_15, (unsigned int) -16); /* line 4878 */
   __ADD(reg_r0_28, reg_r0_14, (unsigned int) -16); /* line 4879 */
   __ADD(reg_r0_29, reg_r0_13, (unsigned int) -16); /* line 4880 */
} /* line 4880 */
  sim_icache_fetch(3449 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4882 */
   __ADD(reg_r0_31, reg_r0_11, (unsigned int) -16); /* line 4883 */
   __ADD(reg_r0_32, reg_r0_10, (unsigned int) -16); /* line 4884 */
   __ADD(reg_r0_33, reg_r0_9, (unsigned int) -16); /* line 4885 */
} /* line 4885 */
  sim_icache_fetch(3453 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_34, reg_r0_8, (unsigned int) -16); /* line 4887 */
   __ADD(reg_r0_35, reg_r0_7, (unsigned int) -16); /* line 4888 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) -16); /* line 4889 */
   __ADD(reg_r0_37, reg_r0_20, (unsigned int) -16); /* line 4890 */
} /* line 4890 */
  sim_icache_fetch(3457 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4892 */
   __MOV(reg_r0_38, reg_r0_20); /* line 4893 */
   __MOV(reg_r0_40, reg_r0_37); /* line 4894 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 4895 */
} /* line 4895 */
  sim_icache_fetch(3462 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4897 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4898 */
  sim_icache_fetch(3464 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4900 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4901 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4902 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4903 */
   __ADD_CYCLES(1);
} /* line 4903 */
  sim_icache_fetch(3470 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4905 */
} /* line 4905 */
  sim_icache_fetch(3471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4907 */
} /* line 4907 */
  sim_icache_fetch(3473 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4909 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4910 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4911 */
  sim_icache_fetch(3477 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4913 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4914 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4915 */
   __MFB(reg_r0_4, t__i32_0); /* line 4916 */
} /* line 4916 */
  sim_icache_fetch(3483 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) -16); /* line 4918 */
} /* line 4918 */
  sim_icache_fetch(3484 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4920 */
} /* line 4920 */
  sim_icache_fetch(3485 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4922 */
} /* line 4922 */
  sim_icache_fetch(3487 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4924 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4925 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4926 */
  sim_icache_fetch(3490 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4928 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4929 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4930 */
   __MFB(reg_r0_4, t__i32_0); /* line 4931 */
} /* line 4931 */
  sim_icache_fetch(3496 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_35, (unsigned int) -16); /* line 4933 */
} /* line 4933 */
  sim_icache_fetch(3497 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4935 */
} /* line 4935 */
  sim_icache_fetch(3498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4937 */
} /* line 4937 */
  sim_icache_fetch(3500 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4939 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4940 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4941 */
  sim_icache_fetch(3503 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4943 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4944 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4945 */
   __MFB(reg_r0_4, t__i32_0); /* line 4946 */
} /* line 4946 */
  sim_icache_fetch(3509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_34, (unsigned int) -16); /* line 4948 */
} /* line 4948 */
  sim_icache_fetch(3510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4950 */
} /* line 4950 */
  sim_icache_fetch(3511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4952 */
} /* line 4952 */
  sim_icache_fetch(3513 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 4954 */
   __MTB(reg_b0_4, reg_r0_4); /* line 4955 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4956 */
  sim_icache_fetch(3516 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 4958 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4959 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 4960 */
   __MFB(reg_r0_4, t__i32_0); /* line 4961 */
} /* line 4961 */
  sim_icache_fetch(3522 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_33, (unsigned int) -16); /* line 4963 */
} /* line 4963 */
  sim_icache_fetch(3523 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4965 */
} /* line 4965 */
  sim_icache_fetch(3524 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4967 */
} /* line 4967 */
  sim_icache_fetch(3526 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 4969 */
   __MTB(reg_b0_5, reg_r0_4); /* line 4970 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4971 */
  sim_icache_fetch(3529 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 4973 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4974 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 4975 */
   __MFB(reg_r0_4, t__i32_0); /* line 4976 */
} /* line 4976 */
  sim_icache_fetch(3535 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_32, (unsigned int) -16); /* line 4978 */
} /* line 4978 */
  sim_icache_fetch(3536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4980 */
} /* line 4980 */
  sim_icache_fetch(3537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4982 */
} /* line 4982 */
  sim_icache_fetch(3539 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 4984 */
   __MTB(reg_b0_6, reg_r0_4); /* line 4985 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4986 */
  sim_icache_fetch(3542 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 4988 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4989 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 4990 */
   __MFB(reg_r0_4, t__i32_0); /* line 4991 */
} /* line 4991 */
  sim_icache_fetch(3548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_31, (unsigned int) -16); /* line 4993 */
} /* line 4993 */
  sim_icache_fetch(3549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4995 */
} /* line 4995 */
  sim_icache_fetch(3550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4997 */
} /* line 4997 */
  sim_icache_fetch(3552 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 4999 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5000 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5001 */
  sim_icache_fetch(3555 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5003 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5004 */
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 5005 */
   __MFB(reg_r0_4, t__i32_0); /* line 5006 */
} /* line 5006 */
  sim_icache_fetch(3561 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 5008 */
} /* line 5008 */
  sim_icache_fetch(3562 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5010 */
} /* line 5010 */
  sim_icache_fetch(3563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5012 */
} /* line 5012 */
  sim_icache_fetch(3565 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5014 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5015 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5016 */
  sim_icache_fetch(3568 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5018 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5019 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5020 */
   __MFB(reg_r0_4, t__i32_0); /* line 5021 */
} /* line 5021 */
  sim_icache_fetch(3574 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_29, (unsigned int) -16); /* line 5023 */
} /* line 5023 */
  sim_icache_fetch(3575 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5025 */
} /* line 5025 */
  sim_icache_fetch(3576 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5027 */
} /* line 5027 */
  sim_icache_fetch(3578 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5029 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5030 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5031 */
  sim_icache_fetch(3581 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5033 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5034 */
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 5035 */
   __MFB(reg_r0_4, t__i32_0); /* line 5036 */
} /* line 5036 */
  sim_icache_fetch(3587 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_28, (unsigned int) -16); /* line 5038 */
} /* line 5038 */
  sim_icache_fetch(3588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5040 */
} /* line 5040 */
  sim_icache_fetch(3589 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5042 */
} /* line 5042 */
  sim_icache_fetch(3591 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5044 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5045 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5046 */
  sim_icache_fetch(3594 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5048 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5049 */
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5050 */
   __MFB(reg_r0_4, t__i32_0); /* line 5051 */
} /* line 5051 */
  sim_icache_fetch(3600 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_27, (unsigned int) -16); /* line 5053 */
} /* line 5053 */
  sim_icache_fetch(3601 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5055 */
} /* line 5055 */
  sim_icache_fetch(3602 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5057 */
} /* line 5057 */
  sim_icache_fetch(3604 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5059 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5060 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5061 */
  sim_icache_fetch(3607 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5063 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5064 */
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5065 */
   __MFB(reg_r0_4, t__i32_0); /* line 5066 */
} /* line 5066 */
  sim_icache_fetch(3613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_26, (unsigned int) -16); /* line 5068 */
} /* line 5068 */
  sim_icache_fetch(3614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5070 */
} /* line 5070 */
  sim_icache_fetch(3615 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5072 */
} /* line 5072 */
  sim_icache_fetch(3617 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5074 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5075 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5076 */
  sim_icache_fetch(3620 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5078 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5079 */
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5080 */
   __MFB(reg_r0_4, t__i32_0); /* line 5081 */
} /* line 5081 */
  sim_icache_fetch(3626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_25, (unsigned int) -16); /* line 5083 */
} /* line 5083 */
  sim_icache_fetch(3627 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5085 */
} /* line 5085 */
  sim_icache_fetch(3628 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5087 */
} /* line 5087 */
  sim_icache_fetch(3630 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5089 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5090 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5091 */
  sim_icache_fetch(3633 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5093 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5094 */
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5095 */
   __MFB(reg_r0_4, t__i32_0); /* line 5096 */
} /* line 5096 */
  sim_icache_fetch(3639 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_24, (unsigned int) -16); /* line 5098 */
} /* line 5098 */
  sim_icache_fetch(3640 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5100 */
} /* line 5100 */
  sim_icache_fetch(3641 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5102 */
} /* line 5102 */
  sim_icache_fetch(3643 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5104 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5105 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5106 */
  sim_icache_fetch(3646 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5108 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5109 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5110 */
   __MFB(reg_r0_4, reg_b0_6); /* line 5111 */
} /* line 5111 */
  sim_icache_fetch(3651 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5113 */
   __ADD(reg_r0_19, reg_r0_23, (unsigned int) -16); /* line 5114 */
} /* line 5114 */
  sim_icache_fetch(3654 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5116 */
} /* line 5116 */
  sim_icache_fetch(3655 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5118 */
} /* line 5118 */
  sim_icache_fetch(3657 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5120 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5121 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5122 */
  sim_icache_fetch(3660 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_5, reg_r0_3); /* line 5124 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5125 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5126 */
   __MFB(reg_r0_22, reg_b0_7); /* line 5127 */
} /* line 5127 */
  sim_icache_fetch(3665 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLEU(reg_b0_7, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5129 */
   __ADD(reg_r0_20, reg_r0_37, (unsigned int) -16); /* line 5130 */
   __MOV(reg_r0_3, reg_r0_39); /* line 5131 */
} /* line 5131 */
  sim_icache_fetch(3669 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5133 */
} /* line 5133 */
  sim_icache_fetch(3670 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5135 */
} /* line 5135 */
  sim_icache_fetch(3672 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5137 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5138 */
  sim_icache_fetch(3674 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5140 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5141 */
   __CMPLEU(reg_b0_0, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5142 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5143 */
   __ADD_CYCLES(1);
} /* line 5143 */
  sim_icache_fetch(3680 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5145 */
} /* line 5145 */
  sim_icache_fetch(3681 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5147 */
} /* line 5147 */
  sim_icache_fetch(3683 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5149 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5150 */
  sim_icache_fetch(3685 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5152 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5153 */
   __CMPLEU(reg_b0_1, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5154 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5155 */
   __ADD_CYCLES(1);
} /* line 5155 */
  sim_icache_fetch(3691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5157 */
} /* line 5157 */
  sim_icache_fetch(3692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5159 */
} /* line 5159 */
  sim_icache_fetch(3694 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5161 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5162 */
  sim_icache_fetch(3696 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5164 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5165 */
   __CMPLEU(reg_b0_2, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5166 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5167 */
   __ADD_CYCLES(1);
} /* line 5167 */
  sim_icache_fetch(3702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5169 */
} /* line 5169 */
  sim_icache_fetch(3703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5171 */
} /* line 5171 */
  sim_icache_fetch(3705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5173 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5174 */
  sim_icache_fetch(3707 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5176 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5177 */
   __CMPLEU(reg_b0_3, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5178 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5179 */
   __ADD_CYCLES(1);
} /* line 5179 */
  sim_icache_fetch(3713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5181 */
} /* line 5181 */
  sim_icache_fetch(3714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5183 */
} /* line 5183 */
  sim_icache_fetch(3716 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5185 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5186 */
  sim_icache_fetch(3718 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5188 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5189 */
   __CMPLEU(reg_b0_4, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5190 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5191 */
   __ADD_CYCLES(1);
} /* line 5191 */
  sim_icache_fetch(3724 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5193 */
} /* line 5193 */
  sim_icache_fetch(3725 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5195 */
} /* line 5195 */
  sim_icache_fetch(3727 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5197 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5198 */
  sim_icache_fetch(3729 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5200 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5201 */
   __CMPLEU(reg_b0_5, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5202 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5203 */
   __ADD_CYCLES(1);
} /* line 5203 */
  sim_icache_fetch(3735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5205 */
} /* line 5205 */
  sim_icache_fetch(3736 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5207 */
} /* line 5207 */
  sim_icache_fetch(3738 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5209 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5210 */
  sim_icache_fetch(3740 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5212 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5213 */
   __CMPLEU(reg_b0_6, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5214 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5215 */
   __ADD_CYCLES(1);
} /* line 5215 */
  sim_icache_fetch(3746 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5217 */
} /* line 5217 */
  sim_icache_fetch(3747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5219 */
} /* line 5219 */
  sim_icache_fetch(3749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5221 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5222 */
  sim_icache_fetch(3751 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5224 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5225 */
   __MTB(reg_b0_7, reg_r0_22); /* line 5226 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5227 */
   __ADD_CYCLES(1);
} /* line 5227 */
  sim_icache_fetch(3756 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5229 */
} /* line 5229 */
  sim_icache_fetch(3757 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5231 */
} /* line 5231 */
  sim_icache_fetch(3759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5233 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5234 */
  sim_icache_fetch(3761 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5236 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5237 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5238 */
   __ADD_CYCLES(1);
} /* line 5238 */
  sim_icache_fetch(3765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5240 */
} /* line 5240 */
  sim_icache_fetch(3766 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5242 */
} /* line 5242 */
  sim_icache_fetch(3768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5244 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5245 */
  sim_icache_fetch(3770 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5247 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5248 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5249 */
   __ADD_CYCLES(1);
} /* line 5249 */
  sim_icache_fetch(3774 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5251 */
} /* line 5251 */
  sim_icache_fetch(3775 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5253 */
} /* line 5253 */
  sim_icache_fetch(3777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5255 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5256 */
  sim_icache_fetch(3779 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5258 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5259 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5260 */
   __ADD_CYCLES(1);
} /* line 5260 */
  sim_icache_fetch(3783 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5262 */
} /* line 5262 */
  sim_icache_fetch(3784 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5264 */
} /* line 5264 */
  sim_icache_fetch(3786 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5266 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5267 */
  sim_icache_fetch(3788 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5269 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5270 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5271 */
   __ADD_CYCLES(1);
} /* line 5271 */
  sim_icache_fetch(3792 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5273 */
} /* line 5273 */
  sim_icache_fetch(3793 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5275 */
} /* line 5275 */
  sim_icache_fetch(3795 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5277 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5278 */
  sim_icache_fetch(3797 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5280 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5281 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5282 */
   __ADD_CYCLES(1);
} /* line 5282 */
  sim_icache_fetch(3801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5284 */
} /* line 5284 */
  sim_icache_fetch(3802 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5286 */
} /* line 5286 */
  sim_icache_fetch(3804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5288 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5289 */
  sim_icache_fetch(3806 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5291 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5292 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5293 */
   __ADD_CYCLES(1);
} /* line 5293 */
  sim_icache_fetch(3810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5295 */
} /* line 5295 */
  sim_icache_fetch(3811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5297 */
} /* line 5297 */
  sim_icache_fetch(3813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5299 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5300 */
  sim_icache_fetch(3815 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5302 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5303 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5304 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5305 */
   __ADD_CYCLES(1);
} /* line 5305 */
  sim_icache_fetch(3820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5307 */
} /* line 5307 */
  sim_icache_fetch(3821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5309 */
} /* line 5309 */
  sim_icache_fetch(3823 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5311 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5313 */
  sim_icache_fetch(3825 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L212X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L212X3;
} /* line 5315 */
l_L228X3: ;/* line 5318 */
__LABEL(l_L228X3);
  sim_icache_fetch(3826 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5319 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5320 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5321 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5322 */
l_L231X3: ;/* line 5325 */
__LABEL(l_L231X3);
  sim_icache_fetch(3832 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5326 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5327 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5328 */
} /* line 5328 */
  sim_icache_fetch(3837 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5330 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5331 */
   __GOTO(l_L230X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L230X3;
} /* line 5332 */
l_L227X3: ;/* line 5335 */
__LABEL(l_L227X3);
  sim_icache_fetch(3841 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5336 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5337 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5338 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5339 */
l_L226X3: ;/* line 5342 */
__LABEL(l_L226X3);
  sim_icache_fetch(3847 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5343 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5344 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5345 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5346 */
l_L225X3: ;/* line 5349 */
__LABEL(l_L225X3);
  sim_icache_fetch(3853 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5350 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5351 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5352 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5353 */
l_L224X3: ;/* line 5356 */
__LABEL(l_L224X3);
  sim_icache_fetch(3859 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5357 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5358 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5359 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5360 */
l_L223X3: ;/* line 5363 */
__LABEL(l_L223X3);
  sim_icache_fetch(3865 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5364 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5365 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5366 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5367 */
l_L222X3: ;/* line 5370 */
__LABEL(l_L222X3);
  sim_icache_fetch(3871 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5371 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5372 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5373 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5374 */
l_L221X3: ;/* line 5377 */
__LABEL(l_L221X3);
  sim_icache_fetch(3877 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5378 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5379 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5380 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5381 */
l_L220X3: ;/* line 5384 */
__LABEL(l_L220X3);
  sim_icache_fetch(3883 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5385 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5386 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5387 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5388 */
l_L219X3: ;/* line 5391 */
__LABEL(l_L219X3);
  sim_icache_fetch(3889 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5392 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5393 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5394 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5395 */
l_L218X3: ;/* line 5398 */
__LABEL(l_L218X3);
  sim_icache_fetch(3895 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5399 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5400 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5401 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5402 */
l_L217X3: ;/* line 5405 */
__LABEL(l_L217X3);
  sim_icache_fetch(3901 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5406 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5407 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5408 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5409 */
l_L216X3: ;/* line 5412 */
__LABEL(l_L216X3);
  sim_icache_fetch(3907 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5413 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5414 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5415 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5416 */
l_L215X3: ;/* line 5419 */
__LABEL(l_L215X3);
  sim_icache_fetch(3913 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5420 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5421 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5422 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5423 */
l_L214X3: ;/* line 5426 */
__LABEL(l_L214X3);
  sim_icache_fetch(3919 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5427 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5428 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5429 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 5430 */
l_L213X3: ;/* line 5433 */
__LABEL(l_L213X3);
  sim_icache_fetch(3925 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5434 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5435 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5436 */
} /* line 5436 */
l_L229X3: ;/* line 5438 */
__LABEL(l_L229X3);
  sim_icache_fetch(3930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5438 */
  sim_icache_fetch(3931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5440 */
} /* line 5440 */
  sim_icache_fetch(3932 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5442 */
l_L230X3: ;/* line 5444 */
__LABEL(l_L230X3);
  sim_icache_fetch(3933 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5445 */
   __GOTO(l_L188X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L188X3;
} /* line 5446 */
l_L209X3: ;/* line 5449 */
__LABEL(l_L209X3);
  sim_icache_fetch(3935 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5450 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5451 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5452 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5453 */
l_L208X3: ;/* line 5456 */
__LABEL(l_L208X3);
  sim_icache_fetch(3939 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5457 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5458 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5459 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5460 */
l_L207X3: ;/* line 5463 */
__LABEL(l_L207X3);
  sim_icache_fetch(3943 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5464 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5465 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5466 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5467 */
l_L206X3: ;/* line 5470 */
__LABEL(l_L206X3);
  sim_icache_fetch(3947 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5471 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5472 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5473 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5474 */
l_L205X3: ;/* line 5477 */
__LABEL(l_L205X3);
  sim_icache_fetch(3951 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5478 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5479 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5480 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5481 */
l_L204X3: ;/* line 5484 */
__LABEL(l_L204X3);
  sim_icache_fetch(3955 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5485 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5486 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5487 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5488 */
l_L203X3: ;/* line 5491 */
__LABEL(l_L203X3);
  sim_icache_fetch(3959 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5492 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5493 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5494 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5495 */
l_L202X3: ;/* line 5498 */
__LABEL(l_L202X3);
  sim_icache_fetch(3963 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5499 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5500 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5501 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5502 */
l_L201X3: ;/* line 5505 */
__LABEL(l_L201X3);
  sim_icache_fetch(3967 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5506 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5507 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5508 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5509 */
l_L200X3: ;/* line 5512 */
__LABEL(l_L200X3);
  sim_icache_fetch(3971 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5513 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5514 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5515 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5516 */
l_L199X3: ;/* line 5519 */
__LABEL(l_L199X3);
  sim_icache_fetch(3975 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5520 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5521 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5522 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5523 */
l_L198X3: ;/* line 5526 */
__LABEL(l_L198X3);
  sim_icache_fetch(3979 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5527 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5528 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5529 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5530 */
l_L197X3: ;/* line 5533 */
__LABEL(l_L197X3);
  sim_icache_fetch(3983 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5534 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5535 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5536 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5537 */
l_L196X3: ;/* line 5540 */
__LABEL(l_L196X3);
  sim_icache_fetch(3987 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5541 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5542 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5543 */
   __GOTO(l_L211X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L211X3;
} /* line 5544 */
l_L195X3: ;/* line 5549 */
__LABEL(l_L195X3);
  sim_icache_fetch(3991 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5550 */
} /* line 5550 */
l_L211X3: ;/* line 5552 */
__LABEL(l_L211X3);
  sim_icache_fetch(3992 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5553 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5554 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5555 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5556 */
} /* line 5556 */
  sim_icache_fetch(3997 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5558 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5559 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5560 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5561 */
} /* line 5561 */
  sim_icache_fetch(4001 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5563 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5564 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5565 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5566 */
} /* line 5566 */
  sim_icache_fetch(4005 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5568 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5569 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5570 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5571 */
} /* line 5571 */
  sim_icache_fetch(4009 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5573 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5574 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5575 */
   __GOTO(l_L212X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L212X3;
} /* line 5576 */
l_L193X3: ;/* line 5579 */
__LABEL(l_L193X3);
  sim_icache_fetch(4013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5580 */
   __GOTO(l_L194X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L194X3;
} /* line 5581 */
l_L189X3: ;/* line 5584 */
__LABEL(l_L189X3);
  sim_icache_fetch(4015 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, 0); /* line 5585 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5586 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5587 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5588 */
} /* line 5588 */
  sim_icache_fetch(4019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5590 */
} /* line 5590 */
  sim_icache_fetch(4020 + t_thisfile.offset, 1);
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
    case 351: goto l_L185X3;
    case 352: goto l_L186X3;
    case 354: goto l_lr_253;
    case 355: goto l_L187X3;
    case 356: goto l_L188X3;
    case 358: goto l_lr_257;
    case 359: goto l_L191X3;
    case 360: goto l_L192X3;
    case 362: goto l_lr_261;
    case 363: goto l_L190X3;
    case 364: goto l_L194X3;
    case 365: goto l_L210X3;
    case 366: goto l_L212X3;
    case 367: goto l_L228X3;
    case 368: goto l_L231X3;
    case 369: goto l_L227X3;
    case 370: goto l_L226X3;
    case 371: goto l_L225X3;
    case 372: goto l_L224X3;
    case 373: goto l_L223X3;
    case 374: goto l_L222X3;
    case 375: goto l_L221X3;
    case 376: goto l_L220X3;
    case 377: goto l_L219X3;
    case 378: goto l_L218X3;
    case 379: goto l_L217X3;
    case 380: goto l_L216X3;
    case 381: goto l_L215X3;
    case 382: goto l_L214X3;
    case 383: goto l_L213X3;
    case 384: goto l_L229X3;
    case 385: goto l_L230X3;
    case 386: goto l_L209X3;
    case 387: goto l_L208X3;
    case 388: goto l_L207X3;
    case 389: goto l_L206X3;
    case 390: goto l_L205X3;
    case 391: goto l_L204X3;
    case 392: goto l_L203X3;
    case 393: goto l_L202X3;
    case 394: goto l_L201X3;
    case 395: goto l_L200X3;
    case 396: goto l_L199X3;
    case 397: goto l_L198X3;
    case 398: goto l_L197X3;
    case 399: goto l_L196X3;
    case 400: goto l_L195X3;
    case 401: goto l_L211X3;
    case 402: goto l_L193X3;
    case 403: goto l_L189X3;
    case 404:
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
  reg_l0_0 = (432 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4021 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5612 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5613 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5614 */
} /* line 5614 */
  sim_icache_fetch(4027 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5616 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5617 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5618 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5619 */
} /* line 5619 */
  sim_icache_fetch(4035 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5621 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5622 */
} /* line 5622 */
  sim_icache_fetch(4038 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_r0_11, reg_r0_7, reg_r0_8); /* line 5624 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5625 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5626 */
} /* line 5626 */
  sim_icache_fetch(4041 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5628 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5629 */
} /* line 5629 */
  sim_icache_fetch(4043 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_1, reg_r0_4, reg_r0_11); /* line 5631 */
   __CMPEQ(reg_b0_2, reg_r0_9, reg_r0_2); /* line 5632 */
} /* line 5632 */
  sim_icache_fetch(4045 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5634 */
  sim_icache_fetch(4046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5636 */
  sim_icache_fetch(4047 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5638 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5639 */
  sim_icache_fetch(4050 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5641 */
} /* line 5641 */
l_L233X3: ;/* line 5644 */
__LABEL(l_L233X3);
  sim_icache_fetch(4052 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5645 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5646 */
   __MOV(reg_r0_5, 0); /* line 5647 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5648 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5649 */
   __ADD_CYCLES(1);
} /* line 5649 */
  sim_icache_fetch(4059 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5651 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5652 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5653 */
} /* line 5653 */
  sim_icache_fetch(4062 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5655 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5656 */
l_L236X3: ;/* line 5659 */
__LABEL(l_L236X3);
  sim_icache_fetch(4064 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5660 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5661 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5662 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5663 */
} /* line 5663 */
  sim_icache_fetch(4070 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5665 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5666 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5667 */
  sim_icache_fetch(4073 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5669 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5670 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5671 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5672 */
} /* line 5672 */
  sim_icache_fetch(4077 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5674 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5675 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5676 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5677 */
} /* line 5677 */
  sim_icache_fetch(4082 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5679 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5680 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5681 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5682 */
  sim_icache_fetch(4087 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5684 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5685 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5686 */
} /* line 5686 */
  sim_icache_fetch(4091 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5688 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5689 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5690 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5691 */
} /* line 5691 */
  sim_icache_fetch(4096 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5693 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5694 */
} /* line 5694 */
  sim_icache_fetch(4098 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5696 */
   __ADD(reg_r0_14, reg_r0_8, (unsigned int) 1); /* line 5697 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5698 */
   __ADD(reg_r0_15, reg_r0_13, (unsigned int) 1); /* line 5699 */
} /* line 5699 */
l_L239X3: ;/* line 5701 */
__LABEL(l_L239X3);
  sim_icache_fetch(4102 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5702 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5703 */
   __ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 5704 */
} /* line 5704 */
  sim_icache_fetch(4106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5706 */
} /* line 5706 */
  sim_icache_fetch(4107 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5708 */
} /* line 5708 */
  sim_icache_fetch(4108 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5710 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5711 */
  sim_icache_fetch(4110 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5713 */
   __CMPLT(reg_b0_0, reg_r0_15, 0); /* line 5714 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5715 */
  sim_icache_fetch(4113 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5717 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5718 */
  sim_icache_fetch(4116 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_14); /* line 5720 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5721 */
} /* line 5721 */
  sim_icache_fetch(4120 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5723 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5724 */
} /* line 5724 */
  sim_icache_fetch(4123 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5726 */
} /* line 5726 */
  sim_icache_fetch(4124 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5728 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5729 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5730 */
} /* line 5730 */
l_L242X3: ;/* line 5732 */
__LABEL(l_L242X3);
  sim_icache_fetch(4127 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_14, reg_r0_8); /* line 5733 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5734 */
} /* line 5734 */
  sim_icache_fetch(4130 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5736 */
} /* line 5736 */
  sim_icache_fetch(4131 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_14, (unsigned int) 255); /* line 5738 */
} /* line 5738 */
  sim_icache_fetch(4132 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5740 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5741 */
  sim_icache_fetch(4134 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5743 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5744 */
  sim_icache_fetch(4136 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5746 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L243X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5747 */
  sim_icache_fetch(4139 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5749 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5750 */
} /* line 5750 */
  sim_icache_fetch(4143 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5752 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5753 */
} /* line 5753 */
  sim_icache_fetch(4146 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5755 */
} /* line 5755 */
  sim_icache_fetch(4147 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5757 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5758 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5759 */
} /* line 5759 */
l_L244X3: ;/* line 5761 */
__LABEL(l_L244X3);
  sim_icache_fetch(4150 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5762 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5763 */
} /* line 5763 */
  sim_icache_fetch(4153 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5765 */
} /* line 5765 */
  sim_icache_fetch(4154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5767 */
  sim_icache_fetch(4155 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5769 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5770 */
  sim_icache_fetch(4157 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5772 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5773 */
  sim_icache_fetch(4160 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5775 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5776 */
} /* line 5776 */
  sim_icache_fetch(4164 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5778 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5779 */
} /* line 5779 */
  sim_icache_fetch(4167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5781 */
} /* line 5781 */
  sim_icache_fetch(4168 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5783 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5784 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5785 */
} /* line 5785 */
l_L246X3: ;/* line 5787 */
__LABEL(l_L246X3);
  sim_icache_fetch(4171 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5788 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5789 */
} /* line 5789 */
  sim_icache_fetch(4174 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5791 */
} /* line 5791 */
  sim_icache_fetch(4175 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5793 */
  sim_icache_fetch(4176 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5795 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5796 */
  sim_icache_fetch(4178 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5798 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5799 */
  sim_icache_fetch(4181 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5801 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5802 */
} /* line 5802 */
  sim_icache_fetch(4185 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5804 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5805 */
} /* line 5805 */
  sim_icache_fetch(4188 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5807 */
} /* line 5807 */
  sim_icache_fetch(4189 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5809 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5810 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5811 */
} /* line 5811 */
l_L248X3: ;/* line 5813 */
__LABEL(l_L248X3);
  sim_icache_fetch(4192 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5814 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5815 */
} /* line 5815 */
  sim_icache_fetch(4195 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5817 */
} /* line 5817 */
  sim_icache_fetch(4196 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5819 */
  sim_icache_fetch(4197 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5821 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5822 */
  sim_icache_fetch(4199 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5824 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5825 */
  sim_icache_fetch(4202 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5827 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5828 */
} /* line 5828 */
  sim_icache_fetch(4206 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5830 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5831 */
} /* line 5831 */
  sim_icache_fetch(4209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5833 */
} /* line 5833 */
  sim_icache_fetch(4210 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5835 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5836 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5837 */
} /* line 5837 */
l_L250X3: ;/* line 5839 */
__LABEL(l_L250X3);
  sim_icache_fetch(4213 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5840 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5841 */
} /* line 5841 */
  sim_icache_fetch(4216 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5843 */
} /* line 5843 */
  sim_icache_fetch(4217 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5845 */
  sim_icache_fetch(4218 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5847 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5848 */
  sim_icache_fetch(4220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5850 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5851 */
  sim_icache_fetch(4223 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5853 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5854 */
} /* line 5854 */
  sim_icache_fetch(4227 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5856 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5857 */
} /* line 5857 */
  sim_icache_fetch(4230 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5859 */
} /* line 5859 */
  sim_icache_fetch(4231 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5861 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5862 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5863 */
} /* line 5863 */
l_L252X3: ;/* line 5865 */
__LABEL(l_L252X3);
  sim_icache_fetch(4234 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5866 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5867 */
} /* line 5867 */
  sim_icache_fetch(4237 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5869 */
} /* line 5869 */
  sim_icache_fetch(4238 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5871 */
  sim_icache_fetch(4239 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5873 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5874 */
  sim_icache_fetch(4241 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5876 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5877 */
  sim_icache_fetch(4244 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5879 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5880 */
} /* line 5880 */
  sim_icache_fetch(4248 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5882 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5883 */
} /* line 5883 */
  sim_icache_fetch(4251 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5885 */
} /* line 5885 */
  sim_icache_fetch(4252 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5887 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5888 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5889 */
} /* line 5889 */
l_L254X3: ;/* line 5891 */
__LABEL(l_L254X3);
  sim_icache_fetch(4255 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5892 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5893 */
} /* line 5893 */
  sim_icache_fetch(4258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5895 */
} /* line 5895 */
  sim_icache_fetch(4259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5897 */
  sim_icache_fetch(4260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5899 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5900 */
  sim_icache_fetch(4262 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5902 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L255X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5903 */
  sim_icache_fetch(4265 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5905 */
} /* line 5905 */
  sim_icache_fetch(4267 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5907 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5908 */
   __ADD_CYCLES(1);
} /* line 5908 */
  sim_icache_fetch(4269 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5910 */
} /* line 5910 */
l_L256X3: ;/* line 5912 */
__LABEL(l_L256X3);
  sim_icache_fetch(4270 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5913 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5914 */
} /* line 5914 */
  sim_icache_fetch(4273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5916 */
} /* line 5916 */
  sim_icache_fetch(4274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5918 */
  sim_icache_fetch(4275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5920 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 5921 */
l_L240X3: ;/* line 5924 */
__LABEL(l_L240X3);
  sim_icache_fetch(4277 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5925 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5926 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 5927 */
l_L258X3: ;/* line 5930 */
__LABEL(l_L258X3);
  sim_icache_fetch(4280 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5931 */
   __MOV(reg_r0_7, 0); /* line 5932 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5933 */
} /* line 5933 */
  sim_icache_fetch(4284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5935 */
} /* line 5935 */
  sim_icache_fetch(4285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5937 */
} /* line 5937 */
l_L232X3: ;/* line 5940 */
__LABEL(l_L232X3);
  sim_icache_fetch(4286 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5941 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5942 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5943 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5944 */
} /* line 5944 */
  sim_icache_fetch(4292 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5946 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5947 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5948 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5949 */
} /* line 5949 */
  sim_icache_fetch(4298 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5951 */
   __ADD(reg_r0_11, reg_r0_2, reg_r0_4); /* line 5952 */
   __LDBUs(reg_r0_13, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 5953 */
   __ADD(reg_r0_12, reg_r0_6, (unsigned int) 2); /* line 5954 */
} /* line 5954 */
  sim_icache_fetch(4303 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_7); /* line 5956 */
   __ADD(reg_r0_14, reg_r0_11, (unsigned int) -8); /* line 5957 */
   __ADD(reg_r0_15, reg_r0_11, (unsigned int) -16); /* line 5958 */
} /* line 5958 */
  sim_icache_fetch(4306 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_5, reg_r0_5, reg_r0_4); /* line 5960 */
   __CMPGE(reg_b0_0, reg_r0_14, (unsigned int) 8); /* line 5961 */
   __SHL(reg_r0_13, reg_r0_13, reg_r0_10); /* line 5962 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_2); /* line 5963 */
} /* line 5963 */
  sim_icache_fetch(4311 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_15, reg_b0_0, reg_r0_15, reg_r0_14); /* line 5965 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 5966 */
   __OR(reg_r0_13, reg_r0_5, reg_r0_13); /* line 5967 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, reg_r0_8); /* line 5968 */
} /* line 5968 */
  sim_icache_fetch(4315 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_5); /* line 5970 */
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 5971 */
   __LDBU(reg_r0_15, mem_trace_ld((reg_r0_15 + (unsigned int) rmask),0,1)); /* line 5972 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5973 */
   __ADD_CYCLES(1);
} /* line 5973 */
  sim_icache_fetch(4320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_12, reg_r0_12, reg_r0_15); /* line 5975 */
} /* line 5975 */
  sim_icache_fetch(4321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_12, reg_r0_12, reg_r0_9); /* line 5977 */
} /* line 5977 */
  sim_icache_fetch(4322 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_13, reg_r0_12); /* line 5980 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5981 */
l_L255X3: ;/* line 5984 */
__LABEL(l_L255X3);
  sim_icache_fetch(4324 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5985 */
   __GOTO(l_L256X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L256X3;
} /* line 5986 */
l_L237X3: ;/* line 5989 */
__LABEL(l_L237X3);
  sim_icache_fetch(4326 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 5990 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5991 */
} /* line 5991 */
l_L257X3: ;/* line 5993 */
__LABEL(l_L257X3);
  sim_icache_fetch(4328 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 5994 */
} /* line 5994 */
  sim_icache_fetch(4329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L258X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5996 */
  sim_icache_fetch(4330 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 5999 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 6000 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6001 */
l_L253X3: ;/* line 6004 */
__LABEL(l_L253X3);
  sim_icache_fetch(4335 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6005 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6006 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6007 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6008 */
   __ADD_CYCLES(1);
} /* line 6008 */
  sim_icache_fetch(4341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6010 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6011 */
} /* line 6011 */
  sim_icache_fetch(4343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6013 */
   __GOTO(l_L254X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L254X3;
} /* line 6014 */
l_L251X3: ;/* line 6017 */
__LABEL(l_L251X3);
  sim_icache_fetch(4345 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6018 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6019 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6020 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6021 */
   __ADD_CYCLES(1);
} /* line 6021 */
  sim_icache_fetch(4351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6023 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6024 */
} /* line 6024 */
  sim_icache_fetch(4353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6026 */
   __GOTO(l_L252X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L252X3;
} /* line 6027 */
l_L249X3: ;/* line 6030 */
__LABEL(l_L249X3);
  sim_icache_fetch(4355 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6031 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6032 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6033 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6034 */
   __ADD_CYCLES(1);
} /* line 6034 */
  sim_icache_fetch(4361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6036 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6037 */
} /* line 6037 */
  sim_icache_fetch(4363 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6039 */
   __GOTO(l_L250X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L250X3;
} /* line 6040 */
l_L247X3: ;/* line 6043 */
__LABEL(l_L247X3);
  sim_icache_fetch(4365 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6044 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6045 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6046 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6047 */
   __ADD_CYCLES(1);
} /* line 6047 */
  sim_icache_fetch(4371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6049 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6050 */
} /* line 6050 */
  sim_icache_fetch(4373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6052 */
   __GOTO(l_L248X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L248X3;
} /* line 6053 */
l_L245X3: ;/* line 6056 */
__LABEL(l_L245X3);
  sim_icache_fetch(4375 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6057 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6058 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6059 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6060 */
   __ADD_CYCLES(1);
} /* line 6060 */
  sim_icache_fetch(4381 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6062 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6063 */
} /* line 6063 */
  sim_icache_fetch(4383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6065 */
   __GOTO(l_L246X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L246X3;
} /* line 6066 */
l_L243X3: ;/* line 6069 */
__LABEL(l_L243X3);
  sim_icache_fetch(4385 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6070 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6071 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6072 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6073 */
   __ADD_CYCLES(1);
} /* line 6073 */
  sim_icache_fetch(4391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6075 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6076 */
} /* line 6076 */
  sim_icache_fetch(4393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6078 */
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 6079 */
l_L241X3: ;/* line 6082 */
__LABEL(l_L241X3);
  sim_icache_fetch(4395 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6083 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6084 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6085 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6086 */
   __ADD_CYCLES(1);
} /* line 6086 */
  sim_icache_fetch(4401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_14, (unsigned int) -1); /* line 6088 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6089 */
} /* line 6089 */
  sim_icache_fetch(4403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6091 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 6092 */
l_L238X3: ;/* line 6095 */
__LABEL(l_L238X3);
  sim_icache_fetch(4405 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6096 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6097 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6098 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6099 */
} /* line 6099 */
  sim_icache_fetch(4410 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6101 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6102 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6103 */
} /* line 6103 */
  sim_icache_fetch(4413 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6105 */
   __ADD(reg_r0_14, reg_r0_8, (unsigned int) 1); /* line 6106 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6107 */
   __ADD(reg_r0_15, reg_r0_13, (unsigned int) 1); /* line 6109 */
} /* line 6109 */
  sim_icache_fetch(4417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L239X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L239X3;
} /* line 6111 */
l_L235X3: ;/* line 6114 */
__LABEL(l_L235X3);
  sim_icache_fetch(4418 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6115 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6116 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6117 */
} /* line 6117 */
  sim_icache_fetch(4423 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6119 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6120 */
} /* line 6120 */
  sim_icache_fetch(4427 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6122 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6123 */
   __ADD_CYCLES(1);
} /* line 6123 */
  sim_icache_fetch(4430 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6125 */
} /* line 6125 */
  sim_icache_fetch(4431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6127 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 6128 */
l_L234X3: ;/* line 6131 */
__LABEL(l_L234X3);
  sim_icache_fetch(4433 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6132 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6133 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6134 */
   __ADD_CYCLES(1);
} /* line 6134 */
  sim_icache_fetch(4437 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6136 */
} /* line 6136 */
  sim_icache_fetch(4438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6138 */
} /* line 6138 */
  sim_icache_fetch(4439 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6140 */
   __GOTO(l_L233X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L233X3;
} /* line 6141 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 405: goto l_L233X3;
    case 406: goto l_L236X3;
    case 407: goto l_L239X3;
    case 408: goto l_L242X3;
    case 409: goto l_L244X3;
    case 410: goto l_L246X3;
    case 411: goto l_L248X3;
    case 412: goto l_L250X3;
    case 413: goto l_L252X3;
    case 414: goto l_L254X3;
    case 415: goto l_L256X3;
    case 416: goto l_L240X3;
    case 417: goto l_L258X3;
    case 418: goto l_L232X3;
    case 419: goto l_L255X3;
    case 420: goto l_L237X3;
    case 421: goto l_L257X3;
    case 422: goto l_L253X3;
    case 423: goto l_L251X3;
    case 424: goto l_L249X3;
    case 425: goto l_L247X3;
    case 426: goto l_L245X3;
    case 427: goto l_L243X3;
    case 428: goto l_L241X3;
    case 429: goto l_L238X3;
    case 430: goto l_L235X3;
    case 431: goto l_L234X3;
    case 432:
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
  reg_l0_0 = (435 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4442 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6163 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6164 */
} /* line 6164 */
		 /* line 6165 */
  sim_icache_fetch(4445 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6168 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (435 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6168 */
l_lr_333: ;/* line 6168 */
__LABEL(l_lr_333);
  sim_icache_fetch(4448 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6170 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6171 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6172 */
   __ADD_CYCLES(1);
} /* line 6172 */
  sim_icache_fetch(4451 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6175 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 434: goto l_lr_333;
    case 435:
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
  reg_l0_0 = (437 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4452 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6221 */
   __MOV(reg_r0_3, 0); /* line 6222 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6223 */
   __ADD_CYCLES(1);
} /* line 6223 */
  sim_icache_fetch(4456 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6225 */
} /* line 6225 */
  sim_icache_fetch(4457 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L259X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6227 */
  sim_icache_fetch(4458 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6230 */
l_L259X3: ;/* line 6233 */
__LABEL(l_L259X3);
  sim_icache_fetch(4459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6236 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6236 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 436: goto l_L259X3;
    case 437:
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
  reg_l0_0 = (438 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4461 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6252 */
} /* line 6252 */
  sim_icache_fetch(4462 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6255 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 438:
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
  reg_l0_0 = (442 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4463 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6270 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6271 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6272 */
} /* line 6272 */
  sim_icache_fetch(4468 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6274 */
} /* line 6274 */
  sim_icache_fetch(4469 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6276 */
} /* line 6276 */
  sim_icache_fetch(4470 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L260X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6278 */
		 /* line 6279 */
  sim_icache_fetch(4471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
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
} /* line 6281 */
l_lr_339: ;/* line 6281 */
__LABEL(l_lr_339);
l_L260X3: ;/* line 6283 */
__LABEL(l_L260X3);
  sim_icache_fetch(4473 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6284 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6285 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6286 */
   __ADD_CYCLES(1);
} /* line 6286 */
  sim_icache_fetch(4476 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6289 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 440: goto l_lr_339;
    case 441: goto l_L260X3;
    case 442:
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
  reg_l0_0 = (455 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4477 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6335 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6336 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6337 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6338 */
} /* line 6338 */
  sim_icache_fetch(4484 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6340 */
} /* line 6340 */
  sim_icache_fetch(4485 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6342 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6343 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6344 */
} /* line 6344 */
  sim_icache_fetch(4490 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6346 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6347 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L261X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6348 */
  sim_icache_fetch(4494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6350 */
l_L263X3: ;/* line 6353 */
__LABEL(l_L263X3);
  sim_icache_fetch(4495 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6354 */
   __MOV(reg_r0_3, 0); /* line 6355 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6356 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6357 */
   __ADD_CYCLES(1);
} /* line 6357 */
  sim_icache_fetch(4500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6359 */
} /* line 6359 */
  sim_icache_fetch(4501 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L264X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6361 */
  sim_icache_fetch(4502 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6364 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6365 */
l_L264X3: ;/* line 6368 */
__LABEL(l_L264X3);
  sim_icache_fetch(4505 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6369 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6370 */
} /* line 6370 */
		 /* line 6371 */
  sim_icache_fetch(4509 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (455 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6373 */
l_lr_345: ;/* line 6373 */
__LABEL(l_lr_345);
  sim_icache_fetch(4511 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6375 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6376 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6377 */
} /* line 6377 */
		 /* line 6378 */
  sim_icache_fetch(4516 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6380 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6381 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (455 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6382 */
l_lr_347: ;/* line 6382 */
__LABEL(l_lr_347);
  sim_icache_fetch(4522 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6384 */
   __MOV(reg_r0_3, 0); /* line 6385 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6386 */
   __ADD_CYCLES(1);
} /* line 6386 */
  sim_icache_fetch(4525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6389 */
l_L262X3: ;/* line 6392 */
__LABEL(l_L262X3);
  sim_icache_fetch(4526 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6393 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6394 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6395 */
   __ADD_CYCLES(1);
} /* line 6395 */
		 /* line 6396 */
  sim_icache_fetch(4530 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6399 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (455 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6399 */
l_lr_350: ;/* line 6399 */
__LABEL(l_lr_350);
  sim_icache_fetch(4533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6401 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 6402 */
l_L261X3: ;/* line 6405 */
__LABEL(l_L261X3);
  sim_icache_fetch(4535 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6406 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6407 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6408 */
   __ADD_CYCLES(1);
} /* line 6408 */
		 /* line 6409 */
  sim_icache_fetch(4540 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6411 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (455 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6412 */
l_lr_353: ;/* line 6412 */
__LABEL(l_lr_353);
  sim_icache_fetch(4543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6414 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 6415 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 443: goto l_L263X3;
    case 444: goto l_L264X3;
    case 446: goto l_lr_345;
    case 448: goto l_lr_347;
    case 449: goto l_L262X3;
    case 451: goto l_lr_350;
    case 452: goto l_L261X3;
    case 454: goto l_lr_353;
    case 455:
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
  reg_l0_0 = (473 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4545 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6434 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6435 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6436 */
} /* line 6436 */
  sim_icache_fetch(4549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6438 */
} /* line 6438 */
l_L265X3: ;/* line 6441 */
__LABEL(l_L265X3);
  sim_icache_fetch(4550 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_2); /* line 6442 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6443 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6444 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6445 */
} /* line 6445 */
  sim_icache_fetch(4554 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6447 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6448 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6449 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6450 */
} /* line 6450 */
  sim_icache_fetch(4558 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6452 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6453 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6454 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6455 */
} /* line 6455 */
  sim_icache_fetch(4562 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6457 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6458 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6459 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6460 */
} /* line 6460 */
  sim_icache_fetch(4566 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6462 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6463 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6464 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6465 */
} /* line 6465 */
  sim_icache_fetch(4570 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6467 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6468 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6469 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6470 */
} /* line 6470 */
  sim_icache_fetch(4574 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6472 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6473 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6474 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L266X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6475 */
  sim_icache_fetch(4578 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6477 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6478 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6479 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6480 */
} /* line 6480 */
  sim_icache_fetch(4582 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6482 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6483 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6484 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6485 */
} /* line 6485 */
  sim_icache_fetch(4586 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6487 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6488 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6489 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6490 */
} /* line 6490 */
  sim_icache_fetch(4590 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6492 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6493 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6494 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6495 */
} /* line 6495 */
  sim_icache_fetch(4594 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6497 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L267X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6498 */
  sim_icache_fetch(4596 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6500 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6501 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6502 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6503 */
} /* line 6503 */
  sim_icache_fetch(4600 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6506 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6507 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6508 */
} /* line 6508 */
  sim_icache_fetch(4604 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6510 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6511 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6512 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6513 */
} /* line 6513 */
  sim_icache_fetch(4608 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6515 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6516 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6517 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6518 */
} /* line 6518 */
  sim_icache_fetch(4612 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6520 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6521 */
  sim_icache_fetch(4614 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6523 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6525 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6526 */
} /* line 6526 */
  sim_icache_fetch(4618 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6528 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6529 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6531 */
} /* line 6531 */
  sim_icache_fetch(4622 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6533 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6534 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6535 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6536 */
} /* line 6536 */
  sim_icache_fetch(4626 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6538 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6539 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6540 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6541 */
} /* line 6541 */
  sim_icache_fetch(4630 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6543 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L269X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6544 */
  sim_icache_fetch(4632 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6546 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6547 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6548 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6549 */
} /* line 6549 */
  sim_icache_fetch(4636 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6551 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6552 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6553 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6554 */
} /* line 6554 */
  sim_icache_fetch(4640 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6556 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6557 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6558 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6559 */
} /* line 6559 */
  sim_icache_fetch(4644 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6561 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6562 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6564 */
} /* line 6564 */
  sim_icache_fetch(4648 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6567 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L270X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6568 */
  sim_icache_fetch(4651 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6570 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6571 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6572 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6573 */
} /* line 6573 */
  sim_icache_fetch(4659 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6575 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6576 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6577 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6578 */
} /* line 6578 */
  sim_icache_fetch(4667 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6580 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6581 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6582 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6583 */
} /* line 6583 */
  sim_icache_fetch(4675 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6588 */
} /* line 6588 */
  sim_icache_fetch(4683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L271X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6590 */
  sim_icache_fetch(4684 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6592 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6593 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6594 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6595 */
} /* line 6595 */
  sim_icache_fetch(4692 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6597 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6600 */
} /* line 6600 */
  sim_icache_fetch(4700 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6602 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6604 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6605 */
} /* line 6605 */
  sim_icache_fetch(4708 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6608 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6610 */
} /* line 6610 */
  sim_icache_fetch(4716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L272X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6612 */
  sim_icache_fetch(4717 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6614 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6615 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6616 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6617 */
} /* line 6617 */
  sim_icache_fetch(4725 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6620 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6621 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6622 */
} /* line 6622 */
  sim_icache_fetch(4733 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6624 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6625 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6626 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6627 */
} /* line 6627 */
  sim_icache_fetch(4741 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6629 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6630 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6631 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6632 */
} /* line 6632 */
  sim_icache_fetch(4749 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L273X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6634 */
  sim_icache_fetch(4750 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6636 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6637 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6639 */
} /* line 6639 */
  sim_icache_fetch(4758 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6641 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6642 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6644 */
} /* line 6644 */
  sim_icache_fetch(4766 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6646 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6647 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6648 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6649 */
} /* line 6649 */
  sim_icache_fetch(4774 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6651 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6652 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6653 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6654 */
} /* line 6654 */
  sim_icache_fetch(4782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6656 */
  sim_icache_fetch(4783 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6658 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6659 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6660 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6661 */
} /* line 6661 */
  sim_icache_fetch(4791 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6664 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6665 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6666 */
} /* line 6666 */
  sim_icache_fetch(4799 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6668 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6669 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6670 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6671 */
} /* line 6671 */
  sim_icache_fetch(4807 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6673 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6674 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6675 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6676 */
} /* line 6676 */
  sim_icache_fetch(4815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L275X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6678 */
  sim_icache_fetch(4816 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6680 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6681 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6682 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6683 */
} /* line 6683 */
  sim_icache_fetch(4824 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6685 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6686 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6687 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6688 */
} /* line 6688 */
  sim_icache_fetch(4832 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6690 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6691 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6692 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6693 */
} /* line 6693 */
  sim_icache_fetch(4840 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6695 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6696 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6697 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6698 */
} /* line 6698 */
  sim_icache_fetch(4848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L276X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6700 */
  sim_icache_fetch(4849 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6702 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6703 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6704 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6705 */
} /* line 6705 */
  sim_icache_fetch(4857 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6707 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6708 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6709 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6710 */
} /* line 6710 */
  sim_icache_fetch(4865 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6712 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6713 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6714 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6715 */
} /* line 6715 */
  sim_icache_fetch(4873 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6717 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6718 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6719 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6720 */
} /* line 6720 */
  sim_icache_fetch(4881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L277X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6722 */
  sim_icache_fetch(4882 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6724 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6725 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6726 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6727 */
} /* line 6727 */
  sim_icache_fetch(4889 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6729 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6730 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6731 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6732 */
} /* line 6732 */
  sim_icache_fetch(4896 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6734 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6735 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6736 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6737 */
} /* line 6737 */
  sim_icache_fetch(4904 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6739 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6740 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6741 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6742 */
} /* line 6742 */
  sim_icache_fetch(4912 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6744 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6745 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6746 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6747 */
} /* line 6747 */
  sim_icache_fetch(4920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L278X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6750 */
  sim_icache_fetch(4921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L265X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L265X3;
} /* line 6752 */
l_L278X3: ;/* line 6755 */
__LABEL(l_L278X3);
  sim_icache_fetch(4922 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6756 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6757 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6758 */
l_L280X3: ;/* line 6761 */
__LABEL(l_L280X3);
  sim_icache_fetch(4926 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6762 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6763 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6764 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6765 */
} /* line 6765 */
  sim_icache_fetch(4930 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 3); /* line 6767 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 4); /* line 6768 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 5); /* line 6769 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6770 */
  sim_icache_fetch(4934 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 6); /* line 6772 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 7); /* line 6773 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 8); /* line 6774 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6775 */
} /* line 6775 */
  sim_icache_fetch(4938 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6777 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6778 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6779 */
  sim_icache_fetch(4941 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6781 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6782 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6783 */
  sim_icache_fetch(4944 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6785 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6786 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6787 */
  sim_icache_fetch(4947 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6789 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 11); /* line 6790 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6791 */
  sim_icache_fetch(4950 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6793 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 12); /* line 6794 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6795 */
  sim_icache_fetch(4953 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6797 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 13); /* line 6798 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6799 */
  sim_icache_fetch(4956 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6801 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 14); /* line 6802 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6803 */
  sim_icache_fetch(4959 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6805 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 15); /* line 6806 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6807 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6808 */
  sim_icache_fetch(4963 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6810 */
   __CMPGT(reg_b0_7, reg_r0_5, 0); /* line 6811 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6812 */
  sim_icache_fetch(4966 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6814 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6815 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6816 */
  sim_icache_fetch(4969 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6818 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6819 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6820 */
  sim_icache_fetch(4972 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6822 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 6823 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6824 */
  sim_icache_fetch(4975 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6826 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 6827 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6828 */
  sim_icache_fetch(4978 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6830 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 6831 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6832 */
  sim_icache_fetch(4981 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6834 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 6835 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6836 */
  sim_icache_fetch(4984 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6838 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 6839 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6840 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6841 */
  sim_icache_fetch(4988 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6843 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 6844 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6845 */
  sim_icache_fetch(4991 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6847 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6848 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6849 */
  sim_icache_fetch(4994 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6851 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6852 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6853 */
  sim_icache_fetch(4997 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6855 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 11); /* line 6856 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6857 */
  sim_icache_fetch(5000 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6859 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 6860 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6861 */
  sim_icache_fetch(5003 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6863 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 6864 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6865 */
  sim_icache_fetch(5006 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6867 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 6868 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6869 */
  sim_icache_fetch(5009 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6871 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 6872 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6873 */
  sim_icache_fetch(5012 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6875 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6876 */
  sim_icache_fetch(5014 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6878 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6879 */
  sim_icache_fetch(5016 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6881 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6882 */
  sim_icache_fetch(5018 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6884 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6885 */
  sim_icache_fetch(5020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6887 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6888 */
  sim_icache_fetch(5022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6890 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6891 */
  sim_icache_fetch(5024 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6893 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6894 */
  sim_icache_fetch(5026 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6896 */
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 6897 */
l_L281X3: ;/* line 6900 */
__LABEL(l_L281X3);
  sim_icache_fetch(5028 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6902 */
l_L277X3: ;/* line 6905 */
__LABEL(l_L277X3);
  sim_icache_fetch(5029 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6906 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6907 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6908 */
l_L276X3: ;/* line 6911 */
__LABEL(l_L276X3);
  sim_icache_fetch(5033 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6912 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6913 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6914 */
l_L275X3: ;/* line 6917 */
__LABEL(l_L275X3);
  sim_icache_fetch(5037 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6918 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6919 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6920 */
l_L274X3: ;/* line 6923 */
__LABEL(l_L274X3);
  sim_icache_fetch(5041 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6924 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6925 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6926 */
l_L273X3: ;/* line 6929 */
__LABEL(l_L273X3);
  sim_icache_fetch(5045 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6930 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6931 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6932 */
l_L272X3: ;/* line 6935 */
__LABEL(l_L272X3);
  sim_icache_fetch(5049 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6936 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6937 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6938 */
l_L271X3: ;/* line 6941 */
__LABEL(l_L271X3);
  sim_icache_fetch(5053 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6942 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6943 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6944 */
l_L270X3: ;/* line 6947 */
__LABEL(l_L270X3);
  sim_icache_fetch(5057 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6948 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6949 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6950 */
l_L269X3: ;/* line 6953 */
__LABEL(l_L269X3);
  sim_icache_fetch(5061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6954 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6955 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6956 */
l_L268X3: ;/* line 6959 */
__LABEL(l_L268X3);
  sim_icache_fetch(5064 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6960 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6961 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6962 */
l_L267X3: ;/* line 6965 */
__LABEL(l_L267X3);
  sim_icache_fetch(5067 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6966 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6967 */
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6968 */
l_L266X3: ;/* line 6971 */
__LABEL(l_L266X3);
  sim_icache_fetch(5070 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6972 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6973 */
} /* line 6973 */
l_L279X3: ;/* line 6975 */
__LABEL(l_L279X3);
  sim_icache_fetch(5072 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6976 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6977 */
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 6978 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 456: goto l_L265X3;
    case 457: goto l_L278X3;
    case 458: goto l_L280X3;
    case 459: goto l_L281X3;
    case 460: goto l_L277X3;
    case 461: goto l_L276X3;
    case 462: goto l_L275X3;
    case 463: goto l_L274X3;
    case 464: goto l_L273X3;
    case 465: goto l_L272X3;
    case 466: goto l_L271X3;
    case 467: goto l_L270X3;
    case 468: goto l_L269X3;
    case 469: goto l_L268X3;
    case 470: goto l_L267X3;
    case 471: goto l_L266X3;
    case 472: goto l_L279X3;
    case 473:
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
  reg_l0_0 = (474 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5075 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6994 */
} /* line 6994 */
  sim_icache_fetch(5076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6997 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 474:
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
  reg_l0_0 = (475 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7013 */
} /* line 7013 */
  sim_icache_fetch(5078 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7016 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 475:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 5088, 0, 0, 0, 2};

