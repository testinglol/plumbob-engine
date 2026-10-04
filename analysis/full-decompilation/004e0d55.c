
void FUN_004e0d55(int param_1)

{
  int iVar1;
  HANDLE pvVar2;
  HANDLE pvVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 local_39c [4];
  undefined4 local_38c;
  undefined1 local_388 [516];
  undefined1 local_184;
  undefined4 local_183;
  undefined4 local_80 [2];
  undefined4 local_78;
  int local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_54;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004e0eba(s_Call_stack__006c95b4);
  FUN_004e0eba(s_Address_Frame_006c95f0);
  _memset(local_80,0,0x74);
  iVar1 = param_1;
  local_80[0] = *(undefined4 *)(param_1 + 0xb8);
  local_5c = *(undefined4 *)(param_1 + 0xc4);
  local_68 = *(int *)(param_1 + 0xb4);
  local_78 = 3;
  local_54 = 3;
  local_60 = 3;
  while( true ) {
    uVar10 = 0;
    puVar5 = local_80;
    uVar8 = 0;
    iVar4 = iVar1;
    uVar6 = DAT_006f2348;
    uVar9 = DAT_006f234c;
    pvVar2 = GetCurrentThread();
    pvVar3 = GetCurrentProcess();
    iVar4 = (*DAT_006f2344)(0x14c,pvVar3,pvVar2,puVar5,iVar4,uVar8,uVar6,uVar9,uVar10);
    if ((iVar4 == 0) || (local_68 == 0)) break;
    FUN_004e0eba(s__08X__08X_006c95e0,local_80[0],local_68);
    puVar7 = local_39c;
    local_39c[0] = 0x218;
    local_38c = 0x200;
    puVar5 = &param_1;
    param_1 = 0;
    uVar6 = local_80[0];
    pvVar2 = GetCurrentProcess();
    iVar4 = (*DAT_006f2350)(pvVar2,uVar6,puVar5,puVar7);
    if (iVar4 == 0) {
      local_184 = DAT_006de560;
      puVar5 = &local_183;
      for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      *(undefined2 *)puVar5 = 0;
      *(undefined1 *)((int)puVar5 + 2) = 0;
      local_c = 0;
      local_8 = 0;
      FUN_004e0bbc(local_80[0],&local_184,0x104,&local_c,&local_8);
      FUN_004e0eba(s__04X__08X__s_006c95c4,local_c,local_8,&local_184);
    }
    else {
      FUN_004e0eba(s__hs__X_006c95d4,local_388,param_1);
    }
  }
  return;
}

