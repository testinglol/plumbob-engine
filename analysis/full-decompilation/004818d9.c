
undefined4 __thiscall FUN_004818d9(int *param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int local_10;
  
  iVar3 = *param_1;
  do {
    if (iVar3 == param_1[1]) {
      return 0;
    }
    if ((*(short *)(iVar3 + 0xc) != 0) &&
       (iVar2 = FUN_00407498((int)*(short *)(iVar3 + 0xc)), iVar2 != 0)) {
      FUN_00457da4();
      sVar1 = FUN_004561a0(0x1a);
      if ((sVar1 != 0) && (FUN_0043270d(param_2), local_10 == iVar2)) {
        return 1;
      }
    }
    iVar3 = iVar3 + 0x10;
  } while( true );
}

