/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -o a.out" */

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
unsigned int compress_3906Xoffset[1];
unsigned int compress_3906Xbuf[3];
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
unsigned int compress_3906XBuf[216]; 
unsigned int compress_3906Xrcs_ident[6]; 
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
	(121 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(135 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(127 << 5),
	(126 << 5),
	(125 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(124 << 5),
	(139 << 5),
	(139 << 5),
	(123 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(139 << 5),
	(122 << 5)
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

unsigned int compress_3906XBuf[216] = { 
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

unsigned int compress_3906Xrcs_ident[6] = { 
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

  sim_icache_fetch(0 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 19 */
   __MOV(reg_r0_5, (unsigned int) 9); /* line 20 */
} /* line 20 */
  sim_icache_fetch(2 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_1, (unsigned int) 16); /* line 22 */
   __ADD(reg_r0_4, reg_r0_1, (unsigned int) 28); /* line 23 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_l0_0); /* line 24 */
} /* line 24 */
  sim_icache_fetch(5 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, (unsigned int) _X1PACKETX4); /* line 26 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_4); /* line 27 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_2); /* line 28 */
} /* line 28 */
		 /* line 29 */
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
} /* line 31 */
l_lr_1: ;/* line 31 */
__LABEL(l_lr_1);
  sim_icache_fetch(11 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, (unsigned int) compress_3906XBuf); /* line 33 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 34 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 35 */
} /* line 35 */
  sim_icache_fetch(15 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 37 */
   __MOV(reg_r0_6, (unsigned int) 800); /* line 38 */
} /* line 38 */
  sim_icache_fetch(18 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_2); /* line 40 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), 0); /* line 41 */
} /* line 41 */
  sim_icache_fetch(21 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 43 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_6); /* line 44 */
} /* line 44 */
		 /* line 45 */
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
} /* line 47 */
l_lr_3: ;/* line 47 */
__LABEL(l_lr_3);
		 /* line 48 */
  sim_icache_fetch(27 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 51 */
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
} /* line 51 */
l_lr_5: ;/* line 51 */
__LABEL(l_lr_5);
  sim_icache_fetch(31 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 53 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 54 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 55 */
   __ADD_CYCLES(1);
} /* line 55 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 58 */
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
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 109 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX2); /* line 110 */
} /* line 110 */
		 /* line 111 */
  sim_icache_fetch(38 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 114 */
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
} /* line 114 */
l_lr_8: ;/* line 114 */
__LABEL(l_lr_8);
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 116 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 117 */
   __ADD_CYCLES(1);
} /* line 117 */
  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Usage);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 120 */
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
  reg_l0_0 = (116 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_9, reg_r0_3, (unsigned int) 3); /* line 181 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 182 */
} /* line 182 */
  sim_icache_fetch(46 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SXTB(reg_r0_4, reg_r0_4); /* line 184 */
   __MOV(reg_r0_5, 0); /* line 185 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 186 */
   __MOV(reg_r0_2, reg_r0_3); /* line 187 */
} /* line 187 */
l_L0X3: ;/* line 190 */
__LABEL(l_L0X3);
  sim_icache_fetch(50 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 191 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 192 */
} /* line 192 */
  sim_icache_fetch(52 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_10, mem_trace_ld(reg_r0_8,0,1)); /* line 194 */
   __LDBs(reg_r0_11, mem_trace_ld(reg_r0_9,0,1)); /* line 195 */
} /* line 195 */
  sim_icache_fetch(54 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 197 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 198 */
   __CMPNE(reg_b0_2, reg_r0_7, 0); /* line 199 */
   __CMPEQ(reg_b0_3, reg_r0_7, reg_r0_4); /* line 200 */
} /* line 200 */
  sim_icache_fetch(58 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 202 */
   __CMPNE(reg_b0_0, reg_r0_10, 0); /* line 203 */
   __CMPEQ(reg_b0_1, reg_r0_10, reg_r0_4); /* line 204 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 205 */
  sim_icache_fetch(62 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_7, reg_b0_3, reg_r0_6, reg_r0_3); /* line 207 */
   __CMPNE(reg_b0_2, reg_r0_11, 0); /* line 208 */
   __CMPEQ(reg_b0_3, reg_r0_11, reg_r0_4); /* line 209 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 210 */
  sim_icache_fetch(66 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_8, reg_r0_7); /* line 212 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 213 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 214 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 215 */
  sim_icache_fetch(70 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_5, reg_b0_3, reg_r0_9, reg_r0_3); /* line 217 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 218 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 4); /* line 219 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 221 */
  sim_icache_fetch(74 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 223 */
l_L4X3: ;/* line 226 */
__LABEL(l_L4X3);
  sim_icache_fetch(75 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 229 */
l_L3X3: ;/* line 232 */
__LABEL(l_L3X3);
  sim_icache_fetch(76 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 234 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 235 */
l_L2X3: ;/* line 238 */
__LABEL(l_L2X3);
  sim_icache_fetch(78 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 241 */
l_L1X3: ;/* line 244 */
__LABEL(l_L1X3);
  sim_icache_fetch(79 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 246 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 247 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 111: goto l_L0X3;
    case 112: goto l_L4X3;
    case 113: goto l_L3X3;
    case 114: goto l_L2X3;
    case 115: goto l_L1X3;
    case 116:
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
  reg_l0_0 = (183 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(81 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 263 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 264 */
} /* line 264 */
  sim_icache_fetch(84 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_3); /* line 266 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 267 */
} /* line 267 */
  sim_icache_fetch(86 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 269 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_4); /* line 270 */
} /* line 270 */
  sim_icache_fetch(89 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 272 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 273 */
} /* line 273 */
  sim_icache_fetch(93 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 275 */
   __MOV(reg_r0_4, (unsigned int) 47); /* line 276 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_7); /* line 277 */
} /* line 277 */
		 /* line 278 */
  sim_icache_fetch(96 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 280 */
l_lr_17: ;/* line 280 */
__LABEL(l_lr_17);
  sim_icache_fetch(98 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 282 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 283 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 284 */
   __ADD_CYCLES(1);
} /* line 284 */
  sim_icache_fetch(101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 286 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 287 */
} /* line 287 */
l_L5X3: ;/* line 290 */
__LABEL(l_L5X3);
  sim_icache_fetch(103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 291 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 292 */
} /* line 292 */
  sim_icache_fetch(105 + t_thisfile.offset, 1);
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
} /* line 294 */
  sim_icache_fetch(106 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 296 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 297 */
   __ADD_CYCLES(1);
} /* line 297 */
  sim_icache_fetch(108 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 299 */
} /* line 299 */
  sim_icache_fetch(109 + t_thisfile.offset, 1);
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
} /* line 301 */
l_L8X3: ;/* line 304 */
__LABEL(l_L8X3);
  sim_icache_fetch(110 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 305 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 306 */
   __ADD_CYCLES(1);
} /* line 306 */
  sim_icache_fetch(112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 308 */
} /* line 308 */
  sim_icache_fetch(113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 310 */
} /* line 310 */
  sim_icache_fetch(114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 312 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 313 */
   __ADD_CYCLES(1);
} /* line 313 */
  sim_icache_fetch(116 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 315 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 316 */
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 317 */
} /* line 317 */
  sim_icache_fetch(119 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 319 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 320 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 321 */
  sim_icache_fetch(123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 323 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 324 */
  sim_icache_fetch(125 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 325 */
  sim_icache_fetch(126 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 327 */
l__X1XCompressXTAGX0X0: ;/* line 329 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(127 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 330 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 331 */
l__X1XCompressXTAGX0X7: ;/* line 334 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(130 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 335 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 336 */
l__X1XCompressXTAGX0X6: ;/* line 339 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(133 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 340 */
} /* line 340 */
  sim_icache_fetch(134 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 342 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 343 */
l__X1XCompressXTAGX0X5: ;/* line 346 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(137 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 347 */
} /* line 347 */
  sim_icache_fetch(138 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 349 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 350 */
l__X1XCompressXTAGX0X4: ;/* line 353 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(141 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 354 */
} /* line 354 */
  sim_icache_fetch(142 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 356 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 357 */
l__X1XCompressXTAGX0X3: ;/* line 360 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 361 */
} /* line 361 */
  sim_icache_fetch(146 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 363 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 364 */
l__X1XCompressXTAGX0X2: ;/* line 367 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(149 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 368 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 369 */
   __ADD_CYCLES(1);
} /* line 369 */
  sim_icache_fetch(151 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 371 */
} /* line 371 */
  sim_icache_fetch(152 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 373 */
} /* line 373 */
  sim_icache_fetch(153 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 375 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 376 */
   __ADD_CYCLES(1);
} /* line 376 */
  sim_icache_fetch(155 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 378 */
} /* line 378 */
  sim_icache_fetch(156 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 380 */
l_L7X3: ;/* line 382 */
__LABEL(l_L7X3);
  sim_icache_fetch(157 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 383 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 384 */
   __GOTO(l_L5X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L5X3;
} /* line 385 */
l_L10X3: ;/* line 388 */
__LABEL(l_L10X3);
  sim_icache_fetch(160 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 389 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 390 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 391 */
} /* line 391 */
  sim_icache_fetch(163 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 393 */
} /* line 393 */
  sim_icache_fetch(164 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 395 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 396 */
  sim_icache_fetch(166 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 399 */
  sim_icache_fetch(167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L7X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L7X3;
} /* line 401 */
l_L11X3: ;/* line 404 */
__LABEL(l_L11X3);
		 /* line 404 */
  sim_icache_fetch(168 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 407 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (183 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 407 */
l_lr_31: ;/* line 407 */
__LABEL(l_lr_31);
		 /* line 408 */
  sim_icache_fetch(172 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (183 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 410 */
l_lr_33: ;/* line 410 */
__LABEL(l_lr_33);
  sim_icache_fetch(174 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 412 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 413 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 414 */
   __ADD_CYCLES(1);
} /* line 414 */
  sim_icache_fetch(177 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 417 */
l__X1XCompressXTAGX0X1: ;/* line 420 */
__LABEL(l__X1XCompressXTAGX0X1);
		 /* line 420 */
  sim_icache_fetch(178 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 423 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 424 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 424 */
l_lr_36: ;/* line 424 */
__LABEL(l_lr_36);
  sim_icache_fetch(182 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 426 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 427 */
} /* line 427 */
  sim_icache_fetch(184 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 429 */
l_L12X3: ;/* line 432 */
__LABEL(l_L12X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 433 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 433 */
  sim_icache_fetch(185 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 436 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (183 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 436 */
l_lr_40: ;/* line 436 */
__LABEL(l_lr_40);
		 /* line 437 */
  sim_icache_fetch(189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (183 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 439 */
l_lr_42: ;/* line 439 */
__LABEL(l_lr_42);
  sim_icache_fetch(191 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 441 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 442 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 443 */
   __ADD_CYCLES(1);
} /* line 443 */
  sim_icache_fetch(194 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 446 */
l_L9X3: ;/* line 449 */
__LABEL(l_L9X3);
  sim_icache_fetch(195 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L12X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L12X3;
} /* line 450 */
l_L6X3: ;/* line 453 */
__LABEL(l_L6X3);
  sim_icache_fetch(196 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 454 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 455 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 456 */
} /* line 456 */
  sim_icache_fetch(200 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 458 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 459 */
} /* line 459 */
  sim_icache_fetch(203 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 461 */
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) fsize,0,4)); /* line 462 */
} /* line 462 */
  sim_icache_fetch(206 + t_thisfile.offset, 1);
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
} /* line 464 */
  sim_icache_fetch(207 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 466 */
   __CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 4096); /* line 467 */
} /* line 467 */
l_L14X3: ;/* line 469 */
__LABEL(l_L14X3);
  sim_icache_fetch(211 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 470 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 471 */
   __ADD_CYCLES(1);
} /* line 471 */
  sim_icache_fetch(214 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 12); /* line 473 */
} /* line 473 */
  sim_icache_fetch(215 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 475 */
  sim_icache_fetch(216 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 477 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 478 */
} /* line 478 */
l_L16X3: ;/* line 480 */
__LABEL(l_L16X3);
  sim_icache_fetch(220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 481 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 482 */
   __ADD_CYCLES(1);
} /* line 482 */
  sim_icache_fetch(223 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 484 */
} /* line 484 */
  sim_icache_fetch(224 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 486 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 487 */
		 /* line 488 */
  sim_icache_fetch(227 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 490 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 491 */
l_lr_48: ;/* line 491 */
__LABEL(l_lr_48);
l_L18X3: ;/* line 493 */
__LABEL(l_L18X3);
  sim_icache_fetch(231 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 494 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 495 */
} /* line 495 */
  sim_icache_fetch(235 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 497 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 498 */
} /* line 498 */
  sim_icache_fetch(239 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) -1); /* line 500 */
   __MOV(reg_r0_9, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 501 */
} /* line 501 */
  sim_icache_fetch(242 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 503 */
   __CMPGE(reg_b0_1, reg_r0_8, 0); /* line 504 */
   __LDBs(reg_r0_10, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 505 */
} /* line 505 */
  sim_icache_fetch(246 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBUs(reg_r0_6, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 507 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 508 */
} /* line 508 */
  sim_icache_fetch(250 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 510 */
   __ZXTB(reg_r0_10, reg_r0_10); /* line 511 */
} /* line 511 */
  sim_icache_fetch(253 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 513 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 514 */
} /* line 514 */
  sim_icache_fetch(256 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 516 */
   __CMPNE(reg_b0_2, reg_r0_10, reg_r0_6); /* line 517 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 518 */
  sim_icache_fetch(260 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_8); /* line 520 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L20X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 521 */
  sim_icache_fetch(263 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_9); /* line 523 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 524 */
l_L22X3: ;/* line 526 */
__LABEL(l_L22X3);
		 /* line 526 */
  sim_icache_fetch(266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (183 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 528 */
l_lr_52: ;/* line 528 */
__LABEL(l_lr_52);
  sim_icache_fetch(268 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 530 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 531 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 532 */
   __ADD_CYCLES(1);
} /* line 532 */
  sim_icache_fetch(271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 535 */
l_L21X3: ;/* line 538 */
__LABEL(l_L21X3);
  sim_icache_fetch(272 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 539 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 540 */
} /* line 540 */
  sim_icache_fetch(276 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 542 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 543 */
} /* line 543 */
  sim_icache_fetch(280 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 545 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 546 */
} /* line 546 */
  sim_icache_fetch(282 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 548 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 549 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 550 */
} /* line 550 */
  sim_icache_fetch(286 + t_thisfile.offset, 1);
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
} /* line 552 */
  sim_icache_fetch(287 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 554 */
} /* line 554 */
  sim_icache_fetch(289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 556 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 557 */
   __ADD_CYCLES(1);
} /* line 557 */
  sim_icache_fetch(291 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 559 */
} /* line 559 */
l_L24X3: ;/* line 561 */
__LABEL(l_L24X3);
  sim_icache_fetch(292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 562 */
} /* line 562 */
  sim_icache_fetch(293 + t_thisfile.offset, 1);
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
} /* line 565 */
  sim_icache_fetch(294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L22X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L22X3;
} /* line 567 */
l_L25X3: ;/* line 570 */
__LABEL(l_L25X3);
  sim_icache_fetch(295 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 571 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 572 */
} /* line 572 */
  sim_icache_fetch(299 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 574 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 575 */
} /* line 575 */
  sim_icache_fetch(302 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 577 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 578 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 579 */
} /* line 579 */
  sim_icache_fetch(306 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 581 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 582 */
} /* line 582 */
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 584 */
  sim_icache_fetch(310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 586 */
} /* line 586 */
  sim_icache_fetch(312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 588 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 589 */
   __ADD_CYCLES(1);
} /* line 589 */
  sim_icache_fetch(314 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 591 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 592 */
} /* line 592 */
l_L27X3: ;/* line 594 */
__LABEL(l_L27X3);
  sim_icache_fetch(317 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 595 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 596 */
} /* line 596 */
  sim_icache_fetch(319 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 598 */
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 599 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 600 */
} /* line 600 */
  sim_icache_fetch(323 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 602 */
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 603 */
} /* line 603 */
  sim_icache_fetch(327 + t_thisfile.offset, 1);
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
} /* line 605 */
		 /* line 606 */
  sim_icache_fetch(328 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (183 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 608 */
l_lr_58: ;/* line 608 */
__LABEL(l_lr_58);
  sim_icache_fetch(330 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 610 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 611 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 612 */
   __ADD_CYCLES(1);
} /* line 612 */
  sim_icache_fetch(333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 615 */
l_L19X3: ;/* line 618 */
__LABEL(l_L19X3);
		 /* line 618 */
  sim_icache_fetch(334 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 620 */
l_lr_61: ;/* line 620 */
__LABEL(l_lr_61);
  sim_icache_fetch(336 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 622 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 623 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 624 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 625 */
   __ADD_CYCLES(1);
} /* line 625 */
  sim_icache_fetch(340 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 628 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 629 */
l_L26X3: ;/* line 632 */
__LABEL(l_L26X3);
  sim_icache_fetch(343 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 633 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 634 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 635 */
} /* line 635 */
  sim_icache_fetch(347 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 637 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 639 */
} /* line 639 */
  sim_icache_fetch(351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L27X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L27X3;
} /* line 641 */
l_L23X3: ;/* line 644 */
__LABEL(l_L23X3);
  sim_icache_fetch(352 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 645 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 646 */
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 647 */
l_L20X3: ;/* line 650 */
__LABEL(l_L20X3);
  sim_icache_fetch(356 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_10, (unsigned int) -1); /* line 651 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 652 */
} /* line 652 */
  sim_icache_fetch(359 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_10, reg_r0_6); /* line 654 */
} /* line 654 */
  sim_icache_fetch(360 + t_thisfile.offset, 1);
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
} /* line 657 */
  sim_icache_fetch(361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L22X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L22X3;
} /* line 659 */
l_L17X3: ;/* line 662 */
__LABEL(l_L17X3);
  sim_icache_fetch(362 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 663 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 664 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 665 */
   __ADD_CYCLES(1);
} /* line 665 */
  sim_icache_fetch(367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 667 */
} /* line 667 */
  sim_icache_fetch(369 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 669 */
		 /* line 670 */
  sim_icache_fetch(370 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 672 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 673 */
l_lr_67: ;/* line 673 */
__LABEL(l_lr_67);
  sim_icache_fetch(374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L18X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L18X3;
} /* line 675 */
l_L28X3: ;/* line 678 */
__LABEL(l_L28X3);
  sim_icache_fetch(375 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 679 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 680 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 681 */
   __ADD_CYCLES(1);
} /* line 681 */
  sim_icache_fetch(380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 683 */
} /* line 683 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
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
} /* line 685 */
		 /* line 686 */
  sim_icache_fetch(383 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 688 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 689 */
l_lr_70: ;/* line 689 */
__LABEL(l_lr_70);
  sim_icache_fetch(387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L18X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L18X3;
} /* line 691 */
l_L29X3: ;/* line 694 */
__LABEL(l_L29X3);
  sim_icache_fetch(388 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 695 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 696 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 697 */
   __ADD_CYCLES(1);
} /* line 697 */
  sim_icache_fetch(393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 699 */
} /* line 699 */
  sim_icache_fetch(395 + t_thisfile.offset, 1);
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
} /* line 701 */
		 /* line 702 */
  sim_icache_fetch(396 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 704 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 705 */
l_lr_73: ;/* line 705 */
__LABEL(l_lr_73);
  sim_icache_fetch(400 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L18X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L18X3;
} /* line 707 */
l_L30X3: ;/* line 710 */
__LABEL(l_L30X3);
  sim_icache_fetch(401 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 711 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 712 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 713 */
   __ADD_CYCLES(1);
} /* line 713 */
  sim_icache_fetch(406 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 715 */
} /* line 715 */
  sim_icache_fetch(408 + t_thisfile.offset, 1);
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
} /* line 717 */
		 /* line 718 */
  sim_icache_fetch(409 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 720 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 721 */
l_lr_76: ;/* line 721 */
__LABEL(l_lr_76);
  sim_icache_fetch(413 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L18X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L18X3;
} /* line 723 */
l_L31X3: ;/* line 726 */
__LABEL(l_L31X3);
		 /* line 726 */
  sim_icache_fetch(414 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (183 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 728 */
l_lr_79: ;/* line 728 */
__LABEL(l_lr_79);
  sim_icache_fetch(416 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L18X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L18X3;
} /* line 730 */
l_L15X3: ;/* line 733 */
__LABEL(l_L15X3);
  sim_icache_fetch(417 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 734 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 735 */
} /* line 735 */
  sim_icache_fetch(420 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 737 */
   __GOTO(l_L16X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L16X3;
} /* line 738 */
l_L13X3: ;/* line 741 */
__LABEL(l_L13X3);
  sim_icache_fetch(423 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 4096); /* line 742 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 743 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 745 */
} /* line 745 */
  sim_icache_fetch(427 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L14X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L14X3;
} /* line 747 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 118: goto l_lr_17;
    case 119: goto l_L5X3;
    case 120: goto l_L8X3;
    case 121: goto l__X1XCompressXTAGX0X0;
    case 122: goto l__X1XCompressXTAGX0X7;
    case 123: goto l__X1XCompressXTAGX0X6;
    case 124: goto l__X1XCompressXTAGX0X5;
    case 125: goto l__X1XCompressXTAGX0X4;
    case 126: goto l__X1XCompressXTAGX0X3;
    case 127: goto l__X1XCompressXTAGX0X2;
    case 128: goto l_L7X3;
    case 129: goto l_L10X3;
    case 130: goto l_L11X3;
    case 132: goto l_lr_31;
    case 134: goto l_lr_33;
    case 135: goto l__X1XCompressXTAGX0X1;
    case 137: goto l_lr_36;
    case 138: goto l_L12X3;
    case 139: goto l__X1XCompressXTAGX0XDEFAULT;
    case 141: goto l_lr_40;
    case 143: goto l_lr_42;
    case 144: goto l_L9X3;
    case 145: goto l_L6X3;
    case 146: goto l_L14X3;
    case 147: goto l_L16X3;
    case 149: goto l_lr_48;
    case 150: goto l_L18X3;
    case 151: goto l_L22X3;
    case 153: goto l_lr_52;
    case 154: goto l_L21X3;
    case 155: goto l_L24X3;
    case 156: goto l_L25X3;
    case 157: goto l_L27X3;
    case 159: goto l_lr_58;
    case 160: goto l_L19X3;
    case 162: goto l_lr_61;
    case 163: goto l_L26X3;
    case 164: goto l_L23X3;
    case 165: goto l_L20X3;
    case 166: goto l_L17X3;
    case 168: goto l_lr_67;
    case 169: goto l_L28X3;
    case 171: goto l_lr_70;
    case 172: goto l_L29X3;
    case 174: goto l_lr_73;
    case 175: goto l_L30X3;
    case 177: goto l_lr_76;
    case 178: goto l_L31X3;
    case 180: goto l_lr_79;
    case 181: goto l_L15X3;
    case 182: goto l_L13X3;
    case 183:
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
  reg_l0_0 = (229 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(428 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 885 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 886 */
} /* line 886 */
  sim_icache_fetch(431 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_8, (unsigned int) 9); /* line 888 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 889 */
   __MOV(reg_r0_6, (unsigned int) 3); /* line 890 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 891 */
} /* line 891 */
  sim_icache_fetch(435 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 893 */
   __MOV(reg_r0_4, 0); /* line 894 */
   __MOV(reg_r0_9, (unsigned int) 10000); /* line 895 */
} /* line 895 */
  sim_icache_fetch(439 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) 511); /* line 897 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 898 */
l_L33X3: ;/* line 900 */
__LABEL(l_L33X3);
  sim_icache_fetch(442 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 901 */
   __MOV(reg_r0_11, (unsigned int) 257); /* line 902 */
} /* line 902 */
  sim_icache_fetch(446 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_12, mem_trace_ld((unsigned int) buflen,0,4)); /* line 904 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) bufp,0,4)); /* line 905 */
} /* line 905 */
  sim_icache_fetch(450 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_10, 0); /* line 907 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 908 */
} /* line 908 */
  sim_icache_fetch(453 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_5); /* line 910 */
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, (unsigned int) 256); /* line 911 */
} /* line 911 */
  sim_icache_fetch(457 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) -1); /* line 913 */
   __ADD(reg_r0_5, reg_r0_13, (unsigned int) 1); /* line 914 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 915 */
} /* line 915 */
  sim_icache_fetch(461 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_3906Xoffset,0,4), 0); /* line 917 */
   __CMPGE(reg_b0_0, reg_r0_12, 0); /* line 918 */
} /* line 918 */
  sim_icache_fetch(464 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 920 */
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 921 */
} /* line 921 */
  sim_icache_fetch(468 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 923 */
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 924 */
} /* line 924 */
  sim_icache_fetch(472 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 926 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_9); /* line 927 */
} /* line 927 */
  sim_icache_fetch(476 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_8); /* line 929 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 930 */
} /* line 930 */
  sim_icache_fetch(480 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_12); /* line 932 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 933 */
  sim_icache_fetch(483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 935 */
} /* line 935 */
  sim_icache_fetch(485 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 937 */
   __MOV(reg_r0_5, reg_l0_0); /* line 938 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 939 */
   __ADD_CYCLES(1);
} /* line 939 */
  sim_icache_fetch(488 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_13, reg_r0_13); /* line 941 */
} /* line 941 */
l_L35X3: ;/* line 943 */
__LABEL(l_L35X3);
  sim_icache_fetch(489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_13); /* line 944 */
} /* line 944 */
l_L36X3: ;/* line 947 */
__LABEL(l_L36X3);
  sim_icache_fetch(490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 948 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 949 */
} /* line 949 */
  sim_icache_fetch(492 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 951 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 952 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 953 */
  sim_icache_fetch(495 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 955 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 956 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 957 */
  sim_icache_fetch(498 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 959 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 960 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L39X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 961 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
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
} /* line 963 */
  sim_icache_fetch(502 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 965 */
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 966 */
l_L40X3: ;/* line 969 */
__LABEL(l_L40X3);
  sim_icache_fetch(504 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 970 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 971 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 972 */
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 973 */
l_L42X3: ;/* line 976 */
__LABEL(l_L42X3);
  sim_icache_fetch(508 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 977 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 978 */
} /* line 978 */
  sim_icache_fetch(512 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) in_count,0,4)); /* line 980 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 981 */
} /* line 981 */
  sim_icache_fetch(516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 983 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 984 */
} /* line 984 */
  sim_icache_fetch(518 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 986 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 987 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 988 */
} /* line 988 */
  sim_icache_fetch(522 + t_thisfile.offset, 1);
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
} /* line 990 */
  sim_icache_fetch(523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 992 */
} /* line 992 */
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 994 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 995 */
   __ADD_CYCLES(1);
} /* line 995 */
  sim_icache_fetch(527 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 997 */
} /* line 997 */
l_L44X3: ;/* line 999 */
__LABEL(l_L44X3);
  sim_icache_fetch(528 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1000 */
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1001 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_7); /* line 1002 */
} /* line 1002 */
  sim_icache_fetch(531 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_8); /* line 1004 */
   __XOR(reg_r0_2, reg_r0_8, reg_r0_3); /* line 1005 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1006 */
  sim_icache_fetch(534 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1008 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1009 */
} /* line 1009 */
  sim_icache_fetch(538 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_9); /* line 1011 */
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1012 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1013 */
   __ADD_CYCLES(1);
} /* line 1013 */
  sim_icache_fetch(542 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1015 */
} /* line 1015 */
  sim_icache_fetch(543 + t_thisfile.offset, 1);
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
} /* line 1017 */
  sim_icache_fetch(544 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_8, mem_trace_ld(reg_r0_10,0,2)); /* line 1019 */
} /* line 1019 */
  sim_icache_fetch(545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L42X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L42X3;
} /* line 1021 */
l_L46X3: ;/* line 1024 */
__LABEL(l_L46X3);
  sim_icache_fetch(546 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_9, reg_r0_2, (unsigned int) htab); /* line 1025 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1026 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_7); /* line 1027 */
} /* line 1027 */
  sim_icache_fetch(550 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1029 */
   __MOV(reg_r0_3, reg_r0_8); /* line 1030 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1031 */
} /* line 1031 */
  sim_icache_fetch(553 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_9, mem_trace_ld(reg_r0_9,0,4)); /* line 1033 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1034 */
   __ADD_CYCLES(1);
} /* line 1034 */
  sim_icache_fetch(555 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_9, 0); /* line 1036 */
} /* line 1036 */
  sim_icache_fetch(556 + t_thisfile.offset, 1);
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
} /* line 1038 */
l_L48X3: ;/* line 1040 */
__LABEL(l_L48X3);
		 /* line 1040 */
  sim_icache_fetch(557 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (229 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1042 */
l_lr_92: ;/* line 1042 */
__LABEL(l_lr_92);
  sim_icache_fetch(559 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1044 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1045 */
} /* line 1045 */
  sim_icache_fetch(562 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1047 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1048 */
} /* line 1048 */
  sim_icache_fetch(566 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1050 */
   __MOV(reg_r0_8, reg_r0_6); /* line 1051 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1052 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1053 */
} /* line 1053 */
  sim_icache_fetch(570 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1055 */
   __ADD(reg_r0_11, reg_r0_9, (unsigned int) 1); /* line 1056 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1057 */
} /* line 1057 */
  sim_icache_fetch(573 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1059 */
   __SH2ADD(reg_r0_12, reg_r0_2, (unsigned int) htab); /* line 1060 */
} /* line 1060 */
  sim_icache_fetch(577 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1062 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1063 */
  sim_icache_fetch(580 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1065 */
   __STH(mem_trace_st(reg_r0_10,0,2), reg_r0_9); /* line 1066 */
} /* line 1066 */
  sim_icache_fetch(583 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_12,0,4), reg_r0_5); /* line 1068 */
   __GOTO(l_L42X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L42X3;
} /* line 1069 */
l_L49X3: ;/* line 1072 */
__LABEL(l_L49X3);
  sim_icache_fetch(585 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_7); /* line 1073 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_8); /* line 1074 */
} /* line 1074 */
  sim_icache_fetch(587 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1076 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1077 */
} /* line 1077 */
  sim_icache_fetch(591 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(593 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1081 */
} /* line 1081 */
  sim_icache_fetch(594 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1083 */
} /* line 1083 */
  sim_icache_fetch(595 + t_thisfile.offset, 1);
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
} /* line 1085 */
		 /* line 1086 */
  sim_icache_fetch(596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (229 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1088 */
l_lr_95: ;/* line 1088 */
__LABEL(l_lr_95);
  sim_icache_fetch(598 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1090 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1091 */
} /* line 1091 */
  sim_icache_fetch(600 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L42X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L42X3;
} /* line 1093 */
l_L50X3: ;/* line 1096 */
__LABEL(l_L50X3);
  sim_icache_fetch(601 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1097 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1098 */
} /* line 1098 */
  sim_icache_fetch(603 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L42X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L42X3;
} /* line 1100 */
l_L47X3: ;/* line 1103 */
__LABEL(l_L47X3);
  sim_icache_fetch(604 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1104 */
   __MOV(reg_r0_11, reg_r0_8); /* line 1105 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1106 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1107 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1108 */
   __ADD_CYCLES(1);
} /* line 1108 */
  sim_icache_fetch(609 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1110 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1111 */
} /* line 1111 */
  sim_icache_fetch(611 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1113 */
} /* line 1113 */
l_L51X3: ;/* line 1116 */
__LABEL(l_L51X3);
  sim_icache_fetch(612 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1117 */
} /* line 1117 */
  sim_icache_fetch(613 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1119 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1120 */
} /* line 1120 */
  sim_icache_fetch(615 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1122 */
} /* line 1122 */
  sim_icache_fetch(616 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1124 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1125 */
} /* line 1125 */
  sim_icache_fetch(619 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1127 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1128 */
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1129 */
} /* line 1129 */
  sim_icache_fetch(622 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1131 */
} /* line 1131 */
  sim_icache_fetch(623 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1133 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1134 */
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1135 */
} /* line 1135 */
  sim_icache_fetch(627 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1137 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1138 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1139 */
  sim_icache_fetch(630 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1141 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1142 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L53X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1143 */
  sim_icache_fetch(633 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1145 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1146 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1147 */
} /* line 1147 */
  sim_icache_fetch(636 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1149 */
   __SUB(reg_r0_9, reg_r0_8, reg_r0_3); /* line 1150 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1151 */
  sim_icache_fetch(640 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1153 */
   __CMPGE(reg_b0_0, reg_r0_9, 0); /* line 1154 */
   __ADD(reg_r0_10, reg_r0_4, reg_r0_9); /* line 1155 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L55X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1156 */
  sim_icache_fetch(644 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_9, reg_r0_10); /* line 1158 */
} /* line 1158 */
  sim_icache_fetch(645 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1160 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1161 */
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1162 */
} /* line 1162 */
  sim_icache_fetch(649 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1164 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1165 */
  sim_icache_fetch(651 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1167 */
  sim_icache_fetch(652 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 1169 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 1170 */
} /* line 1170 */
  sim_icache_fetch(654 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1172 */
  sim_icache_fetch(655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1175 */
  sim_icache_fetch(656 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L51X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L51X3;
} /* line 1177 */
l_L59X3: ;/* line 1180 */
__LABEL(l_L59X3);
  sim_icache_fetch(657 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1181 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1182 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1183 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1185 */
} /* line 1185 */
  sim_icache_fetch(661 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1187 */
l_L58X3: ;/* line 1191 */
__LABEL(l_L58X3);
  sim_icache_fetch(662 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_57, reg_r0_4); /* line 1192 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1193 */
   __GOTO(l_L60X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L60X3;
} /* line 1194 */
l_L57X3: ;/* line 1197 */
__LABEL(l_L57X3);
  sim_icache_fetch(665 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 1198 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1199 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1200 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1201 */
} /* line 1201 */
  sim_icache_fetch(669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1203 */
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1204 */
l_L56X3: ;/* line 1207 */
__LABEL(l_L56X3);
  sim_icache_fetch(671 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_8); /* line 1208 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1209 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1210 */
   __GOTO(l_L60X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L60X3;
} /* line 1211 */
l_L55X3: ;/* line 1214 */
__LABEL(l_L55X3);
  sim_icache_fetch(675 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 1215 */
   __MOV(reg_r0_3, reg_r0_11); /* line 1216 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1217 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1218 */
} /* line 1218 */
  sim_icache_fetch(679 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1220 */
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1221 */
l_L54X3: ;/* line 1224 */
__LABEL(l_L54X3);
  sim_icache_fetch(681 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, reg_r0_7); /* line 1225 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1226 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1227 */
   __GOTO(l_L60X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L60X3;
} /* line 1228 */
l_L53X3: ;/* line 1232 */
__LABEL(l_L53X3);
  sim_icache_fetch(685 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_11); /* line 1233 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1234 */
   __MOV(reg_r0_57, reg_r0_4); /* line 1235 */
} /* line 1235 */
  sim_icache_fetch(688 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1237 */
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1238 */
l_L52X3: ;/* line 1242 */
__LABEL(l_L52X3);
  sim_icache_fetch(690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 1243 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1244 */
} /* line 1244 */
l_L60X3: ;/* line 1246 */
__LABEL(l_L60X3);
  sim_icache_fetch(692 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 1247 */
} /* line 1247 */
  sim_icache_fetch(694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_8, mem_trace_ld(reg_r0_2,0,2)); /* line 1249 */
} /* line 1249 */
  sim_icache_fetch(695 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L42X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L42X3;
} /* line 1251 */
l_L45X3: ;/* line 1254 */
__LABEL(l_L45X3);
		 /* line 1254 */
  sim_icache_fetch(696 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_8); /* line 1257 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (229 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1257 */
l_lr_110: ;/* line 1257 */
__LABEL(l_lr_110);
  sim_icache_fetch(699 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1259 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 1260 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1261 */
   __ADD_CYCLES(1);
} /* line 1261 */
  sim_icache_fetch(703 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1263 */
} /* line 1263 */
		 /* line 1264 */
  sim_icache_fetch(704 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 1266 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (229 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1267 */
l_lr_112: ;/* line 1267 */
__LABEL(l_lr_112);
  sim_icache_fetch(708 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 1269 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 1270 */
} /* line 1270 */
  sim_icache_fetch(712 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1272 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1273 */
} /* line 1273 */
  sim_icache_fetch(716 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 1275 */
   __MOV(reg_r0_3, 0); /* line 1276 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 1277 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1278 */
} /* line 1278 */
  sim_icache_fetch(720 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, reg_r0_7); /* line 1280 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1281 */
l_L62X3: ;/* line 1283 */
__LABEL(l_L62X3);
  sim_icache_fetch(722 + t_thisfile.offset, 1);
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
} /* line 1284 */
  sim_icache_fetch(723 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 1286 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1287 */
} /* line 1287 */
l_L64X3: ;/* line 1289 */
__LABEL(l_L64X3);
  sim_icache_fetch(726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1291 */
l_L63X3: ;/* line 1294 */
__LABEL(l_L63X3);
  sim_icache_fetch(727 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 1295 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1296 */
   __GOTO(l_L64X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L64X3;
} /* line 1297 */
l_L61X3: ;/* line 1300 */
__LABEL(l_L61X3);
  sim_icache_fetch(730 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1301 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1302 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1303 */
   __ADD_CYCLES(1);
} /* line 1303 */
		 /* line 1304 */
  sim_icache_fetch(735 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 1306 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (229 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1307 */
l_lr_118: ;/* line 1307 */
__LABEL(l_lr_118);
  sim_icache_fetch(738 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1309 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1310 */
} /* line 1310 */
  sim_icache_fetch(742 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 1312 */
   __MOV(reg_r0_3, 0); /* line 1313 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1314 */
} /* line 1314 */
  sim_icache_fetch(745 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, reg_r0_7); /* line 1316 */
   __GOTO(l_L62X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L62X3;
} /* line 1317 */
l_L43X3: ;/* line 1320 */
__LABEL(l_L43X3);
  sim_icache_fetch(747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 1321 */
   __GOTO(l_L44X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L44X3;
} /* line 1322 */
l_L39X3: ;/* line 1325 */
__LABEL(l_L39X3);
  sim_icache_fetch(749 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 1326 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1327 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1328 */
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 1329 */
l_L38X3: ;/* line 1332 */
__LABEL(l_L38X3);
  sim_icache_fetch(753 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 1333 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1334 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1335 */
   __GOTO(l_L41X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L41X3;
} /* line 1336 */
l_L37X3: ;/* line 1340 */
__LABEL(l_L37X3);
  sim_icache_fetch(757 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1341 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1342 */
} /* line 1342 */
l_L41X3: ;/* line 1344 */
__LABEL(l_L41X3);
  sim_icache_fetch(759 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1345 */
   __SUB(reg_r0_7, (unsigned int) 8, reg_r0_4); /* line 1346 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1347 */
} /* line 1347 */
  sim_icache_fetch(763 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_7); /* line 1349 */
} /* line 1349 */
		 /* line 1350 */
  sim_icache_fetch(764 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 1353 */
   __MOV(reg_r0_3, reg_r0_2); /* line 1354 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (229 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1354 */
l_lr_125: ;/* line 1354 */
__LABEL(l_lr_125);
  sim_icache_fetch(768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1356 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1357 */
} /* line 1357 */
  sim_icache_fetch(770 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 1359 */
} /* line 1359 */
  sim_icache_fetch(771 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L42X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L42X3;
} /* line 1361 */
l_L34X3: ;/* line 1364 */
__LABEL(l_L34X3);
  sim_icache_fetch(772 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_13, (unsigned int) -1); /* line 1365 */
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1366 */
} /* line 1366 */
  sim_icache_fetch(774 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L35X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L35X3;
} /* line 1368 */
l_L32X3: ;/* line 1371 */
__LABEL(l_L32X3);
  sim_icache_fetch(775 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_3, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 1372 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1373 */
} /* line 1373 */
  sim_icache_fetch(779 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1375 */
   __MOV(reg_r0_8, (unsigned int) 9); /* line 1376 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1377 */
} /* line 1377 */
  sim_icache_fetch(782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_2, (unsigned int) 1); /* line 1379 */
} /* line 1379 */
  sim_icache_fetch(783 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 1381 */
} /* line 1381 */
  sim_icache_fetch(785 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 1383 */
} /* line 1383 */
  sim_icache_fetch(786 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1385 */
   __LDBU(reg_r0_3, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 1386 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1387 */
   __ADD_CYCLES(1);
} /* line 1387 */
  sim_icache_fetch(791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_2, (unsigned int) 1); /* line 1389 */
} /* line 1389 */
  sim_icache_fetch(792 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 1391 */
} /* line 1391 */
  sim_icache_fetch(794 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 1393 */
} /* line 1393 */
  sim_icache_fetch(795 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1395 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1396 */
} /* line 1396 */
  sim_icache_fetch(799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1398 */
} /* line 1398 */
  sim_icache_fetch(801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_2, (unsigned int) 1); /* line 1400 */
} /* line 1400 */
  sim_icache_fetch(802 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_11); /* line 1402 */
   __OR(reg_r0_3, reg_r0_3, reg_r0_10); /* line 1403 */
} /* line 1403 */
  sim_icache_fetch(805 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 1405 */
   __GOTO(l_L33X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L33X3;
} /* line 1406 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 184: goto l_L33X3;
    case 185: goto l_L35X3;
    case 186: goto l_L36X3;
    case 187: goto l_L40X3;
    case 188: goto l_L42X3;
    case 189: goto l_L44X3;
    case 190: goto l_L46X3;
    case 191: goto l_L48X3;
    case 193: goto l_lr_92;
    case 194: goto l_L49X3;
    case 196: goto l_lr_95;
    case 197: goto l_L50X3;
    case 198: goto l_L47X3;
    case 199: goto l_L51X3;
    case 200: goto l_L59X3;
    case 201: goto l_L58X3;
    case 202: goto l_L57X3;
    case 203: goto l_L56X3;
    case 204: goto l_L55X3;
    case 205: goto l_L54X3;
    case 206: goto l_L53X3;
    case 207: goto l_L52X3;
    case 208: goto l_L60X3;
    case 209: goto l_L45X3;
    case 211: goto l_lr_110;
    case 213: goto l_lr_112;
    case 214: goto l_L62X3;
    case 215: goto l_L64X3;
    case 216: goto l_L63X3;
    case 217: goto l_L61X3;
    case 219: goto l_lr_118;
    case 220: goto l_L43X3;
    case 221: goto l_L39X3;
    case 222: goto l_L38X3;
    case 223: goto l_L37X3;
    case 224: goto l_L41X3;
    case 226: goto l_lr_125;
    case 227: goto l_L34X3;
    case 228: goto l_L32X3;
    case 229:
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
  reg_l0_0 = (249 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1425 */
} /* line 1425 */
  sim_icache_fetch(809 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1427 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1428 */
} /* line 1428 */
  sim_icache_fetch(812 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 1430 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 1431 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1432 */
  sim_icache_fetch(815 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 1434 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 1435 */
   __SUB(reg_r0_9, (unsigned int) 8, reg_r0_6); /* line 1436 */
} /* line 1436 */
  sim_icache_fetch(819 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_11, mem_trace_ld((reg_r0_7 + (unsigned int) compress_3906Xbuf),0,1)); /* line 1438 */
   __LDBU(reg_r0_10, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 1439 */
} /* line 1439 */
  sim_icache_fetch(823 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_12, reg_r0_7, (unsigned int) compress_3906Xbuf); /* line 1441 */
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 1442 */
   __SHR(reg_r0_3, reg_r0_3, reg_r0_9); /* line 1443 */
} /* line 1443 */
  sim_icache_fetch(827 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_9, reg_r0_7, ((unsigned int) compress_3906Xbuf + (unsigned int) 1)); /* line 1445 */
   __AND(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1446 */
   __MOV(reg_r0_8, reg_r0_3); /* line 1447 */
} /* line 1447 */
  sim_icache_fetch(831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1449 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 1450 */
} /* line 1450 */
  sim_icache_fetch(833 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_3906Xbuf),0,1), reg_r0_2); /* line 1452 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1453 */
} /* line 1453 */
  sim_icache_fetch(836 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 1455 */
} /* line 1455 */
  sim_icache_fetch(837 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1457 */
  sim_icache_fetch(838 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st((reg_r0_12 + (unsigned int) 1),0,1), reg_r0_3); /* line 1459 */
   __ADD(reg_r0_9, reg_r0_12, (unsigned int) 2); /* line 1460 */
   __SHR(reg_r0_8, reg_r0_3, (unsigned int) 8); /* line 1461 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 1462 */
} /* line 1462 */
l_L66X3: ;/* line 1464 */
__LABEL(l_L66X3);
  sim_icache_fetch(842 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 1465 */
   __MOV(reg_r0_3, (unsigned int) compress_3906Xbuf); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(845 + t_thisfile.offset, 1);
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
} /* line 1468 */
  sim_icache_fetch(846 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_9,0,1), reg_r0_8); /* line 1470 */
} /* line 1470 */
l_L67X3: ;/* line 1472 */
__LABEL(l_L67X3);
  sim_icache_fetch(847 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1473 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1474 */
} /* line 1474 */
  sim_icache_fetch(851 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1476 */
} /* line 1476 */
  sim_icache_fetch(853 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1478 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 1479 */
   __MOV(reg_r0_5, reg_r0_4); /* line 1480 */
} /* line 1480 */
  sim_icache_fetch(856 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) compress_3906Xoffset,0,4), reg_r0_2); /* line 1482 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 1483 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1484 */
} /* line 1484 */
  sim_icache_fetch(860 + t_thisfile.offset, 1);
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
} /* line 1486 */
  sim_icache_fetch(861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_4); /* line 1488 */
} /* line 1488 */
l_L69X3: ;/* line 1491 */
__LABEL(l_L69X3);
  sim_icache_fetch(863 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 1492 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1493 */
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 1494 */
} /* line 1494 */
  sim_icache_fetch(867 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 1496 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 1497 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -4); /* line 1498 */
} /* line 1498 */
  sim_icache_fetch(870 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 1500 */
   __CMPEQ(reg_b0_3, reg_r0_5, 0); /* line 1501 */
} /* line 1501 */
  sim_icache_fetch(872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 1503 */
} /* line 1503 */
  sim_icache_fetch(874 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 1505 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1506 */
  sim_icache_fetch(876 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 1508 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1509 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1510 */
   __ADD_CYCLES(1);
} /* line 1510 */
  sim_icache_fetch(880 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 1512 */
} /* line 1512 */
  sim_icache_fetch(881 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 1514 */
} /* line 1514 */
  sim_icache_fetch(883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 1516 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1517 */
  sim_icache_fetch(885 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 1519 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1520 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1521 */
   __ADD_CYCLES(1);
} /* line 1521 */
  sim_icache_fetch(889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 1523 */
} /* line 1523 */
  sim_icache_fetch(890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 1525 */
} /* line 1525 */
  sim_icache_fetch(892 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 1527 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1528 */
  sim_icache_fetch(894 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 1530 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1531 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 1532 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1533 */
   __ADD_CYCLES(1);
} /* line 1533 */
  sim_icache_fetch(899 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 1535 */
} /* line 1535 */
  sim_icache_fetch(900 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 1537 */
} /* line 1537 */
  sim_icache_fetch(902 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 1539 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1541 */
  sim_icache_fetch(904 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L69X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L69X3;
} /* line 1543 */
l_L70X3: ;/* line 1546 */
__LABEL(l_L70X3);
  sim_icache_fetch(905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_3906Xoffset,0,4), 0); /* line 1547 */
} /* line 1547 */
l_L68X3: ;/* line 1550 */
__LABEL(l_L68X3);
  sim_icache_fetch(907 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1551 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 1552 */
} /* line 1552 */
  sim_icache_fetch(911 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 1554 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1555 */
} /* line 1555 */
  sim_icache_fetch(915 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1557 */
   __MOV(reg_r0_7, (unsigned int) 2); /* line 1558 */
   __MOV(reg_r0_8, (unsigned int) 3); /* line 1559 */
   __MOV(reg_r0_6, (unsigned int) 1); /* line 1560 */
} /* line 1560 */
  sim_icache_fetch(919 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_r0_9, reg_r0_9, 0); /* line 1562 */
   __CMPGT(reg_b0_0, reg_r0_10, 0); /* line 1563 */
   __MOV(reg_r0_5, (unsigned int) compress_3906Xbuf); /* line 1564 */
} /* line 1564 */
  sim_icache_fetch(923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_9); /* line 1566 */
   __MOV(reg_r0_3, 0); /* line 1567 */
} /* line 1567 */
  sim_icache_fetch(925 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1569 */
  sim_icache_fetch(926 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1571 */
l_L73X3: ;/* line 1574 */
__LABEL(l_L73X3);
  sim_icache_fetch(927 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1575 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1576 */
} /* line 1576 */
  sim_icache_fetch(931 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_5,0,1)); /* line 1578 */
} /* line 1578 */
  sim_icache_fetch(932 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 1580 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 1581 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 1582 */
} /* line 1582 */
  sim_icache_fetch(935 + t_thisfile.offset, 1);
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
} /* line 1584 */
  sim_icache_fetch(936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 1586 */
} /* line 1586 */
  sim_icache_fetch(938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_9); /* line 1588 */
} /* line 1588 */
  sim_icache_fetch(939 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1590 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1591 */
} /* line 1591 */
  sim_icache_fetch(943 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_9, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(944 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_6, reg_r0_2); /* line 1595 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 1596 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 1597 */
} /* line 1597 */
  sim_icache_fetch(947 + t_thisfile.offset, 1);
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
} /* line 1599 */
  sim_icache_fetch(948 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 1601 */
} /* line 1601 */
  sim_icache_fetch(950 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_9); /* line 1603 */
} /* line 1603 */
  sim_icache_fetch(951 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1605 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1606 */
} /* line 1606 */
  sim_icache_fetch(955 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_9, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 1608 */
} /* line 1608 */
  sim_icache_fetch(956 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_2); /* line 1610 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 1611 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1612 */
} /* line 1612 */
  sim_icache_fetch(959 + t_thisfile.offset, 1);
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
} /* line 1614 */
  sim_icache_fetch(960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 1616 */
} /* line 1616 */
  sim_icache_fetch(962 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_9); /* line 1618 */
} /* line 1618 */
  sim_icache_fetch(963 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1620 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1621 */
} /* line 1621 */
  sim_icache_fetch(967 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_9, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 1623 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1624 */
} /* line 1624 */
  sim_icache_fetch(969 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_2); /* line 1626 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 1627 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 1628 */
} /* line 1628 */
  sim_icache_fetch(972 + t_thisfile.offset, 1);
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
} /* line 1630 */
  sim_icache_fetch(973 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 1632 */
} /* line 1632 */
  sim_icache_fetch(975 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_9); /* line 1634 */
   __GOTO(l_L73X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L73X3;
} /* line 1635 */
l_L74X3: ;/* line 1638 */
__LABEL(l_L74X3);
  sim_icache_fetch(977 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1639 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1640 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1641 */
   __ADD_CYCLES(1);
} /* line 1641 */
  sim_icache_fetch(982 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1643 */
} /* line 1643 */
  sim_icache_fetch(983 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 1645 */
} /* line 1645 */
l_L72X3: ;/* line 1648 */
__LABEL(l_L72X3);
  sim_icache_fetch(985 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 1649 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 1650 */
} /* line 1650 */
  sim_icache_fetch(988 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_3906Xoffset,0,4), 0); /* line 1652 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 1653 */
} /* line 1653 */
  sim_icache_fetch(992 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1655 */
} /* line 1655 */
  sim_icache_fetch(993 + t_thisfile.offset, 1);
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
} /* line 1657 */
  sim_icache_fetch(994 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 1659 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 1660 */
} /* line 1660 */
  sim_icache_fetch(998 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1663 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1664 */
l_L75X3: ;/* line 1667 */
__LABEL(l_L75X3);
  sim_icache_fetch(1001 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1668 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1669 */
} /* line 1669 */
  sim_icache_fetch(1005 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1671 */
} /* line 1671 */
  sim_icache_fetch(1007 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1673 */
} /* line 1673 */
  sim_icache_fetch(1008 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 1675 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1676 */
} /* line 1676 */
  sim_icache_fetch(1011 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1678 */
  sim_icache_fetch(1012 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 1681 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1682 */
l_L76X3: ;/* line 1685 */
__LABEL(l_L76X3);
  sim_icache_fetch(1015 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 1686 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1687 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1688 */
   __ADD_CYCLES(1);
} /* line 1688 */
  sim_icache_fetch(1019 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 1690 */
} /* line 1690 */
  sim_icache_fetch(1020 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1692 */
} /* line 1692 */
  sim_icache_fetch(1021 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 1695 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1696 */
l_L71X3: ;/* line 1699 */
__LABEL(l_L71X3);
  sim_icache_fetch(1024 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1701 */
l_L65X3: ;/* line 1704 */
__LABEL(l_L65X3);
  sim_icache_fetch(1025 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1705 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1706 */
} /* line 1706 */
  sim_icache_fetch(1029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1708 */
} /* line 1708 */
  sim_icache_fetch(1031 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1710 */
} /* line 1710 */
  sim_icache_fetch(1032 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_1, reg_r0_4, 0); /* line 1712 */
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1713 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 1714 */
} /* line 1714 */
  sim_icache_fetch(1035 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 1716 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1717 */
l_L78X3: ;/* line 1719 */
__LABEL(l_L78X3);
  sim_icache_fetch(1037 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 1720 */
   __STW(mem_trace_st((unsigned int) compress_3906Xoffset,0,4), 0); /* line 1721 */
} /* line 1721 */
  sim_icache_fetch(1040 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_5); /* line 1723 */
} /* line 1723 */
  sim_icache_fetch(1041 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 1726 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1727 */
l_L77X3: ;/* line 1730 */
__LABEL(l_L77X3);
  sim_icache_fetch(1044 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_7, (unsigned int) 2); /* line 1731 */
   __MOV(reg_r0_8, (unsigned int) 3); /* line 1732 */
   __MOV(reg_r0_6, (unsigned int) 1); /* line 1733 */
   __MOV(reg_r0_3, 0); /* line 1734 */
} /* line 1734 */
  sim_icache_fetch(1048 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) compress_3906Xbuf); /* line 1736 */
} /* line 1736 */
l_L79X3: ;/* line 1739 */
__LABEL(l_L79X3);
  sim_icache_fetch(1050 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1740 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1741 */
} /* line 1741 */
  sim_icache_fetch(1054 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_9, mem_trace_ld(reg_r0_5,0,1)); /* line 1743 */
} /* line 1743 */
  sim_icache_fetch(1055 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1745 */
   __ADD(reg_r0_10, reg_r0_4, (unsigned int) 1); /* line 1746 */
} /* line 1746 */
  sim_icache_fetch(1057 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1748 */
   __ADD(reg_r0_11, reg_r0_2, (unsigned int) 7); /* line 1749 */
} /* line 1749 */
  sim_icache_fetch(1059 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, reg_r0_2); /* line 1751 */
} /* line 1751 */
  sim_icache_fetch(1060 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 3); /* line 1753 */
} /* line 1753 */
  sim_icache_fetch(1061 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_11); /* line 1755 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 1756 */
} /* line 1756 */
  sim_icache_fetch(1063 + t_thisfile.offset, 1);
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
} /* line 1758 */
  sim_icache_fetch(1064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 1760 */
} /* line 1760 */
  sim_icache_fetch(1066 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_9); /* line 1762 */
} /* line 1762 */
  sim_icache_fetch(1067 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1764 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1765 */
} /* line 1765 */
  sim_icache_fetch(1071 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_9, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 1767 */
} /* line 1767 */
  sim_icache_fetch(1072 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1769 */
   __ADD(reg_r0_10, reg_r0_4, (unsigned int) 1); /* line 1770 */
} /* line 1770 */
  sim_icache_fetch(1074 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1772 */
   __ADD(reg_r0_11, reg_r0_2, (unsigned int) 7); /* line 1773 */
} /* line 1773 */
  sim_icache_fetch(1076 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, reg_r0_2); /* line 1775 */
} /* line 1775 */
  sim_icache_fetch(1077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 3); /* line 1777 */
} /* line 1777 */
  sim_icache_fetch(1078 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_6, reg_r0_11); /* line 1779 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 1780 */
} /* line 1780 */
  sim_icache_fetch(1080 + t_thisfile.offset, 1);
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
} /* line 1782 */
  sim_icache_fetch(1081 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 1784 */
} /* line 1784 */
  sim_icache_fetch(1083 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_9); /* line 1786 */
} /* line 1786 */
  sim_icache_fetch(1084 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1788 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1789 */
} /* line 1789 */
  sim_icache_fetch(1088 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_9, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 1791 */
} /* line 1791 */
  sim_icache_fetch(1089 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1793 */
   __ADD(reg_r0_10, reg_r0_4, (unsigned int) 1); /* line 1794 */
} /* line 1794 */
  sim_icache_fetch(1091 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1796 */
   __ADD(reg_r0_11, reg_r0_2, (unsigned int) 7); /* line 1797 */
} /* line 1797 */
  sim_icache_fetch(1093 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, reg_r0_2); /* line 1799 */
} /* line 1799 */
  sim_icache_fetch(1094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 3); /* line 1801 */
} /* line 1801 */
  sim_icache_fetch(1095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_11); /* line 1803 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1804 */
} /* line 1804 */
  sim_icache_fetch(1097 + t_thisfile.offset, 1);
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
} /* line 1806 */
  sim_icache_fetch(1098 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 1808 */
} /* line 1808 */
  sim_icache_fetch(1100 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_9); /* line 1810 */
} /* line 1810 */
  sim_icache_fetch(1101 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1812 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1813 */
} /* line 1813 */
  sim_icache_fetch(1105 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_9, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 1815 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1816 */
} /* line 1816 */
  sim_icache_fetch(1107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1818 */
   __ADD(reg_r0_10, reg_r0_4, (unsigned int) 1); /* line 1819 */
} /* line 1819 */
  sim_icache_fetch(1109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1821 */
   __ADD(reg_r0_11, reg_r0_2, (unsigned int) 7); /* line 1822 */
} /* line 1822 */
  sim_icache_fetch(1111 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, reg_r0_2); /* line 1824 */
} /* line 1824 */
  sim_icache_fetch(1112 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 3); /* line 1826 */
} /* line 1826 */
  sim_icache_fetch(1113 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_11); /* line 1828 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 1829 */
} /* line 1829 */
  sim_icache_fetch(1115 + t_thisfile.offset, 1);
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
} /* line 1831 */
  sim_icache_fetch(1116 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 1833 */
} /* line 1833 */
  sim_icache_fetch(1118 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_9); /* line 1835 */
   __GOTO(l_L79X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L79X3;
} /* line 1836 */
l_L83X3: ;/* line 1839 */
__LABEL(l_L83X3);
  sim_icache_fetch(1120 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1840 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1841 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1842 */
   __ADD_CYCLES(1);
} /* line 1842 */
  sim_icache_fetch(1125 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1844 */
} /* line 1844 */
  sim_icache_fetch(1126 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1846 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 1847 */
} /* line 1847 */
  sim_icache_fetch(1128 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_4, reg_r0_2); /* line 1849 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 1850 */
