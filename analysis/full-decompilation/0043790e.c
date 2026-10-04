
void __fastcall FUN_0043790e(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 != '\0') {
    iVar1 = param_1[0x4d];
    for (iVar4 = param_1[0x4c]; iVar4 != iVar1; iVar4 = iVar4 + 0x24) {
      piVar3 = (int *)FUN_00407498((int)*(short *)(iVar4 + 0x10));
      if ((piVar3 != (int *)0x0) && (cVar2 = (**(code **)(*piVar3 + 0x28))(), cVar2 != '\0')) {
        (**(code **)(*piVar3 + 0x24))();
      }
    }
  }
  return;
}

