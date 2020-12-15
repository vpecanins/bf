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

static unsigned int _X1PACKETX15[3];
unsigned int compress_11357Xoffset[1];
unsigned int compress_11357Xbuf[3];
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
unsigned int compress_11357XBuf[216]; 
unsigned int compress_11357Xrcs_ident[6]; 
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
	(146 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(160 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(152 << 5),
	(151 << 5),
	(150 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(149 << 5),
	(164 << 5),
	(164 << 5),
	(148 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(164 << 5),
	(147 << 5)
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

unsigned int compress_11357XBuf[216] = { 
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

unsigned int compress_11357Xrcs_ident[6] = { 
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
   __MOV(reg_r0_5, (unsigned int) compress_11357XBuf); /* line 35 */
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
  reg_l0_0 = (141 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_27, reg_r0_3, (unsigned int) 15); /* line 178 */
   __ADD(reg_r0_26, reg_r0_3, (unsigned int) 14); /* line 179 */
   __ADD(reg_r0_25, reg_r0_3, (unsigned int) 13); /* line 180 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 12); /* line 181 */
   __ADD(reg_r0_23, reg_r0_3, (unsigned int) 11); /* line 182 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 10); /* line 183 */
   __ADD(reg_r0_21, reg_r0_3, (unsigned int) 9); /* line 184 */
} /* line 184 */
  sim_icache_fetch(51 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 186 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 187 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 8); /* line 188 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 7); /* line 189 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 6); /* line 190 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 191 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 192 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 193 */
} /* line 193 */
  sim_icache_fetch(59 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SXTB(reg_r0_4, reg_r0_4); /* line 195 */
   __MOV(reg_r0_5, 0); /* line 196 */
   __MOV(reg_r0_2, reg_r0_3); /* line 197 */
} /* line 197 */
l_L0X3: ;/* line 200 */
__LABEL(l_L0X3);
  sim_icache_fetch(62 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 201 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 202 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 203 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_10,0,1)); /* line 204 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_12,0,1)); /* line 205 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_14,0,1)); /* line 206 */
   __LDBs(reg_r0_17, mem_trace_ld(reg_r0_16,0,1)); /* line 207 */
   __LDBs(reg_r0_19, mem_trace_ld(reg_r0_18,0,1)); /* line 208 */
} /* line 208 */
  sim_icache_fetch(70 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDBs(reg_r0_28, mem_trace_ld(reg_r0_20,0,1)); /* line 210 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_21,0,1)); /* line 211 */
   __LDBs(reg_r0_30, mem_trace_ld(reg_r0_22,0,1)); /* line 212 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_23,0,1)); /* line 213 */
   __LDBs(reg_r0_32, mem_trace_ld(reg_r0_24,0,1)); /* line 214 */
   __LDBs(reg_r0_33, mem_trace_ld(reg_r0_25,0,1)); /* line 215 */
   __LDBs(reg_r0_34, mem_trace_ld(reg_r0_26,0,1)); /* line 216 */
   __LDBs(reg_r0_35, mem_trace_ld(reg_r0_27,0,1)); /* line 217 */
} /* line 217 */
  sim_icache_fetch(78 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 219 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 220 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 221 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 222 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 223 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 224 */
   __CMPNE(reg_b0_6, reg_r0_11, 0); /* line 225 */
   __CMPEQ(reg_b0_7, reg_r0_11, reg_r0_4); /* line 226 */
} /* line 226 */
  sim_icache_fetch(86 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 228 */
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 229 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 230 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 16); /* line 231 */
   __ADD(reg_r0_9, reg_r0_26, (unsigned int) 16); /* line 232 */
   __ADD(reg_r0_11, reg_r0_25, (unsigned int) 16); /* line 233 */
   __ADD(reg_r0_13, reg_r0_24, (unsigned int) 16); /* line 234 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 235 */
  sim_icache_fetch(94 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_6, reg_b0_3, reg_r0_6, reg_r0_3); /* line 237 */
   __CMPNE(reg_b0_2, reg_r0_15, 0); /* line 238 */
   __CMPEQ(reg_b0_3, reg_r0_15, reg_r0_4); /* line 239 */
   __ADD(reg_r0_15, reg_r0_23, (unsigned int) 16); /* line 240 */
   __ADD(reg_r0_36, reg_r0_22, (unsigned int) 16); /* line 241 */
   __ADD(reg_r0_37, reg_r0_21, (unsigned int) 16); /* line 242 */
   __ADD(reg_r0_38, reg_r0_20, (unsigned int) 16); /* line 243 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 244 */
  sim_icache_fetch(102 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_3, reg_b0_5, reg_r0_8, reg_r0_6); /* line 246 */
   __CMPNE(reg_b0_4, reg_r0_17, 0); /* line 247 */
   __CMPEQ(reg_b0_5, reg_r0_17, reg_r0_4); /* line 248 */
   __ADD(reg_r0_17, reg_r0_18, (unsigned int) 16); /* line 249 */
   __ADD(reg_r0_39, reg_r0_16, (unsigned int) 16); /* line 250 */
   __ADD(reg_r0_40, reg_r0_14, (unsigned int) 16); /* line 251 */
   __ADD(reg_r0_41, reg_r0_12, (unsigned int) 16); /* line 252 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 253 */
  sim_icache_fetch(110 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_42, reg_b0_7, reg_r0_10, reg_r0_3); /* line 255 */
   __CMPNE(reg_b0_6, reg_r0_19, 0); /* line 256 */
   __CMPEQ(reg_b0_7, reg_r0_19, reg_r0_4); /* line 257 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 258 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 259 */
   __ADD(reg_r0_19, reg_r0_27, (unsigned int) 16); /* line 260 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 261 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 262 */
  sim_icache_fetch(118 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, reg_r0_42); /* line 264 */
   __CMPNE(reg_b0_0, reg_r0_28, 0); /* line 265 */
   __CMPEQ(reg_b0_1, reg_r0_28, reg_r0_4); /* line 266 */
   __LDBs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 267 */
   __LDBs(reg_r0_28, mem_trace_ld(reg_r0_7,0,1)); /* line 268 */
   __LDBs(reg_r0_43, mem_trace_ld(reg_r0_8,0,1)); /* line 269 */
   __LDBs(reg_r0_44, mem_trace_ld(reg_r0_10,0,1)); /* line 270 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 271 */
  sim_icache_fetch(126 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_14, reg_b0_3, reg_r0_14, reg_r0_12); /* line 273 */
   __CMPNE(reg_b0_2, reg_r0_29, 0); /* line 274 */
   __CMPEQ(reg_b0_3, reg_r0_29, reg_r0_4); /* line 275 */
   __LDBs(reg_r0_29, mem_trace_ld(reg_r0_41,0,1)); /* line 276 */
   __LDBs(reg_r0_42, mem_trace_ld(reg_r0_40,0,1)); /* line 277 */
   __LDBs(reg_r0_45, mem_trace_ld(reg_r0_39,0,1)); /* line 278 */
   __LDBs(reg_r0_46, mem_trace_ld(reg_r0_17,0,1)); /* line 279 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 280 */
  sim_icache_fetch(134 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_16, reg_b0_5, reg_r0_16, reg_r0_14); /* line 282 */
   __CMPNE(reg_b0_4, reg_r0_30, 0); /* line 283 */
   __CMPEQ(reg_b0_5, reg_r0_30, reg_r0_4); /* line 284 */
   __LDBs(reg_r0_30, mem_trace_ld(reg_r0_38,0,1)); /* line 285 */
   __LDBs(reg_r0_47, mem_trace_ld(reg_r0_37,0,1)); /* line 286 */
   __LDBs(reg_r0_48, mem_trace_ld(reg_r0_36,0,1)); /* line 287 */
   __LDBs(reg_r0_49, mem_trace_ld(reg_r0_15,0,1)); /* line 288 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 289 */
  sim_icache_fetch(142 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_18, reg_b0_7, reg_r0_18, reg_r0_16); /* line 291 */
   __CMPNE(reg_b0_6, reg_r0_31, 0); /* line 292 */
   __CMPEQ(reg_b0_7, reg_r0_31, reg_r0_4); /* line 293 */
   __LDBs(reg_r0_31, mem_trace_ld(reg_r0_13,0,1)); /* line 294 */
   __LDBs(reg_r0_50, mem_trace_ld(reg_r0_11,0,1)); /* line 295 */
   __LDBs(reg_r0_51, mem_trace_ld(reg_r0_9,0,1)); /* line 296 */
   __LDBs(reg_r0_52, mem_trace_ld(reg_r0_19,0,1)); /* line 297 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 298 */
  sim_icache_fetch(150 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_20, reg_b0_1, reg_r0_20, reg_r0_18); /* line 300 */
   __CMPNE(reg_b0_0, reg_r0_32, 0); /* line 301 */
   __CMPEQ(reg_b0_1, reg_r0_32, reg_r0_4); /* line 302 */
   __ADD(reg_r0_16, reg_r0_39, (unsigned int) 16); /* line 303 */
   __ADD(reg_r0_14, reg_r0_40, (unsigned int) 16); /* line 304 */
   __ADD(reg_r0_12, reg_r0_41, (unsigned int) 16); /* line 305 */
   __ADD(reg_r0_32, reg_r0_8, (unsigned int) 16); /* line 306 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 307 */
  sim_icache_fetch(158 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SLCT(reg_r0_21, reg_b0_3, reg_r0_21, reg_r0_20); /* line 309 */
   __CMPNE(reg_b0_2, reg_r0_33, 0); /* line 310 */
   __CMPEQ(reg_b0_3, reg_r0_33, reg_r0_4); /* line 311 */
   __ADD(reg_r0_6, reg_r0_7, (unsigned int) 16); /* line 312 */
   __ADD(reg_r0_18, reg_r0_17, (unsigned int) 16); /* line 313 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 314 */
   __ADD(reg_r0_53, reg_r0_2, (unsigned int) 16); /* line 315 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 316 */
  sim_icache_fetch(166 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_22, reg_b0_5, reg_r0_22, reg_r0_21); /* line 318 */
   __CMPNE(reg_b0_4, reg_r0_34, 0); /* line 319 */
   __CMPEQ(reg_b0_5, reg_r0_34, reg_r0_4); /* line 320 */
   __ADD(reg_r0_20, reg_r0_38, (unsigned int) 16); /* line 321 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 322 */
  sim_icache_fetch(171 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_23, reg_b0_7, reg_r0_23, reg_r0_22); /* line 324 */
   __CMPNE(reg_b0_6, reg_r0_35, 0); /* line 325 */
   __CMPEQ(reg_b0_7, reg_r0_35, reg_r0_4); /* line 326 */
   __ADD(reg_r0_21, reg_r0_37, (unsigned int) 16); /* line 327 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 328 */
  sim_icache_fetch(176 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_24, reg_b0_1, reg_r0_24, reg_r0_23); /* line 330 */
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 331 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 332 */
   __ADD(reg_r0_22, reg_r0_36, (unsigned int) 16); /* line 333 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 334 */
  sim_icache_fetch(181 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_25, reg_b0_3, reg_r0_25, reg_r0_24); /* line 336 */
   __CMPNE(reg_b0_2, reg_r0_28, 0); /* line 337 */
   __CMPEQ(reg_b0_3, reg_r0_28, reg_r0_4); /* line 338 */
   __ADD(reg_r0_23, reg_r0_15, (unsigned int) 16); /* line 339 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 340 */
  sim_icache_fetch(186 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_26, reg_b0_5, reg_r0_26, reg_r0_25); /* line 342 */
   __CMPNE(reg_b0_4, reg_r0_43, 0); /* line 343 */
   __CMPEQ(reg_b0_5, reg_r0_43, reg_r0_4); /* line 344 */
   __ADD(reg_r0_24, reg_r0_13, (unsigned int) 16); /* line 345 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 346 */
  sim_icache_fetch(191 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_27, reg_r0_26); /* line 348 */
   __CMPNE(reg_b0_6, reg_r0_44, 0); /* line 349 */
   __CMPEQ(reg_b0_7, reg_r0_44, reg_r0_4); /* line 350 */
   __ADD(reg_r0_25, reg_r0_11, (unsigned int) 16); /* line 351 */
   __ADD(reg_r0_27, reg_r0_19, (unsigned int) 16); /* line 352 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 353 */
  sim_icache_fetch(197 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 355 */
   __CMPNE(reg_b0_0, reg_r0_29, 0); /* line 356 */
   __CMPEQ(reg_b0_1, reg_r0_29, reg_r0_4); /* line 357 */
   __ADD(reg_r0_26, reg_r0_9, (unsigned int) 16); /* line 358 */
   __MOV(reg_r0_2, reg_r0_53); /* line 359 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 360 */
  sim_icache_fetch(203 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_7, reg_r0_3); /* line 362 */
   __CMPNE(reg_b0_2, reg_r0_42, 0); /* line 363 */
   __CMPEQ(reg_b0_3, reg_r0_42, reg_r0_4); /* line 364 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 365 */
  sim_icache_fetch(207 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_3, reg_b0_5, reg_r0_8, reg_r0_7); /* line 367 */
   __CMPNE(reg_b0_4, reg_r0_45, 0); /* line 368 */
   __CMPEQ(reg_b0_5, reg_r0_45, reg_r0_4); /* line 369 */
   __MOV(reg_r0_8, reg_r0_32); /* line 370 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 371 */
  sim_icache_fetch(212 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_42, reg_b0_7, reg_r0_10, reg_r0_3); /* line 373 */
   __CMPNE(reg_b0_6, reg_r0_46, 0); /* line 374 */
   __CMPEQ(reg_b0_7, reg_r0_46, reg_r0_4); /* line 375 */
   __MOV(reg_r0_10, reg_r0_33); /* line 376 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 377 */
  sim_icache_fetch(217 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_41, reg_b0_1, reg_r0_41, reg_r0_42); /* line 379 */
   __CMPNE(reg_b0_0, reg_r0_30, 0); /* line 380 */
   __CMPEQ(reg_b0_1, reg_r0_30, reg_r0_4); /* line 381 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 382 */
  sim_icache_fetch(221 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_40, reg_b0_3, reg_r0_40, reg_r0_41); /* line 384 */
   __CMPNE(reg_b0_2, reg_r0_47, 0); /* line 385 */
   __CMPEQ(reg_b0_3, reg_r0_47, reg_r0_4); /* line 386 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 387 */
  sim_icache_fetch(225 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_39, reg_b0_5, reg_r0_39, reg_r0_40); /* line 389 */
   __CMPNE(reg_b0_4, reg_r0_48, 0); /* line 390 */
   __CMPEQ(reg_b0_5, reg_r0_48, reg_r0_4); /* line 391 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 392 */
  sim_icache_fetch(229 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_17, reg_b0_7, reg_r0_17, reg_r0_39); /* line 394 */
   __CMPNE(reg_b0_6, reg_r0_49, 0); /* line 395 */
   __CMPEQ(reg_b0_7, reg_r0_49, reg_r0_4); /* line 396 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 397 */
  sim_icache_fetch(233 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_38, reg_b0_1, reg_r0_38, reg_r0_17); /* line 399 */
   __CMPNE(reg_b0_0, reg_r0_31, 0); /* line 400 */
   __CMPEQ(reg_b0_1, reg_r0_31, reg_r0_4); /* line 401 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 402 */
  sim_icache_fetch(237 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_37, reg_b0_3, reg_r0_37, reg_r0_38); /* line 404 */
   __CMPNE(reg_b0_2, reg_r0_50, 0); /* line 405 */
   __CMPEQ(reg_b0_3, reg_r0_50, reg_r0_4); /* line 406 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 407 */
  sim_icache_fetch(241 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_36, reg_b0_5, reg_r0_36, reg_r0_37); /* line 409 */
   __CMPNE(reg_b0_4, reg_r0_51, 0); /* line 410 */
   __CMPEQ(reg_b0_5, reg_r0_51, reg_r0_4); /* line 411 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 412 */
  sim_icache_fetch(245 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_15, reg_b0_7, reg_r0_15, reg_r0_36); /* line 414 */
   __CMPNE(reg_b0_6, reg_r0_52, 0); /* line 415 */
   __CMPEQ(reg_b0_7, reg_r0_52, reg_r0_4); /* line 416 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 417 */
  sim_icache_fetch(249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_13, reg_b0_1, reg_r0_13, reg_r0_15); /* line 419 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 420 */
  sim_icache_fetch(251 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_11, reg_b0_3, reg_r0_11, reg_r0_13); /* line 422 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 423 */
  sim_icache_fetch(253 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_5, reg_r0_9, reg_r0_11); /* line 425 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 426 */
  sim_icache_fetch(255 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_19, reg_r0_9); /* line 428 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 430 */
  sim_icache_fetch(257 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 432 */
l_L29X3: ;/* line 435 */
__LABEL(l_L29X3);
  sim_icache_fetch(258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_26, reg_r0_9); /* line 436 */
} /* line 436 */
l_L16X3: ;/* line 439 */
__LABEL(l_L16X3);
  sim_icache_fetch(259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_26); /* line 441 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 442 */
l_L28X3: ;/* line 445 */
__LABEL(l_L28X3);
  sim_icache_fetch(261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_25, reg_r0_11); /* line 446 */
} /* line 446 */
l_L15X3: ;/* line 449 */
__LABEL(l_L15X3);
  sim_icache_fetch(262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_25); /* line 451 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 452 */
l_L27X3: ;/* line 455 */
__LABEL(l_L27X3);
  sim_icache_fetch(264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_24, reg_r0_13); /* line 456 */
} /* line 456 */
l_L14X3: ;/* line 459 */
__LABEL(l_L14X3);
  sim_icache_fetch(265 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_24); /* line 461 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 462 */
l_L26X3: ;/* line 465 */
__LABEL(l_L26X3);
  sim_icache_fetch(267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_23, reg_r0_15); /* line 466 */
} /* line 466 */
l_L13X3: ;/* line 469 */
__LABEL(l_L13X3);
  sim_icache_fetch(268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_23); /* line 471 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 472 */
l_L25X3: ;/* line 475 */
__LABEL(l_L25X3);
  sim_icache_fetch(270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_36); /* line 476 */
} /* line 476 */
l_L12X3: ;/* line 479 */
__LABEL(l_L12X3);
  sim_icache_fetch(271 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_22); /* line 481 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 482 */
l_L24X3: ;/* line 485 */
__LABEL(l_L24X3);
  sim_icache_fetch(273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_21, reg_r0_37); /* line 486 */
} /* line 486 */
l_L11X3: ;/* line 489 */
__LABEL(l_L11X3);
  sim_icache_fetch(274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_21); /* line 491 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 492 */
l_L23X3: ;/* line 495 */
__LABEL(l_L23X3);
  sim_icache_fetch(276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_20, reg_r0_38); /* line 496 */
} /* line 496 */
l_L10X3: ;/* line 499 */
__LABEL(l_L10X3);
  sim_icache_fetch(277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_20); /* line 501 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 502 */
l_L22X3: ;/* line 505 */
__LABEL(l_L22X3);
  sim_icache_fetch(279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_17); /* line 506 */
} /* line 506 */
l_L9X3: ;/* line 509 */
__LABEL(l_L9X3);
  sim_icache_fetch(280 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_18); /* line 511 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 512 */
l_L21X3: ;/* line 515 */
__LABEL(l_L21X3);
  sim_icache_fetch(282 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_39); /* line 517 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 518 */
l_L20X3: ;/* line 521 */
__LABEL(l_L20X3);
  sim_icache_fetch(284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_40); /* line 523 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 524 */
l_L19X3: ;/* line 527 */
__LABEL(l_L19X3);
  sim_icache_fetch(286 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_41); /* line 529 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 530 */
