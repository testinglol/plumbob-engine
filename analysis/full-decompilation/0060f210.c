
void FUN_0060f210(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar2 = __ftol();
  iVar3 = __ftol();
  if (-1 < iVar2) {
    iVar1 = *param_1;
    if (((iVar2 < *(int *)(iVar1 + 0x10)) && (-1 < iVar3)) && (iVar3 < *(int *)(iVar1 + 0x14))) {
      iVar2 = *(int *)(iVar1 + 0x18) * iVar2;
      puVar4 = (undefined1 *)
               (((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) + param_1[2] * iVar3 + param_1[1]);
      puVar4[3] = (char)((uint)param_4 >> 0x18);
      puVar4[2] = (char)((uint)param_4 >> 0x10);
      puVar4[1] = (char)((uint)param_4 >> 8);
      *puVar4 = (char)param_4;
    }
  }
  return;
}

