
bool __thiscall FUN_00523046(int param_1,undefined4 *param_2)

{
  short *psVar1;
  int iVar2;
  
  FUN_0043acf5(*param_2);
  psVar1 = (short *)FUN_00425769(*param_2);
  if (psVar1[0x7b] < 2) {
    iVar2 = FUN_0042573e(*(undefined4 *)(param_1 + 0x10c));
    if (iVar2 != -0xc) {
      iVar2 = FUN_00465062((int)*psVar1);
      return 0 < iVar2;
    }
  }
  return false;
}

