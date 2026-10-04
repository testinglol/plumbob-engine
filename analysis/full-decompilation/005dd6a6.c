
bool FUN_005dd6a6(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  bool bVar3;
  
  if ((DAT_006fe8f0 & 1) == 0) {
    DAT_006fe8f0 = DAT_006fe8f0 | 1;
    piVar2 = (int *)FUN_005e7743();
    DAT_006fe8ec = (**(code **)(*piVar2 + 0x44))(0);
  }
  if ((param_1 != (int *)0x0) && (cVar1 = (**(code **)(*param_1 + 0x20))(0x80), cVar1 != '\0')) {
    bVar3 = *(ushort *)(param_1[0xd] + (int)(param_1[0xe] * param_2 + (int)param_1) * 2) !=
            DAT_006fe8ec;
    (**(code **)(*param_1 + 0x24))(0x80);
    return bVar3;
  }
  return false;
}

