
void FUN_005d5e10(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  DAT_006fe8bc = (int *)FUN_00604849();
  FUN_005d5ee0(param_1);
  iVar3 = 0;
  piVar4 = (int *)0x0;
  if (DAT_006feb14 != (code *)0x0) {
    piVar4 = (int *)(*DAT_006feb14)();
  }
  (**(code **)piVar4[1])();
  DAT_006fe8bc[4] = (int)piVar4;
  cVar1 = FUN_005d6516(s_nosound_006d6f1c,0,1);
  if (cVar1 != '\0') {
    *(undefined1 *)(DAT_006fe8bc + 0x4f) = 0;
  }
  (**(code **)(*piVar4 + 0x1c))();
  cVar1 = (**(code **)(piVar4[0x12] + 8))();
  if (cVar1 != '\0') {
    (**(code **)(*DAT_006fe8bc + 0x2c))();
    (**(code **)(piVar4[0x12] + 0xc))();
    iVar2 = (**(code **)(*param_1 + 0xc))();
    if (0 < iVar2) {
      do {
        iVar3 = iVar3 + 1;
        iVar2 = (**(code **)(*param_1 + 0xc))();
      } while (iVar3 < iVar2);
    }
    iVar3 = (**(code **)*DAT_006fe8bc)();
    cVar1 = (**(code **)(*(int *)(-(uint)(iVar3 != 0) & iVar3 - 0x48U) + 0x14))();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_006fe8bc + 0x40))();
      (**(code **)(piVar4[0x12] + 0x10))();
      FUN_005d5f13();
    }
  }
  return;
}

