
void __thiscall FUN_004ca589(int param_1,float param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  tagRECT local_4c;
  undefined1 local_3c [12];
  undefined1 local_30 [12];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = (int *)(param_1 + (0x15 - param_3) * 4);
  if (*(int *)(param_1 + (0x15 - param_3) * 4) == 0) {
    pvVar4 = operator_new(0x3fe);
    *piVar1 = (int)pvVar4;
    if (pvVar4 != (void *)0x0) {
      *piVar1 = (int)pvVar4 + 0x1fe;
      iVar5 = *(int *)((int)param_2 + 4);
      local_4c.left = *(int *)(iVar5 + 0x68);
      local_4c.top = *(int *)(iVar5 + 0x6c);
      local_4c.right = *(LONG *)(iVar5 + 0x70);
      local_4c.bottom = *(LONG *)(iVar5 + 0x74);
      OffsetRect(&local_4c,-local_4c.left,-local_4c.top);
      iVar5 = FUN_00415707();
      param_3 = -0xff;
      do {
        param_2 = 0.0;
        local_8 = 0;
        local_c = 0;
        FUN_004ca6b6(&local_24,&local_c,&local_8,&param_2);
        param_2 = (float)param_3;
        local_c = 0;
        local_8 = 0;
        FUN_004ca6b6(&local_18,&local_8,&local_c,&param_2);
        puVar6 = (undefined4 *)FUN_005c3840(local_30,&local_24,iVar5 + 0xec);
        local_24 = *puVar6;
        local_20 = puVar6[1];
        local_1c = puVar6[2];
        puVar6 = (undefined4 *)FUN_005c3840(local_3c,&local_18,iVar5 + 0xec);
        local_18 = *puVar6;
        local_14 = puVar6[1];
        local_10 = puVar6[2];
        uVar3 = __ftol();
        iVar2 = param_3 + 1;
        *(undefined2 *)(*piVar1 + param_3 * 2) = uVar3;
        param_3 = iVar2;
      } while (iVar2 < 0x100);
    }
  }
  return;
}

