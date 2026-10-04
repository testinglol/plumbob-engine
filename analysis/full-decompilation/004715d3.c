
void __thiscall FUN_004715d3(int param_1,int param_2,char *param_3,char param_4)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  void *pvVar4;
  char cVar5;
  
  cVar5 = *(char *)(param_1 + 0x5d);
  if (param_4 != -1) {
    cVar5 = param_4;
  }
  if (0 < param_2) {
    iVar2 = FUN_0046fc11(cVar5);
    if (param_2 <= iVar2) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x6c) + cVar5 * 0xc);
      iVar2 = iVar1 + -0xc + param_2 * 0xc;
      iVar1 = *(int *)(iVar1 + -8 + param_2 * 0xc);
      if (iVar1 != 0) {
        FUN_006321f0(iVar1);
        *(undefined4 *)(iVar2 + 4) = 0;
      }
      if (param_3 != (char *)0x0) {
        sVar3 = _strlen(param_3);
        pvVar4 = operator_new(sVar3 + 1);
        *(void **)(iVar2 + 4) = pvVar4;
        FUN_006358b0(pvVar4,param_3);
      }
    }
  }
  return;
}

