
undefined4 __thiscall FUN_005e6990(int param_1,char *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
LAB_005e6997:
    uVar1 = 1;
  }
  else {
    ppuVar3 = &PTR_s_autonomy_006d752c;
    do {
      iVar2 = _strcmp(param_2,*ppuVar3);
      if (iVar2 == 0) goto LAB_005e6997;
      ppuVar3 = ppuVar3 + 1;
    } while (ppuVar3 < &cCheatCommandLine::RTTI_Type_Descriptor);
    uVar1 = 0;
  }
  return uVar1;
}