l_L82X3: ;/* line 1853 */
__LABEL(l_L82X3);
  sim_icache_fetch(1130 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1854 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1855 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1856 */
   __ADD_CYCLES(1);
} /* line 1856 */
  sim_icache_fetch(1135 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1858 */
} /* line 1858 */
  sim_icache_fetch(1136 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1860 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 1861 */
} /* line 1861 */
  sim_icache_fetch(1138 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_4, reg_r0_2); /* line 1863 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 1864 */
l_L81X3: ;/* line 1867 */
__LABEL(l_L81X3);
  sim_icache_fetch(1140 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1868 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1869 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1870 */
   __ADD_CYCLES(1);
} /* line 1870 */
  sim_icache_fetch(1145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1872 */
} /* line 1872 */
  sim_icache_fetch(1146 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1874 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 1875 */
} /* line 1875 */
  sim_icache_fetch(1148 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_4, reg_r0_2); /* line 1877 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 1878 */
l_L80X3: ;/* line 1881 */
__LABEL(l_L80X3);
  sim_icache_fetch(1150 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 1882 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_3906Xoffset,0,4)); /* line 1883 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1884 */
   __ADD_CYCLES(1);
} /* line 1884 */
  sim_icache_fetch(1155 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1886 */
} /* line 1886 */
  sim_icache_fetch(1156 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1888 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 1889 */
} /* line 1889 */
  sim_icache_fetch(1158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_4, reg_r0_2); /* line 1891 */
   __GOTO(l_L78X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L78X3;
} /* line 1892 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 230: goto l_L66X3;
    case 231: goto l_L67X3;
    case 232: goto l_L69X3;
    case 233: goto l_L70X3;
    case 234: goto l_L68X3;
    case 235: goto l_L73X3;
    case 236: goto l_L74X3;
    case 237: goto l_L72X3;
    case 238: goto l_L75X3;
    case 239: goto l_L76X3;
    case 240: goto l_L71X3;
    case 241: goto l_L65X3;
    case 242: goto l_L78X3;
    case 243: goto l_L77X3;
    case 244: goto l_L79X3;
    case 245: goto l_L83X3;
    case 246: goto l_L82X3;
    case 247: goto l_L81X3;
    case 248: goto l_L80X3;
    case 249:
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
  reg_l0_0 = (279 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1160 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 1908 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 1909 */
   __MOV(reg_r0_8, (unsigned int) 9); /* line 1910 */
} /* line 1910 */
  sim_icache_fetch(1163 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, (unsigned int) 253); /* line 1912 */
   __MOV(reg_r0_9, (unsigned int) 511); /* line 1913 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1914 */
} /* line 1914 */
  sim_icache_fetch(1167 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, (unsigned int) 255); /* line 1916 */
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 252)); /* line 1917 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 1918 */
} /* line 1918 */
  sim_icache_fetch(1171 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_8); /* line 1920 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 504)); /* line 1921 */
} /* line 1921 */
  sim_icache_fetch(1175 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_9); /* line 1923 */
} /* line 1923 */
l_L84X3: ;/* line 1926 */
__LABEL(l_L84X3);
  sim_icache_fetch(1177 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1927 */
} /* line 1927 */
  sim_icache_fetch(1178 + t_thisfile.offset, 1);
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
} /* line 1929 */
  sim_icache_fetch(1179 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 1931 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_2); /* line 1932 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -4); /* line 1933 */
} /* line 1933 */
  sim_icache_fetch(1182 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 1935 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_5); /* line 1936 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) -4); /* line 1937 */
} /* line 1937 */
  sim_icache_fetch(1185 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 1939 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_6); /* line 1940 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 1941 */
} /* line 1941 */
  sim_icache_fetch(1188 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 1943 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_7); /* line 1944 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -8); /* line 1945 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -4); /* line 1946 */
} /* line 1946 */
  sim_icache_fetch(1192 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1948 */
   __GOTO(l_L84X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L84X3;
} /* line 1949 */
l_L85X3: ;/* line 1952 */
__LABEL(l_L85X3);
  sim_icache_fetch(1194 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1953 */
   __MOV(reg_r0_5, (unsigned int) 257); /* line 1954 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1955 */
   __ADD_CYCLES(1);
} /* line 1955 */
  sim_icache_fetch(1199 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 1957 */
} /* line 1957 */
  sim_icache_fetch(1200 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, (unsigned int) 256); /* line 1959 */
} /* line 1959 */
		 /* line 1960 */
  sim_icache_fetch(1202 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_5); /* line 1962 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (279 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1963 */
