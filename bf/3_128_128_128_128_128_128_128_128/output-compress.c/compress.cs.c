/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/3_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_9256Xoffset[1];
unsigned int compress_9256Xbuf[3];
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
unsigned int compress_9256XBuf[216]; 
unsigned int compress_9256Xrcs_ident[6]; 
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
	(136 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(150 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(142 << 5),
	(141 << 5),
	(140 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(139 << 5),
	(154 << 5),
	(154 << 5),
	(138 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(154 << 5),
	(137 << 5)
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

unsigned int compress_9256XBuf[216] = { 
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

unsigned int compress_9256Xrcs_ident[6] = { 
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
  sim_icache_fetch(11 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) compress_9256XBuf); /* line 32 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 33 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 34 */
} /* line 34 */
  sim_icache_fetch(15 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), 0); /* line 36 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 37 */
   __MOV(reg_r0_6, (unsigned int) 800); /* line 38 */
} /* line 38 */
  sim_icache_fetch(20 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_2); /* line 40 */
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 41 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_6); /* line 42 */
} /* line 42 */
		 /* line 43 */
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
} /* line 45 */
l_lr_3: ;/* line 45 */
__LABEL(l_lr_3);
		 /* line 46 */
  sim_icache_fetch(27 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 49 */
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
} /* line 49 */
l_lr_5: ;/* line 49 */
__LABEL(l_lr_5);
  sim_icache_fetch(31 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 51 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 52 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 53 */
   __ADD_CYCLES(1);
} /* line 53 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 56 */
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
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 107 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX2); /* line 108 */
} /* line 108 */
		 /* line 109 */
  sim_icache_fetch(38 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 112 */
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
} /* line 112 */
l_lr_8: ;/* line 112 */
__LABEL(l_lr_8);
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 114 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 115 */
   __ADD_CYCLES(1);
} /* line 115 */
  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Usage);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 118 */
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
  reg_l0_0 = (131 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 15); /* line 179 */
   __ADD(reg_r0_21, reg_r0_3, (unsigned int) 14); /* line 180 */
} /* line 180 */
  sim_icache_fetch(46 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 13); /* line 182 */
   __ADD(reg_r0_19, reg_r0_3, (unsigned int) 12); /* line 183 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 11); /* line 184 */
} /* line 184 */
  sim_icache_fetch(49 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_17, reg_r0_3, (unsigned int) 10); /* line 186 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 9); /* line 187 */
   __ADD(reg_r0_15, reg_r0_3, (unsigned int) 8); /* line 188 */
} /* line 188 */
  sim_icache_fetch(52 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 7); /* line 190 */
   __ADD(reg_r0_13, reg_r0_3, (unsigned int) 6); /* line 191 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 5); /* line 192 */
} /* line 192 */
  sim_icache_fetch(55 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 194 */
   __ADD(reg_r0_11, reg_r0_3, (unsigned int) 4); /* line 195 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 196 */
} /* line 196 */
  sim_icache_fetch(58 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SXTB(reg_r0_4, reg_r0_4); /* line 198 */
   __MOV(reg_r0_5, 0); /* line 199 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 200 */
} /* line 200 */
  sim_icache_fetch(61 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_3); /* line 202 */
} /* line 202 */
l_L0X3: ;/* line 205 */
__LABEL(l_L0X3);
  sim_icache_fetch(62 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 206 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 207 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 208 */
} /* line 208 */
  sim_icache_fetch(65 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_10,0,1)); /* line 210 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_11,0,1)); /* line 211 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_12,0,1)); /* line 212 */
} /* line 212 */
  sim_icache_fetch(68 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 214 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 215 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 216 */
} /* line 216 */
  sim_icache_fetch(71 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 218 */
   __CMPEQ(reg_b0_0, reg_r0_7, reg_r0_4); /* line 219 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 220 */
  sim_icache_fetch(74 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_6, reg_r0_3); /* line 222 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 223 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 224 */
  sim_icache_fetch(77 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_9, reg_r0_4); /* line 226 */
   __CMPNE(reg_b0_1, reg_r0_23, 0); /* line 227 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 228 */
  sim_icache_fetch(80 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_8, reg_r0_7); /* line 230 */
   __CMPEQ(reg_b0_0, reg_r0_23, reg_r0_4); /* line 231 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 232 */
  sim_icache_fetch(83 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_10, reg_r0_7); /* line 234 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 235 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 236 */
} /* line 236 */
  sim_icache_fetch(86 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_11, reg_r0_7); /* line 238 */
   __CMPNE(reg_b0_0, reg_r0_25, 0); /* line 239 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 240 */
  sim_icache_fetch(89 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_25, reg_r0_4); /* line 242 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_13,0,1)); /* line 243 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 244 */
  sim_icache_fetch(92 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_12, reg_r0_3); /* line 246 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_14,0,1)); /* line 247 */
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_15,0,1)); /* line 248 */
} /* line 248 */
  sim_icache_fetch(95 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 250 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 251 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_16,0,1)); /* line 252 */
} /* line 252 */
  sim_icache_fetch(98 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_24, reg_b0_1, reg_r0_13, reg_r0_3); /* line 254 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 255 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 256 */
  sim_icache_fetch(101 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_9, reg_r0_4); /* line 258 */
   __CMPNE(reg_b0_1, reg_r0_23, 0); /* line 259 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 260 */
  sim_icache_fetch(104 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_24, reg_b0_0, reg_r0_14, reg_r0_24); /* line 262 */
   __CMPEQ(reg_b0_0, reg_r0_23, reg_r0_4); /* line 263 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 264 */
  sim_icache_fetch(107 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_24, reg_b0_0, reg_r0_15, reg_r0_24); /* line 266 */
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 267 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 268 */
} /* line 268 */
  sim_icache_fetch(110 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_16, reg_r0_24); /* line 270 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_17,0,1)); /* line 271 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 272 */
  sim_icache_fetch(113 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_18,0,1)); /* line 274 */
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_19,0,1)); /* line 275 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_20,0,1)); /* line 276 */
} /* line 276 */
  sim_icache_fetch(116 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 278 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 279 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_21,0,1)); /* line 280 */
} /* line 280 */
  sim_icache_fetch(119 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_25, reg_b0_1, reg_r0_17, reg_r0_3); /* line 282 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 283 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 284 */
  sim_icache_fetch(122 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_9, reg_r0_4); /* line 286 */
   __CMPNE(reg_b0_1, reg_r0_23, 0); /* line 287 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 288 */
  sim_icache_fetch(125 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_25, reg_b0_0, reg_r0_18, reg_r0_25); /* line 290 */
   __CMPEQ(reg_b0_0, reg_r0_23, reg_r0_4); /* line 291 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 292 */
  sim_icache_fetch(128 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_25, reg_b0_0, reg_r0_19, reg_r0_25); /* line 294 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 295 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 296 */
} /* line 296 */
  sim_icache_fetch(131 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_20, reg_r0_25); /* line 298 */
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 299 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 300 */
  sim_icache_fetch(134 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_7, reg_r0_4); /* line 302 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_22,0,1)); /* line 303 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 304 */
  sim_icache_fetch(137 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_21, reg_r0_3); /* line 306 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 307 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 308 */
} /* line 308 */
  sim_icache_fetch(140 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 310 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 311 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 312 */
} /* line 312 */
  sim_icache_fetch(143 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_5, reg_b0_1, reg_r0_22, reg_r0_3); /* line 314 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 315 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 316 */
  sim_icache_fetch(146 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 318 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 319 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 320 */
} /* line 320 */
  sim_icache_fetch(149 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 322 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 323 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 324 */
} /* line 324 */
  sim_icache_fetch(152 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 326 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 327 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 328 */
} /* line 328 */
  sim_icache_fetch(155 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 330 */
   __ADD(reg_r0_22, reg_r0_22, (unsigned int) 16); /* line 331 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 332 */
} /* line 332 */
  sim_icache_fetch(158 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 334 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 335 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_8,0,1)); /* line 336 */
} /* line 336 */
  sim_icache_fetch(161 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_10,0,1)); /* line 338 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_11,0,1)); /* line 339 */
   __LDBs(reg_r0_25, mem_trace_ld(reg_r0_12,0,1)); /* line 340 */
} /* line 340 */
  sim_icache_fetch(164 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 342 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 343 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 344 */
} /* line 344 */
  sim_icache_fetch(167 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 346 */
   __CMPEQ(reg_b0_0, reg_r0_7, reg_r0_4); /* line 347 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 348 */
  sim_icache_fetch(170 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_6, reg_r0_3); /* line 350 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 351 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 352 */
  sim_icache_fetch(173 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_9, reg_r0_4); /* line 354 */
   __CMPNE(reg_b0_1, reg_r0_23, 0); /* line 355 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 356 */
  sim_icache_fetch(176 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_8, reg_r0_7); /* line 358 */
   __CMPEQ(reg_b0_0, reg_r0_23, reg_r0_4); /* line 359 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 360 */
  sim_icache_fetch(179 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_10, reg_r0_7); /* line 362 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 363 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 364 */
} /* line 364 */
  sim_icache_fetch(182 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_11, reg_r0_7); /* line 366 */
   __CMPNE(reg_b0_0, reg_r0_25, 0); /* line 367 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 368 */
  sim_icache_fetch(185 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_25, reg_r0_4); /* line 370 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_13,0,1)); /* line 371 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 372 */
  sim_icache_fetch(188 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_12, reg_r0_3); /* line 374 */
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_14,0,1)); /* line 375 */
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_15,0,1)); /* line 376 */
} /* line 376 */
  sim_icache_fetch(191 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 378 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 379 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_16,0,1)); /* line 380 */
} /* line 380 */
  sim_icache_fetch(194 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_24, reg_b0_1, reg_r0_13, reg_r0_3); /* line 382 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 383 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 384 */
  sim_icache_fetch(197 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_9, reg_r0_4); /* line 386 */
   __CMPNE(reg_b0_1, reg_r0_23, 0); /* line 387 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 388 */
  sim_icache_fetch(200 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_24, reg_b0_0, reg_r0_14, reg_r0_24); /* line 390 */
   __CMPEQ(reg_b0_0, reg_r0_23, reg_r0_4); /* line 391 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 392 */
  sim_icache_fetch(203 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_24, reg_b0_0, reg_r0_15, reg_r0_24); /* line 394 */
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 395 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 396 */
} /* line 396 */
  sim_icache_fetch(206 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_16, reg_r0_24); /* line 398 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_17,0,1)); /* line 399 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 400 */
  sim_icache_fetch(209 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_18,0,1)); /* line 402 */
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_19,0,1)); /* line 403 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_20,0,1)); /* line 404 */
} /* line 404 */
  sim_icache_fetch(212 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 406 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 407 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_21,0,1)); /* line 408 */
} /* line 408 */
  sim_icache_fetch(215 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_25, reg_b0_1, reg_r0_17, reg_r0_3); /* line 410 */
   __CMPNE(reg_b0_0, reg_r0_9, 0); /* line 411 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 412 */
  sim_icache_fetch(218 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_9, reg_r0_4); /* line 414 */
   __CMPNE(reg_b0_1, reg_r0_23, 0); /* line 415 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 416 */
  sim_icache_fetch(221 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_25, reg_b0_0, reg_r0_18, reg_r0_25); /* line 418 */
   __CMPEQ(reg_b0_0, reg_r0_23, reg_r0_4); /* line 419 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 420 */
  sim_icache_fetch(224 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_25, reg_b0_0, reg_r0_19, reg_r0_25); /* line 422 */
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 423 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 424 */
} /* line 424 */
  sim_icache_fetch(227 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_20, reg_r0_25); /* line 426 */
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 427 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 428 */
  sim_icache_fetch(230 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_7, reg_r0_4); /* line 430 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_22,0,1)); /* line 431 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 432 */
  sim_icache_fetch(233 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_21, reg_r0_3); /* line 434 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 435 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 436 */
} /* line 436 */
  sim_icache_fetch(236 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 438 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 439 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 440 */
} /* line 440 */
  sim_icache_fetch(239 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_5, reg_b0_1, reg_r0_22, reg_r0_3); /* line 442 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 443 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 444 */
  sim_icache_fetch(242 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 446 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 447 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 448 */
} /* line 448 */
  sim_icache_fetch(245 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 450 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 451 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 452 */
} /* line 452 */
  sim_icache_fetch(248 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 454 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 455 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 456 */
} /* line 456 */
  sim_icache_fetch(251 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 458 */
   __ADD(reg_r0_22, reg_r0_22, (unsigned int) 16); /* line 459 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 461 */
} /* line 461 */
  sim_icache_fetch(254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 463 */
l_L16X3: ;/* line 466 */
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
} /* line 469 */
l_L19X3: ;/* line 472 */
__LABEL(l_L19X3);
  sim_icache_fetch(256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 475 */
l_L14X3: ;/* line 478 */
__LABEL(l_L14X3);
  sim_icache_fetch(257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_25); /* line 480 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 481 */
l_L13X3: ;/* line 484 */
__LABEL(l_L13X3);
  sim_icache_fetch(259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_25); /* line 486 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 487 */
l_L12X3: ;/* line 490 */
__LABEL(l_L12X3);
  sim_icache_fetch(261 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_25); /* line 492 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 493 */
l_L11X3: ;/* line 496 */
__LABEL(l_L11X3);
  sim_icache_fetch(263 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 499 */
l_L18X3: ;/* line 502 */
__LABEL(l_L18X3);
  sim_icache_fetch(264 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_24); /* line 504 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 505 */
l_L9X3: ;/* line 508 */
__LABEL(l_L9X3);
  sim_icache_fetch(266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_24); /* line 510 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 511 */
l_L8X3: ;/* line 514 */
__LABEL(l_L8X3);
  sim_icache_fetch(268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_24); /* line 516 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 517 */
l_L7X3: ;/* line 520 */
__LABEL(l_L7X3);
  sim_icache_fetch(270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 523 */
l_L17X3: ;/* line 526 */
__LABEL(l_L17X3);
  sim_icache_fetch(271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 529 */
l_L5X3: ;/* line 532 */
__LABEL(l_L5X3);
  sim_icache_fetch(272 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 534 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 535 */
l_L4X3: ;/* line 538 */
__LABEL(l_L4X3);
  sim_icache_fetch(274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 540 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 541 */
l_L3X3: ;/* line 544 */
__LABEL(l_L3X3);
  sim_icache_fetch(276 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 546 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 547 */
l_L2X3: ;/* line 550 */
__LABEL(l_L2X3);
  sim_icache_fetch(278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 553 */
l_L1X3: ;/* line 556 */
__LABEL(l_L1X3);
  sim_icache_fetch(279 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 558 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 559 */
l_L15X3: ;/* line 562 */
__LABEL(l_L15X3);
  sim_icache_fetch(281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 565 */
l_L10X3: ;/* line 568 */
__LABEL(l_L10X3);
  sim_icache_fetch(282 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_24); /* line 570 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 571 */
l_L6X3: ;/* line 574 */
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
} /* line 577 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 111: goto l_L0X3;
    case 112: goto l_L16X3;
    case 113: goto l_L19X3;
    case 114: goto l_L14X3;
    case 115: goto l_L13X3;
    case 116: goto l_L12X3;
    case 117: goto l_L11X3;
    case 118: goto l_L18X3;
    case 119: goto l_L9X3;
    case 120: goto l_L8X3;
    case 121: goto l_L7X3;
    case 122: goto l_L17X3;
    case 123: goto l_L5X3;
    case 124: goto l_L4X3;
    case 125: goto l_L3X3;
    case 126: goto l_L2X3;
    case 127: goto l_L1X3;
    case 128: goto l_L15X3;
    case 129: goto l_L10X3;
    case 130: goto l_L6X3;
    case 131:
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
  reg_l0_0 = (198 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(285 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 593 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 594 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 595 */
} /* line 595 */
  sim_icache_fetch(290 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 597 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 598 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 599 */
} /* line 599 */
  sim_icache_fetch(293 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 601 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 602 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 603 */
} /* line 603 */
  sim_icache_fetch(298 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 605 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 606 */
} /* line 606 */
		 /* line 607 */
  sim_icache_fetch(300 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 609 */
l_lr_32: ;/* line 609 */
__LABEL(l_lr_32);
  sim_icache_fetch(302 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 611 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 612 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 613 */
   __ADD_CYCLES(1);
} /* line 613 */
  sim_icache_fetch(305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 615 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 616 */
} /* line 616 */
l_L20X3: ;/* line 619 */
__LABEL(l_L20X3);
  sim_icache_fetch(307 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 620 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 621 */
} /* line 621 */
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 623 */
  sim_icache_fetch(310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 625 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 626 */
   __ADD_CYCLES(1);
} /* line 626 */
  sim_icache_fetch(312 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 628 */
} /* line 628 */
  sim_icache_fetch(313 + t_thisfile.offset, 1);
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
} /* line 630 */
l_L23X3: ;/* line 633 */
__LABEL(l_L23X3);
  sim_icache_fetch(314 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 634 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 635 */
   __ADD_CYCLES(1);
} /* line 635 */
  sim_icache_fetch(316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 637 */
} /* line 637 */
  sim_icache_fetch(317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 639 */
} /* line 639 */
  sim_icache_fetch(318 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 641 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 642 */
   __ADD_CYCLES(1);
} /* line 642 */
  sim_icache_fetch(320 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 644 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 645 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 646 */
} /* line 646 */
  sim_icache_fetch(323 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 648 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 649 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 650 */
  sim_icache_fetch(327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 652 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 653 */
  sim_icache_fetch(329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 654 */
  sim_icache_fetch(330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 656 */
l__X1XCompressXTAGX0X0: ;/* line 658 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(331 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 659 */
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 660 */
l__X1XCompressXTAGX0X7: ;/* line 663 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(334 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 664 */
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 665 */
l__X1XCompressXTAGX0X6: ;/* line 668 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(337 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 669 */
} /* line 669 */
  sim_icache_fetch(338 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 671 */
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 672 */
l__X1XCompressXTAGX0X5: ;/* line 675 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(341 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 676 */
} /* line 676 */
  sim_icache_fetch(342 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 678 */
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 679 */
l__X1XCompressXTAGX0X4: ;/* line 682 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(345 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 683 */
} /* line 683 */
  sim_icache_fetch(346 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 685 */
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 686 */
l__X1XCompressXTAGX0X3: ;/* line 689 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 690 */
} /* line 690 */
  sim_icache_fetch(350 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 692 */
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 693 */
l__X1XCompressXTAGX0X2: ;/* line 696 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 697 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 698 */
   __ADD_CYCLES(1);
} /* line 698 */
  sim_icache_fetch(355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 700 */
} /* line 700 */
  sim_icache_fetch(356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 702 */
} /* line 702 */
  sim_icache_fetch(357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 704 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 705 */
   __ADD_CYCLES(1);
} /* line 705 */
  sim_icache_fetch(359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 707 */
} /* line 707 */
  sim_icache_fetch(360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 709 */
l_L22X3: ;/* line 711 */
__LABEL(l_L22X3);
  sim_icache_fetch(361 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 712 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 713 */
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 714 */
l_L25X3: ;/* line 717 */
__LABEL(l_L25X3);
  sim_icache_fetch(364 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 718 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 719 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 720 */
} /* line 720 */
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 722 */
} /* line 722 */
  sim_icache_fetch(368 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 724 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 725 */
  sim_icache_fetch(370 + t_thisfile.offset, 1);
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
} /* line 728 */
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L22X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L22X3;
} /* line 730 */
l_L26X3: ;/* line 733 */
__LABEL(l_L26X3);
		 /* line 733 */
  sim_icache_fetch(372 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 736 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (198 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 736 */
l_lr_46: ;/* line 736 */
__LABEL(l_lr_46);
		 /* line 737 */
  sim_icache_fetch(376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (198 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 739 */
l_lr_48: ;/* line 739 */
__LABEL(l_lr_48);
  sim_icache_fetch(378 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 741 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 742 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 743 */
   __ADD_CYCLES(1);
} /* line 743 */
  sim_icache_fetch(381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 746 */
l__X1XCompressXTAGX0X1: ;/* line 749 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 749 */
  sim_icache_fetch(382 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 752 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 753 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 753 */
l_lr_51: ;/* line 753 */
__LABEL(l_lr_51);
  sim_icache_fetch(386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 755 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 756 */
} /* line 756 */
  sim_icache_fetch(388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L23X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L23X3;
} /* line 758 */
l_L27X3: ;/* line 761 */
__LABEL(l_L27X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 762 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 762 */
  sim_icache_fetch(389 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 765 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (198 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 765 */
l_lr_55: ;/* line 765 */
__LABEL(l_lr_55);
		 /* line 766 */
  sim_icache_fetch(393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (198 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 768 */
l_lr_57: ;/* line 768 */
__LABEL(l_lr_57);
  sim_icache_fetch(395 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 770 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 771 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 772 */
   __ADD_CYCLES(1);
} /* line 772 */
  sim_icache_fetch(398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 775 */
l_L24X3: ;/* line 778 */
__LABEL(l_L24X3);
  sim_icache_fetch(399 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L27X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L27X3;
} /* line 779 */
l_L21X3: ;/* line 782 */
__LABEL(l_L21X3);
  sim_icache_fetch(400 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 783 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 784 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 785 */
} /* line 785 */
  sim_icache_fetch(404 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 787 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 788 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 789 */
} /* line 789 */
  sim_icache_fetch(409 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 791 */
} /* line 791 */
  sim_icache_fetch(410 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 4096); /* line 793 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 794 */
  sim_icache_fetch(413 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 796 */
} /* line 796 */
l_L29X3: ;/* line 798 */
__LABEL(l_L29X3);
  sim_icache_fetch(415 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 799 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 800 */
   __ADD_CYCLES(1);
} /* line 800 */
  sim_icache_fetch(418 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 12); /* line 802 */
} /* line 802 */
  sim_icache_fetch(419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 804 */
  sim_icache_fetch(420 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 806 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 807 */
} /* line 807 */
l_L31X3: ;/* line 809 */
__LABEL(l_L31X3);
  sim_icache_fetch(424 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 810 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 811 */
   __ADD_CYCLES(1);
} /* line 811 */
  sim_icache_fetch(427 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 813 */
} /* line 813 */
  sim_icache_fetch(428 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 815 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 816 */
		 /* line 817 */
  sim_icache_fetch(431 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 819 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 820 */
l_lr_63: ;/* line 820 */
__LABEL(l_lr_63);
l_L33X3: ;/* line 822 */
__LABEL(l_L33X3);
  sim_icache_fetch(435 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 823 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 824 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 825 */
} /* line 825 */
  sim_icache_fetch(441 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 827 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 828 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 829 */
} /* line 829 */
  sim_icache_fetch(447 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_10, reg_r0_2, (unsigned int) -1); /* line 831 */
   __LDBUs(reg_r0_11, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 832 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 833 */
} /* line 833 */
  sim_icache_fetch(452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 835 */
   __CMPGE(reg_b0_1, reg_r0_10, 0); /* line 836 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 837 */
} /* line 837 */
  sim_icache_fetch(455 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 839 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 840 */
   __AND(reg_r0_11, reg_r0_11, (unsigned int) 255); /* line 841 */
} /* line 841 */
  sim_icache_fetch(460 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 843 */
   __CMPNE(reg_b0_2, reg_r0_9, reg_r0_11); /* line 844 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 845 */
  sim_icache_fetch(464 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_10); /* line 847 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 848 */
  sim_icache_fetch(467 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 850 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 851 */
l_L37X3: ;/* line 853 */
__LABEL(l_L37X3);
		 /* line 853 */
  sim_icache_fetch(470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (198 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 855 */
l_lr_67: ;/* line 855 */
__LABEL(l_lr_67);
  sim_icache_fetch(472 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 857 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 858 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 859 */
   __ADD_CYCLES(1);
} /* line 859 */
  sim_icache_fetch(475 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 862 */
l_L36X3: ;/* line 865 */
__LABEL(l_L36X3);
  sim_icache_fetch(476 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 866 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 867 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 868 */
} /* line 868 */
  sim_icache_fetch(482 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 870 */
} /* line 870 */
  sim_icache_fetch(484 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 872 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 873 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 874 */
} /* line 874 */
  sim_icache_fetch(487 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 876 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 877 */
} /* line 877 */
  sim_icache_fetch(490 + t_thisfile.offset, 1);
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
} /* line 879 */
  sim_icache_fetch(491 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 881 */
} /* line 881 */
  sim_icache_fetch(493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 883 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 884 */
   __ADD_CYCLES(1);
} /* line 884 */
  sim_icache_fetch(495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 886 */
} /* line 886 */
l_L39X3: ;/* line 888 */
__LABEL(l_L39X3);
  sim_icache_fetch(496 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 889 */
} /* line 889 */
  sim_icache_fetch(497 + t_thisfile.offset, 1);
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
} /* line 892 */
  sim_icache_fetch(498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 894 */
l_L40X3: ;/* line 897 */
__LABEL(l_L40X3);
  sim_icache_fetch(499 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 898 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 899 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 900 */
} /* line 900 */
  sim_icache_fetch(504 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 902 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 903 */
} /* line 903 */
  sim_icache_fetch(508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 905 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 906 */
} /* line 906 */
  sim_icache_fetch(510 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 908 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 909 */
} /* line 909 */
  sim_icache_fetch(513 + t_thisfile.offset, 1);
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
} /* line 911 */
  sim_icache_fetch(514 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 913 */
} /* line 913 */
  sim_icache_fetch(516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 915 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 916 */
   __ADD_CYCLES(1);
} /* line 916 */
  sim_icache_fetch(518 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 918 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 919 */
} /* line 919 */
l_L42X3: ;/* line 921 */
__LABEL(l_L42X3);
  sim_icache_fetch(521 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 922 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 923 */
} /* line 923 */
  sim_icache_fetch(523 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 925 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 926 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 927 */
} /* line 927 */
  sim_icache_fetch(527 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 929 */
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 930 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 931 */
		 /* line 932 */
  sim_icache_fetch(532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (198 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 934 */
l_lr_73: ;/* line 934 */
__LABEL(l_lr_73);
  sim_icache_fetch(534 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 936 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 937 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 938 */
   __ADD_CYCLES(1);
} /* line 938 */
  sim_icache_fetch(537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 941 */
l_L34X3: ;/* line 944 */
__LABEL(l_L34X3);
		 /* line 944 */
  sim_icache_fetch(538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 946 */
l_lr_76: ;/* line 946 */
__LABEL(l_lr_76);
  sim_icache_fetch(540 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 948 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 949 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 950 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 951 */
   __ADD_CYCLES(1);
} /* line 951 */
  sim_icache_fetch(544 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 954 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 955 */
l_L41X3: ;/* line 958 */
__LABEL(l_L41X3);
  sim_icache_fetch(547 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 959 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 960 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 961 */
} /* line 961 */
  sim_icache_fetch(551 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 963 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 964 */
   __GOTO(l_L42X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L42X3;
} /* line 965 */
l_L38X3: ;/* line 968 */
__LABEL(l_L38X3);
  sim_icache_fetch(556 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 969 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 970 */
   __GOTO(l_L39X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L39X3;
} /* line 971 */
l_L35X3: ;/* line 974 */
__LABEL(l_L35X3);
  sim_icache_fetch(560 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 975 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 976 */
} /* line 976 */
  sim_icache_fetch(563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_11); /* line 978 */
} /* line 978 */
  sim_icache_fetch(564 + t_thisfile.offset, 1);
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
} /* line 981 */
  sim_icache_fetch(565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 983 */
l_L32X3: ;/* line 986 */
__LABEL(l_L32X3);
  sim_icache_fetch(566 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 987 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 988 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 989 */
   __ADD_CYCLES(1);
} /* line 989 */
  sim_icache_fetch(571 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 991 */
} /* line 991 */
  sim_icache_fetch(573 + t_thisfile.offset, 1);
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
} /* line 993 */
		 /* line 994 */
  sim_icache_fetch(574 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 996 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 997 */
l_lr_82: ;/* line 997 */
__LABEL(l_lr_82);
  sim_icache_fetch(578 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 999 */
l_L43X3: ;/* line 1002 */
__LABEL(l_L43X3);
  sim_icache_fetch(579 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1003 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1004 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1005 */
   __ADD_CYCLES(1);
} /* line 1005 */
  sim_icache_fetch(584 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1007 */
} /* line 1007 */
  sim_icache_fetch(586 + t_thisfile.offset, 1);
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
} /* line 1009 */
		 /* line 1010 */
  sim_icache_fetch(587 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1012 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1013 */
l_lr_85: ;/* line 1013 */
__LABEL(l_lr_85);
  sim_icache_fetch(591 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 1015 */
l_L44X3: ;/* line 1018 */
__LABEL(l_L44X3);
  sim_icache_fetch(592 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1019 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1020 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1021 */
   __ADD_CYCLES(1);
} /* line 1021 */
  sim_icache_fetch(597 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1023 */
} /* line 1023 */
  sim_icache_fetch(599 + t_thisfile.offset, 1);
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
} /* line 1025 */
		 /* line 1026 */
  sim_icache_fetch(600 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1028 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1029 */
l_lr_88: ;/* line 1029 */
__LABEL(l_lr_88);
  sim_icache_fetch(604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 1031 */
l_L45X3: ;/* line 1034 */
__LABEL(l_L45X3);
  sim_icache_fetch(605 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1035 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1036 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1037 */
   __ADD_CYCLES(1);
} /* line 1037 */
  sim_icache_fetch(610 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1039 */
} /* line 1039 */
  sim_icache_fetch(612 + t_thisfile.offset, 1);
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
} /* line 1041 */
		 /* line 1042 */
  sim_icache_fetch(613 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1044 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1045 */
l_lr_91: ;/* line 1045 */
__LABEL(l_lr_91);
  sim_icache_fetch(617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 1047 */
l_L46X3: ;/* line 1050 */
__LABEL(l_L46X3);
		 /* line 1050 */
  sim_icache_fetch(618 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1052 */
l_lr_94: ;/* line 1052 */
__LABEL(l_lr_94);
  sim_icache_fetch(620 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 1054 */
l_L30X3: ;/* line 1057 */
__LABEL(l_L30X3);
  sim_icache_fetch(621 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1058 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1059 */
} /* line 1059 */
  sim_icache_fetch(624 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1061 */
   __GOTO(l_L31X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L31X3;
} /* line 1062 */
l_L28X3: ;/* line 1065 */
__LABEL(l_L28X3);
  sim_icache_fetch(627 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1066 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1067 */
   __GOTO(l_L29X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L29X3;
} /* line 1068 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 133: goto l_lr_32;
    case 134: goto l_L20X3;
    case 135: goto l_L23X3;
    case 136: goto l__X1XCompressXTAGX0X0;
    case 137: goto l__X1XCompressXTAGX0X7;
    case 138: goto l__X1XCompressXTAGX0X6;
    case 139: goto l__X1XCompressXTAGX0X5;
    case 140: goto l__X1XCompressXTAGX0X4;
    case 141: goto l__X1XCompressXTAGX0X3;
    case 142: goto l__X1XCompressXTAGX0X2;
    case 143: goto l_L22X3;
    case 144: goto l_L25X3;
    case 145: goto l_L26X3;
    case 147: goto l_lr_46;
    case 149: goto l_lr_48;
    case 150: goto l__X1XCompressXTAGX0X1;
    case 152: goto l_lr_51;
    case 153: goto l_L27X3;
    case 154: goto l__X1XCompressXTAGX0XDEFAULT;
    case 156: goto l_lr_55;
    case 158: goto l_lr_57;
    case 159: goto l_L24X3;
    case 160: goto l_L21X3;
    case 161: goto l_L29X3;
    case 162: goto l_L31X3;
    case 164: goto l_lr_63;
    case 165: goto l_L33X3;
    case 166: goto l_L37X3;
    case 168: goto l_lr_67;
    case 169: goto l_L36X3;
    case 170: goto l_L39X3;
    case 171: goto l_L40X3;
    case 172: goto l_L42X3;
    case 174: goto l_lr_73;
    case 175: goto l_L34X3;
    case 177: goto l_lr_76;
    case 178: goto l_L41X3;
    case 179: goto l_L38X3;
    case 180: goto l_L35X3;
    case 181: goto l_L32X3;
    case 183: goto l_lr_82;
    case 184: goto l_L43X3;
    case 186: goto l_lr_85;
    case 187: goto l_L44X3;
    case 189: goto l_lr_88;
    case 190: goto l_L45X3;
    case 192: goto l_lr_91;
    case 193: goto l_L46X3;
    case 195: goto l_lr_94;
    case 196: goto l_L30X3;
    case 197: goto l_L28X3;
    case 198:
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

  sim_icache_fetch(630 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1206 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1207 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1208 */
} /* line 1208 */
  sim_icache_fetch(634 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1210 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1211 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1212 */
} /* line 1212 */
  sim_icache_fetch(638 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1214 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1215 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1216 */
} /* line 1216 */
  sim_icache_fetch(642 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1218 */
   __MOV(reg_r0_11, (unsigned int) 257); /* line 1219 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L47X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1220 */
l_L48X3: ;/* line 1222 */
__LABEL(l_L48X3);
  sim_icache_fetch(647 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_12, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1223 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1224 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1225 */
} /* line 1225 */
  sim_icache_fetch(653 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_5, 0); /* line 1227 */
   __MOV(reg_r0_4, 0); /* line 1228 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1229 */
} /* line 1229 */
  sim_icache_fetch(657 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, (unsigned int) 256); /* line 1231 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) -1); /* line 1232 */
   __ADD(reg_r0_5, reg_r0_13, (unsigned int) 1); /* line 1233 */
} /* line 1233 */
  sim_icache_fetch(661 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) compress_9256Xoffset,0,4), 0); /* line 1235 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1236 */
   __CMPGE(reg_b0_0, reg_r0_12, 0); /* line 1237 */
} /* line 1237 */
  sim_icache_fetch(666 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1239 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1240 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1241 */
} /* line 1241 */
  sim_icache_fetch(672 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1243 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1244 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1245 */
} /* line 1245 */
  sim_icache_fetch(678 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1247 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1248 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_12); /* line 1249 */
} /* line 1249 */
  sim_icache_fetch(684 + t_thisfile.offset, 1);
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
} /* line 1251 */
  sim_icache_fetch(685 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 1253 */
} /* line 1253 */
  sim_icache_fetch(687 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 1255 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1256 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1257 */
   __ADD_CYCLES(1);
} /* line 1257 */
  sim_icache_fetch(690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_13, reg_r0_13); /* line 1259 */
} /* line 1259 */
l_L50X3: ;/* line 1261 */
__LABEL(l_L50X3);
  sim_icache_fetch(691 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_13); /* line 1262 */
} /* line 1262 */
l_L51X3: ;/* line 1265 */
__LABEL(l_L51X3);
  sim_icache_fetch(692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1266 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1267 */
} /* line 1267 */
  sim_icache_fetch(694 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1269 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1270 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1271 */
  sim_icache_fetch(697 + t_thisfile.offset, 3);
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
      goto l_L53X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1275 */
  sim_icache_fetch(700 + t_thisfile.offset, 3);
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
      goto l_L54X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1279 */
  sim_icache_fetch(703 + t_thisfile.offset, 3);
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
      goto l_L55X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1283 */
  sim_icache_fetch(706 + t_thisfile.offset, 3);
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
      goto l_L56X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1287 */
  sim_icache_fetch(709 + t_thisfile.offset, 3);
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
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1291 */
  sim_icache_fetch(712 + t_thisfile.offset, 3);
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
      goto l_L58X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1295 */
  sim_icache_fetch(715 + t_thisfile.offset, 3);
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
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1299 */
  sim_icache_fetch(718 + t_thisfile.offset, 3);
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
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1303 */
  sim_icache_fetch(721 + t_thisfile.offset, 3);
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
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1307 */
  sim_icache_fetch(724 + t_thisfile.offset, 3);
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
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1311 */
  sim_icache_fetch(727 + t_thisfile.offset, 3);
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
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1315 */
  sim_icache_fetch(730 + t_thisfile.offset, 3);
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
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1319 */
  sim_icache_fetch(733 + t_thisfile.offset, 3);
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
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1323 */
  sim_icache_fetch(736 + t_thisfile.offset, 3);
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
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1327 */
  sim_icache_fetch(739 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1331 */
  sim_icache_fetch(742 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1333 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1334 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1335 */
  sim_icache_fetch(745 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1337 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L53X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1338 */
  sim_icache_fetch(747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1340 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1341 */
} /* line 1341 */
  sim_icache_fetch(749 + t_thisfile.offset, 3);
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
      goto l_L54X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1345 */
  sim_icache_fetch(752 + t_thisfile.offset, 3);
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
      goto l_L55X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1349 */
  sim_icache_fetch(755 + t_thisfile.offset, 3);
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
      goto l_L56X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1353 */
  sim_icache_fetch(758 + t_thisfile.offset, 3);
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
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1357 */
  sim_icache_fetch(761 + t_thisfile.offset, 3);
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
      goto l_L58X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1361 */
  sim_icache_fetch(764 + t_thisfile.offset, 3);
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
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1365 */
  sim_icache_fetch(767 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1367 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1368 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1369 */
  sim_icache_fetch(770 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1371 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1372 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1373 */
  sim_icache_fetch(773 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1375 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1376 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1377 */
  sim_icache_fetch(776 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1379 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1380 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1381 */
  sim_icache_fetch(779 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1383 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1384 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1385 */
  sim_icache_fetch(782 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1387 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1388 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1389 */
  sim_icache_fetch(785 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1391 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1392 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1393 */
  sim_icache_fetch(788 + t_thisfile.offset, 1);
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
} /* line 1395 */
  sim_icache_fetch(789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1397 */
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 1398 */
l_L67X3: ;/* line 1401 */
__LABEL(l_L67X3);
  sim_icache_fetch(791 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1402 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1403 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1404 */
} /* line 1404 */
  sim_icache_fetch(794 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1406 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1407 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 1408 */
l_L69X3: ;/* line 1411 */
__LABEL(l_L69X3);
  sim_icache_fetch(798 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1412 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1413 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1414 */
} /* line 1414 */
  sim_icache_fetch(804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1416 */
} /* line 1416 */
  sim_icache_fetch(806 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1418 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1419 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1420 */
} /* line 1420 */
  sim_icache_fetch(809 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1422 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1423 */
} /* line 1423 */
  sim_icache_fetch(812 + t_thisfile.offset, 1);
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
} /* line 1425 */
  sim_icache_fetch(813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1427 */
} /* line 1427 */
  sim_icache_fetch(815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1429 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1430 */
   __ADD_CYCLES(1);
} /* line 1430 */
  sim_icache_fetch(817 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1432 */
} /* line 1432 */
l_L71X3: ;/* line 1434 */
__LABEL(l_L71X3);
  sim_icache_fetch(818 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1435 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1436 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1437 */
} /* line 1437 */
  sim_icache_fetch(821 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1439 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1440 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1441 */
  sim_icache_fetch(824 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1443 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1444 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1445 */
} /* line 1445 */
  sim_icache_fetch(830 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1447 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1448 */
   __ADD_CYCLES(1);
} /* line 1448 */
  sim_icache_fetch(832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1450 */
} /* line 1450 */
  sim_icache_fetch(833 + t_thisfile.offset, 1);
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
} /* line 1452 */
  sim_icache_fetch(834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1454 */
} /* line 1454 */
  sim_icache_fetch(835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 1456 */
l_L73X3: ;/* line 1459 */
__LABEL(l_L73X3);
  sim_icache_fetch(836 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1460 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1461 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1462 */
} /* line 1462 */
  sim_icache_fetch(839 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1464 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1465 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1468 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1469 */
   __ADD_CYCLES(1);
} /* line 1469 */
  sim_icache_fetch(845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1471 */
} /* line 1471 */
  sim_icache_fetch(846 + t_thisfile.offset, 1);
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
} /* line 1473 */
l_L75X3: ;/* line 1475 */
__LABEL(l_L75X3);
		 /* line 1475 */
  sim_icache_fetch(847 + t_thisfile.offset, 2);
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
} /* line 1477 */
l_lr_107: ;/* line 1477 */
__LABEL(l_lr_107);
  sim_icache_fetch(849 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1479 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1480 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1481 */
} /* line 1481 */
  sim_icache_fetch(854 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1483 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1484 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1485 */
} /* line 1485 */
  sim_icache_fetch(858 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1487 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1488 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1489 */
} /* line 1489 */
  sim_icache_fetch(861 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1491 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1492 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1493 */
} /* line 1493 */
  sim_icache_fetch(866 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1495 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1496 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1497 */
  sim_icache_fetch(870 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1499 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1500 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1502 */
} /* line 1502 */
  sim_icache_fetch(874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 1504 */
l_L76X3: ;/* line 1507 */
__LABEL(l_L76X3);
  sim_icache_fetch(875 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1508 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1509 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1510 */
} /* line 1510 */
  sim_icache_fetch(880 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1512 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1513 */
} /* line 1513 */
  sim_icache_fetch(883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1515 */
} /* line 1515 */
  sim_icache_fetch(884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1517 */
} /* line 1517 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
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
} /* line 1519 */
		 /* line 1520 */
  sim_icache_fetch(886 + t_thisfile.offset, 2);
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
l_lr_110: ;/* line 1522 */
__LABEL(l_lr_110);
  sim_icache_fetch(888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1524 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1525 */
} /* line 1525 */
  sim_icache_fetch(890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 1527 */
l_L77X3: ;/* line 1530 */
__LABEL(l_L77X3);
  sim_icache_fetch(891 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1531 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1532 */
} /* line 1532 */
  sim_icache_fetch(893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 1534 */
l_L74X3: ;/* line 1537 */
__LABEL(l_L74X3);
  sim_icache_fetch(894 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1538 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1539 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1540 */
} /* line 1540 */
  sim_icache_fetch(897 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_10, reg_r0_9); /* line 1542 */
} /* line 1542 */
  sim_icache_fetch(898 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1544 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1545 */
} /* line 1545 */
  sim_icache_fetch(900 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1547 */
} /* line 1547 */
l_L78X3: ;/* line 1550 */
__LABEL(l_L78X3);
  sim_icache_fetch(901 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1551 */
} /* line 1551 */
  sim_icache_fetch(902 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1553 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1554 */
} /* line 1554 */
  sim_icache_fetch(904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1556 */
} /* line 1556 */
  sim_icache_fetch(905 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1558 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1559 */
} /* line 1559 */
  sim_icache_fetch(908 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1561 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1562 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1563 */
} /* line 1563 */
  sim_icache_fetch(911 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1565 */
} /* line 1565 */
  sim_icache_fetch(912 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1567 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1568 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1569 */
} /* line 1569 */
  sim_icache_fetch(916 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1571 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1572 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1573 */
  sim_icache_fetch(919 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1575 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1576 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1577 */
  sim_icache_fetch(922 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1579 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1580 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1581 */
} /* line 1581 */
  sim_icache_fetch(925 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1583 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1584 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1585 */
  sim_icache_fetch(929 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1587 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1588 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1589 */
  sim_icache_fetch(932 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1591 */
} /* line 1591 */
  sim_icache_fetch(933 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1593 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1594 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1595 */
} /* line 1595 */
  sim_icache_fetch(936 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1597 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1598 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1599 */
  sim_icache_fetch(940 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1601 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1602 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1603 */
  sim_icache_fetch(943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1605 */
} /* line 1605 */
  sim_icache_fetch(944 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1607 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1608 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1609 */
} /* line 1609 */
  sim_icache_fetch(947 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1611 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1612 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L85X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1613 */
  sim_icache_fetch(951 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1615 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1616 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1617 */
  sim_icache_fetch(954 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1619 */
} /* line 1619 */
  sim_icache_fetch(955 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1621 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1622 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1623 */
} /* line 1623 */
  sim_icache_fetch(958 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1625 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1626 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1627 */
  sim_icache_fetch(962 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1629 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1630 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1631 */
  sim_icache_fetch(965 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1633 */
} /* line 1633 */
  sim_icache_fetch(966 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1635 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1636 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1637 */
} /* line 1637 */
  sim_icache_fetch(969 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1639 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1640 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1641 */
  sim_icache_fetch(973 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1643 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1644 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1645 */
  sim_icache_fetch(976 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1647 */
} /* line 1647 */
  sim_icache_fetch(977 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1649 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1650 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1651 */
} /* line 1651 */
  sim_icache_fetch(980 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1653 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1654 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1655 */
  sim_icache_fetch(984 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1657 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1658 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1659 */
  sim_icache_fetch(987 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1661 */
} /* line 1661 */
  sim_icache_fetch(988 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1663 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1664 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1665 */
} /* line 1665 */
  sim_icache_fetch(991 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1667 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1668 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1669 */
  sim_icache_fetch(995 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1671 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1672 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1673 */
  sim_icache_fetch(998 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1675 */
} /* line 1675 */
  sim_icache_fetch(999 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1677 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1678 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1679 */
} /* line 1679 */
  sim_icache_fetch(1002 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1681 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1682 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1683 */
  sim_icache_fetch(1006 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1685 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1686 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1687 */
  sim_icache_fetch(1009 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1689 */
} /* line 1689 */
  sim_icache_fetch(1010 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1691 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1692 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1693 */
} /* line 1693 */
  sim_icache_fetch(1013 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1695 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1696 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1697 */
  sim_icache_fetch(1017 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1699 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1700 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1701 */
  sim_icache_fetch(1020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1703 */
} /* line 1703 */
  sim_icache_fetch(1021 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1705 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1706 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1707 */
} /* line 1707 */
  sim_icache_fetch(1024 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1709 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1710 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1711 */
  sim_icache_fetch(1028 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1713 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1714 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1715 */
  sim_icache_fetch(1031 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1717 */
} /* line 1717 */
  sim_icache_fetch(1032 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1719 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1720 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1721 */
} /* line 1721 */
  sim_icache_fetch(1035 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1723 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1724 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1725 */
  sim_icache_fetch(1039 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1727 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1728 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1729 */
  sim_icache_fetch(1042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1731 */
} /* line 1731 */
  sim_icache_fetch(1043 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1733 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1734 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1735 */
} /* line 1735 */
  sim_icache_fetch(1046 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1737 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1738 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1739 */
  sim_icache_fetch(1050 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1741 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1742 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1743 */
  sim_icache_fetch(1053 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1745 */
} /* line 1745 */
  sim_icache_fetch(1054 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1747 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1748 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1749 */
} /* line 1749 */
  sim_icache_fetch(1057 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1751 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1752 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1753 */
  sim_icache_fetch(1061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1755 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1756 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1757 */
  sim_icache_fetch(1064 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1759 */
} /* line 1759 */
  sim_icache_fetch(1065 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1761 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1762 */
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1763 */
} /* line 1763 */
  sim_icache_fetch(1068 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1765 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1766 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1767 */
  sim_icache_fetch(1072 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1769 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1770 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1771 */
  sim_icache_fetch(1075 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_7, reg_r0_4); /* line 1773 */
} /* line 1773 */
  sim_icache_fetch(1076 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1775 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1776 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1777 */
} /* line 1777 */
  sim_icache_fetch(1079 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1779 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1780 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1781 */
  sim_icache_fetch(1083 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1783 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1784 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1785 */
  sim_icache_fetch(1086 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1787 */
} /* line 1787 */
  sim_icache_fetch(1087 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1789 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1790 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1791 */
} /* line 1791 */
  sim_icache_fetch(1090 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1793 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1794 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1795 */
  sim_icache_fetch(1094 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1797 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1798 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1799 */
  sim_icache_fetch(1097 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1801 */
} /* line 1801 */
  sim_icache_fetch(1098 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1803 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1804 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1805 */
} /* line 1805 */
  sim_icache_fetch(1101 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1807 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1808 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1809 */
  sim_icache_fetch(1105 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1811 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1812 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1813 */
  sim_icache_fetch(1108 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1815 */
} /* line 1815 */
  sim_icache_fetch(1109 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1817 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1818 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1819 */
} /* line 1819 */
  sim_icache_fetch(1112 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1821 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1822 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1823 */
  sim_icache_fetch(1116 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1825 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1826 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1827 */
  sim_icache_fetch(1119 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1829 */
} /* line 1829 */
  sim_icache_fetch(1120 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1831 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1832 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1833 */
} /* line 1833 */
  sim_icache_fetch(1123 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1835 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1836 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1837 */
  sim_icache_fetch(1127 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1839 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1840 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1841 */
  sim_icache_fetch(1130 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1843 */
} /* line 1843 */
  sim_icache_fetch(1131 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1845 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1846 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1847 */
} /* line 1847 */
  sim_icache_fetch(1134 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1849 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1850 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1851 */
  sim_icache_fetch(1138 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1853 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1854 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1855 */
  sim_icache_fetch(1141 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1857 */
} /* line 1857 */
  sim_icache_fetch(1142 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1859 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1860 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1861 */
} /* line 1861 */
  sim_icache_fetch(1145 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1863 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1864 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1865 */
  sim_icache_fetch(1149 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1867 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1868 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1869 */
  sim_icache_fetch(1152 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1871 */
} /* line 1871 */
  sim_icache_fetch(1153 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1873 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1874 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1875 */
} /* line 1875 */
  sim_icache_fetch(1156 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1877 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1878 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1879 */
  sim_icache_fetch(1160 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1881 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1882 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1883 */
  sim_icache_fetch(1163 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1885 */
} /* line 1885 */
  sim_icache_fetch(1164 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1887 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1888 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1889 */
} /* line 1889 */
  sim_icache_fetch(1167 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1891 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1892 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1893 */
  sim_icache_fetch(1171 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1895 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1896 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1897 */
  sim_icache_fetch(1174 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1899 */
} /* line 1899 */
  sim_icache_fetch(1175 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1901 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1902 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1903 */
} /* line 1903 */
  sim_icache_fetch(1178 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1905 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1906 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1907 */
  sim_icache_fetch(1182 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1909 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1910 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1911 */
  sim_icache_fetch(1185 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1913 */
} /* line 1913 */
  sim_icache_fetch(1186 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1915 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1916 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1917 */
} /* line 1917 */
  sim_icache_fetch(1189 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1919 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1920 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1921 */
  sim_icache_fetch(1193 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1923 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1924 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1925 */
  sim_icache_fetch(1196 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1927 */
} /* line 1927 */
  sim_icache_fetch(1197 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1929 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1930 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1931 */
} /* line 1931 */
  sim_icache_fetch(1200 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1933 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1934 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1935 */
  sim_icache_fetch(1204 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1937 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1938 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1939 */
  sim_icache_fetch(1207 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1941 */
} /* line 1941 */
  sim_icache_fetch(1208 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1943 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1944 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1945 */
} /* line 1945 */
  sim_icache_fetch(1211 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1947 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1948 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1949 */
  sim_icache_fetch(1215 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1951 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1952 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1953 */
  sim_icache_fetch(1218 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1955 */
} /* line 1955 */
  sim_icache_fetch(1219 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1957 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1958 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1959 */
} /* line 1959 */
  sim_icache_fetch(1222 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1961 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1962 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1963 */
  sim_icache_fetch(1226 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1965 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1966 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1967 */
  sim_icache_fetch(1229 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_4, reg_r0_9); /* line 1969 */
} /* line 1969 */
  sim_icache_fetch(1230 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1971 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1972 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_7); /* line 1973 */
} /* line 1973 */
  sim_icache_fetch(1233 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1975 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1976 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1977 */
  sim_icache_fetch(1237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1979 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1980 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1981 */
  sim_icache_fetch(1240 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1983 */
} /* line 1983 */
  sim_icache_fetch(1241 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1985 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1986 */
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1987 */
} /* line 1987 */
  sim_icache_fetch(1244 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1989 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1990 */
  sim_icache_fetch(1247 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1992 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1993 */
  sim_icache_fetch(1249 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 1994 */
  sim_icache_fetch(1250 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1996 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1997 */
} /* line 1997 */
  sim_icache_fetch(1252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1999 */
  sim_icache_fetch(1253 + t_thisfile.offset, 1);
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
} /* line 2002 */
  sim_icache_fetch(1254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 2004 */
l_L141X3: ;/* line 2007 */
__LABEL(l_L141X3);
  sim_icache_fetch(1255 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2008 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2009 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2010 */
} /* line 2010 */
  sim_icache_fetch(1258 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2012 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2013 */
l_L109X3: ;/* line 2017 */
__LABEL(l_L109X3);
  sim_icache_fetch(1260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2018 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2020 */
} /* line 2020 */
  sim_icache_fetch(1262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2022 */
l_L140X3: ;/* line 2025 */
__LABEL(l_L140X3);
  sim_icache_fetch(1263 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2026 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2027 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2029 */
} /* line 2029 */
  sim_icache_fetch(1266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L143X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L143X3;
} /* line 2031 */
l_L139X3: ;/* line 2034 */
__LABEL(l_L139X3);
  sim_icache_fetch(1267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2035 */
} /* line 2035 */
l_L107X3: ;/* line 2038 */
__LABEL(l_L107X3);
  sim_icache_fetch(1268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2039 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2040 */
} /* line 2040 */
  sim_icache_fetch(1270 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2042 */
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2043 */
l_L138X3: ;/* line 2046 */
__LABEL(l_L138X3);
  sim_icache_fetch(1272 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2047 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2048 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2050 */
} /* line 2050 */
  sim_icache_fetch(1275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L144X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L144X3;
} /* line 2052 */
l_L137X3: ;/* line 2055 */
__LABEL(l_L137X3);
  sim_icache_fetch(1276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2056 */
} /* line 2056 */
l_L105X3: ;/* line 2059 */
__LABEL(l_L105X3);
  sim_icache_fetch(1277 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2060 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2061 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2063 */
} /* line 2063 */
  sim_icache_fetch(1280 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2065 */
l_L136X3: ;/* line 2068 */
__LABEL(l_L136X3);
  sim_icache_fetch(1281 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2069 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2070 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2072 */
} /* line 2072 */
  sim_icache_fetch(1284 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L145X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L145X3;
} /* line 2074 */
l_L135X3: ;/* line 2077 */
__LABEL(l_L135X3);
  sim_icache_fetch(1285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2078 */
} /* line 2078 */
l_L103X3: ;/* line 2081 */
__LABEL(l_L103X3);
  sim_icache_fetch(1286 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2082 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2083 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2085 */
} /* line 2085 */
  sim_icache_fetch(1289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2087 */
l_L134X3: ;/* line 2090 */
__LABEL(l_L134X3);
  sim_icache_fetch(1290 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2091 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2092 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2094 */
} /* line 2094 */
  sim_icache_fetch(1293 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L146X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L146X3;
} /* line 2096 */
l_L133X3: ;/* line 2099 */
__LABEL(l_L133X3);
  sim_icache_fetch(1294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2100 */
} /* line 2100 */
l_L101X3: ;/* line 2103 */
__LABEL(l_L101X3);
  sim_icache_fetch(1295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2104 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2105 */
} /* line 2105 */
  sim_icache_fetch(1297 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2107 */
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2108 */
l_L132X3: ;/* line 2111 */
__LABEL(l_L132X3);
  sim_icache_fetch(1299 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2112 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2113 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2115 */
} /* line 2115 */
  sim_icache_fetch(1302 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L147X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L147X3;
} /* line 2117 */
l_L131X3: ;/* line 2120 */
__LABEL(l_L131X3);
  sim_icache_fetch(1303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2121 */
} /* line 2121 */
l_L99X3: ;/* line 2124 */
__LABEL(l_L99X3);
  sim_icache_fetch(1304 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2125 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2126 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2128 */
} /* line 2128 */
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2130 */
l_L130X3: ;/* line 2133 */
__LABEL(l_L130X3);
  sim_icache_fetch(1308 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2134 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2135 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2137 */
} /* line 2137 */
  sim_icache_fetch(1311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L148X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L148X3;
} /* line 2139 */
l_L129X3: ;/* line 2142 */
__LABEL(l_L129X3);
  sim_icache_fetch(1312 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2143 */
} /* line 2143 */
l_L97X3: ;/* line 2146 */
__LABEL(l_L97X3);
  sim_icache_fetch(1313 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2147 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2148 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2150 */
} /* line 2150 */
  sim_icache_fetch(1316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2152 */
l_L128X3: ;/* line 2155 */
__LABEL(l_L128X3);
  sim_icache_fetch(1317 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2156 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2157 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2159 */
} /* line 2159 */
  sim_icache_fetch(1320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L149X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L149X3;
} /* line 2161 */
l_L127X3: ;/* line 2164 */
__LABEL(l_L127X3);
  sim_icache_fetch(1321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2165 */
} /* line 2165 */
l_L95X3: ;/* line 2168 */
__LABEL(l_L95X3);
  sim_icache_fetch(1322 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2169 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2170 */
} /* line 2170 */
  sim_icache_fetch(1324 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2172 */
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2173 */
l_L126X3: ;/* line 2176 */
__LABEL(l_L126X3);
  sim_icache_fetch(1326 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2177 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2178 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2180 */
} /* line 2180 */
  sim_icache_fetch(1329 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L150X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L150X3;
} /* line 2182 */
l_L125X3: ;/* line 2185 */
__LABEL(l_L125X3);
  sim_icache_fetch(1330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2186 */
} /* line 2186 */
l_L93X3: ;/* line 2189 */
__LABEL(l_L93X3);
  sim_icache_fetch(1331 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2190 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2191 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2193 */
} /* line 2193 */
  sim_icache_fetch(1334 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2195 */
l_L124X3: ;/* line 2198 */
__LABEL(l_L124X3);
  sim_icache_fetch(1335 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2199 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2200 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2202 */
} /* line 2202 */
  sim_icache_fetch(1338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L151X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L151X3;
} /* line 2204 */
l_L123X3: ;/* line 2207 */
__LABEL(l_L123X3);
  sim_icache_fetch(1339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2208 */
} /* line 2208 */
l_L91X3: ;/* line 2211 */
__LABEL(l_L91X3);
  sim_icache_fetch(1340 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2212 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2213 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2215 */
} /* line 2215 */
  sim_icache_fetch(1343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2217 */
l_L122X3: ;/* line 2220 */
__LABEL(l_L122X3);
  sim_icache_fetch(1344 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2221 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2222 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2224 */
} /* line 2224 */
  sim_icache_fetch(1347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L152X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L152X3;
} /* line 2226 */
l_L121X3: ;/* line 2229 */
__LABEL(l_L121X3);
  sim_icache_fetch(1348 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2230 */
} /* line 2230 */
l_L89X3: ;/* line 2233 */
__LABEL(l_L89X3);
  sim_icache_fetch(1349 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2234 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2235 */
} /* line 2235 */
  sim_icache_fetch(1351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2237 */
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2238 */
l_L120X3: ;/* line 2241 */
__LABEL(l_L120X3);
  sim_icache_fetch(1353 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2242 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2243 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2245 */
} /* line 2245 */
  sim_icache_fetch(1356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L153X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L153X3;
} /* line 2247 */
l_L119X3: ;/* line 2250 */
__LABEL(l_L119X3);
  sim_icache_fetch(1357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2251 */
} /* line 2251 */
l_L87X3: ;/* line 2254 */
__LABEL(l_L87X3);
  sim_icache_fetch(1358 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2255 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2256 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2258 */
} /* line 2258 */
  sim_icache_fetch(1361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2260 */
l_L118X3: ;/* line 2263 */
__LABEL(l_L118X3);
  sim_icache_fetch(1362 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2264 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2265 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2267 */
} /* line 2267 */
  sim_icache_fetch(1365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L154X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L154X3;
} /* line 2269 */
l_L117X3: ;/* line 2272 */
__LABEL(l_L117X3);
  sim_icache_fetch(1366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2273 */
} /* line 2273 */
l_L85X3: ;/* line 2276 */
__LABEL(l_L85X3);
  sim_icache_fetch(1367 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2277 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2278 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2280 */
} /* line 2280 */
  sim_icache_fetch(1370 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2282 */
l_L116X3: ;/* line 2285 */
__LABEL(l_L116X3);
  sim_icache_fetch(1371 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2286 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2287 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2289 */
} /* line 2289 */
  sim_icache_fetch(1374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L155X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L155X3;
} /* line 2291 */
l_L115X3: ;/* line 2294 */
__LABEL(l_L115X3);
  sim_icache_fetch(1375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2295 */
} /* line 2295 */
l_L83X3: ;/* line 2298 */
__LABEL(l_L83X3);
  sim_icache_fetch(1376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2299 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2300 */
} /* line 2300 */
  sim_icache_fetch(1378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2302 */
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2303 */
l_L114X3: ;/* line 2306 */
__LABEL(l_L114X3);
  sim_icache_fetch(1380 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2307 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2308 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2310 */
} /* line 2310 */
  sim_icache_fetch(1383 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L156X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L156X3;
} /* line 2312 */
l_L113X3: ;/* line 2315 */
__LABEL(l_L113X3);
  sim_icache_fetch(1384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2316 */
} /* line 2316 */
l_L81X3: ;/* line 2319 */
__LABEL(l_L81X3);
  sim_icache_fetch(1385 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2320 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2321 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2323 */
} /* line 2323 */
  sim_icache_fetch(1388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2325 */
l_L112X3: ;/* line 2328 */
__LABEL(l_L112X3);
  sim_icache_fetch(1389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2329 */
} /* line 2329 */
l_L80X3: ;/* line 2333 */
__LABEL(l_L80X3);
  sim_icache_fetch(1390 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2334 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2335 */
} /* line 2335 */
  sim_icache_fetch(1392 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2337 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2338 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2339 */
l_L111X3: ;/* line 2342 */
__LABEL(l_L111X3);
  sim_icache_fetch(1395 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2343 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2344 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2346 */
} /* line 2346 */
  sim_icache_fetch(1398 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L142X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L142X3;
} /* line 2348 */
l_L110X3: ;/* line 2351 */
__LABEL(l_L110X3);
  sim_icache_fetch(1399 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2352 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2353 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2354 */
} /* line 2354 */
  sim_icache_fetch(1402 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2356 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2357 */
l_L108X3: ;/* line 2360 */
__LABEL(l_L108X3);
  sim_icache_fetch(1404 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2361 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2362 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2363 */
} /* line 2363 */
l_L143X3: ;/* line 2365 */
__LABEL(l_L143X3);
  sim_icache_fetch(1407 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2366 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2367 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2368 */
l_L106X3: ;/* line 2371 */
__LABEL(l_L106X3);
  sim_icache_fetch(1410 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2372 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2373 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2374 */
} /* line 2374 */
l_L144X3: ;/* line 2376 */
__LABEL(l_L144X3);
  sim_icache_fetch(1413 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2377 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2378 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2379 */
l_L104X3: ;/* line 2382 */
__LABEL(l_L104X3);
  sim_icache_fetch(1416 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2383 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2384 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2385 */
} /* line 2385 */
l_L145X3: ;/* line 2387 */
__LABEL(l_L145X3);
  sim_icache_fetch(1419 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2388 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2389 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2390 */
l_L102X3: ;/* line 2393 */
__LABEL(l_L102X3);
  sim_icache_fetch(1422 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2394 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2395 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2396 */
} /* line 2396 */
l_L146X3: ;/* line 2398 */
__LABEL(l_L146X3);
  sim_icache_fetch(1425 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2399 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2400 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2401 */
l_L100X3: ;/* line 2404 */
__LABEL(l_L100X3);
  sim_icache_fetch(1428 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2405 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2406 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2407 */
} /* line 2407 */
l_L147X3: ;/* line 2409 */
__LABEL(l_L147X3);
  sim_icache_fetch(1431 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2410 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2411 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2412 */
l_L98X3: ;/* line 2415 */
__LABEL(l_L98X3);
  sim_icache_fetch(1434 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2416 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2417 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2418 */
} /* line 2418 */
l_L148X3: ;/* line 2420 */
__LABEL(l_L148X3);
  sim_icache_fetch(1437 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2421 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2422 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2423 */
l_L96X3: ;/* line 2426 */
__LABEL(l_L96X3);
  sim_icache_fetch(1440 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2427 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2428 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2429 */
} /* line 2429 */
l_L149X3: ;/* line 2431 */
__LABEL(l_L149X3);
  sim_icache_fetch(1443 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2432 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2433 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2434 */
l_L94X3: ;/* line 2437 */
__LABEL(l_L94X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2438 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2439 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2440 */
} /* line 2440 */
l_L150X3: ;/* line 2442 */
__LABEL(l_L150X3);
  sim_icache_fetch(1449 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2443 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2444 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2445 */
l_L92X3: ;/* line 2448 */
__LABEL(l_L92X3);
  sim_icache_fetch(1452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2449 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2450 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2451 */
} /* line 2451 */
l_L151X3: ;/* line 2453 */
__LABEL(l_L151X3);
  sim_icache_fetch(1455 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2454 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2455 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2456 */
l_L90X3: ;/* line 2459 */
__LABEL(l_L90X3);
  sim_icache_fetch(1458 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2460 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2461 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2462 */
} /* line 2462 */
l_L152X3: ;/* line 2464 */
__LABEL(l_L152X3);
  sim_icache_fetch(1461 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2465 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2466 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2467 */
l_L88X3: ;/* line 2470 */
__LABEL(l_L88X3);
  sim_icache_fetch(1464 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2471 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2472 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2473 */
} /* line 2473 */
l_L153X3: ;/* line 2475 */
__LABEL(l_L153X3);
  sim_icache_fetch(1467 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2476 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2477 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2478 */
l_L86X3: ;/* line 2481 */
__LABEL(l_L86X3);
  sim_icache_fetch(1470 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2482 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2483 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2484 */
} /* line 2484 */
l_L154X3: ;/* line 2486 */
__LABEL(l_L154X3);
  sim_icache_fetch(1473 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2487 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2488 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2489 */
l_L84X3: ;/* line 2492 */
__LABEL(l_L84X3);
  sim_icache_fetch(1476 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_8); /* line 2493 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2494 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2495 */
} /* line 2495 */
l_L155X3: ;/* line 2497 */
__LABEL(l_L155X3);
  sim_icache_fetch(1479 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2498 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2499 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2500 */
l_L82X3: ;/* line 2503 */
__LABEL(l_L82X3);
  sim_icache_fetch(1482 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_7); /* line 2504 */
   __MOV(reg_r0_3, reg_r0_10); /* line 2505 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2506 */
} /* line 2506 */
l_L156X3: ;/* line 2508 */
__LABEL(l_L156X3);
  sim_icache_fetch(1485 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2509 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2510 */
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2511 */
l_L79X3: ;/* line 2515 */
__LABEL(l_L79X3);
  sim_icache_fetch(1488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2516 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2517 */
} /* line 2517 */
l_L142X3: ;/* line 2519 */
__LABEL(l_L142X3);
  sim_icache_fetch(1490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2520 */
} /* line 2520 */
  sim_icache_fetch(1492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2522 */
} /* line 2522 */
  sim_icache_fetch(1493 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2524 */
l_L72X3: ;/* line 2527 */
__LABEL(l_L72X3);
		 /* line 2527 */
  sim_icache_fetch(1494 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2530 */
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
} /* line 2530 */
l_lr_194: ;/* line 2530 */
__LABEL(l_lr_194);
  sim_icache_fetch(1497 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2532 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2533 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2534 */
   __ADD_CYCLES(1);
} /* line 2534 */
  sim_icache_fetch(1501 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2536 */
} /* line 2536 */
		 /* line 2537 */
  sim_icache_fetch(1502 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2539 */
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
} /* line 2540 */
l_lr_196: ;/* line 2540 */
__LABEL(l_lr_196);
  sim_icache_fetch(1506 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2542 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2543 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2544 */
} /* line 2544 */
  sim_icache_fetch(1512 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2546 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2547 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2548 */
} /* line 2548 */
  sim_icache_fetch(1516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2550 */
   __MOV(reg_r0_3, 0); /* line 2551 */
} /* line 2551 */
  sim_icache_fetch(1518 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, reg_r0_7); /* line 2553 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L157X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2554 */
l_L158X3: ;/* line 2556 */
__LABEL(l_L158X3);
  sim_icache_fetch(1520 + t_thisfile.offset, 1);
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
} /* line 2557 */
  sim_icache_fetch(1521 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2559 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2560 */
} /* line 2560 */
l_L160X3: ;/* line 2562 */
__LABEL(l_L160X3);
  sim_icache_fetch(1524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2564 */
l_L159X3: ;/* line 2567 */
__LABEL(l_L159X3);
  sim_icache_fetch(1525 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2568 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2569 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2570 */
l_L157X3: ;/* line 2573 */
__LABEL(l_L157X3);
  sim_icache_fetch(1528 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2574 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2575 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2576 */
   __ADD_CYCLES(1);
} /* line 2576 */
		 /* line 2577 */
  sim_icache_fetch(1533 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2579 */
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
} /* line 2580 */
l_lr_202: ;/* line 2580 */
__LABEL(l_lr_202);
  sim_icache_fetch(1536 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2582 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2583 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2584 */
} /* line 2584 */
  sim_icache_fetch(1541 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2586 */
   __MOV(reg_r0_3, 0); /* line 2587 */
} /* line 2587 */
  sim_icache_fetch(1543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, reg_r0_7); /* line 2589 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2590 */
l_L70X3: ;/* line 2593 */
__LABEL(l_L70X3);
  sim_icache_fetch(1545 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2594 */
   __GOTO(l_L71X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L71X3;
} /* line 2595 */
l_L66X3: ;/* line 2598 */
__LABEL(l_L66X3);
  sim_icache_fetch(1547 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2599 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2600 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2601 */
} /* line 2601 */
  sim_icache_fetch(1550 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2603 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2604 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2605 */
l_L65X3: ;/* line 2608 */
__LABEL(l_L65X3);
  sim_icache_fetch(1554 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2609 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2610 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2611 */
} /* line 2611 */
  sim_icache_fetch(1557 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2613 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2614 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2615 */
l_L64X3: ;/* line 2618 */
__LABEL(l_L64X3);
  sim_icache_fetch(1561 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2619 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2620 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2621 */
} /* line 2621 */
  sim_icache_fetch(1564 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2623 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2624 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2625 */
l_L63X3: ;/* line 2628 */
__LABEL(l_L63X3);
  sim_icache_fetch(1568 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2629 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2630 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2631 */
} /* line 2631 */
  sim_icache_fetch(1571 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2633 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2634 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2635 */
l_L62X3: ;/* line 2638 */
__LABEL(l_L62X3);
  sim_icache_fetch(1575 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2639 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2640 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2641 */
} /* line 2641 */
  sim_icache_fetch(1578 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2643 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2644 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2645 */
l_L61X3: ;/* line 2648 */
__LABEL(l_L61X3);
  sim_icache_fetch(1582 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2649 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2650 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2651 */
} /* line 2651 */
  sim_icache_fetch(1585 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2653 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2654 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2655 */
l_L60X3: ;/* line 2658 */
__LABEL(l_L60X3);
  sim_icache_fetch(1589 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2659 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2660 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2661 */
} /* line 2661 */
  sim_icache_fetch(1592 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2663 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2664 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2665 */
l_L59X3: ;/* line 2668 */
__LABEL(l_L59X3);
  sim_icache_fetch(1596 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2669 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2670 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2671 */
} /* line 2671 */
  sim_icache_fetch(1599 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2673 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2674 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2675 */
l_L58X3: ;/* line 2678 */
__LABEL(l_L58X3);
  sim_icache_fetch(1603 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2679 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2680 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2681 */
} /* line 2681 */
  sim_icache_fetch(1606 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2683 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2684 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2685 */
l_L57X3: ;/* line 2688 */
__LABEL(l_L57X3);
  sim_icache_fetch(1610 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2689 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2690 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2691 */
} /* line 2691 */
  sim_icache_fetch(1613 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2693 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2694 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2695 */
l_L56X3: ;/* line 2698 */
__LABEL(l_L56X3);
  sim_icache_fetch(1617 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2699 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2700 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2701 */
} /* line 2701 */
  sim_icache_fetch(1620 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2703 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2704 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2705 */
l_L55X3: ;/* line 2708 */
__LABEL(l_L55X3);
  sim_icache_fetch(1624 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2709 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2710 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2711 */
} /* line 2711 */
  sim_icache_fetch(1627 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2713 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2714 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2715 */
l_L54X3: ;/* line 2718 */
__LABEL(l_L54X3);
  sim_icache_fetch(1631 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2719 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2720 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2721 */
} /* line 2721 */
  sim_icache_fetch(1634 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2723 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2724 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2725 */
l_L53X3: ;/* line 2728 */
__LABEL(l_L53X3);
  sim_icache_fetch(1638 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2729 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2730 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2731 */
} /* line 2731 */
  sim_icache_fetch(1641 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2733 */
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2734 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2735 */
l_L52X3: ;/* line 2738 */
__LABEL(l_L52X3);
  sim_icache_fetch(1645 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2739 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2740 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2741 */
} /* line 2741 */
  sim_icache_fetch(1648 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2744 */
} /* line 2744 */
l_L68X3: ;/* line 2746 */
__LABEL(l_L68X3);
  sim_icache_fetch(1650 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2747 */
} /* line 2747 */
		 /* line 2748 */
  sim_icache_fetch(1651 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_57); /* line 2751 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2752 */
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
} /* line 2752 */
l_lr_221: ;/* line 2752 */
__LABEL(l_lr_221);
  sim_icache_fetch(1655 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2754 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2755 */
} /* line 2755 */
  sim_icache_fetch(1657 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 2757 */
l_L49X3: ;/* line 2760 */
__LABEL(l_L49X3);
  sim_icache_fetch(1658 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_13, (unsigned int) -1); /* line 2761 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2762 */
} /* line 2762 */
  sim_icache_fetch(1660 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L50X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L50X3;
} /* line 2764 */
l_L47X3: ;/* line 2767 */
__LABEL(l_L47X3);
  sim_icache_fetch(1661 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_3, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2768 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2769 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2770 */
} /* line 2770 */
  sim_icache_fetch(1666 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2772 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2773 */
} /* line 2773 */
  sim_icache_fetch(1668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 2775 */
} /* line 2775 */
  sim_icache_fetch(1669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 2777 */
} /* line 2777 */
  sim_icache_fetch(1671 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2779 */
} /* line 2779 */
  sim_icache_fetch(1672 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2781 */
   __LDBU(reg_r0_3, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2782 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2783 */
   __ADD_CYCLES(1);
} /* line 2783 */
  sim_icache_fetch(1677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 2785 */
} /* line 2785 */
  sim_icache_fetch(1678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 2787 */
} /* line 2787 */
  sim_icache_fetch(1680 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2789 */
} /* line 2789 */
  sim_icache_fetch(1681 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2791 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2792 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2793 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2794 */
   __ADD_CYCLES(1);
} /* line 2794 */
  sim_icache_fetch(1688 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 1); /* line 2796 */
   __OR(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2797 */
} /* line 2797 */
  sim_icache_fetch(1690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 2799 */
} /* line 2799 */
  sim_icache_fetch(1692 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2801 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2802 */
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 2803 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 199: goto l_L48X3;
    case 200: goto l_L50X3;
    case 201: goto l_L51X3;
    case 202: goto l_L67X3;
    case 203: goto l_L69X3;
    case 204: goto l_L71X3;
    case 205: goto l_L73X3;
    case 206: goto l_L75X3;
    case 208: goto l_lr_107;
    case 209: goto l_L76X3;
    case 211: goto l_lr_110;
    case 212: goto l_L77X3;
    case 213: goto l_L74X3;
    case 214: goto l_L78X3;
    case 215: goto l_L141X3;
    case 216: goto l_L109X3;
    case 217: goto l_L140X3;
    case 218: goto l_L139X3;
    case 219: goto l_L107X3;
    case 220: goto l_L138X3;
    case 221: goto l_L137X3;
    case 222: goto l_L105X3;
    case 223: goto l_L136X3;
    case 224: goto l_L135X3;
    case 225: goto l_L103X3;
    case 226: goto l_L134X3;
    case 227: goto l_L133X3;
    case 228: goto l_L101X3;
    case 229: goto l_L132X3;
    case 230: goto l_L131X3;
    case 231: goto l_L99X3;
    case 232: goto l_L130X3;
    case 233: goto l_L129X3;
    case 234: goto l_L97X3;
    case 235: goto l_L128X3;
    case 236: goto l_L127X3;
    case 237: goto l_L95X3;
    case 238: goto l_L126X3;
    case 239: goto l_L125X3;
    case 240: goto l_L93X3;
    case 241: goto l_L124X3;
    case 242: goto l_L123X3;
    case 243: goto l_L91X3;
    case 244: goto l_L122X3;
    case 245: goto l_L121X3;
    case 246: goto l_L89X3;
    case 247: goto l_L120X3;
    case 248: goto l_L119X3;
    case 249: goto l_L87X3;
    case 250: goto l_L118X3;
    case 251: goto l_L117X3;
    case 252: goto l_L85X3;
    case 253: goto l_L116X3;
    case 254: goto l_L115X3;
    case 255: goto l_L83X3;
    case 256: goto l_L114X3;
    case 257: goto l_L113X3;
    case 258: goto l_L81X3;
    case 259: goto l_L112X3;
    case 260: goto l_L80X3;
    case 261: goto l_L111X3;
    case 262: goto l_L110X3;
    case 263: goto l_L108X3;
    case 264: goto l_L143X3;
    case 265: goto l_L106X3;
    case 266: goto l_L144X3;
    case 267: goto l_L104X3;
    case 268: goto l_L145X3;
    case 269: goto l_L102X3;
    case 270: goto l_L146X3;
    case 271: goto l_L100X3;
    case 272: goto l_L147X3;
    case 273: goto l_L98X3;
    case 274: goto l_L148X3;
    case 275: goto l_L96X3;
    case 276: goto l_L149X3;
    case 277: goto l_L94X3;
    case 278: goto l_L150X3;
    case 279: goto l_L92X3;
    case 280: goto l_L151X3;
    case 281: goto l_L90X3;
    case 282: goto l_L152X3;
    case 283: goto l_L88X3;
    case 284: goto l_L153X3;
    case 285: goto l_L86X3;
    case 286: goto l_L154X3;
    case 287: goto l_L84X3;
    case 288: goto l_L155X3;
    case 289: goto l_L82X3;
    case 290: goto l_L156X3;
    case 291: goto l_L79X3;
    case 292: goto l_L142X3;
    case 293: goto l_L72X3;
    case 295: goto l_lr_194;
    case 297: goto l_lr_196;
    case 298: goto l_L158X3;
    case 299: goto l_L160X3;
    case 300: goto l_L159X3;
    case 301: goto l_L157X3;
    case 303: goto l_lr_202;
    case 304: goto l_L70X3;
    case 305: goto l_L66X3;
    case 306: goto l_L65X3;
    case 307: goto l_L64X3;
    case 308: goto l_L63X3;
    case 309: goto l_L62X3;
    case 310: goto l_L61X3;
    case 311: goto l_L60X3;
    case 312: goto l_L59X3;
    case 313: goto l_L58X3;
    case 314: goto l_L57X3;
    case 315: goto l_L56X3;
    case 316: goto l_L55X3;
    case 317: goto l_L54X3;
    case 318: goto l_L53X3;
    case 319: goto l_L52X3;
    case 320: goto l_L68X3;
    case 322: goto l_lr_221;
    case 323: goto l_L49X3;
    case 324: goto l_L47X3;
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
  reg_l0_0 = (358 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1696 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 2822 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2823 */
} /* line 2823 */
  sim_icache_fetch(1700 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2825 */
} /* line 2825 */
  sim_icache_fetch(1701 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2827 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2828 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L161X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2829 */
  sim_icache_fetch(1704 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2831 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2832 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2833 */
} /* line 2833 */
  sim_icache_fetch(1709 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_9256Xbuf); /* line 2835 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_9256Xbuf),0,1)); /* line 2836 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2837 */
} /* line 2837 */
  sim_icache_fetch(1714 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_9256Xbuf + (unsigned int) 1)); /* line 2839 */
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2840 */
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2841 */
} /* line 2841 */
  sim_icache_fetch(1718 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2843 */
   __MOV(reg_r0_8, reg_r0_3); /* line 2844 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2845 */
} /* line 2845 */
  sim_icache_fetch(1721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2847 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2848 */
} /* line 2848 */
  sim_icache_fetch(1723 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_9256Xbuf),0,1), reg_r0_2); /* line 2850 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2851 */
} /* line 2851 */
  sim_icache_fetch(1726 + t_thisfile.offset, 1);
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
} /* line 2853 */
  sim_icache_fetch(1727 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2855 */
   __SHR(reg_r0_8, reg_r0_3, (unsigned int) 8); /* line 2856 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2857 */
} /* line 2857 */
  sim_icache_fetch(1730 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2859 */
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2860 */
} /* line 2860 */
l_L163X3: ;/* line 2862 */
__LABEL(l_L163X3);
  sim_icache_fetch(1732 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) compress_9256Xbuf); /* line 2863 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L164X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2864 */
  sim_icache_fetch(1735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_8); /* line 2866 */
} /* line 2866 */
l_L164X3: ;/* line 2868 */
__LABEL(l_L164X3);
  sim_icache_fetch(1736 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 2869 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2870 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2871 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2872 */
   __ADD_CYCLES(1);
} /* line 2872 */
  sim_icache_fetch(1743 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2874 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2875 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2876 */
} /* line 2876 */
  sim_icache_fetch(1746 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) compress_9256Xoffset,0,4), reg_r0_2); /* line 2878 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2879 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2880 */
} /* line 2880 */
  sim_icache_fetch(1750 + t_thisfile.offset, 1);
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
} /* line 2882 */
  sim_icache_fetch(1751 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2884 */
} /* line 2884 */
l_L166X3: ;/* line 2887 */
__LABEL(l_L166X3);
  sim_icache_fetch(1753 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2888 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2889 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2890 */
} /* line 2890 */
  sim_icache_fetch(1757 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2892 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2893 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2894 */
} /* line 2894 */
  sim_icache_fetch(1760 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2896 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2897 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2898 */
} /* line 2898 */
  sim_icache_fetch(1763 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2900 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2901 */
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) 16); /* line 2902 */
} /* line 2902 */
  sim_icache_fetch(1766 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2904 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -16); /* line 2905 */
} /* line 2905 */
  sim_icache_fetch(1769 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2907 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2908 */
  sim_icache_fetch(1771 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2910 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2911 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2912 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2913 */
   __ADD_CYCLES(1);
} /* line 2913 */
  sim_icache_fetch(1776 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2915 */
} /* line 2915 */
  sim_icache_fetch(1777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2917 */
} /* line 2917 */
  sim_icache_fetch(1779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2919 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2920 */
  sim_icache_fetch(1781 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2922 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2923 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2924 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2925 */
   __ADD_CYCLES(1);
} /* line 2925 */
  sim_icache_fetch(1786 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2927 */
} /* line 2927 */
  sim_icache_fetch(1787 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2929 */
} /* line 2929 */
  sim_icache_fetch(1789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2931 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2932 */
  sim_icache_fetch(1791 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2934 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2935 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2936 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2937 */
   __ADD_CYCLES(1);
} /* line 2937 */
  sim_icache_fetch(1796 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2939 */
} /* line 2939 */
  sim_icache_fetch(1797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2941 */
} /* line 2941 */
  sim_icache_fetch(1799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2943 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2944 */
  sim_icache_fetch(1801 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2946 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2947 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2948 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2949 */
   __ADD_CYCLES(1);
} /* line 2949 */
  sim_icache_fetch(1806 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2951 */
} /* line 2951 */
  sim_icache_fetch(1807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2953 */
} /* line 2953 */
  sim_icache_fetch(1809 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2955 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2956 */
  sim_icache_fetch(1811 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2958 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2959 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2960 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2961 */
   __ADD_CYCLES(1);
} /* line 2961 */
  sim_icache_fetch(1816 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2963 */
} /* line 2963 */
  sim_icache_fetch(1817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2965 */
} /* line 2965 */
  sim_icache_fetch(1819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2967 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2968 */
  sim_icache_fetch(1821 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2970 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2971 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2972 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2973 */
   __ADD_CYCLES(1);
} /* line 2973 */
  sim_icache_fetch(1826 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2975 */
} /* line 2975 */
  sim_icache_fetch(1827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2977 */
} /* line 2977 */
  sim_icache_fetch(1829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2979 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2980 */
  sim_icache_fetch(1831 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2982 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2983 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2984 */
} /* line 2984 */
  sim_icache_fetch(1835 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_8, (unsigned int) -16); /* line 2986 */
} /* line 2986 */
  sim_icache_fetch(1836 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2988 */
} /* line 2988 */
  sim_icache_fetch(1837 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2990 */
} /* line 2990 */
  sim_icache_fetch(1839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2992 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2993 */
  sim_icache_fetch(1841 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2995 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2996 */
   __CMPEQ(reg_b0_7, reg_r0_8, 0); /* line 2997 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2998 */
   __ADD_CYCLES(1);
} /* line 2998 */
  sim_icache_fetch(1846 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3000 */
} /* line 3000 */
  sim_icache_fetch(1847 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3002 */
} /* line 3002 */
  sim_icache_fetch(1849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3004 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3005 */
  sim_icache_fetch(1851 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 3007 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3008 */
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 3009 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3010 */
   __ADD_CYCLES(1);
} /* line 3010 */
  sim_icache_fetch(1856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3012 */
} /* line 3012 */
  sim_icache_fetch(1857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3014 */
} /* line 3014 */
  sim_icache_fetch(1859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3016 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3017 */
  sim_icache_fetch(1861 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 3019 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3020 */
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 2); /* line 3021 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3022 */
   __ADD_CYCLES(1);
} /* line 3022 */
  sim_icache_fetch(1866 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3024 */
} /* line 3024 */
  sim_icache_fetch(1867 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3026 */
} /* line 3026 */
  sim_icache_fetch(1869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3028 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3029 */
  sim_icache_fetch(1871 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 3031 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3032 */
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 3); /* line 3033 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3034 */
   __ADD_CYCLES(1);
} /* line 3034 */
  sim_icache_fetch(1876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3036 */
} /* line 3036 */
  sim_icache_fetch(1877 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3038 */
} /* line 3038 */
  sim_icache_fetch(1879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3040 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3041 */
  sim_icache_fetch(1881 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 3043 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3044 */
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 4); /* line 3045 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3046 */
   __ADD_CYCLES(1);
} /* line 3046 */
  sim_icache_fetch(1886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3048 */
} /* line 3048 */
  sim_icache_fetch(1887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3050 */
} /* line 3050 */
  sim_icache_fetch(1889 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3052 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3053 */
  sim_icache_fetch(1891 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 3055 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3056 */
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 5); /* line 3057 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3058 */
   __ADD_CYCLES(1);
} /* line 3058 */
  sim_icache_fetch(1896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3060 */
} /* line 3060 */
  sim_icache_fetch(1897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3062 */
} /* line 3062 */
  sim_icache_fetch(1899 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3064 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3065 */
  sim_icache_fetch(1901 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 3067 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3068 */
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 6); /* line 3069 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3070 */
   __ADD_CYCLES(1);
} /* line 3070 */
  sim_icache_fetch(1906 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3072 */
} /* line 3072 */
  sim_icache_fetch(1907 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3074 */
} /* line 3074 */
  sim_icache_fetch(1909 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3076 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3077 */
  sim_icache_fetch(1911 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 3079 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3080 */
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 7); /* line 3081 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3082 */
   __ADD_CYCLES(1);
} /* line 3082 */
  sim_icache_fetch(1916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3084 */
} /* line 3084 */
  sim_icache_fetch(1917 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3086 */
} /* line 3086 */
  sim_icache_fetch(1919 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3088 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3089 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3090 */
  sim_icache_fetch(1922 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_7,0,1)); /* line 3092 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3093 */
   __MFB(reg_r0_6, reg_b0_7); /* line 3094 */
} /* line 3094 */
  sim_icache_fetch(1926 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_7, reg_r0_8, (unsigned int) 8); /* line 3096 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) 16); /* line 3097 */
} /* line 3097 */
  sim_icache_fetch(1928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3099 */
} /* line 3099 */
  sim_icache_fetch(1929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3101 */
} /* line 3101 */
  sim_icache_fetch(1931 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3103 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3104 */
  sim_icache_fetch(1933 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 1),0,1)); /* line 3106 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3107 */
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 9); /* line 3108 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3109 */
   __ADD_CYCLES(1);
} /* line 3109 */
  sim_icache_fetch(1938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3111 */
} /* line 3111 */
  sim_icache_fetch(1939 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3113 */
} /* line 3113 */
  sim_icache_fetch(1941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3115 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3116 */
  sim_icache_fetch(1943 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,1)); /* line 3118 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3119 */
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 10); /* line 3120 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3121 */
   __ADD_CYCLES(1);
} /* line 3121 */
  sim_icache_fetch(1948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3123 */
} /* line 3123 */
  sim_icache_fetch(1949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3125 */
} /* line 3125 */
  sim_icache_fetch(1951 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3127 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3128 */
  sim_icache_fetch(1953 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 3),0,1)); /* line 3130 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3131 */
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 11); /* line 3132 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3133 */
   __ADD_CYCLES(1);
} /* line 3133 */
  sim_icache_fetch(1958 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3135 */
} /* line 3135 */
  sim_icache_fetch(1959 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3137 */
} /* line 3137 */
  sim_icache_fetch(1961 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3139 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3140 */
  sim_icache_fetch(1963 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,1)); /* line 3142 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3143 */
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 12); /* line 3144 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3145 */
   __ADD_CYCLES(1);
} /* line 3145 */
  sim_icache_fetch(1968 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3147 */
} /* line 3147 */
  sim_icache_fetch(1969 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3149 */
} /* line 3149 */
  sim_icache_fetch(1971 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3151 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3152 */
  sim_icache_fetch(1973 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 5),0,1)); /* line 3154 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3155 */
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 13); /* line 3156 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3157 */
   __ADD_CYCLES(1);
} /* line 3157 */
  sim_icache_fetch(1978 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3159 */
} /* line 3159 */
  sim_icache_fetch(1979 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3161 */
} /* line 3161 */
  sim_icache_fetch(1981 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3163 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3164 */
  sim_icache_fetch(1983 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 6),0,1)); /* line 3166 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3167 */
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 14); /* line 3168 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3169 */
   __ADD_CYCLES(1);
} /* line 3169 */
  sim_icache_fetch(1988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3171 */
} /* line 3171 */
  sim_icache_fetch(1989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3173 */
} /* line 3173 */
  sim_icache_fetch(1991 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3175 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3176 */
  sim_icache_fetch(1993 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 7),0,1)); /* line 3178 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3179 */
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 15); /* line 3180 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3181 */
   __ADD_CYCLES(1);
} /* line 3181 */
  sim_icache_fetch(1998 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3183 */
} /* line 3183 */
  sim_icache_fetch(1999 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3185 */
} /* line 3185 */
  sim_icache_fetch(2001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3187 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3188 */
  sim_icache_fetch(2003 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 8),0,1)); /* line 3190 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3191 */
   __MTB(reg_b0_7, reg_r0_6); /* line 3192 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3193 */
   __ADD_CYCLES(1);
} /* line 3193 */
  sim_icache_fetch(2008 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3195 */
} /* line 3195 */
  sim_icache_fetch(2009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3197 */
} /* line 3197 */
  sim_icache_fetch(2011 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3199 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3200 */
  sim_icache_fetch(2013 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 9),0,1)); /* line 3202 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3203 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3204 */
   __ADD_CYCLES(1);
} /* line 3204 */
  sim_icache_fetch(2017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3206 */
} /* line 3206 */
  sim_icache_fetch(2018 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3208 */
} /* line 3208 */
  sim_icache_fetch(2020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3210 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3211 */
  sim_icache_fetch(2022 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 10),0,1)); /* line 3213 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3214 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3215 */
   __ADD_CYCLES(1);
} /* line 3215 */
  sim_icache_fetch(2026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3217 */
} /* line 3217 */
  sim_icache_fetch(2027 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3219 */
} /* line 3219 */
  sim_icache_fetch(2029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3221 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3222 */
  sim_icache_fetch(2031 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 11),0,1)); /* line 3224 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3225 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3226 */
   __ADD_CYCLES(1);
} /* line 3226 */
  sim_icache_fetch(2035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3228 */
} /* line 3228 */
  sim_icache_fetch(2036 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3230 */
} /* line 3230 */
  sim_icache_fetch(2038 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3232 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3233 */
  sim_icache_fetch(2040 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,1)); /* line 3235 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3236 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3237 */
   __ADD_CYCLES(1);
} /* line 3237 */
  sim_icache_fetch(2044 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3239 */
} /* line 3239 */
  sim_icache_fetch(2045 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3241 */
} /* line 3241 */
  sim_icache_fetch(2047 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3243 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3244 */
  sim_icache_fetch(2049 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 13),0,1)); /* line 3246 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3247 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3248 */
   __ADD_CYCLES(1);
} /* line 3248 */
  sim_icache_fetch(2053 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3250 */
} /* line 3250 */
  sim_icache_fetch(2054 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3252 */
} /* line 3252 */
  sim_icache_fetch(2056 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3254 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3255 */
  sim_icache_fetch(2058 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 14),0,1)); /* line 3257 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3258 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3259 */
   __ADD_CYCLES(1);
} /* line 3259 */
  sim_icache_fetch(2062 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3261 */
} /* line 3261 */
  sim_icache_fetch(2063 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3263 */
} /* line 3263 */
  sim_icache_fetch(2065 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3265 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3266 */
  sim_icache_fetch(2067 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_7, mem_trace_ld((reg_r0_7 + (unsigned int) 15),0,1)); /* line 3268 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3269 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3270 */
   __ADD_CYCLES(1);
} /* line 3270 */
  sim_icache_fetch(2071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3272 */
} /* line 3272 */
  sim_icache_fetch(2072 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3274 */
} /* line 3274 */
  sim_icache_fetch(2074 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 3276 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L167X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3278 */
  sim_icache_fetch(2076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L166X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L166X3;
} /* line 3280 */
l_L167X3: ;/* line 3283 */
__LABEL(l_L167X3);
  sim_icache_fetch(2077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_9256Xoffset,0,4), 0); /* line 3284 */
} /* line 3284 */
l_L165X3: ;/* line 3287 */
__LABEL(l_L165X3);
  sim_icache_fetch(2079 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3288 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3289 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3290 */
} /* line 3290 */
  sim_icache_fetch(2085 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 3292 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3293 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3294 */
} /* line 3294 */
  sim_icache_fetch(2089 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3296 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3297 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3298 */
} /* line 3298 */
  sim_icache_fetch(2092 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_2, reg_r0_6); /* line 3300 */
   __CMPGT(reg_b0_1, reg_r0_22, 0); /* line 3301 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3302 */
} /* line 3302 */
  sim_icache_fetch(2095 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3304 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3305 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L168X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3306 */
  sim_icache_fetch(2098 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3308 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3309 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L169X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3310 */
  sim_icache_fetch(2101 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3312 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3313 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3314 */
} /* line 3314 */
  sim_icache_fetch(2104 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3316 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3317 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3318 */
} /* line 3318 */
  sim_icache_fetch(2107 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3320 */
   __MOV(reg_r0_5, (unsigned int) compress_9256Xbuf); /* line 3321 */
   __MOV(reg_r0_3, 0); /* line 3322 */
} /* line 3322 */
l_L170X3: ;/* line 3325 */
__LABEL(l_L170X3);
  sim_icache_fetch(2111 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3326 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3327 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3328 */
} /* line 3328 */
  sim_icache_fetch(2116 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3330 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3331 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3332 */
} /* line 3332 */
  sim_icache_fetch(2119 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3334 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3335 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3336 */
} /* line 3336 */
  sim_icache_fetch(2122 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3338 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3339 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L171X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3340 */
  sim_icache_fetch(2125 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3342 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3343 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3344 */
} /* line 3344 */
  sim_icache_fetch(2128 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3346 */
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3347 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3348 */
} /* line 3348 */
  sim_icache_fetch(2131 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3350 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3351 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3352 */
} /* line 3352 */
  sim_icache_fetch(2134 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3354 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3355 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3356 */
} /* line 3356 */
  sim_icache_fetch(2138 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3358 */
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 16); /* line 3359 */
} /* line 3359 */
  sim_icache_fetch(2140 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3361 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3362 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3363 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3364 */
   __ADD_CYCLES(1);
} /* line 3364 */
  sim_icache_fetch(2146 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_4); /* line 3366 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3367 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3368 */
} /* line 3368 */
  sim_icache_fetch(2149 + t_thisfile.offset, 1);
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
} /* line 3370 */
  sim_icache_fetch(2150 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3372 */
} /* line 3372 */
  sim_icache_fetch(2152 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3374 */
} /* line 3374 */
  sim_icache_fetch(2153 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3376 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3377 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3378 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3379 */
   __ADD_CYCLES(1);
} /* line 3379 */
  sim_icache_fetch(2159 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_4); /* line 3381 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3382 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3383 */
} /* line 3383 */
  sim_icache_fetch(2162 + t_thisfile.offset, 1);
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
} /* line 3385 */
  sim_icache_fetch(2163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3387 */
} /* line 3387 */
  sim_icache_fetch(2165 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3389 */
} /* line 3389 */
  sim_icache_fetch(2166 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3391 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3392 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3393 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3394 */
   __ADD_CYCLES(1);
} /* line 3394 */
  sim_icache_fetch(2172 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_4); /* line 3396 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3397 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3398 */
} /* line 3398 */
  sim_icache_fetch(2175 + t_thisfile.offset, 1);
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
} /* line 3400 */
  sim_icache_fetch(2176 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3402 */
} /* line 3402 */
  sim_icache_fetch(2178 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3404 */
} /* line 3404 */
  sim_icache_fetch(2179 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3406 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3407 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3408 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3409 */
   __ADD_CYCLES(1);
} /* line 3409 */
  sim_icache_fetch(2185 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_4); /* line 3411 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3412 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3413 */
} /* line 3413 */
  sim_icache_fetch(2188 + t_thisfile.offset, 1);
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
} /* line 3415 */
  sim_icache_fetch(2189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3417 */
} /* line 3417 */
  sim_icache_fetch(2191 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3419 */
} /* line 3419 */
  sim_icache_fetch(2192 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3421 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3422 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3423 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3424 */
   __ADD_CYCLES(1);
} /* line 3424 */
  sim_icache_fetch(2198 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_4); /* line 3426 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3427 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3428 */
} /* line 3428 */
  sim_icache_fetch(2201 + t_thisfile.offset, 1);
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
} /* line 3430 */
  sim_icache_fetch(2202 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3432 */
} /* line 3432 */
  sim_icache_fetch(2204 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3434 */
} /* line 3434 */
  sim_icache_fetch(2205 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3436 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3437 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3438 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3439 */
   __ADD_CYCLES(1);
} /* line 3439 */
  sim_icache_fetch(2211 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_4); /* line 3441 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3442 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3443 */
} /* line 3443 */
  sim_icache_fetch(2214 + t_thisfile.offset, 1);
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
} /* line 3445 */
  sim_icache_fetch(2215 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3447 */
} /* line 3447 */
  sim_icache_fetch(2217 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3449 */
} /* line 3449 */
  sim_icache_fetch(2218 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3451 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3452 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3453 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3454 */
   __ADD_CYCLES(1);
} /* line 3454 */
  sim_icache_fetch(2224 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_4); /* line 3456 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3457 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3458 */
} /* line 3458 */
  sim_icache_fetch(2227 + t_thisfile.offset, 1);
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
} /* line 3460 */
  sim_icache_fetch(2228 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3462 */
} /* line 3462 */
  sim_icache_fetch(2230 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3464 */
} /* line 3464 */
  sim_icache_fetch(2231 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3466 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3467 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3468 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3469 */
   __ADD_CYCLES(1);
} /* line 3469 */
  sim_icache_fetch(2237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_4); /* line 3471 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3472 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3473 */
} /* line 3473 */
  sim_icache_fetch(2240 + t_thisfile.offset, 1);
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
} /* line 3475 */
  sim_icache_fetch(2241 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3477 */
} /* line 3477 */
  sim_icache_fetch(2243 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3479 */
} /* line 3479 */
  sim_icache_fetch(2244 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3481 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3482 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3483 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3484 */
   __ADD_CYCLES(1);
} /* line 3484 */
  sim_icache_fetch(2250 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_4); /* line 3486 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3487 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3488 */
} /* line 3488 */
  sim_icache_fetch(2253 + t_thisfile.offset, 1);
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
} /* line 3490 */
  sim_icache_fetch(2254 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3492 */
} /* line 3492 */
  sim_icache_fetch(2256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3494 */
} /* line 3494 */
  sim_icache_fetch(2257 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3496 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3497 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3498 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3499 */
   __ADD_CYCLES(1);
} /* line 3499 */
  sim_icache_fetch(2263 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_4); /* line 3501 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3502 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3503 */
} /* line 3503 */
  sim_icache_fetch(2266 + t_thisfile.offset, 1);
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
} /* line 3505 */
  sim_icache_fetch(2267 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3507 */
} /* line 3507 */
  sim_icache_fetch(2269 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3509 */
} /* line 3509 */
  sim_icache_fetch(2270 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3511 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3512 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3513 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3514 */
   __ADD_CYCLES(1);
} /* line 3514 */
  sim_icache_fetch(2276 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_4); /* line 3516 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3517 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3518 */
} /* line 3518 */
  sim_icache_fetch(2279 + t_thisfile.offset, 1);
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
} /* line 3520 */
  sim_icache_fetch(2280 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3522 */
} /* line 3522 */
  sim_icache_fetch(2282 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3524 */
} /* line 3524 */
  sim_icache_fetch(2283 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3526 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3527 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3528 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3529 */
   __ADD_CYCLES(1);
} /* line 3529 */
  sim_icache_fetch(2289 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_4); /* line 3531 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3532 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3533 */
} /* line 3533 */
  sim_icache_fetch(2292 + t_thisfile.offset, 1);
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
} /* line 3535 */
  sim_icache_fetch(2293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3537 */
} /* line 3537 */
  sim_icache_fetch(2295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3539 */
} /* line 3539 */
  sim_icache_fetch(2296 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3541 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3542 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3543 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3544 */
   __ADD_CYCLES(1);
} /* line 3544 */
  sim_icache_fetch(2302 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_4); /* line 3546 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3547 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3548 */
} /* line 3548 */
  sim_icache_fetch(2305 + t_thisfile.offset, 1);
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
} /* line 3550 */
  sim_icache_fetch(2306 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3552 */
} /* line 3552 */
  sim_icache_fetch(2308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3554 */
} /* line 3554 */
  sim_icache_fetch(2309 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3556 */
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3557 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3558 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3559 */
   __ADD_CYCLES(1);
} /* line 3559 */
  sim_icache_fetch(2315 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_4); /* line 3561 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3562 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3563 */
} /* line 3563 */
  sim_icache_fetch(2318 + t_thisfile.offset, 1);
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
} /* line 3565 */
  sim_icache_fetch(2319 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3567 */
} /* line 3567 */
  sim_icache_fetch(2321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3569 */
} /* line 3569 */
  sim_icache_fetch(2322 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3571 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3572 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3573 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3574 */
   __ADD_CYCLES(1);
} /* line 3574 */
  sim_icache_fetch(2328 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_4); /* line 3576 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3577 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3578 */
} /* line 3578 */
  sim_icache_fetch(2331 + t_thisfile.offset, 1);
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
} /* line 3580 */
  sim_icache_fetch(2332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3582 */
} /* line 3582 */
  sim_icache_fetch(2334 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_5); /* line 3584 */
} /* line 3584 */
  sim_icache_fetch(2335 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3586 */
   __LDBs(reg_r0_38, mem_trace_ld(reg_r0_37,0,1)); /* line 3587 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3588 */
} /* line 3588 */
  sim_icache_fetch(2340 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3590 */
} /* line 3590 */
  sim_icache_fetch(2341 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 3592 */
   __ADD(reg_r0_4, reg_r0_6, (unsigned int) 1); /* line 3593 */
   __MOV(reg_r0_3, reg_r0_2); /* line 3594 */
} /* line 3594 */
  sim_icache_fetch(2344 + t_thisfile.offset, 1);
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
} /* line 3596 */
  sim_icache_fetch(2345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3598 */
} /* line 3598 */
  sim_icache_fetch(2347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_6,0,1), reg_r0_38); /* line 3600 */
} /* line 3600 */
  sim_icache_fetch(2348 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3602 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3603 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3604 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3605 */
   __ADD_CYCLES(1);
} /* line 3605 */
  sim_icache_fetch(2354 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3607 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3608 */
} /* line 3608 */
  sim_icache_fetch(2356 + t_thisfile.offset, 1);
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
} /* line 3610 */
  sim_icache_fetch(2357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3612 */
} /* line 3612 */
  sim_icache_fetch(2359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3614 */
} /* line 3614 */
  sim_icache_fetch(2360 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3616 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3617 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3618 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3619 */
   __ADD_CYCLES(1);
} /* line 3619 */
  sim_icache_fetch(2366 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3621 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3622 */
} /* line 3622 */
  sim_icache_fetch(2368 + t_thisfile.offset, 1);
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
} /* line 3624 */
  sim_icache_fetch(2369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3626 */
} /* line 3626 */
  sim_icache_fetch(2371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3628 */
} /* line 3628 */
  sim_icache_fetch(2372 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3630 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3631 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3632 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3633 */
   __ADD_CYCLES(1);
} /* line 3633 */
  sim_icache_fetch(2378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3635 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3636 */
} /* line 3636 */
  sim_icache_fetch(2380 + t_thisfile.offset, 1);
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
} /* line 3638 */
  sim_icache_fetch(2381 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3640 */
} /* line 3640 */
  sim_icache_fetch(2383 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3642 */
} /* line 3642 */
  sim_icache_fetch(2384 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3644 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3645 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3646 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3647 */
   __ADD_CYCLES(1);
} /* line 3647 */
  sim_icache_fetch(2390 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3649 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3650 */
} /* line 3650 */
  sim_icache_fetch(2392 + t_thisfile.offset, 1);
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
} /* line 3652 */
  sim_icache_fetch(2393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3654 */
} /* line 3654 */
  sim_icache_fetch(2395 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3656 */
} /* line 3656 */
  sim_icache_fetch(2396 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3658 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3659 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3660 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3661 */
   __ADD_CYCLES(1);
} /* line 3661 */
  sim_icache_fetch(2402 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3663 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3664 */
} /* line 3664 */
  sim_icache_fetch(2404 + t_thisfile.offset, 1);
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
} /* line 3666 */
  sim_icache_fetch(2405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3668 */
} /* line 3668 */
  sim_icache_fetch(2407 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3670 */
} /* line 3670 */
  sim_icache_fetch(2408 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3672 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3673 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3674 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3675 */
   __ADD_CYCLES(1);
} /* line 3675 */
  sim_icache_fetch(2414 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3677 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3678 */
} /* line 3678 */
  sim_icache_fetch(2416 + t_thisfile.offset, 1);
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
} /* line 3680 */
  sim_icache_fetch(2417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3682 */
} /* line 3682 */
  sim_icache_fetch(2419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3684 */
} /* line 3684 */
  sim_icache_fetch(2420 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3686 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3687 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3688 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3689 */
   __ADD_CYCLES(1);
} /* line 3689 */
  sim_icache_fetch(2426 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3691 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3692 */
} /* line 3692 */
  sim_icache_fetch(2428 + t_thisfile.offset, 1);
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
} /* line 3694 */
  sim_icache_fetch(2429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3696 */
} /* line 3696 */
  sim_icache_fetch(2431 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3698 */
} /* line 3698 */
  sim_icache_fetch(2432 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3700 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3701 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3702 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3703 */
   __ADD_CYCLES(1);
} /* line 3703 */
  sim_icache_fetch(2438 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3705 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3706 */
} /* line 3706 */
  sim_icache_fetch(2440 + t_thisfile.offset, 1);
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
} /* line 3708 */
  sim_icache_fetch(2441 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3710 */
} /* line 3710 */
  sim_icache_fetch(2443 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3712 */
} /* line 3712 */
  sim_icache_fetch(2444 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3714 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3715 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3716 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3717 */
   __ADD_CYCLES(1);
} /* line 3717 */
  sim_icache_fetch(2450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3719 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3720 */
} /* line 3720 */
  sim_icache_fetch(2452 + t_thisfile.offset, 1);
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
} /* line 3722 */
  sim_icache_fetch(2453 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3724 */
} /* line 3724 */
  sim_icache_fetch(2455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3726 */
} /* line 3726 */
  sim_icache_fetch(2456 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3728 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3729 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3730 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3731 */
   __ADD_CYCLES(1);
} /* line 3731 */
  sim_icache_fetch(2462 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3733 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3734 */
} /* line 3734 */
  sim_icache_fetch(2464 + t_thisfile.offset, 1);
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
} /* line 3736 */
  sim_icache_fetch(2465 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3738 */
} /* line 3738 */
  sim_icache_fetch(2467 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3740 */
} /* line 3740 */
  sim_icache_fetch(2468 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3742 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3743 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3744 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3745 */
   __ADD_CYCLES(1);
} /* line 3745 */
  sim_icache_fetch(2474 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3747 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3748 */
} /* line 3748 */
  sim_icache_fetch(2476 + t_thisfile.offset, 1);
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
} /* line 3750 */
  sim_icache_fetch(2477 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3752 */
} /* line 3752 */
  sim_icache_fetch(2479 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3754 */
} /* line 3754 */
  sim_icache_fetch(2480 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3756 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3757 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3758 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3759 */
   __ADD_CYCLES(1);
} /* line 3759 */
  sim_icache_fetch(2486 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3761 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3762 */
} /* line 3762 */
  sim_icache_fetch(2488 + t_thisfile.offset, 1);
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
} /* line 3764 */
  sim_icache_fetch(2489 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3766 */
} /* line 3766 */
  sim_icache_fetch(2491 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3768 */
} /* line 3768 */
  sim_icache_fetch(2492 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3770 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3771 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3772 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3773 */
   __ADD_CYCLES(1);
} /* line 3773 */
  sim_icache_fetch(2498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3775 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3776 */
} /* line 3776 */
  sim_icache_fetch(2500 + t_thisfile.offset, 1);
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
} /* line 3778 */
  sim_icache_fetch(2501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3780 */
} /* line 3780 */
  sim_icache_fetch(2503 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3782 */
} /* line 3782 */
  sim_icache_fetch(2504 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3784 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3785 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3786 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3787 */
   __ADD_CYCLES(1);
} /* line 3787 */
  sim_icache_fetch(2510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3789 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3790 */
} /* line 3790 */
  sim_icache_fetch(2512 + t_thisfile.offset, 1);
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
} /* line 3792 */
  sim_icache_fetch(2513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3794 */
} /* line 3794 */
  sim_icache_fetch(2515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3796 */
} /* line 3796 */
  sim_icache_fetch(2516 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3798 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3799 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3800 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3801 */
   __ADD_CYCLES(1);
} /* line 3801 */
  sim_icache_fetch(2522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3803 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3804 */
} /* line 3804 */
  sim_icache_fetch(2524 + t_thisfile.offset, 1);
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
} /* line 3806 */
  sim_icache_fetch(2525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(2527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3810 */
   __GOTO(l_L170X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L170X3;
} /* line 3811 */
l_L171X3: ;/* line 3814 */
__LABEL(l_L171X3);
  sim_icache_fetch(2529 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3815 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3816 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3817 */
   __ADD_CYCLES(1);
} /* line 3817 */
  sim_icache_fetch(2534 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3819 */
} /* line 3819 */
  sim_icache_fetch(2535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3821 */
} /* line 3821 */
l_L169X3: ;/* line 3824 */
__LABEL(l_L169X3);
  sim_icache_fetch(2537 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3825 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3826 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3827 */
} /* line 3827 */
  sim_icache_fetch(2542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_9256Xoffset,0,4), 0); /* line 3829 */
} /* line 3829 */
  sim_icache_fetch(2544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3831 */
} /* line 3831 */
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
} /* line 3833 */
  sim_icache_fetch(2546 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3835 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3836 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3837 */
} /* line 3837 */
  sim_icache_fetch(2552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3840 */
l_L172X3: ;/* line 3843 */
__LABEL(l_L172X3);
  sim_icache_fetch(2553 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3844 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3845 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3846 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3847 */
   __ADD_CYCLES(1);
} /* line 3847 */
  sim_icache_fetch(2560 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3849 */
} /* line 3849 */
  sim_icache_fetch(2561 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3851 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3852 */
} /* line 3852 */
  sim_icache_fetch(2564 + t_thisfile.offset, 1);
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
} /* line 3854 */
  sim_icache_fetch(2565 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3857 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3858 */
l_L173X3: ;/* line 3861 */
__LABEL(l_L173X3);
  sim_icache_fetch(2568 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3862 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3863 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3864 */
   __ADD_CYCLES(1);
} /* line 3864 */
  sim_icache_fetch(2572 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3866 */
} /* line 3866 */
  sim_icache_fetch(2573 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3868 */
} /* line 3868 */
  sim_icache_fetch(2574 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3871 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3872 */
l_L168X3: ;/* line 3875 */
__LABEL(l_L168X3);
  sim_icache_fetch(2577 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3877 */
l_L162X3: ;/* line 3880 */
__LABEL(l_L162X3);
  sim_icache_fetch(2578 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 3881 */
   __GOTO(l_L163X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L163X3;
} /* line 3882 */
l_L161X3: ;/* line 3885 */
__LABEL(l_L161X3);
  sim_icache_fetch(2580 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 3886 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3887 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 3888 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3889 */
   __ADD_CYCLES(1);
} /* line 3889 */
  sim_icache_fetch(2587 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3891 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3892 */
} /* line 3892 */
  sim_icache_fetch(2589 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3894 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3895 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L174X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3896 */
l_L175X3: ;/* line 3898 */
__LABEL(l_L175X3);
  sim_icache_fetch(2592 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3899 */
   __STW(mem_trace_st((unsigned int) compress_9256Xoffset,0,4), 0); /* line 3900 */
} /* line 3900 */
  sim_icache_fetch(2595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3902 */
} /* line 3902 */
  sim_icache_fetch(2596 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3904 */
} /* line 3904 */
  sim_icache_fetch(2597 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3907 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3908 */
l_L174X3: ;/* line 3911 */
__LABEL(l_L174X3);
  sim_icache_fetch(2600 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3912 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3913 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3914 */
} /* line 3914 */
  sim_icache_fetch(2603 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3916 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3917 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3918 */
} /* line 3918 */
  sim_icache_fetch(2606 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3920 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3921 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3922 */
} /* line 3922 */
  sim_icache_fetch(2609 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3924 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3925 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3926 */
} /* line 3926 */
  sim_icache_fetch(2612 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3928 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3929 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3930 */
} /* line 3930 */
  sim_icache_fetch(2615 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) compress_9256Xbuf); /* line 3932 */
   __MOV(reg_r0_3, 0); /* line 3933 */
} /* line 3933 */
l_L176X3: ;/* line 3936 */
__LABEL(l_L176X3);
  sim_icache_fetch(2618 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 3937 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3938 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3939 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3940 */
   __ADD_CYCLES(1);
} /* line 3940 */
  sim_icache_fetch(2624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3942 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3943 */
} /* line 3943 */
  sim_icache_fetch(2626 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3945 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3946 */
} /* line 3946 */
  sim_icache_fetch(2628 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3948 */
} /* line 3948 */
  sim_icache_fetch(2629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3950 */
} /* line 3950 */
  sim_icache_fetch(2630 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3952 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3953 */
} /* line 3953 */
  sim_icache_fetch(2632 + t_thisfile.offset, 1);
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
} /* line 3955 */
  sim_icache_fetch(2633 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3957 */
} /* line 3957 */
  sim_icache_fetch(2635 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3959 */
} /* line 3959 */
  sim_icache_fetch(2636 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 3961 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3962 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3963 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3964 */
   __ADD_CYCLES(1);
} /* line 3964 */
  sim_icache_fetch(2642 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3966 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3967 */
} /* line 3967 */
  sim_icache_fetch(2644 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3969 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3970 */
} /* line 3970 */
  sim_icache_fetch(2646 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3972 */
} /* line 3972 */
  sim_icache_fetch(2647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3974 */
} /* line 3974 */
  sim_icache_fetch(2648 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3976 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3977 */
} /* line 3977 */
  sim_icache_fetch(2650 + t_thisfile.offset, 1);
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
} /* line 3979 */
  sim_icache_fetch(2651 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3981 */
} /* line 3981 */
  sim_icache_fetch(2653 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3983 */
} /* line 3983 */
  sim_icache_fetch(2654 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 3985 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3986 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3987 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3988 */
   __ADD_CYCLES(1);
} /* line 3988 */
  sim_icache_fetch(2660 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3990 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3991 */
} /* line 3991 */
  sim_icache_fetch(2662 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3993 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3994 */
} /* line 3994 */
  sim_icache_fetch(2664 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3996 */
} /* line 3996 */
  sim_icache_fetch(2665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3998 */
} /* line 3998 */
  sim_icache_fetch(2666 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 4000 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 4001 */
} /* line 4001 */
  sim_icache_fetch(2668 + t_thisfile.offset, 1);
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
} /* line 4003 */
  sim_icache_fetch(2669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4005 */
} /* line 4005 */
  sim_icache_fetch(2671 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4007 */
} /* line 4007 */
  sim_icache_fetch(2672 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4009 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 4010 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4011 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4012 */
   __ADD_CYCLES(1);
} /* line 4012 */
  sim_icache_fetch(2678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4014 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4015 */
} /* line 4015 */
  sim_icache_fetch(2680 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4017 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4018 */
} /* line 4018 */
  sim_icache_fetch(2682 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4020 */
} /* line 4020 */
  sim_icache_fetch(2683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4022 */
} /* line 4022 */
  sim_icache_fetch(2684 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 4024 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 4025 */
} /* line 4025 */
  sim_icache_fetch(2686 + t_thisfile.offset, 1);
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
} /* line 4027 */
  sim_icache_fetch(2687 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4029 */
} /* line 4029 */
  sim_icache_fetch(2689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4031 */
} /* line 4031 */
  sim_icache_fetch(2690 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4033 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 4034 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4035 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4036 */
   __ADD_CYCLES(1);
} /* line 4036 */
  sim_icache_fetch(2696 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4038 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4039 */
} /* line 4039 */
  sim_icache_fetch(2698 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4041 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4042 */
} /* line 4042 */
  sim_icache_fetch(2700 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4044 */
} /* line 4044 */
  sim_icache_fetch(2701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4046 */
} /* line 4046 */
  sim_icache_fetch(2702 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 4048 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 4049 */
} /* line 4049 */
  sim_icache_fetch(2704 + t_thisfile.offset, 1);
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
} /* line 4051 */
  sim_icache_fetch(2705 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4053 */
} /* line 4053 */
  sim_icache_fetch(2707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4055 */
} /* line 4055 */
  sim_icache_fetch(2708 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4057 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 4058 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4059 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4060 */
   __ADD_CYCLES(1);
} /* line 4060 */
  sim_icache_fetch(2714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4062 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4063 */
} /* line 4063 */
  sim_icache_fetch(2716 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4065 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4066 */
} /* line 4066 */
  sim_icache_fetch(2718 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4068 */
} /* line 4068 */
  sim_icache_fetch(2719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4070 */
} /* line 4070 */
  sim_icache_fetch(2720 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 4072 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 4073 */
} /* line 4073 */
  sim_icache_fetch(2722 + t_thisfile.offset, 1);
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
} /* line 4075 */
  sim_icache_fetch(2723 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4077 */
} /* line 4077 */
  sim_icache_fetch(2725 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4079 */
} /* line 4079 */
  sim_icache_fetch(2726 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4081 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 4082 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4083 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4084 */
   __ADD_CYCLES(1);
} /* line 4084 */
  sim_icache_fetch(2732 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4086 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4087 */
} /* line 4087 */
  sim_icache_fetch(2734 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4089 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4090 */
} /* line 4090 */
  sim_icache_fetch(2736 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4092 */
} /* line 4092 */
  sim_icache_fetch(2737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4094 */
} /* line 4094 */
  sim_icache_fetch(2738 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 4096 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 4097 */
} /* line 4097 */
  sim_icache_fetch(2740 + t_thisfile.offset, 1);
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
} /* line 4099 */
  sim_icache_fetch(2741 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4101 */
} /* line 4101 */
  sim_icache_fetch(2743 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4103 */
} /* line 4103 */
  sim_icache_fetch(2744 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4105 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4106 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4107 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4108 */
   __ADD_CYCLES(1);
} /* line 4108 */
  sim_icache_fetch(2750 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4110 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4111 */
} /* line 4111 */
  sim_icache_fetch(2752 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4113 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4114 */
} /* line 4114 */
  sim_icache_fetch(2754 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4116 */
} /* line 4116 */
  sim_icache_fetch(2755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4118 */
} /* line 4118 */
  sim_icache_fetch(2756 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4120 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4121 */
} /* line 4121 */
  sim_icache_fetch(2758 + t_thisfile.offset, 1);
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
} /* line 4123 */
  sim_icache_fetch(2759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4125 */
} /* line 4125 */
  sim_icache_fetch(2761 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4127 */
} /* line 4127 */
  sim_icache_fetch(2762 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4129 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4130 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4131 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4132 */
   __ADD_CYCLES(1);
} /* line 4132 */
  sim_icache_fetch(2768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4134 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4135 */
} /* line 4135 */
  sim_icache_fetch(2770 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4137 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4138 */
} /* line 4138 */
  sim_icache_fetch(2772 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4140 */
} /* line 4140 */
  sim_icache_fetch(2773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4142 */
} /* line 4142 */
  sim_icache_fetch(2774 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4144 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4145 */
} /* line 4145 */
  sim_icache_fetch(2776 + t_thisfile.offset, 1);
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
} /* line 4147 */
  sim_icache_fetch(2777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4149 */
} /* line 4149 */
  sim_icache_fetch(2779 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4151 */
} /* line 4151 */
  sim_icache_fetch(2780 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4153 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4154 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4155 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4156 */
   __ADD_CYCLES(1);
} /* line 4156 */
  sim_icache_fetch(2786 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4158 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4159 */
} /* line 4159 */
  sim_icache_fetch(2788 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4161 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4162 */
} /* line 4162 */
  sim_icache_fetch(2790 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4164 */
} /* line 4164 */
  sim_icache_fetch(2791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4166 */
} /* line 4166 */
  sim_icache_fetch(2792 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4168 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4169 */
} /* line 4169 */
  sim_icache_fetch(2794 + t_thisfile.offset, 1);
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
} /* line 4171 */
  sim_icache_fetch(2795 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4173 */
} /* line 4173 */
  sim_icache_fetch(2797 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4175 */
} /* line 4175 */
  sim_icache_fetch(2798 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4177 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4178 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4179 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4180 */
   __ADD_CYCLES(1);
} /* line 4180 */
  sim_icache_fetch(2804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4182 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4183 */
} /* line 4183 */
  sim_icache_fetch(2806 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4185 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4186 */
} /* line 4186 */
  sim_icache_fetch(2808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4188 */
} /* line 4188 */
  sim_icache_fetch(2809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4190 */
} /* line 4190 */
  sim_icache_fetch(2810 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4192 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4193 */
} /* line 4193 */
  sim_icache_fetch(2812 + t_thisfile.offset, 1);
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
} /* line 4195 */
  sim_icache_fetch(2813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4197 */
} /* line 4197 */
  sim_icache_fetch(2815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4199 */
} /* line 4199 */
  sim_icache_fetch(2816 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4201 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4202 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4203 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4204 */
   __ADD_CYCLES(1);
} /* line 4204 */
  sim_icache_fetch(2822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4206 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4207 */
} /* line 4207 */
  sim_icache_fetch(2824 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4209 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4210 */
} /* line 4210 */
  sim_icache_fetch(2826 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4212 */
} /* line 4212 */
  sim_icache_fetch(2827 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4214 */
} /* line 4214 */
  sim_icache_fetch(2828 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4216 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4217 */
} /* line 4217 */
  sim_icache_fetch(2830 + t_thisfile.offset, 1);
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
} /* line 4219 */
  sim_icache_fetch(2831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4221 */
} /* line 4221 */
  sim_icache_fetch(2833 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4223 */
} /* line 4223 */
  sim_icache_fetch(2834 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4225 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4226 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4227 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4228 */
   __ADD_CYCLES(1);
} /* line 4228 */
  sim_icache_fetch(2840 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4230 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4231 */
} /* line 4231 */
  sim_icache_fetch(2842 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4233 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4234 */
} /* line 4234 */
  sim_icache_fetch(2844 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4236 */
} /* line 4236 */
  sim_icache_fetch(2845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4238 */
} /* line 4238 */
  sim_icache_fetch(2846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4240 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4241 */
} /* line 4241 */
  sim_icache_fetch(2848 + t_thisfile.offset, 1);
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
} /* line 4243 */
  sim_icache_fetch(2849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4245 */
} /* line 4245 */
  sim_icache_fetch(2851 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4247 */
} /* line 4247 */
  sim_icache_fetch(2852 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4249 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4250 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4251 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4252 */
   __ADD_CYCLES(1);
} /* line 4252 */
  sim_icache_fetch(2858 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4254 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4255 */
} /* line 4255 */
  sim_icache_fetch(2860 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4257 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4258 */
} /* line 4258 */
  sim_icache_fetch(2862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4260 */
} /* line 4260 */
  sim_icache_fetch(2863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4262 */
} /* line 4262 */
  sim_icache_fetch(2864 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4264 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4265 */
} /* line 4265 */
  sim_icache_fetch(2866 + t_thisfile.offset, 1);
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
} /* line 4267 */
  sim_icache_fetch(2867 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4269 */
} /* line 4269 */
  sim_icache_fetch(2869 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4271 */
} /* line 4271 */
  sim_icache_fetch(2870 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4273 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4274 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4275 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4276 */
   __ADD_CYCLES(1);
} /* line 4276 */
  sim_icache_fetch(2876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4278 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4279 */
} /* line 4279 */
  sim_icache_fetch(2878 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4281 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4282 */
} /* line 4282 */
  sim_icache_fetch(2880 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4284 */
} /* line 4284 */
  sim_icache_fetch(2881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4286 */
} /* line 4286 */
  sim_icache_fetch(2882 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4288 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4289 */
} /* line 4289 */
  sim_icache_fetch(2884 + t_thisfile.offset, 1);
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
} /* line 4291 */
  sim_icache_fetch(2885 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4293 */
} /* line 4293 */
  sim_icache_fetch(2887 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4295 */
} /* line 4295 */
  sim_icache_fetch(2888 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4297 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4298 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4299 */
} /* line 4299 */
  sim_icache_fetch(2893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4301 */
} /* line 4301 */
  sim_icache_fetch(2894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4303 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4304 */
} /* line 4304 */
  sim_icache_fetch(2896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4306 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4307 */
} /* line 4307 */
  sim_icache_fetch(2898 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4309 */
} /* line 4309 */
  sim_icache_fetch(2899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4311 */
} /* line 4311 */
  sim_icache_fetch(2900 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4313 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4314 */
} /* line 4314 */
  sim_icache_fetch(2902 + t_thisfile.offset, 1);
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
} /* line 4316 */
  sim_icache_fetch(2903 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4318 */
} /* line 4318 */
  sim_icache_fetch(2905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4320 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 4321 */
l_L192X3: ;/* line 4324 */
__LABEL(l_L192X3);
  sim_icache_fetch(2907 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4325 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4326 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4327 */
   __ADD_CYCLES(1);
} /* line 4327 */
  sim_icache_fetch(2912 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4329 */
} /* line 4329 */
  sim_icache_fetch(2913 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4331 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4332 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4333 */
l_L191X3: ;/* line 4336 */
__LABEL(l_L191X3);
  sim_icache_fetch(2916 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4337 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4338 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4339 */
   __ADD_CYCLES(1);
} /* line 4339 */
  sim_icache_fetch(2921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4341 */
} /* line 4341 */
  sim_icache_fetch(2922 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4343 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4344 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4345 */
l_L190X3: ;/* line 4348 */
__LABEL(l_L190X3);
  sim_icache_fetch(2925 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4349 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4350 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4351 */
   __ADD_CYCLES(1);
} /* line 4351 */
  sim_icache_fetch(2930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4353 */
} /* line 4353 */
  sim_icache_fetch(2931 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4355 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4356 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4357 */
l_L189X3: ;/* line 4360 */
__LABEL(l_L189X3);
  sim_icache_fetch(2934 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4361 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4362 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4363 */
   __ADD_CYCLES(1);
} /* line 4363 */
  sim_icache_fetch(2939 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4365 */
} /* line 4365 */
  sim_icache_fetch(2940 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4367 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4368 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4369 */
l_L188X3: ;/* line 4372 */
__LABEL(l_L188X3);
  sim_icache_fetch(2943 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4373 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4374 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4375 */
   __ADD_CYCLES(1);
} /* line 4375 */
  sim_icache_fetch(2948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4377 */
} /* line 4377 */
  sim_icache_fetch(2949 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4379 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4380 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4381 */
l_L187X3: ;/* line 4384 */
__LABEL(l_L187X3);
  sim_icache_fetch(2952 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4385 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4386 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4387 */
   __ADD_CYCLES(1);
} /* line 4387 */
  sim_icache_fetch(2957 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4389 */
} /* line 4389 */
  sim_icache_fetch(2958 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4391 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4392 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4393 */
l_L186X3: ;/* line 4396 */
__LABEL(l_L186X3);
  sim_icache_fetch(2961 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4397 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4398 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4399 */
   __ADD_CYCLES(1);
} /* line 4399 */
  sim_icache_fetch(2966 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4401 */
} /* line 4401 */
  sim_icache_fetch(2967 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4403 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4404 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4405 */
l_L185X3: ;/* line 4408 */
__LABEL(l_L185X3);
  sim_icache_fetch(2970 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4409 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4410 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4411 */
   __ADD_CYCLES(1);
} /* line 4411 */
  sim_icache_fetch(2975 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4413 */
} /* line 4413 */
  sim_icache_fetch(2976 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4415 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4416 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4417 */
l_L184X3: ;/* line 4420 */
__LABEL(l_L184X3);
  sim_icache_fetch(2979 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4421 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4422 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4423 */
   __ADD_CYCLES(1);
} /* line 4423 */
  sim_icache_fetch(2984 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4425 */
} /* line 4425 */
  sim_icache_fetch(2985 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4427 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4428 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4429 */
l_L183X3: ;/* line 4432 */
__LABEL(l_L183X3);
  sim_icache_fetch(2988 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4433 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4434 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4435 */
   __ADD_CYCLES(1);
} /* line 4435 */
  sim_icache_fetch(2993 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4437 */
} /* line 4437 */
  sim_icache_fetch(2994 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4439 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4440 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4441 */
l_L182X3: ;/* line 4444 */
__LABEL(l_L182X3);
  sim_icache_fetch(2997 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4445 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4446 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4447 */
   __ADD_CYCLES(1);
} /* line 4447 */
  sim_icache_fetch(3002 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4449 */
} /* line 4449 */
  sim_icache_fetch(3003 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4451 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4452 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4453 */
l_L181X3: ;/* line 4456 */
__LABEL(l_L181X3);
  sim_icache_fetch(3006 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4457 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4458 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4459 */
   __ADD_CYCLES(1);
} /* line 4459 */
  sim_icache_fetch(3011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4461 */
} /* line 4461 */
  sim_icache_fetch(3012 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4463 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4464 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4465 */
l_L180X3: ;/* line 4468 */
__LABEL(l_L180X3);
  sim_icache_fetch(3015 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4469 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4470 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4471 */
   __ADD_CYCLES(1);
} /* line 4471 */
  sim_icache_fetch(3020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4473 */
} /* line 4473 */
  sim_icache_fetch(3021 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4475 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4476 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4477 */
l_L179X3: ;/* line 4480 */
__LABEL(l_L179X3);
  sim_icache_fetch(3024 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4481 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4482 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4483 */
   __ADD_CYCLES(1);
} /* line 4483 */
  sim_icache_fetch(3029 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4485 */
} /* line 4485 */
  sim_icache_fetch(3030 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4487 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4488 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4489 */
l_L178X3: ;/* line 4492 */
__LABEL(l_L178X3);
  sim_icache_fetch(3033 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4493 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4494 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4495 */
   __ADD_CYCLES(1);
} /* line 4495 */
  sim_icache_fetch(3038 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4497 */
} /* line 4497 */
  sim_icache_fetch(3039 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4499 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4500 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4501 */
l_L177X3: ;/* line 4504 */
__LABEL(l_L177X3);
  sim_icache_fetch(3042 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4505 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_9256Xoffset,0,4)); /* line 4506 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4507 */
   __ADD_CYCLES(1);
} /* line 4507 */
  sim_icache_fetch(3047 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4509 */
} /* line 4509 */
  sim_icache_fetch(3048 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4511 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4512 */
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4513 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 326: goto l_L163X3;
    case 327: goto l_L164X3;
    case 328: goto l_L166X3;
    case 329: goto l_L167X3;
    case 330: goto l_L165X3;
    case 331: goto l_L170X3;
    case 332: goto l_L171X3;
    case 333: goto l_L169X3;
    case 334: goto l_L172X3;
    case 335: goto l_L173X3;
    case 336: goto l_L168X3;
    case 337: goto l_L162X3;
    case 338: goto l_L161X3;
    case 339: goto l_L175X3;
    case 340: goto l_L174X3;
    case 341: goto l_L176X3;
    case 342: goto l_L192X3;
    case 343: goto l_L191X3;
    case 344: goto l_L190X3;
    case 345: goto l_L189X3;
    case 346: goto l_L188X3;
    case 347: goto l_L187X3;
    case 348: goto l_L186X3;
    case 349: goto l_L185X3;
    case 350: goto l_L184X3;
    case 351: goto l_L183X3;
    case 352: goto l_L182X3;
    case 353: goto l_L181X3;
    case 354: goto l_L180X3;
    case 355: goto l_L179X3;
    case 356: goto l_L178X3;
    case 357: goto l_L177X3;
    case 358:
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
  reg_l0_0 = (412 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3051 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4529 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4530 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4531 */
} /* line 4531 */
  sim_icache_fetch(3055 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4533 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4534 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4535 */
} /* line 4535 */
  sim_icache_fetch(3058 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4537 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4538 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4539 */
} /* line 4539 */
  sim_icache_fetch(3061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4541 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4542 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4543 */
} /* line 4543 */
  sim_icache_fetch(3064 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4545 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4546 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4547 */
} /* line 4547 */
  sim_icache_fetch(3067 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4549 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4550 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4551 */
} /* line 4551 */
  sim_icache_fetch(3070 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4553 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4554 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4555 */
} /* line 4555 */
  sim_icache_fetch(3075 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4557 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4558 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4559 */
} /* line 4559 */
  sim_icache_fetch(3079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4561 */
} /* line 4561 */
l_L193X3: ;/* line 4564 */
__LABEL(l_L193X3);
  sim_icache_fetch(3081 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4565 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4566 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4567 */
} /* line 4567 */
  sim_icache_fetch(3084 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4569 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4570 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L194X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4571 */
  sim_icache_fetch(3087 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4573 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4574 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4575 */
} /* line 4575 */
  sim_icache_fetch(3090 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4577 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4578 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4579 */
} /* line 4579 */
  sim_icache_fetch(3093 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4581 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4582 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4583 */
} /* line 4583 */
  sim_icache_fetch(3096 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4585 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4586 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4587 */
} /* line 4587 */
  sim_icache_fetch(3099 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4589 */
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4590 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4591 */
} /* line 4591 */
  sim_icache_fetch(3102 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4593 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4594 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4595 */
} /* line 4595 */
  sim_icache_fetch(3105 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4597 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4598 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4599 */
} /* line 4599 */
  sim_icache_fetch(3108 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4601 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4602 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4603 */
} /* line 4603 */
  sim_icache_fetch(3111 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4605 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4606 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4607 */
} /* line 4607 */
  sim_icache_fetch(3114 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4609 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4610 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4611 */
} /* line 4611 */
  sim_icache_fetch(3117 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4613 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4614 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4615 */
} /* line 4615 */
  sim_icache_fetch(3120 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4617 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4618 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4619 */
} /* line 4619 */
  sim_icache_fetch(3123 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4621 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4622 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4623 */
} /* line 4623 */
  sim_icache_fetch(3126 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4625 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4626 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4627 */
} /* line 4627 */
  sim_icache_fetch(3129 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4629 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4630 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4631 */
} /* line 4631 */
  sim_icache_fetch(3132 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4633 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4634 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4635 */
} /* line 4635 */
  sim_icache_fetch(3135 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4637 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4638 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4639 */
} /* line 4639 */
  sim_icache_fetch(3138 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4641 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4642 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4643 */
} /* line 4643 */
  sim_icache_fetch(3141 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4645 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4646 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4647 */
} /* line 4647 */
  sim_icache_fetch(3144 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4649 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4650 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4651 */
} /* line 4651 */
  sim_icache_fetch(3147 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4653 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4654 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4655 */
} /* line 4655 */
  sim_icache_fetch(3150 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4657 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4658 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4659 */
} /* line 4659 */
  sim_icache_fetch(3153 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4661 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4662 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4663 */
} /* line 4663 */
  sim_icache_fetch(3156 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4665 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4666 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4667 */
} /* line 4667 */
  sim_icache_fetch(3159 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4669 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4670 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4671 */
} /* line 4671 */
  sim_icache_fetch(3162 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4673 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4674 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4675 */
} /* line 4675 */
  sim_icache_fetch(3165 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4677 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4678 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4679 */
} /* line 4679 */
  sim_icache_fetch(3168 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4681 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4682 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4683 */
} /* line 4683 */
  sim_icache_fetch(3171 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4685 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4686 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4687 */
} /* line 4687 */
  sim_icache_fetch(3174 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4689 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4690 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4691 */
} /* line 4691 */
  sim_icache_fetch(3177 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4693 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4694 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4695 */
} /* line 4695 */
  sim_icache_fetch(3180 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4697 */
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4698 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4700 */
} /* line 4700 */
  sim_icache_fetch(3183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L193X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L193X3;
} /* line 4702 */
l_L194X3: ;/* line 4705 */
__LABEL(l_L194X3);
  sim_icache_fetch(3184 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4706 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4707 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4708 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4709 */
   __ADD_CYCLES(1);
} /* line 4709 */
  sim_icache_fetch(3190 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4711 */
} /* line 4711 */
  sim_icache_fetch(3191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4713 */
} /* line 4713 */
		 /* line 4714 */
  sim_icache_fetch(3193 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4716 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (412 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4717 */
l_lr_261: ;/* line 4717 */
__LABEL(l_lr_261);
  sim_icache_fetch(3197 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_3); /* line 4719 */
   __MOV(reg_r0_4, reg_r0_3); /* line 4720 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4721 */
} /* line 4721 */
  sim_icache_fetch(3200 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4723 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L195X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4724 */
  sim_icache_fetch(3202 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 4726 */
} /* line 4726 */
  sim_icache_fetch(3203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4729 */
l_L195X3: ;/* line 4732 */
__LABEL(l_L195X3);
  sim_icache_fetch(3204 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4733 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4734 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4735 */
} /* line 4735 */
  sim_icache_fetch(3207 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4737 */
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4738 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4739 */
} /* line 4739 */
  sim_icache_fetch(3212 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_59, reg_r0_2); /* line 4741 */
} /* line 4741 */
  sim_icache_fetch(3213 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 1); /* line 4743 */
} /* line 4743 */
  sim_icache_fetch(3214 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4745 */
} /* line 4745 */
  sim_icache_fetch(3216 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4747 */
} /* line 4747 */
l_L196X3: ;/* line 4750 */
__LABEL(l_L196X3);
		 /* line 4750 */
  sim_icache_fetch(3217 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (412 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4752 */
l_lr_265: ;/* line 4752 */
__LABEL(l_lr_265);
  sim_icache_fetch(3219 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, reg_r0_3); /* line 4754 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4755 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4756 */
} /* line 4756 */
  sim_icache_fetch(3223 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4758 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4759 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L197X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4760 */
  sim_icache_fetch(3227 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4762 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4763 */
} /* line 4763 */
  sim_icache_fetch(3230 + t_thisfile.offset, 1);
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
} /* line 4765 */
l_L199X3: ;/* line 4768 */
__LABEL(l_L199X3);
  sim_icache_fetch(3231 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4769 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4770 */
} /* line 4770 */
  sim_icache_fetch(3233 + t_thisfile.offset, 1);
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
} /* line 4772 */
  sim_icache_fetch(3234 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4774 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4775 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4776 */
} /* line 4776 */
  sim_icache_fetch(3237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4778 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4779 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4780 */
} /* line 4780 */
  sim_icache_fetch(3240 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4782 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4783 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4784 */
} /* line 4784 */
  sim_icache_fetch(3243 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4786 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4787 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4788 */
} /* line 4788 */
  sim_icache_fetch(3246 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4790 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4791 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4792 */
} /* line 4792 */
  sim_icache_fetch(3249 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4794 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4795 */
   __GOTO(l_L199X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L199X3;
} /* line 4796 */
l_L200X3: ;/* line 4799 */
__LABEL(l_L200X3);
  sim_icache_fetch(3252 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4800 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4801 */
} /* line 4801 */
		 /* line 4802 */
  sim_icache_fetch(3255 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4804 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4805 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (412 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4806 */
l_lr_269: ;/* line 4806 */
__LABEL(l_lr_269);
  sim_icache_fetch(3261 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4808 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4809 */
} /* line 4809 */
  sim_icache_fetch(3263 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L197X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4811 */
l_L198X3: ;/* line 4814 */
__LABEL(l_L198X3);
  sim_icache_fetch(3264 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4815 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4816 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4817 */
   __ADD_CYCLES(1);
} /* line 4817 */
  sim_icache_fetch(3268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4819 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4820 */
} /* line 4820 */
  sim_icache_fetch(3270 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4822 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4823 */
  sim_icache_fetch(3273 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4825 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4826 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4827 */
} /* line 4827 */
l_L202X3: ;/* line 4830 */
__LABEL(l_L202X3);
  sim_icache_fetch(3276 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4831 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4832 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4833 */
} /* line 4833 */
  sim_icache_fetch(3281 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4835 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L203X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4836 */
  sim_icache_fetch(3283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4838 */
} /* line 4838 */
  sim_icache_fetch(3284 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4840 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4841 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4842 */
} /* line 4842 */
  sim_icache_fetch(3289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4844 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4845 */
  sim_icache_fetch(3291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4847 */
} /* line 4847 */
  sim_icache_fetch(3292 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4849 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4850 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4851 */
} /* line 4851 */
  sim_icache_fetch(3297 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4853 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L205X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4854 */
  sim_icache_fetch(3299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4856 */
} /* line 4856 */
  sim_icache_fetch(3300 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4858 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4859 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4860 */
} /* line 4860 */
  sim_icache_fetch(3305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4862 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4863 */
  sim_icache_fetch(3307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4865 */
} /* line 4865 */
  sim_icache_fetch(3308 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4867 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4868 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4869 */
} /* line 4869 */
  sim_icache_fetch(3313 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4871 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4872 */
  sim_icache_fetch(3315 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4874 */
} /* line 4874 */
  sim_icache_fetch(3316 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4876 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4877 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4878 */
} /* line 4878 */
  sim_icache_fetch(3321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4880 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4881 */
  sim_icache_fetch(3323 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4883 */
} /* line 4883 */
  sim_icache_fetch(3324 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4885 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4886 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4887 */
} /* line 4887 */
  sim_icache_fetch(3329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4889 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4890 */
  sim_icache_fetch(3331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4892 */
} /* line 4892 */
  sim_icache_fetch(3332 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4894 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4895 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4896 */
} /* line 4896 */
  sim_icache_fetch(3337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4898 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4899 */
  sim_icache_fetch(3339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4901 */
} /* line 4901 */
  sim_icache_fetch(3340 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4903 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4904 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4905 */
} /* line 4905 */
  sim_icache_fetch(3345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4907 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4908 */
  sim_icache_fetch(3347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4910 */
} /* line 4910 */
  sim_icache_fetch(3348 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4912 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4913 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4914 */
} /* line 4914 */
  sim_icache_fetch(3353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4916 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4917 */
  sim_icache_fetch(3355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4919 */
} /* line 4919 */
  sim_icache_fetch(3356 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4921 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4922 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4923 */
} /* line 4923 */
  sim_icache_fetch(3361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4925 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4926 */
  sim_icache_fetch(3363 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4928 */
} /* line 4928 */
  sim_icache_fetch(3364 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4930 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4931 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4932 */
} /* line 4932 */
  sim_icache_fetch(3369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4934 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4935 */
  sim_icache_fetch(3371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4937 */
} /* line 4937 */
  sim_icache_fetch(3372 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4939 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4940 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4941 */
} /* line 4941 */
  sim_icache_fetch(3377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4943 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4944 */
  sim_icache_fetch(3379 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4946 */
} /* line 4946 */
  sim_icache_fetch(3380 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4948 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4949 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4950 */
} /* line 4950 */
  sim_icache_fetch(3385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4952 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4953 */
  sim_icache_fetch(3387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4955 */
} /* line 4955 */
  sim_icache_fetch(3388 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4957 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4958 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4959 */
} /* line 4959 */
  sim_icache_fetch(3393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4961 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4962 */
  sim_icache_fetch(3395 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4964 */
} /* line 4964 */
  sim_icache_fetch(3396 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4966 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4967 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4968 */
} /* line 4968 */
  sim_icache_fetch(3401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4970 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4971 */
  sim_icache_fetch(3403 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4973 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4974 */
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 4975 */
l_L218X3: ;/* line 4978 */
__LABEL(l_L218X3);
  sim_icache_fetch(3406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4979 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4980 */
} /* line 4980 */
  sim_icache_fetch(3408 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4982 */
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 4983 */
l_L220X3: ;/* line 4986 */
__LABEL(l_L220X3);
  sim_icache_fetch(3410 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, reg_r0_3); /* line 4987 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4988 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4989 */
} /* line 4989 */
  sim_icache_fetch(3414 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4991 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4992 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4993 */
} /* line 4993 */
  sim_icache_fetch(3420 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 4995 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4996 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4997 */
} /* line 4997 */
  sim_icache_fetch(3425 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4999 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 5000 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 5001 */
} /* line 5001 */
  sim_icache_fetch(3431 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 5003 */
   __ADD(reg_r0_23, reg_r0_19, (unsigned int) -16); /* line 5004 */
   __ADD(reg_r0_24, reg_r0_18, (unsigned int) -16); /* line 5005 */
} /* line 5005 */
  sim_icache_fetch(3434 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_25, reg_r0_17, (unsigned int) -16); /* line 5007 */
   __ADD(reg_r0_26, reg_r0_16, (unsigned int) -16); /* line 5008 */
   __ADD(reg_r0_27, reg_r0_15, (unsigned int) -16); /* line 5009 */
} /* line 5009 */
  sim_icache_fetch(3437 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_28, reg_r0_14, (unsigned int) -16); /* line 5011 */
   __ADD(reg_r0_29, reg_r0_13, (unsigned int) -16); /* line 5012 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 5013 */
} /* line 5013 */
  sim_icache_fetch(3440 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_31, reg_r0_11, (unsigned int) -16); /* line 5015 */
   __ADD(reg_r0_32, reg_r0_10, (unsigned int) -16); /* line 5016 */
   __ADD(reg_r0_33, reg_r0_9, (unsigned int) -16); /* line 5017 */
} /* line 5017 */
  sim_icache_fetch(3443 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_34, reg_r0_8, (unsigned int) -16); /* line 5019 */
   __ADD(reg_r0_35, reg_r0_7, (unsigned int) -16); /* line 5020 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) -16); /* line 5021 */
} /* line 5021 */
  sim_icache_fetch(3446 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_38, reg_r0_20); /* line 5023 */
   __ADD(reg_r0_37, reg_r0_20, (unsigned int) -16); /* line 5024 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 5025 */
} /* line 5025 */
  sim_icache_fetch(3449 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5027 */
   __MOV(reg_r0_40, reg_r0_37); /* line 5028 */
} /* line 5028 */
  sim_icache_fetch(3452 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5030 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5031 */
  sim_icache_fetch(3454 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5033 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5034 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 5035 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5036 */
   __ADD_CYCLES(1);
} /* line 5036 */
  sim_icache_fetch(3460 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5038 */
} /* line 5038 */
  sim_icache_fetch(3461 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5040 */
} /* line 5040 */
  sim_icache_fetch(3463 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 5042 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 5043 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5044 */
  sim_icache_fetch(3467 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 5046 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5047 */
   __MFB(reg_r0_4, reg_b0_1); /* line 5048 */
} /* line 5048 */
  sim_icache_fetch(3471 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 5050 */
   __ADD(reg_r0_6, reg_r0_36, (unsigned int) -16); /* line 5051 */
} /* line 5051 */
  sim_icache_fetch(3474 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5053 */
} /* line 5053 */
  sim_icache_fetch(3475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5055 */
} /* line 5055 */
  sim_icache_fetch(3477 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 5057 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5058 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5059 */
  sim_icache_fetch(3480 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5061 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5062 */
   __MFB(reg_r0_4, reg_b0_2); /* line 5063 */
} /* line 5063 */
  sim_icache_fetch(3484 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 5065 */
   __ADD(reg_r0_7, reg_r0_35, (unsigned int) -16); /* line 5066 */
} /* line 5066 */
  sim_icache_fetch(3487 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5068 */
} /* line 5068 */
  sim_icache_fetch(3488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5070 */
} /* line 5070 */
  sim_icache_fetch(3490 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 5072 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5073 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5074 */
  sim_icache_fetch(3493 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 5076 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5077 */
   __MFB(reg_r0_4, reg_b0_3); /* line 5078 */
} /* line 5078 */
  sim_icache_fetch(3497 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 5080 */
   __ADD(reg_r0_8, reg_r0_34, (unsigned int) -16); /* line 5081 */
} /* line 5081 */
  sim_icache_fetch(3500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5083 */
} /* line 5083 */
  sim_icache_fetch(3501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5085 */
} /* line 5085 */
  sim_icache_fetch(3503 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 5087 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5088 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5089 */
  sim_icache_fetch(3506 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 5091 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5092 */
   __MFB(reg_r0_4, reg_b0_4); /* line 5093 */
} /* line 5093 */
  sim_icache_fetch(3510 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 5095 */
   __ADD(reg_r0_9, reg_r0_33, (unsigned int) -16); /* line 5096 */
} /* line 5096 */
  sim_icache_fetch(3513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5098 */
} /* line 5098 */
  sim_icache_fetch(3514 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5100 */
} /* line 5100 */
  sim_icache_fetch(3516 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 5102 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5103 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5104 */
  sim_icache_fetch(3519 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 5106 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5107 */
   __MFB(reg_r0_4, reg_b0_5); /* line 5108 */
} /* line 5108 */
  sim_icache_fetch(3523 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 5110 */
   __ADD(reg_r0_10, reg_r0_32, (unsigned int) -16); /* line 5111 */
} /* line 5111 */
  sim_icache_fetch(3526 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5113 */
} /* line 5113 */
  sim_icache_fetch(3527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5115 */
} /* line 5115 */
  sim_icache_fetch(3529 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 5117 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5118 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5119 */
  sim_icache_fetch(3532 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 5121 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5122 */
   __MFB(reg_r0_4, reg_b0_6); /* line 5123 */
} /* line 5123 */
  sim_icache_fetch(3536 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 5125 */
   __ADD(reg_r0_11, reg_r0_31, (unsigned int) -16); /* line 5126 */
} /* line 5126 */
  sim_icache_fetch(3539 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5128 */
} /* line 5128 */
  sim_icache_fetch(3540 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5130 */
} /* line 5130 */
  sim_icache_fetch(3542 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 5132 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5133 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5134 */
  sim_icache_fetch(3545 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5136 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5137 */
   __MFB(reg_r0_4, reg_b0_7); /* line 5138 */
} /* line 5138 */
  sim_icache_fetch(3549 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 5140 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 5141 */
} /* line 5141 */
  sim_icache_fetch(3552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5143 */
} /* line 5143 */
  sim_icache_fetch(3553 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5145 */
} /* line 5145 */
  sim_icache_fetch(3555 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5147 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5148 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5149 */
  sim_icache_fetch(3558 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5151 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5152 */
   __MFB(reg_r0_4, reg_b0_0); /* line 5153 */
} /* line 5153 */
  sim_icache_fetch(3562 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5155 */
   __ADD(reg_r0_13, reg_r0_29, (unsigned int) -16); /* line 5156 */
} /* line 5156 */
  sim_icache_fetch(3565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5158 */
} /* line 5158 */
  sim_icache_fetch(3566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5160 */
} /* line 5160 */
  sim_icache_fetch(3568 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5162 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5163 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5164 */
  sim_icache_fetch(3571 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5166 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5167 */
   __MFB(reg_r0_4, reg_b0_1); /* line 5168 */
} /* line 5168 */
  sim_icache_fetch(3575 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 5170 */
   __ADD(reg_r0_14, reg_r0_28, (unsigned int) -16); /* line 5171 */
} /* line 5171 */
  sim_icache_fetch(3578 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5173 */
} /* line 5173 */
  sim_icache_fetch(3579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5175 */
} /* line 5175 */
  sim_icache_fetch(3581 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5177 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5178 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5179 */
  sim_icache_fetch(3584 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5181 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5182 */
   __MFB(reg_r0_4, reg_b0_2); /* line 5183 */
} /* line 5183 */
  sim_icache_fetch(3588 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5185 */
   __ADD(reg_r0_15, reg_r0_27, (unsigned int) -16); /* line 5186 */
} /* line 5186 */
  sim_icache_fetch(3591 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5188 */
} /* line 5188 */
  sim_icache_fetch(3592 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5190 */
} /* line 5190 */
  sim_icache_fetch(3594 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5192 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5193 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5194 */
  sim_icache_fetch(3597 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5196 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5197 */
   __MFB(reg_r0_4, reg_b0_3); /* line 5198 */
} /* line 5198 */
  sim_icache_fetch(3601 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5200 */
   __ADD(reg_r0_16, reg_r0_26, (unsigned int) -16); /* line 5201 */
} /* line 5201 */
  sim_icache_fetch(3604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5203 */
} /* line 5203 */
  sim_icache_fetch(3605 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5205 */
} /* line 5205 */
  sim_icache_fetch(3607 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5207 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5208 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5209 */
  sim_icache_fetch(3610 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5211 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5212 */
   __MFB(reg_r0_4, reg_b0_4); /* line 5213 */
} /* line 5213 */
  sim_icache_fetch(3614 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5215 */
   __ADD(reg_r0_17, reg_r0_25, (unsigned int) -16); /* line 5216 */
} /* line 5216 */
  sim_icache_fetch(3617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5218 */
} /* line 5218 */
  sim_icache_fetch(3618 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5220 */
} /* line 5220 */
  sim_icache_fetch(3620 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5222 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5223 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5224 */
  sim_icache_fetch(3623 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5226 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5227 */
   __MFB(reg_r0_4, reg_b0_5); /* line 5228 */
} /* line 5228 */
  sim_icache_fetch(3627 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5230 */
   __ADD(reg_r0_18, reg_r0_24, (unsigned int) -16); /* line 5231 */
} /* line 5231 */
  sim_icache_fetch(3630 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5233 */
} /* line 5233 */
  sim_icache_fetch(3631 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5235 */
} /* line 5235 */
  sim_icache_fetch(3633 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5237 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5238 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5239 */
  sim_icache_fetch(3636 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5241 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5242 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5243 */
} /* line 5243 */
  sim_icache_fetch(3640 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5245 */
   __ADD(reg_r0_19, reg_r0_23, (unsigned int) -16); /* line 5246 */
   __MFB(reg_r0_4, t__i32_0); /* line 5247 */
} /* line 5247 */
  sim_icache_fetch(3644 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5249 */
} /* line 5249 */
  sim_icache_fetch(3645 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5251 */
} /* line 5251 */
  sim_icache_fetch(3647 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5253 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5254 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5255 */
  sim_icache_fetch(3650 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, reg_r0_3); /* line 5257 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5258 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5259 */
} /* line 5259 */
  sim_icache_fetch(3654 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLEU(reg_b0_7, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5261 */
   __ADD(reg_r0_20, reg_r0_37, (unsigned int) -16); /* line 5262 */
   __MFB(reg_r0_22, t__i32_0); /* line 5263 */
} /* line 5263 */
  sim_icache_fetch(3658 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5265 */
   __MOV(reg_r0_3, reg_r0_39); /* line 5266 */
} /* line 5266 */
  sim_icache_fetch(3660 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5268 */
} /* line 5268 */
  sim_icache_fetch(3662 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5270 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5271 */
  sim_icache_fetch(3664 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5273 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5274 */
   __CMPLEU(reg_b0_0, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5275 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5276 */
   __ADD_CYCLES(1);
} /* line 5276 */
  sim_icache_fetch(3670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5278 */
} /* line 5278 */
  sim_icache_fetch(3671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5280 */
} /* line 5280 */
  sim_icache_fetch(3673 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5282 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5283 */
  sim_icache_fetch(3675 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5285 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5286 */
   __CMPLEU(reg_b0_1, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5287 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5288 */
   __ADD_CYCLES(1);
} /* line 5288 */
  sim_icache_fetch(3681 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5290 */
} /* line 5290 */
  sim_icache_fetch(3682 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5292 */
} /* line 5292 */
  sim_icache_fetch(3684 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5294 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5295 */
  sim_icache_fetch(3686 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5297 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5298 */
   __CMPLEU(reg_b0_2, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5299 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5300 */
   __ADD_CYCLES(1);
} /* line 5300 */
  sim_icache_fetch(3692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5302 */
} /* line 5302 */
  sim_icache_fetch(3693 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5304 */
} /* line 5304 */
  sim_icache_fetch(3695 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5306 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5307 */
  sim_icache_fetch(3697 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5309 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5310 */
   __CMPLEU(reg_b0_3, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5311 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5312 */
   __ADD_CYCLES(1);
} /* line 5312 */
  sim_icache_fetch(3703 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5314 */
} /* line 5314 */
  sim_icache_fetch(3704 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5316 */
} /* line 5316 */
  sim_icache_fetch(3706 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5318 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5319 */
  sim_icache_fetch(3708 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5321 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5322 */
   __CMPLEU(reg_b0_4, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5323 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5324 */
   __ADD_CYCLES(1);
} /* line 5324 */
  sim_icache_fetch(3714 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5326 */
} /* line 5326 */
  sim_icache_fetch(3715 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5328 */
} /* line 5328 */
  sim_icache_fetch(3717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5330 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5331 */
  sim_icache_fetch(3719 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5333 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5334 */
   __CMPLEU(reg_b0_5, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5335 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5336 */
   __ADD_CYCLES(1);
} /* line 5336 */
  sim_icache_fetch(3725 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5338 */
} /* line 5338 */
  sim_icache_fetch(3726 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5340 */
} /* line 5340 */
  sim_icache_fetch(3728 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5342 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5343 */
  sim_icache_fetch(3730 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5345 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5346 */
   __CMPLEU(reg_b0_6, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5347 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5348 */
   __ADD_CYCLES(1);
} /* line 5348 */
  sim_icache_fetch(3736 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5350 */
} /* line 5350 */
  sim_icache_fetch(3737 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5352 */
} /* line 5352 */
  sim_icache_fetch(3739 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5354 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5355 */
  sim_icache_fetch(3741 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5357 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5358 */
   __MTB(reg_b0_7, reg_r0_22); /* line 5359 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5360 */
   __ADD_CYCLES(1);
} /* line 5360 */
  sim_icache_fetch(3746 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5362 */
} /* line 5362 */
  sim_icache_fetch(3747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5364 */
} /* line 5364 */
  sim_icache_fetch(3749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5366 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5367 */
  sim_icache_fetch(3751 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5369 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5370 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5371 */
   __ADD_CYCLES(1);
} /* line 5371 */
  sim_icache_fetch(3755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5373 */
} /* line 5373 */
  sim_icache_fetch(3756 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5375 */
} /* line 5375 */
  sim_icache_fetch(3758 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5377 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5378 */
  sim_icache_fetch(3760 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5380 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5381 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5382 */
   __ADD_CYCLES(1);
} /* line 5382 */
  sim_icache_fetch(3764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5384 */
} /* line 5384 */
  sim_icache_fetch(3765 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5386 */
} /* line 5386 */
  sim_icache_fetch(3767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5388 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5389 */
  sim_icache_fetch(3769 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5391 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5392 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5393 */
   __ADD_CYCLES(1);
} /* line 5393 */
  sim_icache_fetch(3773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5395 */
} /* line 5395 */
  sim_icache_fetch(3774 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5397 */
} /* line 5397 */
  sim_icache_fetch(3776 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5399 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5400 */
  sim_icache_fetch(3778 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5402 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5403 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5404 */
   __ADD_CYCLES(1);
} /* line 5404 */
  sim_icache_fetch(3782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5406 */
} /* line 5406 */
  sim_icache_fetch(3783 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5408 */
} /* line 5408 */
  sim_icache_fetch(3785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5410 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5411 */
  sim_icache_fetch(3787 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5413 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5414 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5415 */
   __ADD_CYCLES(1);
} /* line 5415 */
  sim_icache_fetch(3791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5417 */
} /* line 5417 */
  sim_icache_fetch(3792 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5419 */
} /* line 5419 */
  sim_icache_fetch(3794 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5421 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5422 */
  sim_icache_fetch(3796 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5424 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5425 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5426 */
   __ADD_CYCLES(1);
} /* line 5426 */
  sim_icache_fetch(3800 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5428 */
} /* line 5428 */
  sim_icache_fetch(3801 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5430 */
} /* line 5430 */
  sim_icache_fetch(3803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5432 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5433 */
  sim_icache_fetch(3805 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5435 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5436 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5437 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5438 */
   __ADD_CYCLES(1);
} /* line 5438 */
  sim_icache_fetch(3810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5440 */
} /* line 5440 */
  sim_icache_fetch(3811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5442 */
} /* line 5442 */
  sim_icache_fetch(3813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5444 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5446 */
  sim_icache_fetch(3815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5448 */
l_L236X3: ;/* line 5451 */
__LABEL(l_L236X3);
  sim_icache_fetch(3816 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5452 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5453 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5455 */
} /* line 5455 */
  sim_icache_fetch(3821 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5457 */
l_L239X3: ;/* line 5460 */
__LABEL(l_L239X3);
  sim_icache_fetch(3822 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5461 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5462 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5463 */
} /* line 5463 */
  sim_icache_fetch(3827 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5465 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5466 */
   __GOTO(l_L238X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L238X3;
} /* line 5467 */
l_L235X3: ;/* line 5470 */
__LABEL(l_L235X3);
  sim_icache_fetch(3831 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5471 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5472 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5474 */
} /* line 5474 */
  sim_icache_fetch(3836 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5476 */
l_L234X3: ;/* line 5479 */
__LABEL(l_L234X3);
  sim_icache_fetch(3837 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5480 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5481 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5483 */
} /* line 5483 */
  sim_icache_fetch(3842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5485 */
l_L233X3: ;/* line 5488 */
__LABEL(l_L233X3);
  sim_icache_fetch(3843 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5489 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5490 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5492 */
} /* line 5492 */
  sim_icache_fetch(3848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5494 */
l_L232X3: ;/* line 5497 */
__LABEL(l_L232X3);
  sim_icache_fetch(3849 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5498 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5499 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5501 */
} /* line 5501 */
  sim_icache_fetch(3854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5503 */
l_L231X3: ;/* line 5506 */
__LABEL(l_L231X3);
  sim_icache_fetch(3855 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5507 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5508 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5510 */
} /* line 5510 */
  sim_icache_fetch(3860 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5512 */
l_L230X3: ;/* line 5515 */
__LABEL(l_L230X3);
  sim_icache_fetch(3861 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5516 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5517 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5519 */
} /* line 5519 */
  sim_icache_fetch(3866 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5521 */
l_L229X3: ;/* line 5524 */
__LABEL(l_L229X3);
  sim_icache_fetch(3867 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5525 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5526 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5528 */
} /* line 5528 */
  sim_icache_fetch(3872 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5530 */
l_L228X3: ;/* line 5533 */
__LABEL(l_L228X3);
  sim_icache_fetch(3873 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5534 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5535 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5537 */
} /* line 5537 */
  sim_icache_fetch(3878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5539 */
l_L227X3: ;/* line 5542 */
__LABEL(l_L227X3);
  sim_icache_fetch(3879 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5543 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5544 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5546 */
} /* line 5546 */
  sim_icache_fetch(3884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5548 */
l_L226X3: ;/* line 5551 */
__LABEL(l_L226X3);
  sim_icache_fetch(3885 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5552 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5553 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5555 */
} /* line 5555 */
  sim_icache_fetch(3890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5557 */
l_L225X3: ;/* line 5560 */
__LABEL(l_L225X3);
  sim_icache_fetch(3891 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5561 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5562 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5564 */
} /* line 5564 */
  sim_icache_fetch(3896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5566 */
l_L224X3: ;/* line 5569 */
__LABEL(l_L224X3);
  sim_icache_fetch(3897 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5570 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5571 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5573 */
} /* line 5573 */
  sim_icache_fetch(3902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5575 */
l_L223X3: ;/* line 5578 */
__LABEL(l_L223X3);
  sim_icache_fetch(3903 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5579 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5580 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5582 */
} /* line 5582 */
  sim_icache_fetch(3908 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5584 */
l_L222X3: ;/* line 5587 */
__LABEL(l_L222X3);
  sim_icache_fetch(3909 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5588 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5589 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5591 */
} /* line 5591 */
  sim_icache_fetch(3914 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L237X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L237X3;
} /* line 5593 */
l_L221X3: ;/* line 5596 */
__LABEL(l_L221X3);
  sim_icache_fetch(3915 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5597 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5598 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5599 */
} /* line 5599 */
l_L237X3: ;/* line 5601 */
__LABEL(l_L237X3);
  sim_icache_fetch(3920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5601 */
  sim_icache_fetch(3921 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5603 */
} /* line 5603 */
  sim_icache_fetch(3922 + t_thisfile.offset, 1);
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
} /* line 5605 */
l_L238X3: ;/* line 5607 */
__LABEL(l_L238X3);
  sim_icache_fetch(3923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5608 */
   __GOTO(l_L196X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L196X3;
} /* line 5609 */
l_L217X3: ;/* line 5612 */
__LABEL(l_L217X3);
  sim_icache_fetch(3925 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5613 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5614 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5616 */
} /* line 5616 */
  sim_icache_fetch(3928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5618 */
l_L216X3: ;/* line 5621 */
__LABEL(l_L216X3);
  sim_icache_fetch(3929 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5622 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5623 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5625 */
} /* line 5625 */
  sim_icache_fetch(3932 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5627 */
l_L215X3: ;/* line 5630 */
__LABEL(l_L215X3);
  sim_icache_fetch(3933 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5631 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5632 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5634 */
} /* line 5634 */
  sim_icache_fetch(3936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5636 */
l_L214X3: ;/* line 5639 */
__LABEL(l_L214X3);
  sim_icache_fetch(3937 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5640 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5641 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5643 */
} /* line 5643 */
  sim_icache_fetch(3940 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5645 */
l_L213X3: ;/* line 5648 */
__LABEL(l_L213X3);
  sim_icache_fetch(3941 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5649 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5650 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5652 */
} /* line 5652 */
  sim_icache_fetch(3944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5654 */
l_L212X3: ;/* line 5657 */
__LABEL(l_L212X3);
  sim_icache_fetch(3945 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5658 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5659 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5661 */
} /* line 5661 */
  sim_icache_fetch(3948 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5663 */
l_L211X3: ;/* line 5666 */
__LABEL(l_L211X3);
  sim_icache_fetch(3949 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5667 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5668 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5670 */
} /* line 5670 */
  sim_icache_fetch(3952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5672 */
l_L210X3: ;/* line 5675 */
__LABEL(l_L210X3);
  sim_icache_fetch(3953 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5676 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5677 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5679 */
} /* line 5679 */
  sim_icache_fetch(3956 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5681 */
l_L209X3: ;/* line 5684 */
__LABEL(l_L209X3);
  sim_icache_fetch(3957 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5685 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5686 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5688 */
} /* line 5688 */
  sim_icache_fetch(3960 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5690 */
l_L208X3: ;/* line 5693 */
__LABEL(l_L208X3);
  sim_icache_fetch(3961 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5694 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5695 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5697 */
} /* line 5697 */
  sim_icache_fetch(3964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5699 */
l_L207X3: ;/* line 5702 */
__LABEL(l_L207X3);
  sim_icache_fetch(3965 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5703 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5704 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5706 */
} /* line 5706 */
  sim_icache_fetch(3968 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5708 */
l_L206X3: ;/* line 5711 */
__LABEL(l_L206X3);
  sim_icache_fetch(3969 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5712 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5713 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5715 */
} /* line 5715 */
  sim_icache_fetch(3972 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5717 */
l_L205X3: ;/* line 5720 */
__LABEL(l_L205X3);
  sim_icache_fetch(3973 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5721 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5722 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5724 */
} /* line 5724 */
  sim_icache_fetch(3976 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5726 */
l_L204X3: ;/* line 5729 */
__LABEL(l_L204X3);
  sim_icache_fetch(3977 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5730 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5731 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5733 */
} /* line 5733 */
  sim_icache_fetch(3980 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L219X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L219X3;
} /* line 5735 */
l_L203X3: ;/* line 5740 */
__LABEL(l_L203X3);
  sim_icache_fetch(3981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5741 */
} /* line 5741 */
l_L219X3: ;/* line 5743 */
__LABEL(l_L219X3);
  sim_icache_fetch(3982 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5744 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5745 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5746 */
} /* line 5746 */
  sim_icache_fetch(3986 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5748 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5749 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5750 */
} /* line 5750 */
  sim_icache_fetch(3989 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5752 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5753 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5754 */
} /* line 5754 */
  sim_icache_fetch(3992 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5756 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5757 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5758 */
} /* line 5758 */
  sim_icache_fetch(3995 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5760 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5761 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5762 */
} /* line 5762 */
  sim_icache_fetch(3998 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_5); /* line 5764 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5765 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5766 */
} /* line 5766 */
  sim_icache_fetch(4001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5768 */
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5769 */
l_L201X3: ;/* line 5772 */
__LABEL(l_L201X3);
  sim_icache_fetch(4003 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5773 */
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5774 */
l_L197X3: ;/* line 5777 */
__LABEL(l_L197X3);
  sim_icache_fetch(4005 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 5778 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5779 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5780 */
} /* line 5780 */
  sim_icache_fetch(4008 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5782 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5783 */
} /* line 5783 */
  sim_icache_fetch(4010 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5786 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 359: goto l_L193X3;
    case 360: goto l_L194X3;
    case 362: goto l_lr_261;
    case 363: goto l_L195X3;
    case 364: goto l_L196X3;
    case 366: goto l_lr_265;
    case 367: goto l_L199X3;
    case 368: goto l_L200X3;
    case 370: goto l_lr_269;
    case 371: goto l_L198X3;
    case 372: goto l_L202X3;
    case 373: goto l_L218X3;
    case 374: goto l_L220X3;
    case 375: goto l_L236X3;
    case 376: goto l_L239X3;
    case 377: goto l_L235X3;
    case 378: goto l_L234X3;
    case 379: goto l_L233X3;
    case 380: goto l_L232X3;
    case 381: goto l_L231X3;
    case 382: goto l_L230X3;
    case 383: goto l_L229X3;
    case 384: goto l_L228X3;
    case 385: goto l_L227X3;
    case 386: goto l_L226X3;
    case 387: goto l_L225X3;
    case 388: goto l_L224X3;
    case 389: goto l_L223X3;
    case 390: goto l_L222X3;
    case 391: goto l_L221X3;
    case 392: goto l_L237X3;
    case 393: goto l_L238X3;
    case 394: goto l_L217X3;
    case 395: goto l_L216X3;
    case 396: goto l_L215X3;
    case 397: goto l_L214X3;
    case 398: goto l_L213X3;
    case 399: goto l_L212X3;
    case 400: goto l_L211X3;
    case 401: goto l_L210X3;
    case 402: goto l_L209X3;
    case 403: goto l_L208X3;
    case 404: goto l_L207X3;
    case 405: goto l_L206X3;
    case 406: goto l_L205X3;
    case 407: goto l_L204X3;
    case 408: goto l_L203X3;
    case 409: goto l_L219X3;
    case 410: goto l_L201X3;
    case 411: goto l_L197X3;
    case 412:
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
  reg_l0_0 = (440 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4011 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5805 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5806 */
} /* line 5806 */
  sim_icache_fetch(4015 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5808 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5809 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5810 */
} /* line 5810 */
  sim_icache_fetch(4021 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5812 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5813 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5814 */
} /* line 5814 */
  sim_icache_fetch(4027 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5816 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5817 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5818 */
} /* line 5818 */
  sim_icache_fetch(4030 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_r0_5, reg_r0_7, reg_r0_8); /* line 5820 */
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5821 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5822 */
} /* line 5822 */
  sim_icache_fetch(4033 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_1, reg_r0_4, reg_r0_5); /* line 5824 */
   __CMPEQ(reg_b0_2, reg_r0_9, reg_r0_2); /* line 5825 */
} /* line 5825 */
  sim_icache_fetch(4035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5827 */
  sim_icache_fetch(4036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5829 */
  sim_icache_fetch(4037 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5831 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L242X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5832 */
  sim_icache_fetch(4040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5834 */
} /* line 5834 */
l_L241X3: ;/* line 5837 */
__LABEL(l_L241X3);
  sim_icache_fetch(4042 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5838 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5839 */
   __MOV(reg_r0_5, 0); /* line 5840 */
} /* line 5840 */
  sim_icache_fetch(4047 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, reg_r0_7); /* line 5842 */
} /* line 5842 */
  sim_icache_fetch(4048 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5844 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5845 */
   __MOV(reg_r0_17, reg_r0_4); /* line 5846 */
} /* line 5846 */
  sim_icache_fetch(4051 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5848 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L243X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5849 */
l_L244X3: ;/* line 5852 */
__LABEL(l_L244X3);
  sim_icache_fetch(4053 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5853 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5854 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5855 */
} /* line 5855 */
  sim_icache_fetch(4058 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5857 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5858 */
  sim_icache_fetch(4060 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5860 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5861 */
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5862 */
} /* line 5862 */
  sim_icache_fetch(4063 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5864 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5865 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 5866 */
} /* line 5866 */
  sim_icache_fetch(4067 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5868 */
   __CMPLT(reg_b0_1, reg_r0_8, 0); /* line 5869 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5870 */
  sim_icache_fetch(4071 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5872 */
   __ADD(reg_r0_9, reg_r0_8, (unsigned int) 1); /* line 5873 */
} /* line 5873 */
  sim_icache_fetch(4074 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5875 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5876 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5877 */
} /* line 5877 */
  sim_icache_fetch(4078 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5879 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5880 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5881 */
} /* line 5881 */
  sim_icache_fetch(4081 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5883 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 5884 */
   __CMPLT(reg_b0_4, reg_r0_10, 0); /* line 5885 */
} /* line 5885 */
l_L247X3: ;/* line 5887 */
__LABEL(l_L247X3);
  sim_icache_fetch(4084 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_12, reg_r0_4); /* line 5888 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5889 */
   __ADD(reg_r0_13, reg_r0_10, (unsigned int) 1); /* line 5890 */
} /* line 5890 */
  sim_icache_fetch(4088 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_5, reg_r0_12, (unsigned int) 255); /* line 5892 */
   __CMPLT(reg_b0_6, reg_r0_13, 0); /* line 5893 */
   __ADD(reg_r0_4, reg_r0_13, (unsigned int) 1); /* line 5894 */
} /* line 5894 */
  sim_icache_fetch(4091 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_5, reg_r0_4, 0); /* line 5896 */
   __ADD(reg_r0_12, reg_r0_4, (unsigned int) 1); /* line 5897 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5898 */
  sim_icache_fetch(4094 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5900 */
   __CMPLT(reg_b0_0, reg_r0_12, 0); /* line 5901 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5902 */
  sim_icache_fetch(4097 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5904 */
   __ADD(reg_r0_14, reg_r0_12, (unsigned int) 1); /* line 5905 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5906 */
  sim_icache_fetch(4101 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5908 */
   __CMPLT(reg_b0_2, reg_r0_14, 0); /* line 5909 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5910 */
} /* line 5910 */
  sim_icache_fetch(4105 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 5912 */
} /* line 5912 */
  sim_icache_fetch(4107 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 5914 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5915 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5916 */
} /* line 5916 */
  sim_icache_fetch(4111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_7, reg_r0_2, 0); /* line 5918 */
} /* line 5918 */
  sim_icache_fetch(4112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_7, reg_r0_7); /* line 5920 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 5921 */
} /* line 5921 */
l_L250X3: ;/* line 5923 */
__LABEL(l_L250X3);
  sim_icache_fetch(4114 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_7); /* line 5924 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_7); /* line 5925 */
} /* line 5925 */
  sim_icache_fetch(4117 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_7, reg_b0_2); /* line 5927 */
} /* line 5927 */
  sim_icache_fetch(4118 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_15, (unsigned int) 255); /* line 5929 */
} /* line 5929 */
  sim_icache_fetch(4119 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_2, reg_r0_7); /* line 5931 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5932 */
  sim_icache_fetch(4121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5934 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5935 */
  sim_icache_fetch(4123 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5937 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5938 */
  sim_icache_fetch(4126 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 5940 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5941 */
} /* line 5941 */
  sim_icache_fetch(4130 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5943 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5944 */
} /* line 5944 */
  sim_icache_fetch(4133 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5946 */
} /* line 5946 */
  sim_icache_fetch(4134 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5948 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5949 */
   __ADD(reg_r0_8, reg_r0_7, (unsigned int) 1); /* line 5950 */
} /* line 5950 */
l_L252X3: ;/* line 5952 */
__LABEL(l_L252X3);
  sim_icache_fetch(4137 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_11, reg_r0_6); /* line 5953 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5954 */
} /* line 5954 */
  sim_icache_fetch(4140 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_11, (unsigned int) 255); /* line 5956 */
} /* line 5956 */
  sim_icache_fetch(4141 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5958 */
  sim_icache_fetch(4142 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5960 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5961 */
  sim_icache_fetch(4144 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5963 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5964 */
  sim_icache_fetch(4147 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5966 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5967 */
} /* line 5967 */
  sim_icache_fetch(4151 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 5969 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5970 */
} /* line 5970 */
  sim_icache_fetch(4154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5972 */
} /* line 5972 */
  sim_icache_fetch(4155 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_7, reg_r0_7); /* line 5974 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5975 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 5976 */
} /* line 5976 */
l_L254X3: ;/* line 5978 */
__LABEL(l_L254X3);
  sim_icache_fetch(4158 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_9, reg_r0_7); /* line 5979 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_7); /* line 5980 */
} /* line 5980 */
  sim_icache_fetch(4161 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_9, (unsigned int) 255); /* line 5982 */
} /* line 5982 */
  sim_icache_fetch(4162 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5984 */
  sim_icache_fetch(4163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5986 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5987 */
  sim_icache_fetch(4165 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5989 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L255X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5990 */
  sim_icache_fetch(4168 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5992 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5993 */
} /* line 5993 */
  sim_icache_fetch(4172 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5995 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5996 */
} /* line 5996 */
  sim_icache_fetch(4175 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5998 */
} /* line 5998 */
  sim_icache_fetch(4176 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 6000 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6001 */
   __ADD(reg_r0_8, reg_r0_7, (unsigned int) 1); /* line 6002 */
} /* line 6002 */
l_L256X3: ;/* line 6004 */
__LABEL(l_L256X3);
  sim_icache_fetch(4179 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_9, reg_r0_6); /* line 6005 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 6006 */
} /* line 6006 */
  sim_icache_fetch(4182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_9, (unsigned int) 255); /* line 6008 */
} /* line 6008 */
  sim_icache_fetch(4183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6010 */
  sim_icache_fetch(4184 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 6012 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6013 */
  sim_icache_fetch(4186 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6015 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L257X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6016 */
  sim_icache_fetch(4189 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 6018 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6019 */
} /* line 6019 */
  sim_icache_fetch(4193 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 6021 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6022 */
} /* line 6022 */
  sim_icache_fetch(4196 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6024 */
} /* line 6024 */
  sim_icache_fetch(4197 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_7, reg_r0_7); /* line 6026 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6027 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 6028 */
} /* line 6028 */
l_L258X3: ;/* line 6030 */
__LABEL(l_L258X3);
  sim_icache_fetch(4200 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_9, reg_r0_7); /* line 6031 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_7); /* line 6032 */
} /* line 6032 */
  sim_icache_fetch(4203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_9, (unsigned int) 255); /* line 6034 */
} /* line 6034 */
  sim_icache_fetch(4204 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6036 */
  sim_icache_fetch(4205 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 6038 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6039 */
  sim_icache_fetch(4207 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6041 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L259X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6042 */
  sim_icache_fetch(4210 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 6044 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6045 */
} /* line 6045 */
  sim_icache_fetch(4214 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 6047 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6048 */
} /* line 6048 */
  sim_icache_fetch(4217 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6050 */
} /* line 6050 */
  sim_icache_fetch(4218 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 6052 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6053 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6054 */
} /* line 6054 */
l_L260X3: ;/* line 6056 */
__LABEL(l_L260X3);
  sim_icache_fetch(4221 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 6057 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 6058 */
} /* line 6058 */
  sim_icache_fetch(4224 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 6060 */
} /* line 6060 */
  sim_icache_fetch(4225 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6062 */
  sim_icache_fetch(4226 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 6064 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6065 */
  sim_icache_fetch(4228 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6067 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L261X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6068 */
  sim_icache_fetch(4231 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 6070 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6071 */
} /* line 6071 */
  sim_icache_fetch(4235 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 6073 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6074 */
} /* line 6074 */
  sim_icache_fetch(4238 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6076 */
} /* line 6076 */
  sim_icache_fetch(4239 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 6078 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6079 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6080 */
} /* line 6080 */
l_L262X3: ;/* line 6082 */
__LABEL(l_L262X3);
  sim_icache_fetch(4242 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 6083 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 6084 */
} /* line 6084 */
  sim_icache_fetch(4245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 255); /* line 6086 */
} /* line 6086 */
  sim_icache_fetch(4246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6088 */
  sim_icache_fetch(4247 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 6090 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6091 */
  sim_icache_fetch(4249 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6093 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L263X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6094 */
  sim_icache_fetch(4252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 6096 */
} /* line 6096 */
  sim_icache_fetch(4254 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 6098 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6099 */
   __ADD_CYCLES(1);
} /* line 6099 */
  sim_icache_fetch(4256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 6101 */
} /* line 6101 */
l_L264X3: ;/* line 6103 */
__LABEL(l_L264X3);
  sim_icache_fetch(4257 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_6); /* line 6104 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 6105 */
} /* line 6105 */
  sim_icache_fetch(4260 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 6107 */
} /* line 6107 */
  sim_icache_fetch(4261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6109 */
  sim_icache_fetch(4262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 6111 */
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 6112 */
l_L248X3: ;/* line 6115 */
__LABEL(l_L248X3);
  sim_icache_fetch(4264 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_17, reg_r0_5); /* line 6116 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6117 */
   __GOTO(l_L265X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L265X3;
} /* line 6118 */
l_L266X3: ;/* line 6121 */
__LABEL(l_L266X3);
  sim_icache_fetch(4267 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6122 */
   __MOV(reg_r0_7, 0); /* line 6123 */
   __SHL(reg_r0_17, reg_r0_17, (unsigned int) 3); /* line 6124 */
} /* line 6124 */
  sim_icache_fetch(4271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 1); /* line 6126 */
} /* line 6126 */
  sim_icache_fetch(4272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_17, reg_r0_2); /* line 6128 */
} /* line 6128 */
l_L240X3: ;/* line 6131 */
__LABEL(l_L240X3);
  sim_icache_fetch(4273 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6132 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 6133 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 6134 */
} /* line 6134 */
  sim_icache_fetch(4277 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 6136 */
   __ADD(reg_r0_9, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 6137 */
   __SUB(reg_r0_10, (unsigned int) 16, reg_r0_4); /* line 6138 */
} /* line 6138 */
  sim_icache_fetch(4282 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_11, reg_r0_2, reg_r0_4); /* line 6140 */
   __SUB(reg_r0_13, (unsigned int) 8, reg_r0_4); /* line 6141 */
   __ADD(reg_r0_12, reg_r0_6, (unsigned int) 2); /* line 6142 */
} /* line 6142 */
  sim_icache_fetch(4285 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_14, reg_r0_11, (unsigned int) -8); /* line 6144 */
   __ADD(reg_r0_15, reg_r0_11, (unsigned int) -16); /* line 6145 */
   __LDBUs(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 6146 */
} /* line 6146 */
  sim_icache_fetch(4288 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_7); /* line 6148 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 6149 */
   __CMPGE(reg_b0_0, reg_r0_14, (unsigned int) 8); /* line 6150 */
} /* line 6150 */
  sim_icache_fetch(4292 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_15, reg_b0_0, reg_r0_15, reg_r0_14); /* line 6152 */
   __SLCT(reg_r0_10, reg_b0_0, reg_r0_10, reg_r0_13); /* line 6153 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, reg_r0_9); /* line 6154 */
} /* line 6154 */
  sim_icache_fetch(4295 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHL(reg_r0_6, reg_r0_6, reg_r0_13); /* line 6156 */
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 6157 */
   __LDBU(reg_r0_15, mem_trace_ld((reg_r0_15 + (unsigned int) rmask),0,1)); /* line 6158 */
} /* line 6158 */
  sim_icache_fetch(4299 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_5, reg_r0_5, reg_r0_4); /* line 6160 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 6161 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_2); /* line 6162 */
} /* line 6162 */
  sim_icache_fetch(4304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_6, reg_r0_5, reg_r0_6); /* line 6164 */
   __AND(reg_r0_12, reg_r0_12, reg_r0_15); /* line 6165 */
} /* line 6165 */
  sim_icache_fetch(4306 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_6, reg_b0_0, reg_r0_6, reg_r0_5); /* line 6167 */
   __SHL(reg_r0_12, reg_r0_12, reg_r0_10); /* line 6168 */
} /* line 6168 */
  sim_icache_fetch(4308 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_6, reg_r0_12); /* line 6171 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6172 */
l_L263X3: ;/* line 6175 */
__LABEL(l_L263X3);
  sim_icache_fetch(4310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6176 */
   __GOTO(l_L264X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L264X3;
} /* line 6177 */
l_L245X3: ;/* line 6180 */
__LABEL(l_L245X3);
  sim_icache_fetch(4312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_17, reg_r0_17, 0); /* line 6181 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6182 */
} /* line 6182 */
l_L265X3: ;/* line 6184 */
__LABEL(l_L265X3);
  sim_icache_fetch(4314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_17, 0); /* line 6185 */
} /* line 6185 */
  sim_icache_fetch(4315 + t_thisfile.offset, 1);
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
} /* line 6187 */
  sim_icache_fetch(4316 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_17); /* line 6190 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_16); /* line 6191 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6192 */
l_L261X3: ;/* line 6195 */
__LABEL(l_L261X3);
  sim_icache_fetch(4321 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6196 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6197 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6198 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6199 */
   __ADD_CYCLES(1);
} /* line 6199 */
  sim_icache_fetch(4327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6201 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6202 */
} /* line 6202 */
  sim_icache_fetch(4329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6204 */
   __GOTO(l_L262X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L262X3;
} /* line 6205 */
l_L259X3: ;/* line 6208 */
__LABEL(l_L259X3);
  sim_icache_fetch(4331 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6209 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6210 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6211 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6212 */
   __ADD_CYCLES(1);
} /* line 6212 */
  sim_icache_fetch(4337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6214 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6215 */
} /* line 6215 */
  sim_icache_fetch(4339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6217 */
   __GOTO(l_L260X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L260X3;
} /* line 6218 */
l_L257X3: ;/* line 6221 */
__LABEL(l_L257X3);
  sim_icache_fetch(4341 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_7, (unsigned int) -1); /* line 6222 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6223 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6224 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6225 */
   __ADD_CYCLES(1);
} /* line 6225 */
  sim_icache_fetch(4347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_9, (unsigned int) -1); /* line 6227 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 6228 */
} /* line 6228 */
  sim_icache_fetch(4349 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6230 */
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6231 */
l_L255X3: ;/* line 6234 */
__LABEL(l_L255X3);
  sim_icache_fetch(4351 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6235 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6236 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6237 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6238 */
   __ADD_CYCLES(1);
} /* line 6238 */
  sim_icache_fetch(4357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_9, (unsigned int) -1); /* line 6240 */
   __ADD(reg_r0_8, reg_r0_7, (unsigned int) 1); /* line 6241 */
} /* line 6241 */
  sim_icache_fetch(4359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6243 */
   __GOTO(l_L256X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L256X3;
} /* line 6244 */
l_L253X3: ;/* line 6247 */
__LABEL(l_L253X3);
  sim_icache_fetch(4361 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_7, (unsigned int) -1); /* line 6248 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6249 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6250 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6251 */
   __ADD_CYCLES(1);
} /* line 6251 */
  sim_icache_fetch(4367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_9, (unsigned int) -1); /* line 6253 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 6254 */
} /* line 6254 */
  sim_icache_fetch(4369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6256 */
   __GOTO(l_L254X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L254X3;
} /* line 6257 */
l_L251X3: ;/* line 6260 */
__LABEL(l_L251X3);
  sim_icache_fetch(4371 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6261 */
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6262 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6263 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6264 */
   __ADD_CYCLES(1);
} /* line 6264 */
  sim_icache_fetch(4377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_11, (unsigned int) -1); /* line 6266 */
   __ADD(reg_r0_8, reg_r0_7, (unsigned int) 1); /* line 6267 */
} /* line 6267 */
  sim_icache_fetch(4379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6269 */
   __GOTO(l_L252X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L252X3;
} /* line 6270 */
l_L249X3: ;/* line 6273 */
__LABEL(l_L249X3);
  sim_icache_fetch(4381 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_7, (unsigned int) -1); /* line 6274 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6275 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6276 */
} /* line 6276 */
  sim_icache_fetch(4386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_2, reg_r0_14, 0); /* line 6278 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6279 */
} /* line 6279 */
  sim_icache_fetch(4388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6281 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 6282 */
} /* line 6282 */
  sim_icache_fetch(4390 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_7, reg_r0_2, 0); /* line 6284 */
   __GOTO(l_L250X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L250X3;
} /* line 6285 */
l_L246X3: ;/* line 6288 */
__LABEL(l_L246X3);
  sim_icache_fetch(4392 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6289 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6290 */
   __ADD(reg_r0_9, reg_r0_8, (unsigned int) 1); /* line 6291 */
} /* line 6291 */
  sim_icache_fetch(4396 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6293 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 6294 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 6295 */
} /* line 6295 */
  sim_icache_fetch(4399 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 6297 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 6298 */
   __CMPLT(reg_b0_4, reg_r0_10, 0); /* line 6300 */
} /* line 6300 */
  sim_icache_fetch(4402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L247X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L247X3;
} /* line 6302 */
l_L243X3: ;/* line 6305 */
__LABEL(l_L243X3);
  sim_icache_fetch(4403 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6306 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6307 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6308 */
} /* line 6308 */
  sim_icache_fetch(4408 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6310 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6311 */
} /* line 6311 */
  sim_icache_fetch(4412 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_17, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6313 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6314 */
   __ADD_CYCLES(1);
} /* line 6314 */
  sim_icache_fetch(4415 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_17); /* line 6316 */
} /* line 6316 */
  sim_icache_fetch(4416 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6318 */
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 6319 */
l_L242X3: ;/* line 6322 */
__LABEL(l_L242X3);
  sim_icache_fetch(4418 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6323 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6324 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6325 */
   __ADD_CYCLES(1);
} /* line 6325 */
  sim_icache_fetch(4422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6327 */
} /* line 6327 */
  sim_icache_fetch(4423 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6329 */
} /* line 6329 */
  sim_icache_fetch(4424 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6331 */
   __GOTO(l_L241X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L241X3;
} /* line 6332 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 413: goto l_L241X3;
    case 414: goto l_L244X3;
    case 415: goto l_L247X3;
    case 416: goto l_L250X3;
    case 417: goto l_L252X3;
    case 418: goto l_L254X3;
    case 419: goto l_L256X3;
    case 420: goto l_L258X3;
    case 421: goto l_L260X3;
    case 422: goto l_L262X3;
    case 423: goto l_L264X3;
    case 424: goto l_L248X3;
    case 425: goto l_L266X3;
    case 426: goto l_L240X3;
    case 427: goto l_L263X3;
    case 428: goto l_L245X3;
    case 429: goto l_L265X3;
    case 430: goto l_L261X3;
    case 431: goto l_L259X3;
    case 432: goto l_L257X3;
    case 433: goto l_L255X3;
    case 434: goto l_L253X3;
    case 435: goto l_L251X3;
    case 436: goto l_L249X3;
    case 437: goto l_L246X3;
    case 438: goto l_L243X3;
    case 439: goto l_L242X3;
    case 440:
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
  reg_l0_0 = (443 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4427 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6354 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6355 */
} /* line 6355 */
		 /* line 6356 */
  sim_icache_fetch(4430 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6359 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (443 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6359 */
l_lr_341: ;/* line 6359 */
__LABEL(l_lr_341);
  sim_icache_fetch(4433 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6361 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6362 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6363 */
   __ADD_CYCLES(1);
} /* line 6363 */
  sim_icache_fetch(4436 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6366 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 442: goto l_lr_341;
    case 443:
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
  reg_l0_0 = (445 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4437 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6412 */
   __MOV(reg_r0_3, 0); /* line 6413 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6414 */
   __ADD_CYCLES(1);
} /* line 6414 */
  sim_icache_fetch(4441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6416 */
} /* line 6416 */
  sim_icache_fetch(4442 + t_thisfile.offset, 1);
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
} /* line 6418 */
  sim_icache_fetch(4443 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6421 */
l_L267X3: ;/* line 6424 */
__LABEL(l_L267X3);
  sim_icache_fetch(4444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6427 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6427 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 444: goto l_L267X3;
    case 445:
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
  reg_l0_0 = (446 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6443 */
} /* line 6443 */
  sim_icache_fetch(4447 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6446 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 446:
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
  reg_l0_0 = (450 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4448 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6461 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6462 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6463 */
} /* line 6463 */
  sim_icache_fetch(4453 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6465 */
} /* line 6465 */
  sim_icache_fetch(4454 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6467 */
} /* line 6467 */
  sim_icache_fetch(4455 + t_thisfile.offset, 1);
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
} /* line 6469 */
		 /* line 6470 */
  sim_icache_fetch(4456 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (450 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6472 */
l_lr_347: ;/* line 6472 */
__LABEL(l_lr_347);
l_L268X3: ;/* line 6474 */
__LABEL(l_L268X3);
  sim_icache_fetch(4458 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6475 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6476 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6477 */
   __ADD_CYCLES(1);
} /* line 6477 */
  sim_icache_fetch(4461 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6480 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 448: goto l_lr_347;
    case 449: goto l_L268X3;
    case 450:
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
  reg_l0_0 = (463 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4462 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6526 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6527 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6528 */
} /* line 6528 */
  sim_icache_fetch(4467 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6530 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6531 */
} /* line 6531 */
  sim_icache_fetch(4470 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6533 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6534 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6535 */
} /* line 6535 */
  sim_icache_fetch(4475 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6537 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6538 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L269X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6539 */
  sim_icache_fetch(4479 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L270X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6541 */
l_L271X3: ;/* line 6544 */
__LABEL(l_L271X3);
  sim_icache_fetch(4480 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6545 */
   __MOV(reg_r0_3, 0); /* line 6546 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6547 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6548 */
   __ADD_CYCLES(1);
} /* line 6548 */
  sim_icache_fetch(4485 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6550 */
} /* line 6550 */
  sim_icache_fetch(4486 + t_thisfile.offset, 1);
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
} /* line 6552 */
  sim_icache_fetch(4487 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6555 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6556 */
l_L272X3: ;/* line 6559 */
__LABEL(l_L272X3);
  sim_icache_fetch(4490 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6560 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6561 */
} /* line 6561 */
		 /* line 6562 */
  sim_icache_fetch(4494 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (463 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6564 */
l_lr_353: ;/* line 6564 */
__LABEL(l_lr_353);
  sim_icache_fetch(4496 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6566 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6567 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6568 */
} /* line 6568 */
		 /* line 6569 */
  sim_icache_fetch(4501 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6571 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6572 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (463 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6573 */
l_lr_355: ;/* line 6573 */
__LABEL(l_lr_355);
  sim_icache_fetch(4507 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6575 */
   __MOV(reg_r0_3, 0); /* line 6576 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6577 */
   __ADD_CYCLES(1);
} /* line 6577 */
  sim_icache_fetch(4510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6580 */
l_L270X3: ;/* line 6583 */
__LABEL(l_L270X3);
  sim_icache_fetch(4511 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6584 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6585 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6586 */
   __ADD_CYCLES(1);
} /* line 6586 */
		 /* line 6587 */
  sim_icache_fetch(4515 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6590 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (463 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6590 */
l_lr_358: ;/* line 6590 */
__LABEL(l_lr_358);
  sim_icache_fetch(4518 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6592 */
   __GOTO(l_L271X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L271X3;
} /* line 6593 */
l_L269X3: ;/* line 6596 */
__LABEL(l_L269X3);
  sim_icache_fetch(4520 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6597 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6598 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6599 */
   __ADD_CYCLES(1);
} /* line 6599 */
		 /* line 6600 */
  sim_icache_fetch(4525 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6602 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (463 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6603 */
l_lr_361: ;/* line 6603 */
__LABEL(l_lr_361);
  sim_icache_fetch(4528 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6605 */
   __GOTO(l_L271X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L271X3;
} /* line 6606 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 451: goto l_L271X3;
    case 452: goto l_L272X3;
    case 454: goto l_lr_353;
    case 456: goto l_lr_355;
    case 457: goto l_L270X3;
    case 459: goto l_lr_358;
    case 460: goto l_L269X3;
    case 462: goto l_lr_361;
    case 463:
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
  reg_l0_0 = (481 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4530 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6625 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6626 */
} /* line 6626 */
  sim_icache_fetch(4533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6628 */
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6629 */
} /* line 6629 */
l_L273X3: ;/* line 6632 */
__LABEL(l_L273X3);
  sim_icache_fetch(4535 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_2); /* line 6633 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6634 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6635 */
} /* line 6635 */
  sim_icache_fetch(4538 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6637 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6638 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6639 */
} /* line 6639 */
  sim_icache_fetch(4541 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6641 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6642 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6643 */
} /* line 6643 */
  sim_icache_fetch(4544 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6645 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6646 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6647 */
} /* line 6647 */
  sim_icache_fetch(4547 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6651 */
} /* line 6651 */
  sim_icache_fetch(4550 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6653 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6654 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6655 */
} /* line 6655 */
  sim_icache_fetch(4553 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6658 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6659 */
} /* line 6659 */
  sim_icache_fetch(4556 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6661 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6662 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6663 */
} /* line 6663 */
  sim_icache_fetch(4559 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6665 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6666 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6667 */
} /* line 6667 */
  sim_icache_fetch(4562 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6669 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6670 */
  sim_icache_fetch(4564 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6672 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6673 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6674 */
} /* line 6674 */
  sim_icache_fetch(4567 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6676 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6677 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6678 */
} /* line 6678 */
  sim_icache_fetch(4570 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6680 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6681 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6682 */
} /* line 6682 */
  sim_icache_fetch(4573 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6684 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6685 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6686 */
} /* line 6686 */
  sim_icache_fetch(4576 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6688 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6689 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6690 */
} /* line 6690 */
  sim_icache_fetch(4579 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6692 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L275X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6693 */
  sim_icache_fetch(4581 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6695 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6696 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6697 */
} /* line 6697 */
  sim_icache_fetch(4584 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6699 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6700 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6701 */
} /* line 6701 */
  sim_icache_fetch(4587 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6703 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6704 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6705 */
} /* line 6705 */
  sim_icache_fetch(4590 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6707 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6708 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6709 */
} /* line 6709 */
  sim_icache_fetch(4593 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6711 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6712 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6713 */
} /* line 6713 */
  sim_icache_fetch(4596 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6715 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6716 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L276X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6717 */
  sim_icache_fetch(4599 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6719 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6720 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6721 */
} /* line 6721 */
  sim_icache_fetch(4602 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6723 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6724 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6725 */
} /* line 6725 */
  sim_icache_fetch(4605 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6727 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6728 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6729 */
} /* line 6729 */
  sim_icache_fetch(4608 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6731 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6732 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6733 */
} /* line 6733 */
  sim_icache_fetch(4611 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6735 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6736 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6737 */
} /* line 6737 */
  sim_icache_fetch(4614 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6739 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6740 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L277X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6741 */
  sim_icache_fetch(4617 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6743 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6744 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6745 */
} /* line 6745 */
  sim_icache_fetch(4620 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6747 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6748 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6749 */
} /* line 6749 */
  sim_icache_fetch(4623 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6751 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6752 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6753 */
} /* line 6753 */
  sim_icache_fetch(4626 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6755 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6756 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6757 */
} /* line 6757 */
  sim_icache_fetch(4629 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6759 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6760 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6761 */
} /* line 6761 */
  sim_icache_fetch(4632 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6763 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6764 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6765 */
} /* line 6765 */
  sim_icache_fetch(4635 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L278X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6767 */
  sim_icache_fetch(4636 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6769 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6770 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6771 */
} /* line 6771 */
  sim_icache_fetch(4642 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6773 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6774 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6775 */
} /* line 6775 */
  sim_icache_fetch(4648 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6777 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6778 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6779 */
} /* line 6779 */
  sim_icache_fetch(4654 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6781 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6782 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6783 */
} /* line 6783 */
  sim_icache_fetch(4660 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6785 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6786 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6787 */
} /* line 6787 */
  sim_icache_fetch(4666 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6789 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6790 */
  sim_icache_fetch(4669 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6792 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6793 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6794 */
} /* line 6794 */
  sim_icache_fetch(4675 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6796 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6797 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6798 */
} /* line 6798 */
  sim_icache_fetch(4681 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6800 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6801 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6802 */
} /* line 6802 */
  sim_icache_fetch(4687 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6804 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6805 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6806 */
} /* line 6806 */
  sim_icache_fetch(4693 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6808 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6809 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6810 */
} /* line 6810 */
  sim_icache_fetch(4699 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6812 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6813 */
  sim_icache_fetch(4702 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6815 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6816 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6817 */
} /* line 6817 */
  sim_icache_fetch(4708 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6819 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6820 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6821 */
} /* line 6821 */
  sim_icache_fetch(4714 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6823 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6824 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6825 */
} /* line 6825 */
  sim_icache_fetch(4720 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6827 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6828 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6829 */
} /* line 6829 */
  sim_icache_fetch(4726 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6831 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6832 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6833 */
} /* line 6833 */
  sim_icache_fetch(4732 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6835 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6836 */
  sim_icache_fetch(4735 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6838 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6839 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6840 */
} /* line 6840 */
  sim_icache_fetch(4741 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6842 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6843 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6844 */
} /* line 6844 */
  sim_icache_fetch(4747 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6846 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6847 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6848 */
} /* line 6848 */
  sim_icache_fetch(4753 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6850 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6851 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6852 */
} /* line 6852 */
  sim_icache_fetch(4759 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6854 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6855 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6856 */
} /* line 6856 */
  sim_icache_fetch(4765 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6858 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6859 */
  sim_icache_fetch(4768 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6861 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6862 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6863 */
} /* line 6863 */
  sim_icache_fetch(4774 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6865 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6866 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6867 */
} /* line 6867 */
  sim_icache_fetch(4780 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6869 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6870 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6871 */
} /* line 6871 */
  sim_icache_fetch(4786 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6873 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6874 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6875 */
} /* line 6875 */
  sim_icache_fetch(4792 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6877 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6878 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6879 */
} /* line 6879 */
  sim_icache_fetch(4798 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6881 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6882 */
  sim_icache_fetch(4801 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6884 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6885 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6886 */
} /* line 6886 */
  sim_icache_fetch(4807 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6888 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6889 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6890 */
} /* line 6890 */
  sim_icache_fetch(4813 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6892 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6893 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6894 */
} /* line 6894 */
  sim_icache_fetch(4819 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6896 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6897 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6898 */
} /* line 6898 */
  sim_icache_fetch(4825 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6900 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6901 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6902 */
} /* line 6902 */
  sim_icache_fetch(4831 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6904 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6905 */
  sim_icache_fetch(4834 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6907 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6908 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6909 */
} /* line 6909 */
  sim_icache_fetch(4840 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6911 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6912 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6913 */
} /* line 6913 */
  sim_icache_fetch(4846 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6915 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6916 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6917 */
} /* line 6917 */
  sim_icache_fetch(4852 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6919 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6920 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6921 */
} /* line 6921 */
  sim_icache_fetch(4858 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6923 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6924 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6925 */
} /* line 6925 */
  sim_icache_fetch(4864 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6927 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6928 */
  sim_icache_fetch(4867 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6930 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6931 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6932 */
} /* line 6932 */
  sim_icache_fetch(4872 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6934 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6935 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6936 */
} /* line 6936 */
  sim_icache_fetch(4877 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6938 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6939 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6940 */
} /* line 6940 */
  sim_icache_fetch(4883 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6942 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6943 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6944 */
} /* line 6944 */
  sim_icache_fetch(4889 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6946 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6947 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6948 */
} /* line 6948 */
  sim_icache_fetch(4895 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6950 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6951 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6952 */
} /* line 6952 */
  sim_icache_fetch(4901 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6954 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6955 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6957 */
  sim_icache_fetch(4906 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L273X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L273X3;
} /* line 6959 */
l_L286X3: ;/* line 6962 */
__LABEL(l_L286X3);
  sim_icache_fetch(4907 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6963 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6964 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 6965 */
l_L288X3: ;/* line 6968 */
__LABEL(l_L288X3);
  sim_icache_fetch(4911 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6969 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6970 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6971 */
} /* line 6971 */
  sim_icache_fetch(4914 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 2); /* line 6973 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 3); /* line 6974 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6975 */
  sim_icache_fetch(4917 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 4); /* line 6977 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 5); /* line 6978 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 6); /* line 6979 */
} /* line 6979 */
  sim_icache_fetch(4920 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 7); /* line 6981 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 8); /* line 6982 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6983 */
} /* line 6983 */
  sim_icache_fetch(4923 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6985 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6986 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6987 */
  sim_icache_fetch(4926 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6989 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6990 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6991 */
  sim_icache_fetch(4929 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6993 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 10); /* line 6994 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6995 */
  sim_icache_fetch(4932 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6997 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 11); /* line 6998 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6999 */
  sim_icache_fetch(4935 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 7001 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 12); /* line 7002 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7003 */
  sim_icache_fetch(4938 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 7005 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 13); /* line 7006 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7007 */
  sim_icache_fetch(4941 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 7009 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 14); /* line 7010 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7011 */
  sim_icache_fetch(4944 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 7013 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 15); /* line 7014 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 7015 */
} /* line 7015 */
  sim_icache_fetch(4947 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_7, reg_r0_5, 0); /* line 7017 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7018 */
  sim_icache_fetch(4949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 7020 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7021 */
  sim_icache_fetch(4951 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 7023 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 7024 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7025 */
  sim_icache_fetch(4954 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 7027 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 2); /* line 7028 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7029 */
  sim_icache_fetch(4957 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 7031 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 7032 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7033 */
  sim_icache_fetch(4960 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 7035 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 7036 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7037 */
  sim_icache_fetch(4963 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 7039 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 7040 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7041 */
  sim_icache_fetch(4966 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 7043 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 7044 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7045 */
  sim_icache_fetch(4969 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 7047 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 7048 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7049 */
  sim_icache_fetch(4972 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 7051 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 7052 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 7053 */
} /* line 7053 */
  sim_icache_fetch(4975 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 7055 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7056 */
  sim_icache_fetch(4977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 7058 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7059 */
  sim_icache_fetch(4979 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 7061 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 10); /* line 7062 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7063 */
  sim_icache_fetch(4982 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 7065 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 7066 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7067 */
  sim_icache_fetch(4985 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 7069 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 7070 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7071 */
  sim_icache_fetch(4988 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 7073 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 7074 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7075 */
  sim_icache_fetch(4991 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 7077 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 7078 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7079 */
  sim_icache_fetch(4994 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 7081 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 7082 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7083 */
  sim_icache_fetch(4997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 7085 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7086 */
  sim_icache_fetch(4999 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 7088 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7089 */
  sim_icache_fetch(5001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 7091 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7092 */
  sim_icache_fetch(5003 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 7094 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7095 */
  sim_icache_fetch(5005 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 7097 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7098 */
  sim_icache_fetch(5007 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 7100 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7101 */
  sim_icache_fetch(5009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 7103 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7104 */
  sim_icache_fetch(5011 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 7106 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 7107 */
l_L289X3: ;/* line 7110 */
__LABEL(l_L289X3);
  sim_icache_fetch(5013 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7112 */
l_L285X3: ;/* line 7115 */
__LABEL(l_L285X3);
  sim_icache_fetch(5014 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 7116 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 7117 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7118 */
l_L284X3: ;/* line 7121 */
__LABEL(l_L284X3);
  sim_icache_fetch(5018 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 7122 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 7123 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7124 */
l_L283X3: ;/* line 7127 */
__LABEL(l_L283X3);
  sim_icache_fetch(5022 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 7128 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 7129 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7130 */
l_L282X3: ;/* line 7133 */
__LABEL(l_L282X3);
  sim_icache_fetch(5026 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 7134 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 7135 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7136 */
l_L281X3: ;/* line 7139 */
__LABEL(l_L281X3);
  sim_icache_fetch(5030 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 7140 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 7141 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7142 */
l_L280X3: ;/* line 7145 */
__LABEL(l_L280X3);
  sim_icache_fetch(5034 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 7146 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 7147 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7148 */
l_L279X3: ;/* line 7151 */
__LABEL(l_L279X3);
  sim_icache_fetch(5038 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 7152 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 7153 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7154 */
l_L278X3: ;/* line 7157 */
__LABEL(l_L278X3);
  sim_icache_fetch(5042 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 7158 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 7159 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7160 */
l_L277X3: ;/* line 7163 */
__LABEL(l_L277X3);
  sim_icache_fetch(5046 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 7164 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 7165 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7166 */
l_L276X3: ;/* line 7169 */
__LABEL(l_L276X3);
  sim_icache_fetch(5049 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 7170 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 7171 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7172 */
l_L275X3: ;/* line 7175 */
__LABEL(l_L275X3);
  sim_icache_fetch(5052 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 7176 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 7177 */
   __GOTO(l_L287X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L287X3;
} /* line 7178 */
l_L274X3: ;/* line 7181 */
__LABEL(l_L274X3);
  sim_icache_fetch(5055 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 7182 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 7183 */
} /* line 7183 */
l_L287X3: ;/* line 7185 */
__LABEL(l_L287X3);
  sim_icache_fetch(5057 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 7186 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 7187 */
   __GOTO(l_L288X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L288X3;
} /* line 7188 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 464: goto l_L273X3;
    case 465: goto l_L286X3;
    case 466: goto l_L288X3;
    case 467: goto l_L289X3;
    case 468: goto l_L285X3;
    case 469: goto l_L284X3;
    case 470: goto l_L283X3;
    case 471: goto l_L282X3;
    case 472: goto l_L281X3;
    case 473: goto l_L280X3;
    case 474: goto l_L279X3;
    case 475: goto l_L278X3;
    case 476: goto l_L277X3;
    case 477: goto l_L276X3;
    case 478: goto l_L275X3;
    case 479: goto l_L274X3;
    case 480: goto l_L287X3;
    case 481:
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
  reg_l0_0 = (482 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5060 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7204 */
} /* line 7204 */
  sim_icache_fetch(5061 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7207 */
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

extern unsigned int version(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(version);  sim_gprof_enter(&sim_gprof_idx,"version");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (483 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5062 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7223 */
} /* line 7223 */
  sim_icache_fetch(5063 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7226 */
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


static sim_fileinfo_t t_thisfile = {"compress.s", 5072, 0, 0, 0, 2};

