/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/bf/2_128_128_128_128_128_128_128_128/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O3 -H3 -o a.out" */

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
unsigned int compress_8838Xoffset[1];
unsigned int compress_8838Xbuf[3];
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
unsigned int compress_8838XBuf[216]; 
unsigned int compress_8838Xrcs_ident[6]; 
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
	(133 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(147 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(139 << 5),
	(138 << 5),
	(137 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(136 << 5),
	(151 << 5),
	(151 << 5),
	(135 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(151 << 5),
	(134 << 5)
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

unsigned int compress_8838XBuf[216] = { 
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

unsigned int compress_8838Xrcs_ident[6] = { 
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
  sim_icache_fetch(2 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_1, (unsigned int) 28); /* line 22 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_l0_0); /* line 23 */
} /* line 23 */
  sim_icache_fetch(4 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_1, (unsigned int) 16); /* line 25 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_4); /* line 26 */
} /* line 26 */
  sim_icache_fetch(6 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1PACKETX4); /* line 28 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_2); /* line 29 */
} /* line 29 */
		 /* line 30 */
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
} /* line 32 */
l_lr_1: ;/* line 32 */
__LABEL(l_lr_1);
  sim_icache_fetch(11 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 34 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 35 */
} /* line 35 */
  sim_icache_fetch(13 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 800); /* line 37 */
   __MOV(reg_r0_5, (unsigned int) compress_8838XBuf); /* line 38 */
} /* line 38 */
  sim_icache_fetch(17 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_2); /* line 40 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 41 */
} /* line 41 */
  sim_icache_fetch(19 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), 0); /* line 43 */
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 44 */
} /* line 44 */
		 /* line 45 */
  sim_icache_fetch(23 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_6); /* line 47 */
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
} /* line 48 */
l_lr_3: ;/* line 48 */
__LABEL(l_lr_3);
		 /* line 49 */
  sim_icache_fetch(27 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 52 */
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
} /* line 52 */
l_lr_5: ;/* line 52 */
__LABEL(l_lr_5);
  sim_icache_fetch(31 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 54 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 55 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 56 */
   __ADD_CYCLES(1);
} /* line 56 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 59 */
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
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 110 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX2); /* line 111 */
} /* line 111 */
		 /* line 112 */
  sim_icache_fetch(38 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 115 */
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
} /* line 115 */
l_lr_8: ;/* line 115 */
__LABEL(l_lr_8);
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 117 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 118 */
   __ADD_CYCLES(1);
} /* line 118 */
  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Usage);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 121 */
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
  reg_l0_0 = (128 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(44 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_21, reg_r0_3, (unsigned int) 15); /* line 182 */
} /* line 182 */
  sim_icache_fetch(45 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 14); /* line 184 */
   __ADD(reg_r0_19, reg_r0_3, (unsigned int) 13); /* line 185 */
} /* line 185 */
  sim_icache_fetch(47 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_18, reg_r0_3, (unsigned int) 12); /* line 187 */
   __ADD(reg_r0_17, reg_r0_3, (unsigned int) 11); /* line 188 */
} /* line 188 */
  sim_icache_fetch(49 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 10); /* line 190 */
   __ADD(reg_r0_15, reg_r0_3, (unsigned int) 9); /* line 191 */
} /* line 191 */
  sim_icache_fetch(51 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_14, reg_r0_3, (unsigned int) 8); /* line 193 */
   __ADD(reg_r0_13, reg_r0_3, (unsigned int) 7); /* line 194 */
} /* line 194 */
  sim_icache_fetch(53 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_12, reg_r0_3, (unsigned int) 6); /* line 196 */
   __ADD(reg_r0_11, reg_r0_3, (unsigned int) 5); /* line 197 */
} /* line 197 */
  sim_icache_fetch(55 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_9, reg_r0_3, (unsigned int) 3); /* line 199 */
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 4); /* line 200 */
} /* line 200 */
  sim_icache_fetch(57 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 202 */
   __ADD(reg_r0_8, reg_r0_3, (unsigned int) 2); /* line 203 */
} /* line 203 */
  sim_icache_fetch(59 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SXTB(reg_r0_4, reg_r0_4); /* line 205 */
   __MOV(reg_r0_5, 0); /* line 206 */
} /* line 206 */
  sim_icache_fetch(61 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_3); /* line 208 */
} /* line 208 */
l_L0X3: ;/* line 211 */
__LABEL(l_L0X3);
  sim_icache_fetch(62 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 212 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 213 */
} /* line 213 */
  sim_icache_fetch(64 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_22, mem_trace_ld(reg_r0_8,0,1)); /* line 215 */
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_9,0,1)); /* line 216 */
} /* line 216 */
  sim_icache_fetch(66 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 218 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 219 */
} /* line 219 */
  sim_icache_fetch(68 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 221 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 222 */
  sim_icache_fetch(70 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 224 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 225 */
} /* line 225 */
  sim_icache_fetch(72 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_6, reg_r0_3); /* line 227 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 228 */
  sim_icache_fetch(74 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_22, 0); /* line 230 */
   __CMPEQ(reg_b0_1, reg_r0_22, reg_r0_4); /* line 231 */
} /* line 231 */
  sim_icache_fetch(76 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_8, reg_r0_7); /* line 233 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 234 */
  sim_icache_fetch(78 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_23, 0); /* line 236 */
   __CMPEQ(reg_b0_1, reg_r0_23, reg_r0_4); /* line 237 */
} /* line 237 */
  sim_icache_fetch(80 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_9, reg_r0_3); /* line 239 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 240 */
  sim_icache_fetch(82 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_10,0,1)); /* line 242 */
   __LDBs(reg_r0_22, mem_trace_ld(reg_r0_11,0,1)); /* line 243 */
} /* line 243 */
  sim_icache_fetch(84 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_12,0,1)); /* line 245 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_13,0,1)); /* line 246 */
} /* line 246 */
  sim_icache_fetch(86 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 248 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 249 */
} /* line 249 */
  sim_icache_fetch(88 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_10, reg_r0_7); /* line 251 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 252 */
  sim_icache_fetch(90 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_22, 0); /* line 254 */
   __CMPEQ(reg_b0_1, reg_r0_22, reg_r0_4); /* line 255 */
} /* line 255 */
  sim_icache_fetch(92 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_11, reg_r0_3); /* line 257 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 258 */
  sim_icache_fetch(94 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_23, 0); /* line 260 */
   __CMPEQ(reg_b0_1, reg_r0_23, reg_r0_4); /* line 261 */
} /* line 261 */
  sim_icache_fetch(96 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_12, reg_r0_7); /* line 263 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 264 */
  sim_icache_fetch(98 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 266 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 267 */
} /* line 267 */
  sim_icache_fetch(100 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_13, reg_r0_3); /* line 269 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 270 */
  sim_icache_fetch(102 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_14,0,1)); /* line 272 */
   __LDBs(reg_r0_22, mem_trace_ld(reg_r0_15,0,1)); /* line 273 */
} /* line 273 */
  sim_icache_fetch(104 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_16,0,1)); /* line 275 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_17,0,1)); /* line 276 */
} /* line 276 */
  sim_icache_fetch(106 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 278 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 279 */
} /* line 279 */
  sim_icache_fetch(108 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_14, reg_r0_7); /* line 281 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 282 */
  sim_icache_fetch(110 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_22, 0); /* line 284 */
   __CMPEQ(reg_b0_1, reg_r0_22, reg_r0_4); /* line 285 */
} /* line 285 */
  sim_icache_fetch(112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_15, reg_r0_3); /* line 287 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 288 */
  sim_icache_fetch(114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_23, 0); /* line 290 */
   __CMPEQ(reg_b0_1, reg_r0_23, reg_r0_4); /* line 291 */
} /* line 291 */
  sim_icache_fetch(116 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_16, reg_r0_7); /* line 293 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 294 */
  sim_icache_fetch(118 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 296 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 297 */
} /* line 297 */
  sim_icache_fetch(120 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_17, reg_r0_3); /* line 299 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 300 */
  sim_icache_fetch(122 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_18,0,1)); /* line 302 */
   __LDBs(reg_r0_22, mem_trace_ld(reg_r0_19,0,1)); /* line 303 */
} /* line 303 */
  sim_icache_fetch(124 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_20,0,1)); /* line 305 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_21,0,1)); /* line 306 */
} /* line 306 */
  sim_icache_fetch(126 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 308 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 309 */
} /* line 309 */
  sim_icache_fetch(128 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_18, reg_r0_7); /* line 311 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 312 */
  sim_icache_fetch(130 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_22, 0); /* line 314 */
   __CMPEQ(reg_b0_1, reg_r0_22, reg_r0_4); /* line 315 */
} /* line 315 */
  sim_icache_fetch(132 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_19, reg_r0_3); /* line 317 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 318 */
  sim_icache_fetch(134 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_23, 0); /* line 320 */
   __CMPEQ(reg_b0_1, reg_r0_23, reg_r0_4); /* line 321 */
} /* line 321 */
  sim_icache_fetch(136 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_20, reg_r0_7); /* line 323 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 324 */
  sim_icache_fetch(138 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 326 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 327 */
} /* line 327 */
  sim_icache_fetch(140 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_1, reg_r0_21, reg_r0_3); /* line 329 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 330 */
  sim_icache_fetch(142 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 332 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 333 */
} /* line 333 */
  sim_icache_fetch(144 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 335 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 336 */
} /* line 336 */
  sim_icache_fetch(146 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 338 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 339 */
} /* line 339 */
  sim_icache_fetch(148 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 341 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 342 */
} /* line 342 */
  sim_icache_fetch(150 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 344 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 345 */
} /* line 345 */
  sim_icache_fetch(152 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 347 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 348 */
} /* line 348 */
  sim_icache_fetch(154 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 350 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 351 */
} /* line 351 */
  sim_icache_fetch(156 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 353 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 354 */
} /* line 354 */
  sim_icache_fetch(158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 356 */
   __LDBs(reg_r0_7, mem_trace_ld(reg_r0_6,0,1)); /* line 357 */
} /* line 357 */
  sim_icache_fetch(160 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_22, mem_trace_ld(reg_r0_8,0,1)); /* line 359 */
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_9,0,1)); /* line 360 */
} /* line 360 */
  sim_icache_fetch(162 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 362 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 363 */
} /* line 363 */
  sim_icache_fetch(164 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_2, reg_r0_5); /* line 365 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 366 */
  sim_icache_fetch(166 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_7, 0); /* line 368 */
   __CMPEQ(reg_b0_1, reg_r0_7, reg_r0_4); /* line 369 */
} /* line 369 */
  sim_icache_fetch(168 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_6, reg_r0_3); /* line 371 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 372 */
  sim_icache_fetch(170 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_22, 0); /* line 374 */
   __CMPEQ(reg_b0_1, reg_r0_22, reg_r0_4); /* line 375 */
} /* line 375 */
  sim_icache_fetch(172 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_8, reg_r0_7); /* line 377 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 378 */
  sim_icache_fetch(174 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_23, 0); /* line 380 */
   __CMPEQ(reg_b0_1, reg_r0_23, reg_r0_4); /* line 381 */
} /* line 381 */
  sim_icache_fetch(176 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_9, reg_r0_3); /* line 383 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 384 */
  sim_icache_fetch(178 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_10,0,1)); /* line 386 */
   __LDBs(reg_r0_22, mem_trace_ld(reg_r0_11,0,1)); /* line 387 */
} /* line 387 */
  sim_icache_fetch(180 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_12,0,1)); /* line 389 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_13,0,1)); /* line 390 */
} /* line 390 */
  sim_icache_fetch(182 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 392 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 393 */
} /* line 393 */
  sim_icache_fetch(184 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_10, reg_r0_7); /* line 395 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 396 */
  sim_icache_fetch(186 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_22, 0); /* line 398 */
   __CMPEQ(reg_b0_1, reg_r0_22, reg_r0_4); /* line 399 */
} /* line 399 */
  sim_icache_fetch(188 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_11, reg_r0_3); /* line 401 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 402 */
  sim_icache_fetch(190 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_23, 0); /* line 404 */
   __CMPEQ(reg_b0_1, reg_r0_23, reg_r0_4); /* line 405 */
} /* line 405 */
  sim_icache_fetch(192 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_12, reg_r0_7); /* line 407 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 408 */
  sim_icache_fetch(194 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 410 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 411 */
} /* line 411 */
  sim_icache_fetch(196 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_13, reg_r0_3); /* line 413 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 414 */
  sim_icache_fetch(198 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_14,0,1)); /* line 416 */
   __LDBs(reg_r0_22, mem_trace_ld(reg_r0_15,0,1)); /* line 417 */
} /* line 417 */
  sim_icache_fetch(200 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_16,0,1)); /* line 419 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_17,0,1)); /* line 420 */
} /* line 420 */
  sim_icache_fetch(202 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 422 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 423 */
} /* line 423 */
  sim_icache_fetch(204 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_14, reg_r0_7); /* line 425 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 426 */
  sim_icache_fetch(206 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_22, 0); /* line 428 */
   __CMPEQ(reg_b0_1, reg_r0_22, reg_r0_4); /* line 429 */
} /* line 429 */
  sim_icache_fetch(208 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_15, reg_r0_3); /* line 431 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 432 */
  sim_icache_fetch(210 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_23, 0); /* line 434 */
   __CMPEQ(reg_b0_1, reg_r0_23, reg_r0_4); /* line 435 */
} /* line 435 */
  sim_icache_fetch(212 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_16, reg_r0_7); /* line 437 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 438 */
  sim_icache_fetch(214 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 440 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 441 */
} /* line 441 */
  sim_icache_fetch(216 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_17, reg_r0_3); /* line 443 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 444 */
  sim_icache_fetch(218 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_18,0,1)); /* line 446 */
   __LDBs(reg_r0_22, mem_trace_ld(reg_r0_19,0,1)); /* line 447 */
} /* line 447 */
  sim_icache_fetch(220 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_23, mem_trace_ld(reg_r0_20,0,1)); /* line 449 */
   __LDBs(reg_r0_24, mem_trace_ld(reg_r0_21,0,1)); /* line 450 */
} /* line 450 */
  sim_icache_fetch(222 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 452 */
   __CMPEQ(reg_b0_1, reg_r0_3, reg_r0_4); /* line 453 */
} /* line 453 */
  sim_icache_fetch(224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_18, reg_r0_7); /* line 455 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 456 */
  sim_icache_fetch(226 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_22, 0); /* line 458 */
   __CMPEQ(reg_b0_1, reg_r0_22, reg_r0_4); /* line 459 */
} /* line 459 */
  sim_icache_fetch(228 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_1, reg_r0_19, reg_r0_3); /* line 461 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 462 */
  sim_icache_fetch(230 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_23, 0); /* line 464 */
   __CMPEQ(reg_b0_1, reg_r0_23, reg_r0_4); /* line 465 */
} /* line 465 */
  sim_icache_fetch(232 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_20, reg_r0_7); /* line 467 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 468 */
  sim_icache_fetch(234 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_24, 0); /* line 470 */
   __CMPEQ(reg_b0_1, reg_r0_24, reg_r0_4); /* line 471 */
} /* line 471 */
  sim_icache_fetch(236 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_5, reg_b0_1, reg_r0_21, reg_r0_3); /* line 473 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 474 */
  sim_icache_fetch(238 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 476 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 477 */
} /* line 477 */
  sim_icache_fetch(240 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 479 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 480 */
} /* line 480 */
  sim_icache_fetch(242 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 482 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 483 */
} /* line 483 */
  sim_icache_fetch(244 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 485 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 486 */
} /* line 486 */
  sim_icache_fetch(246 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 488 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 489 */
} /* line 489 */
  sim_icache_fetch(248 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 491 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 492 */
} /* line 492 */
  sim_icache_fetch(250 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 494 */
   __ADD(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 495 */
} /* line 495 */
  sim_icache_fetch(252 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 497 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 499 */
} /* line 499 */
  sim_icache_fetch(254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L0X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L0X3;
} /* line 501 */
l_L16X3: ;/* line 504 */
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
} /* line 507 */
l_L15X3: ;/* line 510 */
__LABEL(l_L15X3);
  sim_icache_fetch(256 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 512 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 513 */
l_L14X3: ;/* line 516 */
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
} /* line 519 */
l_L13X3: ;/* line 522 */
__LABEL(l_L13X3);
  sim_icache_fetch(259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 524 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 525 */
l_L12X3: ;/* line 528 */
__LABEL(l_L12X3);
  sim_icache_fetch(261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 531 */
l_L11X3: ;/* line 534 */
__LABEL(l_L11X3);
  sim_icache_fetch(262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 536 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 537 */
l_L10X3: ;/* line 540 */
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
} /* line 543 */
l_L9X3: ;/* line 546 */
__LABEL(l_L9X3);
  sim_icache_fetch(265 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 548 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 549 */
l_L8X3: ;/* line 552 */
__LABEL(l_L8X3);
  sim_icache_fetch(267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 555 */
l_L7X3: ;/* line 558 */
__LABEL(l_L7X3);
  sim_icache_fetch(268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 560 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 561 */
l_L6X3: ;/* line 564 */
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
} /* line 567 */
l_L5X3: ;/* line 570 */
__LABEL(l_L5X3);
  sim_icache_fetch(271 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 572 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 573 */
l_L4X3: ;/* line 576 */
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
} /* line 579 */
l_L3X3: ;/* line 582 */
__LABEL(l_L3X3);
  sim_icache_fetch(274 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_7); /* line 584 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 585 */
l_L2X3: ;/* line 588 */
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
} /* line 591 */
l_L1X3: ;/* line 594 */
__LABEL(l_L1X3);
  sim_icache_fetch(277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 596 */
   __RETURN(rindex);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 597 */
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
    case 128:
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
  reg_l0_0 = (195 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(279 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 613 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 614 */
} /* line 614 */
  sim_icache_fetch(282 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_3); /* line 616 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 617 */
} /* line 617 */
  sim_icache_fetch(284 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 619 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_4); /* line 620 */
} /* line 620 */
  sim_icache_fetch(287 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), 0); /* line 622 */
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_5); /* line 623 */
} /* line 623 */
  sim_icache_fetch(291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_4,0,4)); /* line 625 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_7); /* line 626 */
} /* line 626 */
		 /* line 627 */
  sim_icache_fetch(293 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 47); /* line 630 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(rindex);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) rindex;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 630 */
l_lr_29: ;/* line 630 */
__LABEL(l_lr_29);
  sim_icache_fetch(296 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 632 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 633 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 634 */
   __ADD_CYCLES(1);
} /* line 634 */
  sim_icache_fetch(299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 4); /* line 636 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -1); /* line 637 */
} /* line 637 */
l_L17X3: ;/* line 640 */
__LABEL(l_L17X3);
  sim_icache_fetch(301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, 0); /* line 641 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 642 */
} /* line 642 */
  sim_icache_fetch(303 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L18X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 644 */
  sim_icache_fetch(304 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld(reg_r0_3,0,1)); /* line 646 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 647 */
   __ADD_CYCLES(1);
} /* line 647 */
  sim_icache_fetch(306 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) 45); /* line 649 */
} /* line 649 */
  sim_icache_fetch(307 + t_thisfile.offset, 1);
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
} /* line 651 */
l_L20X3: ;/* line 654 */
__LABEL(l_L20X3);
  sim_icache_fetch(308 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 655 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 656 */
   __ADD_CYCLES(1);
} /* line 656 */
  sim_icache_fetch(310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 658 */
} /* line 658 */
  sim_icache_fetch(311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 660 */
} /* line 660 */
  sim_icache_fetch(312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 662 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 663 */
   __ADD_CYCLES(1);
} /* line 663 */
  sim_icache_fetch(314 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_3, 0); /* line 665 */
   __CMPLT(reg_r0_4, reg_r0_3, (unsigned int) 67); /* line 666 */
} /* line 666 */
  sim_icache_fetch(316 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_r0_5, reg_r0_3, (unsigned int) 118); /* line 668 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 669 */
  sim_icache_fetch(318 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_0, reg_r0_4, reg_r0_5); /* line 671 */
   __SH2ADD(reg_r0_3, reg_r0_3, ((unsigned int) _X1XCompressXTAGPACKETX0 + (unsigned int) -268)); /* line 672 */
} /* line 672 */
  sim_icache_fetch(321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_l0_0, mem_trace_ld(reg_r0_3,0,4)); /* line 674 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 675 */
  sim_icache_fetch(323 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 676 */
  sim_icache_fetch(324 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(reg_l0_0);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 678 */
l__X1XCompressXTAGX0X0: ;/* line 680 */
__LABEL(l__X1XCompressXTAGX0X0);
  sim_icache_fetch(325 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), 0); /* line 681 */
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 682 */
l__X1XCompressXTAGX0X7: ;/* line 685 */
__LABEL(l__X1XCompressXTAGX0X7);
  sim_icache_fetch(328 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), 0); /* line 686 */
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 687 */
l__X1XCompressXTAGX0X6: ;/* line 690 */
__LABEL(l__X1XCompressXTAGX0X6);
  sim_icache_fetch(331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 691 */
} /* line 691 */
  sim_icache_fetch(332 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) quiet,0,4), reg_r0_3); /* line 693 */
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 694 */
l__X1XCompressXTAGX0X5: ;/* line 697 */
__LABEL(l__X1XCompressXTAGX0X5);
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 698 */
} /* line 698 */
  sim_icache_fetch(336 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) nomagic,0,4), reg_r0_3); /* line 700 */
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 701 */
l__X1XCompressXTAGX0X4: ;/* line 704 */
__LABEL(l__X1XCompressXTAGX0X4);
  sim_icache_fetch(339 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 705 */
} /* line 705 */
  sim_icache_fetch(340 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) do_decomp,0,4), reg_r0_3); /* line 707 */
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 708 */
l__X1XCompressXTAGX0X3: ;/* line 711 */
__LABEL(l__X1XCompressXTAGX0X3);
  sim_icache_fetch(343 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 712 */
} /* line 712 */
  sim_icache_fetch(344 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) zcat_flg,0,4), reg_r0_3); /* line 714 */
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 715 */
l__X1XCompressXTAGX0X2: ;/* line 718 */
__LABEL(l__X1XCompressXTAGX0X2);
  sim_icache_fetch(347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 719 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 720 */
   __ADD_CYCLES(1);
} /* line 720 */
  sim_icache_fetch(349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 1); /* line 722 */
} /* line 722 */
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_4); /* line 724 */
} /* line 724 */
  sim_icache_fetch(351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 726 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 727 */
   __ADD_CYCLES(1);
} /* line 727 */
  sim_icache_fetch(353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 729 */
} /* line 729 */
  sim_icache_fetch(354 + t_thisfile.offset, 1);
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
} /* line 731 */
l_L19X3: ;/* line 733 */
__LABEL(l_L19X3);
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 734 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 736 */
} /* line 736 */
  sim_icache_fetch(357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L17X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L17X3;
} /* line 738 */
l_L22X3: ;/* line 741 */
__LABEL(l_L22X3);
  sim_icache_fetch(358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -1); /* line 742 */
   __LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 743 */
} /* line 743 */
  sim_icache_fetch(360 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 745 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 746 */
} /* line 746 */
  sim_icache_fetch(362 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 748 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 749 */
  sim_icache_fetch(364 + t_thisfile.offset, 1);
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
} /* line 752 */
  sim_icache_fetch(365 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L19X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L19X3;
} /* line 754 */
l_L23X3: ;/* line 757 */
__LABEL(l_L23X3);
		 /* line 757 */
  sim_icache_fetch(366 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 760 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (195 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 760 */
l_lr_43: ;/* line 760 */
__LABEL(l_lr_43);
		 /* line 761 */
  sim_icache_fetch(370 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (195 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 763 */
l_lr_45: ;/* line 763 */
__LABEL(l_lr_45);
  sim_icache_fetch(372 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 765 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 766 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 767 */
   __ADD_CYCLES(1);
} /* line 767 */
  sim_icache_fetch(375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 770 */
l__X1XCompressXTAGX0X1: ;/* line 773 */
__LABEL(l__X1XCompressXTAGX0X1);
  sim_icache_fetch(376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 774 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_6); /* line 775 */
} /* line 775 */
		 /* line 776 */
  sim_icache_fetch(378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(version);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) version;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 778 */
l_lr_48: ;/* line 778 */
__LABEL(l_lr_48);
  sim_icache_fetch(380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 780 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 781 */
} /* line 781 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L20X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L20X3;
} /* line 783 */
l_L24X3: ;/* line 786 */
__LABEL(l_L24X3);
l__X1XCompressXTAGX0XDEFAULT: ;/* line 787 */
__LABEL(l__X1XCompressXTAGX0XDEFAULT);
		 /* line 787 */
  sim_icache_fetch(383 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 790 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (195 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 790 */
l_lr_52: ;/* line 790 */
__LABEL(l_lr_52);
		 /* line 791 */
  sim_icache_fetch(387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(Usage);
   reg_l0_0 = (195 << 5);
   {
    typedef void t_FT ();
    t_FT *t_call = (t_FT*) Usage;
    (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 793 */
l_lr_54: ;/* line 793 */
__LABEL(l_lr_54);
  sim_icache_fetch(389 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 795 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 796 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 797 */
   __ADD_CYCLES(1);
} /* line 797 */
  sim_icache_fetch(392 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 800 */
l_L21X3: ;/* line 803 */
__LABEL(l_L21X3);
  sim_icache_fetch(393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L24X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L24X3;
} /* line 804 */
l_L18X3: ;/* line 807 */
__LABEL(l_L18X3);
  sim_icache_fetch(394 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 808 */
   __MOV(reg_r0_4, (unsigned int) 9); /* line 809 */
} /* line 809 */
  sim_icache_fetch(397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 811 */
   __MOV(reg_r0_5, (unsigned int) 12); /* line 812 */
} /* line 812 */
  sim_icache_fetch(399 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 814 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 815 */
} /* line 815 */
  sim_icache_fetch(402 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 817 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 818 */
  sim_icache_fetch(405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_4); /* line 820 */
} /* line 820 */
l_L26X3: ;/* line 822 */
__LABEL(l_L26X3);
  sim_icache_fetch(407 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 823 */
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 4096); /* line 824 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 825 */
   __ADD_CYCLES(1);
} /* line 825 */
  sim_icache_fetch(412 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_1, reg_r0_4, (unsigned int) 12); /* line 827 */
} /* line 827 */
  sim_icache_fetch(413 + t_thisfile.offset, 1);
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
} /* line 829 */
  sim_icache_fetch(414 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_5); /* line 831 */
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 832 */
} /* line 832 */
l_L28X3: ;/* line 834 */
__LABEL(l_L28X3);
  sim_icache_fetch(418 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 835 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 836 */
   __ADD_CYCLES(1);
} /* line 836 */
  sim_icache_fetch(421 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 838 */
} /* line 838 */
  sim_icache_fetch(422 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_3); /* line 840 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 841 */
		 /* line 842 */
  sim_icache_fetch(425 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 844 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 845 */
l_lr_60: ;/* line 845 */
__LABEL(l_lr_60);
l_L30X3: ;/* line 847 */
__LABEL(l_L30X3);
  sim_icache_fetch(429 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 848 */
   __MOV(reg_r0_5, (unsigned int) CompBuf); /* line 849 */
} /* line 849 */
  sim_icache_fetch(433 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 851 */
   __MOV(reg_r0_4, (unsigned int) UnComp); /* line 852 */
} /* line 852 */
  sim_icache_fetch(437 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) -1); /* line 854 */
   __MOV(reg_r0_9, ((unsigned int) CompBuf + (unsigned int) 1)); /* line 855 */
} /* line 855 */
  sim_icache_fetch(440 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, 0); /* line 857 */
   __CMPGE(reg_b0_1, reg_r0_8, 0); /* line 858 */
} /* line 858 */
  sim_icache_fetch(442 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_6, mem_trace_ld((unsigned int) CompBuf,0,1)); /* line 860 */
   __LDBUs(reg_r0_10, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 861 */
} /* line 861 */
  sim_icache_fetch(446 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 863 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 864 */
} /* line 864 */
  sim_icache_fetch(450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 866 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 867 */
} /* line 867 */
  sim_icache_fetch(452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_5); /* line 869 */
   __CMPNE(reg_b0_2, reg_r0_6, reg_r0_10); /* line 870 */
} /* line 870 */
  sim_icache_fetch(455 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 872 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 873 */
  sim_icache_fetch(458 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_8); /* line 875 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 876 */
  sim_icache_fetch(461 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_9); /* line 878 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L33X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 879 */
l_L34X3: ;/* line 881 */
__LABEL(l_L34X3);
		 /* line 881 */
  sim_icache_fetch(464 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (195 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 883 */
l_lr_64: ;/* line 883 */
__LABEL(l_lr_64);
  sim_icache_fetch(466 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 885 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 886 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 887 */
   __ADD_CYCLES(1);
} /* line 887 */
  sim_icache_fetch(469 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 890 */
l_L33X3: ;/* line 893 */
__LABEL(l_L33X3);
  sim_icache_fetch(470 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 894 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 895 */
} /* line 895 */
  sim_icache_fetch(474 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBUs(reg_r0_5, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 897 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 898 */
} /* line 898 */
  sim_icache_fetch(478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 900 */
   __ADD(reg_r0_6, reg_r0_4, (unsigned int) 1); /* line 901 */
} /* line 901 */
  sim_icache_fetch(480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 903 */
   __AND(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 904 */
} /* line 904 */
  sim_icache_fetch(482 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 906 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 907 */
  sim_icache_fetch(485 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_6); /* line 909 */
} /* line 909 */
  sim_icache_fetch(487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 911 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 912 */
   __ADD_CYCLES(1);
} /* line 912 */
  sim_icache_fetch(489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 914 */
} /* line 914 */
l_L36X3: ;/* line 916 */
__LABEL(l_L36X3);
  sim_icache_fetch(490 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_4, reg_r0_5); /* line 917 */
} /* line 917 */
  sim_icache_fetch(491 + t_thisfile.offset, 1);
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
} /* line 920 */
  sim_icache_fetch(492 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 922 */
l_L37X3: ;/* line 925 */
__LABEL(l_L37X3);
  sim_icache_fetch(493 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 926 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) bufp,0,4)); /* line 927 */
} /* line 927 */
  sim_icache_fetch(497 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 929 */
   __MOV(reg_r0_5, (unsigned int) 1); /* line 930 */
} /* line 930 */
  sim_icache_fetch(500 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 932 */
   __ADD(reg_r0_8, reg_r0_4, (unsigned int) 1); /* line 933 */
} /* line 933 */
  sim_icache_fetch(502 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 935 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 936 */
} /* line 936 */
  sim_icache_fetch(505 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 938 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 939 */
  sim_icache_fetch(508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 941 */
} /* line 941 */
  sim_icache_fetch(510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_4,0,1)); /* line 943 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 944 */
   __ADD_CYCLES(1);
} /* line 944 */
  sim_icache_fetch(512 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_4, reg_r0_4); /* line 946 */
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 947 */
} /* line 947 */
l_L39X3: ;/* line 949 */
__LABEL(l_L39X3);
  sim_icache_fetch(515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_4, (unsigned int) 128); /* line 950 */
   __AND(reg_r0_2, reg_r0_4, (unsigned int) 31); /* line 951 */
} /* line 951 */
  sim_icache_fetch(517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_5, reg_r0_5, reg_r0_2); /* line 953 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 12); /* line 954 */
} /* line 954 */
  sim_icache_fetch(519 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) block_compress,0,4), reg_r0_6); /* line 956 */
   __STW(mem_trace_st((unsigned int) maxmaxcode,0,4), reg_r0_5); /* line 957 */
} /* line 957 */
  sim_icache_fetch(523 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxbits,0,4), reg_r0_2); /* line 959 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 960 */
		 /* line 961 */
  sim_icache_fetch(526 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (195 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 963 */
l_lr_70: ;/* line 963 */
__LABEL(l_lr_70);
  sim_icache_fetch(528 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 965 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 966 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 967 */
   __ADD_CYCLES(1);
} /* line 967 */
  sim_icache_fetch(531 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 970 */
l_L31X3: ;/* line 973 */
__LABEL(l_L31X3);
		 /* line 973 */
  sim_icache_fetch(532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(decompress);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) decompress;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 975 */
l_lr_73: ;/* line 975 */
__LABEL(l_lr_73);
  sim_icache_fetch(534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 977 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 978 */
} /* line 978 */
  sim_icache_fetch(536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 980 */
} /* line 980 */
  sim_icache_fetch(537 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_7); /* line 983 */
   __RETURN(Compress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 984 */
l_L38X3: ;/* line 987 */
__LABEL(l_L38X3);
  sim_icache_fetch(540 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 988 */
   __MOV(reg_r0_6, (unsigned int) 100000); /* line 989 */
} /* line 989 */
  sim_icache_fetch(543 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) 1); /* line 991 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 992 */
} /* line 992 */
  sim_icache_fetch(546 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) fsize,0,4), reg_r0_6); /* line 994 */
   __GOTO(l_L39X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L39X3;
} /* line 995 */
l_L35X3: ;/* line 998 */
__LABEL(l_L35X3);
  sim_icache_fetch(549 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -1); /* line 999 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1001 */
} /* line 1001 */
  sim_icache_fetch(552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L36X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L36X3;
} /* line 1003 */
l_L32X3: ;/* line 1006 */
__LABEL(l_L32X3);
  sim_icache_fetch(553 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 1007 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 1008 */
} /* line 1008 */
  sim_icache_fetch(556 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_6, reg_r0_10); /* line 1010 */
} /* line 1010 */
  sim_icache_fetch(557 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L33X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1013 */
  sim_icache_fetch(558 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L34X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L34X3;
} /* line 1015 */
l_L29X3: ;/* line 1018 */
__LABEL(l_L29X3);
  sim_icache_fetch(559 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1019 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1020 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1021 */
   __ADD_CYCLES(1);
} /* line 1021 */
  sim_icache_fetch(564 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 8192); /* line 1023 */
} /* line 1023 */
  sim_icache_fetch(566 + t_thisfile.offset, 1);
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
} /* line 1025 */
		 /* line 1026 */
  sim_icache_fetch(567 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1028 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1029 */
l_lr_79: ;/* line 1029 */
__LABEL(l_lr_79);
  sim_icache_fetch(571 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1031 */
l_L40X3: ;/* line 1034 */
__LABEL(l_L40X3);
  sim_icache_fetch(572 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1035 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1036 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1037 */
   __ADD_CYCLES(1);
} /* line 1037 */
  sim_icache_fetch(577 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 16384); /* line 1039 */
} /* line 1039 */
  sim_icache_fetch(579 + t_thisfile.offset, 1);
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
} /* line 1041 */
		 /* line 1042 */
  sim_icache_fetch(580 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1044 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1045 */
l_lr_82: ;/* line 1045 */
__LABEL(l_lr_82);
  sim_icache_fetch(584 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1047 */
l_L41X3: ;/* line 1050 */
__LABEL(l_L41X3);
  sim_icache_fetch(585 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1051 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1052 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1053 */
   __ADD_CYCLES(1);
} /* line 1053 */
  sim_icache_fetch(590 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 32768); /* line 1055 */
} /* line 1055 */
  sim_icache_fetch(592 + t_thisfile.offset, 1);
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
} /* line 1057 */
		 /* line 1058 */
  sim_icache_fetch(593 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1060 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1061 */
l_lr_85: ;/* line 1061 */
__LABEL(l_lr_85);
  sim_icache_fetch(597 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1063 */
l_L42X3: ;/* line 1066 */
__LABEL(l_L42X3);
  sim_icache_fetch(598 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) fsize,0,4)); /* line 1067 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1068 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1069 */
   __ADD_CYCLES(1);
} /* line 1069 */
  sim_icache_fetch(603 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 47000); /* line 1071 */
} /* line 1071 */
  sim_icache_fetch(605 + t_thisfile.offset, 1);
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
} /* line 1073 */
		 /* line 1074 */
  sim_icache_fetch(606 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1076 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1077 */
l_lr_88: ;/* line 1077 */
__LABEL(l_lr_88);
  sim_icache_fetch(610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1079 */
l_L43X3: ;/* line 1082 */
__LABEL(l_L43X3);
		 /* line 1082 */
  sim_icache_fetch(611 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressf);
   reg_l0_0 = (195 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressf;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1084 */
l_lr_91: ;/* line 1084 */
__LABEL(l_lr_91);
  sim_icache_fetch(613 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L30X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L30X3;
} /* line 1086 */
l_L27X3: ;/* line 1089 */
__LABEL(l_L27X3);
  sim_icache_fetch(614 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1090 */
   __MOV(reg_r0_6, (unsigned int) 5003); /* line 1091 */
} /* line 1091 */
  sim_icache_fetch(617 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) hsize,0,4), reg_r0_6); /* line 1093 */
   __GOTO(l_L28X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L28X3;
} /* line 1094 */
l_L25X3: ;/* line 1097 */
__LABEL(l_L25X3);
  sim_icache_fetch(620 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) 12); /* line 1098 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 1100 */
} /* line 1100 */
  sim_icache_fetch(622 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L26X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L26X3;
} /* line 1102 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 130: goto l_lr_29;
    case 131: goto l_L17X3;
    case 132: goto l_L20X3;
    case 133: goto l__X1XCompressXTAGX0X0;
    case 134: goto l__X1XCompressXTAGX0X7;
    case 135: goto l__X1XCompressXTAGX0X6;
    case 136: goto l__X1XCompressXTAGX0X5;
    case 137: goto l__X1XCompressXTAGX0X4;
    case 138: goto l__X1XCompressXTAGX0X3;
    case 139: goto l__X1XCompressXTAGX0X2;
    case 140: goto l_L19X3;
    case 141: goto l_L22X3;
    case 142: goto l_L23X3;
    case 144: goto l_lr_43;
    case 146: goto l_lr_45;
    case 147: goto l__X1XCompressXTAGX0X1;
    case 149: goto l_lr_48;
    case 150: goto l_L24X3;
    case 151: goto l__X1XCompressXTAGX0XDEFAULT;
    case 153: goto l_lr_52;
    case 155: goto l_lr_54;
    case 156: goto l_L21X3;
    case 157: goto l_L18X3;
    case 158: goto l_L26X3;
    case 159: goto l_L28X3;
    case 161: goto l_lr_60;
    case 162: goto l_L30X3;
    case 163: goto l_L34X3;
    case 165: goto l_lr_64;
    case 166: goto l_L33X3;
    case 167: goto l_L36X3;
    case 168: goto l_L37X3;
    case 169: goto l_L39X3;
    case 171: goto l_lr_70;
    case 172: goto l_L31X3;
    case 174: goto l_lr_73;
    case 175: goto l_L38X3;
    case 176: goto l_L35X3;
    case 177: goto l_L32X3;
    case 178: goto l_L29X3;
    case 180: goto l_lr_79;
    case 181: goto l_L40X3;
    case 183: goto l_lr_82;
    case 184: goto l_L41X3;
    case 186: goto l_lr_85;
    case 187: goto l_L42X3;
    case 189: goto l_lr_88;
    case 190: goto l_L43X3;
    case 192: goto l_lr_91;
    case 193: goto l_L27X3;
    case 194: goto l_L25X3;
    case 195:
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
  reg_l0_0 = (308 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(623 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1240 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) nomagic,0,4)); /* line 1241 */
} /* line 1241 */
  sim_icache_fetch(626 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 3); /* line 1243 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1244 */
} /* line 1244 */
  sim_icache_fetch(628 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_5, 0); /* line 1246 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 1247 */
} /* line 1247 */
  sim_icache_fetch(630 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) 10000); /* line 1249 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1250 */
