/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/1_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_8419Xoffset[1];
unsigned int compress_8419Xbuf[3];
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
unsigned int compress_8419XBuf[216]; 
unsigned int compress_8419Xrcs_ident[6]; 
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
	(134 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(148 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(140 << 5),
	(139 << 5),
	(138 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(137 << 5),
	(152 << 5),
	(152 << 5),
	(136 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(152 << 5),
	(135 << 5)
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

unsigned int compress_8419XBuf[216] = { 
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

unsigned int compress_8419Xrcs_ident[6] = { 
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

  sim_icache_fetch(0 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 19 */
} /* line 19 */
  sim_icache_fetch(1 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_l0_0); /* line 21 */
} /* line 21 */
  sim_icache_fetch(2 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_1, (unsigned int) 28); /* line 23 */
} /* line 23 */
  sim_icache_fetch(3 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_4); /* line 25 */
} /* line 25 */
  sim_icache_fetch(4 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_1, (unsigned int) 16); /* line 27 */
} /* line 27 */
  sim_icache_fetch(5 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_2); /* line 29 */
} /* line 29 */
  sim_icache_fetch(6 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 9); /* line 31 */
} /* line 31 */
  sim_icache_fetch(7 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1PACKETX4); /* line 33 */
} /* line 33 */
		 /* line 34 */
  sim_icache_fetch(9 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
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
} /* line 36 */
l_lr_1: ;/* line 36 */
__LABEL(l_lr_1);
  sim_icache_fetch(11 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 38 */
} /* line 38 */
  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 40 */
} /* line 40 */
  sim_icache_fetch(13 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) compress_8419XBuf); /* line 42 */
} /* line 42 */
  sim_icache_fetch(15 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) 800); /* line 44 */
} /* line 44 */
  sim_icache_fetch(17 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 46 */
} /* line 46 */
  sim_icache_fetch(18 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_2); /* line 48 */
} /* line 48 */
  sim_icache_fetch(19 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), 0); /* line 50 */
} /* line 50 */
  sim_icache_fetch(21 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 52 */
} /* line 52 */
  sim_icache_fetch(23 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_6); /* line 54 */
} /* line 54 */
		 /* line 55 */
  sim_icache_fetch(25 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
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
} /* line 57 */
l_lr_3: ;/* line 57 */
__LABEL(l_lr_3);
  sim_icache_fetch(27 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 59 */
} /* line 59 */
		 /* line 60 */
  sim_icache_fetch(29 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
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
} /* line 62 */
l_lr_5: ;/* line 62 */
__LABEL(l_lr_5);
  sim_icache_fetch(31 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 64 */
} /* line 64 */
  sim_icache_fetch(32 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 66 */
} /* line 66 */
  sim_icache_fetch(33 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 69 */
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

  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 120 */
} /* line 120 */
  sim_icache_fetch(35 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 122 */
} /* line 122 */
  sim_icache_fetch(36 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX2); /* line 124 */
} /* line 124 */
		 /* line 125 */
  sim_icache_fetch(38 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
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
} /* line 127 */
l_lr_8: ;/* line 127 */
__LABEL(l_lr_8);
  sim_icache_fetch(40 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 129 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 130 */
   __ADD_CYCLES(1);
} /* line 130 */
  sim_icache_fetch(42 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Usage);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 133 */
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
  reg_l0_0 = (129 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 193 */
  sim_icache_fetch(44 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 15); /* line 195 */
} /* line 195 */
  sim_icache_fetch(45 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_3, (unsigned int) 14); /* line 197 */
} /* line 197 */
  sim_icache_fetch(46 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 13); /* line 199 */
} /* line 199 */
  sim_icache_fetch(47 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_3, (unsigned int) 12); /* line 201 */
} /* line 201 */
  sim_icache_fetch(48 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 11); /* line 203 */
} /* line 203 */
  sim_icache_fetch(49 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_3, (unsigned int) 10); /* line 205 */
} /* line 205 */
  sim_icache_fetch(50 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 9); /* line 207 */
} /* line 207 */
  sim_icache_fetch(51 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_3, (unsigned int) 8); /* line 209 */
} /* line 209 */
  sim_icache_fetch(52 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 7); /* line 211 */
} /* line 211 */
  sim_icache_fetch(53 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_3, (unsigned int) 6); /* line 213 */
} /* line 213 */
  sim_icache_fetch(54 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 5); /* line 215 */
} /* line 215 */
  sim_icache_fetch(55 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_3, (unsigned int) 4); /* line 217 */
} /* line 217 */
  sim_icache_fetch(56 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 3); /* line 219 */
} /* line 219 */
  sim_icache_fetch(57 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) 2); /* line 221 */
} /* line 221 */
  sim_icache_fetch(58 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 223 */
} /* line 223 */
  sim_icache_fetch(59 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SXTB(reg_r0_4, reg_r0_4); /* line 225 */
} /* line 225 */
  sim_icache_fetch(60 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, 0); /* line 227 */
} /* line 227 */
  sim_icache_fetch(61 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_3); /* line 229 */
} /* line 229 */
l_L0X3: ;/* line 232 */
__LABEL(l_L0X3);
  sim_icache_fetch(62 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 233 */
} /* line 233 */
  sim_icache_fetch(63 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_6,0,1)); /* line 235 */
} /* line 235 */
  sim_icache_fetch(64 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 237 */
} /* line 237 */
  sim_icache_fetch(65 + t_thisfile.offset, 1);
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
} /* line 239 */
  sim_icache_fetch(66 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 241 */
} /* line 241 */
  sim_icache_fetch(67 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_2, reg_r0_5); /* line 243 */
} /* line 243 */
  sim_icache_fetch(68 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 245 */
} /* line 245 */
  sim_icache_fetch(69 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 247 */
  sim_icache_fetch(70 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 249 */
} /* line 249 */
  sim_icache_fetch(71 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_6, reg_r0_5); /* line 251 */
} /* line 251 */
  sim_icache_fetch(72 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_7,0,1)); /* line 253 */
} /* line 253 */
  sim_icache_fetch(73 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_8,0,1)); /* line 255 */
} /* line 255 */
  sim_icache_fetch(74 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 257 */
} /* line 257 */
  sim_icache_fetch(75 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 259 */
  sim_icache_fetch(76 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 261 */
} /* line 261 */
  sim_icache_fetch(77 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_7, reg_r0_5); /* line 263 */
} /* line 263 */
  sim_icache_fetch(78 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 265 */
} /* line 265 */
  sim_icache_fetch(79 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 267 */
  sim_icache_fetch(80 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 269 */
} /* line 269 */
  sim_icache_fetch(81 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_8, reg_r0_5); /* line 271 */
} /* line 271 */
  sim_icache_fetch(82 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 273 */
} /* line 273 */
  sim_icache_fetch(83 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_10,0,1)); /* line 275 */
} /* line 275 */
  sim_icache_fetch(84 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 277 */
} /* line 277 */
  sim_icache_fetch(85 + t_thisfile.offset, 1);
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
} /* line 279 */
  sim_icache_fetch(86 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 281 */
} /* line 281 */
  sim_icache_fetch(87 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_9, reg_r0_5); /* line 283 */
} /* line 283 */
  sim_icache_fetch(88 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 285 */
} /* line 285 */
  sim_icache_fetch(89 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 287 */
  sim_icache_fetch(90 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 289 */
} /* line 289 */
  sim_icache_fetch(91 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_10, reg_r0_5); /* line 291 */
} /* line 291 */
  sim_icache_fetch(92 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_11,0,1)); /* line 293 */
} /* line 293 */
  sim_icache_fetch(93 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_12,0,1)); /* line 295 */
} /* line 295 */
  sim_icache_fetch(94 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 297 */
} /* line 297 */
  sim_icache_fetch(95 + t_thisfile.offset, 1);
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
} /* line 299 */
  sim_icache_fetch(96 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 301 */
} /* line 301 */
  sim_icache_fetch(97 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_11, reg_r0_5); /* line 303 */
} /* line 303 */
  sim_icache_fetch(98 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 305 */
} /* line 305 */
  sim_icache_fetch(99 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 307 */
  sim_icache_fetch(100 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 309 */
} /* line 309 */
  sim_icache_fetch(101 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_12, reg_r0_5); /* line 311 */
} /* line 311 */
  sim_icache_fetch(102 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_13,0,1)); /* line 313 */
} /* line 313 */
  sim_icache_fetch(103 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_14,0,1)); /* line 315 */
} /* line 315 */
  sim_icache_fetch(104 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 317 */
} /* line 317 */
  sim_icache_fetch(105 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 319 */
  sim_icache_fetch(106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 321 */
} /* line 321 */
  sim_icache_fetch(107 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_13, reg_r0_5); /* line 323 */
} /* line 323 */
  sim_icache_fetch(108 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 325 */
} /* line 325 */
  sim_icache_fetch(109 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 327 */
  sim_icache_fetch(110 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 329 */
} /* line 329 */
  sim_icache_fetch(111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_14, reg_r0_5); /* line 331 */
} /* line 331 */
  sim_icache_fetch(112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_15,0,1)); /* line 333 */
} /* line 333 */
  sim_icache_fetch(113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_16,0,1)); /* line 335 */
} /* line 335 */
  sim_icache_fetch(114 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 337 */
} /* line 337 */
  sim_icache_fetch(115 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 339 */
  sim_icache_fetch(116 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 341 */
} /* line 341 */
  sim_icache_fetch(117 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_15, reg_r0_5); /* line 343 */
} /* line 343 */
  sim_icache_fetch(118 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 345 */
} /* line 345 */
  sim_icache_fetch(119 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 347 */
  sim_icache_fetch(120 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 349 */
} /* line 349 */
  sim_icache_fetch(121 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_16, reg_r0_5); /* line 351 */
} /* line 351 */
  sim_icache_fetch(122 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_17,0,1)); /* line 353 */
} /* line 353 */
  sim_icache_fetch(123 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_18,0,1)); /* line 355 */
} /* line 355 */
  sim_icache_fetch(124 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 357 */
} /* line 357 */
  sim_icache_fetch(125 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 359 */
  sim_icache_fetch(126 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 361 */
} /* line 361 */
  sim_icache_fetch(127 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_17, reg_r0_5); /* line 363 */
} /* line 363 */
  sim_icache_fetch(128 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 365 */
} /* line 365 */
  sim_icache_fetch(129 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 367 */
  sim_icache_fetch(130 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 369 */
} /* line 369 */
  sim_icache_fetch(131 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_18, reg_r0_5); /* line 371 */
} /* line 371 */
  sim_icache_fetch(132 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_19,0,1)); /* line 373 */
} /* line 373 */
  sim_icache_fetch(133 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_20,0,1)); /* line 375 */
} /* line 375 */
  sim_icache_fetch(134 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 377 */
} /* line 377 */
  sim_icache_fetch(135 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 379 */
  sim_icache_fetch(136 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 381 */
} /* line 381 */
  sim_icache_fetch(137 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_19, reg_r0_5); /* line 383 */
} /* line 383 */
  sim_icache_fetch(138 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 385 */
} /* line 385 */
  sim_icache_fetch(139 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 387 */
  sim_icache_fetch(140 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 389 */
} /* line 389 */
  sim_icache_fetch(141 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_20, reg_r0_5); /* line 391 */
} /* line 391 */
  sim_icache_fetch(142 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 393 */
} /* line 393 */
  sim_icache_fetch(143 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 395 */
} /* line 395 */
  sim_icache_fetch(144 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 397 */
} /* line 397 */
  sim_icache_fetch(145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 399 */
} /* line 399 */
  sim_icache_fetch(146 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 401 */
} /* line 401 */
  sim_icache_fetch(147 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 403 */
} /* line 403 */
  sim_icache_fetch(148 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 405 */
} /* line 405 */
  sim_icache_fetch(149 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 407 */
} /* line 407 */
  sim_icache_fetch(150 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 409 */
} /* line 409 */
  sim_icache_fetch(151 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 411 */
} /* line 411 */
  sim_icache_fetch(152 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 413 */
} /* line 413 */
  sim_icache_fetch(153 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 415 */
} /* line 415 */
  sim_icache_fetch(154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 417 */
} /* line 417 */
  sim_icache_fetch(155 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 419 */
} /* line 419 */
  sim_icache_fetch(156 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 421 */
} /* line 421 */
  sim_icache_fetch(157 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 423 */
} /* line 423 */
  sim_icache_fetch(158 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 425 */
} /* line 425 */
  sim_icache_fetch(159 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_6,0,1)); /* line 427 */
} /* line 427 */
  sim_icache_fetch(160 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 429 */
} /* line 429 */
  sim_icache_fetch(161 + t_thisfile.offset, 1);
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
} /* line 431 */
  sim_icache_fetch(162 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 433 */
} /* line 433 */
  sim_icache_fetch(163 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_2, reg_r0_5); /* line 435 */
} /* line 435 */
  sim_icache_fetch(164 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 437 */
} /* line 437 */
  sim_icache_fetch(165 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 439 */
  sim_icache_fetch(166 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 441 */
} /* line 441 */
  sim_icache_fetch(167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_6, reg_r0_5); /* line 443 */
} /* line 443 */
  sim_icache_fetch(168 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_7,0,1)); /* line 445 */
} /* line 445 */
  sim_icache_fetch(169 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_8,0,1)); /* line 447 */
} /* line 447 */
  sim_icache_fetch(170 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 449 */
} /* line 449 */
  sim_icache_fetch(171 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 451 */
  sim_icache_fetch(172 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 453 */
} /* line 453 */
  sim_icache_fetch(173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_7, reg_r0_5); /* line 455 */
} /* line 455 */
  sim_icache_fetch(174 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 457 */
} /* line 457 */
  sim_icache_fetch(175 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 459 */
  sim_icache_fetch(176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 461 */
} /* line 461 */
  sim_icache_fetch(177 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_8, reg_r0_5); /* line 463 */
} /* line 463 */
  sim_icache_fetch(178 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 465 */
} /* line 465 */
  sim_icache_fetch(179 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_10,0,1)); /* line 467 */
} /* line 467 */
  sim_icache_fetch(180 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 469 */
} /* line 469 */
  sim_icache_fetch(181 + t_thisfile.offset, 1);
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
} /* line 471 */
  sim_icache_fetch(182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 473 */
} /* line 473 */
  sim_icache_fetch(183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_9, reg_r0_5); /* line 475 */
} /* line 475 */
  sim_icache_fetch(184 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 477 */
} /* line 477 */
  sim_icache_fetch(185 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 479 */
  sim_icache_fetch(186 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 481 */
} /* line 481 */
  sim_icache_fetch(187 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_10, reg_r0_5); /* line 483 */
} /* line 483 */
  sim_icache_fetch(188 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_11,0,1)); /* line 485 */
} /* line 485 */
  sim_icache_fetch(189 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_12,0,1)); /* line 487 */
} /* line 487 */
  sim_icache_fetch(190 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 489 */
} /* line 489 */
  sim_icache_fetch(191 + t_thisfile.offset, 1);
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
} /* line 491 */
  sim_icache_fetch(192 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 493 */
} /* line 493 */
  sim_icache_fetch(193 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_11, reg_r0_5); /* line 495 */
} /* line 495 */
  sim_icache_fetch(194 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 497 */
} /* line 497 */
  sim_icache_fetch(195 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 499 */
  sim_icache_fetch(196 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 501 */
} /* line 501 */
  sim_icache_fetch(197 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_12, reg_r0_5); /* line 503 */
} /* line 503 */
  sim_icache_fetch(198 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_13,0,1)); /* line 505 */
} /* line 505 */
  sim_icache_fetch(199 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_14,0,1)); /* line 507 */
} /* line 507 */
  sim_icache_fetch(200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 509 */
} /* line 509 */
  sim_icache_fetch(201 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 511 */
  sim_icache_fetch(202 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 513 */
} /* line 513 */
  sim_icache_fetch(203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_13, reg_r0_5); /* line 515 */
} /* line 515 */
  sim_icache_fetch(204 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 517 */
} /* line 517 */
  sim_icache_fetch(205 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 519 */
  sim_icache_fetch(206 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 521 */
} /* line 521 */
  sim_icache_fetch(207 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_14, reg_r0_5); /* line 523 */
} /* line 523 */
  sim_icache_fetch(208 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_15,0,1)); /* line 525 */
} /* line 525 */
  sim_icache_fetch(209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_16,0,1)); /* line 527 */
} /* line 527 */
  sim_icache_fetch(210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 529 */
} /* line 529 */
  sim_icache_fetch(211 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 531 */
  sim_icache_fetch(212 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 533 */
} /* line 533 */
  sim_icache_fetch(213 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_15, reg_r0_5); /* line 535 */
} /* line 535 */
  sim_icache_fetch(214 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 537 */
} /* line 537 */
  sim_icache_fetch(215 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 539 */
  sim_icache_fetch(216 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 541 */
} /* line 541 */
  sim_icache_fetch(217 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_16, reg_r0_5); /* line 543 */
} /* line 543 */
  sim_icache_fetch(218 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_17,0,1)); /* line 545 */
} /* line 545 */
  sim_icache_fetch(219 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_18,0,1)); /* line 547 */
} /* line 547 */
  sim_icache_fetch(220 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 549 */
} /* line 549 */
  sim_icache_fetch(221 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 551 */
  sim_icache_fetch(222 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 553 */
} /* line 553 */
  sim_icache_fetch(223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_17, reg_r0_5); /* line 555 */
} /* line 555 */
  sim_icache_fetch(224 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 557 */
} /* line 557 */
  sim_icache_fetch(225 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 559 */
  sim_icache_fetch(226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 561 */
} /* line 561 */
  sim_icache_fetch(227 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_18, reg_r0_5); /* line 563 */
} /* line 563 */
  sim_icache_fetch(228 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_19,0,1)); /* line 565 */
} /* line 565 */
  sim_icache_fetch(229 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_20,0,1)); /* line 567 */
} /* line 567 */
  sim_icache_fetch(230 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 569 */
} /* line 569 */
  sim_icache_fetch(231 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 571 */
  sim_icache_fetch(232 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_4); /* line 573 */
} /* line 573 */
  sim_icache_fetch(233 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_19, reg_r0_5); /* line 575 */
} /* line 575 */
  sim_icache_fetch(234 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_21, 0); /* line 577 */
} /* line 577 */
  sim_icache_fetch(235 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 579 */
  sim_icache_fetch(236 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_21, reg_r0_4); /* line 581 */
} /* line 581 */
  sim_icache_fetch(237 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_20, reg_r0_5); /* line 583 */
} /* line 583 */
  sim_icache_fetch(238 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 585 */
} /* line 585 */
  sim_icache_fetch(239 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 587 */
} /* line 587 */
  sim_icache_fetch(240 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 589 */
} /* line 589 */
  sim_icache_fetch(241 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 591 */
} /* line 591 */
  sim_icache_fetch(242 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 593 */
} /* line 593 */
  sim_icache_fetch(243 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 595 */
} /* line 595 */
  sim_icache_fetch(244 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 597 */
} /* line 597 */
  sim_icache_fetch(245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 599 */
} /* line 599 */
  sim_icache_fetch(246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 601 */
} /* line 601 */
  sim_icache_fetch(247 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 603 */
} /* line 603 */
  sim_icache_fetch(248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 605 */
} /* line 605 */
  sim_icache_fetch(249 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 607 */
} /* line 607 */
  sim_icache_fetch(250 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 609 */
} /* line 609 */
  sim_icache_fetch(251 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 611 */
} /* line 611 */
  sim_icache_fetch(252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 613 */
} /* line 613 */
  sim_icache_fetch(253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 616 */
} /* line 616 */
  sim_icache_fetch(254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 618 */
l_L16X3: ;/* line 621 */
__LABEL(l_L16X3);
  sim_icache_fetch(255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 623 */
} /* line 623 */
  sim_icache_fetch(256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 625 */
l_L15X3: ;/* line 628 */
__LABEL(l_L15X3);
  sim_icache_fetch(257 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 630 */
} /* line 630 */
  sim_icache_fetch(258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 632 */
l_L14X3: ;/* line 635 */
__LABEL(l_L14X3);
  sim_icache_fetch(259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 637 */
} /* line 637 */
  sim_icache_fetch(260 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 639 */
l_L13X3: ;/* line 642 */
__LABEL(l_L13X3);
  sim_icache_fetch(261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 644 */
} /* line 644 */
  sim_icache_fetch(262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 646 */
l_L12X3: ;/* line 649 */
__LABEL(l_L12X3);
  sim_icache_fetch(263 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 651 */
} /* line 651 */
  sim_icache_fetch(264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 653 */
l_L11X3: ;/* line 656 */
__LABEL(l_L11X3);
  sim_icache_fetch(265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 658 */
} /* line 658 */
  sim_icache_fetch(266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 660 */
l_L10X3: ;/* line 663 */
__LABEL(l_L10X3);
  sim_icache_fetch(267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 665 */
} /* line 665 */
  sim_icache_fetch(268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 667 */
l_L9X3: ;/* line 670 */
__LABEL(l_L9X3);
  sim_icache_fetch(269 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 672 */
} /* line 672 */
  sim_icache_fetch(270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 674 */
l_L8X3: ;/* line 677 */
__LABEL(l_L8X3);
  sim_icache_fetch(271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 679 */
} /* line 679 */
  sim_icache_fetch(272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 681 */
l_L7X3: ;/* line 684 */
__LABEL(l_L7X3);
  sim_icache_fetch(273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 686 */
} /* line 686 */
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 688 */
l_L6X3: ;/* line 691 */
__LABEL(l_L6X3);
  sim_icache_fetch(275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 693 */
} /* line 693 */
  sim_icache_fetch(276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 695 */
l_L5X3: ;/* line 698 */
__LABEL(l_L5X3);
  sim_icache_fetch(277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 700 */
} /* line 700 */
  sim_icache_fetch(278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 702 */
l_L4X3: ;/* line 705 */
__LABEL(l_L4X3);
  sim_icache_fetch(279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 707 */
} /* line 707 */
  sim_icache_fetch(280 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 709 */
l_L3X3: ;/* line 712 */
__LABEL(l_L3X3);
  sim_icache_fetch(281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 714 */
} /* line 714 */
  sim_icache_fetch(282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 716 */
l_L2X3: ;/* line 719 */
__LABEL(l_L2X3);
  sim_icache_fetch(283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 721 */
} /* line 721 */
  sim_icache_fetch(284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 723 */
l_L1X3: ;/* line 726 */
__LABEL(l_L1X3);
  sim_icache_fetch(285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 727 */
} /* line 727 */
l_L17X3: ;/* line 729 */
__LABEL(l_L17X3);
  sim_icache_fetch(286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 731 */
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
    case 116: goto l_L12X3;
    case 117: goto l_L11X3;
    case 118: goto l_L10X3;
    case 119: goto l_L9X3;
    case 120: goto l_L8X3;
    case 121: goto l_L7X3;
    case 122: goto l_L6X3;
    case 123: goto l_L5X3;
    case 124: goto l_L4X3;
    case 125: goto l_L3X3;
    case 126: goto l_L2X3;
    case 127: goto l_L1X3;
    case 128: goto l_L17X3;
    case 129:
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
  reg_l0_0 = (185 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 747 */
} /* line 747 */
  sim_icache_fetch(288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 749 */
} /* line 749 */
  sim_icache_fetch(289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_3); /* line 751 */
} /* line 751 */
  sim_icache_fetch(290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_4); /* line 753 */
} /* line 753 */
  sim_icache_fetch(291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 755 */
} /* line 755 */
  sim_icache_fetch(293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 757 */
} /* line 757 */
  sim_icache_fetch(295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 759 */
} /* line 759 */
  sim_icache_fetch(297 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_7); /* line 761 */
} /* line 761 */
  sim_icache_fetch(298 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 763 */
} /* line 763 */
  sim_icache_fetch(300 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 765 */
} /* line 765 */
  sim_icache_fetch(301 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) 47); /* line 767 */
} /* line 767 */
		 /* line 768 */
  sim_icache_fetch(302 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (185 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 770 */
l_lr_30: ;/* line 770 */
__LABEL(l_lr_30);
  sim_icache_fetch(304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 772 */
} /* line 772 */
  sim_icache_fetch(305 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 774 */
} /* line 774 */
  sim_icache_fetch(306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 776 */
} /* line 776 */
  sim_icache_fetch(307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 778 */
} /* line 778 */
l_L18X3: ;/* line 781 */
__LABEL(l_L18X3);
  sim_icache_fetch(308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 782 */
} /* line 782 */
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 784 */
  sim_icache_fetch(310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 786 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 787 */
   __ADD_CYCLES(1);
} /* line 787 */
  sim_icache_fetch(312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 789 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 790 */
   __ADD_CYCLES(1);
} /* line 790 */
  sim_icache_fetch(314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 792 */
} /* line 792 */
  sim_icache_fetch(315 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 794 */
l_L21X3: ;/* line 797 */
__LABEL(l_L21X3);
  sim_icache_fetch(316 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 798 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 799 */
   __ADD_CYCLES(1);
} /* line 799 */
  sim_icache_fetch(318 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 801 */
} /* line 801 */
  sim_icache_fetch(319 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 803 */
} /* line 803 */
  sim_icache_fetch(320 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 805 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 806 */
   __ADD_CYCLES(1);
} /* line 806 */
  sim_icache_fetch(322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 808 */
} /* line 808 */
  sim_icache_fetch(323 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 810 */
  sim_icache_fetch(324 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 812 */
} /* line 812 */
  sim_icache_fetch(325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 814 */
} /* line 814 */
  sim_icache_fetch(326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 816 */
} /* line 816 */
  sim_icache_fetch(327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 818 */
  sim_icache_fetch(328 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 820 */
} /* line 820 */
  sim_icache_fetch(330 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 822 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 823 */
   __ADD_CYCLES(1);
} /* line 823 */
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 825 */
l__X1XCompressXTAGX0X0: ;/* line 827 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 829 */
} /* line 829 */
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L21X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L21X3;
} /* line 831 */
l__X1XCompressXTAGX0X7: ;/* line 834 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(336 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 836 */
} /* line 836 */
  sim_icache_fetch(338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L21X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L21X3;
} /* line 838 */
l__X1XCompressXTAGX0X6: ;/* line 841 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 842 */
} /* line 842 */
  sim_icache_fetch(340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 845 */
} /* line 845 */
  sim_icache_fetch(342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L21X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L21X3;
} /* line 847 */
l__X1XCompressXTAGX0X5: ;/* line 850 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 851 */
} /* line 851 */
  sim_icache_fetch(344 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 854 */
} /* line 854 */
  sim_icache_fetch(346 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L21X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L21X3;
} /* line 856 */
l__X1XCompressXTAGX0X4: ;/* line 859 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 860 */
} /* line 860 */
  sim_icache_fetch(348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 863 */
} /* line 863 */
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L21X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L21X3;
} /* line 865 */
l__X1XCompressXTAGX0X3: ;/* line 868 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 869 */
} /* line 869 */
  sim_icache_fetch(352 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 872 */
} /* line 872 */
  sim_icache_fetch(354 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L21X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L21X3;
} /* line 874 */
l__X1XCompressXTAGX0X2: ;/* line 877 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 878 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 879 */
   __ADD_CYCLES(1);
} /* line 879 */
  sim_icache_fetch(357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 881 */
} /* line 881 */
  sim_icache_fetch(358 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 883 */
} /* line 883 */
  sim_icache_fetch(359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 885 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 886 */
   __ADD_CYCLES(1);
} /* line 886 */
  sim_icache_fetch(361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 888 */
} /* line 888 */
  sim_icache_fetch(362 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 890 */
l_L20X3: ;/* line 892 */
__LABEL(l_L20X3);
  sim_icache_fetch(363 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 893 */
} /* line 893 */
  sim_icache_fetch(364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 896 */
} /* line 896 */
  sim_icache_fetch(365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L18X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L18X3;
} /* line 898 */
l_L23X3: ;/* line 901 */
__LABEL(l_L23X3);
  sim_icache_fetch(366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 902 */
} /* line 902 */
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 904 */
} /* line 904 */
  sim_icache_fetch(368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 906 */
  sim_icache_fetch(369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 908 */
} /* line 908 */
  sim_icache_fetch(370 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 910 */
} /* line 910 */
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 912 */
} /* line 912 */
  sim_icache_fetch(372 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 915 */
  sim_icache_fetch(373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 917 */
l_L24X3: ;/* line 920 */
__LABEL(l_L24X3);
  sim_icache_fetch(374 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 921 */
} /* line 921 */
		 /* line 922 */
  sim_icache_fetch(376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (185 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 924 */
l_lr_44: ;/* line 924 */
__LABEL(l_lr_44);
		 /* line 925 */
  sim_icache_fetch(378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (185 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 927 */
l_lr_46: ;/* line 927 */
__LABEL(l_lr_46);
  sim_icache_fetch(380 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 929 */
} /* line 929 */
  sim_icache_fetch(381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 931 */
} /* line 931 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 934 */
l__X1XCompressXTAGX0X1: ;/* line 937 */
__LABEL(l__X1XCompressXTAGX0X1);
  sim_icache_fetch(383 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 938 */
} /* line 938 */
  sim_icache_fetch(384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 940 */
} /* line 940 */
		 /* line 941 */
  sim_icache_fetch(385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (185 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 943 */
l_lr_49: ;/* line 943 */
__LABEL(l_lr_49);
  sim_icache_fetch(387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 945 */
} /* line 945 */
  sim_icache_fetch(388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 947 */
} /* line 947 */
  sim_icache_fetch(389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L21X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L21X3;
} /* line 949 */
l_L22X3: ;/* line 952 */
__LABEL(l_L22X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 953 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
  sim_icache_fetch(390 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 954 */
} /* line 954 */
		 /* line 955 */
  sim_icache_fetch(392 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (185 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 957 */
l_lr_53: ;/* line 957 */
__LABEL(l_lr_53);
		 /* line 958 */
  sim_icache_fetch(394 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (185 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 960 */
l_lr_55: ;/* line 960 */
__LABEL(l_lr_55);
  sim_icache_fetch(396 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 962 */
} /* line 962 */
  sim_icache_fetch(397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 964 */
} /* line 964 */
  sim_icache_fetch(398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 967 */
l_L19X3: ;/* line 970 */
__LABEL(l_L19X3);
  sim_icache_fetch(399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 971 */
} /* line 971 */
  sim_icache_fetch(401 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) 9); /* line 973 */
} /* line 973 */
  sim_icache_fetch(402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 975 */
} /* line 975 */
  sim_icache_fetch(403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 977 */
  sim_icache_fetch(404 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 12); /* line 979 */
} /* line 979 */
  sim_icache_fetch(405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 981 */
} /* line 981 */
  sim_icache_fetch(406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 5003); /* line 983 */
} /* line 983 */
  sim_icache_fetch(408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) fsize,0,4)); /* line 985 */
} /* line 985 */
  sim_icache_fetch(410 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 987 */
} /* line 987 */
l_L26X3: ;/* line 989 */
__LABEL(l_L26X3);
  sim_icache_fetch(412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 990 */
} /* line 990 */
  sim_icache_fetch(414 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_6, (unsigned int) 4096); /* line 992 */
} /* line 992 */
  sim_icache_fetch(416 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_4, (unsigned int) 12); /* line 994 */
} /* line 994 */
  sim_icache_fetch(417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 996 */
  sim_icache_fetch(418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 998 */
} /* line 998 */
l_L28X3: ;/* line 1000 */
__LABEL(l_L28X3);
  sim_icache_fetch(420 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1001 */
} /* line 1001 */
  sim_icache_fetch(422 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_5); /* line 1003 */
} /* line 1003 */
  sim_icache_fetch(424 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 1005 */
} /* line 1005 */
  sim_icache_fetch(425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 1007 */
} /* line 1007 */
  sim_icache_fetch(427 + t_thisfile.offset, 1);
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
} /* line 1009 */
  sim_icache_fetch(428 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_5); /* line 1011 */
} /* line 1011 */
l_L30X3: ;/* line 1013 */
__LABEL(l_L30X3);
		 /* line 1013 */
  sim_icache_fetch(430 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (185 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1015 */
l_lr_61: ;/* line 1015 */
__LABEL(l_lr_61);
  sim_icache_fetch(432 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1017 */
} /* line 1017 */
  sim_icache_fetch(434 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 1019 */
} /* line 1019 */
  sim_icache_fetch(436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 1021 */
} /* line 1021 */
  sim_icache_fetch(438 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1023 */
} /* line 1023 */
  sim_icache_fetch(440 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) -1); /* line 1025 */
} /* line 1025 */
  sim_icache_fetch(441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 1027 */
} /* line 1027 */
  sim_icache_fetch(442 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_1, reg_r0_8, 0); /* line 1029 */
} /* line 1029 */
  sim_icache_fetch(443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 1031 */
} /* line 1031 */
  sim_icache_fetch(445 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 1033 */
} /* line 1033 */
  sim_icache_fetch(447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 1035 */
} /* line 1035 */
  sim_icache_fetch(449 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_9, reg_r0_9); /* line 1037 */
} /* line 1037 */
  sim_icache_fetch(450 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 1039 */
} /* line 1039 */
  sim_icache_fetch(451 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_2, reg_r0_9, reg_r0_10); /* line 1041 */
} /* line 1041 */
  sim_icache_fetch(452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1043 */
} /* line 1043 */
  sim_icache_fetch(454 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 1045 */
} /* line 1045 */
  sim_icache_fetch(456 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 1047 */
} /* line 1047 */
  sim_icache_fetch(458 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 1049 */
} /* line 1049 */
  sim_icache_fetch(460 + t_thisfile.offset, 1);
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
} /* line 1051 */
  sim_icache_fetch(461 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_8); /* line 1053 */
} /* line 1053 */
  sim_icache_fetch(463 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1055 */
  sim_icache_fetch(464 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 1057 */
} /* line 1057 */
l_L33X3: ;/* line 1059 */
__LABEL(l_L33X3);
  sim_icache_fetch(466 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1060 */
l_L35X3: ;/* line 1062 */
__LABEL(l_L35X3);
		 /* line 1062 */
  sim_icache_fetch(467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (185 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1064 */
l_lr_65: ;/* line 1064 */
__LABEL(l_lr_65);
  sim_icache_fetch(469 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1066 */
} /* line 1066 */
  sim_icache_fetch(470 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1068 */
} /* line 1068 */
  sim_icache_fetch(471 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1071 */
l_L34X3: ;/* line 1074 */
__LABEL(l_L34X3);
  sim_icache_fetch(472 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1075 */
} /* line 1075 */
  sim_icache_fetch(474 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1077 */
} /* line 1077 */
  sim_icache_fetch(476 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(477 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1081 */
} /* line 1081 */
  sim_icache_fetch(478 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_4, (unsigned int) 1); /* line 1083 */
} /* line 1083 */
  sim_icache_fetch(479 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBUs(reg_r0_6, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1087 */
} /* line 1087 */
  sim_icache_fetch(483 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 1089 */
} /* line 1089 */
  sim_icache_fetch(484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 1091 */
} /* line 1091 */
  sim_icache_fetch(486 + t_thisfile.offset, 1);
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
} /* line 1093 */
  sim_icache_fetch(487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 1095 */
} /* line 1095 */
  sim_icache_fetch(489 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 1097 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1098 */
   __ADD_CYCLES(1);
} /* line 1098 */
  sim_icache_fetch(491 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 1100 */
} /* line 1100 */
l_L37X3: ;/* line 1102 */
__LABEL(l_L37X3);
  sim_icache_fetch(492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_6); /* line 1103 */
} /* line 1103 */
  sim_icache_fetch(493 + t_thisfile.offset, 1);
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
} /* line 1106 */
  sim_icache_fetch(494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L35X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L35X3;
} /* line 1108 */
l_L38X3: ;/* line 1111 */
__LABEL(l_L38X3);
  sim_icache_fetch(495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1112 */
} /* line 1112 */
  sim_icache_fetch(497 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1114 */
} /* line 1114 */
  sim_icache_fetch(499 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 1116 */
} /* line 1116 */
  sim_icache_fetch(500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1118 */
} /* line 1118 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_4, (unsigned int) 1); /* line 1120 */
} /* line 1120 */
  sim_icache_fetch(502 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) 1); /* line 1122 */
} /* line 1122 */
  sim_icache_fetch(503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) 100000); /* line 1124 */
} /* line 1124 */
  sim_icache_fetch(505 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 1126 */
} /* line 1126 */
  sim_icache_fetch(507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 1128 */
} /* line 1128 */
  sim_icache_fetch(509 + t_thisfile.offset, 1);
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
} /* line 1130 */
  sim_icache_fetch(510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 1132 */
} /* line 1132 */
  sim_icache_fetch(512 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 1134 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1135 */
   __ADD_CYCLES(1);
} /* line 1135 */
  sim_icache_fetch(514 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 1137 */
} /* line 1137 */
l_L40X3: ;/* line 1139 */
__LABEL(l_L40X3);
  sim_icache_fetch(515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 1140 */
} /* line 1140 */
  sim_icache_fetch(516 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_6, reg_r0_6, reg_r0_2); /* line 1142 */
} /* line 1142 */
  sim_icache_fetch(517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_4, reg_r0_4, (unsigned int) 128); /* line 1144 */
} /* line 1144 */
  sim_icache_fetch(518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 1146 */
} /* line 1146 */
  sim_icache_fetch(519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_6); /* line 1148 */
} /* line 1148 */
  sim_icache_fetch(521 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_4); /* line 1150 */
} /* line 1150 */
  sim_icache_fetch(523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 1152 */
} /* line 1152 */
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_8); /* line 1154 */
} /* line 1154 */
  sim_icache_fetch(527 + t_thisfile.offset, 1);
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
} /* line 1156 */
		 /* line 1157 */
  sim_icache_fetch(528 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (185 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1159 */
l_lr_71: ;/* line 1159 */
__LABEL(l_lr_71);
  sim_icache_fetch(530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1161 */
} /* line 1161 */
  sim_icache_fetch(531 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1163 */
} /* line 1163 */
  sim_icache_fetch(532 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1166 */
l_L31X3: ;/* line 1169 */
__LABEL(l_L31X3);
		 /* line 1169 */
  sim_icache_fetch(533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (185 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1171 */
l_lr_74: ;/* line 1171 */
__LABEL(l_lr_74);
  sim_icache_fetch(535 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1173 */
} /* line 1173 */
  sim_icache_fetch(536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1175 */
} /* line 1175 */
  sim_icache_fetch(537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 1177 */
} /* line 1177 */
  sim_icache_fetch(538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 1179 */
} /* line 1179 */
  sim_icache_fetch(540 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1182 */
l_L39X3: ;/* line 1185 */
__LABEL(l_L39X3);
  sim_icache_fetch(541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 1186 */
} /* line 1186 */
  sim_icache_fetch(542 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) 1); /* line 1188 */
} /* line 1188 */
  sim_icache_fetch(543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 1191 */
} /* line 1191 */
  sim_icache_fetch(545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L40X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L40X3;
} /* line 1193 */
l_L36X3: ;/* line 1196 */
__LABEL(l_L36X3);
  sim_icache_fetch(546 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 1197 */
} /* line 1197 */
  sim_icache_fetch(547 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1200 */
} /* line 1200 */
  sim_icache_fetch(549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 1202 */
l_L32X3: ;/* line 1205 */
__LABEL(l_L32X3);
  sim_icache_fetch(550 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 1206 */
} /* line 1206 */
  sim_icache_fetch(551 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_2, reg_r0_9, reg_r0_10); /* line 1208 */
} /* line 1208 */
  sim_icache_fetch(552 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1211 */
} /* line 1211 */
  sim_icache_fetch(554 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 1213 */
l_L29X3: ;/* line 1216 */
__LABEL(l_L29X3);
  sim_icache_fetch(555 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1217 */
} /* line 1217 */
  sim_icache_fetch(557 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 5003); /* line 1219 */
} /* line 1219 */
  sim_icache_fetch(559 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1221 */
} /* line 1221 */
  sim_icache_fetch(561 + t_thisfile.offset, 1);
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
} /* line 1223 */
  sim_icache_fetch(562 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_5); /* line 1226 */
} /* line 1226 */
  sim_icache_fetch(564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1228 */
l_L41X3: ;/* line 1231 */
__LABEL(l_L41X3);
  sim_icache_fetch(565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1232 */
} /* line 1232 */
  sim_icache_fetch(567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 5003); /* line 1234 */
} /* line 1234 */
  sim_icache_fetch(569 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1236 */
} /* line 1236 */
  sim_icache_fetch(571 + t_thisfile.offset, 1);
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
} /* line 1238 */
  sim_icache_fetch(572 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_5); /* line 1241 */
} /* line 1241 */
  sim_icache_fetch(574 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1243 */
l_L42X3: ;/* line 1246 */
__LABEL(l_L42X3);
  sim_icache_fetch(575 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1247 */
} /* line 1247 */
  sim_icache_fetch(577 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 5003); /* line 1249 */
} /* line 1249 */
  sim_icache_fetch(579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1251 */
} /* line 1251 */
  sim_icache_fetch(581 + t_thisfile.offset, 1);
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
} /* line 1253 */
  sim_icache_fetch(582 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_5); /* line 1256 */
} /* line 1256 */
  sim_icache_fetch(584 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1258 */
l_L43X3: ;/* line 1261 */
__LABEL(l_L43X3);
  sim_icache_fetch(585 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1262 */
} /* line 1262 */
  sim_icache_fetch(587 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 5003); /* line 1264 */
} /* line 1264 */
  sim_icache_fetch(589 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1266 */
} /* line 1266 */
  sim_icache_fetch(591 + t_thisfile.offset, 1);
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
} /* line 1268 */
  sim_icache_fetch(592 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_5); /* line 1271 */
} /* line 1271 */
  sim_icache_fetch(594 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1273 */
l_L27X3: ;/* line 1276 */
__LABEL(l_L27X3);
  sim_icache_fetch(595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1278 */
} /* line 1278 */
  sim_icache_fetch(596 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L28X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L28X3;
} /* line 1280 */
l_L25X3: ;/* line 1283 */
__LABEL(l_L25X3);
  sim_icache_fetch(597 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1284 */
} /* line 1284 */
  sim_icache_fetch(599 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 12); /* line 1286 */
} /* line 1286 */
  sim_icache_fetch(600 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1288 */
} /* line 1288 */
  sim_icache_fetch(601 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 5003); /* line 1291 */
} /* line 1291 */
  sim_icache_fetch(603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L26X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L26X3;
} /* line 1293 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 131: goto l_lr_30;
    case 132: goto l_L18X3;
    case 133: goto l_L21X3;
    case 134: goto l__X1XCompressXTAGX0X0;
    case 135: goto l__X1XCompressXTAGX0X7;
    case 136: goto l__X1XCompressXTAGX0X6;
    case 137: goto l__X1XCompressXTAGX0X5;
    case 138: goto l__X1XCompressXTAGX0X4;
    case 139: goto l__X1XCompressXTAGX0X3;
    case 140: goto l__X1XCompressXTAGX0X2;
    case 141: goto l_L20X3;
    case 142: goto l_L23X3;
    case 143: goto l_L24X3;
    case 145: goto l_lr_44;
    case 147: goto l_lr_46;
    case 148: goto l__X1XCompressXTAGX0X1;
    case 150: goto l_lr_49;
    case 151: goto l_L22X3;
    case 152: goto l__X1XCompressXTAGX0XDEFAULT;
    case 154: goto l_lr_53;
    case 156: goto l_lr_55;
    case 157: goto l_L19X3;
    case 158: goto l_L26X3;
    case 159: goto l_L28X3;
    case 160: goto l_L30X3;
    case 162: goto l_lr_61;
    case 163: goto l_L33X3;
    case 164: goto l_L35X3;
    case 166: goto l_lr_65;
    case 167: goto l_L34X3;
    case 168: goto l_L37X3;
    case 169: goto l_L38X3;
    case 170: goto l_L40X3;
    case 172: goto l_lr_71;
    case 173: goto l_L31X3;
    case 175: goto l_lr_74;
    case 176: goto l_L39X3;
    case 177: goto l_L36X3;
    case 178: goto l_L32X3;
    case 179: goto l_L29X3;
    case 180: goto l_L41X3;
    case 181: goto l_L42X3;
    case 182: goto l_L43X3;
    case 183: goto l_L27X3;
    case 184: goto l_L25X3;
    case 185:
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
  reg_l0_0 = (270 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1431 */
} /* line 1431 */
  sim_icache_fetch(605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1433 */
} /* line 1433 */
  sim_icache_fetch(606 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1435 */
} /* line 1435 */
  sim_icache_fetch(608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1437 */
} /* line 1437 */
  sim_icache_fetch(609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1439 */
} /* line 1439 */
  sim_icache_fetch(610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1441 */
l_L45X3: ;/* line 1443 */
__LABEL(l_L45X3);
  sim_icache_fetch(611 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 1); /* line 1444 */
} /* line 1444 */
  sim_icache_fetch(612 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, (unsigned int) 10000); /* line 1446 */
} /* line 1446 */
  sim_icache_fetch(614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) 9); /* line 1448 */
} /* line 1448 */
  sim_icache_fetch(615 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, (unsigned int) 511); /* line 1450 */
} /* line 1450 */
  sim_icache_fetch(617 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1452 */
} /* line 1452 */
  sim_icache_fetch(619 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_11, (unsigned int) 257); /* line 1454 */
} /* line 1454 */
  sim_icache_fetch(621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_10, 0); /* line 1456 */
} /* line 1456 */
  sim_icache_fetch(622 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, (unsigned int) 256); /* line 1458 */
} /* line 1458 */
  sim_icache_fetch(624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1460 */
} /* line 1460 */
  sim_icache_fetch(626 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_12, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1462 */
} /* line 1462 */
  sim_icache_fetch(628 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) -1); /* line 1464 */
} /* line 1464 */
  sim_icache_fetch(629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_10, 0); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(630 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 1468 */
} /* line 1468 */
  sim_icache_fetch(631 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1470 */
} /* line 1470 */
  sim_icache_fetch(633 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, 0); /* line 1472 */
} /* line 1472 */
  sim_icache_fetch(634 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1474 */
} /* line 1474 */
  sim_icache_fetch(636 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_5); /* line 1476 */
} /* line 1476 */
  sim_icache_fetch(638 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, reg_l0_0); /* line 1478 */
} /* line 1478 */
  sim_icache_fetch(639 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_8419Xoffset,0,4), 0); /* line 1480 */
} /* line 1480 */
  sim_icache_fetch(641 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1482 */
} /* line 1482 */
  sim_icache_fetch(643 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1484 */
} /* line 1484 */
  sim_icache_fetch(645 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1486 */
} /* line 1486 */
  sim_icache_fetch(647 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1488 */
} /* line 1488 */
  sim_icache_fetch(649 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_7); /* line 1490 */
} /* line 1490 */
  sim_icache_fetch(651 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_8); /* line 1492 */
} /* line 1492 */
  sim_icache_fetch(653 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_9); /* line 1494 */
} /* line 1494 */
  sim_icache_fetch(655 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1496 */
} /* line 1496 */
  sim_icache_fetch(657 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_10); /* line 1498 */
} /* line 1498 */
  sim_icache_fetch(659 + t_thisfile.offset, 1);
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
} /* line 1500 */
  sim_icache_fetch(660 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_13); /* line 1502 */
} /* line 1502 */
  sim_icache_fetch(662 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 1504 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1505 */
   __ADD_CYCLES(1);
} /* line 1505 */
  sim_icache_fetch(664 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_12, reg_r0_12); /* line 1507 */
} /* line 1507 */
l_L47X3: ;/* line 1509 */
__LABEL(l_L47X3);
  sim_icache_fetch(665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_12); /* line 1510 */
} /* line 1510 */
l_L48X3: ;/* line 1513 */
__LABEL(l_L48X3);
  sim_icache_fetch(666 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1514 */
} /* line 1514 */
  sim_icache_fetch(667 + t_thisfile.offset, 1);
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
} /* line 1516 */
  sim_icache_fetch(668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1518 */
} /* line 1518 */
  sim_icache_fetch(669 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1520 */
} /* line 1520 */
  sim_icache_fetch(670 + t_thisfile.offset, 1);
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
} /* line 1522 */
  sim_icache_fetch(671 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1524 */
} /* line 1524 */
  sim_icache_fetch(672 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1526 */
} /* line 1526 */
  sim_icache_fetch(673 + t_thisfile.offset, 1);
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
} /* line 1528 */
  sim_icache_fetch(674 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1530 */
} /* line 1530 */
  sim_icache_fetch(675 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1532 */
} /* line 1532 */
  sim_icache_fetch(676 + t_thisfile.offset, 1);
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
} /* line 1534 */
  sim_icache_fetch(677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1536 */
} /* line 1536 */
  sim_icache_fetch(678 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1538 */
} /* line 1538 */
  sim_icache_fetch(679 + t_thisfile.offset, 1);
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
} /* line 1540 */
  sim_icache_fetch(680 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1542 */
} /* line 1542 */
  sim_icache_fetch(681 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1544 */
} /* line 1544 */
  sim_icache_fetch(682 + t_thisfile.offset, 1);
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
} /* line 1546 */
  sim_icache_fetch(683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1548 */
} /* line 1548 */
  sim_icache_fetch(684 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1550 */
} /* line 1550 */
  sim_icache_fetch(685 + t_thisfile.offset, 1);
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
} /* line 1552 */
  sim_icache_fetch(686 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1554 */
} /* line 1554 */
  sim_icache_fetch(687 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1556 */
} /* line 1556 */
  sim_icache_fetch(688 + t_thisfile.offset, 1);
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
} /* line 1558 */
  sim_icache_fetch(689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1560 */
} /* line 1560 */
  sim_icache_fetch(690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1562 */
} /* line 1562 */
  sim_icache_fetch(691 + t_thisfile.offset, 1);
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
} /* line 1564 */
  sim_icache_fetch(692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1566 */
} /* line 1566 */
  sim_icache_fetch(693 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1568 */
} /* line 1568 */
  sim_icache_fetch(694 + t_thisfile.offset, 1);
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
} /* line 1570 */
  sim_icache_fetch(695 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1572 */
} /* line 1572 */
  sim_icache_fetch(696 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1574 */
} /* line 1574 */
  sim_icache_fetch(697 + t_thisfile.offset, 1);
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
} /* line 1576 */
  sim_icache_fetch(698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1578 */
} /* line 1578 */
  sim_icache_fetch(699 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1580 */
} /* line 1580 */
  sim_icache_fetch(700 + t_thisfile.offset, 1);
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
} /* line 1582 */
  sim_icache_fetch(701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1584 */
} /* line 1584 */
  sim_icache_fetch(702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1586 */
} /* line 1586 */
  sim_icache_fetch(703 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1588 */
  sim_icache_fetch(704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1590 */
} /* line 1590 */
  sim_icache_fetch(705 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1592 */
} /* line 1592 */
  sim_icache_fetch(706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1594 */
  sim_icache_fetch(707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1596 */
} /* line 1596 */
  sim_icache_fetch(708 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1598 */
} /* line 1598 */
  sim_icache_fetch(709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1600 */
  sim_icache_fetch(710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1602 */
} /* line 1602 */
  sim_icache_fetch(711 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1604 */
} /* line 1604 */
  sim_icache_fetch(712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1606 */
  sim_icache_fetch(713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1608 */
} /* line 1608 */
  sim_icache_fetch(714 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1610 */
} /* line 1610 */
  sim_icache_fetch(715 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1612 */
} /* line 1612 */
  sim_icache_fetch(716 + t_thisfile.offset, 1);
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
} /* line 1614 */
  sim_icache_fetch(717 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1616 */
} /* line 1616 */
  sim_icache_fetch(718 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1618 */
} /* line 1618 */
  sim_icache_fetch(719 + t_thisfile.offset, 1);
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
} /* line 1620 */
  sim_icache_fetch(720 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1622 */
} /* line 1622 */
  sim_icache_fetch(721 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1624 */
} /* line 1624 */
  sim_icache_fetch(722 + t_thisfile.offset, 1);
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
} /* line 1626 */
  sim_icache_fetch(723 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1628 */
} /* line 1628 */
  sim_icache_fetch(724 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1630 */
} /* line 1630 */
  sim_icache_fetch(725 + t_thisfile.offset, 1);
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
} /* line 1632 */
  sim_icache_fetch(726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1634 */
} /* line 1634 */
  sim_icache_fetch(727 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1636 */
} /* line 1636 */
  sim_icache_fetch(728 + t_thisfile.offset, 1);
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
} /* line 1638 */
  sim_icache_fetch(729 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1640 */
} /* line 1640 */
  sim_icache_fetch(730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1642 */
} /* line 1642 */
  sim_icache_fetch(731 + t_thisfile.offset, 1);
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
} /* line 1644 */
  sim_icache_fetch(732 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1646 */
} /* line 1646 */
  sim_icache_fetch(733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1648 */
} /* line 1648 */
  sim_icache_fetch(734 + t_thisfile.offset, 1);
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
} /* line 1650 */
  sim_icache_fetch(735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1652 */
} /* line 1652 */
  sim_icache_fetch(736 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1654 */
} /* line 1654 */
  sim_icache_fetch(737 + t_thisfile.offset, 1);
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
} /* line 1656 */
  sim_icache_fetch(738 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1658 */
} /* line 1658 */
  sim_icache_fetch(739 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1660 */
} /* line 1660 */
  sim_icache_fetch(740 + t_thisfile.offset, 1);
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
} /* line 1662 */
  sim_icache_fetch(741 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1664 */
} /* line 1664 */
  sim_icache_fetch(742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1666 */
} /* line 1666 */
  sim_icache_fetch(743 + t_thisfile.offset, 1);
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
} /* line 1668 */
  sim_icache_fetch(744 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1670 */
} /* line 1670 */
  sim_icache_fetch(745 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1672 */
} /* line 1672 */
  sim_icache_fetch(746 + t_thisfile.offset, 1);
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
} /* line 1674 */
  sim_icache_fetch(747 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1676 */
} /* line 1676 */
  sim_icache_fetch(748 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1678 */
} /* line 1678 */
  sim_icache_fetch(749 + t_thisfile.offset, 1);
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
} /* line 1680 */
  sim_icache_fetch(750 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1682 */
} /* line 1682 */
  sim_icache_fetch(751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1684 */
} /* line 1684 */
  sim_icache_fetch(752 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1686 */
  sim_icache_fetch(753 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1688 */
} /* line 1688 */
  sim_icache_fetch(754 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1690 */
} /* line 1690 */
  sim_icache_fetch(755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1692 */
  sim_icache_fetch(756 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1694 */
} /* line 1694 */
  sim_icache_fetch(757 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1696 */
} /* line 1696 */
  sim_icache_fetch(758 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1698 */
  sim_icache_fetch(759 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1700 */
} /* line 1700 */
  sim_icache_fetch(760 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1702 */
} /* line 1702 */
  sim_icache_fetch(761 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1704 */
  sim_icache_fetch(762 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1706 */
} /* line 1706 */
  sim_icache_fetch(763 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1709 */
} /* line 1709 */
  sim_icache_fetch(764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1711 */
l_L64X3: ;/* line 1714 */
__LABEL(l_L64X3);
  sim_icache_fetch(765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1715 */
} /* line 1715 */
  sim_icache_fetch(766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1717 */
} /* line 1717 */
  sim_icache_fetch(767 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1719 */
} /* line 1719 */
  sim_icache_fetch(768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1721 */
} /* line 1721 */
  sim_icache_fetch(770 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1724 */
} /* line 1724 */
  sim_icache_fetch(771 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 1726 */
l_L66X3: ;/* line 1729 */
__LABEL(l_L66X3);
  sim_icache_fetch(772 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1730 */
} /* line 1730 */
  sim_icache_fetch(774 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1732 */
} /* line 1732 */
  sim_icache_fetch(776 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1734 */
} /* line 1734 */
  sim_icache_fetch(777 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1736 */
} /* line 1736 */
  sim_icache_fetch(778 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_8, (unsigned int) 1); /* line 1738 */
} /* line 1738 */
  sim_icache_fetch(779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1740 */
} /* line 1740 */
  sim_icache_fetch(781 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1742 */
} /* line 1742 */
  sim_icache_fetch(783 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 1); /* line 1744 */
} /* line 1744 */
  sim_icache_fetch(784 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1746 */
} /* line 1746 */
  sim_icache_fetch(786 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1748 */
  sim_icache_fetch(787 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_9); /* line 1750 */
} /* line 1750 */
  sim_icache_fetch(789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 1752 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1753 */
   __ADD_CYCLES(1);
} /* line 1753 */
  sim_icache_fetch(791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 1755 */
} /* line 1755 */
l_L68X3: ;/* line 1757 */
__LABEL(l_L68X3);
  sim_icache_fetch(792 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_8, (unsigned int) -1); /* line 1758 */
} /* line 1758 */
  sim_icache_fetch(793 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1760 */
  sim_icache_fetch(794 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_8, reg_r0_6); /* line 1762 */
} /* line 1762 */
  sim_icache_fetch(795 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __XOR(reg_r0_2, reg_r0_7, reg_r0_3); /* line 1764 */
} /* line 1764 */
  sim_icache_fetch(796 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1766 */
} /* line 1766 */
  sim_icache_fetch(798 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1768 */
} /* line 1768 */
  sim_icache_fetch(799 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_11, reg_r0_8, reg_r0_11); /* line 1770 */
} /* line 1770 */
  sim_icache_fetch(800 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_11, reg_r0_7); /* line 1772 */
} /* line 1772 */
  sim_icache_fetch(801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1774 */
} /* line 1774 */
  sim_icache_fetch(802 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 1776 */
} /* line 1776 */
  sim_icache_fetch(804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_10); /* line 1778 */
} /* line 1778 */
  sim_icache_fetch(806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1780 */
  sim_icache_fetch(807 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_3,0,2)); /* line 1782 */
} /* line 1782 */
  sim_icache_fetch(808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1784 */
l_L70X3: ;/* line 1787 */
__LABEL(l_L70X3);
  sim_icache_fetch(809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1788 */
} /* line 1788 */
  sim_icache_fetch(810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 1790 */
} /* line 1790 */
  sim_icache_fetch(811 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_8); /* line 1792 */
} /* line 1792 */
  sim_icache_fetch(812 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1794 */
} /* line 1794 */
  sim_icache_fetch(813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_2, reg_r0_2, (unsigned int) htab); /* line 1796 */
} /* line 1796 */
  sim_icache_fetch(815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld(reg_r0_2,0,4)); /* line 1798 */
} /* line 1798 */
  sim_icache_fetch(816 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_7); /* line 1800 */
} /* line 1800 */
  sim_icache_fetch(817 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1802 */
} /* line 1802 */
  sim_icache_fetch(818 + t_thisfile.offset, 1);
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
} /* line 1804 */
l_L72X3: ;/* line 1806 */
__LABEL(l_L72X3);
		 /* line 1806 */
  sim_icache_fetch(819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (270 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1808 */
l_lr_94: ;/* line 1808 */
__LABEL(l_lr_94);
  sim_icache_fetch(821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1810 */
} /* line 1810 */
  sim_icache_fetch(823 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1812 */
} /* line 1812 */
  sim_icache_fetch(824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1814 */
} /* line 1814 */
  sim_icache_fetch(825 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 1816 */
} /* line 1816 */
  sim_icache_fetch(826 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_9, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1818 */
} /* line 1818 */
  sim_icache_fetch(828 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1820 */
} /* line 1820 */
  sim_icache_fetch(830 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_9, (unsigned int) 1); /* line 1822 */
} /* line 1822 */
  sim_icache_fetch(831 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1824 */
} /* line 1824 */
  sim_icache_fetch(832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1826 */
} /* line 1826 */
  sim_icache_fetch(833 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1828 */
} /* line 1828 */
  sim_icache_fetch(834 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1830 */
} /* line 1830 */
  sim_icache_fetch(836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_2, reg_r0_2, (unsigned int) htab); /* line 1832 */
} /* line 1832 */
  sim_icache_fetch(838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1834 */
} /* line 1834 */
  sim_icache_fetch(839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1836 */
} /* line 1836 */
  sim_icache_fetch(841 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1838 */
  sim_icache_fetch(842 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1840 */
} /* line 1840 */
  sim_icache_fetch(844 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st(reg_r0_10,0,2), reg_r0_9); /* line 1842 */
} /* line 1842 */
  sim_icache_fetch(845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_5); /* line 1845 */
} /* line 1845 */
  sim_icache_fetch(846 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1847 */
l_L73X3: ;/* line 1850 */
__LABEL(l_L73X3);
  sim_icache_fetch(847 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 1851 */
} /* line 1851 */
  sim_icache_fetch(848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_7); /* line 1853 */
} /* line 1853 */
  sim_icache_fetch(849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1855 */
} /* line 1855 */
  sim_icache_fetch(851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1857 */
} /* line 1857 */
  sim_icache_fetch(853 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1859 */
} /* line 1859 */
  sim_icache_fetch(855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1861 */
} /* line 1861 */
  sim_icache_fetch(856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1863 */
} /* line 1863 */
  sim_icache_fetch(857 + t_thisfile.offset, 1);
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
} /* line 1865 */
		 /* line 1866 */
  sim_icache_fetch(858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (270 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1868 */
l_lr_97: ;/* line 1868 */
__LABEL(l_lr_97);
  sim_icache_fetch(860 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1870 */
} /* line 1870 */
  sim_icache_fetch(861 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1872 */
} /* line 1872 */
  sim_icache_fetch(862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1874 */
l_L74X3: ;/* line 1877 */
__LABEL(l_L74X3);
  sim_icache_fetch(863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1878 */
} /* line 1878 */
  sim_icache_fetch(864 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1880 */
} /* line 1880 */
  sim_icache_fetch(865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1882 */
l_L71X3: ;/* line 1885 */
__LABEL(l_L71X3);
  sim_icache_fetch(866 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1886 */
} /* line 1886 */
  sim_icache_fetch(867 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, reg_r0_57); /* line 1888 */
} /* line 1888 */
  sim_icache_fetch(868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1890 */
} /* line 1890 */
  sim_icache_fetch(869 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1892 */
} /* line 1892 */
  sim_icache_fetch(870 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1894 */
} /* line 1894 */
  sim_icache_fetch(871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1896 */
} /* line 1896 */
  sim_icache_fetch(872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 1898 */
} /* line 1898 */
l_L75X3: ;/* line 1901 */
__LABEL(l_L75X3);
  sim_icache_fetch(873 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1902 */
} /* line 1902 */
  sim_icache_fetch(874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1904 */
} /* line 1904 */
  sim_icache_fetch(875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1906 */
} /* line 1906 */
  sim_icache_fetch(876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1908 */
} /* line 1908 */
  sim_icache_fetch(877 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1910 */
} /* line 1910 */
  sim_icache_fetch(879 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1912 */
} /* line 1912 */
  sim_icache_fetch(880 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1914 */
} /* line 1914 */
  sim_icache_fetch(881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1916 */
} /* line 1916 */
  sim_icache_fetch(882 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1918 */
  sim_icache_fetch(883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 1920 */
} /* line 1920 */
  sim_icache_fetch(884 + t_thisfile.offset, 1);
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
} /* line 1922 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1924 */
} /* line 1924 */
  sim_icache_fetch(886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 1926 */
} /* line 1926 */
  sim_icache_fetch(887 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 1928 */
} /* line 1928 */
  sim_icache_fetch(888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1930 */
} /* line 1930 */
  sim_icache_fetch(890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1932 */
} /* line 1932 */
  sim_icache_fetch(891 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1934 */
} /* line 1934 */
  sim_icache_fetch(892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1936 */
} /* line 1936 */
  sim_icache_fetch(893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1938 */
  sim_icache_fetch(894 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 1940 */
} /* line 1940 */
  sim_icache_fetch(895 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1942 */
  sim_icache_fetch(896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1944 */
} /* line 1944 */
  sim_icache_fetch(897 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 1946 */
} /* line 1946 */
  sim_icache_fetch(898 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 1948 */
} /* line 1948 */
  sim_icache_fetch(899 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1950 */
} /* line 1950 */
  sim_icache_fetch(901 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1952 */
} /* line 1952 */
  sim_icache_fetch(902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1954 */
} /* line 1954 */
  sim_icache_fetch(903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1956 */
} /* line 1956 */
  sim_icache_fetch(904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1958 */
  sim_icache_fetch(905 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 1960 */
} /* line 1960 */
  sim_icache_fetch(906 + t_thisfile.offset, 1);
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
} /* line 1962 */
  sim_icache_fetch(907 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1964 */
} /* line 1964 */
  sim_icache_fetch(908 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 1966 */
} /* line 1966 */
  sim_icache_fetch(909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 1968 */
} /* line 1968 */
  sim_icache_fetch(910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1970 */
} /* line 1970 */
  sim_icache_fetch(912 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1972 */
} /* line 1972 */
  sim_icache_fetch(913 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1974 */
} /* line 1974 */
  sim_icache_fetch(914 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1976 */
} /* line 1976 */
  sim_icache_fetch(915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1978 */
  sim_icache_fetch(916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 1980 */
} /* line 1980 */
  sim_icache_fetch(917 + t_thisfile.offset, 1);
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
} /* line 1982 */
  sim_icache_fetch(918 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1984 */
} /* line 1984 */
  sim_icache_fetch(919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 1986 */
} /* line 1986 */
  sim_icache_fetch(920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 1988 */
} /* line 1988 */
  sim_icache_fetch(921 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1990 */
} /* line 1990 */
  sim_icache_fetch(923 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1992 */
} /* line 1992 */
  sim_icache_fetch(924 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1994 */
} /* line 1994 */
  sim_icache_fetch(925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1996 */
} /* line 1996 */
  sim_icache_fetch(926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1998 */
  sim_icache_fetch(927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2000 */
} /* line 2000 */
  sim_icache_fetch(928 + t_thisfile.offset, 1);
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
} /* line 2002 */
  sim_icache_fetch(929 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2004 */
} /* line 2004 */
  sim_icache_fetch(930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2006 */
} /* line 2006 */
  sim_icache_fetch(931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2008 */
} /* line 2008 */
  sim_icache_fetch(932 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2010 */
} /* line 2010 */
  sim_icache_fetch(934 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2012 */
} /* line 2012 */
  sim_icache_fetch(935 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2014 */
} /* line 2014 */
  sim_icache_fetch(936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2016 */
} /* line 2016 */
  sim_icache_fetch(937 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2018 */
  sim_icache_fetch(938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2020 */
} /* line 2020 */
  sim_icache_fetch(939 + t_thisfile.offset, 1);
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
} /* line 2022 */
  sim_icache_fetch(940 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2024 */
} /* line 2024 */
  sim_icache_fetch(941 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2026 */
} /* line 2026 */
  sim_icache_fetch(942 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2028 */
} /* line 2028 */
  sim_icache_fetch(943 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2030 */
} /* line 2030 */
  sim_icache_fetch(945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2032 */
} /* line 2032 */
  sim_icache_fetch(946 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2034 */
} /* line 2034 */
  sim_icache_fetch(947 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2036 */
} /* line 2036 */
  sim_icache_fetch(948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2038 */
  sim_icache_fetch(949 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2040 */
} /* line 2040 */
  sim_icache_fetch(950 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2042 */
  sim_icache_fetch(951 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2044 */
} /* line 2044 */
  sim_icache_fetch(952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2046 */
} /* line 2046 */
  sim_icache_fetch(953 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2048 */
} /* line 2048 */
  sim_icache_fetch(954 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2050 */
} /* line 2050 */
  sim_icache_fetch(956 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2052 */
} /* line 2052 */
  sim_icache_fetch(957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2054 */
} /* line 2054 */
  sim_icache_fetch(958 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2056 */
} /* line 2056 */
  sim_icache_fetch(959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2058 */
  sim_icache_fetch(960 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2060 */
} /* line 2060 */
  sim_icache_fetch(961 + t_thisfile.offset, 1);
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
} /* line 2062 */
  sim_icache_fetch(962 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2064 */
} /* line 2064 */
  sim_icache_fetch(963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2066 */
} /* line 2066 */
  sim_icache_fetch(964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2068 */
} /* line 2068 */
  sim_icache_fetch(965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2070 */
} /* line 2070 */
  sim_icache_fetch(967 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2072 */
} /* line 2072 */
  sim_icache_fetch(968 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2074 */
} /* line 2074 */
  sim_icache_fetch(969 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2076 */
} /* line 2076 */
  sim_icache_fetch(970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2078 */
  sim_icache_fetch(971 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2080 */
} /* line 2080 */
  sim_icache_fetch(972 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2082 */
  sim_icache_fetch(973 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2084 */
} /* line 2084 */
  sim_icache_fetch(974 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2086 */
} /* line 2086 */
  sim_icache_fetch(975 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2088 */
} /* line 2088 */
  sim_icache_fetch(976 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2090 */
} /* line 2090 */
  sim_icache_fetch(978 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2092 */
} /* line 2092 */
  sim_icache_fetch(979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2094 */
} /* line 2094 */
  sim_icache_fetch(980 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2096 */
} /* line 2096 */
  sim_icache_fetch(981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2098 */
  sim_icache_fetch(982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2100 */
} /* line 2100 */
  sim_icache_fetch(983 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2102 */
  sim_icache_fetch(984 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2104 */
} /* line 2104 */
  sim_icache_fetch(985 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2106 */
} /* line 2106 */
  sim_icache_fetch(986 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2108 */
} /* line 2108 */
  sim_icache_fetch(987 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2110 */
} /* line 2110 */
  sim_icache_fetch(989 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2112 */
} /* line 2112 */
  sim_icache_fetch(990 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2114 */
} /* line 2114 */
  sim_icache_fetch(991 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2116 */
} /* line 2116 */
  sim_icache_fetch(992 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2118 */
  sim_icache_fetch(993 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2120 */
} /* line 2120 */
  sim_icache_fetch(994 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2122 */
  sim_icache_fetch(995 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2124 */
} /* line 2124 */
  sim_icache_fetch(996 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2126 */
} /* line 2126 */
  sim_icache_fetch(997 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2128 */
} /* line 2128 */
  sim_icache_fetch(998 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2130 */
} /* line 2130 */
  sim_icache_fetch(1000 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2132 */
} /* line 2132 */
  sim_icache_fetch(1001 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2134 */
} /* line 2134 */
  sim_icache_fetch(1002 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2136 */
} /* line 2136 */
  sim_icache_fetch(1003 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2138 */
  sim_icache_fetch(1004 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2140 */
} /* line 2140 */
  sim_icache_fetch(1005 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2142 */
  sim_icache_fetch(1006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2144 */
} /* line 2144 */
  sim_icache_fetch(1007 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2146 */
} /* line 2146 */
  sim_icache_fetch(1008 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2148 */
} /* line 2148 */
  sim_icache_fetch(1009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2150 */
} /* line 2150 */
  sim_icache_fetch(1011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2152 */
} /* line 2152 */
  sim_icache_fetch(1012 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2154 */
} /* line 2154 */
  sim_icache_fetch(1013 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2156 */
} /* line 2156 */
  sim_icache_fetch(1014 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2158 */
  sim_icache_fetch(1015 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2160 */
} /* line 2160 */
  sim_icache_fetch(1016 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2162 */
  sim_icache_fetch(1017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2164 */
} /* line 2164 */
  sim_icache_fetch(1018 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2166 */
} /* line 2166 */
  sim_icache_fetch(1019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2168 */
} /* line 2168 */
  sim_icache_fetch(1020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2170 */
} /* line 2170 */
  sim_icache_fetch(1022 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2172 */
} /* line 2172 */
  sim_icache_fetch(1023 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2174 */
} /* line 2174 */
  sim_icache_fetch(1024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2176 */
} /* line 2176 */
  sim_icache_fetch(1025 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2178 */
  sim_icache_fetch(1026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2180 */
} /* line 2180 */
  sim_icache_fetch(1027 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2182 */
  sim_icache_fetch(1028 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2184 */
} /* line 2184 */
  sim_icache_fetch(1029 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2186 */
} /* line 2186 */
  sim_icache_fetch(1030 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2188 */
} /* line 2188 */
  sim_icache_fetch(1031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2190 */
} /* line 2190 */
  sim_icache_fetch(1033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2192 */
} /* line 2192 */
  sim_icache_fetch(1034 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2194 */
} /* line 2194 */
  sim_icache_fetch(1035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2196 */
} /* line 2196 */
  sim_icache_fetch(1036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2198 */
  sim_icache_fetch(1037 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2200 */
} /* line 2200 */
  sim_icache_fetch(1038 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2202 */
  sim_icache_fetch(1039 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2204 */
} /* line 2204 */
  sim_icache_fetch(1040 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2206 */
} /* line 2206 */
  sim_icache_fetch(1041 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2208 */
} /* line 2208 */
  sim_icache_fetch(1042 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 2210 */
} /* line 2210 */
  sim_icache_fetch(1044 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2212 */
} /* line 2212 */
  sim_icache_fetch(1045 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 2214 */
} /* line 2214 */
  sim_icache_fetch(1046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2216 */
} /* line 2216 */
  sim_icache_fetch(1047 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2218 */
  sim_icache_fetch(1048 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2220 */
} /* line 2220 */
  sim_icache_fetch(1049 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2222 */
  sim_icache_fetch(1050 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2224 */
} /* line 2224 */
  sim_icache_fetch(1051 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_7, reg_r0_4); /* line 2226 */
} /* line 2226 */
  sim_icache_fetch(1052 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2228 */
} /* line 2228 */
  sim_icache_fetch(1053 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2230 */
} /* line 2230 */
  sim_icache_fetch(1055 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2232 */
} /* line 2232 */
  sim_icache_fetch(1056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2234 */
} /* line 2234 */
  sim_icache_fetch(1057 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2236 */
} /* line 2236 */
  sim_icache_fetch(1058 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2238 */
  sim_icache_fetch(1059 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2240 */
} /* line 2240 */
  sim_icache_fetch(1060 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2242 */
  sim_icache_fetch(1061 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2244 */
} /* line 2244 */
  sim_icache_fetch(1062 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2246 */
} /* line 2246 */
  sim_icache_fetch(1063 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2248 */
} /* line 2248 */
  sim_icache_fetch(1064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2250 */
} /* line 2250 */
  sim_icache_fetch(1066 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2252 */
} /* line 2252 */
  sim_icache_fetch(1067 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2254 */
} /* line 2254 */
  sim_icache_fetch(1068 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2256 */
} /* line 2256 */
  sim_icache_fetch(1069 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2258 */
  sim_icache_fetch(1070 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2260 */
} /* line 2260 */
  sim_icache_fetch(1071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2262 */
  sim_icache_fetch(1072 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2264 */
} /* line 2264 */
  sim_icache_fetch(1073 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2266 */
} /* line 2266 */
  sim_icache_fetch(1074 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2268 */
} /* line 2268 */
  sim_icache_fetch(1075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2270 */
} /* line 2270 */
  sim_icache_fetch(1077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2272 */
} /* line 2272 */
  sim_icache_fetch(1078 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2274 */
} /* line 2274 */
  sim_icache_fetch(1079 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2276 */
} /* line 2276 */
  sim_icache_fetch(1080 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2278 */
  sim_icache_fetch(1081 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2280 */
} /* line 2280 */
  sim_icache_fetch(1082 + t_thisfile.offset, 1);
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
} /* line 2282 */
  sim_icache_fetch(1083 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2284 */
} /* line 2284 */
  sim_icache_fetch(1084 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2286 */
} /* line 2286 */
  sim_icache_fetch(1085 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2288 */
} /* line 2288 */
  sim_icache_fetch(1086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2290 */
} /* line 2290 */
  sim_icache_fetch(1088 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2292 */
} /* line 2292 */
  sim_icache_fetch(1089 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2294 */
} /* line 2294 */
  sim_icache_fetch(1090 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2296 */
} /* line 2296 */
  sim_icache_fetch(1091 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2298 */
  sim_icache_fetch(1092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2300 */
} /* line 2300 */
  sim_icache_fetch(1093 + t_thisfile.offset, 1);
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
} /* line 2302 */
  sim_icache_fetch(1094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2304 */
} /* line 2304 */
  sim_icache_fetch(1095 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2306 */
} /* line 2306 */
  sim_icache_fetch(1096 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2308 */
} /* line 2308 */
  sim_icache_fetch(1097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2310 */
} /* line 2310 */
  sim_icache_fetch(1099 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2312 */
} /* line 2312 */
  sim_icache_fetch(1100 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2314 */
} /* line 2314 */
  sim_icache_fetch(1101 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2316 */
} /* line 2316 */
  sim_icache_fetch(1102 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2318 */
  sim_icache_fetch(1103 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2320 */
} /* line 2320 */
  sim_icache_fetch(1104 + t_thisfile.offset, 1);
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
} /* line 2322 */
  sim_icache_fetch(1105 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2324 */
} /* line 2324 */
  sim_icache_fetch(1106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2326 */
} /* line 2326 */
  sim_icache_fetch(1107 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2328 */
} /* line 2328 */
  sim_icache_fetch(1108 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2330 */
} /* line 2330 */
  sim_icache_fetch(1110 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2332 */
} /* line 2332 */
  sim_icache_fetch(1111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2334 */
} /* line 2334 */
  sim_icache_fetch(1112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2336 */
} /* line 2336 */
  sim_icache_fetch(1113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2338 */
  sim_icache_fetch(1114 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2340 */
} /* line 2340 */
  sim_icache_fetch(1115 + t_thisfile.offset, 1);
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
} /* line 2342 */
  sim_icache_fetch(1116 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2344 */
} /* line 2344 */
  sim_icache_fetch(1117 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2346 */
} /* line 2346 */
  sim_icache_fetch(1118 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2348 */
} /* line 2348 */
  sim_icache_fetch(1119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2350 */
} /* line 2350 */
  sim_icache_fetch(1121 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2352 */
} /* line 2352 */
  sim_icache_fetch(1122 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2354 */
} /* line 2354 */
  sim_icache_fetch(1123 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2356 */
} /* line 2356 */
  sim_icache_fetch(1124 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2358 */
  sim_icache_fetch(1125 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2360 */
} /* line 2360 */
  sim_icache_fetch(1126 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2362 */
  sim_icache_fetch(1127 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2364 */
} /* line 2364 */
  sim_icache_fetch(1128 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2366 */
} /* line 2366 */
  sim_icache_fetch(1129 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2368 */
} /* line 2368 */
  sim_icache_fetch(1130 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2370 */
} /* line 2370 */
  sim_icache_fetch(1132 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2372 */
} /* line 2372 */
  sim_icache_fetch(1133 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2374 */
} /* line 2374 */
  sim_icache_fetch(1134 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2376 */
} /* line 2376 */
  sim_icache_fetch(1135 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2378 */
  sim_icache_fetch(1136 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2380 */
} /* line 2380 */
  sim_icache_fetch(1137 + t_thisfile.offset, 1);
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
} /* line 2382 */
  sim_icache_fetch(1138 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2384 */
} /* line 2384 */
  sim_icache_fetch(1139 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2386 */
} /* line 2386 */
  sim_icache_fetch(1140 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2388 */
} /* line 2388 */
  sim_icache_fetch(1141 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2390 */
} /* line 2390 */
  sim_icache_fetch(1143 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2392 */
} /* line 2392 */
  sim_icache_fetch(1144 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2394 */
} /* line 2394 */
  sim_icache_fetch(1145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2396 */
} /* line 2396 */
  sim_icache_fetch(1146 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2398 */
  sim_icache_fetch(1147 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2400 */
} /* line 2400 */
  sim_icache_fetch(1148 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2402 */
  sim_icache_fetch(1149 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2404 */
} /* line 2404 */
  sim_icache_fetch(1150 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2406 */
} /* line 2406 */
  sim_icache_fetch(1151 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2408 */
} /* line 2408 */
  sim_icache_fetch(1152 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2410 */
} /* line 2410 */
  sim_icache_fetch(1154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2412 */
} /* line 2412 */
  sim_icache_fetch(1155 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2414 */
} /* line 2414 */
  sim_icache_fetch(1156 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2416 */
} /* line 2416 */
  sim_icache_fetch(1157 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2418 */
  sim_icache_fetch(1158 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2420 */
} /* line 2420 */
  sim_icache_fetch(1159 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2422 */
  sim_icache_fetch(1160 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2424 */
} /* line 2424 */
  sim_icache_fetch(1161 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2426 */
} /* line 2426 */
  sim_icache_fetch(1162 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2428 */
} /* line 2428 */
  sim_icache_fetch(1163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2430 */
} /* line 2430 */
  sim_icache_fetch(1165 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2432 */
} /* line 2432 */
  sim_icache_fetch(1166 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2434 */
} /* line 2434 */
  sim_icache_fetch(1167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2436 */
} /* line 2436 */
  sim_icache_fetch(1168 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2438 */
  sim_icache_fetch(1169 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2440 */
} /* line 2440 */
  sim_icache_fetch(1170 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2442 */
  sim_icache_fetch(1171 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2444 */
} /* line 2444 */
  sim_icache_fetch(1172 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2446 */
} /* line 2446 */
  sim_icache_fetch(1173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2448 */
} /* line 2448 */
  sim_icache_fetch(1174 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2450 */
} /* line 2450 */
  sim_icache_fetch(1176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2452 */
} /* line 2452 */
  sim_icache_fetch(1177 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2454 */
} /* line 2454 */
  sim_icache_fetch(1178 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2456 */
} /* line 2456 */
  sim_icache_fetch(1179 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2458 */
  sim_icache_fetch(1180 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2460 */
} /* line 2460 */
  sim_icache_fetch(1181 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2462 */
  sim_icache_fetch(1182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2464 */
} /* line 2464 */
  sim_icache_fetch(1183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2466 */
} /* line 2466 */
  sim_icache_fetch(1184 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2468 */
} /* line 2468 */
  sim_icache_fetch(1185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2470 */
} /* line 2470 */
  sim_icache_fetch(1187 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2472 */
} /* line 2472 */
  sim_icache_fetch(1188 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2474 */
} /* line 2474 */
  sim_icache_fetch(1189 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2476 */
} /* line 2476 */
  sim_icache_fetch(1190 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2478 */
  sim_icache_fetch(1191 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2480 */
} /* line 2480 */
  sim_icache_fetch(1192 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2482 */
  sim_icache_fetch(1193 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2484 */
} /* line 2484 */
  sim_icache_fetch(1194 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2486 */
} /* line 2486 */
  sim_icache_fetch(1195 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2488 */
} /* line 2488 */
  sim_icache_fetch(1196 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2490 */
} /* line 2490 */
  sim_icache_fetch(1198 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2492 */
} /* line 2492 */
  sim_icache_fetch(1199 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2494 */
} /* line 2494 */
  sim_icache_fetch(1200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2496 */
} /* line 2496 */
  sim_icache_fetch(1201 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2498 */
  sim_icache_fetch(1202 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2500 */
} /* line 2500 */
  sim_icache_fetch(1203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2502 */
  sim_icache_fetch(1204 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2504 */
} /* line 2504 */
  sim_icache_fetch(1205 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_8); /* line 2506 */
} /* line 2506 */
  sim_icache_fetch(1206 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_6); /* line 2508 */
} /* line 2508 */
  sim_icache_fetch(1207 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2510 */
} /* line 2510 */
  sim_icache_fetch(1209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2512 */
} /* line 2512 */
  sim_icache_fetch(1210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2514 */
} /* line 2514 */
  sim_icache_fetch(1211 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2516 */
} /* line 2516 */
  sim_icache_fetch(1212 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2518 */
  sim_icache_fetch(1213 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2520 */
} /* line 2520 */
  sim_icache_fetch(1214 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2522 */
  sim_icache_fetch(1215 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2524 */
} /* line 2524 */
  sim_icache_fetch(1216 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_4, reg_r0_7); /* line 2526 */
} /* line 2526 */
  sim_icache_fetch(1217 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_6); /* line 2528 */
} /* line 2528 */
  sim_icache_fetch(1218 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 2530 */
} /* line 2530 */
  sim_icache_fetch(1220 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2532 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2533 */
   __ADD_CYCLES(1);
} /* line 2533 */
  sim_icache_fetch(1222 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2535 */
} /* line 2535 */
  sim_icache_fetch(1223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2537 */
  sim_icache_fetch(1224 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 2539 */
} /* line 2539 */
  sim_icache_fetch(1225 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2542 */
  sim_icache_fetch(1226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2544 */
l_L110X3: ;/* line 2547 */
__LABEL(l_L110X3);
  sim_icache_fetch(1227 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2548 */
} /* line 2548 */
  sim_icache_fetch(1228 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2550 */
} /* line 2550 */
  sim_icache_fetch(1229 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2552 */
} /* line 2552 */
  sim_icache_fetch(1230 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2555 */
} /* line 2555 */
  sim_icache_fetch(1231 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2557 */
l_L106X3: ;/* line 2562 */
__LABEL(l_L106X3);
  sim_icache_fetch(1232 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 2562 */
  sim_icache_fetch(1233 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2564 */
l_L105X3: ;/* line 2567 */
__LABEL(l_L105X3);
  sim_icache_fetch(1234 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2568 */
} /* line 2568 */
  sim_icache_fetch(1235 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2570 */
} /* line 2570 */
  sim_icache_fetch(1236 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2572 */
} /* line 2572 */
  sim_icache_fetch(1237 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2574 */
} /* line 2574 */
  sim_icache_fetch(1238 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2577 */
} /* line 2577 */
  sim_icache_fetch(1239 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2579 */
l_L104X3: ;/* line 2582 */
__LABEL(l_L104X3);
  sim_icache_fetch(1240 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2584 */
} /* line 2584 */
  sim_icache_fetch(1241 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2586 */
l_L103X3: ;/* line 2589 */
__LABEL(l_L103X3);
  sim_icache_fetch(1242 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2590 */
} /* line 2590 */
  sim_icache_fetch(1243 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2592 */
} /* line 2592 */
  sim_icache_fetch(1244 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2594 */
} /* line 2594 */
  sim_icache_fetch(1245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2596 */
} /* line 2596 */
  sim_icache_fetch(1246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2599 */
} /* line 2599 */
  sim_icache_fetch(1247 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2601 */
l_L102X3: ;/* line 2604 */
__LABEL(l_L102X3);
  sim_icache_fetch(1248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2606 */
} /* line 2606 */
  sim_icache_fetch(1249 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2608 */
l_L101X3: ;/* line 2611 */
__LABEL(l_L101X3);
  sim_icache_fetch(1250 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2612 */
} /* line 2612 */
  sim_icache_fetch(1251 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2614 */
} /* line 2614 */
  sim_icache_fetch(1252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2616 */
} /* line 2616 */
  sim_icache_fetch(1253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2618 */
} /* line 2618 */
  sim_icache_fetch(1254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2621 */
} /* line 2621 */
  sim_icache_fetch(1255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2623 */
l_L100X3: ;/* line 2626 */
__LABEL(l_L100X3);
  sim_icache_fetch(1256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2628 */
} /* line 2628 */
  sim_icache_fetch(1257 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2630 */
l_L99X3: ;/* line 2633 */
__LABEL(l_L99X3);
  sim_icache_fetch(1258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2634 */
} /* line 2634 */
  sim_icache_fetch(1259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2636 */
} /* line 2636 */
  sim_icache_fetch(1260 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2638 */
} /* line 2638 */
  sim_icache_fetch(1261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2640 */
} /* line 2640 */
  sim_icache_fetch(1262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2643 */
} /* line 2643 */
  sim_icache_fetch(1263 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2645 */
l_L98X3: ;/* line 2648 */
__LABEL(l_L98X3);
  sim_icache_fetch(1264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2650 */
} /* line 2650 */
  sim_icache_fetch(1265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2652 */
l_L97X3: ;/* line 2655 */
__LABEL(l_L97X3);
  sim_icache_fetch(1266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2656 */
} /* line 2656 */
  sim_icache_fetch(1267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2658 */
} /* line 2658 */
  sim_icache_fetch(1268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2660 */
} /* line 2660 */
  sim_icache_fetch(1269 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2662 */
} /* line 2662 */
  sim_icache_fetch(1270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2665 */
} /* line 2665 */
  sim_icache_fetch(1271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2667 */
l_L96X3: ;/* line 2670 */
__LABEL(l_L96X3);
  sim_icache_fetch(1272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2672 */
} /* line 2672 */
  sim_icache_fetch(1273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2674 */
l_L95X3: ;/* line 2677 */
__LABEL(l_L95X3);
  sim_icache_fetch(1274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2678 */
} /* line 2678 */
  sim_icache_fetch(1275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2680 */
} /* line 2680 */
  sim_icache_fetch(1276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2682 */
} /* line 2682 */
  sim_icache_fetch(1277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2684 */
} /* line 2684 */
  sim_icache_fetch(1278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2687 */
} /* line 2687 */
  sim_icache_fetch(1279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2689 */
l_L94X3: ;/* line 2692 */
__LABEL(l_L94X3);
  sim_icache_fetch(1280 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2694 */
} /* line 2694 */
  sim_icache_fetch(1281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2696 */
l_L93X3: ;/* line 2699 */
__LABEL(l_L93X3);
  sim_icache_fetch(1282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2700 */
} /* line 2700 */
  sim_icache_fetch(1283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2702 */
} /* line 2702 */
  sim_icache_fetch(1284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2704 */
} /* line 2704 */
  sim_icache_fetch(1285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2706 */
} /* line 2706 */
  sim_icache_fetch(1286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2709 */
} /* line 2709 */
  sim_icache_fetch(1287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2711 */
l_L92X3: ;/* line 2714 */
__LABEL(l_L92X3);
  sim_icache_fetch(1288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2716 */
} /* line 2716 */
  sim_icache_fetch(1289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2718 */
l_L91X3: ;/* line 2721 */
__LABEL(l_L91X3);
  sim_icache_fetch(1290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2722 */
} /* line 2722 */
  sim_icache_fetch(1291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2724 */
} /* line 2724 */
  sim_icache_fetch(1292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2726 */
} /* line 2726 */
  sim_icache_fetch(1293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2728 */
} /* line 2728 */
  sim_icache_fetch(1294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2731 */
} /* line 2731 */
  sim_icache_fetch(1295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2733 */
l_L90X3: ;/* line 2736 */
__LABEL(l_L90X3);
  sim_icache_fetch(1296 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2738 */
} /* line 2738 */
  sim_icache_fetch(1297 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2740 */
l_L89X3: ;/* line 2743 */
__LABEL(l_L89X3);
  sim_icache_fetch(1298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2744 */
} /* line 2744 */
  sim_icache_fetch(1299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2746 */
} /* line 2746 */
  sim_icache_fetch(1300 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2748 */
} /* line 2748 */
  sim_icache_fetch(1301 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2750 */
} /* line 2750 */
  sim_icache_fetch(1302 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2753 */
} /* line 2753 */
  sim_icache_fetch(1303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2755 */
l_L88X3: ;/* line 2758 */
__LABEL(l_L88X3);
  sim_icache_fetch(1304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2760 */
} /* line 2760 */
  sim_icache_fetch(1305 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2762 */
l_L87X3: ;/* line 2765 */
__LABEL(l_L87X3);
  sim_icache_fetch(1306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2766 */
} /* line 2766 */
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2768 */
} /* line 2768 */
  sim_icache_fetch(1308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2770 */
} /* line 2770 */
  sim_icache_fetch(1309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2772 */
} /* line 2772 */
  sim_icache_fetch(1310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2775 */
} /* line 2775 */
  sim_icache_fetch(1311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2777 */
l_L86X3: ;/* line 2780 */
__LABEL(l_L86X3);
  sim_icache_fetch(1312 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2782 */
} /* line 2782 */
  sim_icache_fetch(1313 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2784 */
l_L85X3: ;/* line 2787 */
__LABEL(l_L85X3);
  sim_icache_fetch(1314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2788 */
} /* line 2788 */
  sim_icache_fetch(1315 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2790 */
} /* line 2790 */
  sim_icache_fetch(1316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2792 */
} /* line 2792 */
  sim_icache_fetch(1317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2794 */
} /* line 2794 */
  sim_icache_fetch(1318 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2797 */
} /* line 2797 */
  sim_icache_fetch(1319 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2799 */
l_L84X3: ;/* line 2802 */
__LABEL(l_L84X3);
  sim_icache_fetch(1320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2804 */
} /* line 2804 */
  sim_icache_fetch(1321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2806 */
l_L83X3: ;/* line 2809 */
__LABEL(l_L83X3);
  sim_icache_fetch(1322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2810 */
} /* line 2810 */
  sim_icache_fetch(1323 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2812 */
} /* line 2812 */
  sim_icache_fetch(1324 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2814 */
} /* line 2814 */
  sim_icache_fetch(1325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2816 */
} /* line 2816 */
  sim_icache_fetch(1326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2819 */
} /* line 2819 */
  sim_icache_fetch(1327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2821 */
l_L82X3: ;/* line 2824 */
__LABEL(l_L82X3);
  sim_icache_fetch(1328 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2826 */
} /* line 2826 */
  sim_icache_fetch(1329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2828 */
l_L81X3: ;/* line 2831 */
__LABEL(l_L81X3);
  sim_icache_fetch(1330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2832 */
} /* line 2832 */
  sim_icache_fetch(1331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2834 */
} /* line 2834 */
  sim_icache_fetch(1332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2836 */
} /* line 2836 */
  sim_icache_fetch(1333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2838 */
} /* line 2838 */
  sim_icache_fetch(1334 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2841 */
} /* line 2841 */
  sim_icache_fetch(1335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2843 */
l_L80X3: ;/* line 2846 */
__LABEL(l_L80X3);
  sim_icache_fetch(1336 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_8); /* line 2848 */
} /* line 2848 */
  sim_icache_fetch(1337 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2850 */
l_L79X3: ;/* line 2853 */
__LABEL(l_L79X3);
  sim_icache_fetch(1338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2854 */
} /* line 2854 */
  sim_icache_fetch(1339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2856 */
} /* line 2856 */
  sim_icache_fetch(1340 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2858 */
} /* line 2858 */
  sim_icache_fetch(1341 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2860 */
} /* line 2860 */
  sim_icache_fetch(1342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2863 */
} /* line 2863 */
  sim_icache_fetch(1343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2865 */
l_L78X3: ;/* line 2868 */
__LABEL(l_L78X3);
  sim_icache_fetch(1344 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2870 */
} /* line 2870 */
  sim_icache_fetch(1345 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2872 */
l_L109X3: ;/* line 2875 */
__LABEL(l_L109X3);
  sim_icache_fetch(1346 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2876 */
} /* line 2876 */
l_L77X3: ;/* line 2879 */
__LABEL(l_L77X3);
  sim_icache_fetch(1347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2880 */
} /* line 2880 */
  sim_icache_fetch(1348 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 2882 */
  sim_icache_fetch(1349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2884 */
} /* line 2884 */
  sim_icache_fetch(1350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2886 */
} /* line 2886 */
  sim_icache_fetch(1351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2889 */
} /* line 2889 */
  sim_icache_fetch(1352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2891 */
l_L108X3: ;/* line 2894 */
__LABEL(l_L108X3);
  sim_icache_fetch(1353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2895 */
} /* line 2895 */
l_L76X3: ;/* line 2899 */
__LABEL(l_L76X3);
  sim_icache_fetch(1354 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 2899 */
l_L111X3: ;/* line 2901 */
__LABEL(l_L111X3);
  sim_icache_fetch(1355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2902 */
} /* line 2902 */
  sim_icache_fetch(1357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_2,0,2)); /* line 2904 */
} /* line 2904 */
  sim_icache_fetch(1358 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2906 */
} /* line 2906 */
  sim_icache_fetch(1359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2908 */
} /* line 2908 */
  sim_icache_fetch(1360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 2910 */
l_L107X3: ;/* line 2913 */
__LABEL(l_L107X3);
  sim_icache_fetch(1361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2914 */
} /* line 2914 */
  sim_icache_fetch(1362 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2916 */
} /* line 2916 */
  sim_icache_fetch(1363 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_9); /* line 2918 */
} /* line 2918 */
  sim_icache_fetch(1364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2921 */
} /* line 2921 */
  sim_icache_fetch(1365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2923 */
l_L69X3: ;/* line 2926 */
__LABEL(l_L69X3);
  sim_icache_fetch(1366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_7); /* line 2927 */
} /* line 2927 */
		 /* line 2928 */
  sim_icache_fetch(1367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (270 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2930 */
l_lr_139: ;/* line 2930 */
__LABEL(l_lr_139);
  sim_icache_fetch(1369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2932 */
} /* line 2932 */
  sim_icache_fetch(1371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2934 */
} /* line 2934 */
  sim_icache_fetch(1372 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2936 */
} /* line 2936 */
  sim_icache_fetch(1373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2938 */
} /* line 2938 */
		 /* line 2939 */
  sim_icache_fetch(1375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (270 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2941 */
l_lr_141: ;/* line 2941 */
__LABEL(l_lr_141);
  sim_icache_fetch(1377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2943 */
} /* line 2943 */
  sim_icache_fetch(1379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2945 */
} /* line 2945 */
  sim_icache_fetch(1381 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2947 */
} /* line 2947 */
  sim_icache_fetch(1383 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2949 */
} /* line 2949 */
  sim_icache_fetch(1384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2951 */
l_L113X3: ;/* line 2953 */
__LABEL(l_L113X3);
  sim_icache_fetch(1385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2954 */
} /* line 2954 */
  sim_icache_fetch(1387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) 2); /* line 2956 */
} /* line 2956 */
  sim_icache_fetch(1388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_6, reg_r0_2); /* line 2958 */
} /* line 2958 */
  sim_icache_fetch(1389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2960 */
  sim_icache_fetch(1390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2962 */
} /* line 2962 */
  sim_icache_fetch(1391 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 2964 */
} /* line 2964 */
  sim_icache_fetch(1392 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_4); /* line 2966 */
} /* line 2966 */
l_L115X3: ;/* line 2968 */
__LABEL(l_L115X3);
  sim_icache_fetch(1394 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2969 */
} /* line 2969 */
  sim_icache_fetch(1395 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2972 */
l_L114X3: ;/* line 2975 */
__LABEL(l_L114X3);
  sim_icache_fetch(1396 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2976 */
} /* line 2976 */
  sim_icache_fetch(1397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 2979 */
} /* line 2979 */
  sim_icache_fetch(1398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L115X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L115X3;
} /* line 2981 */
l_L112X3: ;/* line 2984 */
__LABEL(l_L112X3);
  sim_icache_fetch(1399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2985 */
} /* line 2985 */
  sim_icache_fetch(1401 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2987 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2988 */
   __ADD_CYCLES(1);
} /* line 2988 */
  sim_icache_fetch(1404 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2990 */
} /* line 2990 */
		 /* line 2991 */
  sim_icache_fetch(1405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (270 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2993 */
l_lr_147: ;/* line 2993 */
__LABEL(l_lr_147);
  sim_icache_fetch(1407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2995 */
} /* line 2995 */
  sim_icache_fetch(1409 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L113X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L113X3;
} /* line 2997 */
l_L67X3: ;/* line 3000 */
__LABEL(l_L67X3);
  sim_icache_fetch(1410 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 3002 */
} /* line 3002 */
  sim_icache_fetch(1411 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 3004 */
l_L63X3: ;/* line 3007 */
__LABEL(l_L63X3);
  sim_icache_fetch(1412 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3008 */
} /* line 3008 */
  sim_icache_fetch(1413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3010 */
} /* line 3010 */
  sim_icache_fetch(1414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3012 */
} /* line 3012 */
  sim_icache_fetch(1415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3014 */
} /* line 3014 */
  sim_icache_fetch(1417 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 3017 */
} /* line 3017 */
  sim_icache_fetch(1418 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3019 */
l_L62X3: ;/* line 3022 */
__LABEL(l_L62X3);
  sim_icache_fetch(1419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3023 */
} /* line 3023 */
  sim_icache_fetch(1420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3025 */
} /* line 3025 */
  sim_icache_fetch(1421 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3027 */
} /* line 3027 */
  sim_icache_fetch(1422 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3029 */
} /* line 3029 */
  sim_icache_fetch(1424 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 3032 */
} /* line 3032 */
  sim_icache_fetch(1425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3034 */
l_L61X3: ;/* line 3037 */
__LABEL(l_L61X3);
  sim_icache_fetch(1426 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3038 */
} /* line 3038 */
  sim_icache_fetch(1427 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3040 */
} /* line 3040 */
  sim_icache_fetch(1428 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3042 */
} /* line 3042 */
  sim_icache_fetch(1429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3044 */
} /* line 3044 */
  sim_icache_fetch(1431 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 3047 */
} /* line 3047 */
  sim_icache_fetch(1432 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3049 */
l_L60X3: ;/* line 3052 */
__LABEL(l_L60X3);
  sim_icache_fetch(1433 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3053 */
} /* line 3053 */
  sim_icache_fetch(1434 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3055 */
} /* line 3055 */
  sim_icache_fetch(1435 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3057 */
} /* line 3057 */
  sim_icache_fetch(1436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3059 */
} /* line 3059 */
  sim_icache_fetch(1438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 3062 */
} /* line 3062 */
  sim_icache_fetch(1439 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3064 */
l_L59X3: ;/* line 3067 */
__LABEL(l_L59X3);
  sim_icache_fetch(1440 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3068 */
} /* line 3068 */
  sim_icache_fetch(1441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3070 */
} /* line 3070 */
  sim_icache_fetch(1442 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3072 */
} /* line 3072 */
  sim_icache_fetch(1443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3074 */
} /* line 3074 */
  sim_icache_fetch(1445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 3077 */
} /* line 3077 */
  sim_icache_fetch(1446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3079 */
l_L58X3: ;/* line 3082 */
__LABEL(l_L58X3);
  sim_icache_fetch(1447 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3083 */
} /* line 3083 */
  sim_icache_fetch(1448 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3085 */
} /* line 3085 */
  sim_icache_fetch(1449 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3087 */
} /* line 3087 */
  sim_icache_fetch(1450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3089 */
} /* line 3089 */
  sim_icache_fetch(1452 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 3092 */
} /* line 3092 */
  sim_icache_fetch(1453 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3094 */
l_L57X3: ;/* line 3097 */
__LABEL(l_L57X3);
  sim_icache_fetch(1454 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3098 */
} /* line 3098 */
  sim_icache_fetch(1455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3100 */
} /* line 3100 */
  sim_icache_fetch(1456 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3102 */
} /* line 3102 */
  sim_icache_fetch(1457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3104 */
} /* line 3104 */
  sim_icache_fetch(1459 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 3107 */
} /* line 3107 */
  sim_icache_fetch(1460 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3109 */
l_L56X3: ;/* line 3112 */
__LABEL(l_L56X3);
  sim_icache_fetch(1461 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3113 */
} /* line 3113 */
  sim_icache_fetch(1462 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3115 */
} /* line 3115 */
  sim_icache_fetch(1463 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3117 */
} /* line 3117 */
  sim_icache_fetch(1464 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3119 */
} /* line 3119 */
  sim_icache_fetch(1466 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 3122 */
} /* line 3122 */
  sim_icache_fetch(1467 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3124 */
l_L55X3: ;/* line 3127 */
__LABEL(l_L55X3);
  sim_icache_fetch(1468 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3128 */
} /* line 3128 */
  sim_icache_fetch(1469 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3130 */
} /* line 3130 */
  sim_icache_fetch(1470 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3132 */
} /* line 3132 */
  sim_icache_fetch(1471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3134 */
} /* line 3134 */
  sim_icache_fetch(1473 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 3137 */
} /* line 3137 */
  sim_icache_fetch(1474 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3139 */
l_L54X3: ;/* line 3142 */
__LABEL(l_L54X3);
  sim_icache_fetch(1475 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3143 */
} /* line 3143 */
  sim_icache_fetch(1476 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3145 */
} /* line 3145 */
  sim_icache_fetch(1477 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3147 */
} /* line 3147 */
  sim_icache_fetch(1478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3149 */
} /* line 3149 */
  sim_icache_fetch(1480 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 3152 */
} /* line 3152 */
  sim_icache_fetch(1481 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3154 */
l_L53X3: ;/* line 3157 */
__LABEL(l_L53X3);
  sim_icache_fetch(1482 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3158 */
} /* line 3158 */
  sim_icache_fetch(1483 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3160 */
} /* line 3160 */
  sim_icache_fetch(1484 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3162 */
} /* line 3162 */
  sim_icache_fetch(1485 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3164 */
} /* line 3164 */
  sim_icache_fetch(1487 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 3167 */
} /* line 3167 */
  sim_icache_fetch(1488 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3169 */
l_L52X3: ;/* line 3172 */
__LABEL(l_L52X3);
  sim_icache_fetch(1489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3173 */
} /* line 3173 */
  sim_icache_fetch(1490 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3175 */
} /* line 3175 */
  sim_icache_fetch(1491 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3177 */
} /* line 3177 */
  sim_icache_fetch(1492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3179 */
} /* line 3179 */
  sim_icache_fetch(1494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3182 */
} /* line 3182 */
  sim_icache_fetch(1495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3184 */
l_L51X3: ;/* line 3187 */
__LABEL(l_L51X3);
  sim_icache_fetch(1496 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3188 */
} /* line 3188 */
  sim_icache_fetch(1497 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3190 */
} /* line 3190 */
  sim_icache_fetch(1498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3192 */
} /* line 3192 */
  sim_icache_fetch(1499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3194 */
} /* line 3194 */
  sim_icache_fetch(1501 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 3197 */
} /* line 3197 */
  sim_icache_fetch(1502 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3199 */
l_L50X3: ;/* line 3202 */
__LABEL(l_L50X3);
  sim_icache_fetch(1503 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3203 */
} /* line 3203 */
  sim_icache_fetch(1504 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3205 */
} /* line 3205 */
  sim_icache_fetch(1505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3207 */
} /* line 3207 */
  sim_icache_fetch(1506 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3209 */
} /* line 3209 */
  sim_icache_fetch(1508 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 3212 */
} /* line 3212 */
  sim_icache_fetch(1509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 3214 */
l_L49X3: ;/* line 3217 */
__LABEL(l_L49X3);
  sim_icache_fetch(1510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 3218 */
} /* line 3218 */
  sim_icache_fetch(1511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 3220 */
} /* line 3220 */
  sim_icache_fetch(1512 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 3222 */
} /* line 3222 */
  sim_icache_fetch(1513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 3224 */
} /* line 3224 */
  sim_icache_fetch(1515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 3226 */
l_L65X3: ;/* line 3228 */
__LABEL(l_L65X3);
  sim_icache_fetch(1516 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, (unsigned int) 8, reg_r0_4); /* line 3229 */
} /* line 3229 */
  sim_icache_fetch(1517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 3231 */
} /* line 3231 */
  sim_icache_fetch(1518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_57); /* line 3233 */
} /* line 3233 */
		 /* line 3234 */
  sim_icache_fetch(1519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (270 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 3236 */
l_lr_166: ;/* line 3236 */
__LABEL(l_lr_166);
  sim_icache_fetch(1521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 3238 */
} /* line 3238 */
  sim_icache_fetch(1522 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 3240 */
} /* line 3240 */
  sim_icache_fetch(1523 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 3242 */
l_L46X3: ;/* line 3245 */
__LABEL(l_L46X3);
  sim_icache_fetch(1524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, (unsigned int) -1); /* line 3247 */
} /* line 3247 */
  sim_icache_fetch(1525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 3249 */
l_L44X3: ;/* line 3252 */
__LABEL(l_L44X3);
  sim_icache_fetch(1526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3253 */
} /* line 3253 */
  sim_icache_fetch(1528 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 3255 */
} /* line 3255 */
  sim_icache_fetch(1530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3257 */
} /* line 3257 */
  sim_icache_fetch(1531 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) 3); /* line 3259 */
} /* line 3259 */
  sim_icache_fetch(1532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3261 */
} /* line 3261 */
  sim_icache_fetch(1534 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3263 */
} /* line 3263 */
  sim_icache_fetch(1535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3265 */
} /* line 3265 */
  sim_icache_fetch(1537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 3267 */
} /* line 3267 */
  sim_icache_fetch(1539 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3269 */
} /* line 3269 */
  sim_icache_fetch(1540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3271 */
} /* line 3271 */
  sim_icache_fetch(1542 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3273 */
} /* line 3273 */
  sim_icache_fetch(1543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3275 */
} /* line 3275 */
  sim_icache_fetch(1545 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 3277 */
} /* line 3277 */
  sim_icache_fetch(1547 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3279 */
} /* line 3279 */
  sim_icache_fetch(1548 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3281 */
} /* line 3281 */
  sim_icache_fetch(1550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3283 */
} /* line 3283 */
  sim_icache_fetch(1552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_3, reg_r0_3, reg_r0_5); /* line 3285 */
} /* line 3285 */
  sim_icache_fetch(1553 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3288 */
} /* line 3288 */
  sim_icache_fetch(1554 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 3290 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 186: goto l_L45X3;
    case 187: goto l_L47X3;
    case 188: goto l_L48X3;
    case 189: goto l_L64X3;
    case 190: goto l_L66X3;
    case 191: goto l_L68X3;
    case 192: goto l_L70X3;
    case 193: goto l_L72X3;
    case 195: goto l_lr_94;
    case 196: goto l_L73X3;
    case 198: goto l_lr_97;
    case 199: goto l_L74X3;
    case 200: goto l_L71X3;
    case 201: goto l_L75X3;
    case 202: goto l_L110X3;
    case 203: goto l_L106X3;
    case 204: goto l_L105X3;
    case 205: goto l_L104X3;
    case 206: goto l_L103X3;
    case 207: goto l_L102X3;
    case 208: goto l_L101X3;
    case 209: goto l_L100X3;
    case 210: goto l_L99X3;
    case 211: goto l_L98X3;
    case 212: goto l_L97X3;
    case 213: goto l_L96X3;
    case 214: goto l_L95X3;
    case 215: goto l_L94X3;
    case 216: goto l_L93X3;
    case 217: goto l_L92X3;
    case 218: goto l_L91X3;
    case 219: goto l_L90X3;
    case 220: goto l_L89X3;
    case 221: goto l_L88X3;
    case 222: goto l_L87X3;
    case 223: goto l_L86X3;
    case 224: goto l_L85X3;
    case 225: goto l_L84X3;
    case 226: goto l_L83X3;
    case 227: goto l_L82X3;
    case 228: goto l_L81X3;
    case 229: goto l_L80X3;
    case 230: goto l_L79X3;
    case 231: goto l_L78X3;
    case 232: goto l_L109X3;
    case 233: goto l_L77X3;
    case 234: goto l_L108X3;
    case 235: goto l_L76X3;
    case 236: goto l_L111X3;
    case 237: goto l_L107X3;
    case 238: goto l_L69X3;
    case 240: goto l_lr_139;
    case 242: goto l_lr_141;
    case 243: goto l_L113X3;
    case 244: goto l_L115X3;
    case 245: goto l_L114X3;
    case 246: goto l_L112X3;
    case 248: goto l_lr_147;
    case 249: goto l_L67X3;
    case 250: goto l_L63X3;
    case 251: goto l_L62X3;
    case 252: goto l_L61X3;
    case 253: goto l_L60X3;
    case 254: goto l_L59X3;
    case 255: goto l_L58X3;
    case 256: goto l_L57X3;
    case 257: goto l_L56X3;
    case 258: goto l_L55X3;
    case 259: goto l_L54X3;
    case 260: goto l_L53X3;
    case 261: goto l_L52X3;
    case 262: goto l_L51X3;
    case 263: goto l_L50X3;
    case 264: goto l_L49X3;
    case 265: goto l_L65X3;
    case 267: goto l_lr_166;
    case 268: goto l_L46X3;
    case 269: goto l_L44X3;
    case 270:
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
  reg_l0_0 = (304 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1555 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 3308 */
  sim_icache_fetch(1556 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 3310 */
} /* line 3310 */
  sim_icache_fetch(1558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3312 */
} /* line 3312 */
  sim_icache_fetch(1560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 3314 */
} /* line 3314 */
  sim_icache_fetch(1561 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBUs(reg_r0_7, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 3316 */
} /* line 3316 */
  sim_icache_fetch(1563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 3318 */
} /* line 3318 */
  sim_icache_fetch(1564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_7, reg_r0_7, reg_r0_8); /* line 3320 */
} /* line 3320 */
  sim_icache_fetch(1565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBUs(reg_r0_8, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 3322 */
} /* line 3322 */
  sim_icache_fetch(1567 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 3324 */
} /* line 3324 */
  sim_icache_fetch(1568 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) compress_8419Xbuf),0,1)); /* line 3326 */
} /* line 3326 */
  sim_icache_fetch(1570 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 3328 */
} /* line 3328 */
  sim_icache_fetch(1571 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_8, reg_r0_8, reg_r0_9); /* line 3330 */
} /* line 3330 */
  sim_icache_fetch(1572 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_7, reg_r0_7, reg_r0_8); /* line 3332 */
} /* line 3332 */
  sim_icache_fetch(1573 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3334 */
  sim_icache_fetch(1574 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_6); /* line 3336 */
} /* line 3336 */
  sim_icache_fetch(1575 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_3, reg_r0_3, reg_r0_8); /* line 3338 */
} /* line 3338 */
  sim_icache_fetch(1576 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_3); /* line 3340 */
} /* line 3340 */
  sim_icache_fetch(1577 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) compress_8419Xbuf); /* line 3342 */
} /* line 3342 */
  sim_icache_fetch(1579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_2, ((unsigned int) compress_8419Xbuf + (unsigned int) 1)); /* line 3344 */
} /* line 3344 */
  sim_icache_fetch(1581 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -8); /* line 3346 */
} /* line 3346 */
  sim_icache_fetch(1582 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_6); /* line 3348 */
} /* line 3348 */
  sim_icache_fetch(1583 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_5, (unsigned int) 8); /* line 3350 */
} /* line 3350 */
  sim_icache_fetch(1584 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) compress_8419Xbuf),0,1), reg_r0_7); /* line 3352 */
} /* line 3352 */
  sim_icache_fetch(1586 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3354 */
  sim_icache_fetch(1587 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 2); /* line 3356 */
} /* line 3356 */
  sim_icache_fetch(1588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_8, reg_r0_3, (unsigned int) 8); /* line 3358 */
} /* line 3358 */
  sim_icache_fetch(1589 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -8); /* line 3360 */
} /* line 3360 */
  sim_icache_fetch(1590 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_5, 0); /* line 3362 */
} /* line 3362 */
  sim_icache_fetch(1591 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_9 + (unsigned int) 1),0,1), reg_r0_3); /* line 3364 */
} /* line 3364 */
l_L118X3: ;/* line 3366 */
__LABEL(l_L118X3);
  sim_icache_fetch(1592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3367 */
  sim_icache_fetch(1593 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) compress_8419Xbuf); /* line 3369 */
} /* line 3369 */
  sim_icache_fetch(1595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_10,0,1), reg_r0_8); /* line 3371 */
} /* line 3371 */
l_L120X3: ;/* line 3373 */
__LABEL(l_L120X3);
  sim_icache_fetch(1596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 3374 */
} /* line 3374 */
  sim_icache_fetch(1598 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3376 */
} /* line 3376 */
  sim_icache_fetch(1600 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3378 */
} /* line 3378 */
  sim_icache_fetch(1602 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_5); /* line 3380 */
} /* line 3380 */
  sim_icache_fetch(1603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_7, reg_r0_5, (unsigned int) 3); /* line 3382 */
} /* line 3382 */
  sim_icache_fetch(1604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 3384 */
} /* line 3384 */
  sim_icache_fetch(1605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_5, reg_r0_6); /* line 3386 */
} /* line 3386 */
  sim_icache_fetch(1606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, reg_r0_5); /* line 3388 */
} /* line 3388 */
  sim_icache_fetch(1607 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_8419Xoffset,0,4), reg_r0_2); /* line 3390 */
} /* line 3390 */
  sim_icache_fetch(1609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3392 */
  sim_icache_fetch(1610 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 3394 */
} /* line 3394 */
l_L122X3: ;/* line 3397 */
__LABEL(l_L122X3);
  sim_icache_fetch(1612 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3398 */
} /* line 3398 */
  sim_icache_fetch(1614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_3,0,1)); /* line 3400 */
} /* line 3400 */
  sim_icache_fetch(1615 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3402 */
} /* line 3402 */
  sim_icache_fetch(1616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_4, (unsigned int) 1); /* line 3404 */
} /* line 3404 */
  sim_icache_fetch(1617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_4, (unsigned int) 2); /* line 3406 */
} /* line 3406 */
  sim_icache_fetch(1618 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_4, (unsigned int) 3); /* line 3408 */
} /* line 3408 */
  sim_icache_fetch(1619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_4, (unsigned int) 4); /* line 3410 */
} /* line 3410 */
  sim_icache_fetch(1620 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_4, reg_r0_4, (unsigned int) 5); /* line 3412 */
} /* line 3412 */
  sim_icache_fetch(1621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_5, reg_r0_4, (unsigned int) 6); /* line 3414 */
} /* line 3414 */
  sim_icache_fetch(1622 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_4, (unsigned int) 7); /* line 3416 */
} /* line 3416 */
  sim_icache_fetch(1623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_4, (unsigned int) 8); /* line 3418 */
} /* line 3418 */
  sim_icache_fetch(1624 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) 16); /* line 3420 */
} /* line 3420 */
  sim_icache_fetch(1625 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) -16); /* line 3422 */
} /* line 3422 */
  sim_icache_fetch(1626 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3424 */
} /* line 3424 */
  sim_icache_fetch(1628 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3426 */
} /* line 3426 */
  sim_icache_fetch(1629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3428 */
  sim_icache_fetch(1630 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3430 */
} /* line 3430 */
  sim_icache_fetch(1632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 3432 */
} /* line 3432 */
  sim_icache_fetch(1633 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3434 */
} /* line 3434 */
  sim_icache_fetch(1634 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_4, (unsigned int) 9); /* line 3436 */
} /* line 3436 */
  sim_icache_fetch(1635 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3438 */
} /* line 3438 */
  sim_icache_fetch(1637 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3440 */
} /* line 3440 */
  sim_icache_fetch(1638 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3442 */
  sim_icache_fetch(1639 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3444 */
} /* line 3444 */
  sim_icache_fetch(1641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 3446 */
} /* line 3446 */
  sim_icache_fetch(1642 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3448 */
} /* line 3448 */
  sim_icache_fetch(1643 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_4, (unsigned int) 10); /* line 3450 */
} /* line 3450 */
  sim_icache_fetch(1644 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3452 */
} /* line 3452 */
  sim_icache_fetch(1646 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3454 */
} /* line 3454 */
  sim_icache_fetch(1647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3456 */
  sim_icache_fetch(1648 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3458 */
} /* line 3458 */
  sim_icache_fetch(1650 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 3460 */
} /* line 3460 */
  sim_icache_fetch(1651 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3462 */
} /* line 3462 */
  sim_icache_fetch(1652 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_4, (unsigned int) 11); /* line 3464 */
} /* line 3464 */
  sim_icache_fetch(1653 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3466 */
} /* line 3466 */
  sim_icache_fetch(1655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3468 */
} /* line 3468 */
  sim_icache_fetch(1656 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3470 */
  sim_icache_fetch(1657 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3472 */
} /* line 3472 */
  sim_icache_fetch(1659 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 3474 */
} /* line 3474 */
  sim_icache_fetch(1660 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3476 */
} /* line 3476 */
  sim_icache_fetch(1661 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_4, (unsigned int) 12); /* line 3478 */
} /* line 3478 */
  sim_icache_fetch(1662 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3480 */
} /* line 3480 */
  sim_icache_fetch(1664 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3482 */
} /* line 3482 */
  sim_icache_fetch(1665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3484 */
  sim_icache_fetch(1666 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3486 */
} /* line 3486 */
  sim_icache_fetch(1668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 3488 */
} /* line 3488 */
  sim_icache_fetch(1669 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3490 */
} /* line 3490 */
  sim_icache_fetch(1670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_4, reg_r0_4, (unsigned int) 13); /* line 3492 */
} /* line 3492 */
  sim_icache_fetch(1671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3494 */
} /* line 3494 */
  sim_icache_fetch(1673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3496 */
} /* line 3496 */
  sim_icache_fetch(1674 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3498 */
  sim_icache_fetch(1675 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3500 */
} /* line 3500 */
  sim_icache_fetch(1677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 3502 */
} /* line 3502 */
  sim_icache_fetch(1678 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3504 */
} /* line 3504 */
  sim_icache_fetch(1679 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_5, reg_r0_4, (unsigned int) 14); /* line 3506 */
} /* line 3506 */
  sim_icache_fetch(1680 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3508 */
} /* line 3508 */
  sim_icache_fetch(1682 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3510 */
} /* line 3510 */
  sim_icache_fetch(1683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3512 */
  sim_icache_fetch(1684 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3514 */
} /* line 3514 */
  sim_icache_fetch(1686 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 3516 */
} /* line 3516 */
  sim_icache_fetch(1687 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3518 */
} /* line 3518 */
  sim_icache_fetch(1688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_4, (unsigned int) 15); /* line 3520 */
} /* line 3520 */
  sim_icache_fetch(1689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_8, (unsigned int) -16); /* line 3522 */
} /* line 3522 */
  sim_icache_fetch(1690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3524 */
} /* line 3524 */
  sim_icache_fetch(1692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3526 */
} /* line 3526 */
  sim_icache_fetch(1693 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3528 */
  sim_icache_fetch(1694 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3530 */
} /* line 3530 */
  sim_icache_fetch(1696 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 3532 */
} /* line 3532 */
  sim_icache_fetch(1697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3534 */
} /* line 3534 */
  sim_icache_fetch(1698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_8, 0); /* line 3536 */
} /* line 3536 */
  sim_icache_fetch(1699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3538 */
} /* line 3538 */
  sim_icache_fetch(1701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3540 */
} /* line 3540 */
  sim_icache_fetch(1702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3542 */
  sim_icache_fetch(1703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3544 */
} /* line 3544 */
  sim_icache_fetch(1705 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 3546 */
} /* line 3546 */
  sim_icache_fetch(1706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3548 */
} /* line 3548 */
  sim_icache_fetch(1707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 3550 */
} /* line 3550 */
  sim_icache_fetch(1708 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3552 */
} /* line 3552 */
  sim_icache_fetch(1710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3554 */
} /* line 3554 */
  sim_icache_fetch(1711 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3556 */
  sim_icache_fetch(1712 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3558 */
} /* line 3558 */
  sim_icache_fetch(1714 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 3560 */
} /* line 3560 */
  sim_icache_fetch(1715 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3562 */
} /* line 3562 */
  sim_icache_fetch(1716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 2); /* line 3564 */
} /* line 3564 */
  sim_icache_fetch(1717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3566 */
} /* line 3566 */
  sim_icache_fetch(1719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3568 */
} /* line 3568 */
  sim_icache_fetch(1720 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3570 */
  sim_icache_fetch(1721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3572 */
} /* line 3572 */
  sim_icache_fetch(1723 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 3574 */
} /* line 3574 */
  sim_icache_fetch(1724 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3576 */
} /* line 3576 */
  sim_icache_fetch(1725 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 3); /* line 3578 */
} /* line 3578 */
  sim_icache_fetch(1726 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3580 */
} /* line 3580 */
  sim_icache_fetch(1728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3582 */
} /* line 3582 */
  sim_icache_fetch(1729 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3584 */
  sim_icache_fetch(1730 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3586 */
} /* line 3586 */
  sim_icache_fetch(1732 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 3588 */
} /* line 3588 */
  sim_icache_fetch(1733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3590 */
} /* line 3590 */
  sim_icache_fetch(1734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 4); /* line 3592 */
} /* line 3592 */
  sim_icache_fetch(1735 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3594 */
} /* line 3594 */
  sim_icache_fetch(1737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3596 */
} /* line 3596 */
  sim_icache_fetch(1738 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3598 */
  sim_icache_fetch(1739 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3600 */
} /* line 3600 */
  sim_icache_fetch(1741 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 3602 */
} /* line 3602 */
  sim_icache_fetch(1742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3604 */
} /* line 3604 */
  sim_icache_fetch(1743 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 5); /* line 3606 */
} /* line 3606 */
  sim_icache_fetch(1744 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3608 */
} /* line 3608 */
  sim_icache_fetch(1746 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3610 */
} /* line 3610 */
  sim_icache_fetch(1747 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3612 */
  sim_icache_fetch(1748 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3614 */
} /* line 3614 */
  sim_icache_fetch(1750 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 3616 */
} /* line 3616 */
  sim_icache_fetch(1751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3618 */
} /* line 3618 */
  sim_icache_fetch(1752 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 6); /* line 3620 */
} /* line 3620 */
  sim_icache_fetch(1753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3622 */
} /* line 3622 */
  sim_icache_fetch(1755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3624 */
} /* line 3624 */
  sim_icache_fetch(1756 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3626 */
  sim_icache_fetch(1757 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3628 */
} /* line 3628 */
  sim_icache_fetch(1759 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 3630 */
} /* line 3630 */
  sim_icache_fetch(1760 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 1); /* line 3632 */
} /* line 3632 */
  sim_icache_fetch(1761 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 7); /* line 3634 */
} /* line 3634 */
  sim_icache_fetch(1762 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 3636 */
} /* line 3636 */
  sim_icache_fetch(1764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3638 */
} /* line 3638 */
  sim_icache_fetch(1765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3640 */
  sim_icache_fetch(1766 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3642 */
} /* line 3642 */
  sim_icache_fetch(1768 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_7,0,1)); /* line 3644 */
} /* line 3644 */
  sim_icache_fetch(1769 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3646 */
} /* line 3646 */
  sim_icache_fetch(1770 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_8, (unsigned int) 8); /* line 3648 */
} /* line 3648 */
  sim_icache_fetch(1771 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) 16); /* line 3650 */
} /* line 3650 */
  sim_icache_fetch(1772 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3652 */
} /* line 3652 */
  sim_icache_fetch(1774 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3654 */
} /* line 3654 */
  sim_icache_fetch(1775 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3656 */
  sim_icache_fetch(1776 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3658 */
} /* line 3658 */
  sim_icache_fetch(1778 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 1),0,1)); /* line 3660 */
} /* line 3660 */
  sim_icache_fetch(1779 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3662 */
} /* line 3662 */
  sim_icache_fetch(1780 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 9); /* line 3664 */
} /* line 3664 */
  sim_icache_fetch(1781 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3666 */
} /* line 3666 */
  sim_icache_fetch(1783 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3668 */
} /* line 3668 */
  sim_icache_fetch(1784 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3670 */
  sim_icache_fetch(1785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3672 */
} /* line 3672 */
  sim_icache_fetch(1787 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,1)); /* line 3674 */
} /* line 3674 */
  sim_icache_fetch(1788 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3676 */
} /* line 3676 */
  sim_icache_fetch(1789 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 10); /* line 3678 */
} /* line 3678 */
  sim_icache_fetch(1790 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3680 */
} /* line 3680 */
  sim_icache_fetch(1792 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3682 */
} /* line 3682 */
  sim_icache_fetch(1793 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3684 */
  sim_icache_fetch(1794 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3686 */
} /* line 3686 */
  sim_icache_fetch(1796 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 3),0,1)); /* line 3688 */
} /* line 3688 */
  sim_icache_fetch(1797 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3690 */
} /* line 3690 */
  sim_icache_fetch(1798 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 11); /* line 3692 */
} /* line 3692 */
  sim_icache_fetch(1799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3694 */
} /* line 3694 */
  sim_icache_fetch(1801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3696 */
} /* line 3696 */
  sim_icache_fetch(1802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3698 */
  sim_icache_fetch(1803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3700 */
} /* line 3700 */
  sim_icache_fetch(1805 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,1)); /* line 3702 */
} /* line 3702 */
  sim_icache_fetch(1806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3704 */
} /* line 3704 */
  sim_icache_fetch(1807 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 12); /* line 3706 */
} /* line 3706 */
  sim_icache_fetch(1808 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3708 */
} /* line 3708 */
  sim_icache_fetch(1810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3710 */
} /* line 3710 */
  sim_icache_fetch(1811 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3712 */
  sim_icache_fetch(1812 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3714 */
} /* line 3714 */
  sim_icache_fetch(1814 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 5),0,1)); /* line 3716 */
} /* line 3716 */
  sim_icache_fetch(1815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3718 */
} /* line 3718 */
  sim_icache_fetch(1816 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 13); /* line 3720 */
} /* line 3720 */
  sim_icache_fetch(1817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3722 */
} /* line 3722 */
  sim_icache_fetch(1819 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3724 */
} /* line 3724 */
  sim_icache_fetch(1820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3726 */
  sim_icache_fetch(1821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3728 */
} /* line 3728 */
  sim_icache_fetch(1823 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 6),0,1)); /* line 3730 */
} /* line 3730 */
  sim_icache_fetch(1824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3732 */
} /* line 3732 */
  sim_icache_fetch(1825 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 14); /* line 3734 */
} /* line 3734 */
  sim_icache_fetch(1826 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3736 */
} /* line 3736 */
  sim_icache_fetch(1828 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3738 */
} /* line 3738 */
  sim_icache_fetch(1829 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3740 */
  sim_icache_fetch(1830 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3742 */
} /* line 3742 */
  sim_icache_fetch(1832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 7),0,1)); /* line 3744 */
} /* line 3744 */
  sim_icache_fetch(1833 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3746 */
} /* line 3746 */
  sim_icache_fetch(1834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 15); /* line 3748 */
} /* line 3748 */
  sim_icache_fetch(1835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3750 */
} /* line 3750 */
  sim_icache_fetch(1837 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3752 */
} /* line 3752 */
  sim_icache_fetch(1838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3754 */
  sim_icache_fetch(1839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3756 */
} /* line 3756 */
  sim_icache_fetch(1841 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 8),0,1)); /* line 3758 */
} /* line 3758 */
  sim_icache_fetch(1842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3760 */
} /* line 3760 */
  sim_icache_fetch(1843 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_4, 0); /* line 3762 */
} /* line 3762 */
  sim_icache_fetch(1844 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3764 */
} /* line 3764 */
  sim_icache_fetch(1846 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3766 */
} /* line 3766 */
  sim_icache_fetch(1847 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3768 */
  sim_icache_fetch(1848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3770 */
} /* line 3770 */
  sim_icache_fetch(1850 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 9),0,1)); /* line 3772 */
} /* line 3772 */
  sim_icache_fetch(1851 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3774 */
} /* line 3774 */
  sim_icache_fetch(1852 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3776 */
} /* line 3776 */
  sim_icache_fetch(1854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3778 */
} /* line 3778 */
  sim_icache_fetch(1855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3780 */
  sim_icache_fetch(1856 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3782 */
} /* line 3782 */
  sim_icache_fetch(1858 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 10),0,1)); /* line 3784 */
} /* line 3784 */
  sim_icache_fetch(1859 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3786 */
} /* line 3786 */
  sim_icache_fetch(1860 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3788 */
} /* line 3788 */
  sim_icache_fetch(1862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3790 */
} /* line 3790 */
  sim_icache_fetch(1863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3792 */
  sim_icache_fetch(1864 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3794 */
} /* line 3794 */
  sim_icache_fetch(1866 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 11),0,1)); /* line 3796 */
} /* line 3796 */
  sim_icache_fetch(1867 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3798 */
} /* line 3798 */
  sim_icache_fetch(1868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3800 */
} /* line 3800 */
  sim_icache_fetch(1870 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3802 */
} /* line 3802 */
  sim_icache_fetch(1871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3804 */
  sim_icache_fetch(1872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3806 */
} /* line 3806 */
  sim_icache_fetch(1874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,1)); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(1875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3810 */
} /* line 3810 */
  sim_icache_fetch(1876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3812 */
} /* line 3812 */
  sim_icache_fetch(1878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3814 */
} /* line 3814 */
  sim_icache_fetch(1879 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3816 */
  sim_icache_fetch(1880 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3818 */
} /* line 3818 */
  sim_icache_fetch(1882 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 13),0,1)); /* line 3820 */
} /* line 3820 */
  sim_icache_fetch(1883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3822 */
} /* line 3822 */
  sim_icache_fetch(1884 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3824 */
} /* line 3824 */
  sim_icache_fetch(1886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3826 */
} /* line 3826 */
  sim_icache_fetch(1887 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3828 */
  sim_icache_fetch(1888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3830 */
} /* line 3830 */
  sim_icache_fetch(1890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld((reg_r0_7 + (unsigned int) 14),0,1)); /* line 3832 */
} /* line 3832 */
  sim_icache_fetch(1891 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3834 */
} /* line 3834 */
  sim_icache_fetch(1892 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3836 */
} /* line 3836 */
  sim_icache_fetch(1894 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 3838 */
} /* line 3838 */
  sim_icache_fetch(1895 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3840 */
  sim_icache_fetch(1896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3842 */
} /* line 3842 */
  sim_icache_fetch(1898 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_7, mem_trace_ld((reg_r0_7 + (unsigned int) 15),0,1)); /* line 3844 */
} /* line 3844 */
  sim_icache_fetch(1899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 1); /* line 3846 */
} /* line 3846 */
  sim_icache_fetch(1900 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 3848 */
} /* line 3848 */
  sim_icache_fetch(1902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 3850 */
} /* line 3850 */
  sim_icache_fetch(1903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3853 */
  sim_icache_fetch(1904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L122X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L122X3;
} /* line 3855 */
l_L123X3: ;/* line 3858 */
__LABEL(l_L123X3);
  sim_icache_fetch(1905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_8419Xoffset,0,4), 0); /* line 3859 */
} /* line 3859 */
l_L121X3: ;/* line 3862 */
__LABEL(l_L121X3);
  sim_icache_fetch(1907 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3863 */
} /* line 3863 */
  sim_icache_fetch(1909 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_20, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3865 */
} /* line 3865 */
  sim_icache_fetch(1911 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_21, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3867 */
} /* line 3867 */
  sim_icache_fetch(1913 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_20); /* line 3869 */
} /* line 3869 */
  sim_icache_fetch(1914 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_r0_21, reg_r0_21, 0); /* line 3871 */
} /* line 3871 */
  sim_icache_fetch(1915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_0, reg_r0_2, reg_r0_21); /* line 3873 */
} /* line 3873 */
  sim_icache_fetch(1916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3875 */
  sim_icache_fetch(1917 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 3877 */
} /* line 3877 */
  sim_icache_fetch(1919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_19, (unsigned int) 15); /* line 3879 */
} /* line 3879 */
  sim_icache_fetch(1920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 3881 */
} /* line 3881 */
  sim_icache_fetch(1921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3883 */
  sim_icache_fetch(1922 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, (unsigned int) 14); /* line 3885 */
} /* line 3885 */
  sim_icache_fetch(1923 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_17, (unsigned int) 13); /* line 3887 */
} /* line 3887 */
  sim_icache_fetch(1924 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, (unsigned int) 12); /* line 3889 */
} /* line 3889 */
  sim_icache_fetch(1925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_15, (unsigned int) 11); /* line 3891 */
} /* line 3891 */
  sim_icache_fetch(1926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_14, (unsigned int) 10); /* line 3893 */
} /* line 3893 */
  sim_icache_fetch(1927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_13, (unsigned int) 9); /* line 3895 */
} /* line 3895 */
  sim_icache_fetch(1928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, (unsigned int) 8); /* line 3897 */
} /* line 3897 */
  sim_icache_fetch(1929 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_11, (unsigned int) 7); /* line 3899 */
} /* line 3899 */
  sim_icache_fetch(1930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_10, (unsigned int) 6); /* line 3901 */
} /* line 3901 */
  sim_icache_fetch(1931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, (unsigned int) 5); /* line 3903 */
} /* line 3903 */
  sim_icache_fetch(1932 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) 4); /* line 3905 */
} /* line 3905 */
  sim_icache_fetch(1933 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, (unsigned int) 3); /* line 3907 */
} /* line 3907 */
  sim_icache_fetch(1934 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) 2); /* line 3909 */
} /* line 3909 */
  sim_icache_fetch(1935 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 1); /* line 3911 */
} /* line 3911 */
  sim_icache_fetch(1936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) compress_8419Xbuf); /* line 3913 */
} /* line 3913 */
  sim_icache_fetch(1938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 3915 */
} /* line 3915 */
l_L126X3: ;/* line 3918 */
__LABEL(l_L126X3);
  sim_icache_fetch(1939 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3919 */
} /* line 3919 */
  sim_icache_fetch(1941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3921 */
} /* line 3921 */
  sim_icache_fetch(1943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3923 */
} /* line 3923 */
  sim_icache_fetch(1944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3925 */
  sim_icache_fetch(1945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 3927 */
} /* line 3927 */
  sim_icache_fetch(1946 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld(reg_r0_4,0,1)); /* line 3929 */
} /* line 3929 */
  sim_icache_fetch(1947 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_5, (unsigned int) 16); /* line 3931 */
} /* line 3931 */
  sim_icache_fetch(1948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) 16); /* line 3933 */
} /* line 3933 */
  sim_icache_fetch(1949 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_17, (unsigned int) 16); /* line 3935 */
} /* line 3935 */
  sim_icache_fetch(1950 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_25, reg_r0_16, (unsigned int) 16); /* line 3937 */
} /* line 3937 */
  sim_icache_fetch(1951 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_15, (unsigned int) 16); /* line 3939 */
} /* line 3939 */
  sim_icache_fetch(1952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_27, reg_r0_14, (unsigned int) 16); /* line 3941 */
} /* line 3941 */
  sim_icache_fetch(1953 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_28, reg_r0_13, (unsigned int) 16); /* line 3943 */
} /* line 3943 */
  sim_icache_fetch(1954 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_29, reg_r0_12, (unsigned int) 16); /* line 3945 */
} /* line 3945 */
  sim_icache_fetch(1955 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_11, (unsigned int) 16); /* line 3947 */
} /* line 3947 */
  sim_icache_fetch(1956 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_31, reg_r0_10, (unsigned int) 16); /* line 3949 */
} /* line 3949 */
  sim_icache_fetch(1957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_32, reg_r0_9, (unsigned int) 16); /* line 3951 */
} /* line 3951 */
  sim_icache_fetch(1958 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_33, reg_r0_8, (unsigned int) 16); /* line 3953 */
} /* line 3953 */
  sim_icache_fetch(1959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_34, reg_r0_7, (unsigned int) 16); /* line 3955 */
} /* line 3955 */
  sim_icache_fetch(1960 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_35, reg_r0_6, (unsigned int) 16); /* line 3957 */
} /* line 3957 */
  sim_icache_fetch(1961 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_19, (unsigned int) 16); /* line 3959 */
} /* line 3959 */
  sim_icache_fetch(1962 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_4, (unsigned int) 16); /* line 3961 */
} /* line 3961 */
  sim_icache_fetch(1963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3963 */
} /* line 3963 */
  sim_icache_fetch(1964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3965 */
} /* line 3965 */
  sim_icache_fetch(1965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3967 */
} /* line 3967 */
  sim_icache_fetch(1967 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 3969 */
} /* line 3969 */
  sim_icache_fetch(1968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3971 */
} /* line 3971 */
  sim_icache_fetch(1970 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3973 */
} /* line 3973 */
  sim_icache_fetch(1972 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_5, reg_r0_2); /* line 3975 */
} /* line 3975 */
  sim_icache_fetch(1973 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3977 */
  sim_icache_fetch(1974 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 3979 */
} /* line 3979 */
  sim_icache_fetch(1975 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 1),0,1)); /* line 3981 */
} /* line 3981 */
  sim_icache_fetch(1976 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_22, (unsigned int) 16); /* line 3983 */
} /* line 3983 */
  sim_icache_fetch(1977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3985 */
} /* line 3985 */
  sim_icache_fetch(1979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 3987 */
} /* line 3987 */
  sim_icache_fetch(1980 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3989 */
} /* line 3989 */
  sim_icache_fetch(1982 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3991 */
} /* line 3991 */
  sim_icache_fetch(1984 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_6, reg_r0_2); /* line 3993 */
} /* line 3993 */
  sim_icache_fetch(1985 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3995 */
  sim_icache_fetch(1986 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 3997 */
} /* line 3997 */
  sim_icache_fetch(1987 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 2),0,1)); /* line 3999 */
} /* line 3999 */
  sim_icache_fetch(1988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_35, (unsigned int) 16); /* line 4001 */
} /* line 4001 */
  sim_icache_fetch(1989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4003 */
} /* line 4003 */
  sim_icache_fetch(1991 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4005 */
} /* line 4005 */
  sim_icache_fetch(1992 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4007 */
} /* line 4007 */
  sim_icache_fetch(1994 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4009 */
} /* line 4009 */
  sim_icache_fetch(1996 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 4011 */
} /* line 4011 */
  sim_icache_fetch(1997 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4013 */
  sim_icache_fetch(1998 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4015 */
} /* line 4015 */
  sim_icache_fetch(1999 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 3),0,1)); /* line 4017 */
} /* line 4017 */
  sim_icache_fetch(2000 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_34, (unsigned int) 16); /* line 4019 */
} /* line 4019 */
  sim_icache_fetch(2001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4021 */
} /* line 4021 */
  sim_icache_fetch(2003 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4023 */
} /* line 4023 */
  sim_icache_fetch(2004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4025 */
} /* line 4025 */
  sim_icache_fetch(2006 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4027 */
} /* line 4027 */
  sim_icache_fetch(2008 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 4029 */
} /* line 4029 */
  sim_icache_fetch(2009 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4031 */
  sim_icache_fetch(2010 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4033 */
} /* line 4033 */
  sim_icache_fetch(2011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,1)); /* line 4035 */
} /* line 4035 */
  sim_icache_fetch(2012 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_33, (unsigned int) 16); /* line 4037 */
} /* line 4037 */
  sim_icache_fetch(2013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4039 */
} /* line 4039 */
  sim_icache_fetch(2015 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4041 */
} /* line 4041 */
  sim_icache_fetch(2016 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4043 */
} /* line 4043 */
  sim_icache_fetch(2018 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4045 */
} /* line 4045 */
  sim_icache_fetch(2020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 4047 */
} /* line 4047 */
  sim_icache_fetch(2021 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4049 */
  sim_icache_fetch(2022 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4051 */
} /* line 4051 */
  sim_icache_fetch(2023 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 5),0,1)); /* line 4053 */
} /* line 4053 */
  sim_icache_fetch(2024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_32, (unsigned int) 16); /* line 4055 */
} /* line 4055 */
  sim_icache_fetch(2025 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4057 */
} /* line 4057 */
  sim_icache_fetch(2027 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4059 */
} /* line 4059 */
  sim_icache_fetch(2028 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4061 */
} /* line 4061 */
  sim_icache_fetch(2030 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4063 */
} /* line 4063 */
  sim_icache_fetch(2032 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 4065 */
} /* line 4065 */
  sim_icache_fetch(2033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4067 */
  sim_icache_fetch(2034 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4069 */
} /* line 4069 */
  sim_icache_fetch(2035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 6),0,1)); /* line 4071 */
} /* line 4071 */
  sim_icache_fetch(2036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_31, (unsigned int) 16); /* line 4073 */
} /* line 4073 */
  sim_icache_fetch(2037 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4075 */
} /* line 4075 */
  sim_icache_fetch(2039 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4077 */
} /* line 4077 */
  sim_icache_fetch(2040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4079 */
} /* line 4079 */
  sim_icache_fetch(2042 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4081 */
} /* line 4081 */
  sim_icache_fetch(2044 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 4083 */
} /* line 4083 */
  sim_icache_fetch(2045 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4085 */
  sim_icache_fetch(2046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4087 */
} /* line 4087 */
  sim_icache_fetch(2047 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 7),0,1)); /* line 4089 */
} /* line 4089 */
  sim_icache_fetch(2048 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_30, (unsigned int) 16); /* line 4091 */
} /* line 4091 */
  sim_icache_fetch(2049 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4093 */
} /* line 4093 */
  sim_icache_fetch(2051 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4095 */
} /* line 4095 */
  sim_icache_fetch(2052 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4097 */
} /* line 4097 */
  sim_icache_fetch(2054 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4099 */
} /* line 4099 */
  sim_icache_fetch(2056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 4101 */
} /* line 4101 */
  sim_icache_fetch(2057 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4103 */
  sim_icache_fetch(2058 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4105 */
} /* line 4105 */
  sim_icache_fetch(2059 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,1)); /* line 4107 */
} /* line 4107 */
  sim_icache_fetch(2060 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_29, (unsigned int) 16); /* line 4109 */
} /* line 4109 */
  sim_icache_fetch(2061 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4111 */
} /* line 4111 */
  sim_icache_fetch(2063 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4113 */
} /* line 4113 */
  sim_icache_fetch(2064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4115 */
} /* line 4115 */
  sim_icache_fetch(2066 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4117 */
} /* line 4117 */
  sim_icache_fetch(2068 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 4119 */
} /* line 4119 */
  sim_icache_fetch(2069 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4121 */
  sim_icache_fetch(2070 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4123 */
} /* line 4123 */
  sim_icache_fetch(2071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 9),0,1)); /* line 4125 */
} /* line 4125 */
  sim_icache_fetch(2072 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_28, (unsigned int) 16); /* line 4127 */
} /* line 4127 */
  sim_icache_fetch(2073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4129 */
} /* line 4129 */
  sim_icache_fetch(2075 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4131 */
} /* line 4131 */
  sim_icache_fetch(2076 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4133 */
} /* line 4133 */
  sim_icache_fetch(2078 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4135 */
} /* line 4135 */
  sim_icache_fetch(2080 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 4137 */
} /* line 4137 */
  sim_icache_fetch(2081 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4139 */
  sim_icache_fetch(2082 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4141 */
} /* line 4141 */
  sim_icache_fetch(2083 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 10),0,1)); /* line 4143 */
} /* line 4143 */
  sim_icache_fetch(2084 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_27, (unsigned int) 16); /* line 4145 */
} /* line 4145 */
  sim_icache_fetch(2085 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4147 */
} /* line 4147 */
  sim_icache_fetch(2087 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4149 */
} /* line 4149 */
  sim_icache_fetch(2088 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4151 */
} /* line 4151 */
  sim_icache_fetch(2090 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4153 */
} /* line 4153 */
  sim_icache_fetch(2092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 4155 */
} /* line 4155 */
  sim_icache_fetch(2093 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4157 */
  sim_icache_fetch(2094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4159 */
} /* line 4159 */
  sim_icache_fetch(2095 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 11),0,1)); /* line 4161 */
} /* line 4161 */
  sim_icache_fetch(2096 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_26, (unsigned int) 16); /* line 4163 */
} /* line 4163 */
  sim_icache_fetch(2097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4165 */
} /* line 4165 */
  sim_icache_fetch(2099 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4167 */
} /* line 4167 */
  sim_icache_fetch(2100 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4169 */
} /* line 4169 */
  sim_icache_fetch(2102 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4171 */
} /* line 4171 */
  sim_icache_fetch(2104 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 4173 */
} /* line 4173 */
  sim_icache_fetch(2105 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4175 */
  sim_icache_fetch(2106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4177 */
} /* line 4177 */
  sim_icache_fetch(2107 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,1)); /* line 4179 */
} /* line 4179 */
  sim_icache_fetch(2108 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_25, (unsigned int) 16); /* line 4181 */
} /* line 4181 */
  sim_icache_fetch(2109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4183 */
} /* line 4183 */
  sim_icache_fetch(2111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4185 */
} /* line 4185 */
  sim_icache_fetch(2112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4187 */
} /* line 4187 */
  sim_icache_fetch(2114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4189 */
} /* line 4189 */
  sim_icache_fetch(2116 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 4191 */
} /* line 4191 */
  sim_icache_fetch(2117 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4193 */
  sim_icache_fetch(2118 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4195 */
} /* line 4195 */
  sim_icache_fetch(2119 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 13),0,1)); /* line 4197 */
} /* line 4197 */
  sim_icache_fetch(2120 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_24, (unsigned int) 16); /* line 4199 */
} /* line 4199 */
  sim_icache_fetch(2121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4201 */
} /* line 4201 */
  sim_icache_fetch(2123 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4203 */
} /* line 4203 */
  sim_icache_fetch(2124 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4205 */
} /* line 4205 */
  sim_icache_fetch(2126 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4207 */
} /* line 4207 */
  sim_icache_fetch(2128 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 4209 */
} /* line 4209 */
  sim_icache_fetch(2129 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4211 */
  sim_icache_fetch(2130 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4213 */
} /* line 4213 */
  sim_icache_fetch(2131 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 14),0,1)); /* line 4215 */
} /* line 4215 */
  sim_icache_fetch(2132 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) 16); /* line 4217 */
} /* line 4217 */
  sim_icache_fetch(2133 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4219 */
} /* line 4219 */
  sim_icache_fetch(2135 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4221 */
} /* line 4221 */
  sim_icache_fetch(2136 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4223 */
} /* line 4223 */
  sim_icache_fetch(2138 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4225 */
} /* line 4225 */
  sim_icache_fetch(2140 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 4227 */
} /* line 4227 */
  sim_icache_fetch(2141 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4229 */
  sim_icache_fetch(2142 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4231 */
} /* line 4231 */
  sim_icache_fetch(2143 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_4 + (unsigned int) 15),0,1)); /* line 4233 */
} /* line 4233 */
  sim_icache_fetch(2144 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_36, (unsigned int) 16); /* line 4235 */
} /* line 4235 */
  sim_icache_fetch(2145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4237 */
} /* line 4237 */
  sim_icache_fetch(2147 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_4); /* line 4239 */
} /* line 4239 */
  sim_icache_fetch(2148 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4241 */
} /* line 4241 */
  sim_icache_fetch(2150 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4243 */
} /* line 4243 */
  sim_icache_fetch(2152 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 4245 */
} /* line 4245 */
  sim_icache_fetch(2153 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4247 */
  sim_icache_fetch(2154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4249 */
} /* line 4249 */
  sim_icache_fetch(2155 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld(reg_r0_37,0,1)); /* line 4251 */
} /* line 4251 */
  sim_icache_fetch(2156 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_37, (unsigned int) 16); /* line 4253 */
} /* line 4253 */
  sim_icache_fetch(2157 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_38); /* line 4255 */
} /* line 4255 */
  sim_icache_fetch(2158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4257 */
} /* line 4257 */
  sim_icache_fetch(2160 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4259 */
} /* line 4259 */
  sim_icache_fetch(2161 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4261 */
} /* line 4261 */
  sim_icache_fetch(2163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4263 */
} /* line 4263 */
  sim_icache_fetch(2165 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 4265 */
} /* line 4265 */
  sim_icache_fetch(2166 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4267 */
  sim_icache_fetch(2167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4269 */
} /* line 4269 */
  sim_icache_fetch(2168 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 4271 */
} /* line 4271 */
  sim_icache_fetch(2169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4273 */
} /* line 4273 */
  sim_icache_fetch(2171 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4275 */
} /* line 4275 */
  sim_icache_fetch(2172 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4277 */
} /* line 4277 */
  sim_icache_fetch(2174 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4279 */
} /* line 4279 */
  sim_icache_fetch(2176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 4281 */
} /* line 4281 */
  sim_icache_fetch(2177 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4283 */
  sim_icache_fetch(2178 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4285 */
} /* line 4285 */
  sim_icache_fetch(2179 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 4287 */
} /* line 4287 */
  sim_icache_fetch(2180 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4289 */
} /* line 4289 */
  sim_icache_fetch(2182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4291 */
} /* line 4291 */
  sim_icache_fetch(2183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4293 */
} /* line 4293 */
  sim_icache_fetch(2185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4295 */
} /* line 4295 */
  sim_icache_fetch(2187 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 4297 */
} /* line 4297 */
  sim_icache_fetch(2188 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4299 */
  sim_icache_fetch(2189 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4301 */
} /* line 4301 */
  sim_icache_fetch(2190 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 4303 */
} /* line 4303 */
  sim_icache_fetch(2191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4305 */
} /* line 4305 */
  sim_icache_fetch(2193 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4307 */
} /* line 4307 */
  sim_icache_fetch(2194 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4309 */
} /* line 4309 */
  sim_icache_fetch(2196 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4311 */
} /* line 4311 */
  sim_icache_fetch(2198 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 4313 */
} /* line 4313 */
  sim_icache_fetch(2199 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4315 */
  sim_icache_fetch(2200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4317 */
} /* line 4317 */
  sim_icache_fetch(2201 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 4319 */
} /* line 4319 */
  sim_icache_fetch(2202 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4321 */
} /* line 4321 */
  sim_icache_fetch(2204 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4323 */
} /* line 4323 */
  sim_icache_fetch(2205 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4325 */
} /* line 4325 */
  sim_icache_fetch(2207 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4327 */
} /* line 4327 */
  sim_icache_fetch(2209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 4329 */
} /* line 4329 */
  sim_icache_fetch(2210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4331 */
  sim_icache_fetch(2211 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4333 */
} /* line 4333 */
  sim_icache_fetch(2212 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 4335 */
} /* line 4335 */
  sim_icache_fetch(2213 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4337 */
} /* line 4337 */
  sim_icache_fetch(2215 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4339 */
} /* line 4339 */
  sim_icache_fetch(2216 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4341 */
} /* line 4341 */
  sim_icache_fetch(2218 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4343 */
} /* line 4343 */
  sim_icache_fetch(2220 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 4345 */
} /* line 4345 */
  sim_icache_fetch(2221 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4347 */
  sim_icache_fetch(2222 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4349 */
} /* line 4349 */
  sim_icache_fetch(2223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 4351 */
} /* line 4351 */
  sim_icache_fetch(2224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4353 */
} /* line 4353 */
  sim_icache_fetch(2226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4355 */
} /* line 4355 */
  sim_icache_fetch(2227 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4357 */
} /* line 4357 */
  sim_icache_fetch(2229 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4359 */
} /* line 4359 */
  sim_icache_fetch(2231 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 4361 */
} /* line 4361 */
  sim_icache_fetch(2232 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4363 */
  sim_icache_fetch(2233 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4365 */
} /* line 4365 */
  sim_icache_fetch(2234 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 4367 */
} /* line 4367 */
  sim_icache_fetch(2235 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4369 */
} /* line 4369 */
  sim_icache_fetch(2237 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4371 */
} /* line 4371 */
  sim_icache_fetch(2238 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4373 */
} /* line 4373 */
  sim_icache_fetch(2240 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4375 */
} /* line 4375 */
  sim_icache_fetch(2242 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 4377 */
} /* line 4377 */
  sim_icache_fetch(2243 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4379 */
  sim_icache_fetch(2244 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4381 */
} /* line 4381 */
  sim_icache_fetch(2245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 4383 */
} /* line 4383 */
  sim_icache_fetch(2246 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4385 */
} /* line 4385 */
  sim_icache_fetch(2248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4387 */
} /* line 4387 */
  sim_icache_fetch(2249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4389 */
} /* line 4389 */
  sim_icache_fetch(2251 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4391 */
} /* line 4391 */
  sim_icache_fetch(2253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 4393 */
} /* line 4393 */
  sim_icache_fetch(2254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4395 */
  sim_icache_fetch(2255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4397 */
} /* line 4397 */
  sim_icache_fetch(2256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 4399 */
} /* line 4399 */
  sim_icache_fetch(2257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4401 */
} /* line 4401 */
  sim_icache_fetch(2259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4403 */
} /* line 4403 */
  sim_icache_fetch(2260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4405 */
} /* line 4405 */
  sim_icache_fetch(2262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4407 */
} /* line 4407 */
  sim_icache_fetch(2264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 4409 */
} /* line 4409 */
  sim_icache_fetch(2265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4411 */
  sim_icache_fetch(2266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4413 */
} /* line 4413 */
  sim_icache_fetch(2267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 4415 */
} /* line 4415 */
  sim_icache_fetch(2268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4417 */
} /* line 4417 */
  sim_icache_fetch(2270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4419 */
} /* line 4419 */
  sim_icache_fetch(2271 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4421 */
} /* line 4421 */
  sim_icache_fetch(2273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4423 */
} /* line 4423 */
  sim_icache_fetch(2275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 4425 */
} /* line 4425 */
  sim_icache_fetch(2276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4427 */
  sim_icache_fetch(2277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4429 */
} /* line 4429 */
  sim_icache_fetch(2278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 4431 */
} /* line 4431 */
  sim_icache_fetch(2279 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4433 */
} /* line 4433 */
  sim_icache_fetch(2281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4435 */
} /* line 4435 */
  sim_icache_fetch(2282 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4437 */
} /* line 4437 */
  sim_icache_fetch(2284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4439 */
} /* line 4439 */
  sim_icache_fetch(2286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 4441 */
} /* line 4441 */
  sim_icache_fetch(2287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4443 */
  sim_icache_fetch(2288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4445 */
} /* line 4445 */
  sim_icache_fetch(2289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 4447 */
} /* line 4447 */
  sim_icache_fetch(2290 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4449 */
} /* line 4449 */
  sim_icache_fetch(2292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4451 */
} /* line 4451 */
  sim_icache_fetch(2293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4453 */
} /* line 4453 */
  sim_icache_fetch(2295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4455 */
} /* line 4455 */
  sim_icache_fetch(2297 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 4457 */
} /* line 4457 */
  sim_icache_fetch(2298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4459 */
  sim_icache_fetch(2299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4461 */
} /* line 4461 */
  sim_icache_fetch(2300 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 4463 */
} /* line 4463 */
  sim_icache_fetch(2301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4465 */
} /* line 4465 */
  sim_icache_fetch(2303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4467 */
} /* line 4467 */
  sim_icache_fetch(2304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4469 */
} /* line 4469 */
  sim_icache_fetch(2306 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4471 */
} /* line 4471 */
  sim_icache_fetch(2308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 4473 */
} /* line 4473 */
  sim_icache_fetch(2309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4475 */
  sim_icache_fetch(2310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4477 */
} /* line 4477 */
  sim_icache_fetch(2311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 4479 */
} /* line 4479 */
  sim_icache_fetch(2312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4481 */
} /* line 4481 */
  sim_icache_fetch(2314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4483 */
} /* line 4483 */
  sim_icache_fetch(2315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4485 */
} /* line 4485 */
  sim_icache_fetch(2317 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4487 */
} /* line 4487 */
  sim_icache_fetch(2319 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 4489 */
} /* line 4489 */
  sim_icache_fetch(2320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4491 */
  sim_icache_fetch(2321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4493 */
} /* line 4493 */
  sim_icache_fetch(2322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 4495 */
} /* line 4495 */
  sim_icache_fetch(2323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4497 */
} /* line 4497 */
  sim_icache_fetch(2325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_37); /* line 4500 */
} /* line 4500 */
  sim_icache_fetch(2326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L126X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L126X3;
} /* line 4502 */
l_L127X3: ;/* line 4505 */
__LABEL(l_L127X3);
  sim_icache_fetch(2327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4506 */
} /* line 4506 */
  sim_icache_fetch(2329 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4508 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4509 */
   __ADD_CYCLES(1);
} /* line 4509 */
  sim_icache_fetch(2332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 4511 */
} /* line 4511 */
  sim_icache_fetch(2333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 4513 */
} /* line 4513 */
l_L125X3: ;/* line 4516 */
__LABEL(l_L125X3);
  sim_icache_fetch(2335 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 4517 */
} /* line 4517 */
  sim_icache_fetch(2337 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 9); /* line 4519 */
} /* line 4519 */
  sim_icache_fetch(2338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4521 */
} /* line 4521 */
  sim_icache_fetch(2339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 511); /* line 4523 */
} /* line 4523 */
  sim_icache_fetch(2341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_8419Xoffset,0,4), 0); /* line 4525 */
} /* line 4525 */
  sim_icache_fetch(2343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4527 */
  sim_icache_fetch(2344 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 4529 */
} /* line 4529 */
  sim_icache_fetch(2346 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_2); /* line 4531 */
} /* line 4531 */
  sim_icache_fetch(2348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 4534 */
} /* line 4534 */
  sim_icache_fetch(2350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L124X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L124X3;
} /* line 4536 */
l_L128X3: ;/* line 4539 */
__LABEL(l_L128X3);
  sim_icache_fetch(2351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4540 */
} /* line 4540 */
  sim_icache_fetch(2353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 4542 */
} /* line 4542 */
  sim_icache_fetch(2355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 4544 */
} /* line 4544 */
  sim_icache_fetch(2356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 4546 */
} /* line 4546 */
  sim_icache_fetch(2357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 4548 */
} /* line 4548 */
  sim_icache_fetch(2359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 4550 */
} /* line 4550 */
  sim_icache_fetch(2361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4552 */
  sim_icache_fetch(2362 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 4555 */
} /* line 4555 */
  sim_icache_fetch(2364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L124X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L124X3;
} /* line 4557 */
l_L129X3: ;/* line 4560 */
__LABEL(l_L129X3);
  sim_icache_fetch(2365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 4561 */
} /* line 4561 */
  sim_icache_fetch(2367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 4563 */
} /* line 4563 */
  sim_icache_fetch(2368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 4565 */
} /* line 4565 */
  sim_icache_fetch(2369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 4567 */
} /* line 4567 */
  sim_icache_fetch(2370 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 4570 */
} /* line 4570 */
  sim_icache_fetch(2372 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L124X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L124X3;
} /* line 4572 */
l_L119X3: ;/* line 4575 */
__LABEL(l_L119X3);
  sim_icache_fetch(2373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) compress_8419Xbuf); /* line 4577 */
} /* line 4577 */
  sim_icache_fetch(2375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L120X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L120X3;
} /* line 4579 */
l_L117X3: ;/* line 4582 */
__LABEL(l_L117X3);
  sim_icache_fetch(2376 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_5, 0); /* line 4584 */
} /* line 4584 */
  sim_icache_fetch(2377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L118X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L118X3;
} /* line 4586 */
l_L116X3: ;/* line 4589 */
__LABEL(l_L116X3);
  sim_icache_fetch(2378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4590 */
} /* line 4590 */
  sim_icache_fetch(2380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4592 */
} /* line 4592 */
  sim_icache_fetch(2382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4594 */
} /* line 4594 */
  sim_icache_fetch(2383 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4596 */
} /* line 4596 */
  sim_icache_fetch(2384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4598 */
} /* line 4598 */
  sim_icache_fetch(2385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4600 */
} /* line 4600 */
  sim_icache_fetch(2386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 4602 */
} /* line 4602 */
  sim_icache_fetch(2387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 4604 */
} /* line 4604 */
  sim_icache_fetch(2388 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4606 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4607 */
   __ADD_CYCLES(1);
} /* line 4607 */
  sim_icache_fetch(2391 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 4609 */
} /* line 4609 */
  sim_icache_fetch(2392 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4611 */
l_L131X3: ;/* line 4613 */
__LABEL(l_L131X3);
  sim_icache_fetch(2393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 4614 */
} /* line 4614 */
  sim_icache_fetch(2395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_8419Xoffset,0,4), 0); /* line 4616 */
} /* line 4616 */
l_L124X3: ;/* line 4618 */
__LABEL(l_L124X3);
  sim_icache_fetch(2397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4620 */
l_L130X3: ;/* line 4623 */
__LABEL(l_L130X3);
  sim_icache_fetch(2398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_19, (unsigned int) 15); /* line 4624 */
} /* line 4624 */
  sim_icache_fetch(2399 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, (unsigned int) 14); /* line 4626 */
} /* line 4626 */
  sim_icache_fetch(2400 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_17, (unsigned int) 13); /* line 4628 */
} /* line 4628 */
  sim_icache_fetch(2401 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, (unsigned int) 12); /* line 4630 */
} /* line 4630 */
  sim_icache_fetch(2402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_15, (unsigned int) 11); /* line 4632 */
} /* line 4632 */
  sim_icache_fetch(2403 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_14, (unsigned int) 10); /* line 4634 */
} /* line 4634 */
  sim_icache_fetch(2404 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_13, (unsigned int) 9); /* line 4636 */
} /* line 4636 */
  sim_icache_fetch(2405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, (unsigned int) 8); /* line 4638 */
} /* line 4638 */
  sim_icache_fetch(2406 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_11, (unsigned int) 7); /* line 4640 */
} /* line 4640 */
  sim_icache_fetch(2407 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_10, (unsigned int) 6); /* line 4642 */
} /* line 4642 */
  sim_icache_fetch(2408 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, (unsigned int) 5); /* line 4644 */
} /* line 4644 */
  sim_icache_fetch(2409 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) 4); /* line 4646 */
} /* line 4646 */
  sim_icache_fetch(2410 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, (unsigned int) 3); /* line 4648 */
} /* line 4648 */
  sim_icache_fetch(2411 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) 2); /* line 4650 */
} /* line 4650 */
  sim_icache_fetch(2412 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 1); /* line 4652 */
} /* line 4652 */
  sim_icache_fetch(2413 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) compress_8419Xbuf); /* line 4654 */
} /* line 4654 */
  sim_icache_fetch(2415 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 4656 */
} /* line 4656 */
l_L132X3: ;/* line 4659 */
__LABEL(l_L132X3);
  sim_icache_fetch(2416 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4660 */
} /* line 4660 */
  sim_icache_fetch(2418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4662 */
} /* line 4662 */
  sim_icache_fetch(2420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4664 */
} /* line 4664 */
  sim_icache_fetch(2421 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4666 */
} /* line 4666 */
  sim_icache_fetch(2422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4668 */
} /* line 4668 */
  sim_icache_fetch(2423 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4670 */
} /* line 4670 */
  sim_icache_fetch(2424 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4672 */
} /* line 4672 */
  sim_icache_fetch(2425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_21); /* line 4674 */
} /* line 4674 */
  sim_icache_fetch(2426 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4676 */
  sim_icache_fetch(2427 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4678 */
} /* line 4678 */
  sim_icache_fetch(2428 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld(reg_r0_4,0,1)); /* line 4680 */
} /* line 4680 */
  sim_icache_fetch(2429 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 4682 */
} /* line 4682 */
  sim_icache_fetch(2430 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4684 */
} /* line 4684 */
  sim_icache_fetch(2432 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4686 */
} /* line 4686 */
  sim_icache_fetch(2433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4688 */
} /* line 4688 */
  sim_icache_fetch(2435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4690 */
} /* line 4690 */
  sim_icache_fetch(2437 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4692 */
} /* line 4692 */
  sim_icache_fetch(2438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4694 */
} /* line 4694 */
  sim_icache_fetch(2439 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4696 */
} /* line 4696 */
  sim_icache_fetch(2440 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4698 */
} /* line 4698 */
  sim_icache_fetch(2441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4700 */
} /* line 4700 */
  sim_icache_fetch(2442 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_5, reg_r0_21); /* line 4702 */
} /* line 4702 */
  sim_icache_fetch(2443 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4704 */
  sim_icache_fetch(2444 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4706 */
} /* line 4706 */
  sim_icache_fetch(2445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 1),0,1)); /* line 4708 */
} /* line 4708 */
  sim_icache_fetch(2446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4710 */
} /* line 4710 */
  sim_icache_fetch(2447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4712 */
} /* line 4712 */
  sim_icache_fetch(2449 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4714 */
} /* line 4714 */
  sim_icache_fetch(2450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4716 */
} /* line 4716 */
  sim_icache_fetch(2452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4718 */
} /* line 4718 */
  sim_icache_fetch(2454 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4720 */
} /* line 4720 */
  sim_icache_fetch(2455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4722 */
} /* line 4722 */
  sim_icache_fetch(2456 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4724 */
} /* line 4724 */
  sim_icache_fetch(2457 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4726 */
} /* line 4726 */
  sim_icache_fetch(2458 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4728 */
} /* line 4728 */
  sim_icache_fetch(2459 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_6, reg_r0_21); /* line 4730 */
} /* line 4730 */
  sim_icache_fetch(2460 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4732 */
  sim_icache_fetch(2461 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4734 */
} /* line 4734 */
  sim_icache_fetch(2462 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 2),0,1)); /* line 4736 */
} /* line 4736 */
  sim_icache_fetch(2463 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 4738 */
} /* line 4738 */
  sim_icache_fetch(2464 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4740 */
} /* line 4740 */
  sim_icache_fetch(2466 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4742 */
} /* line 4742 */
  sim_icache_fetch(2467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4744 */
} /* line 4744 */
  sim_icache_fetch(2469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4746 */
} /* line 4746 */
  sim_icache_fetch(2471 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4748 */
} /* line 4748 */
  sim_icache_fetch(2472 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4750 */
} /* line 4750 */
  sim_icache_fetch(2473 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4752 */
} /* line 4752 */
  sim_icache_fetch(2474 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4754 */
} /* line 4754 */
  sim_icache_fetch(2475 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4756 */
} /* line 4756 */
  sim_icache_fetch(2476 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_21); /* line 4758 */
} /* line 4758 */
  sim_icache_fetch(2477 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4760 */
  sim_icache_fetch(2478 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4762 */
} /* line 4762 */
  sim_icache_fetch(2479 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 3),0,1)); /* line 4764 */
} /* line 4764 */
  sim_icache_fetch(2480 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 4766 */
} /* line 4766 */
  sim_icache_fetch(2481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4768 */
} /* line 4768 */
  sim_icache_fetch(2483 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4770 */
} /* line 4770 */
  sim_icache_fetch(2484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4772 */
} /* line 4772 */
  sim_icache_fetch(2486 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4774 */
} /* line 4774 */
  sim_icache_fetch(2488 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4776 */
} /* line 4776 */
  sim_icache_fetch(2489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4778 */
} /* line 4778 */
  sim_icache_fetch(2490 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4780 */
} /* line 4780 */
  sim_icache_fetch(2491 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4782 */
} /* line 4782 */
  sim_icache_fetch(2492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4784 */
} /* line 4784 */
  sim_icache_fetch(2493 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_21); /* line 4786 */
} /* line 4786 */
  sim_icache_fetch(2494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4788 */
  sim_icache_fetch(2495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4790 */
} /* line 4790 */
  sim_icache_fetch(2496 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,1)); /* line 4792 */
} /* line 4792 */
  sim_icache_fetch(2497 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 4794 */
} /* line 4794 */
  sim_icache_fetch(2498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4796 */
} /* line 4796 */
  sim_icache_fetch(2500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4798 */
} /* line 4798 */
  sim_icache_fetch(2501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4800 */
} /* line 4800 */
  sim_icache_fetch(2503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4802 */
} /* line 4802 */
  sim_icache_fetch(2505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4804 */
} /* line 4804 */
  sim_icache_fetch(2506 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4806 */
} /* line 4806 */
  sim_icache_fetch(2507 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4808 */
} /* line 4808 */
  sim_icache_fetch(2508 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4810 */
} /* line 4810 */
  sim_icache_fetch(2509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4812 */
} /* line 4812 */
  sim_icache_fetch(2510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_21); /* line 4814 */
} /* line 4814 */
  sim_icache_fetch(2511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4816 */
  sim_icache_fetch(2512 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4818 */
} /* line 4818 */
  sim_icache_fetch(2513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 5),0,1)); /* line 4820 */
} /* line 4820 */
  sim_icache_fetch(2514 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 4822 */
} /* line 4822 */
  sim_icache_fetch(2515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4824 */
} /* line 4824 */
  sim_icache_fetch(2517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4826 */
} /* line 4826 */
  sim_icache_fetch(2518 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4828 */
} /* line 4828 */
  sim_icache_fetch(2520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4830 */
} /* line 4830 */
  sim_icache_fetch(2522 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4832 */
} /* line 4832 */
  sim_icache_fetch(2523 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4834 */
} /* line 4834 */
  sim_icache_fetch(2524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4836 */
} /* line 4836 */
  sim_icache_fetch(2525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4838 */
} /* line 4838 */
  sim_icache_fetch(2526 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4840 */
} /* line 4840 */
  sim_icache_fetch(2527 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_21); /* line 4842 */
} /* line 4842 */
  sim_icache_fetch(2528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4844 */
  sim_icache_fetch(2529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4846 */
} /* line 4846 */
  sim_icache_fetch(2530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 6),0,1)); /* line 4848 */
} /* line 4848 */
  sim_icache_fetch(2531 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 4850 */
} /* line 4850 */
  sim_icache_fetch(2532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4852 */
} /* line 4852 */
  sim_icache_fetch(2534 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4854 */
} /* line 4854 */
  sim_icache_fetch(2535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4856 */
} /* line 4856 */
  sim_icache_fetch(2537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4858 */
} /* line 4858 */
  sim_icache_fetch(2539 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4860 */
} /* line 4860 */
  sim_icache_fetch(2540 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4862 */
} /* line 4862 */
  sim_icache_fetch(2541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4864 */
} /* line 4864 */
  sim_icache_fetch(2542 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4866 */
} /* line 4866 */
  sim_icache_fetch(2543 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4868 */
} /* line 4868 */
  sim_icache_fetch(2544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_21); /* line 4870 */
} /* line 4870 */
  sim_icache_fetch(2545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4872 */
  sim_icache_fetch(2546 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4874 */
} /* line 4874 */
  sim_icache_fetch(2547 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 7),0,1)); /* line 4876 */
} /* line 4876 */
  sim_icache_fetch(2548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 4878 */
} /* line 4878 */
  sim_icache_fetch(2549 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4880 */
} /* line 4880 */
  sim_icache_fetch(2551 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4882 */
} /* line 4882 */
  sim_icache_fetch(2552 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4884 */
} /* line 4884 */
  sim_icache_fetch(2554 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4886 */
} /* line 4886 */
  sim_icache_fetch(2556 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4888 */
} /* line 4888 */
  sim_icache_fetch(2557 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4890 */
} /* line 4890 */
  sim_icache_fetch(2558 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4892 */
} /* line 4892 */
  sim_icache_fetch(2559 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4894 */
} /* line 4894 */
  sim_icache_fetch(2560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4896 */
} /* line 4896 */
  sim_icache_fetch(2561 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_21); /* line 4898 */
} /* line 4898 */
  sim_icache_fetch(2562 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4900 */
  sim_icache_fetch(2563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4902 */
} /* line 4902 */
  sim_icache_fetch(2564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,1)); /* line 4904 */
} /* line 4904 */
  sim_icache_fetch(2565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 4906 */
} /* line 4906 */
  sim_icache_fetch(2566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4908 */
} /* line 4908 */
  sim_icache_fetch(2568 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4910 */
} /* line 4910 */
  sim_icache_fetch(2569 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4912 */
} /* line 4912 */
  sim_icache_fetch(2571 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4914 */
} /* line 4914 */
  sim_icache_fetch(2573 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4916 */
} /* line 4916 */
  sim_icache_fetch(2574 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4918 */
} /* line 4918 */
  sim_icache_fetch(2575 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4920 */
} /* line 4920 */
  sim_icache_fetch(2576 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4922 */
} /* line 4922 */
  sim_icache_fetch(2577 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4924 */
} /* line 4924 */
  sim_icache_fetch(2578 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_21); /* line 4926 */
} /* line 4926 */
  sim_icache_fetch(2579 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4928 */
  sim_icache_fetch(2580 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4930 */
} /* line 4930 */
  sim_icache_fetch(2581 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 9),0,1)); /* line 4932 */
} /* line 4932 */
  sim_icache_fetch(2582 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4934 */
} /* line 4934 */
  sim_icache_fetch(2583 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4936 */
} /* line 4936 */
  sim_icache_fetch(2585 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4938 */
} /* line 4938 */
  sim_icache_fetch(2586 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4940 */
} /* line 4940 */
  sim_icache_fetch(2588 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4942 */
} /* line 4942 */
  sim_icache_fetch(2590 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4944 */
} /* line 4944 */
  sim_icache_fetch(2591 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4946 */
} /* line 4946 */
  sim_icache_fetch(2592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4948 */
} /* line 4948 */
  sim_icache_fetch(2593 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4950 */
} /* line 4950 */
  sim_icache_fetch(2594 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4952 */
} /* line 4952 */
  sim_icache_fetch(2595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_21); /* line 4954 */
} /* line 4954 */
  sim_icache_fetch(2596 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4956 */
  sim_icache_fetch(2597 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4958 */
} /* line 4958 */
  sim_icache_fetch(2598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 10),0,1)); /* line 4960 */
} /* line 4960 */
  sim_icache_fetch(2599 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4962 */
} /* line 4962 */
  sim_icache_fetch(2600 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4964 */
} /* line 4964 */
  sim_icache_fetch(2602 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4966 */
} /* line 4966 */
  sim_icache_fetch(2603 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4968 */
} /* line 4968 */
  sim_icache_fetch(2605 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4970 */
} /* line 4970 */
  sim_icache_fetch(2607 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4972 */
} /* line 4972 */
  sim_icache_fetch(2608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4974 */
} /* line 4974 */
  sim_icache_fetch(2609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 4976 */
} /* line 4976 */
  sim_icache_fetch(2610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 4978 */
} /* line 4978 */
  sim_icache_fetch(2611 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 4980 */
} /* line 4980 */
  sim_icache_fetch(2612 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_21); /* line 4982 */
} /* line 4982 */
  sim_icache_fetch(2613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4984 */
  sim_icache_fetch(2614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 4986 */
} /* line 4986 */
  sim_icache_fetch(2615 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 11),0,1)); /* line 4988 */
} /* line 4988 */
  sim_icache_fetch(2616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4990 */
} /* line 4990 */
  sim_icache_fetch(2617 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4992 */
} /* line 4992 */
  sim_icache_fetch(2619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 4994 */
} /* line 4994 */
  sim_icache_fetch(2620 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 4996 */
} /* line 4996 */
  sim_icache_fetch(2622 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4998 */
} /* line 4998 */
  sim_icache_fetch(2624 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5000 */
} /* line 5000 */
  sim_icache_fetch(2625 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5002 */
} /* line 5002 */
  sim_icache_fetch(2626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 5004 */
} /* line 5004 */
  sim_icache_fetch(2627 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 5006 */
} /* line 5006 */
  sim_icache_fetch(2628 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 5008 */
} /* line 5008 */
  sim_icache_fetch(2629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_21); /* line 5010 */
} /* line 5010 */
  sim_icache_fetch(2630 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5012 */
  sim_icache_fetch(2631 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 5014 */
} /* line 5014 */
  sim_icache_fetch(2632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,1)); /* line 5016 */
} /* line 5016 */
  sim_icache_fetch(2633 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 5018 */
} /* line 5018 */
  sim_icache_fetch(2634 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 5020 */
} /* line 5020 */
  sim_icache_fetch(2636 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 5022 */
} /* line 5022 */
  sim_icache_fetch(2637 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5024 */
} /* line 5024 */
  sim_icache_fetch(2639 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5026 */
} /* line 5026 */
  sim_icache_fetch(2641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5028 */
} /* line 5028 */
  sim_icache_fetch(2642 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5030 */
} /* line 5030 */
  sim_icache_fetch(2643 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 5032 */
} /* line 5032 */
  sim_icache_fetch(2644 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 5034 */
} /* line 5034 */
  sim_icache_fetch(2645 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 5036 */
} /* line 5036 */
  sim_icache_fetch(2646 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_21); /* line 5038 */
} /* line 5038 */
  sim_icache_fetch(2647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5040 */
  sim_icache_fetch(2648 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 5042 */
} /* line 5042 */
  sim_icache_fetch(2649 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 13),0,1)); /* line 5044 */
} /* line 5044 */
  sim_icache_fetch(2650 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 5046 */
} /* line 5046 */
  sim_icache_fetch(2651 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 5048 */
} /* line 5048 */
  sim_icache_fetch(2653 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 5050 */
} /* line 5050 */
  sim_icache_fetch(2654 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5052 */
} /* line 5052 */
  sim_icache_fetch(2656 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5054 */
} /* line 5054 */
  sim_icache_fetch(2658 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5056 */
} /* line 5056 */
  sim_icache_fetch(2659 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5058 */
} /* line 5058 */
  sim_icache_fetch(2660 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 5060 */
} /* line 5060 */
  sim_icache_fetch(2661 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 5062 */
} /* line 5062 */
  sim_icache_fetch(2662 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 5064 */
} /* line 5064 */
  sim_icache_fetch(2663 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_21); /* line 5066 */
} /* line 5066 */
  sim_icache_fetch(2664 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5068 */
  sim_icache_fetch(2665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 5070 */
} /* line 5070 */
  sim_icache_fetch(2666 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 14),0,1)); /* line 5072 */
} /* line 5072 */
  sim_icache_fetch(2667 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 5074 */
} /* line 5074 */
  sim_icache_fetch(2668 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 5076 */
} /* line 5076 */
  sim_icache_fetch(2670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 5078 */
} /* line 5078 */
  sim_icache_fetch(2671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5080 */
} /* line 5080 */
  sim_icache_fetch(2673 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_20, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5082 */
} /* line 5082 */
  sim_icache_fetch(2675 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5084 */
} /* line 5084 */
  sim_icache_fetch(2676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5086 */
} /* line 5086 */
  sim_icache_fetch(2677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 7); /* line 5088 */
} /* line 5088 */
  sim_icache_fetch(2678 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_2); /* line 5090 */
} /* line 5090 */
  sim_icache_fetch(2679 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 3); /* line 5092 */
} /* line 5092 */
  sim_icache_fetch(2680 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_21); /* line 5094 */
} /* line 5094 */
  sim_icache_fetch(2681 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5096 */
  sim_icache_fetch(2682 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_20, (unsigned int) 1); /* line 5098 */
} /* line 5098 */
  sim_icache_fetch(2683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_21, mem_trace_ld((reg_r0_4 + (unsigned int) 15),0,1)); /* line 5100 */
} /* line 5100 */
  sim_icache_fetch(2684 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 5102 */
} /* line 5102 */
  sim_icache_fetch(2685 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 5104 */
} /* line 5104 */
  sim_icache_fetch(2686 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 5106 */
} /* line 5106 */
  sim_icache_fetch(2688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_20,0,1), reg_r0_21); /* line 5109 */
} /* line 5109 */
  sim_icache_fetch(2689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L132X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L132X3;
} /* line 5111 */
l_L148X3: ;/* line 5114 */
__LABEL(l_L148X3);
  sim_icache_fetch(2690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5115 */
} /* line 5115 */
  sim_icache_fetch(2692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5117 */
} /* line 5117 */
  sim_icache_fetch(2694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5119 */
} /* line 5119 */
  sim_icache_fetch(2695 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5121 */
} /* line 5121 */
  sim_icache_fetch(2696 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5123 */
} /* line 5123 */
  sim_icache_fetch(2697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5125 */
} /* line 5125 */
  sim_icache_fetch(2698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5127 */
} /* line 5127 */
  sim_icache_fetch(2699 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5130 */
} /* line 5130 */
  sim_icache_fetch(2700 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5132 */
l_L147X3: ;/* line 5135 */
__LABEL(l_L147X3);
  sim_icache_fetch(2701 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5136 */
} /* line 5136 */
  sim_icache_fetch(2703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5138 */
} /* line 5138 */
  sim_icache_fetch(2705 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5140 */
} /* line 5140 */
  sim_icache_fetch(2706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5142 */
} /* line 5142 */
  sim_icache_fetch(2707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5144 */
} /* line 5144 */
  sim_icache_fetch(2708 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5146 */
} /* line 5146 */
  sim_icache_fetch(2709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5148 */
} /* line 5148 */
  sim_icache_fetch(2710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5151 */
} /* line 5151 */
  sim_icache_fetch(2711 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5153 */
l_L146X3: ;/* line 5156 */
__LABEL(l_L146X3);
  sim_icache_fetch(2712 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5157 */
} /* line 5157 */
  sim_icache_fetch(2714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5159 */
} /* line 5159 */
  sim_icache_fetch(2716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5161 */
} /* line 5161 */
  sim_icache_fetch(2717 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5163 */
} /* line 5163 */
  sim_icache_fetch(2718 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5165 */
} /* line 5165 */
  sim_icache_fetch(2719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5167 */
} /* line 5167 */
  sim_icache_fetch(2720 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5169 */
} /* line 5169 */
  sim_icache_fetch(2721 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5172 */
} /* line 5172 */
  sim_icache_fetch(2722 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5174 */
l_L145X3: ;/* line 5177 */
__LABEL(l_L145X3);
  sim_icache_fetch(2723 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5178 */
} /* line 5178 */
  sim_icache_fetch(2725 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5180 */
} /* line 5180 */
  sim_icache_fetch(2727 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5182 */
} /* line 5182 */
  sim_icache_fetch(2728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5184 */
} /* line 5184 */
  sim_icache_fetch(2729 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5186 */
} /* line 5186 */
  sim_icache_fetch(2730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5188 */
} /* line 5188 */
  sim_icache_fetch(2731 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5190 */
} /* line 5190 */
  sim_icache_fetch(2732 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5193 */
} /* line 5193 */
  sim_icache_fetch(2733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5195 */
l_L144X3: ;/* line 5198 */
__LABEL(l_L144X3);
  sim_icache_fetch(2734 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5199 */
} /* line 5199 */
  sim_icache_fetch(2736 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5201 */
} /* line 5201 */
  sim_icache_fetch(2738 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5203 */
} /* line 5203 */
  sim_icache_fetch(2739 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5205 */
} /* line 5205 */
  sim_icache_fetch(2740 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5207 */
} /* line 5207 */
  sim_icache_fetch(2741 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5209 */
} /* line 5209 */
  sim_icache_fetch(2742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5211 */
} /* line 5211 */
  sim_icache_fetch(2743 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5214 */
} /* line 5214 */
  sim_icache_fetch(2744 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5216 */
l_L143X3: ;/* line 5219 */
__LABEL(l_L143X3);
  sim_icache_fetch(2745 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5220 */
} /* line 5220 */
  sim_icache_fetch(2747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5222 */
} /* line 5222 */
  sim_icache_fetch(2749 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5224 */
} /* line 5224 */
  sim_icache_fetch(2750 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5226 */
} /* line 5226 */
  sim_icache_fetch(2751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5228 */
} /* line 5228 */
  sim_icache_fetch(2752 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5230 */
} /* line 5230 */
  sim_icache_fetch(2753 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5232 */
} /* line 5232 */
  sim_icache_fetch(2754 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5235 */
} /* line 5235 */
  sim_icache_fetch(2755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5237 */
l_L142X3: ;/* line 5240 */
__LABEL(l_L142X3);
  sim_icache_fetch(2756 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5241 */
} /* line 5241 */
  sim_icache_fetch(2758 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5243 */
} /* line 5243 */
  sim_icache_fetch(2760 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5245 */
} /* line 5245 */
  sim_icache_fetch(2761 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5247 */
} /* line 5247 */
  sim_icache_fetch(2762 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5249 */
} /* line 5249 */
  sim_icache_fetch(2763 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5251 */
} /* line 5251 */
  sim_icache_fetch(2764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5253 */
} /* line 5253 */
  sim_icache_fetch(2765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5256 */
} /* line 5256 */
  sim_icache_fetch(2766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5258 */
l_L141X3: ;/* line 5261 */
__LABEL(l_L141X3);
  sim_icache_fetch(2767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5262 */
} /* line 5262 */
  sim_icache_fetch(2769 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5264 */
} /* line 5264 */
  sim_icache_fetch(2771 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5266 */
} /* line 5266 */
  sim_icache_fetch(2772 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5268 */
} /* line 5268 */
  sim_icache_fetch(2773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5270 */
} /* line 5270 */
  sim_icache_fetch(2774 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5272 */
} /* line 5272 */
  sim_icache_fetch(2775 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5274 */
} /* line 5274 */
  sim_icache_fetch(2776 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5277 */
} /* line 5277 */
  sim_icache_fetch(2777 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5279 */
l_L140X3: ;/* line 5282 */
__LABEL(l_L140X3);
  sim_icache_fetch(2778 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5283 */
} /* line 5283 */
  sim_icache_fetch(2780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5285 */
} /* line 5285 */
  sim_icache_fetch(2782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5287 */
} /* line 5287 */
  sim_icache_fetch(2783 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5289 */
} /* line 5289 */
  sim_icache_fetch(2784 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5291 */
} /* line 5291 */
  sim_icache_fetch(2785 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5293 */
} /* line 5293 */
  sim_icache_fetch(2786 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5295 */
} /* line 5295 */
  sim_icache_fetch(2787 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5298 */
} /* line 5298 */
  sim_icache_fetch(2788 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5300 */
l_L139X3: ;/* line 5303 */
__LABEL(l_L139X3);
  sim_icache_fetch(2789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5304 */
} /* line 5304 */
  sim_icache_fetch(2791 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5306 */
} /* line 5306 */
  sim_icache_fetch(2793 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5308 */
} /* line 5308 */
  sim_icache_fetch(2794 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5310 */
} /* line 5310 */
  sim_icache_fetch(2795 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5312 */
} /* line 5312 */
  sim_icache_fetch(2796 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5314 */
} /* line 5314 */
  sim_icache_fetch(2797 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5316 */
} /* line 5316 */
  sim_icache_fetch(2798 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5319 */
} /* line 5319 */
  sim_icache_fetch(2799 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5321 */
l_L138X3: ;/* line 5324 */
__LABEL(l_L138X3);
  sim_icache_fetch(2800 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5325 */
} /* line 5325 */
  sim_icache_fetch(2802 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5327 */
} /* line 5327 */
  sim_icache_fetch(2804 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5329 */
} /* line 5329 */
  sim_icache_fetch(2805 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5331 */
} /* line 5331 */
  sim_icache_fetch(2806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5333 */
} /* line 5333 */
  sim_icache_fetch(2807 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5335 */
} /* line 5335 */
  sim_icache_fetch(2808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5337 */
} /* line 5337 */
  sim_icache_fetch(2809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5340 */
} /* line 5340 */
  sim_icache_fetch(2810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5342 */
l_L137X3: ;/* line 5345 */
__LABEL(l_L137X3);
  sim_icache_fetch(2811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5346 */
} /* line 5346 */
  sim_icache_fetch(2813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5348 */
} /* line 5348 */
  sim_icache_fetch(2815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5350 */
} /* line 5350 */
  sim_icache_fetch(2816 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5352 */
} /* line 5352 */
  sim_icache_fetch(2817 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5354 */
} /* line 5354 */
  sim_icache_fetch(2818 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5356 */
} /* line 5356 */
  sim_icache_fetch(2819 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5358 */
} /* line 5358 */
  sim_icache_fetch(2820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5361 */
} /* line 5361 */
  sim_icache_fetch(2821 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5363 */
l_L136X3: ;/* line 5366 */
__LABEL(l_L136X3);
  sim_icache_fetch(2822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5367 */
} /* line 5367 */
  sim_icache_fetch(2824 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5369 */
} /* line 5369 */
  sim_icache_fetch(2826 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5371 */
} /* line 5371 */
  sim_icache_fetch(2827 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5373 */
} /* line 5373 */
  sim_icache_fetch(2828 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5375 */
} /* line 5375 */
  sim_icache_fetch(2829 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5377 */
} /* line 5377 */
  sim_icache_fetch(2830 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5379 */
} /* line 5379 */
  sim_icache_fetch(2831 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5382 */
} /* line 5382 */
  sim_icache_fetch(2832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5384 */
l_L135X3: ;/* line 5387 */
__LABEL(l_L135X3);
  sim_icache_fetch(2833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5388 */
} /* line 5388 */
  sim_icache_fetch(2835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5390 */
} /* line 5390 */
  sim_icache_fetch(2837 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5392 */
} /* line 5392 */
  sim_icache_fetch(2838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5394 */
} /* line 5394 */
  sim_icache_fetch(2839 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5396 */
} /* line 5396 */
  sim_icache_fetch(2840 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5398 */
} /* line 5398 */
  sim_icache_fetch(2841 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5400 */
} /* line 5400 */
  sim_icache_fetch(2842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5403 */
} /* line 5403 */
  sim_icache_fetch(2843 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5405 */
l_L134X3: ;/* line 5408 */
__LABEL(l_L134X3);
  sim_icache_fetch(2844 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5409 */
} /* line 5409 */
  sim_icache_fetch(2846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5411 */
} /* line 5411 */
  sim_icache_fetch(2848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5413 */
} /* line 5413 */
  sim_icache_fetch(2849 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5415 */
} /* line 5415 */
  sim_icache_fetch(2850 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5417 */
} /* line 5417 */
  sim_icache_fetch(2851 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5419 */
} /* line 5419 */
  sim_icache_fetch(2852 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5421 */
} /* line 5421 */
  sim_icache_fetch(2853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5424 */
} /* line 5424 */
  sim_icache_fetch(2854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5426 */
l_L133X3: ;/* line 5429 */
__LABEL(l_L133X3);
  sim_icache_fetch(2855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8419Xoffset,0,4)); /* line 5430 */
} /* line 5430 */
  sim_icache_fetch(2857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 5432 */
} /* line 5432 */
  sim_icache_fetch(2859 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 5434 */
} /* line 5434 */
  sim_icache_fetch(2860 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 5436 */
} /* line 5436 */
  sim_icache_fetch(2861 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 5438 */
} /* line 5438 */
  sim_icache_fetch(2862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 5440 */
} /* line 5440 */
  sim_icache_fetch(2863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5442 */
} /* line 5442 */
  sim_icache_fetch(2864 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, reg_r0_5); /* line 5445 */
} /* line 5445 */
  sim_icache_fetch(2865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L131X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L131X3;
} /* line 5447 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 271: goto l_L118X3;
    case 272: goto l_L120X3;
    case 273: goto l_L122X3;
    case 274: goto l_L123X3;
    case 275: goto l_L121X3;
    case 276: goto l_L126X3;
    case 277: goto l_L127X3;
    case 278: goto l_L125X3;
    case 279: goto l_L128X3;
    case 280: goto l_L129X3;
    case 281: goto l_L119X3;
    case 282: goto l_L117X3;
    case 283: goto l_L116X3;
    case 284: goto l_L131X3;
    case 285: goto l_L124X3;
    case 286: goto l_L130X3;
    case 287: goto l_L132X3;
    case 288: goto l_L148X3;
    case 289: goto l_L147X3;
    case 290: goto l_L146X3;
    case 291: goto l_L145X3;
    case 292: goto l_L144X3;
    case 293: goto l_L143X3;
    case 294: goto l_L142X3;
    case 295: goto l_L141X3;
    case 296: goto l_L140X3;
    case 297: goto l_L139X3;
    case 298: goto l_L138X3;
    case 299: goto l_L137X3;
    case 300: goto l_L136X3;
    case 301: goto l_L135X3;
    case 302: goto l_L134X3;
    case 303: goto l_L133X3;
    case 304:
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
  reg_l0_0 = (358 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(2866 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 5463 */
} /* line 5463 */
  sim_icache_fetch(2867 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 5465 */
} /* line 5465 */
  sim_icache_fetch(2868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_20, (unsigned int) 9); /* line 5467 */
} /* line 5467 */
  sim_icache_fetch(2869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_21, (unsigned int) 511); /* line 5469 */
} /* line 5469 */
  sim_icache_fetch(2871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_19, (unsigned int) 240); /* line 5471 */
} /* line 5471 */
  sim_icache_fetch(2872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, (unsigned int) 241); /* line 5473 */
} /* line 5473 */
  sim_icache_fetch(2873 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_17, (unsigned int) 242); /* line 5475 */
} /* line 5475 */
  sim_icache_fetch(2874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, (unsigned int) 243); /* line 5477 */
} /* line 5477 */
  sim_icache_fetch(2875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_15, (unsigned int) 244); /* line 5479 */
} /* line 5479 */
  sim_icache_fetch(2876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_14, (unsigned int) 245); /* line 5481 */
} /* line 5481 */
  sim_icache_fetch(2877 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_13, (unsigned int) 246); /* line 5483 */
} /* line 5483 */
  sim_icache_fetch(2878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, (unsigned int) 247); /* line 5485 */
} /* line 5485 */
  sim_icache_fetch(2879 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_11, (unsigned int) 248); /* line 5487 */
} /* line 5487 */
  sim_icache_fetch(2880 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_10, (unsigned int) 249); /* line 5489 */
} /* line 5489 */
  sim_icache_fetch(2881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, (unsigned int) 250); /* line 5491 */
} /* line 5491 */
  sim_icache_fetch(2882 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) 251); /* line 5493 */
} /* line 5493 */
  sim_icache_fetch(2883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, (unsigned int) 252); /* line 5495 */
} /* line 5495 */
  sim_icache_fetch(2884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) 253); /* line 5497 */
} /* line 5497 */
  sim_icache_fetch(2885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 254); /* line 5499 */
} /* line 5499 */
  sim_icache_fetch(2886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 5501 */
} /* line 5501 */
  sim_icache_fetch(2888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 5503 */
} /* line 5503 */
  sim_icache_fetch(2890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 255); /* line 5505 */
} /* line 5505 */
  sim_icache_fetch(2891 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_38, reg_l0_0); /* line 5507 */
} /* line 5507 */
  sim_icache_fetch(2892 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 5509 */
} /* line 5509 */
  sim_icache_fetch(2894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 5511 */
} /* line 5511 */
l_L149X3: ;/* line 5514 */
__LABEL(l_L149X3);
  sim_icache_fetch(2896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 5515 */
} /* line 5515 */
  sim_icache_fetch(2897 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5517 */
  sim_icache_fetch(2898 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 5519 */
} /* line 5519 */
  sim_icache_fetch(2899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 5521 */
} /* line 5521 */
  sim_icache_fetch(2900 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 5523 */
} /* line 5523 */
  sim_icache_fetch(2901 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 5525 */
} /* line 5525 */
  sim_icache_fetch(2902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 5527 */
} /* line 5527 */
  sim_icache_fetch(2903 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 5529 */
} /* line 5529 */
  sim_icache_fetch(2904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 5531 */
} /* line 5531 */
  sim_icache_fetch(2905 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 5533 */
} /* line 5533 */
  sim_icache_fetch(2906 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 5535 */
} /* line 5535 */
  sim_icache_fetch(2907 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 5537 */
} /* line 5537 */
  sim_icache_fetch(2908 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 5539 */
} /* line 5539 */
  sim_icache_fetch(2909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 5541 */
} /* line 5541 */
  sim_icache_fetch(2910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 5543 */
} /* line 5543 */
  sim_icache_fetch(2911 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 5545 */
} /* line 5545 */
  sim_icache_fetch(2912 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 5547 */
} /* line 5547 */
  sim_icache_fetch(2913 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 5549 */
} /* line 5549 */
  sim_icache_fetch(2914 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 5551 */
} /* line 5551 */
  sim_icache_fetch(2915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 5553 */
} /* line 5553 */
  sim_icache_fetch(2916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 5555 */
} /* line 5555 */
  sim_icache_fetch(2917 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 5557 */
} /* line 5557 */
  sim_icache_fetch(2918 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 5559 */
} /* line 5559 */
  sim_icache_fetch(2919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 5561 */
} /* line 5561 */
  sim_icache_fetch(2920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 5563 */
} /* line 5563 */
  sim_icache_fetch(2921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 5565 */
} /* line 5565 */
  sim_icache_fetch(2922 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 5567 */
} /* line 5567 */
  sim_icache_fetch(2923 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 5569 */
} /* line 5569 */
  sim_icache_fetch(2924 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 5571 */
} /* line 5571 */
  sim_icache_fetch(2925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 5573 */
} /* line 5573 */
  sim_icache_fetch(2926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 5575 */
} /* line 5575 */
  sim_icache_fetch(2927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 5577 */
} /* line 5577 */
  sim_icache_fetch(2928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 5579 */
} /* line 5579 */
  sim_icache_fetch(2929 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 5581 */
} /* line 5581 */
  sim_icache_fetch(2930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 5583 */
} /* line 5583 */
  sim_icache_fetch(2931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 5585 */
} /* line 5585 */
  sim_icache_fetch(2932 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 5587 */
} /* line 5587 */
  sim_icache_fetch(2933 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 5589 */
} /* line 5589 */
  sim_icache_fetch(2934 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 5591 */
} /* line 5591 */
  sim_icache_fetch(2935 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 5593 */
} /* line 5593 */
  sim_icache_fetch(2936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 5595 */
} /* line 5595 */
  sim_icache_fetch(2937 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 5597 */
} /* line 5597 */
  sim_icache_fetch(2938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 5599 */
} /* line 5599 */
  sim_icache_fetch(2939 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 5601 */
} /* line 5601 */
  sim_icache_fetch(2940 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 5603 */
} /* line 5603 */
  sim_icache_fetch(2941 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 5605 */
} /* line 5605 */
  sim_icache_fetch(2942 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 5607 */
} /* line 5607 */
  sim_icache_fetch(2943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 5609 */
} /* line 5609 */
  sim_icache_fetch(2944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 5611 */
} /* line 5611 */
  sim_icache_fetch(2945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 5613 */
} /* line 5613 */
  sim_icache_fetch(2946 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 5615 */
} /* line 5615 */
  sim_icache_fetch(2947 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 5617 */
} /* line 5617 */
  sim_icache_fetch(2948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 5619 */
} /* line 5619 */
  sim_icache_fetch(2949 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 5621 */
} /* line 5621 */
  sim_icache_fetch(2950 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 5623 */
} /* line 5623 */
  sim_icache_fetch(2951 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 5625 */
} /* line 5625 */
  sim_icache_fetch(2952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 5627 */
} /* line 5627 */
  sim_icache_fetch(2953 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 5629 */
} /* line 5629 */
  sim_icache_fetch(2954 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 5631 */
} /* line 5631 */
  sim_icache_fetch(2955 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 5633 */
} /* line 5633 */
  sim_icache_fetch(2956 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 5635 */
} /* line 5635 */
  sim_icache_fetch(2957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 5637 */
} /* line 5637 */
  sim_icache_fetch(2958 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 5639 */
} /* line 5639 */
  sim_icache_fetch(2959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 5641 */
} /* line 5641 */
  sim_icache_fetch(2960 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 5643 */
} /* line 5643 */
  sim_icache_fetch(2961 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 5645 */
} /* line 5645 */
  sim_icache_fetch(2962 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 5647 */
} /* line 5647 */
  sim_icache_fetch(2963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 5649 */
} /* line 5649 */
  sim_icache_fetch(2964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 5651 */
} /* line 5651 */
  sim_icache_fetch(2965 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 5653 */
} /* line 5653 */
  sim_icache_fetch(2966 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 5655 */
} /* line 5655 */
  sim_icache_fetch(2967 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 5657 */
} /* line 5657 */
  sim_icache_fetch(2968 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 5659 */
} /* line 5659 */
  sim_icache_fetch(2969 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 5661 */
} /* line 5661 */
  sim_icache_fetch(2970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 5663 */
} /* line 5663 */
  sim_icache_fetch(2971 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 5665 */
} /* line 5665 */
  sim_icache_fetch(2972 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 5667 */
} /* line 5667 */
  sim_icache_fetch(2973 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 5669 */
} /* line 5669 */
  sim_icache_fetch(2974 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 5671 */
} /* line 5671 */
  sim_icache_fetch(2975 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 5673 */
} /* line 5673 */
  sim_icache_fetch(2976 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 5675 */
} /* line 5675 */
  sim_icache_fetch(2977 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 5677 */
} /* line 5677 */
  sim_icache_fetch(2978 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 5679 */
} /* line 5679 */
  sim_icache_fetch(2979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 5681 */
} /* line 5681 */
  sim_icache_fetch(2980 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 5683 */
} /* line 5683 */
  sim_icache_fetch(2981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 5685 */
} /* line 5685 */
  sim_icache_fetch(2982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 5687 */
} /* line 5687 */
  sim_icache_fetch(2983 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 5689 */
} /* line 5689 */
  sim_icache_fetch(2984 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 5691 */
} /* line 5691 */
  sim_icache_fetch(2985 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 5693 */
} /* line 5693 */
  sim_icache_fetch(2986 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 5695 */
} /* line 5695 */
  sim_icache_fetch(2987 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 5697 */
} /* line 5697 */
  sim_icache_fetch(2988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 5699 */
} /* line 5699 */
  sim_icache_fetch(2989 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 5701 */
} /* line 5701 */
  sim_icache_fetch(2990 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 5703 */
} /* line 5703 */
  sim_icache_fetch(2991 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 5705 */
} /* line 5705 */
  sim_icache_fetch(2992 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 5707 */
} /* line 5707 */
  sim_icache_fetch(2993 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 5709 */
} /* line 5709 */
  sim_icache_fetch(2994 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 5711 */
} /* line 5711 */
  sim_icache_fetch(2995 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 5713 */
} /* line 5713 */
  sim_icache_fetch(2996 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 5715 */
} /* line 5715 */
  sim_icache_fetch(2997 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 5718 */
} /* line 5718 */
  sim_icache_fetch(2998 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L149X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L149X3;
} /* line 5720 */
l_L150X3: ;/* line 5723 */
__LABEL(l_L150X3);
  sim_icache_fetch(2999 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 5724 */
} /* line 5724 */
  sim_icache_fetch(3000 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 5726 */
} /* line 5726 */
  sim_icache_fetch(3002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) 257); /* line 5728 */
} /* line 5728 */
  sim_icache_fetch(3004 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 5730 */
} /* line 5730 */
  sim_icache_fetch(3005 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 5732 */
} /* line 5732 */
  sim_icache_fetch(3007 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5734 */
} /* line 5734 */
		 /* line 5735 */
  sim_icache_fetch(3009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (358 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 5737 */
l_lr_207: ;/* line 5737 */
__LABEL(l_lr_207);
  sim_icache_fetch(3011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_3); /* line 5739 */
} /* line 5739 */
  sim_icache_fetch(3012 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, reg_r0_3); /* line 5741 */
} /* line 5741 */
  sim_icache_fetch(3013 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 5743 */
} /* line 5743 */
  sim_icache_fetch(3014 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5745 */
  sim_icache_fetch(3015 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5747 */
} /* line 5747 */
  sim_icache_fetch(3016 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 5749 */
} /* line 5749 */
  sim_icache_fetch(3017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5752 */
l_L151X3: ;/* line 5755 */
__LABEL(l_L151X3);
  sim_icache_fetch(3018 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 5756 */
} /* line 5756 */
  sim_icache_fetch(3019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 5758 */
} /* line 5758 */
  sim_icache_fetch(3020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 5760 */
} /* line 5760 */
  sim_icache_fetch(3021 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5762 */
} /* line 5762 */
  sim_icache_fetch(3023 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 5764 */
} /* line 5764 */
  sim_icache_fetch(3025 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) 1); /* line 5766 */
} /* line 5766 */
  sim_icache_fetch(3026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 5768 */
} /* line 5768 */
  sim_icache_fetch(3027 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_59, reg_r0_2); /* line 5770 */
} /* line 5770 */
  sim_icache_fetch(3028 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 5772 */
} /* line 5772 */
  sim_icache_fetch(3030 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 5774 */
} /* line 5774 */
l_L152X3: ;/* line 5777 */
__LABEL(l_L152X3);
		 /* line 5777 */
  sim_icache_fetch(3031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (358 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 5779 */
l_lr_211: ;/* line 5779 */
__LABEL(l_lr_211);
  sim_icache_fetch(3033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, reg_r0_3); /* line 5781 */
} /* line 5781 */
  sim_icache_fetch(3034 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 5783 */
} /* line 5783 */
  sim_icache_fetch(3035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5785 */
  sim_icache_fetch(3036 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 5787 */
} /* line 5787 */
  sim_icache_fetch(3038 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 5789 */
} /* line 5789 */
  sim_icache_fetch(3040 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 5791 */
} /* line 5791 */
  sim_icache_fetch(3041 + t_thisfile.offset, 1);
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
} /* line 5793 */
  sim_icache_fetch(3042 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 5795 */
} /* line 5795 */
  sim_icache_fetch(3044 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 255); /* line 5797 */
} /* line 5797 */
l_L155X3: ;/* line 5800 */
__LABEL(l_L155X3);
  sim_icache_fetch(3045 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 5801 */
} /* line 5801 */
  sim_icache_fetch(3046 + t_thisfile.offset, 1);
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
} /* line 5803 */
  sim_icache_fetch(3047 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 5805 */
} /* line 5805 */
  sim_icache_fetch(3048 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 5807 */
} /* line 5807 */
  sim_icache_fetch(3049 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 5809 */
} /* line 5809 */
  sim_icache_fetch(3050 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 5811 */
} /* line 5811 */
  sim_icache_fetch(3051 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 5813 */
} /* line 5813 */
  sim_icache_fetch(3052 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 5815 */
} /* line 5815 */
  sim_icache_fetch(3053 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 5817 */
} /* line 5817 */
  sim_icache_fetch(3054 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 5819 */
} /* line 5819 */
  sim_icache_fetch(3055 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 5821 */
} /* line 5821 */
  sim_icache_fetch(3056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 5823 */
} /* line 5823 */
  sim_icache_fetch(3057 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 5825 */
} /* line 5825 */
  sim_icache_fetch(3058 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 5827 */
} /* line 5827 */
  sim_icache_fetch(3059 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 5829 */
} /* line 5829 */
  sim_icache_fetch(3060 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 5831 */
} /* line 5831 */
  sim_icache_fetch(3061 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 5833 */
} /* line 5833 */
  sim_icache_fetch(3062 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 5835 */
} /* line 5835 */
  sim_icache_fetch(3063 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 5837 */
} /* line 5837 */
  sim_icache_fetch(3064 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 5840 */
} /* line 5840 */
  sim_icache_fetch(3065 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L155X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L155X3;
} /* line 5842 */
l_L156X3: ;/* line 5845 */
__LABEL(l_L156X3);
  sim_icache_fetch(3066 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 1); /* line 5846 */
} /* line 5846 */
  sim_icache_fetch(3067 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 5848 */
} /* line 5848 */
  sim_icache_fetch(3069 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 5850 */
} /* line 5850 */
  sim_icache_fetch(3071 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 5852 */
} /* line 5852 */
		 /* line 5853 */
  sim_icache_fetch(3073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (358 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 5855 */
l_lr_215: ;/* line 5855 */
__LABEL(l_lr_215);
  sim_icache_fetch(3075 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, reg_r0_3); /* line 5857 */
} /* line 5857 */
  sim_icache_fetch(3076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 5859 */
} /* line 5859 */
  sim_icache_fetch(3077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5861 */
l_L154X3: ;/* line 5864 */
__LABEL(l_L154X3);
  sim_icache_fetch(3078 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_4); /* line 5865 */
} /* line 5865 */
  sim_icache_fetch(3079 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5867 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5868 */
   __ADD_CYCLES(1);
} /* line 5868 */
  sim_icache_fetch(3082 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 5870 */
} /* line 5870 */
  sim_icache_fetch(3083 + t_thisfile.offset, 1);
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
} /* line 5872 */
  sim_icache_fetch(3084 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_59); /* line 5874 */
} /* line 5874 */
  sim_icache_fetch(3085 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 5876 */
} /* line 5876 */
  sim_icache_fetch(3087 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 5878 */
} /* line 5878 */
  sim_icache_fetch(3088 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 5880 */
} /* line 5880 */
l_L158X3: ;/* line 5883 */
__LABEL(l_L158X3);
  sim_icache_fetch(3089 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5884 */
} /* line 5884 */
  sim_icache_fetch(3091 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5886 */
} /* line 5886 */
  sim_icache_fetch(3092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5888 */
  sim_icache_fetch(3093 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5890 */
} /* line 5890 */
  sim_icache_fetch(3095 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5892 */
} /* line 5892 */
  sim_icache_fetch(3096 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 5894 */
} /* line 5894 */
  sim_icache_fetch(3097 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5896 */
} /* line 5896 */
  sim_icache_fetch(3098 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L160X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5898 */
  sim_icache_fetch(3099 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5900 */
} /* line 5900 */
  sim_icache_fetch(3101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5902 */
} /* line 5902 */
  sim_icache_fetch(3103 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5904 */
} /* line 5904 */
  sim_icache_fetch(3104 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 5906 */
} /* line 5906 */
  sim_icache_fetch(3105 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5908 */
} /* line 5908 */
  sim_icache_fetch(3106 + t_thisfile.offset, 1);
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
} /* line 5910 */
  sim_icache_fetch(3107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5912 */
} /* line 5912 */
  sim_icache_fetch(3109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5914 */
} /* line 5914 */
  sim_icache_fetch(3111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5916 */
} /* line 5916 */
  sim_icache_fetch(3112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 5918 */
} /* line 5918 */
  sim_icache_fetch(3113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5920 */
} /* line 5920 */
  sim_icache_fetch(3114 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L162X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5922 */
  sim_icache_fetch(3115 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5924 */
} /* line 5924 */
  sim_icache_fetch(3117 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5926 */
} /* line 5926 */
  sim_icache_fetch(3119 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5928 */
} /* line 5928 */
  sim_icache_fetch(3120 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 5930 */
} /* line 5930 */
  sim_icache_fetch(3121 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5932 */
} /* line 5932 */
  sim_icache_fetch(3122 + t_thisfile.offset, 1);
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
} /* line 5934 */
  sim_icache_fetch(3123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5936 */
} /* line 5936 */
  sim_icache_fetch(3125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5938 */
} /* line 5938 */
  sim_icache_fetch(3127 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5940 */
} /* line 5940 */
  sim_icache_fetch(3128 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 5942 */
} /* line 5942 */
  sim_icache_fetch(3129 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5944 */
} /* line 5944 */
  sim_icache_fetch(3130 + t_thisfile.offset, 1);
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
} /* line 5946 */
  sim_icache_fetch(3131 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5948 */
} /* line 5948 */
  sim_icache_fetch(3133 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5950 */
} /* line 5950 */
  sim_icache_fetch(3135 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5952 */
} /* line 5952 */
  sim_icache_fetch(3136 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 5954 */
} /* line 5954 */
  sim_icache_fetch(3137 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5956 */
} /* line 5956 */
  sim_icache_fetch(3138 + t_thisfile.offset, 1);
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
} /* line 5958 */
  sim_icache_fetch(3139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5960 */
} /* line 5960 */
  sim_icache_fetch(3141 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5962 */
} /* line 5962 */
  sim_icache_fetch(3143 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5964 */
} /* line 5964 */
  sim_icache_fetch(3144 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 5966 */
} /* line 5966 */
  sim_icache_fetch(3145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5968 */
} /* line 5968 */
  sim_icache_fetch(3146 + t_thisfile.offset, 1);
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
} /* line 5970 */
  sim_icache_fetch(3147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5972 */
} /* line 5972 */
  sim_icache_fetch(3149 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5974 */
} /* line 5974 */
  sim_icache_fetch(3151 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5976 */
} /* line 5976 */
  sim_icache_fetch(3152 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 5978 */
} /* line 5978 */
  sim_icache_fetch(3153 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5980 */
} /* line 5980 */
  sim_icache_fetch(3154 + t_thisfile.offset, 1);
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
} /* line 5982 */
  sim_icache_fetch(3155 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5984 */
} /* line 5984 */
  sim_icache_fetch(3157 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5986 */
} /* line 5986 */
  sim_icache_fetch(3159 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 5988 */
} /* line 5988 */
  sim_icache_fetch(3160 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 5990 */
} /* line 5990 */
  sim_icache_fetch(3161 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 5992 */
} /* line 5992 */
  sim_icache_fetch(3162 + t_thisfile.offset, 1);
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
} /* line 5994 */
  sim_icache_fetch(3163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5996 */
} /* line 5996 */
  sim_icache_fetch(3165 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 5998 */
} /* line 5998 */
  sim_icache_fetch(3167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 6000 */
} /* line 6000 */
  sim_icache_fetch(3168 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 6002 */
} /* line 6002 */
  sim_icache_fetch(3169 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 6004 */
} /* line 6004 */
  sim_icache_fetch(3170 + t_thisfile.offset, 1);
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
} /* line 6006 */
  sim_icache_fetch(3171 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6008 */
} /* line 6008 */
  sim_icache_fetch(3173 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 6010 */
} /* line 6010 */
  sim_icache_fetch(3175 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 6012 */
} /* line 6012 */
  sim_icache_fetch(3176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 6014 */
} /* line 6014 */
  sim_icache_fetch(3177 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 6016 */
} /* line 6016 */
  sim_icache_fetch(3178 + t_thisfile.offset, 1);
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
} /* line 6018 */
  sim_icache_fetch(3179 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6020 */
} /* line 6020 */
  sim_icache_fetch(3181 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 6022 */
} /* line 6022 */
  sim_icache_fetch(3183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 6024 */
} /* line 6024 */
  sim_icache_fetch(3184 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 6026 */
} /* line 6026 */
  sim_icache_fetch(3185 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 6028 */
} /* line 6028 */
  sim_icache_fetch(3186 + t_thisfile.offset, 1);
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
} /* line 6030 */
  sim_icache_fetch(3187 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6032 */
} /* line 6032 */
  sim_icache_fetch(3189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 6034 */
} /* line 6034 */
  sim_icache_fetch(3191 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 6036 */
} /* line 6036 */
  sim_icache_fetch(3192 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 6038 */
} /* line 6038 */
  sim_icache_fetch(3193 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 6040 */
} /* line 6040 */
  sim_icache_fetch(3194 + t_thisfile.offset, 1);
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
} /* line 6042 */
  sim_icache_fetch(3195 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6044 */
} /* line 6044 */
  sim_icache_fetch(3197 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 6046 */
} /* line 6046 */
  sim_icache_fetch(3199 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 6048 */
} /* line 6048 */
  sim_icache_fetch(3200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 6050 */
} /* line 6050 */
  sim_icache_fetch(3201 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 6052 */
} /* line 6052 */
  sim_icache_fetch(3202 + t_thisfile.offset, 1);
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
} /* line 6054 */
  sim_icache_fetch(3203 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6056 */
} /* line 6056 */
  sim_icache_fetch(3205 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 6058 */
} /* line 6058 */
  sim_icache_fetch(3207 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 6060 */
} /* line 6060 */
  sim_icache_fetch(3208 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 6062 */
} /* line 6062 */
  sim_icache_fetch(3209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 6064 */
} /* line 6064 */
  sim_icache_fetch(3210 + t_thisfile.offset, 1);
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
} /* line 6066 */
  sim_icache_fetch(3211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6068 */
} /* line 6068 */
  sim_icache_fetch(3213 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 6070 */
} /* line 6070 */
  sim_icache_fetch(3215 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_2,0,2)); /* line 6072 */
} /* line 6072 */
  sim_icache_fetch(3216 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 6074 */
} /* line 6074 */
  sim_icache_fetch(3217 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 6077 */
} /* line 6077 */
  sim_icache_fetch(3218 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 6079 */
l_L174X3: ;/* line 6083 */
__LABEL(l_L174X3);
  sim_icache_fetch(3219 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6083 */
  sim_icache_fetch(3220 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6085 */
} /* line 6085 */
  sim_icache_fetch(3222 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 6088 */
} /* line 6088 */
  sim_icache_fetch(3223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6090 */
l_L176X3: ;/* line 6093 */
__LABEL(l_L176X3);
  sim_icache_fetch(3224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6094 */
} /* line 6094 */
  sim_icache_fetch(3226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_3,0,1)); /* line 6096 */
} /* line 6096 */
  sim_icache_fetch(3227 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 1); /* line 6098 */
} /* line 6098 */
  sim_icache_fetch(3228 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_3); /* line 6100 */
} /* line 6100 */
  sim_icache_fetch(3229 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 6102 */
} /* line 6102 */
  sim_icache_fetch(3231 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_1, reg_r0_4, ((unsigned int) htab + (unsigned int) 4096)); /* line 6104 */
} /* line 6104 */
  sim_icache_fetch(3233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_2, reg_r0_5, ((unsigned int) htab + (unsigned int) 4096)); /* line 6106 */
} /* line 6106 */
  sim_icache_fetch(3235 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_3, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 6108 */
} /* line 6108 */
  sim_icache_fetch(3237 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_4, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 6110 */
} /* line 6110 */
  sim_icache_fetch(3239 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_5, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 6112 */
} /* line 6112 */
  sim_icache_fetch(3241 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_6, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 6114 */
} /* line 6114 */
  sim_icache_fetch(3243 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_7, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 6116 */
} /* line 6116 */
  sim_icache_fetch(3245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 6118 */
} /* line 6118 */
  sim_icache_fetch(3246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_23, reg_r0_17, (unsigned int) -16); /* line 6120 */
} /* line 6120 */
  sim_icache_fetch(3247 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_24, reg_r0_16, (unsigned int) -16); /* line 6122 */
} /* line 6122 */
  sim_icache_fetch(3248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_25, reg_r0_15, (unsigned int) -16); /* line 6124 */
} /* line 6124 */
  sim_icache_fetch(3249 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_26, reg_r0_14, (unsigned int) -16); /* line 6126 */
} /* line 6126 */
  sim_icache_fetch(3250 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_27, reg_r0_13, (unsigned int) -16); /* line 6128 */
} /* line 6128 */
  sim_icache_fetch(3251 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_28, reg_r0_12, (unsigned int) -16); /* line 6130 */
} /* line 6130 */
  sim_icache_fetch(3252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 6132 */
} /* line 6132 */
  sim_icache_fetch(3253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_10, (unsigned int) -16); /* line 6134 */
} /* line 6134 */
  sim_icache_fetch(3254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_31, reg_r0_9, (unsigned int) -16); /* line 6136 */
} /* line 6136 */
  sim_icache_fetch(3255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_32, reg_r0_8, (unsigned int) -16); /* line 6138 */
} /* line 6138 */
  sim_icache_fetch(3256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_33, reg_r0_7, (unsigned int) -16); /* line 6140 */
} /* line 6140 */
  sim_icache_fetch(3257 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_34, reg_r0_6, (unsigned int) -16); /* line 6142 */
} /* line 6142 */
  sim_icache_fetch(3258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_35, reg_r0_5, (unsigned int) -16); /* line 6144 */
} /* line 6144 */
  sim_icache_fetch(3259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_4, (unsigned int) -16); /* line 6146 */
} /* line 6146 */
  sim_icache_fetch(3260 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_37, reg_r0_18, (unsigned int) -16); /* line 6148 */
} /* line 6148 */
  sim_icache_fetch(3261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_38, reg_r0_18); /* line 6150 */
} /* line 6150 */
  sim_icache_fetch(3262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 6152 */
} /* line 6152 */
  sim_icache_fetch(3263 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_40, reg_r0_37); /* line 6154 */
} /* line 6154 */
  sim_icache_fetch(3264 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_21); /* line 6156 */
} /* line 6156 */
  sim_icache_fetch(3266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 6158 */
} /* line 6158 */
  sim_icache_fetch(3267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L177X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6160 */
  sim_icache_fetch(3268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6162 */
} /* line 6162 */
  sim_icache_fetch(3270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 6164 */
} /* line 6164 */
  sim_icache_fetch(3271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6166 */
} /* line 6166 */
  sim_icache_fetch(3272 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_0, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 6168 */
} /* line 6168 */
  sim_icache_fetch(3274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6170 */
} /* line 6170 */
  sim_icache_fetch(3276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 6172 */
} /* line 6172 */
  sim_icache_fetch(3277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L178X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6174 */
  sim_icache_fetch(3278 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6176 */
} /* line 6176 */
  sim_icache_fetch(3280 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 6178 */
} /* line 6178 */
  sim_icache_fetch(3281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6180 */
} /* line 6180 */
  sim_icache_fetch(3282 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_1, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 6182 */
} /* line 6182 */
  sim_icache_fetch(3284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_36, (unsigned int) -16); /* line 6184 */
} /* line 6184 */
  sim_icache_fetch(3285 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6186 */
} /* line 6186 */
  sim_icache_fetch(3287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 6188 */
} /* line 6188 */
  sim_icache_fetch(3288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6190 */
  sim_icache_fetch(3289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6192 */
} /* line 6192 */
  sim_icache_fetch(3291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 6194 */
} /* line 6194 */
  sim_icache_fetch(3292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6196 */
} /* line 6196 */
  sim_icache_fetch(3293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_2, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 6198 */
} /* line 6198 */
  sim_icache_fetch(3295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_35, (unsigned int) -16); /* line 6200 */
} /* line 6200 */
  sim_icache_fetch(3296 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6202 */
} /* line 6202 */
  sim_icache_fetch(3298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 6204 */
} /* line 6204 */
  sim_icache_fetch(3299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L180X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6206 */
  sim_icache_fetch(3300 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6208 */
} /* line 6208 */
  sim_icache_fetch(3302 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 6210 */
} /* line 6210 */
  sim_icache_fetch(3303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6212 */
} /* line 6212 */
  sim_icache_fetch(3304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_3, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 6214 */
} /* line 6214 */
  sim_icache_fetch(3306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_34, (unsigned int) -16); /* line 6216 */
} /* line 6216 */
  sim_icache_fetch(3307 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6218 */
} /* line 6218 */
  sim_icache_fetch(3309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 6220 */
} /* line 6220 */
  sim_icache_fetch(3310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L181X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6222 */
  sim_icache_fetch(3311 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6224 */
} /* line 6224 */
  sim_icache_fetch(3313 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 6226 */
} /* line 6226 */
  sim_icache_fetch(3314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6228 */
} /* line 6228 */
  sim_icache_fetch(3315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_4, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 6230 */
} /* line 6230 */
  sim_icache_fetch(3317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_33, (unsigned int) -16); /* line 6232 */
} /* line 6232 */
  sim_icache_fetch(3318 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6234 */
} /* line 6234 */
  sim_icache_fetch(3320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 6236 */
} /* line 6236 */
  sim_icache_fetch(3321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L182X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6238 */
  sim_icache_fetch(3322 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6240 */
} /* line 6240 */
  sim_icache_fetch(3324 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 6242 */
} /* line 6242 */
  sim_icache_fetch(3325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6244 */
} /* line 6244 */
  sim_icache_fetch(3326 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_5, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 6246 */
} /* line 6246 */
  sim_icache_fetch(3328 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_32, (unsigned int) -16); /* line 6248 */
} /* line 6248 */
  sim_icache_fetch(3329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6250 */
} /* line 6250 */
  sim_icache_fetch(3331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 6252 */
} /* line 6252 */
  sim_icache_fetch(3332 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L183X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6254 */
  sim_icache_fetch(3333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6256 */
} /* line 6256 */
  sim_icache_fetch(3335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 6258 */
} /* line 6258 */
  sim_icache_fetch(3336 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6260 */
} /* line 6260 */
  sim_icache_fetch(3337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_6, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 6262 */
} /* line 6262 */
  sim_icache_fetch(3339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_31, (unsigned int) -16); /* line 6264 */
} /* line 6264 */
  sim_icache_fetch(3340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6266 */
} /* line 6266 */
  sim_icache_fetch(3342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 6268 */
} /* line 6268 */
  sim_icache_fetch(3343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L184X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6270 */
  sim_icache_fetch(3344 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6272 */
} /* line 6272 */
  sim_icache_fetch(3346 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 6274 */
} /* line 6274 */
  sim_icache_fetch(3347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6276 */
} /* line 6276 */
  sim_icache_fetch(3348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 6278 */
} /* line 6278 */
  sim_icache_fetch(3350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_30, (unsigned int) -16); /* line 6280 */
} /* line 6280 */
  sim_icache_fetch(3351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6282 */
} /* line 6282 */
  sim_icache_fetch(3353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 6284 */
} /* line 6284 */
  sim_icache_fetch(3354 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L185X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6286 */
  sim_icache_fetch(3355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6288 */
} /* line 6288 */
  sim_icache_fetch(3357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 6290 */
} /* line 6290 */
  sim_icache_fetch(3358 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6292 */
} /* line 6292 */
  sim_icache_fetch(3359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 6294 */
} /* line 6294 */
  sim_icache_fetch(3361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 6296 */
} /* line 6296 */
  sim_icache_fetch(3362 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6298 */
} /* line 6298 */
  sim_icache_fetch(3364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 6300 */
} /* line 6300 */
  sim_icache_fetch(3365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L186X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6302 */
  sim_icache_fetch(3366 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6304 */
} /* line 6304 */
  sim_icache_fetch(3368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 6306 */
} /* line 6306 */
  sim_icache_fetch(3369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6308 */
} /* line 6308 */
  sim_icache_fetch(3370 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 6310 */
} /* line 6310 */
  sim_icache_fetch(3372 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_28, (unsigned int) -16); /* line 6312 */
} /* line 6312 */
  sim_icache_fetch(3373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6314 */
} /* line 6314 */
  sim_icache_fetch(3375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 6316 */
} /* line 6316 */
  sim_icache_fetch(3376 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L187X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6318 */
  sim_icache_fetch(3377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6320 */
} /* line 6320 */
  sim_icache_fetch(3379 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 6322 */
} /* line 6322 */
  sim_icache_fetch(3380 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6324 */
} /* line 6324 */
  sim_icache_fetch(3381 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 6326 */
} /* line 6326 */
  sim_icache_fetch(3383 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_27, (unsigned int) -16); /* line 6328 */
} /* line 6328 */
  sim_icache_fetch(3384 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6330 */
} /* line 6330 */
  sim_icache_fetch(3386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 6332 */
} /* line 6332 */
  sim_icache_fetch(3387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L188X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6334 */
  sim_icache_fetch(3388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6336 */
} /* line 6336 */
  sim_icache_fetch(3390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 6338 */
} /* line 6338 */
  sim_icache_fetch(3391 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6340 */
} /* line 6340 */
  sim_icache_fetch(3392 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 6342 */
} /* line 6342 */
  sim_icache_fetch(3394 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_26, (unsigned int) -16); /* line 6344 */
} /* line 6344 */
  sim_icache_fetch(3395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6346 */
} /* line 6346 */
  sim_icache_fetch(3397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 6348 */
} /* line 6348 */
  sim_icache_fetch(3398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L189X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6350 */
  sim_icache_fetch(3399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6352 */
} /* line 6352 */
  sim_icache_fetch(3401 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 6354 */
} /* line 6354 */
  sim_icache_fetch(3402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6356 */
} /* line 6356 */
  sim_icache_fetch(3403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 6358 */
} /* line 6358 */
  sim_icache_fetch(3405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_25, (unsigned int) -16); /* line 6360 */
} /* line 6360 */
  sim_icache_fetch(3406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6362 */
} /* line 6362 */
  sim_icache_fetch(3408 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 6364 */
} /* line 6364 */
  sim_icache_fetch(3409 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L190X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6366 */
  sim_icache_fetch(3410 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6368 */
} /* line 6368 */
  sim_icache_fetch(3412 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 6370 */
} /* line 6370 */
  sim_icache_fetch(3413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6372 */
} /* line 6372 */
  sim_icache_fetch(3414 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 6374 */
} /* line 6374 */
  sim_icache_fetch(3416 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_24, (unsigned int) -16); /* line 6376 */
} /* line 6376 */
  sim_icache_fetch(3417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6378 */
} /* line 6378 */
  sim_icache_fetch(3419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 6380 */
} /* line 6380 */
  sim_icache_fetch(3420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L191X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6382 */
  sim_icache_fetch(3421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6384 */
} /* line 6384 */
  sim_icache_fetch(3423 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 6386 */
} /* line 6386 */
  sim_icache_fetch(3424 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6388 */
} /* line 6388 */
  sim_icache_fetch(3425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) -16); /* line 6390 */
} /* line 6390 */
  sim_icache_fetch(3426 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 6392 */
} /* line 6392 */
  sim_icache_fetch(3428 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_23, (unsigned int) -16); /* line 6394 */
} /* line 6394 */
  sim_icache_fetch(3429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6396 */
} /* line 6396 */
  sim_icache_fetch(3431 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 6398 */
} /* line 6398 */
  sim_icache_fetch(3432 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L192X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6400 */
  sim_icache_fetch(3433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6402 */
} /* line 6402 */
  sim_icache_fetch(3435 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_3,0,1)); /* line 6404 */
} /* line 6404 */
  sim_icache_fetch(3436 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) 1); /* line 6406 */
} /* line 6406 */
  sim_icache_fetch(3437 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_3); /* line 6408 */
} /* line 6408 */
  sim_icache_fetch(3438 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_7, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 6410 */
} /* line 6410 */
  sim_icache_fetch(3440 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_37, (unsigned int) -16); /* line 6412 */
} /* line 6412 */
  sim_icache_fetch(3441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_39); /* line 6414 */
} /* line 6414 */
  sim_icache_fetch(3442 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_21); /* line 6416 */
} /* line 6416 */
  sim_icache_fetch(3444 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 6418 */
} /* line 6418 */
  sim_icache_fetch(3445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L177X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6420 */
  sim_icache_fetch(3446 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6422 */
} /* line 6422 */
  sim_icache_fetch(3448 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 6424 */
} /* line 6424 */
  sim_icache_fetch(3449 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6426 */
} /* line 6426 */
  sim_icache_fetch(3450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_0, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 6428 */
} /* line 6428 */
  sim_icache_fetch(3452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6430 */
} /* line 6430 */
  sim_icache_fetch(3454 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 6432 */
} /* line 6432 */
  sim_icache_fetch(3455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L178X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6434 */
  sim_icache_fetch(3456 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6436 */
} /* line 6436 */
  sim_icache_fetch(3458 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 6438 */
} /* line 6438 */
  sim_icache_fetch(3459 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6440 */
} /* line 6440 */
  sim_icache_fetch(3460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_1, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 6442 */
} /* line 6442 */
  sim_icache_fetch(3462 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6444 */
} /* line 6444 */
  sim_icache_fetch(3464 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 6446 */
} /* line 6446 */
  sim_icache_fetch(3465 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6448 */
  sim_icache_fetch(3466 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6450 */
} /* line 6450 */
  sim_icache_fetch(3468 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 6452 */
} /* line 6452 */
  sim_icache_fetch(3469 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6454 */
} /* line 6454 */
  sim_icache_fetch(3470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_2, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 6456 */
} /* line 6456 */
  sim_icache_fetch(3472 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6458 */
} /* line 6458 */
  sim_icache_fetch(3474 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 6460 */
} /* line 6460 */
  sim_icache_fetch(3475 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L180X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6462 */
  sim_icache_fetch(3476 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6464 */
} /* line 6464 */
  sim_icache_fetch(3478 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 6466 */
} /* line 6466 */
  sim_icache_fetch(3479 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6468 */
} /* line 6468 */
  sim_icache_fetch(3480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_3, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 6470 */
} /* line 6470 */
  sim_icache_fetch(3482 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6472 */
} /* line 6472 */
  sim_icache_fetch(3484 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 6474 */
} /* line 6474 */
  sim_icache_fetch(3485 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L181X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6476 */
  sim_icache_fetch(3486 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6478 */
} /* line 6478 */
  sim_icache_fetch(3488 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 6480 */
} /* line 6480 */
  sim_icache_fetch(3489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6482 */
} /* line 6482 */
  sim_icache_fetch(3490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_4, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 6484 */
} /* line 6484 */
  sim_icache_fetch(3492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6486 */
} /* line 6486 */
  sim_icache_fetch(3494 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 6488 */
} /* line 6488 */
  sim_icache_fetch(3495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L182X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6490 */
  sim_icache_fetch(3496 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6492 */
} /* line 6492 */
  sim_icache_fetch(3498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 6494 */
} /* line 6494 */
  sim_icache_fetch(3499 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6496 */
} /* line 6496 */
  sim_icache_fetch(3500 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_5, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 6498 */
} /* line 6498 */
  sim_icache_fetch(3502 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6500 */
} /* line 6500 */
  sim_icache_fetch(3504 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 6502 */
} /* line 6502 */
  sim_icache_fetch(3505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L183X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6504 */
  sim_icache_fetch(3506 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6506 */
} /* line 6506 */
  sim_icache_fetch(3508 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 6508 */
} /* line 6508 */
  sim_icache_fetch(3509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6510 */
} /* line 6510 */
  sim_icache_fetch(3510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_6, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 6512 */
} /* line 6512 */
  sim_icache_fetch(3512 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6514 */
} /* line 6514 */
  sim_icache_fetch(3514 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 6516 */
} /* line 6516 */
  sim_icache_fetch(3515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L184X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6518 */
  sim_icache_fetch(3516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6520 */
} /* line 6520 */
  sim_icache_fetch(3518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 6522 */
} /* line 6522 */
  sim_icache_fetch(3519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6524 */
} /* line 6524 */
  sim_icache_fetch(3520 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_7, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 6526 */
} /* line 6526 */
  sim_icache_fetch(3522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6528 */
} /* line 6528 */
  sim_icache_fetch(3524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 6530 */
} /* line 6530 */
  sim_icache_fetch(3525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L185X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6532 */
  sim_icache_fetch(3526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6534 */
} /* line 6534 */
  sim_icache_fetch(3528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 6536 */
} /* line 6536 */
  sim_icache_fetch(3529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6538 */
} /* line 6538 */
  sim_icache_fetch(3530 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6540 */
} /* line 6540 */
  sim_icache_fetch(3532 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 6542 */
} /* line 6542 */
  sim_icache_fetch(3533 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L186X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6544 */
  sim_icache_fetch(3534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6546 */
} /* line 6546 */
  sim_icache_fetch(3536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 6548 */
} /* line 6548 */
  sim_icache_fetch(3537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6550 */
} /* line 6550 */
  sim_icache_fetch(3538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6552 */
} /* line 6552 */
  sim_icache_fetch(3540 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 6554 */
} /* line 6554 */
  sim_icache_fetch(3541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L187X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6556 */
  sim_icache_fetch(3542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6558 */
} /* line 6558 */
  sim_icache_fetch(3544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 6560 */
} /* line 6560 */
  sim_icache_fetch(3545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6562 */
} /* line 6562 */
  sim_icache_fetch(3546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6564 */
} /* line 6564 */
  sim_icache_fetch(3548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 6566 */
} /* line 6566 */
  sim_icache_fetch(3549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L188X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6568 */
  sim_icache_fetch(3550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6570 */
} /* line 6570 */
  sim_icache_fetch(3552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 6572 */
} /* line 6572 */
  sim_icache_fetch(3553 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6574 */
} /* line 6574 */
  sim_icache_fetch(3554 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6576 */
} /* line 6576 */
  sim_icache_fetch(3556 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 6578 */
} /* line 6578 */
  sim_icache_fetch(3557 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L189X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6580 */
  sim_icache_fetch(3558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6582 */
} /* line 6582 */
  sim_icache_fetch(3560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 6584 */
} /* line 6584 */
  sim_icache_fetch(3561 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6586 */
} /* line 6586 */
  sim_icache_fetch(3562 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6588 */
} /* line 6588 */
  sim_icache_fetch(3564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 6590 */
} /* line 6590 */
  sim_icache_fetch(3565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L190X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6592 */
  sim_icache_fetch(3566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6594 */
} /* line 6594 */
  sim_icache_fetch(3568 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 6596 */
} /* line 6596 */
  sim_icache_fetch(3569 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6598 */
} /* line 6598 */
  sim_icache_fetch(3570 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6600 */
} /* line 6600 */
  sim_icache_fetch(3572 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 6602 */
} /* line 6602 */
  sim_icache_fetch(3573 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L191X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6604 */
  sim_icache_fetch(3574 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 6606 */
} /* line 6606 */
  sim_icache_fetch(3576 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 6608 */
} /* line 6608 */
  sim_icache_fetch(3577 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_2, (unsigned int) 1); /* line 6610 */
} /* line 6610 */
  sim_icache_fetch(3578 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) -16); /* line 6612 */
} /* line 6612 */
  sim_icache_fetch(3579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_20); /* line 6614 */
} /* line 6614 */
  sim_icache_fetch(3581 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 6616 */
} /* line 6616 */
  sim_icache_fetch(3582 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L192X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6619 */
  sim_icache_fetch(3583 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 6621 */
l_L192X3: ;/* line 6624 */
__LABEL(l_L192X3);
  sim_icache_fetch(3584 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_22, (unsigned int) -15); /* line 6626 */
} /* line 6626 */
  sim_icache_fetch(3585 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6628 */
l_L195X3: ;/* line 6631 */
__LABEL(l_L195X3);
  sim_icache_fetch(3586 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 6632 */
} /* line 6632 */
  sim_icache_fetch(3588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 6634 */
} /* line 6634 */
  sim_icache_fetch(3589 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 6636 */
} /* line 6636 */
  sim_icache_fetch(3590 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 6638 */
} /* line 6638 */
  sim_icache_fetch(3592 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 6641 */
} /* line 6641 */
  sim_icache_fetch(3594 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L194X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L194X3;
} /* line 6643 */
l_L191X3: ;/* line 6646 */
__LABEL(l_L191X3);
  sim_icache_fetch(3595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -15); /* line 6648 */
} /* line 6648 */
  sim_icache_fetch(3596 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6650 */
l_L190X3: ;/* line 6653 */
__LABEL(l_L190X3);
  sim_icache_fetch(3597 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -14); /* line 6655 */
} /* line 6655 */
  sim_icache_fetch(3598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6657 */
l_L189X3: ;/* line 6660 */
__LABEL(l_L189X3);
  sim_icache_fetch(3599 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -13); /* line 6662 */
} /* line 6662 */
  sim_icache_fetch(3600 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6664 */
l_L188X3: ;/* line 6667 */
__LABEL(l_L188X3);
  sim_icache_fetch(3601 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -12); /* line 6669 */
} /* line 6669 */
  sim_icache_fetch(3602 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6671 */
l_L187X3: ;/* line 6674 */
__LABEL(l_L187X3);
  sim_icache_fetch(3603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -11); /* line 6676 */
} /* line 6676 */
  sim_icache_fetch(3604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6678 */
l_L186X3: ;/* line 6681 */
__LABEL(l_L186X3);
  sim_icache_fetch(3605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -10); /* line 6683 */
} /* line 6683 */
  sim_icache_fetch(3606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6685 */
l_L185X3: ;/* line 6688 */
__LABEL(l_L185X3);
  sim_icache_fetch(3607 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -9); /* line 6690 */
} /* line 6690 */
  sim_icache_fetch(3608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6692 */
l_L184X3: ;/* line 6695 */
__LABEL(l_L184X3);
  sim_icache_fetch(3609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -8); /* line 6697 */
} /* line 6697 */
  sim_icache_fetch(3610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6699 */
l_L183X3: ;/* line 6702 */
__LABEL(l_L183X3);
  sim_icache_fetch(3611 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -7); /* line 6704 */
} /* line 6704 */
  sim_icache_fetch(3612 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6706 */
l_L182X3: ;/* line 6709 */
__LABEL(l_L182X3);
  sim_icache_fetch(3613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -6); /* line 6711 */
} /* line 6711 */
  sim_icache_fetch(3614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6713 */
l_L181X3: ;/* line 6716 */
__LABEL(l_L181X3);
  sim_icache_fetch(3615 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -5); /* line 6718 */
} /* line 6718 */
  sim_icache_fetch(3616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6720 */
l_L180X3: ;/* line 6723 */
__LABEL(l_L180X3);
  sim_icache_fetch(3617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -4); /* line 6725 */
} /* line 6725 */
  sim_icache_fetch(3618 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6727 */
l_L179X3: ;/* line 6730 */
__LABEL(l_L179X3);
  sim_icache_fetch(3619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -3); /* line 6732 */
} /* line 6732 */
  sim_icache_fetch(3620 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6734 */
l_L178X3: ;/* line 6737 */
__LABEL(l_L178X3);
  sim_icache_fetch(3621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -2); /* line 6739 */
} /* line 6739 */
  sim_icache_fetch(3622 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 6741 */
l_L177X3: ;/* line 6744 */
__LABEL(l_L177X3);
  sim_icache_fetch(3623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_58, reg_r0_19, (unsigned int) -1); /* line 6745 */
} /* line 6745 */
l_L193X3: ;/* line 6747 */
__LABEL(l_L193X3);
  sim_icache_fetch(3624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 6748 */
} /* line 6748 */
  sim_icache_fetch(3626 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 6750 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6751 */
   __ADD_CYCLES(1);
} /* line 6751 */
  sim_icache_fetch(3629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 6753 */
} /* line 6753 */
  sim_icache_fetch(3630 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L195X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6755 */
l_L194X3: ;/* line 6757 */
__LABEL(l_L194X3);
  sim_icache_fetch(3631 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_59, reg_r0_41); /* line 6759 */
} /* line 6759 */
  sim_icache_fetch(3632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L152X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L152X3;
} /* line 6761 */
l_L173X3: ;/* line 6765 */
__LABEL(l_L173X3);
  sim_icache_fetch(3633 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6765 */
  sim_icache_fetch(3634 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6767 */
} /* line 6767 */
  sim_icache_fetch(3636 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 6770 */
} /* line 6770 */
  sim_icache_fetch(3637 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6772 */
l_L172X3: ;/* line 6776 */
__LABEL(l_L172X3);
  sim_icache_fetch(3638 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6776 */
  sim_icache_fetch(3639 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6778 */
} /* line 6778 */
  sim_icache_fetch(3641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 6781 */
} /* line 6781 */
  sim_icache_fetch(3642 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6783 */
l_L171X3: ;/* line 6787 */
__LABEL(l_L171X3);
  sim_icache_fetch(3643 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6787 */
  sim_icache_fetch(3644 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6789 */
} /* line 6789 */
  sim_icache_fetch(3646 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 6792 */
} /* line 6792 */
  sim_icache_fetch(3647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6794 */
l_L170X3: ;/* line 6798 */
__LABEL(l_L170X3);
  sim_icache_fetch(3648 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6798 */
  sim_icache_fetch(3649 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6800 */
} /* line 6800 */
  sim_icache_fetch(3651 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 6803 */
} /* line 6803 */
  sim_icache_fetch(3652 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6805 */
l_L169X3: ;/* line 6809 */
__LABEL(l_L169X3);
  sim_icache_fetch(3653 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6809 */
  sim_icache_fetch(3654 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6811 */
} /* line 6811 */
  sim_icache_fetch(3656 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 6814 */
} /* line 6814 */
  sim_icache_fetch(3657 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6816 */
l_L168X3: ;/* line 6820 */
__LABEL(l_L168X3);
  sim_icache_fetch(3658 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6820 */
  sim_icache_fetch(3659 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6822 */
} /* line 6822 */
  sim_icache_fetch(3661 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 6825 */
} /* line 6825 */
  sim_icache_fetch(3662 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6827 */
l_L167X3: ;/* line 6831 */
__LABEL(l_L167X3);
  sim_icache_fetch(3663 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6831 */
  sim_icache_fetch(3664 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6833 */
} /* line 6833 */
  sim_icache_fetch(3666 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 6836 */
} /* line 6836 */
  sim_icache_fetch(3667 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6838 */
l_L166X3: ;/* line 6842 */
__LABEL(l_L166X3);
  sim_icache_fetch(3668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6842 */
  sim_icache_fetch(3669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6844 */
} /* line 6844 */
  sim_icache_fetch(3671 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 6847 */
} /* line 6847 */
  sim_icache_fetch(3672 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6849 */
l_L165X3: ;/* line 6853 */
__LABEL(l_L165X3);
  sim_icache_fetch(3673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6853 */
  sim_icache_fetch(3674 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6855 */
} /* line 6855 */
  sim_icache_fetch(3676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 6858 */
} /* line 6858 */
  sim_icache_fetch(3677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6860 */
l_L164X3: ;/* line 6864 */
__LABEL(l_L164X3);
  sim_icache_fetch(3678 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6864 */
  sim_icache_fetch(3679 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6866 */
} /* line 6866 */
  sim_icache_fetch(3681 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 6869 */
} /* line 6869 */
  sim_icache_fetch(3682 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6871 */
l_L163X3: ;/* line 6875 */
__LABEL(l_L163X3);
  sim_icache_fetch(3683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6875 */
  sim_icache_fetch(3684 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6877 */
} /* line 6877 */
  sim_icache_fetch(3686 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 6880 */
} /* line 6880 */
  sim_icache_fetch(3687 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6882 */
l_L162X3: ;/* line 6886 */
__LABEL(l_L162X3);
  sim_icache_fetch(3688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6886 */
  sim_icache_fetch(3689 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6888 */
} /* line 6888 */
  sim_icache_fetch(3691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 6891 */
} /* line 6891 */
  sim_icache_fetch(3692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6893 */
l_L161X3: ;/* line 6897 */
__LABEL(l_L161X3);
  sim_icache_fetch(3693 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6897 */
  sim_icache_fetch(3694 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6899 */
} /* line 6899 */
  sim_icache_fetch(3696 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 6902 */
} /* line 6902 */
  sim_icache_fetch(3697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6904 */
l_L160X3: ;/* line 6908 */
__LABEL(l_L160X3);
  sim_icache_fetch(3698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6908 */
  sim_icache_fetch(3699 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6910 */
} /* line 6910 */
  sim_icache_fetch(3701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 6913 */
} /* line 6913 */
  sim_icache_fetch(3702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 6915 */
l_L159X3: ;/* line 6919 */
__LABEL(l_L159X3);
  sim_icache_fetch(3703 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6919 */
  sim_icache_fetch(3704 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 6921 */
} /* line 6921 */
  sim_icache_fetch(3706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 6923 */
l_L175X3: ;/* line 6925 */
__LABEL(l_L175X3);
  sim_icache_fetch(3707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -15); /* line 6926 */
} /* line 6926 */
  sim_icache_fetch(3708 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -14); /* line 6928 */
} /* line 6928 */
  sim_icache_fetch(3709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -13); /* line 6930 */
} /* line 6930 */
  sim_icache_fetch(3710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -12); /* line 6932 */
} /* line 6932 */
  sim_icache_fetch(3711 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -11); /* line 6934 */
} /* line 6934 */
  sim_icache_fetch(3712 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -10); /* line 6936 */
} /* line 6936 */
  sim_icache_fetch(3713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -9); /* line 6938 */
} /* line 6938 */
  sim_icache_fetch(3714 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -8); /* line 6940 */
} /* line 6940 */
  sim_icache_fetch(3715 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -7); /* line 6942 */
} /* line 6942 */
  sim_icache_fetch(3716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -6); /* line 6944 */
} /* line 6944 */
  sim_icache_fetch(3717 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -5); /* line 6946 */
} /* line 6946 */
  sim_icache_fetch(3718 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -4); /* line 6948 */
} /* line 6948 */
  sim_icache_fetch(3719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -2); /* line 6950 */
} /* line 6950 */
  sim_icache_fetch(3720 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_6); /* line 6952 */
} /* line 6952 */
  sim_icache_fetch(3721 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -3); /* line 6954 */
} /* line 6954 */
  sim_icache_fetch(3722 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_5, (unsigned int) -1); /* line 6956 */
} /* line 6956 */
  sim_icache_fetch(3723 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) 1); /* line 6958 */
} /* line 6958 */
  sim_icache_fetch(3724 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 6960 */
} /* line 6960 */
  sim_icache_fetch(3725 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 6962 */
} /* line 6962 */
  sim_icache_fetch(3726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, reg_r0_2); /* line 6965 */
} /* line 6965 */
  sim_icache_fetch(3727 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 6967 */
l_L157X3: ;/* line 6970 */
__LABEL(l_L157X3);
  sim_icache_fetch(3728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, reg_r0_58); /* line 6971 */
} /* line 6971 */
  sim_icache_fetch(3729 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_4); /* line 6973 */
} /* line 6973 */
  sim_icache_fetch(3730 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 6976 */
} /* line 6976 */
  sim_icache_fetch(3732 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 6978 */
l_L153X3: ;/* line 6981 */
__LABEL(l_L153X3);
  sim_icache_fetch(3733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6982 */
} /* line 6982 */
  sim_icache_fetch(3734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6984 */
} /* line 6984 */
  sim_icache_fetch(3735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 6986 */
} /* line 6986 */
  sim_icache_fetch(3736 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 6988 */
} /* line 6988 */
  sim_icache_fetch(3737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 6990 */
} /* line 6990 */
  sim_icache_fetch(3738 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6993 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 305: goto l_L149X3;
    case 306: goto l_L150X3;
    case 308: goto l_lr_207;
    case 309: goto l_L151X3;
    case 310: goto l_L152X3;
    case 312: goto l_lr_211;
    case 313: goto l_L155X3;
    case 314: goto l_L156X3;
    case 316: goto l_lr_215;
    case 317: goto l_L154X3;
    case 318: goto l_L158X3;
    case 319: goto l_L174X3;
    case 320: goto l_L176X3;
    case 321: goto l_L192X3;
    case 322: goto l_L195X3;
    case 323: goto l_L191X3;
    case 324: goto l_L190X3;
    case 325: goto l_L189X3;
    case 326: goto l_L188X3;
    case 327: goto l_L187X3;
    case 328: goto l_L186X3;
    case 329: goto l_L185X3;
    case 330: goto l_L184X3;
    case 331: goto l_L183X3;
    case 332: goto l_L182X3;
    case 333: goto l_L181X3;
    case 334: goto l_L180X3;
    case 335: goto l_L179X3;
    case 336: goto l_L178X3;
    case 337: goto l_L177X3;
    case 338: goto l_L193X3;
    case 339: goto l_L194X3;
    case 340: goto l_L173X3;
    case 341: goto l_L172X3;
    case 342: goto l_L171X3;
    case 343: goto l_L170X3;
    case 344: goto l_L169X3;
    case 345: goto l_L168X3;
    case 346: goto l_L167X3;
    case 347: goto l_L166X3;
    case 348: goto l_L165X3;
    case 349: goto l_L164X3;
    case 350: goto l_L163X3;
    case 351: goto l_L162X3;
    case 352: goto l_L161X3;
    case 353: goto l_L160X3;
    case 354: goto l_L159X3;
    case 355: goto l_L175X3;
    case 356: goto l_L157X3;
    case 357: goto l_L153X3;
    case 358:
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
  reg_l0_0 = (386 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3739 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 7011 */
  sim_icache_fetch(3740 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 7013 */
} /* line 7013 */
  sim_icache_fetch(3742 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 7015 */
} /* line 7015 */
  sim_icache_fetch(3744 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 7017 */
} /* line 7017 */
  sim_icache_fetch(3746 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 7019 */
} /* line 7019 */
  sim_icache_fetch(3748 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 7021 */
} /* line 7021 */
  sim_icache_fetch(3749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 7023 */
} /* line 7023 */
  sim_icache_fetch(3751 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 7025 */
} /* line 7025 */
  sim_icache_fetch(3753 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_r0_8, reg_r0_5, reg_r0_6); /* line 7027 */
} /* line 7027 */
  sim_icache_fetch(3754 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_8); /* line 7029 */
} /* line 7029 */
  sim_icache_fetch(3755 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 7031 */
} /* line 7031 */
  sim_icache_fetch(3757 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 7033 */
} /* line 7033 */
  sim_icache_fetch(3758 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_5, reg_r0_7, reg_r0_8); /* line 7035 */
} /* line 7035 */
  sim_icache_fetch(3759 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_1, reg_r0_4, reg_r0_5); /* line 7037 */
} /* line 7037 */
  sim_icache_fetch(3760 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L196X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7039 */
  sim_icache_fetch(3761 + t_thisfile.offset, 1);
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
} /* line 7041 */
  sim_icache_fetch(3762 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 7043 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 7044 */
   __ADD_CYCLES(1);
} /* line 7044 */
  sim_icache_fetch(3765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7046 */
} /* line 7046 */
  sim_icache_fetch(3766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_4, reg_r0_2); /* line 7048 */
} /* line 7048 */
  sim_icache_fetch(3767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_4); /* line 7050 */
} /* line 7050 */
  sim_icache_fetch(3769 + t_thisfile.offset, 1);
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
} /* line 7052 */
  sim_icache_fetch(3770 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 7054 */
} /* line 7054 */
l_L197X3: ;/* line 7057 */
__LABEL(l_L197X3);
  sim_icache_fetch(3772 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 7058 */
} /* line 7058 */
  sim_icache_fetch(3774 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) 9); /* line 7060 */
} /* line 7060 */
  sim_icache_fetch(3775 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 7062 */
} /* line 7062 */
  sim_icache_fetch(3776 + t_thisfile.offset, 1);
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
} /* line 7064 */
  sim_icache_fetch(3777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 511); /* line 7066 */
} /* line 7066 */
  sim_icache_fetch(3779 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, 0); /* line 7068 */
} /* line 7068 */
  sim_icache_fetch(3780 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_7); /* line 7070 */
} /* line 7070 */
  sim_icache_fetch(3781 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_5); /* line 7072 */
} /* line 7072 */
  sim_icache_fetch(3783 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 7074 */
} /* line 7074 */
  sim_icache_fetch(3785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_2); /* line 7076 */
} /* line 7076 */
  sim_icache_fetch(3787 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, 0, reg_r0_5); /* line 7078 */
} /* line 7078 */
  sim_icache_fetch(3788 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_2); /* line 7080 */
} /* line 7080 */
  sim_icache_fetch(3789 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_19, reg_r0_5); /* line 7082 */
} /* line 7082 */
  sim_icache_fetch(3790 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 7084 */
} /* line 7084 */
l_L200X3: ;/* line 7087 */
__LABEL(l_L200X3);
  sim_icache_fetch(3792 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7088 */
} /* line 7088 */
  sim_icache_fetch(3794 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 7090 */
} /* line 7090 */
  sim_icache_fetch(3795 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7092 */
} /* line 7092 */
  sim_icache_fetch(3796 + t_thisfile.offset, 1);
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
} /* line 7094 */
  sim_icache_fetch(3797 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 7096 */
} /* line 7096 */
  sim_icache_fetch(3798 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7098 */
} /* line 7098 */
  sim_icache_fetch(3800 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 7100 */
} /* line 7100 */
  sim_icache_fetch(3801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) 1); /* line 7102 */
} /* line 7102 */
  sim_icache_fetch(3802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_1, reg_r0_6, 0); /* line 7104 */
} /* line 7104 */
  sim_icache_fetch(3803 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 7106 */
} /* line 7106 */
  sim_icache_fetch(3804 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_2, reg_r0_8, 0); /* line 7108 */
} /* line 7108 */
  sim_icache_fetch(3805 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_8, (unsigned int) 1); /* line 7110 */
} /* line 7110 */
  sim_icache_fetch(3806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 7112 */
} /* line 7112 */
  sim_icache_fetch(3807 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 7114 */
} /* line 7114 */
  sim_icache_fetch(3808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_4, reg_r0_10, 0); /* line 7116 */
} /* line 7116 */
  sim_icache_fetch(3809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 7118 */
} /* line 7118 */
  sim_icache_fetch(3810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_5, reg_r0_11, 0); /* line 7120 */
} /* line 7120 */
  sim_icache_fetch(3811 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 7122 */
} /* line 7122 */
  sim_icache_fetch(3812 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_6, reg_r0_12, 0); /* line 7124 */
} /* line 7124 */
  sim_icache_fetch(3813 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 7126 */
} /* line 7126 */
  sim_icache_fetch(3814 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 7128 */
} /* line 7128 */
  sim_icache_fetch(3815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 7130 */
} /* line 7130 */
  sim_icache_fetch(3816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7132 */
} /* line 7132 */
  sim_icache_fetch(3818 + t_thisfile.offset, 1);
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
} /* line 7134 */
  sim_icache_fetch(3819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7136 */
} /* line 7136 */
  sim_icache_fetch(3821 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 7138 */
} /* line 7138 */
  sim_icache_fetch(3822 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7140 */
} /* line 7140 */
  sim_icache_fetch(3823 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_15, reg_b0_0); /* line 7142 */
} /* line 7142 */
  sim_icache_fetch(3824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 7144 */
} /* line 7144 */
  sim_icache_fetch(3825 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 7146 */
} /* line 7146 */
  sim_icache_fetch(3826 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 7148 */
} /* line 7148 */
  sim_icache_fetch(3828 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 7150 */
} /* line 7150 */
  sim_icache_fetch(3829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7152 */
} /* line 7152 */
  sim_icache_fetch(3831 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 7154 */
} /* line 7154 */
l_L203X3: ;/* line 7156 */
__LABEL(l_L203X3);
  sim_icache_fetch(3832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_16, reg_r0_5); /* line 7157 */
} /* line 7157 */
  sim_icache_fetch(3833 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_17, reg_b0_7); /* line 7159 */
} /* line 7159 */
  sim_icache_fetch(3834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 7161 */
} /* line 7161 */
  sim_icache_fetch(3835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_16, reg_r0_7, (unsigned int) 1); /* line 7163 */
} /* line 7163 */
  sim_icache_fetch(3836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 7165 */
} /* line 7165 */
  sim_icache_fetch(3838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7167 */
  sim_icache_fetch(3839 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7169 */
} /* line 7169 */
  sim_icache_fetch(3840 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7171 */
  sim_icache_fetch(3841 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MTB(reg_b0_1, reg_r0_17); /* line 7173 */
} /* line 7173 */
  sim_icache_fetch(3842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MTB(reg_b0_7, reg_r0_15); /* line 7175 */
} /* line 7175 */
  sim_icache_fetch(3843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7177 */
} /* line 7177 */
  sim_icache_fetch(3845 + t_thisfile.offset, 1);
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
} /* line 7179 */
  sim_icache_fetch(3846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7181 */
} /* line 7181 */
  sim_icache_fetch(3848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_16); /* line 7183 */
} /* line 7183 */
  sim_icache_fetch(3850 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 7185 */
} /* line 7185 */
  sim_icache_fetch(3851 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7187 */
} /* line 7187 */
  sim_icache_fetch(3852 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_7, reg_r0_7); /* line 7189 */
} /* line 7189 */
l_L206X3: ;/* line 7191 */
__LABEL(l_L206X3);
  sim_icache_fetch(3853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_7); /* line 7192 */
} /* line 7192 */
  sim_icache_fetch(3854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 255); /* line 7194 */
} /* line 7194 */
  sim_icache_fetch(3855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_15, reg_b0_7); /* line 7196 */
} /* line 7196 */
  sim_icache_fetch(3856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_7, reg_r0_2, 0); /* line 7198 */
} /* line 7198 */
  sim_icache_fetch(3857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7200 */
} /* line 7200 */
  sim_icache_fetch(3859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_7); /* line 7202 */
} /* line 7202 */
  sim_icache_fetch(3861 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7204 */
  sim_icache_fetch(3862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7206 */
} /* line 7206 */
  sim_icache_fetch(3863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7208 */
  sim_icache_fetch(3864 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) 1); /* line 7210 */
} /* line 7210 */
  sim_icache_fetch(3865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MTB(reg_b0_0, reg_r0_15); /* line 7212 */
} /* line 7212 */
  sim_icache_fetch(3866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7214 */
} /* line 7214 */
  sim_icache_fetch(3868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7216 */
  sim_icache_fetch(3869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7218 */
} /* line 7218 */
  sim_icache_fetch(3871 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 7220 */
} /* line 7220 */
  sim_icache_fetch(3873 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 7222 */
} /* line 7222 */
  sim_icache_fetch(3874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7224 */
} /* line 7224 */
  sim_icache_fetch(3875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 7226 */
} /* line 7226 */
l_L208X3: ;/* line 7228 */
__LABEL(l_L208X3);
  sim_icache_fetch(3876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_5); /* line 7229 */
} /* line 7229 */
  sim_icache_fetch(3877 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_6, (unsigned int) 255); /* line 7231 */
} /* line 7231 */
  sim_icache_fetch(3878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_7, reg_r0_2, 0); /* line 7233 */
} /* line 7233 */
  sim_icache_fetch(3879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7235 */
} /* line 7235 */
  sim_icache_fetch(3881 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 7237 */
} /* line 7237 */
  sim_icache_fetch(3883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7239 */
  sim_icache_fetch(3884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7241 */
} /* line 7241 */
  sim_icache_fetch(3885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7243 */
  sim_icache_fetch(3886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_6, (unsigned int) 1); /* line 7245 */
} /* line 7245 */
  sim_icache_fetch(3887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7247 */
} /* line 7247 */
  sim_icache_fetch(3889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7249 */
  sim_icache_fetch(3890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7251 */
} /* line 7251 */
  sim_icache_fetch(3892 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 7253 */
} /* line 7253 */
  sim_icache_fetch(3894 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 7255 */
} /* line 7255 */
  sim_icache_fetch(3895 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7257 */
} /* line 7257 */
  sim_icache_fetch(3896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 7259 */
} /* line 7259 */
l_L210X3: ;/* line 7261 */
__LABEL(l_L210X3);
  sim_icache_fetch(3897 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_6); /* line 7262 */
} /* line 7262 */
  sim_icache_fetch(3898 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 255); /* line 7264 */
} /* line 7264 */
  sim_icache_fetch(3899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_3, reg_r0_2, 0); /* line 7266 */
} /* line 7266 */
  sim_icache_fetch(3900 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7268 */
} /* line 7268 */
  sim_icache_fetch(3902 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 7270 */
} /* line 7270 */
  sim_icache_fetch(3904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7272 */
  sim_icache_fetch(3905 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7274 */
} /* line 7274 */
  sim_icache_fetch(3906 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7276 */
  sim_icache_fetch(3907 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) 1); /* line 7278 */
} /* line 7278 */
  sim_icache_fetch(3908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7280 */
} /* line 7280 */
  sim_icache_fetch(3910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7282 */
  sim_icache_fetch(3911 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7284 */
} /* line 7284 */
  sim_icache_fetch(3913 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 7286 */
} /* line 7286 */
  sim_icache_fetch(3915 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 7288 */
} /* line 7288 */
  sim_icache_fetch(3916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7290 */
} /* line 7290 */
  sim_icache_fetch(3917 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 7292 */
} /* line 7292 */
l_L212X3: ;/* line 7294 */
__LABEL(l_L212X3);
  sim_icache_fetch(3918 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_5); /* line 7295 */
} /* line 7295 */
  sim_icache_fetch(3919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_6, (unsigned int) 255); /* line 7297 */
} /* line 7297 */
  sim_icache_fetch(3920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_3, reg_r0_2, 0); /* line 7299 */
} /* line 7299 */
  sim_icache_fetch(3921 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7301 */
} /* line 7301 */
  sim_icache_fetch(3923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 7303 */
} /* line 7303 */
  sim_icache_fetch(3925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7305 */
  sim_icache_fetch(3926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7307 */
} /* line 7307 */
  sim_icache_fetch(3927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7309 */
  sim_icache_fetch(3928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_6, (unsigned int) 1); /* line 7311 */
} /* line 7311 */
  sim_icache_fetch(3929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7313 */
} /* line 7313 */
  sim_icache_fetch(3931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7315 */
  sim_icache_fetch(3932 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7317 */
} /* line 7317 */
  sim_icache_fetch(3934 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 7319 */
} /* line 7319 */
  sim_icache_fetch(3936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 7321 */
} /* line 7321 */
  sim_icache_fetch(3937 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7323 */
} /* line 7323 */
  sim_icache_fetch(3938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 7325 */
} /* line 7325 */
l_L214X3: ;/* line 7327 */
__LABEL(l_L214X3);
  sim_icache_fetch(3939 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_6); /* line 7328 */
} /* line 7328 */
  sim_icache_fetch(3940 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 255); /* line 7330 */
} /* line 7330 */
  sim_icache_fetch(3941 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_3, reg_r0_2, 0); /* line 7332 */
} /* line 7332 */
  sim_icache_fetch(3942 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7334 */
} /* line 7334 */
  sim_icache_fetch(3944 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 7336 */
} /* line 7336 */
  sim_icache_fetch(3946 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7338 */
  sim_icache_fetch(3947 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7340 */
} /* line 7340 */
  sim_icache_fetch(3948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7342 */
  sim_icache_fetch(3949 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) 1); /* line 7344 */
} /* line 7344 */
  sim_icache_fetch(3950 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7346 */
} /* line 7346 */
  sim_icache_fetch(3952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7348 */
  sim_icache_fetch(3953 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7350 */
} /* line 7350 */
  sim_icache_fetch(3955 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 7352 */
} /* line 7352 */
  sim_icache_fetch(3957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 7354 */
} /* line 7354 */
  sim_icache_fetch(3958 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7356 */
} /* line 7356 */
  sim_icache_fetch(3959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 7358 */
} /* line 7358 */
l_L216X3: ;/* line 7360 */
__LABEL(l_L216X3);
  sim_icache_fetch(3960 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_5); /* line 7361 */
} /* line 7361 */
  sim_icache_fetch(3961 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_6, (unsigned int) 255); /* line 7363 */
} /* line 7363 */
  sim_icache_fetch(3962 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_3, reg_r0_2, 0); /* line 7365 */
} /* line 7365 */
  sim_icache_fetch(3963 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7367 */
} /* line 7367 */
  sim_icache_fetch(3965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 7369 */
} /* line 7369 */
  sim_icache_fetch(3967 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7371 */
  sim_icache_fetch(3968 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7373 */
} /* line 7373 */
  sim_icache_fetch(3969 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7375 */
  sim_icache_fetch(3970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_6, (unsigned int) 1); /* line 7377 */
} /* line 7377 */
  sim_icache_fetch(3971 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7379 */
} /* line 7379 */
  sim_icache_fetch(3973 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7381 */
  sim_icache_fetch(3974 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7383 */
} /* line 7383 */
  sim_icache_fetch(3976 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 7385 */
} /* line 7385 */
  sim_icache_fetch(3978 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 7387 */
} /* line 7387 */
  sim_icache_fetch(3979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 7389 */
} /* line 7389 */
  sim_icache_fetch(3980 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 7391 */
} /* line 7391 */
l_L218X3: ;/* line 7393 */
__LABEL(l_L218X3);
  sim_icache_fetch(3981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_6); /* line 7394 */
} /* line 7394 */
  sim_icache_fetch(3982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 255); /* line 7396 */
} /* line 7396 */
  sim_icache_fetch(3983 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 7398 */
} /* line 7398 */
  sim_icache_fetch(3984 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7400 */
} /* line 7400 */
  sim_icache_fetch(3986 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 7402 */
} /* line 7402 */
  sim_icache_fetch(3988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7404 */
  sim_icache_fetch(3989 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7406 */
} /* line 7406 */
  sim_icache_fetch(3990 + t_thisfile.offset, 1);
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
} /* line 7408 */
  sim_icache_fetch(3991 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) 1); /* line 7410 */
} /* line 7410 */
  sim_icache_fetch(3992 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 7412 */
} /* line 7412 */
  sim_icache_fetch(3994 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7414 */
  sim_icache_fetch(3995 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 7416 */
} /* line 7416 */
  sim_icache_fetch(3997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 7418 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 7419 */
   __ADD_CYCLES(1);
} /* line 7419 */
  sim_icache_fetch(3999 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 7421 */
} /* line 7421 */
l_L220X3: ;/* line 7423 */
__LABEL(l_L220X3);
  sim_icache_fetch(4000 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_2, reg_r0_5); /* line 7424 */
} /* line 7424 */
  sim_icache_fetch(4001 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 7426 */
} /* line 7426 */
  sim_icache_fetch(4002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 7428 */
} /* line 7428 */
  sim_icache_fetch(4004 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7430 */
  sim_icache_fetch(4005 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 7433 */
} /* line 7433 */
  sim_icache_fetch(4006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L200X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L200X3;
} /* line 7435 */
l_L204X3: ;/* line 7438 */
__LABEL(l_L204X3);
  sim_icache_fetch(4007 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_19, reg_r0_4); /* line 7440 */
} /* line 7440 */
  sim_icache_fetch(4008 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L221X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L221X3;
} /* line 7442 */
l_L222X3: ;/* line 7445 */
__LABEL(l_L222X3);
  sim_icache_fetch(4009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 7446 */
} /* line 7446 */
  sim_icache_fetch(4011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_19, reg_r0_19, (unsigned int) 3); /* line 7448 */
} /* line 7448 */
  sim_icache_fetch(4012 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 1); /* line 7450 */
} /* line 7450 */
  sim_icache_fetch(4013 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_19, reg_r0_2); /* line 7452 */
} /* line 7452 */
  sim_icache_fetch(4014 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, 0); /* line 7454 */
} /* line 7454 */
l_L196X3: ;/* line 7457 */
__LABEL(l_L196X3);
  sim_icache_fetch(4015 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 7458 */
} /* line 7458 */
  sim_icache_fetch(4017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 7460 */
} /* line 7460 */
  sim_icache_fetch(4018 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, reg_r0_4); /* line 7462 */
} /* line 7462 */
  sim_icache_fetch(4019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -8); /* line 7464 */
} /* line 7464 */
  sim_icache_fetch(4020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 8); /* line 7466 */
} /* line 7466 */
  sim_icache_fetch(4021 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_9, reg_r0_7, (unsigned int) 3); /* line 7468 */
} /* line 7468 */
  sim_icache_fetch(4022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) _X1PACKETX15); /* line 7470 */
} /* line 7470 */
  sim_icache_fetch(4024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 2); /* line 7472 */
} /* line 7472 */
  sim_icache_fetch(4025 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_12, reg_r0_9, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 7474 */
} /* line 7474 */
  sim_icache_fetch(4027 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, reg_r0_12); /* line 7476 */
} /* line 7476 */
  sim_icache_fetch(4028 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 7478 */
} /* line 7478 */
  sim_icache_fetch(4029 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -16); /* line 7480 */
} /* line 7480 */
  sim_icache_fetch(4030 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_6); /* line 7482 */
} /* line 7482 */
  sim_icache_fetch(4031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 7484 */
} /* line 7484 */
  sim_icache_fetch(4033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, (unsigned int) 16, reg_r0_4); /* line 7486 */
} /* line 7486 */
  sim_icache_fetch(4034 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_11, reg_r0_11, reg_r0_5); /* line 7488 */
} /* line 7488 */
  sim_icache_fetch(4035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_5, (unsigned int) 8, reg_r0_4); /* line 7490 */
} /* line 7490 */
  sim_icache_fetch(4036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_6, reg_b0_0, reg_r0_6, reg_r0_5); /* line 7492 */
} /* line 7492 */
  sim_icache_fetch(4037 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_11, reg_r0_11, reg_r0_6); /* line 7494 */
} /* line 7494 */
  sim_icache_fetch(4038 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBUs(reg_r0_10, mem_trace_ld((reg_r0_10 + (unsigned int) 1),0,1)); /* line 7496 */
} /* line 7496 */
  sim_icache_fetch(4039 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_9 + (unsigned int) _X1PACKETX15),0,1)); /* line 7498 */
} /* line 7498 */
  sim_icache_fetch(4041 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_10, reg_r0_10, reg_r0_5); /* line 7500 */
} /* line 7500 */
  sim_icache_fetch(4042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_9, reg_r0_9, reg_r0_4); /* line 7502 */
} /* line 7502 */
  sim_icache_fetch(4043 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_10, reg_r0_9, reg_r0_10); /* line 7504 */
} /* line 7504 */
  sim_icache_fetch(4044 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_10, reg_b0_0, reg_r0_10, reg_r0_9); /* line 7506 */
} /* line 7506 */
  sim_icache_fetch(4045 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_3, reg_r0_10, reg_r0_11); /* line 7508 */
} /* line 7508 */
  sim_icache_fetch(4046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_7); /* line 7510 */
} /* line 7510 */
  sim_icache_fetch(4047 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_2); /* line 7512 */
} /* line 7512 */
  sim_icache_fetch(4049 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 7514 */
} /* line 7514 */
  sim_icache_fetch(4051 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7517 */
l_L219X3: ;/* line 7520 */
__LABEL(l_L219X3);
  sim_icache_fetch(4052 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 7522 */
} /* line 7522 */
  sim_icache_fetch(4053 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 7524 */
l_L201X3: ;/* line 7527 */
__LABEL(l_L201X3);
  sim_icache_fetch(4054 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MAX(reg_r0_19, reg_r0_19, 0); /* line 7528 */
} /* line 7528 */
l_L221X3: ;/* line 7530 */
__LABEL(l_L221X3);
  sim_icache_fetch(4055 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_19, 0); /* line 7531 */
} /* line 7531 */
  sim_icache_fetch(4056 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7533 */
  sim_icache_fetch(4057 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) -1); /* line 7535 */
} /* line 7535 */
  sim_icache_fetch(4058 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_19); /* line 7537 */
} /* line 7537 */
  sim_icache_fetch(4060 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_18); /* line 7539 */
} /* line 7539 */
  sim_icache_fetch(4062 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7542 */
l_L217X3: ;/* line 7545 */
__LABEL(l_L217X3);
  sim_icache_fetch(4063 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7546 */
} /* line 7546 */
  sim_icache_fetch(4065 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 7548 */
} /* line 7548 */
  sim_icache_fetch(4066 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -1); /* line 7551 */
} /* line 7551 */
  sim_icache_fetch(4067 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L218X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L218X3;
} /* line 7553 */
l_L215X3: ;/* line 7556 */
__LABEL(l_L215X3);
  sim_icache_fetch(4068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7557 */
} /* line 7557 */
  sim_icache_fetch(4070 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 7559 */
} /* line 7559 */
  sim_icache_fetch(4071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_6, (unsigned int) -1); /* line 7562 */
} /* line 7562 */
  sim_icache_fetch(4072 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L216X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L216X3;
} /* line 7564 */
l_L213X3: ;/* line 7567 */
__LABEL(l_L213X3);
  sim_icache_fetch(4073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7568 */
} /* line 7568 */
  sim_icache_fetch(4075 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 7570 */
} /* line 7570 */
  sim_icache_fetch(4076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -1); /* line 7573 */
} /* line 7573 */
  sim_icache_fetch(4077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L214X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L214X3;
} /* line 7575 */
l_L211X3: ;/* line 7578 */
__LABEL(l_L211X3);
  sim_icache_fetch(4078 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7579 */
} /* line 7579 */
  sim_icache_fetch(4080 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 7581 */
} /* line 7581 */
  sim_icache_fetch(4081 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_6, (unsigned int) -1); /* line 7584 */
} /* line 7584 */
  sim_icache_fetch(4082 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L212X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L212X3;
} /* line 7586 */
l_L209X3: ;/* line 7589 */
__LABEL(l_L209X3);
  sim_icache_fetch(4083 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7590 */
} /* line 7590 */
  sim_icache_fetch(4085 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 7592 */
} /* line 7592 */
  sim_icache_fetch(4086 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -1); /* line 7595 */
} /* line 7595 */
  sim_icache_fetch(4087 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L210X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L210X3;
} /* line 7597 */
l_L207X3: ;/* line 7600 */
__LABEL(l_L207X3);
  sim_icache_fetch(4088 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7601 */
} /* line 7601 */
  sim_icache_fetch(4090 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 7603 */
} /* line 7603 */
  sim_icache_fetch(4091 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_6, (unsigned int) -1); /* line 7606 */
} /* line 7606 */
  sim_icache_fetch(4092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L208X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L208X3;
} /* line 7608 */
l_L205X3: ;/* line 7611 */
__LABEL(l_L205X3);
  sim_icache_fetch(4093 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7612 */
} /* line 7612 */
  sim_icache_fetch(4095 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, (unsigned int) -1); /* line 7614 */
} /* line 7614 */
  sim_icache_fetch(4096 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -1); /* line 7617 */
} /* line 7617 */
  sim_icache_fetch(4097 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L206X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L206X3;
} /* line 7619 */
l_L202X3: ;/* line 7622 */
__LABEL(l_L202X3);
  sim_icache_fetch(4098 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_16, mem_trace_ld((unsigned int) buflen,0,4)); /* line 7623 */
} /* line 7623 */
  sim_icache_fetch(4100 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 7625 */
} /* line 7625 */
  sim_icache_fetch(4102 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_16, (unsigned int) -1); /* line 7627 */
} /* line 7627 */
  sim_icache_fetch(4103 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 7629 */
} /* line 7629 */
  sim_icache_fetch(4104 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 7631 */
} /* line 7631 */
  sim_icache_fetch(4105 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 7633 */
} /* line 7633 */
  sim_icache_fetch(4106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_r0_15, reg_r0_14, 0); /* line 7636 */
} /* line 7636 */
  sim_icache_fetch(4107 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L203X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L203X3;
} /* line 7638 */
l_L199X3: ;/* line 7641 */
__LABEL(l_L199X3);
  sim_icache_fetch(4108 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_19, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 7642 */
} /* line 7642 */
  sim_icache_fetch(4110 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, 0); /* line 7644 */
} /* line 7644 */
  sim_icache_fetch(4111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, 0, reg_r0_19); /* line 7646 */
} /* line 7646 */
  sim_icache_fetch(4112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_2); /* line 7648 */
} /* line 7648 */
  sim_icache_fetch(4113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_7); /* line 7651 */
} /* line 7651 */
  sim_icache_fetch(4114 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L200X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L200X3;
} /* line 7653 */
l_L198X3: ;/* line 7656 */
__LABEL(l_L198X3);
  sim_icache_fetch(4115 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 7657 */
} /* line 7657 */
  sim_icache_fetch(4117 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 7659 */
} /* line 7659 */
  sim_icache_fetch(4118 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 7661 */
} /* line 7661 */
  sim_icache_fetch(4119 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 7663 */
} /* line 7663 */
  sim_icache_fetch(4120 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 7666 */
} /* line 7666 */
  sim_icache_fetch(4122 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L197X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L197X3;
} /* line 7668 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 359: goto l_L197X3;
    case 360: goto l_L200X3;
    case 361: goto l_L203X3;
    case 362: goto l_L206X3;
    case 363: goto l_L208X3;
    case 364: goto l_L210X3;
    case 365: goto l_L212X3;
    case 366: goto l_L214X3;
    case 367: goto l_L216X3;
    case 368: goto l_L218X3;
    case 369: goto l_L220X3;
    case 370: goto l_L204X3;
    case 371: goto l_L222X3;
    case 372: goto l_L196X3;
    case 373: goto l_L219X3;
    case 374: goto l_L201X3;
    case 375: goto l_L221X3;
    case 376: goto l_L217X3;
    case 377: goto l_L215X3;
    case 378: goto l_L213X3;
    case 379: goto l_L211X3;
    case 380: goto l_L209X3;
    case 381: goto l_L207X3;
    case 382: goto l_L205X3;
    case 383: goto l_L202X3;
    case 384: goto l_L199X3;
    case 385: goto l_L198X3;
    case 386:
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
  reg_l0_0 = (389 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4123 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 7690 */
} /* line 7690 */
  sim_icache_fetch(4124 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 7692 */
} /* line 7692 */
  sim_icache_fetch(4125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 7694 */
} /* line 7694 */
		 /* line 7695 */
  sim_icache_fetch(4127 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (389 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 7697 */
l_lr_287: ;/* line 7697 */
__LABEL(l_lr_287);
  sim_icache_fetch(4129 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 7699 */
} /* line 7699 */
  sim_icache_fetch(4130 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 7701 */
} /* line 7701 */
  sim_icache_fetch(4131 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7704 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 388: goto l_lr_287;
    case 389:
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
  reg_l0_0 = (391 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4132 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 7749 */
  sim_icache_fetch(4133 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 7751 */
} /* line 7751 */
  sim_icache_fetch(4135 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7753 */
} /* line 7753 */
  sim_icache_fetch(4136 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 7755 */
} /* line 7755 */
  sim_icache_fetch(4137 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7757 */
  sim_icache_fetch(4138 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7760 */
l_L223X3: ;/* line 7763 */
__LABEL(l_L223X3);
  sim_icache_fetch(4139 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 7764 */
} /* line 7764 */
  sim_icache_fetch(4140 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7767 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 390: goto l_L223X3;
    case 391:
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
  reg_l0_0 = (392 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4141 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 7782 */
  sim_icache_fetch(4142 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 7784 */
} /* line 7784 */
  sim_icache_fetch(4143 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7787 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 392:
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
  reg_l0_0 = (396 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4144 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 7802 */
} /* line 7802 */
  sim_icache_fetch(4145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 7804 */
} /* line 7804 */
  sim_icache_fetch(4146 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 7806 */
} /* line 7806 */
  sim_icache_fetch(4148 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 7808 */
} /* line 7808 */
  sim_icache_fetch(4150 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 7810 */
} /* line 7810 */
  sim_icache_fetch(4151 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7812 */
		 /* line 7813 */
  sim_icache_fetch(4152 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (396 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 7815 */
l_lr_293: ;/* line 7815 */
__LABEL(l_lr_293);
l_L224X3: ;/* line 7817 */
__LABEL(l_L224X3);
  sim_icache_fetch(4154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 7818 */
} /* line 7818 */
  sim_icache_fetch(4155 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 7820 */
} /* line 7820 */
  sim_icache_fetch(4156 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7823 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 394: goto l_lr_293;
    case 395: goto l_L224X3;
    case 396:
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
  reg_l0_0 = (410 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4157 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 7869 */
} /* line 7869 */
  sim_icache_fetch(4158 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 7871 */
} /* line 7871 */
  sim_icache_fetch(4159 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 7873 */
} /* line 7873 */
  sim_icache_fetch(4161 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 7875 */
} /* line 7875 */
  sim_icache_fetch(4163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 10000); /* line 7877 */
} /* line 7877 */
  sim_icache_fetch(4165 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 7879 */
} /* line 7879 */
  sim_icache_fetch(4167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 7881 */
} /* line 7881 */
  sim_icache_fetch(4168 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 7883 */
} /* line 7883 */
  sim_icache_fetch(4169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 2147483647); /* line 7885 */
} /* line 7885 */
  sim_icache_fetch(4171 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_4); /* line 7887 */
} /* line 7887 */
  sim_icache_fetch(4173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7889 */
  sim_icache_fetch(4174 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7891 */
l_L227X3: ;/* line 7894 */
__LABEL(l_L227X3);
  sim_icache_fetch(4175 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) ratio,0,4)); /* line 7895 */
} /* line 7895 */
  sim_icache_fetch(4177 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 7897 */
} /* line 7897 */
  sim_icache_fetch(4178 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, reg_r0_4); /* line 7899 */
} /* line 7899 */
  sim_icache_fetch(4179 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7901 */
  sim_icache_fetch(4180 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7903 */
} /* line 7903 */
  sim_icache_fetch(4181 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_2); /* line 7905 */
} /* line 7905 */
l_L229X3: ;/* line 7907 */
__LABEL(l_L229X3);
  sim_icache_fetch(4183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7909 */
l_L228X3: ;/* line 7912 */
__LABEL(l_L228X3);
  sim_icache_fetch(4184 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 7913 */
} /* line 7913 */
  sim_icache_fetch(4186 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 7915 */
} /* line 7915 */
		 /* line 7916 */
  sim_icache_fetch(4188 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (410 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 7918 */
l_lr_300: ;/* line 7918 */
__LABEL(l_lr_300);
  sim_icache_fetch(4190 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) 257); /* line 7920 */
} /* line 7920 */
  sim_icache_fetch(4192 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 7922 */
} /* line 7922 */
  sim_icache_fetch(4193 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 7924 */
} /* line 7924 */
  sim_icache_fetch(4195 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 7926 */
} /* line 7926 */
  sim_icache_fetch(4197 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 7928 */
} /* line 7928 */
		 /* line 7929 */
  sim_icache_fetch(4199 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (410 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 7931 */
l_lr_302: ;/* line 7931 */
__LABEL(l_lr_302);
  sim_icache_fetch(4201 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 7933 */
} /* line 7933 */
  sim_icache_fetch(4202 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7936 */
} /* line 7936 */
  sim_icache_fetch(4203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 7938 */
l_L226X3: ;/* line 7941 */
__LABEL(l_L226X3);
  sim_icache_fetch(4204 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) in_count,0,4)); /* line 7942 */
} /* line 7942 */
  sim_icache_fetch(4206 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, reg_r0_3); /* line 7944 */
} /* line 7944 */
  sim_icache_fetch(4207 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_5); /* line 7946 */
} /* line 7946 */
		 /* line 7947 */
  sim_icache_fetch(4208 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (410 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 7949 */
l_lr_305: ;/* line 7949 */
__LABEL(l_lr_305);
  sim_icache_fetch(4210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_3); /* line 7952 */
} /* line 7952 */
  sim_icache_fetch(4211 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L227X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L227X3;
} /* line 7954 */
l_L225X3: ;/* line 7957 */
__LABEL(l_L225X3);
  sim_icache_fetch(4212 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) in_count,0,4)); /* line 7958 */
} /* line 7958 */
  sim_icache_fetch(4214 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 7960 */
} /* line 7960 */
  sim_icache_fetch(4216 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_5, (unsigned int) 8); /* line 7962 */
} /* line 7962 */
		 /* line 7963 */
  sim_icache_fetch(4217 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (410 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 7965 */
l_lr_308: ;/* line 7965 */
__LABEL(l_lr_308);
  sim_icache_fetch(4219 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_3); /* line 7968 */
} /* line 7968 */
  sim_icache_fetch(4220 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L227X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L227X3;
} /* line 7970 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 397: goto l_L227X3;
    case 398: goto l_L229X3;
    case 399: goto l_L228X3;
    case 401: goto l_lr_300;
    case 403: goto l_lr_302;
    case 404: goto l_L226X3;
    case 406: goto l_lr_305;
    case 407: goto l_L225X3;
    case 409: goto l_lr_308;
    case 410:
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
  reg_l0_0 = (428 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4221 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 7988 */
  sim_icache_fetch(4222 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_5, reg_r0_3, (unsigned int) htab); /* line 7990 */
} /* line 7990 */
  sim_icache_fetch(4224 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -64); /* line 7992 */
} /* line 7992 */
  sim_icache_fetch(4225 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -16); /* line 7994 */
} /* line 7994 */
  sim_icache_fetch(4226 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 7996 */
} /* line 7996 */
l_L230X3: ;/* line 7999 */
__LABEL(l_L230X3);
  sim_icache_fetch(4227 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_2); /* line 8000 */
} /* line 8000 */
  sim_icache_fetch(4228 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_4); /* line 8002 */
} /* line 8002 */
  sim_icache_fetch(4229 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 8004 */
} /* line 8004 */
  sim_icache_fetch(4230 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 8006 */
} /* line 8006 */
  sim_icache_fetch(4231 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 8008 */
} /* line 8008 */
  sim_icache_fetch(4232 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 8010 */
} /* line 8010 */
  sim_icache_fetch(4233 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 8012 */
} /* line 8012 */
  sim_icache_fetch(4234 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 8014 */
} /* line 8014 */
  sim_icache_fetch(4235 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 8016 */
} /* line 8016 */
  sim_icache_fetch(4236 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 8018 */
} /* line 8018 */
  sim_icache_fetch(4237 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 8020 */
} /* line 8020 */
  sim_icache_fetch(4238 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_8); /* line 8022 */
} /* line 8022 */
  sim_icache_fetch(4239 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_8); /* line 8024 */
} /* line 8024 */
  sim_icache_fetch(4240 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_8); /* line 8026 */
} /* line 8026 */
  sim_icache_fetch(4241 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_8); /* line 8028 */
} /* line 8028 */
  sim_icache_fetch(4242 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_8); /* line 8030 */
} /* line 8030 */
  sim_icache_fetch(4243 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_8); /* line 8032 */
} /* line 8032 */
  sim_icache_fetch(4244 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_8); /* line 8034 */
} /* line 8034 */
  sim_icache_fetch(4245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_8); /* line 8036 */
} /* line 8036 */
  sim_icache_fetch(4246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_8); /* line 8038 */
} /* line 8038 */
  sim_icache_fetch(4247 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_8); /* line 8040 */
} /* line 8040 */
  sim_icache_fetch(4248 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_8); /* line 8042 */
} /* line 8042 */
  sim_icache_fetch(4249 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_8); /* line 8044 */
} /* line 8044 */
  sim_icache_fetch(4250 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_8); /* line 8046 */
} /* line 8046 */
  sim_icache_fetch(4251 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_8); /* line 8048 */
} /* line 8048 */
  sim_icache_fetch(4252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_8); /* line 8050 */
} /* line 8050 */
  sim_icache_fetch(4253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_8); /* line 8052 */
} /* line 8052 */
  sim_icache_fetch(4254 + t_thisfile.offset, 1);
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
} /* line 8054 */
  sim_icache_fetch(4255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 8056 */
} /* line 8056 */
  sim_icache_fetch(4256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_8); /* line 8058 */
} /* line 8058 */
  sim_icache_fetch(4257 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_8); /* line 8060 */
} /* line 8060 */
  sim_icache_fetch(4258 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_8); /* line 8062 */
} /* line 8062 */
  sim_icache_fetch(4259 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_8); /* line 8064 */
} /* line 8064 */
  sim_icache_fetch(4260 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_8); /* line 8066 */
} /* line 8066 */
  sim_icache_fetch(4261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_8); /* line 8068 */
} /* line 8068 */
  sim_icache_fetch(4262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_8); /* line 8070 */
} /* line 8070 */
  sim_icache_fetch(4263 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_8); /* line 8072 */
} /* line 8072 */
  sim_icache_fetch(4264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_8); /* line 8074 */
} /* line 8074 */
  sim_icache_fetch(4265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_8); /* line 8076 */
} /* line 8076 */
  sim_icache_fetch(4266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_8); /* line 8078 */
} /* line 8078 */
  sim_icache_fetch(4267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_8); /* line 8080 */
} /* line 8080 */
  sim_icache_fetch(4268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_8); /* line 8082 */
} /* line 8082 */
  sim_icache_fetch(4269 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_8); /* line 8084 */
} /* line 8084 */
  sim_icache_fetch(4270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_8); /* line 8086 */
} /* line 8086 */
  sim_icache_fetch(4271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_8); /* line 8088 */
} /* line 8088 */
  sim_icache_fetch(4272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8090 */
  sim_icache_fetch(4273 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 8092 */
} /* line 8092 */
  sim_icache_fetch(4274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_8); /* line 8094 */
} /* line 8094 */
  sim_icache_fetch(4275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_8); /* line 8096 */
} /* line 8096 */
  sim_icache_fetch(4276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_8); /* line 8098 */
} /* line 8098 */
  sim_icache_fetch(4277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_8); /* line 8100 */
} /* line 8100 */
  sim_icache_fetch(4278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_8); /* line 8102 */
} /* line 8102 */
  sim_icache_fetch(4279 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_8); /* line 8104 */
} /* line 8104 */
  sim_icache_fetch(4280 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_8); /* line 8106 */
} /* line 8106 */
  sim_icache_fetch(4281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_8); /* line 8108 */
} /* line 8108 */
  sim_icache_fetch(4282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_8); /* line 8110 */
} /* line 8110 */
  sim_icache_fetch(4283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_8); /* line 8112 */
} /* line 8112 */
  sim_icache_fetch(4284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_8); /* line 8114 */
} /* line 8114 */
  sim_icache_fetch(4285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_8); /* line 8116 */
} /* line 8116 */
  sim_icache_fetch(4286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_8); /* line 8118 */
} /* line 8118 */
  sim_icache_fetch(4287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_8); /* line 8120 */
} /* line 8120 */
  sim_icache_fetch(4288 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_8); /* line 8122 */
} /* line 8122 */
  sim_icache_fetch(4289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_8); /* line 8124 */
} /* line 8124 */
  sim_icache_fetch(4290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8126 */
  sim_icache_fetch(4291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 8128 */
} /* line 8128 */
  sim_icache_fetch(4292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_8); /* line 8130 */
} /* line 8130 */
  sim_icache_fetch(4293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_8); /* line 8132 */
} /* line 8132 */
  sim_icache_fetch(4294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_8); /* line 8134 */
} /* line 8134 */
  sim_icache_fetch(4295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_8); /* line 8136 */
} /* line 8136 */
  sim_icache_fetch(4296 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_8); /* line 8138 */
} /* line 8138 */
  sim_icache_fetch(4297 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_8); /* line 8140 */
} /* line 8140 */
  sim_icache_fetch(4298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_8); /* line 8142 */
} /* line 8142 */
  sim_icache_fetch(4299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_8); /* line 8144 */
} /* line 8144 */
  sim_icache_fetch(4300 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_8); /* line 8146 */
} /* line 8146 */
  sim_icache_fetch(4301 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_8); /* line 8148 */
} /* line 8148 */
  sim_icache_fetch(4302 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_8); /* line 8150 */
} /* line 8150 */
  sim_icache_fetch(4303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_8); /* line 8152 */
} /* line 8152 */
  sim_icache_fetch(4304 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_8); /* line 8154 */
} /* line 8154 */
  sim_icache_fetch(4305 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_8); /* line 8156 */
} /* line 8156 */
  sim_icache_fetch(4306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_8); /* line 8158 */
} /* line 8158 */
  sim_icache_fetch(4307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_8); /* line 8160 */
} /* line 8160 */
  sim_icache_fetch(4308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8162 */
  sim_icache_fetch(4309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 8164 */
} /* line 8164 */
  sim_icache_fetch(4310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 8166 */
} /* line 8166 */
  sim_icache_fetch(4311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_8); /* line 8168 */
} /* line 8168 */
  sim_icache_fetch(4312 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_8); /* line 8170 */
} /* line 8170 */
  sim_icache_fetch(4313 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_8); /* line 8172 */
} /* line 8172 */
  sim_icache_fetch(4314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_8); /* line 8174 */
} /* line 8174 */
  sim_icache_fetch(4315 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_8); /* line 8176 */
} /* line 8176 */
  sim_icache_fetch(4316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_8); /* line 8178 */
} /* line 8178 */
  sim_icache_fetch(4317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_8); /* line 8180 */
} /* line 8180 */
  sim_icache_fetch(4318 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_8); /* line 8182 */
} /* line 8182 */
  sim_icache_fetch(4319 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_8); /* line 8184 */
} /* line 8184 */
  sim_icache_fetch(4320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_8); /* line 8186 */
} /* line 8186 */
  sim_icache_fetch(4321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_8); /* line 8188 */
} /* line 8188 */
  sim_icache_fetch(4322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_8); /* line 8190 */
} /* line 8190 */
  sim_icache_fetch(4323 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_8); /* line 8192 */
} /* line 8192 */
  sim_icache_fetch(4324 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_8); /* line 8194 */
} /* line 8194 */
  sim_icache_fetch(4325 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_8); /* line 8196 */
} /* line 8196 */
  sim_icache_fetch(4326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_8); /* line 8198 */
} /* line 8198 */
  sim_icache_fetch(4327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8200 */
  sim_icache_fetch(4328 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_8); /* line 8202 */
} /* line 8202 */
  sim_icache_fetch(4330 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_8); /* line 8204 */
} /* line 8204 */
  sim_icache_fetch(4332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_8); /* line 8206 */
} /* line 8206 */
  sim_icache_fetch(4334 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_8); /* line 8208 */
} /* line 8208 */
  sim_icache_fetch(4336 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_8); /* line 8210 */
} /* line 8210 */
  sim_icache_fetch(4338 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_8); /* line 8212 */
} /* line 8212 */
  sim_icache_fetch(4340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_8); /* line 8214 */
} /* line 8214 */
  sim_icache_fetch(4342 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_8); /* line 8216 */
} /* line 8216 */
  sim_icache_fetch(4344 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_8); /* line 8218 */
} /* line 8218 */
  sim_icache_fetch(4346 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_8); /* line 8220 */
} /* line 8220 */
  sim_icache_fetch(4348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_8); /* line 8222 */
} /* line 8222 */
  sim_icache_fetch(4350 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_8); /* line 8224 */
} /* line 8224 */
  sim_icache_fetch(4352 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_8); /* line 8226 */
} /* line 8226 */
  sim_icache_fetch(4354 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_8); /* line 8228 */
} /* line 8228 */
  sim_icache_fetch(4356 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_8); /* line 8230 */
} /* line 8230 */
  sim_icache_fetch(4358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_8); /* line 8232 */
} /* line 8232 */
  sim_icache_fetch(4360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8234 */
  sim_icache_fetch(4361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_8); /* line 8236 */
} /* line 8236 */
  sim_icache_fetch(4363 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_8); /* line 8238 */
} /* line 8238 */
  sim_icache_fetch(4365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_8); /* line 8240 */
} /* line 8240 */
  sim_icache_fetch(4367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_8); /* line 8242 */
} /* line 8242 */
  sim_icache_fetch(4369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_8); /* line 8244 */
} /* line 8244 */
  sim_icache_fetch(4371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_8); /* line 8246 */
} /* line 8246 */
  sim_icache_fetch(4373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_8); /* line 8248 */
} /* line 8248 */
  sim_icache_fetch(4375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_8); /* line 8250 */
} /* line 8250 */
  sim_icache_fetch(4377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_8); /* line 8252 */
} /* line 8252 */
  sim_icache_fetch(4379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_8); /* line 8254 */
} /* line 8254 */
  sim_icache_fetch(4381 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_8); /* line 8256 */
} /* line 8256 */
  sim_icache_fetch(4383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_8); /* line 8258 */
} /* line 8258 */
  sim_icache_fetch(4385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_8); /* line 8260 */
} /* line 8260 */
  sim_icache_fetch(4387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_8); /* line 8262 */
} /* line 8262 */
  sim_icache_fetch(4389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_8); /* line 8264 */
} /* line 8264 */
  sim_icache_fetch(4391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_8); /* line 8266 */
} /* line 8266 */
  sim_icache_fetch(4393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8268 */
  sim_icache_fetch(4394 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_8); /* line 8270 */
} /* line 8270 */
  sim_icache_fetch(4396 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_8); /* line 8272 */
} /* line 8272 */
  sim_icache_fetch(4398 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_8); /* line 8274 */
} /* line 8274 */
  sim_icache_fetch(4400 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_8); /* line 8276 */
} /* line 8276 */
  sim_icache_fetch(4402 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_8); /* line 8278 */
} /* line 8278 */
  sim_icache_fetch(4404 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_8); /* line 8280 */
} /* line 8280 */
  sim_icache_fetch(4406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_8); /* line 8282 */
} /* line 8282 */
  sim_icache_fetch(4408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_8); /* line 8284 */
} /* line 8284 */
  sim_icache_fetch(4410 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_8); /* line 8286 */
} /* line 8286 */
  sim_icache_fetch(4412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_8); /* line 8288 */
} /* line 8288 */
  sim_icache_fetch(4414 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_8); /* line 8290 */
} /* line 8290 */
  sim_icache_fetch(4416 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_8); /* line 8292 */
} /* line 8292 */
  sim_icache_fetch(4418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_8); /* line 8294 */
} /* line 8294 */
  sim_icache_fetch(4420 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_8); /* line 8296 */
} /* line 8296 */
  sim_icache_fetch(4422 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_8); /* line 8298 */
} /* line 8298 */
  sim_icache_fetch(4424 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_8); /* line 8300 */
} /* line 8300 */
  sim_icache_fetch(4426 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8302 */
  sim_icache_fetch(4427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_8); /* line 8304 */
} /* line 8304 */
  sim_icache_fetch(4429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_8); /* line 8306 */
} /* line 8306 */
  sim_icache_fetch(4431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_8); /* line 8308 */
} /* line 8308 */
  sim_icache_fetch(4433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_8); /* line 8310 */
} /* line 8310 */
  sim_icache_fetch(4435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_8); /* line 8312 */
} /* line 8312 */
  sim_icache_fetch(4437 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_8); /* line 8314 */
} /* line 8314 */
  sim_icache_fetch(4439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_8); /* line 8316 */
} /* line 8316 */
  sim_icache_fetch(4441 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_8); /* line 8318 */
} /* line 8318 */
  sim_icache_fetch(4443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_8); /* line 8320 */
} /* line 8320 */
  sim_icache_fetch(4445 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_8); /* line 8322 */
} /* line 8322 */
  sim_icache_fetch(4447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_8); /* line 8324 */
} /* line 8324 */
  sim_icache_fetch(4449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_8); /* line 8326 */
} /* line 8326 */
  sim_icache_fetch(4451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_8); /* line 8328 */
} /* line 8328 */
  sim_icache_fetch(4453 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_8); /* line 8330 */
} /* line 8330 */
  sim_icache_fetch(4455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_8); /* line 8332 */
} /* line 8332 */
  sim_icache_fetch(4457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_8); /* line 8334 */
} /* line 8334 */
  sim_icache_fetch(4459 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8336 */
  sim_icache_fetch(4460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_8); /* line 8338 */
} /* line 8338 */
  sim_icache_fetch(4462 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_8); /* line 8340 */
} /* line 8340 */
  sim_icache_fetch(4464 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_8); /* line 8342 */
} /* line 8342 */
  sim_icache_fetch(4466 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_8); /* line 8344 */
} /* line 8344 */
  sim_icache_fetch(4468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_8); /* line 8346 */
} /* line 8346 */
  sim_icache_fetch(4470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_8); /* line 8348 */
} /* line 8348 */
  sim_icache_fetch(4472 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_8); /* line 8350 */
} /* line 8350 */
  sim_icache_fetch(4474 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_8); /* line 8352 */
} /* line 8352 */
  sim_icache_fetch(4476 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_8); /* line 8354 */
} /* line 8354 */
  sim_icache_fetch(4478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_8); /* line 8356 */
} /* line 8356 */
  sim_icache_fetch(4480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_8); /* line 8358 */
} /* line 8358 */
  sim_icache_fetch(4482 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_8); /* line 8360 */
} /* line 8360 */
  sim_icache_fetch(4484 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_8); /* line 8362 */
} /* line 8362 */
  sim_icache_fetch(4486 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_8); /* line 8364 */
} /* line 8364 */
  sim_icache_fetch(4488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_8); /* line 8366 */
} /* line 8366 */
  sim_icache_fetch(4490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_8); /* line 8368 */
} /* line 8368 */
  sim_icache_fetch(4492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8370 */
  sim_icache_fetch(4493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_8); /* line 8372 */
} /* line 8372 */
  sim_icache_fetch(4495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_8); /* line 8374 */
} /* line 8374 */
  sim_icache_fetch(4497 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_8); /* line 8376 */
} /* line 8376 */
  sim_icache_fetch(4499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_8); /* line 8378 */
} /* line 8378 */
  sim_icache_fetch(4501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_8); /* line 8380 */
} /* line 8380 */
  sim_icache_fetch(4503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_8); /* line 8382 */
} /* line 8382 */
  sim_icache_fetch(4505 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_8); /* line 8384 */
} /* line 8384 */
  sim_icache_fetch(4507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_8); /* line 8386 */
} /* line 8386 */
  sim_icache_fetch(4509 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_8); /* line 8388 */
} /* line 8388 */
  sim_icache_fetch(4511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_8); /* line 8390 */
} /* line 8390 */
  sim_icache_fetch(4513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_8); /* line 8392 */
} /* line 8392 */
  sim_icache_fetch(4515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_8); /* line 8394 */
} /* line 8394 */
  sim_icache_fetch(4517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_8); /* line 8396 */
} /* line 8396 */
  sim_icache_fetch(4519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_8); /* line 8398 */
} /* line 8398 */
  sim_icache_fetch(4521 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_8); /* line 8400 */
} /* line 8400 */
  sim_icache_fetch(4523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_8); /* line 8402 */
} /* line 8402 */
  sim_icache_fetch(4525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8404 */
  sim_icache_fetch(4526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_8); /* line 8406 */
} /* line 8406 */
  sim_icache_fetch(4528 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_8); /* line 8408 */
} /* line 8408 */
  sim_icache_fetch(4530 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_8); /* line 8410 */
} /* line 8410 */
  sim_icache_fetch(4532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_8); /* line 8412 */
} /* line 8412 */
  sim_icache_fetch(4534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_8); /* line 8414 */
} /* line 8414 */
  sim_icache_fetch(4536 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_8); /* line 8416 */
} /* line 8416 */
  sim_icache_fetch(4538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_8); /* line 8418 */
} /* line 8418 */
  sim_icache_fetch(4540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_8); /* line 8420 */
} /* line 8420 */
  sim_icache_fetch(4542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_8); /* line 8422 */
} /* line 8422 */
  sim_icache_fetch(4544 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_8); /* line 8424 */
} /* line 8424 */
  sim_icache_fetch(4546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_8); /* line 8426 */
} /* line 8426 */
  sim_icache_fetch(4548 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_8); /* line 8428 */
} /* line 8428 */
  sim_icache_fetch(4550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_8); /* line 8430 */
} /* line 8430 */
  sim_icache_fetch(4552 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_8); /* line 8432 */
} /* line 8432 */
  sim_icache_fetch(4554 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_8); /* line 8434 */
} /* line 8434 */
  sim_icache_fetch(4556 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_8); /* line 8436 */
} /* line 8436 */
  sim_icache_fetch(4558 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L242X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8438 */
  sim_icache_fetch(4559 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -832); /* line 8440 */
} /* line 8440 */
  sim_icache_fetch(4561 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -208); /* line 8442 */
} /* line 8442 */
  sim_icache_fetch(4562 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 8444 */
} /* line 8444 */
  sim_icache_fetch(4563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_8); /* line 8446 */
} /* line 8446 */
  sim_icache_fetch(4565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_8); /* line 8448 */
} /* line 8448 */
  sim_icache_fetch(4567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_8); /* line 8450 */
} /* line 8450 */
  sim_icache_fetch(4569 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_8); /* line 8452 */
} /* line 8452 */
  sim_icache_fetch(4571 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_8); /* line 8454 */
} /* line 8454 */
  sim_icache_fetch(4573 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_8); /* line 8456 */
} /* line 8456 */
  sim_icache_fetch(4575 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_8); /* line 8458 */
} /* line 8458 */
  sim_icache_fetch(4577 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_8); /* line 8460 */
} /* line 8460 */
  sim_icache_fetch(4579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_8); /* line 8462 */
} /* line 8462 */
  sim_icache_fetch(4581 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_8); /* line 8464 */
} /* line 8464 */
  sim_icache_fetch(4583 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_8); /* line 8466 */
} /* line 8466 */
  sim_icache_fetch(4585 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_8); /* line 8468 */
} /* line 8468 */
  sim_icache_fetch(4587 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_8); /* line 8470 */
} /* line 8470 */
  sim_icache_fetch(4589 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_8); /* line 8472 */
} /* line 8472 */
  sim_icache_fetch(4591 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_8); /* line 8474 */
} /* line 8474 */
  sim_icache_fetch(4593 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_8); /* line 8476 */
} /* line 8476 */
  sim_icache_fetch(4595 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 8478 */
} /* line 8478 */
  sim_icache_fetch(4597 + t_thisfile.offset, 1);
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
} /* line 8481 */
  sim_icache_fetch(4598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L230X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L230X3;
} /* line 8483 */
l_L243X3: ;/* line 8486 */
__LABEL(l_L243X3);
  sim_icache_fetch(4599 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_3, (unsigned int) -768); /* line 8487 */
} /* line 8487 */
  sim_icache_fetch(4601 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8489 */
} /* line 8489 */
  sim_icache_fetch(4602 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_7, (unsigned int) -192); /* line 8492 */
} /* line 8492 */
  sim_icache_fetch(4603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8494 */
l_L245X3: ;/* line 8497 */
__LABEL(l_L245X3);
  sim_icache_fetch(4604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 8498 */
} /* line 8498 */
  sim_icache_fetch(4605 + t_thisfile.offset, 1);
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
} /* line 8500 */
  sim_icache_fetch(4606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 8502 */
} /* line 8502 */
  sim_icache_fetch(4607 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 8504 */
} /* line 8504 */
  sim_icache_fetch(4608 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 2); /* line 8506 */
} /* line 8506 */
  sim_icache_fetch(4609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 3); /* line 8508 */
} /* line 8508 */
  sim_icache_fetch(4610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 4); /* line 8510 */
} /* line 8510 */
  sim_icache_fetch(4611 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 5); /* line 8512 */
} /* line 8512 */
  sim_icache_fetch(4612 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 6); /* line 8514 */
} /* line 8514 */
  sim_icache_fetch(4613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 7); /* line 8516 */
} /* line 8516 */
  sim_icache_fetch(4614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 8); /* line 8518 */
} /* line 8518 */
  sim_icache_fetch(4615 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 8520 */
} /* line 8520 */
  sim_icache_fetch(4616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 8522 */
} /* line 8522 */
  sim_icache_fetch(4617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_8); /* line 8524 */
} /* line 8524 */
  sim_icache_fetch(4618 + t_thisfile.offset, 1);
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
} /* line 8526 */
  sim_icache_fetch(4619 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 8528 */
} /* line 8528 */
  sim_icache_fetch(4620 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_8); /* line 8530 */
} /* line 8530 */
  sim_icache_fetch(4621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8532 */
  sim_icache_fetch(4622 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 10); /* line 8534 */
} /* line 8534 */
  sim_icache_fetch(4623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_8); /* line 8536 */
} /* line 8536 */
  sim_icache_fetch(4624 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8538 */
  sim_icache_fetch(4625 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 11); /* line 8540 */
} /* line 8540 */
  sim_icache_fetch(4626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_8); /* line 8542 */
} /* line 8542 */
  sim_icache_fetch(4627 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8544 */
  sim_icache_fetch(4628 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 12); /* line 8546 */
} /* line 8546 */
  sim_icache_fetch(4629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_8); /* line 8548 */
} /* line 8548 */
  sim_icache_fetch(4630 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8550 */
  sim_icache_fetch(4631 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 13); /* line 8552 */
} /* line 8552 */
  sim_icache_fetch(4632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_8); /* line 8554 */
} /* line 8554 */
  sim_icache_fetch(4633 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8556 */
  sim_icache_fetch(4634 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 14); /* line 8558 */
} /* line 8558 */
  sim_icache_fetch(4635 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_8); /* line 8560 */
} /* line 8560 */
  sim_icache_fetch(4636 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8562 */
  sim_icache_fetch(4637 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 15); /* line 8564 */
} /* line 8564 */
  sim_icache_fetch(4638 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 8566 */
} /* line 8566 */
  sim_icache_fetch(4639 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_8); /* line 8568 */
} /* line 8568 */
  sim_icache_fetch(4640 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8570 */
  sim_icache_fetch(4641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_7, reg_r0_5, 0); /* line 8572 */
} /* line 8572 */
  sim_icache_fetch(4642 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_8); /* line 8574 */
} /* line 8574 */
  sim_icache_fetch(4643 + t_thisfile.offset, 1);
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
} /* line 8576 */
  sim_icache_fetch(4644 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 8578 */
} /* line 8578 */
  sim_icache_fetch(4645 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_8); /* line 8580 */
} /* line 8580 */
  sim_icache_fetch(4646 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8582 */
  sim_icache_fetch(4647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 8584 */
} /* line 8584 */
  sim_icache_fetch(4648 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_8); /* line 8586 */
} /* line 8586 */
  sim_icache_fetch(4649 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8588 */
  sim_icache_fetch(4650 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 8590 */
} /* line 8590 */
  sim_icache_fetch(4651 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_8); /* line 8592 */
} /* line 8592 */
  sim_icache_fetch(4652 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8594 */
  sim_icache_fetch(4653 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 8596 */
} /* line 8596 */
  sim_icache_fetch(4654 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_8); /* line 8598 */
} /* line 8598 */
  sim_icache_fetch(4655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8600 */
  sim_icache_fetch(4656 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 8602 */
} /* line 8602 */
  sim_icache_fetch(4657 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_8); /* line 8604 */
} /* line 8604 */
  sim_icache_fetch(4658 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8606 */
  sim_icache_fetch(4659 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 8608 */
} /* line 8608 */
  sim_icache_fetch(4660 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_8); /* line 8610 */
} /* line 8610 */
  sim_icache_fetch(4661 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8612 */
  sim_icache_fetch(4662 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 8614 */
} /* line 8614 */
  sim_icache_fetch(4663 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_8); /* line 8616 */
} /* line 8616 */
  sim_icache_fetch(4664 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8618 */
  sim_icache_fetch(4665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 8620 */
} /* line 8620 */
  sim_icache_fetch(4666 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 8622 */
} /* line 8622 */
  sim_icache_fetch(4667 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_8); /* line 8624 */
} /* line 8624 */
  sim_icache_fetch(4668 + t_thisfile.offset, 1);
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
} /* line 8626 */
  sim_icache_fetch(4669 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 8628 */
} /* line 8628 */
  sim_icache_fetch(4670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_8); /* line 8630 */
} /* line 8630 */
  sim_icache_fetch(4671 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8632 */
  sim_icache_fetch(4672 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 8634 */
} /* line 8634 */
  sim_icache_fetch(4673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_8); /* line 8636 */
} /* line 8636 */
  sim_icache_fetch(4674 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8638 */
  sim_icache_fetch(4675 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 8640 */
} /* line 8640 */
  sim_icache_fetch(4676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_8); /* line 8642 */
} /* line 8642 */
  sim_icache_fetch(4677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8644 */
  sim_icache_fetch(4678 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 8646 */
} /* line 8646 */
  sim_icache_fetch(4679 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_8); /* line 8648 */
} /* line 8648 */
  sim_icache_fetch(4680 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8650 */
  sim_icache_fetch(4681 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 8652 */
} /* line 8652 */
  sim_icache_fetch(4682 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_8); /* line 8654 */
} /* line 8654 */
  sim_icache_fetch(4683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8656 */
  sim_icache_fetch(4684 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 8658 */
} /* line 8658 */
  sim_icache_fetch(4685 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_8); /* line 8660 */
} /* line 8660 */
  sim_icache_fetch(4686 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8662 */
  sim_icache_fetch(4687 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 8664 */
} /* line 8664 */
  sim_icache_fetch(4688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_8); /* line 8666 */
} /* line 8666 */
  sim_icache_fetch(4689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8668 */
  sim_icache_fetch(4690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_8); /* line 8670 */
} /* line 8670 */
  sim_icache_fetch(4691 + t_thisfile.offset, 1);
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
} /* line 8672 */
  sim_icache_fetch(4692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_8); /* line 8674 */
} /* line 8674 */
  sim_icache_fetch(4693 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8676 */
  sim_icache_fetch(4694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_8); /* line 8678 */
} /* line 8678 */
  sim_icache_fetch(4695 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8680 */
  sim_icache_fetch(4696 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_8); /* line 8682 */
} /* line 8682 */
  sim_icache_fetch(4697 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8684 */
  sim_icache_fetch(4698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_8); /* line 8686 */
} /* line 8686 */
  sim_icache_fetch(4699 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8688 */
  sim_icache_fetch(4700 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_8); /* line 8690 */
} /* line 8690 */
  sim_icache_fetch(4701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8692 */
  sim_icache_fetch(4702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_8); /* line 8694 */
} /* line 8694 */
  sim_icache_fetch(4703 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 8696 */
  sim_icache_fetch(4704 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_8); /* line 8699 */
} /* line 8699 */
  sim_icache_fetch(4705 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L245X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L245X3;
} /* line 8701 */
l_L246X3: ;/* line 8704 */
__LABEL(l_L246X3);
  sim_icache_fetch(4706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 8706 */
l_L242X3: ;/* line 8709 */
__LABEL(l_L242X3);
  sim_icache_fetch(4707 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -768); /* line 8710 */
} /* line 8710 */
  sim_icache_fetch(4709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8712 */
} /* line 8712 */
  sim_icache_fetch(4710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -192); /* line 8715 */
} /* line 8715 */
  sim_icache_fetch(4711 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8717 */
l_L241X3: ;/* line 8720 */
__LABEL(l_L241X3);
  sim_icache_fetch(4712 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -704); /* line 8721 */
} /* line 8721 */
  sim_icache_fetch(4714 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8723 */
} /* line 8723 */
  sim_icache_fetch(4715 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -176); /* line 8726 */
} /* line 8726 */
  sim_icache_fetch(4716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8728 */
l_L240X3: ;/* line 8731 */
__LABEL(l_L240X3);
  sim_icache_fetch(4717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -640); /* line 8732 */
} /* line 8732 */
  sim_icache_fetch(4719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8734 */
} /* line 8734 */
  sim_icache_fetch(4720 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -160); /* line 8737 */
} /* line 8737 */
  sim_icache_fetch(4721 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8739 */
l_L239X3: ;/* line 8742 */
__LABEL(l_L239X3);
  sim_icache_fetch(4722 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -576); /* line 8743 */
} /* line 8743 */
  sim_icache_fetch(4724 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8745 */
} /* line 8745 */
  sim_icache_fetch(4725 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -144); /* line 8748 */
} /* line 8748 */
  sim_icache_fetch(4726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8750 */
l_L238X3: ;/* line 8753 */
__LABEL(l_L238X3);
  sim_icache_fetch(4727 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -512); /* line 8754 */
} /* line 8754 */
  sim_icache_fetch(4729 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8756 */
} /* line 8756 */
  sim_icache_fetch(4730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -128); /* line 8759 */
} /* line 8759 */
  sim_icache_fetch(4731 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8761 */
l_L237X3: ;/* line 8764 */
__LABEL(l_L237X3);
  sim_icache_fetch(4732 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -448); /* line 8765 */
} /* line 8765 */
  sim_icache_fetch(4734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8767 */
} /* line 8767 */
  sim_icache_fetch(4735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -112); /* line 8770 */
} /* line 8770 */
  sim_icache_fetch(4736 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8772 */
l_L236X3: ;/* line 8775 */
__LABEL(l_L236X3);
  sim_icache_fetch(4737 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -384); /* line 8776 */
} /* line 8776 */
  sim_icache_fetch(4739 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8778 */
} /* line 8778 */
  sim_icache_fetch(4740 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -96); /* line 8781 */
} /* line 8781 */
  sim_icache_fetch(4741 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8783 */
l_L235X3: ;/* line 8786 */
__LABEL(l_L235X3);
  sim_icache_fetch(4742 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -320); /* line 8787 */
} /* line 8787 */
  sim_icache_fetch(4744 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8789 */
} /* line 8789 */
  sim_icache_fetch(4745 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -80); /* line 8792 */
} /* line 8792 */
  sim_icache_fetch(4746 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8794 */
l_L234X3: ;/* line 8797 */
__LABEL(l_L234X3);
  sim_icache_fetch(4747 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -256); /* line 8798 */
} /* line 8798 */
  sim_icache_fetch(4748 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8800 */
} /* line 8800 */
  sim_icache_fetch(4749 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -64); /* line 8803 */
} /* line 8803 */
  sim_icache_fetch(4750 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8805 */
l_L233X3: ;/* line 8808 */
__LABEL(l_L233X3);
  sim_icache_fetch(4751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -192); /* line 8809 */
} /* line 8809 */
  sim_icache_fetch(4752 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8811 */
} /* line 8811 */
  sim_icache_fetch(4753 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 8814 */
} /* line 8814 */
  sim_icache_fetch(4754 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8816 */
l_L232X3: ;/* line 8819 */
__LABEL(l_L232X3);
  sim_icache_fetch(4755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -128); /* line 8820 */
} /* line 8820 */
  sim_icache_fetch(4756 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8822 */
} /* line 8822 */
  sim_icache_fetch(4757 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -32); /* line 8825 */
} /* line 8825 */
  sim_icache_fetch(4758 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 8827 */
l_L231X3: ;/* line 8830 */
__LABEL(l_L231X3);
  sim_icache_fetch(4759 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -64); /* line 8831 */
} /* line 8831 */
  sim_icache_fetch(4760 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_5, (unsigned int) -64); /* line 8833 */
} /* line 8833 */
  sim_icache_fetch(4761 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -16); /* line 8835 */
} /* line 8835 */
l_L244X3: ;/* line 8837 */
__LABEL(l_L244X3);
  sim_icache_fetch(4762 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_6, (unsigned int) 16); /* line 8839 */
} /* line 8839 */
  sim_icache_fetch(4763 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L245X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L245X3;
} /* line 8841 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 411: goto l_L230X3;
    case 412: goto l_L243X3;
    case 413: goto l_L245X3;
    case 414: goto l_L246X3;
    case 415: goto l_L242X3;
    case 416: goto l_L241X3;
    case 417: goto l_L240X3;
    case 418: goto l_L239X3;
    case 419: goto l_L238X3;
    case 420: goto l_L237X3;
    case 421: goto l_L236X3;
    case 422: goto l_L235X3;
    case 423: goto l_L234X3;
    case 424: goto l_L233X3;
    case 425: goto l_L232X3;
    case 426: goto l_L231X3;
    case 427: goto l_L244X3;
    case 428:
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
  reg_l0_0 = (429 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 8856 */
  sim_icache_fetch(4765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 8858 */
} /* line 8858 */
  sim_icache_fetch(4766 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 8861 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 429:
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
  reg_l0_0 = (430 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4767 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 8876 */
  sim_icache_fetch(4768 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 8878 */
} /* line 8878 */
  sim_icache_fetch(4769 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 8881 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 430:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 4784, 0, 0, 0, 2};

