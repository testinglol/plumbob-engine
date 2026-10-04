
void __thiscall FUN_004300be(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = '\x01';
  iVar3 = *(int *)(*param_1 + 4);
  iVar4 = *param_1;
  while (iVar3 != 0) {
    cVar1 = FUN_00430155(param_3,iVar3 + 0x10);
    iVar4 = iVar3;
    if (cVar1 == '\0') {
      iVar3 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar3 = *(int *)(iVar3 + 8);
    }
  }
  if (cVar1 != '\0') {
    if (iVar4 == *(int *)(*param_1 + 8)) goto LAB_0043012d;
    FUN_0042a392();
  }
  cVar1 = FUN_00430155(iVar4 + 0x10,param_3);
  if (cVar1 == '\0') {
    *(undefined1 *)(param_2 + 1) = 0;
    *param_2 = iVar4;
    return;
  }
LAB_0043012d:
  piVar2 = (int *)FUN_004308cd(&param_3,0,iVar4,param_3);
  *param_2 = *piVar2;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}

