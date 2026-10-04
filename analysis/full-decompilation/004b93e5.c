
undefined4 FUN_004b93e5(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_40 [12];
  undefined4 local_34;
  uint local_20;
  char local_14;
  char local_13;
  
  *param_2 = 0;
  iVar1 = FUN_0063711e(&local_14,1,0xe,param_1);
  if ((((*(byte *)(param_1 + 0xc) & 0x10) == 0) && (local_14 == 'B')) && (local_13 == 'M')) {
    iVar2 = FUN_0063711e(local_40,1,0x28,param_1);
    iVar1 = iVar1 + iVar2;
    if (((*(byte *)(param_1 + 0xc) & 0x10) == 0) && (local_34._2_2_ == 8)) {
      if (local_20 == 0) {
        local_20 = 1 << ((byte)(local_34 << 3) & 0x1f) & 0xffff;
      }
      *param_2 = local_20;
      return 1;
    }
  }
  FUN_00637235(param_1,-iVar1,1);
  return 0;
}

