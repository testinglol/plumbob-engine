
uint __fastcall FUN_0048c2bc(int *param_1)

{
  uint in_EAX;
  int *piVar1;
  short *psVar2;
  
  piVar1 = DAT_006e5790;
  if (*param_1 == 0) {
    return in_EAX & 0xffff0000;
  }
  do {
    if (piVar1 == DAT_006e5794) {
      psVar2 = (short *)0x0;
LAB_0048c2e4:
      if (psVar2 == (short *)0x0) {
        return 0;
      }
      return (int)*psVar2;
    }
    if (*(int *)(*piVar1 + 8) == *param_1) {
      psVar2 = (short *)*piVar1;
      goto LAB_0048c2e4;
    }
    piVar1 = piVar1 + 1;
  } while( true );
}

