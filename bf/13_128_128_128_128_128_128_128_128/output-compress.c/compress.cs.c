/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/13_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_13457Xoffset[1];
unsigned int compress_13457Xbuf[3];
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
unsigned int compress_13457XBuf[216]; 
unsigned int compress_13457Xrcs_ident[6]; 
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
	(151 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(165 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(157 << 5),
	(156 << 5),
	(155 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(154 << 5),
	(169 << 5),
	(169 << 5),
	(153 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(169 << 5),
	(152 << 5)
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

unsigned int compress_13457XBuf[216] = { 
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

unsigned int compress_13457Xrcs_ident[6] = { 
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
   __MOV(reg_r0_5, (unsigned int) compress_13457XBuf); /* line 35 */
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
  reg_l0_0 = (146 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 177 */
   __ADD(reg_r0_32, reg_r0_3, (unsigned int) 15); /* line 178 */
   __ADD(reg_r0_31, reg_r0_3, (unsigned int) 14); /* line 179 */
   __ADD(reg_r0_30, reg_r0_3, (unsigned int) 13); /* line 180 */
   __ADD(reg_r0_28, reg_r0_3, (unsigned int) 12); /* line 181 */
   __ADD(reg_r0_26, reg_r0_3, (unsigned int) 11); /* line 182 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 10); /* line 183 */
   __ADD(reg_r0_22, reg_r0_3, (unsigned int) 9); /* line 184 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 8); /* line 185 */
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 7); /* line 186 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 6); /* line 187 */
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 5); /* line 188 */
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 4); /* line 189 */
} /* line 189 */
  sim_icache_fetch(57 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __SXTB(reg_r0_4, reg_r0_4); /* line 191 */
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 3); /* line 192 */
   __MOV(reg_r0_5, 0); /* line 193 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 194 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 195 */
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
  sim_icache_fetch(69 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
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
} /* line 218 */
  sim_icache_fetch(82 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __LDBs(reg_r0_33, mem_trace_ld(reg_r0_30,0,1)); /* line 220 */
   __LDBs(reg_r0_34, mem_trace_ld(reg_r0_31,0,1)); /* line 221 */
   __LDBs(reg_r0_35, mem_trace_ld(reg_r0_32,0,1)); /* line 222 */
   __ADD(reg_r0_36, reg_r0_6, (unsigned int) 16); /* line 223 */
   __ADD(reg_r0_37, reg_r0_31, (unsigned int) 16); /* line 224 */
   __ADD(reg_r0_38, reg_r0_30, (unsigned int) 16); /* line 225 */
   __ADD(reg_r0_39, reg_r0_28, (unsigned int) 16); /* line 226 */
   __ADD(reg_r0_40, reg_r0_26, (unsigned int) 16); /* line 227 */
   __ADD(reg_r0_41, reg_r0_24, (unsigned int) 16); /* line 228 */
   __ADD(reg_r0_42, reg_r0_22, (unsigned int) 16); /* line 229 */
   __ADD(reg_r0_43, reg_r0_20, (unsigned int) 16); /* line 230 */
   __ADD(reg_r0_44, reg_r0_18, (unsigned int) 16); /* line 231 */
   __ADD(reg_r0_45, reg_r0_16, (unsigned int) 16); /* line 232 */
} /* line 232 */
  sim_icache_fetch(95 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 234 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 235 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 236 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 237 */
   __CMPNE(reg_b0_4, reg_r0_9, 0); /* line 238 */
   __CMPEQ(reg_b0_5, reg_r0_9, reg_r0_4); /* line 239 */
   __CMPNE(reg_b0_6, reg_r0_11, 0); /* line 240 */
   __CMPEQ(reg_b0_7, reg_r0_11, reg_r0_4); /* line 241 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 16); /* line 242 */
   __ADD(reg_r0_7, reg_r0_12, (unsigned int) 16); /* line 243 */
   __ADD(reg_r0_9, reg_r0_10, (unsigned int) 16); /* line 244 */
   __ADD(reg_r0_11, reg_r0_8, (unsigned int) 16); /* line 245 */
   __ADD(reg_r0_46, reg_r0_32, (unsigned int) 16); /* line 246 */
} /* line 246 */
  sim_icache_fetch(108 + t_thisfile.offset, 13);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __SLCT(reg_r0_47, reg_b0_1, reg_r0_2, reg_r0_5); /* line 248 */
   __CMPNE(reg_b0_0, reg_r0_13, 0); /* line 249 */
   __CMPEQ(reg_b0_1, reg_r0_13, reg_r0_4); /* line 250 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 251 */
   __LDBs(reg_r0_13, mem_trace_ld(reg_r0_36,0,1)); /* line 252 */
   __LDBs(reg_r0_48, mem_trace_ld(reg_r0_11,0,1)); /* line 253 */
   __LDBs(reg_r0_49, mem_trace_ld(reg_r0_9,0,1)); /* line 254 */
   __LDBs(reg_r0_50, mem_trace_ld(reg_r0_7,0,1)); /* line 255 */
   __LDBs(reg_r0_51, mem_trace_ld(reg_r0_3,0,1)); /* line 256 */
   __LDBs(reg_r0_52, mem_trace_ld(reg_r0_45,0,1)); /* line 257 */
   __LDBs(reg_r0_53, mem_trace_ld(reg_r0_44,0,1)); /* line 258 */
   __LDBs(reg_r0_54, mem_trace_ld(reg_r0_43,0,1)); /* line 259 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 260 */
  sim_icache_fetch(121 + t_thisfile.offset, 13);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __SLCT(reg_r0_6, reg_b0_3, reg_r0_6, reg_r0_47); /* line 262 */
   __CMPNE(reg_b0_2, reg_r0_15, 0); /* line 263 */
   __CMPEQ(reg_b0_3, reg_r0_15, reg_r0_4); /* line 264 */
   __LDBs(reg_r0_15, mem_trace_ld(reg_r0_2,0,1)); /* line 265 */
   __LDBs(reg_r0_55, mem_trace_ld(reg_r0_42,0,1)); /* line 266 */
   __LDBs(reg_r0_56, mem_trace_ld(reg_r0_41,0,1)); /* line 267 */
   __LDBs(reg_r0_57, mem_trace_ld(reg_r0_40,0,1)); /* line 268 */
   __LDBs(reg_r0_58, mem_trace_ld(reg_r0_39,0,1)); /* line 269 */
   __LDBs(reg_r0_59, mem_trace_ld(reg_r0_38,0,1)); /* line 270 */
   __LDBs(reg_r0_60, mem_trace_ld(reg_r0_37,0,1)); /* line 271 */
   __LDBs(reg_r0_61, mem_trace_ld(reg_r0_46,0,1)); /* line 272 */
   __ADD(reg_r0_62, reg_r0_2, (unsigned int) 16); /* line 273 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 274 */
  sim_icache_fetch(134 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_8, reg_b0_5, reg_r0_8, reg_r0_6); /* line 276 */
   __CMPNE(reg_b0_4, reg_r0_17, 0); /* line 277 */
   __CMPEQ(reg_b0_5, reg_r0_17, reg_r0_4); /* line 278 */
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
   __ADD(reg_r0_8, reg_r0_11, (unsigned int) 16); /* line 290 */
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
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 16); /* line 296 */
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
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) 16); /* line 302 */
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
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 16); /* line 308 */
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
   __CMPNE(reg_b0_2, reg_r0_33, 0); /* line 318 */
   __CMPEQ(reg_b0_3, reg_r0_33, reg_r0_4); /* line 319 */
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
   __CMPNE(reg_b0_4, reg_r0_34, 0); /* line 324 */
   __CMPEQ(reg_b0_5, reg_r0_34, reg_r0_4); /* line 325 */
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
   __CMPNE(reg_b0_0, reg_r0_15, 0); /* line 336 */
   __CMPEQ(reg_b0_1, reg_r0_15, reg_r0_4); /* line 337 */
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
   __CMPNE(reg_b0_2, reg_r0_13, 0); /* line 342 */
   __CMPEQ(reg_b0_3, reg_r0_13, reg_r0_4); /* line 343 */
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
   __SLCT(reg_r0_31, reg_b0_5, reg_r0_31, reg_r0_30); /* line 347 */
   __CMPNE(reg_b0_4, reg_r0_48, 0); /* line 348 */
   __CMPEQ(reg_b0_5, reg_r0_48, reg_r0_4); /* line 349 */
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
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_32, reg_r0_31); /* line 353 */
   __CMPNE(reg_b0_6, reg_r0_49, 0); /* line 354 */
   __CMPEQ(reg_b0_7, reg_r0_49, reg_r0_4); /* line 355 */
   __ADD(reg_r0_30, reg_r0_38, (unsigned int) 16); /* line 356 */
   __ADD(reg_r0_32, reg_r0_46, (unsigned int) 16); /* line 357 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 358 */
  sim_icache_fetch(204 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_47, reg_b0_1, reg_r0_2, reg_r0_5); /* line 360 */
   __CMPNE(reg_b0_0, reg_r0_50, 0); /* line 361 */
   __CMPEQ(reg_b0_1, reg_r0_50, reg_r0_4); /* line 362 */
   __ADD(reg_r0_31, reg_r0_37, (unsigned int) 16); /* line 363 */
   __MOV(reg_r0_2, reg_r0_62); /* line 364 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 365 */
  sim_icache_fetch(210 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_36, reg_b0_3, reg_r0_36, reg_r0_47); /* line 367 */
   __CMPNE(reg_b0_2, reg_r0_51, 0); /* line 368 */
   __CMPEQ(reg_b0_3, reg_r0_51, reg_r0_4); /* line 369 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 370 */
  sim_icache_fetch(214 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_11, reg_b0_5, reg_r0_11, reg_r0_36); /* line 372 */
   __CMPNE(reg_b0_4, reg_r0_52, 0); /* line 373 */
   __CMPEQ(reg_b0_5, reg_r0_52, reg_r0_4); /* line 374 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 375 */
  sim_icache_fetch(218 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_9, reg_b0_7, reg_r0_9, reg_r0_11); /* line 377 */
   __CMPNE(reg_b0_6, reg_r0_53, 0); /* line 378 */
   __CMPEQ(reg_b0_7, reg_r0_53, reg_r0_4); /* line 379 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 380 */
  sim_icache_fetch(222 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_7, reg_r0_9); /* line 382 */
   __CMPNE(reg_b0_0, reg_r0_54, 0); /* line 383 */
   __CMPEQ(reg_b0_1, reg_r0_54, reg_r0_4); /* line 384 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 385 */
  sim_icache_fetch(226 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_3, reg_r0_3, reg_r0_7); /* line 387 */
   __CMPNE(reg_b0_2, reg_r0_55, 0); /* line 388 */
   __CMPEQ(reg_b0_3, reg_r0_55, reg_r0_4); /* line 389 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L22X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 390 */
  sim_icache_fetch(230 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_45, reg_b0_5, reg_r0_45, reg_r0_3); /* line 392 */
   __CMPNE(reg_b0_4, reg_r0_56, 0); /* line 393 */
   __CMPEQ(reg_b0_5, reg_r0_56, reg_r0_4); /* line 394 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 395 */
  sim_icache_fetch(234 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_44, reg_b0_7, reg_r0_44, reg_r0_45); /* line 397 */
   __CMPNE(reg_b0_6, reg_r0_57, 0); /* line 398 */
   __CMPEQ(reg_b0_7, reg_r0_57, reg_r0_4); /* line 399 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 400 */
  sim_icache_fetch(238 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_43, reg_b0_1, reg_r0_43, reg_r0_44); /* line 402 */
   __CMPNE(reg_b0_0, reg_r0_58, 0); /* line 403 */
   __CMPEQ(reg_b0_1, reg_r0_58, reg_r0_4); /* line 404 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 405 */
  sim_icache_fetch(242 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_42, reg_b0_3, reg_r0_42, reg_r0_43); /* line 407 */
   __CMPNE(reg_b0_2, reg_r0_59, 0); /* line 408 */
   __CMPEQ(reg_b0_3, reg_r0_59, reg_r0_4); /* line 409 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 410 */
  sim_icache_fetch(246 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_41, reg_b0_5, reg_r0_41, reg_r0_42); /* line 412 */
   __CMPNE(reg_b0_4, reg_r0_60, 0); /* line 413 */
   __CMPEQ(reg_b0_5, reg_r0_60, reg_r0_4); /* line 414 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 415 */
  sim_icache_fetch(250 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_40, reg_b0_7, reg_r0_40, reg_r0_41); /* line 417 */
   __CMPNE(reg_b0_6, reg_r0_61, 0); /* line 418 */
   __CMPEQ(reg_b0_7, reg_r0_61, reg_r0_4); /* line 419 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 420 */
  sim_icache_fetch(254 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_39, reg_b0_1, reg_r0_39, reg_r0_40); /* line 422 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 423 */
  sim_icache_fetch(256 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_38, reg_b0_3, reg_r0_38, reg_r0_39); /* line 425 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 426 */
  sim_icache_fetch(258 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_37, reg_b0_5, reg_r0_37, reg_r0_38); /* line 428 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 429 */
  sim_icache_fetch(260 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_7, reg_r0_46, reg_r0_37); /* line 431 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 433 */
  sim_icache_fetch(262 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 435 */
l_L32X3: ;/* line 438 */
__LABEL(l_L32X3);
  sim_icache_fetch(263 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_31, reg_r0_37); /* line 439 */
} /* line 439 */
l_L16X3: ;/* line 442 */
__LABEL(l_L16X3);
  sim_icache_fetch(264 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_31); /* line 443 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 444 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 445 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 446 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 447 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 448 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 449 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 450 */
l_L31X3: ;/* line 453 */
__LABEL(l_L31X3);
  sim_icache_fetch(272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_30, reg_r0_38); /* line 454 */
} /* line 454 */
l_L15X3: ;/* line 457 */
__LABEL(l_L15X3);
  sim_icache_fetch(273 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_30); /* line 458 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 459 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 460 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 461 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 462 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 463 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 464 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 465 */
l_L30X3: ;/* line 468 */
__LABEL(l_L30X3);
  sim_icache_fetch(281 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_28, reg_r0_39); /* line 469 */
} /* line 469 */
l_L14X3: ;/* line 472 */
__LABEL(l_L14X3);
  sim_icache_fetch(282 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_28); /* line 473 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 474 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 475 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 476 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 477 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 478 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 479 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 480 */
l_L29X3: ;/* line 483 */
__LABEL(l_L29X3);
  sim_icache_fetch(290 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_26, reg_r0_40); /* line 484 */
} /* line 484 */
l_L13X3: ;/* line 487 */
__LABEL(l_L13X3);
  sim_icache_fetch(291 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_26); /* line 488 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 489 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 490 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 491 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 492 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 493 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 494 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 495 */
l_L28X3: ;/* line 498 */
__LABEL(l_L28X3);
  sim_icache_fetch(299 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_24, reg_r0_41); /* line 499 */
} /* line 499 */
l_L12X3: ;/* line 502 */
__LABEL(l_L12X3);
  sim_icache_fetch(300 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_24); /* line 503 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 504 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 505 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 506 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 507 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 508 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 509 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 510 */
l_L27X3: ;/* line 513 */
__LABEL(l_L27X3);
  sim_icache_fetch(308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_22, reg_r0_42); /* line 514 */
} /* line 514 */
l_L11X3: ;/* line 517 */
__LABEL(l_L11X3);
  sim_icache_fetch(309 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_22); /* line 518 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 519 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 520 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 521 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 522 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 523 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 524 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 525 */
l_L26X3: ;/* line 528 */
__LABEL(l_L26X3);
  sim_icache_fetch(317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_20, reg_r0_43); /* line 529 */
} /* line 529 */
l_L10X3: ;/* line 532 */
__LABEL(l_L10X3);
  sim_icache_fetch(318 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_20); /* line 533 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 534 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 535 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 536 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 537 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 538 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 539 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 540 */
l_L25X3: ;/* line 543 */
__LABEL(l_L25X3);
  sim_icache_fetch(326 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_18, reg_r0_44); /* line 544 */
} /* line 544 */
l_L9X3: ;/* line 547 */
__LABEL(l_L9X3);
  sim_icache_fetch(327 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_18); /* line 548 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 549 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 550 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 551 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 552 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 553 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 554 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 555 */
l_L24X3: ;/* line 558 */
__LABEL(l_L24X3);
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, reg_r0_45); /* line 559 */
} /* line 559 */
l_L8X3: ;/* line 562 */
__LABEL(l_L8X3);
  sim_icache_fetch(336 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_16); /* line 563 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 564 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 565 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 566 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 567 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 568 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 569 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 570 */
l_L23X3: ;/* line 573 */
__LABEL(l_L23X3);
  sim_icache_fetch(344 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_14, reg_r0_3); /* line 574 */
} /* line 574 */
l_L7X3: ;/* line 577 */
__LABEL(l_L7X3);
  sim_icache_fetch(345 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_14); /* line 578 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 579 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 580 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 581 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 582 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 583 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 584 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 585 */
l_L22X3: ;/* line 588 */
__LABEL(l_L22X3);
  sim_icache_fetch(353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, reg_r0_7); /* line 589 */
} /* line 589 */
l_L6X3: ;/* line 592 */
__LABEL(l_L6X3);
  sim_icache_fetch(354 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_12); /* line 593 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 594 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 595 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 596 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 597 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 598 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 599 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 600 */
l_L21X3: ;/* line 603 */
__LABEL(l_L21X3);
  sim_icache_fetch(362 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_10, reg_r0_9); /* line 604 */
} /* line 604 */
l_L5X3: ;/* line 607 */
__LABEL(l_L5X3);
  sim_icache_fetch(363 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_10); /* line 608 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 609 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 610 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 611 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 612 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 613 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 614 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 615 */
l_L20X3: ;/* line 618 */
__LABEL(l_L20X3);
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_11); /* line 619 */
} /* line 619 */
l_L4X3: ;/* line 622 */
__LABEL(l_L4X3);
  sim_icache_fetch(372 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_8); /* line 623 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 624 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 625 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 626 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 627 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 628 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 629 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 630 */
l_L19X3: ;/* line 633 */
__LABEL(l_L19X3);
  sim_icache_fetch(380 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_36); /* line 634 */
} /* line 634 */
l_L3X3: ;/* line 637 */
__LABEL(l_L3X3);
  sim_icache_fetch(381 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_6); /* line 638 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 639 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 640 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 641 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 642 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 643 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 644 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 645 */
l_L18X3: ;/* line 648 */
__LABEL(l_L18X3);
  sim_icache_fetch(389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_47); /* line 649 */
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 650 */
l_L17X3: ;/* line 653 */
__LABEL(l_L17X3);
  sim_icache_fetch(391 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_3, reg_r0_5); /* line 654 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 655 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 656 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 657 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 658 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 659 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 660 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 661 */
