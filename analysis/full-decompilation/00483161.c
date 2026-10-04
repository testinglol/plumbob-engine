
undefined4 FUN_00483161(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar4 = &DAT_006c25a8;
  uVar2 = param_2[1] & 0xf;
  iVar1 = param_2[1] >> 4;
  puVar3 = &DAT_006c26dc;
  FUN_006323d0(&DAT_006c3cd0);
  FUN_006321fb(iVar1);
  FUN_006323d0(puVar3);
  FUN_006321fb(uVar2);
  FUN_006323d0(puVar4);
  uVar2 = param_2[1] & 0xf;
  puVar4 = &DAT_006c3cd4;
  puVar3 = &DAT_006c26dc;
  FUN_006321fb(*param_2 >> 4);
  FUN_006323d0(puVar3);
  FUN_006321fb(uVar2);
  FUN_006323d0(puVar4);
  return param_1;
}

