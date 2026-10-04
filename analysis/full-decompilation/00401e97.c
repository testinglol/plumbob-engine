
void FUN_00401e97(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined **local_224 [3];
  undefined1 local_218 [260];
  undefined **local_114 [3];
  undefined1 local_108 [260];
  
  if (param_2 != (int *)0x0) {
    FUN_0046f824(local_108,0,0x104);
    local_114[0] = &PTR_FUN_006664e8;
    FUN_0046f824(local_218,0,0x104);
    local_224[0] = &PTR_FUN_006664e8;
    (**(code **)(*param_2 + 0x24))(local_114);
    FUN_0041218d(local_114,local_224);
    for (iVar2 = DAT_006de708; iVar2 != DAT_006de70c; iVar2 = iVar2 + 0x54) {
      iVar1 = FUN_0046f973(local_224);
      if (iVar1 == 0) {
        iVar1 = FUN_0040204f(*(undefined2 *)(iVar2 + 0x4c));
        if (((iVar1 != 0) && (-1 < *(int *)(iVar2 + 0x50))) &&
           (*(int *)(iVar2 + 0x50) < (int)*(short *)(iVar1 + 2))) {
          FUN_00402611(CONCAT22(*(short *)(iVar1 + 2) >> 0xf,*(undefined2 *)(iVar2 + 0x4c)));
        }
      }
    }
  }
  return;
}