l_L45X3: ;/* line 1252 */
__LABEL(l_L45X3);
  sim_icache_fetch(633 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) 511); /* line 1253 */
   __MOV(reg_r0_8, (unsigned int) 9); /* line 1254 */
} /* line 1254 */
  sim_icache_fetch(636 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1256 */
   __MOV(reg_r0_11, (unsigned int) 257); /* line 1257 */
} /* line 1257 */
  sim_icache_fetch(640 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_12, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1259 */
   __LDWs(reg_r0_13, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1260 */
} /* line 1260 */
  sim_icache_fetch(644 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_10, 0); /* line 1262 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1263 */
} /* line 1263 */
  sim_icache_fetch(647 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, (unsigned int) 256); /* line 1265 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) -1); /* line 1266 */
} /* line 1266 */
  sim_icache_fetch(650 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_12, 0); /* line 1268 */
   __ADD(reg_r0_10, reg_r0_13, (unsigned int) 1); /* line 1269 */
} /* line 1269 */
  sim_icache_fetch(652 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, 0); /* line 1271 */
   __MOV(reg_r0_3, (unsigned int) 65536); /* line 1272 */
} /* line 1272 */
  sim_icache_fetch(655 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_8838Xoffset,0,4), 0); /* line 1274 */
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_5); /* line 1275 */
} /* line 1275 */
  sim_icache_fetch(659 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 1277 */
   __MOV(reg_r0_5, reg_l0_0); /* line 1278 */
} /* line 1278 */
  sim_icache_fetch(662 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), 0); /* line 1280 */
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 1281 */
} /* line 1281 */
  sim_icache_fetch(666 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 1283 */
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_7); /* line 1284 */
} /* line 1284 */
  sim_icache_fetch(670 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_8); /* line 1286 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_9); /* line 1287 */
} /* line 1287 */
  sim_icache_fetch(674 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1289 */
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_12); /* line 1290 */
} /* line 1290 */
  sim_icache_fetch(678 + t_thisfile.offset, 1);
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
} /* line 1292 */
  sim_icache_fetch(679 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_10); /* line 1294 */
} /* line 1294 */
  sim_icache_fetch(681 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 1296 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1297 */
   __ADD_CYCLES(1);
} /* line 1297 */
  sim_icache_fetch(683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_13, reg_r0_13); /* line 1299 */
} /* line 1299 */
l_L47X3: ;/* line 1301 */
__LABEL(l_L47X3);
  sim_icache_fetch(684 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, reg_r0_13); /* line 1302 */
} /* line 1302 */
l_L48X3: ;/* line 1305 */
__LABEL(l_L48X3);
  sim_icache_fetch(685 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1306 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1307 */
} /* line 1307 */
  sim_icache_fetch(687 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1309 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1310 */
  sim_icache_fetch(689 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1312 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1313 */
  sim_icache_fetch(691 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1315 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1316 */
} /* line 1316 */
  sim_icache_fetch(693 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1318 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L51X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1319 */
  sim_icache_fetch(695 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1321 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1322 */
  sim_icache_fetch(697 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1324 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1325 */
} /* line 1325 */
  sim_icache_fetch(699 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1327 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L53X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1328 */
  sim_icache_fetch(701 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1330 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1331 */
  sim_icache_fetch(703 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1333 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1334 */
} /* line 1334 */
  sim_icache_fetch(705 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1336 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L55X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1337 */
  sim_icache_fetch(707 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1339 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1340 */
  sim_icache_fetch(709 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1342 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1343 */
} /* line 1343 */
  sim_icache_fetch(711 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1345 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1346 */
  sim_icache_fetch(713 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1348 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1349 */
  sim_icache_fetch(715 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1351 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1352 */
} /* line 1352 */
  sim_icache_fetch(717 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1354 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1355 */
  sim_icache_fetch(719 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1357 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1358 */
  sim_icache_fetch(721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1360 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1361 */
} /* line 1361 */
  sim_icache_fetch(723 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1363 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1364 */
  sim_icache_fetch(725 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1366 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1367 */
  sim_icache_fetch(727 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1369 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1370 */
} /* line 1370 */
  sim_icache_fetch(729 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1372 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1373 */
  sim_icache_fetch(731 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1375 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1376 */
  sim_icache_fetch(733 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1378 */
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1379 */
} /* line 1379 */
  sim_icache_fetch(735 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1381 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1382 */
  sim_icache_fetch(737 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1384 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1385 */
} /* line 1385 */
  sim_icache_fetch(739 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1387 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1388 */
  sim_icache_fetch(741 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1390 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L51X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1391 */
  sim_icache_fetch(743 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1393 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1394 */
} /* line 1394 */
  sim_icache_fetch(745 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1396 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1397 */
  sim_icache_fetch(747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1399 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L53X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1400 */
  sim_icache_fetch(749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1402 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1403 */
} /* line 1403 */
  sim_icache_fetch(751 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1405 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1406 */
  sim_icache_fetch(753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1408 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L55X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1409 */
  sim_icache_fetch(755 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1411 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1412 */
} /* line 1412 */
  sim_icache_fetch(757 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1414 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1415 */
  sim_icache_fetch(759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1417 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1418 */
  sim_icache_fetch(761 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1420 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1421 */
} /* line 1421 */
  sim_icache_fetch(763 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1423 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1424 */
  sim_icache_fetch(765 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1426 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1427 */
  sim_icache_fetch(767 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1429 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1430 */
} /* line 1430 */
  sim_icache_fetch(769 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1432 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1433 */
  sim_icache_fetch(771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1435 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1436 */
  sim_icache_fetch(773 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1438 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1439 */
} /* line 1439 */
  sim_icache_fetch(775 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1441 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1442 */
  sim_icache_fetch(777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1444 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1445 */
  sim_icache_fetch(779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 1447 */
   __SHL(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 1448 */
} /* line 1448 */
  sim_icache_fetch(781 + t_thisfile.offset, 1);
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
} /* line 1450 */
  sim_icache_fetch(782 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1452 */
   __GOTO(l_L48X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L48X3;
} /* line 1453 */
l_L64X3: ;/* line 1456 */
__LABEL(l_L64X3);
  sim_icache_fetch(784 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 1457 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 1458 */
} /* line 1458 */
  sim_icache_fetch(786 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 1460 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 1461 */
} /* line 1461 */
  sim_icache_fetch(789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 15); /* line 1463 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 1464 */
l_L66X3: ;/* line 1467 */
__LABEL(l_L66X3);
  sim_icache_fetch(791 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) buflen,0,4)); /* line 1468 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 1469 */
} /* line 1469 */
  sim_icache_fetch(795 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_9, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1471 */
   __LDWs(reg_r0_10, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 1472 */
} /* line 1472 */
  sim_icache_fetch(799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 1474 */
   __ADD(reg_r0_11, reg_r0_6, (unsigned int) 1); /* line 1475 */
} /* line 1475 */
  sim_icache_fetch(801 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 1477 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 1); /* line 1478 */
} /* line 1478 */
  sim_icache_fetch(803 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_3); /* line 1480 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1481 */
  sim_icache_fetch(806 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_11); /* line 1483 */
} /* line 1483 */
  sim_icache_fetch(808 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 1485 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1486 */
   __ADD_CYCLES(1);
} /* line 1486 */
  sim_icache_fetch(810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 1488 */
} /* line 1488 */
l_L68X3: ;/* line 1490 */
__LABEL(l_L68X3);
  sim_icache_fetch(811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_6, (unsigned int) -1); /* line 1491 */
   __SHL(reg_r0_3, reg_r0_6, reg_r0_7); /* line 1492 */
} /* line 1492 */
  sim_icache_fetch(813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __XOR(reg_r0_2, reg_r0_8, reg_r0_3); /* line 1494 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1495 */
  sim_icache_fetch(815 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_10, reg_r0_6, reg_r0_10); /* line 1497 */
   __SH2ADD(reg_r0_3, reg_r0_2, (unsigned int) htab); /* line 1498 */
} /* line 1498 */
  sim_icache_fetch(818 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_10, reg_r0_8); /* line 1500 */
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 1501 */
} /* line 1501 */
  sim_icache_fetch(820 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) in_count,0,4), reg_r0_9); /* line 1503 */
   __SH1ADD(reg_r0_10, reg_r0_2, (unsigned int) codetab); /* line 1504 */
} /* line 1504 */
  sim_icache_fetch(824 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_3, reg_r0_5); /* line 1506 */
} /* line 1506 */
  sim_icache_fetch(825 + t_thisfile.offset, 1);
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
} /* line 1508 */
  sim_icache_fetch(826 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_8, mem_trace_ld(reg_r0_10,0,2)); /* line 1510 */
} /* line 1510 */
  sim_icache_fetch(827 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1512 */
l_L70X3: ;/* line 1515 */
__LABEL(l_L70X3);
  sim_icache_fetch(828 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 1516 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_7); /* line 1517 */
} /* line 1517 */
  sim_icache_fetch(830 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_6); /* line 1519 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 1520 */
} /* line 1520 */
  sim_icache_fetch(832 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_2, reg_r0_2, (unsigned int) htab); /* line 1522 */
   __MOV(reg_r0_3, reg_r0_8); /* line 1523 */
} /* line 1523 */
  sim_icache_fetch(835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld(reg_r0_2,0,4)); /* line 1525 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 1526 */
   __ADD_CYCLES(1);
} /* line 1526 */
  sim_icache_fetch(837 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1528 */
} /* line 1528 */
  sim_icache_fetch(838 + t_thisfile.offset, 1);
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
} /* line 1530 */
l_L72X3: ;/* line 1532 */
__LABEL(l_L72X3);
		 /* line 1532 */
  sim_icache_fetch(839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (308 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1534 */
l_lr_104: ;/* line 1534 */
__LABEL(l_lr_104);
  sim_icache_fetch(841 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) out_count,0,4)); /* line 1536 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1537 */
} /* line 1537 */
  sim_icache_fetch(844 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 1539 */
   __LDW(reg_r0_10, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 1540 */
} /* line 1540 */
  sim_icache_fetch(848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1542 */
   __MOV(reg_r0_8, reg_r0_6); /* line 1543 */
} /* line 1543 */
  sim_icache_fetch(850 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_10); /* line 1545 */
   __ADD(reg_r0_11, reg_r0_9, (unsigned int) 1); /* line 1546 */
} /* line 1546 */
  sim_icache_fetch(852 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1548 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1549 */
} /* line 1549 */
  sim_icache_fetch(854 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_3); /* line 1551 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1552 */
} /* line 1552 */
  sim_icache_fetch(857 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 1554 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1555 */
  sim_icache_fetch(860 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_11); /* line 1557 */
   __SH2ADD(reg_r0_2, reg_r0_2, (unsigned int) htab); /* line 1558 */
} /* line 1558 */
  sim_icache_fetch(864 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_9); /* line 1560 */
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_5); /* line 1562 */
} /* line 1562 */
  sim_icache_fetch(866 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1564 */
l_L73X3: ;/* line 1567 */
__LABEL(l_L73X3);
  sim_icache_fetch(867 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_7); /* line 1568 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_8); /* line 1569 */
} /* line 1569 */
  sim_icache_fetch(869 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 1571 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) checkpoint,0,4)); /* line 1572 */
} /* line 1572 */
  sim_icache_fetch(873 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 1574 */
} /* line 1574 */
  sim_icache_fetch(875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1576 */
} /* line 1576 */
  sim_icache_fetch(876 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ANDL(reg_b0_0, reg_r0_2, reg_r0_5); /* line 1578 */
} /* line 1578 */
  sim_icache_fetch(877 + t_thisfile.offset, 1);
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
} /* line 1580 */
		 /* line 1581 */
  sim_icache_fetch(878 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_block);
   reg_l0_0 = (308 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) cl_block;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 1583 */
l_lr_107: ;/* line 1583 */
__LABEL(l_lr_107);
  sim_icache_fetch(880 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1585 */
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1586 */
} /* line 1586 */
  sim_icache_fetch(882 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1588 */
l_L74X3: ;/* line 1591 */
__LABEL(l_L74X3);
  sim_icache_fetch(883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1592 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 1595 */
l_L71X3: ;/* line 1598 */
__LABEL(l_L71X3);
  sim_icache_fetch(886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1599 */
   __MOV(reg_r0_4, reg_r0_57); /* line 1600 */
} /* line 1600 */
  sim_icache_fetch(888 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1602 */
   __MOV(reg_r0_10, reg_r0_8); /* line 1603 */
} /* line 1603 */
  sim_icache_fetch(890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_57, reg_r0_57, reg_r0_2); /* line 1605 */
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 1606 */
} /* line 1606 */
  sim_icache_fetch(892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 1608 */
} /* line 1608 */
l_L75X3: ;/* line 1611 */
__LABEL(l_L75X3);
  sim_icache_fetch(893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_2, reg_r0_2, reg_r0_3); /* line 1612 */
} /* line 1612 */
  sim_icache_fetch(894 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 1614 */
   __ADD(reg_r0_6, reg_r0_2, reg_r0_4); /* line 1615 */
} /* line 1615 */
  sim_icache_fetch(896 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_2, reg_r0_6); /* line 1617 */
} /* line 1617 */
  sim_icache_fetch(897 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1619 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1620 */
} /* line 1620 */
  sim_icache_fetch(900 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1622 */
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1623 */
} /* line 1623 */
  sim_icache_fetch(902 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_4, reg_r0_7); /* line 1625 */
} /* line 1625 */
  sim_icache_fetch(903 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1627 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1628 */
} /* line 1628 */
  sim_icache_fetch(905 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1630 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1631 */
  sim_icache_fetch(907 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1633 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1634 */
  sim_icache_fetch(910 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1636 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1637 */
} /* line 1637 */
  sim_icache_fetch(912 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1639 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1640 */
} /* line 1640 */
  sim_icache_fetch(914 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1642 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1643 */
} /* line 1643 */
  sim_icache_fetch(916 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1645 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1646 */
  sim_icache_fetch(918 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1648 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1649 */
  sim_icache_fetch(921 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1651 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1652 */
} /* line 1652 */
  sim_icache_fetch(923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1654 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1655 */
} /* line 1655 */
  sim_icache_fetch(925 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1657 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1658 */
} /* line 1658 */
  sim_icache_fetch(927 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1660 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1661 */
  sim_icache_fetch(929 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1663 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1664 */
  sim_icache_fetch(932 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1666 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1667 */
} /* line 1667 */
  sim_icache_fetch(934 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1669 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1670 */
} /* line 1670 */
  sim_icache_fetch(936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1672 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1673 */
} /* line 1673 */
  sim_icache_fetch(938 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1675 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1676 */
  sim_icache_fetch(940 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1678 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1679 */
  sim_icache_fetch(943 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1681 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1682 */
} /* line 1682 */
  sim_icache_fetch(945 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1684 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1685 */
} /* line 1685 */
  sim_icache_fetch(947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1687 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1688 */
} /* line 1688 */
  sim_icache_fetch(949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1690 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1691 */
  sim_icache_fetch(951 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1693 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L85X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1694 */
  sim_icache_fetch(954 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1696 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1697 */
} /* line 1697 */
  sim_icache_fetch(956 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1699 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1700 */
} /* line 1700 */
  sim_icache_fetch(958 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1702 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1703 */
} /* line 1703 */
  sim_icache_fetch(960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1705 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1706 */
  sim_icache_fetch(962 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1708 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1709 */
  sim_icache_fetch(965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1711 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1712 */
} /* line 1712 */
  sim_icache_fetch(967 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1714 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1715 */
} /* line 1715 */
  sim_icache_fetch(969 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1717 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(971 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1720 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1721 */
  sim_icache_fetch(973 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1723 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1724 */
  sim_icache_fetch(976 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1726 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1727 */
} /* line 1727 */
  sim_icache_fetch(978 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1729 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1730 */
} /* line 1730 */
  sim_icache_fetch(980 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1732 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1733 */
} /* line 1733 */
  sim_icache_fetch(982 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1735 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1736 */
  sim_icache_fetch(984 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1738 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1739 */
  sim_icache_fetch(987 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1741 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1742 */
} /* line 1742 */
  sim_icache_fetch(989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1744 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1745 */
} /* line 1745 */
  sim_icache_fetch(991 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1747 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1748 */
} /* line 1748 */
  sim_icache_fetch(993 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1750 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1751 */
  sim_icache_fetch(995 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1753 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1754 */
  sim_icache_fetch(998 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1756 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(1000 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1759 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1760 */
} /* line 1760 */
  sim_icache_fetch(1002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1762 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1763 */
} /* line 1763 */
  sim_icache_fetch(1004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1765 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1766 */
  sim_icache_fetch(1006 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1768 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1769 */
  sim_icache_fetch(1009 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1771 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1772 */
} /* line 1772 */
  sim_icache_fetch(1011 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1774 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1775 */
} /* line 1775 */
  sim_icache_fetch(1013 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1777 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1778 */
} /* line 1778 */
  sim_icache_fetch(1015 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1780 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1781 */
  sim_icache_fetch(1017 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1783 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1784 */
  sim_icache_fetch(1020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1786 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1787 */
} /* line 1787 */
  sim_icache_fetch(1022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1789 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1790 */
} /* line 1790 */
  sim_icache_fetch(1024 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1792 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1793 */
} /* line 1793 */
  sim_icache_fetch(1026 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1795 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1796 */
  sim_icache_fetch(1028 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1798 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1799 */
  sim_icache_fetch(1031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1801 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1802 */
} /* line 1802 */
  sim_icache_fetch(1033 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1804 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1805 */
} /* line 1805 */
  sim_icache_fetch(1035 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1807 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1808 */
} /* line 1808 */
  sim_icache_fetch(1037 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1810 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1811 */
  sim_icache_fetch(1039 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1813 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1814 */
  sim_icache_fetch(1042 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1816 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1817 */
} /* line 1817 */
  sim_icache_fetch(1044 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1819 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1820 */
} /* line 1820 */
  sim_icache_fetch(1046 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1822 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1823 */
} /* line 1823 */
  sim_icache_fetch(1048 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1825 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1826 */
  sim_icache_fetch(1050 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1828 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1829 */
  sim_icache_fetch(1053 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1831 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1832 */
} /* line 1832 */
  sim_icache_fetch(1055 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1834 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1835 */
} /* line 1835 */
  sim_icache_fetch(1057 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1837 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1838 */
} /* line 1838 */
  sim_icache_fetch(1059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1840 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1841 */
  sim_icache_fetch(1061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 1843 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1844 */
  sim_icache_fetch(1064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1846 */
   __SUB(reg_r0_7, reg_r0_2, reg_r0_3); /* line 1847 */
} /* line 1847 */
  sim_icache_fetch(1066 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1849 */
   __ADD(reg_r0_8, reg_r0_7, reg_r0_4); /* line 1850 */
} /* line 1850 */
  sim_icache_fetch(1068 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1852 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1853 */
} /* line 1853 */
  sim_icache_fetch(1070 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_8); /* line 1855 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1856 */
  sim_icache_fetch(1072 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1858 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1859 */
  sim_icache_fetch(1075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1861 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1862 */
} /* line 1862 */
  sim_icache_fetch(1077 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1864 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1865 */
} /* line 1865 */
  sim_icache_fetch(1079 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1867 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1868 */
} /* line 1868 */
  sim_icache_fetch(1081 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1870 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1871 */
  sim_icache_fetch(1083 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1873 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1874 */
  sim_icache_fetch(1086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1876 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1877 */
} /* line 1877 */
  sim_icache_fetch(1088 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1879 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1880 */
} /* line 1880 */
  sim_icache_fetch(1090 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1882 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1883 */
} /* line 1883 */
  sim_icache_fetch(1092 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1885 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1886 */
  sim_icache_fetch(1094 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1888 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1889 */
  sim_icache_fetch(1097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1891 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1892 */
} /* line 1892 */
  sim_icache_fetch(1099 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1894 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1895 */
} /* line 1895 */
  sim_icache_fetch(1101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1897 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1898 */
} /* line 1898 */
  sim_icache_fetch(1103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1900 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1901 */
  sim_icache_fetch(1105 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1903 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1904 */
  sim_icache_fetch(1108 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1906 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1907 */
} /* line 1907 */
  sim_icache_fetch(1110 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1909 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1910 */
} /* line 1910 */
  sim_icache_fetch(1112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1912 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1913 */
} /* line 1913 */
  sim_icache_fetch(1114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1915 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1916 */
  sim_icache_fetch(1116 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1918 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1919 */
  sim_icache_fetch(1119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1921 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1922 */
} /* line 1922 */
  sim_icache_fetch(1121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1924 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1925 */
} /* line 1925 */
  sim_icache_fetch(1123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1927 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1928 */
} /* line 1928 */
  sim_icache_fetch(1125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1930 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1931 */
  sim_icache_fetch(1127 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1933 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1934 */
  sim_icache_fetch(1130 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1936 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1937 */
} /* line 1937 */
  sim_icache_fetch(1132 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1939 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1940 */
} /* line 1940 */
  sim_icache_fetch(1134 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1942 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1943 */
} /* line 1943 */
  sim_icache_fetch(1136 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1945 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1946 */
  sim_icache_fetch(1138 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1948 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1949 */
  sim_icache_fetch(1141 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1951 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1952 */
} /* line 1952 */
  sim_icache_fetch(1143 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1954 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1955 */
} /* line 1955 */
  sim_icache_fetch(1145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1957 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1958 */
} /* line 1958 */
  sim_icache_fetch(1147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1960 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1961 */
  sim_icache_fetch(1149 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1963 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1964 */
  sim_icache_fetch(1152 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1966 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1967 */
} /* line 1967 */
  sim_icache_fetch(1154 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1969 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 1970 */
} /* line 1970 */
  sim_icache_fetch(1156 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1972 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1973 */
} /* line 1973 */
  sim_icache_fetch(1158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 1975 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1976 */
  sim_icache_fetch(1160 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 1978 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1979 */
  sim_icache_fetch(1163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1981 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 1982 */
} /* line 1982 */
  sim_icache_fetch(1165 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 1984 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 1985 */
} /* line 1985 */
  sim_icache_fetch(1167 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 1987 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 1988 */
} /* line 1988 */
  sim_icache_fetch(1169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 1990 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1991 */
  sim_icache_fetch(1171 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 1993 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 1994 */
  sim_icache_fetch(1174 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 1996 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 1997 */
} /* line 1997 */
  sim_icache_fetch(1176 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1999 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 2000 */
} /* line 2000 */
  sim_icache_fetch(1178 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 2002 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 2003 */
} /* line 2003 */
  sim_icache_fetch(1180 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 2005 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2006 */
  sim_icache_fetch(1182 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2008 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2009 */
  sim_icache_fetch(1185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2011 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2012 */
} /* line 2012 */
  sim_icache_fetch(1187 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2014 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 2015 */
} /* line 2015 */
  sim_icache_fetch(1189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 2017 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 2018 */
} /* line 2018 */
  sim_icache_fetch(1191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 2020 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2021 */
  sim_icache_fetch(1193 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2023 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2024 */
  sim_icache_fetch(1196 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2026 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2027 */
} /* line 2027 */
  sim_icache_fetch(1198 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2029 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 2030 */
} /* line 2030 */
  sim_icache_fetch(1200 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 2032 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 2033 */
} /* line 2033 */
  sim_icache_fetch(1202 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 2035 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2036 */
  sim_icache_fetch(1204 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2038 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2039 */
  sim_icache_fetch(1207 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2041 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2042 */
} /* line 2042 */
  sim_icache_fetch(1209 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2044 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 2045 */
} /* line 2045 */
  sim_icache_fetch(1211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 2047 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 2048 */
} /* line 2048 */
  sim_icache_fetch(1213 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_9); /* line 2050 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2051 */
  sim_icache_fetch(1215 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_8, (unsigned int) htab); /* line 2053 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2054 */
  sim_icache_fetch(1218 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2056 */
   __SUB(reg_r0_7, reg_r0_8, reg_r0_3); /* line 2057 */
} /* line 2057 */
  sim_icache_fetch(1220 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2059 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_7); /* line 2060 */
} /* line 2060 */
  sim_icache_fetch(1222 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 2062 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 2063 */
} /* line 2063 */
  sim_icache_fetch(1224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 2065 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2066 */
  sim_icache_fetch(1226 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_7, (unsigned int) htab); /* line 2068 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2069 */
  sim_icache_fetch(1229 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2071 */
   __SUB(reg_r0_8, reg_r0_7, reg_r0_3); /* line 2072 */
} /* line 2072 */
  sim_icache_fetch(1231 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_8, 0); /* line 2074 */
   __ADD(reg_r0_9, reg_r0_4, reg_r0_8); /* line 2075 */
} /* line 2075 */
  sim_icache_fetch(1233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_1, reg_r0_6, reg_r0_5); /* line 2077 */
   __CMPGT(reg_b0_2, reg_r0_6, 0); /* line 2078 */
} /* line 2078 */
  sim_icache_fetch(1235 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_2, reg_b0_0, reg_r0_8, reg_r0_9); /* line 2080 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2081 */
  sim_icache_fetch(1237 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH2ADD(reg_r0_6, reg_r0_2, (unsigned int) htab); /* line 2083 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2084 */
  sim_icache_fetch(1240 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_6, mem_trace_ld(reg_r0_6,0,4)); /* line 2086 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2087 */
   __ADD_CYCLES(1);
} /* line 2087 */
  sim_icache_fetch(1242 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_5); /* line 2089 */
   __CMPGT(reg_b0_1, reg_r0_6, 0); /* line 2090 */
} /* line 2090 */
  sim_icache_fetch(1244 + t_thisfile.offset, 1);
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
} /* line 2092 */
  sim_icache_fetch(1245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2095 */
  sim_icache_fetch(1246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L75X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L75X3;
} /* line 2097 */
l_L138X3: ;/* line 2100 */
__LABEL(l_L138X3);
  sim_icache_fetch(1247 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2101 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2102 */
} /* line 2102 */
  sim_icache_fetch(1249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2104 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2106 */
} /* line 2106 */
  sim_icache_fetch(1251 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2108 */
l_L106X3: ;/* line 2112 */
__LABEL(l_L106X3);
  sim_icache_fetch(1252 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2114 */
} /* line 2114 */
  sim_icache_fetch(1253 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2116 */
l_L137X3: ;/* line 2119 */
__LABEL(l_L137X3);
  sim_icache_fetch(1254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2120 */
} /* line 2120 */
l_L105X3: ;/* line 2123 */
__LABEL(l_L105X3);
  sim_icache_fetch(1255 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2124 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2125 */
} /* line 2125 */
  sim_icache_fetch(1257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2127 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2128 */
} /* line 2128 */
  sim_icache_fetch(1259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2130 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2131 */
l_L136X3: ;/* line 2134 */
__LABEL(l_L136X3);
  sim_icache_fetch(1261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2135 */
} /* line 2135 */
l_L104X3: ;/* line 2138 */
__LABEL(l_L104X3);
  sim_icache_fetch(1262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2139 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2141 */
} /* line 2141 */
  sim_icache_fetch(1264 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2143 */
l_L135X3: ;/* line 2146 */
__LABEL(l_L135X3);
  sim_icache_fetch(1265 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2147 */
} /* line 2147 */
l_L103X3: ;/* line 2150 */
__LABEL(l_L103X3);
  sim_icache_fetch(1266 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2151 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2152 */
} /* line 2152 */
  sim_icache_fetch(1268 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2154 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2155 */
} /* line 2155 */
  sim_icache_fetch(1270 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2157 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2158 */
l_L134X3: ;/* line 2161 */
__LABEL(l_L134X3);
  sim_icache_fetch(1272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2162 */
} /* line 2162 */
l_L102X3: ;/* line 2165 */
__LABEL(l_L102X3);
  sim_icache_fetch(1273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2166 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2168 */
} /* line 2168 */
  sim_icache_fetch(1275 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2170 */
l_L133X3: ;/* line 2173 */
__LABEL(l_L133X3);
  sim_icache_fetch(1276 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2174 */
} /* line 2174 */
l_L101X3: ;/* line 2177 */
__LABEL(l_L101X3);
  sim_icache_fetch(1277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2178 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2179 */
} /* line 2179 */
  sim_icache_fetch(1279 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2181 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2182 */
} /* line 2182 */
  sim_icache_fetch(1281 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2184 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2185 */
l_L132X3: ;/* line 2188 */
__LABEL(l_L132X3);
  sim_icache_fetch(1283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2189 */
} /* line 2189 */
l_L100X3: ;/* line 2192 */
__LABEL(l_L100X3);
  sim_icache_fetch(1284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2193 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2195 */
} /* line 2195 */
  sim_icache_fetch(1286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2197 */
l_L131X3: ;/* line 2200 */
__LABEL(l_L131X3);
  sim_icache_fetch(1287 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2201 */
} /* line 2201 */
l_L99X3: ;/* line 2204 */
__LABEL(l_L99X3);
  sim_icache_fetch(1288 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2205 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2206 */
} /* line 2206 */
  sim_icache_fetch(1290 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2208 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2209 */
} /* line 2209 */
  sim_icache_fetch(1292 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2211 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2212 */
l_L130X3: ;/* line 2215 */
__LABEL(l_L130X3);
  sim_icache_fetch(1294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2216 */
} /* line 2216 */
l_L98X3: ;/* line 2219 */
__LABEL(l_L98X3);
  sim_icache_fetch(1295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2220 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2222 */
} /* line 2222 */
  sim_icache_fetch(1297 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2224 */
l_L129X3: ;/* line 2227 */
__LABEL(l_L129X3);
  sim_icache_fetch(1298 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2228 */
} /* line 2228 */
l_L97X3: ;/* line 2231 */
__LABEL(l_L97X3);
  sim_icache_fetch(1299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2232 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2233 */
} /* line 2233 */
  sim_icache_fetch(1301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2235 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2236 */
} /* line 2236 */
  sim_icache_fetch(1303 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2238 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2239 */
l_L128X3: ;/* line 2242 */
__LABEL(l_L128X3);
  sim_icache_fetch(1305 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2243 */
} /* line 2243 */
l_L96X3: ;/* line 2246 */
__LABEL(l_L96X3);
  sim_icache_fetch(1306 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2247 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2249 */
} /* line 2249 */
  sim_icache_fetch(1308 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2251 */
l_L127X3: ;/* line 2254 */
__LABEL(l_L127X3);
  sim_icache_fetch(1309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2255 */
} /* line 2255 */
l_L95X3: ;/* line 2258 */
__LABEL(l_L95X3);
  sim_icache_fetch(1310 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2259 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2260 */
} /* line 2260 */
  sim_icache_fetch(1312 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2262 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2263 */
} /* line 2263 */
  sim_icache_fetch(1314 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2265 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2266 */
l_L126X3: ;/* line 2269 */
__LABEL(l_L126X3);
  sim_icache_fetch(1316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2270 */
} /* line 2270 */
l_L94X3: ;/* line 2273 */
__LABEL(l_L94X3);
  sim_icache_fetch(1317 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2274 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2276 */
} /* line 2276 */
  sim_icache_fetch(1319 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2278 */
l_L125X3: ;/* line 2281 */
__LABEL(l_L125X3);
  sim_icache_fetch(1320 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2282 */
} /* line 2282 */
l_L93X3: ;/* line 2285 */
__LABEL(l_L93X3);
  sim_icache_fetch(1321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2286 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2287 */
} /* line 2287 */
  sim_icache_fetch(1323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2289 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2290 */
} /* line 2290 */
  sim_icache_fetch(1325 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2292 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2293 */
l_L124X3: ;/* line 2296 */
__LABEL(l_L124X3);
  sim_icache_fetch(1327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2297 */
} /* line 2297 */
l_L92X3: ;/* line 2300 */
__LABEL(l_L92X3);
  sim_icache_fetch(1328 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2301 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2303 */
} /* line 2303 */
  sim_icache_fetch(1330 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2305 */
l_L123X3: ;/* line 2308 */
__LABEL(l_L123X3);
  sim_icache_fetch(1331 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2309 */
} /* line 2309 */
l_L91X3: ;/* line 2312 */
__LABEL(l_L91X3);
  sim_icache_fetch(1332 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2313 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2314 */
} /* line 2314 */
  sim_icache_fetch(1334 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2316 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2317 */
} /* line 2317 */
  sim_icache_fetch(1336 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2319 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2320 */
l_L122X3: ;/* line 2323 */
__LABEL(l_L122X3);
  sim_icache_fetch(1338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2324 */
} /* line 2324 */
l_L90X3: ;/* line 2327 */
__LABEL(l_L90X3);
  sim_icache_fetch(1339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2328 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2330 */
} /* line 2330 */
  sim_icache_fetch(1341 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2332 */
l_L121X3: ;/* line 2335 */
__LABEL(l_L121X3);
  sim_icache_fetch(1342 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2336 */
} /* line 2336 */
l_L89X3: ;/* line 2339 */
__LABEL(l_L89X3);
  sim_icache_fetch(1343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2340 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2341 */
} /* line 2341 */
  sim_icache_fetch(1345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2343 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2344 */
} /* line 2344 */
  sim_icache_fetch(1347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2346 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2347 */
l_L120X3: ;/* line 2350 */
__LABEL(l_L120X3);
  sim_icache_fetch(1349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2351 */
} /* line 2351 */
l_L88X3: ;/* line 2354 */
__LABEL(l_L88X3);
  sim_icache_fetch(1350 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2355 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2357 */
} /* line 2357 */
  sim_icache_fetch(1352 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2359 */
l_L119X3: ;/* line 2362 */
__LABEL(l_L119X3);
  sim_icache_fetch(1353 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2363 */
} /* line 2363 */
l_L87X3: ;/* line 2366 */
__LABEL(l_L87X3);
  sim_icache_fetch(1354 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2367 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2368 */
} /* line 2368 */
  sim_icache_fetch(1356 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2370 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2371 */
} /* line 2371 */
  sim_icache_fetch(1358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2373 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2374 */
l_L118X3: ;/* line 2377 */
__LABEL(l_L118X3);
  sim_icache_fetch(1360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2378 */
} /* line 2378 */
l_L86X3: ;/* line 2381 */
__LABEL(l_L86X3);
  sim_icache_fetch(1361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2382 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2384 */
} /* line 2384 */
  sim_icache_fetch(1363 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2386 */
l_L117X3: ;/* line 2389 */
__LABEL(l_L117X3);
  sim_icache_fetch(1364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2390 */
} /* line 2390 */
l_L85X3: ;/* line 2393 */
__LABEL(l_L85X3);
  sim_icache_fetch(1365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2394 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2395 */
} /* line 2395 */
  sim_icache_fetch(1367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2397 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2398 */
} /* line 2398 */
  sim_icache_fetch(1369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2400 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2401 */
l_L116X3: ;/* line 2404 */
__LABEL(l_L116X3);
  sim_icache_fetch(1371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2405 */
} /* line 2405 */
l_L84X3: ;/* line 2408 */
__LABEL(l_L84X3);
  sim_icache_fetch(1372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2409 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2411 */
} /* line 2411 */
  sim_icache_fetch(1374 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2413 */
l_L115X3: ;/* line 2416 */
__LABEL(l_L115X3);
  sim_icache_fetch(1375 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2417 */
} /* line 2417 */
l_L83X3: ;/* line 2420 */
__LABEL(l_L83X3);
  sim_icache_fetch(1376 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2421 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2422 */
} /* line 2422 */
  sim_icache_fetch(1378 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2424 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2425 */
} /* line 2425 */
  sim_icache_fetch(1380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2427 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2428 */
l_L114X3: ;/* line 2431 */
__LABEL(l_L114X3);
  sim_icache_fetch(1382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2432 */
} /* line 2432 */
l_L82X3: ;/* line 2435 */
__LABEL(l_L82X3);
  sim_icache_fetch(1383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2436 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2438 */
} /* line 2438 */
  sim_icache_fetch(1385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2440 */
l_L113X3: ;/* line 2443 */
__LABEL(l_L113X3);
  sim_icache_fetch(1386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2444 */
} /* line 2444 */
l_L81X3: ;/* line 2447 */
__LABEL(l_L81X3);
  sim_icache_fetch(1387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2448 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2449 */
} /* line 2449 */
  sim_icache_fetch(1389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2451 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2452 */
} /* line 2452 */
  sim_icache_fetch(1391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2454 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2455 */
l_L112X3: ;/* line 2458 */
__LABEL(l_L112X3);
  sim_icache_fetch(1393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, reg_r0_7); /* line 2459 */
} /* line 2459 */
l_L80X3: ;/* line 2462 */
__LABEL(l_L80X3);
  sim_icache_fetch(1394 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_8); /* line 2463 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2465 */
} /* line 2465 */
  sim_icache_fetch(1396 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2467 */
l_L111X3: ;/* line 2470 */
__LABEL(l_L111X3);
  sim_icache_fetch(1397 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2471 */
} /* line 2471 */
l_L79X3: ;/* line 2474 */
__LABEL(l_L79X3);
  sim_icache_fetch(1398 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2475 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2476 */
} /* line 2476 */
  sim_icache_fetch(1400 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2478 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2479 */
} /* line 2479 */
  sim_icache_fetch(1402 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2481 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2482 */
l_L110X3: ;/* line 2485 */
__LABEL(l_L110X3);
  sim_icache_fetch(1404 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, reg_r0_8); /* line 2486 */
} /* line 2486 */
l_L78X3: ;/* line 2489 */
__LABEL(l_L78X3);
  sim_icache_fetch(1405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 2490 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2492 */
} /* line 2492 */
  sim_icache_fetch(1407 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L139X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L139X3;
} /* line 2494 */
l_L109X3: ;/* line 2497 */
__LABEL(l_L109X3);
  sim_icache_fetch(1408 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2498 */
} /* line 2498 */
l_L77X3: ;/* line 2502 */
__LABEL(l_L77X3);
  sim_icache_fetch(1409 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2503 */
} /* line 2503 */
  sim_icache_fetch(1410 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2505 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2506 */
} /* line 2506 */
  sim_icache_fetch(1412 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_57, reg_r0_4); /* line 2508 */
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2509 */
l_L108X3: ;/* line 2512 */
__LABEL(l_L108X3);
  sim_icache_fetch(1414 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, reg_r0_7); /* line 2513 */
} /* line 2513 */
l_L76X3: ;/* line 2517 */
__LABEL(l_L76X3);
  sim_icache_fetch(1415 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_57, reg_r0_4); /* line 2518 */
} /* line 2518 */
l_L139X3: ;/* line 2520 */
__LABEL(l_L139X3);
  sim_icache_fetch(1416 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_2, reg_r0_2, (unsigned int) codetab); /* line 2521 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2522 */
} /* line 2522 */
  sim_icache_fetch(1419 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDHU(reg_r0_8, mem_trace_ld(reg_r0_2,0,2)); /* line 2524 */
} /* line 2524 */
  sim_icache_fetch(1420 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 2526 */
l_L107X3: ;/* line 2529 */
__LABEL(l_L107X3);
  sim_icache_fetch(1421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_2); /* line 2530 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 2531 */
} /* line 2531 */
  sim_icache_fetch(1423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_10); /* line 2533 */
   __MOV(reg_r0_57, reg_r0_4); /* line 2535 */
} /* line 2535 */
  sim_icache_fetch(1425 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L72X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L72X3;
} /* line 2537 */
l_L69X3: ;/* line 2540 */
__LABEL(l_L69X3);
		 /* line 2540 */
  sim_icache_fetch(1426 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_8); /* line 2543 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (308 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2543 */
l_lr_177: ;/* line 2543 */
__LABEL(l_lr_177);
  sim_icache_fetch(1429 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) out_count,0,4)); /* line 2545 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 2546 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2547 */
   __ADD_CYCLES(1);
} /* line 2547 */
  sim_icache_fetch(1433 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2549 */
} /* line 2549 */
		 /* line 2550 */
  sim_icache_fetch(1434 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) out_count,0,4), reg_r0_2); /* line 2552 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (308 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2553 */
l_lr_179: ;/* line 2553 */
__LABEL(l_lr_179);
  sim_icache_fetch(1438 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) zcat_flg,0,4)); /* line 2555 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) quiet,0,4)); /* line 2556 */
} /* line 2556 */
  sim_icache_fetch(1442 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2558 */
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2559 */
} /* line 2559 */
  sim_icache_fetch(1446 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __NORL(reg_b0_0, reg_r0_2, reg_r0_4); /* line 2561 */
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2562 */
} /* line 2562 */
  sim_icache_fetch(1448 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, reg_r0_7); /* line 2564 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L140X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2565 */
l_L141X3: ;/* line 2567 */
__LABEL(l_L141X3);
  sim_icache_fetch(1450 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2568 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2569 */
  sim_icache_fetch(1452 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) exit_stat,0,4), reg_r0_8); /* line 2571 */
   __MOV(reg_r0_3, 0); /* line 2572 */
} /* line 2572 */
l_L143X3: ;/* line 2574 */
__LABEL(l_L143X3);
  sim_icache_fetch(1455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2575 */
} /* line 2575 */
  sim_icache_fetch(1456 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressf);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2578 */
l_L142X3: ;/* line 2581 */
__LABEL(l_L142X3);
  sim_icache_fetch(1457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 2582 */
   __GOTO(l_L143X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L143X3;
} /* line 2583 */
l_L140X3: ;/* line 2586 */
__LABEL(l_L140X3);
  sim_icache_fetch(1459 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2587 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2588 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2589 */
   __ADD_CYCLES(1);
} /* line 2589 */
		 /* line 2590 */
  sim_icache_fetch(1464 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_3, reg_r0_4, reg_r0_2); /* line 2592 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(prratio);
   reg_l0_0 = (308 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) prratio;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2593 */
l_lr_185: ;/* line 2593 */
__LABEL(l_lr_185);
  sim_icache_fetch(1467 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2595 */
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) in_count,0,4)); /* line 2596 */
} /* line 2596 */
  sim_icache_fetch(1471 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_8, (unsigned int) 2); /* line 2598 */
} /* line 2598 */
  sim_icache_fetch(1472 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_6, reg_r0_7); /* line 2600 */
   __GOTO(l_L141X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L141X3;
} /* line 2601 */
l_L67X3: ;/* line 2604 */
__LABEL(l_L67X3);
  sim_icache_fetch(1474 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 2605 */
   __GOTO(l_L68X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L68X3;
} /* line 2606 */
l_L63X3: ;/* line 2609 */
__LABEL(l_L63X3);
  sim_icache_fetch(1476 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2610 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2611 */
} /* line 2611 */
  sim_icache_fetch(1478 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2613 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2614 */
} /* line 2614 */
  sim_icache_fetch(1481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 2616 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2617 */
l_L62X3: ;/* line 2620 */
__LABEL(l_L62X3);
  sim_icache_fetch(1483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2621 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2622 */
} /* line 2622 */
  sim_icache_fetch(1485 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2624 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2625 */
} /* line 2625 */
  sim_icache_fetch(1488 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 13); /* line 2627 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2628 */
l_L61X3: ;/* line 2631 */
__LABEL(l_L61X3);
  sim_icache_fetch(1490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2632 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2633 */
} /* line 2633 */
  sim_icache_fetch(1492 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2635 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2636 */
} /* line 2636 */
  sim_icache_fetch(1495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 12); /* line 2638 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2639 */
l_L60X3: ;/* line 2642 */
__LABEL(l_L60X3);
  sim_icache_fetch(1497 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2643 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2644 */
} /* line 2644 */
  sim_icache_fetch(1499 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2646 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2647 */
} /* line 2647 */
  sim_icache_fetch(1502 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 11); /* line 2649 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2650 */
l_L59X3: ;/* line 2653 */
__LABEL(l_L59X3);
  sim_icache_fetch(1504 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2654 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2655 */
} /* line 2655 */
  sim_icache_fetch(1506 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2657 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2658 */
} /* line 2658 */
  sim_icache_fetch(1509 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 10); /* line 2660 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2661 */
l_L58X3: ;/* line 2664 */
__LABEL(l_L58X3);
  sim_icache_fetch(1511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2665 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2666 */
} /* line 2666 */
  sim_icache_fetch(1513 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2668 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2669 */
} /* line 2669 */
  sim_icache_fetch(1516 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 9); /* line 2671 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2672 */
l_L57X3: ;/* line 2675 */
__LABEL(l_L57X3);
  sim_icache_fetch(1518 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2676 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2677 */
} /* line 2677 */
  sim_icache_fetch(1520 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2679 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2680 */
} /* line 2680 */
  sim_icache_fetch(1523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2682 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2683 */
l_L56X3: ;/* line 2686 */
__LABEL(l_L56X3);
  sim_icache_fetch(1525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2687 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2688 */
} /* line 2688 */
  sim_icache_fetch(1527 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2690 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2691 */
} /* line 2691 */
  sim_icache_fetch(1530 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 2693 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2694 */
l_L55X3: ;/* line 2697 */
__LABEL(l_L55X3);
  sim_icache_fetch(1532 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2698 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2699 */
} /* line 2699 */
  sim_icache_fetch(1534 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2701 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2702 */
} /* line 2702 */
  sim_icache_fetch(1537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 2704 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2705 */
l_L54X3: ;/* line 2708 */
__LABEL(l_L54X3);
  sim_icache_fetch(1539 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2709 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2710 */
} /* line 2710 */
  sim_icache_fetch(1541 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2712 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2713 */
} /* line 2713 */
  sim_icache_fetch(1544 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 5); /* line 2715 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2716 */
l_L53X3: ;/* line 2719 */
__LABEL(l_L53X3);
  sim_icache_fetch(1546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2720 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2721 */
} /* line 2721 */
  sim_icache_fetch(1548 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2723 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2724 */
} /* line 2724 */
  sim_icache_fetch(1551 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 4); /* line 2726 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2727 */
l_L52X3: ;/* line 2730 */
__LABEL(l_L52X3);
  sim_icache_fetch(1553 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2731 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2732 */
} /* line 2732 */
  sim_icache_fetch(1555 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2734 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2735 */
} /* line 2735 */
  sim_icache_fetch(1558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 3); /* line 2737 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2738 */
l_L51X3: ;/* line 2741 */
__LABEL(l_L51X3);
  sim_icache_fetch(1560 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2742 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2743 */
} /* line 2743 */
  sim_icache_fetch(1562 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2745 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2746 */
} /* line 2746 */
  sim_icache_fetch(1565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 2); /* line 2748 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2749 */
l_L50X3: ;/* line 2752 */
__LABEL(l_L50X3);
  sim_icache_fetch(1567 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2753 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2754 */
} /* line 2754 */
  sim_icache_fetch(1569 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2756 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2757 */
} /* line 2757 */
  sim_icache_fetch(1572 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 2759 */
   __GOTO(l_L65X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L65X3;
} /* line 2760 */
l_L49X3: ;/* line 2763 */
__LABEL(l_L49X3);
  sim_icache_fetch(1574 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_6); /* line 2764 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_5); /* line 2765 */
} /* line 2765 */
  sim_icache_fetch(1576 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) hsize,0,4)); /* line 2767 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_57); /* line 2768 */
} /* line 2768 */
  sim_icache_fetch(1579 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 2770 */
l_L65X3: ;/* line 2772 */
__LABEL(l_L65X3);
  sim_icache_fetch(1580 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_7, (unsigned int) 8, reg_r0_4); /* line 2773 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_2); /* line 2774 */
} /* line 2774 */
  sim_icache_fetch(1582 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 2776 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_7); /* line 2777 */
} /* line 2777 */
		 /* line 2778 */
  sim_icache_fetch(1584 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (308 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 2780 */
l_lr_204: ;/* line 2780 */
__LABEL(l_lr_204);
  sim_icache_fetch(1586 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_8, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2782 */
   __LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2783 */
} /* line 2783 */
  sim_icache_fetch(1588 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 2785 */
} /* line 2785 */
  sim_icache_fetch(1589 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L66X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L66X3;
} /* line 2787 */
l_L46X3: ;/* line 2790 */
__LABEL(l_L46X3);
  sim_icache_fetch(1590 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_13, (unsigned int) -1); /* line 2791 */
   __GOTO(l_L47X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L47X3;
} /* line 2792 */
l_L44X3: ;/* line 2795 */
__LABEL(l_L44X3);
  sim_icache_fetch(1592 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_3, mem_trace_ld((unsigned int) magic_header,0,1)); /* line 2796 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2797 */
} /* line 2797 */
  sim_icache_fetch(1596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 3); /* line 2799 */
   __MOV(reg_r0_7, (unsigned int) 1); /* line 2800 */
} /* line 2800 */
  sim_icache_fetch(1598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 2802 */
} /* line 2802 */
  sim_icache_fetch(1599 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 2804 */
} /* line 2804 */
  sim_icache_fetch(1601 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2806 */
} /* line 2806 */
  sim_icache_fetch(1602 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2808 */
   __LDBU(reg_r0_3, mem_trace_ld(((unsigned int) magic_header + (unsigned int) 1),0,1)); /* line 2809 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2810 */
   __ADD_CYCLES(1);
} /* line 2810 */
  sim_icache_fetch(1607 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 2812 */
} /* line 2812 */
  sim_icache_fetch(1608 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 2814 */
} /* line 2814 */
  sim_icache_fetch(1610 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2816 */
} /* line 2816 */
  sim_icache_fetch(1611 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2818 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 2819 */
} /* line 2819 */
  sim_icache_fetch(1615 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 2821 */
} /* line 2821 */
  sim_icache_fetch(1617 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 2823 */
} /* line 2823 */
  sim_icache_fetch(1618 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_8); /* line 2825 */
   __OR(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2826 */
} /* line 2826 */
  sim_icache_fetch(1621 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 2828 */
   __GOTO(l_L45X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L45X3;
} /* line 2829 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 196: goto l_L45X3;
    case 197: goto l_L47X3;
    case 198: goto l_L48X3;
    case 199: goto l_L64X3;
    case 200: goto l_L66X3;
    case 201: goto l_L68X3;
    case 202: goto l_L70X3;
    case 203: goto l_L72X3;
    case 205: goto l_lr_104;
    case 206: goto l_L73X3;
    case 208: goto l_lr_107;
    case 209: goto l_L74X3;
    case 210: goto l_L71X3;
    case 211: goto l_L75X3;
    case 212: goto l_L138X3;
    case 213: goto l_L106X3;
    case 214: goto l_L137X3;
    case 215: goto l_L105X3;
    case 216: goto l_L136X3;
    case 217: goto l_L104X3;
    case 218: goto l_L135X3;
    case 219: goto l_L103X3;
    case 220: goto l_L134X3;
    case 221: goto l_L102X3;
    case 222: goto l_L133X3;
    case 223: goto l_L101X3;
    case 224: goto l_L132X3;
    case 225: goto l_L100X3;
    case 226: goto l_L131X3;
    case 227: goto l_L99X3;
    case 228: goto l_L130X3;
    case 229: goto l_L98X3;
    case 230: goto l_L129X3;
    case 231: goto l_L97X3;
    case 232: goto l_L128X3;
    case 233: goto l_L96X3;
    case 234: goto l_L127X3;
    case 235: goto l_L95X3;
    case 236: goto l_L126X3;
    case 237: goto l_L94X3;
    case 238: goto l_L125X3;
    case 239: goto l_L93X3;
    case 240: goto l_L124X3;
    case 241: goto l_L92X3;
    case 242: goto l_L123X3;
    case 243: goto l_L91X3;
    case 244: goto l_L122X3;
    case 245: goto l_L90X3;
    case 246: goto l_L121X3;
    case 247: goto l_L89X3;
    case 248: goto l_L120X3;
    case 249: goto l_L88X3;
    case 250: goto l_L119X3;
    case 251: goto l_L87X3;
    case 252: goto l_L118X3;
    case 253: goto l_L86X3;
    case 254: goto l_L117X3;
    case 255: goto l_L85X3;
    case 256: goto l_L116X3;
    case 257: goto l_L84X3;
    case 258: goto l_L115X3;
    case 259: goto l_L83X3;
    case 260: goto l_L114X3;
    case 261: goto l_L82X3;
    case 262: goto l_L113X3;
    case 263: goto l_L81X3;
    case 264: goto l_L112X3;
    case 265: goto l_L80X3;
    case 266: goto l_L111X3;
    case 267: goto l_L79X3;
    case 268: goto l_L110X3;
    case 269: goto l_L78X3;
    case 270: goto l_L109X3;
    case 271: goto l_L77X3;
    case 272: goto l_L108X3;
    case 273: goto l_L76X3;
    case 274: goto l_L139X3;
    case 275: goto l_L107X3;
    case 276: goto l_L69X3;
    case 278: goto l_lr_177;
    case 280: goto l_lr_179;
    case 281: goto l_L141X3;
    case 282: goto l_L143X3;
    case 283: goto l_L142X3;
    case 284: goto l_L140X3;
    case 286: goto l_lr_185;
    case 287: goto l_L67X3;
    case 288: goto l_L63X3;
    case 289: goto l_L62X3;
    case 290: goto l_L61X3;
    case 291: goto l_L60X3;
    case 292: goto l_L59X3;
    case 293: goto l_L58X3;
    case 294: goto l_L57X3;
    case 295: goto l_L56X3;
    case 296: goto l_L55X3;
    case 297: goto l_L54X3;
    case 298: goto l_L53X3;
    case 299: goto l_L52X3;
    case 300: goto l_L51X3;
    case 301: goto l_L50X3;
    case 302: goto l_L49X3;
    case 303: goto l_L65X3;
    case 305: goto l_lr_204;
    case 306: goto l_L46X3;
    case 307: goto l_L44X3;
    case 308:
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
  reg_l0_0 = (340 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1623 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 2848 */
} /* line 2848 */
  sim_icache_fetch(1625 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2850 */
   __CMPGE(reg_b0_0, reg_r0_3, 0); /* line 2851 */
} /* line 2851 */
  sim_icache_fetch(1628 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_7, reg_r0_2, (unsigned int) 3); /* line 2853 */
   __AND(reg_r0_6, reg_r0_2, (unsigned int) 7); /* line 2854 */
} /* line 2854 */
  sim_icache_fetch(1630 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBUs(reg_r0_2, mem_trace_ld((reg_r0_6 + (unsigned int) lmask),0,1)); /* line 2856 */
   __SHL(reg_r0_8, reg_r0_3, reg_r0_6); /* line 2857 */
} /* line 2857 */
  sim_icache_fetch(1633 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_10, mem_trace_ld((reg_r0_7 + (unsigned int) compress_8838Xbuf),0,1)); /* line 2859 */
   __LDBUs(reg_r0_9, mem_trace_ld((reg_r0_6 + (unsigned int) rmask),0,1)); /* line 2860 */
} /* line 2860 */
  sim_icache_fetch(1637 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_2, reg_r0_2, reg_r0_8); /* line 2862 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2863 */
  sim_icache_fetch(1639 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2865 */
   __SUB(reg_r0_8, (unsigned int) 8, reg_r0_6); /* line 2866 */
} /* line 2866 */
  sim_icache_fetch(1641 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2868 */
   __SHR(reg_r0_3, reg_r0_3, reg_r0_8); /* line 2869 */
} /* line 2869 */
  sim_icache_fetch(1643 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_9, reg_r0_7, (unsigned int) compress_8838Xbuf); /* line 2871 */
   __MOV(reg_r0_8, reg_r0_3); /* line 2872 */
} /* line 2872 */
  sim_icache_fetch(1646 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_10, reg_r0_7, ((unsigned int) compress_8838Xbuf + (unsigned int) 1)); /* line 2874 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2875 */
} /* line 2875 */
  sim_icache_fetch(1649 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_7 + (unsigned int) compress_8838Xbuf),0,1), reg_r0_2); /* line 2877 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2878 */
} /* line 2878 */
  sim_icache_fetch(1652 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGE(reg_b0_0, reg_r0_4, (unsigned int) 8); /* line 2880 */
} /* line 2880 */
  sim_icache_fetch(1653 + t_thisfile.offset, 1);
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
} /* line 2882 */
  sim_icache_fetch(1654 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 2); /* line 2884 */
   __SHR(reg_r0_8, reg_r0_3, (unsigned int) 8); /* line 2885 */
} /* line 2885 */
  sim_icache_fetch(1656 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_9 + (unsigned int) 1),0,1), reg_r0_3); /* line 2887 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -8); /* line 2888 */
} /* line 2888 */
l_L145X3: ;/* line 2890 */
__LABEL(l_L145X3);
  sim_icache_fetch(1658 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPNE(reg_b0_0, reg_r0_4, 0); /* line 2891 */
   __MOV(reg_r0_3, (unsigned int) compress_8838Xbuf); /* line 2892 */
} /* line 2892 */
  sim_icache_fetch(1661 + t_thisfile.offset, 1);
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
} /* line 2894 */
  sim_icache_fetch(1662 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_10,0,1), reg_r0_8); /* line 2896 */
} /* line 2896 */
l_L146X3: ;/* line 2898 */
__LABEL(l_L146X3);
  sim_icache_fetch(1663 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 2899 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 2900 */
} /* line 2900 */
  sim_icache_fetch(1667 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 2902 */
} /* line 2902 */
  sim_icache_fetch(1669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2904 */
   __SHL(reg_r0_7, reg_r0_4, (unsigned int) 3); /* line 2905 */
} /* line 2905 */
  sim_icache_fetch(1671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_7); /* line 2907 */
   __ADD(reg_r0_6, reg_r0_4, reg_r0_6); /* line 2908 */
} /* line 2908 */
  sim_icache_fetch(1673 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_8838Xoffset,0,4), reg_r0_2); /* line 2910 */
   __MOV(reg_r0_5, reg_r0_4); /* line 2911 */
} /* line 2911 */
  sim_icache_fetch(1676 + t_thisfile.offset, 1);
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
} /* line 2913 */
  sim_icache_fetch(1677 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_6); /* line 2915 */
} /* line 2915 */
l_L148X3: ;/* line 2918 */
__LABEL(l_L148X3);
  sim_icache_fetch(1679 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 2919 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2920 */
} /* line 2920 */
  sim_icache_fetch(1682 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2922 */
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2923 */
} /* line 2923 */
  sim_icache_fetch(1684 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2925 */
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 2926 */
} /* line 2926 */
  sim_icache_fetch(1686 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 2928 */
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 2929 */
} /* line 2929 */
  sim_icache_fetch(1688 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 2931 */
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 2932 */
} /* line 2932 */
  sim_icache_fetch(1690 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 2934 */
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) 16); /* line 2935 */
} /* line 2935 */
  sim_icache_fetch(1692 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2937 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -16); /* line 2938 */
} /* line 2938 */
  sim_icache_fetch(1695 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2940 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2941 */
  sim_icache_fetch(1697 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 1),0,1)); /* line 2943 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2944 */
} /* line 2944 */
  sim_icache_fetch(1700 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 2946 */
} /* line 2946 */
  sim_icache_fetch(1701 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2948 */
} /* line 2948 */
  sim_icache_fetch(1702 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2950 */
} /* line 2950 */
  sim_icache_fetch(1704 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2952 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2953 */
  sim_icache_fetch(1706 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 2),0,1)); /* line 2955 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2956 */
} /* line 2956 */
  sim_icache_fetch(1709 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 2958 */
} /* line 2958 */
  sim_icache_fetch(1710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2960 */
} /* line 2960 */
  sim_icache_fetch(1711 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2962 */
} /* line 2962 */
  sim_icache_fetch(1713 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2964 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2965 */
  sim_icache_fetch(1715 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 3),0,1)); /* line 2967 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2968 */
} /* line 2968 */
  sim_icache_fetch(1718 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 2970 */
} /* line 2970 */
  sim_icache_fetch(1719 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2972 */
} /* line 2972 */
  sim_icache_fetch(1720 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2974 */
} /* line 2974 */
  sim_icache_fetch(1722 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2976 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2977 */
  sim_icache_fetch(1724 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 4),0,1)); /* line 2979 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2980 */
} /* line 2980 */
  sim_icache_fetch(1727 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 2982 */
} /* line 2982 */
  sim_icache_fetch(1728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2984 */
} /* line 2984 */
  sim_icache_fetch(1729 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2986 */
} /* line 2986 */
  sim_icache_fetch(1731 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 2988 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 2989 */
  sim_icache_fetch(1733 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 5),0,1)); /* line 2991 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 2992 */
} /* line 2992 */
  sim_icache_fetch(1736 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 2994 */
} /* line 2994 */
  sim_icache_fetch(1737 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 2996 */
} /* line 2996 */
  sim_icache_fetch(1738 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 2998 */
} /* line 2998 */
  sim_icache_fetch(1740 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3000 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3001 */
  sim_icache_fetch(1742 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 6),0,1)); /* line 3003 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3004 */
} /* line 3004 */
  sim_icache_fetch(1745 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 3006 */
} /* line 3006 */
  sim_icache_fetch(1746 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3008 */
} /* line 3008 */
  sim_icache_fetch(1747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3010 */
} /* line 3010 */
  sim_icache_fetch(1749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3012 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3013 */
  sim_icache_fetch(1751 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 7),0,1)); /* line 3015 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3016 */
} /* line 3016 */
  sim_icache_fetch(1754 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 3018 */
   __ADD(reg_r0_5, reg_r0_8, (unsigned int) -16); /* line 3019 */
} /* line 3019 */
  sim_icache_fetch(1756 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3021 */
} /* line 3021 */
  sim_icache_fetch(1757 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3023 */
} /* line 3023 */
  sim_icache_fetch(1759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3025 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3026 */
  sim_icache_fetch(1761 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 8),0,1)); /* line 3028 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3029 */
} /* line 3029 */
  sim_icache_fetch(1764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_8, 0); /* line 3031 */
} /* line 3031 */
  sim_icache_fetch(1765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3033 */
} /* line 3033 */
  sim_icache_fetch(1766 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3035 */
} /* line 3035 */
  sim_icache_fetch(1768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3037 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3038 */
  sim_icache_fetch(1770 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 9),0,1)); /* line 3040 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3041 */
} /* line 3041 */
  sim_icache_fetch(1773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 3043 */
} /* line 3043 */
  sim_icache_fetch(1774 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3045 */
} /* line 3045 */
  sim_icache_fetch(1775 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3047 */
} /* line 3047 */
  sim_icache_fetch(1777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3049 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3050 */
  sim_icache_fetch(1779 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 10),0,1)); /* line 3052 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3053 */
} /* line 3053 */
  sim_icache_fetch(1782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 2); /* line 3055 */
} /* line 3055 */
  sim_icache_fetch(1783 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3057 */
} /* line 3057 */
  sim_icache_fetch(1784 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3059 */
} /* line 3059 */
  sim_icache_fetch(1786 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3061 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3062 */
  sim_icache_fetch(1788 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 11),0,1)); /* line 3064 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3065 */
} /* line 3065 */
  sim_icache_fetch(1791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 3); /* line 3067 */
} /* line 3067 */
  sim_icache_fetch(1792 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3069 */
} /* line 3069 */
  sim_icache_fetch(1793 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3071 */
} /* line 3071 */
  sim_icache_fetch(1795 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3073 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3074 */
  sim_icache_fetch(1797 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 12),0,1)); /* line 3076 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3077 */
} /* line 3077 */
  sim_icache_fetch(1800 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 4); /* line 3079 */
} /* line 3079 */
  sim_icache_fetch(1801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3081 */
} /* line 3081 */
  sim_icache_fetch(1802 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3083 */
} /* line 3083 */
  sim_icache_fetch(1804 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3085 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3086 */
  sim_icache_fetch(1806 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 13),0,1)); /* line 3088 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3089 */
} /* line 3089 */
  sim_icache_fetch(1809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 5); /* line 3091 */
} /* line 3091 */
  sim_icache_fetch(1810 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3093 */
} /* line 3093 */
  sim_icache_fetch(1811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3095 */
} /* line 3095 */
  sim_icache_fetch(1813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3097 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3098 */
  sim_icache_fetch(1815 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_3 + (unsigned int) 14),0,1)); /* line 3100 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3101 */
} /* line 3101 */
  sim_icache_fetch(1818 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 6); /* line 3103 */
} /* line 3103 */
  sim_icache_fetch(1819 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3105 */
} /* line 3105 */
  sim_icache_fetch(1820 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3107 */
} /* line 3107 */
  sim_icache_fetch(1822 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3109 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3110 */
  sim_icache_fetch(1824 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_3, mem_trace_ld((reg_r0_3 + (unsigned int) 15),0,1)); /* line 3112 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3113 */
} /* line 3113 */
  sim_icache_fetch(1827 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 7); /* line 3115 */
} /* line 3115 */
  sim_icache_fetch(1828 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3117 */
} /* line 3117 */
  sim_icache_fetch(1829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3119 */
} /* line 3119 */
  sim_icache_fetch(1831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 3121 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3122 */
  sim_icache_fetch(1833 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld(reg_r0_7,0,1)); /* line 3124 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3125 */
} /* line 3125 */
  sim_icache_fetch(1836 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_7, reg_r0_8, (unsigned int) 8); /* line 3127 */
   __ADD(reg_r0_3, reg_r0_7, (unsigned int) 16); /* line 3128 */
} /* line 3128 */
  sim_icache_fetch(1838 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3130 */
} /* line 3130 */
  sim_icache_fetch(1839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3132 */
} /* line 3132 */
  sim_icache_fetch(1841 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3134 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3135 */
  sim_icache_fetch(1843 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 1),0,1)); /* line 3137 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3138 */
} /* line 3138 */
  sim_icache_fetch(1846 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_8, (unsigned int) 9); /* line 3140 */
} /* line 3140 */
  sim_icache_fetch(1847 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3142 */
} /* line 3142 */
  sim_icache_fetch(1848 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3144 */
} /* line 3144 */
  sim_icache_fetch(1850 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3146 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3147 */
  sim_icache_fetch(1852 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,1)); /* line 3149 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3150 */
} /* line 3150 */
  sim_icache_fetch(1855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_8, (unsigned int) 10); /* line 3152 */
} /* line 3152 */
  sim_icache_fetch(1856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3154 */
} /* line 3154 */
  sim_icache_fetch(1857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3156 */
} /* line 3156 */
  sim_icache_fetch(1859 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3158 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3159 */
  sim_icache_fetch(1861 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 3),0,1)); /* line 3161 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3162 */
} /* line 3162 */
  sim_icache_fetch(1864 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_2, reg_r0_8, (unsigned int) 11); /* line 3164 */
} /* line 3164 */
  sim_icache_fetch(1865 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3166 */
} /* line 3166 */
  sim_icache_fetch(1866 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3168 */
} /* line 3168 */
  sim_icache_fetch(1868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3170 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3171 */
  sim_icache_fetch(1870 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,1)); /* line 3173 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3174 */
} /* line 3174 */
  sim_icache_fetch(1873 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_3, reg_r0_8, (unsigned int) 12); /* line 3176 */
} /* line 3176 */
  sim_icache_fetch(1874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3178 */
} /* line 3178 */
  sim_icache_fetch(1875 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3180 */
} /* line 3180 */
  sim_icache_fetch(1877 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3182 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3183 */
  sim_icache_fetch(1879 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 5),0,1)); /* line 3185 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3186 */
} /* line 3186 */
  sim_icache_fetch(1882 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_4, reg_r0_8, (unsigned int) 13); /* line 3188 */
} /* line 3188 */
  sim_icache_fetch(1883 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3190 */
} /* line 3190 */
  sim_icache_fetch(1884 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3192 */
} /* line 3192 */
  sim_icache_fetch(1886 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3194 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3195 */
  sim_icache_fetch(1888 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 6),0,1)); /* line 3197 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3198 */
} /* line 3198 */
  sim_icache_fetch(1891 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_5, reg_r0_8, (unsigned int) 14); /* line 3200 */
} /* line 3200 */
  sim_icache_fetch(1892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3202 */
} /* line 3202 */
  sim_icache_fetch(1893 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3204 */
} /* line 3204 */
  sim_icache_fetch(1895 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3206 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3207 */
  sim_icache_fetch(1897 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 7),0,1)); /* line 3209 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3210 */
} /* line 3210 */
  sim_icache_fetch(1900 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_6, reg_r0_8, (unsigned int) 15); /* line 3212 */
} /* line 3212 */
  sim_icache_fetch(1901 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3214 */
} /* line 3214 */
  sim_icache_fetch(1902 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3216 */
} /* line 3216 */
  sim_icache_fetch(1904 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3218 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3219 */
  sim_icache_fetch(1906 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 8),0,1)); /* line 3221 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3222 */
} /* line 3222 */
  sim_icache_fetch(1909 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_5, 0); /* line 3224 */
} /* line 3224 */
  sim_icache_fetch(1910 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3226 */
} /* line 3226 */
  sim_icache_fetch(1911 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3228 */
} /* line 3228 */
  sim_icache_fetch(1913 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3230 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3231 */
  sim_icache_fetch(1915 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 9),0,1)); /* line 3233 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3234 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3235 */
   __ADD_CYCLES(1);
} /* line 3235 */
  sim_icache_fetch(1919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3237 */
} /* line 3237 */
  sim_icache_fetch(1920 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3239 */
} /* line 3239 */
  sim_icache_fetch(1922 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3241 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3242 */
  sim_icache_fetch(1924 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 10),0,1)); /* line 3244 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3245 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3246 */
   __ADD_CYCLES(1);
} /* line 3246 */
  sim_icache_fetch(1928 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3248 */
} /* line 3248 */
  sim_icache_fetch(1929 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3250 */
} /* line 3250 */
  sim_icache_fetch(1931 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3252 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3253 */
  sim_icache_fetch(1933 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 11),0,1)); /* line 3255 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3256 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3257 */
   __ADD_CYCLES(1);
} /* line 3257 */
  sim_icache_fetch(1937 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3259 */
} /* line 3259 */
  sim_icache_fetch(1938 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3261 */
} /* line 3261 */
  sim_icache_fetch(1940 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3263 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3264 */
  sim_icache_fetch(1942 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,1)); /* line 3266 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3267 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3268 */
   __ADD_CYCLES(1);
} /* line 3268 */
  sim_icache_fetch(1946 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3270 */
} /* line 3270 */
  sim_icache_fetch(1947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3272 */
} /* line 3272 */
  sim_icache_fetch(1949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3274 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3275 */
  sim_icache_fetch(1951 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 13),0,1)); /* line 3277 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3278 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3279 */
   __ADD_CYCLES(1);
} /* line 3279 */
  sim_icache_fetch(1955 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3281 */
} /* line 3281 */
  sim_icache_fetch(1956 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3283 */
} /* line 3283 */
  sim_icache_fetch(1958 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3285 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3286 */
  sim_icache_fetch(1960 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_4, mem_trace_ld((reg_r0_7 + (unsigned int) 14),0,1)); /* line 3288 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3289 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3290 */
   __ADD_CYCLES(1);
} /* line 3290 */
  sim_icache_fetch(1964 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_2, (unsigned int) 1); /* line 3292 */
} /* line 3292 */
  sim_icache_fetch(1965 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_6); /* line 3294 */
} /* line 3294 */
  sim_icache_fetch(1967 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 3296 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3297 */
  sim_icache_fetch(1969 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_7, mem_trace_ld((reg_r0_7 + (unsigned int) 15),0,1)); /* line 3299 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3300 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3301 */
   __ADD_CYCLES(1);
} /* line 3301 */
  sim_icache_fetch(1973 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 3303 */
} /* line 3303 */
  sim_icache_fetch(1974 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3305 */
} /* line 3305 */
  sim_icache_fetch(1976 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 3307 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3309 */
  sim_icache_fetch(1978 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L148X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L148X3;
} /* line 3311 */
l_L149X3: ;/* line 3314 */
__LABEL(l_L149X3);
  sim_icache_fetch(1979 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) compress_8838Xoffset,0,4), 0); /* line 3315 */
} /* line 3315 */
l_L147X3: ;/* line 3318 */
__LABEL(l_L147X3);
  sim_icache_fetch(1981 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 3319 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 3320 */
} /* line 3320 */
  sim_icache_fetch(1985 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_21, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3322 */
   __LDWs(reg_r0_22, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 3323 */
} /* line 3323 */
  sim_icache_fetch(1989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3325 */
   __MOV(reg_r0_20, (unsigned int) 15); /* line 3326 */
} /* line 3326 */
  sim_icache_fetch(1991 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_r0_21, reg_r0_21, 0); /* line 3328 */
   __CMPGT(reg_b0_0, reg_r0_22, 0); /* line 3329 */
} /* line 3329 */
  sim_icache_fetch(1993 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_b0_1, reg_r0_2, reg_r0_21); /* line 3331 */
   __MOV(reg_r0_19, (unsigned int) 14); /* line 3332 */
} /* line 3332 */
  sim_icache_fetch(1995 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_18, (unsigned int) 13); /* line 3334 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L150X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3335 */
  sim_icache_fetch(1997 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_17, (unsigned int) 12); /* line 3337 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3338 */
  sim_icache_fetch(1999 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_15, (unsigned int) 10); /* line 3340 */
   __MOV(reg_r0_16, (unsigned int) 11); /* line 3341 */
} /* line 3341 */
  sim_icache_fetch(2001 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_13, (unsigned int) 8); /* line 3343 */
   __MOV(reg_r0_14, (unsigned int) 9); /* line 3344 */
} /* line 3344 */
  sim_icache_fetch(2003 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_11, (unsigned int) 6); /* line 3346 */
   __MOV(reg_r0_12, (unsigned int) 7); /* line 3347 */
} /* line 3347 */
  sim_icache_fetch(2005 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) 4); /* line 3349 */
   __MOV(reg_r0_10, (unsigned int) 5); /* line 3350 */
} /* line 3350 */
  sim_icache_fetch(2007 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_7, (unsigned int) 2); /* line 3352 */
   __MOV(reg_r0_8, (unsigned int) 3); /* line 3353 */
} /* line 3353 */
  sim_icache_fetch(2009 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 1); /* line 3355 */
   __MOV(reg_r0_5, (unsigned int) compress_8838Xbuf); /* line 3356 */
} /* line 3356 */
  sim_icache_fetch(2012 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 3358 */
} /* line 3358 */
l_L152X3: ;/* line 3361 */
__LABEL(l_L152X3);
  sim_icache_fetch(2013 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3362 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3363 */
} /* line 3363 */
  sim_icache_fetch(2017 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_5,0,1)); /* line 3365 */
   __ADD(reg_r0_22, reg_r0_6, (unsigned int) 16); /* line 3366 */
} /* line 3366 */
  sim_icache_fetch(2019 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_2); /* line 3368 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3369 */
} /* line 3369 */
  sim_icache_fetch(2021 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_23, reg_r0_19, (unsigned int) 16); /* line 3371 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3372 */
  sim_icache_fetch(2023 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_24, reg_r0_18, (unsigned int) 16); /* line 3374 */
   __ADD(reg_r0_25, reg_r0_17, (unsigned int) 16); /* line 3375 */
} /* line 3375 */
  sim_icache_fetch(2025 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_26, reg_r0_16, (unsigned int) 16); /* line 3377 */
   __ADD(reg_r0_27, reg_r0_15, (unsigned int) 16); /* line 3378 */
} /* line 3378 */
  sim_icache_fetch(2027 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_28, reg_r0_14, (unsigned int) 16); /* line 3380 */
   __ADD(reg_r0_29, reg_r0_13, (unsigned int) 16); /* line 3381 */
} /* line 3381 */
  sim_icache_fetch(2029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) 16); /* line 3383 */
   __ADD(reg_r0_31, reg_r0_11, (unsigned int) 16); /* line 3384 */
} /* line 3384 */
  sim_icache_fetch(2031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_32, reg_r0_10, (unsigned int) 16); /* line 3386 */
   __ADD(reg_r0_33, reg_r0_9, (unsigned int) 16); /* line 3387 */
} /* line 3387 */
  sim_icache_fetch(2033 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_34, reg_r0_8, (unsigned int) 16); /* line 3389 */
   __ADD(reg_r0_35, reg_r0_7, (unsigned int) 16); /* line 3390 */
} /* line 3390 */
  sim_icache_fetch(2035 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_36, reg_r0_20, (unsigned int) 16); /* line 3392 */
   __ADD(reg_r0_37, reg_r0_5, (unsigned int) 16); /* line 3393 */
} /* line 3393 */
  sim_icache_fetch(2037 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3395 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3396 */
} /* line 3396 */
  sim_icache_fetch(2040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3398 */
   __ADD(reg_r0_2, reg_r0_3, (unsigned int) 16); /* line 3399 */
} /* line 3399 */
  sim_icache_fetch(2042 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3401 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3402 */
} /* line 3402 */
  sim_icache_fetch(2046 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 3404 */
} /* line 3404 */
  sim_icache_fetch(2047 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_6, reg_r0_4); /* line 3406 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3407 */
} /* line 3407 */
  sim_icache_fetch(2049 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_22, (unsigned int) 16); /* line 3409 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3410 */
  sim_icache_fetch(2051 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3412 */
} /* line 3412 */
  sim_icache_fetch(2053 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3414 */
} /* line 3414 */
  sim_icache_fetch(2054 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3416 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3417 */
} /* line 3417 */
  sim_icache_fetch(2058 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 3419 */
} /* line 3419 */
  sim_icache_fetch(2059 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_4); /* line 3421 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3422 */
} /* line 3422 */
  sim_icache_fetch(2061 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_35, (unsigned int) 16); /* line 3424 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3425 */
  sim_icache_fetch(2063 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3427 */
} /* line 3427 */
  sim_icache_fetch(2065 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3429 */
} /* line 3429 */
  sim_icache_fetch(2066 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3431 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3432 */
} /* line 3432 */
  sim_icache_fetch(2070 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 3434 */
} /* line 3434 */
  sim_icache_fetch(2071 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_4); /* line 3436 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3437 */
} /* line 3437 */
  sim_icache_fetch(2073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_8, reg_r0_34, (unsigned int) 16); /* line 3439 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3440 */
  sim_icache_fetch(2075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3442 */
} /* line 3442 */
  sim_icache_fetch(2077 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3444 */
} /* line 3444 */
  sim_icache_fetch(2078 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3446 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3447 */
} /* line 3447 */
  sim_icache_fetch(2082 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 3449 */
} /* line 3449 */
  sim_icache_fetch(2083 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_4); /* line 3451 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3452 */
} /* line 3452 */
  sim_icache_fetch(2085 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_9, reg_r0_33, (unsigned int) 16); /* line 3454 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3455 */
  sim_icache_fetch(2087 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3457 */
} /* line 3457 */
  sim_icache_fetch(2089 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3459 */
} /* line 3459 */
  sim_icache_fetch(2090 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3461 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3462 */
} /* line 3462 */
  sim_icache_fetch(2094 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 3464 */
} /* line 3464 */
  sim_icache_fetch(2095 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_4); /* line 3466 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3467 */
} /* line 3467 */
  sim_icache_fetch(2097 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_10, reg_r0_32, (unsigned int) 16); /* line 3469 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3470 */
  sim_icache_fetch(2099 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3472 */
} /* line 3472 */
  sim_icache_fetch(2101 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3474 */
} /* line 3474 */
  sim_icache_fetch(2102 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3476 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3477 */
} /* line 3477 */
  sim_icache_fetch(2106 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 3479 */
} /* line 3479 */
  sim_icache_fetch(2107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_4); /* line 3481 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3482 */
} /* line 3482 */
  sim_icache_fetch(2109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_11, reg_r0_31, (unsigned int) 16); /* line 3484 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3485 */
  sim_icache_fetch(2111 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3487 */
} /* line 3487 */
  sim_icache_fetch(2113 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3489 */
} /* line 3489 */
  sim_icache_fetch(2114 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3491 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3492 */
} /* line 3492 */
  sim_icache_fetch(2118 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 3494 */
} /* line 3494 */
  sim_icache_fetch(2119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_4); /* line 3496 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3497 */
} /* line 3497 */
  sim_icache_fetch(2121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) 16); /* line 3499 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3500 */
  sim_icache_fetch(2123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3502 */
} /* line 3502 */
  sim_icache_fetch(2125 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3504 */
} /* line 3504 */
  sim_icache_fetch(2126 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3506 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3507 */
} /* line 3507 */
  sim_icache_fetch(2130 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 3509 */
} /* line 3509 */
  sim_icache_fetch(2131 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_4); /* line 3511 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3512 */
} /* line 3512 */
  sim_icache_fetch(2133 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_13, reg_r0_29, (unsigned int) 16); /* line 3514 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3515 */
  sim_icache_fetch(2135 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3517 */
} /* line 3517 */
  sim_icache_fetch(2137 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3519 */
} /* line 3519 */
  sim_icache_fetch(2138 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3521 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3522 */
} /* line 3522 */
  sim_icache_fetch(2142 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 3524 */
} /* line 3524 */
  sim_icache_fetch(2143 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_4); /* line 3526 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3527 */
} /* line 3527 */
  sim_icache_fetch(2145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_14, reg_r0_28, (unsigned int) 16); /* line 3529 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3530 */
  sim_icache_fetch(2147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3532 */
} /* line 3532 */
  sim_icache_fetch(2149 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3534 */
} /* line 3534 */
  sim_icache_fetch(2150 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3536 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3537 */
} /* line 3537 */
  sim_icache_fetch(2154 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 3539 */
} /* line 3539 */
  sim_icache_fetch(2155 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_4); /* line 3541 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3542 */
} /* line 3542 */
  sim_icache_fetch(2157 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_15, reg_r0_27, (unsigned int) 16); /* line 3544 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3545 */
  sim_icache_fetch(2159 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3547 */
} /* line 3547 */
  sim_icache_fetch(2161 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3549 */
} /* line 3549 */
  sim_icache_fetch(2162 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3551 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3552 */
} /* line 3552 */
  sim_icache_fetch(2166 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 3554 */
} /* line 3554 */
  sim_icache_fetch(2167 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_4); /* line 3556 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3557 */
} /* line 3557 */
  sim_icache_fetch(2169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_16, reg_r0_26, (unsigned int) 16); /* line 3559 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3560 */
  sim_icache_fetch(2171 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3562 */
} /* line 3562 */
  sim_icache_fetch(2173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3564 */
} /* line 3564 */
  sim_icache_fetch(2174 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3566 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3567 */
} /* line 3567 */
  sim_icache_fetch(2178 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 3569 */
} /* line 3569 */
  sim_icache_fetch(2179 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_4); /* line 3571 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3572 */
} /* line 3572 */
  sim_icache_fetch(2181 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_17, reg_r0_25, (unsigned int) 16); /* line 3574 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3575 */
  sim_icache_fetch(2183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3577 */
} /* line 3577 */
  sim_icache_fetch(2185 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3579 */
} /* line 3579 */
  sim_icache_fetch(2186 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3581 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3582 */
} /* line 3582 */
  sim_icache_fetch(2190 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 3584 */
} /* line 3584 */
  sim_icache_fetch(2191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_4); /* line 3586 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3587 */
} /* line 3587 */
  sim_icache_fetch(2193 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_18, reg_r0_24, (unsigned int) 16); /* line 3589 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3590 */
  sim_icache_fetch(2195 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3592 */
} /* line 3592 */
  sim_icache_fetch(2197 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3594 */
} /* line 3594 */
  sim_icache_fetch(2198 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3596 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3597 */
} /* line 3597 */
  sim_icache_fetch(2202 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_38, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 3599 */
} /* line 3599 */
  sim_icache_fetch(2203 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_4); /* line 3601 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3602 */
} /* line 3602 */
  sim_icache_fetch(2205 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_23, (unsigned int) 16); /* line 3604 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3605 */
  sim_icache_fetch(2207 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3607 */
} /* line 3607 */
  sim_icache_fetch(2209 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3609 */
} /* line 3609 */
  sim_icache_fetch(2210 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3611 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3612 */
} /* line 3612 */
  sim_icache_fetch(2214 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 3614 */
} /* line 3614 */
  sim_icache_fetch(2215 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_4); /* line 3616 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3617 */
} /* line 3617 */
  sim_icache_fetch(2217 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_20, reg_r0_36, (unsigned int) 16); /* line 3619 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3620 */
  sim_icache_fetch(2219 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3622 */
} /* line 3622 */
  sim_icache_fetch(2221 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_5); /* line 3624 */
} /* line 3624 */
  sim_icache_fetch(2222 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3626 */
   __LDWs(reg_r0_21, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3627 */
} /* line 3627 */
  sim_icache_fetch(2226 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_38, mem_trace_ld(reg_r0_37,0,1)); /* line 3629 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 16); /* line 3630 */
} /* line 3630 */
  sim_icache_fetch(2228 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 3632 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 3633 */
} /* line 3633 */
  sim_icache_fetch(2230 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 3635 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3636 */
  sim_icache_fetch(2232 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 3638 */
} /* line 3638 */
  sim_icache_fetch(2234 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_21,0,1), reg_r0_38); /* line 3640 */
} /* line 3640 */
  sim_icache_fetch(2235 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3642 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3643 */
} /* line 3643 */
  sim_icache_fetch(2239 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 1),0,1)); /* line 3645 */
} /* line 3645 */
  sim_icache_fetch(2240 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_22, reg_r0_2); /* line 3647 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3648 */
} /* line 3648 */
  sim_icache_fetch(2242 + t_thisfile.offset, 1);
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
} /* line 3650 */
  sim_icache_fetch(2243 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3652 */
} /* line 3652 */
  sim_icache_fetch(2245 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3654 */
} /* line 3654 */
  sim_icache_fetch(2246 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3656 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3657 */
} /* line 3657 */
  sim_icache_fetch(2250 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 2),0,1)); /* line 3659 */
} /* line 3659 */
  sim_icache_fetch(2251 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_35, reg_r0_2); /* line 3661 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3662 */
} /* line 3662 */
  sim_icache_fetch(2253 + t_thisfile.offset, 1);
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
} /* line 3664 */
  sim_icache_fetch(2254 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3666 */
} /* line 3666 */
  sim_icache_fetch(2256 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3668 */
} /* line 3668 */
  sim_icache_fetch(2257 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3670 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3671 */
} /* line 3671 */
  sim_icache_fetch(2261 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 3),0,1)); /* line 3673 */
} /* line 3673 */
  sim_icache_fetch(2262 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_34, reg_r0_2); /* line 3675 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3676 */
} /* line 3676 */
  sim_icache_fetch(2264 + t_thisfile.offset, 1);
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
} /* line 3678 */
  sim_icache_fetch(2265 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3680 */
} /* line 3680 */
  sim_icache_fetch(2267 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3682 */
} /* line 3682 */
  sim_icache_fetch(2268 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3684 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3685 */
} /* line 3685 */
  sim_icache_fetch(2272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 4),0,1)); /* line 3687 */
} /* line 3687 */
  sim_icache_fetch(2273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_33, reg_r0_2); /* line 3689 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3690 */
} /* line 3690 */
  sim_icache_fetch(2275 + t_thisfile.offset, 1);
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
} /* line 3692 */
  sim_icache_fetch(2276 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3694 */
} /* line 3694 */
  sim_icache_fetch(2278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3696 */
} /* line 3696 */
  sim_icache_fetch(2279 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3698 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3699 */
} /* line 3699 */
  sim_icache_fetch(2283 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 5),0,1)); /* line 3701 */
} /* line 3701 */
  sim_icache_fetch(2284 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_32, reg_r0_2); /* line 3703 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3704 */
} /* line 3704 */
  sim_icache_fetch(2286 + t_thisfile.offset, 1);
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
} /* line 3706 */
  sim_icache_fetch(2287 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3708 */
} /* line 3708 */
  sim_icache_fetch(2289 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3710 */
} /* line 3710 */
  sim_icache_fetch(2290 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3712 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3713 */
} /* line 3713 */
  sim_icache_fetch(2294 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 6),0,1)); /* line 3715 */
} /* line 3715 */
  sim_icache_fetch(2295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_31, reg_r0_2); /* line 3717 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3718 */
} /* line 3718 */
  sim_icache_fetch(2297 + t_thisfile.offset, 1);
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
} /* line 3720 */
  sim_icache_fetch(2298 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3722 */
} /* line 3722 */
  sim_icache_fetch(2300 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3724 */
} /* line 3724 */
  sim_icache_fetch(2301 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3726 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3727 */
} /* line 3727 */
  sim_icache_fetch(2305 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 7),0,1)); /* line 3729 */
} /* line 3729 */
  sim_icache_fetch(2306 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_30, reg_r0_2); /* line 3731 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3732 */
} /* line 3732 */
  sim_icache_fetch(2308 + t_thisfile.offset, 1);
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
} /* line 3734 */
  sim_icache_fetch(2309 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3736 */
} /* line 3736 */
  sim_icache_fetch(2311 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3738 */
} /* line 3738 */
  sim_icache_fetch(2312 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3740 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3741 */
} /* line 3741 */
  sim_icache_fetch(2316 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 8),0,1)); /* line 3743 */
} /* line 3743 */
  sim_icache_fetch(2317 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_29, reg_r0_2); /* line 3745 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3746 */
} /* line 3746 */
  sim_icache_fetch(2319 + t_thisfile.offset, 1);
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
} /* line 3748 */
  sim_icache_fetch(2320 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3750 */
} /* line 3750 */
  sim_icache_fetch(2322 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3752 */
} /* line 3752 */
  sim_icache_fetch(2323 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3754 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3755 */
} /* line 3755 */
  sim_icache_fetch(2327 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 9),0,1)); /* line 3757 */
} /* line 3757 */
  sim_icache_fetch(2328 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_28, reg_r0_2); /* line 3759 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3760 */
} /* line 3760 */
  sim_icache_fetch(2330 + t_thisfile.offset, 1);
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
} /* line 3762 */
  sim_icache_fetch(2331 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3764 */
} /* line 3764 */
  sim_icache_fetch(2333 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3766 */
} /* line 3766 */
  sim_icache_fetch(2334 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3768 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3769 */
} /* line 3769 */
  sim_icache_fetch(2338 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 10),0,1)); /* line 3771 */
} /* line 3771 */
  sim_icache_fetch(2339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_27, reg_r0_2); /* line 3773 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3774 */
} /* line 3774 */
  sim_icache_fetch(2341 + t_thisfile.offset, 1);
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
} /* line 3776 */
  sim_icache_fetch(2342 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3778 */
} /* line 3778 */
  sim_icache_fetch(2344 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3780 */
} /* line 3780 */
  sim_icache_fetch(2345 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3782 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3783 */
} /* line 3783 */
  sim_icache_fetch(2349 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 11),0,1)); /* line 3785 */
} /* line 3785 */
  sim_icache_fetch(2350 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_26, reg_r0_2); /* line 3787 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3788 */
} /* line 3788 */
  sim_icache_fetch(2352 + t_thisfile.offset, 1);
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
} /* line 3790 */
  sim_icache_fetch(2353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3792 */
} /* line 3792 */
  sim_icache_fetch(2355 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3794 */
} /* line 3794 */
  sim_icache_fetch(2356 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3796 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3797 */
} /* line 3797 */
  sim_icache_fetch(2360 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 12),0,1)); /* line 3799 */
} /* line 3799 */
  sim_icache_fetch(2361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_25, reg_r0_2); /* line 3801 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3802 */
} /* line 3802 */
  sim_icache_fetch(2363 + t_thisfile.offset, 1);
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
} /* line 3804 */
  sim_icache_fetch(2364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3806 */
} /* line 3806 */
  sim_icache_fetch(2366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(2367 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3810 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3811 */
} /* line 3811 */
  sim_icache_fetch(2371 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 13),0,1)); /* line 3813 */
} /* line 3813 */
  sim_icache_fetch(2372 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_24, reg_r0_2); /* line 3815 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3816 */
} /* line 3816 */
  sim_icache_fetch(2374 + t_thisfile.offset, 1);
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
} /* line 3818 */
  sim_icache_fetch(2375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3820 */
} /* line 3820 */
  sim_icache_fetch(2377 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3822 */
} /* line 3822 */
  sim_icache_fetch(2378 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3824 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3825 */
} /* line 3825 */
  sim_icache_fetch(2382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_37 + (unsigned int) 14),0,1)); /* line 3827 */
} /* line 3827 */
  sim_icache_fetch(2383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_23, reg_r0_2); /* line 3829 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3830 */
} /* line 3830 */
  sim_icache_fetch(2385 + t_thisfile.offset, 1);
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
} /* line 3832 */
  sim_icache_fetch(2386 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3834 */
} /* line 3834 */
  sim_icache_fetch(2388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3836 */
} /* line 3836 */
  sim_icache_fetch(2389 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3838 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3839 */
} /* line 3839 */
  sim_icache_fetch(2393 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_37, mem_trace_ld((reg_r0_37 + (unsigned int) 15),0,1)); /* line 3841 */
} /* line 3841 */
  sim_icache_fetch(2394 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_36, reg_r0_2); /* line 3843 */
   __ADD(reg_r0_2, reg_r0_4, (unsigned int) 1); /* line 3844 */
} /* line 3844 */
  sim_icache_fetch(2396 + t_thisfile.offset, 1);
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
} /* line 3846 */
  sim_icache_fetch(2397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_2); /* line 3848 */
} /* line 3848 */
  sim_icache_fetch(2399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_37); /* line 3850 */
   __GOTO(l_L152X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L152X3;
} /* line 3851 */
l_L153X3: ;/* line 3854 */
__LABEL(l_L153X3);
  sim_icache_fetch(2401 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3855 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3856 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3857 */
   __ADD_CYCLES(1);
} /* line 3857 */
  sim_icache_fetch(2406 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_3); /* line 3859 */
} /* line 3859 */
  sim_icache_fetch(2407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_2); /* line 3861 */
} /* line 3861 */
l_L151X3: ;/* line 3864 */
__LABEL(l_L151X3);
  sim_icache_fetch(2409 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 3865 */
   __MOV(reg_r0_3, (unsigned int) 9); /* line 3866 */
} /* line 3866 */
  sim_icache_fetch(2412 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) compress_8838Xoffset,0,4), 0); /* line 3868 */
   __MOV(reg_r0_4, (unsigned int) 511); /* line 3869 */
} /* line 3869 */
  sim_icache_fetch(2416 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 3871 */
} /* line 3871 */
  sim_icache_fetch(2417 + t_thisfile.offset, 1);
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
} /* line 3873 */
  sim_icache_fetch(2418 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_3); /* line 3875 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3876 */
} /* line 3876 */
  sim_icache_fetch(2422 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 3879 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3880 */
l_L154X3: ;/* line 3883 */
__LABEL(l_L154X3);
  sim_icache_fetch(2425 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3884 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 3885 */
} /* line 3885 */
  sim_icache_fetch(2429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 3887 */
} /* line 3887 */
  sim_icache_fetch(2431 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 3889 */
} /* line 3889 */
  sim_icache_fetch(2432 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 3891 */
   __CMPEQ(reg_b0_0, reg_r0_2, reg_r0_3); /* line 3892 */
} /* line 3892 */
  sim_icache_fetch(2435 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L155X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3894 */
  sim_icache_fetch(2436 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_4); /* line 3897 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3898 */
l_L155X3: ;/* line 3901 */
__LABEL(l_L155X3);
  sim_icache_fetch(2439 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 3902 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 3903 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 3904 */
   __ADD_CYCLES(1);
} /* line 3904 */
  sim_icache_fetch(2443 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 3906 */
} /* line 3906 */
  sim_icache_fetch(2444 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 3908 */
} /* line 3908 */
  sim_icache_fetch(2445 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 3911 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3912 */
l_L150X3: ;/* line 3915 */
__LABEL(l_L150X3);
  sim_icache_fetch(2448 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3917 */
l_L144X3: ;/* line 3920 */
__LABEL(l_L144X3);
  sim_icache_fetch(2449 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 3921 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 3922 */
} /* line 3922 */
  sim_icache_fetch(2453 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 3924 */
} /* line 3924 */
  sim_icache_fetch(2455 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3926 */
} /* line 3926 */
  sim_icache_fetch(2456 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3928 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) 7); /* line 3929 */
} /* line 3929 */
  sim_icache_fetch(2458 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_4, 0); /* line 3931 */
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_2); /* line 3932 */
} /* line 3932 */
  sim_icache_fetch(2460 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 3934 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L156X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 3935 */
l_L157X3: ;/* line 3937 */
__LABEL(l_L157X3);
  sim_icache_fetch(2462 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, reg_r0_5); /* line 3938 */
   __STW(mem_trace_st((unsigned int) compress_8838Xoffset,0,4), 0); /* line 3939 */
} /* line 3939 */
  sim_icache_fetch(2465 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bytes_out,0,4), reg_r0_3); /* line 3942 */
   __RETURN(output);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3943 */
