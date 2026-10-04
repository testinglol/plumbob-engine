
void __thiscall FUN_00467805(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  char *pcVar5;
  int iStack00000008;
  
  piVar3 = param_2;
  iVar2 = *param_2;
  cVar1 = *(char *)(iVar2 + 2);
  uVar4 = __ftol();
  iStack00000008 = (param_2[1] - iVar2) / 3;
  if (0 < iStack00000008) {
    param_2 = (int *)0x0;
    do {
      pcVar5 = (char *)(*piVar3 + (int)param_2);
      param_2 = (int *)((int)param_2 + 3);
      iStack00000008 = iStack00000008 + -1;
      *(undefined1 *)
       (*(int *)(*(int *)(*(int *)(param_1 + 0x44 + (cVar1 + -1) * 4) + 0xc) + *pcVar5 * 4) +
       (int)pcVar5[1]) = uVar4;
    } while (iStack00000008 != 0);
  }
  return;
}