l_lr_152: ;/* line 1963 */
__LABEL(l_lr_152);
  sim_icache_fetch(1206 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_4, reg_r0_3); /* line 1965 */
   __MOV(reg_r0_2, reg_r0_3); /* line 1966 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 1967 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1968 */
} /* line 1968 */
  sim_icache_fetch(1210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1970 */
  sim_icache_fetch(1211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 1974 */
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1974 */
l_L86X3: ;/* line 1977 */
__LABEL(l_L86X3);
  sim_icache_fetch(1213 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 1978 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 1979 */
} /* line 1979 */
  sim_icache_fetch(1215 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 1981 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 1982 */
   __MOV(reg_r0_58, reg_r0_2); /* line 1983 */
} /* line 1983 */
  sim_icache_fetch(1219 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, ((unsigned int) htab + (unsigned int) 4096)); /* line 1985 */
   __MOV(reg_r0_59, reg_r0_4); /* line 1986 */
} /* line 1986 */
  sim_icache_fetch(1222 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) 1); /* line 1988 */
} /* line 1988 */
  sim_icache_fetch(1223 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 1990 */
} /* line 1990 */
  sim_icache_fetch(1225 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 1992 */
} /* line 1992 */
l_L87X3: ;/* line 1995 */
__LABEL(l_L87X3);
		 /* line 1995 */
  sim_icache_fetch(1226 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (279 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1997 */
l_lr_156: ;/* line 1997 */
__LABEL(l_lr_156);
  sim_icache_fetch(1228 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, reg_r0_3); /* line 1999 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 2000 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2001 */
} /* line 2001 */
  sim_icache_fetch(1232 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 2003 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 2004 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2005 */
  sim_icache_fetch(1236 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 2007 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 504)); /* line 2008 */
} /* line 2008 */
  sim_icache_fetch(1239 + t_thisfile.offset, 1);
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
} /* line 2010 */
l_L90X3: ;/* line 2013 */
__LABEL(l_L90X3);
  sim_icache_fetch(1240 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 2014 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -4); /* line 2015 */
} /* line 2015 */
  sim_icache_fetch(1242 + t_thisfile.offset, 1);
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
} /* line 2017 */
  sim_icache_fetch(1243 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 2019 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 2020 */
} /* line 2020 */
  sim_icache_fetch(1245 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 2022 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 2023 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -8); /* line 2024 */
   __GOTO(l_L90X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L90X3;
} /* line 2025 */
l_L91X3: ;/* line 2028 */
__LABEL(l_L91X3);
  sim_icache_fetch(1249 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 2029 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 2030 */
} /* line 2030 */
  sim_icache_fetch(1252 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 2032 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 2033 */
} /* line 2033 */
		 /* line 2034 */
  sim_icache_fetch(1256 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (279 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2036 */
l_lr_160: ;/* line 2036 */
__LABEL(l_lr_160);
  sim_icache_fetch(1258 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 2038 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 2039 */
} /* line 2039 */
  sim_icache_fetch(1260 + t_thisfile.offset, 1);
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
} /* line 2041 */
l_L89X3: ;/* line 2044 */
__LABEL(l_L89X3);
  sim_icache_fetch(1261 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 2045 */
   __MOV(reg_r0_8, reg_r0_4); /* line 2046 */
   __MOV(reg_r0_2, reg_r0_4); /* line 2047 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2048 */
   __ADD_CYCLES(1);
} /* line 2048 */
  sim_icache_fetch(1266 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 2050 */
} /* line 2050 */
  sim_icache_fetch(1267 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 2052 */
   __MOV(reg_r0_5, reg_r0_57); /* line 2053 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2054 */
l_L93X3: ;/* line 2057 */
__LABEL(l_L93X3);
  sim_icache_fetch(1271 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2058 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 2059 */
} /* line 2059 */
  sim_icache_fetch(1274 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 2061 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2062 */
  sim_icache_fetch(1277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 2064 */
} /* line 2064 */
  sim_icache_fetch(1278 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 2066 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2067 */
   __ADD_CYCLES(1);
} /* line 2067 */
  sim_icache_fetch(1280 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 2069 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 2070 */
} /* line 2070 */
  sim_icache_fetch(1283 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 2072 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2073 */
  sim_icache_fetch(1286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 2075 */
} /* line 2075 */
  sim_icache_fetch(1287 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 2077 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2078 */
   __ADD_CYCLES(1);
} /* line 2078 */
  sim_icache_fetch(1289 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 2080 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 2081 */
} /* line 2081 */
  sim_icache_fetch(1292 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 2083 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2084 */
  sim_icache_fetch(1295 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 2086 */
} /* line 2086 */
  sim_icache_fetch(1296 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 2088 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2089 */
   __ADD_CYCLES(1);
} /* line 2089 */
  sim_icache_fetch(1298 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 2091 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 2092 */
} /* line 2092 */
  sim_icache_fetch(1301 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 2094 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2095 */
  sim_icache_fetch(1304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 2097 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2098 */
} /* line 2098 */
  sim_icache_fetch(1306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 2100 */
} /* line 2100 */
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L93X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L93X3;
} /* line 2102 */
l_L97X3: ;/* line 2105 */
__LABEL(l_L97X3);
  sim_icache_fetch(1308 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 2106 */
   __MOV(reg_r0_2, reg_r0_6); /* line 2107 */
   __MOV(reg_r0_12, reg_r0_8); /* line 2108 */
   __GOTO(l_L98X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L98X3;
} /* line 2109 */
l_L99X3: ;/* line 2112 */
__LABEL(l_L99X3);
  sim_icache_fetch(1312 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, reg_r0_3); /* line 2113 */
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2114 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2115 */
} /* line 2115 */
  sim_icache_fetch(1316 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 2117 */
   __CMPLEU(reg_b0_1, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 2118 */
} /* line 2118 */
  sim_icache_fetch(1320 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_10, reg_r0_2, (unsigned int) 1); /* line 2120 */
   __CMPLEU(reg_b0_2, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 2121 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -4); /* line 2122 */
} /* line 2122 */
  sim_icache_fetch(1324 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 2124 */
   __MOV(reg_r0_11, reg_r0_8); /* line 2125 */
} /* line 2125 */
  sim_icache_fetch(1327 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2127 */
   __CMPLEU(reg_b0_3, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 2128 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2129 */
  sim_icache_fetch(1331 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_6,0,1)); /* line 2131 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2132 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 2133 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2134 */
   __ADD_CYCLES(1);
} /* line 2134 */
  sim_icache_fetch(1336 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_2, (unsigned int) 1); /* line 2136 */
} /* line 2136 */
  sim_icache_fetch(1337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 2138 */
} /* line 2138 */
  sim_icache_fetch(1339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2140 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2141 */
  sim_icache_fetch(1341 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_7,0,1)); /* line 2143 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2144 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2145 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2146 */
   __ADD_CYCLES(1);
} /* line 2146 */
  sim_icache_fetch(1346 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_2, (unsigned int) 1); /* line 2148 */
} /* line 2148 */
  sim_icache_fetch(1347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 2150 */
} /* line 2150 */
  sim_icache_fetch(1349 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2152 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2153 */
  sim_icache_fetch(1351 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_8,0,1)); /* line 2155 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2156 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 2157 */
} /* line 2157 */
  sim_icache_fetch(1355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -4); /* line 2159 */
} /* line 2159 */
  sim_icache_fetch(1356 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_10, reg_r0_2, (unsigned int) 1); /* line 2161 */
} /* line 2161 */
  sim_icache_fetch(1357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_10); /* line 2163 */
} /* line 2163 */
  sim_icache_fetch(1359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2165 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2167 */
  sim_icache_fetch(1361 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L99X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L99X3;
} /* line 2169 */
l_L103X3: ;/* line 2172 */
__LABEL(l_L103X3);
  sim_icache_fetch(1362 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_57, reg_r0_5, (unsigned int) -3); /* line 2173 */
   __MOV(reg_r0_58, reg_r0_13); /* line 2174 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 2176 */
} /* line 2176 */
  sim_icache_fetch(1366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L104X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L104X3;
} /* line 2178 */
l_L106X3: ;/* line 2181 */
__LABEL(l_L106X3);
  sim_icache_fetch(1367 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 2182 */
   __SH1ADD(reg_r0_2, reg_r0_3, (unsigned int) codetab); /* line 2183 */
} /* line 2183 */
  sim_icache_fetch(1370 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st(reg_r0_2,0,2), reg_r0_59); /* line 2185 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 2186 */
} /* line 2186 */
  sim_icache_fetch(1373 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_3 + (unsigned int) htab),0,1), reg_r0_58); /* line 2188 */
   __GOTO(l_L105X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L105X3;
} /* line 2189 */
l_L102X3: ;/* line 2192 */
__LABEL(l_L102X3);
  sim_icache_fetch(1376 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_57, reg_r0_9, (unsigned int) -3); /* line 2193 */
   __MOV(reg_r0_58, reg_r0_13); /* line 2194 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 2196 */
} /* line 2196 */
  sim_icache_fetch(1380 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L104X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L104X3;
} /* line 2198 */
l_L101X3: ;/* line 2201 */
__LABEL(l_L101X3);
  sim_icache_fetch(1381 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_57, reg_r0_9, (unsigned int) -2); /* line 2202 */
   __MOV(reg_r0_58, reg_r0_13); /* line 2203 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 2205 */
} /* line 2205 */
  sim_icache_fetch(1385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L104X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L104X3;
} /* line 2207 */
l_L100X3: ;/* line 2210 */
__LABEL(l_L100X3);
  sim_icache_fetch(1386 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_57, reg_r0_9, (unsigned int) -1); /* line 2211 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 2212 */
   __MOV(reg_r0_58, reg_r0_13); /* line 2213 */
} /* line 2213 */
l_L104X3: ;/* line 2215 */
__LABEL(l_L104X3);
  sim_icache_fetch(1390 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 2216 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2217 */
   __ADD_CYCLES(1);
} /* line 2217 */
  sim_icache_fetch(1393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 2219 */
} /* line 2219 */
  sim_icache_fetch(1394 + t_thisfile.offset, 1);
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
} /* line 2221 */
l_L105X3: ;/* line 2223 */
__LABEL(l_L105X3);
  sim_icache_fetch(1395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_12); /* line 2224 */
   __GOTO(l_L87X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L87X3;
} /* line 2225 */
l_L96X3: ;/* line 2228 */
__LABEL(l_L96X3);
  sim_icache_fetch(1397 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 2229 */
   __MOV(reg_r0_2, reg_r0_7); /* line 2230 */
   __MOV(reg_r0_12, reg_r0_8); /* line 2231 */
   __GOTO(l_L98X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L98X3;
} /* line 2232 */
l_L95X3: ;/* line 2235 */
__LABEL(l_L95X3);
  sim_icache_fetch(1401 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 2236 */
   __MOV(reg_r0_2, reg_r0_6); /* line 2237 */
   __MOV(reg_r0_12, reg_r0_8); /* line 2238 */
   __GOTO(l_L98X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L98X3;
} /* line 2239 */
l_L94X3: ;/* line 2244 */
__LABEL(l_L94X3);
  sim_icache_fetch(1405 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, reg_r0_8); /* line 2245 */
} /* line 2245 */
l_L98X3: ;/* line 2247 */
__LABEL(l_L98X3);
  sim_icache_fetch(1406 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDBU(reg_r0_2, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 2248 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -3); /* line 2249 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -2); /* line 2250 */
} /* line 2250 */
  sim_icache_fetch(1410 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, reg_r0_5); /* line 2252 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) 1); /* line 2253 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -1); /* line 2254 */
} /* line 2254 */
  sim_icache_fetch(1413 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_2); /* line 2256 */
   __MOV(reg_r0_13, reg_r0_2); /* line 2257 */
   __GOTO(l_L99X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L99X3;
} /* line 2258 */
l_L92X3: ;/* line 2261 */
__LABEL(l_L92X3);
  sim_icache_fetch(1416 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_58); /* line 2262 */
   __MOV(reg_r0_2, reg_r0_59); /* line 2263 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 2264 */
   __GOTO(l_L93X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L93X3;
} /* line 2265 */
l_L88X3: ;/* line 2268 */
__LABEL(l_L88X3);
  sim_icache_fetch(1420 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_3, 0); /* line 2269 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 2270 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2271 */
} /* line 2271 */
  sim_icache_fetch(1423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2273 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 2274 */
} /* line 2274 */
  sim_icache_fetch(1425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2277 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 250: goto l_L84X3;
    case 251: goto l_L85X3;
    case 253: goto l_lr_152;
    case 254: goto l_L86X3;
    case 255: goto l_L87X3;
    case 257: goto l_lr_156;
    case 258: goto l_L90X3;
    case 259: goto l_L91X3;
    case 261: goto l_lr_160;
    case 262: goto l_L89X3;
    case 263: goto l_L93X3;
    case 264: goto l_L97X3;
    case 265: goto l_L99X3;
    case 266: goto l_L103X3;
    case 267: goto l_L106X3;
    case 268: goto l_L102X3;
    case 269: goto l_L101X3;
    case 270: goto l_L100X3;
    case 271: goto l_L104X3;
    case 272: goto l_L105X3;
    case 273: goto l_L96X3;
    case 274: goto l_L95X3;
    case 275: goto l_L94X3;
    case 276: goto l_L98X3;
    case 277: goto l_L92X3;
    case 278: goto l_L88X3;
    case 279:
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
  reg_l0_0 = (303 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1426 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2296 */
} /* line 2296 */
  sim_icache_fetch(1428 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 2298 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 2299 */
} /* line 2299 */
  sim_icache_fetch(1432 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 2301 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 2302 */
} /* line 2302 */
  sim_icache_fetch(1436 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 2304 */
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 2305 */
} /* line 2305 */
  sim_icache_fetch(1439 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_9, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 2307 */
   __CMPGT(reg_r0_8, reg_r0_5, reg_r0_6); /* line 2308 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 2309 */
} /* line 2309 */
  sim_icache_fetch(1443 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_8); /* line 2311 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2312 */
} /* line 2312 */
  sim_icache_fetch(1446 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_6, reg_r0_7, reg_r0_9); /* line 2314 */
} /* line 2314 */
  sim_icache_fetch(1447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_1, reg_r0_4, reg_r0_6); /* line 2316 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 2317 */
} /* line 2317 */
  sim_icache_fetch(1449 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_5, reg_r0_2); /* line 2319 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2320 */
  sim_icache_fetch(1451 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2322 */
  sim_icache_fetch(1452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_5); /* line 2324 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2325 */
  sim_icache_fetch(1455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 2327 */
} /* line 2327 */
l_L108X3: ;/* line 2330 */
__LABEL(l_L108X3);
  sim_icache_fetch(1457 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 2331 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2332 */
} /* line 2332 */
  sim_icache_fetch(1461 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_5, 0); /* line 2334 */
   __MOV(reg_r0_4, (unsigned int) _X1PACKETX15); /* line 2335 */
   __MOV(reg_r0_10, reg_r0_7); /* line 2336 */
} /* line 2336 */
  sim_icache_fetch(1465 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 2338 */
   __SUB(reg_r0_8, (unsigned int) 3, reg_r0_6); /* line 2339 */
   __MOV(reg_r0_11, reg_r0_6); /* line 2340 */
} /* line 2340 */
  sim_icache_fetch(1468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_8); /* line 2342 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2343 */