l_L4X3: ;/* line 533 */
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
} /* line 536 */
l_L17X3: ;/* line 539 */
__LABEL(l_L17X3);
  sim_icache_fetch(289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_7); /* line 540 */
} /* line 540 */
l_L3X3: ;/* line 543 */
__LABEL(l_L3X3);
  sim_icache_fetch(290 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 545 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 546 */
l_L2X3: ;/* line 549 */
__LABEL(l_L2X3);
  sim_icache_fetch(292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 552 */
l_L1X3: ;/* line 555 */
__LABEL(l_L1X3);
  sim_icache_fetch(293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 557 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 558 */
l_L8X3: ;/* line 561 */
__LABEL(l_L8X3);
  sim_icache_fetch(295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_16); /* line 563 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 564 */
l_L7X3: ;/* line 567 */
__LABEL(l_L7X3);
  sim_icache_fetch(297 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_14); /* line 569 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 570 */
l_L6X3: ;/* line 573 */
__LABEL(l_L6X3);
  sim_icache_fetch(299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_12); /* line 575 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 576 */
l_L5X3: ;/* line 579 */
__LABEL(l_L5X3);
  sim_icache_fetch(301 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 579 */
l_L18X3: ;/* line 581 */
__LABEL(l_L18X3);
  sim_icache_fetch(302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_42); /* line 583 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 584 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 111: goto l_L0X3;
    case 112: goto l_L29X3;
    case 113: goto l_L16X3;
    case 114: goto l_L28X3;
    case 115: goto l_L15X3;
    case 116: goto l_L27X3;
    case 117: goto l_L14X3;
    case 118: goto l_L26X3;
    case 119: goto l_L13X3;
    case 120: goto l_L25X3;
    case 121: goto l_L12X3;
    case 122: goto l_L24X3;
    case 123: goto l_L11X3;
    case 124: goto l_L23X3;
    case 125: goto l_L10X3;
    case 126: goto l_L22X3;
    case 127: goto l_L9X3;
    case 128: goto l_L21X3;
    case 129: goto l_L20X3;
    case 130: goto l_L19X3;
    case 131: goto l_L4X3;
    case 132: goto l_L17X3;
    case 133: goto l_L3X3;
    case 134: goto l_L2X3;
    case 135: goto l_L1X3;
    case 136: goto l_L8X3;
    case 137: goto l_L7X3;
    case 138: goto l_L6X3;
    case 139: goto l_L5X3;
    case 140: goto l_L18X3;
    case 141:
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
  reg_l0_0 = (208 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(304 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 600 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 601 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 602 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 603 */
} /* line 603 */
  sim_icache_fetch(311 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 605 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 606 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 607 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 608 */
} /* line 608 */
  sim_icache_fetch(316 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 610 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 611 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 612 */
} /* line 612 */
		 /* line 613 */
  sim_icache_fetch(319 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 615 */
l_lr_42: ;/* line 615 */
__LABEL(l_lr_42);
  sim_icache_fetch(321 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 617 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 618 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 619 */
   __ADD_CYCLES(1);
} /* line 619 */
  sim_icache_fetch(324 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 621 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 622 */
} /* line 622 */
l_L30X3: ;/* line 625 */
__LABEL(l_L30X3);
  sim_icache_fetch(326 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 626 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 627 */
} /* line 627 */
  sim_icache_fetch(328 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 629 */
  sim_icache_fetch(329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 631 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 632 */
   __ADD_CYCLES(1);
} /* line 632 */
  sim_icache_fetch(331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 634 */
} /* line 634 */
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 636 */
l_L33X3: ;/* line 639 */
__LABEL(l_L33X3);
  sim_icache_fetch(333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 640 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 641 */
   __ADD_CYCLES(1);
} /* line 641 */
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 643 */
} /* line 643 */
  sim_icache_fetch(336 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 645 */
} /* line 645 */
  sim_icache_fetch(337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 647 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 648 */
   __ADD_CYCLES(1);
} /* line 648 */
  sim_icache_fetch(339 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 650 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 651 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 652 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 653 */
} /* line 653 */
  sim_icache_fetch(344 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 655 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 656 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 657 */
  sim_icache_fetch(347 + t_thisfile.offset, 1);
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
} /* line 659 */
  sim_icache_fetch(348 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 660 */
  sim_icache_fetch(349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 662 */
l__X1XCompressXTAGX0X0: ;/* line 664 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(350 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 665 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 666 */
l__X1XCompressXTAGX0X7: ;/* line 669 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(353 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 670 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 671 */
l__X1XCompressXTAGX0X6: ;/* line 674 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 675 */
} /* line 675 */
  sim_icache_fetch(357 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 677 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 678 */
l__X1XCompressXTAGX0X5: ;/* line 681 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 682 */
} /* line 682 */
  sim_icache_fetch(361 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 684 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 685 */
l__X1XCompressXTAGX0X4: ;/* line 688 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 689 */
} /* line 689 */
  sim_icache_fetch(365 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 691 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 692 */
l__X1XCompressXTAGX0X3: ;/* line 695 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 696 */
} /* line 696 */
  sim_icache_fetch(369 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 698 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 699 */
l__X1XCompressXTAGX0X2: ;/* line 702 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 703 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 704 */
   __ADD_CYCLES(1);
} /* line 704 */
  sim_icache_fetch(374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 706 */
} /* line 706 */
  sim_icache_fetch(375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 708 */
} /* line 708 */
  sim_icache_fetch(376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 710 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 711 */
   __ADD_CYCLES(1);
} /* line 711 */
  sim_icache_fetch(378 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 713 */
} /* line 713 */
  sim_icache_fetch(379 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 715 */
l_L32X3: ;/* line 717 */
__LABEL(l_L32X3);
  sim_icache_fetch(380 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 718 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 719 */
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 720 */
l_L36X3: ;/* line 723 */
__LABEL(l_L36X3);
  sim_icache_fetch(383 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 724 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 725 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 726 */
} /* line 726 */
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 728 */
} /* line 728 */
  sim_icache_fetch(387 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 730 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 731 */
  sim_icache_fetch(389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 734 */
  sim_icache_fetch(390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 736 */
l_L37X3: ;/* line 739 */
__LABEL(l_L37X3);
		 /* line 739 */
  sim_icache_fetch(391 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 742 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (208 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 742 */
l_lr_56: ;/* line 742 */
__LABEL(l_lr_56);
		 /* line 743 */
  sim_icache_fetch(395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (208 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 745 */
l_lr_58: ;/* line 745 */
__LABEL(l_lr_58);
  sim_icache_fetch(397 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 747 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 748 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 749 */
   __ADD_CYCLES(1);
} /* line 749 */
  sim_icache_fetch(400 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 752 */
l__X1XCompressXTAGX0X1: ;/* line 755 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 755 */
  sim_icache_fetch(401 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 758 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 759 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 759 */
l_lr_61: ;/* line 759 */
__LABEL(l_lr_61);
  sim_icache_fetch(405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 761 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 762 */
} /* line 762 */
  sim_icache_fetch(407 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 764 */
l_L35X3: ;/* line 767 */
__LABEL(l_L35X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 768 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 768 */
  sim_icache_fetch(408 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 771 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (208 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 771 */
l_lr_65: ;/* line 771 */
__LABEL(l_lr_65);
		 /* line 772 */
  sim_icache_fetch(412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (208 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 774 */
l_lr_67: ;/* line 774 */
__LABEL(l_lr_67);
  sim_icache_fetch(414 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 776 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 777 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 778 */
   __ADD_CYCLES(1);
} /* line 778 */
  sim_icache_fetch(417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 781 */
l_L34X3: ;/* line 784 */
__LABEL(l_L34X3);
  sim_icache_fetch(418 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L32X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L32X3;
} /* line 785 */
l_L31X3: ;/* line 788 */
__LABEL(l_L31X3);
  sim_icache_fetch(419 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 789 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 790 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 791 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 792 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 793 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 794 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 795 */
   __ADD_CYCLES(1);
} /* line 795 */
  sim_icache_fetch(429 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 797 */
   __CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 4096); /* line 798 */
} /* line 798 */
  sim_icache_fetch(432 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 800 */
  sim_icache_fetch(433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 802 */
} /* line 802 */
l_L39X3: ;/* line 804 */
__LABEL(l_L39X3);
  sim_icache_fetch(435 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 805 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 806 */
   __ADD_CYCLES(1);
} /* line 806 */
  sim_icache_fetch(438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 808 */
} /* line 808 */
  sim_icache_fetch(439 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 810 */
  sim_icache_fetch(440 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 812 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 813 */
} /* line 813 */
l_L41X3: ;/* line 815 */
__LABEL(l_L41X3);
  sim_icache_fetch(444 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 816 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 817 */
   __ADD_CYCLES(1);
} /* line 817 */
  sim_icache_fetch(447 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 819 */
} /* line 819 */
  sim_icache_fetch(448 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 821 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 822 */
		 /* line 823 */
  sim_icache_fetch(451 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 825 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 826 */
l_lr_73: ;/* line 826 */
__LABEL(l_lr_73);
l_L43X3: ;/* line 828 */
__LABEL(l_L43X3);
  sim_icache_fetch(455 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 829 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 830 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 831 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 832 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 833 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 834 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 835 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 836 */
} /* line 836 */
  sim_icache_fetch(471 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 838 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 839 */
} /* line 839 */
  sim_icache_fetch(475 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 841 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 842 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 843 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 844 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 845 */
} /* line 845 */
  sim_icache_fetch(481 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 847 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 848 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 849 */
  sim_icache_fetch(484 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 851 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 852 */
  sim_icache_fetch(487 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 854 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L46X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 855 */
l_L47X3: ;/* line 857 */
__LABEL(l_L47X3);
		 /* line 857 */
  sim_icache_fetch(490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (208 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 859 */
l_lr_77: ;/* line 859 */
__LABEL(l_lr_77);
  sim_icache_fetch(492 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 861 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 862 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 863 */
   __ADD_CYCLES(1);
} /* line 863 */
  sim_icache_fetch(495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 866 */
l_L46X3: ;/* line 869 */
__LABEL(l_L46X3);
  sim_icache_fetch(496 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 870 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 871 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 872 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 873 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 874 */
   __ADD_CYCLES(1);
} /* line 874 */
  sim_icache_fetch(505 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 876 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 877 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 878 */
} /* line 878 */
  sim_icache_fetch(508 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 880 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 881 */
} /* line 881 */
  sim_icache_fetch(511 + t_thisfile.offset, 1);
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
} /* line 883 */
  sim_icache_fetch(512 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 885 */
} /* line 885 */
  sim_icache_fetch(514 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 887 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 888 */
   __ADD_CYCLES(1);
} /* line 888 */
  sim_icache_fetch(516 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 890 */
} /* line 890 */
l_L49X3: ;/* line 892 */
__LABEL(l_L49X3);
  sim_icache_fetch(517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 893 */
} /* line 893 */
  sim_icache_fetch(518 + t_thisfile.offset, 1);
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
} /* line 896 */
  sim_icache_fetch(519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 898 */
l_L50X3: ;/* line 901 */
__LABEL(l_L50X3);
  sim_icache_fetch(520 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 902 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 903 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 904 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 905 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 906 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 907 */
   __ADD_CYCLES(1);
} /* line 907 */
  sim_icache_fetch(530 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 909 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 910 */
} /* line 910 */
  sim_icache_fetch(532 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 912 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 913 */
} /* line 913 */
  sim_icache_fetch(535 + t_thisfile.offset, 1);
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
} /* line 915 */
  sim_icache_fetch(536 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 917 */
} /* line 917 */
  sim_icache_fetch(538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 919 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 920 */
   __ADD_CYCLES(1);
} /* line 920 */
  sim_icache_fetch(540 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 922 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 923 */
} /* line 923 */
l_L52X3: ;/* line 925 */
__LABEL(l_L52X3);
  sim_icache_fetch(543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 926 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 927 */
} /* line 927 */
  sim_icache_fetch(545 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 929 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 930 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 931 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 932 */
} /* line 932 */
  sim_icache_fetch(551 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 934 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 935 */
		 /* line 936 */
  sim_icache_fetch(554 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (208 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 938 */
l_lr_83: ;/* line 938 */
__LABEL(l_lr_83);
  sim_icache_fetch(556 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 940 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 941 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 942 */
   __ADD_CYCLES(1);
} /* line 942 */
  sim_icache_fetch(559 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 945 */
l_L44X3: ;/* line 948 */
__LABEL(l_L44X3);
		 /* line 948 */
  sim_icache_fetch(560 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 950 */
l_lr_86: ;/* line 950 */
__LABEL(l_lr_86);
  sim_icache_fetch(562 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 952 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 953 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 954 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 955 */
   __ADD_CYCLES(1);
} /* line 955 */
  sim_icache_fetch(566 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 958 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 959 */
l_L51X3: ;/* line 962 */
__LABEL(l_L51X3);
  sim_icache_fetch(569 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 963 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 964 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 965 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 966 */
} /* line 966 */
  sim_icache_fetch(575 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 968 */
   __GOTO(l_L52X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L52X3;
} /* line 969 */
l_L48X3: ;/* line 972 */
__LABEL(l_L48X3);
  sim_icache_fetch(578 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 973 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 974 */
   __GOTO(l_L49X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L49X3;
} /* line 975 */
l_L45X3: ;/* line 978 */
__LABEL(l_L45X3);
  sim_icache_fetch(582 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 979 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 980 */
} /* line 980 */
  sim_icache_fetch(585 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 982 */
} /* line 982 */
  sim_icache_fetch(586 + t_thisfile.offset, 1);
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
} /* line 985 */
  sim_icache_fetch(587 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 987 */
l_L42X3: ;/* line 990 */
__LABEL(l_L42X3);
  sim_icache_fetch(588 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 991 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 992 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 993 */
   __ADD_CYCLES(1);
} /* line 993 */
  sim_icache_fetch(593 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 995 */
} /* line 995 */
  sim_icache_fetch(595 + t_thisfile.offset, 1);
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
} /* line 997 */
		 /* line 998 */
  sim_icache_fetch(596 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1000 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1001 */
l_lr_92: ;/* line 1001 */
__LABEL(l_lr_92);
  sim_icache_fetch(600 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1003 */
l_L53X3: ;/* line 1006 */
__LABEL(l_L53X3);
  sim_icache_fetch(601 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1007 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1008 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1009 */
   __ADD_CYCLES(1);
} /* line 1009 */
  sim_icache_fetch(606 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1011 */
} /* line 1011 */
  sim_icache_fetch(608 + t_thisfile.offset, 1);
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
} /* line 1013 */
		 /* line 1014 */
  sim_icache_fetch(609 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1016 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1017 */
l_lr_95: ;/* line 1017 */
__LABEL(l_lr_95);
  sim_icache_fetch(613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1019 */
l_L54X3: ;/* line 1022 */
__LABEL(l_L54X3);
  sim_icache_fetch(614 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1023 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1024 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1025 */
   __ADD_CYCLES(1);
} /* line 1025 */
  sim_icache_fetch(619 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1027 */
} /* line 1027 */
  sim_icache_fetch(621 + t_thisfile.offset, 1);
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
} /* line 1029 */
		 /* line 1030 */
  sim_icache_fetch(622 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1032 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1033 */
l_lr_98: ;/* line 1033 */
__LABEL(l_lr_98);
  sim_icache_fetch(626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1035 */
l_L55X3: ;/* line 1038 */
__LABEL(l_L55X3);
  sim_icache_fetch(627 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1039 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1040 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1041 */
   __ADD_CYCLES(1);
} /* line 1041 */
  sim_icache_fetch(632 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1043 */
} /* line 1043 */
  sim_icache_fetch(634 + t_thisfile.offset, 1);
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
} /* line 1045 */
		 /* line 1046 */
  sim_icache_fetch(635 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1048 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1049 */
l_lr_101: ;/* line 1049 */
__LABEL(l_lr_101);
  sim_icache_fetch(639 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1051 */
l_L56X3: ;/* line 1054 */
__LABEL(l_L56X3);
		 /* line 1054 */
  sim_icache_fetch(640 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (208 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1056 */
l_lr_104: ;/* line 1056 */
__LABEL(l_lr_104);
  sim_icache_fetch(642 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L43X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L43X3;
} /* line 1058 */
l_L40X3: ;/* line 1061 */
__LABEL(l_L40X3);
  sim_icache_fetch(643 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1062 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1063 */
} /* line 1063 */
  sim_icache_fetch(646 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1065 */
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 1066 */
l_L38X3: ;/* line 1069 */
__LABEL(l_L38X3);
  sim_icache_fetch(649 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1070 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1071 */
   __GOTO(l_L39X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L39X3;
} /* line 1072 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 143: goto l_lr_42;
    case 144: goto l_L30X3;
    case 145: goto l_L33X3;
    case 146: goto l__X1XCompressXTAGX0X0;
    case 147: goto l__X1XCompressXTAGX0X7;
    case 148: goto l__X1XCompressXTAGX0X6;
    case 149: goto l__X1XCompressXTAGX0X5;
    case 150: goto l__X1XCompressXTAGX0X4;
    case 151: goto l__X1XCompressXTAGX0X3;
    case 152: goto l__X1XCompressXTAGX0X2;
    case 153: goto l_L32X3;
    case 154: goto l_L36X3;
    case 155: goto l_L37X3;
    case 157: goto l_lr_56;
    case 159: goto l_lr_58;
    case 160: goto l__X1XCompressXTAGX0X1;
    case 162: goto l_lr_61;
    case 163: goto l_L35X3;
    case 164: goto l__X1XCompressXTAGX0XDEFAULT;
    case 166: goto l_lr_65;
    case 168: goto l_lr_67;
    case 169: goto l_L34X3;
    case 170: goto l_L31X3;
    case 171: goto l_L39X3;
    case 172: goto l_L41X3;
    case 174: goto l_lr_73;
    case 175: goto l_L43X3;
    case 176: goto l_L47X3;
    case 178: goto l_lr_77;
    case 179: goto l_L46X3;
    case 180: goto l_L49X3;
    case 181: goto l_L50X3;
    case 182: goto l_L52X3;
    case 184: goto l_lr_83;
    case 185: goto l_L44X3;
    case 187: goto l_lr_86;
    case 188: goto l_L51X3;
    case 189: goto l_L48X3;
    case 190: goto l_L45X3;
    case 191: goto l_L42X3;
    case 193: goto l_lr_92;
    case 194: goto l_L53X3;
    case 196: goto l_lr_95;
    case 197: goto l_L54X3;
    case 199: goto l_lr_98;
    case 200: goto l_L55X3;
    case 202: goto l_lr_101;
    case 203: goto l_L56X3;
    case 205: goto l_lr_104;
    case 206: goto l_L40X3;
    case 207: goto l_L38X3;
    case 208:
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
  reg_l0_0 = (327 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(652 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1210 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1211 */
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1212 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1213 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1214 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1215 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1216 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1217 */
} /* line 1217 */
  sim_icache_fetch(664 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1219 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1220 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1221 */
   __MOV(reg_r0_4, 0); /* line 1222 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1223 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1224 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1225 */
} /* line 1225 */
  sim_icache_fetch(676 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1227 */
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 1228 */
} /* line 1228 */
  sim_icache_fetch(678 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, (unsigned int) 256); /* line 1230 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1231 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 1); /* line 1232 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1233 */
l_L58X3: ;/* line 1235 */
__LABEL(l_L58X3);
  sim_icache_fetch(683 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((unsigned int) compress_11357Xoffset,0,4), 0); /* line 1236 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1237 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1238 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1239 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1240 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1241 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1242 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 1243 */
} /* line 1243 */
  sim_icache_fetch(698 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1245 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1246 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1247 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1248 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1249 */
  sim_icache_fetch(707 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 1251 */
} /* line 1251 */
  sim_icache_fetch(709 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1253 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1254 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1255 */
   __ADD_CYCLES(1);
} /* line 1255 */
  sim_icache_fetch(712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1257 */
} /* line 1257 */
l_L60X3: ;/* line 1259 */
__LABEL(l_L60X3);
  sim_icache_fetch(713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1260 */
} /* line 1260 */
l_L61X3: ;/* line 1263 */
__LABEL(l_L61X3);
  sim_icache_fetch(714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1264 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1265 */
} /* line 1265 */
  sim_icache_fetch(716 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1267 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1268 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1269 */
  sim_icache_fetch(719 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1271 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1272 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1273 */
  sim_icache_fetch(722 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1275 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1276 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1277 */
  sim_icache_fetch(725 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1279 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1280 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1281 */
  sim_icache_fetch(728 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1283 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1284 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1285 */
  sim_icache_fetch(731 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1289 */
  sim_icache_fetch(734 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1293 */
  sim_icache_fetch(737 + t_thisfile.offset, 3);
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
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1297 */
  sim_icache_fetch(740 + t_thisfile.offset, 3);
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
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1301 */
  sim_icache_fetch(743 + t_thisfile.offset, 3);
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
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1305 */
  sim_icache_fetch(746 + t_thisfile.offset, 3);
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
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1309 */
  sim_icache_fetch(749 + t_thisfile.offset, 3);
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
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1313 */
  sim_icache_fetch(752 + t_thisfile.offset, 3);
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
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1317 */
  sim_icache_fetch(755 + t_thisfile.offset, 3);
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
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1321 */
  sim_icache_fetch(758 + t_thisfile.offset, 3);
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
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1325 */
  sim_icache_fetch(761 + t_thisfile.offset, 3);
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
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1329 */
  sim_icache_fetch(764 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1331 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1332 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1333 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1334 */
  sim_icache_fetch(768 + t_thisfile.offset, 3);
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
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1338 */
  sim_icache_fetch(771 + t_thisfile.offset, 3);
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
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1342 */
  sim_icache_fetch(774 + t_thisfile.offset, 3);
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
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1346 */
  sim_icache_fetch(777 + t_thisfile.offset, 3);
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
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1350 */
  sim_icache_fetch(780 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1354 */
  sim_icache_fetch(783 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1358 */
  sim_icache_fetch(786 + t_thisfile.offset, 3);
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
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1362 */
  sim_icache_fetch(789 + t_thisfile.offset, 3);
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
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1366 */
  sim_icache_fetch(792 + t_thisfile.offset, 3);
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
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1370 */
  sim_icache_fetch(795 + t_thisfile.offset, 3);
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
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1374 */
  sim_icache_fetch(798 + t_thisfile.offset, 3);
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
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1378 */
  sim_icache_fetch(801 + t_thisfile.offset, 3);
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
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1382 */
  sim_icache_fetch(804 + t_thisfile.offset, 3);
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
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1386 */
  sim_icache_fetch(807 + t_thisfile.offset, 3);
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
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1390 */
  sim_icache_fetch(810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1392 */
  sim_icache_fetch(811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1394 */
   __GOTO(l_L61X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L61X3;
} /* line 1395 */
l_L77X3: ;/* line 1398 */
__LABEL(l_L77X3);
  sim_icache_fetch(813 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1399 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1400 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1401 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1402 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1403 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 1404 */
l_L79X3: ;/* line 1407 */
__LABEL(l_L79X3);
  sim_icache_fetch(820 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1408 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1409 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1410 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1411 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1412 */
   __ADD_CYCLES(1);
} /* line 1412 */
  sim_icache_fetch(829 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1414 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1415 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1416 */
} /* line 1416 */
  sim_icache_fetch(832 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1418 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1419 */
} /* line 1419 */
  sim_icache_fetch(835 + t_thisfile.offset, 1);
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
} /* line 1421 */
  sim_icache_fetch(836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1423 */
} /* line 1423 */
  sim_icache_fetch(838 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1425 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1426 */
   __ADD_CYCLES(1);
} /* line 1426 */
  sim_icache_fetch(840 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1428 */
} /* line 1428 */
l_L81X3: ;/* line 1430 */
__LABEL(l_L81X3);
  sim_icache_fetch(841 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1431 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1432 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1433 */
} /* line 1433 */
  sim_icache_fetch(844 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1435 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1436 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1437 */
  sim_icache_fetch(847 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1439 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1440 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1441 */
} /* line 1441 */
  sim_icache_fetch(853 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1443 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1444 */
   __ADD_CYCLES(1);
} /* line 1444 */
  sim_icache_fetch(855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1446 */
} /* line 1446 */
  sim_icache_fetch(856 + t_thisfile.offset, 1);
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
} /* line 1448 */
  sim_icache_fetch(857 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1450 */
} /* line 1450 */
  sim_icache_fetch(858 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 1452 */
l_L83X3: ;/* line 1455 */
__LABEL(l_L83X3);
  sim_icache_fetch(859 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1456 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1457 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1458 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1459 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1460 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1461 */
} /* line 1461 */
  sim_icache_fetch(866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1463 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1464 */
   __ADD_CYCLES(1);
} /* line 1464 */
  sim_icache_fetch(868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(869 + t_thisfile.offset, 1);
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
} /* line 1468 */
l_L85X3: ;/* line 1470 */
__LABEL(l_L85X3);
		 /* line 1470 */
  sim_icache_fetch(870 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (327 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1472 */
l_lr_117: ;/* line 1472 */
__LABEL(l_lr_117);
  sim_icache_fetch(872 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1474 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1475 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1476 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1477 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1478 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1479 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1480 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1481 */
   __ADD_CYCLES(1);
} /* line 1481 */
  sim_icache_fetch(883 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1483 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1484 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1485 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1486 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1487 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1488 */
} /* line 1488 */
  sim_icache_fetch(891 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1490 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1491 */
  sim_icache_fetch(894 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1493 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1494 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1495 */
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 1496 */
l_L86X3: ;/* line 1499 */
__LABEL(l_L86X3);
  sim_icache_fetch(899 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1500 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1501 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1502 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1503 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1504 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1505 */
   __ADD_CYCLES(1);
} /* line 1505 */
  sim_icache_fetch(908 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1507 */
} /* line 1507 */
  sim_icache_fetch(909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1509 */
} /* line 1509 */
  sim_icache_fetch(910 + t_thisfile.offset, 1);
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
} /* line 1511 */
		 /* line 1512 */
  sim_icache_fetch(911 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (327 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1514 */
l_lr_120: ;/* line 1514 */
__LABEL(l_lr_120);
  sim_icache_fetch(913 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1516 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1517 */
} /* line 1517 */
  sim_icache_fetch(915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 1519 */
l_L87X3: ;/* line 1522 */
__LABEL(l_L87X3);
  sim_icache_fetch(916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1523 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1524 */
} /* line 1524 */
  sim_icache_fetch(918 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 1526 */
l_L84X3: ;/* line 1529 */
__LABEL(l_L84X3);
  sim_icache_fetch(919 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1530 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1531 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1532 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1533 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1534 */
   __ADD_CYCLES(1);
} /* line 1534 */
  sim_icache_fetch(924 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1536 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1537 */
} /* line 1537 */
  sim_icache_fetch(926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1539 */
} /* line 1539 */
l_L88X3: ;/* line 1542 */
__LABEL(l_L88X3);
  sim_icache_fetch(927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1543 */
} /* line 1543 */
  sim_icache_fetch(928 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1545 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1546 */
} /* line 1546 */
  sim_icache_fetch(930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1548 */
} /* line 1548 */
  sim_icache_fetch(931 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1550 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1551 */
} /* line 1551 */
  sim_icache_fetch(934 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1553 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1554 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1555 */
} /* line 1555 */
  sim_icache_fetch(937 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1557 */
} /* line 1557 */
  sim_icache_fetch(938 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1559 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1560 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1561 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1562 */
} /* line 1562 */
  sim_icache_fetch(943 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1564 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1565 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1566 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1567 */
  sim_icache_fetch(947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1569 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1570 */
  sim_icache_fetch(949 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1572 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1573 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1574 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1575 */
} /* line 1575 */
  sim_icache_fetch(954 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1577 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1578 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1579 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1580 */
  sim_icache_fetch(958 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1582 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1583 */
  sim_icache_fetch(960 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1585 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1586 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1587 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1588 */
} /* line 1588 */
  sim_icache_fetch(965 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1590 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1591 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1592 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1593 */
  sim_icache_fetch(969 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1595 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1596 */
  sim_icache_fetch(971 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1598 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1599 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1600 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1601 */
} /* line 1601 */
  sim_icache_fetch(976 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1603 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1604 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1605 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1606 */
  sim_icache_fetch(980 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1608 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1609 */
  sim_icache_fetch(982 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1611 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1612 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1613 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1614 */
} /* line 1614 */
  sim_icache_fetch(987 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1616 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1617 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1618 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1619 */
  sim_icache_fetch(991 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1621 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1622 */
  sim_icache_fetch(993 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1624 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1625 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1626 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1627 */
} /* line 1627 */
  sim_icache_fetch(998 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1629 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1630 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1631 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1632 */
  sim_icache_fetch(1002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1634 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1635 */
  sim_icache_fetch(1004 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1637 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1638 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1639 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1640 */
} /* line 1640 */
  sim_icache_fetch(1009 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1642 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1643 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1644 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1645 */
  sim_icache_fetch(1013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1647 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1648 */
  sim_icache_fetch(1015 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1650 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1651 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1652 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1653 */
} /* line 1653 */
  sim_icache_fetch(1020 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1655 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1656 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1657 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1658 */
  sim_icache_fetch(1024 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1660 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1661 */
  sim_icache_fetch(1026 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1663 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1664 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1665 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1666 */
} /* line 1666 */
  sim_icache_fetch(1031 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1668 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1669 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1670 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1671 */
  sim_icache_fetch(1035 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1673 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1674 */
  sim_icache_fetch(1037 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1676 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1677 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1678 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1679 */
} /* line 1679 */
  sim_icache_fetch(1042 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1681 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1682 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1683 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1684 */
  sim_icache_fetch(1046 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1686 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1687 */
  sim_icache_fetch(1048 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1689 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1690 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1691 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1692 */
} /* line 1692 */
  sim_icache_fetch(1053 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1694 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1695 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1696 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1697 */
  sim_icache_fetch(1057 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1699 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1700 */
  sim_icache_fetch(1059 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1702 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1703 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1704 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1705 */
} /* line 1705 */
  sim_icache_fetch(1064 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1707 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1708 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1709 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1710 */
  sim_icache_fetch(1068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1712 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1713 */
  sim_icache_fetch(1070 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1715 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1716 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1717 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(1075 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1720 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1721 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1722 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1723 */
  sim_icache_fetch(1079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1725 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1726 */
  sim_icache_fetch(1081 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1728 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1729 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1730 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1731 */
} /* line 1731 */
  sim_icache_fetch(1086 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1733 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1734 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1735 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1736 */
  sim_icache_fetch(1090 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1738 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1739 */
  sim_icache_fetch(1092 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1741 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1742 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1743 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1744 */
} /* line 1744 */
  sim_icache_fetch(1097 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1746 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1747 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1748 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1749 */
  sim_icache_fetch(1101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1751 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1752 */
  sim_icache_fetch(1103 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1754 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1755 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1756 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(1108 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1759 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1760 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1761 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1762 */
  sim_icache_fetch(1112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1764 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1765 */
  sim_icache_fetch(1114 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1767 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1768 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1769 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1770 */
} /* line 1770 */
  sim_icache_fetch(1119 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1772 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1773 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1774 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1775 */
  sim_icache_fetch(1123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1777 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1778 */
  sim_icache_fetch(1125 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1780 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1781 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1782 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1783 */
} /* line 1783 */
  sim_icache_fetch(1130 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1785 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1786 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1787 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1788 */
  sim_icache_fetch(1134 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1790 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1791 */
  sim_icache_fetch(1136 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1793 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1794 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1795 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1796 */
} /* line 1796 */
  sim_icache_fetch(1141 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1798 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1799 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1800 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1801 */
  sim_icache_fetch(1145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1803 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1804 */
  sim_icache_fetch(1147 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1806 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1807 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1808 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1809 */
} /* line 1809 */
  sim_icache_fetch(1152 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1811 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1812 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1813 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1814 */
  sim_icache_fetch(1156 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1816 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1817 */
  sim_icache_fetch(1158 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1819 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1820 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1821 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1822 */
} /* line 1822 */
  sim_icache_fetch(1163 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1824 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1825 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1826 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1827 */
  sim_icache_fetch(1167 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1829 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1830 */
  sim_icache_fetch(1169 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1832 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1833 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1834 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1835 */
} /* line 1835 */
  sim_icache_fetch(1174 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1837 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1838 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1839 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1840 */
  sim_icache_fetch(1178 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1842 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1843 */
  sim_icache_fetch(1180 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1845 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1846 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1847 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1848 */
} /* line 1848 */
  sim_icache_fetch(1185 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1850 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1851 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1852 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1853 */
  sim_icache_fetch(1189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1855 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1856 */
  sim_icache_fetch(1191 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1858 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1859 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1860 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1861 */
} /* line 1861 */
  sim_icache_fetch(1196 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1863 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1864 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1865 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1866 */
  sim_icache_fetch(1200 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1868 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1869 */
  sim_icache_fetch(1202 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1871 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1872 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1873 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1874 */
} /* line 1874 */
  sim_icache_fetch(1207 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1876 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1877 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1878 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1879 */
  sim_icache_fetch(1211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1881 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1882 */
  sim_icache_fetch(1213 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1884 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1885 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1886 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1887 */
} /* line 1887 */
  sim_icache_fetch(1218 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1889 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1890 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1891 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1892 */
  sim_icache_fetch(1222 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1894 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1895 */
  sim_icache_fetch(1224 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1897 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1898 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1899 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1900 */
} /* line 1900 */
  sim_icache_fetch(1229 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1902 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1903 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1904 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1905 */
  sim_icache_fetch(1233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1907 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1908 */
  sim_icache_fetch(1235 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1910 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1911 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1912 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1913 */
} /* line 1913 */
  sim_icache_fetch(1240 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1915 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1916 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1917 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1918 */
  sim_icache_fetch(1244 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1920 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1921 */
  sim_icache_fetch(1246 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1923 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1924 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1925 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1926 */
} /* line 1926 */
  sim_icache_fetch(1251 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1928 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1929 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1930 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1931 */
  sim_icache_fetch(1255 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1933 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1934 */
  sim_icache_fetch(1257 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1936 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1937 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1938 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1939 */
} /* line 1939 */
  sim_icache_fetch(1262 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1941 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1942 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1943 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1944 */
  sim_icache_fetch(1266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1946 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1947 */
  sim_icache_fetch(1268 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1949 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1950 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1951 */
} /* line 1951 */
  sim_icache_fetch(1272 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1953 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1954 */
  sim_icache_fetch(1274 + t_thisfile.offset, 1);
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
} /* line 1956 */
  sim_icache_fetch(1275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1958 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1959 */
} /* line 1959 */
  sim_icache_fetch(1277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1961 */
  sim_icache_fetch(1278 + t_thisfile.offset, 1);
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
} /* line 1964 */
  sim_icache_fetch(1279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L88X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L88X3;
} /* line 1966 */
l_L152X3: ;/* line 1969 */
__LABEL(l_L152X3);
  sim_icache_fetch(1280 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1970 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1971 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1972 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1973 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 1974 */
l_L151X3: ;/* line 1978 */
__LABEL(l_L151X3);
  sim_icache_fetch(1285 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 1979 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1980 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 1981 */
l_L150X3: ;/* line 1984 */
__LABEL(l_L150X3);
  sim_icache_fetch(1288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 1985 */
} /* line 1985 */
l_L118X3: ;/* line 1988 */
__LABEL(l_L118X3);
  sim_icache_fetch(1289 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 1989 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1990 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1991 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1992 */
} /* line 1992 */
  sim_icache_fetch(1293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1994 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 1995 */
l_L149X3: ;/* line 1998 */
__LABEL(l_L149X3);
  sim_icache_fetch(1295 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 1999 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2000 */
   __GOTO(l_L154X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L154X3;
} /* line 2001 */
l_L148X3: ;/* line 2004 */
__LABEL(l_L148X3);
  sim_icache_fetch(1298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2005 */
} /* line 2005 */
l_L116X3: ;/* line 2008 */
__LABEL(l_L116X3);
  sim_icache_fetch(1299 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2009 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2010 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2011 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2012 */
} /* line 2012 */
  sim_icache_fetch(1303 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2014 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2015 */
l_L147X3: ;/* line 2018 */
__LABEL(l_L147X3);
  sim_icache_fetch(1305 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2019 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2020 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2021 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2022 */
l_L146X3: ;/* line 2025 */
__LABEL(l_L146X3);
  sim_icache_fetch(1309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2026 */
} /* line 2026 */
l_L114X3: ;/* line 2029 */
__LABEL(l_L114X3);
  sim_icache_fetch(1310 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2030 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2031 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2032 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2033 */
} /* line 2033 */
  sim_icache_fetch(1314 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2035 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2036 */
l_L145X3: ;/* line 2039 */
__LABEL(l_L145X3);
  sim_icache_fetch(1316 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2040 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2041 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2042 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2043 */
l_L144X3: ;/* line 2046 */
__LABEL(l_L144X3);
  sim_icache_fetch(1320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2047 */
} /* line 2047 */
l_L112X3: ;/* line 2050 */
__LABEL(l_L112X3);
  sim_icache_fetch(1321 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2051 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2052 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2053 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2054 */
} /* line 2054 */
  sim_icache_fetch(1325 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2056 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2057 */
l_L143X3: ;/* line 2060 */
__LABEL(l_L143X3);
  sim_icache_fetch(1327 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2061 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2062 */
   __GOTO(l_L155X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L155X3;
} /* line 2063 */
l_L142X3: ;/* line 2066 */
__LABEL(l_L142X3);
  sim_icache_fetch(1330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2067 */
} /* line 2067 */
l_L110X3: ;/* line 2070 */
__LABEL(l_L110X3);
  sim_icache_fetch(1331 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2071 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2072 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2073 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2074 */
} /* line 2074 */
  sim_icache_fetch(1335 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2076 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2077 */
l_L141X3: ;/* line 2080 */
__LABEL(l_L141X3);
  sim_icache_fetch(1337 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2081 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2082 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2083 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2084 */
l_L140X3: ;/* line 2087 */
__LABEL(l_L140X3);
  sim_icache_fetch(1341 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2088 */
} /* line 2088 */
l_L108X3: ;/* line 2091 */
__LABEL(l_L108X3);
  sim_icache_fetch(1342 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2092 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2093 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2094 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2095 */
} /* line 2095 */
  sim_icache_fetch(1346 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2097 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2098 */
l_L139X3: ;/* line 2101 */
__LABEL(l_L139X3);
  sim_icache_fetch(1348 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2102 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2103 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2104 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2105 */
l_L138X3: ;/* line 2108 */
__LABEL(l_L138X3);
  sim_icache_fetch(1352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2109 */
} /* line 2109 */
l_L106X3: ;/* line 2112 */
__LABEL(l_L106X3);
  sim_icache_fetch(1353 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2113 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2114 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2115 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2116 */
} /* line 2116 */
  sim_icache_fetch(1357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2118 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2119 */
l_L137X3: ;/* line 2122 */
__LABEL(l_L137X3);
  sim_icache_fetch(1359 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2123 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2124 */
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2125 */
l_L136X3: ;/* line 2128 */
__LABEL(l_L136X3);
  sim_icache_fetch(1362 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2129 */
} /* line 2129 */
l_L104X3: ;/* line 2132 */
__LABEL(l_L104X3);
  sim_icache_fetch(1363 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2133 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2134 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2135 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2136 */
} /* line 2136 */
  sim_icache_fetch(1367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2138 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2139 */
l_L135X3: ;/* line 2142 */
__LABEL(l_L135X3);
  sim_icache_fetch(1369 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2143 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2144 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2145 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2146 */
l_L134X3: ;/* line 2149 */
__LABEL(l_L134X3);
  sim_icache_fetch(1373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2150 */
} /* line 2150 */
l_L102X3: ;/* line 2153 */
__LABEL(l_L102X3);
  sim_icache_fetch(1374 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2154 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2155 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2156 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2157 */
} /* line 2157 */
  sim_icache_fetch(1378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2159 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2160 */
l_L133X3: ;/* line 2163 */
__LABEL(l_L133X3);
  sim_icache_fetch(1380 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2164 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2165 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2166 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2167 */
l_L132X3: ;/* line 2170 */
__LABEL(l_L132X3);
  sim_icache_fetch(1384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2171 */
} /* line 2171 */
l_L100X3: ;/* line 2174 */
__LABEL(l_L100X3);
  sim_icache_fetch(1385 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2175 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2176 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2177 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2178 */
} /* line 2178 */
  sim_icache_fetch(1389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2180 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2181 */
l_L131X3: ;/* line 2184 */
__LABEL(l_L131X3);
  sim_icache_fetch(1391 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2185 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2186 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 2187 */
l_L130X3: ;/* line 2190 */
__LABEL(l_L130X3);
  sim_icache_fetch(1394 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2191 */
} /* line 2191 */
l_L98X3: ;/* line 2194 */
__LABEL(l_L98X3);
  sim_icache_fetch(1395 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2195 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2196 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2197 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2198 */
} /* line 2198 */
  sim_icache_fetch(1399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2200 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2201 */
l_L129X3: ;/* line 2204 */
__LABEL(l_L129X3);
  sim_icache_fetch(1401 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2205 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2206 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2207 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2208 */
l_L128X3: ;/* line 2211 */
__LABEL(l_L128X3);
  sim_icache_fetch(1405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2212 */
} /* line 2212 */
l_L96X3: ;/* line 2215 */
__LABEL(l_L96X3);
  sim_icache_fetch(1406 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2216 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2217 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2218 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2219 */
} /* line 2219 */
  sim_icache_fetch(1410 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2221 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2222 */
l_L127X3: ;/* line 2225 */
__LABEL(l_L127X3);
  sim_icache_fetch(1412 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2226 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2227 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2228 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2229 */
l_L126X3: ;/* line 2232 */
__LABEL(l_L126X3);
  sim_icache_fetch(1416 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2233 */
} /* line 2233 */
l_L94X3: ;/* line 2236 */
__LABEL(l_L94X3);
  sim_icache_fetch(1417 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2237 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2238 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2239 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2240 */
} /* line 2240 */
  sim_icache_fetch(1421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2242 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2243 */
l_L125X3: ;/* line 2246 */
__LABEL(l_L125X3);
  sim_icache_fetch(1423 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2247 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2248 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2249 */
l_L124X3: ;/* line 2252 */
__LABEL(l_L124X3);
  sim_icache_fetch(1426 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2253 */
} /* line 2253 */
l_L92X3: ;/* line 2256 */
__LABEL(l_L92X3);
  sim_icache_fetch(1427 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2257 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2258 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2259 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2260 */
} /* line 2260 */
  sim_icache_fetch(1431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2262 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2263 */
l_L123X3: ;/* line 2266 */
__LABEL(l_L123X3);
  sim_icache_fetch(1433 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2267 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2268 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2269 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2270 */
l_L122X3: ;/* line 2273 */
__LABEL(l_L122X3);
  sim_icache_fetch(1437 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2274 */
} /* line 2274 */
l_L90X3: ;/* line 2278 */
__LABEL(l_L90X3);
  sim_icache_fetch(1438 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2279 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2280 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2281 */
} /* line 2281 */
  sim_icache_fetch(1441 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2283 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2284 */
l_L121X3: ;/* line 2287 */
__LABEL(l_L121X3);
  sim_icache_fetch(1443 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2288 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2289 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2290 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2291 */
l_L120X3: ;/* line 2294 */
__LABEL(l_L120X3);
  sim_icache_fetch(1447 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2295 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2296 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2297 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2298 */
   __GOTO(l_L85X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L85X3;
} /* line 2299 */
l_L119X3: ;/* line 2303 */
__LABEL(l_L119X3);
  sim_icache_fetch(1452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2304 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2305 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2306 */
l_L117X3: ;/* line 2309 */
__LABEL(l_L117X3);
  sim_icache_fetch(1455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2310 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2311 */
} /* line 2311 */
l_L154X3: ;/* line 2313 */
__LABEL(l_L154X3);
  sim_icache_fetch(1457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2314 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2315 */
l_L115X3: ;/* line 2318 */
__LABEL(l_L115X3);
  sim_icache_fetch(1459 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2319 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2320 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2321 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2322 */
l_L113X3: ;/* line 2325 */
__LABEL(l_L113X3);
  sim_icache_fetch(1463 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2326 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2327 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2328 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2329 */
l_L111X3: ;/* line 2332 */
__LABEL(l_L111X3);
  sim_icache_fetch(1467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2333 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2334 */
} /* line 2334 */
l_L155X3: ;/* line 2336 */
__LABEL(l_L155X3);
  sim_icache_fetch(1469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2337 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2338 */
l_L109X3: ;/* line 2341 */
__LABEL(l_L109X3);
  sim_icache_fetch(1471 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2342 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2343 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2344 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2345 */
l_L107X3: ;/* line 2348 */
__LABEL(l_L107X3);
  sim_icache_fetch(1475 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2349 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2350 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2351 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2352 */
l_L105X3: ;/* line 2355 */
__LABEL(l_L105X3);
  sim_icache_fetch(1479 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2356 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2357 */
} /* line 2357 */
l_L156X3: ;/* line 2359 */
__LABEL(l_L156X3);
  sim_icache_fetch(1481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2360 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2361 */
l_L103X3: ;/* line 2364 */
__LABEL(l_L103X3);
  sim_icache_fetch(1483 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2365 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2366 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2367 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2368 */
l_L101X3: ;/* line 2371 */
__LABEL(l_L101X3);
  sim_icache_fetch(1487 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2372 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2373 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2374 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2375 */
l_L99X3: ;/* line 2378 */
__LABEL(l_L99X3);
  sim_icache_fetch(1491 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2379 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2380 */
} /* line 2380 */
l_L157X3: ;/* line 2382 */
__LABEL(l_L157X3);
  sim_icache_fetch(1493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2383 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2384 */
l_L97X3: ;/* line 2387 */
__LABEL(l_L97X3);
  sim_icache_fetch(1495 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2388 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2389 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2390 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2391 */
l_L95X3: ;/* line 2394 */
__LABEL(l_L95X3);
  sim_icache_fetch(1499 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2395 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2396 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2397 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2398 */
l_L93X3: ;/* line 2401 */
__LABEL(l_L93X3);
  sim_icache_fetch(1503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2402 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2403 */
} /* line 2403 */
l_L158X3: ;/* line 2405 */
__LABEL(l_L158X3);
  sim_icache_fetch(1505 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2406 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2407 */
l_L91X3: ;/* line 2410 */
__LABEL(l_L91X3);
  sim_icache_fetch(1507 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2411 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2412 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2413 */
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2414 */
l_L89X3: ;/* line 2418 */
__LABEL(l_L89X3);
  sim_icache_fetch(1511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2419 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2420 */
} /* line 2420 */
l_L153X3: ;/* line 2422 */
__LABEL(l_L153X3);
  sim_icache_fetch(1513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2423 */
} /* line 2423 */
  sim_icache_fetch(1515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2425 */
} /* line 2425 */
  sim_icache_fetch(1516 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 2427 */
l_L82X3: ;/* line 2430 */
__LABEL(l_L82X3);
		 /* line 2430 */
  sim_icache_fetch(1517 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2433 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (327 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2433 */
l_lr_196: ;/* line 2433 */
__LABEL(l_lr_196);
  sim_icache_fetch(1520 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2435 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2436 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2437 */
   __ADD_CYCLES(1);
} /* line 2437 */
  sim_icache_fetch(1524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2439 */
} /* line 2439 */
		 /* line 2440 */
  sim_icache_fetch(1525 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2442 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (327 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2443 */
l_lr_198: ;/* line 2443 */
__LABEL(l_lr_198);
  sim_icache_fetch(1529 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2445 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2446 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2447 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2448 */
   __MOV(reg_r0_3, 0); /* line 2449 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2450 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2451 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2452 */
   __ADD_CYCLES(1);
} /* line 2452 */
  sim_icache_fetch(1541 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2454 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2455 */
} /* line 2455 */
  sim_icache_fetch(1543 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2457 */
l_L160X3: ;/* line 2459 */
__LABEL(l_L160X3);
  sim_icache_fetch(1544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L161X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2460 */
  sim_icache_fetch(1545 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2462 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2463 */
} /* line 2463 */
l_L162X3: ;/* line 2465 */
__LABEL(l_L162X3);
  sim_icache_fetch(1548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2467 */
l_L161X3: ;/* line 2470 */
__LABEL(l_L161X3);
  sim_icache_fetch(1549 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2471 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2472 */
   __GOTO(l_L162X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L162X3;
} /* line 2473 */
l_L159X3: ;/* line 2476 */
__LABEL(l_L159X3);
  sim_icache_fetch(1552 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2477 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2478 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2479 */
   __ADD_CYCLES(1);
} /* line 2479 */
		 /* line 2480 */
  sim_icache_fetch(1557 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2482 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (327 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2483 */
l_lr_204: ;/* line 2483 */
__LABEL(l_lr_204);
  sim_icache_fetch(1560 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2485 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2486 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2487 */
   __MOV(reg_r0_3, 0); /* line 2488 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2489 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2490 */
   __ADD_CYCLES(1);
} /* line 2490 */
  sim_icache_fetch(1568 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2492 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2493 */
l_L80X3: ;/* line 2496 */
__LABEL(l_L80X3);
  sim_icache_fetch(1570 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2497 */
   __GOTO(l_L81X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L81X3;
} /* line 2498 */
l_L76X3: ;/* line 2501 */
__LABEL(l_L76X3);
  sim_icache_fetch(1572 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2502 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2503 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2504 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2505 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2506 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2507 */
l_L75X3: ;/* line 2510 */
__LABEL(l_L75X3);
  sim_icache_fetch(1579 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2511 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2512 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2513 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2514 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2515 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2516 */
l_L74X3: ;/* line 2519 */
__LABEL(l_L74X3);
  sim_icache_fetch(1586 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2520 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2521 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2522 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2523 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2524 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2525 */
l_L73X3: ;/* line 2528 */
__LABEL(l_L73X3);
  sim_icache_fetch(1593 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2529 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2530 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2531 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2532 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2533 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2534 */
l_L72X3: ;/* line 2537 */
__LABEL(l_L72X3);
  sim_icache_fetch(1600 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2538 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2539 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2540 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2541 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2542 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2543 */
l_L71X3: ;/* line 2546 */
__LABEL(l_L71X3);
  sim_icache_fetch(1607 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2547 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2548 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2549 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2550 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2551 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2552 */
l_L70X3: ;/* line 2555 */
__LABEL(l_L70X3);
  sim_icache_fetch(1614 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2556 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2557 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2558 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2559 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2560 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2561 */
l_L69X3: ;/* line 2564 */
__LABEL(l_L69X3);
  sim_icache_fetch(1621 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2565 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2566 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2567 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2568 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2569 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2570 */
l_L68X3: ;/* line 2573 */
__LABEL(l_L68X3);
  sim_icache_fetch(1628 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2574 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2575 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2576 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2577 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2578 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2579 */
l_L67X3: ;/* line 2582 */
__LABEL(l_L67X3);
  sim_icache_fetch(1635 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2583 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2584 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2585 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2586 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2587 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2588 */
l_L66X3: ;/* line 2591 */
__LABEL(l_L66X3);
  sim_icache_fetch(1642 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2592 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2593 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2594 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2595 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2596 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2597 */
l_L65X3: ;/* line 2600 */
__LABEL(l_L65X3);
  sim_icache_fetch(1649 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2601 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2602 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2603 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2604 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2605 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2606 */
l_L64X3: ;/* line 2609 */
__LABEL(l_L64X3);
  sim_icache_fetch(1656 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2610 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2611 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2612 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2613 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2614 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2615 */
l_L63X3: ;/* line 2618 */
__LABEL(l_L63X3);
  sim_icache_fetch(1663 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2619 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2620 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2621 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2622 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2623 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2624 */
l_L62X3: ;/* line 2628 */
__LABEL(l_L62X3);
  sim_icache_fetch(1670 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2629 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2630 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2631 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2632 */
} /* line 2632 */
l_L78X3: ;/* line 2634 */
__LABEL(l_L78X3);
  sim_icache_fetch(1675 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2635 */
} /* line 2635 */
		 /* line 2636 */
  sim_icache_fetch(1676 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2639 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2640 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2641 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (327 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2641 */
l_lr_223: ;/* line 2641 */
__LABEL(l_lr_223);
  sim_icache_fetch(1681 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2643 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2644 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2645 */
} /* line 2645 */
  sim_icache_fetch(1684 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 2647 */
l_L59X3: ;/* line 2650 */
__LABEL(l_L59X3);
  sim_icache_fetch(1685 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2651 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2652 */
} /* line 2652 */
  sim_icache_fetch(1687 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L60X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L60X3;
} /* line 2654 */
l_L57X3: ;/* line 2657 */
__LABEL(l_L57X3);
  sim_icache_fetch(1688 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_15, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2658 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2659 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2660 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2661 */
   __MOV(reg_r0_16, (unsigned int) 257); /* line 2662 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2663 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2664 */
   __ADD_CYCLES(1);
} /* line 2664 */
  sim_icache_fetch(1698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_11, (unsigned int) 1); /* line 2666 */
} /* line 2666 */
  sim_icache_fetch(1699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_17); /* line 2668 */
} /* line 2668 */
  sim_icache_fetch(1701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2670 */
} /* line 2670 */
  sim_icache_fetch(1702 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2672 */
   __LDBU(reg_r0_15, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2673 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2674 */
   __ADD_CYCLES(1);
} /* line 2674 */
  sim_icache_fetch(1707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_11, (unsigned int) 1); /* line 2676 */
} /* line 2676 */
  sim_icache_fetch(1708 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_17); /* line 2678 */
} /* line 2678 */
  sim_icache_fetch(1710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2680 */
} /* line 2680 */
  sim_icache_fetch(1711 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2682 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2683 */
   __LDW(reg_r0_17, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2684 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2685 */
   __ADD_CYCLES(1);
} /* line 2685 */
  sim_icache_fetch(1718 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2687 */
   __OR(reg_r0_15, reg_r0_15, reg_r0_17); /* line 2688 */
} /* line 2688 */
  sim_icache_fetch(1720 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2690 */
} /* line 2690 */
  sim_icache_fetch(1722 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_15); /* line 2692 */
} /* line 2692 */
  sim_icache_fetch(1723 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2694 */
   __LDW(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2695 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2696 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2697 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2698 */
   __ADD_CYCLES(1);
} /* line 2698 */
  sim_icache_fetch(1732 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_11, 0); /* line 2700 */
   __ADD(reg_r0_13, reg_r0_15, (unsigned int) -1); /* line 2701 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 1); /* line 2702 */
} /* line 2702 */
  sim_icache_fetch(1735 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_16, (unsigned int) 256); /* line 2704 */
   __GOTO(l_L58X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L58X3;
} /* line 2705 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 209: goto l_L58X3;
    case 210: goto l_L60X3;
    case 211: goto l_L61X3;
    case 212: goto l_L77X3;
    case 213: goto l_L79X3;
    case 214: goto l_L81X3;
    case 215: goto l_L83X3;
    case 216: goto l_L85X3;
    case 218: goto l_lr_117;
    case 219: goto l_L86X3;
    case 221: goto l_lr_120;
    case 222: goto l_L87X3;
    case 223: goto l_L84X3;
    case 224: goto l_L88X3;
    case 225: goto l_L152X3;
    case 226: goto l_L151X3;
    case 227: goto l_L150X3;
    case 228: goto l_L118X3;
    case 229: goto l_L149X3;
    case 230: goto l_L148X3;
    case 231: goto l_L116X3;
    case 232: goto l_L147X3;
    case 233: goto l_L146X3;
    case 234: goto l_L114X3;
    case 235: goto l_L145X3;
    case 236: goto l_L144X3;
    case 237: goto l_L112X3;
    case 238: goto l_L143X3;
    case 239: goto l_L142X3;
    case 240: goto l_L110X3;
    case 241: goto l_L141X3;
    case 242: goto l_L140X3;
    case 243: goto l_L108X3;
    case 244: goto l_L139X3;
    case 245: goto l_L138X3;
    case 246: goto l_L106X3;
    case 247: goto l_L137X3;
    case 248: goto l_L136X3;
    case 249: goto l_L104X3;
    case 250: goto l_L135X3;
    case 251: goto l_L134X3;
    case 252: goto l_L102X3;
    case 253: goto l_L133X3;
    case 254: goto l_L132X3;
    case 255: goto l_L100X3;
    case 256: goto l_L131X3;
    case 257: goto l_L130X3;
    case 258: goto l_L98X3;
    case 259: goto l_L129X3;
    case 260: goto l_L128X3;
    case 261: goto l_L96X3;
    case 262: goto l_L127X3;
    case 263: goto l_L126X3;
    case 264: goto l_L94X3;
    case 265: goto l_L125X3;
    case 266: goto l_L124X3;
    case 267: goto l_L92X3;
    case 268: goto l_L123X3;
    case 269: goto l_L122X3;
    case 270: goto l_L90X3;
    case 271: goto l_L121X3;
    case 272: goto l_L120X3;
    case 273: goto l_L119X3;
    case 274: goto l_L117X3;
    case 275: goto l_L154X3;
    case 276: goto l_L115X3;
    case 277: goto l_L113X3;
    case 278: goto l_L111X3;
    case 279: goto l_L155X3;
    case 280: goto l_L109X3;
    case 281: goto l_L107X3;
    case 282: goto l_L105X3;
    case 283: goto l_L156X3;
    case 284: goto l_L103X3;
    case 285: goto l_L101X3;
    case 286: goto l_L99X3;
    case 287: goto l_L157X3;
    case 288: goto l_L97X3;
    case 289: goto l_L95X3;
    case 290: goto l_L93X3;
    case 291: goto l_L158X3;
    case 292: goto l_L91X3;
    case 293: goto l_L89X3;
    case 294: goto l_L153X3;
    case 295: goto l_L82X3;
    case 297: goto l_lr_196;
    case 299: goto l_lr_198;
    case 300: goto l_L160X3;
    case 301: goto l_L162X3;
    case 302: goto l_L161X3;
    case 303: goto l_L159X3;
    case 305: goto l_lr_204;
    case 306: goto l_L80X3;
    case 307: goto l_L76X3;
    case 308: goto l_L75X3;
    case 309: goto l_L74X3;
    case 310: goto l_L73X3;
    case 311: goto l_L72X3;
    case 312: goto l_L71X3;
    case 313: goto l_L70X3;
    case 314: goto l_L69X3;
    case 315: goto l_L68X3;
    case 316: goto l_L67X3;
    case 317: goto l_L66X3;
    case 318: goto l_L65X3;
    case 319: goto l_L64X3;
    case 320: goto l_L63X3;
    case 321: goto l_L62X3;
    case 322: goto l_L78X3;
    case 324: goto l_lr_223;
    case 325: goto l_L59X3;
    case 326: goto l_L57X3;
    case 327:
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
  reg_l0_0 = (359 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1738 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 2724 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2725 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2726 */
} /* line 2726 */
  sim_icache_fetch(1743 + t_thisfile.offset, 1);
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
} /* line 2728 */
  sim_icache_fetch(1744 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2730 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2731 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2732 */
} /* line 2732 */
  sim_icache_fetch(1747 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_11357Xbuf); /* line 2734 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_11357Xbuf),0,1)); /* line 2735 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_11357Xbuf + (unsigned int) 1)); /* line 2736 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2737 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2738 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2739 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2740 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2741 */
} /* line 2741 */
  sim_icache_fetch(1760 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2743 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2744 */
} /* line 2744 */
  sim_icache_fetch(1762 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2746 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2747 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2748 */
} /* line 2748 */
  sim_icache_fetch(1765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2750 */
} /* line 2750 */
  sim_icache_fetch(1766 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_11357Xbuf),0,1), reg_r0_2); /* line 2752 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L164X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2753 */
  sim_icache_fetch(1769 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2755 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2756 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2757 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2758 */
} /* line 2758 */
l_L164X3: ;/* line 2760 */
__LABEL(l_L164X3);
  sim_icache_fetch(1773 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2761 */
   __MOV(reg_r0_3, (unsigned int) compress_11357Xbuf); /* line 2762 */
} /* line 2762 */
  sim_icache_fetch(1776 + t_thisfile.offset, 1);
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
} /* line 2764 */
  sim_icache_fetch(1777 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2766 */
} /* line 2766 */
l_L165X3: ;/* line 2768 */
__LABEL(l_L165X3);
  sim_icache_fetch(1778 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 2769 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2770 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2771 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2772 */
   __ADD_CYCLES(1);
} /* line 2772 */
  sim_icache_fetch(1785 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2774 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2775 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2776 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2777 */
} /* line 2777 */
  sim_icache_fetch(1789 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_11357Xoffset,0,4), reg_r0_2); /* line 2779 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2780 */
} /* line 2780 */
  sim_icache_fetch(1792 + t_thisfile.offset, 1);
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
} /* line 2782 */
  sim_icache_fetch(1793 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2784 */
} /* line 2784 */
l_L167X3: ;/* line 2787 */
__LABEL(l_L167X3);
  sim_icache_fetch(1795 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2788 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2789 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2790 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2791 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2792 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2793 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2794 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2795 */
} /* line 2795 */
  sim_icache_fetch(1804 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2797 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2798 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -16); /* line 2799 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 16); /* line 2800 */
} /* line 2800 */
  sim_icache_fetch(1808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2802 */
} /* line 2802 */
  sim_icache_fetch(1809 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2804 */
} /* line 2804 */
  sim_icache_fetch(1811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2806 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2807 */
  sim_icache_fetch(1813 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2809 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2810 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2811 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2812 */
   __ADD_CYCLES(1);
} /* line 2812 */
  sim_icache_fetch(1818 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2814 */
} /* line 2814 */
  sim_icache_fetch(1819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2816 */
} /* line 2816 */
  sim_icache_fetch(1821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2818 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2819 */
  sim_icache_fetch(1823 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2821 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2822 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2823 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2824 */
   __ADD_CYCLES(1);
} /* line 2824 */
  sim_icache_fetch(1828 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2826 */
} /* line 2826 */
  sim_icache_fetch(1829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2828 */
} /* line 2828 */
  sim_icache_fetch(1831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2830 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2831 */
  sim_icache_fetch(1833 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2833 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2834 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2835 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2836 */
   __ADD_CYCLES(1);
} /* line 2836 */
  sim_icache_fetch(1838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2838 */
} /* line 2838 */
  sim_icache_fetch(1839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2840 */
} /* line 2840 */
  sim_icache_fetch(1841 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2842 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2843 */
  sim_icache_fetch(1843 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2845 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2846 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2847 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2848 */
   __ADD_CYCLES(1);
} /* line 2848 */
  sim_icache_fetch(1848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2850 */
} /* line 2850 */
  sim_icache_fetch(1849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2852 */
} /* line 2852 */
  sim_icache_fetch(1851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2854 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2855 */
  sim_icache_fetch(1853 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2857 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2858 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2859 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2860 */
   __ADD_CYCLES(1);
} /* line 2860 */
  sim_icache_fetch(1858 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2862 */
} /* line 2862 */
  sim_icache_fetch(1859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2864 */
} /* line 2864 */
  sim_icache_fetch(1861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2866 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2867 */
  sim_icache_fetch(1863 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2869 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2870 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2871 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2872 */
   __ADD_CYCLES(1);
} /* line 2872 */
  sim_icache_fetch(1868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2874 */
} /* line 2874 */
  sim_icache_fetch(1869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2876 */
} /* line 2876 */
  sim_icache_fetch(1871 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2878 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2879 */
  sim_icache_fetch(1873 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2881 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2882 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2883 */
   __ADD(reg_r0_5, reg_r0_7, (unsigned int) -16); /* line 2884 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2885 */
   __ADD_CYCLES(1);
} /* line 2885 */
  sim_icache_fetch(1879 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2887 */
} /* line 2887 */
  sim_icache_fetch(1880 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2889 */
} /* line 2889 */
  sim_icache_fetch(1882 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2891 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2892 */
  sim_icache_fetch(1884 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2894 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2895 */
   __CMPEQ(reg_b0_7, reg_r0_7, 0); /* line 2896 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2897 */
   __ADD_CYCLES(1);
} /* line 2897 */
  sim_icache_fetch(1889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2899 */
} /* line 2899 */
  sim_icache_fetch(1890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2901 */
} /* line 2901 */
  sim_icache_fetch(1892 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2903 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2904 */
  sim_icache_fetch(1894 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 2906 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2907 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2908 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2909 */
   __ADD_CYCLES(1);
} /* line 2909 */
  sim_icache_fetch(1899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2911 */
} /* line 2911 */
  sim_icache_fetch(1900 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2913 */
} /* line 2913 */
  sim_icache_fetch(1902 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2915 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2916 */
  sim_icache_fetch(1904 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 2918 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2919 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2920 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2921 */
   __ADD_CYCLES(1);
} /* line 2921 */
  sim_icache_fetch(1909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2923 */
} /* line 2923 */
  sim_icache_fetch(1910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2925 */
} /* line 2925 */
  sim_icache_fetch(1912 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2927 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2928 */
  sim_icache_fetch(1914 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 2930 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2931 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2932 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2933 */
   __ADD_CYCLES(1);
} /* line 2933 */
  sim_icache_fetch(1919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2935 */
} /* line 2935 */
  sim_icache_fetch(1920 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2937 */
} /* line 2937 */
  sim_icache_fetch(1922 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2939 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2940 */
  sim_icache_fetch(1924 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 2942 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2943 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 4); /* line 2944 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2945 */
   __ADD_CYCLES(1);
} /* line 2945 */
  sim_icache_fetch(1929 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2947 */
} /* line 2947 */
  sim_icache_fetch(1930 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2949 */
} /* line 2949 */
  sim_icache_fetch(1932 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2951 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2952 */
  sim_icache_fetch(1934 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 2954 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2955 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 5); /* line 2956 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2957 */
   __ADD_CYCLES(1);
} /* line 2957 */
  sim_icache_fetch(1939 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2959 */
} /* line 2959 */
  sim_icache_fetch(1940 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2961 */
} /* line 2961 */
  sim_icache_fetch(1942 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2963 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2964 */
  sim_icache_fetch(1944 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 2966 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2967 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 6); /* line 2968 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2969 */
   __ADD_CYCLES(1);
} /* line 2969 */
  sim_icache_fetch(1949 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2971 */
} /* line 2971 */
  sim_icache_fetch(1950 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2973 */
} /* line 2973 */
  sim_icache_fetch(1952 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2975 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2976 */
  sim_icache_fetch(1954 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 2978 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2979 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 7); /* line 2980 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2981 */
   __ADD_CYCLES(1);
} /* line 2981 */
  sim_icache_fetch(1959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 2983 */
} /* line 2983 */
  sim_icache_fetch(1960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 2985 */
} /* line 2985 */
  sim_icache_fetch(1962 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2987 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 2988 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2989 */
  sim_icache_fetch(1965 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 2991 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2992 */
   __CMPEQ(reg_b0_7, reg_r0_7, (unsigned int) 8); /* line 2993 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) 16); /* line 2994 */
   __MFB(reg_r0_8, t__i32_0); /* line 2995 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2996 */
   __ADD_CYCLES(1);
} /* line 2996 */
  sim_icache_fetch(1972 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 2998 */
} /* line 2998 */
  sim_icache_fetch(1973 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3000 */
} /* line 3000 */
  sim_icache_fetch(1975 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3002 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3003 */
  sim_icache_fetch(1977 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 3005 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3006 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 9); /* line 3007 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3008 */
   __ADD_CYCLES(1);
} /* line 3008 */
  sim_icache_fetch(1982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3010 */
} /* line 3010 */
  sim_icache_fetch(1983 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3012 */
} /* line 3012 */
  sim_icache_fetch(1985 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3014 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3015 */
  sim_icache_fetch(1987 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 2),0,1)); /* line 3017 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3018 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 10); /* line 3019 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3020 */
   __ADD_CYCLES(1);
} /* line 3020 */
  sim_icache_fetch(1992 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3022 */
} /* line 3022 */
  sim_icache_fetch(1993 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3024 */
} /* line 3024 */
  sim_icache_fetch(1995 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3026 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3027 */
  sim_icache_fetch(1997 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 3),0,1)); /* line 3029 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3030 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 11); /* line 3031 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3032 */
   __ADD_CYCLES(1);
} /* line 3032 */
  sim_icache_fetch(2002 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3034 */
} /* line 3034 */
  sim_icache_fetch(2003 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3036 */
} /* line 3036 */
  sim_icache_fetch(2005 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3038 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3039 */
  sim_icache_fetch(2007 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 4),0,1)); /* line 3041 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3042 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 12); /* line 3043 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3044 */
   __ADD_CYCLES(1);
} /* line 3044 */
  sim_icache_fetch(2012 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3046 */
} /* line 3046 */
  sim_icache_fetch(2013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3048 */
} /* line 3048 */
  sim_icache_fetch(2015 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3050 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3051 */
  sim_icache_fetch(2017 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 5),0,1)); /* line 3053 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3054 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 13); /* line 3055 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3056 */
   __ADD_CYCLES(1);
} /* line 3056 */
  sim_icache_fetch(2022 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3058 */
} /* line 3058 */
  sim_icache_fetch(2023 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3060 */
} /* line 3060 */
  sim_icache_fetch(2025 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3062 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3063 */
  sim_icache_fetch(2027 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 6),0,1)); /* line 3065 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3066 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 14); /* line 3067 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3068 */
   __ADD_CYCLES(1);
} /* line 3068 */
  sim_icache_fetch(2032 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3070 */
} /* line 3070 */
  sim_icache_fetch(2033 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3072 */
} /* line 3072 */
  sim_icache_fetch(2035 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3074 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3075 */
  sim_icache_fetch(2037 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 7),0,1)); /* line 3077 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3078 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 15); /* line 3079 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3080 */
   __ADD_CYCLES(1);
} /* line 3080 */
  sim_icache_fetch(2042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3082 */
} /* line 3082 */
  sim_icache_fetch(2043 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3084 */
} /* line 3084 */
  sim_icache_fetch(2045 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3086 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3087 */
  sim_icache_fetch(2047 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 8),0,1)); /* line 3089 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3090 */
   __MTB(reg_b0_7, reg_r0_8); /* line 3091 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3092 */
   __ADD_CYCLES(1);
} /* line 3092 */
  sim_icache_fetch(2052 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3094 */
} /* line 3094 */
  sim_icache_fetch(2053 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3096 */
} /* line 3096 */
  sim_icache_fetch(2055 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3098 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3099 */
  sim_icache_fetch(2057 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 9),0,1)); /* line 3101 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3102 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3103 */
   __ADD_CYCLES(1);
} /* line 3103 */
  sim_icache_fetch(2061 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3105 */
} /* line 3105 */
  sim_icache_fetch(2062 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3107 */
} /* line 3107 */
  sim_icache_fetch(2064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3109 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3110 */
  sim_icache_fetch(2066 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 10),0,1)); /* line 3112 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3113 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3114 */
   __ADD_CYCLES(1);
} /* line 3114 */
  sim_icache_fetch(2070 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3116 */
} /* line 3116 */
  sim_icache_fetch(2071 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3118 */
} /* line 3118 */
  sim_icache_fetch(2073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3120 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3121 */
  sim_icache_fetch(2075 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 11),0,1)); /* line 3123 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3124 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3125 */
   __ADD_CYCLES(1);
} /* line 3125 */
  sim_icache_fetch(2079 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3127 */
} /* line 3127 */
  sim_icache_fetch(2080 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3129 */
} /* line 3129 */
  sim_icache_fetch(2082 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3131 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3132 */
  sim_icache_fetch(2084 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 12),0,1)); /* line 3134 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3135 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3136 */
   __ADD_CYCLES(1);
} /* line 3136 */
  sim_icache_fetch(2088 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3138 */
} /* line 3138 */
  sim_icache_fetch(2089 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3140 */
} /* line 3140 */
  sim_icache_fetch(2091 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3142 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3143 */
  sim_icache_fetch(2093 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 13),0,1)); /* line 3145 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3146 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3147 */
   __ADD_CYCLES(1);
} /* line 3147 */
  sim_icache_fetch(2097 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3149 */
} /* line 3149 */
  sim_icache_fetch(2098 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3151 */
} /* line 3151 */
  sim_icache_fetch(2100 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3153 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3154 */
  sim_icache_fetch(2102 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 14),0,1)); /* line 3156 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3157 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3158 */
   __ADD_CYCLES(1);
} /* line 3158 */
  sim_icache_fetch(2106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3160 */
} /* line 3160 */
  sim_icache_fetch(2107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3162 */
} /* line 3162 */
  sim_icache_fetch(2109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3164 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3165 */
  sim_icache_fetch(2111 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 15),0,1)); /* line 3167 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3168 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3169 */
   __ADD_CYCLES(1);
} /* line 3169 */
  sim_icache_fetch(2115 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3171 */
} /* line 3171 */
  sim_icache_fetch(2116 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3173 */
} /* line 3173 */
  sim_icache_fetch(2118 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 3175 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3177 */
  sim_icache_fetch(2120 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 3179 */
l_L168X3: ;/* line 3182 */
__LABEL(l_L168X3);
  sim_icache_fetch(2121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_11357Xoffset,0,4), 0); /* line 3183 */
} /* line 3183 */
l_L166X3: ;/* line 3186 */
__LABEL(l_L166X3);
  sim_icache_fetch(2123 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3187 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3188 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3189 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3190 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3191 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3192 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3193 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3194 */
} /* line 3194 */
  sim_icache_fetch(2135 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3196 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3197 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3198 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3199 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3200 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3201 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3202 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3203 */
} /* line 3203 */
  sim_icache_fetch(2143 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3205 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3206 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3207 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3208 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3209 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3210 */
   __MOV(reg_r0_5, (unsigned int) compress_11357Xbuf); /* line 3211 */
   __MOV(reg_r0_3, 0); /* line 3212 */
} /* line 3212 */
  sim_icache_fetch(2152 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3214 */
} /* line 3214 */
  sim_icache_fetch(2153 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L169X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3216 */
  sim_icache_fetch(2154 + t_thisfile.offset, 1);
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
} /* line 3218 */
l_L171X3: ;/* line 3221 */
__LABEL(l_L171X3);
  sim_icache_fetch(2155 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3222 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3223 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3224 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3225 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3226 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3227 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3228 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3229 */
} /* line 3229 */
  sim_icache_fetch(2165 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3231 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3232 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3233 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3234 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3235 */
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3236 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3237 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3238 */
} /* line 3238 */
  sim_icache_fetch(2173 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3240 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3241 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3242 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3243 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3244 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3245 */
} /* line 3245 */
  sim_icache_fetch(2179 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3247 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L172X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3248 */
  sim_icache_fetch(2181 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3250 */
} /* line 3250 */
  sim_icache_fetch(2183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3252 */
} /* line 3252 */
  sim_icache_fetch(2184 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3254 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3255 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3256 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3257 */
   __ADD_CYCLES(1);
} /* line 3257 */
  sim_icache_fetch(2190 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 3259 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3260 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3261 */
} /* line 3261 */
  sim_icache_fetch(2193 + t_thisfile.offset, 1);
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
} /* line 3263 */
  sim_icache_fetch(2194 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3265 */
} /* line 3265 */
  sim_icache_fetch(2196 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3267 */
} /* line 3267 */
  sim_icache_fetch(2197 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3269 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3270 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3271 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3272 */
   __ADD_CYCLES(1);
} /* line 3272 */
  sim_icache_fetch(2203 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 3274 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3275 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3276 */
} /* line 3276 */
  sim_icache_fetch(2206 + t_thisfile.offset, 1);
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
} /* line 3278 */
  sim_icache_fetch(2207 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3280 */
} /* line 3280 */
  sim_icache_fetch(2209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3282 */
} /* line 3282 */
  sim_icache_fetch(2210 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3284 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3285 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3286 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3287 */
   __ADD_CYCLES(1);
} /* line 3287 */
  sim_icache_fetch(2216 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 3289 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3290 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3291 */
} /* line 3291 */
  sim_icache_fetch(2219 + t_thisfile.offset, 1);
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
} /* line 3293 */
  sim_icache_fetch(2220 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3295 */
} /* line 3295 */
  sim_icache_fetch(2222 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3297 */
} /* line 3297 */
  sim_icache_fetch(2223 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3299 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3300 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3301 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3302 */
   __ADD_CYCLES(1);
} /* line 3302 */
  sim_icache_fetch(2229 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 3304 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3305 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3306 */
} /* line 3306 */
  sim_icache_fetch(2232 + t_thisfile.offset, 1);
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
} /* line 3308 */
  sim_icache_fetch(2233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3310 */
} /* line 3310 */
  sim_icache_fetch(2235 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3312 */
} /* line 3312 */
  sim_icache_fetch(2236 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3314 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3315 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3316 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3317 */
   __ADD_CYCLES(1);
} /* line 3317 */
  sim_icache_fetch(2242 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 3319 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3320 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3321 */
} /* line 3321 */
  sim_icache_fetch(2245 + t_thisfile.offset, 1);
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
} /* line 3323 */
  sim_icache_fetch(2246 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3325 */
} /* line 3325 */
  sim_icache_fetch(2248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3327 */
} /* line 3327 */
  sim_icache_fetch(2249 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3329 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3330 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3331 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3332 */
   __ADD_CYCLES(1);
} /* line 3332 */
  sim_icache_fetch(2255 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 3334 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3335 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3336 */
} /* line 3336 */
  sim_icache_fetch(2258 + t_thisfile.offset, 1);
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
} /* line 3338 */
  sim_icache_fetch(2259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3340 */
} /* line 3340 */
  sim_icache_fetch(2261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3342 */
} /* line 3342 */
  sim_icache_fetch(2262 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3344 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3345 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3346 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3347 */
   __ADD_CYCLES(1);
} /* line 3347 */
  sim_icache_fetch(2268 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 3349 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3350 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3351 */
} /* line 3351 */
  sim_icache_fetch(2271 + t_thisfile.offset, 1);
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
} /* line 3353 */
  sim_icache_fetch(2272 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3355 */
} /* line 3355 */
  sim_icache_fetch(2274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3357 */
} /* line 3357 */
  sim_icache_fetch(2275 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3359 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3360 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3361 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3362 */
   __ADD_CYCLES(1);
} /* line 3362 */
  sim_icache_fetch(2281 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 3364 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3365 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3366 */
} /* line 3366 */
  sim_icache_fetch(2284 + t_thisfile.offset, 1);
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
} /* line 3368 */
  sim_icache_fetch(2285 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3370 */
} /* line 3370 */
  sim_icache_fetch(2287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3372 */
} /* line 3372 */
  sim_icache_fetch(2288 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3374 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3375 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3376 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3377 */
   __ADD_CYCLES(1);
} /* line 3377 */
  sim_icache_fetch(2294 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 3379 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3380 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3381 */
} /* line 3381 */
  sim_icache_fetch(2297 + t_thisfile.offset, 1);
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
} /* line 3383 */
  sim_icache_fetch(2298 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3385 */
} /* line 3385 */
  sim_icache_fetch(2300 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3387 */
} /* line 3387 */
  sim_icache_fetch(2301 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3389 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3390 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3391 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3392 */
   __ADD_CYCLES(1);
} /* line 3392 */
  sim_icache_fetch(2307 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 3394 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3395 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3396 */
} /* line 3396 */
  sim_icache_fetch(2310 + t_thisfile.offset, 1);
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
} /* line 3398 */
  sim_icache_fetch(2311 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3400 */
} /* line 3400 */
  sim_icache_fetch(2313 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3402 */
} /* line 3402 */
  sim_icache_fetch(2314 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3404 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3405 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3406 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3407 */
   __ADD_CYCLES(1);
} /* line 3407 */
  sim_icache_fetch(2320 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 3409 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3410 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3411 */
} /* line 3411 */
  sim_icache_fetch(2323 + t_thisfile.offset, 1);
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
} /* line 3413 */
  sim_icache_fetch(2324 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3415 */
} /* line 3415 */
  sim_icache_fetch(2326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3417 */
} /* line 3417 */
  sim_icache_fetch(2327 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3419 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3420 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3421 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3422 */
   __ADD_CYCLES(1);
} /* line 3422 */
  sim_icache_fetch(2333 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 3424 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3425 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3426 */
} /* line 3426 */
  sim_icache_fetch(2336 + t_thisfile.offset, 1);
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
} /* line 3428 */
  sim_icache_fetch(2337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3430 */
} /* line 3430 */
  sim_icache_fetch(2339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3432 */
} /* line 3432 */
  sim_icache_fetch(2340 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3434 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3435 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3436 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3437 */
   __ADD_CYCLES(1);
} /* line 3437 */
  sim_icache_fetch(2346 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 3439 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3440 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3441 */
} /* line 3441 */
  sim_icache_fetch(2349 + t_thisfile.offset, 1);
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
} /* line 3443 */
  sim_icache_fetch(2350 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3445 */
} /* line 3445 */
  sim_icache_fetch(2352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3447 */
} /* line 3447 */
  sim_icache_fetch(2353 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3449 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3450 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3451 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3452 */
   __ADD_CYCLES(1);
} /* line 3452 */
  sim_icache_fetch(2359 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_2); /* line 3454 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3455 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3456 */
} /* line 3456 */
  sim_icache_fetch(2362 + t_thisfile.offset, 1);
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
} /* line 3458 */
  sim_icache_fetch(2363 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3460 */
} /* line 3460 */
  sim_icache_fetch(2365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3462 */
} /* line 3462 */
  sim_icache_fetch(2366 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3464 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3465 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3466 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3467 */
   __ADD_CYCLES(1);
} /* line 3467 */
  sim_icache_fetch(2372 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_2); /* line 3469 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3470 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3471 */
} /* line 3471 */
  sim_icache_fetch(2375 + t_thisfile.offset, 1);
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
} /* line 3473 */
  sim_icache_fetch(2376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3475 */
} /* line 3475 */
  sim_icache_fetch(2378 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_5); /* line 3477 */
} /* line 3477 */
  sim_icache_fetch(2379 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3479 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_37,0,1)); /* line 3480 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3481 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3482 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3483 */
   __ADD_CYCLES(1);
} /* line 3483 */
  sim_icache_fetch(2386 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3485 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3486 */
   __MOV(reg_r0_3, reg_r0_38); /* line 3487 */
} /* line 3487 */
  sim_icache_fetch(2389 + t_thisfile.offset, 1);
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
} /* line 3489 */
  sim_icache_fetch(2390 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3491 */
} /* line 3491 */
  sim_icache_fetch(2392 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3493 */
} /* line 3493 */
  sim_icache_fetch(2393 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3495 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3496 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3497 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3498 */
   __ADD_CYCLES(1);
} /* line 3498 */
  sim_icache_fetch(2399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3500 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3501 */
} /* line 3501 */
  sim_icache_fetch(2401 + t_thisfile.offset, 1);
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
} /* line 3503 */
  sim_icache_fetch(2402 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3505 */
} /* line 3505 */
  sim_icache_fetch(2404 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3507 */
} /* line 3507 */
  sim_icache_fetch(2405 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3509 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3510 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3511 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3512 */
   __ADD_CYCLES(1);
} /* line 3512 */
  sim_icache_fetch(2411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3514 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3515 */
} /* line 3515 */
  sim_icache_fetch(2413 + t_thisfile.offset, 1);
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
} /* line 3517 */
  sim_icache_fetch(2414 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3519 */
} /* line 3519 */
  sim_icache_fetch(2416 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3521 */
} /* line 3521 */
  sim_icache_fetch(2417 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3523 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3524 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3525 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3526 */
   __ADD_CYCLES(1);
} /* line 3526 */
  sim_icache_fetch(2423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3528 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3529 */
} /* line 3529 */
  sim_icache_fetch(2425 + t_thisfile.offset, 1);
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
} /* line 3531 */
  sim_icache_fetch(2426 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3533 */
} /* line 3533 */
  sim_icache_fetch(2428 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3535 */
} /* line 3535 */
  sim_icache_fetch(2429 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3537 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3538 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3539 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3540 */
   __ADD_CYCLES(1);
} /* line 3540 */
  sim_icache_fetch(2435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3542 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3543 */
} /* line 3543 */
  sim_icache_fetch(2437 + t_thisfile.offset, 1);
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
} /* line 3545 */
  sim_icache_fetch(2438 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3547 */
} /* line 3547 */
  sim_icache_fetch(2440 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3549 */
} /* line 3549 */
  sim_icache_fetch(2441 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3551 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3552 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3553 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3554 */
   __ADD_CYCLES(1);
} /* line 3554 */
  sim_icache_fetch(2447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3556 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3557 */
} /* line 3557 */
  sim_icache_fetch(2449 + t_thisfile.offset, 1);
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
} /* line 3559 */
  sim_icache_fetch(2450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3561 */
} /* line 3561 */
  sim_icache_fetch(2452 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3563 */
} /* line 3563 */
  sim_icache_fetch(2453 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3565 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3566 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3567 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3568 */
   __ADD_CYCLES(1);
} /* line 3568 */
  sim_icache_fetch(2459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3570 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3571 */
} /* line 3571 */
  sim_icache_fetch(2461 + t_thisfile.offset, 1);
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
} /* line 3573 */
  sim_icache_fetch(2462 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3575 */
} /* line 3575 */
  sim_icache_fetch(2464 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3577 */
} /* line 3577 */
  sim_icache_fetch(2465 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3579 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3580 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3581 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3582 */
   __ADD_CYCLES(1);
} /* line 3582 */
  sim_icache_fetch(2471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3584 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3585 */
} /* line 3585 */
  sim_icache_fetch(2473 + t_thisfile.offset, 1);
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
} /* line 3587 */
  sim_icache_fetch(2474 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3589 */
} /* line 3589 */
  sim_icache_fetch(2476 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3591 */
} /* line 3591 */
  sim_icache_fetch(2477 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3593 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3594 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3595 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3596 */
   __ADD_CYCLES(1);
} /* line 3596 */
  sim_icache_fetch(2483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3598 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3599 */
} /* line 3599 */
  sim_icache_fetch(2485 + t_thisfile.offset, 1);
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
} /* line 3601 */
  sim_icache_fetch(2486 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3603 */
} /* line 3603 */
  sim_icache_fetch(2488 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3605 */
} /* line 3605 */
  sim_icache_fetch(2489 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3607 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3608 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3609 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3610 */
   __ADD_CYCLES(1);
} /* line 3610 */
  sim_icache_fetch(2495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3612 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3613 */
} /* line 3613 */
  sim_icache_fetch(2497 + t_thisfile.offset, 1);
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
} /* line 3615 */
  sim_icache_fetch(2498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3617 */
} /* line 3617 */
  sim_icache_fetch(2500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3619 */
} /* line 3619 */
  sim_icache_fetch(2501 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3621 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3622 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3623 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3624 */
   __ADD_CYCLES(1);
} /* line 3624 */
  sim_icache_fetch(2507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3626 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3627 */
} /* line 3627 */
  sim_icache_fetch(2509 + t_thisfile.offset, 1);
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
} /* line 3629 */
  sim_icache_fetch(2510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3631 */
} /* line 3631 */
  sim_icache_fetch(2512 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3633 */
} /* line 3633 */
  sim_icache_fetch(2513 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3635 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3636 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3637 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3638 */
   __ADD_CYCLES(1);
} /* line 3638 */
  sim_icache_fetch(2519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3640 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3641 */
} /* line 3641 */
  sim_icache_fetch(2521 + t_thisfile.offset, 1);
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
} /* line 3643 */
  sim_icache_fetch(2522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3645 */
} /* line 3645 */
  sim_icache_fetch(2524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3647 */
} /* line 3647 */
  sim_icache_fetch(2525 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3649 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3650 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3651 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3652 */
   __ADD_CYCLES(1);
} /* line 3652 */
  sim_icache_fetch(2531 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3654 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3655 */
} /* line 3655 */
  sim_icache_fetch(2533 + t_thisfile.offset, 1);
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
} /* line 3657 */
  sim_icache_fetch(2534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3659 */
} /* line 3659 */
  sim_icache_fetch(2536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3661 */
} /* line 3661 */
  sim_icache_fetch(2537 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3663 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3664 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3665 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3666 */
   __ADD_CYCLES(1);
} /* line 3666 */
  sim_icache_fetch(2543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3668 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3669 */
} /* line 3669 */
  sim_icache_fetch(2545 + t_thisfile.offset, 1);
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
} /* line 3671 */
  sim_icache_fetch(2546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3673 */
} /* line 3673 */
  sim_icache_fetch(2548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3675 */
} /* line 3675 */
  sim_icache_fetch(2549 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3677 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3678 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3679 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3680 */
   __ADD_CYCLES(1);
} /* line 3680 */
  sim_icache_fetch(2555 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3682 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3683 */
} /* line 3683 */
  sim_icache_fetch(2557 + t_thisfile.offset, 1);
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
} /* line 3685 */
  sim_icache_fetch(2558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3687 */
} /* line 3687 */
  sim_icache_fetch(2560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3689 */
} /* line 3689 */
  sim_icache_fetch(2561 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3691 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3692 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3693 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3694 */
   __ADD_CYCLES(1);
} /* line 3694 */
  sim_icache_fetch(2567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3696 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3697 */
} /* line 3697 */
  sim_icache_fetch(2569 + t_thisfile.offset, 1);
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
} /* line 3699 */
  sim_icache_fetch(2570 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3701 */
} /* line 3701 */
  sim_icache_fetch(2572 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3703 */
   __GOTO(l_L171X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L171X3;
} /* line 3704 */
l_L172X3: ;/* line 3707 */
__LABEL(l_L172X3);
  sim_icache_fetch(2574 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3708 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3709 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3710 */
   __ADD_CYCLES(1);
} /* line 3710 */
  sim_icache_fetch(2579 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3712 */
} /* line 3712 */
  sim_icache_fetch(2580 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3714 */
} /* line 3714 */
l_L170X3: ;/* line 3717 */
__LABEL(l_L170X3);
  sim_icache_fetch(2582 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_11357Xoffset,0,4), 0); /* line 3718 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3719 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3720 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3721 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3722 */
   __ADD_CYCLES(1);
} /* line 3722 */
  sim_icache_fetch(2590 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3724 */
} /* line 3724 */
  sim_icache_fetch(2591 + t_thisfile.offset, 1);
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
} /* line 3726 */
  sim_icache_fetch(2592 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3729 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3730 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3731 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3732 */
l_L173X3: ;/* line 3735 */
__LABEL(l_L173X3);
  sim_icache_fetch(2599 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3736 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3737 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3738 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3739 */
   __ADD_CYCLES(1);
} /* line 3739 */
  sim_icache_fetch(2606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3741 */
} /* line 3741 */
  sim_icache_fetch(2607 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3743 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3744 */
} /* line 3744 */
  sim_icache_fetch(2610 + t_thisfile.offset, 1);
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
} /* line 3746 */
  sim_icache_fetch(2611 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3749 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3750 */
l_L174X3: ;/* line 3753 */
__LABEL(l_L174X3);
  sim_icache_fetch(2614 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3754 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3755 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3756 */
   __ADD_CYCLES(1);
} /* line 3756 */
  sim_icache_fetch(2618 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3758 */
} /* line 3758 */
  sim_icache_fetch(2619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3760 */
} /* line 3760 */
  sim_icache_fetch(2620 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3763 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3764 */
l_L169X3: ;/* line 3767 */
__LABEL(l_L169X3);
  sim_icache_fetch(2623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3769 */
l_L163X3: ;/* line 3772 */
__LABEL(l_L163X3);
  sim_icache_fetch(2624 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3773 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3774 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3775 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3776 */
   __ADD_CYCLES(1);
} /* line 3776 */
  sim_icache_fetch(2631 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3778 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3779 */
} /* line 3779 */
  sim_icache_fetch(2633 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3781 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3782 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L175X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3783 */
l_L176X3: ;/* line 3785 */
__LABEL(l_L176X3);
  sim_icache_fetch(2636 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3786 */
   __STW(mem_trace_st((unsigned int) compress_11357Xoffset,0,4), 0); /* line 3787 */
} /* line 3787 */
  sim_icache_fetch(2639 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3789 */
} /* line 3789 */
  sim_icache_fetch(2640 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3791 */
} /* line 3791 */
  sim_icache_fetch(2641 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3794 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3795 */
l_L175X3: ;/* line 3798 */
__LABEL(l_L175X3);
  sim_icache_fetch(2644 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3799 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3800 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3801 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3802 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3803 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3804 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3805 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3806 */
} /* line 3806 */
  sim_icache_fetch(2652 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3808 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3809 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3810 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3811 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3812 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3813 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3814 */
   __MOV(reg_r0_5, (unsigned int) compress_11357Xbuf); /* line 3815 */
} /* line 3815 */
  sim_icache_fetch(2661 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 3817 */
} /* line 3817 */
l_L177X3: ;/* line 3820 */
__LABEL(l_L177X3);
  sim_icache_fetch(2662 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3821 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3822 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3823 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3824 */
   __ADD_CYCLES(1);
} /* line 3824 */
  sim_icache_fetch(2668 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3826 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3827 */
} /* line 3827 */
  sim_icache_fetch(2670 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3829 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3830 */
} /* line 3830 */
  sim_icache_fetch(2672 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3832 */
} /* line 3832 */
  sim_icache_fetch(2673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3834 */
} /* line 3834 */
  sim_icache_fetch(2674 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3836 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3837 */
} /* line 3837 */
  sim_icache_fetch(2676 + t_thisfile.offset, 1);
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
} /* line 3839 */
  sim_icache_fetch(2677 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3841 */
} /* line 3841 */
  sim_icache_fetch(2679 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3843 */
} /* line 3843 */
  sim_icache_fetch(2680 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3845 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3846 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3847 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3848 */
   __ADD_CYCLES(1);
} /* line 3848 */
  sim_icache_fetch(2686 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3850 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3851 */
} /* line 3851 */
  sim_icache_fetch(2688 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3853 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3854 */
} /* line 3854 */
  sim_icache_fetch(2690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3856 */
} /* line 3856 */
  sim_icache_fetch(2691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3858 */
} /* line 3858 */
  sim_icache_fetch(2692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3860 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3861 */
} /* line 3861 */
  sim_icache_fetch(2694 + t_thisfile.offset, 1);
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
} /* line 3863 */
  sim_icache_fetch(2695 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3865 */
} /* line 3865 */
  sim_icache_fetch(2697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3867 */
} /* line 3867 */
  sim_icache_fetch(2698 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3869 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3870 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3871 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3872 */
   __ADD_CYCLES(1);
} /* line 3872 */
  sim_icache_fetch(2704 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3874 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3875 */
} /* line 3875 */
  sim_icache_fetch(2706 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3877 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3878 */
} /* line 3878 */
  sim_icache_fetch(2708 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3880 */
} /* line 3880 */
  sim_icache_fetch(2709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3882 */
} /* line 3882 */
  sim_icache_fetch(2710 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3884 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3885 */
} /* line 3885 */
  sim_icache_fetch(2712 + t_thisfile.offset, 1);
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
} /* line 3887 */
  sim_icache_fetch(2713 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3889 */
} /* line 3889 */
  sim_icache_fetch(2715 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3891 */
} /* line 3891 */
  sim_icache_fetch(2716 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3893 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3894 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3895 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3896 */
   __ADD_CYCLES(1);
} /* line 3896 */
  sim_icache_fetch(2722 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3898 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3899 */
} /* line 3899 */
  sim_icache_fetch(2724 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3901 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3902 */
} /* line 3902 */
  sim_icache_fetch(2726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3904 */
} /* line 3904 */
  sim_icache_fetch(2727 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3906 */
} /* line 3906 */
  sim_icache_fetch(2728 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 3908 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3909 */
} /* line 3909 */
  sim_icache_fetch(2730 + t_thisfile.offset, 1);
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
} /* line 3911 */
  sim_icache_fetch(2731 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3913 */
} /* line 3913 */
  sim_icache_fetch(2733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3915 */
} /* line 3915 */
  sim_icache_fetch(2734 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3917 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3918 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3919 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3920 */
   __ADD_CYCLES(1);
} /* line 3920 */
  sim_icache_fetch(2740 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3922 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3923 */
} /* line 3923 */
  sim_icache_fetch(2742 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3925 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3926 */
} /* line 3926 */
  sim_icache_fetch(2744 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3928 */
} /* line 3928 */
  sim_icache_fetch(2745 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3930 */
} /* line 3930 */
  sim_icache_fetch(2746 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 3932 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3933 */
} /* line 3933 */
  sim_icache_fetch(2748 + t_thisfile.offset, 1);
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
} /* line 3935 */
  sim_icache_fetch(2749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3937 */
} /* line 3937 */
  sim_icache_fetch(2751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3939 */
} /* line 3939 */
  sim_icache_fetch(2752 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3941 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3942 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3943 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3944 */
   __ADD_CYCLES(1);
} /* line 3944 */
  sim_icache_fetch(2758 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3946 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3947 */
} /* line 3947 */
  sim_icache_fetch(2760 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3949 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3950 */
} /* line 3950 */
  sim_icache_fetch(2762 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3952 */
} /* line 3952 */
  sim_icache_fetch(2763 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3954 */
} /* line 3954 */
  sim_icache_fetch(2764 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 3956 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3957 */
} /* line 3957 */
  sim_icache_fetch(2766 + t_thisfile.offset, 1);
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
} /* line 3959 */
  sim_icache_fetch(2767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3961 */
} /* line 3961 */
  sim_icache_fetch(2769 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3963 */
} /* line 3963 */
  sim_icache_fetch(2770 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3965 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3966 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3967 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3968 */
   __ADD_CYCLES(1);
} /* line 3968 */
  sim_icache_fetch(2776 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3970 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3971 */
} /* line 3971 */
  sim_icache_fetch(2778 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3973 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3974 */
} /* line 3974 */
  sim_icache_fetch(2780 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3976 */
} /* line 3976 */
  sim_icache_fetch(2781 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3978 */
} /* line 3978 */
  sim_icache_fetch(2782 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 3980 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 3981 */
} /* line 3981 */
  sim_icache_fetch(2784 + t_thisfile.offset, 1);
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
} /* line 3983 */
  sim_icache_fetch(2785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3985 */
} /* line 3985 */
  sim_icache_fetch(2787 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3987 */
} /* line 3987 */
  sim_icache_fetch(2788 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 3989 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3990 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3991 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3992 */
   __ADD_CYCLES(1);
} /* line 3992 */
  sim_icache_fetch(2794 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3994 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3995 */
} /* line 3995 */
  sim_icache_fetch(2796 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3997 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3998 */
} /* line 3998 */
  sim_icache_fetch(2798 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4000 */
} /* line 4000 */
  sim_icache_fetch(2799 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4002 */
} /* line 4002 */
  sim_icache_fetch(2800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4004 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4005 */
} /* line 4005 */
  sim_icache_fetch(2802 + t_thisfile.offset, 1);
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
} /* line 4007 */
  sim_icache_fetch(2803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4009 */
} /* line 4009 */
  sim_icache_fetch(2805 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4011 */
} /* line 4011 */
  sim_icache_fetch(2806 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4013 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4014 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4015 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4016 */
   __ADD_CYCLES(1);
} /* line 4016 */
  sim_icache_fetch(2812 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4018 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4019 */
} /* line 4019 */
  sim_icache_fetch(2814 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4021 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4022 */
} /* line 4022 */
  sim_icache_fetch(2816 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4024 */
} /* line 4024 */
  sim_icache_fetch(2817 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4026 */
} /* line 4026 */
  sim_icache_fetch(2818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4028 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4029 */
} /* line 4029 */
  sim_icache_fetch(2820 + t_thisfile.offset, 1);
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
} /* line 4031 */
  sim_icache_fetch(2821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4033 */
} /* line 4033 */
  sim_icache_fetch(2823 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4035 */
} /* line 4035 */
  sim_icache_fetch(2824 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4037 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4038 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4039 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4040 */
   __ADD_CYCLES(1);
} /* line 4040 */
  sim_icache_fetch(2830 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4042 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4043 */
} /* line 4043 */
  sim_icache_fetch(2832 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4045 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4046 */
} /* line 4046 */
  sim_icache_fetch(2834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4048 */
} /* line 4048 */
  sim_icache_fetch(2835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4050 */
} /* line 4050 */
  sim_icache_fetch(2836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4052 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4053 */
} /* line 4053 */
  sim_icache_fetch(2838 + t_thisfile.offset, 1);
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
} /* line 4055 */
  sim_icache_fetch(2839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4057 */
} /* line 4057 */
  sim_icache_fetch(2841 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4059 */
} /* line 4059 */
  sim_icache_fetch(2842 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4061 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4062 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4063 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4064 */
   __ADD_CYCLES(1);
} /* line 4064 */
  sim_icache_fetch(2848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4066 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4067 */
} /* line 4067 */
  sim_icache_fetch(2850 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4069 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4070 */
} /* line 4070 */
  sim_icache_fetch(2852 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4072 */
} /* line 4072 */
  sim_icache_fetch(2853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4074 */
} /* line 4074 */
  sim_icache_fetch(2854 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4076 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4077 */
} /* line 4077 */
  sim_icache_fetch(2856 + t_thisfile.offset, 1);
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
} /* line 4079 */
  sim_icache_fetch(2857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4081 */
} /* line 4081 */
  sim_icache_fetch(2859 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4083 */
} /* line 4083 */
  sim_icache_fetch(2860 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4085 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4086 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4087 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4088 */
   __ADD_CYCLES(1);
} /* line 4088 */
  sim_icache_fetch(2866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4090 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4091 */
} /* line 4091 */
  sim_icache_fetch(2868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4093 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4094 */
} /* line 4094 */
  sim_icache_fetch(2870 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4096 */
} /* line 4096 */
  sim_icache_fetch(2871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4098 */
} /* line 4098 */
  sim_icache_fetch(2872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4100 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4101 */
} /* line 4101 */
  sim_icache_fetch(2874 + t_thisfile.offset, 1);
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
} /* line 4103 */
  sim_icache_fetch(2875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4105 */
} /* line 4105 */
  sim_icache_fetch(2877 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4107 */
} /* line 4107 */
  sim_icache_fetch(2878 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4109 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4110 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4111 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4112 */
   __ADD_CYCLES(1);
} /* line 4112 */
  sim_icache_fetch(2884 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4114 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4115 */
} /* line 4115 */
  sim_icache_fetch(2886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4117 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4118 */
} /* line 4118 */
  sim_icache_fetch(2888 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4120 */
} /* line 4120 */
  sim_icache_fetch(2889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4122 */
} /* line 4122 */
  sim_icache_fetch(2890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4124 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4125 */
} /* line 4125 */
  sim_icache_fetch(2892 + t_thisfile.offset, 1);
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
} /* line 4127 */
  sim_icache_fetch(2893 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4129 */
} /* line 4129 */
  sim_icache_fetch(2895 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4131 */
} /* line 4131 */
  sim_icache_fetch(2896 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4133 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4134 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4135 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4136 */
   __ADD_CYCLES(1);
} /* line 4136 */
  sim_icache_fetch(2902 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4138 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4139 */
} /* line 4139 */
  sim_icache_fetch(2904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4141 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4142 */
} /* line 4142 */
  sim_icache_fetch(2906 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4144 */
} /* line 4144 */
  sim_icache_fetch(2907 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4146 */
} /* line 4146 */
  sim_icache_fetch(2908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4148 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4149 */
} /* line 4149 */
  sim_icache_fetch(2910 + t_thisfile.offset, 1);
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
} /* line 4151 */
  sim_icache_fetch(2911 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4153 */
} /* line 4153 */
  sim_icache_fetch(2913 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4155 */
} /* line 4155 */
  sim_icache_fetch(2914 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4157 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4158 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4159 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4160 */
   __ADD_CYCLES(1);
} /* line 4160 */
  sim_icache_fetch(2920 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4162 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4163 */
} /* line 4163 */
  sim_icache_fetch(2922 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4165 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4166 */
} /* line 4166 */
  sim_icache_fetch(2924 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4168 */
} /* line 4168 */
  sim_icache_fetch(2925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4170 */
} /* line 4170 */
  sim_icache_fetch(2926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4172 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4173 */
} /* line 4173 */
  sim_icache_fetch(2928 + t_thisfile.offset, 1);
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
} /* line 4175 */
  sim_icache_fetch(2929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4177 */
} /* line 4177 */
  sim_icache_fetch(2931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4179 */
} /* line 4179 */
  sim_icache_fetch(2932 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4181 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4182 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4183 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4184 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4185 */
   __ADD_CYCLES(1);
} /* line 4185 */
  sim_icache_fetch(2939 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4187 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4188 */
} /* line 4188 */
  sim_icache_fetch(2941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4190 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4191 */
} /* line 4191 */
  sim_icache_fetch(2943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4193 */
} /* line 4193 */
  sim_icache_fetch(2944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4195 */
} /* line 4195 */
  sim_icache_fetch(2945 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4197 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4198 */
} /* line 4198 */
  sim_icache_fetch(2947 + t_thisfile.offset, 1);
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
} /* line 4200 */
  sim_icache_fetch(2948 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4202 */
} /* line 4202 */
  sim_icache_fetch(2950 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4204 */
   __GOTO(l_L177X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L177X3;
} /* line 4205 */
l_L193X3: ;/* line 4208 */
__LABEL(l_L193X3);
  sim_icache_fetch(2952 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4209 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4210 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4211 */
   __ADD_CYCLES(1);
} /* line 4211 */
  sim_icache_fetch(2957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4213 */
} /* line 4213 */
  sim_icache_fetch(2958 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4215 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4216 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4217 */
l_L192X3: ;/* line 4220 */
__LABEL(l_L192X3);
  sim_icache_fetch(2961 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4221 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4222 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4223 */
   __ADD_CYCLES(1);
} /* line 4223 */
  sim_icache_fetch(2966 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4225 */
} /* line 4225 */
  sim_icache_fetch(2967 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4227 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4228 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4229 */
l_L191X3: ;/* line 4232 */
__LABEL(l_L191X3);
  sim_icache_fetch(2970 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4233 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4234 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4235 */
   __ADD_CYCLES(1);
} /* line 4235 */
  sim_icache_fetch(2975 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4237 */
} /* line 4237 */
  sim_icache_fetch(2976 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4239 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4240 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4241 */
l_L190X3: ;/* line 4244 */
__LABEL(l_L190X3);
  sim_icache_fetch(2979 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4245 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4246 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4247 */
   __ADD_CYCLES(1);
} /* line 4247 */
  sim_icache_fetch(2984 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4249 */
} /* line 4249 */
  sim_icache_fetch(2985 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4251 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4252 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4253 */
l_L189X3: ;/* line 4256 */
__LABEL(l_L189X3);
  sim_icache_fetch(2988 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4257 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4258 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4259 */
   __ADD_CYCLES(1);
} /* line 4259 */
  sim_icache_fetch(2993 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4261 */
} /* line 4261 */
  sim_icache_fetch(2994 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4263 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4264 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4265 */
l_L188X3: ;/* line 4268 */
__LABEL(l_L188X3);
  sim_icache_fetch(2997 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4269 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4270 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4271 */
   __ADD_CYCLES(1);
} /* line 4271 */
  sim_icache_fetch(3002 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4273 */
} /* line 4273 */
  sim_icache_fetch(3003 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4275 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4276 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4277 */
l_L187X3: ;/* line 4280 */
__LABEL(l_L187X3);
  sim_icache_fetch(3006 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4281 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4282 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4283 */
   __ADD_CYCLES(1);
} /* line 4283 */
  sim_icache_fetch(3011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4285 */
} /* line 4285 */
  sim_icache_fetch(3012 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4287 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4288 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4289 */
l_L186X3: ;/* line 4292 */
__LABEL(l_L186X3);
  sim_icache_fetch(3015 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4293 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4294 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4295 */
   __ADD_CYCLES(1);
} /* line 4295 */
  sim_icache_fetch(3020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4297 */
} /* line 4297 */
  sim_icache_fetch(3021 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4299 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4300 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4301 */
l_L185X3: ;/* line 4304 */
__LABEL(l_L185X3);
  sim_icache_fetch(3024 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4305 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4306 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4307 */
   __ADD_CYCLES(1);
} /* line 4307 */
  sim_icache_fetch(3029 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4309 */
} /* line 4309 */
  sim_icache_fetch(3030 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4311 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4312 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4313 */
l_L184X3: ;/* line 4316 */
__LABEL(l_L184X3);
  sim_icache_fetch(3033 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4317 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4318 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4319 */
   __ADD_CYCLES(1);
} /* line 4319 */
  sim_icache_fetch(3038 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4321 */
} /* line 4321 */
  sim_icache_fetch(3039 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4323 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4324 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4325 */
l_L183X3: ;/* line 4328 */
__LABEL(l_L183X3);
  sim_icache_fetch(3042 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4329 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4330 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4331 */
   __ADD_CYCLES(1);
} /* line 4331 */
  sim_icache_fetch(3047 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4333 */
} /* line 4333 */
  sim_icache_fetch(3048 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4335 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4336 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4337 */
l_L182X3: ;/* line 4340 */
__LABEL(l_L182X3);
  sim_icache_fetch(3051 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4341 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4342 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4343 */
   __ADD_CYCLES(1);
} /* line 4343 */
  sim_icache_fetch(3056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4345 */
} /* line 4345 */
  sim_icache_fetch(3057 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4347 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4348 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4349 */
l_L181X3: ;/* line 4352 */
__LABEL(l_L181X3);
  sim_icache_fetch(3060 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4353 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4354 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4355 */
   __ADD_CYCLES(1);
} /* line 4355 */
  sim_icache_fetch(3065 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4357 */
} /* line 4357 */
  sim_icache_fetch(3066 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4359 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4360 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4361 */
l_L180X3: ;/* line 4364 */
__LABEL(l_L180X3);
  sim_icache_fetch(3069 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4365 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4366 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4367 */
   __ADD_CYCLES(1);
} /* line 4367 */
  sim_icache_fetch(3074 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4369 */
} /* line 4369 */
  sim_icache_fetch(3075 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4371 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4372 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4373 */
l_L179X3: ;/* line 4376 */
__LABEL(l_L179X3);
  sim_icache_fetch(3078 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4377 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4378 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4379 */
   __ADD_CYCLES(1);
} /* line 4379 */
  sim_icache_fetch(3083 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4381 */
} /* line 4381 */
  sim_icache_fetch(3084 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4383 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4384 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4385 */
l_L178X3: ;/* line 4388 */
__LABEL(l_L178X3);
  sim_icache_fetch(3087 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4389 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_11357Xoffset,0,4)); /* line 4390 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4391 */
   __ADD_CYCLES(1);
} /* line 4391 */
  sim_icache_fetch(3092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4393 */
} /* line 4393 */
  sim_icache_fetch(3093 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4395 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4396 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4397 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 328: goto l_L164X3;
    case 329: goto l_L165X3;
    case 330: goto l_L167X3;
    case 331: goto l_L168X3;
    case 332: goto l_L166X3;
    case 333: goto l_L171X3;
    case 334: goto l_L172X3;
    case 335: goto l_L170X3;
    case 336: goto l_L173X3;
    case 337: goto l_L174X3;
    case 338: goto l_L169X3;
    case 339: goto l_L163X3;
    case 340: goto l_L176X3;
    case 341: goto l_L175X3;
    case 342: goto l_L177X3;
    case 343: goto l_L193X3;
    case 344: goto l_L192X3;
    case 345: goto l_L191X3;
    case 346: goto l_L190X3;
    case 347: goto l_L189X3;
    case 348: goto l_L188X3;
    case 349: goto l_L187X3;
    case 350: goto l_L186X3;
    case 351: goto l_L185X3;
    case 352: goto l_L184X3;
    case 353: goto l_L183X3;
    case 354: goto l_L182X3;
    case 355: goto l_L181X3;
    case 356: goto l_L180X3;
    case 357: goto l_L179X3;
    case 358: goto l_L178X3;
    case 359:
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
  reg_l0_0 = (413 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3096 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4413 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4414 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4415 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4416 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4417 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4418 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4419 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4420 */
} /* line 4420 */
  sim_icache_fetch(3105 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4422 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4423 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4424 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4425 */
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4426 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4427 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4428 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4429 */
} /* line 4429 */
  sim_icache_fetch(3113 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4431 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4432 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4433 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4434 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4435 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4436 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4437 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4438 */
} /* line 4438 */
  sim_icache_fetch(3124 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4440 */
} /* line 4440 */
l_L194X3: ;/* line 4443 */
__LABEL(l_L194X3);
  sim_icache_fetch(3126 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4444 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4445 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4446 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4447 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4448 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4449 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4450 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4451 */
} /* line 4451 */
  sim_icache_fetch(3134 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4453 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4454 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4455 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4456 */
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4457 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4458 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4459 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L195X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4460 */
  sim_icache_fetch(3142 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4462 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4463 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4464 */
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4465 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4466 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4467 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4468 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4469 */
} /* line 4469 */
  sim_icache_fetch(3150 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4471 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4472 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4473 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4474 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4475 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4476 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4477 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4478 */
} /* line 4478 */
  sim_icache_fetch(3158 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4480 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4481 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4482 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4483 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4484 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4485 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4486 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4487 */
} /* line 4487 */
  sim_icache_fetch(3166 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4489 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4490 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4491 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4492 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4493 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4494 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4495 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4496 */
} /* line 4496 */
  sim_icache_fetch(3174 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4498 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4499 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4500 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4501 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4502 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4503 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4504 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4505 */
} /* line 4505 */
  sim_icache_fetch(3182 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4507 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4508 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4509 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4510 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4511 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4512 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4513 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4514 */
} /* line 4514 */
  sim_icache_fetch(3190 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4516 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4517 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4518 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4519 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4520 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4521 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4522 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4523 */
} /* line 4523 */
  sim_icache_fetch(3198 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4525 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4526 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4527 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4528 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4529 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4530 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4531 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4532 */
} /* line 4532 */
  sim_icache_fetch(3206 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4534 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4535 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4536 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4537 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4538 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4539 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4540 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4541 */
} /* line 4541 */
  sim_icache_fetch(3214 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4543 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4544 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4545 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4546 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4547 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4548 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4549 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4550 */
} /* line 4550 */
  sim_icache_fetch(3222 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4552 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4553 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4554 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4555 */
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4556 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4557 */
   __GOTO(l_L194X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L194X3;
} /* line 4558 */
l_L195X3: ;/* line 4561 */
__LABEL(l_L195X3);
  sim_icache_fetch(3229 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4562 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4563 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4564 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4565 */
   __ADD_CYCLES(1);
} /* line 4565 */
  sim_icache_fetch(3235 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4567 */
} /* line 4567 */
  sim_icache_fetch(3236 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4569 */
} /* line 4569 */
		 /* line 4570 */
  sim_icache_fetch(3238 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4572 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (413 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4573 */
l_lr_262: ;/* line 4573 */
__LABEL(l_lr_262);
  sim_icache_fetch(3242 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_2, t__i32_0); /* line 4575 */
   __MOV(reg_r0_4, t__i32_0); /* line 4576 */
   __CMPEQ(reg_b0_0, t__i32_0, (unsigned int) -1); /* line 4577 */
   __MOV(reg_r0_3, 0); /* line 4578 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4579 */
   __MOV(reg_r0_5, t__i32_0); /* line 4580 */
} /* line 4580 */
  sim_icache_fetch(3248 + t_thisfile.offset, 1);
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
} /* line 4582 */
  sim_icache_fetch(3249 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4585 */
l_L196X3: ;/* line 4588 */
__LABEL(l_L196X3);
  sim_icache_fetch(3250 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4589 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4590 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4591 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4592 */
} /* line 4592 */
  sim_icache_fetch(3255 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4594 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4595 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4596 */
} /* line 4596 */
  sim_icache_fetch(3259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4598 */
} /* line 4598 */
  sim_icache_fetch(3260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4600 */
} /* line 4600 */
  sim_icache_fetch(3262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4602 */
} /* line 4602 */
l_L197X3: ;/* line 4605 */
__LABEL(l_L197X3);
		 /* line 4605 */
  sim_icache_fetch(3263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (413 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4607 */
l_lr_266: ;/* line 4607 */
__LABEL(l_lr_266);
  sim_icache_fetch(3265 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4609 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4610 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4611 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4612 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4613 */
} /* line 4613 */
  sim_icache_fetch(3272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L198X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4615 */
  sim_icache_fetch(3273 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4617 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4618 */
} /* line 4618 */
  sim_icache_fetch(3276 + t_thisfile.offset, 1);
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
} /* line 4620 */
l_L200X3: ;/* line 4623 */
__LABEL(l_L200X3);
  sim_icache_fetch(3277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4624 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4625 */
} /* line 4625 */
  sim_icache_fetch(3279 + t_thisfile.offset, 1);
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
} /* line 4627 */
  sim_icache_fetch(3280 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4629 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4630 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4631 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4632 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4633 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4634 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4635 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4636 */
} /* line 4636 */
  sim_icache_fetch(3288 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4638 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4639 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4640 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4641 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4642 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4643 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4644 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4645 */
} /* line 4645 */
  sim_icache_fetch(3296 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4647 */
   __GOTO(l_L200X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L200X3;
} /* line 4648 */
l_L201X3: ;/* line 4651 */
__LABEL(l_L201X3);
  sim_icache_fetch(3298 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4652 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4653 */
} /* line 4653 */
		 /* line 4654 */
  sim_icache_fetch(3301 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4656 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4657 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (413 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4658 */
l_lr_270: ;/* line 4658 */
__LABEL(l_lr_270);
  sim_icache_fetch(3307 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4660 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4661 */
} /* line 4661 */
  sim_icache_fetch(3309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L198X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4663 */
l_L199X3: ;/* line 4666 */
__LABEL(l_L199X3);
  sim_icache_fetch(3310 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4667 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4668 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4669 */
   __ADD_CYCLES(1);
} /* line 4669 */
  sim_icache_fetch(3314 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4671 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4672 */
} /* line 4672 */
  sim_icache_fetch(3316 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4674 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L202X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4675 */
  sim_icache_fetch(3319 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4677 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4678 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4679 */
} /* line 4679 */
l_L203X3: ;/* line 4682 */
__LABEL(l_L203X3);
  sim_icache_fetch(3322 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4683 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4684 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4685 */
} /* line 4685 */
  sim_icache_fetch(3327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4687 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4688 */
  sim_icache_fetch(3329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4690 */
} /* line 4690 */
  sim_icache_fetch(3330 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4692 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4693 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4694 */
} /* line 4694 */
  sim_icache_fetch(3335 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4696 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L205X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4697 */
  sim_icache_fetch(3337 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4699 */
} /* line 4699 */
  sim_icache_fetch(3338 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4701 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4702 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4703 */
} /* line 4703 */
  sim_icache_fetch(3343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4705 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4706 */
  sim_icache_fetch(3345 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4708 */
} /* line 4708 */
  sim_icache_fetch(3346 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4710 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4711 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4712 */
} /* line 4712 */
  sim_icache_fetch(3351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4714 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4715 */
  sim_icache_fetch(3353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4717 */
} /* line 4717 */
  sim_icache_fetch(3354 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4719 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4720 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4721 */
} /* line 4721 */
  sim_icache_fetch(3359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4723 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4724 */
  sim_icache_fetch(3361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4726 */
} /* line 4726 */
  sim_icache_fetch(3362 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4728 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4729 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4730 */
} /* line 4730 */
  sim_icache_fetch(3367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4732 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4733 */
  sim_icache_fetch(3369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4735 */
} /* line 4735 */
  sim_icache_fetch(3370 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4737 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4738 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4739 */
} /* line 4739 */
  sim_icache_fetch(3375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4741 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4742 */
  sim_icache_fetch(3377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4744 */
} /* line 4744 */
  sim_icache_fetch(3378 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4746 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4747 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4748 */
} /* line 4748 */
  sim_icache_fetch(3383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4750 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4751 */
  sim_icache_fetch(3385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4753 */
} /* line 4753 */
  sim_icache_fetch(3386 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4755 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4756 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4757 */
} /* line 4757 */
  sim_icache_fetch(3391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4759 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4760 */
  sim_icache_fetch(3393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4762 */
} /* line 4762 */
  sim_icache_fetch(3394 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4764 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4765 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4766 */
} /* line 4766 */
  sim_icache_fetch(3399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4768 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4769 */
  sim_icache_fetch(3401 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4771 */
} /* line 4771 */
  sim_icache_fetch(3402 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4773 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4774 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4775 */
} /* line 4775 */
  sim_icache_fetch(3407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4777 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4778 */
  sim_icache_fetch(3409 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4780 */
} /* line 4780 */
  sim_icache_fetch(3410 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4782 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4783 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4784 */
} /* line 4784 */
  sim_icache_fetch(3415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4786 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4787 */
  sim_icache_fetch(3417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4789 */
} /* line 4789 */
  sim_icache_fetch(3418 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4791 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4792 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4793 */
} /* line 4793 */
  sim_icache_fetch(3423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4795 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4796 */
  sim_icache_fetch(3425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4798 */
} /* line 4798 */
  sim_icache_fetch(3426 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4800 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4801 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4802 */
} /* line 4802 */
  sim_icache_fetch(3431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4804 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4805 */
  sim_icache_fetch(3433 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4807 */
} /* line 4807 */
  sim_icache_fetch(3434 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4809 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4810 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4811 */
} /* line 4811 */
  sim_icache_fetch(3439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4813 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4814 */
  sim_icache_fetch(3441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4816 */
} /* line 4816 */
  sim_icache_fetch(3442 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4818 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4819 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4820 */
} /* line 4820 */
  sim_icache_fetch(3447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4822 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4823 */
  sim_icache_fetch(3449 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4825 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4826 */
   __GOTO(l_L203X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L203X3;
} /* line 4827 */
l_L219X3: ;/* line 4830 */
__LABEL(l_L219X3);
  sim_icache_fetch(3452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4831 */
   __MOV(reg_r0_40, reg_r0_8); /* line 4832 */
} /* line 4832 */
  sim_icache_fetch(3454 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4834 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 4835 */
l_L221X3: ;/* line 4838 */
__LABEL(l_L221X3);
  sim_icache_fetch(3456 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_5, reg_r0_3); /* line 4839 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4840 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4841 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4842 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4843 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4844 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4845 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4846 */
} /* line 4846 */
  sim_icache_fetch(3470 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4848 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4849 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4850 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4851 */
   __ADD(reg_r0_22, reg_r0_19, (unsigned int) -16); /* line 4852 */
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) -16); /* line 4853 */
   __ADD(reg_r0_24, reg_r0_17, (unsigned int) -16); /* line 4854 */
   __ADD(reg_r0_25, reg_r0_16, (unsigned int) -16); /* line 4855 */
} /* line 4855 */
  sim_icache_fetch(3481 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 4857 */
   __ADD(reg_r0_27, reg_r0_15, (unsigned int) -16); /* line 4858 */
   __ADD(reg_r0_28, reg_r0_14, (unsigned int) -16); /* line 4859 */
   __ADD(reg_r0_29, reg_r0_13, (unsigned int) -16); /* line 4860 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4861 */
   __ADD(reg_r0_31, reg_r0_11, (unsigned int) -16); /* line 4862 */
   __ADD(reg_r0_32, reg_r0_10, (unsigned int) -16); /* line 4863 */
   __ADD(reg_r0_33, reg_r0_9, (unsigned int) -16); /* line 4864 */
} /* line 4864 */
  sim_icache_fetch(3489 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 4866 */
   __MOV(reg_r0_38, reg_r0_20); /* line 4867 */
   __ADD(reg_r0_34, reg_r0_8, (unsigned int) -16); /* line 4868 */
   __ADD(reg_r0_35, reg_r0_7, (unsigned int) -16); /* line 4869 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) -16); /* line 4870 */
   __ADD(reg_r0_37, reg_r0_20, (unsigned int) -16); /* line 4871 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 4872 */
} /* line 4872 */
  sim_icache_fetch(3497 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4874 */
   __MOV(reg_r0_26, reg_r0_37); /* line 4875 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4876 */
  sim_icache_fetch(3500 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4878 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4879 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4880 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4881 */
   __ADD_CYCLES(1);
} /* line 4881 */
  sim_icache_fetch(3506 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4883 */
} /* line 4883 */
  sim_icache_fetch(3507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4885 */
} /* line 4885 */
  sim_icache_fetch(3509 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4887 */
   __CMPLEU(reg_b0_1, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 4888 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4889 */
  sim_icache_fetch(3513 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4891 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4892 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4893 */
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) -16); /* line 4894 */
   __MFB(reg_r0_4, t__i32_0); /* line 4895 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4896 */
   __ADD_CYCLES(1);
} /* line 4896 */
  sim_icache_fetch(3521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 4898 */
} /* line 4898 */
  sim_icache_fetch(3522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 4900 */
} /* line 4900 */
  sim_icache_fetch(3524 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4902 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4903 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4904 */
  sim_icache_fetch(3527 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 4906 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4907 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 4908 */
   __ADD(reg_r0_7, reg_r0_35, (unsigned int) -16); /* line 4909 */
   __MFB(reg_r0_4, t__i32_0); /* line 4910 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4911 */
   __ADD_CYCLES(1);
} /* line 4911 */
  sim_icache_fetch(3535 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 4913 */
} /* line 4913 */
  sim_icache_fetch(3536 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 4915 */
} /* line 4915 */
  sim_icache_fetch(3538 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 4917 */
   __MTB(reg_b0_3, reg_r0_4); /* line 4918 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4919 */
  sim_icache_fetch(3541 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 4921 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4922 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 4923 */
   __ADD(reg_r0_8, reg_r0_34, (unsigned int) -16); /* line 4924 */
   __MFB(reg_r0_4, t__i32_0); /* line 4925 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4926 */
   __ADD_CYCLES(1);
} /* line 4926 */
  sim_icache_fetch(3549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 4928 */
} /* line 4928 */
  sim_icache_fetch(3550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 4930 */
} /* line 4930 */
  sim_icache_fetch(3552 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 4932 */
   __MTB(reg_b0_4, reg_r0_4); /* line 4933 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4934 */
  sim_icache_fetch(3555 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 4936 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4937 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 4938 */
   __ADD(reg_r0_9, reg_r0_33, (unsigned int) -16); /* line 4939 */
   __MFB(reg_r0_4, t__i32_0); /* line 4940 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4941 */
   __ADD_CYCLES(1);
} /* line 4941 */
  sim_icache_fetch(3563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 4943 */
} /* line 4943 */
  sim_icache_fetch(3564 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 4945 */
} /* line 4945 */
  sim_icache_fetch(3566 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 4947 */
   __MTB(reg_b0_5, reg_r0_4); /* line 4948 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4949 */
  sim_icache_fetch(3569 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 4951 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4952 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 4953 */
   __ADD(reg_r0_10, reg_r0_32, (unsigned int) -16); /* line 4954 */
   __MFB(reg_r0_4, t__i32_0); /* line 4955 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4956 */
   __ADD_CYCLES(1);
} /* line 4956 */
  sim_icache_fetch(3577 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 4958 */
} /* line 4958 */
  sim_icache_fetch(3578 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 4960 */
} /* line 4960 */
  sim_icache_fetch(3580 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 4962 */
   __MTB(reg_b0_6, reg_r0_4); /* line 4963 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4964 */
  sim_icache_fetch(3583 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 4966 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4967 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 4968 */
   __ADD(reg_r0_11, reg_r0_31, (unsigned int) -16); /* line 4969 */
   __MFB(reg_r0_4, t__i32_0); /* line 4970 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4971 */
   __ADD_CYCLES(1);
} /* line 4971 */
  sim_icache_fetch(3591 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 4973 */
} /* line 4973 */
  sim_icache_fetch(3592 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 4975 */
} /* line 4975 */
  sim_icache_fetch(3594 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 4977 */
   __MTB(reg_b0_7, reg_r0_4); /* line 4978 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4979 */
  sim_icache_fetch(3597 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 4981 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4982 */
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 4983 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4984 */
   __MFB(reg_r0_4, t__i32_0); /* line 4985 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4986 */
   __ADD_CYCLES(1);
} /* line 4986 */
  sim_icache_fetch(3605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 4988 */
} /* line 4988 */
  sim_icache_fetch(3606 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 4990 */
} /* line 4990 */
  sim_icache_fetch(3608 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 4992 */
   __MTB(reg_b0_0, reg_r0_4); /* line 4993 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4994 */
  sim_icache_fetch(3611 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 4996 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4997 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4998 */
   __ADD(reg_r0_13, reg_r0_29, (unsigned int) -16); /* line 4999 */
   __MFB(reg_r0_4, t__i32_0); /* line 5000 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5001 */
   __ADD_CYCLES(1);
} /* line 5001 */
  sim_icache_fetch(3619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 5003 */
} /* line 5003 */
  sim_icache_fetch(3620 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 5005 */
} /* line 5005 */
  sim_icache_fetch(3622 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5007 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5008 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5009 */
  sim_icache_fetch(3625 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5011 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5012 */
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 5013 */
   __ADD(reg_r0_14, reg_r0_28, (unsigned int) -16); /* line 5014 */
   __MFB(reg_r0_4, t__i32_0); /* line 5015 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5016 */
   __ADD_CYCLES(1);
} /* line 5016 */
  sim_icache_fetch(3633 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 5018 */
} /* line 5018 */
  sim_icache_fetch(3634 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 5020 */
} /* line 5020 */
  sim_icache_fetch(3636 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5022 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5023 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5024 */
  sim_icache_fetch(3639 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5026 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5027 */
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5028 */
   __ADD(reg_r0_15, reg_r0_27, (unsigned int) -16); /* line 5029 */
   __MFB(reg_r0_4, t__i32_0); /* line 5030 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5031 */
   __ADD_CYCLES(1);
} /* line 5031 */
  sim_icache_fetch(3647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 5033 */
} /* line 5033 */
  sim_icache_fetch(3648 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 5035 */
} /* line 5035 */
  sim_icache_fetch(3650 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5037 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5038 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5039 */
  sim_icache_fetch(3653 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5041 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5042 */
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5043 */
   __ADD(reg_r0_16, reg_r0_25, (unsigned int) -16); /* line 5044 */
   __MFB(reg_r0_4, t__i32_0); /* line 5045 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5046 */
   __ADD_CYCLES(1);
} /* line 5046 */
  sim_icache_fetch(3661 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 5048 */
} /* line 5048 */
  sim_icache_fetch(3662 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 5050 */
} /* line 5050 */
  sim_icache_fetch(3664 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5052 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5053 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5054 */
  sim_icache_fetch(3667 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5056 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5057 */
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5058 */
   __ADD(reg_r0_17, reg_r0_24, (unsigned int) -16); /* line 5059 */
   __MFB(reg_r0_4, t__i32_0); /* line 5060 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5061 */
   __ADD_CYCLES(1);
} /* line 5061 */
  sim_icache_fetch(3675 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 5063 */
} /* line 5063 */
  sim_icache_fetch(3676 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 5065 */
} /* line 5065 */
  sim_icache_fetch(3678 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5067 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5068 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5069 */
  sim_icache_fetch(3681 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5071 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5072 */
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5073 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) -16); /* line 5074 */
   __MFB(reg_r0_4, t__i32_0); /* line 5075 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5076 */
   __ADD_CYCLES(1);
} /* line 5076 */
  sim_icache_fetch(3689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 5078 */
} /* line 5078 */
  sim_icache_fetch(3690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 5080 */
} /* line 5080 */
  sim_icache_fetch(3692 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5082 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5083 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5084 */
  sim_icache_fetch(3695 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5086 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5087 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5088 */
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5089 */
   __ADD(reg_r0_19, reg_r0_22, (unsigned int) -16); /* line 5090 */
   __MFB(reg_r0_4, t__i32_0); /* line 5091 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5092 */
   __ADD_CYCLES(1);
} /* line 5092 */
  sim_icache_fetch(3704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_2, (unsigned int) 1); /* line 5094 */
} /* line 5094 */
  sim_icache_fetch(3705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_26); /* line 5096 */
} /* line 5096 */
  sim_icache_fetch(3707 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5098 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5099 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5100 */
  sim_icache_fetch(3710 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_5, reg_r0_3); /* line 5102 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5103 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5104 */
   __CMPLEU(reg_b0_7, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5105 */
   __ADD(reg_r0_20, reg_r0_37, (unsigned int) -16); /* line 5106 */
   __MOV(reg_r0_3, reg_r0_39); /* line 5107 */
   __MFB(reg_r0_26, t__i32_0); /* line 5108 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5109 */
   __ADD_CYCLES(1);
} /* line 5109 */
  sim_icache_fetch(3720 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5111 */
} /* line 5111 */
  sim_icache_fetch(3721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5113 */
} /* line 5113 */
  sim_icache_fetch(3723 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5115 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5116 */
  sim_icache_fetch(3725 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5118 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5119 */
   __CMPLEU(reg_b0_0, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5120 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5121 */
   __ADD_CYCLES(1);
} /* line 5121 */
  sim_icache_fetch(3731 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5123 */
} /* line 5123 */
  sim_icache_fetch(3732 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5125 */
} /* line 5125 */
  sim_icache_fetch(3734 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5127 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5128 */
  sim_icache_fetch(3736 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5130 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5131 */
   __CMPLEU(reg_b0_1, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5132 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5133 */
   __ADD_CYCLES(1);
} /* line 5133 */
  sim_icache_fetch(3742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5135 */
} /* line 5135 */
  sim_icache_fetch(3743 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5137 */
} /* line 5137 */
  sim_icache_fetch(3745 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5139 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5140 */
  sim_icache_fetch(3747 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5142 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5143 */
   __CMPLEU(reg_b0_2, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5144 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5145 */
   __ADD_CYCLES(1);
} /* line 5145 */
  sim_icache_fetch(3753 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5147 */
} /* line 5147 */
  sim_icache_fetch(3754 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5149 */
} /* line 5149 */
  sim_icache_fetch(3756 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5151 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5152 */
  sim_icache_fetch(3758 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5154 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5155 */
   __CMPLEU(reg_b0_3, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5156 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5157 */
   __ADD_CYCLES(1);
} /* line 5157 */
  sim_icache_fetch(3764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5159 */
} /* line 5159 */
  sim_icache_fetch(3765 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5161 */
} /* line 5161 */
  sim_icache_fetch(3767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5163 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5164 */
  sim_icache_fetch(3769 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5166 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5167 */
   __CMPLEU(reg_b0_4, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5168 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5169 */
   __ADD_CYCLES(1);
} /* line 5169 */
  sim_icache_fetch(3775 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5171 */
} /* line 5171 */
  sim_icache_fetch(3776 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5173 */
} /* line 5173 */
  sim_icache_fetch(3778 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5175 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5176 */
  sim_icache_fetch(3780 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5178 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5179 */
   __CMPLEU(reg_b0_5, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5180 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5181 */
   __ADD_CYCLES(1);
} /* line 5181 */
  sim_icache_fetch(3786 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5183 */
} /* line 5183 */
  sim_icache_fetch(3787 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5185 */
} /* line 5185 */
  sim_icache_fetch(3789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5187 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5188 */
  sim_icache_fetch(3791 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5190 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5191 */
   __CMPLEU(reg_b0_6, reg_r0_22, ((unsigned int) htab + (unsigned int) 4096)); /* line 5192 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5193 */
   __ADD_CYCLES(1);
} /* line 5193 */
  sim_icache_fetch(3797 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5195 */
} /* line 5195 */
  sim_icache_fetch(3798 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5197 */
} /* line 5197 */
  sim_icache_fetch(3800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5199 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5200 */
  sim_icache_fetch(3802 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5202 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5203 */
   __MTB(reg_b0_7, reg_r0_26); /* line 5204 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5205 */
   __ADD_CYCLES(1);
} /* line 5205 */
  sim_icache_fetch(3807 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5207 */
} /* line 5207 */
  sim_icache_fetch(3808 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5209 */
} /* line 5209 */
  sim_icache_fetch(3810 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5211 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5212 */
  sim_icache_fetch(3812 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5214 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5215 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5216 */
   __ADD_CYCLES(1);
} /* line 5216 */
  sim_icache_fetch(3816 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5218 */
} /* line 5218 */
  sim_icache_fetch(3817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5220 */
} /* line 5220 */
  sim_icache_fetch(3819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5222 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5223 */
  sim_icache_fetch(3821 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5225 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5226 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5227 */
   __ADD_CYCLES(1);
} /* line 5227 */
  sim_icache_fetch(3825 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5229 */
} /* line 5229 */
  sim_icache_fetch(3826 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5231 */
} /* line 5231 */
  sim_icache_fetch(3828 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5233 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5234 */
  sim_icache_fetch(3830 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5236 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5237 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5238 */
   __ADD_CYCLES(1);
} /* line 5238 */
  sim_icache_fetch(3834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5240 */
} /* line 5240 */
  sim_icache_fetch(3835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5242 */
} /* line 5242 */
  sim_icache_fetch(3837 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5244 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5245 */
  sim_icache_fetch(3839 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5247 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5248 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5249 */
   __ADD_CYCLES(1);
} /* line 5249 */
  sim_icache_fetch(3843 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5251 */
} /* line 5251 */
  sim_icache_fetch(3844 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5253 */
} /* line 5253 */
  sim_icache_fetch(3846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5255 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5256 */
  sim_icache_fetch(3848 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5258 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5259 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5260 */
   __ADD_CYCLES(1);
} /* line 5260 */
  sim_icache_fetch(3852 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5262 */
} /* line 5262 */
  sim_icache_fetch(3853 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5264 */
} /* line 5264 */
  sim_icache_fetch(3855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5266 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5267 */
  sim_icache_fetch(3857 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_22, mem_trace_ld(reg_r0_22,0,1)); /* line 5269 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5270 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5271 */
   __ADD_CYCLES(1);
} /* line 5271 */
  sim_icache_fetch(3861 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5273 */
} /* line 5273 */
  sim_icache_fetch(3862 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5275 */
} /* line 5275 */
  sim_icache_fetch(3864 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_22); /* line 5277 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5278 */
  sim_icache_fetch(3866 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5280 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5281 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5282 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5283 */
   __ADD_CYCLES(1);
} /* line 5283 */
  sim_icache_fetch(3871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5285 */
} /* line 5285 */
  sim_icache_fetch(3872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5287 */
} /* line 5287 */
  sim_icache_fetch(3874 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5289 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5291 */
  sim_icache_fetch(3876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L221X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L221X3;
} /* line 5293 */
l_L237X3: ;/* line 5296 */
__LABEL(l_L237X3);
  sim_icache_fetch(3877 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5297 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5298 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5299 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5300 */
l_L240X3: ;/* line 5303 */
__LABEL(l_L240X3);
  sim_icache_fetch(3883 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5304 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5305 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5306 */
} /* line 5306 */
  sim_icache_fetch(3888 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5308 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5309 */
   __GOTO(l_L239X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L239X3;
} /* line 5310 */
l_L236X3: ;/* line 5313 */
__LABEL(l_L236X3);
  sim_icache_fetch(3892 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5314 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5315 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5316 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5317 */
l_L235X3: ;/* line 5320 */
__LABEL(l_L235X3);
  sim_icache_fetch(3898 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5321 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5322 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5323 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5324 */
l_L234X3: ;/* line 5327 */
__LABEL(l_L234X3);
  sim_icache_fetch(3904 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5328 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5329 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5330 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5331 */
l_L233X3: ;/* line 5334 */
__LABEL(l_L233X3);
  sim_icache_fetch(3910 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5335 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5336 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5337 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5338 */
l_L232X3: ;/* line 5341 */
__LABEL(l_L232X3);
  sim_icache_fetch(3916 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5342 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5343 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5344 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5345 */
l_L231X3: ;/* line 5348 */
__LABEL(l_L231X3);
  sim_icache_fetch(3922 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5349 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5350 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5351 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5352 */
l_L230X3: ;/* line 5355 */
__LABEL(l_L230X3);
  sim_icache_fetch(3928 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5356 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5357 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5358 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5359 */
l_L229X3: ;/* line 5362 */
__LABEL(l_L229X3);
  sim_icache_fetch(3934 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5363 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5364 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5365 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5366 */
l_L228X3: ;/* line 5369 */
__LABEL(l_L228X3);
  sim_icache_fetch(3940 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5370 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5371 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5372 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5373 */
l_L227X3: ;/* line 5376 */
__LABEL(l_L227X3);
  sim_icache_fetch(3946 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5377 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5378 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5379 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5380 */
l_L226X3: ;/* line 5383 */
__LABEL(l_L226X3);
  sim_icache_fetch(3952 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5384 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5385 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5386 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5387 */
l_L225X3: ;/* line 5390 */
__LABEL(l_L225X3);
  sim_icache_fetch(3958 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5391 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5392 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5393 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5394 */
l_L224X3: ;/* line 5397 */
__LABEL(l_L224X3);
  sim_icache_fetch(3964 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5398 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5399 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5400 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5401 */
l_L223X3: ;/* line 5404 */
__LABEL(l_L223X3);
  sim_icache_fetch(3970 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5405 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5406 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5407 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5408 */
l_L222X3: ;/* line 5411 */
__LABEL(l_L222X3);
  sim_icache_fetch(3976 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5412 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5413 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5414 */
} /* line 5414 */
l_L238X3: ;/* line 5416 */
__LABEL(l_L238X3);
  sim_icache_fetch(3981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5416 */
  sim_icache_fetch(3982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5418 */
} /* line 5418 */
  sim_icache_fetch(3983 + t_thisfile.offset, 1);
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
} /* line 5420 */
l_L239X3: ;/* line 5422 */
__LABEL(l_L239X3);
  sim_icache_fetch(3984 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_40); /* line 5423 */
   __GOTO(l_L197X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L197X3;
} /* line 5424 */
l_L218X3: ;/* line 5427 */
__LABEL(l_L218X3);
  sim_icache_fetch(3986 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5428 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5429 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5430 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5431 */
l_L217X3: ;/* line 5434 */
__LABEL(l_L217X3);
  sim_icache_fetch(3990 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5435 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5436 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5437 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5438 */
l_L216X3: ;/* line 5441 */
__LABEL(l_L216X3);
  sim_icache_fetch(3994 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5442 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5443 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5444 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5445 */
l_L215X3: ;/* line 5448 */
__LABEL(l_L215X3);
  sim_icache_fetch(3998 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5449 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5450 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5451 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5452 */
l_L214X3: ;/* line 5455 */
__LABEL(l_L214X3);
  sim_icache_fetch(4002 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5456 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5457 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5458 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5459 */
l_L213X3: ;/* line 5462 */
__LABEL(l_L213X3);
  sim_icache_fetch(4006 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5463 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5464 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5465 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5466 */
l_L212X3: ;/* line 5469 */
__LABEL(l_L212X3);
  sim_icache_fetch(4010 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5470 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5471 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5472 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5473 */
l_L211X3: ;/* line 5476 */
__LABEL(l_L211X3);
  sim_icache_fetch(4014 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5477 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5478 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5479 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5480 */
l_L210X3: ;/* line 5483 */
__LABEL(l_L210X3);
  sim_icache_fetch(4018 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5484 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5485 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5486 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5487 */
l_L209X3: ;/* line 5490 */
__LABEL(l_L209X3);
  sim_icache_fetch(4022 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5491 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5492 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5493 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5494 */
l_L208X3: ;/* line 5497 */
__LABEL(l_L208X3);
  sim_icache_fetch(4026 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5498 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5499 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5500 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5501 */
l_L207X3: ;/* line 5504 */
__LABEL(l_L207X3);
  sim_icache_fetch(4030 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5505 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5506 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5507 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5508 */
l_L206X3: ;/* line 5511 */
__LABEL(l_L206X3);
  sim_icache_fetch(4034 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5512 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5513 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5514 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5515 */
l_L205X3: ;/* line 5518 */
__LABEL(l_L205X3);
  sim_icache_fetch(4038 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5519 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5520 */
   __MOV(reg_r0_40, reg_r0_8); /* line 5521 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5522 */
l_L204X3: ;/* line 5527 */
__LABEL(l_L204X3);
  sim_icache_fetch(4042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_40, reg_r0_8); /* line 5528 */
} /* line 5528 */
l_L220X3: ;/* line 5530 */
__LABEL(l_L220X3);
  sim_icache_fetch(4043 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5531 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5532 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5533 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5534 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5535 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5536 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5537 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5538 */
} /* line 5538 */
  sim_icache_fetch(4052 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5540 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5541 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5542 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5543 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5544 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5545 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5546 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5547 */
} /* line 5547 */
  sim_icache_fetch(4060 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5549 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5550 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5551 */
   __GOTO(l_L221X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L221X3;
} /* line 5552 */
l_L202X3: ;/* line 5555 */
__LABEL(l_L202X3);
  sim_icache_fetch(4064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5556 */
   __GOTO(l_L203X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L203X3;
} /* line 5557 */
l_L198X3: ;/* line 5560 */
__LABEL(l_L198X3);
  sim_icache_fetch(4066 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5561 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5562 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5563 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5564 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5565 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5566 */
   __ADD_CYCLES(1);
} /* line 5566 */
  sim_icache_fetch(4072 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5569 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 360: goto l_L194X3;
    case 361: goto l_L195X3;
    case 363: goto l_lr_262;
    case 364: goto l_L196X3;
    case 365: goto l_L197X3;
    case 367: goto l_lr_266;
    case 368: goto l_L200X3;
    case 369: goto l_L201X3;
    case 371: goto l_lr_270;
    case 372: goto l_L199X3;
    case 373: goto l_L203X3;
    case 374: goto l_L219X3;
    case 375: goto l_L221X3;
    case 376: goto l_L237X3;
    case 377: goto l_L240X3;
    case 378: goto l_L236X3;
    case 379: goto l_L235X3;
    case 380: goto l_L234X3;
    case 381: goto l_L233X3;
    case 382: goto l_L232X3;
    case 383: goto l_L231X3;
    case 384: goto l_L230X3;
    case 385: goto l_L229X3;
    case 386: goto l_L228X3;
    case 387: goto l_L227X3;
    case 388: goto l_L226X3;
    case 389: goto l_L225X3;
    case 390: goto l_L224X3;
    case 391: goto l_L223X3;
    case 392: goto l_L222X3;
    case 393: goto l_L238X3;
    case 394: goto l_L239X3;
    case 395: goto l_L218X3;
    case 396: goto l_L217X3;
    case 397: goto l_L216X3;
    case 398: goto l_L215X3;
    case 399: goto l_L214X3;
    case 400: goto l_L213X3;
    case 401: goto l_L212X3;
    case 402: goto l_L211X3;
    case 403: goto l_L210X3;
    case 404: goto l_L209X3;
    case 405: goto l_L208X3;
    case 406: goto l_L207X3;
    case 407: goto l_L206X3;
    case 408: goto l_L205X3;
    case 409: goto l_L204X3;
    case 410: goto l_L220X3;
    case 411: goto l_L202X3;
    case 412: goto l_L198X3;
    case 413:
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
  reg_l0_0 = (441 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4073 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5588 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5589 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5590 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5591 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5592 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5593 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5594 */
} /* line 5594 */
  sim_icache_fetch(4087 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5596 */
} /* line 5596 */
  sim_icache_fetch(4089 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_r0_11, reg_r0_7, reg_r0_8); /* line 5598 */
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5599 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5600 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5601 */
} /* line 5601 */
  sim_icache_fetch(4093 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5603 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5604 */
} /* line 5604 */
  sim_icache_fetch(4095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_1, reg_r0_4, reg_r0_11); /* line 5606 */
   __CMPEQ(reg_b0_2, reg_r0_9, reg_r0_2); /* line 5607 */
} /* line 5607 */
  sim_icache_fetch(4097 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5609 */
  sim_icache_fetch(4098 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L242X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5611 */
  sim_icache_fetch(4099 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5613 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L243X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5614 */
  sim_icache_fetch(4102 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5616 */
} /* line 5616 */
l_L242X3: ;/* line 5619 */
__LABEL(l_L242X3);
  sim_icache_fetch(4104 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5620 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5621 */
   __MOV(reg_r0_5, 0); /* line 5622 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5623 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5624 */
   __ADD_CYCLES(1);
} /* line 5624 */
  sim_icache_fetch(4111 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5626 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5627 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5628 */
} /* line 5628 */
  sim_icache_fetch(4114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5630 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5631 */
l_L245X3: ;/* line 5634 */
__LABEL(l_L245X3);
  sim_icache_fetch(4116 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5635 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5636 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5637 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5638 */
} /* line 5638 */
  sim_icache_fetch(4122 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5640 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5641 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5642 */
  sim_icache_fetch(4125 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5644 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5645 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5646 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5647 */
} /* line 5647 */
  sim_icache_fetch(4129 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5649 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5650 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5651 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5652 */
} /* line 5652 */
  sim_icache_fetch(4134 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5654 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5655 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5656 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5657 */
  sim_icache_fetch(4139 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5659 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5660 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5661 */
} /* line 5661 */
  sim_icache_fetch(4143 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5663 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5664 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5665 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5666 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5667 */
} /* line 5667 */
  sim_icache_fetch(4149 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5669 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5670 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5671 */
} /* line 5671 */
  sim_icache_fetch(4152 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5673 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5674 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5675 */
} /* line 5675 */
l_L248X3: ;/* line 5677 */
__LABEL(l_L248X3);
  sim_icache_fetch(4155 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5678 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5679 */
} /* line 5679 */
  sim_icache_fetch(4158 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5681 */
} /* line 5681 */
  sim_icache_fetch(4159 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5683 */
} /* line 5683 */
  sim_icache_fetch(4160 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5685 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5686 */
  sim_icache_fetch(4162 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5688 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5689 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5690 */
  sim_icache_fetch(4165 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5692 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5693 */
  sim_icache_fetch(4168 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5695 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5696 */
} /* line 5696 */
  sim_icache_fetch(4172 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5698 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5699 */
} /* line 5699 */
  sim_icache_fetch(4175 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5701 */
} /* line 5701 */
  sim_icache_fetch(4176 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5703 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5704 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5705 */
} /* line 5705 */
l_L251X3: ;/* line 5707 */
__LABEL(l_L251X3);
  sim_icache_fetch(4179 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5708 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5709 */
} /* line 5709 */
  sim_icache_fetch(4182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5711 */
} /* line 5711 */
  sim_icache_fetch(4183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5713 */
} /* line 5713 */
  sim_icache_fetch(4184 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5715 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5716 */
  sim_icache_fetch(4186 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5718 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5719 */
  sim_icache_fetch(4188 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5721 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5722 */
  sim_icache_fetch(4191 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5724 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5725 */
} /* line 5725 */
  sim_icache_fetch(4195 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5727 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5728 */
} /* line 5728 */
  sim_icache_fetch(4198 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5730 */
} /* line 5730 */
  sim_icache_fetch(4199 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5732 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5733 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5734 */
} /* line 5734 */
l_L253X3: ;/* line 5736 */
__LABEL(l_L253X3);
  sim_icache_fetch(4202 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5737 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5738 */
} /* line 5738 */
  sim_icache_fetch(4205 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5740 */
} /* line 5740 */
  sim_icache_fetch(4206 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5742 */
  sim_icache_fetch(4207 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5744 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5745 */
  sim_icache_fetch(4209 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5747 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5748 */
  sim_icache_fetch(4212 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5750 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5751 */
} /* line 5751 */
  sim_icache_fetch(4216 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5753 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5754 */
} /* line 5754 */
  sim_icache_fetch(4219 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5756 */
} /* line 5756 */
  sim_icache_fetch(4220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5758 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5759 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5760 */
} /* line 5760 */
l_L255X3: ;/* line 5762 */
__LABEL(l_L255X3);
  sim_icache_fetch(4223 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5763 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5764 */
} /* line 5764 */
  sim_icache_fetch(4226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5766 */
} /* line 5766 */
  sim_icache_fetch(4227 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5768 */
  sim_icache_fetch(4228 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5770 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5771 */
  sim_icache_fetch(4230 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5773 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L256X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5774 */
  sim_icache_fetch(4233 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5776 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5777 */
} /* line 5777 */
  sim_icache_fetch(4237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5779 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5780 */
} /* line 5780 */
  sim_icache_fetch(4240 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5782 */
} /* line 5782 */
  sim_icache_fetch(4241 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5784 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5785 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5786 */
} /* line 5786 */
l_L257X3: ;/* line 5788 */
__LABEL(l_L257X3);
  sim_icache_fetch(4244 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5789 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5790 */
} /* line 5790 */
  sim_icache_fetch(4247 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5792 */
} /* line 5792 */
  sim_icache_fetch(4248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5794 */
  sim_icache_fetch(4249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5796 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5797 */
  sim_icache_fetch(4251 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5799 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L258X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5800 */
  sim_icache_fetch(4254 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5802 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5803 */
} /* line 5803 */
  sim_icache_fetch(4258 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5805 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5806 */
} /* line 5806 */
  sim_icache_fetch(4261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5808 */
} /* line 5808 */
  sim_icache_fetch(4262 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5810 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5811 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5812 */
} /* line 5812 */
l_L259X3: ;/* line 5814 */
__LABEL(l_L259X3);
  sim_icache_fetch(4265 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5815 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5816 */
} /* line 5816 */
  sim_icache_fetch(4268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5818 */
} /* line 5818 */
  sim_icache_fetch(4269 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5820 */
  sim_icache_fetch(4270 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5822 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5823 */
  sim_icache_fetch(4272 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5825 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L260X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5826 */
  sim_icache_fetch(4275 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5828 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5829 */
} /* line 5829 */
  sim_icache_fetch(4279 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5831 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5832 */
} /* line 5832 */
  sim_icache_fetch(4282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5834 */
} /* line 5834 */
  sim_icache_fetch(4283 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5836 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5837 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5838 */
} /* line 5838 */
l_L261X3: ;/* line 5840 */
__LABEL(l_L261X3);
  sim_icache_fetch(4286 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5841 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5842 */
} /* line 5842 */
  sim_icache_fetch(4289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5844 */
} /* line 5844 */
  sim_icache_fetch(4290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5846 */
  sim_icache_fetch(4291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5848 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5849 */
  sim_icache_fetch(4293 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5851 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5852 */
  sim_icache_fetch(4296 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5854 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5855 */
} /* line 5855 */
  sim_icache_fetch(4300 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5857 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5858 */
} /* line 5858 */
  sim_icache_fetch(4303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5860 */
} /* line 5860 */
  sim_icache_fetch(4304 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5862 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5863 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5864 */
} /* line 5864 */
l_L263X3: ;/* line 5866 */
__LABEL(l_L263X3);
  sim_icache_fetch(4307 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5867 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5868 */
} /* line 5868 */
  sim_icache_fetch(4310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5870 */
} /* line 5870 */
  sim_icache_fetch(4311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5872 */
  sim_icache_fetch(4312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5874 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5875 */
  sim_icache_fetch(4314 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5877 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L264X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5878 */
  sim_icache_fetch(4317 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5880 */
} /* line 5880 */
  sim_icache_fetch(4319 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5882 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5883 */
   __ADD_CYCLES(1);
} /* line 5883 */
  sim_icache_fetch(4321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5885 */
} /* line 5885 */
l_L265X3: ;/* line 5887 */
__LABEL(l_L265X3);
  sim_icache_fetch(4322 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5888 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5889 */
} /* line 5889 */
  sim_icache_fetch(4325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5891 */
} /* line 5891 */
  sim_icache_fetch(4326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5893 */
  sim_icache_fetch(4327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5895 */
   __GOTO(l_L245X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L245X3;
} /* line 5896 */
l_L249X3: ;/* line 5899 */
__LABEL(l_L249X3);
  sim_icache_fetch(4329 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5900 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5901 */
   __GOTO(l_L266X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L266X3;
} /* line 5902 */
l_L267X3: ;/* line 5905 */
__LABEL(l_L267X3);
  sim_icache_fetch(4332 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5906 */
   __MOV(reg_r0_7, 0); /* line 5907 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 5908 */
} /* line 5908 */
  sim_icache_fetch(4336 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 5910 */
} /* line 5910 */
  sim_icache_fetch(4337 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 5912 */
} /* line 5912 */
l_L241X3: ;/* line 5915 */
__LABEL(l_L241X3);
  sim_icache_fetch(4338 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5916 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 5917 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 5918 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 5919 */
} /* line 5919 */
  sim_icache_fetch(4344 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 5921 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 5922 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 5923 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 5924 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 5925 */
} /* line 5925 */
  sim_icache_fetch(4352 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 5927 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 5928 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 5929 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 5930 */
} /* line 5930 */
  sim_icache_fetch(4356 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 5932 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 5933 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 5934 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 5935 */
} /* line 5935 */
  sim_icache_fetch(4361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 5937 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 5938 */
} /* line 5938 */
  sim_icache_fetch(4363 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5940 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 5941 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 5942 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 5943 */
} /* line 5943 */
  sim_icache_fetch(4367 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 5945 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5946 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 5947 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5948 */
   __ADD_CYCLES(1);
} /* line 5948 */
  sim_icache_fetch(4372 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 5950 */
} /* line 5950 */
  sim_icache_fetch(4373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 5952 */
} /* line 5952 */
  sim_icache_fetch(4374 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 5955 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5956 */
l_L264X3: ;/* line 5959 */
__LABEL(l_L264X3);
  sim_icache_fetch(4376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5960 */
   __GOTO(l_L265X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L265X3;
} /* line 5961 */
l_L246X3: ;/* line 5964 */
__LABEL(l_L246X3);
  sim_icache_fetch(4378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 5965 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5966 */
} /* line 5966 */
l_L266X3: ;/* line 5968 */
__LABEL(l_L266X3);
  sim_icache_fetch(4380 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 5969 */
} /* line 5969 */
  sim_icache_fetch(4381 + t_thisfile.offset, 1);
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
} /* line 5971 */
  sim_icache_fetch(4382 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 5974 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 5975 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5976 */
l_L262X3: ;/* line 5979 */
__LABEL(l_L262X3);
  sim_icache_fetch(4387 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 5980 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5981 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5982 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5983 */
   __ADD_CYCLES(1);
} /* line 5983 */
  sim_icache_fetch(4393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 5985 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5986 */
} /* line 5986 */
  sim_icache_fetch(4395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5988 */
   __GOTO(l_L263X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L263X3;
} /* line 5989 */
l_L260X3: ;/* line 5992 */
__LABEL(l_L260X3);
  sim_icache_fetch(4397 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 5993 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5994 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5995 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5996 */
   __ADD_CYCLES(1);
} /* line 5996 */
  sim_icache_fetch(4403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 5998 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5999 */
} /* line 5999 */
  sim_icache_fetch(4405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6001 */
   __GOTO(l_L261X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L261X3;
} /* line 6002 */
l_L258X3: ;/* line 6005 */
__LABEL(l_L258X3);
  sim_icache_fetch(4407 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6006 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6007 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6008 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6009 */
   __ADD_CYCLES(1);
} /* line 6009 */
  sim_icache_fetch(4413 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6011 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6012 */
} /* line 6012 */
  sim_icache_fetch(4415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6014 */
   __GOTO(l_L259X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L259X3;
} /* line 6015 */
l_L256X3: ;/* line 6018 */
__LABEL(l_L256X3);
  sim_icache_fetch(4417 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6019 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6020 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6021 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6022 */
   __ADD_CYCLES(1);
} /* line 6022 */
  sim_icache_fetch(4423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6024 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6025 */
} /* line 6025 */
  sim_icache_fetch(4425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6027 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 6028 */
l_L254X3: ;/* line 6031 */
__LABEL(l_L254X3);
  sim_icache_fetch(4427 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6032 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6033 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6034 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6035 */
   __ADD_CYCLES(1);
} /* line 6035 */
  sim_icache_fetch(4433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6037 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6038 */
} /* line 6038 */
  sim_icache_fetch(4435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6040 */
   __GOTO(l_L255X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L255X3;
} /* line 6041 */
l_L252X3: ;/* line 6044 */
__LABEL(l_L252X3);
  sim_icache_fetch(4437 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6045 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6046 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6047 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6048 */
   __ADD_CYCLES(1);
} /* line 6048 */
  sim_icache_fetch(4443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6050 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6051 */
} /* line 6051 */
  sim_icache_fetch(4445 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6053 */
   __GOTO(l_L253X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L253X3;
} /* line 6054 */
l_L250X3: ;/* line 6057 */
__LABEL(l_L250X3);
  sim_icache_fetch(4447 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6058 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6059 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6060 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6061 */
   __ADD_CYCLES(1);
} /* line 6061 */
  sim_icache_fetch(4453 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6063 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6064 */
} /* line 6064 */
  sim_icache_fetch(4455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6066 */
   __GOTO(l_L251X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L251X3;
} /* line 6067 */
l_L247X3: ;/* line 6070 */
__LABEL(l_L247X3);
  sim_icache_fetch(4457 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6071 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6072 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6073 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6074 */
} /* line 6074 */
  sim_icache_fetch(4462 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6076 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6077 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6078 */
} /* line 6078 */
  sim_icache_fetch(4465 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6080 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6081 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6082 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6083 */
} /* line 6083 */
  sim_icache_fetch(4469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6085 */
   __GOTO(l_L248X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L248X3;
} /* line 6086 */
l_L244X3: ;/* line 6089 */
__LABEL(l_L244X3);
  sim_icache_fetch(4471 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6090 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6091 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6092 */
} /* line 6092 */
  sim_icache_fetch(4476 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6094 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6095 */
} /* line 6095 */
  sim_icache_fetch(4480 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6097 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6098 */
   __ADD_CYCLES(1);
} /* line 6098 */
  sim_icache_fetch(4483 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6100 */
} /* line 6100 */
  sim_icache_fetch(4484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6102 */
   __GOTO(l_L245X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L245X3;
} /* line 6103 */
l_L243X3: ;/* line 6106 */
__LABEL(l_L243X3);
  sim_icache_fetch(4486 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6107 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6108 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6109 */
   __ADD_CYCLES(1);
} /* line 6109 */
  sim_icache_fetch(4490 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6111 */
} /* line 6111 */
  sim_icache_fetch(4491 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6113 */
} /* line 6113 */
  sim_icache_fetch(4492 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6115 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 6116 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 414: goto l_L242X3;
    case 415: goto l_L245X3;
    case 416: goto l_L248X3;
    case 417: goto l_L251X3;
    case 418: goto l_L253X3;
    case 419: goto l_L255X3;
    case 420: goto l_L257X3;
    case 421: goto l_L259X3;
    case 422: goto l_L261X3;
    case 423: goto l_L263X3;
    case 424: goto l_L265X3;
    case 425: goto l_L249X3;
    case 426: goto l_L267X3;
    case 427: goto l_L241X3;
    case 428: goto l_L264X3;
    case 429: goto l_L246X3;
    case 430: goto l_L266X3;
    case 431: goto l_L262X3;
    case 432: goto l_L260X3;
    case 433: goto l_L258X3;
    case 434: goto l_L256X3;
    case 435: goto l_L254X3;
    case 436: goto l_L252X3;
    case 437: goto l_L250X3;
    case 438: goto l_L247X3;
    case 439: goto l_L244X3;
    case 440: goto l_L243X3;
    case 441:
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
  reg_l0_0 = (444 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4495 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6138 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6139 */
} /* line 6139 */
		 /* line 6140 */
  sim_icache_fetch(4498 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6143 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (444 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6143 */
l_lr_342: ;/* line 6143 */
__LABEL(l_lr_342);
  sim_icache_fetch(4501 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6145 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6146 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6147 */
   __ADD_CYCLES(1);
} /* line 6147 */
  sim_icache_fetch(4504 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6150 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 443: goto l_lr_342;
    case 444:
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
  reg_l0_0 = (446 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4505 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6196 */
   __MOV(reg_r0_3, 0); /* line 6197 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6198 */
   __ADD_CYCLES(1);
} /* line 6198 */
  sim_icache_fetch(4509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6200 */
} /* line 6200 */
  sim_icache_fetch(4510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6202 */
  sim_icache_fetch(4511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6205 */
l_L268X3: ;/* line 6208 */
__LABEL(l_L268X3);
  sim_icache_fetch(4512 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6211 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6211 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 445: goto l_L268X3;
    case 446:
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
  reg_l0_0 = (447 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4514 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6227 */
} /* line 6227 */
  sim_icache_fetch(4515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6230 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 447:
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
  reg_l0_0 = (451 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4516 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6245 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6246 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6247 */
} /* line 6247 */
  sim_icache_fetch(4521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6249 */
} /* line 6249 */
  sim_icache_fetch(4522 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6251 */
} /* line 6251 */
  sim_icache_fetch(4523 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L269X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6253 */
		 /* line 6254 */
  sim_icache_fetch(4524 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (451 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6256 */
l_lr_348: ;/* line 6256 */
__LABEL(l_lr_348);
l_L269X3: ;/* line 6258 */
__LABEL(l_L269X3);
  sim_icache_fetch(4526 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6259 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6260 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6261 */
   __ADD_CYCLES(1);
} /* line 6261 */
  sim_icache_fetch(4529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6264 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 449: goto l_lr_348;
    case 450: goto l_L269X3;
    case 451:
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
  reg_l0_0 = (464 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4530 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6310 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6311 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6312 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6313 */
} /* line 6313 */
  sim_icache_fetch(4537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6315 */
} /* line 6315 */
  sim_icache_fetch(4538 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6317 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6318 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6319 */
} /* line 6319 */
  sim_icache_fetch(4543 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6321 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6322 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L270X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6323 */
  sim_icache_fetch(4547 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L271X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6325 */
l_L272X3: ;/* line 6328 */
__LABEL(l_L272X3);
  sim_icache_fetch(4548 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6329 */
   __MOV(reg_r0_3, 0); /* line 6330 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6331 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6332 */
   __ADD_CYCLES(1);
} /* line 6332 */
  sim_icache_fetch(4553 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6334 */
} /* line 6334 */
  sim_icache_fetch(4554 + t_thisfile.offset, 1);
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
} /* line 6336 */
  sim_icache_fetch(4555 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6339 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6340 */
l_L273X3: ;/* line 6343 */
__LABEL(l_L273X3);
  sim_icache_fetch(4558 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6344 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6345 */
} /* line 6345 */
		 /* line 6346 */
  sim_icache_fetch(4562 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (464 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6348 */
l_lr_354: ;/* line 6348 */
__LABEL(l_lr_354);
  sim_icache_fetch(4564 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6350 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6351 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6352 */
} /* line 6352 */
		 /* line 6353 */
  sim_icache_fetch(4569 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6355 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6356 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (464 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6357 */
l_lr_356: ;/* line 6357 */
__LABEL(l_lr_356);
  sim_icache_fetch(4575 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6359 */
   __MOV(reg_r0_3, 0); /* line 6360 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6361 */
   __ADD_CYCLES(1);
} /* line 6361 */
  sim_icache_fetch(4578 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6364 */
l_L271X3: ;/* line 6367 */
__LABEL(l_L271X3);
  sim_icache_fetch(4579 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6368 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6369 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6370 */
   __ADD_CYCLES(1);
} /* line 6370 */
		 /* line 6371 */
  sim_icache_fetch(4583 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6374 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (464 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6374 */
l_lr_359: ;/* line 6374 */
__LABEL(l_lr_359);
  sim_icache_fetch(4586 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6376 */
   __GOTO(l_L272X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L272X3;
} /* line 6377 */
l_L270X3: ;/* line 6380 */
__LABEL(l_L270X3);
  sim_icache_fetch(4588 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6381 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6382 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6383 */
   __ADD_CYCLES(1);
} /* line 6383 */
		 /* line 6384 */
  sim_icache_fetch(4593 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6386 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (464 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6387 */
l_lr_362: ;/* line 6387 */
__LABEL(l_lr_362);
  sim_icache_fetch(4596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6389 */
   __GOTO(l_L272X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L272X3;
} /* line 6390 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 452: goto l_L272X3;
    case 453: goto l_L273X3;
    case 455: goto l_lr_354;
    case 457: goto l_lr_356;
    case 458: goto l_L271X3;
    case 460: goto l_lr_359;
    case 461: goto l_L270X3;
    case 463: goto l_lr_362;
    case 464:
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
  reg_l0_0 = (482 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4598 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6409 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6410 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6411 */
} /* line 6411 */
  sim_icache_fetch(4602 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6413 */
} /* line 6413 */
l_L274X3: ;/* line 6416 */
__LABEL(l_L274X3);
  sim_icache_fetch(4603 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_2); /* line 6417 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6418 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6419 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6420 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6421 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6422 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6423 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6424 */
} /* line 6424 */
  sim_icache_fetch(4611 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6426 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6427 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6428 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6429 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6430 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6431 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6432 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6433 */
} /* line 6433 */
  sim_icache_fetch(4619 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6435 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6436 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6437 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6438 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6439 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6440 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6441 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6442 */
} /* line 6442 */
  sim_icache_fetch(4627 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6444 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6445 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6446 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L275X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6447 */
  sim_icache_fetch(4631 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6449 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6450 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6451 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6452 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6453 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6454 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6455 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6456 */
} /* line 6456 */
  sim_icache_fetch(4639 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6458 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6459 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6460 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6461 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6462 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6463 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6464 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6465 */
} /* line 6465 */
  sim_icache_fetch(4647 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6467 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L276X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6468 */
  sim_icache_fetch(4649 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6470 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6471 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6472 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6473 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6474 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6475 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6476 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6477 */
} /* line 6477 */
  sim_icache_fetch(4657 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6479 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6480 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6481 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6482 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6483 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6484 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6485 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6486 */
} /* line 6486 */
  sim_icache_fetch(4665 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6488 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L277X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6489 */
  sim_icache_fetch(4667 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6491 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6492 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6493 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6494 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6495 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6496 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6497 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6498 */
} /* line 6498 */
  sim_icache_fetch(4675 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6500 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6501 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6502 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6503 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6504 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6505 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6506 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6507 */
} /* line 6507 */
  sim_icache_fetch(4683 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6509 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L278X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6510 */
  sim_icache_fetch(4685 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6512 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6513 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6514 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6515 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6516 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6517 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6518 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6519 */
} /* line 6519 */
  sim_icache_fetch(4693 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6521 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6522 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6523 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6525 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6527 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6528 */
} /* line 6528 */
  sim_icache_fetch(4701 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6531 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6532 */
  sim_icache_fetch(4704 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6534 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6535 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6536 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6537 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6538 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6539 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6540 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6541 */
} /* line 6541 */
  sim_icache_fetch(4720 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6543 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6544 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6545 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6546 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6547 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6548 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6549 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6550 */
} /* line 6550 */
  sim_icache_fetch(4736 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6552 */
  sim_icache_fetch(4737 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6554 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6555 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6556 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6557 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6558 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6559 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6560 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6561 */
} /* line 6561 */
  sim_icache_fetch(4753 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6564 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6565 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6567 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6568 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6569 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6570 */
} /* line 6570 */
  sim_icache_fetch(4769 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6572 */
  sim_icache_fetch(4770 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6574 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6575 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6576 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6577 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6578 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6579 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6580 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6581 */
} /* line 6581 */
  sim_icache_fetch(4786 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6583 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6584 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6588 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6589 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6590 */
} /* line 6590 */
  sim_icache_fetch(4802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6592 */
  sim_icache_fetch(4803 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6594 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6595 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6596 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6597 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6599 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6600 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6601 */
} /* line 6601 */
  sim_icache_fetch(4819 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6604 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6605 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6606 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6608 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6610 */
} /* line 6610 */
  sim_icache_fetch(4835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6612 */
  sim_icache_fetch(4836 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6614 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6615 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6616 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6617 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6620 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6621 */
} /* line 6621 */
  sim_icache_fetch(4852 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6623 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6624 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6625 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6626 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6627 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6628 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6629 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6630 */
} /* line 6630 */
  sim_icache_fetch(4868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6632 */
  sim_icache_fetch(4869 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6634 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6635 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6636 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6637 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6639 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6640 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6641 */
} /* line 6641 */
  sim_icache_fetch(4885 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6644 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6645 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6646 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6647 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6648 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6650 */
} /* line 6650 */
  sim_icache_fetch(4901 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6652 */
  sim_icache_fetch(4902 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6654 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6655 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6656 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6658 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6659 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6660 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6661 */
} /* line 6661 */
  sim_icache_fetch(4918 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6664 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6665 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6666 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6667 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6668 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6669 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6670 */
} /* line 6670 */
  sim_icache_fetch(4934 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6672 */
  sim_icache_fetch(4935 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6674 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6675 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6676 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6677 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6678 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6679 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6680 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6681 */
} /* line 6681 */
  sim_icache_fetch(4950 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6683 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6684 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6685 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6686 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6687 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6688 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6689 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6690 */
} /* line 6690 */
  sim_icache_fetch(4965 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6692 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6693 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6694 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6695 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L287X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6697 */
  sim_icache_fetch(4974 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L274X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L274X3;
} /* line 6699 */
l_L287X3: ;/* line 6702 */
__LABEL(l_L287X3);
  sim_icache_fetch(4975 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6703 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6704 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6705 */
l_L289X3: ;/* line 6708 */
__LABEL(l_L289X3);
  sim_icache_fetch(4979 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6709 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6710 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6711 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6712 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 4); /* line 6713 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 5); /* line 6714 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 6); /* line 6715 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6716 */
} /* line 6716 */
  sim_icache_fetch(4987 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 7); /* line 6718 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 8); /* line 6719 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6720 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6721 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6722 */
  sim_icache_fetch(4992 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6724 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6725 */
  sim_icache_fetch(4994 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6727 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6728 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6729 */
  sim_icache_fetch(4997 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6731 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6732 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6733 */
  sim_icache_fetch(5000 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6735 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6736 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6737 */
  sim_icache_fetch(5003 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6739 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 12); /* line 6740 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6741 */
  sim_icache_fetch(5006 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6743 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 13); /* line 6744 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6745 */
  sim_icache_fetch(5009 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6747 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 14); /* line 6748 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6749 */
  sim_icache_fetch(5012 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6751 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 15); /* line 6752 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6753 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6754 */
  sim_icache_fetch(5016 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6756 */
   __CMPGT(reg_b0_7, reg_r0_5, 0); /* line 6757 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6758 */
  sim_icache_fetch(5019 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6760 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6761 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6762 */
  sim_icache_fetch(5022 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6764 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6765 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6766 */
  sim_icache_fetch(5025 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6768 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6769 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6770 */
  sim_icache_fetch(5028 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6772 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 4); /* line 6773 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6774 */
  sim_icache_fetch(5031 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6776 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 5); /* line 6777 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6778 */
  sim_icache_fetch(5034 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6780 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 6); /* line 6781 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6782 */
  sim_icache_fetch(5037 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6784 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 7); /* line 6785 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6786 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6787 */
  sim_icache_fetch(5041 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6789 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 6790 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6791 */
  sim_icache_fetch(5044 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6793 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6794 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6795 */
  sim_icache_fetch(5047 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6797 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6798 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6799 */
  sim_icache_fetch(5050 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6801 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6802 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6803 */
  sim_icache_fetch(5053 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6805 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 12); /* line 6806 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6807 */
  sim_icache_fetch(5056 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6809 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 13); /* line 6810 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6811 */
  sim_icache_fetch(5059 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6813 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 14); /* line 6814 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6815 */
  sim_icache_fetch(5062 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6817 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 15); /* line 6818 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6819 */
  sim_icache_fetch(5065 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6821 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6822 */
  sim_icache_fetch(5067 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6824 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6825 */
  sim_icache_fetch(5069 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6827 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6828 */
  sim_icache_fetch(5071 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6830 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6831 */
  sim_icache_fetch(5073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6833 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6834 */
  sim_icache_fetch(5075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6836 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6837 */
  sim_icache_fetch(5077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6839 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6840 */
  sim_icache_fetch(5079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6842 */
   __GOTO(l_L289X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L289X3;
} /* line 6843 */
l_L290X3: ;/* line 6846 */
__LABEL(l_L290X3);
  sim_icache_fetch(5081 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6848 */
l_L286X3: ;/* line 6851 */
__LABEL(l_L286X3);
  sim_icache_fetch(5082 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6852 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6853 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6854 */
l_L285X3: ;/* line 6857 */
__LABEL(l_L285X3);
  sim_icache_fetch(5086 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6858 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6859 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6860 */
l_L284X3: ;/* line 6863 */
__LABEL(l_L284X3);
  sim_icache_fetch(5090 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6864 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6865 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6866 */
l_L283X3: ;/* line 6869 */
__LABEL(l_L283X3);
  sim_icache_fetch(5094 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6870 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6871 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6872 */
l_L282X3: ;/* line 6875 */
__LABEL(l_L282X3);
  sim_icache_fetch(5098 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6876 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6877 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6878 */
l_L281X3: ;/* line 6881 */
__LABEL(l_L281X3);
  sim_icache_fetch(5102 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6882 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6883 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6884 */
l_L280X3: ;/* line 6887 */
__LABEL(l_L280X3);
  sim_icache_fetch(5106 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6888 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6889 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6890 */
l_L279X3: ;/* line 6893 */
__LABEL(l_L279X3);
  sim_icache_fetch(5110 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6894 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6895 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6896 */
l_L278X3: ;/* line 6899 */
__LABEL(l_L278X3);
  sim_icache_fetch(5114 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6900 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6901 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6902 */
l_L277X3: ;/* line 6905 */
__LABEL(l_L277X3);
  sim_icache_fetch(5117 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6906 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6907 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6908 */
l_L276X3: ;/* line 6911 */
__LABEL(l_L276X3);
  sim_icache_fetch(5120 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6912 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6913 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 6914 */
l_L275X3: ;/* line 6917 */
__LABEL(l_L275X3);
  sim_icache_fetch(5123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 6918 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6919 */
} /* line 6919 */
l_L288X3: ;/* line 6921 */
__LABEL(l_L288X3);
  sim_icache_fetch(5125 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 6922 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 6923 */
   __GOTO(l_L289X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L289X3;
} /* line 6924 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 465: goto l_L274X3;
    case 466: goto l_L287X3;
    case 467: goto l_L289X3;
    case 468: goto l_L290X3;
    case 469: goto l_L286X3;
    case 470: goto l_L285X3;
    case 471: goto l_L284X3;
    case 472: goto l_L283X3;
    case 473: goto l_L282X3;
    case 474: goto l_L281X3;
    case 475: goto l_L280X3;
    case 476: goto l_L279X3;
    case 477: goto l_L278X3;
    case 478: goto l_L277X3;
    case 479: goto l_L276X3;
    case 480: goto l_L275X3;
    case 481: goto l_L288X3;
    case 482:
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
  reg_l0_0 = (483 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5128 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6940 */
} /* line 6940 */
  sim_icache_fetch(5129 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6943 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 483:
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
  reg_l0_0 = (484 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5130 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6959 */
} /* line 6959 */
  sim_icache_fetch(5131 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
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
    case 484:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 5136, 0, 0, 0, 2};

