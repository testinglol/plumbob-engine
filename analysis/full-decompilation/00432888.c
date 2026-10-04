
void __thiscall FUN_00432888(int param_1,char *param_2,undefined2 param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar1 = *param_2;
  iVar3 = (int)param_2[2];
  if (-1 < cVar1) {
    if (((((int)cVar1 < *(int *)(param_1 + 0x10)) && (cVar2 = param_2[1], -1 < cVar2)) &&
        ((int)cVar2 < *(int *)(param_1 + 0x10))) && ((0 < iVar3 && (iVar3 < 3)))) {
      *(undefined2 *)
       (*(int *)(*(int *)(*(int *)(param_1 + 0x38 + iVar3 * 4) + 0xc) + cVar1 * 4) + cVar2 * 2) =
           param_3;
    }
  }
  return;
}