l_L156X3: ;/* line 3946 */
__LABEL(l_L156X3);
  sim_icache_fetch(2468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_19, (unsigned int) 14); /* line 3947 */
   __MOV(reg_r0_20, (unsigned int) 15); /* line 3948 */
} /* line 3948 */
  sim_icache_fetch(2470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_17, (unsigned int) 12); /* line 3950 */
   __MOV(reg_r0_18, (unsigned int) 13); /* line 3951 */
} /* line 3951 */
  sim_icache_fetch(2472 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_15, (unsigned int) 10); /* line 3953 */
   __MOV(reg_r0_16, (unsigned int) 11); /* line 3954 */
} /* line 3954 */
  sim_icache_fetch(2474 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_13, (unsigned int) 8); /* line 3956 */
   __MOV(reg_r0_14, (unsigned int) 9); /* line 3957 */
} /* line 3957 */
  sim_icache_fetch(2476 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_11, (unsigned int) 6); /* line 3959 */
   __MOV(reg_r0_12, (unsigned int) 7); /* line 3960 */
} /* line 3960 */
  sim_icache_fetch(2478 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_9, (unsigned int) 4); /* line 3962 */
   __MOV(reg_r0_10, (unsigned int) 5); /* line 3963 */
} /* line 3963 */
  sim_icache_fetch(2480 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_7, (unsigned int) 2); /* line 3965 */
   __MOV(reg_r0_8, (unsigned int) 3); /* line 3966 */
} /* line 3966 */
  sim_icache_fetch(2482 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 1); /* line 3968 */
   __MOV(reg_r0_5, (unsigned int) compress_8838Xbuf); /* line 3969 */
} /* line 3969 */
  sim_icache_fetch(2485 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 3971 */
} /* line 3971 */
l_L158X3: ;/* line 3974 */
__LABEL(l_L158X3);
  sim_icache_fetch(2486 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 3975 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 3976 */
} /* line 3976 */
  sim_icache_fetch(2490 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld(reg_r0_5,0,1)); /* line 3978 */
} /* line 3978 */
  sim_icache_fetch(2491 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3980 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 3981 */
} /* line 3981 */
  sim_icache_fetch(2493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 3983 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 3984 */
} /* line 3984 */
  sim_icache_fetch(2495 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 3986 */
} /* line 3986 */
  sim_icache_fetch(2496 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 3988 */
} /* line 3988 */
  sim_icache_fetch(2497 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_23); /* line 3990 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3991 */
} /* line 3991 */
  sim_icache_fetch(2499 + t_thisfile.offset, 1);
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
} /* line 3993 */
  sim_icache_fetch(2500 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 3995 */
} /* line 3995 */
  sim_icache_fetch(2502 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 3997 */
} /* line 3997 */
  sim_icache_fetch(2503 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 3999 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4000 */
} /* line 4000 */
  sim_icache_fetch(2507 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 1),0,1)); /* line 4002 */
} /* line 4002 */
  sim_icache_fetch(2508 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4004 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4005 */
} /* line 4005 */
  sim_icache_fetch(2510 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4007 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4008 */
} /* line 4008 */
  sim_icache_fetch(2512 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4010 */
} /* line 4010 */
  sim_icache_fetch(2513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4012 */
} /* line 4012 */
  sim_icache_fetch(2514 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_6, reg_r0_23); /* line 4014 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 4015 */
} /* line 4015 */
  sim_icache_fetch(2516 + t_thisfile.offset, 1);
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
} /* line 4017 */
  sim_icache_fetch(2517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4019 */
} /* line 4019 */
  sim_icache_fetch(2519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4021 */
} /* line 4021 */
  sim_icache_fetch(2520 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4023 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4024 */
} /* line 4024 */
  sim_icache_fetch(2524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 2),0,1)); /* line 4026 */
} /* line 4026 */
  sim_icache_fetch(2525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4028 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4029 */
} /* line 4029 */
  sim_icache_fetch(2527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4031 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4032 */
} /* line 4032 */
  sim_icache_fetch(2529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4034 */
} /* line 4034 */
  sim_icache_fetch(2530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4036 */
} /* line 4036 */
  sim_icache_fetch(2531 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_7, reg_r0_23); /* line 4038 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) 16); /* line 4039 */
} /* line 4039 */
  sim_icache_fetch(2533 + t_thisfile.offset, 1);
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
} /* line 4041 */
  sim_icache_fetch(2534 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4043 */
} /* line 4043 */
  sim_icache_fetch(2536 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4045 */
} /* line 4045 */
  sim_icache_fetch(2537 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4047 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4048 */
} /* line 4048 */
  sim_icache_fetch(2541 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 3),0,1)); /* line 4050 */
} /* line 4050 */
  sim_icache_fetch(2542 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4052 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4053 */
} /* line 4053 */
  sim_icache_fetch(2544 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4055 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4056 */
} /* line 4056 */
  sim_icache_fetch(2546 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4058 */
} /* line 4058 */
  sim_icache_fetch(2547 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4060 */
} /* line 4060 */
  sim_icache_fetch(2548 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_8, reg_r0_23); /* line 4062 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 4063 */
} /* line 4063 */
  sim_icache_fetch(2550 + t_thisfile.offset, 1);
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
} /* line 4065 */
  sim_icache_fetch(2551 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4067 */
} /* line 4067 */
  sim_icache_fetch(2553 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4069 */
} /* line 4069 */
  sim_icache_fetch(2554 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4071 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4072 */
} /* line 4072 */
  sim_icache_fetch(2558 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 4),0,1)); /* line 4074 */
} /* line 4074 */
  sim_icache_fetch(2559 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4076 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4077 */
} /* line 4077 */
  sim_icache_fetch(2561 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4079 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4080 */
} /* line 4080 */
  sim_icache_fetch(2563 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4082 */
} /* line 4082 */
  sim_icache_fetch(2564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4084 */
} /* line 4084 */
  sim_icache_fetch(2565 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_9, reg_r0_23); /* line 4086 */
   __ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 4087 */
} /* line 4087 */
  sim_icache_fetch(2567 + t_thisfile.offset, 1);
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
} /* line 4089 */
  sim_icache_fetch(2568 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4091 */
} /* line 4091 */
  sim_icache_fetch(2570 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4093 */
} /* line 4093 */
  sim_icache_fetch(2571 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4095 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4096 */
} /* line 4096 */
  sim_icache_fetch(2575 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 5),0,1)); /* line 4098 */
} /* line 4098 */
  sim_icache_fetch(2576 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4100 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4101 */
} /* line 4101 */
  sim_icache_fetch(2578 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4103 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4104 */
} /* line 4104 */
  sim_icache_fetch(2580 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4106 */
} /* line 4106 */
  sim_icache_fetch(2581 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4108 */
} /* line 4108 */
  sim_icache_fetch(2582 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_10, reg_r0_23); /* line 4110 */
   __ADD(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 4111 */
} /* line 4111 */
  sim_icache_fetch(2584 + t_thisfile.offset, 1);
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
} /* line 4113 */
  sim_icache_fetch(2585 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4115 */
} /* line 4115 */
  sim_icache_fetch(2587 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4117 */
} /* line 4117 */
  sim_icache_fetch(2588 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4119 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4120 */
} /* line 4120 */
  sim_icache_fetch(2592 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 6),0,1)); /* line 4122 */
} /* line 4122 */
  sim_icache_fetch(2593 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4124 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4125 */
} /* line 4125 */
  sim_icache_fetch(2595 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4127 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4128 */
} /* line 4128 */
  sim_icache_fetch(2597 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4130 */
} /* line 4130 */
  sim_icache_fetch(2598 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4132 */
} /* line 4132 */
  sim_icache_fetch(2599 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_11, reg_r0_23); /* line 4134 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 4135 */
} /* line 4135 */
  sim_icache_fetch(2601 + t_thisfile.offset, 1);
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
} /* line 4137 */
  sim_icache_fetch(2602 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4139 */
} /* line 4139 */
  sim_icache_fetch(2604 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4141 */
} /* line 4141 */
  sim_icache_fetch(2605 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4143 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4144 */
} /* line 4144 */
  sim_icache_fetch(2609 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 7),0,1)); /* line 4146 */
} /* line 4146 */
  sim_icache_fetch(2610 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4148 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4149 */
} /* line 4149 */
  sim_icache_fetch(2612 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4151 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4152 */
} /* line 4152 */
  sim_icache_fetch(2614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4154 */
} /* line 4154 */
  sim_icache_fetch(2615 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4156 */
} /* line 4156 */
  sim_icache_fetch(2616 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_12, reg_r0_23); /* line 4158 */
   __ADD(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 4159 */
} /* line 4159 */
  sim_icache_fetch(2618 + t_thisfile.offset, 1);
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
} /* line 4161 */
  sim_icache_fetch(2619 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4163 */
} /* line 4163 */
  sim_icache_fetch(2621 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4165 */
} /* line 4165 */
  sim_icache_fetch(2622 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4167 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4168 */
} /* line 4168 */
  sim_icache_fetch(2626 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,1)); /* line 4170 */
} /* line 4170 */
  sim_icache_fetch(2627 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4172 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4173 */
} /* line 4173 */
  sim_icache_fetch(2629 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4175 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4176 */
} /* line 4176 */
  sim_icache_fetch(2631 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4178 */
} /* line 4178 */
  sim_icache_fetch(2632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4180 */
} /* line 4180 */
  sim_icache_fetch(2633 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, reg_r0_23); /* line 4182 */
   __ADD(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 4183 */
} /* line 4183 */
  sim_icache_fetch(2635 + t_thisfile.offset, 1);
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
} /* line 4185 */
  sim_icache_fetch(2636 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4187 */
} /* line 4187 */
  sim_icache_fetch(2638 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4189 */
} /* line 4189 */
  sim_icache_fetch(2639 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4191 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4192 */
} /* line 4192 */
  sim_icache_fetch(2643 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 9),0,1)); /* line 4194 */
} /* line 4194 */
  sim_icache_fetch(2644 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4196 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4197 */
} /* line 4197 */
  sim_icache_fetch(2646 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4199 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4200 */
} /* line 4200 */
  sim_icache_fetch(2648 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4202 */
} /* line 4202 */
  sim_icache_fetch(2649 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4204 */
} /* line 4204 */
  sim_icache_fetch(2650 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_14, reg_r0_23); /* line 4206 */
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 4207 */
} /* line 4207 */
  sim_icache_fetch(2652 + t_thisfile.offset, 1);
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
} /* line 4209 */
  sim_icache_fetch(2653 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4211 */
} /* line 4211 */
  sim_icache_fetch(2655 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4213 */
} /* line 4213 */
  sim_icache_fetch(2656 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4215 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4216 */
} /* line 4216 */
  sim_icache_fetch(2660 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 10),0,1)); /* line 4218 */
} /* line 4218 */
  sim_icache_fetch(2661 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4220 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4221 */
} /* line 4221 */
  sim_icache_fetch(2663 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4223 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4224 */
} /* line 4224 */
  sim_icache_fetch(2665 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4226 */
} /* line 4226 */
  sim_icache_fetch(2666 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4228 */
} /* line 4228 */
  sim_icache_fetch(2667 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_15, reg_r0_23); /* line 4230 */
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) 16); /* line 4231 */
} /* line 4231 */
  sim_icache_fetch(2669 + t_thisfile.offset, 1);
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
} /* line 4233 */
  sim_icache_fetch(2670 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4235 */
} /* line 4235 */
  sim_icache_fetch(2672 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4237 */
} /* line 4237 */
  sim_icache_fetch(2673 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4239 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4240 */
} /* line 4240 */
  sim_icache_fetch(2677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 11),0,1)); /* line 4242 */
} /* line 4242 */
  sim_icache_fetch(2678 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4244 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4245 */
} /* line 4245 */
  sim_icache_fetch(2680 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4247 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4248 */
} /* line 4248 */
  sim_icache_fetch(2682 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4250 */
} /* line 4250 */
  sim_icache_fetch(2683 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4252 */
} /* line 4252 */
  sim_icache_fetch(2684 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_16, reg_r0_23); /* line 4254 */
   __ADD(reg_r0_16, reg_r0_16, (unsigned int) 16); /* line 4255 */
} /* line 4255 */
  sim_icache_fetch(2686 + t_thisfile.offset, 1);
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
} /* line 4257 */
  sim_icache_fetch(2687 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4259 */
} /* line 4259 */
  sim_icache_fetch(2689 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4261 */
} /* line 4261 */
  sim_icache_fetch(2690 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4263 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4264 */
} /* line 4264 */
  sim_icache_fetch(2694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 12),0,1)); /* line 4266 */
} /* line 4266 */
  sim_icache_fetch(2695 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4268 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4269 */
} /* line 4269 */
  sim_icache_fetch(2697 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4271 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4272 */
} /* line 4272 */
  sim_icache_fetch(2699 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4274 */
} /* line 4274 */
  sim_icache_fetch(2700 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4276 */
} /* line 4276 */
  sim_icache_fetch(2701 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, reg_r0_23); /* line 4278 */
   __ADD(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 4279 */
} /* line 4279 */
  sim_icache_fetch(2703 + t_thisfile.offset, 1);
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
} /* line 4281 */
  sim_icache_fetch(2704 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4283 */
} /* line 4283 */
  sim_icache_fetch(2706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4285 */
} /* line 4285 */
  sim_icache_fetch(2707 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4287 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4288 */
} /* line 4288 */
  sim_icache_fetch(2711 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 13),0,1)); /* line 4290 */
} /* line 4290 */
  sim_icache_fetch(2712 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4292 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4293 */
} /* line 4293 */
  sim_icache_fetch(2714 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4295 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4296 */
} /* line 4296 */
  sim_icache_fetch(2716 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4298 */
} /* line 4298 */
  sim_icache_fetch(2717 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4300 */
} /* line 4300 */
  sim_icache_fetch(2718 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_18, reg_r0_23); /* line 4302 */
   __ADD(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 4303 */
} /* line 4303 */
  sim_icache_fetch(2720 + t_thisfile.offset, 1);
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
} /* line 4305 */
  sim_icache_fetch(2721 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4307 */
} /* line 4307 */
  sim_icache_fetch(2723 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4309 */
} /* line 4309 */
  sim_icache_fetch(2724 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4311 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4312 */
} /* line 4312 */
  sim_icache_fetch(2728 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 14),0,1)); /* line 4314 */
} /* line 4314 */
  sim_icache_fetch(2729 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4316 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4317 */
} /* line 4317 */
  sim_icache_fetch(2731 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4319 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4320 */
} /* line 4320 */
  sim_icache_fetch(2733 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4322 */
} /* line 4322 */
  sim_icache_fetch(2734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4324 */
} /* line 4324 */
  sim_icache_fetch(2735 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_19, reg_r0_23); /* line 4326 */
   __ADD(reg_r0_19, reg_r0_19, (unsigned int) 16); /* line 4327 */
} /* line 4327 */
  sim_icache_fetch(2737 + t_thisfile.offset, 1);
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
} /* line 4329 */
  sim_icache_fetch(2738 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4331 */
} /* line 4331 */
  sim_icache_fetch(2740 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4333 */
} /* line 4333 */
  sim_icache_fetch(2741 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4335 */
   __LDWs(reg_r0_4, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4336 */
} /* line 4336 */
  sim_icache_fetch(2745 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBs(reg_r0_21, mem_trace_ld((reg_r0_5 + (unsigned int) 15),0,1)); /* line 4338 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 4339 */
} /* line 4339 */
  sim_icache_fetch(2747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4341 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 1); /* line 4342 */
} /* line 4342 */
  sim_icache_fetch(2749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4344 */
   __ADD(reg_r0_23, reg_r0_2, (unsigned int) 7); /* line 4345 */
} /* line 4345 */
  sim_icache_fetch(2751 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_2); /* line 4347 */
} /* line 4347 */
  sim_icache_fetch(2752 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 3); /* line 4349 */
} /* line 4349 */
  sim_icache_fetch(2753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_20, reg_r0_23); /* line 4351 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 16); /* line 4352 */
} /* line 4352 */
  sim_icache_fetch(2755 + t_thisfile.offset, 1);
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
} /* line 4354 */
  sim_icache_fetch(2756 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 4356 */
} /* line 4356 */
  sim_icache_fetch(2758 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_21); /* line 4358 */
   __GOTO(l_L158X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L158X3;
} /* line 4359 */
l_L174X3: ;/* line 4362 */
__LABEL(l_L174X3);
  sim_icache_fetch(2760 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4363 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4364 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4365 */
   __ADD_CYCLES(1);
} /* line 4365 */
  sim_icache_fetch(2765 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4367 */
} /* line 4367 */
  sim_icache_fetch(2766 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4369 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4370 */
} /* line 4370 */
  sim_icache_fetch(2768 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4372 */
} /* line 4372 */
  sim_icache_fetch(2769 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4374 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4375 */
l_L173X3: ;/* line 4378 */
__LABEL(l_L173X3);
  sim_icache_fetch(2771 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4379 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4380 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4381 */
   __ADD_CYCLES(1);
} /* line 4381 */
  sim_icache_fetch(2776 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4383 */
} /* line 4383 */
  sim_icache_fetch(2777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4385 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4386 */
} /* line 4386 */
  sim_icache_fetch(2779 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4388 */
} /* line 4388 */
  sim_icache_fetch(2780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4390 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4391 */
l_L172X3: ;/* line 4394 */
__LABEL(l_L172X3);
  sim_icache_fetch(2782 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4395 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4396 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4397 */
   __ADD_CYCLES(1);
} /* line 4397 */
  sim_icache_fetch(2787 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4399 */
} /* line 4399 */
  sim_icache_fetch(2788 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4401 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4402 */
} /* line 4402 */
  sim_icache_fetch(2790 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4404 */
} /* line 4404 */
  sim_icache_fetch(2791 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4406 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4407 */
l_L171X3: ;/* line 4410 */
__LABEL(l_L171X3);
  sim_icache_fetch(2793 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4411 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4412 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4413 */
   __ADD_CYCLES(1);
} /* line 4413 */
  sim_icache_fetch(2798 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4415 */
} /* line 4415 */
  sim_icache_fetch(2799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4417 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4418 */
} /* line 4418 */
  sim_icache_fetch(2801 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4420 */
} /* line 4420 */
  sim_icache_fetch(2802 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4422 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4423 */
l_L170X3: ;/* line 4426 */
__LABEL(l_L170X3);
  sim_icache_fetch(2804 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4427 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4428 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4429 */
   __ADD_CYCLES(1);
} /* line 4429 */
  sim_icache_fetch(2809 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4431 */
} /* line 4431 */
  sim_icache_fetch(2810 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4433 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4434 */
} /* line 4434 */
  sim_icache_fetch(2812 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4436 */
} /* line 4436 */
  sim_icache_fetch(2813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4438 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4439 */
l_L169X3: ;/* line 4442 */
__LABEL(l_L169X3);
  sim_icache_fetch(2815 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4443 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4444 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4445 */
   __ADD_CYCLES(1);
} /* line 4445 */
  sim_icache_fetch(2820 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4447 */
} /* line 4447 */
  sim_icache_fetch(2821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4449 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4450 */
} /* line 4450 */
  sim_icache_fetch(2823 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4452 */
} /* line 4452 */
  sim_icache_fetch(2824 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4454 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4455 */
l_L168X3: ;/* line 4458 */
__LABEL(l_L168X3);
  sim_icache_fetch(2826 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4459 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4460 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4461 */
   __ADD_CYCLES(1);
} /* line 4461 */
  sim_icache_fetch(2831 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4463 */
} /* line 4463 */
  sim_icache_fetch(2832 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4465 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4466 */
} /* line 4466 */
  sim_icache_fetch(2834 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4468 */
} /* line 4468 */
  sim_icache_fetch(2835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4470 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4471 */
l_L167X3: ;/* line 4474 */
__LABEL(l_L167X3);
  sim_icache_fetch(2837 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4475 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4476 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4477 */
   __ADD_CYCLES(1);
} /* line 4477 */
  sim_icache_fetch(2842 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4479 */
} /* line 4479 */
  sim_icache_fetch(2843 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4481 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4482 */
} /* line 4482 */
  sim_icache_fetch(2845 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4484 */
} /* line 4484 */
  sim_icache_fetch(2846 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4486 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4487 */
l_L166X3: ;/* line 4490 */
__LABEL(l_L166X3);
  sim_icache_fetch(2848 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4491 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4492 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4493 */
   __ADD_CYCLES(1);
} /* line 4493 */
  sim_icache_fetch(2853 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4495 */
} /* line 4495 */
  sim_icache_fetch(2854 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4497 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4498 */
} /* line 4498 */
  sim_icache_fetch(2856 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4500 */
} /* line 4500 */
  sim_icache_fetch(2857 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4502 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4503 */
l_L165X3: ;/* line 4506 */
__LABEL(l_L165X3);
  sim_icache_fetch(2859 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4507 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4508 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4509 */
   __ADD_CYCLES(1);
} /* line 4509 */
  sim_icache_fetch(2864 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4511 */
} /* line 4511 */
  sim_icache_fetch(2865 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4513 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4514 */
} /* line 4514 */
  sim_icache_fetch(2867 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4516 */
} /* line 4516 */
  sim_icache_fetch(2868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4518 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4519 */
l_L164X3: ;/* line 4522 */
__LABEL(l_L164X3);
  sim_icache_fetch(2870 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4523 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4524 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4525 */
   __ADD_CYCLES(1);
} /* line 4525 */
  sim_icache_fetch(2875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4527 */
} /* line 4527 */
  sim_icache_fetch(2876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4529 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4530 */
} /* line 4530 */
  sim_icache_fetch(2878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4532 */
} /* line 4532 */
  sim_icache_fetch(2879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4534 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4535 */
l_L163X3: ;/* line 4538 */
__LABEL(l_L163X3);
  sim_icache_fetch(2881 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4539 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4540 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4541 */
   __ADD_CYCLES(1);
} /* line 4541 */
  sim_icache_fetch(2886 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4543 */
} /* line 4543 */
  sim_icache_fetch(2887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4545 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4546 */
} /* line 4546 */
  sim_icache_fetch(2889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4548 */
} /* line 4548 */
  sim_icache_fetch(2890 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4550 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4551 */
l_L162X3: ;/* line 4554 */
__LABEL(l_L162X3);
  sim_icache_fetch(2892 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4555 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4556 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4557 */
   __ADD_CYCLES(1);
} /* line 4557 */
  sim_icache_fetch(2897 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4559 */
} /* line 4559 */
  sim_icache_fetch(2898 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4561 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4562 */
} /* line 4562 */
  sim_icache_fetch(2900 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4564 */
} /* line 4564 */
  sim_icache_fetch(2901 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4566 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4567 */
l_L161X3: ;/* line 4570 */
__LABEL(l_L161X3);
  sim_icache_fetch(2903 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4571 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4572 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4573 */
   __ADD_CYCLES(1);
} /* line 4573 */
  sim_icache_fetch(2908 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4575 */
} /* line 4575 */
  sim_icache_fetch(2909 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4577 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4578 */
} /* line 4578 */
  sim_icache_fetch(2911 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4580 */
} /* line 4580 */
  sim_icache_fetch(2912 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4582 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4583 */
l_L160X3: ;/* line 4586 */
__LABEL(l_L160X3);
  sim_icache_fetch(2914 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4587 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4588 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4589 */
   __ADD_CYCLES(1);
} /* line 4589 */
  sim_icache_fetch(2919 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4591 */
} /* line 4591 */
  sim_icache_fetch(2920 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4593 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4594 */
} /* line 4594 */
  sim_icache_fetch(2922 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4596 */
} /* line 4596 */
  sim_icache_fetch(2923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4598 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4599 */
l_L159X3: ;/* line 4602 */
__LABEL(l_L159X3);
  sim_icache_fetch(2925 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 4603 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) compress_8838Xoffset,0,4)); /* line 4604 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4605 */
   __ADD_CYCLES(1);
} /* line 4605 */
  sim_icache_fetch(2930 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4607 */
} /* line 4607 */
  sim_icache_fetch(2931 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 4609 */
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 7); /* line 4610 */
} /* line 4610 */
  sim_icache_fetch(2933 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_2); /* line 4612 */
} /* line 4612 */
  sim_icache_fetch(2934 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_4, (unsigned int) 3); /* line 4614 */
   __GOTO(l_L157X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L157X3;
} /* line 4615 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 309: goto l_L145X3;
    case 310: goto l_L146X3;
    case 311: goto l_L148X3;
    case 312: goto l_L149X3;
    case 313: goto l_L147X3;
    case 314: goto l_L152X3;
    case 315: goto l_L153X3;
    case 316: goto l_L151X3;
    case 317: goto l_L154X3;
    case 318: goto l_L155X3;
    case 319: goto l_L150X3;
    case 320: goto l_L144X3;
    case 321: goto l_L157X3;
    case 322: goto l_L156X3;
    case 323: goto l_L158X3;
    case 324: goto l_L174X3;
    case 325: goto l_L173X3;
    case 326: goto l_L172X3;
    case 327: goto l_L171X3;
    case 328: goto l_L170X3;
    case 329: goto l_L169X3;
    case 330: goto l_L168X3;
    case 331: goto l_L167X3;
    case 332: goto l_L166X3;
    case 333: goto l_L165X3;
    case 334: goto l_L164X3;
    case 335: goto l_L163X3;
    case 336: goto l_L162X3;
    case 337: goto l_L161X3;
    case 338: goto l_L160X3;
    case 339: goto l_L159X3;
    case 340:
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
  reg_l0_0 = (396 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(2936 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 4631 */
   __MOV(reg_r0_20, (unsigned int) 9); /* line 4632 */
} /* line 4632 */
  sim_icache_fetch(2938 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_21, (unsigned int) 511); /* line 4634 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 4635 */
} /* line 4635 */
  sim_icache_fetch(2941 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_18, (unsigned int) 241); /* line 4637 */
   __MOV(reg_r0_19, (unsigned int) 240); /* line 4638 */
} /* line 4638 */
  sim_icache_fetch(2943 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_16, (unsigned int) 243); /* line 4640 */
   __MOV(reg_r0_17, (unsigned int) 242); /* line 4641 */
} /* line 4641 */
  sim_icache_fetch(2945 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, (unsigned int) 245); /* line 4643 */
   __MOV(reg_r0_15, (unsigned int) 244); /* line 4644 */
} /* line 4644 */
  sim_icache_fetch(2947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_12, (unsigned int) 247); /* line 4646 */
   __MOV(reg_r0_13, (unsigned int) 246); /* line 4647 */
} /* line 4647 */
  sim_icache_fetch(2949 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_10, (unsigned int) 249); /* line 4649 */
   __MOV(reg_r0_11, (unsigned int) 248); /* line 4650 */
} /* line 4650 */
  sim_icache_fetch(2951 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_8, (unsigned int) 251); /* line 4652 */
   __MOV(reg_r0_9, (unsigned int) 250); /* line 4653 */
} /* line 4653 */
  sim_icache_fetch(2953 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 253); /* line 4655 */
   __MOV(reg_r0_7, (unsigned int) 252); /* line 4656 */
} /* line 4656 */
  sim_icache_fetch(2955 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, ((unsigned int) htab + (unsigned int) 240)); /* line 4658 */
   __MOV(reg_r0_5, (unsigned int) 254); /* line 4659 */
} /* line 4659 */
  sim_icache_fetch(2958 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4661 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4662 */
} /* line 4662 */
  sim_icache_fetch(2961 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_20); /* line 4664 */
   __MOV(reg_r0_38, reg_l0_0); /* line 4665 */
} /* line 4665 */
  sim_icache_fetch(2964 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_21); /* line 4667 */
} /* line 4667 */
l_L175X3: ;/* line 4670 */
__LABEL(l_L175X3);
  sim_icache_fetch(2966 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4671 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) -32); /* line 4672 */
} /* line 4672 */
  sim_icache_fetch(2968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_21, reg_r0_2, (unsigned int) -16); /* line 4674 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L176X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4675 */
  sim_icache_fetch(2970 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_23, reg_r0_5, (unsigned int) -16); /* line 4677 */
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) -16); /* line 4678 */
} /* line 4678 */
  sim_icache_fetch(2972 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_25, reg_r0_7, (unsigned int) -16); /* line 4680 */
   __ADD(reg_r0_24, reg_r0_6, (unsigned int) -16); /* line 4681 */
} /* line 4681 */
  sim_icache_fetch(2974 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_27, reg_r0_9, (unsigned int) -16); /* line 4683 */
   __ADD(reg_r0_26, reg_r0_8, (unsigned int) -16); /* line 4684 */
} /* line 4684 */
  sim_icache_fetch(2976 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_29, reg_r0_11, (unsigned int) -16); /* line 4686 */
   __ADD(reg_r0_28, reg_r0_10, (unsigned int) -16); /* line 4687 */
} /* line 4687 */
  sim_icache_fetch(2978 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_31, reg_r0_13, (unsigned int) -16); /* line 4689 */
   __ADD(reg_r0_30, reg_r0_12, (unsigned int) -16); /* line 4690 */
} /* line 4690 */
  sim_icache_fetch(2980 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_33, reg_r0_15, (unsigned int) -16); /* line 4692 */
   __ADD(reg_r0_32, reg_r0_14, (unsigned int) -16); /* line 4693 */
} /* line 4693 */
  sim_icache_fetch(2982 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_35, reg_r0_17, (unsigned int) -16); /* line 4695 */
   __ADD(reg_r0_34, reg_r0_16, (unsigned int) -16); /* line 4696 */
} /* line 4696 */
  sim_icache_fetch(2984 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 4698 */
   __ADD(reg_r0_36, reg_r0_18, (unsigned int) -16); /* line 4699 */
} /* line 4699 */
  sim_icache_fetch(2986 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4701 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 15),0,1), reg_r0_2); /* line 4702 */
} /* line 4702 */
  sim_icache_fetch(2988 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4704 */
   __ADD(reg_r0_2, reg_r0_21, (unsigned int) -16); /* line 4705 */
} /* line 4705 */
  sim_icache_fetch(2990 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 14),0,1), reg_r0_5); /* line 4707 */
   __ADD(reg_r0_5, reg_r0_23, (unsigned int) -16); /* line 4708 */
} /* line 4708 */
  sim_icache_fetch(2992 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4710 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 13),0,1), reg_r0_6); /* line 4711 */
} /* line 4711 */
  sim_icache_fetch(2994 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4713 */
   __ADD(reg_r0_6, reg_r0_24, (unsigned int) -16); /* line 4714 */
} /* line 4714 */
  sim_icache_fetch(2996 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,1), reg_r0_7); /* line 4716 */
   __ADD(reg_r0_7, reg_r0_25, (unsigned int) -16); /* line 4717 */
} /* line 4717 */
  sim_icache_fetch(2998 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4719 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 11),0,1), reg_r0_8); /* line 4720 */
} /* line 4720 */
  sim_icache_fetch(3000 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4722 */
   __ADD(reg_r0_8, reg_r0_26, (unsigned int) -16); /* line 4723 */
} /* line 4723 */
  sim_icache_fetch(3002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 10),0,1), reg_r0_9); /* line 4725 */
   __ADD(reg_r0_9, reg_r0_27, (unsigned int) -16); /* line 4726 */
} /* line 4726 */
  sim_icache_fetch(3004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4728 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 9),0,1), reg_r0_10); /* line 4729 */
} /* line 4729 */
  sim_icache_fetch(3006 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4731 */
   __ADD(reg_r0_10, reg_r0_28, (unsigned int) -16); /* line 4732 */
} /* line 4732 */
  sim_icache_fetch(3008 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,1), reg_r0_11); /* line 4734 */
   __ADD(reg_r0_11, reg_r0_29, (unsigned int) -16); /* line 4735 */
} /* line 4735 */
  sim_icache_fetch(3010 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4737 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 7),0,1), reg_r0_12); /* line 4738 */
} /* line 4738 */
  sim_icache_fetch(3012 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4740 */
   __ADD(reg_r0_12, reg_r0_30, (unsigned int) -16); /* line 4741 */
} /* line 4741 */
  sim_icache_fetch(3014 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 6),0,1), reg_r0_13); /* line 4743 */
   __ADD(reg_r0_13, reg_r0_31, (unsigned int) -16); /* line 4744 */
} /* line 4744 */
  sim_icache_fetch(3016 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4746 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 5),0,1), reg_r0_14); /* line 4747 */
} /* line 4747 */
  sim_icache_fetch(3018 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4749 */
   __ADD(reg_r0_14, reg_r0_32, (unsigned int) -16); /* line 4750 */
} /* line 4750 */
  sim_icache_fetch(3020 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,1), reg_r0_15); /* line 4752 */
   __ADD(reg_r0_15, reg_r0_33, (unsigned int) -16); /* line 4753 */
} /* line 4753 */
  sim_icache_fetch(3022 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4755 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 3),0,1), reg_r0_16); /* line 4756 */
} /* line 4756 */
  sim_icache_fetch(3024 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4758 */
   __ADD(reg_r0_16, reg_r0_34, (unsigned int) -16); /* line 4759 */
} /* line 4759 */
  sim_icache_fetch(3026 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 2),0,1), reg_r0_17); /* line 4761 */
   __ADD(reg_r0_17, reg_r0_35, (unsigned int) -16); /* line 4762 */
} /* line 4762 */
  sim_icache_fetch(3028 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4764 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) 1),0,1), reg_r0_18); /* line 4765 */
} /* line 4765 */
  sim_icache_fetch(3030 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4767 */
   __ADD(reg_r0_18, reg_r0_36, (unsigned int) -16); /* line 4768 */
} /* line 4768 */
  sim_icache_fetch(3032 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_4,0,1), reg_r0_19); /* line 4770 */
   __ADD(reg_r0_3, reg_r0_20, (unsigned int) -32); /* line 4771 */
} /* line 4771 */
  sim_icache_fetch(3034 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 4773 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) -16); /* line 4774 */
} /* line 4774 */
  sim_icache_fetch(3036 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 30),0,2), 0); /* line 4776 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 15),0,1), reg_r0_21); /* line 4777 */
} /* line 4777 */
  sim_icache_fetch(3038 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 28),0,2), 0); /* line 4779 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 14),0,1), reg_r0_23); /* line 4780 */
} /* line 4780 */
  sim_icache_fetch(3040 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 26),0,2), 0); /* line 4782 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 13),0,1), reg_r0_24); /* line 4783 */
} /* line 4783 */
  sim_icache_fetch(3042 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 24),0,2), 0); /* line 4785 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 12),0,1), reg_r0_25); /* line 4786 */
} /* line 4786 */
  sim_icache_fetch(3044 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 22),0,2), 0); /* line 4788 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 11),0,1), reg_r0_26); /* line 4789 */
} /* line 4789 */
  sim_icache_fetch(3046 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 20),0,2), 0); /* line 4791 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 10),0,1), reg_r0_27); /* line 4792 */
} /* line 4792 */
  sim_icache_fetch(3048 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 18),0,2), 0); /* line 4794 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 9),0,1), reg_r0_28); /* line 4795 */
} /* line 4795 */
  sim_icache_fetch(3050 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 16),0,2), 0); /* line 4797 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 8),0,1), reg_r0_29); /* line 4798 */
} /* line 4798 */
  sim_icache_fetch(3052 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 14),0,2), 0); /* line 4800 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 7),0,1), reg_r0_30); /* line 4801 */
} /* line 4801 */
  sim_icache_fetch(3054 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 12),0,2), 0); /* line 4803 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 6),0,1), reg_r0_31); /* line 4804 */
} /* line 4804 */
  sim_icache_fetch(3056 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 10),0,2), 0); /* line 4806 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 5),0,1), reg_r0_32); /* line 4807 */
} /* line 4807 */
  sim_icache_fetch(3058 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 8),0,2), 0); /* line 4809 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 4),0,1), reg_r0_33); /* line 4810 */
} /* line 4810 */
  sim_icache_fetch(3060 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 6),0,2), 0); /* line 4812 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 3),0,1), reg_r0_34); /* line 4813 */
} /* line 4813 */
  sim_icache_fetch(3062 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 4),0,2), 0); /* line 4815 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 2),0,1), reg_r0_35); /* line 4816 */
} /* line 4816 */
  sim_icache_fetch(3064 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_20 + (unsigned int) 2),0,2), 0); /* line 4818 */
   __STB(mem_trace_st((reg_r0_22 + (unsigned int) 1),0,1), reg_r0_36); /* line 4819 */
} /* line 4819 */
  sim_icache_fetch(3066 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st(reg_r0_20,0,2), 0); /* line 4821 */
   __STB(mem_trace_st(reg_r0_22,0,1), reg_r0_37); /* line 4823 */
} /* line 4823 */
  sim_icache_fetch(3068 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L175X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L175X3;
} /* line 4825 */
l_L176X3: ;/* line 4828 */
__LABEL(l_L176X3);
  sim_icache_fetch(3069 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4829 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_38); /* line 4830 */
} /* line 4830 */
  sim_icache_fetch(3072 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_4, (unsigned int) 257); /* line 4832 */
} /* line 4832 */
  sim_icache_fetch(3074 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 4834 */
} /* line 4834 */
  sim_icache_fetch(3075 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, (unsigned int) 256); /* line 4836 */
} /* line 4836 */
		 /* line 4837 */
  sim_icache_fetch(3077 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 4839 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (396 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4840 */
l_lr_243: ;/* line 4840 */
__LABEL(l_lr_243);
  sim_icache_fetch(3081 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_3); /* line 4842 */
   __MOV(reg_r0_4, reg_r0_3); /* line 4843 */
} /* line 4843 */
  sim_icache_fetch(3083 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4845 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 4846 */
} /* line 4846 */
  sim_icache_fetch(3085 + t_thisfile.offset, 1);
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
} /* line 4848 */
  sim_icache_fetch(3086 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 4852 */
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4852 */
l_L177X3: ;/* line 4855 */
__LABEL(l_L177X3);
  sim_icache_fetch(3088 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 4856 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 4857 */
} /* line 4857 */
  sim_icache_fetch(3090 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 4859 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_59); /* line 4860 */
} /* line 4860 */
  sim_icache_fetch(3093 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_58, ((unsigned int) htab + (unsigned int) 4096)); /* line 4862 */
   __MOV(reg_r0_57, reg_r0_4); /* line 4863 */
} /* line 4863 */
  sim_icache_fetch(3096 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_5, (unsigned int) 1); /* line 4865 */
   __MOV(reg_r0_59, reg_r0_2); /* line 4866 */
} /* line 4866 */
  sim_icache_fetch(3098 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 4868 */
} /* line 4868 */
  sim_icache_fetch(3100 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4870 */
} /* line 4870 */
l_L178X3: ;/* line 4873 */
__LABEL(l_L178X3);
		 /* line 4873 */
  sim_icache_fetch(3101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (396 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4875 */
l_lr_247: ;/* line 4875 */
__LABEL(l_lr_247);
  sim_icache_fetch(3103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4877 */
   __CMPGT(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4878 */
} /* line 4878 */
  sim_icache_fetch(3105 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) block_compress,0,4)); /* line 4880 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L179X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4881 */
  sim_icache_fetch(3108 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_r0_3, reg_r0_3, (unsigned int) 256); /* line 4883 */
   __MOV(reg_r0_2, (unsigned int) 255); /* line 4884 */
} /* line 4884 */
  sim_icache_fetch(3111 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ANDL(reg_b0_0, reg_r0_3, reg_r0_6); /* line 4886 */
   __MOV(reg_r0_3, ((unsigned int) codetab + (unsigned int) 480)); /* line 4887 */
} /* line 4887 */
  sim_icache_fetch(3114 + t_thisfile.offset, 1);
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
} /* line 4889 */
l_L181X3: ;/* line 4892 */
__LABEL(l_L181X3);
  sim_icache_fetch(3115 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 4893 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -16); /* line 4894 */
} /* line 4894 */
  sim_icache_fetch(3117 + t_thisfile.offset, 1);
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
} /* line 4896 */
  sim_icache_fetch(3118 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 30),0,2), 0); /* line 4898 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,2), 0); /* line 4899 */
} /* line 4899 */
  sim_icache_fetch(3120 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 26),0,2), 0); /* line 4901 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,2), 0); /* line 4902 */
} /* line 4902 */
  sim_icache_fetch(3122 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 22),0,2), 0); /* line 4904 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,2), 0); /* line 4905 */
} /* line 4905 */
  sim_icache_fetch(3124 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 18),0,2), 0); /* line 4907 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,2), 0); /* line 4908 */
} /* line 4908 */
  sim_icache_fetch(3126 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 14),0,2), 0); /* line 4910 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,2), 0); /* line 4911 */
} /* line 4911 */
  sim_icache_fetch(3128 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 10),0,2), 0); /* line 4913 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,2), 0); /* line 4914 */
} /* line 4914 */
  sim_icache_fetch(3130 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 6),0,2), 0); /* line 4916 */
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,2), 0); /* line 4917 */
} /* line 4917 */
  sim_icache_fetch(3132 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st((reg_r0_3 + (unsigned int) 2),0,2), 0); /* line 4919 */
   __STH(mem_trace_st(reg_r0_3,0,2), 0); /* line 4920 */
} /* line 4920 */
  sim_icache_fetch(3134 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -32); /* line 4922 */
   __GOTO(l_L181X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L181X3;
} /* line 4923 */
l_L182X3: ;/* line 4926 */
__LABEL(l_L182X3);
  sim_icache_fetch(3136 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 256); /* line 4927 */
   __MOV(reg_r0_2, (unsigned int) 1); /* line 4928 */
} /* line 4928 */
  sim_icache_fetch(3139 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_2); /* line 4930 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_3); /* line 4931 */
} /* line 4931 */
		 /* line 4932 */
  sim_icache_fetch(3143 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(compressgetcode);
   reg_l0_0 = (396 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) compressgetcode;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 4934 */
l_lr_251: ;/* line 4934 */
__LABEL(l_lr_251);
  sim_icache_fetch(3145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_3); /* line 4936 */
   __CMPEQ(reg_b0_0, reg_r0_3, (unsigned int) -1); /* line 4937 */
} /* line 4937 */
  sim_icache_fetch(3147 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L183X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4939 */
l_L180X3: ;/* line 4942 */
__LABEL(l_L180X3);
  sim_icache_fetch(3148 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 4943 */
   __MOV(reg_r0_8, reg_r0_4); /* line 4944 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4945 */
   __ADD_CYCLES(1);
} /* line 4945 */
  sim_icache_fetch(3152 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_4, reg_r0_3); /* line 4947 */
   __MOV(reg_r0_2, reg_r0_4); /* line 4948 */
} /* line 4948 */
  sim_icache_fetch(3154 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 256); /* line 4950 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L184X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4951 */
  sim_icache_fetch(3157 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_58,0,1), reg_r0_57); /* line 4953 */
   __MOV(reg_r0_2, reg_r0_59); /* line 4954 */
} /* line 4954 */
  sim_icache_fetch(3159 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_58, (unsigned int) 1); /* line 4956 */
} /* line 4956 */
l_L185X3: ;/* line 4959 */
__LABEL(l_L185X3);
  sim_icache_fetch(3160 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, reg_r0_4); /* line 4960 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 4961 */
} /* line 4961 */
  sim_icache_fetch(3163 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_2, (unsigned int) codetab); /* line 4963 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L186X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4964 */
  sim_icache_fetch(3166 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_3); /* line 4966 */
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4967 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4968 */
   __ADD_CYCLES(1);
} /* line 4968 */
  sim_icache_fetch(3169 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4970 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4971 */
} /* line 4971 */
  sim_icache_fetch(3172 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4973 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L187X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4974 */
  sim_icache_fetch(3175 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 1),0,1), reg_r0_3); /* line 4976 */
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4977 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4978 */
   __ADD_CYCLES(1);
} /* line 4978 */
  sim_icache_fetch(3178 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 4980 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 4981 */
} /* line 4981 */
  sim_icache_fetch(3181 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 4983 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L188X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4984 */
  sim_icache_fetch(3184 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 2),0,1), reg_r0_3); /* line 4986 */
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 4987 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4988 */
   __ADD_CYCLES(1);
} /* line 4988 */
  sim_icache_fetch(3187 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 4990 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 4991 */
} /* line 4991 */
  sim_icache_fetch(3190 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 4993 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L189X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 4994 */
  sim_icache_fetch(3193 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 3),0,1), reg_r0_3); /* line 4996 */
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 4997 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 4998 */
   __ADD_CYCLES(1);
} /* line 4998 */
  sim_icache_fetch(3196 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 5000 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 5001 */
} /* line 5001 */
  sim_icache_fetch(3199 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 5003 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L190X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5004 */
  sim_icache_fetch(3202 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,1), reg_r0_3); /* line 5006 */
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 5007 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5008 */
   __ADD_CYCLES(1);
} /* line 5008 */
  sim_icache_fetch(3205 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 5010 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 5011 */
} /* line 5011 */
  sim_icache_fetch(3208 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 5013 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L191X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5014 */
  sim_icache_fetch(3211 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 5),0,1), reg_r0_3); /* line 5016 */
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 5017 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5018 */
   __ADD_CYCLES(1);
} /* line 5018 */
  sim_icache_fetch(3214 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 5020 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 5021 */
} /* line 5021 */
  sim_icache_fetch(3217 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 5023 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L192X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5024 */
  sim_icache_fetch(3220 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 6),0,1), reg_r0_3); /* line 5026 */
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 5027 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5028 */
   __ADD_CYCLES(1);
} /* line 5028 */
  sim_icache_fetch(3223 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 5030 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 5031 */
} /* line 5031 */
  sim_icache_fetch(3226 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 5033 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L193X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5034 */
  sim_icache_fetch(3229 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 7),0,1), reg_r0_3); /* line 5036 */
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 5037 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5038 */
   __ADD_CYCLES(1);
} /* line 5038 */
  sim_icache_fetch(3232 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 5040 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 5041 */
} /* line 5041 */
  sim_icache_fetch(3235 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 5043 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L194X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5044 */
  sim_icache_fetch(3238 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,1), reg_r0_3); /* line 5046 */
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 5047 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5048 */
   __ADD_CYCLES(1);
} /* line 5048 */
  sim_icache_fetch(3241 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 5050 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 5051 */
} /* line 5051 */
  sim_icache_fetch(3244 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 5053 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L195X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5054 */
  sim_icache_fetch(3247 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 9),0,1), reg_r0_3); /* line 5056 */
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 5057 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5058 */
   __ADD_CYCLES(1);
} /* line 5058 */
  sim_icache_fetch(3250 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 5060 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 5061 */
} /* line 5061 */
  sim_icache_fetch(3253 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 5063 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L196X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5064 */
  sim_icache_fetch(3256 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 10),0,1), reg_r0_3); /* line 5066 */
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 5067 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5068 */
   __ADD_CYCLES(1);
} /* line 5068 */
  sim_icache_fetch(3259 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 5070 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 5071 */
} /* line 5071 */
  sim_icache_fetch(3262 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 5073 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L197X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5074 */
  sim_icache_fetch(3265 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 11),0,1), reg_r0_3); /* line 5076 */
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 5077 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5078 */
   __ADD_CYCLES(1);
} /* line 5078 */
  sim_icache_fetch(3268 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 5080 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 5081 */
} /* line 5081 */
  sim_icache_fetch(3271 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 5083 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L198X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5084 */
  sim_icache_fetch(3274 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,1), reg_r0_3); /* line 5086 */
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 5087 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5088 */
   __ADD_CYCLES(1);
} /* line 5088 */
  sim_icache_fetch(3277 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 5090 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 5091 */
} /* line 5091 */
  sim_icache_fetch(3280 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 5093 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L199X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5094 */
  sim_icache_fetch(3283 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 13),0,1), reg_r0_3); /* line 5096 */
   __LDHU(reg_r0_7, mem_trace_ld(reg_r0_7,0,2)); /* line 5097 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5098 */
   __ADD_CYCLES(1);
} /* line 5098 */
  sim_icache_fetch(3286 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_7, reg_r0_4); /* line 5100 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) htab),0,1)); /* line 5101 */
} /* line 5101 */
  sim_icache_fetch(3289 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_6, reg_r0_7, (unsigned int) codetab); /* line 5103 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L200X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5104 */
  sim_icache_fetch(3292 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 14),0,1), reg_r0_3); /* line 5106 */
   __LDHU(reg_r0_6, mem_trace_ld(reg_r0_6,0,2)); /* line 5107 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5108 */
   __ADD_CYCLES(1);
} /* line 5108 */
  sim_icache_fetch(3295 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_6, reg_r0_4); /* line 5110 */
   __LDBUs(reg_r0_3, mem_trace_ld((reg_r0_6 + (unsigned int) htab),0,1)); /* line 5111 */
} /* line 5111 */
  sim_icache_fetch(3298 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SH1ADD(reg_r0_7, reg_r0_6, (unsigned int) codetab); /* line 5113 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L201X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5114 */
  sim_icache_fetch(3301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_5 + (unsigned int) 15),0,1), reg_r0_3); /* line 5116 */
   __LDHU(reg_r0_2, mem_trace_ld(reg_r0_7,0,2)); /* line 5117 */
} /* line 5117 */
  sim_icache_fetch(3303 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 16); /* line 5119 */
   __GOTO(l_L185X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L185X3;
} /* line 5120 */
l_L201X3: ;/* line 5123 */
__LABEL(l_L201X3);
  sim_icache_fetch(3305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 15); /* line 5124 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5126 */
} /* line 5126 */
  sim_icache_fetch(3307 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5128 */
l_L203X3: ;/* line 5131 */
__LABEL(l_L203X3);
  sim_icache_fetch(3308 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5132 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5133 */
} /* line 5133 */
  sim_icache_fetch(3311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_21, reg_r0_3); /* line 5135 */
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5136 */
} /* line 5136 */
  sim_icache_fetch(3314 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5138 */
   __CMPLEU(reg_b0_1, reg_r0_5, ((unsigned int) htab + (unsigned int) 4096)); /* line 5139 */
} /* line 5139 */
  sim_icache_fetch(3317 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_2, reg_r0_6, ((unsigned int) htab + (unsigned int) 4096)); /* line 5141 */
   __CMPLEU(reg_b0_3, reg_r0_7, ((unsigned int) htab + (unsigned int) 4096)); /* line 5142 */
} /* line 5142 */
  sim_icache_fetch(3321 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_4, reg_r0_8, ((unsigned int) htab + (unsigned int) 4096)); /* line 5144 */
   __CMPLEU(reg_b0_5, reg_r0_9, ((unsigned int) htab + (unsigned int) 4096)); /* line 5145 */
} /* line 5145 */
  sim_icache_fetch(3325 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_6, reg_r0_10, ((unsigned int) htab + (unsigned int) 4096)); /* line 5147 */
   __CMPLEU(reg_b0_7, reg_r0_11, ((unsigned int) htab + (unsigned int) 4096)); /* line 5148 */
} /* line 5148 */
  sim_icache_fetch(3329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -16); /* line 5150 */
   __ADD(reg_r0_23, reg_r0_18, (unsigned int) -16); /* line 5151 */
} /* line 5151 */
  sim_icache_fetch(3331 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_24, reg_r0_17, (unsigned int) -16); /* line 5153 */
   __ADD(reg_r0_25, reg_r0_16, (unsigned int) -16); /* line 5154 */
} /* line 5154 */
  sim_icache_fetch(3333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_26, reg_r0_15, (unsigned int) -16); /* line 5156 */
   __ADD(reg_r0_27, reg_r0_14, (unsigned int) -16); /* line 5157 */
} /* line 5157 */
  sim_icache_fetch(3335 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_28, reg_r0_13, (unsigned int) -16); /* line 5159 */
   __ADD(reg_r0_29, reg_r0_12, (unsigned int) -16); /* line 5160 */
} /* line 5160 */
  sim_icache_fetch(3337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_30, reg_r0_11, (unsigned int) -16); /* line 5162 */
   __ADD(reg_r0_31, reg_r0_10, (unsigned int) -16); /* line 5163 */
} /* line 5163 */
  sim_icache_fetch(3339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_32, reg_r0_9, (unsigned int) -16); /* line 5165 */
   __ADD(reg_r0_33, reg_r0_8, (unsigned int) -16); /* line 5166 */
} /* line 5166 */
  sim_icache_fetch(3341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_34, reg_r0_7, (unsigned int) -16); /* line 5168 */
   __ADD(reg_r0_35, reg_r0_6, (unsigned int) -16); /* line 5169 */
} /* line 5169 */
  sim_icache_fetch(3343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_36, reg_r0_5, (unsigned int) -16); /* line 5171 */
   __ADD(reg_r0_37, reg_r0_19, (unsigned int) -16); /* line 5172 */
} /* line 5172 */
  sim_icache_fetch(3345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_38, reg_r0_19); /* line 5174 */
   __ADD(reg_r0_39, reg_r0_3, (unsigned int) -16); /* line 5175 */
} /* line 5175 */
  sim_icache_fetch(3347 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5177 */
   __MOV(reg_r0_40, reg_r0_37); /* line 5178 */
} /* line 5178 */
  sim_icache_fetch(3350 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5180 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5181 */
  sim_icache_fetch(3352 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 5183 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5184 */
} /* line 5184 */
  sim_icache_fetch(3355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_0, reg_r0_12, ((unsigned int) htab + (unsigned int) 4096)); /* line 5186 */
} /* line 5186 */
  sim_icache_fetch(3357 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5188 */
} /* line 5188 */
  sim_icache_fetch(3358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5190 */
} /* line 5190 */
  sim_icache_fetch(3360 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_5); /* line 5192 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L205X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5193 */
  sim_icache_fetch(3362 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 5195 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5196 */
} /* line 5196 */
  sim_icache_fetch(3365 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_1, reg_r0_13, ((unsigned int) htab + (unsigned int) 4096)); /* line 5198 */
   __ADD(reg_r0_5, reg_r0_36, (unsigned int) -16); /* line 5199 */
} /* line 5199 */
  sim_icache_fetch(3368 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5201 */
} /* line 5201 */
  sim_icache_fetch(3369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5203 */
} /* line 5203 */
  sim_icache_fetch(3371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_6); /* line 5205 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5206 */
  sim_icache_fetch(3373 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_7, mem_trace_ld(reg_r0_7,0,1)); /* line 5208 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5209 */
} /* line 5209 */
  sim_icache_fetch(3376 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_2, reg_r0_14, ((unsigned int) htab + (unsigned int) 4096)); /* line 5211 */
   __ADD(reg_r0_6, reg_r0_35, (unsigned int) -16); /* line 5212 */
} /* line 5212 */
  sim_icache_fetch(3379 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5214 */
} /* line 5214 */
  sim_icache_fetch(3380 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5216 */
} /* line 5216 */
  sim_icache_fetch(3382 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_7); /* line 5218 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5219 */
  sim_icache_fetch(3384 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_8, mem_trace_ld(reg_r0_8,0,1)); /* line 5221 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5222 */
} /* line 5222 */
  sim_icache_fetch(3387 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_3, reg_r0_15, ((unsigned int) htab + (unsigned int) 4096)); /* line 5224 */
   __ADD(reg_r0_7, reg_r0_34, (unsigned int) -16); /* line 5225 */
} /* line 5225 */
  sim_icache_fetch(3390 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5227 */
} /* line 5227 */
  sim_icache_fetch(3391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5229 */
} /* line 5229 */
  sim_icache_fetch(3393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_8); /* line 5231 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5232 */
  sim_icache_fetch(3395 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_9, mem_trace_ld(reg_r0_9,0,1)); /* line 5234 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5235 */
} /* line 5235 */
  sim_icache_fetch(3398 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_4, reg_r0_16, ((unsigned int) htab + (unsigned int) 4096)); /* line 5237 */
   __ADD(reg_r0_8, reg_r0_33, (unsigned int) -16); /* line 5238 */
} /* line 5238 */
  sim_icache_fetch(3401 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5240 */
} /* line 5240 */
  sim_icache_fetch(3402 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5242 */
} /* line 5242 */
  sim_icache_fetch(3404 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_9); /* line 5244 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5245 */
  sim_icache_fetch(3406 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_10, mem_trace_ld(reg_r0_10,0,1)); /* line 5247 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5248 */
} /* line 5248 */
  sim_icache_fetch(3409 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_5, reg_r0_17, ((unsigned int) htab + (unsigned int) 4096)); /* line 5250 */
   __ADD(reg_r0_9, reg_r0_32, (unsigned int) -16); /* line 5251 */
} /* line 5251 */
  sim_icache_fetch(3412 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5253 */
} /* line 5253 */
  sim_icache_fetch(3413 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5255 */
} /* line 5255 */
  sim_icache_fetch(3415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_10); /* line 5257 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5258 */
  sim_icache_fetch(3417 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_11, mem_trace_ld(reg_r0_11,0,1)); /* line 5260 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5261 */
} /* line 5261 */
  sim_icache_fetch(3420 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_6, reg_r0_18, ((unsigned int) htab + (unsigned int) 4096)); /* line 5263 */
   __ADD(reg_r0_10, reg_r0_31, (unsigned int) -16); /* line 5264 */
} /* line 5264 */
  sim_icache_fetch(3423 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5266 */
} /* line 5266 */
  sim_icache_fetch(3424 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5268 */
} /* line 5268 */
  sim_icache_fetch(3426 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_11); /* line 5270 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5271 */
  sim_icache_fetch(3428 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 5273 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5274 */
} /* line 5274 */
  sim_icache_fetch(3431 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_7, reg_r0_38, ((unsigned int) htab + (unsigned int) 4096)); /* line 5276 */
   __ADD(reg_r0_11, reg_r0_30, (unsigned int) -16); /* line 5277 */
} /* line 5277 */
  sim_icache_fetch(3434 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5279 */
} /* line 5279 */
  sim_icache_fetch(3435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5281 */
} /* line 5281 */
  sim_icache_fetch(3437 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_12); /* line 5283 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5284 */
  sim_icache_fetch(3439 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_13, mem_trace_ld(reg_r0_13,0,1)); /* line 5286 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5287 */
} /* line 5287 */
  sim_icache_fetch(3442 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_0, reg_r0_3, ((unsigned int) htab + (unsigned int) 4096)); /* line 5289 */
   __ADD(reg_r0_12, reg_r0_29, (unsigned int) -16); /* line 5290 */
} /* line 5290 */
  sim_icache_fetch(3445 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5292 */
} /* line 5292 */
  sim_icache_fetch(3446 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5294 */
} /* line 5294 */
  sim_icache_fetch(3448 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_13); /* line 5296 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5297 */
  sim_icache_fetch(3450 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_14, mem_trace_ld(reg_r0_14,0,1)); /* line 5299 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5300 */
} /* line 5300 */
  sim_icache_fetch(3453 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_1, reg_r0_36, ((unsigned int) htab + (unsigned int) 4096)); /* line 5302 */
   __ADD(reg_r0_13, reg_r0_28, (unsigned int) -16); /* line 5303 */
} /* line 5303 */
  sim_icache_fetch(3456 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5305 */
} /* line 5305 */
  sim_icache_fetch(3457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5307 */
} /* line 5307 */
  sim_icache_fetch(3459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_14); /* line 5309 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5310 */
  sim_icache_fetch(3461 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 5312 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5313 */
} /* line 5313 */
  sim_icache_fetch(3464 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_2, reg_r0_35, ((unsigned int) htab + (unsigned int) 4096)); /* line 5315 */
   __ADD(reg_r0_14, reg_r0_27, (unsigned int) -16); /* line 5316 */
} /* line 5316 */
  sim_icache_fetch(3467 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5318 */
} /* line 5318 */
  sim_icache_fetch(3468 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5320 */
} /* line 5320 */
  sim_icache_fetch(3470 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_15); /* line 5322 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5323 */
  sim_icache_fetch(3472 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_16, mem_trace_ld(reg_r0_16,0,1)); /* line 5325 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5326 */
} /* line 5326 */
  sim_icache_fetch(3475 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_3, reg_r0_34, ((unsigned int) htab + (unsigned int) 4096)); /* line 5328 */
   __ADD(reg_r0_15, reg_r0_26, (unsigned int) -16); /* line 5329 */
} /* line 5329 */
  sim_icache_fetch(3478 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5331 */
} /* line 5331 */
  sim_icache_fetch(3479 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5333 */
} /* line 5333 */
  sim_icache_fetch(3481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_16); /* line 5335 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5336 */
  sim_icache_fetch(3483 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_17, mem_trace_ld(reg_r0_17,0,1)); /* line 5338 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5339 */
} /* line 5339 */
  sim_icache_fetch(3486 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_4, reg_r0_33, ((unsigned int) htab + (unsigned int) 4096)); /* line 5341 */
   __ADD(reg_r0_16, reg_r0_25, (unsigned int) -16); /* line 5342 */
} /* line 5342 */
  sim_icache_fetch(3489 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5344 */
} /* line 5344 */
  sim_icache_fetch(3490 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5346 */
} /* line 5346 */
  sim_icache_fetch(3492 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_17); /* line 5348 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5349 */
  sim_icache_fetch(3494 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_18, mem_trace_ld(reg_r0_18,0,1)); /* line 5351 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5352 */
} /* line 5352 */
  sim_icache_fetch(3497 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLEU(reg_b0_5, reg_r0_32, ((unsigned int) htab + (unsigned int) 4096)); /* line 5354 */
   __ADD(reg_r0_17, reg_r0_24, (unsigned int) -16); /* line 5355 */
} /* line 5355 */
  sim_icache_fetch(3500 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5357 */
} /* line 5357 */
  sim_icache_fetch(3501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5359 */
} /* line 5359 */
  sim_icache_fetch(3503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_18); /* line 5361 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5362 */
  sim_icache_fetch(3505 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_19, mem_trace_ld(reg_r0_19,0,1)); /* line 5364 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5365 */
} /* line 5365 */
  sim_icache_fetch(3508 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) -16); /* line 5367 */
   __CMPLEU(reg_b0_6, reg_r0_31, ((unsigned int) htab + (unsigned int) 4096)); /* line 5368 */
} /* line 5368 */
  sim_icache_fetch(3511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5370 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) -16); /* line 5371 */
} /* line 5371 */
  sim_icache_fetch(3513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5373 */
} /* line 5373 */
  sim_icache_fetch(3515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_19); /* line 5375 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5376 */
  sim_icache_fetch(3517 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_4, mem_trace_ld(reg_r0_3,0,1)); /* line 5378 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5379 */
} /* line 5379 */
  sim_icache_fetch(3520 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_21, reg_r0_3); /* line 5381 */
   __CMPLEU(reg_b0_7, reg_r0_30, ((unsigned int) htab + (unsigned int) 4096)); /* line 5382 */
} /* line 5382 */
  sim_icache_fetch(3523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_22, reg_r0_2, (unsigned int) 1); /* line 5384 */
   __ADD(reg_r0_19, reg_r0_37, (unsigned int) -16); /* line 5385 */
} /* line 5385 */
  sim_icache_fetch(3525 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_22); /* line 5387 */
   __MOV(reg_r0_3, reg_r0_39); /* line 5388 */
} /* line 5388 */
  sim_icache_fetch(3528 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_4); /* line 5390 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L204X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5391 */
  sim_icache_fetch(3530 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_36, mem_trace_ld(reg_r0_36,0,1)); /* line 5393 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5394 */
} /* line 5394 */
  sim_icache_fetch(3533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_0, reg_r0_29, ((unsigned int) htab + (unsigned int) 4096)); /* line 5396 */
} /* line 5396 */
  sim_icache_fetch(3535 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5398 */
} /* line 5398 */
  sim_icache_fetch(3536 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5400 */
} /* line 5400 */
  sim_icache_fetch(3538 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_36); /* line 5402 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L205X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5403 */
  sim_icache_fetch(3540 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_35, mem_trace_ld(reg_r0_35,0,1)); /* line 5405 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5406 */
} /* line 5406 */
  sim_icache_fetch(3543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_1, reg_r0_28, ((unsigned int) htab + (unsigned int) 4096)); /* line 5408 */
} /* line 5408 */
  sim_icache_fetch(3545 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5410 */
} /* line 5410 */
  sim_icache_fetch(3546 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5412 */
} /* line 5412 */
  sim_icache_fetch(3548 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_35); /* line 5414 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L206X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5415 */
  sim_icache_fetch(3550 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_34, mem_trace_ld(reg_r0_34,0,1)); /* line 5417 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5418 */
} /* line 5418 */
  sim_icache_fetch(3553 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_2, reg_r0_27, ((unsigned int) htab + (unsigned int) 4096)); /* line 5420 */
} /* line 5420 */
  sim_icache_fetch(3555 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5422 */
} /* line 5422 */
  sim_icache_fetch(3556 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5424 */
} /* line 5424 */
  sim_icache_fetch(3558 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_34); /* line 5426 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L207X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5427 */
  sim_icache_fetch(3560 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_33, mem_trace_ld(reg_r0_33,0,1)); /* line 5429 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5430 */
} /* line 5430 */
  sim_icache_fetch(3563 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_3, reg_r0_26, ((unsigned int) htab + (unsigned int) 4096)); /* line 5432 */
} /* line 5432 */
  sim_icache_fetch(3565 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5434 */
} /* line 5434 */
  sim_icache_fetch(3566 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5436 */
} /* line 5436 */
  sim_icache_fetch(3568 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_33); /* line 5438 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L208X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5439 */
  sim_icache_fetch(3570 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_32, mem_trace_ld(reg_r0_32,0,1)); /* line 5441 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5442 */
} /* line 5442 */
  sim_icache_fetch(3573 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_4, reg_r0_25, ((unsigned int) htab + (unsigned int) 4096)); /* line 5444 */
} /* line 5444 */
  sim_icache_fetch(3575 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5446 */
} /* line 5446 */
  sim_icache_fetch(3576 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5448 */
} /* line 5448 */
  sim_icache_fetch(3578 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_32); /* line 5450 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L209X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5451 */
  sim_icache_fetch(3580 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_31, mem_trace_ld(reg_r0_31,0,1)); /* line 5453 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5454 */
} /* line 5454 */
  sim_icache_fetch(3583 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_5, reg_r0_24, ((unsigned int) htab + (unsigned int) 4096)); /* line 5456 */
} /* line 5456 */
  sim_icache_fetch(3585 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5458 */
} /* line 5458 */
  sim_icache_fetch(3586 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5460 */
} /* line 5460 */
  sim_icache_fetch(3588 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_31); /* line 5462 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L210X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5463 */
  sim_icache_fetch(3590 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_30, mem_trace_ld(reg_r0_30,0,1)); /* line 5465 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5466 */
} /* line 5466 */
  sim_icache_fetch(3593 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_6, reg_r0_23, ((unsigned int) htab + (unsigned int) 4096)); /* line 5468 */
} /* line 5468 */
  sim_icache_fetch(3595 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5470 */
} /* line 5470 */
  sim_icache_fetch(3596 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5472 */
} /* line 5472 */
  sim_icache_fetch(3598 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_30); /* line 5474 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L211X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5475 */
  sim_icache_fetch(3600 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_29, mem_trace_ld(reg_r0_29,0,1)); /* line 5477 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5478 */
} /* line 5478 */
  sim_icache_fetch(3603 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLEU(reg_b0_7, reg_r0_40, ((unsigned int) htab + (unsigned int) 4096)); /* line 5480 */
} /* line 5480 */
  sim_icache_fetch(3605 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5482 */
} /* line 5482 */
  sim_icache_fetch(3606 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5484 */
} /* line 5484 */
  sim_icache_fetch(3608 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_29); /* line 5486 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L212X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5487 */
  sim_icache_fetch(3610 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_28, mem_trace_ld(reg_r0_28,0,1)); /* line 5489 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5490 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5491 */
   __ADD_CYCLES(1);
} /* line 5491 */
  sim_icache_fetch(3614 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5493 */
} /* line 5493 */
  sim_icache_fetch(3615 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5495 */
} /* line 5495 */
  sim_icache_fetch(3617 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_28); /* line 5497 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L213X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5498 */
  sim_icache_fetch(3619 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_27, mem_trace_ld(reg_r0_27,0,1)); /* line 5500 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5501 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5502 */
   __ADD_CYCLES(1);
} /* line 5502 */
  sim_icache_fetch(3623 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5504 */
} /* line 5504 */
  sim_icache_fetch(3624 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5506 */
} /* line 5506 */
  sim_icache_fetch(3626 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_27); /* line 5508 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L214X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5509 */
  sim_icache_fetch(3628 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_26, mem_trace_ld(reg_r0_26,0,1)); /* line 5511 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5512 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5513 */
   __ADD_CYCLES(1);
} /* line 5513 */
  sim_icache_fetch(3632 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5515 */
} /* line 5515 */
  sim_icache_fetch(3633 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5517 */
} /* line 5517 */
  sim_icache_fetch(3635 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_26); /* line 5519 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L215X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5520 */
  sim_icache_fetch(3637 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_25, mem_trace_ld(reg_r0_25,0,1)); /* line 5522 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5523 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5524 */
   __ADD_CYCLES(1);
} /* line 5524 */
  sim_icache_fetch(3641 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5526 */
} /* line 5526 */
  sim_icache_fetch(3642 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5528 */
} /* line 5528 */
  sim_icache_fetch(3644 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_25); /* line 5530 */
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L216X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5531 */
  sim_icache_fetch(3646 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_24, mem_trace_ld(reg_r0_24,0,1)); /* line 5533 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5534 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5535 */
   __ADD_CYCLES(1);
} /* line 5535 */
  sim_icache_fetch(3650 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5537 */
} /* line 5537 */
  sim_icache_fetch(3651 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5539 */
} /* line 5539 */
  sim_icache_fetch(3653 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_24); /* line 5541 */
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L217X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5542 */
  sim_icache_fetch(3655 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_23, mem_trace_ld(reg_r0_23,0,1)); /* line 5544 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5545 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5546 */
   __ADD_CYCLES(1);
} /* line 5546 */
  sim_icache_fetch(3659 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5548 */
} /* line 5548 */
  sim_icache_fetch(3660 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5550 */
} /* line 5550 */
  sim_icache_fetch(3662 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_23); /* line 5552 */
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L218X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5553 */
  sim_icache_fetch(3664 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_37, mem_trace_ld(reg_r0_37,0,1)); /* line 5555 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) outbuf,0,4)); /* line 5556 */
} /* line 5556 */
  sim_icache_fetch(3667 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) -16); /* line 5558 */
} /* line 5558 */
  sim_icache_fetch(3668 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5560 */
} /* line 5560 */
  sim_icache_fetch(3669 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) outbuf,0,4), reg_r0_4); /* line 5562 */
} /* line 5562 */
  sim_icache_fetch(3671 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_2,0,1), reg_r0_37); /* line 5564 */
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L219X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5566 */
  sim_icache_fetch(3673 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L203X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L203X3;
} /* line 5568 */
l_L219X3: ;/* line 5571 */
__LABEL(l_L219X3);
  sim_icache_fetch(3674 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_21, (unsigned int) -15); /* line 5572 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5574 */
} /* line 5574 */
  sim_icache_fetch(3677 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5576 */
l_L222X3: ;/* line 5579 */
__LABEL(l_L222X3);
  sim_icache_fetch(3678 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 5580 */
   __SH1ADD(reg_r0_3, reg_r0_2, (unsigned int) codetab); /* line 5581 */
} /* line 5581 */
  sim_icache_fetch(3681 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STH(mem_trace_st(reg_r0_3,0,2), reg_r0_59); /* line 5583 */
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_4); /* line 5584 */
} /* line 5584 */
  sim_icache_fetch(3684 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_2 + (unsigned int) htab),0,1), reg_r0_57); /* line 5586 */
   __GOTO(l_L221X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L221X3;
} /* line 5587 */
l_L218X3: ;/* line 5590 */
__LABEL(l_L218X3);
  sim_icache_fetch(3687 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -15); /* line 5591 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5593 */
} /* line 5593 */
  sim_icache_fetch(3690 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5595 */
l_L217X3: ;/* line 5598 */
__LABEL(l_L217X3);
  sim_icache_fetch(3691 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -14); /* line 5599 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5601 */
} /* line 5601 */
  sim_icache_fetch(3694 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5603 */
l_L216X3: ;/* line 5606 */
__LABEL(l_L216X3);
  sim_icache_fetch(3695 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -13); /* line 5607 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5609 */
} /* line 5609 */
  sim_icache_fetch(3698 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5611 */
l_L215X3: ;/* line 5614 */
__LABEL(l_L215X3);
  sim_icache_fetch(3699 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -12); /* line 5615 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5617 */
} /* line 5617 */
  sim_icache_fetch(3702 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5619 */
l_L214X3: ;/* line 5622 */
__LABEL(l_L214X3);
  sim_icache_fetch(3703 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -11); /* line 5623 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5625 */
} /* line 5625 */
  sim_icache_fetch(3706 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5627 */
l_L213X3: ;/* line 5630 */
__LABEL(l_L213X3);
  sim_icache_fetch(3707 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -10); /* line 5631 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5633 */
} /* line 5633 */
  sim_icache_fetch(3710 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5635 */
l_L212X3: ;/* line 5638 */
__LABEL(l_L212X3);
  sim_icache_fetch(3711 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -9); /* line 5639 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5641 */
} /* line 5641 */
  sim_icache_fetch(3714 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5643 */
l_L211X3: ;/* line 5646 */
__LABEL(l_L211X3);
  sim_icache_fetch(3715 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -8); /* line 5647 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5649 */
} /* line 5649 */
  sim_icache_fetch(3718 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5651 */
l_L210X3: ;/* line 5654 */
__LABEL(l_L210X3);
  sim_icache_fetch(3719 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -7); /* line 5655 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5657 */
} /* line 5657 */
  sim_icache_fetch(3722 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5659 */
l_L209X3: ;/* line 5662 */
__LABEL(l_L209X3);
  sim_icache_fetch(3723 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -6); /* line 5663 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5665 */
} /* line 5665 */
  sim_icache_fetch(3726 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5667 */
l_L208X3: ;/* line 5670 */
__LABEL(l_L208X3);
  sim_icache_fetch(3727 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -5); /* line 5671 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5673 */
} /* line 5673 */
  sim_icache_fetch(3730 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5675 */
l_L207X3: ;/* line 5678 */
__LABEL(l_L207X3);
  sim_icache_fetch(3731 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -4); /* line 5679 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5681 */
} /* line 5681 */
  sim_icache_fetch(3734 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5683 */
l_L206X3: ;/* line 5686 */
__LABEL(l_L206X3);
  sim_icache_fetch(3735 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -3); /* line 5687 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5689 */
} /* line 5689 */
  sim_icache_fetch(3738 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5691 */
l_L205X3: ;/* line 5694 */
__LABEL(l_L205X3);
  sim_icache_fetch(3739 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -2); /* line 5695 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5697 */
} /* line 5697 */
  sim_icache_fetch(3742 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L220X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L220X3;
} /* line 5699 */
l_L204X3: ;/* line 5702 */
__LABEL(l_L204X3);
  sim_icache_fetch(3743 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_58, reg_r0_20, (unsigned int) -1); /* line 5703 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5704 */
} /* line 5704 */
l_L220X3: ;/* line 5706 */
__LABEL(l_L220X3);
  sim_icache_fetch(3746 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5707 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 5708 */
   __ADD_CYCLES(1);
} /* line 5708 */
  sim_icache_fetch(3749 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_2, reg_r0_3); /* line 5710 */
} /* line 5710 */
  sim_icache_fetch(3750 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L222X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5712 */
l_L221X3: ;/* line 5714 */
__LABEL(l_L221X3);
  sim_icache_fetch(3751 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_59, reg_r0_41); /* line 5715 */
   __GOTO(l_L178X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L178X3;
} /* line 5716 */
l_L200X3: ;/* line 5719 */
__LABEL(l_L200X3);
  sim_icache_fetch(3753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 5720 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5722 */
} /* line 5722 */
  sim_icache_fetch(3755 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5724 */
l_L199X3: ;/* line 5727 */
__LABEL(l_L199X3);
  sim_icache_fetch(3756 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 13); /* line 5728 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5730 */
} /* line 5730 */
  sim_icache_fetch(3758 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5732 */
l_L198X3: ;/* line 5735 */
__LABEL(l_L198X3);
  sim_icache_fetch(3759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 12); /* line 5736 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5738 */
} /* line 5738 */
  sim_icache_fetch(3761 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5740 */
l_L197X3: ;/* line 5743 */
__LABEL(l_L197X3);
  sim_icache_fetch(3762 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 11); /* line 5744 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5746 */
} /* line 5746 */
  sim_icache_fetch(3764 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5748 */
l_L196X3: ;/* line 5751 */
__LABEL(l_L196X3);
  sim_icache_fetch(3765 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 10); /* line 5752 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5754 */
} /* line 5754 */
  sim_icache_fetch(3767 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5756 */
l_L195X3: ;/* line 5759 */
__LABEL(l_L195X3);
  sim_icache_fetch(3768 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 9); /* line 5760 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5762 */
} /* line 5762 */
  sim_icache_fetch(3770 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5764 */
l_L194X3: ;/* line 5767 */
__LABEL(l_L194X3);
  sim_icache_fetch(3771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 5768 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5770 */
} /* line 5770 */
  sim_icache_fetch(3773 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5772 */
l_L193X3: ;/* line 5775 */
__LABEL(l_L193X3);
  sim_icache_fetch(3774 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 5776 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5778 */
} /* line 5778 */
  sim_icache_fetch(3776 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5780 */
l_L192X3: ;/* line 5783 */
__LABEL(l_L192X3);
  sim_icache_fetch(3777 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 6); /* line 5784 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5786 */
} /* line 5786 */
  sim_icache_fetch(3779 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5788 */
l_L191X3: ;/* line 5791 */
__LABEL(l_L191X3);
  sim_icache_fetch(3780 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 5); /* line 5792 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5794 */
} /* line 5794 */
  sim_icache_fetch(3782 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5796 */
l_L190X3: ;/* line 5799 */
__LABEL(l_L190X3);
  sim_icache_fetch(3783 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 5800 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5802 */
} /* line 5802 */
  sim_icache_fetch(3785 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5804 */
l_L189X3: ;/* line 5807 */
__LABEL(l_L189X3);
  sim_icache_fetch(3786 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 3); /* line 5808 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5810 */
} /* line 5810 */
  sim_icache_fetch(3788 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5812 */
l_L188X3: ;/* line 5815 */
__LABEL(l_L188X3);
  sim_icache_fetch(3789 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 2); /* line 5816 */
   __MOV(reg_r0_2, reg_r0_7); /* line 5818 */
} /* line 5818 */
  sim_icache_fetch(3791 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5820 */
l_L187X3: ;/* line 5823 */
__LABEL(l_L187X3);
  sim_icache_fetch(3792 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 5824 */
   __MOV(reg_r0_2, reg_r0_6); /* line 5826 */
} /* line 5826 */
  sim_icache_fetch(3794 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L202X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L202X3;
} /* line 5828 */
l_L186X3: ;/* line 5833 */
__LABEL(l_L186X3);
  sim_icache_fetch(3795 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 5833 */
l_L202X3: ;/* line 5835 */
__LABEL(l_L202X3);
  sim_icache_fetch(3796 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_57, mem_trace_ld((reg_r0_2 + (unsigned int) htab),0,1)); /* line 5836 */
   __ADD(reg_r0_19, reg_r0_5, (unsigned int) -15); /* line 5837 */
} /* line 5837 */
  sim_icache_fetch(3799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) -14); /* line 5839 */
   __ADD(reg_r0_17, reg_r0_5, (unsigned int) -13); /* line 5840 */
} /* line 5840 */
  sim_icache_fetch(3801 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_16, reg_r0_5, (unsigned int) -12); /* line 5842 */
   __ADD(reg_r0_15, reg_r0_5, (unsigned int) -11); /* line 5843 */
} /* line 5843 */
  sim_icache_fetch(3803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) -10); /* line 5845 */
   __ADD(reg_r0_13, reg_r0_5, (unsigned int) -9); /* line 5846 */
} /* line 5846 */
  sim_icache_fetch(3805 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) -8); /* line 5848 */
   __ADD(reg_r0_11, reg_r0_5, (unsigned int) -7); /* line 5849 */
} /* line 5849 */
  sim_icache_fetch(3807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) -6); /* line 5851 */
   __ADD(reg_r0_9, reg_r0_5, (unsigned int) -5); /* line 5852 */
} /* line 5852 */
  sim_icache_fetch(3809 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -3); /* line 5854 */
   __ADD(reg_r0_6, reg_r0_5, (unsigned int) -2); /* line 5855 */
} /* line 5855 */
  sim_icache_fetch(3811 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -1); /* line 5857 */
   __MOV(reg_r0_41, reg_r0_8); /* line 5858 */
} /* line 5858 */
  sim_icache_fetch(3813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_20, reg_r0_5, (unsigned int) 1); /* line 5860 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) -4); /* line 5861 */
} /* line 5861 */
  sim_icache_fetch(3815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st(reg_r0_5,0,1), reg_r0_57); /* line 5863 */
   __MOV(reg_r0_3, reg_r0_5); /* line 5864 */
} /* line 5864 */
  sim_icache_fetch(3817 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_2); /* line 5866 */
   __GOTO(l_L203X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L203X3;
} /* line 5867 */
l_L184X3: ;/* line 5870 */
__LABEL(l_L184X3);
  sim_icache_fetch(3819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, reg_r0_58); /* line 5871 */
   __GOTO(l_L185X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L185X3;
} /* line 5872 */
l_L183X3: ;/* line 5875 */
__LABEL(l_L183X3);
  sim_icache_fetch(3821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5876 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5877 */
} /* line 5877 */
  sim_icache_fetch(3823 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5879 */
   __MOV(reg_r0_3, 0); /* line 5880 */
} /* line 5880 */
  sim_icache_fetch(3825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5882 */
   __GOTO(l_L223X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L223X3;
} /* line 5883 */
l_L179X3: ;/* line 5886 */
__LABEL(l_L179X3);
  sim_icache_fetch(3827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 5887 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 5888 */
} /* line 5888 */
  sim_icache_fetch(3829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 5890 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 5891 */
} /* line 5891 */
  sim_icache_fetch(3831 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 5893 */
} /* line 5893 */
l_L223X3: ;/* line 5895 */
__LABEL(l_L223X3);
  sim_icache_fetch(3832 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(decompress);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 5897 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 341: goto l_L175X3;
    case 342: goto l_L176X3;
    case 344: goto l_lr_243;
    case 345: goto l_L177X3;
    case 346: goto l_L178X3;
    case 348: goto l_lr_247;
    case 349: goto l_L181X3;
    case 350: goto l_L182X3;
    case 352: goto l_lr_251;
    case 353: goto l_L180X3;
    case 354: goto l_L185X3;
    case 355: goto l_L201X3;
    case 356: goto l_L203X3;
    case 357: goto l_L219X3;
    case 358: goto l_L222X3;
    case 359: goto l_L218X3;
    case 360: goto l_L217X3;
    case 361: goto l_L216X3;
    case 362: goto l_L215X3;
    case 363: goto l_L214X3;
    case 364: goto l_L213X3;
    case 365: goto l_L212X3;
    case 366: goto l_L211X3;
    case 367: goto l_L210X3;
    case 368: goto l_L209X3;
    case 369: goto l_L208X3;
    case 370: goto l_L207X3;
    case 371: goto l_L206X3;
    case 372: goto l_L205X3;
    case 373: goto l_L204X3;
    case 374: goto l_L220X3;
    case 375: goto l_L221X3;
    case 376: goto l_L200X3;
    case 377: goto l_L199X3;
    case 378: goto l_L198X3;
    case 379: goto l_L197X3;
    case 380: goto l_L196X3;
    case 381: goto l_L195X3;
    case 382: goto l_L194X3;
    case 383: goto l_L193X3;
    case 384: goto l_L192X3;
    case 385: goto l_L191X3;
    case 386: goto l_L190X3;
    case 387: goto l_L189X3;
    case 388: goto l_L188X3;
    case 389: goto l_L187X3;
    case 390: goto l_L186X3;
    case 391: goto l_L202X3;
    case 392: goto l_L184X3;
    case 393: goto l_L183X3;
    case 394: goto l_L179X3;
    case 395: goto l_L223X3;
    case 396:
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
  reg_l0_0 = (433 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(3833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) maxbits,0,4)); /* line 5916 */
} /* line 5916 */
  sim_icache_fetch(3835 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) maxmaxcode,0,4)); /* line 5918 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5919 */
} /* line 5919 */
  sim_icache_fetch(3839 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) free_ent,0,4)); /* line 5921 */
   __LDW(reg_r0_6, mem_trace_ld((unsigned int) maxcode,0,4)); /* line 5922 */
} /* line 5922 */
  sim_icache_fetch(3843 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_7, mem_trace_ld((unsigned int) _X1PACKETX13,0,4)); /* line 5924 */
   __CMPGT(reg_r0_4, reg_r0_4, 0); /* line 5925 */
} /* line 5925 */
  sim_icache_fetch(3846 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_9, mem_trace_ld((unsigned int) _X1PACKETX14,0,4)); /* line 5927 */
   __CMPGT(reg_r0_8, reg_r0_5, reg_r0_6); /* line 5928 */
} /* line 5928 */
  sim_icache_fetch(3849 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ORL(reg_r0_4, reg_r0_4, reg_r0_8); /* line 5930 */
   __CMPGT(reg_b0_0, reg_r0_5, reg_r0_6); /* line 5931 */
} /* line 5931 */
  sim_icache_fetch(3851 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_r0_5, reg_r0_7, reg_r0_9); /* line 5933 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5934 */
} /* line 5934 */
  sim_icache_fetch(3854 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ORL(reg_b0_1, reg_r0_4, reg_r0_5); /* line 5936 */
} /* line 5936 */
  sim_icache_fetch(3855 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 1); /* line 5938 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L224X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5939 */
  sim_icache_fetch(3857 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPEQ(reg_b0_0, reg_r0_6, reg_r0_2); /* line 5941 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L225X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5942 */
  sim_icache_fetch(3859 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_6); /* line 5944 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L226X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5945 */
  sim_icache_fetch(3862 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 5947 */
} /* line 5947 */
l_L225X3: ;/* line 5950 */
__LABEL(l_L225X3);
  sim_icache_fetch(3864 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) clear_flg,0,4)); /* line 5951 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 5952 */
} /* line 5952 */
  sim_icache_fetch(3868 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, 0); /* line 5954 */
   __MOV(reg_r0_19, reg_r0_7); /* line 5955 */
} /* line 5955 */
  sim_icache_fetch(3870 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 5957 */
   __SUB(reg_r0_6, 0, reg_r0_5); /* line 5958 */
} /* line 5958 */
  sim_icache_fetch(3872 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 5960 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L227X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5961 */
l_L228X3: ;/* line 5963 */
__LABEL(l_L228X3);
  sim_icache_fetch(3874 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_20, reg_r0_5); /* line 5964 */
} /* line 5964 */
l_L229X3: ;/* line 5967 */
__LABEL(l_L229X3);
  sim_icache_fetch(3875 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 5968 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 5969 */
} /* line 5969 */
  sim_icache_fetch(3878 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 5971 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L230X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 5972 */
  sim_icache_fetch(3881 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 5974 */
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) 1); /* line 5975 */
} /* line 5975 */
  sim_icache_fetch(3883 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 5977 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) 1); /* line 5978 */
} /* line 5978 */
  sim_icache_fetch(3885 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_6, 0); /* line 5980 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 5981 */
} /* line 5981 */
  sim_icache_fetch(3887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_2, reg_r0_8, 0); /* line 5983 */
   __ADD(reg_r0_9, reg_r0_8, (unsigned int) 1); /* line 5984 */
} /* line 5984 */
  sim_icache_fetch(3889 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_3, reg_r0_9, 0); /* line 5986 */
   __ADD(reg_r0_10, reg_r0_9, (unsigned int) 1); /* line 5987 */
} /* line 5987 */
  sim_icache_fetch(3891 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_4, reg_r0_10, 0); /* line 5989 */
   __ADD(reg_r0_11, reg_r0_10, (unsigned int) 1); /* line 5990 */
} /* line 5990 */
  sim_icache_fetch(3893 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_5, reg_r0_11, 0); /* line 5992 */
   __ADD(reg_r0_12, reg_r0_11, (unsigned int) 1); /* line 5993 */
} /* line 5993 */
  sim_icache_fetch(3895 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_6, reg_r0_12, 0); /* line 5995 */
   __ADD(reg_r0_13, reg_r0_12, (unsigned int) 1); /* line 5996 */
} /* line 5996 */
  sim_icache_fetch(3897 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_7, reg_r0_13, 0); /* line 5998 */
   __ADD(reg_r0_14, reg_r0_13, (unsigned int) 1); /* line 5999 */
} /* line 5999 */
  sim_icache_fetch(3899 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6001 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L231X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6002 */
  sim_icache_fetch(3902 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6004 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 6005 */
} /* line 6005 */
  sim_icache_fetch(3905 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 6007 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6008 */
} /* line 6008 */
  sim_icache_fetch(3908 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 6010 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6011 */
} /* line 6011 */
  sim_icache_fetch(3910 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6013 */
   __MFB(reg_r0_7, reg_b0_0); /* line 6014 */
} /* line 6014 */
  sim_icache_fetch(3913 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 6016 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6017 */
} /* line 6017 */
l_L232X3: ;/* line 6019 */
__LABEL(l_L232X3);
  sim_icache_fetch(3915 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_5); /* line 6020 */
   __ADD(reg_r0_17, reg_r0_15, (unsigned int) 1); /* line 6021 */
} /* line 6021 */
  sim_icache_fetch(3917 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 6023 */
   __MFB(reg_r0_18, reg_b0_7); /* line 6024 */
} /* line 6024 */
  sim_icache_fetch(3920 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_7, reg_r0_16, (unsigned int) 255); /* line 6026 */
} /* line 6026 */
  sim_icache_fetch(3921 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_7, reg_r0_18); /* line 6028 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6029 */
  sim_icache_fetch(3923 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6031 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L234X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6032 */
  sim_icache_fetch(3925 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6034 */
   __MTB(reg_b0_1, reg_r0_7); /* line 6035 */
} /* line 6035 */
  sim_icache_fetch(3928 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6037 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L235X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6038 */
  sim_icache_fetch(3931 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_17); /* line 6040 */
} /* line 6040 */
  sim_icache_fetch(3933 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_15, mem_trace_ld(reg_r0_15,0,1)); /* line 6042 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6043 */
} /* line 6043 */
  sim_icache_fetch(3935 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6045 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6046 */
} /* line 6046 */
  sim_icache_fetch(3938 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_15, reg_r0_15); /* line 6048 */
} /* line 6048 */
l_L236X3: ;/* line 6050 */
__LABEL(l_L236X3);
  sim_icache_fetch(3939 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_6, reg_r0_15); /* line 6051 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) 1); /* line 6052 */
} /* line 6052 */
  sim_icache_fetch(3941 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_15); /* line 6054 */
   __MFB(reg_r0_16, reg_b0_1); /* line 6055 */
} /* line 6055 */
  sim_icache_fetch(3944 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_1, reg_r0_6, (unsigned int) 255); /* line 6057 */
} /* line 6057 */
  sim_icache_fetch(3945 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MTB(reg_b0_1, reg_r0_16); /* line 6059 */
   if (t__i32_0) {    __BRANCH(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6060 */
  sim_icache_fetch(3947 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6062 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L237X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6063 */
  sim_icache_fetch(3949 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6065 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L238X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6066 */
  sim_icache_fetch(3952 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_7); /* line 6068 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6069 */
} /* line 6069 */
  sim_icache_fetch(3956 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 6071 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6072 */
} /* line 6072 */
  sim_icache_fetch(3959 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6074 */
} /* line 6074 */
  sim_icache_fetch(3960 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 6076 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6077 */
} /* line 6077 */
l_L239X3: ;/* line 6079 */
__LABEL(l_L239X3);
  sim_icache_fetch(3962 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_7, reg_r0_5); /* line 6080 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 6081 */
} /* line 6081 */
  sim_icache_fetch(3964 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 6083 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 255); /* line 6084 */
} /* line 6084 */
  sim_icache_fetch(3967 + t_thisfile.offset, 1);
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
} /* line 6086 */
  sim_icache_fetch(3968 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6088 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L240X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6089 */
  sim_icache_fetch(3970 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6091 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L241X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6092 */
  sim_icache_fetch(3973 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 6094 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6095 */
} /* line 6095 */
  sim_icache_fetch(3977 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 6097 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6098 */
} /* line 6098 */
  sim_icache_fetch(3980 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6100 */
} /* line 6100 */
  sim_icache_fetch(3981 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 6102 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6103 */
} /* line 6103 */
l_L242X3: ;/* line 6105 */
__LABEL(l_L242X3);
  sim_icache_fetch(3983 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_7, reg_r0_6); /* line 6106 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) 1); /* line 6107 */
} /* line 6107 */
  sim_icache_fetch(3985 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 6109 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 255); /* line 6110 */
} /* line 6110 */
  sim_icache_fetch(3988 + t_thisfile.offset, 1);
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
} /* line 6112 */
  sim_icache_fetch(3989 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6114 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L243X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6115 */
  sim_icache_fetch(3991 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6117 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L244X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6118 */
  sim_icache_fetch(3994 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 6120 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6121 */
} /* line 6121 */
  sim_icache_fetch(3998 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 6123 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6124 */
} /* line 6124 */
  sim_icache_fetch(4001 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6126 */
} /* line 6126 */
  sim_icache_fetch(4002 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 6128 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6129 */
} /* line 6129 */
l_L245X3: ;/* line 6131 */
__LABEL(l_L245X3);
  sim_icache_fetch(4004 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_7, reg_r0_5); /* line 6132 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 6133 */
} /* line 6133 */
  sim_icache_fetch(4006 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 6135 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 255); /* line 6136 */
} /* line 6136 */
  sim_icache_fetch(4009 + t_thisfile.offset, 1);
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
} /* line 6138 */
  sim_icache_fetch(4010 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6140 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L246X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6141 */
  sim_icache_fetch(4012 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6143 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L247X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6144 */
  sim_icache_fetch(4015 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 6146 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6147 */
} /* line 6147 */
  sim_icache_fetch(4019 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 6149 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6150 */
} /* line 6150 */
  sim_icache_fetch(4022 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6152 */
} /* line 6152 */
  sim_icache_fetch(4023 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 6154 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6155 */
} /* line 6155 */
l_L248X3: ;/* line 6157 */
__LABEL(l_L248X3);
  sim_icache_fetch(4025 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_7, reg_r0_6); /* line 6158 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) 1); /* line 6159 */
} /* line 6159 */
  sim_icache_fetch(4027 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 6161 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 255); /* line 6162 */
} /* line 6162 */
  sim_icache_fetch(4030 + t_thisfile.offset, 1);
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
} /* line 6164 */
  sim_icache_fetch(4031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6166 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L249X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6167 */
  sim_icache_fetch(4033 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6169 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L250X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6170 */
  sim_icache_fetch(4036 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 6172 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6173 */
} /* line 6173 */
  sim_icache_fetch(4040 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 6175 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6176 */
} /* line 6176 */
  sim_icache_fetch(4043 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6178 */
} /* line 6178 */
  sim_icache_fetch(4044 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 6180 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6181 */
} /* line 6181 */
l_L251X3: ;/* line 6183 */
__LABEL(l_L251X3);
  sim_icache_fetch(4046 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_7, reg_r0_5); /* line 6184 */
   __ADD(reg_r0_8, reg_r0_6, (unsigned int) 1); /* line 6185 */
} /* line 6185 */
  sim_icache_fetch(4048 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 6187 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 255); /* line 6188 */
} /* line 6188 */
  sim_icache_fetch(4051 + t_thisfile.offset, 1);
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
} /* line 6190 */
  sim_icache_fetch(4052 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6192 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L252X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6193 */
  sim_icache_fetch(4054 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6195 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L253X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6196 */
  sim_icache_fetch(4057 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 6198 */
   __LDWs(reg_r0_2, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6199 */
} /* line 6199 */
  sim_icache_fetch(4061 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDB(reg_r0_6, mem_trace_ld(reg_r0_6,0,1)); /* line 6201 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6202 */
} /* line 6202 */
  sim_icache_fetch(4064 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6204 */
} /* line 6204 */
  sim_icache_fetch(4065 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 6206 */
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6207 */
} /* line 6207 */
l_L254X3: ;/* line 6209 */
__LABEL(l_L254X3);
  sim_icache_fetch(4067 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_7, reg_r0_6); /* line 6210 */
   __ADD(reg_r0_8, reg_r0_5, (unsigned int) 1); /* line 6211 */
} /* line 6211 */
  sim_icache_fetch(4069 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_6); /* line 6213 */
   __CMPEQ(reg_b0_2, reg_r0_7, (unsigned int) 255); /* line 6214 */
} /* line 6214 */
  sim_icache_fetch(4072 + t_thisfile.offset, 1);
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
} /* line 6216 */
  sim_icache_fetch(4073 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6218 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L255X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6219 */
  sim_icache_fetch(4075 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) buflen,0,4), reg_r0_2); /* line 6221 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L256X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6222 */
  sim_icache_fetch(4078 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((unsigned int) bufp,0,4), reg_r0_8); /* line 6224 */
} /* line 6224 */
  sim_icache_fetch(4080 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDB(reg_r0_5, mem_trace_ld(reg_r0_5,0,1)); /* line 6226 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6227 */
   __ADD_CYCLES(1);
} /* line 6227 */
  sim_icache_fetch(4082 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ZXTB(reg_r0_5, reg_r0_5); /* line 6229 */
} /* line 6229 */
l_L257X3: ;/* line 6231 */
__LABEL(l_L257X3);
  sim_icache_fetch(4083 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_2, reg_r0_5); /* line 6232 */
   __STB(mem_trace_st((reg_r0_4 + (unsigned int) _X1PACKETX15),0,1), reg_r0_5); /* line 6233 */
} /* line 6233 */
  sim_icache_fetch(4086 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 255); /* line 6235 */
} /* line 6235 */
  sim_icache_fetch(4087 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L233X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6237 */
  sim_icache_fetch(4088 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 6239 */
   __GOTO(l_L229X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L229X3;
} /* line 6240 */
l_L233X3: ;/* line 6243 */
__LABEL(l_L233X3);
  sim_icache_fetch(4090 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_20, reg_r0_4); /* line 6244 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6246 */
} /* line 6246 */
  sim_icache_fetch(4092 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6248 */
l_L259X3: ;/* line 6251 */
__LABEL(l_L259X3);
  sim_icache_fetch(4093 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6252 */
   __SHL(reg_r0_20, reg_r0_20, (unsigned int) 3); /* line 6253 */
} /* line 6253 */
  sim_icache_fetch(4096 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_7, 0); /* line 6255 */
   __ADD(reg_r0_20, reg_r0_20, (unsigned int) 1); /* line 6256 */
} /* line 6256 */
  sim_icache_fetch(4098 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_9, reg_r0_20, reg_r0_2); /* line 6258 */
} /* line 6258 */
l_L224X3: ;/* line 6261 */
__LABEL(l_L224X3);
  sim_icache_fetch(4099 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6262 */
   __AND(reg_r0_4, reg_r0_7, (unsigned int) 7); /* line 6263 */
} /* line 6263 */
  sim_icache_fetch(4102 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_5, reg_r0_7, (unsigned int) 3); /* line 6265 */
   __SUB(reg_r0_6, (unsigned int) 16, reg_r0_4); /* line 6266 */
} /* line 6266 */
  sim_icache_fetch(4104 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_10, reg_r0_5, (unsigned int) _X1PACKETX15); /* line 6268 */
   __ADD(reg_r0_8, reg_r0_2, reg_r0_4); /* line 6269 */
} /* line 6269 */
  sim_icache_fetch(4107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_11, reg_r0_8, (unsigned int) -8); /* line 6271 */
   __ADD(reg_r0_12, reg_r0_10, (unsigned int) 2); /* line 6272 */
} /* line 6272 */
  sim_icache_fetch(4109 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_13, reg_r0_5, ((unsigned int) _X1PACKETX15 + (unsigned int) 1)); /* line 6274 */
   __CMPGE(reg_b0_0, reg_r0_11, (unsigned int) 8); /* line 6275 */
} /* line 6275 */
  sim_icache_fetch(4112 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 6277 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, reg_r0_13); /* line 6278 */
} /* line 6278 */
  sim_icache_fetch(4114 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, reg_r0_11); /* line 6280 */
   __LDBU(reg_r0_12, mem_trace_ld(reg_r0_12,0,1)); /* line 6281 */
} /* line 6281 */
  sim_icache_fetch(4116 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SUB(reg_r0_11, (unsigned int) 8, reg_r0_4); /* line 6283 */
   __LDBU(reg_r0_8, mem_trace_ld((reg_r0_8 + (unsigned int) rmask),0,1)); /* line 6284 */
} /* line 6284 */
  sim_icache_fetch(4119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_6, reg_b0_0, reg_r0_6, reg_r0_11); /* line 6286 */
   __LDBUs(reg_r0_10, mem_trace_ld((reg_r0_10 + (unsigned int) 1),0,1)); /* line 6287 */
} /* line 6287 */
  sim_icache_fetch(4121 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDBU(reg_r0_5, mem_trace_ld((reg_r0_5 + (unsigned int) _X1PACKETX15),0,1)); /* line 6289 */
   __AND(reg_r0_12, reg_r0_12, reg_r0_8); /* line 6290 */
} /* line 6290 */
  sim_icache_fetch(4124 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_10, reg_r0_10, reg_r0_11); /* line 6292 */
   __SHL(reg_r0_12, reg_r0_12, reg_r0_6); /* line 6293 */
} /* line 6293 */
  sim_icache_fetch(4126 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, reg_r0_7); /* line 6295 */
   __SHR(reg_r0_5, reg_r0_5, reg_r0_4); /* line 6296 */
} /* line 6296 */
  sim_icache_fetch(4128 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_10, reg_r0_5, reg_r0_10); /* line 6298 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_2); /* line 6299 */
} /* line 6299 */
  sim_icache_fetch(4131 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_10, reg_b0_0, reg_r0_10, reg_r0_5); /* line 6301 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_9); /* line 6302 */
} /* line 6302 */
  sim_icache_fetch(4134 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_10, reg_r0_12); /* line 6305 */
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6306 */
l_L256X3: ;/* line 6309 */
__LABEL(l_L256X3);
  sim_icache_fetch(4136 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 6310 */
   __GOTO(l_L257X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L257X3;
} /* line 6311 */
l_L255X3: ;/* line 6314 */
__LABEL(l_L255X3);
  sim_icache_fetch(4138 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6315 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6317 */
} /* line 6317 */
  sim_icache_fetch(4140 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6319 */
l_L253X3: ;/* line 6322 */
__LABEL(l_L253X3);
  sim_icache_fetch(4141 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6323 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6324 */
} /* line 6324 */
  sim_icache_fetch(4145 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6326 */
} /* line 6326 */
  sim_icache_fetch(4146 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -1); /* line 6328 */
} /* line 6328 */
  sim_icache_fetch(4147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6330 */
   __GOTO(l_L254X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L254X3;
} /* line 6331 */
l_L252X3: ;/* line 6334 */
__LABEL(l_L252X3);
  sim_icache_fetch(4149 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6335 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6337 */
} /* line 6337 */
  sim_icache_fetch(4151 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6339 */
l_L250X3: ;/* line 6342 */
__LABEL(l_L250X3);
  sim_icache_fetch(4152 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6343 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6344 */
} /* line 6344 */
  sim_icache_fetch(4156 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 6346 */
} /* line 6346 */
  sim_icache_fetch(4157 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -1); /* line 6348 */
} /* line 6348 */
  sim_icache_fetch(4158 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6350 */
   __GOTO(l_L251X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L251X3;
} /* line 6351 */
l_L249X3: ;/* line 6354 */
__LABEL(l_L249X3);
  sim_icache_fetch(4160 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6355 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6357 */
} /* line 6357 */
  sim_icache_fetch(4162 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6359 */
l_L247X3: ;/* line 6362 */
__LABEL(l_L247X3);
  sim_icache_fetch(4163 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6363 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6364 */
} /* line 6364 */
  sim_icache_fetch(4167 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6366 */
} /* line 6366 */
  sim_icache_fetch(4168 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -1); /* line 6368 */
} /* line 6368 */
  sim_icache_fetch(4169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6370 */
   __GOTO(l_L248X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L248X3;
} /* line 6371 */
l_L246X3: ;/* line 6374 */
__LABEL(l_L246X3);
  sim_icache_fetch(4171 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6375 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6377 */
} /* line 6377 */
  sim_icache_fetch(4173 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6379 */
l_L244X3: ;/* line 6382 */
__LABEL(l_L244X3);
  sim_icache_fetch(4174 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6383 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6384 */
} /* line 6384 */
  sim_icache_fetch(4178 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 6386 */
} /* line 6386 */
  sim_icache_fetch(4179 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -1); /* line 6388 */
} /* line 6388 */
  sim_icache_fetch(4180 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6390 */
   __GOTO(l_L245X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L245X3;
} /* line 6391 */
l_L243X3: ;/* line 6394 */
__LABEL(l_L243X3);
  sim_icache_fetch(4182 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6395 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6397 */
} /* line 6397 */
  sim_icache_fetch(4184 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6399 */
l_L241X3: ;/* line 6402 */
__LABEL(l_L241X3);
  sim_icache_fetch(4185 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6403 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6404 */
} /* line 6404 */
  sim_icache_fetch(4189 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) -1); /* line 6406 */
} /* line 6406 */
  sim_icache_fetch(4190 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -1); /* line 6408 */
} /* line 6408 */
  sim_icache_fetch(4191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6410 */
   __GOTO(l_L242X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L242X3;
} /* line 6411 */
l_L240X3: ;/* line 6414 */
__LABEL(l_L240X3);
  sim_icache_fetch(4193 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6415 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6417 */
} /* line 6417 */
  sim_icache_fetch(4195 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6419 */
l_L238X3: ;/* line 6422 */
__LABEL(l_L238X3);
  sim_icache_fetch(4196 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_7, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6423 */
   __LDWs(reg_r0_6, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6424 */
} /* line 6424 */
  sim_icache_fetch(4200 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 6426 */
} /* line 6426 */
  sim_icache_fetch(4201 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) -1); /* line 6428 */
} /* line 6428 */
  sim_icache_fetch(4202 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6430 */
   __GOTO(l_L239X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L239X3;
} /* line 6431 */
l_L237X3: ;/* line 6434 */
__LABEL(l_L237X3);
  sim_icache_fetch(4204 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6435 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6437 */
} /* line 6437 */
  sim_icache_fetch(4206 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6439 */
l_L235X3: ;/* line 6442 */
__LABEL(l_L235X3);
  sim_icache_fetch(4207 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_15, (unsigned int) -1); /* line 6443 */
   __LDWs(reg_r0_5, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6444 */
} /* line 6444 */
  sim_icache_fetch(4210 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 6446 */
} /* line 6446 */
  sim_icache_fetch(4211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6448 */
   __GOTO(l_L236X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L236X3;
} /* line 6449 */
l_L234X3: ;/* line 6452 */
__LABEL(l_L234X3);
  sim_icache_fetch(4213 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6453 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6455 */
} /* line 6455 */
  sim_icache_fetch(4215 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L258X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L258X3;
} /* line 6457 */
l_L231X3: ;/* line 6460 */
__LABEL(l_L231X3);
  sim_icache_fetch(4216 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_16, mem_trace_ld((unsigned int) buflen,0,4)); /* line 6461 */
   __LDWs(reg_r0_15, mem_trace_ld((unsigned int) bufp,0,4)); /* line 6462 */
} /* line 6462 */
  sim_icache_fetch(4220 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, (unsigned int) -1); /* line 6464 */
   __ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 6465 */
} /* line 6465 */
  sim_icache_fetch(4222 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_16, (unsigned int) -1); /* line 6467 */
   __CMPLT(reg_r0_7, reg_r0_14, 0); /* line 6468 */
} /* line 6468 */
  sim_icache_fetch(4224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGE(reg_b0_0, reg_r0_2, 0); /* line 6470 */
   __GOTO(l_L232X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L232X3;
} /* line 6471 */
l_L230X3: ;/* line 6474 */
__LABEL(l_L230X3);
  sim_icache_fetch(4226 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, 0); /* line 6475 */
   __MOV(reg_r0_3, (unsigned int) -1); /* line 6476 */
} /* line 6476 */
l_L258X3: ;/* line 6478 */
__LABEL(l_L258X3);
  sim_icache_fetch(4228 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLE(reg_b0_0, reg_r0_20, 0); /* line 6479 */
} /* line 6479 */
  sim_icache_fetch(4229 + t_thisfile.offset, 1);
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
} /* line 6481 */
  sim_icache_fetch(4230 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) _X1PACKETX14,0,4), reg_r0_20); /* line 6483 */
   __STW(mem_trace_st((unsigned int) _X1PACKETX13,0,4), reg_r0_19); /* line 6484 */
} /* line 6484 */
  sim_icache_fetch(4234 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(compressgetcode);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6487 */
l_L227X3: ;/* line 6490 */
__LABEL(l_L227X3);
  sim_icache_fetch(4235 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, (unsigned int) 511); /* line 6491 */
   __MOV(reg_r0_2, (unsigned int) 9); /* line 6492 */
} /* line 6492 */
  sim_icache_fetch(4238 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) n_bits,0,4), reg_r0_2); /* line 6494 */
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_6); /* line 6495 */
} /* line 6495 */
  sim_icache_fetch(4242 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), 0); /* line 6497 */
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6498 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6499 */
   __ADD_CYCLES(1);
} /* line 6499 */
  sim_icache_fetch(4247 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SUB(reg_r0_6, 0, reg_r0_5); /* line 6501 */
} /* line 6501 */
  sim_icache_fetch(4248 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_6); /* line 6503 */
   __GOTO(l_L228X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L228X3;
} /* line 6504 */
l_L226X3: ;/* line 6507 */
__LABEL(l_L226X3);
  sim_icache_fetch(4250 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) n_bits,0,4)); /* line 6508 */
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6509 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6510 */
   __ADD_CYCLES(1);
} /* line 6510 */
  sim_icache_fetch(4254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_3, reg_r0_3, reg_r0_2); /* line 6512 */
} /* line 6512 */
  sim_icache_fetch(4255 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) -1); /* line 6514 */
} /* line 6514 */
  sim_icache_fetch(4256 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) maxcode,0,4), reg_r0_3); /* line 6516 */
   __GOTO(l_L225X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L225X3;
} /* line 6517 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 397: goto l_L225X3;
    case 398: goto l_L228X3;
    case 399: goto l_L229X3;
    case 400: goto l_L232X3;
    case 401: goto l_L236X3;
    case 402: goto l_L239X3;
    case 403: goto l_L242X3;
    case 404: goto l_L245X3;
    case 405: goto l_L248X3;
    case 406: goto l_L251X3;
    case 407: goto l_L254X3;
    case 408: goto l_L257X3;
    case 409: goto l_L233X3;
    case 410: goto l_L259X3;
    case 411: goto l_L224X3;
    case 412: goto l_L256X3;
    case 413: goto l_L255X3;
    case 414: goto l_L253X3;
    case 415: goto l_L252X3;
    case 416: goto l_L250X3;
    case 417: goto l_L249X3;
    case 418: goto l_L247X3;
    case 419: goto l_L246X3;
    case 420: goto l_L244X3;
    case 421: goto l_L243X3;
    case 422: goto l_L241X3;
    case 423: goto l_L240X3;
    case 424: goto l_L238X3;
    case 425: goto l_L237X3;
    case 426: goto l_L235X3;
    case 427: goto l_L234X3;
    case 428: goto l_L231X3;
    case 429: goto l_L230X3;
    case 430: goto l_L258X3;
    case 431: goto l_L227X3;
    case 432: goto l_L226X3;
    case 433:
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
  reg_l0_0 = (436 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4259 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6539 */
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 6540 */
} /* line 6540 */
		 /* line 6541 */
  sim_icache_fetch(4262 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6544 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (436 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6544 */
l_lr_334: ;/* line 6544 */
__LABEL(l_lr_334);
  sim_icache_fetch(4265 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6546 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6547 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6548 */
   __ADD_CYCLES(1);
} /* line 6548 */
  sim_icache_fetch(4268 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(writeerr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6551 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 435: goto l_lr_334;
    case 436:
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
  reg_l0_0 = (438 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4269 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) bgnd_flag,0,4)); /* line 6597 */
} /* line 6597 */
  sim_icache_fetch(4271 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6599 */
} /* line 6599 */
  sim_icache_fetch(4272 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPNE(reg_b0_0, reg_r0_2, 0); /* line 6601 */
} /* line 6601 */
  sim_icache_fetch(4273 + t_thisfile.offset, 1);
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
} /* line 6603 */
  sim_icache_fetch(4274 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6606 */
l_L260X3: ;/* line 6609 */
__LABEL(l_L260X3);
  sim_icache_fetch(4275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6612 */
   __RETURN(foreground);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6612 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 437: goto l_L260X3;
    case 438:
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
  reg_l0_0 = (439 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4277 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6628 */
} /* line 6628 */
  sim_icache_fetch(4278 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(onintr);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6631 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 439:
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
  reg_l0_0 = (443 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4279 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6646 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) do_decomp,0,4)); /* line 6647 */
} /* line 6647 */
  sim_icache_fetch(4282 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 6649 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6650 */
} /* line 6650 */
  sim_icache_fetch(4285 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPEQ(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 6652 */
} /* line 6652 */
  sim_icache_fetch(4286 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L261X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6654 */
		 /* line 6655 */
  sim_icache_fetch(4287 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
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
} /* line 6657 */
l_lr_340: ;/* line 6657 */
__LABEL(l_lr_340);
l_L261X3: ;/* line 6659 */
__LABEL(l_L261X3);
  sim_icache_fetch(4289 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) 1); /* line 6660 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6661 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6662 */
   __ADD_CYCLES(1);
} /* line 6662 */
  sim_icache_fetch(4292 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(oops);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6665 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 441: goto l_lr_340;
    case 442: goto l_L261X3;
    case 443:
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
  reg_l0_0 = (456 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4293 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 6711 */
   __LDW(reg_r0_2, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6712 */
} /* line 6712 */
  sim_icache_fetch(4296 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_3, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6714 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 6715 */
} /* line 6715 */
  sim_icache_fetch(4299 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_4, reg_r0_2, (unsigned int) 10000); /* line 6717 */
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 8388607); /* line 6718 */
} /* line 6718 */
  sim_icache_fetch(4303 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 6720 */
   __MOV(reg_r0_2, (unsigned int) 2147483647); /* line 6721 */
} /* line 6721 */
  sim_icache_fetch(4306 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) checkpoint,0,4), reg_r0_4); /* line 6723 */
   __CMPEQ(reg_b0_1, reg_r0_3, 0); /* line 6724 */
} /* line 6724 */
  sim_icache_fetch(4309 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L262X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6726 */
  sim_icache_fetch(4310 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L263X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6728 */
l_L264X3: ;/* line 6731 */
__LABEL(l_L264X3);
  sim_icache_fetch(4311 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) ratio,0,4)); /* line 6732 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6733 */
} /* line 6733 */
  sim_icache_fetch(4314 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 6735 */
} /* line 6735 */
  sim_icache_fetch(4315 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_2, reg_r0_4); /* line 6737 */
} /* line 6737 */
  sim_icache_fetch(4316 + t_thisfile.offset, 1);
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
} /* line 6739 */
  sim_icache_fetch(4317 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), reg_r0_2); /* line 6742 */
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6743 */
l_L265X3: ;/* line 6746 */
__LABEL(l_L265X3);
  sim_icache_fetch(4320 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) ratio,0,4), 0); /* line 6747 */
   __LDW(reg_r0_3, mem_trace_ld((unsigned int) hsize,0,4)); /* line 6748 */
} /* line 6748 */
		 /* line 6749 */
  sim_icache_fetch(4324 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(cl_hash);
   reg_l0_0 = (456 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) cl_hash;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6751 */
l_lr_346: ;/* line 6751 */
__LABEL(l_lr_346);
  sim_icache_fetch(4326 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) 1); /* line 6753 */
   __MOV(reg_r0_2, (unsigned int) 257); /* line 6754 */
} /* line 6754 */
  sim_icache_fetch(4329 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) free_ent,0,4), reg_r0_2); /* line 6756 */
   __MOV(reg_r0_3, (unsigned int) 256); /* line 6757 */
} /* line 6757 */
		 /* line 6758 */
  sim_icache_fetch(4333 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((unsigned int) clear_flg,0,4), reg_r0_4); /* line 6760 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(output);
   reg_l0_0 = (456 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) output;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6761 */
