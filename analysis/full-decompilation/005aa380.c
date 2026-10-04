
undefined4
FUN_005aa380(uint param_1,char *param_2,undefined2 *param_3,int param_4,undefined4 param_5,
            int param_6,int param_7,int param_8,undefined4 param_9,int param_10,int param_11,
            undefined4 param_12)

{
  undefined2 *puVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint local_108;
  undefined1 local_100 [256];
  
  local_108 = param_1;
  if (param_8 != 0) {
    local_108 = param_1 | 0x200;
  }
  if (param_10 != 0) {
    local_108 = local_108 | 0x100;
  }
  puVar8 = (undefined4 *)((int)param_3 + param_7 + param_6 + 0x83 & ~(param_6 - 1U));
  puVar9 = puVar8 + -4;
  puVar1 = param_3 + 8;
  iVar2 = (int)param_3 + param_4 + (-0x30 - param_7);
  FUN_00635858(local_100,"%s LOW",param_2);
  FUN_005aa2c0(param_3,local_100,0x44,param_7,local_108 | 0x8000,0,puVar9);
  FUN_005aa2c0(puVar9,0,(iVar2 - (int)puVar9) + -0x10,param_7,local_108,param_3,iVar2);
  FUN_00635858(local_100,"%s HIGH",param_2);
  FUN_005aa2c0(iVar2,local_100,0,param_7,local_108 | 0x8010,puVar9,0);
  (&DAT_00703ea0)[param_1 & 0xf] = puVar1;
  FUN_005a9250(puVar1,0,0x44);
  iVar6 = (int)puVar1 - (int)param_2;
  do {
    cVar3 = *param_2;
    param_2[iVar6] = cVar3;
    param_2 = param_2 + 1;
  } while (cVar3 != '\0');
  *(undefined2 **)(param_3 + 0xc) = param_3;
  *(int *)(param_3 + 0xe) = iVar2;
  *param_3 = 0x4253;
  puVar4 = (undefined4 *)(param_3 + 0x10);
  **(undefined2 **)(param_3 + 0xe) = 0x4253;
  *(undefined4 *)(param_3 + 0x1c) = param_5;
  *(int *)(param_3 + 0x1e) = param_6;
  *(uint *)(param_3 + 0x22) = local_108;
  *(undefined2 *)puVar4 = 0x4253;
  *(undefined4 **)(param_3 + 0x18) = puVar4;
  *(undefined4 **)(param_3 + 0x1a) = puVar4;
  *(undefined4 *)(param_3 + 0x12) = 0x7fffffff;
  *(int *)(param_3 + 0x20) = param_7;
  *(undefined4 *)(param_3 + 0x24) = 0;
  *(undefined4 *)(param_3 + 0x26) = param_12;
  puVar7 = puVar4;
  if ((undefined4 *)
      (((uint)(*(int *)(param_3 + 0x1a) - *(int *)(param_3 + 0x18)) >> 1) + *(int *)(param_3 + 0x18)
      ) < puVar9) {
    do {
      puVar4 = (undefined4 *)puVar4[5];
    } while (puVar9 < puVar4);
    puVar7 = (undefined4 *)puVar4[4];
  }
  else {
    do {
      puVar7 = (undefined4 *)puVar7[4];
    } while (puVar7 < puVar9);
    puVar4 = (undefined4 *)puVar7[5];
  }
  *puVar8 = puVar7;
  puVar8[1] = puVar4;
  puVar8[-3] = puVar8[-2] - (int)puVar9;
  puVar4[4] = puVar9;
  puVar7[5] = puVar9;
  *(byte *)((int)puVar8 + -0xd) = *(byte *)((int)puVar8 + -0xd) | 0x40;
  *(undefined2 *)puVar9 = 0x4246;
  if (param_11 != 0) {
    uVar5 = FUN_005b6760();
    *(undefined4 *)(param_3 + 0x24) = uVar5;
  }
  return puVar8[-3];
}

