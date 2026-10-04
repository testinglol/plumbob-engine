
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005fb294(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  int *local_8;
  
  cVar3 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar3 == '\0') {
LAB_005fb3c5:
    uVar4 = 1;
  }
  else {
    cVar3 = (**(code **)(*param_1 + 0x24))();
    if (cVar3 == '\0') {
LAB_005fb2cd:
      cVar3 = (**(code **)(*DAT_006fed70 + 0x94))();
      *(char *)(param_1 + 0x68) = cVar3;
      if (cVar3 == '\0') {
        *(undefined1 *)(param_1 + 0x68) = 0;
        local_14 = local_14 & 0xfffdffef | 0x40;
        uVar4 = FUN_005f9c2f(param_2);
        return uVar4;
      }
      cVar3 = FUN_005f98f3();
      if (cVar3 != '\0') {
        if (param_1[0x20] != 0) {
          (**(code **)(*param_1 + 0xf0))();
        }
        _memset(&local_18,0,0x14);
        local_18 = 0x14;
        local_10 = *(undefined4 *)(param_1[0x2f] + 4);
        local_8 = param_1 + 0x2a;
        local_14 = ((9 < param_1[0xe]) - 1 & 8) + 0x100e0 & 0xffffffbf | 0x20010;
        iVar5 = (**(code **)(*DAT_006fed6c + 0xc))(DAT_006fed6c,&local_18,param_1 + 0x20,0);
        if (iVar5 == 0) {
          _DAT_006fed50 = _DAT_006fed50 + 1;
          puVar2 = (undefined4 *)param_1[0x20];
          piVar1 = param_1 + 0x5e;
          iVar5 = (**(code **)*puVar2)(puVar2,&DAT_00677238,piVar1);
          if (iVar5 != 0) {
            *piVar1 = 0;
          }
          if ((char)param_1[0x6e] != '\0') {
            (**(code **)(*(int *)*piVar1 + 0x48))((int *)*piVar1,1,0);
          }
          goto LAB_005fb3c5;
        }
      }
    }
    else if ((char)param_2 != '\0') {
      (**(code **)(*param_1 + 0x28))();
      goto LAB_005fb2cd;
    }
    uVar4 = 0;
  }
  return uVar4;
}

