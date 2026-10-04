
void FUN_00591e31(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 local_404 [1024];
  
  if (param_1 == 0) {
    puVar2 = &DAT_006de560;
  }
  else {
    uVar1 = __ftol(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x78),
                   *(undefined4 *)(param_1 + 0x7c));
    uVar1 = __ftol(uVar1);
    uVar1 = __ftol(uVar1);
    FUN_00635858(local_404,s__s__d__d__d__d__d__d__d_006d0628,
                 *(undefined4 *)(*(int *)(param_1 + 4) + 4),*(undefined4 *)(param_1 + 0x14),uVar1);
    puVar2 = local_404;
  }
  FUN_005d4bbf(puVar2);
  return;
}