l_lr_348: ;/* line 6761 */
__LABEL(l_lr_348);
  sim_icache_fetch(4337 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 6763 */
   __MOV(reg_r0_3, 0); /* line 6764 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6765 */
   __ADD_CYCLES(1);
} /* line 6765 */
  sim_icache_fetch(4340 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_block);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 6768 */
l_L263X3: ;/* line 6771 */
__LABEL(l_L263X3);
  sim_icache_fetch(4341 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6772 */
   __MOV(reg_r0_4, reg_r0_3); /* line 6773 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6774 */
   __ADD_CYCLES(1);
} /* line 6774 */
		 /* line 6775 */
  sim_icache_fetch(4345 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_5); /* line 6778 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (456 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6778 */
l_lr_351: ;/* line 6778 */
__LABEL(l_lr_351);
  sim_icache_fetch(4348 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_3); /* line 6780 */
   __GOTO(l_L264X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L264X3;
} /* line 6781 */
l_L262X3: ;/* line 6784 */
__LABEL(l_L262X3);
  sim_icache_fetch(4350 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_5, mem_trace_ld((unsigned int) in_count,0,4)); /* line 6785 */
   __LDW(reg_r0_4, mem_trace_ld((unsigned int) bytes_out,0,4)); /* line 6786 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 6787 */
   __ADD_CYCLES(1);
} /* line 6787 */
		 /* line 6788 */
  sim_icache_fetch(4355 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_3, reg_r0_5, (unsigned int) 8); /* line 6790 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(_i_div);
   reg_l0_0 = (456 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _i_div;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 6791 */