l_L2X3: ;/* line 664 */
__LABEL(l_L2X3);
  sim_icache_fetch(399 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_47); /* line 665 */
} /* line 665 */
l_L34X3: ;/* line 667 */
__LABEL(l_L34X3);
  sim_icache_fetch(400 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 668 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 669 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 670 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 671 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 672 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 673 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 674 */
l_L1X3: ;/* line 677 */
__LABEL(l_L1X3);
  sim_icache_fetch(407 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_3, reg_r0_5); /* line 678 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 679 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 680 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 12),0,4)); /* line 681 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 8),0,4)); /* line 682 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 4),0,4)); /* line 683 */
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_1,0,4)); /* line 684 */
} /* line 684 */
l_L33X3: ;/* line 686 */
__LABEL(l_L33X3);
  sim_icache_fetch(414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 688 */
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
    case 141: goto l_L17X3;
    case 142: goto l_L2X3;
    case 143: goto l_L34X3;
    case 144: goto l_L1X3;
    case 145: goto l_L33X3;
    case 146:
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
  reg_l0_0 = (213 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(415 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 705 */
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 706 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 707 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 708 */
} /* line 708 */
  sim_icache_fetch(422 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 710 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 711 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_4); /* line 712 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 713 */
} /* line 713 */
  sim_icache_fetch(427 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 715 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 716 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_7); /* line 717 */
} /* line 717 */
		 /* line 718 */
  sim_icache_fetch(430 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 720 */
l_lr_47: ;/* line 720 */
__LABEL(l_lr_47);
  sim_icache_fetch(432 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 722 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 723 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 724 */
   __ADD_CYCLES(1);
} /* line 724 */
  sim_icache_fetch(435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 726 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 727 */
} /* line 727 */
l_L35X3: ;/* line 730 */
__LABEL(l_L35X3);
  sim_icache_fetch(437 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 731 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 732 */
} /* line 732 */
  sim_icache_fetch(439 + t_thisfile.offset, 1);
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
} /* line 734 */
  sim_icache_fetch(440 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 736 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 737 */
   __ADD_CYCLES(1);
} /* line 737 */
  sim_icache_fetch(442 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 739 */
} /* line 739 */
  sim_icache_fetch(443 + t_thisfile.offset, 1);
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
} /* line 741 */
l_L38X3: ;/* line 744 */
__LABEL(l_L38X3);
  sim_icache_fetch(444 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 745 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 746 */
   __ADD_CYCLES(1);
} /* line 746 */
  sim_icache_fetch(446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 748 */
} /* line 748 */
  sim_icache_fetch(447 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 750 */
} /* line 750 */
  sim_icache_fetch(448 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 752 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 753 */
   __ADD_CYCLES(1);
} /* line 753 */
  sim_icache_fetch(450 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 755 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 756 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 757 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 758 */
} /* line 758 */
  sim_icache_fetch(455 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 760 */
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 761 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L39X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 762 */
  sim_icache_fetch(458 + t_thisfile.offset, 1);
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
} /* line 764 */
  sim_icache_fetch(459 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 765 */
  sim_icache_fetch(460 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 767 */
l__X1XCompressXTAGX0X0: ;/* line 769 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(461 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 770 */
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 771 */
l__X1XCompressXTAGX0X7: ;/* line 774 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(464 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 775 */
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 776 */
l__X1XCompressXTAGX0X6: ;/* line 779 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(467 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 780 */
} /* line 780 */
  sim_icache_fetch(468 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 782 */
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 783 */
l__X1XCompressXTAGX0X5: ;/* line 786 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(471 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 787 */
} /* line 787 */
  sim_icache_fetch(472 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 789 */
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 790 */
l__X1XCompressXTAGX0X4: ;/* line 793 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(475 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 794 */
} /* line 794 */
  sim_icache_fetch(476 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 796 */
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 797 */
l__X1XCompressXTAGX0X3: ;/* line 800 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(479 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 801 */
} /* line 801 */
  sim_icache_fetch(480 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 803 */
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 804 */
l__X1XCompressXTAGX0X2: ;/* line 807 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 808 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 809 */
   __ADD_CYCLES(1);
} /* line 809 */
  sim_icache_fetch(485 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 811 */
} /* line 811 */
  sim_icache_fetch(486 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 813 */
} /* line 813 */
  sim_icache_fetch(487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 815 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 816 */
   __ADD_CYCLES(1);
} /* line 816 */
  sim_icache_fetch(489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 818 */
} /* line 818 */
  sim_icache_fetch(490 + t_thisfile.offset, 1);
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
l_L37X3: ;/* line 822 */
__LABEL(l_L37X3);
  sim_icache_fetch(491 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 823 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 824 */
   __GOTO(l_L35X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L35X3;
} /* line 825 */
l_L41X3: ;/* line 828 */
__LABEL(l_L41X3);
  sim_icache_fetch(494 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 829 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 830 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 831 */
} /* line 831 */
  sim_icache_fetch(497 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 833 */
} /* line 833 */
  sim_icache_fetch(498 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 835 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 836 */
  sim_icache_fetch(500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 839 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 841 */
l_L42X3: ;/* line 844 */
__LABEL(l_L42X3);
		 /* line 844 */
  sim_icache_fetch(502 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 847 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (213 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 847 */
l_lr_61: ;/* line 847 */
__LABEL(l_lr_61);
		 /* line 848 */
  sim_icache_fetch(506 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (213 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 850 */
l_lr_63: ;/* line 850 */
__LABEL(l_lr_63);
  sim_icache_fetch(508 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 852 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 853 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 854 */
   __ADD_CYCLES(1);
} /* line 854 */
  sim_icache_fetch(511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 857 */
l__X1XCompressXTAGX0X1: ;/* line 860 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 860 */
  sim_icache_fetch(512 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 863 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 864 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 864 */
l_lr_66: ;/* line 864 */
__LABEL(l_lr_66);
  sim_icache_fetch(516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 866 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 867 */
} /* line 867 */
  sim_icache_fetch(518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L38X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L38X3;
} /* line 869 */
l_L40X3: ;/* line 872 */
__LABEL(l_L40X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 873 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 873 */
  sim_icache_fetch(519 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 876 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (213 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 876 */
l_lr_70: ;/* line 876 */
__LABEL(l_lr_70);
		 /* line 877 */
  sim_icache_fetch(523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (213 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 879 */
l_lr_72: ;/* line 879 */
__LABEL(l_lr_72);
  sim_icache_fetch(525 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 881 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 882 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 883 */
   __ADD_CYCLES(1);
} /* line 883 */
  sim_icache_fetch(528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 886 */
l_L39X3: ;/* line 889 */
__LABEL(l_L39X3);
  sim_icache_fetch(529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L37X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L37X3;
} /* line 890 */
l_L36X3: ;/* line 893 */
__LABEL(l_L36X3);
  sim_icache_fetch(530 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 894 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 895 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 896 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 897 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 898 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 899 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 900 */
   __ADD_CYCLES(1);
} /* line 900 */
  sim_icache_fetch(540 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 902 */
   __CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 4096); /* line 903 */
} /* line 903 */
  sim_icache_fetch(543 + t_thisfile.offset, 1);
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
} /* line 905 */
  sim_icache_fetch(544 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 907 */
} /* line 907 */
l_L44X3: ;/* line 909 */
__LABEL(l_L44X3);
  sim_icache_fetch(546 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 910 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 911 */
   __ADD_CYCLES(1);
} /* line 911 */
  sim_icache_fetch(549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 913 */
} /* line 913 */
  sim_icache_fetch(550 + t_thisfile.offset, 1);
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
} /* line 915 */
  sim_icache_fetch(551 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 917 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 918 */
} /* line 918 */
l_L46X3: ;/* line 920 */
__LABEL(l_L46X3);
  sim_icache_fetch(555 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 921 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 922 */
   __ADD_CYCLES(1);
} /* line 922 */
  sim_icache_fetch(558 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 924 */
} /* line 924 */
  sim_icache_fetch(559 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 926 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L47X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 927 */
		 /* line 928 */
  sim_icache_fetch(562 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 930 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 931 */
l_lr_78: ;/* line 931 */
__LABEL(l_lr_78);
l_L48X3: ;/* line 933 */
__LABEL(l_L48X3);
  sim_icache_fetch(566 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 934 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 935 */
   __LDBs(reg_r0_9, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 936 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 937 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 938 */
   __MOV(reg_r0_8, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 939 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 940 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 941 */
} /* line 941 */
  sim_icache_fetch(582 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 943 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 944 */
} /* line 944 */
  sim_icache_fetch(586 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 946 */
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 947 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) -1); /* line 948 */
   __ZXTB(reg_r0_9, reg_r0_9); /* line 949 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 950 */
} /* line 950 */
  sim_icache_fetch(592 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_4, 0); /* line 952 */
   __CMPNE(reg_b0_1, reg_r0_9, reg_r0_10); /* line 953 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 954 */
  sim_icache_fetch(595 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_4); /* line 956 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 957 */
  sim_icache_fetch(598 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 959 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L51X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 960 */
l_L52X3: ;/* line 962 */
__LABEL(l_L52X3);
		 /* line 962 */
  sim_icache_fetch(601 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (213 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 964 */
l_lr_82: ;/* line 964 */
__LABEL(l_lr_82);
  sim_icache_fetch(603 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 966 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 967 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 968 */
   __ADD_CYCLES(1);
} /* line 968 */
  sim_icache_fetch(606 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 971 */
l_L51X3: ;/* line 974 */
__LABEL(l_L51X3);
  sim_icache_fetch(607 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 975 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 976 */
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 977 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 978 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 979 */
   __ADD_CYCLES(1);
} /* line 979 */
  sim_icache_fetch(616 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 981 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 982 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 983 */
} /* line 983 */
  sim_icache_fetch(619 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 985 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 986 */
} /* line 986 */
  sim_icache_fetch(622 + t_thisfile.offset, 1);
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
} /* line 988 */
  sim_icache_fetch(623 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 990 */
} /* line 990 */
  sim_icache_fetch(625 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 992 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 993 */
   __ADD_CYCLES(1);
} /* line 993 */
  sim_icache_fetch(627 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 995 */
} /* line 995 */
l_L54X3: ;/* line 997 */
__LABEL(l_L54X3);
  sim_icache_fetch(628 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 998 */
} /* line 998 */
  sim_icache_fetch(629 + t_thisfile.offset, 1);
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
  sim_icache_fetch(630 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L52X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L52X3;
} /* line 1003 */
l_L55X3: ;/* line 1006 */
__LABEL(l_L55X3);
  sim_icache_fetch(631 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1007 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1008 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 1009 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 1010 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 1011 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1012 */
   __ADD_CYCLES(1);
} /* line 1012 */
  sim_icache_fetch(641 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 1014 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 1015 */
} /* line 1015 */
  sim_icache_fetch(643 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 1017 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1018 */
} /* line 1018 */
  sim_icache_fetch(646 + t_thisfile.offset, 1);
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
} /* line 1020 */
  sim_icache_fetch(647 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 1022 */
} /* line 1022 */
  sim_icache_fetch(649 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 1024 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1025 */
   __ADD_CYCLES(1);
} /* line 1025 */
  sim_icache_fetch(651 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 1027 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 1028 */
} /* line 1028 */
l_L57X3: ;/* line 1030 */
__LABEL(l_L57X3);
  sim_icache_fetch(654 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 1031 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 1032 */
} /* line 1032 */
  sim_icache_fetch(656 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 1034 */
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 1035 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 1036 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 1037 */
} /* line 1037 */
  sim_icache_fetch(662 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 1039 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1040 */
		 /* line 1041 */
  sim_icache_fetch(665 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (213 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1043 */
l_lr_88: ;/* line 1043 */
__LABEL(l_lr_88);
  sim_icache_fetch(667 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1045 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1046 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1047 */
   __ADD_CYCLES(1);
} /* line 1047 */
  sim_icache_fetch(670 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1050 */
l_L49X3: ;/* line 1053 */
__LABEL(l_L49X3);
		 /* line 1053 */
  sim_icache_fetch(671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1055 */
l_lr_91: ;/* line 1055 */
__LABEL(l_lr_91);
  sim_icache_fetch(673 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 1057 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1058 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1059 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1060 */
   __ADD_CYCLES(1);
} /* line 1060 */
  sim_icache_fetch(677 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 1063 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1064 */
l_L56X3: ;/* line 1067 */
__LABEL(l_L56X3);
  sim_icache_fetch(680 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 1068 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 1069 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 1070 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 1071 */
} /* line 1071 */
  sim_icache_fetch(686 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 1073 */
   __GOTO(l_L57X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L57X3;
} /* line 1074 */
l_L53X3: ;/* line 1077 */
__LABEL(l_L53X3);
  sim_icache_fetch(689 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 1078 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1079 */
   __GOTO(l_L54X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L54X3;
} /* line 1080 */
l_L50X3: ;/* line 1083 */
__LABEL(l_L50X3);
  sim_icache_fetch(693 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) -1); /* line 1084 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(696 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1087 */
} /* line 1087 */
  sim_icache_fetch(697 + t_thisfile.offset, 1);
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
} /* line 1090 */
  sim_icache_fetch(698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L52X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L52X3;
} /* line 1092 */
l_L47X3: ;/* line 1095 */
__LABEL(l_L47X3);
  sim_icache_fetch(699 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1096 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1097 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1098 */
   __ADD_CYCLES(1);
} /* line 1098 */
  sim_icache_fetch(704 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1100 */
} /* line 1100 */
  sim_icache_fetch(706 + t_thisfile.offset, 1);
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
} /* line 1102 */
		 /* line 1103 */
  sim_icache_fetch(707 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1105 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1106 */
l_lr_97: ;/* line 1106 */
__LABEL(l_lr_97);
  sim_icache_fetch(711 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1108 */
l_L58X3: ;/* line 1111 */
__LABEL(l_L58X3);
  sim_icache_fetch(712 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1112 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1113 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1114 */
   __ADD_CYCLES(1);
} /* line 1114 */
  sim_icache_fetch(717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1116 */
} /* line 1116 */
  sim_icache_fetch(719 + t_thisfile.offset, 1);
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
} /* line 1118 */
		 /* line 1119 */
  sim_icache_fetch(720 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1121 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1122 */
l_lr_100: ;/* line 1122 */
__LABEL(l_lr_100);
  sim_icache_fetch(724 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1124 */
l_L59X3: ;/* line 1127 */
__LABEL(l_L59X3);
  sim_icache_fetch(725 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1128 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1129 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1130 */
   __ADD_CYCLES(1);
} /* line 1130 */
  sim_icache_fetch(730 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1132 */
} /* line 1132 */
  sim_icache_fetch(732 + t_thisfile.offset, 1);
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
} /* line 1134 */
		 /* line 1135 */
  sim_icache_fetch(733 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1137 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1138 */
l_lr_103: ;/* line 1138 */
__LABEL(l_lr_103);
  sim_icache_fetch(737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1140 */
l_L60X3: ;/* line 1143 */
__LABEL(l_L60X3);
  sim_icache_fetch(738 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1144 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1145 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1146 */
   __ADD_CYCLES(1);
} /* line 1146 */
  sim_icache_fetch(743 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1148 */
} /* line 1148 */
  sim_icache_fetch(745 + t_thisfile.offset, 1);
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
} /* line 1150 */
		 /* line 1151 */
  sim_icache_fetch(746 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1153 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1154 */
l_lr_106: ;/* line 1154 */
__LABEL(l_lr_106);
  sim_icache_fetch(750 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1156 */
l_L61X3: ;/* line 1159 */
__LABEL(l_L61X3);
		 /* line 1159 */
  sim_icache_fetch(751 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (213 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1161 */
l_lr_109: ;/* line 1161 */
__LABEL(l_lr_109);
  sim_icache_fetch(753 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1163 */
l_L45X3: ;/* line 1166 */
__LABEL(l_L45X3);
  sim_icache_fetch(754 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1167 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1168 */
} /* line 1168 */
  sim_icache_fetch(757 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1170 */
   __GOTO(l_L46X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L46X3;
} /* line 1171 */
l_L43X3: ;/* line 1174 */
__LABEL(l_L43X3);
  sim_icache_fetch(760 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1175 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1176 */
   __GOTO(l_L44X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L44X3;
} /* line 1177 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 148: goto l_lr_47;
    case 149: goto l_L35X3;
    case 150: goto l_L38X3;
    case 151: goto l__X1XCompressXTAGX0X0;
    case 152: goto l__X1XCompressXTAGX0X7;
    case 153: goto l__X1XCompressXTAGX0X6;
    case 154: goto l__X1XCompressXTAGX0X5;
    case 155: goto l__X1XCompressXTAGX0X4;
    case 156: goto l__X1XCompressXTAGX0X3;
    case 157: goto l__X1XCompressXTAGX0X2;
    case 158: goto l_L37X3;
    case 159: goto l_L41X3;
    case 160: goto l_L42X3;
    case 162: goto l_lr_61;
    case 164: goto l_lr_63;
    case 165: goto l__X1XCompressXTAGX0X1;
    case 167: goto l_lr_66;
    case 168: goto l_L40X3;
    case 169: goto l__X1XCompressXTAGX0XDEFAULT;
    case 171: goto l_lr_70;
    case 173: goto l_lr_72;
    case 174: goto l_L39X3;
    case 175: goto l_L36X3;
    case 176: goto l_L44X3;
    case 177: goto l_L46X3;
    case 179: goto l_lr_78;
    case 180: goto l_L48X3;
    case 181: goto l_L52X3;
    case 183: goto l_lr_82;
    case 184: goto l_L51X3;
    case 185: goto l_L54X3;
    case 186: goto l_L55X3;
    case 187: goto l_L57X3;
    case 189: goto l_lr_88;
    case 190: goto l_L49X3;
    case 192: goto l_lr_91;
    case 193: goto l_L56X3;
    case 194: goto l_L53X3;
    case 195: goto l_L50X3;
    case 196: goto l_L47X3;
    case 198: goto l_lr_97;
    case 199: goto l_L58X3;
    case 201: goto l_lr_100;
    case 202: goto l_L59X3;
    case 204: goto l_lr_103;
    case 205: goto l_L60X3;
    case 207: goto l_lr_106;
    case 208: goto l_L61X3;
    case 210: goto l_lr_109;
    case 211: goto l_L45X3;
    case 212: goto l_L43X3;
    case 213:
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
  reg_l0_0 = (332 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(763 + t_thisfile.offset, 21);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1315 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1316 */
   __LDWs(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1317 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1318 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1319 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1320 */
   __MOV(reg_r0_4, 0); /* line 1321 */
   __MOV(reg_r0_12, (unsigned int) 257); /* line 1322 */
   __MOV(reg_r0_10, (unsigned int) 511); /* line 1323 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 1324 */
   __MOV(reg_r0_8, (unsigned int) 10000); /* line 1325 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1326 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1327 */
} /* line 1327 */
  sim_icache_fetch(784 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1329 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1330 */
} /* line 1330 */
  sim_icache_fetch(787 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1332 */
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 1333 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) -1); /* line 1334 */
   __ADD(reg_r0_15, reg_r0_14, (unsigned int) 1); /* line 1335 */
} /* line 1335 */
  sim_icache_fetch(791 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, (unsigned int) 256); /* line 1337 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 1338 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1339 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1340 */
l_L63X3: ;/* line 1342 */
__LABEL(l_L63X3);
  sim_icache_fetch(796 + t_thisfile.offset, 23);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __STW(mem_trace_st((unsigned int) compress_13457Xoffset,0,4), 0); /* line 1343 */
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1344 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1345 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1346 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1347 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1348 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_8); /* line 1349 */
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 1350 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_10); /* line 1351 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_12); /* line 1352 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_13); /* line 1353 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1354 */
  sim_icache_fetch(819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 1356 */
} /* line 1356 */
  sim_icache_fetch(821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 1358 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1359 */
   __ADD_CYCLES(1);
} /* line 1359 */
  sim_icache_fetch(823 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 1361 */
} /* line 1361 */
l_L65X3: ;/* line 1363 */
__LABEL(l_L65X3);
  sim_icache_fetch(824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_14); /* line 1364 */
} /* line 1364 */
l_L66X3: ;/* line 1367 */
__LABEL(l_L66X3);
  sim_icache_fetch(825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1368 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1369 */
} /* line 1369 */
  sim_icache_fetch(827 + t_thisfile.offset, 3);
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
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1373 */
  sim_icache_fetch(830 + t_thisfile.offset, 3);
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
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1377 */
  sim_icache_fetch(833 + t_thisfile.offset, 3);
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
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1381 */
  sim_icache_fetch(836 + t_thisfile.offset, 3);
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
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1385 */
  sim_icache_fetch(839 + t_thisfile.offset, 3);
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
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1389 */
  sim_icache_fetch(842 + t_thisfile.offset, 3);
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
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1393 */
  sim_icache_fetch(845 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1395 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1396 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1397 */
  sim_icache_fetch(848 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1399 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1400 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1401 */
  sim_icache_fetch(851 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1403 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1404 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1405 */
  sim_icache_fetch(854 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1407 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1408 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1409 */
  sim_icache_fetch(857 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1411 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1412 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1413 */
  sim_icache_fetch(860 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1415 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1416 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1417 */
  sim_icache_fetch(863 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1419 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1420 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1421 */
  sim_icache_fetch(866 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1423 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1424 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1425 */
  sim_icache_fetch(869 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1427 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1428 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1429 */
  sim_icache_fetch(872 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1431 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1432 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1433 */
  sim_icache_fetch(875 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1435 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1436 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1437 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1438 */
  sim_icache_fetch(879 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1440 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1441 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1442 */
  sim_icache_fetch(882 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1444 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1445 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1446 */
  sim_icache_fetch(885 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1448 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1449 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1450 */
  sim_icache_fetch(888 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1452 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1453 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1454 */
  sim_icache_fetch(891 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1456 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1457 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1458 */
  sim_icache_fetch(894 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1460 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1461 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1462 */
  sim_icache_fetch(897 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1464 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1465 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1466 */
  sim_icache_fetch(900 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1468 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1469 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1470 */
  sim_icache_fetch(903 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1472 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1473 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1474 */
  sim_icache_fetch(906 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1476 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1477 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1478 */
  sim_icache_fetch(909 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1480 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1481 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1482 */
  sim_icache_fetch(912 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1484 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1485 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1486 */
  sim_icache_fetch(915 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1488 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1489 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1490 */
  sim_icache_fetch(918 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1492 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1493 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1494 */
  sim_icache_fetch(921 + t_thisfile.offset, 1);
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
} /* line 1496 */
  sim_icache_fetch(922 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1498 */
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1499 */
l_L82X3: ;/* line 1502 */
__LABEL(l_L82X3);
  sim_icache_fetch(924 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1503 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1504 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1505 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1506 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1507 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 1508 */
l_L84X3: ;/* line 1511 */
__LABEL(l_L84X3);
  sim_icache_fetch(931 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1512 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1513 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1514 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1515 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1516 */
   __ADD_CYCLES(1);
} /* line 1516 */
  sim_icache_fetch(940 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1518 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1519 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 1); /* line 1520 */
} /* line 1520 */
  sim_icache_fetch(943 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1522 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1523 */
} /* line 1523 */
  sim_icache_fetch(946 + t_thisfile.offset, 1);
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
} /* line 1525 */
  sim_icache_fetch(947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1527 */
} /* line 1527 */
  sim_icache_fetch(949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1529 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1530 */
   __ADD_CYCLES(1);
} /* line 1530 */
  sim_icache_fetch(951 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1532 */
} /* line 1532 */
l_L86X3: ;/* line 1534 */
__LABEL(l_L86X3);
  sim_icache_fetch(952 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1535 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1536 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_8); /* line 1537 */
} /* line 1537 */
  sim_icache_fetch(955 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_9); /* line 1539 */
   __XOR(reg_r0_2, reg_r0_9, reg_r0_3); /* line 1540 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1541 */
  sim_icache_fetch(958 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1543 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1544 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1545 */
} /* line 1545 */
  sim_icache_fetch(964 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1547 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1548 */
   __ADD_CYCLES(1);
} /* line 1548 */
  sim_icache_fetch(966 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1550 */
} /* line 1550 */
  sim_icache_fetch(967 + t_thisfile.offset, 1);
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
} /* line 1552 */
  sim_icache_fetch(968 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_10,0,2)); /* line 1554 */
} /* line 1554 */
  sim_icache_fetch(969 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L84X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L84X3;
} /* line 1556 */
l_L88X3: ;/* line 1559 */
__LABEL(l_L88X3);
  sim_icache_fetch(970 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SH2ADD(reg_r0_7, reg_r0_2, (unsigned int) htab); /* line 1560 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1561 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1562 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1563 */
   __MOV(reg_r0_3, reg_r0_9); /* line 1564 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1565 */
} /* line 1565 */
  sim_icache_fetch(977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 1567 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1568 */
   __ADD_CYCLES(1);
} /* line 1568 */
  sim_icache_fetch(979 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1570 */
} /* line 1570 */
  sim_icache_fetch(980 + t_thisfile.offset, 1);
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
} /* line 1572 */
l_L90X3: ;/* line 1574 */
__LABEL(l_L90X3);
		 /* line 1574 */
  sim_icache_fetch(981 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (332 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1576 */
l_lr_122: ;/* line 1576 */
__LABEL(l_lr_122);
  sim_icache_fetch(983 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1578 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1579 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1580 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1581 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1582 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1583 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1584 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1585 */
   __ADD_CYCLES(1);
} /* line 1585 */
  sim_icache_fetch(994 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1587 */
   __MOV(reg_r0_9, reg_r0_6); /* line 1588 */
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_10); /* line 1589 */
   __ADD(reg_r0_11, reg_r0_7, (unsigned int) 1); /* line 1590 */
   __SH1ADD(reg_r0_12, reg_r0_2, (unsigned int) codetab); /* line 1591 */
   __SH2ADD(reg_r0_13, reg_r0_2, (unsigned int) htab); /* line 1592 */
} /* line 1592 */
  sim_icache_fetch(1002 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1594 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1595 */
  sim_icache_fetch(1005 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1597 */
   __STH(mem_trace_st(reg_r0_12,0,2), reg_r0_7); /* line 1598 */
   __STW(mem_trace_st(reg_r0_13,0,4), reg_r0_5); /* line 1599 */
   __GOTO(l_L84X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L84X3;
} /* line 1600 */
l_L91X3: ;/* line 1603 */
__LABEL(l_L91X3);
  sim_icache_fetch(1010 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1604 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1605 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1606 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 1607 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_9); /* line 1608 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1609 */
   __ADD_CYCLES(1);
} /* line 1609 */
  sim_icache_fetch(1019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1611 */
} /* line 1611 */
  sim_icache_fetch(1020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1613 */
} /* line 1613 */
  sim_icache_fetch(1021 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1615 */
		 /* line 1616 */
  sim_icache_fetch(1022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (332 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1618 */
l_lr_125: ;/* line 1618 */
__LABEL(l_lr_125);
  sim_icache_fetch(1024 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1620 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1621 */
} /* line 1621 */
  sim_icache_fetch(1026 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L84X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L84X3;
} /* line 1623 */
l_L92X3: ;/* line 1626 */
__LABEL(l_L92X3);
  sim_icache_fetch(1027 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1627 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1628 */
} /* line 1628 */
  sim_icache_fetch(1029 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L84X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L84X3;
} /* line 1630 */
l_L89X3: ;/* line 1633 */
__LABEL(l_L89X3);
  sim_icache_fetch(1030 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1634 */
   __MOV(reg_r0_11, reg_r0_9); /* line 1635 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1636 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1637 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1638 */
   __ADD_CYCLES(1);
} /* line 1638 */
  sim_icache_fetch(1035 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1640 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1641 */
} /* line 1641 */
  sim_icache_fetch(1037 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1643 */
} /* line 1643 */
l_L93X3: ;/* line 1646 */
__LABEL(l_L93X3);
  sim_icache_fetch(1038 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1647 */
} /* line 1647 */
  sim_icache_fetch(1039 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1649 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1650 */
} /* line 1650 */
  sim_icache_fetch(1041 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1652 */
} /* line 1652 */
  sim_icache_fetch(1042 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1654 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1655 */
} /* line 1655 */
  sim_icache_fetch(1045 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1657 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1658 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1659 */
} /* line 1659 */
  sim_icache_fetch(1048 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1661 */
} /* line 1661 */
  sim_icache_fetch(1049 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1663 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1664 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1665 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1666 */
} /* line 1666 */
  sim_icache_fetch(1054 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1668 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1669 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1670 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1671 */
  sim_icache_fetch(1058 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1673 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1674 */
  sim_icache_fetch(1060 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1676 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1677 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1678 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1679 */
} /* line 1679 */
  sim_icache_fetch(1065 + t_thisfile.offset, 4);
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
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1684 */
  sim_icache_fetch(1069 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1686 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1687 */
  sim_icache_fetch(1071 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1689 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1690 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1691 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1692 */
} /* line 1692 */
  sim_icache_fetch(1076 + t_thisfile.offset, 4);
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
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1697 */
  sim_icache_fetch(1080 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1699 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1700 */
  sim_icache_fetch(1082 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1702 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1703 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1704 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1705 */
} /* line 1705 */
  sim_icache_fetch(1087 + t_thisfile.offset, 4);
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
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1710 */
  sim_icache_fetch(1091 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1712 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1713 */
  sim_icache_fetch(1093 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1715 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1716 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1717 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(1098 + t_thisfile.offset, 4);
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
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1723 */
  sim_icache_fetch(1102 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1725 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1726 */
  sim_icache_fetch(1104 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1728 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1729 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1730 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1731 */
} /* line 1731 */
  sim_icache_fetch(1109 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1733 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1734 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1735 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1736 */
  sim_icache_fetch(1113 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1738 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1739 */
  sim_icache_fetch(1115 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1741 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1742 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1743 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1744 */
} /* line 1744 */
  sim_icache_fetch(1120 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1746 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1747 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1748 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1749 */
  sim_icache_fetch(1124 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1751 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1752 */
  sim_icache_fetch(1126 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1754 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1755 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1756 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(1131 + t_thisfile.offset, 4);
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
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1762 */
  sim_icache_fetch(1135 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1764 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1765 */
  sim_icache_fetch(1137 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1767 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1768 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1769 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1770 */
} /* line 1770 */
  sim_icache_fetch(1142 + t_thisfile.offset, 4);
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
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1775 */
  sim_icache_fetch(1146 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1777 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1778 */
  sim_icache_fetch(1148 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1780 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1781 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1782 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1783 */
} /* line 1783 */
  sim_icache_fetch(1153 + t_thisfile.offset, 4);
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
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1788 */
  sim_icache_fetch(1157 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1790 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1791 */
  sim_icache_fetch(1159 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1793 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1794 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1795 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1796 */
} /* line 1796 */
  sim_icache_fetch(1164 + t_thisfile.offset, 4);
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
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1801 */
  sim_icache_fetch(1168 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1803 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1804 */
  sim_icache_fetch(1170 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1806 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1807 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1808 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1809 */
} /* line 1809 */
  sim_icache_fetch(1175 + t_thisfile.offset, 4);
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
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1814 */
  sim_icache_fetch(1179 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1816 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1817 */
  sim_icache_fetch(1181 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1819 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1820 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1821 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1822 */
} /* line 1822 */
  sim_icache_fetch(1186 + t_thisfile.offset, 4);
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
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1827 */
  sim_icache_fetch(1190 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1829 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1830 */
  sim_icache_fetch(1192 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1832 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1833 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1834 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1835 */
} /* line 1835 */
  sim_icache_fetch(1197 + t_thisfile.offset, 4);
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
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1840 */
  sim_icache_fetch(1201 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1842 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1843 */
  sim_icache_fetch(1203 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1845 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1846 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1847 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1848 */
} /* line 1848 */
  sim_icache_fetch(1208 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1850 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1851 */
   __ADD(reg_r0_9, reg_r0_7, reg_r0_4); /* line 1852 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1853 */
  sim_icache_fetch(1212 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1855 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1856 */
  sim_icache_fetch(1214 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1858 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1859 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1860 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1861 */
} /* line 1861 */
  sim_icache_fetch(1219 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1863 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1864 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1865 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1866 */
  sim_icache_fetch(1223 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1868 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1869 */
  sim_icache_fetch(1225 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1871 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1872 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1873 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1874 */
} /* line 1874 */
  sim_icache_fetch(1230 + t_thisfile.offset, 4);
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
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1879 */
  sim_icache_fetch(1234 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1881 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1882 */
  sim_icache_fetch(1236 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1884 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1885 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1886 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1887 */
} /* line 1887 */
  sim_icache_fetch(1241 + t_thisfile.offset, 4);
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
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1892 */
  sim_icache_fetch(1245 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1894 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1895 */
  sim_icache_fetch(1247 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1897 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1898 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1899 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1900 */
} /* line 1900 */
  sim_icache_fetch(1252 + t_thisfile.offset, 4);
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
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1905 */
  sim_icache_fetch(1256 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1907 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1908 */
  sim_icache_fetch(1258 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1910 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1911 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1912 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1913 */
} /* line 1913 */
  sim_icache_fetch(1263 + t_thisfile.offset, 4);
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
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1918 */
  sim_icache_fetch(1267 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1920 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1921 */
  sim_icache_fetch(1269 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1923 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1924 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1925 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1926 */
} /* line 1926 */
  sim_icache_fetch(1274 + t_thisfile.offset, 4);
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
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1931 */
  sim_icache_fetch(1278 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1933 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1934 */
  sim_icache_fetch(1280 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1936 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1937 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1938 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1939 */
} /* line 1939 */
  sim_icache_fetch(1285 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1941 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1942 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1943 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1944 */
  sim_icache_fetch(1289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1946 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1947 */
  sim_icache_fetch(1291 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1949 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1950 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1951 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1952 */
} /* line 1952 */
  sim_icache_fetch(1296 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1954 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1955 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1956 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1957 */
  sim_icache_fetch(1300 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1959 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1960 */
  sim_icache_fetch(1302 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1962 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1963 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 1964 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 1965 */
} /* line 1965 */
  sim_icache_fetch(1307 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1967 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1968 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 1969 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1970 */
  sim_icache_fetch(1311 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 1972 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1973 */
  sim_icache_fetch(1313 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1975 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1976 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1977 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1978 */
} /* line 1978 */
  sim_icache_fetch(1318 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1980 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1981 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 1982 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1983 */
  sim_icache_fetch(1322 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 1985 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1986 */
  sim_icache_fetch(1324 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1988 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1989 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1990 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1991 */
} /* line 1991 */
  sim_icache_fetch(1329 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1993 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1994 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1995 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1996 */
  sim_icache_fetch(1333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1998 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1999 */
  sim_icache_fetch(1335 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2001 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2002 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 2003 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 2004 */
} /* line 2004 */
  sim_icache_fetch(1340 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2006 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2007 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 2008 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2009 */
  sim_icache_fetch(1344 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 2011 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L147X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2012 */
  sim_icache_fetch(1346 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2014 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2015 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2016 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2017 */
} /* line 2017 */
  sim_icache_fetch(1351 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2019 */
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2020 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_8); /* line 2021 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L148X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2022 */
  sim_icache_fetch(1355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_10); /* line 2024 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2025 */
  sim_icache_fetch(1357 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2027 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2028 */
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2029 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 2030 */
} /* line 2030 */
  sim_icache_fetch(1362 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2032 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 2033 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 2034 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2035 */
  sim_icache_fetch(1366 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 2037 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2038 */
  sim_icache_fetch(1368 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2040 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2041 */
   __SH2ADD(reg_r0_6, reg_r0_9, (unsigned int) htab); /* line 2042 */
   __SUB(reg_r0_7, reg_r0_9, reg_r0_3); /* line 2043 */
} /* line 2043 */
  sim_icache_fetch(1373 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2045 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2046 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_7); /* line 2047 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2048 */
  sim_icache_fetch(1377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_10); /* line 2050 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2051 */
  sim_icache_fetch(1379 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2053 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2054 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 2055 */
} /* line 2055 */
  sim_icache_fetch(1383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2057 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L154X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2058 */
  sim_icache_fetch(1385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L155X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2060 */
  sim_icache_fetch(1386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2062 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2063 */
} /* line 2063 */
  sim_icache_fetch(1388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L156X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2065 */
  sim_icache_fetch(1389 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L157X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2068 */
  sim_icache_fetch(1390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L93X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L93X3;
} /* line 2070 */
l_L157X3: ;/* line 2073 */
__LABEL(l_L157X3);
  sim_icache_fetch(1391 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2074 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2075 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2076 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2077 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2078 */
l_L156X3: ;/* line 2082 */
__LABEL(l_L156X3);
  sim_icache_fetch(1396 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2083 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2084 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2085 */
l_L155X3: ;/* line 2088 */
__LABEL(l_L155X3);
  sim_icache_fetch(1399 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2089 */
} /* line 2089 */
l_L123X3: ;/* line 2092 */
__LABEL(l_L123X3);
  sim_icache_fetch(1400 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2093 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2094 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2095 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2096 */
} /* line 2096 */
  sim_icache_fetch(1404 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2098 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2099 */
l_L154X3: ;/* line 2102 */
__LABEL(l_L154X3);
  sim_icache_fetch(1406 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2103 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2104 */
   __GOTO(l_L159X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L159X3;
} /* line 2105 */
l_L153X3: ;/* line 2108 */
__LABEL(l_L153X3);
  sim_icache_fetch(1409 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2109 */
} /* line 2109 */
l_L121X3: ;/* line 2112 */
__LABEL(l_L121X3);
  sim_icache_fetch(1410 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2113 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2114 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2115 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2116 */
} /* line 2116 */
  sim_icache_fetch(1414 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2118 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2119 */
l_L152X3: ;/* line 2122 */
__LABEL(l_L152X3);
  sim_icache_fetch(1416 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2123 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2124 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2125 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2126 */
l_L151X3: ;/* line 2129 */
__LABEL(l_L151X3);
  sim_icache_fetch(1420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2130 */
} /* line 2130 */
l_L119X3: ;/* line 2133 */
__LABEL(l_L119X3);
  sim_icache_fetch(1421 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2134 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2135 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2136 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2137 */
} /* line 2137 */
  sim_icache_fetch(1425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2139 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2140 */
l_L150X3: ;/* line 2143 */
__LABEL(l_L150X3);
  sim_icache_fetch(1427 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2144 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2145 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2146 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2147 */
l_L149X3: ;/* line 2150 */
__LABEL(l_L149X3);
  sim_icache_fetch(1431 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2151 */
} /* line 2151 */
l_L117X3: ;/* line 2154 */
__LABEL(l_L117X3);
  sim_icache_fetch(1432 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2155 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2156 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2157 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2158 */
} /* line 2158 */
  sim_icache_fetch(1436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2160 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2161 */
l_L148X3: ;/* line 2164 */
__LABEL(l_L148X3);
  sim_icache_fetch(1438 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2165 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2166 */
   __GOTO(l_L160X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L160X3;
} /* line 2167 */
l_L147X3: ;/* line 2170 */
__LABEL(l_L147X3);
  sim_icache_fetch(1441 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2171 */
} /* line 2171 */
l_L115X3: ;/* line 2174 */
__LABEL(l_L115X3);
  sim_icache_fetch(1442 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2175 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2176 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2177 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2178 */
} /* line 2178 */
  sim_icache_fetch(1446 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2180 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2181 */
l_L146X3: ;/* line 2184 */
__LABEL(l_L146X3);
  sim_icache_fetch(1448 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2185 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2186 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2187 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2188 */
l_L145X3: ;/* line 2191 */
__LABEL(l_L145X3);
  sim_icache_fetch(1452 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2192 */
} /* line 2192 */
l_L113X3: ;/* line 2195 */
__LABEL(l_L113X3);
  sim_icache_fetch(1453 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2196 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2197 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2198 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2199 */
} /* line 2199 */
  sim_icache_fetch(1457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2201 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2202 */
l_L144X3: ;/* line 2205 */
__LABEL(l_L144X3);
  sim_icache_fetch(1459 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2206 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2207 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2208 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2209 */
l_L143X3: ;/* line 2212 */
__LABEL(l_L143X3);
  sim_icache_fetch(1463 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2213 */
} /* line 2213 */
l_L111X3: ;/* line 2216 */
__LABEL(l_L111X3);
  sim_icache_fetch(1464 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2217 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2218 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2219 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2220 */
} /* line 2220 */
  sim_icache_fetch(1468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2222 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2223 */
l_L142X3: ;/* line 2226 */
__LABEL(l_L142X3);
  sim_icache_fetch(1470 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2227 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2228 */
   __GOTO(l_L161X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L161X3;
} /* line 2229 */
l_L141X3: ;/* line 2232 */
__LABEL(l_L141X3);
  sim_icache_fetch(1473 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2233 */
} /* line 2233 */
l_L109X3: ;/* line 2236 */
__LABEL(l_L109X3);
  sim_icache_fetch(1474 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2237 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2238 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2239 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2240 */
} /* line 2240 */
  sim_icache_fetch(1478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2242 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2243 */
l_L140X3: ;/* line 2246 */
__LABEL(l_L140X3);
  sim_icache_fetch(1480 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2247 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2248 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2249 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2250 */
l_L139X3: ;/* line 2253 */
__LABEL(l_L139X3);
  sim_icache_fetch(1484 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2254 */
} /* line 2254 */
l_L107X3: ;/* line 2257 */
__LABEL(l_L107X3);
  sim_icache_fetch(1485 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2258 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2259 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2260 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2261 */
} /* line 2261 */
  sim_icache_fetch(1489 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2263 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2264 */
l_L138X3: ;/* line 2267 */
__LABEL(l_L138X3);
  sim_icache_fetch(1491 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2268 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2269 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2270 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2271 */
l_L137X3: ;/* line 2274 */
__LABEL(l_L137X3);
  sim_icache_fetch(1495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2275 */
} /* line 2275 */
l_L105X3: ;/* line 2278 */
__LABEL(l_L105X3);
  sim_icache_fetch(1496 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2279 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2280 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2281 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2282 */
} /* line 2282 */
  sim_icache_fetch(1500 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2284 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2285 */
l_L136X3: ;/* line 2288 */
__LABEL(l_L136X3);
  sim_icache_fetch(1502 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2289 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2290 */
   __GOTO(l_L162X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L162X3;
} /* line 2291 */
l_L135X3: ;/* line 2294 */
__LABEL(l_L135X3);
  sim_icache_fetch(1505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2295 */
} /* line 2295 */
l_L103X3: ;/* line 2298 */
__LABEL(l_L103X3);
  sim_icache_fetch(1506 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2299 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2300 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2301 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2302 */
} /* line 2302 */
  sim_icache_fetch(1510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2304 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2305 */
l_L134X3: ;/* line 2308 */
__LABEL(l_L134X3);
  sim_icache_fetch(1512 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2309 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2310 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2311 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2312 */
l_L133X3: ;/* line 2315 */
__LABEL(l_L133X3);
  sim_icache_fetch(1516 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_9, reg_r0_7); /* line 2316 */
} /* line 2316 */
l_L101X3: ;/* line 2319 */
__LABEL(l_L101X3);
  sim_icache_fetch(1517 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2320 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2321 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2322 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2323 */
} /* line 2323 */
  sim_icache_fetch(1521 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2325 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2326 */
l_L132X3: ;/* line 2329 */
__LABEL(l_L132X3);
  sim_icache_fetch(1523 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2330 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2331 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2332 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2333 */
l_L131X3: ;/* line 2336 */
__LABEL(l_L131X3);
  sim_icache_fetch(1527 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_9); /* line 2337 */
} /* line 2337 */
l_L99X3: ;/* line 2340 */
__LABEL(l_L99X3);
  sim_icache_fetch(1528 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2341 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2342 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2343 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2344 */
} /* line 2344 */
  sim_icache_fetch(1532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2346 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2347 */
l_L130X3: ;/* line 2350 */
__LABEL(l_L130X3);
  sim_icache_fetch(1534 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, reg_r0_9); /* line 2351 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2352 */
   __GOTO(l_L163X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L163X3;
} /* line 2353 */
l_L129X3: ;/* line 2356 */
__LABEL(l_L129X3);
  sim_icache_fetch(1537 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2357 */
} /* line 2357 */
l_L97X3: ;/* line 2360 */
__LABEL(l_L97X3);
  sim_icache_fetch(1538 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2361 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2362 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2363 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2364 */
} /* line 2364 */
  sim_icache_fetch(1542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2366 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2367 */
l_L128X3: ;/* line 2370 */
__LABEL(l_L128X3);
  sim_icache_fetch(1544 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 2371 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2372 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2373 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2374 */
l_L127X3: ;/* line 2377 */
__LABEL(l_L127X3);
  sim_icache_fetch(1548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2378 */
} /* line 2378 */
l_L95X3: ;/* line 2382 */
__LABEL(l_L95X3);
  sim_icache_fetch(1549 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 2383 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2384 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2385 */
} /* line 2385 */
  sim_icache_fetch(1552 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2387 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2388 */
l_L126X3: ;/* line 2391 */
__LABEL(l_L126X3);
  sim_icache_fetch(1554 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2392 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2393 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2394 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2395 */
l_L125X3: ;/* line 2398 */
__LABEL(l_L125X3);
  sim_icache_fetch(1558 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2399 */
   __MOV(reg_r0_3, reg_r0_11); /* line 2400 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2401 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2402 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2403 */
l_L124X3: ;/* line 2407 */
__LABEL(l_L124X3);
  sim_icache_fetch(1563 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 2408 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2409 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2410 */
l_L122X3: ;/* line 2413 */
__LABEL(l_L122X3);
  sim_icache_fetch(1566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2414 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2415 */
} /* line 2415 */
l_L159X3: ;/* line 2417 */
__LABEL(l_L159X3);
  sim_icache_fetch(1568 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2418 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2419 */
l_L120X3: ;/* line 2422 */
__LABEL(l_L120X3);
  sim_icache_fetch(1570 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2423 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2424 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2425 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2426 */
l_L118X3: ;/* line 2429 */
__LABEL(l_L118X3);
  sim_icache_fetch(1574 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2430 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2431 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2432 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2433 */
l_L116X3: ;/* line 2436 */
__LABEL(l_L116X3);
  sim_icache_fetch(1578 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2437 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2438 */
} /* line 2438 */
l_L160X3: ;/* line 2440 */
__LABEL(l_L160X3);
  sim_icache_fetch(1580 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2441 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2442 */
l_L114X3: ;/* line 2445 */
__LABEL(l_L114X3);
  sim_icache_fetch(1582 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2446 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2447 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2448 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2449 */
l_L112X3: ;/* line 2452 */
__LABEL(l_L112X3);
  sim_icache_fetch(1586 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2453 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2454 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2455 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2456 */
l_L110X3: ;/* line 2459 */
__LABEL(l_L110X3);
  sim_icache_fetch(1590 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2460 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2461 */
} /* line 2461 */
l_L161X3: ;/* line 2463 */
__LABEL(l_L161X3);
  sim_icache_fetch(1592 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2464 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2465 */
l_L108X3: ;/* line 2468 */
__LABEL(l_L108X3);
  sim_icache_fetch(1594 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2469 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2470 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2471 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2472 */
l_L106X3: ;/* line 2475 */
__LABEL(l_L106X3);
  sim_icache_fetch(1598 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2476 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2477 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2478 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2479 */
l_L104X3: ;/* line 2482 */
__LABEL(l_L104X3);
  sim_icache_fetch(1602 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2483 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2484 */
} /* line 2484 */
l_L162X3: ;/* line 2486 */
__LABEL(l_L162X3);
  sim_icache_fetch(1604 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2487 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2488 */
l_L102X3: ;/* line 2491 */
__LABEL(l_L102X3);
  sim_icache_fetch(1606 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2492 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2493 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2494 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2495 */
l_L100X3: ;/* line 2498 */
__LABEL(l_L100X3);
  sim_icache_fetch(1610 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_9); /* line 2499 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2500 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2501 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2502 */
l_L98X3: ;/* line 2505 */
__LABEL(l_L98X3);
  sim_icache_fetch(1614 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2506 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2507 */
} /* line 2507 */
l_L163X3: ;/* line 2509 */
__LABEL(l_L163X3);
  sim_icache_fetch(1616 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2510 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2511 */
l_L96X3: ;/* line 2514 */
__LABEL(l_L96X3);
  sim_icache_fetch(1618 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 2515 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2516 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2517 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 2518 */
l_L94X3: ;/* line 2522 */
__LABEL(l_L94X3);
  sim_icache_fetch(1622 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2523 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2524 */
} /* line 2524 */
l_L158X3: ;/* line 2526 */
__LABEL(l_L158X3);
  sim_icache_fetch(1624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2527 */
} /* line 2527 */
  sim_icache_fetch(1626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_9, mem_trace_ld(reg_r0_2,0,2)); /* line 2529 */
} /* line 2529 */
  sim_icache_fetch(1627 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L84X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L84X3;
} /* line 2531 */
l_L87X3: ;/* line 2534 */
__LABEL(l_L87X3);
		 /* line 2534 */
  sim_icache_fetch(1628 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_9); /* line 2537 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (332 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2537 */
l_lr_201: ;/* line 2537 */
__LABEL(l_lr_201);
  sim_icache_fetch(1631 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2539 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2540 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2541 */
   __ADD_CYCLES(1);
} /* line 2541 */
  sim_icache_fetch(1635 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2543 */
} /* line 2543 */
		 /* line 2544 */
  sim_icache_fetch(1636 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2546 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (332 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2547 */
l_lr_203: ;/* line 2547 */
__LABEL(l_lr_203);
  sim_icache_fetch(1640 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2549 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2550 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2551 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2552 */
   __MOV(reg_r0_3, 0); /* line 2553 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2554 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2555 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2556 */
   __ADD_CYCLES(1);
} /* line 2556 */
  sim_icache_fetch(1652 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2558 */
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2559 */
} /* line 2559 */
  sim_icache_fetch(1654 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L164X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2561 */
l_L165X3: ;/* line 2563 */
__LABEL(l_L165X3);
  sim_icache_fetch(1655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L166X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2564 */
  sim_icache_fetch(1656 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2566 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2567 */
} /* line 2567 */
l_L167X3: ;/* line 2569 */
__LABEL(l_L167X3);
  sim_icache_fetch(1659 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2571 */
l_L166X3: ;/* line 2574 */
__LABEL(l_L166X3);
  sim_icache_fetch(1660 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2575 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2576 */
   __GOTO(l_L167X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L167X3;
} /* line 2577 */
l_L164X3: ;/* line 2580 */
__LABEL(l_L164X3);
  sim_icache_fetch(1663 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2581 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2582 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2583 */
   __ADD_CYCLES(1);
} /* line 2583 */
		 /* line 2584 */
  sim_icache_fetch(1668 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2586 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (332 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2587 */
l_lr_209: ;/* line 2587 */
__LABEL(l_lr_209);
  sim_icache_fetch(1671 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2589 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2590 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2591 */
   __MOV(reg_r0_3, 0); /* line 2592 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2593 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2594 */
   __ADD_CYCLES(1);
} /* line 2594 */
  sim_icache_fetch(1679 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_6, reg_r0_7); /* line 2596 */
   __GOTO(l_L165X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L165X3;
} /* line 2597 */
l_L85X3: ;/* line 2600 */
__LABEL(l_L85X3);
  sim_icache_fetch(1681 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2601 */
   __GOTO(l_L86X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L86X3;
} /* line 2602 */
l_L81X3: ;/* line 2605 */
__LABEL(l_L81X3);
  sim_icache_fetch(1683 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2606 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2607 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2608 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2609 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2610 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2611 */
l_L80X3: ;/* line 2614 */
__LABEL(l_L80X3);
  sim_icache_fetch(1690 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2615 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2616 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2617 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2618 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2619 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2620 */
l_L79X3: ;/* line 2623 */
__LABEL(l_L79X3);
  sim_icache_fetch(1697 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2624 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2625 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2626 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2627 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2628 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2629 */
l_L78X3: ;/* line 2632 */
__LABEL(l_L78X3);
  sim_icache_fetch(1704 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2633 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2634 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2635 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2636 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2637 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2638 */
l_L77X3: ;/* line 2641 */
__LABEL(l_L77X3);
  sim_icache_fetch(1711 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2642 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2643 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2644 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2645 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2646 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2647 */
l_L76X3: ;/* line 2650 */
__LABEL(l_L76X3);
  sim_icache_fetch(1718 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2651 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2652 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2653 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2654 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2655 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2656 */
l_L75X3: ;/* line 2659 */
__LABEL(l_L75X3);
  sim_icache_fetch(1725 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2660 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2661 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2662 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2663 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2664 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2665 */
l_L74X3: ;/* line 2668 */
__LABEL(l_L74X3);
  sim_icache_fetch(1732 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2669 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2670 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2671 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2672 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2673 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2674 */
l_L73X3: ;/* line 2677 */
__LABEL(l_L73X3);
  sim_icache_fetch(1739 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2678 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2679 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2680 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2681 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2682 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2683 */
l_L72X3: ;/* line 2686 */
__LABEL(l_L72X3);
  sim_icache_fetch(1746 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2687 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2688 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2689 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2690 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2691 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2692 */
l_L71X3: ;/* line 2695 */
__LABEL(l_L71X3);
  sim_icache_fetch(1753 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2696 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2697 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2698 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2699 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2700 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2701 */
l_L70X3: ;/* line 2704 */
__LABEL(l_L70X3);
  sim_icache_fetch(1760 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2705 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2706 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2707 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2708 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2709 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2710 */
l_L69X3: ;/* line 2713 */
__LABEL(l_L69X3);
  sim_icache_fetch(1767 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2714 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2715 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2716 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2717 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2718 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2719 */
l_L68X3: ;/* line 2722 */
__LABEL(l_L68X3);
  sim_icache_fetch(1774 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2723 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2724 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2725 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2726 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2727 */
   __GOTO(l_L83X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L83X3;
} /* line 2728 */
l_L67X3: ;/* line 2732 */
__LABEL(l_L67X3);
  sim_icache_fetch(1781 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2733 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2734 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2735 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2736 */
} /* line 2736 */
l_L83X3: ;/* line 2738 */
__LABEL(l_L83X3);
  sim_icache_fetch(1786 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_4); /* line 2739 */
} /* line 2739 */
		 /* line 2740 */
  sim_icache_fetch(1787 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2743 */
   __MOV(reg_r0_3, reg_r0_2); /* line 2744 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_8); /* line 2745 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (332 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2745 */
l_lr_228: ;/* line 2745 */
__LABEL(l_lr_228);
  sim_icache_fetch(1792 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2747 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2748 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2749 */
} /* line 2749 */
  sim_icache_fetch(1795 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L84X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L84X3;
} /* line 2751 */
l_L64X3: ;/* line 2754 */
__LABEL(l_L64X3);
  sim_icache_fetch(1796 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) -1); /* line 2755 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2756 */
l_L62X3: ;/* line 2759 */
__LABEL(l_L62X3);
  sim_icache_fetch(1798 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_16, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2760 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2761 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2762 */
   __MOV(reg_r0_9, (unsigned int) 9); /* line 2763 */
   __MOV(reg_r0_17, (unsigned int) 257); /* line 2764 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2765 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2766 */
   __ADD_CYCLES(1);
} /* line 2766 */
  sim_icache_fetch(1808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2768 */
} /* line 2768 */
  sim_icache_fetch(1809 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2770 */
} /* line 2770 */
  sim_icache_fetch(1811 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2772 */
} /* line 2772 */
  sim_icache_fetch(1812 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2774 */
   __LDBU(reg_r0_16, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2775 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2776 */
   __ADD_CYCLES(1);
} /* line 2776 */
  sim_icache_fetch(1817 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_11, (unsigned int) 1); /* line 2778 */
} /* line 2778 */
  sim_icache_fetch(1818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_18); /* line 2780 */
} /* line 2780 */
  sim_icache_fetch(1820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2782 */
} /* line 2782 */
  sim_icache_fetch(1821 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2784 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2785 */
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2786 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2787 */
   __ADD_CYCLES(1);
} /* line 2787 */
  sim_icache_fetch(1828 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_11, (unsigned int) 1); /* line 2789 */
   __OR(reg_r0_16, reg_r0_16, reg_r0_18); /* line 2790 */
} /* line 2790 */
  sim_icache_fetch(1830 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_19); /* line 2792 */
} /* line 2792 */
  sim_icache_fetch(1832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_11,0,1), reg_r0_16); /* line 2794 */
} /* line 2794 */
  sim_icache_fetch(1833 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2796 */
   __LDW(reg_r0_16, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2797 */
   __LDWs(reg_r0_14, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2798 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2799 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2800 */
   __ADD_CYCLES(1);
} /* line 2800 */
  sim_icache_fetch(1842 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_1, reg_r0_11, 0); /* line 2802 */
   __ADD(reg_r0_13, reg_r0_16, (unsigned int) -1); /* line 2803 */
   __ADD(reg_r0_15, reg_r0_14, (unsigned int) 1); /* line 2804 */
} /* line 2804 */
  sim_icache_fetch(1845 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_17, (unsigned int) 256); /* line 2806 */
   __CMPGE(reg_b0_0, reg_r0_13, 0); /* line 2807 */
   __GOTO(l_L63X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L63X3;
} /* line 2808 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 214: goto l_L63X3;
    case 215: goto l_L65X3;
    case 216: goto l_L66X3;
    case 217: goto l_L82X3;
    case 218: goto l_L84X3;
    case 219: goto l_L86X3;
    case 220: goto l_L88X3;
    case 221: goto l_L90X3;
    case 223: goto l_lr_122;
    case 224: goto l_L91X3;
    case 226: goto l_lr_125;
    case 227: goto l_L92X3;
    case 228: goto l_L89X3;
    case 229: goto l_L93X3;
    case 230: goto l_L157X3;
    case 231: goto l_L156X3;
    case 232: goto l_L155X3;
    case 233: goto l_L123X3;
    case 234: goto l_L154X3;
    case 235: goto l_L153X3;
    case 236: goto l_L121X3;
    case 237: goto l_L152X3;
    case 238: goto l_L151X3;
    case 239: goto l_L119X3;
    case 240: goto l_L150X3;
    case 241: goto l_L149X3;
    case 242: goto l_L117X3;
    case 243: goto l_L148X3;
    case 244: goto l_L147X3;
    case 245: goto l_L115X3;
    case 246: goto l_L146X3;
    case 247: goto l_L145X3;
    case 248: goto l_L113X3;
    case 249: goto l_L144X3;
    case 250: goto l_L143X3;
    case 251: goto l_L111X3;
    case 252: goto l_L142X3;
    case 253: goto l_L141X3;
    case 254: goto l_L109X3;
    case 255: goto l_L140X3;
    case 256: goto l_L139X3;
    case 257: goto l_L107X3;
    case 258: goto l_L138X3;
    case 259: goto l_L137X3;
    case 260: goto l_L105X3;
    case 261: goto l_L136X3;
    case 262: goto l_L135X3;
    case 263: goto l_L103X3;
    case 264: goto l_L134X3;
    case 265: goto l_L133X3;
    case 266: goto l_L101X3;
    case 267: goto l_L132X3;
    case 268: goto l_L131X3;
    case 269: goto l_L99X3;
    case 270: goto l_L130X3;
    case 271: goto l_L129X3;
    case 272: goto l_L97X3;
    case 273: goto l_L128X3;
    case 274: goto l_L127X3;
    case 275: goto l_L95X3;
    case 276: goto l_L126X3;
    case 277: goto l_L125X3;
    case 278: goto l_L124X3;
    case 279: goto l_L122X3;
    case 280: goto l_L159X3;
    case 281: goto l_L120X3;
    case 282: goto l_L118X3;
    case 283: goto l_L116X3;
    case 284: goto l_L160X3;
    case 285: goto l_L114X3;
    case 286: goto l_L112X3;
    case 287: goto l_L110X3;
    case 288: goto l_L161X3;
    case 289: goto l_L108X3;
    case 290: goto l_L106X3;
    case 291: goto l_L104X3;
    case 292: goto l_L162X3;
    case 293: goto l_L102X3;
    case 294: goto l_L100X3;
    case 295: goto l_L98X3;
    case 296: goto l_L163X3;
    case 297: goto l_L96X3;
    case 298: goto l_L94X3;
    case 299: goto l_L158X3;
    case 300: goto l_L87X3;
    case 302: goto l_lr_201;
    case 304: goto l_lr_203;
    case 305: goto l_L165X3;
    case 306: goto l_L167X3;
    case 307: goto l_L166X3;
    case 308: goto l_L164X3;
    case 310: goto l_lr_209;
    case 311: goto l_L85X3;
    case 312: goto l_L81X3;
    case 313: goto l_L80X3;
    case 314: goto l_L79X3;
    case 315: goto l_L78X3;
    case 316: goto l_L77X3;
    case 317: goto l_L76X3;
    case 318: goto l_L75X3;
    case 319: goto l_L74X3;
    case 320: goto l_L73X3;
    case 321: goto l_L72X3;
    case 322: goto l_L71X3;
    case 323: goto l_L70X3;
    case 324: goto l_L69X3;
    case 325: goto l_L68X3;
    case 326: goto l_L67X3;
    case 327: goto l_L83X3;
    case 329: goto l_lr_228;
    case 330: goto l_L64X3;
    case 331: goto l_L62X3;
    case 332:
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
  reg_l0_0 = (364 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1849 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 2827 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2828 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2829 */
} /* line 2829 */
  sim_icache_fetch(1854 + t_thisfile.offset, 1);
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
} /* line 2831 */
  sim_icache_fetch(1855 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2833 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2834 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2835 */
} /* line 2835 */
  sim_icache_fetch(1858 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_13457Xbuf); /* line 2837 */
   __LDB(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_13457Xbuf),0,1)); /* line 2838 */
   __ADD(reg_r0_13, reg_r0_7, ((unsigned int) compress_13457Xbuf + (unsigned int) 1)); /* line 2839 */
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2840 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2841 */
   __LDBU(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2842 */
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_6); /* line 2843 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2844 */
} /* line 2844 */
  sim_icache_fetch(1871 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2846 */
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2847 */
} /* line 2847 */
  sim_icache_fetch(1873 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2849 */
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2850 */
   __MOV(reg_r0_6, reg_r0_3); /* line 2851 */
} /* line 2851 */
  sim_icache_fetch(1876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2853 */
} /* line 2853 */
  sim_icache_fetch(1877 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_13457Xbuf),0,1), reg_r0_2); /* line 2855 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L169X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2856 */
  sim_icache_fetch(1880 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 2858 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 2); /* line 2859 */
   __SHR(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 2860 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2861 */
} /* line 2861 */
l_L169X3: ;/* line 2863 */
__LABEL(l_L169X3);
  sim_icache_fetch(1884 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2864 */
   __MOV(reg_r0_3, (unsigned int) compress_13457Xbuf); /* line 2865 */
} /* line 2865 */
  sim_icache_fetch(1887 + t_thisfile.offset, 1);
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
} /* line 2867 */
  sim_icache_fetch(1888 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_13,0,1), reg_r0_6); /* line 2869 */
} /* line 2869 */
l_L170X3: ;/* line 2871 */
__LABEL(l_L170X3);
  sim_icache_fetch(1889 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 2872 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2873 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2874 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2875 */
   __ADD_CYCLES(1);
} /* line 2875 */
  sim_icache_fetch(1896 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2877 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2878 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2879 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2880 */
} /* line 2880 */
  sim_icache_fetch(1900 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_13457Xoffset,0,4), reg_r0_2); /* line 2882 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2883 */
} /* line 2883 */
  sim_icache_fetch(1903 + t_thisfile.offset, 1);
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
} /* line 2885 */
  sim_icache_fetch(1904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2887 */
} /* line 2887 */
l_L172X3: ;/* line 2890 */
__LABEL(l_L172X3);
  sim_icache_fetch(1906 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2891 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2892 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2893 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2894 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2895 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2896 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2897 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2898 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2899 */
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2900 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -16); /* line 2901 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 16); /* line 2902 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2903 */
   __ADD_CYCLES(1);
} /* line 2903 */
  sim_icache_fetch(1920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2905 */
} /* line 2905 */
  sim_icache_fetch(1921 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2907 */
} /* line 2907 */
  sim_icache_fetch(1923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2909 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2910 */
  sim_icache_fetch(1925 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2912 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2913 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2914 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2915 */
   __ADD_CYCLES(1);
} /* line 2915 */
  sim_icache_fetch(1930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2917 */
} /* line 2917 */
  sim_icache_fetch(1931 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2919 */
} /* line 2919 */
  sim_icache_fetch(1933 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2921 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2922 */
  sim_icache_fetch(1935 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2924 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2925 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2926 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2927 */
   __ADD_CYCLES(1);
} /* line 2927 */
  sim_icache_fetch(1940 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2929 */
} /* line 2929 */
  sim_icache_fetch(1941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2931 */
} /* line 2931 */
  sim_icache_fetch(1943 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2933 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2934 */
  sim_icache_fetch(1945 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2936 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2937 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2938 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2939 */
   __ADD_CYCLES(1);
} /* line 2939 */
  sim_icache_fetch(1950 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2941 */
} /* line 2941 */
  sim_icache_fetch(1951 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2943 */
} /* line 2943 */
  sim_icache_fetch(1953 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2945 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2946 */
  sim_icache_fetch(1955 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2948 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2949 */
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2950 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2951 */
   __ADD_CYCLES(1);
} /* line 2951 */
  sim_icache_fetch(1960 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2953 */
} /* line 2953 */
  sim_icache_fetch(1961 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2955 */
} /* line 2955 */
  sim_icache_fetch(1963 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2957 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2958 */
  sim_icache_fetch(1965 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2960 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2961 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2962 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2963 */
   __ADD_CYCLES(1);
} /* line 2963 */
  sim_icache_fetch(1970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2965 */
} /* line 2965 */
  sim_icache_fetch(1971 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2967 */
} /* line 2967 */
  sim_icache_fetch(1973 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2969 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2970 */
  sim_icache_fetch(1975 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 2972 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2973 */
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 2974 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2975 */
   __ADD_CYCLES(1);
} /* line 2975 */
  sim_icache_fetch(1980 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2977 */
} /* line 2977 */
  sim_icache_fetch(1981 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2979 */
} /* line 2979 */
  sim_icache_fetch(1983 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2981 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2982 */
  sim_icache_fetch(1985 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 2984 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2985 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 2986 */
   __ADD(reg_r0_5, reg_r0_7, (unsigned int) -16); /* line 2987 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2988 */
   __ADD_CYCLES(1);
} /* line 2988 */
  sim_icache_fetch(1991 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2990 */
} /* line 2990 */
  sim_icache_fetch(1992 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2992 */
} /* line 2992 */
  sim_icache_fetch(1994 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2994 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2995 */
  sim_icache_fetch(1996 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 2997 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2998 */
   __CMPEQ(reg_b0_7, reg_r0_7, 0); /* line 2999 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3000 */
   __ADD_CYCLES(1);
} /* line 3000 */
  sim_icache_fetch(2001 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3002 */
} /* line 3002 */
  sim_icache_fetch(2002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3004 */
} /* line 3004 */
  sim_icache_fetch(2004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3006 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3007 */
  sim_icache_fetch(2006 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 3009 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3010 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 3011 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3012 */
   __ADD_CYCLES(1);
} /* line 3012 */
  sim_icache_fetch(2011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3014 */
} /* line 3014 */
  sim_icache_fetch(2012 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3016 */
} /* line 3016 */
  sim_icache_fetch(2014 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3018 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3019 */
  sim_icache_fetch(2016 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 3021 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3022 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 3023 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3024 */
   __ADD_CYCLES(1);
} /* line 3024 */
  sim_icache_fetch(2021 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3026 */
} /* line 3026 */
  sim_icache_fetch(2022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3028 */
} /* line 3028 */
  sim_icache_fetch(2024 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3030 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3031 */
  sim_icache_fetch(2026 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 3033 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3034 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 3035 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3036 */
   __ADD_CYCLES(1);
} /* line 3036 */
  sim_icache_fetch(2031 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3038 */
} /* line 3038 */
  sim_icache_fetch(2032 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3040 */
} /* line 3040 */
  sim_icache_fetch(2034 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3042 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3043 */
  sim_icache_fetch(2036 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 3045 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3046 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 4); /* line 3047 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3048 */
   __ADD_CYCLES(1);
} /* line 3048 */
  sim_icache_fetch(2041 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3050 */
} /* line 3050 */
  sim_icache_fetch(2042 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3052 */
} /* line 3052 */
  sim_icache_fetch(2044 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3054 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3055 */
  sim_icache_fetch(2046 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 3057 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3058 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 5); /* line 3059 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3060 */
   __ADD_CYCLES(1);
} /* line 3060 */
  sim_icache_fetch(2051 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3062 */
} /* line 3062 */
  sim_icache_fetch(2052 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3064 */
} /* line 3064 */
  sim_icache_fetch(2054 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3066 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3067 */
  sim_icache_fetch(2056 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 3069 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3070 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 6); /* line 3071 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3072 */
   __ADD_CYCLES(1);
} /* line 3072 */
  sim_icache_fetch(2061 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 3074 */
} /* line 3074 */
  sim_icache_fetch(2062 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 3076 */
} /* line 3076 */
  sim_icache_fetch(2064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3078 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3079 */
  sim_icache_fetch(2066 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 3081 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3082 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 7); /* line 3083 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3084 */
   __ADD_CYCLES(1);
} /* line 3084 */
  sim_icache_fetch(2071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3086 */
} /* line 3086 */
  sim_icache_fetch(2072 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3088 */
} /* line 3088 */
  sim_icache_fetch(2074 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3090 */
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3091 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3092 */
  sim_icache_fetch(2077 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 3094 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3095 */
   __CMPEQ(reg_b0_7, reg_r0_7, (unsigned int) 8); /* line 3096 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) 16); /* line 3097 */
   __MFB(reg_r0_8, t__i32_0); /* line 3098 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3099 */
   __ADD_CYCLES(1);
} /* line 3099 */
  sim_icache_fetch(2084 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3101 */
} /* line 3101 */
  sim_icache_fetch(2085 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3103 */
} /* line 3103 */
  sim_icache_fetch(2087 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3105 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3106 */
  sim_icache_fetch(2089 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 3108 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3109 */
   __CMPEQ(reg_b0_0, reg_r0_7, (unsigned int) 9); /* line 3110 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3111 */
   __ADD_CYCLES(1);
} /* line 3111 */
  sim_icache_fetch(2094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3113 */
} /* line 3113 */
  sim_icache_fetch(2095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3115 */
} /* line 3115 */
  sim_icache_fetch(2097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3117 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3118 */
  sim_icache_fetch(2099 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 2),0,1)); /* line 3120 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3121 */
   __CMPEQ(reg_b0_1, reg_r0_7, (unsigned int) 10); /* line 3122 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3123 */
   __ADD_CYCLES(1);
} /* line 3123 */
  sim_icache_fetch(2104 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3125 */
} /* line 3125 */
  sim_icache_fetch(2105 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3127 */
} /* line 3127 */
  sim_icache_fetch(2107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3129 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3130 */
  sim_icache_fetch(2109 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 3),0,1)); /* line 3132 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3133 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 11); /* line 3134 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3135 */
   __ADD_CYCLES(1);
} /* line 3135 */
  sim_icache_fetch(2114 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3137 */
} /* line 3137 */
  sim_icache_fetch(2115 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3139 */
} /* line 3139 */
  sim_icache_fetch(2117 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3141 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3142 */
  sim_icache_fetch(2119 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 4),0,1)); /* line 3144 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3145 */
   __CMPEQ(reg_b0_3, reg_r0_7, (unsigned int) 12); /* line 3146 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3147 */
   __ADD_CYCLES(1);
} /* line 3147 */
  sim_icache_fetch(2124 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3149 */
} /* line 3149 */
  sim_icache_fetch(2125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3151 */
} /* line 3151 */
  sim_icache_fetch(2127 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3153 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3154 */
  sim_icache_fetch(2129 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 5),0,1)); /* line 3156 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3157 */
   __CMPEQ(reg_b0_4, reg_r0_7, (unsigned int) 13); /* line 3158 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3159 */
   __ADD_CYCLES(1);
} /* line 3159 */
  sim_icache_fetch(2134 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3161 */
} /* line 3161 */
  sim_icache_fetch(2135 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3163 */
} /* line 3163 */
  sim_icache_fetch(2137 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3165 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3166 */
  sim_icache_fetch(2139 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 6),0,1)); /* line 3168 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3169 */
   __CMPEQ(reg_b0_5, reg_r0_7, (unsigned int) 14); /* line 3170 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3171 */
   __ADD_CYCLES(1);
} /* line 3171 */
  sim_icache_fetch(2144 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 1); /* line 3173 */
} /* line 3173 */
  sim_icache_fetch(2145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_9); /* line 3175 */
} /* line 3175 */
  sim_icache_fetch(2147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3177 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3178 */
  sim_icache_fetch(2149 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 7),0,1)); /* line 3180 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3181 */
   __CMPEQ(reg_b0_6, reg_r0_7, (unsigned int) 15); /* line 3182 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3183 */
   __ADD_CYCLES(1);
} /* line 3183 */
  sim_icache_fetch(2154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3185 */
} /* line 3185 */
  sim_icache_fetch(2155 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3187 */
} /* line 3187 */
  sim_icache_fetch(2157 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3189 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3190 */
  sim_icache_fetch(2159 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 8),0,1)); /* line 3192 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3193 */
   __MTB(reg_b0_7, reg_r0_8); /* line 3194 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3195 */
   __ADD_CYCLES(1);
} /* line 3195 */
  sim_icache_fetch(2164 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3197 */
} /* line 3197 */
  sim_icache_fetch(2165 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3199 */
} /* line 3199 */
  sim_icache_fetch(2167 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3201 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3202 */
  sim_icache_fetch(2169 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 9),0,1)); /* line 3204 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3205 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3206 */
   __ADD_CYCLES(1);
} /* line 3206 */
  sim_icache_fetch(2173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3208 */
} /* line 3208 */
  sim_icache_fetch(2174 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3210 */
} /* line 3210 */
  sim_icache_fetch(2176 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3212 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3213 */
  sim_icache_fetch(2178 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 10),0,1)); /* line 3215 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3216 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3217 */
   __ADD_CYCLES(1);
} /* line 3217 */
  sim_icache_fetch(2182 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3219 */
} /* line 3219 */
  sim_icache_fetch(2183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3221 */
} /* line 3221 */
  sim_icache_fetch(2185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3223 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3224 */
  sim_icache_fetch(2187 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 11),0,1)); /* line 3226 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3227 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3228 */
   __ADD_CYCLES(1);
} /* line 3228 */
  sim_icache_fetch(2191 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3230 */
} /* line 3230 */
  sim_icache_fetch(2192 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3232 */
} /* line 3232 */
  sim_icache_fetch(2194 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3234 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3235 */
  sim_icache_fetch(2196 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 12),0,1)); /* line 3237 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3238 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3239 */
   __ADD_CYCLES(1);
} /* line 3239 */
  sim_icache_fetch(2200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3241 */
} /* line 3241 */
  sim_icache_fetch(2201 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3243 */
} /* line 3243 */
  sim_icache_fetch(2203 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3245 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3246 */
  sim_icache_fetch(2205 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 13),0,1)); /* line 3248 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3249 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3250 */
   __ADD_CYCLES(1);
} /* line 3250 */
  sim_icache_fetch(2209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3252 */
} /* line 3252 */
  sim_icache_fetch(2210 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3254 */
} /* line 3254 */
  sim_icache_fetch(2212 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3256 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3257 */
  sim_icache_fetch(2214 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_6 + (unsigned int) 14),0,1)); /* line 3259 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3260 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3261 */
   __ADD_CYCLES(1);
} /* line 3261 */
  sim_icache_fetch(2218 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_2, (unsigned int) 1); /* line 3263 */
} /* line 3263 */
  sim_icache_fetch(2219 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_7); /* line 3265 */
} /* line 3265 */
  sim_icache_fetch(2221 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3267 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3268 */
  sim_icache_fetch(2223 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 15),0,1)); /* line 3270 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3271 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3272 */
   __ADD_CYCLES(1);
} /* line 3272 */
  sim_icache_fetch(2227 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3274 */
} /* line 3274 */
  sim_icache_fetch(2228 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3276 */
} /* line 3276 */
  sim_icache_fetch(2230 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 3278 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L173X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3280 */
  sim_icache_fetch(2232 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L172X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L172X3;
} /* line 3282 */
l_L173X3: ;/* line 3285 */
__LABEL(l_L173X3);
  sim_icache_fetch(2233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_13457Xoffset,0,4), 0); /* line 3286 */
} /* line 3286 */
l_L171X3: ;/* line 3289 */
__LABEL(l_L171X3);
  sim_icache_fetch(2235 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3290 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3291 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3292 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 3293 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3294 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3295 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3296 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3297 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3298 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3299 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3300 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3301 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3302 */
} /* line 3302 */
  sim_icache_fetch(2252 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3304 */
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3305 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3306 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3307 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3308 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3309 */
   __MOV(reg_r0_5, (unsigned int) compress_13457Xbuf); /* line 3310 */
   __MOV(reg_r0_3, 0); /* line 3311 */
} /* line 3311 */
  sim_icache_fetch(2261 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3313 */
   __CMPGT(reg_r0_6, reg_r0_6, 0); /* line 3314 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3315 */
} /* line 3315 */
  sim_icache_fetch(2264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_6); /* line 3317 */
} /* line 3317 */
  sim_icache_fetch(2265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L174X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3319 */
  sim_icache_fetch(2266 + t_thisfile.offset, 1);
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
} /* line 3321 */
l_L176X3: ;/* line 3324 */
__LABEL(l_L176X3);
  sim_icache_fetch(2267 + t_thisfile.offset, 15);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3325 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3326 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3327 */
   __ADD(reg_r0_22, reg_r0_7, (unsigned int) 16); /* line 3328 */
   __ADD(reg_r0_23, reg_r0_20, (unsigned int) 16); /* line 3329 */
   __ADD(reg_r0_24, reg_r0_19, (unsigned int) 16); /* line 3330 */
   __ADD(reg_r0_25, reg_r0_18, (unsigned int) 16); /* line 3331 */
   __ADD(reg_r0_26, reg_r0_17, (unsigned int) 16); /* line 3332 */
   __ADD(reg_r0_27, reg_r0_16, (unsigned int) 16); /* line 3333 */
   __ADD(reg_r0_28, reg_r0_15, (unsigned int) 16); /* line 3334 */
   __ADD(reg_r0_29, reg_r0_14, (unsigned int) 16); /* line 3335 */
   __ADD(reg_r0_30, reg_r0_13, (unsigned int) 16); /* line 3336 */
   __ADD(reg_r0_31, reg_r0_12, (unsigned int) 16); /* line 3337 */
} /* line 3337 */
  sim_icache_fetch(2282 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_32, reg_r0_11, (unsigned int) 16); /* line 3339 */
   __ADD(reg_r0_33, reg_r0_10, (unsigned int) 16); /* line 3340 */
   __ADD(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 3341 */
   __ADD(reg_r0_35, reg_r0_8, (unsigned int) 16); /* line 3342 */
   __ADD(reg_r0_36, reg_r0_21, (unsigned int) 16); /* line 3343 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3344 */
   __ADD(reg_r0_38, reg_r0_3, (unsigned int) 16); /* line 3345 */
} /* line 3345 */
  sim_icache_fetch(2289 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3347 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3348 */
   __ADD(reg_r0_3, reg_r0_38, (unsigned int) 16); /* line 3349 */
} /* line 3349 */
  sim_icache_fetch(2292 + t_thisfile.offset, 1);
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
} /* line 3351 */
  sim_icache_fetch(2293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3353 */
} /* line 3353 */
  sim_icache_fetch(2295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3355 */
} /* line 3355 */
  sim_icache_fetch(2296 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3357 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3358 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3359 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3360 */
   __ADD_CYCLES(1);
} /* line 3360 */
  sim_icache_fetch(2302 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 3362 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3363 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 16); /* line 3364 */
} /* line 3364 */
  sim_icache_fetch(2305 + t_thisfile.offset, 1);
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
} /* line 3366 */
  sim_icache_fetch(2306 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3368 */
} /* line 3368 */
  sim_icache_fetch(2308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3370 */
} /* line 3370 */
  sim_icache_fetch(2309 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3372 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3373 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3374 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3375 */
   __ADD_CYCLES(1);
} /* line 3375 */
  sim_icache_fetch(2315 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 3377 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3378 */
   __ADD(reg_r0_8, reg_r0_35, (unsigned int) 16); /* line 3379 */
} /* line 3379 */
  sim_icache_fetch(2318 + t_thisfile.offset, 1);
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
} /* line 3381 */
  sim_icache_fetch(2319 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3383 */
} /* line 3383 */
  sim_icache_fetch(2321 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3385 */
} /* line 3385 */
  sim_icache_fetch(2322 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3387 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3388 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3389 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3390 */
   __ADD_CYCLES(1);
} /* line 3390 */
  sim_icache_fetch(2328 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_2); /* line 3392 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3393 */
   __ADD(reg_r0_9, reg_r0_34, (unsigned int) 16); /* line 3394 */
} /* line 3394 */
  sim_icache_fetch(2331 + t_thisfile.offset, 1);
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
} /* line 3396 */
  sim_icache_fetch(2332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3398 */
} /* line 3398 */
  sim_icache_fetch(2334 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3400 */
} /* line 3400 */
  sim_icache_fetch(2335 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3402 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3403 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3404 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3405 */
   __ADD_CYCLES(1);
} /* line 3405 */
  sim_icache_fetch(2341 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_2); /* line 3407 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3408 */
   __ADD(reg_r0_10, reg_r0_33, (unsigned int) 16); /* line 3409 */
} /* line 3409 */
  sim_icache_fetch(2344 + t_thisfile.offset, 1);
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
} /* line 3411 */
  sim_icache_fetch(2345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3413 */
} /* line 3413 */
  sim_icache_fetch(2347 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3415 */
} /* line 3415 */
  sim_icache_fetch(2348 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3417 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3418 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3419 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3420 */
   __ADD_CYCLES(1);
} /* line 3420 */
  sim_icache_fetch(2354 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_2); /* line 3422 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3423 */
   __ADD(reg_r0_11, reg_r0_32, (unsigned int) 16); /* line 3424 */
} /* line 3424 */
  sim_icache_fetch(2357 + t_thisfile.offset, 1);
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
} /* line 3426 */
  sim_icache_fetch(2358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3428 */
} /* line 3428 */
  sim_icache_fetch(2360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3430 */
} /* line 3430 */
  sim_icache_fetch(2361 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3432 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3433 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3434 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3435 */
   __ADD_CYCLES(1);
} /* line 3435 */
  sim_icache_fetch(2367 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_2); /* line 3437 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3438 */
   __ADD(reg_r0_12, reg_r0_31, (unsigned int) 16); /* line 3439 */
} /* line 3439 */
  sim_icache_fetch(2370 + t_thisfile.offset, 1);
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
} /* line 3441 */
  sim_icache_fetch(2371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3443 */
} /* line 3443 */
  sim_icache_fetch(2373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3445 */
} /* line 3445 */
  sim_icache_fetch(2374 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3447 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3448 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3449 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3450 */
   __ADD_CYCLES(1);
} /* line 3450 */
  sim_icache_fetch(2380 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_2); /* line 3452 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3453 */
   __ADD(reg_r0_13, reg_r0_30, (unsigned int) 16); /* line 3454 */
} /* line 3454 */
  sim_icache_fetch(2383 + t_thisfile.offset, 1);
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
} /* line 3456 */
  sim_icache_fetch(2384 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3458 */
} /* line 3458 */
  sim_icache_fetch(2386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3460 */
} /* line 3460 */
  sim_icache_fetch(2387 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3462 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3463 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3464 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3465 */
   __ADD_CYCLES(1);
} /* line 3465 */
  sim_icache_fetch(2393 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_2); /* line 3467 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3468 */
   __ADD(reg_r0_14, reg_r0_29, (unsigned int) 16); /* line 3469 */
} /* line 3469 */
  sim_icache_fetch(2396 + t_thisfile.offset, 1);
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
} /* line 3471 */
  sim_icache_fetch(2397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3473 */
} /* line 3473 */
  sim_icache_fetch(2399 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3475 */
} /* line 3475 */
  sim_icache_fetch(2400 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3477 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3478 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3479 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3480 */
   __ADD_CYCLES(1);
} /* line 3480 */
  sim_icache_fetch(2406 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_2); /* line 3482 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3483 */
   __ADD(reg_r0_15, reg_r0_28, (unsigned int) 16); /* line 3484 */
} /* line 3484 */
  sim_icache_fetch(2409 + t_thisfile.offset, 1);
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
} /* line 3486 */
  sim_icache_fetch(2410 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3488 */
} /* line 3488 */
  sim_icache_fetch(2412 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3490 */
} /* line 3490 */
  sim_icache_fetch(2413 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3492 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3493 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3494 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3495 */
   __ADD_CYCLES(1);
} /* line 3495 */
  sim_icache_fetch(2419 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_2); /* line 3497 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3498 */
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 16); /* line 3499 */
} /* line 3499 */
  sim_icache_fetch(2422 + t_thisfile.offset, 1);
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
} /* line 3501 */
  sim_icache_fetch(2423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3503 */
} /* line 3503 */
  sim_icache_fetch(2425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3505 */
} /* line 3505 */
  sim_icache_fetch(2426 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3507 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3508 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3509 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3510 */
   __ADD_CYCLES(1);
} /* line 3510 */
  sim_icache_fetch(2432 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_2); /* line 3512 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3513 */
   __ADD(reg_r0_17, reg_r0_26, (unsigned int) 16); /* line 3514 */
} /* line 3514 */
  sim_icache_fetch(2435 + t_thisfile.offset, 1);
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
} /* line 3516 */
  sim_icache_fetch(2436 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3518 */
} /* line 3518 */
  sim_icache_fetch(2438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3520 */
} /* line 3520 */
  sim_icache_fetch(2439 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3522 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3523 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3524 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3525 */
   __ADD_CYCLES(1);
} /* line 3525 */
  sim_icache_fetch(2445 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_2); /* line 3527 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3528 */
   __ADD(reg_r0_18, reg_r0_25, (unsigned int) 16); /* line 3529 */
} /* line 3529 */
  sim_icache_fetch(2448 + t_thisfile.offset, 1);
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
} /* line 3531 */
  sim_icache_fetch(2449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3533 */
} /* line 3533 */
  sim_icache_fetch(2451 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3535 */
} /* line 3535 */
  sim_icache_fetch(2452 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3537 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3538 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3539 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3540 */
   __ADD_CYCLES(1);
} /* line 3540 */
  sim_icache_fetch(2458 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_2); /* line 3542 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3543 */
   __ADD(reg_r0_19, reg_r0_24, (unsigned int) 16); /* line 3544 */
} /* line 3544 */
  sim_icache_fetch(2461 + t_thisfile.offset, 1);
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
} /* line 3546 */
  sim_icache_fetch(2462 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3548 */
} /* line 3548 */
  sim_icache_fetch(2464 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3550 */
} /* line 3550 */
  sim_icache_fetch(2465 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3552 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3553 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3554 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3555 */
   __ADD_CYCLES(1);
} /* line 3555 */
  sim_icache_fetch(2471 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_2); /* line 3557 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3558 */
   __ADD(reg_r0_20, reg_r0_23, (unsigned int) 16); /* line 3559 */
} /* line 3559 */
  sim_icache_fetch(2474 + t_thisfile.offset, 1);
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
} /* line 3561 */
  sim_icache_fetch(2475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3563 */
} /* line 3563 */
  sim_icache_fetch(2477 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3565 */
} /* line 3565 */
  sim_icache_fetch(2478 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3567 */
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3568 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3569 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3570 */
   __ADD_CYCLES(1);
} /* line 3570 */
  sim_icache_fetch(2484 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_2); /* line 3572 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3573 */
   __ADD(reg_r0_21, reg_r0_36, (unsigned int) 16); /* line 3574 */
} /* line 3574 */
  sim_icache_fetch(2487 + t_thisfile.offset, 1);
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
} /* line 3576 */
  sim_icache_fetch(2488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3578 */
} /* line 3578 */
  sim_icache_fetch(2490 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_5); /* line 3580 */
} /* line 3580 */
  sim_icache_fetch(2491 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3582 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_37,0,1)); /* line 3583 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3584 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3585 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3586 */
   __ADD_CYCLES(1);
} /* line 3586 */
  sim_icache_fetch(2498 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_38, reg_r0_2); /* line 3588 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3589 */
} /* line 3589 */
  sim_icache_fetch(2500 + t_thisfile.offset, 1);
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
} /* line 3591 */
  sim_icache_fetch(2501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3593 */
} /* line 3593 */
  sim_icache_fetch(2503 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3595 */
} /* line 3595 */
  sim_icache_fetch(2504 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3597 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3598 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3599 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3600 */
   __ADD_CYCLES(1);
} /* line 3600 */
  sim_icache_fetch(2510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3602 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3603 */
} /* line 3603 */
  sim_icache_fetch(2512 + t_thisfile.offset, 1);
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
} /* line 3605 */
  sim_icache_fetch(2513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3607 */
} /* line 3607 */
  sim_icache_fetch(2515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3609 */
} /* line 3609 */
  sim_icache_fetch(2516 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3611 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3612 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3613 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3614 */
   __ADD_CYCLES(1);
} /* line 3614 */
  sim_icache_fetch(2522 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3616 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3617 */
} /* line 3617 */
  sim_icache_fetch(2524 + t_thisfile.offset, 1);
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
} /* line 3619 */
  sim_icache_fetch(2525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3621 */
} /* line 3621 */
  sim_icache_fetch(2527 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3623 */
} /* line 3623 */
  sim_icache_fetch(2528 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3625 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3626 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3627 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3628 */
   __ADD_CYCLES(1);
} /* line 3628 */
  sim_icache_fetch(2534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3630 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3631 */
} /* line 3631 */
  sim_icache_fetch(2536 + t_thisfile.offset, 1);
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
} /* line 3633 */
  sim_icache_fetch(2537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3635 */
} /* line 3635 */
  sim_icache_fetch(2539 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3637 */
} /* line 3637 */
  sim_icache_fetch(2540 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3639 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3640 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3641 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3642 */
   __ADD_CYCLES(1);
} /* line 3642 */
  sim_icache_fetch(2546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3644 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3645 */
} /* line 3645 */
  sim_icache_fetch(2548 + t_thisfile.offset, 1);
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
} /* line 3647 */
  sim_icache_fetch(2549 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3649 */
} /* line 3649 */
  sim_icache_fetch(2551 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3651 */
} /* line 3651 */
  sim_icache_fetch(2552 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3653 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3654 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3655 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3656 */
   __ADD_CYCLES(1);
} /* line 3656 */
  sim_icache_fetch(2558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3658 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3659 */
} /* line 3659 */
  sim_icache_fetch(2560 + t_thisfile.offset, 1);
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
} /* line 3661 */
  sim_icache_fetch(2561 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3663 */
} /* line 3663 */
  sim_icache_fetch(2563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3665 */
} /* line 3665 */
  sim_icache_fetch(2564 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3667 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3668 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3669 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3670 */
   __ADD_CYCLES(1);
} /* line 3670 */
  sim_icache_fetch(2570 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3672 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3673 */
} /* line 3673 */
  sim_icache_fetch(2572 + t_thisfile.offset, 1);
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
} /* line 3675 */
  sim_icache_fetch(2573 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3677 */
} /* line 3677 */
  sim_icache_fetch(2575 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3679 */
} /* line 3679 */
  sim_icache_fetch(2576 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3681 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3682 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3683 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3684 */
   __ADD_CYCLES(1);
} /* line 3684 */
  sim_icache_fetch(2582 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3686 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3687 */
} /* line 3687 */
  sim_icache_fetch(2584 + t_thisfile.offset, 1);
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
} /* line 3689 */
  sim_icache_fetch(2585 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3691 */
} /* line 3691 */
  sim_icache_fetch(2587 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3693 */
} /* line 3693 */
  sim_icache_fetch(2588 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3695 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3696 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3697 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3698 */
   __ADD_CYCLES(1);
} /* line 3698 */
  sim_icache_fetch(2594 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3700 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3701 */
} /* line 3701 */
  sim_icache_fetch(2596 + t_thisfile.offset, 1);
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
} /* line 3703 */
  sim_icache_fetch(2597 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3705 */
} /* line 3705 */
  sim_icache_fetch(2599 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3707 */
} /* line 3707 */
  sim_icache_fetch(2600 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3709 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3710 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3711 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3712 */
   __ADD_CYCLES(1);
} /* line 3712 */
  sim_icache_fetch(2606 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3714 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3715 */
} /* line 3715 */
  sim_icache_fetch(2608 + t_thisfile.offset, 1);
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
} /* line 3717 */
  sim_icache_fetch(2609 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3719 */
} /* line 3719 */
  sim_icache_fetch(2611 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3721 */
} /* line 3721 */
  sim_icache_fetch(2612 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3723 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3724 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3725 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3726 */
   __ADD_CYCLES(1);
} /* line 3726 */
  sim_icache_fetch(2618 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3728 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3729 */
} /* line 3729 */
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
} /* line 3731 */
  sim_icache_fetch(2621 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3733 */
} /* line 3733 */
  sim_icache_fetch(2623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3735 */
} /* line 3735 */
  sim_icache_fetch(2624 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3737 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3738 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3739 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3740 */
   __ADD_CYCLES(1);
} /* line 3740 */
  sim_icache_fetch(2630 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3742 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3743 */
} /* line 3743 */
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
} /* line 3745 */
  sim_icache_fetch(2633 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3747 */
} /* line 3747 */
  sim_icache_fetch(2635 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3749 */
} /* line 3749 */
  sim_icache_fetch(2636 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3751 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3752 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3753 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3754 */
   __ADD_CYCLES(1);
} /* line 3754 */
  sim_icache_fetch(2642 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3756 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3757 */
} /* line 3757 */
  sim_icache_fetch(2644 + t_thisfile.offset, 1);
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
} /* line 3759 */
  sim_icache_fetch(2645 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3761 */
} /* line 3761 */
  sim_icache_fetch(2647 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3763 */
} /* line 3763 */
  sim_icache_fetch(2648 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3765 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3766 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3767 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3768 */
   __ADD_CYCLES(1);
} /* line 3768 */
  sim_icache_fetch(2654 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3770 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3771 */
} /* line 3771 */
  sim_icache_fetch(2656 + t_thisfile.offset, 1);
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
} /* line 3773 */
  sim_icache_fetch(2657 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3775 */
} /* line 3775 */
  sim_icache_fetch(2659 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3777 */
} /* line 3777 */
  sim_icache_fetch(2660 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3779 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3780 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3781 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3782 */
   __ADD_CYCLES(1);
} /* line 3782 */
  sim_icache_fetch(2666 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3784 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3785 */
} /* line 3785 */
  sim_icache_fetch(2668 + t_thisfile.offset, 1);
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
} /* line 3787 */
  sim_icache_fetch(2669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3789 */
} /* line 3789 */
  sim_icache_fetch(2671 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3791 */
} /* line 3791 */
  sim_icache_fetch(2672 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3793 */
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3794 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3795 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3796 */
   __ADD_CYCLES(1);
} /* line 3796 */
  sim_icache_fetch(2678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3798 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3799 */
} /* line 3799 */
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
} /* line 3801 */
  sim_icache_fetch(2681 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3803 */
} /* line 3803 */
  sim_icache_fetch(2683 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3805 */
   __GOTO(l_L176X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L176X3;
} /* line 3806 */
l_L177X3: ;/* line 3809 */
__LABEL(l_L177X3);
  sim_icache_fetch(2685 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3810 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3811 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3812 */
   __ADD_CYCLES(1);
} /* line 3812 */
  sim_icache_fetch(2690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3814 */
} /* line 3814 */
  sim_icache_fetch(2691 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3816 */
} /* line 3816 */
l_L175X3: ;/* line 3819 */
__LABEL(l_L175X3);
  sim_icache_fetch(2693 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) compress_13457Xoffset,0,4), 0); /* line 3820 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3821 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3822 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3823 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3824 */
   __ADD_CYCLES(1);
} /* line 3824 */
  sim_icache_fetch(2701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3826 */
} /* line 3826 */
  sim_icache_fetch(2702 + t_thisfile.offset, 1);
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
} /* line 3828 */
  sim_icache_fetch(2703 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3831 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3832 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3833 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3834 */
l_L178X3: ;/* line 3837 */
__LABEL(l_L178X3);
  sim_icache_fetch(2710 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3838 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3839 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3840 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3841 */
   __ADD_CYCLES(1);
} /* line 3841 */
  sim_icache_fetch(2717 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3843 */
} /* line 3843 */
  sim_icache_fetch(2718 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3845 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3846 */
} /* line 3846 */
  sim_icache_fetch(2721 + t_thisfile.offset, 1);
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
} /* line 3848 */
  sim_icache_fetch(2722 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3851 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3852 */
l_L179X3: ;/* line 3855 */
__LABEL(l_L179X3);
  sim_icache_fetch(2725 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3856 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3857 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3858 */
   __ADD_CYCLES(1);
} /* line 3858 */
  sim_icache_fetch(2729 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3860 */
} /* line 3860 */
  sim_icache_fetch(2730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3862 */
} /* line 3862 */
  sim_icache_fetch(2731 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3865 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3866 */
l_L174X3: ;/* line 3869 */
__LABEL(l_L174X3);
  sim_icache_fetch(2734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3871 */
l_L168X3: ;/* line 3874 */
__LABEL(l_L168X3);
  sim_icache_fetch(2735 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 3875 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3876 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 3877 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3878 */
   __ADD_CYCLES(1);
} /* line 3878 */
  sim_icache_fetch(2742 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_4, 0); /* line 3880 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3881 */
} /* line 3881 */
  sim_icache_fetch(2744 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 3883 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 3884 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L180X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3885 */
l_L181X3: ;/* line 3887 */
__LABEL(l_L181X3);
  sim_icache_fetch(2747 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_2); /* line 3888 */
   __STW(mem_trace_st((unsigned int) compress_13457Xoffset,0,4), 0); /* line 3889 */
} /* line 3889 */
  sim_icache_fetch(2750 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 3891 */
} /* line 3891 */
  sim_icache_fetch(2751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3893 */
} /* line 3893 */
  sim_icache_fetch(2752 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3896 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3897 */
l_L180X3: ;/* line 3900 */
__LABEL(l_L180X3);
  sim_icache_fetch(2755 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __MOV(reg_r0_9, (unsigned int) 3); /* line 3901 */
   __MOV(reg_r0_10, (unsigned int) 4); /* line 3902 */
   __MOV(reg_r0_11, (unsigned int) 5); /* line 3903 */
   __MOV(reg_r0_12, (unsigned int) 6); /* line 3904 */
   __MOV(reg_r0_13, (unsigned int) 7); /* line 3905 */
   __MOV(reg_r0_14, (unsigned int) 8); /* line 3906 */
   __MOV(reg_r0_15, (unsigned int) 9); /* line 3907 */
   __MOV(reg_r0_16, (unsigned int) 10); /* line 3908 */
   __MOV(reg_r0_17, (unsigned int) 11); /* line 3909 */
   __MOV(reg_r0_18, (unsigned int) 12); /* line 3910 */
   __MOV(reg_r0_19, (unsigned int) 13); /* line 3911 */
   __MOV(reg_r0_20, (unsigned int) 14); /* line 3912 */
   __MOV(reg_r0_21, (unsigned int) 15); /* line 3913 */
} /* line 3913 */
  sim_icache_fetch(2768 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 3915 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 3916 */
   __MOV(reg_r0_5, (unsigned int) compress_13457Xbuf); /* line 3917 */
   __MOV(reg_r0_3, 0); /* line 3918 */
} /* line 3918 */
l_L182X3: ;/* line 3921 */
__LABEL(l_L182X3);
  sim_icache_fetch(2773 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 3922 */
   __LDBs(reg_r0_6, mem_trace_ld(reg_r0_5,0,1)); /* line 3923 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3924 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3925 */
   __ADD_CYCLES(1);
} /* line 3925 */
  sim_icache_fetch(2779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3927 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3928 */
} /* line 3928 */
  sim_icache_fetch(2781 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3930 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3931 */
} /* line 3931 */
  sim_icache_fetch(2783 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3933 */
} /* line 3933 */
  sim_icache_fetch(2784 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3935 */
} /* line 3935 */
  sim_icache_fetch(2785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3937 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3938 */
} /* line 3938 */
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
} /* line 3940 */
  sim_icache_fetch(2788 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3942 */
} /* line 3942 */
  sim_icache_fetch(2790 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3944 */
} /* line 3944 */
  sim_icache_fetch(2791 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 3946 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3947 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3948 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3949 */
   __ADD_CYCLES(1);
} /* line 3949 */
  sim_icache_fetch(2797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3951 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3952 */
} /* line 3952 */
  sim_icache_fetch(2799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3954 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3955 */
} /* line 3955 */
  sim_icache_fetch(2801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3957 */
} /* line 3957 */
  sim_icache_fetch(2802 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3959 */
} /* line 3959 */
  sim_icache_fetch(2803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 3961 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 3962 */
} /* line 3962 */
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
} /* line 3964 */
  sim_icache_fetch(2806 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3966 */
} /* line 3966 */
  sim_icache_fetch(2808 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3968 */
} /* line 3968 */
  sim_icache_fetch(2809 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 3970 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3971 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3972 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3973 */
   __ADD_CYCLES(1);
} /* line 3973 */
  sim_icache_fetch(2815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3975 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3976 */
} /* line 3976 */
  sim_icache_fetch(2817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3978 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3979 */
} /* line 3979 */
  sim_icache_fetch(2819 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3981 */
} /* line 3981 */
  sim_icache_fetch(2820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3983 */
} /* line 3983 */
  sim_icache_fetch(2821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 3985 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 3986 */
} /* line 3986 */
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
} /* line 3988 */
  sim_icache_fetch(2824 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3990 */
} /* line 3990 */
  sim_icache_fetch(2826 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 3992 */
} /* line 3992 */
  sim_icache_fetch(2827 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 3994 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3995 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3996 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3997 */
   __ADD_CYCLES(1);
} /* line 3997 */
  sim_icache_fetch(2833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3999 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4000 */
} /* line 4000 */
  sim_icache_fetch(2835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4002 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4003 */
} /* line 4003 */
  sim_icache_fetch(2837 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4005 */
} /* line 4005 */
  sim_icache_fetch(2838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4007 */
} /* line 4007 */
  sim_icache_fetch(2839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 4009 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 4010 */
} /* line 4010 */
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
} /* line 4012 */
  sim_icache_fetch(2842 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4014 */
} /* line 4014 */
  sim_icache_fetch(2844 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4016 */
} /* line 4016 */
  sim_icache_fetch(2845 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4018 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 4019 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4020 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4021 */
   __ADD_CYCLES(1);
} /* line 4021 */
  sim_icache_fetch(2851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4023 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4024 */
} /* line 4024 */
  sim_icache_fetch(2853 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4026 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4027 */
} /* line 4027 */
  sim_icache_fetch(2855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4029 */
} /* line 4029 */
  sim_icache_fetch(2856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4031 */
} /* line 4031 */
  sim_icache_fetch(2857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 4033 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 4034 */
} /* line 4034 */
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
} /* line 4036 */
  sim_icache_fetch(2860 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4038 */
} /* line 4038 */
  sim_icache_fetch(2862 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4040 */
} /* line 4040 */
  sim_icache_fetch(2863 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4042 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 4043 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4044 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4045 */
   __ADD_CYCLES(1);
} /* line 4045 */
  sim_icache_fetch(2869 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4047 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4048 */
} /* line 4048 */
  sim_icache_fetch(2871 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4050 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4051 */
} /* line 4051 */
  sim_icache_fetch(2873 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4053 */
} /* line 4053 */
  sim_icache_fetch(2874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4055 */
} /* line 4055 */
  sim_icache_fetch(2875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 4057 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 4058 */
} /* line 4058 */
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
} /* line 4060 */
  sim_icache_fetch(2878 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4062 */
} /* line 4062 */
  sim_icache_fetch(2880 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4064 */
} /* line 4064 */
  sim_icache_fetch(2881 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4066 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 4067 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4068 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4069 */
   __ADD_CYCLES(1);
} /* line 4069 */
  sim_icache_fetch(2887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4071 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4072 */
} /* line 4072 */
  sim_icache_fetch(2889 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4074 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4075 */
} /* line 4075 */
  sim_icache_fetch(2891 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4077 */
} /* line 4077 */
  sim_icache_fetch(2892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4079 */
} /* line 4079 */
  sim_icache_fetch(2893 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 4081 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 4082 */
} /* line 4082 */
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
} /* line 4084 */
  sim_icache_fetch(2896 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4086 */
} /* line 4086 */
  sim_icache_fetch(2898 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4088 */
} /* line 4088 */
  sim_icache_fetch(2899 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4090 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4091 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4092 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4093 */
   __ADD_CYCLES(1);
} /* line 4093 */
  sim_icache_fetch(2905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4095 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4096 */
} /* line 4096 */
  sim_icache_fetch(2907 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4098 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4099 */
} /* line 4099 */
  sim_icache_fetch(2909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4101 */
} /* line 4101 */
  sim_icache_fetch(2910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4103 */
} /* line 4103 */
  sim_icache_fetch(2911 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4105 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4106 */
} /* line 4106 */
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
} /* line 4108 */
  sim_icache_fetch(2914 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4110 */
} /* line 4110 */
  sim_icache_fetch(2916 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4112 */
} /* line 4112 */
  sim_icache_fetch(2917 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4114 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4115 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4116 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4117 */
   __ADD_CYCLES(1);
} /* line 4117 */
  sim_icache_fetch(2923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4119 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4120 */
} /* line 4120 */
  sim_icache_fetch(2925 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4122 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4123 */
} /* line 4123 */
  sim_icache_fetch(2927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4125 */
} /* line 4125 */
  sim_icache_fetch(2928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4127 */
} /* line 4127 */
  sim_icache_fetch(2929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4129 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4130 */
} /* line 4130 */
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
} /* line 4132 */
  sim_icache_fetch(2932 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4134 */
} /* line 4134 */
  sim_icache_fetch(2934 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4136 */
} /* line 4136 */
  sim_icache_fetch(2935 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4138 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4139 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4140 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4141 */
   __ADD_CYCLES(1);
} /* line 4141 */
  sim_icache_fetch(2941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4143 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4144 */
} /* line 4144 */
  sim_icache_fetch(2943 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4146 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4147 */
} /* line 4147 */
  sim_icache_fetch(2945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4149 */
} /* line 4149 */
  sim_icache_fetch(2946 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4151 */
} /* line 4151 */
  sim_icache_fetch(2947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4153 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4154 */
} /* line 4154 */
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
} /* line 4156 */
  sim_icache_fetch(2950 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4158 */
} /* line 4158 */
  sim_icache_fetch(2952 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4160 */
} /* line 4160 */
  sim_icache_fetch(2953 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4162 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4163 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4164 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4165 */
   __ADD_CYCLES(1);
} /* line 4165 */
  sim_icache_fetch(2959 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4167 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4168 */
} /* line 4168 */
  sim_icache_fetch(2961 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4170 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4171 */
} /* line 4171 */
  sim_icache_fetch(2963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4173 */
} /* line 4173 */
  sim_icache_fetch(2964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4175 */
} /* line 4175 */
  sim_icache_fetch(2965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4177 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4178 */
} /* line 4178 */
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
} /* line 4180 */
  sim_icache_fetch(2968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4182 */
} /* line 4182 */
  sim_icache_fetch(2970 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4184 */
} /* line 4184 */
  sim_icache_fetch(2971 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4186 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4187 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4188 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4189 */
   __ADD_CYCLES(1);
} /* line 4189 */
  sim_icache_fetch(2977 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4191 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4192 */
} /* line 4192 */
  sim_icache_fetch(2979 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4194 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4195 */
} /* line 4195 */
  sim_icache_fetch(2981 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4197 */
} /* line 4197 */
  sim_icache_fetch(2982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4199 */
} /* line 4199 */
  sim_icache_fetch(2983 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4201 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4202 */
} /* line 4202 */
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
} /* line 4204 */
  sim_icache_fetch(2986 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4206 */
} /* line 4206 */
  sim_icache_fetch(2988 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4208 */
} /* line 4208 */
  sim_icache_fetch(2989 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4210 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4211 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4212 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4213 */
   __ADD_CYCLES(1);
} /* line 4213 */
  sim_icache_fetch(2995 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4215 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4216 */
} /* line 4216 */
  sim_icache_fetch(2997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4218 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4219 */
} /* line 4219 */
  sim_icache_fetch(2999 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4221 */
} /* line 4221 */
  sim_icache_fetch(3000 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4223 */
} /* line 4223 */
  sim_icache_fetch(3001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4225 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4226 */
} /* line 4226 */
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
} /* line 4228 */
  sim_icache_fetch(3004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4230 */
} /* line 4230 */
  sim_icache_fetch(3006 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4232 */
} /* line 4232 */
  sim_icache_fetch(3007 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4234 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4235 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4236 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4237 */
   __ADD_CYCLES(1);
} /* line 4237 */
  sim_icache_fetch(3013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4239 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4240 */
} /* line 4240 */
  sim_icache_fetch(3015 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4242 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4243 */
} /* line 4243 */
  sim_icache_fetch(3017 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4245 */
} /* line 4245 */
  sim_icache_fetch(3018 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4247 */
} /* line 4247 */
  sim_icache_fetch(3019 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4249 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4250 */
} /* line 4250 */
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
} /* line 4252 */
  sim_icache_fetch(3022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4254 */
} /* line 4254 */
  sim_icache_fetch(3024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4256 */
} /* line 4256 */
  sim_icache_fetch(3025 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4258 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4259 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4260 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4261 */
   __ADD_CYCLES(1);
} /* line 4261 */
  sim_icache_fetch(3031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4263 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4264 */
} /* line 4264 */
  sim_icache_fetch(3033 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4266 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4267 */
} /* line 4267 */
  sim_icache_fetch(3035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4269 */
} /* line 4269 */
  sim_icache_fetch(3036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4271 */
} /* line 4271 */
  sim_icache_fetch(3037 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4273 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4274 */
} /* line 4274 */
  sim_icache_fetch(3039 + t_thisfile.offset, 1);
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
} /* line 4276 */
  sim_icache_fetch(3040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4278 */
} /* line 4278 */
  sim_icache_fetch(3042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4280 */
} /* line 4280 */
  sim_icache_fetch(3043 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4282 */
   __LDBs(reg_r0_6, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4283 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4284 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4285 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4286 */
   __ADD_CYCLES(1);
} /* line 4286 */
  sim_icache_fetch(3050 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4288 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4289 */
} /* line 4289 */
  sim_icache_fetch(3052 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4291 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4292 */
} /* line 4292 */
  sim_icache_fetch(3054 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4294 */
} /* line 4294 */
  sim_icache_fetch(3055 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4296 */
} /* line 4296 */
  sim_icache_fetch(3056 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_21, reg_r0_23); /* line 4298 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 4299 */
} /* line 4299 */
  sim_icache_fetch(3058 + t_thisfile.offset, 1);
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
} /* line 4301 */
  sim_icache_fetch(3059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4303 */
} /* line 4303 */
  sim_icache_fetch(3061 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 4305 */
   __GOTO(l_L182X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L182X3;
} /* line 4306 */
l_L198X3: ;/* line 4309 */
__LABEL(l_L198X3);
  sim_icache_fetch(3063 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4310 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4311 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4312 */
   __ADD_CYCLES(1);
} /* line 4312 */
  sim_icache_fetch(3068 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4314 */
} /* line 4314 */
  sim_icache_fetch(3069 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4316 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4317 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4318 */
l_L197X3: ;/* line 4321 */
__LABEL(l_L197X3);
  sim_icache_fetch(3072 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4322 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4323 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4324 */
   __ADD_CYCLES(1);
} /* line 4324 */
  sim_icache_fetch(3077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4326 */
} /* line 4326 */
  sim_icache_fetch(3078 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4328 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4329 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4330 */
l_L196X3: ;/* line 4333 */
__LABEL(l_L196X3);
  sim_icache_fetch(3081 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4334 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4335 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4336 */
   __ADD_CYCLES(1);
} /* line 4336 */
  sim_icache_fetch(3086 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4338 */
} /* line 4338 */
  sim_icache_fetch(3087 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4340 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4341 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4342 */
l_L195X3: ;/* line 4345 */
__LABEL(l_L195X3);
  sim_icache_fetch(3090 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4346 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4347 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4348 */
   __ADD_CYCLES(1);
} /* line 4348 */
  sim_icache_fetch(3095 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4350 */
} /* line 4350 */
  sim_icache_fetch(3096 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4352 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4353 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4354 */
l_L194X3: ;/* line 4357 */
__LABEL(l_L194X3);
  sim_icache_fetch(3099 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4358 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4359 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4360 */
   __ADD_CYCLES(1);
} /* line 4360 */
  sim_icache_fetch(3104 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4362 */
} /* line 4362 */
  sim_icache_fetch(3105 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4364 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4365 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4366 */
l_L193X3: ;/* line 4369 */
__LABEL(l_L193X3);
  sim_icache_fetch(3108 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4370 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4371 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4372 */
   __ADD_CYCLES(1);
} /* line 4372 */
  sim_icache_fetch(3113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4374 */
} /* line 4374 */
  sim_icache_fetch(3114 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4376 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4377 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4378 */
l_L192X3: ;/* line 4381 */
__LABEL(l_L192X3);
  sim_icache_fetch(3117 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4382 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4383 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4384 */
   __ADD_CYCLES(1);
} /* line 4384 */
  sim_icache_fetch(3122 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4386 */
} /* line 4386 */
  sim_icache_fetch(3123 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4388 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4389 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4390 */
l_L191X3: ;/* line 4393 */
__LABEL(l_L191X3);
  sim_icache_fetch(3126 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4394 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4395 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4396 */
   __ADD_CYCLES(1);
} /* line 4396 */
  sim_icache_fetch(3131 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4398 */
} /* line 4398 */
  sim_icache_fetch(3132 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4400 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4401 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4402 */
l_L190X3: ;/* line 4405 */
__LABEL(l_L190X3);
  sim_icache_fetch(3135 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4406 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4407 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4408 */
   __ADD_CYCLES(1);
} /* line 4408 */
  sim_icache_fetch(3140 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4410 */
} /* line 4410 */
  sim_icache_fetch(3141 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4412 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4413 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4414 */
l_L189X3: ;/* line 4417 */
__LABEL(l_L189X3);
  sim_icache_fetch(3144 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4418 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4419 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4420 */
   __ADD_CYCLES(1);
} /* line 4420 */
  sim_icache_fetch(3149 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4422 */
} /* line 4422 */
  sim_icache_fetch(3150 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4424 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4425 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4426 */
l_L188X3: ;/* line 4429 */
__LABEL(l_L188X3);
  sim_icache_fetch(3153 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4430 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4431 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4432 */
   __ADD_CYCLES(1);
} /* line 4432 */
  sim_icache_fetch(3158 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4434 */
} /* line 4434 */
  sim_icache_fetch(3159 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4436 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4437 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4438 */
l_L187X3: ;/* line 4441 */
__LABEL(l_L187X3);
  sim_icache_fetch(3162 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4442 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4443 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4444 */
   __ADD_CYCLES(1);
} /* line 4444 */
  sim_icache_fetch(3167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4446 */
} /* line 4446 */
  sim_icache_fetch(3168 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4448 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4449 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4450 */
l_L186X3: ;/* line 4453 */
__LABEL(l_L186X3);
  sim_icache_fetch(3171 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4454 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4455 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4456 */
   __ADD_CYCLES(1);
} /* line 4456 */
  sim_icache_fetch(3176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4458 */
} /* line 4458 */
  sim_icache_fetch(3177 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4460 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4461 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4462 */
l_L185X3: ;/* line 4465 */
__LABEL(l_L185X3);
  sim_icache_fetch(3180 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4466 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4467 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4468 */
   __ADD_CYCLES(1);
} /* line 4468 */
  sim_icache_fetch(3185 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4470 */
} /* line 4470 */
  sim_icache_fetch(3186 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4472 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4473 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4474 */
l_L184X3: ;/* line 4477 */
__LABEL(l_L184X3);
  sim_icache_fetch(3189 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4478 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4479 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4480 */
   __ADD_CYCLES(1);
} /* line 4480 */
  sim_icache_fetch(3194 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4482 */
} /* line 4482 */
  sim_icache_fetch(3195 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4484 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4485 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4486 */
l_L183X3: ;/* line 4489 */
__LABEL(l_L183X3);
  sim_icache_fetch(3198 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4490 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) compress_13457Xoffset,0,4)); /* line 4491 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4492 */
   __ADD_CYCLES(1);
} /* line 4492 */
  sim_icache_fetch(3203 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 7); /* line 4494 */
} /* line 4494 */
  sim_icache_fetch(3204 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_1, reg_r0_2, 0); /* line 4496 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4497 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4498 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 333: goto l_L169X3;
    case 334: goto l_L170X3;
    case 335: goto l_L172X3;
    case 336: goto l_L173X3;
    case 337: goto l_L171X3;
    case 338: goto l_L176X3;
    case 339: goto l_L177X3;
    case 340: goto l_L175X3;
    case 341: goto l_L178X3;
    case 342: goto l_L179X3;
    case 343: goto l_L174X3;
    case 344: goto l_L168X3;
    case 345: goto l_L181X3;
    case 346: goto l_L180X3;
    case 347: goto l_L182X3;
    case 348: goto l_L198X3;
    case 349: goto l_L197X3;
    case 350: goto l_L196X3;
    case 351: goto l_L195X3;
    case 352: goto l_L194X3;
    case 353: goto l_L193X3;
    case 354: goto l_L192X3;
    case 355: goto l_L191X3;
    case 356: goto l_L190X3;
    case 357: goto l_L189X3;
    case 358: goto l_L188X3;
    case 359: goto l_L187X3;
    case 360: goto l_L186X3;
    case 361: goto l_L185X3;
    case 362: goto l_L184X3;
    case 363: goto l_L183X3;
    case 364:
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
  reg_l0_0 = (418 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3207 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4514 */
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4515 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4516 */
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4517 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4518 */
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4519 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4520 */
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4521 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4522 */
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4523 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4524 */
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4525 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4526 */
} /* line 4526 */
  sim_icache_fetch(3221 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4528 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4529 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4530 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4531 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4532 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4533 */
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4534 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4535 */
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4536 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4537 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4538 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4539 */
} /* line 4539 */
l_L199X3: ;/* line 4542 */
__LABEL(l_L199X3);
  sim_icache_fetch(3237 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4543 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4544 */
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4545 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4546 */
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4547 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4548 */
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4549 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4550 */
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4551 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4552 */
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4553 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4554 */
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4555 */
} /* line 4555 */
  sim_icache_fetch(3250 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4557 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4558 */
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4559 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4560 */
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4561 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4562 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L200X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4563 */
  sim_icache_fetch(3257 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4565 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4566 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4567 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4568 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4569 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4570 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4571 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4572 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4573 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4574 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4575 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4576 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4577 */
} /* line 4577 */
  sim_icache_fetch(3270 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4579 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4580 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4581 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4582 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4583 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4584 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4585 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4586 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4587 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4588 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4589 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4590 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4591 */
} /* line 4591 */
  sim_icache_fetch(3283 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4593 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4594 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4595 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4596 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4597 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4598 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4599 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4600 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4601 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4602 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4603 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4604 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4605 */
} /* line 4605 */
  sim_icache_fetch(3296 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4607 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4608 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4609 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4610 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4611 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4612 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4613 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4614 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4615 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4616 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4617 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4618 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4619 */
} /* line 4619 */
  sim_icache_fetch(3309 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4621 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4622 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4623 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4624 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4625 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4626 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4627 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4628 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4629 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4630 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4631 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4632 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4633 */
} /* line 4633 */
  sim_icache_fetch(3322 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4635 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4636 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4637 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4638 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4639 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4640 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4641 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4642 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4643 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4644 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4645 */
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4646 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4647 */
} /* line 4647 */
  sim_icache_fetch(3335 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4649 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4650 */
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4651 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4652 */
   __GOTO(l_L199X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L199X3;
} /* line 4653 */
l_L200X3: ;/* line 4656 */
__LABEL(l_L200X3);
  sim_icache_fetch(3340 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4657 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4658 */
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4659 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4660 */
   __ADD_CYCLES(1);
} /* line 4660 */
  sim_icache_fetch(3346 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4662 */
} /* line 4662 */
  sim_icache_fetch(3347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4664 */
} /* line 4664 */
		 /* line 4665 */
  sim_icache_fetch(3349 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4667 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (418 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4668 */
l_lr_267: ;/* line 4668 */
__LABEL(l_lr_267);
  sim_icache_fetch(3353 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MOV(reg_r0_2, t__i32_0); /* line 4670 */
   __MOV(reg_r0_4, t__i32_0); /* line 4671 */
   __CMPEQ(reg_b0_0, t__i32_0, (unsigned int) -1); /* line 4672 */
   __MOV(reg_r0_3, 0); /* line 4673 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4674 */
   __MOV(reg_r0_5, t__i32_0); /* line 4675 */
} /* line 4675 */
  sim_icache_fetch(3359 + t_thisfile.offset, 1);
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
} /* line 4677 */
  sim_icache_fetch(3360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4680 */
l_L201X3: ;/* line 4683 */
__LABEL(l_L201X3);
  sim_icache_fetch(3361 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4684 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4685 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4686 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4687 */
} /* line 4687 */
  sim_icache_fetch(3366 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4689 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4690 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4691 */
} /* line 4691 */
  sim_icache_fetch(3370 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 1); /* line 4693 */
} /* line 4693 */
  sim_icache_fetch(3371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 4695 */
} /* line 4695 */
  sim_icache_fetch(3373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_3,0,1), reg_r0_5); /* line 4697 */
} /* line 4697 */
l_L202X3: ;/* line 4700 */
__LABEL(l_L202X3);
		 /* line 4700 */
  sim_icache_fetch(3374 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (418 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4702 */
l_lr_271: ;/* line 4702 */
__LABEL(l_lr_271);
  sim_icache_fetch(3376 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_4, reg_r0_3); /* line 4704 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4705 */
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4706 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4707 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4708 */
} /* line 4708 */
  sim_icache_fetch(3383 + t_thisfile.offset, 1);
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
} /* line 4710 */
  sim_icache_fetch(3384 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4712 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4713 */
} /* line 4713 */
  sim_icache_fetch(3387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4715 */
l_L205X3: ;/* line 4718 */
__LABEL(l_L205X3);
  sim_icache_fetch(3388 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4719 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4720 */
} /* line 4720 */
  sim_icache_fetch(3390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4722 */
  sim_icache_fetch(3391 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4724 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4725 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4726 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4727 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4728 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4729 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4730 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4731 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4732 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4733 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4734 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4735 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4736 */
} /* line 4736 */
  sim_icache_fetch(3404 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4738 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4739 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4740 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4741 */
   __GOTO(l_L205X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L205X3;
} /* line 4742 */
l_L206X3: ;/* line 4745 */
__LABEL(l_L206X3);
  sim_icache_fetch(3409 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4746 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4747 */
} /* line 4747 */
		 /* line 4748 */
  sim_icache_fetch(3412 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4750 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4751 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (418 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4752 */
l_lr_275: ;/* line 4752 */
__LABEL(l_lr_275);
  sim_icache_fetch(3418 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4754 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4755 */
} /* line 4755 */
  sim_icache_fetch(3420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L203X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4757 */
l_L204X3: ;/* line 4760 */
__LABEL(l_L204X3);
  sim_icache_fetch(3421 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4761 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4762 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4763 */
   __ADD_CYCLES(1);
} /* line 4763 */
  sim_icache_fetch(3425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4765 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4766 */
} /* line 4766 */
  sim_icache_fetch(3427 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4768 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4769 */
  sim_icache_fetch(3430 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4771 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4772 */
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4773 */
} /* line 4773 */
l_L208X3: ;/* line 4776 */
__LABEL(l_L208X3);
  sim_icache_fetch(3433 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4777 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4778 */
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4779 */
} /* line 4779 */
  sim_icache_fetch(3438 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4781 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4782 */
  sim_icache_fetch(3440 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4784 */
} /* line 4784 */
  sim_icache_fetch(3441 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4786 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4787 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4788 */
} /* line 4788 */
  sim_icache_fetch(3446 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4790 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4791 */
  sim_icache_fetch(3448 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4793 */
} /* line 4793 */
  sim_icache_fetch(3449 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4795 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4796 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4797 */
} /* line 4797 */
  sim_icache_fetch(3454 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4799 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4800 */
  sim_icache_fetch(3456 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4802 */
} /* line 4802 */
  sim_icache_fetch(3457 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4804 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4805 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4806 */
} /* line 4806 */
  sim_icache_fetch(3462 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4808 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4809 */
  sim_icache_fetch(3464 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4811 */
} /* line 4811 */
  sim_icache_fetch(3465 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4813 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4814 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4815 */
} /* line 4815 */
  sim_icache_fetch(3470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4817 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4818 */
  sim_icache_fetch(3472 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 4820 */
} /* line 4820 */
  sim_icache_fetch(3473 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4822 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4823 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4824 */
} /* line 4824 */
  sim_icache_fetch(3478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4826 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4827 */
  sim_icache_fetch(3480 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 4829 */
} /* line 4829 */
  sim_icache_fetch(3481 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4831 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4832 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4833 */
} /* line 4833 */
  sim_icache_fetch(3486 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4835 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4836 */
  sim_icache_fetch(3488 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 4838 */
} /* line 4838 */
  sim_icache_fetch(3489 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4840 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4841 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4842 */
} /* line 4842 */
  sim_icache_fetch(3494 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4844 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4845 */
  sim_icache_fetch(3496 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 4847 */
} /* line 4847 */
  sim_icache_fetch(3497 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4849 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4850 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4851 */
} /* line 4851 */
  sim_icache_fetch(3502 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4853 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4854 */
  sim_icache_fetch(3504 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 4856 */
} /* line 4856 */
  sim_icache_fetch(3505 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4858 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4859 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4860 */
} /* line 4860 */
  sim_icache_fetch(3510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4862 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4863 */
  sim_icache_fetch(3512 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 4865 */
} /* line 4865 */
  sim_icache_fetch(3513 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4867 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4868 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4869 */
} /* line 4869 */
  sim_icache_fetch(3518 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4871 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4872 */
  sim_icache_fetch(3520 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 4874 */
} /* line 4874 */
  sim_icache_fetch(3521 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4876 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4877 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4878 */
} /* line 4878 */
  sim_icache_fetch(3526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4880 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L220X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4881 */
  sim_icache_fetch(3528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 4883 */
} /* line 4883 */
  sim_icache_fetch(3529 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4885 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4886 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4887 */
} /* line 4887 */
  sim_icache_fetch(3534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4889 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L221X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4890 */
  sim_icache_fetch(3536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 4892 */
} /* line 4892 */
  sim_icache_fetch(3537 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4894 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4895 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4896 */
} /* line 4896 */
  sim_icache_fetch(3542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4898 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4899 */
  sim_icache_fetch(3544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 4901 */
} /* line 4901 */
  sim_icache_fetch(3545 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4903 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4904 */
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4905 */
} /* line 4905 */
  sim_icache_fetch(3550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4907 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L223X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4908 */
  sim_icache_fetch(3552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 4910 */
} /* line 4910 */
  sim_icache_fetch(3553 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4912 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4913 */
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4914 */
} /* line 4914 */
  sim_icache_fetch(3558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDHUs(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 4916 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4917 */
  sim_icache_fetch(3560 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 4919 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4920 */
   __GOTO(l_L208X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L208X3;
} /* line 4921 */
l_L224X3: ;/* line 4924 */
__LABEL(l_L224X3);
  sim_icache_fetch(3563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 4925 */
   __MOV(reg_r0_41, reg_r0_8); /* line 4926 */
} /* line 4926 */
  sim_icache_fetch(3565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_6); /* line 4928 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 4929 */
l_L226X3: ;/* line 4932 */
__LABEL(l_L226X3);
  sim_icache_fetch(3567 + t_thisfile.offset, 22);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __MOV(reg_r0_5, reg_r0_3); /* line 4933 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 4934 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4935 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 4936 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 4937 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 4938 */
   __CMPLEU(reg_b0_3, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 4939 */
   __CMPLEU(reg_b0_4, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 4940 */
   __CMPLEU(reg_b0_5, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 4941 */
   __CMPLEU(reg_b0_6, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 4942 */
   __CMPLEU(reg_b0_7, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 4943 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 4944 */
   __ADD(reg_r0_22, reg_r0_19, (unsigned int) -16); /* line 4945 */
} /* line 4945 */
  sim_icache_fetch(3589 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) -16); /* line 4947 */
   __ADD(reg_r0_24, reg_r0_17, (unsigned int) -16); /* line 4948 */
   __ADD(reg_r0_25, reg_r0_16, (unsigned int) -16); /* line 4949 */
   __ADD(reg_r0_26, reg_r0_15, (unsigned int) -16); /* line 4950 */
   __ADD(reg_r0_27, reg_r0_14, (unsigned int) -16); /* line 4951 */
   __ADD(reg_r0_28, reg_r0_13, (unsigned int) -16); /* line 4952 */
   __ADD(reg_r0_29, reg_r0_12, (unsigned int) -16); /* line 4953 */
   __ADD(reg_r0_30, reg_r0_11, (unsigned int) -16); /* line 4954 */
   __ADD(reg_r0_31, reg_r0_10, (unsigned int) -16); /* line 4955 */
   __ADD(reg_r0_32, reg_r0_9, (unsigned int) -16); /* line 4956 */
   __ADD(reg_r0_33, reg_r0_8, (unsigned int) -16); /* line 4957 */
   __ADD(reg_r0_34, reg_r0_7, (unsigned int) -16); /* line 4958 */
   __ADD(reg_r0_35, reg_r0_6, (unsigned int) -16); /* line 4959 */
} /* line 4959 */
  sim_icache_fetch(3602 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 4961 */
   __MOV(reg_r0_38, reg_r0_20); /* line 4962 */
   __ADD(reg_r0_37, reg_r0_20, (unsigned int) -16); /* line 4963 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 4964 */
} /* line 4964 */
  sim_icache_fetch(3606 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 4966 */
   __MOV(reg_r0_40, reg_r0_37); /* line 4967 */
} /* line 4967 */
  sim_icache_fetch(3609 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 4969 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4970 */
  sim_icache_fetch(3611 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 4972 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4973 */
   __CMPLEU(reg_b0_0, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 4974 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4975 */
   __ADD_CYCLES(1);
} /* line 4975 */
  sim_icache_fetch(3617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 4977 */
} /* line 4977 */
  sim_icache_fetch(3618 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4979 */
} /* line 4979 */
  sim_icache_fetch(3620 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 4981 */
   __CMPLEU(reg_b0_1, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 4982 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4983 */
  sim_icache_fetch(3624 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 4985 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4986 */
   __CMPLEU(reg_b0_1, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 4987 */
   __ADD(reg_r0_6, reg_r0_35, (unsigned int) -16); /* line 4988 */
   __MFB(reg_r0_4, t__i32_0); /* line 4989 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4990 */
   __ADD_CYCLES(1);
} /* line 4990 */
  sim_icache_fetch(3632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 4992 */
} /* line 4992 */
  sim_icache_fetch(3633 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 4994 */
} /* line 4994 */
  sim_icache_fetch(3635 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 4996 */
   __MTB(reg_b0_2, reg_r0_4); /* line 4997 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4998 */
  sim_icache_fetch(3638 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5000 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5001 */
   __CMPLEU(reg_b0_2, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 5002 */
   __ADD(reg_r0_7, reg_r0_34, (unsigned int) -16); /* line 5003 */
   __MFB(reg_r0_4, t__i32_0); /* line 5004 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5005 */
   __ADD_CYCLES(1);
} /* line 5005 */
  sim_icache_fetch(3646 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5007 */
} /* line 5007 */
  sim_icache_fetch(3647 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5009 */
} /* line 5009 */
  sim_icache_fetch(3649 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 5011 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5012 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5013 */
  sim_icache_fetch(3652 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 5015 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5016 */
   __CMPLEU(reg_b0_3, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 5017 */
   __ADD(reg_r0_8, reg_r0_33, (unsigned int) -16); /* line 5018 */
   __MFB(reg_r0_4, t__i32_0); /* line 5019 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5020 */
   __ADD_CYCLES(1);
} /* line 5020 */
  sim_icache_fetch(3660 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5022 */
} /* line 5022 */
  sim_icache_fetch(3661 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5024 */
} /* line 5024 */
  sim_icache_fetch(3663 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 5026 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5027 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5028 */
  sim_icache_fetch(3666 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 5030 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5031 */
   __CMPLEU(reg_b0_4, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 5032 */
   __ADD(reg_r0_9, reg_r0_32, (unsigned int) -16); /* line 5033 */
   __MFB(reg_r0_4, t__i32_0); /* line 5034 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5035 */
   __ADD_CYCLES(1);
} /* line 5035 */
  sim_icache_fetch(3674 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5037 */
} /* line 5037 */
  sim_icache_fetch(3675 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5039 */
} /* line 5039 */
  sim_icache_fetch(3677 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 5041 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5042 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5043 */
  sim_icache_fetch(3680 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 5045 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5046 */
   __CMPLEU(reg_b0_5, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 5047 */
   __ADD(reg_r0_10, reg_r0_31, (unsigned int) -16); /* line 5048 */
   __MFB(reg_r0_4, t__i32_0); /* line 5049 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5050 */
   __ADD_CYCLES(1);
} /* line 5050 */
  sim_icache_fetch(3688 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5052 */
} /* line 5052 */
  sim_icache_fetch(3689 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5054 */
} /* line 5054 */
  sim_icache_fetch(3691 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 5056 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5057 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5058 */
  sim_icache_fetch(3694 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 5060 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5061 */
   __CMPLEU(reg_b0_6, reg_r0_19, ((unsigned int) htab + (unsigned int) 4096)); /* line 5062 */
   __ADD(reg_r0_11, reg_r0_30, (unsigned int) -16); /* line 5063 */
   __MFB(reg_r0_4, t__i32_0); /* line 5064 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5065 */
   __ADD_CYCLES(1);
} /* line 5065 */
  sim_icache_fetch(3702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5067 */
} /* line 5067 */
  sim_icache_fetch(3703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5069 */
} /* line 5069 */
  sim_icache_fetch(3705 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 5071 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5072 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5073 */
  sim_icache_fetch(3708 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5075 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5076 */
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 5077 */
   __ADD(reg_r0_12, reg_r0_29, (unsigned int) -16); /* line 5078 */
   __MFB(reg_r0_4, t__i32_0); /* line 5079 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5080 */
   __ADD_CYCLES(1);
} /* line 5080 */
  sim_icache_fetch(3716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5082 */
} /* line 5082 */
  sim_icache_fetch(3717 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5084 */
} /* line 5084 */
  sim_icache_fetch(3719 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5086 */
   __MTB(reg_b0_0, reg_r0_4); /* line 5087 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5088 */
  sim_icache_fetch(3722 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5090 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5091 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5092 */
   __ADD(reg_r0_13, reg_r0_28, (unsigned int) -16); /* line 5093 */
   __MFB(reg_r0_4, t__i32_0); /* line 5094 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5095 */
   __ADD_CYCLES(1);
} /* line 5095 */
  sim_icache_fetch(3730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5097 */
} /* line 5097 */
  sim_icache_fetch(3731 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5099 */
} /* line 5099 */
  sim_icache_fetch(3733 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5101 */
   __MTB(reg_b0_1, reg_r0_4); /* line 5102 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5103 */
  sim_icache_fetch(3736 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5105 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5106 */
   __CMPLEU(reg_b0_1, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5107 */
   __ADD(reg_r0_14, reg_r0_27, (unsigned int) -16); /* line 5108 */
   __MFB(reg_r0_4, t__i32_0); /* line 5109 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5110 */
   __ADD_CYCLES(1);
} /* line 5110 */
  sim_icache_fetch(3744 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5112 */
} /* line 5112 */
  sim_icache_fetch(3745 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5114 */
} /* line 5114 */
  sim_icache_fetch(3747 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5116 */
   __MTB(reg_b0_2, reg_r0_4); /* line 5117 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5118 */
  sim_icache_fetch(3750 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5120 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5121 */
   __CMPLEU(reg_b0_2, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5122 */
   __ADD(reg_r0_15, reg_r0_26, (unsigned int) -16); /* line 5123 */
   __MFB(reg_r0_4, t__i32_0); /* line 5124 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5125 */
   __ADD_CYCLES(1);
} /* line 5125 */
  sim_icache_fetch(3758 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5127 */
} /* line 5127 */
  sim_icache_fetch(3759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5129 */
} /* line 5129 */
  sim_icache_fetch(3761 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5131 */
   __MTB(reg_b0_3, reg_r0_4); /* line 5132 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5133 */
  sim_icache_fetch(3764 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5135 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5136 */
   __CMPLEU(reg_b0_3, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5137 */
   __ADD(reg_r0_16, reg_r0_25, (unsigned int) -16); /* line 5138 */
   __MFB(reg_r0_4, t__i32_0); /* line 5139 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5140 */
   __ADD_CYCLES(1);
} /* line 5140 */
  sim_icache_fetch(3772 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5142 */
} /* line 5142 */
  sim_icache_fetch(3773 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5144 */
} /* line 5144 */
  sim_icache_fetch(3775 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5146 */
   __MTB(reg_b0_4, reg_r0_4); /* line 5147 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5148 */
  sim_icache_fetch(3778 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5150 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5151 */
   __CMPLEU(reg_b0_4, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5152 */
   __ADD(reg_r0_17, reg_r0_24, (unsigned int) -16); /* line 5153 */
   __MFB(reg_r0_4, t__i32_0); /* line 5154 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5155 */
   __ADD_CYCLES(1);
} /* line 5155 */
  sim_icache_fetch(3786 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5157 */
} /* line 5157 */
  sim_icache_fetch(3787 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5159 */
} /* line 5159 */
  sim_icache_fetch(3789 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5161 */
   __MTB(reg_b0_5, reg_r0_4); /* line 5162 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5163 */
  sim_icache_fetch(3792 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5165 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5166 */
   __CMPLEU(reg_b0_5, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5167 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) -16); /* line 5168 */
   __MFB(reg_r0_4, t__i32_0); /* line 5169 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5170 */
   __ADD_CYCLES(1);
} /* line 5170 */
  sim_icache_fetch(3800 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5172 */
} /* line 5172 */
  sim_icache_fetch(3801 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5174 */
} /* line 5174 */
  sim_icache_fetch(3803 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5176 */
   __MTB(reg_b0_6, reg_r0_4); /* line 5177 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5178 */
  sim_icache_fetch(3806 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDBU(reg_r0_20, mem_trace_ld(reg_r0_20,0,1)); /* line 5180 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5181 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5182 */
   __CMPLEU(reg_b0_6, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5183 */
   __ADD(reg_r0_19, reg_r0_22, (unsigned int) -16); /* line 5184 */
   __MFB(reg_r0_4, t__i32_0); /* line 5185 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5186 */
   __ADD_CYCLES(1);
} /* line 5186 */
  sim_icache_fetch(3815 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_36, reg_r0_2, (unsigned int) 1); /* line 5188 */
} /* line 5188 */
  sim_icache_fetch(3816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_36); /* line 5190 */
} /* line 5190 */
  sim_icache_fetch(3818 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_20); /* line 5192 */
   __MTB(reg_b0_7, reg_r0_4); /* line 5193 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L242X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5194 */
  sim_icache_fetch(3821 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __MOV(reg_r0_5, reg_r0_3); /* line 5196 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5197 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5198 */
   __CMPLEU(reg_b0_7, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5199 */
   __ADD(reg_r0_20, reg_r0_37, (unsigned int) -16); /* line 5200 */
   __MOV(reg_r0_3, reg_r0_39); /* line 5201 */
   __MFB(reg_r0_36, t__i32_0); /* line 5202 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5203 */
   __ADD_CYCLES(1);
} /* line 5203 */
  sim_icache_fetch(3831 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_38, reg_r0_2, (unsigned int) 1); /* line 5205 */
} /* line 5205 */
  sim_icache_fetch(3832 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_38); /* line 5207 */
} /* line 5207 */
  sim_icache_fetch(3834 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5209 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5210 */
  sim_icache_fetch(3836 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5212 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5213 */
   __CMPLEU(reg_b0_0, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5214 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5215 */
   __ADD_CYCLES(1);
} /* line 5215 */
  sim_icache_fetch(3842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5217 */
} /* line 5217 */
  sim_icache_fetch(3843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5219 */
} /* line 5219 */
  sim_icache_fetch(3845 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5221 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L228X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5222 */
  sim_icache_fetch(3847 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5224 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5225 */
   __CMPLEU(reg_b0_1, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5226 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5227 */
   __ADD_CYCLES(1);
} /* line 5227 */
  sim_icache_fetch(3853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5229 */
} /* line 5229 */
  sim_icache_fetch(3854 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5231 */
} /* line 5231 */
  sim_icache_fetch(3856 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5233 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L229X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5234 */
  sim_icache_fetch(3858 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5236 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5237 */
   __CMPLEU(reg_b0_2, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5238 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5239 */
   __ADD_CYCLES(1);
} /* line 5239 */
  sim_icache_fetch(3864 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5241 */
} /* line 5241 */
  sim_icache_fetch(3865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5243 */
} /* line 5243 */
  sim_icache_fetch(3867 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5245 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5246 */
  sim_icache_fetch(3869 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5248 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5249 */
   __CMPLEU(reg_b0_3, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5250 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5251 */
   __ADD_CYCLES(1);
} /* line 5251 */
  sim_icache_fetch(3875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5253 */
} /* line 5253 */
  sim_icache_fetch(3876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5255 */
} /* line 5255 */
  sim_icache_fetch(3878 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5257 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5258 */
  sim_icache_fetch(3880 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5260 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5261 */
   __CMPLEU(reg_b0_4, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5262 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5263 */
   __ADD_CYCLES(1);
} /* line 5263 */
  sim_icache_fetch(3886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5265 */
} /* line 5265 */
  sim_icache_fetch(3887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5267 */
} /* line 5267 */
  sim_icache_fetch(3889 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5269 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L232X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5270 */
  sim_icache_fetch(3891 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5272 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5273 */
   __CMPLEU(reg_b0_5, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5274 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5275 */
   __ADD_CYCLES(1);
} /* line 5275 */
  sim_icache_fetch(3897 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5277 */
} /* line 5277 */
  sim_icache_fetch(3898 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5279 */
} /* line 5279 */
  sim_icache_fetch(3900 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5281 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5282 */
  sim_icache_fetch(3902 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5284 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5285 */
   __CMPLEU(reg_b0_6, reg_r0_22, ((unsigned int) htab + (unsigned int) 4096)); /* line 5286 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5287 */
   __ADD_CYCLES(1);
} /* line 5287 */
  sim_icache_fetch(3908 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5289 */
} /* line 5289 */
  sim_icache_fetch(3909 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5291 */
} /* line 5291 */
  sim_icache_fetch(3911 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5293 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5294 */
  sim_icache_fetch(3913 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5296 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5297 */
   __MTB(reg_b0_7, reg_r0_36); /* line 5298 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5299 */
   __ADD_CYCLES(1);
} /* line 5299 */
  sim_icache_fetch(3918 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5301 */
} /* line 5301 */
  sim_icache_fetch(3919 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5303 */
} /* line 5303 */
  sim_icache_fetch(3921 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5305 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5306 */
  sim_icache_fetch(3923 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5308 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5309 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5310 */
   __ADD_CYCLES(1);
} /* line 5310 */
  sim_icache_fetch(3927 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5312 */
} /* line 5312 */
  sim_icache_fetch(3928 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5314 */
} /* line 5314 */
  sim_icache_fetch(3930 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5316 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L236X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5317 */
  sim_icache_fetch(3932 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5319 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5320 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5321 */
   __ADD_CYCLES(1);
} /* line 5321 */
  sim_icache_fetch(3936 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5323 */
} /* line 5323 */
  sim_icache_fetch(3937 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5325 */
} /* line 5325 */
  sim_icache_fetch(3939 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5327 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5328 */
  sim_icache_fetch(3941 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5330 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5331 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5332 */
   __ADD_CYCLES(1);
} /* line 5332 */
  sim_icache_fetch(3945 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5334 */
} /* line 5334 */
  sim_icache_fetch(3946 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5336 */
} /* line 5336 */
  sim_icache_fetch(3948 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5338 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5339 */
  sim_icache_fetch(3950 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5341 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5342 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5343 */
   __ADD_CYCLES(1);
} /* line 5343 */
  sim_icache_fetch(3954 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5345 */
} /* line 5345 */
  sim_icache_fetch(3955 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5347 */
} /* line 5347 */
  sim_icache_fetch(3957 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5349 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L239X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5350 */
  sim_icache_fetch(3959 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5352 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5353 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5354 */
   __ADD_CYCLES(1);
} /* line 5354 */
  sim_icache_fetch(3963 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5356 */
} /* line 5356 */
  sim_icache_fetch(3964 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5358 */
} /* line 5358 */
  sim_icache_fetch(3966 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5360 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5361 */
  sim_icache_fetch(3968 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_22, mem_trace_ld(reg_r0_22,0,1)); /* line 5363 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5364 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5365 */
   __ADD_CYCLES(1);
} /* line 5365 */
  sim_icache_fetch(3972 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5367 */
} /* line 5367 */
  sim_icache_fetch(3973 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5369 */
} /* line 5369 */
  sim_icache_fetch(3975 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_22); /* line 5371 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5372 */
  sim_icache_fetch(3977 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5374 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5375 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) -16); /* line 5376 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5377 */
   __ADD_CYCLES(1);
} /* line 5377 */
  sim_icache_fetch(3982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5379 */
} /* line 5379 */
  sim_icache_fetch(3983 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5381 */
} /* line 5381 */
  sim_icache_fetch(3985 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5383 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L242X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5385 */
  sim_icache_fetch(3987 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L226X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L226X3;
} /* line 5387 */
l_L242X3: ;/* line 5390 */
__LABEL(l_L242X3);
  sim_icache_fetch(3988 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_5, (unsigned int) -15); /* line 5391 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5392 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5393 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5394 */
l_L245X3: ;/* line 5397 */
__LABEL(l_L245X3);
  sim_icache_fetch(3994 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5398 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5399 */
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5400 */
} /* line 5400 */
  sim_icache_fetch(3999 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5402 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5403 */
   __GOTO(l_L244X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L244X3;
} /* line 5404 */
l_L241X3: ;/* line 5407 */
__LABEL(l_L241X3);
  sim_icache_fetch(4003 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5408 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5409 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5410 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5411 */
l_L240X3: ;/* line 5414 */
__LABEL(l_L240X3);
  sim_icache_fetch(4009 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -14); /* line 5415 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5416 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5417 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5418 */
l_L239X3: ;/* line 5421 */
__LABEL(l_L239X3);
  sim_icache_fetch(4015 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -13); /* line 5422 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5423 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5424 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5425 */
l_L238X3: ;/* line 5428 */
__LABEL(l_L238X3);
  sim_icache_fetch(4021 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -12); /* line 5429 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5430 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5431 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5432 */
l_L237X3: ;/* line 5435 */
__LABEL(l_L237X3);
  sim_icache_fetch(4027 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -11); /* line 5436 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5437 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5438 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5439 */
l_L236X3: ;/* line 5442 */
__LABEL(l_L236X3);
  sim_icache_fetch(4033 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -10); /* line 5443 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5444 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5445 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5446 */
l_L235X3: ;/* line 5449 */
__LABEL(l_L235X3);
  sim_icache_fetch(4039 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -9); /* line 5450 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5451 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5452 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5453 */
l_L234X3: ;/* line 5456 */
__LABEL(l_L234X3);
  sim_icache_fetch(4045 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -8); /* line 5457 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5458 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5459 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5460 */
l_L233X3: ;/* line 5463 */
__LABEL(l_L233X3);
  sim_icache_fetch(4051 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -7); /* line 5464 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5465 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5466 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5467 */
l_L232X3: ;/* line 5470 */
__LABEL(l_L232X3);
  sim_icache_fetch(4057 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -6); /* line 5471 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5472 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5473 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5474 */
l_L231X3: ;/* line 5477 */
__LABEL(l_L231X3);
  sim_icache_fetch(4063 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -5); /* line 5478 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5479 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5480 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5481 */
l_L230X3: ;/* line 5484 */
__LABEL(l_L230X3);
  sim_icache_fetch(4069 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -4); /* line 5485 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5486 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5487 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5488 */
l_L229X3: ;/* line 5491 */
__LABEL(l_L229X3);
  sim_icache_fetch(4075 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -3); /* line 5492 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5493 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5494 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5495 */
l_L228X3: ;/* line 5498 */
__LABEL(l_L228X3);
  sim_icache_fetch(4081 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -2); /* line 5499 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5500 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5501 */
   __GOTO(l_L243X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L243X3;
} /* line 5502 */
l_L227X3: ;/* line 5505 */
__LABEL(l_L227X3);
  sim_icache_fetch(4087 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -1); /* line 5506 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5507 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5508 */
} /* line 5508 */
l_L243X3: ;/* line 5510 */
__LABEL(l_L243X3);
  sim_icache_fetch(4092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5510 */
  sim_icache_fetch(4093 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5512 */
} /* line 5512 */
  sim_icache_fetch(4094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L245X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5514 */
l_L244X3: ;/* line 5516 */
__LABEL(l_L244X3);
  sim_icache_fetch(4095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5517 */
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5518 */
l_L223X3: ;/* line 5521 */
__LABEL(l_L223X3);
  sim_icache_fetch(4097 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5522 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5523 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5524 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5525 */
l_L222X3: ;/* line 5528 */
__LABEL(l_L222X3);
  sim_icache_fetch(4101 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5529 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5530 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5531 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5532 */
l_L221X3: ;/* line 5535 */
__LABEL(l_L221X3);
  sim_icache_fetch(4105 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5536 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5537 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5538 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5539 */
l_L220X3: ;/* line 5542 */
__LABEL(l_L220X3);
  sim_icache_fetch(4109 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5543 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5544 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5545 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5546 */
l_L219X3: ;/* line 5549 */
__LABEL(l_L219X3);
  sim_icache_fetch(4113 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5550 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5551 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5552 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5553 */
l_L218X3: ;/* line 5556 */
__LABEL(l_L218X3);
  sim_icache_fetch(4117 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5557 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5558 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5559 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5560 */
l_L217X3: ;/* line 5563 */
__LABEL(l_L217X3);
  sim_icache_fetch(4121 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5564 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5565 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5566 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5567 */
l_L216X3: ;/* line 5570 */
__LABEL(l_L216X3);
  sim_icache_fetch(4125 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5571 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5572 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5573 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5574 */
l_L215X3: ;/* line 5577 */
__LABEL(l_L215X3);
  sim_icache_fetch(4129 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5578 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5579 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5580 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5581 */
l_L214X3: ;/* line 5584 */
__LABEL(l_L214X3);
  sim_icache_fetch(4133 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5585 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5586 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5587 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5588 */
l_L213X3: ;/* line 5591 */
__LABEL(l_L213X3);
  sim_icache_fetch(4137 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5592 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5593 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5594 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5595 */
l_L212X3: ;/* line 5598 */
__LABEL(l_L212X3);
  sim_icache_fetch(4141 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5599 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5600 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5601 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5602 */
l_L211X3: ;/* line 5605 */
__LABEL(l_L211X3);
  sim_icache_fetch(4145 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5606 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5607 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5608 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5609 */
l_L210X3: ;/* line 5612 */
__LABEL(l_L210X3);
  sim_icache_fetch(4149 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5613 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5614 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5615 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 5616 */
l_L209X3: ;/* line 5621 */
__LABEL(l_L209X3);
  sim_icache_fetch(4153 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_41, reg_r0_8); /* line 5622 */
} /* line 5622 */
l_L225X3: ;/* line 5624 */
__LABEL(l_L225X3);
  sim_icache_fetch(4154 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5625 */
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) -15); /* line 5626 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -14); /* line 5627 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -13); /* line 5628 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -12); /* line 5629 */
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -11); /* line 5630 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -10); /* line 5631 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -9); /* line 5632 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -8); /* line 5633 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -7); /* line 5634 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -6); /* line 5635 */
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -5); /* line 5636 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -4); /* line 5637 */
} /* line 5637 */
  sim_icache_fetch(4168 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 5639 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5640 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 1); /* line 5641 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 5642 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 5643 */
} /* line 5643 */
  sim_icache_fetch(4173 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5645 */
   __GOTO(l_L226X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L226X3;
} /* line 5646 */
l_L207X3: ;/* line 5649 */
__LABEL(l_L207X3);
  sim_icache_fetch(4175 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5650 */
   __GOTO(l_L208X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L208X3;
} /* line 5651 */
l_L203X3: ;/* line 5654 */
__LABEL(l_L203X3);
  sim_icache_fetch(4177 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MOV(reg_r0_3, 0); /* line 5655 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5656 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5657 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5658 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5659 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5660 */
   __ADD_CYCLES(1);
} /* line 5660 */
  sim_icache_fetch(4183 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5663 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 365: goto l_L199X3;
    case 366: goto l_L200X3;
    case 368: goto l_lr_267;
    case 369: goto l_L201X3;
    case 370: goto l_L202X3;
    case 372: goto l_lr_271;
    case 373: goto l_L205X3;
    case 374: goto l_L206X3;
    case 376: goto l_lr_275;
    case 377: goto l_L204X3;
    case 378: goto l_L208X3;
    case 379: goto l_L224X3;
    case 380: goto l_L226X3;
    case 381: goto l_L242X3;
    case 382: goto l_L245X3;
    case 383: goto l_L241X3;
    case 384: goto l_L240X3;
    case 385: goto l_L239X3;
    case 386: goto l_L238X3;
    case 387: goto l_L237X3;
    case 388: goto l_L236X3;
    case 389: goto l_L235X3;
    case 390: goto l_L234X3;
    case 391: goto l_L233X3;
    case 392: goto l_L232X3;
    case 393: goto l_L231X3;
    case 394: goto l_L230X3;
    case 395: goto l_L229X3;
    case 396: goto l_L228X3;
    case 397: goto l_L227X3;
    case 398: goto l_L243X3;
    case 399: goto l_L244X3;
    case 400: goto l_L223X3;
    case 401: goto l_L222X3;
    case 402: goto l_L221X3;
    case 403: goto l_L220X3;
    case 404: goto l_L219X3;
    case 405: goto l_L218X3;
    case 406: goto l_L217X3;
    case 407: goto l_L216X3;
    case 408: goto l_L215X3;
    case 409: goto l_L214X3;
    case 410: goto l_L213X3;
    case 411: goto l_L212X3;
    case 412: goto l_L211X3;
    case 413: goto l_L210X3;
    case 414: goto l_L209X3;
    case 415: goto l_L225X3;
    case 416: goto l_L207X3;
    case 417: goto l_L203X3;
    case 418:
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
  reg_l0_0 = (446 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4184 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5682 */
   __LDW(reg_r0_8, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5683 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5684 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5685 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5686 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5687 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5688 */
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5689 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5690 */
   __ADD_CYCLES(1);
} /* line 5690 */
  sim_icache_fetch(4201 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPGE(reg_r0_11, reg_r0_7, reg_r0_8); /* line 5692 */
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5693 */
   __CMPGT(reg_r0_10, reg_r0_5, reg_r0_6); /* line 5694 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5695 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 5696 */
} /* line 5696 */
  sim_icache_fetch(4206 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_10); /* line 5698 */
   __CMPEQ(reg_b0_1, reg_r0_9, reg_r0_2); /* line 5699 */
} /* line 5699 */
  sim_icache_fetch(4208 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_2, reg_r0_4, reg_r0_11); /* line 5701 */
} /* line 5701 */
  sim_icache_fetch(4209 + t_thisfile.offset, 1);
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
} /* line 5703 */
  sim_icache_fetch(4210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5705 */
  sim_icache_fetch(4211 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_9); /* line 5707 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L248X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5708 */
  sim_icache_fetch(4214 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5710 */
} /* line 5710 */
l_L247X3: ;/* line 5713 */
__LABEL(l_L247X3);
  sim_icache_fetch(4216 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5714 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5715 */
   __MOV(reg_r0_5, 0); /* line 5716 */
   __MOV(reg_r0_17, reg_r0_7); /* line 5717 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5718 */
   __ADD_CYCLES(1);
} /* line 5718 */
  sim_icache_fetch(4223 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5720 */
   __SUB(reg_r0_6, 0, reg_r0_4); /* line 5721 */
   __MOV(reg_r0_18, reg_r0_4); /* line 5722 */
} /* line 5722 */
  sim_icache_fetch(4226 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5724 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5725 */
l_L250X3: ;/* line 5728 */
__LABEL(l_L250X3);
  sim_icache_fetch(4228 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5729 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5730 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5731 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5732 */
} /* line 5732 */
  sim_icache_fetch(4234 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 5734 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5735 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5736 */
  sim_icache_fetch(4237 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5738 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 5739 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 5740 */
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) 1); /* line 5741 */
} /* line 5741 */
  sim_icache_fetch(4241 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5743 */
   __CMPGE(reg_b0_2, reg_r0_2, 0); /* line 5744 */
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5745 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5746 */
} /* line 5746 */
  sim_icache_fetch(4246 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5748 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 5749 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5750 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5751 */
  sim_icache_fetch(4251 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 5753 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 5754 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5755 */
} /* line 5755 */
  sim_icache_fetch(4255 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5757 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5758 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5759 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 5760 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5761 */
} /* line 5761 */
  sim_icache_fetch(4261 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5763 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5764 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5765 */
} /* line 5765 */
  sim_icache_fetch(4264 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5767 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 5768 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 5769 */
} /* line 5769 */
l_L253X3: ;/* line 5771 */
__LABEL(l_L253X3);
  sim_icache_fetch(4267 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_4); /* line 5772 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5773 */
} /* line 5773 */
  sim_icache_fetch(4270 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_4, reg_b0_7); /* line 5775 */
} /* line 5775 */
  sim_icache_fetch(4271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 5777 */
} /* line 5777 */
  sim_icache_fetch(4272 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_4); /* line 5779 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5780 */
  sim_icache_fetch(4274 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5782 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 5783 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5784 */
  sim_icache_fetch(4277 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5786 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L255X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5787 */
  sim_icache_fetch(4280 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_15); /* line 5789 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5790 */
} /* line 5790 */
  sim_icache_fetch(4284 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5792 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5793 */
} /* line 5793 */
  sim_icache_fetch(4287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5795 */
} /* line 5795 */
  sim_icache_fetch(4288 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 5797 */
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 5798 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 5799 */
} /* line 5799 */
l_L256X3: ;/* line 5801 */
__LABEL(l_L256X3);
  sim_icache_fetch(4291 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_8); /* line 5802 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_8); /* line 5803 */
} /* line 5803 */
  sim_icache_fetch(4294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MFB(reg_r0_8, reg_b0_0); /* line 5805 */
} /* line 5805 */
  sim_icache_fetch(4295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_15, (unsigned int) 255); /* line 5807 */
} /* line 5807 */
  sim_icache_fetch(4296 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_0, reg_r0_8); /* line 5809 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5810 */
  sim_icache_fetch(4298 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5812 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5813 */
  sim_icache_fetch(4300 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5815 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L257X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5816 */
  sim_icache_fetch(4303 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 5818 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5819 */
} /* line 5819 */
  sim_icache_fetch(4307 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5821 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5822 */
} /* line 5822 */
  sim_icache_fetch(4310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5824 */
} /* line 5824 */
  sim_icache_fetch(4311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5826 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5827 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5828 */
} /* line 5828 */
l_L258X3: ;/* line 5830 */
__LABEL(l_L258X3);
  sim_icache_fetch(4314 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5831 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5832 */
} /* line 5832 */
  sim_icache_fetch(4317 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 255); /* line 5834 */
} /* line 5834 */
  sim_icache_fetch(4318 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5836 */
  sim_icache_fetch(4319 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5838 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5839 */
  sim_icache_fetch(4321 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5841 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L259X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5842 */
  sim_icache_fetch(4324 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5844 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5845 */
} /* line 5845 */
  sim_icache_fetch(4328 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5847 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5848 */
} /* line 5848 */
  sim_icache_fetch(4331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5850 */
} /* line 5850 */
  sim_icache_fetch(4332 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5852 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5853 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5854 */
} /* line 5854 */
l_L260X3: ;/* line 5856 */
__LABEL(l_L260X3);
  sim_icache_fetch(4335 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5857 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5858 */
} /* line 5858 */
  sim_icache_fetch(4338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 255); /* line 5860 */
} /* line 5860 */
  sim_icache_fetch(4339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5862 */
  sim_icache_fetch(4340 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5864 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5865 */
  sim_icache_fetch(4342 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5867 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L261X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5868 */
  sim_icache_fetch(4345 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5870 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5871 */
} /* line 5871 */
  sim_icache_fetch(4349 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5873 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5874 */
} /* line 5874 */
  sim_icache_fetch(4352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5876 */
} /* line 5876 */
  sim_icache_fetch(4353 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5878 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5879 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5880 */
} /* line 5880 */
l_L262X3: ;/* line 5882 */
__LABEL(l_L262X3);
  sim_icache_fetch(4356 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5883 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5884 */
} /* line 5884 */
  sim_icache_fetch(4359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5886 */
} /* line 5886 */
  sim_icache_fetch(4360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5888 */
  sim_icache_fetch(4361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5890 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5891 */
  sim_icache_fetch(4363 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5893 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L263X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5894 */
  sim_icache_fetch(4366 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5896 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5897 */
} /* line 5897 */
  sim_icache_fetch(4370 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5899 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5900 */
} /* line 5900 */
  sim_icache_fetch(4373 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5902 */
} /* line 5902 */
  sim_icache_fetch(4374 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5904 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5905 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5906 */
} /* line 5906 */
l_L264X3: ;/* line 5908 */
__LABEL(l_L264X3);
  sim_icache_fetch(4377 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5909 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5910 */
} /* line 5910 */
  sim_icache_fetch(4380 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5912 */
} /* line 5912 */
  sim_icache_fetch(4381 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5914 */
  sim_icache_fetch(4382 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5916 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5917 */
  sim_icache_fetch(4384 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5919 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L265X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5920 */
  sim_icache_fetch(4387 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5922 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5923 */
} /* line 5923 */
  sim_icache_fetch(4391 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5925 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5926 */
} /* line 5926 */
  sim_icache_fetch(4394 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5928 */
} /* line 5928 */
  sim_icache_fetch(4395 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5930 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5931 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 5932 */
} /* line 5932 */
l_L266X3: ;/* line 5934 */
__LABEL(l_L266X3);
  sim_icache_fetch(4398 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_4); /* line 5935 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5936 */
} /* line 5936 */
  sim_icache_fetch(4401 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5938 */
} /* line 5938 */
  sim_icache_fetch(4402 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5940 */
  sim_icache_fetch(4403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5942 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5943 */
  sim_icache_fetch(4405 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5945 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L267X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5946 */
  sim_icache_fetch(4408 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5948 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5949 */
} /* line 5949 */
  sim_icache_fetch(4412 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5951 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5952 */
} /* line 5952 */
  sim_icache_fetch(4415 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5954 */
} /* line 5954 */
  sim_icache_fetch(4416 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 5956 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 5957 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 5958 */
} /* line 5958 */
l_L268X3: ;/* line 5960 */
__LABEL(l_L268X3);
  sim_icache_fetch(4419 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_6); /* line 5961 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 5962 */
} /* line 5962 */
  sim_icache_fetch(4422 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 255); /* line 5964 */
} /* line 5964 */
  sim_icache_fetch(4423 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5966 */
  sim_icache_fetch(4424 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5968 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L251X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5969 */
  sim_icache_fetch(4426 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 5971 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L269X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5972 */
  sim_icache_fetch(4429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 5974 */
} /* line 5974 */
  sim_icache_fetch(4431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 5976 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5977 */
   __ADD_CYCLES(1);
} /* line 5977 */
  sim_icache_fetch(4433 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 5979 */
} /* line 5979 */
l_L270X3: ;/* line 5981 */
__LABEL(l_L270X3);
  sim_icache_fetch(4434 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_4); /* line 5982 */
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1), reg_r0_4); /* line 5983 */
} /* line 5983 */
  sim_icache_fetch(4437 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 5985 */
} /* line 5985 */
  sim_icache_fetch(4438 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L254X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5987 */
  sim_icache_fetch(4439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5989 */
   __GOTO(l_L250X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L250X3;
} /* line 5990 */
l_L254X3: ;/* line 5993 */
__LABEL(l_L254X3);
  sim_icache_fetch(4441 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_18, reg_r0_5); /* line 5994 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 5995 */
   __GOTO(l_L271X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L271X3;
} /* line 5996 */
l_L272X3: ;/* line 5999 */
__LABEL(l_L272X3);
  sim_icache_fetch(4444 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6000 */
   __MOV(reg_r0_7, 0); /* line 6001 */
   __SHL(reg_r0_18, reg_r0_18, (unsigned int) 3); /* line 6002 */
} /* line 6002 */
  sim_icache_fetch(4448 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 1); /* line 6004 */
} /* line 6004 */
  sim_icache_fetch(4449 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, reg_r0_18, reg_r0_2); /* line 6006 */
} /* line 6006 */
l_L246X3: ;/* line 6009 */
__LABEL(l_L246X3);
  sim_icache_fetch(4450 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6010 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 6011 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 6012 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_8); /* line 6013 */
} /* line 6013 */
  sim_icache_fetch(4456 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 6015 */
   __LDBU(reg_r0_11, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 6016 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 6017 */
   __SUB(reg_r0_9, (unsigned int) 16, reg_r0_4); /* line 6018 */
   __SUB(reg_r0_10, (unsigned int) 8, reg_r0_4); /* line 6019 */
} /* line 6019 */
  sim_icache_fetch(4464 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_7, reg_r0_2, reg_r0_7); /* line 6021 */
   __ADD(reg_r0_12, reg_r0_2, reg_r0_4); /* line 6022 */
   __LDBUs(reg_r0_14, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 6023 */
   __ADD(reg_r0_13, reg_r0_6, (unsigned int) 2); /* line 6024 */
} /* line 6024 */
  sim_icache_fetch(4468 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SHR(reg_r0_11, reg_r0_11, reg_r0_4); /* line 6026 */
   __ADD(reg_r0_2, reg_r0_12, (unsigned int) -8); /* line 6027 */
   __ADD(reg_r0_5, reg_r0_12, (unsigned int) -16); /* line 6028 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_7); /* line 6029 */
} /* line 6029 */
  sim_icache_fetch(4473 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 6031 */
   __SHL(reg_r0_14, reg_r0_14, reg_r0_10); /* line 6032 */
} /* line 6032 */
  sim_icache_fetch(4475 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 6034 */
   __SLCT(reg_r0_9, reg_b0_0, reg_r0_9, reg_r0_10); /* line 6035 */
   __OR(reg_r0_14, reg_r0_11, reg_r0_14); /* line 6036 */
   __SLCT(reg_r0_13, reg_b0_0, reg_r0_13, reg_r0_8); /* line 6037 */
} /* line 6037 */
  sim_icache_fetch(4479 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_11); /* line 6039 */
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 6040 */
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) rmask),0,1)); /* line 6041 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6042 */
   __ADD_CYCLES(1);
} /* line 6042 */
  sim_icache_fetch(4484 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __AND(reg_r0_13, reg_r0_13, reg_r0_5); /* line 6044 */
} /* line 6044 */
  sim_icache_fetch(4485 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_13, reg_r0_13, reg_r0_9); /* line 6046 */
} /* line 6046 */
  sim_icache_fetch(4486 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_14, reg_r0_13); /* line 6049 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6050 */
l_L269X3: ;/* line 6053 */
__LABEL(l_L269X3);
  sim_icache_fetch(4488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6054 */
   __GOTO(l_L270X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L270X3;
} /* line 6055 */
l_L251X3: ;/* line 6058 */
__LABEL(l_L251X3);
  sim_icache_fetch(4490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, 0); /* line 6059 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6060 */
} /* line 6060 */
l_L271X3: ;/* line 6062 */
__LABEL(l_L271X3);
  sim_icache_fetch(4492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_18, 0); /* line 6063 */
} /* line 6063 */
  sim_icache_fetch(4493 + t_thisfile.offset, 1);
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
} /* line 6065 */
  sim_icache_fetch(4494 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_18); /* line 6068 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_17); /* line 6069 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6070 */
l_L267X3: ;/* line 6073 */
__LABEL(l_L267X3);
  sim_icache_fetch(4499 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6074 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6075 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6076 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6077 */
   __ADD_CYCLES(1);
} /* line 6077 */
  sim_icache_fetch(4505 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6079 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6080 */
} /* line 6080 */
  sim_icache_fetch(4507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6082 */
   __GOTO(l_L268X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L268X3;
} /* line 6083 */
l_L265X3: ;/* line 6086 */
__LABEL(l_L265X3);
  sim_icache_fetch(4509 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6087 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6088 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6089 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6090 */
   __ADD_CYCLES(1);
} /* line 6090 */
  sim_icache_fetch(4515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6092 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6093 */
} /* line 6093 */
  sim_icache_fetch(4517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6095 */
   __GOTO(l_L266X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L266X3;
} /* line 6096 */
l_L263X3: ;/* line 6099 */
__LABEL(l_L263X3);
  sim_icache_fetch(4519 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6100 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6101 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6102 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6103 */
   __ADD_CYCLES(1);
} /* line 6103 */
  sim_icache_fetch(4525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6105 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6106 */
} /* line 6106 */
  sim_icache_fetch(4527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6108 */
   __GOTO(l_L264X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L264X3;
} /* line 6109 */
l_L261X3: ;/* line 6112 */
__LABEL(l_L261X3);
  sim_icache_fetch(4529 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6113 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6114 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6115 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6116 */
   __ADD_CYCLES(1);
} /* line 6116 */
  sim_icache_fetch(4535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6118 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6119 */
} /* line 6119 */
  sim_icache_fetch(4537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6121 */
   __GOTO(l_L262X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L262X3;
} /* line 6122 */
l_L259X3: ;/* line 6125 */
__LABEL(l_L259X3);
  sim_icache_fetch(4539 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6126 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6127 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6128 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6129 */
   __ADD_CYCLES(1);
} /* line 6129 */
  sim_icache_fetch(4545 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6131 */
   __ADD(reg_r0_7, reg_r0_4, (unsigned int) 1); /* line 6132 */
} /* line 6132 */
  sim_icache_fetch(4547 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6134 */
   __GOTO(l_L260X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L260X3;
} /* line 6135 */
l_L257X3: ;/* line 6138 */
__LABEL(l_L257X3);
  sim_icache_fetch(4549 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6139 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6140 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6141 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6142 */
   __ADD_CYCLES(1);
} /* line 6142 */
  sim_icache_fetch(4555 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) -1); /* line 6144 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 6145 */
} /* line 6145 */
  sim_icache_fetch(4557 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 6147 */
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6148 */
l_L255X3: ;/* line 6151 */
__LABEL(l_L255X3);
  sim_icache_fetch(4559 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6152 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6153 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6154 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6155 */
   __ADD_CYCLES(1);
} /* line 6155 */
  sim_icache_fetch(4565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_15, (unsigned int) -1); /* line 6157 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 6158 */
} /* line 6158 */
  sim_icache_fetch(4567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6160 */
   __GOTO(l_L256X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L256X3;
} /* line 6161 */
l_L252X3: ;/* line 6164 */
__LABEL(l_L252X3);
  sim_icache_fetch(4569 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 6165 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6166 */
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 6167 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 6168 */
} /* line 6168 */
  sim_icache_fetch(4574 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6170 */
   __CMPLT(reg_b0_5, reg_r0_12, 0); /* line 6171 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 6172 */
} /* line 6172 */
  sim_icache_fetch(4577 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGE(reg_b0_6, reg_r0_2, 0); /* line 6174 */
   __ADD(reg_r0_15, reg_r0_8, (unsigned int) 1); /* line 6175 */
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 6176 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 6177 */
} /* line 6177 */
  sim_icache_fetch(4581 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6179 */
   __GOTO(l_L253X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L253X3;
} /* line 6180 */
l_L249X3: ;/* line 6183 */
__LABEL(l_L249X3);
  sim_icache_fetch(4583 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6184 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 6185 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6186 */
} /* line 6186 */
  sim_icache_fetch(4588 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6188 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 6189 */
} /* line 6189 */
  sim_icache_fetch(4592 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_18, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6191 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6192 */
   __ADD_CYCLES(1);
} /* line 6192 */
  sim_icache_fetch(4595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_18); /* line 6194 */
} /* line 6194 */
  sim_icache_fetch(4596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6196 */
   __GOTO(l_L250X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L250X3;
} /* line 6197 */
l_L248X3: ;/* line 6200 */
__LABEL(l_L248X3);
  sim_icache_fetch(4598 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6201 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6202 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6203 */
   __ADD_CYCLES(1);
} /* line 6203 */
  sim_icache_fetch(4602 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6205 */
} /* line 6205 */
  sim_icache_fetch(4603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6207 */
} /* line 6207 */
  sim_icache_fetch(4604 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6209 */
   __GOTO(l_L247X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L247X3;
} /* line 6210 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 419: goto l_L247X3;
    case 420: goto l_L250X3;
    case 421: goto l_L253X3;
    case 422: goto l_L256X3;
    case 423: goto l_L258X3;
    case 424: goto l_L260X3;
    case 425: goto l_L262X3;
    case 426: goto l_L264X3;
    case 427: goto l_L266X3;
    case 428: goto l_L268X3;
    case 429: goto l_L270X3;
    case 430: goto l_L254X3;
    case 431: goto l_L272X3;
    case 432: goto l_L246X3;
    case 433: goto l_L269X3;
    case 434: goto l_L251X3;
    case 435: goto l_L271X3;
    case 436: goto l_L267X3;
    case 437: goto l_L265X3;
    case 438: goto l_L263X3;
    case 439: goto l_L261X3;
    case 440: goto l_L259X3;
    case 441: goto l_L257X3;
    case 442: goto l_L255X3;
    case 443: goto l_L252X3;
    case 444: goto l_L249X3;
    case 445: goto l_L248X3;
    case 446:
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
  reg_l0_0 = (449 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4607 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6232 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6233 */
} /* line 6233 */
		 /* line 6234 */
  sim_icache_fetch(4610 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6237 */
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
} /* line 6237 */
l_lr_347: ;/* line 6237 */
__LABEL(l_lr_347);
  sim_icache_fetch(4613 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6239 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6240 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6241 */
   __ADD_CYCLES(1);
} /* line 6241 */
  sim_icache_fetch(4616 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6244 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 448: goto l_lr_347;
    case 449:
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
  reg_l0_0 = (451 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4617 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6290 */
   __MOV(reg_r0_3, 0); /* line 6291 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6292 */
   __ADD_CYCLES(1);
} /* line 6292 */
  sim_icache_fetch(4621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6294 */
} /* line 6294 */
  sim_icache_fetch(4622 + t_thisfile.offset, 1);
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
} /* line 6296 */
  sim_icache_fetch(4623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6299 */
l_L273X3: ;/* line 6302 */
__LABEL(l_L273X3);
  sim_icache_fetch(4624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6305 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6305 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 450: goto l_L273X3;
    case 451:
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
  reg_l0_0 = (452 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6321 */
} /* line 6321 */
  sim_icache_fetch(4627 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6324 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 452:
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
  reg_l0_0 = (456 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4628 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6339 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6340 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6341 */
} /* line 6341 */
  sim_icache_fetch(4633 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6343 */
} /* line 6343 */
  sim_icache_fetch(4634 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6345 */
} /* line 6345 */
  sim_icache_fetch(4635 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6347 */
		 /* line 6348 */
  sim_icache_fetch(4636 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (456 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6350 */
l_lr_353: ;/* line 6350 */
__LABEL(l_lr_353);
l_L274X3: ;/* line 6352 */
__LABEL(l_L274X3);
  sim_icache_fetch(4638 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6353 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6354 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6355 */
   __ADD_CYCLES(1);
} /* line 6355 */
  sim_icache_fetch(4641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6358 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 454: goto l_lr_353;
    case 455: goto l_L274X3;
    case 456:
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
  reg_l0_0 = (469 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4642 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6404 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6405 */
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6406 */
   __MOV(reg_r0_4, (unsigned int) 2147483647); /* line 6407 */
} /* line 6407 */
  sim_icache_fetch(4649 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6409 */
} /* line 6409 */
  sim_icache_fetch(4650 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 10000); /* line 6411 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6412 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6413 */
} /* line 6413 */
  sim_icache_fetch(4655 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 6415 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6416 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L275X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6417 */
  sim_icache_fetch(4659 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L276X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6419 */
l_L277X3: ;/* line 6422 */
__LABEL(l_L277X3);
  sim_icache_fetch(4660 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6423 */
   __MOV(reg_r0_3, 0); /* line 6424 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6425 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6426 */
   __ADD_CYCLES(1);
} /* line 6426 */
  sim_icache_fetch(4665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_4, reg_r0_2); /* line 6428 */
} /* line 6428 */
  sim_icache_fetch(4666 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L278X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6430 */
  sim_icache_fetch(4667 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_4); /* line 6433 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6434 */
l_L278X3: ;/* line 6437 */
__LABEL(l_L278X3);
  sim_icache_fetch(4670 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6438 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6439 */
} /* line 6439 */
		 /* line 6440 */
  sim_icache_fetch(4674 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (469 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6442 */
l_lr_359: ;/* line 6442 */
__LABEL(l_lr_359);
  sim_icache_fetch(4676 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6444 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6445 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6446 */
} /* line 6446 */
		 /* line 6447 */
  sim_icache_fetch(4681 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6449 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6450 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (469 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6451 */
l_lr_361: ;/* line 6451 */
__LABEL(l_lr_361);
  sim_icache_fetch(4687 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6453 */
   __MOV(reg_r0_3, 0); /* line 6454 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6455 */
   __ADD_CYCLES(1);
} /* line 6455 */
  sim_icache_fetch(4690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6458 */
l_L276X3: ;/* line 6461 */
__LABEL(l_L276X3);
  sim_icache_fetch(4691 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6462 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6463 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6464 */
   __ADD_CYCLES(1);
} /* line 6464 */
		 /* line 6465 */
  sim_icache_fetch(4695 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6468 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (469 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6468 */
l_lr_364: ;/* line 6468 */
__LABEL(l_lr_364);
  sim_icache_fetch(4698 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6470 */
   __GOTO(l_L277X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L277X3;
} /* line 6471 */
l_L275X3: ;/* line 6474 */
__LABEL(l_L275X3);
  sim_icache_fetch(4700 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6475 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6476 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6477 */
   __ADD_CYCLES(1);
} /* line 6477 */
		 /* line 6478 */
  sim_icache_fetch(4705 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_2, (unsigned int) 8); /* line 6480 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (469 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6481 */
l_lr_367: ;/* line 6481 */
__LABEL(l_lr_367);
  sim_icache_fetch(4708 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 6483 */
   __GOTO(l_L277X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L277X3;
} /* line 6484 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 457: goto l_L277X3;
    case 458: goto l_L278X3;
    case 460: goto l_lr_359;
    case 462: goto l_lr_361;
    case 463: goto l_L276X3;
    case 465: goto l_lr_364;
    case 466: goto l_L275X3;
    case 468: goto l_lr_367;
    case 469:
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
  reg_l0_0 = (487 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4710 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 6503 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 6504 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6505 */
} /* line 6505 */
  sim_icache_fetch(4714 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 6507 */
} /* line 6507 */
l_L279X3: ;/* line 6510 */
__LABEL(l_L279X3);
  sim_icache_fetch(4715 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __MOV(reg_r0_3, reg_r0_2); /* line 6511 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6512 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6513 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6514 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6515 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6516 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6517 */
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6518 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6519 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6520 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6521 */
} /* line 6521 */
  sim_icache_fetch(4726 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 6523 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 6524 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 6525 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 6526 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 6527 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 6528 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 6529 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 6530 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 6531 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 6532 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 6533 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 6534 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 6535 */
} /* line 6535 */
  sim_icache_fetch(4739 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 6537 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 6538 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 6539 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L280X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6540 */
  sim_icache_fetch(4743 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 6542 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 6543 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 6544 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 6545 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 6546 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 6547 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 6548 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 6549 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 6550 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 6551 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 6552 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 6553 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6554 */
} /* line 6554 */
  sim_icache_fetch(4756 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 6556 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 6557 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 6558 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 6559 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L281X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6560 */
  sim_icache_fetch(4761 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 6562 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 6563 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 6564 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 6565 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 6566 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 6567 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 6568 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 6569 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 6570 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 6571 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 6572 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 6573 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6574 */
} /* line 6574 */
  sim_icache_fetch(4774 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 6576 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 6577 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 6578 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 6579 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6580 */
  sim_icache_fetch(4779 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_6); /* line 6582 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_6); /* line 6583 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_6); /* line 6584 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_6); /* line 6585 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_6); /* line 6586 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_6); /* line 6587 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_6); /* line 6588 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_6); /* line 6589 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_6); /* line 6590 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_6); /* line 6591 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_6); /* line 6592 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_6); /* line 6593 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6594 */
} /* line 6594 */
  sim_icache_fetch(4792 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_6); /* line 6596 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_6); /* line 6597 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_6); /* line 6598 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_6); /* line 6599 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L283X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6600 */
  sim_icache_fetch(4797 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_6); /* line 6602 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_6); /* line 6603 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_6); /* line 6604 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_6); /* line 6605 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_6); /* line 6606 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_6); /* line 6607 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_6); /* line 6608 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_6); /* line 6609 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_6); /* line 6610 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_6); /* line 6611 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_6); /* line 6612 */
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6613 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6614 */
} /* line 6614 */
  sim_icache_fetch(4810 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_6); /* line 6616 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_6); /* line 6617 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_6); /* line 6618 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_6); /* line 6619 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_6); /* line 6620 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L284X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6621 */
  sim_icache_fetch(4816 + t_thisfile.offset, 26);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_6); /* line 6623 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_6); /* line 6624 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_6); /* line 6625 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_6); /* line 6626 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_6); /* line 6627 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_6); /* line 6628 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_6); /* line 6629 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_6); /* line 6630 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_6); /* line 6631 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_6); /* line 6632 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_6); /* line 6633 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_6); /* line 6634 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_6); /* line 6635 */
} /* line 6635 */
  sim_icache_fetch(4842 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_6); /* line 6637 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_6); /* line 6638 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_6); /* line 6639 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L285X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6640 */
  sim_icache_fetch(4849 + t_thisfile.offset, 26);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_6); /* line 6642 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_6); /* line 6643 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_6); /* line 6644 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_6); /* line 6645 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_6); /* line 6646 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_6); /* line 6647 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_6); /* line 6648 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_6); /* line 6649 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_6); /* line 6650 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_6); /* line 6651 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_6); /* line 6652 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_6); /* line 6653 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_6); /* line 6654 */
} /* line 6654 */
  sim_icache_fetch(4875 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_6); /* line 6656 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_6); /* line 6657 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_6); /* line 6658 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L286X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6659 */
  sim_icache_fetch(4882 + t_thisfile.offset, 26);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_6); /* line 6661 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_6); /* line 6662 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_6); /* line 6663 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_6); /* line 6664 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_6); /* line 6665 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_6); /* line 6666 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_6); /* line 6667 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_6); /* line 6668 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_6); /* line 6669 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_6); /* line 6670 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_6); /* line 6671 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_6); /* line 6672 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_6); /* line 6673 */
} /* line 6673 */
  sim_icache_fetch(4908 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_6); /* line 6675 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_6); /* line 6676 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_6); /* line 6677 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L287X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6678 */
  sim_icache_fetch(4915 + t_thisfile.offset, 26);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_6); /* line 6680 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_6); /* line 6681 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_6); /* line 6682 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_6); /* line 6683 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_6); /* line 6684 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_6); /* line 6685 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_6); /* line 6686 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_6); /* line 6687 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_6); /* line 6688 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_6); /* line 6689 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_6); /* line 6690 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_6); /* line 6691 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_6); /* line 6692 */
} /* line 6692 */
  sim_icache_fetch(4941 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_6); /* line 6694 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_6); /* line 6695 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_6); /* line 6696 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L288X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6697 */
  sim_icache_fetch(4948 + t_thisfile.offset, 26);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_6); /* line 6699 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_6); /* line 6700 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_6); /* line 6701 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_6); /* line 6702 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_6); /* line 6703 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_6); /* line 6704 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_6); /* line 6705 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_6); /* line 6706 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_6); /* line 6707 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_6); /* line 6708 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_6); /* line 6709 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_6); /* line 6710 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_6); /* line 6711 */
} /* line 6711 */
  sim_icache_fetch(4974 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_6); /* line 6713 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_6); /* line 6714 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_6); /* line 6715 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L289X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6716 */
  sim_icache_fetch(4981 + t_thisfile.offset, 26);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_6); /* line 6718 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_6); /* line 6719 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_6); /* line 6720 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_6); /* line 6721 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_6); /* line 6722 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_6); /* line 6723 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_6); /* line 6724 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_6); /* line 6725 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_6); /* line 6726 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_6); /* line 6727 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_6); /* line 6728 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_6); /* line 6729 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_6); /* line 6730 */
} /* line 6730 */
  sim_icache_fetch(5007 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_6); /* line 6732 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_6); /* line 6733 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_6); /* line 6734 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L290X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6735 */
  sim_icache_fetch(5014 + t_thisfile.offset, 26);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_6); /* line 6737 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_6); /* line 6738 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_6); /* line 6739 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_6); /* line 6740 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_6); /* line 6741 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_6); /* line 6742 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_6); /* line 6743 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_6); /* line 6744 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_6); /* line 6745 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_6); /* line 6746 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_6); /* line 6747 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_6); /* line 6748 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_6); /* line 6749 */
} /* line 6749 */
  sim_icache_fetch(5040 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_6); /* line 6751 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_6); /* line 6752 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_6); /* line 6753 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L291X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6754 */
  sim_icache_fetch(5047 + t_thisfile.offset, 25);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_6); /* line 6756 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_6); /* line 6757 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_6); /* line 6758 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_6); /* line 6759 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_6); /* line 6760 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_6); /* line 6761 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_6); /* line 6762 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_6); /* line 6763 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_6); /* line 6764 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_6); /* line 6765 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_6); /* line 6766 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -208); /* line 6767 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -832); /* line 6768 */
} /* line 6768 */
  sim_icache_fetch(5072 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_6); /* line 6770 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_6); /* line 6771 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_6); /* line 6772 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_6); /* line 6773 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_6); /* line 6774 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 6775 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 6776 */
} /* line 6776 */
  sim_icache_fetch(5085 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L292X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6779 */
  sim_icache_fetch(5086 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L279X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L279X3;
} /* line 6781 */
l_L292X3: ;/* line 6784 */
__LABEL(l_L292X3);
  sim_icache_fetch(5087 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -768); /* line 6785 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -192); /* line 6786 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6787 */
l_L294X3: ;/* line 6790 */
__LABEL(l_L294X3);
  sim_icache_fetch(5091 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 6791 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 6792 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 6793 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 3); /* line 6794 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 4); /* line 6795 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 5); /* line 6796 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 6); /* line 6797 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 7); /* line 6798 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 6799 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 6800 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6801 */
} /* line 6801 */
  sim_icache_fetch(5102 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8); /* line 6803 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6804 */
  sim_icache_fetch(5104 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_6); /* line 6806 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6807 */
  sim_icache_fetch(5106 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_6); /* line 6809 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 9); /* line 6810 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6811 */
  sim_icache_fetch(5109 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_6); /* line 6813 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 10); /* line 6814 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6815 */
  sim_icache_fetch(5112 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_6); /* line 6817 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 11); /* line 6818 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6819 */
  sim_icache_fetch(5115 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_6); /* line 6821 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 12); /* line 6822 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6823 */
  sim_icache_fetch(5118 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_6); /* line 6825 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 13); /* line 6826 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6827 */
  sim_icache_fetch(5121 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_6); /* line 6829 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 14); /* line 6830 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6831 */
  sim_icache_fetch(5124 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_6); /* line 6833 */
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 15); /* line 6834 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 6835 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6836 */
  sim_icache_fetch(5128 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_6); /* line 6838 */
   __CMPGT(reg_b0_0, reg_r0_5, 0); /* line 6839 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6840 */
  sim_icache_fetch(5131 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_6); /* line 6842 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 1); /* line 6843 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6844 */
  sim_icache_fetch(5134 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_6); /* line 6846 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 2); /* line 6847 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6848 */
  sim_icache_fetch(5137 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_6); /* line 6850 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 3); /* line 6851 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6852 */
  sim_icache_fetch(5140 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 6854 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 4); /* line 6855 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6856 */
  sim_icache_fetch(5143 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 6858 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 5); /* line 6859 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6860 */
  sim_icache_fetch(5146 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 6862 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 6); /* line 6863 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6864 */
  sim_icache_fetch(5149 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 6866 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 7); /* line 6867 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 6868 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6869 */
  sim_icache_fetch(5153 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_6); /* line 6871 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 8); /* line 6872 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6873 */
  sim_icache_fetch(5156 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_6); /* line 6875 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 9); /* line 6876 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6877 */
  sim_icache_fetch(5159 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_6); /* line 6879 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 10); /* line 6880 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6881 */
  sim_icache_fetch(5162 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_6); /* line 6883 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 11); /* line 6884 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6885 */
  sim_icache_fetch(5165 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_6); /* line 6887 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 12); /* line 6888 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6889 */
  sim_icache_fetch(5168 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_6); /* line 6891 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 13); /* line 6892 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6893 */
  sim_icache_fetch(5171 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_6); /* line 6895 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 14); /* line 6896 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6897 */
  sim_icache_fetch(5174 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_6); /* line 6899 */
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 15); /* line 6900 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6901 */
  sim_icache_fetch(5177 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_6); /* line 6903 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6904 */
  sim_icache_fetch(5179 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_6); /* line 6906 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6907 */
  sim_icache_fetch(5181 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_6); /* line 6909 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6910 */
  sim_icache_fetch(5183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_6); /* line 6912 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6913 */
  sim_icache_fetch(5185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_6); /* line 6915 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6916 */
  sim_icache_fetch(5187 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_6); /* line 6918 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6919 */
  sim_icache_fetch(5189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_6); /* line 6921 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L295X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6922 */
  sim_icache_fetch(5191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_6); /* line 6924 */
   __GOTO(l_L294X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L294X3;
} /* line 6925 */
l_L295X3: ;/* line 6928 */
__LABEL(l_L295X3);
  sim_icache_fetch(5193 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6930 */
l_L291X3: ;/* line 6933 */
__LABEL(l_L291X3);
  sim_icache_fetch(5194 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -768); /* line 6934 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -192); /* line 6935 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6936 */
l_L290X3: ;/* line 6939 */
__LABEL(l_L290X3);
  sim_icache_fetch(5198 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -704); /* line 6940 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -176); /* line 6941 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6942 */
l_L289X3: ;/* line 6945 */
__LABEL(l_L289X3);
  sim_icache_fetch(5202 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -640); /* line 6946 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -160); /* line 6947 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6948 */
l_L288X3: ;/* line 6951 */
__LABEL(l_L288X3);
  sim_icache_fetch(5206 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -576); /* line 6952 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -144); /* line 6953 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6954 */
l_L287X3: ;/* line 6957 */
__LABEL(l_L287X3);
  sim_icache_fetch(5210 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -512); /* line 6958 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -128); /* line 6959 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6960 */
l_L286X3: ;/* line 6963 */
__LABEL(l_L286X3);
  sim_icache_fetch(5214 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -448); /* line 6964 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -112); /* line 6965 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6966 */
l_L285X3: ;/* line 6969 */
__LABEL(l_L285X3);
  sim_icache_fetch(5218 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -384); /* line 6970 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -96); /* line 6971 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6972 */
l_L284X3: ;/* line 6975 */
__LABEL(l_L284X3);
  sim_icache_fetch(5222 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -320); /* line 6976 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -80); /* line 6977 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6978 */
l_L283X3: ;/* line 6981 */
__LABEL(l_L283X3);
  sim_icache_fetch(5226 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -256); /* line 6982 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -64); /* line 6983 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6984 */
l_L282X3: ;/* line 6987 */
__LABEL(l_L282X3);
  sim_icache_fetch(5229 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 6988 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 6989 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6990 */
l_L281X3: ;/* line 6993 */
__LABEL(l_L281X3);
  sim_icache_fetch(5232 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 6994 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 6995 */
   __GOTO(l_L293X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L293X3;
} /* line 6996 */
l_L280X3: ;/* line 6999 */
__LABEL(l_L280X3);
  sim_icache_fetch(5235 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 7000 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 7001 */
} /* line 7001 */
l_L293X3: ;/* line 7003 */
__LABEL(l_L293X3);
  sim_icache_fetch(5237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 7004 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -64); /* line 7005 */
   __GOTO(l_L294X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L294X3;
} /* line 7006 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 470: goto l_L279X3;
    case 471: goto l_L292X3;
    case 472: goto l_L294X3;
    case 473: goto l_L295X3;
    case 474: goto l_L291X3;
    case 475: goto l_L290X3;
    case 476: goto l_L289X3;
    case 477: goto l_L288X3;
    case 478: goto l_L287X3;
    case 479: goto l_L286X3;
    case 480: goto l_L285X3;
    case 481: goto l_L284X3;
    case 482: goto l_L283X3;
    case 483: goto l_L282X3;
    case 484: goto l_L281X3;
    case 485: goto l_L280X3;
    case 486: goto l_L293X3;
    case 487:
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
  reg_l0_0 = (488 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5240 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7022 */
} /* line 7022 */
  sim_icache_fetch(5241 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7025 */
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

extern unsigned int version(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(version);  sim_gprof_enter(&sim_gprof_idx,"version");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (489 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(5242 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7041 */
} /* line 7041 */
  sim_icache_fetch(5243 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7044 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 489:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 5248, 0, 0, 0, 2};

