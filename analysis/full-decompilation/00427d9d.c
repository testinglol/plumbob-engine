
void __thiscall FUN_00427d9d(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined **local_334;
  undefined4 local_330;
  undefined1 local_328 [260];
  undefined **local_224;
  undefined4 local_220;
  undefined1 local_218 [260];
  undefined **local_114;
  undefined4 local_110;
  undefined1 local_108 [260];
  
  FUN_0046f824(local_218,0,0x104);
  local_224 = &PTR_FUN_006664e8;
  FUN_0046f824(local_328,0,0x104);
  local_334 = &PTR_FUN_006664e8;
  FUN_0046f824(local_108,0,0x104);
  local_114 = &PTR_FUN_006664e8;
  FUN_00425691(param_2,&local_224);
  FUN_00425691(param_3,&local_334);
  FUN_00412122(param_1,&local_114);
  FUN_0046f847(&DAT_006c273c,0xffffffff);
  uVar4 = local_220;
  uVar6 = local_110;
  FUN_005b8e25(local_220,local_110);
  cVar1 = FUN_005b9849(uVar4,uVar6);
  if (cVar1 != '\0') {
    uVar4 = local_330;
    FUN_005b8e25(local_330,local_220);
    cVar1 = FUN_005b9849(uVar4,local_220);
    if (cVar1 != '\0') {
      FUN_005b8e25(local_110,local_330);
      cVar1 = FUN_005b9849(local_110,local_330);
      if (cVar1 != '\0') {
        iVar2 = FUN_00425ddf(param_2);
        iVar3 = FUN_00425ddf(param_3);
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x110) = param_3;
        }
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x110) = param_2;
        }
        iVar2 = FUN_00425316(*(undefined4 *)(DAT_006e486c + 0x44));
        if (iVar2 == 0) {
          return;
        }
        FUN_0046f8cb(s_Error_saving_neighborhood__006c2704);
        FUN_0046fa40(iVar2);
        pcVar5 = &DAT_006c26dc;
        goto LAB_00427f04;
      }
    }
  }
  pcVar5 = s_Couldn_t_move_house_files__006c2720;
LAB_00427f04:
  FUN_0046f847(pcVar5,0xffffffff);
  return;
}