l_L111X3: ;/* line 2346 */
__LABEL(l_L111X3);
  sim_icache_fetch(1470 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, (unsigned int) 3); /* line 2347 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2348 */
   __CMPLT(reg_b0_1, reg_r0_3, (unsigned int) 2); /* line 2349 */
} /* line 2349 */
  sim_icache_fetch(1474 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2351 */
   __CMPLT(reg_b0_0, reg_r0_3, (unsigned int) 1); /* line 2352 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2353 */
  sim_icache_fetch(1478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 2355 */
   __CMPLT(reg_b0_2, reg_r0_3, 0); /* line 2356 */
} /* line 2356 */
  sim_icache_fetch(1480 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 2358 */
   __CMPGE(reg_b0_3, reg_r0_2, 0); /* line 2359 */
   __ADD(reg_r0_7, reg_r0_6, (unsigned int) 1); /* line 2360 */
} /* line 2360 */
  sim_icache_fetch(1484 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2362 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2363 */
  sim_icache_fetch(1487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 2365 */
} /* line 2365 */
  sim_icache_fetch(1489 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 2367 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 2368 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2369 */
} /* line 2369 */
  sim_icache_fetch(1493 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_3, reg_r0_2, 0); /* line 2371 */
} /* line 2371 */
  sim_icache_fetch(1494 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 2373 */
   __ADD(reg_r0_8, reg_r0_7, (unsigned int) 1); /* line 2374 */
} /* line 2374 */
l_L114X3: ;/* line 2376 */
__LABEL(l_L114X3);
  sim_icache_fetch(1496 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_9, reg_r0_6); /* line 2377 */
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_6); /* line 2378 */
} /* line 2378 */
  sim_icache_fetch(1498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_4, reg_r0_9, (unsigned int) 255); /* line 2380 */
} /* line 2380 */
  sim_icache_fetch(1499 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2382 */
  sim_icache_fetch(1500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2384 */
  sim_icache_fetch(1501 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 2386 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2387 */
  sim_icache_fetch(1504 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 2389 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2390 */
} /* line 2390 */
  sim_icache_fetch(1508 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 2392 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2393 */
} /* line 2393 */
  sim_icache_fetch(1511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 2395 */
} /* line 2395 */
  sim_icache_fetch(1512 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_7, reg_r0_7); /* line 2397 */
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 2398 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 2399 */
} /* line 2399 */
l_L118X3: ;/* line 2401 */
__LABEL(l_L118X3);
  sim_icache_fetch(1515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_9, reg_r0_7); /* line 2402 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_7); /* line 2403 */
} /* line 2403 */
  sim_icache_fetch(1517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_9, (unsigned int) 255); /* line 2405 */
} /* line 2405 */
  sim_icache_fetch(1518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2407 */
  sim_icache_fetch(1519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2409 */
  sim_icache_fetch(1520 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 2411 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2412 */
  sim_icache_fetch(1523 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 2414 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2415 */
} /* line 2415 */
  sim_icache_fetch(1527 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 2417 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2418 */
} /* line 2418 */
  sim_icache_fetch(1530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 2420 */
} /* line 2420 */
  sim_icache_fetch(1531 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 2422 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 2423 */
   __ADD(reg_r0_8, reg_r0_7, (unsigned int) 1); /* line 2424 */
} /* line 2424 */
l_L122X3: ;/* line 2426 */
__LABEL(l_L122X3);
  sim_icache_fetch(1534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_9, reg_r0_6); /* line 2427 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_6); /* line 2428 */
} /* line 2428 */
  sim_icache_fetch(1536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_9, (unsigned int) 255); /* line 2430 */
} /* line 2430 */
  sim_icache_fetch(1537 + t_thisfile.offset, 1);
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
} /* line 2432 */
  sim_icache_fetch(1538 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2434 */
  sim_icache_fetch(1539 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 2436 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2437 */
  sim_icache_fetch(1542 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 2439 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 2440 */
} /* line 2440 */
  sim_icache_fetch(1545 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 2442 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2443 */
   __ADD_CYCLES(1);
} /* line 2443 */
  sim_icache_fetch(1547 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_7, reg_r0_7); /* line 2445 */
} /* line 2445 */
l_L126X3: ;/* line 2447 */
__LABEL(l_L126X3);
  sim_icache_fetch(1548 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_7); /* line 2448 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_7); /* line 2449 */
} /* line 2449 */
  sim_icache_fetch(1550 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 2451 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2452 */
} /* line 2452 */
  sim_icache_fetch(1552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2454 */
  sim_icache_fetch(1553 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2456 */
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2457 */
l_L127X3: ;/* line 2460 */
__LABEL(l_L127X3);
  sim_icache_fetch(1555 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) 3); /* line 2461 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2462 */
   __GOTO(l_L128X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L128X3;
} /* line 2463 */
l_L129X3: ;/* line 2466 */
__LABEL(l_L129X3);
  sim_icache_fetch(1558 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2467 */
   __MOV(reg_r0_7, 0); /* line 2468 */
   __SHL(reg_r0_11, reg_r0_11, (unsigned int) 3); /* line 2469 */
} /* line 2469 */
  sim_icache_fetch(1562 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 1); /* line 2471 */
} /* line 2471 */
  sim_icache_fetch(1563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_9, reg_r0_11, reg_r0_2); /* line 2473 */
} /* line 2473 */
l_L107X3: ;/* line 2476 */
__LABEL(l_L107X3);
  sim_icache_fetch(1564 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2477 */
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 2478 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 2479 */
} /* line 2479 */
  sim_icache_fetch(1568 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 2481 */
   __ADD(reg_r0_8, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 2482 */
} /* line 2482 */
  sim_icache_fetch(1572 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_10, reg_r0_2, reg_r0_4); /* line 2484 */
   __SUB(reg_r0_12, (unsigned int) 16, reg_r0_4); /* line 2485 */
   __SUB(reg_r0_13, (unsigned int) 8, reg_r0_4); /* line 2486 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 2); /* line 2487 */
} /* line 2487 */
  sim_icache_fetch(1576 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_7); /* line 2489 */
   __ADD(reg_r0_14, reg_r0_10, (unsigned int) -8); /* line 2490 */
   __ADD(reg_r0_15, reg_r0_10, (unsigned int) -16); /* line 2491 */
   __LDBUs(reg_r0_6, mem_trace_ld((reg_r0_6 + (unsigned int) 1),0,1)); /* line 2492 */
} /* line 2492 */
  sim_icache_fetch(1580 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 2494 */
   __CMPGE(reg_b0_0, reg_r0_14, (unsigned int) 8); /* line 2495 */
} /* line 2495 */
  sim_icache_fetch(1583 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __SLCT(reg_r0_15, reg_b0_0, reg_r0_15, reg_r0_14); /* line 2497 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, reg_r0_13); /* line 2498 */
   __SHL(reg_r0_6, reg_r0_6, reg_r0_13); /* line 2499 */
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, reg_r0_8); /* line 2500 */
} /* line 2500 */
  sim_icache_fetch(1587 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_5, reg_r0_5, reg_r0_4); /* line 2502 */
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 2503 */
   __LDBU(reg_r0_15, mem_trace_ld((reg_r0_15 + (unsigned int) rmask),0,1)); /* line 2504 */
} /* line 2504 */
  sim_icache_fetch(1591 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_6, reg_r0_5, reg_r0_6); /* line 2506 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_2); /* line 2507 */
} /* line 2507 */
  sim_icache_fetch(1594 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_6, reg_b0_0, reg_r0_6, reg_r0_5); /* line 2509 */
   __AND(reg_r0_11, reg_r0_11, reg_r0_15); /* line 2510 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_9); /* line 2511 */
} /* line 2511 */
  sim_icache_fetch(1598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_11, reg_r0_11, reg_r0_12); /* line 2513 */
} /* line 2513 */
  sim_icache_fetch(1599 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_6, reg_r0_11); /* line 2516 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2517 */
