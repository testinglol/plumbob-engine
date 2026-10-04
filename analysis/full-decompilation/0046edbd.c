
undefined1 * __thiscall FUN_0046edbd(int *param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if ((((-1 < (int)param_3) && (param_3 < (uint)((param_1[1] - *param_1) / 0xc))) &&
      (piVar1 = (int *)(*param_1 + param_3 * 0xc), -1 < (int)param_2)) &&
     (iVar2 = *piVar1, param_2 < (uint)(piVar1[1] - iVar2 >> 2))) {
    puVar3 = *(undefined1 **)(iVar2 + param_2 * 4);
    if (puVar3 != (undefined1 *)0x0) {
      return puVar3;
    }
    return &DAT_006de560;
  }
  return (undefined1 *)0x0;
}

