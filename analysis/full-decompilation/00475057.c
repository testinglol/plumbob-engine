
void __fastcall FUN_00475057(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2) + -2;
  iVar1 = FUN_004750a6();
  iVar1 = *(int *)(iVar1 + 0xc);
  sVar3 = (short)iVar4;
  do {
    if (sVar3 < 0) {
      iVar1 = 0;
LAB_00475093:
      FUN_004754ac(iVar1);
      return;
    }
    iVar2 = FUN_004754ac((int)(short)iVar4);
    if (*(int *)(iVar2 + 0xc) != iVar1) {
      iVar1 = (int)(short)((short)iVar4 + 1);
      goto LAB_00475093;
    }
    iVar4 = iVar4 + -1;
    sVar3 = (short)iVar4;
  } while( true );
}