l_lr_354: ;/* line 6791 */
__LABEL(l_lr_354);
  sim_icache_fetch(4358 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_3); /* line 6793 */
   __GOTO(l_L264X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L264X3;
} /* line 6794 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 444: goto l_L264X3;
    case 445: goto l_L265X3;
    case 447: goto l_lr_346;
    case 449: goto l_lr_348;
    case 450: goto l_L263X3;
    case 452: goto l_lr_351;
    case 453: goto l_L262X3;
    case 455: goto l_lr_354;
    case 456:
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
  reg_l0_0 = (474 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4360 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SH2ADD(reg_r0_6, reg_r0_3, (unsigned int) htab); /* line 6813 */
} /* line 6813 */
  sim_icache_fetch(4362 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_3, (unsigned int) -16); /* line 6815 */
   __ADD(reg_r0_2, reg_r0_6, (unsigned int) -64); /* line 6816 */
} /* line 6816 */
  sim_icache_fetch(4364 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -32); /* line 6818 */
} /* line 6818 */
l_L266X3: ;/* line 6821 */
__LABEL(l_L266X3);
  sim_icache_fetch(4365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_2); /* line 6822 */
   __MOV(reg_r0_5, reg_r0_4); /* line 6823 */
} /* line 6823 */
  sim_icache_fetch(4367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 6825 */
   __MOV(reg_r0_8, (unsigned int) -1); /* line 6826 */
} /* line 6826 */
  sim_icache_fetch(4369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 16); /* line 6828 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 32); /* line 6829 */
} /* line 6829 */
  sim_icache_fetch(4371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 48); /* line 6831 */
   __CMPLT(reg_b0_4, reg_r0_4, (unsigned int) 64); /* line 6832 */
} /* line 6832 */
  sim_icache_fetch(4373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_5, reg_r0_4, (unsigned int) 80); /* line 6834 */
   __CMPLT(reg_b0_6, reg_r0_4, (unsigned int) 96); /* line 6835 */
} /* line 6835 */
  sim_icache_fetch(4375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_8); /* line 6837 */
   __CMPLT(reg_b0_7, reg_r0_4, (unsigned int) 112); /* line 6838 */
} /* line 6838 */
  sim_icache_fetch(4377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 4),0,4), reg_r0_8); /* line 6840 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 8),0,4), reg_r0_8); /* line 6841 */
} /* line 6841 */
  sim_icache_fetch(4379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 12),0,4), reg_r0_8); /* line 6843 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 16),0,4), reg_r0_8); /* line 6844 */
} /* line 6844 */
  sim_icache_fetch(4381 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 20),0,4), reg_r0_8); /* line 6846 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 24),0,4), reg_r0_8); /* line 6847 */
} /* line 6847 */
  sim_icache_fetch(4383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 28),0,4), reg_r0_8); /* line 6849 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 32),0,4), reg_r0_8); /* line 6850 */
} /* line 6850 */
  sim_icache_fetch(4385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 36),0,4), reg_r0_8); /* line 6852 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 40),0,4), reg_r0_8); /* line 6853 */
} /* line 6853 */
  sim_icache_fetch(4387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 44),0,4), reg_r0_8); /* line 6855 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 48),0,4), reg_r0_8); /* line 6856 */
} /* line 6856 */
  sim_icache_fetch(4389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 52),0,4), reg_r0_8); /* line 6858 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 56),0,4), reg_r0_8); /* line 6859 */
} /* line 6859 */
  sim_icache_fetch(4391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) 60),0,4), reg_r0_8); /* line 6861 */
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L267X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6862 */
  sim_icache_fetch(4393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -64),0,4), reg_r0_8); /* line 6864 */
   __CMPLT(reg_b0_0, reg_r0_4, (unsigned int) 128); /* line 6865 */
} /* line 6865 */
  sim_icache_fetch(4395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -60),0,4), reg_r0_8); /* line 6867 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -56),0,4), reg_r0_8); /* line 6868 */
} /* line 6868 */
  sim_icache_fetch(4397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -52),0,4), reg_r0_8); /* line 6870 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -48),0,4), reg_r0_8); /* line 6871 */
} /* line 6871 */
  sim_icache_fetch(4399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -44),0,4), reg_r0_8); /* line 6873 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -40),0,4), reg_r0_8); /* line 6874 */
} /* line 6874 */
  sim_icache_fetch(4401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -36),0,4), reg_r0_8); /* line 6876 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -32),0,4), reg_r0_8); /* line 6877 */
} /* line 6877 */
  sim_icache_fetch(4403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -28),0,4), reg_r0_8); /* line 6879 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -24),0,4), reg_r0_8); /* line 6880 */
} /* line 6880 */
  sim_icache_fetch(4405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -20),0,4), reg_r0_8); /* line 6882 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -16),0,4), reg_r0_8); /* line 6883 */
} /* line 6883 */
  sim_icache_fetch(4407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -12),0,4), reg_r0_8); /* line 6885 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -8),0,4), reg_r0_8); /* line 6886 */
} /* line 6886 */
  sim_icache_fetch(4409 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -4),0,4), reg_r0_8); /* line 6888 */
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L268X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6889 */
  sim_icache_fetch(4411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -128),0,4), reg_r0_8); /* line 6891 */
   __CMPLT(reg_b0_1, reg_r0_4, (unsigned int) 144); /* line 6892 */
} /* line 6892 */
  sim_icache_fetch(4413 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -124),0,4), reg_r0_8); /* line 6894 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -120),0,4), reg_r0_8); /* line 6895 */
} /* line 6895 */
  sim_icache_fetch(4415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -116),0,4), reg_r0_8); /* line 6897 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -112),0,4), reg_r0_8); /* line 6898 */
} /* line 6898 */
  sim_icache_fetch(4417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -108),0,4), reg_r0_8); /* line 6900 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -104),0,4), reg_r0_8); /* line 6901 */
} /* line 6901 */
  sim_icache_fetch(4419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -100),0,4), reg_r0_8); /* line 6903 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -96),0,4), reg_r0_8); /* line 6904 */
} /* line 6904 */
  sim_icache_fetch(4421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -92),0,4), reg_r0_8); /* line 6906 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -88),0,4), reg_r0_8); /* line 6907 */
} /* line 6907 */
  sim_icache_fetch(4423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -84),0,4), reg_r0_8); /* line 6909 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -80),0,4), reg_r0_8); /* line 6910 */
} /* line 6910 */
  sim_icache_fetch(4425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -76),0,4), reg_r0_8); /* line 6912 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -72),0,4), reg_r0_8); /* line 6913 */
} /* line 6913 */
  sim_icache_fetch(4427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -68),0,4), reg_r0_8); /* line 6915 */
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L269X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6916 */
  sim_icache_fetch(4429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -192),0,4), reg_r0_8); /* line 6918 */
   __CMPLT(reg_b0_2, reg_r0_4, (unsigned int) 160); /* line 6919 */
} /* line 6919 */
  sim_icache_fetch(4431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -188),0,4), reg_r0_8); /* line 6921 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -184),0,4), reg_r0_8); /* line 6922 */
} /* line 6922 */
  sim_icache_fetch(4433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -180),0,4), reg_r0_8); /* line 6924 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -176),0,4), reg_r0_8); /* line 6925 */
} /* line 6925 */
  sim_icache_fetch(4435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -172),0,4), reg_r0_8); /* line 6927 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -168),0,4), reg_r0_8); /* line 6928 */
} /* line 6928 */
  sim_icache_fetch(4437 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -164),0,4), reg_r0_8); /* line 6930 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -160),0,4), reg_r0_8); /* line 6931 */
} /* line 6931 */
  sim_icache_fetch(4439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -156),0,4), reg_r0_8); /* line 6933 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -152),0,4), reg_r0_8); /* line 6934 */
} /* line 6934 */
  sim_icache_fetch(4441 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -148),0,4), reg_r0_8); /* line 6936 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -144),0,4), reg_r0_8); /* line 6937 */
} /* line 6937 */
  sim_icache_fetch(4443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -140),0,4), reg_r0_8); /* line 6939 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -136),0,4), reg_r0_8); /* line 6940 */
} /* line 6940 */
  sim_icache_fetch(4445 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -132),0,4), reg_r0_8); /* line 6942 */
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L270X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6943 */
  sim_icache_fetch(4447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_3, reg_r0_4, (unsigned int) 176); /* line 6945 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) -208); /* line 6946 */
} /* line 6946 */
  sim_icache_fetch(4449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -256),0,4), reg_r0_8); /* line 6948 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -252),0,4), reg_r0_8); /* line 6949 */
} /* line 6949 */
  sim_icache_fetch(4451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -248),0,4), reg_r0_8); /* line 6951 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -244),0,4), reg_r0_8); /* line 6952 */
} /* line 6952 */
  sim_icache_fetch(4453 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -240),0,4), reg_r0_8); /* line 6954 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -236),0,4), reg_r0_8); /* line 6955 */
} /* line 6955 */
  sim_icache_fetch(4455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -232),0,4), reg_r0_8); /* line 6957 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -228),0,4), reg_r0_8); /* line 6958 */
} /* line 6958 */
  sim_icache_fetch(4457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -224),0,4), reg_r0_8); /* line 6960 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -220),0,4), reg_r0_8); /* line 6961 */
} /* line 6961 */
  sim_icache_fetch(4459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -216),0,4), reg_r0_8); /* line 6963 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -212),0,4), reg_r0_8); /* line 6964 */
} /* line 6964 */
  sim_icache_fetch(4461 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -208),0,4), reg_r0_8); /* line 6966 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -204),0,4), reg_r0_8); /* line 6967 */
} /* line 6967 */
  sim_icache_fetch(4463 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -200),0,4), reg_r0_8); /* line 6969 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -196),0,4), reg_r0_8); /* line 6970 */
} /* line 6970 */
  sim_icache_fetch(4465 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_4) {    __BRANCH(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L271X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6972 */
  sim_icache_fetch(4466 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -320),0,4), reg_r0_8); /* line 6974 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -316),0,4), reg_r0_8); /* line 6975 */
} /* line 6975 */
  sim_icache_fetch(4470 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -312),0,4), reg_r0_8); /* line 6977 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -308),0,4), reg_r0_8); /* line 6978 */
} /* line 6978 */
  sim_icache_fetch(4474 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -304),0,4), reg_r0_8); /* line 6980 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -300),0,4), reg_r0_8); /* line 6981 */
} /* line 6981 */
  sim_icache_fetch(4478 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -296),0,4), reg_r0_8); /* line 6983 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -292),0,4), reg_r0_8); /* line 6984 */
} /* line 6984 */
  sim_icache_fetch(4482 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -288),0,4), reg_r0_8); /* line 6986 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -284),0,4), reg_r0_8); /* line 6987 */
} /* line 6987 */
  sim_icache_fetch(4486 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -280),0,4), reg_r0_8); /* line 6989 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -276),0,4), reg_r0_8); /* line 6990 */
} /* line 6990 */
  sim_icache_fetch(4490 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -272),0,4), reg_r0_8); /* line 6992 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -268),0,4), reg_r0_8); /* line 6993 */
} /* line 6993 */
  sim_icache_fetch(4494 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -264),0,4), reg_r0_8); /* line 6995 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -260),0,4), reg_r0_8); /* line 6996 */
} /* line 6996 */
  sim_icache_fetch(4498 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_5) {    __BRANCH(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L272X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 6998 */
  sim_icache_fetch(4499 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -384),0,4), reg_r0_8); /* line 7000 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -380),0,4), reg_r0_8); /* line 7001 */
} /* line 7001 */
  sim_icache_fetch(4503 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -376),0,4), reg_r0_8); /* line 7003 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -372),0,4), reg_r0_8); /* line 7004 */
} /* line 7004 */
  sim_icache_fetch(4507 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -368),0,4), reg_r0_8); /* line 7006 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -364),0,4), reg_r0_8); /* line 7007 */
} /* line 7007 */
  sim_icache_fetch(4511 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -360),0,4), reg_r0_8); /* line 7009 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -356),0,4), reg_r0_8); /* line 7010 */
} /* line 7010 */
  sim_icache_fetch(4515 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -352),0,4), reg_r0_8); /* line 7012 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -348),0,4), reg_r0_8); /* line 7013 */
} /* line 7013 */
  sim_icache_fetch(4519 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -344),0,4), reg_r0_8); /* line 7015 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -340),0,4), reg_r0_8); /* line 7016 */
} /* line 7016 */
  sim_icache_fetch(4523 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -336),0,4), reg_r0_8); /* line 7018 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -332),0,4), reg_r0_8); /* line 7019 */
} /* line 7019 */
  sim_icache_fetch(4527 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -328),0,4), reg_r0_8); /* line 7021 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -324),0,4), reg_r0_8); /* line 7022 */
} /* line 7022 */
  sim_icache_fetch(4531 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_6) {    __BRANCH(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L273X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7024 */
  sim_icache_fetch(4532 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -448),0,4), reg_r0_8); /* line 7026 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -444),0,4), reg_r0_8); /* line 7027 */
} /* line 7027 */
  sim_icache_fetch(4536 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -440),0,4), reg_r0_8); /* line 7029 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -436),0,4), reg_r0_8); /* line 7030 */
} /* line 7030 */
  sim_icache_fetch(4540 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -432),0,4), reg_r0_8); /* line 7032 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -428),0,4), reg_r0_8); /* line 7033 */
} /* line 7033 */
  sim_icache_fetch(4544 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -424),0,4), reg_r0_8); /* line 7035 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -420),0,4), reg_r0_8); /* line 7036 */
} /* line 7036 */
  sim_icache_fetch(4548 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -416),0,4), reg_r0_8); /* line 7038 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -412),0,4), reg_r0_8); /* line 7039 */
} /* line 7039 */
  sim_icache_fetch(4552 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -408),0,4), reg_r0_8); /* line 7041 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -404),0,4), reg_r0_8); /* line 7042 */
} /* line 7042 */
  sim_icache_fetch(4556 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -400),0,4), reg_r0_8); /* line 7044 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -396),0,4), reg_r0_8); /* line 7045 */
} /* line 7045 */
  sim_icache_fetch(4560 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -392),0,4), reg_r0_8); /* line 7047 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -388),0,4), reg_r0_8); /* line 7048 */
} /* line 7048 */
  sim_icache_fetch(4564 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_7) {    __BRANCH(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L274X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7050 */
  sim_icache_fetch(4565 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -512),0,4), reg_r0_8); /* line 7052 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -508),0,4), reg_r0_8); /* line 7053 */
} /* line 7053 */
  sim_icache_fetch(4569 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -504),0,4), reg_r0_8); /* line 7055 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -500),0,4), reg_r0_8); /* line 7056 */
} /* line 7056 */
  sim_icache_fetch(4573 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -496),0,4), reg_r0_8); /* line 7058 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -492),0,4), reg_r0_8); /* line 7059 */
} /* line 7059 */
  sim_icache_fetch(4577 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -488),0,4), reg_r0_8); /* line 7061 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -484),0,4), reg_r0_8); /* line 7062 */
} /* line 7062 */
  sim_icache_fetch(4581 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -480),0,4), reg_r0_8); /* line 7064 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -476),0,4), reg_r0_8); /* line 7065 */
} /* line 7065 */
  sim_icache_fetch(4585 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -472),0,4), reg_r0_8); /* line 7067 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -468),0,4), reg_r0_8); /* line 7068 */
} /* line 7068 */
  sim_icache_fetch(4589 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -464),0,4), reg_r0_8); /* line 7070 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -460),0,4), reg_r0_8); /* line 7071 */
} /* line 7071 */
  sim_icache_fetch(4593 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -456),0,4), reg_r0_8); /* line 7073 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -452),0,4), reg_r0_8); /* line 7074 */
} /* line 7074 */
  sim_icache_fetch(4597 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L275X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7076 */
  sim_icache_fetch(4598 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -576),0,4), reg_r0_8); /* line 7078 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -572),0,4), reg_r0_8); /* line 7079 */
} /* line 7079 */
  sim_icache_fetch(4602 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -568),0,4), reg_r0_8); /* line 7081 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -564),0,4), reg_r0_8); /* line 7082 */
} /* line 7082 */
  sim_icache_fetch(4606 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -560),0,4), reg_r0_8); /* line 7084 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -556),0,4), reg_r0_8); /* line 7085 */
} /* line 7085 */
  sim_icache_fetch(4610 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -552),0,4), reg_r0_8); /* line 7087 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -548),0,4), reg_r0_8); /* line 7088 */
} /* line 7088 */
  sim_icache_fetch(4614 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -544),0,4), reg_r0_8); /* line 7090 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -540),0,4), reg_r0_8); /* line 7091 */
} /* line 7091 */
  sim_icache_fetch(4618 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -536),0,4), reg_r0_8); /* line 7093 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -532),0,4), reg_r0_8); /* line 7094 */
} /* line 7094 */
  sim_icache_fetch(4622 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -528),0,4), reg_r0_8); /* line 7096 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -524),0,4), reg_r0_8); /* line 7097 */
} /* line 7097 */
  sim_icache_fetch(4626 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -520),0,4), reg_r0_8); /* line 7099 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -516),0,4), reg_r0_8); /* line 7100 */
} /* line 7100 */
  sim_icache_fetch(4630 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_1) {    __BRANCH(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L276X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7102 */
  sim_icache_fetch(4631 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -640),0,4), reg_r0_8); /* line 7104 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -636),0,4), reg_r0_8); /* line 7105 */
} /* line 7105 */
  sim_icache_fetch(4635 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -632),0,4), reg_r0_8); /* line 7107 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -628),0,4), reg_r0_8); /* line 7108 */
} /* line 7108 */
  sim_icache_fetch(4639 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -624),0,4), reg_r0_8); /* line 7110 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -620),0,4), reg_r0_8); /* line 7111 */
} /* line 7111 */
  sim_icache_fetch(4643 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -616),0,4), reg_r0_8); /* line 7113 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -612),0,4), reg_r0_8); /* line 7114 */
} /* line 7114 */
  sim_icache_fetch(4647 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -608),0,4), reg_r0_8); /* line 7116 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -604),0,4), reg_r0_8); /* line 7117 */
} /* line 7117 */
  sim_icache_fetch(4651 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -600),0,4), reg_r0_8); /* line 7119 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -596),0,4), reg_r0_8); /* line 7120 */
} /* line 7120 */
  sim_icache_fetch(4655 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -592),0,4), reg_r0_8); /* line 7122 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -588),0,4), reg_r0_8); /* line 7123 */
} /* line 7123 */
  sim_icache_fetch(4659 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -584),0,4), reg_r0_8); /* line 7125 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -580),0,4), reg_r0_8); /* line 7126 */
} /* line 7126 */
  sim_icache_fetch(4663 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_2) {    __BRANCH(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L277X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7128 */
  sim_icache_fetch(4664 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -704),0,4), reg_r0_8); /* line 7130 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -700),0,4), reg_r0_8); /* line 7131 */
} /* line 7131 */
  sim_icache_fetch(4668 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -696),0,4), reg_r0_8); /* line 7133 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -692),0,4), reg_r0_8); /* line 7134 */
} /* line 7134 */
  sim_icache_fetch(4672 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -688),0,4), reg_r0_8); /* line 7136 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -684),0,4), reg_r0_8); /* line 7137 */
} /* line 7137 */
  sim_icache_fetch(4676 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -680),0,4), reg_r0_8); /* line 7139 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -676),0,4), reg_r0_8); /* line 7140 */
} /* line 7140 */
  sim_icache_fetch(4680 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -672),0,4), reg_r0_8); /* line 7142 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -668),0,4), reg_r0_8); /* line 7143 */
} /* line 7143 */
  sim_icache_fetch(4684 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -664),0,4), reg_r0_8); /* line 7145 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -660),0,4), reg_r0_8); /* line 7146 */
} /* line 7146 */
  sim_icache_fetch(4688 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -656),0,4), reg_r0_8); /* line 7148 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -652),0,4), reg_r0_8); /* line 7149 */
} /* line 7149 */
  sim_icache_fetch(4692 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -648),0,4), reg_r0_8); /* line 7151 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -644),0,4), reg_r0_8); /* line 7152 */
} /* line 7152 */
  sim_icache_fetch(4696 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_3) {    __BRANCH(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L278X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7154 */
  sim_icache_fetch(4697 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -208); /* line 7156 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -832); /* line 7157 */
} /* line 7157 */
  sim_icache_fetch(4700 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -768),0,4), reg_r0_8); /* line 7159 */
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 7160 */
} /* line 7160 */
  sim_icache_fetch(4703 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -764),0,4), reg_r0_8); /* line 7162 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -760),0,4), reg_r0_8); /* line 7163 */
} /* line 7163 */
  sim_icache_fetch(4707 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -756),0,4), reg_r0_8); /* line 7165 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -752),0,4), reg_r0_8); /* line 7166 */
} /* line 7166 */
  sim_icache_fetch(4711 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -748),0,4), reg_r0_8); /* line 7168 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -744),0,4), reg_r0_8); /* line 7169 */
} /* line 7169 */
  sim_icache_fetch(4715 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -740),0,4), reg_r0_8); /* line 7171 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -736),0,4), reg_r0_8); /* line 7172 */
} /* line 7172 */
  sim_icache_fetch(4719 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -732),0,4), reg_r0_8); /* line 7174 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -728),0,4), reg_r0_8); /* line 7175 */
} /* line 7175 */
  sim_icache_fetch(4723 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -724),0,4), reg_r0_8); /* line 7177 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -720),0,4), reg_r0_8); /* line 7178 */
} /* line 7178 */
  sim_icache_fetch(4727 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -716),0,4), reg_r0_8); /* line 7180 */
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -712),0,4), reg_r0_8); /* line 7181 */
} /* line 7181 */
  sim_icache_fetch(4731 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_2 + (unsigned int) -708),0,4), reg_r0_8); /* line 7183 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) -832); /* line 7184 */
} /* line 7184 */
  sim_icache_fetch(4735 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (reg_b0_0) {    __BRANCH(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L279X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7187 */
  sim_icache_fetch(4736 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L266X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L266X3;
} /* line 7189 */
l_L279X3: ;/* line 7192 */
__LABEL(l_L279X3);
  sim_icache_fetch(4737 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_3, (unsigned int) -768); /* line 7193 */
   __ADD(reg_r0_7, reg_r0_5, (unsigned int) -192); /* line 7195 */
} /* line 7195 */
  sim_icache_fetch(4740 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7197 */
l_L281X3: ;/* line 7200 */
__LABEL(l_L281X3);
  sim_icache_fetch(4741 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_2, 0); /* line 7201 */
   __MOV(reg_r0_8, (unsigned int) -1); /* line 7202 */
} /* line 7202 */
  sim_icache_fetch(4743 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 1); /* line 7204 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7205 */
  sim_icache_fetch(4745 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 2); /* line 7207 */
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 3); /* line 7208 */
} /* line 7208 */
  sim_icache_fetch(4747 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 4); /* line 7210 */
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 5); /* line 7211 */
} /* line 7211 */
  sim_icache_fetch(4749 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 6); /* line 7213 */
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 7); /* line 7214 */
} /* line 7214 */
  sim_icache_fetch(4751 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_7, reg_r0_2, (unsigned int) 8); /* line 7216 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) -64); /* line 7217 */
} /* line 7217 */
  sim_icache_fetch(4753 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), reg_r0_8); /* line 7219 */
   __ADD(reg_r0_5, reg_r0_2, (unsigned int) -16); /* line 7220 */
} /* line 7220 */
  sim_icache_fetch(4755 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_2, (unsigned int) 9); /* line 7222 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7223 */
  sim_icache_fetch(4757 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), reg_r0_8); /* line 7225 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7226 */
  sim_icache_fetch(4759 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), reg_r0_8); /* line 7228 */
   __CMPGT(reg_b0_1, reg_r0_2, (unsigned int) 10); /* line 7229 */
} /* line 7229 */
  sim_icache_fetch(4761 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_2, reg_r0_2, (unsigned int) 11); /* line 7231 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7232 */
  sim_icache_fetch(4763 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), reg_r0_8); /* line 7234 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7235 */
  sim_icache_fetch(4765 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), reg_r0_8); /* line 7237 */
   __CMPGT(reg_b0_3, reg_r0_2, (unsigned int) 12); /* line 7238 */
} /* line 7238 */
  sim_icache_fetch(4767 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_4, reg_r0_2, (unsigned int) 13); /* line 7240 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7241 */
  sim_icache_fetch(4769 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), reg_r0_8); /* line 7243 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7244 */
  sim_icache_fetch(4771 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), reg_r0_8); /* line 7246 */
   __CMPGT(reg_b0_5, reg_r0_2, (unsigned int) 14); /* line 7247 */
} /* line 7247 */
  sim_icache_fetch(4773 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_6, reg_r0_2, (unsigned int) 15); /* line 7249 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7250 */
  sim_icache_fetch(4775 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), reg_r0_8); /* line 7252 */
   __ADD(reg_r0_2, reg_r0_5, (unsigned int) -16); /* line 7253 */
} /* line 7253 */
  sim_icache_fetch(4777 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_7, reg_r0_5, 0); /* line 7255 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7256 */
  sim_icache_fetch(4779 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), reg_r0_8); /* line 7258 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7259 */
  sim_icache_fetch(4781 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), reg_r0_8); /* line 7261 */
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 7262 */
} /* line 7262 */
  sim_icache_fetch(4783 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 7264 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7265 */
  sim_icache_fetch(4785 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), reg_r0_8); /* line 7267 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7268 */
  sim_icache_fetch(4787 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), reg_r0_8); /* line 7270 */
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 3); /* line 7271 */
} /* line 7271 */
  sim_icache_fetch(4789 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 4); /* line 7273 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7274 */
  sim_icache_fetch(4791 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), reg_r0_8); /* line 7276 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7277 */
  sim_icache_fetch(4793 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), reg_r0_8); /* line 7279 */
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 5); /* line 7280 */
} /* line 7280 */
  sim_icache_fetch(4795 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 6); /* line 7282 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7283 */
  sim_icache_fetch(4797 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), reg_r0_8); /* line 7285 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7286 */
  sim_icache_fetch(4799 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_8); /* line 7288 */
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 7); /* line 7289 */
} /* line 7289 */
  sim_icache_fetch(4801 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_7, reg_r0_5, (unsigned int) 8); /* line 7291 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7292 */
  sim_icache_fetch(4803 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 60),0,4), reg_r0_8); /* line 7294 */
   __ADD(reg_r0_3, reg_r0_4, (unsigned int) -64); /* line 7295 */
} /* line 7295 */
  sim_icache_fetch(4805 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_0, reg_r0_5, (unsigned int) 9); /* line 7297 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7298 */
  sim_icache_fetch(4807 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 56),0,4), reg_r0_8); /* line 7300 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7301 */
  sim_icache_fetch(4809 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 52),0,4), reg_r0_8); /* line 7303 */
   __CMPGT(reg_b0_1, reg_r0_5, (unsigned int) 10); /* line 7304 */
} /* line 7304 */
  sim_icache_fetch(4811 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_2 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_2, reg_r0_5, (unsigned int) 11); /* line 7306 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7307 */
  sim_icache_fetch(4813 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 48),0,4), reg_r0_8); /* line 7309 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7310 */
  sim_icache_fetch(4815 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 44),0,4), reg_r0_8); /* line 7312 */
   __CMPGT(reg_b0_3, reg_r0_5, (unsigned int) 12); /* line 7313 */
} /* line 7313 */
  sim_icache_fetch(4817 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_4, reg_r0_5, (unsigned int) 13); /* line 7315 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7316 */
  sim_icache_fetch(4819 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 40),0,4), reg_r0_8); /* line 7318 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7319 */
  sim_icache_fetch(4821 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 36),0,4), reg_r0_8); /* line 7321 */
   __CMPGT(reg_b0_5, reg_r0_5, (unsigned int) 14); /* line 7322 */
} /* line 7322 */
  sim_icache_fetch(4823 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_6 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPGT(reg_b0_6, reg_r0_5, (unsigned int) 15); /* line 7324 */
   if (!t__i32_0) {    __BRANCHF(t__i32_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7325 */
  sim_icache_fetch(4825 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 32),0,4), reg_r0_8); /* line 7327 */
   if (!reg_b0_7) {    __BRANCHF(reg_b0_7);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7328 */
  sim_icache_fetch(4827 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 28),0,4), reg_r0_8); /* line 7330 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7331 */
  sim_icache_fetch(4829 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 24),0,4), reg_r0_8); /* line 7333 */
   if (!reg_b0_1) {    __BRANCHF(reg_b0_1);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7334 */
  sim_icache_fetch(4831 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 20),0,4), reg_r0_8); /* line 7336 */
   if (!reg_b0_2) {    __BRANCHF(reg_b0_2);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7337 */
  sim_icache_fetch(4833 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 16),0,4), reg_r0_8); /* line 7339 */
   if (!reg_b0_3) {    __BRANCHF(reg_b0_3);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7340 */
  sim_icache_fetch(4835 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 12),0,4), reg_r0_8); /* line 7342 */
   if (!reg_b0_4) {    __BRANCHF(reg_b0_4);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7343 */
  sim_icache_fetch(4837 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 8),0,4), reg_r0_8); /* line 7345 */
   if (!reg_b0_5) {    __BRANCHF(reg_b0_5);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7346 */
  sim_icache_fetch(4839 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_4 + (unsigned int) 4),0,4), reg_r0_8); /* line 7348 */
   if (!reg_b0_6) {    __BRANCHF(reg_b0_6);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L282X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 7349 */
  sim_icache_fetch(4841 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_4,0,4), reg_r0_8); /* line 7351 */
   __GOTO(l_L281X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L281X3;
} /* line 7352 */
l_L282X3: ;/* line 7355 */
__LABEL(l_L282X3);
  sim_icache_fetch(4843 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(cl_hash);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7357 */
l_L278X3: ;/* line 7360 */
__LABEL(l_L278X3);
  sim_icache_fetch(4844 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -768); /* line 7361 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -192); /* line 7363 */
} /* line 7363 */
  sim_icache_fetch(4847 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7365 */
l_L277X3: ;/* line 7368 */
__LABEL(l_L277X3);
  sim_icache_fetch(4848 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -704); /* line 7369 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -176); /* line 7371 */
} /* line 7371 */
  sim_icache_fetch(4851 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7373 */
l_L276X3: ;/* line 7376 */
__LABEL(l_L276X3);
  sim_icache_fetch(4852 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -640); /* line 7377 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -160); /* line 7379 */
} /* line 7379 */
  sim_icache_fetch(4855 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7381 */
l_L275X3: ;/* line 7384 */
__LABEL(l_L275X3);
  sim_icache_fetch(4856 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -576); /* line 7385 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -144); /* line 7387 */
} /* line 7387 */
  sim_icache_fetch(4859 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7389 */
l_L274X3: ;/* line 7392 */
__LABEL(l_L274X3);
  sim_icache_fetch(4860 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -512); /* line 7393 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -128); /* line 7395 */
} /* line 7395 */
  sim_icache_fetch(4863 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7397 */
l_L273X3: ;/* line 7400 */
__LABEL(l_L273X3);
  sim_icache_fetch(4864 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -448); /* line 7401 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -112); /* line 7403 */
} /* line 7403 */
  sim_icache_fetch(4867 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7405 */
l_L272X3: ;/* line 7408 */
__LABEL(l_L272X3);
  sim_icache_fetch(4868 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -384); /* line 7409 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -96); /* line 7411 */
} /* line 7411 */
  sim_icache_fetch(4871 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7413 */
l_L271X3: ;/* line 7416 */
__LABEL(l_L271X3);
  sim_icache_fetch(4872 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -320); /* line 7417 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -80); /* line 7419 */
} /* line 7419 */
  sim_icache_fetch(4875 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7421 */
l_L270X3: ;/* line 7424 */
__LABEL(l_L270X3);
  sim_icache_fetch(4876 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -256); /* line 7425 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -64); /* line 7427 */
} /* line 7427 */
  sim_icache_fetch(4878 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7429 */
l_L269X3: ;/* line 7432 */
__LABEL(l_L269X3);
  sim_icache_fetch(4879 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -192); /* line 7433 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -48); /* line 7435 */
} /* line 7435 */
  sim_icache_fetch(4881 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7437 */
l_L268X3: ;/* line 7440 */
__LABEL(l_L268X3);
  sim_icache_fetch(4882 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -128); /* line 7441 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -32); /* line 7443 */
} /* line 7443 */
  sim_icache_fetch(4884 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L280X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L280X3;
} /* line 7445 */
l_L267X3: ;/* line 7448 */
__LABEL(l_L267X3);
  sim_icache_fetch(4885 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) -64); /* line 7449 */
   __ADD(reg_r0_7, reg_r0_7, (unsigned int) -16); /* line 7450 */
} /* line 7450 */
l_L280X3: ;/* line 7452 */
__LABEL(l_L280X3);
  sim_icache_fetch(4887 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_7, (unsigned int) 16); /* line 7453 */
   __ADD(reg_r0_3, reg_r0_6, (unsigned int) -64); /* line 7455 */
} /* line 7455 */
  sim_icache_fetch(4889 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L281X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L281X3;
} /* line 7457 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 457: goto l_L266X3;
    case 458: goto l_L279X3;
    case 459: goto l_L281X3;
    case 460: goto l_L282X3;
    case 461: goto l_L278X3;
    case 462: goto l_L277X3;
    case 463: goto l_L276X3;
    case 464: goto l_L275X3;
    case 465: goto l_L274X3;
    case 466: goto l_L273X3;
    case 467: goto l_L272X3;
    case 468: goto l_L271X3;
    case 469: goto l_L270X3;
    case 470: goto l_L269X3;
    case 471: goto l_L268X3;
    case 472: goto l_L267X3;
    case 473: goto l_L280X3;
    case 474:
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
  reg_l0_0 = (475 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4890 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7473 */
} /* line 7473 */
  sim_icache_fetch(4891 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(prratio);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7476 */
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

extern unsigned int version(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(version);  sim_gprof_enter(&sim_gprof_idx,"version");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (476 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(4892 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 7492 */
} /* line 7492 */
  sim_icache_fetch(4893 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(version);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 7495 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 476:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"compress.s", 4896, 0, 0, 0, 2};