l_L125X3: ;/* line 2520 */
__LABEL(l_L125X3);
  sim_icache_fetch(1601 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_7, (unsigned int) -1); /* line 2521 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 2522 */
   __GOTO(l_L126X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L126X3;
} /* line 2523 */
l_L124X3: ;/* line 2526 */
__LABEL(l_L124X3);
  sim_icache_fetch(1604 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MAX(reg_r0_11, reg_r0_11, 0); /* line 2527 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2528 */
   __GOTO(l_L128X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L128X3;
} /* line 2529 */
l_L123X3: ;/* line 2532 */
__LABEL(l_L123X3);
  sim_icache_fetch(1607 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) 2); /* line 2533 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2534 */
   __GOTO(l_L128X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L128X3;
} /* line 2535 */
l_L121X3: ;/* line 2538 */
__LABEL(l_L121X3);
  sim_icache_fetch(1610 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2539 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2540 */
} /* line 2540 */
  sim_icache_fetch(1614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2542 */
} /* line 2542 */
  sim_icache_fetch(1615 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_9, (unsigned int) -1); /* line 2544 */
   __ADD(reg_r0_8, reg_r0_7, (unsigned int) 1); /* line 2545 */
} /* line 2545 */
  sim_icache_fetch(1617 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 2547 */
   __GOTO(l_L122X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L122X3;
} /* line 2548 */
l_L120X3: ;/* line 2551 */
__LABEL(l_L120X3);
  sim_icache_fetch(1619 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MAX(reg_r0_11, reg_r0_11, 0); /* line 2552 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2553 */
   __GOTO(l_L128X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L128X3;
} /* line 2554 */
l_L119X3: ;/* line 2557 */
__LABEL(l_L119X3);
  sim_icache_fetch(1622 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) 1); /* line 2558 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2559 */
   __GOTO(l_L128X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L128X3;
} /* line 2560 */
l_L117X3: ;/* line 2563 */
__LABEL(l_L117X3);
  sim_icache_fetch(1625 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) buflen,0,4)); /* line 2564 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2565 */
} /* line 2565 */
  sim_icache_fetch(1629 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, (unsigned int) -1); /* line 2567 */
} /* line 2567 */
  sim_icache_fetch(1630 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_9, (unsigned int) -1); /* line 2569 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 2570 */
} /* line 2570 */
  sim_icache_fetch(1632 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_1, reg_r0_2, 0); /* line 2572 */
   __GOTO(l_L118X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L118X3;
} /* line 2573 */
l_L116X3: ;/* line 2576 */
__LABEL(l_L116X3);
  sim_icache_fetch(1634 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MAX(reg_r0_11, reg_r0_11, 0); /* line 2577 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2578 */
   __GOTO(l_L128X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L128X3;
} /* line 2579 */
l_L115X3: ;/* line 2582 */
__LABEL(l_L115X3);
  sim_icache_fetch(1637 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_11, reg_r0_5); /* line 2583 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2584 */
   __GOTO(l_L128X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L128X3;
} /* line 2585 */
l_L113X3: ;/* line 2588 */
__LABEL(l_L113X3);
  sim_icache_fetch(1640 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2589 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) bufp,0,4)); /* line 2590 */
} /* line 2590 */
  sim_icache_fetch(1643 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 2592 */
} /* line 2592 */
  sim_icache_fetch(1644 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGE(reg_b0_3, reg_r0_2, 0); /* line 2594 */
   __ADD(reg_r0_8, reg_r0_7, (unsigned int) 1); /* line 2595 */
   __GOTO(l_L114X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L114X3;
} /* line 2596 */
l_L112X3: ;/* line 2599 */
__LABEL(l_L112X3);
  sim_icache_fetch(1647 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_11, reg_r0_11, 0); /* line 2600 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2601 */
} /* line 2601 */
l_L128X3: ;/* line 2603 */
__LABEL(l_L128X3);
  sim_icache_fetch(1649 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_11, 0); /* line 2604 */
} /* line 2604 */
  sim_icache_fetch(1650 + t_thisfile.offset, 1);
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
} /* line 2606 */
  sim_icache_fetch(1651 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_11); /* line 2608 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_10); /* line 2609 */
} /* line 2609 */
  sim_icache_fetch(1655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2612 */
l_L110X3: ;/* line 2615 */
__LABEL(l_L110X3);
  sim_icache_fetch(1656 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 511); /* line 2616 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 2617 */
} /* line 2617 */
  sim_icache_fetch(1659 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 2619 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_6); /* line 2620 */
} /* line 2620 */
  sim_icache_fetch(1663 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 2622 */
   __LDW(reg_r0_11, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2623 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2624 */
   __ADD_CYCLES(1);
} /* line 2624 */
  sim_icache_fetch(1668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_8, (unsigned int) 3, reg_r0_11); /* line 2626 */
} /* line 2626 */
  sim_icache_fetch(1669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_8); /* line 2628 */
   __GOTO(l_L111X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L111X3;
} /* line 2629 */
l_L109X3: ;/* line 2632 */
__LABEL(l_L109X3);
  sim_icache_fetch(1671 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2633 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 2634 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2635 */
   __ADD_CYCLES(1);
} /* line 2635 */
  sim_icache_fetch(1675 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 2637 */
} /* line 2637 */
  sim_icache_fetch(1676 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 2639 */
} /* line 2639 */
  sim_icache_fetch(1677 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 2641 */
   __GOTO(l_L108X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L108X3;
} /* line 2642 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 280: goto l_L108X3;
    case 281: goto l_L111X3;
    case 282: goto l_L114X3;
    case 283: goto l_L118X3;
    case 284: goto l_L122X3;
    case 285: goto l_L126X3;
    case 286: goto l_L127X3;
    case 287: goto l_L129X3;
    case 288: goto l_L107X3;
    case 289: goto l_L125X3;
    case 290: goto l_L124X3;
    case 291: goto l_L123X3;
    case 292: goto l_L121X3;
    case 293: goto l_L120X3;
    case 294: goto l_L119X3;
    case 295: goto l_L117X3;
    case 296: goto l_L116X3;
    case 297: goto l_L115X3;
    case 298: goto l_L113X3;
    case 299: goto l_L112X3;
    case 300: goto l_L128X3;
    case 301: goto l_L110X3;
    case 302: goto l_L109X3;
    case 303:
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
  reg_l0_0 = (306 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1680 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 2664 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 2665 */
} /* line 2665 */
		 /* line 2666 */
  sim_icache_fetch(1683 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 2669 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (306 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2669 */
l_lr_204: ;/* line 2669 */
__LABEL(l_lr_204);
  sim_icache_fetch(1686 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 2671 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2672 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2673 */
   __ADD_CYCLES(1);
} /* line 2673 */
  sim_icache_fetch(1689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2676 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 305: goto l_lr_204;
    case 306:
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
  reg_l0_0 = (308 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 2722 */
} /* line 2722 */
  sim_icache_fetch(1692 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 2724 */
} /* line 2724 */
  sim_icache_fetch(1693 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 2726 */
} /* line 2726 */
  sim_icache_fetch(1694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2728 */
  sim_icache_fetch(1695 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2731 */
l_L130X3: ;/* line 2734 */
__LABEL(l_L130X3);
  sim_icache_fetch(1696 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 2737 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2737 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 307: goto l_L130X3;
    case 308:
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
  reg_l0_0 = (309 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 2753 */
} /* line 2753 */
  sim_icache_fetch(1699 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2756 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 309:
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
  reg_l0_0 = (313 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1700 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 2771 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 2772 */
} /* line 2772 */
  sim_icache_fetch(1703 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 2774 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 2775 */
} /* line 2775 */
  sim_icache_fetch(1706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 2777 */
} /* line 2777 */
  sim_icache_fetch(1707 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2779 */
		 /* line 2780 */
  sim_icache_fetch(1708 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (313 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2782 */
l_lr_210: ;/* line 2782 */
__LABEL(l_lr_210);
l_L131X3: ;/* line 2784 */
__LABEL(l_L131X3);
  sim_icache_fetch(1710 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 2785 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2786 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2787 */
   __ADD_CYCLES(1);
} /* line 2787 */
  sim_icache_fetch(1713 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2790 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 311: goto l_lr_210;
    case 312: goto l_L131X3;
    case 313:
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
  reg_l0_0 = (326 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1714 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 2836 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2837 */
} /* line 2837 */
  sim_icache_fetch(1717 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2839 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 2840 */
} /* line 2840 */
  sim_icache_fetch(1720 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 10000); /* line 2842 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 2843 */
} /* line 2843 */
  sim_icache_fetch(1724 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2845 */
   __MOV(reg_r0_2, (unsigned int) 2147483647); /* line 2846 */
} /* line 2846 */
  sim_icache_fetch(1727 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_4); /* line 2848 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 2849 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2850 */
  sim_icache_fetch(1731 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2852 */
l_L134X3: ;/* line 2855 */
__LABEL(l_L134X3);
  sim_icache_fetch(1732 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) ratio,0,4)); /* line 2856 */
   __MOV(reg_r0_3, 0); /* line 2857 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2858 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2859 */
   __ADD_CYCLES(1);
} /* line 2859 */
  sim_icache_fetch(1737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2861 */
} /* line 2861 */
  sim_icache_fetch(1738 + t_thisfile.offset, 1);
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
} /* line 2863 */
  sim_icache_fetch(1739 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_2); /* line 2866 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2867 */
l_L135X3: ;/* line 2870 */
__LABEL(l_L135X3);
  sim_icache_fetch(1742 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 2871 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2872 */
} /* line 2872 */
		 /* line 2873 */
  sim_icache_fetch(1746 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (326 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2875 */
l_lr_216: ;/* line 2875 */
__LABEL(l_lr_216);
  sim_icache_fetch(1748 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 2877 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 2878 */
} /* line 2878 */
  sim_icache_fetch(1751 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 2880 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 2881 */
} /* line 2881 */
		 /* line 2882 */
  sim_icache_fetch(1755 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 2884 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (326 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2885 */
l_lr_218: ;/* line 2885 */
__LABEL(l_lr_218);
  sim_icache_fetch(1759 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2887 */
   __MOV(reg_r0_3, 0); /* line 2888 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2889 */
   __ADD_CYCLES(1);
} /* line 2889 */
  sim_icache_fetch(1762 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2892 */
l_L133X3: ;/* line 2895 */
__LABEL(l_L133X3);
  sim_icache_fetch(1763 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2896 */
   __MOV(reg_r0_4, reg_r0_3); /* line 2897 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2898 */
   __ADD_CYCLES(1);
} /* line 2898 */
		 /* line 2899 */
  sim_icache_fetch(1767 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 2902 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (326 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2902 */
l_lr_221: ;/* line 2902 */
__LABEL(l_lr_221);
  sim_icache_fetch(1770 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_3); /* line 2904 */
   __GOTO(l_L134X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L134X3;
} /* line 2905 */
l_L132X3: ;/* line 2908 */
__LABEL(l_L132X3);
  sim_icache_fetch(1772 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2909 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2910 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2911 */
   __ADD_CYCLES(1);
} /* line 2911 */
		 /* line 2912 */
  sim_icache_fetch(1777 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_5, (unsigned int) 8); /* line 2914 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (326 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2915 */
l_lr_224: ;/* line 2915 */
__LABEL(l_lr_224);
  sim_icache_fetch(1780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_3); /* line 2917 */
   __GOTO(l_L134X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L134X3;
} /* line 2918 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 314: goto l_L134X3;
    case 315: goto l_L135X3;
    case 317: goto l_lr_216;
    case 319: goto l_lr_218;
    case 320: goto l_L133X3;
    case 322: goto l_lr_221;
    case 323: goto l_L132X3;
    case 325: goto l_lr_224;
    case 326:
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
  reg_l0_0 = (334 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1782 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_7, reg_r0_3, (unsigned int) htab); /* line 2937 */
} /* line 2937 */
  sim_icache_fetch(1784 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) -16); /* line 2939 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 2940 */
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -64); /* line 2941 */
} /* line 2941 */
l_L136X3: ;/* line 2944 */
__LABEL(l_L136X3);
  sim_icache_fetch(1787 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, reg_r0_2); /* line 2945 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2946 */
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2947 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2948 */
} /* line 2948 */
  sim_icache_fetch(1791 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_6); /* line 2950 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_6); /* line 2951 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 2952 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -48); /* line 2953 */
} /* line 2953 */
  sim_icache_fetch(1795 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_6); /* line 2955 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_6); /* line 2956 */
} /* line 2956 */
  sim_icache_fetch(1797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_6); /* line 2958 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_6); /* line 2959 */
} /* line 2959 */
  sim_icache_fetch(1799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_6); /* line 2961 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_6); /* line 2962 */
} /* line 2962 */
  sim_icache_fetch(1801 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_6); /* line 2964 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_6); /* line 2965 */
} /* line 2965 */
  sim_icache_fetch(1803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_6); /* line 2967 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_6); /* line 2968 */
} /* line 2968 */
  sim_icache_fetch(1805 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_6); /* line 2970 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_6); /* line 2971 */
} /* line 2971 */
  sim_icache_fetch(1807 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_6); /* line 2973 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_6); /* line 2974 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2975 */
  sim_icache_fetch(1810 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_6); /* line 2977 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_6); /* line 2978 */
} /* line 2978 */
  sim_icache_fetch(1812 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_6); /* line 2980 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_6); /* line 2981 */
} /* line 2981 */
  sim_icache_fetch(1814 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_6); /* line 2983 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_6); /* line 2984 */
} /* line 2984 */
  sim_icache_fetch(1816 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_6); /* line 2986 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_6); /* line 2987 */
} /* line 2987 */
  sim_icache_fetch(1818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_6); /* line 2989 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_6); /* line 2990 */
} /* line 2990 */
  sim_icache_fetch(1820 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_6); /* line 2992 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_6); /* line 2993 */
} /* line 2993 */
  sim_icache_fetch(1822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_6); /* line 2995 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_6); /* line 2996 */
} /* line 2996 */
  sim_icache_fetch(1824 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_6); /* line 2998 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_6); /* line 2999 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3000 */
  sim_icache_fetch(1827 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_6); /* line 3002 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_6); /* line 3003 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -48); /* line 3004 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 3005 */
} /* line 3005 */
  sim_icache_fetch(1831 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_6); /* line 3007 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_6); /* line 3008 */
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 3009 */
} /* line 3009 */
  sim_icache_fetch(1834 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_6); /* line 3011 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_6); /* line 3012 */
} /* line 3012 */
  sim_icache_fetch(1836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_6); /* line 3014 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_6); /* line 3015 */
} /* line 3015 */
  sim_icache_fetch(1838 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_6); /* line 3017 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_6); /* line 3018 */
} /* line 3018 */
  sim_icache_fetch(1840 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_6); /* line 3020 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_6); /* line 3021 */
} /* line 3021 */
  sim_icache_fetch(1842 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_6); /* line 3023 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_6); /* line 3024 */
} /* line 3024 */
  sim_icache_fetch(1844 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_6); /* line 3026 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_6); /* line 3027 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -192); /* line 3028 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3030 */
  sim_icache_fetch(1848 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L136X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L136X3;
} /* line 3032 */
l_L139X3: ;/* line 3035 */
__LABEL(l_L139X3);
  sim_icache_fetch(1849 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -128); /* line 3036 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -32); /* line 3037 */
   __GOTO(l_L140X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L140X3;
} /* line 3038 */
l_L141X3: ;/* line 3041 */
__LABEL(l_L141X3);
  sim_icache_fetch(1852 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 3042 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 1); /* line 3043 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 2); /* line 3044 */
   __MOV(reg_r0_6, (unsigned int) -1); /* line 3045 */
} /* line 3045 */
  sim_icache_fetch(1856 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 3); /* line 3047 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -4); /* line 3048 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3049 */
  sim_icache_fetch(1859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_6); /* line 3051 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3052 */
  sim_icache_fetch(1861 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_6); /* line 3054 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3055 */
  sim_icache_fetch(1863 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_6); /* line 3057 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3058 */
  sim_icache_fetch(1865 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_6); /* line 3060 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 3061 */
   __GOTO(l_L141X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L141X3;
} /* line 3062 */
l_L142X3: ;/* line 3065 */
__LABEL(l_L142X3);
  sim_icache_fetch(1868 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3067 */
l_L138X3: ;/* line 3070 */
__LABEL(l_L138X3);
  sim_icache_fetch(1869 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 3071 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -32); /* line 3072 */
   __GOTO(l_L140X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L140X3;
} /* line 3073 */
l_L137X3: ;/* line 3076 */
__LABEL(l_L137X3);
  sim_icache_fetch(1872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 3077 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 3078 */
} /* line 3078 */
l_L140X3: ;/* line 3080 */
__LABEL(l_L140X3);
  sim_icache_fetch(1874 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_8, (unsigned int) 16); /* line 3081 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) -16); /* line 3082 */
   __GOTO(l_L141X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L141X3;
} /* line 3083 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 327: goto l_L136X3;
    case 328: goto l_L139X3;
    case 329: goto l_L141X3;
    case 330: goto l_L142X3;
    case 331: goto l_L138X3;
    case 332: goto l_L137X3;
    case 333: goto l_L140X3;
    case 334:
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
  reg_l0_0 = (335 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1877 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 3099 */
} /* line 3099 */
  sim_icache_fetch(1878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3102 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 335:
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
  reg_l0_0 = (336 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1879 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 3118 */
} /* line 3118 */
  sim_icache_fetch(1880 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3121 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 336:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 1888, 0, 0, 0, 2};

