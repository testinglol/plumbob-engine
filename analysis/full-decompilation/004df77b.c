
void FUN_004df77b(undefined4 param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 local_150;
  undefined4 local_14f;
  uint local_10;
  char local_c [8];
  
  puVar1 = (uint *)(param_2 + 0xc);
  param_2 = *(int *)(param_2 + 4);
  uVar3 = *puVar1 >> 0xc;
  FUN_004e066d(param_1,s_Block____08x___d_pages___d_bytes_006c8c70,param_2,uVar3,uVar3 << 0xc);
  if (uVar3 != 0) {
    do {
      local_10 = uVar3;
      FUN_00636510(&DAT_006f0fdc,param_2,0x1000);
      puVar4 = &DAT_006f0fdc;
      do {
        local_150 = 0;
        puVar5 = &local_14f;
        for (iVar2 = 0x4f; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        *(undefined2 *)puVar5 = 0;
        *(undefined1 *)((int)puVar5 + 2) = 0;
        iVar2 = 0;
        do {
          wsprintfA(local_c,s__02x_006c8c68,(uint)(byte)puVar4[iVar2]);
          FUN_006358c0(&local_150,local_c);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 0x40);
        iVar2 = 0;
        do {
          local_c[0] = puVar4[iVar2];
          if ((local_c[0] < ' ') || ('\x7f' < local_c[0])) {
            local_c[0] = '.';
          }
          local_c[1] = 0;
          FUN_006358c0(&local_150,local_c);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 0x40);
        FUN_006358c0(&local_150,&DAT_006c8578);
        FUN_004e066d(param_1,&DAT_006c08e0,&local_150);
        puVar4 = puVar4 + 0x40;
      } while ((int)puVar4 < 0x6f1fdc);
      param_2 = param_2 + 0x1000;
      uVar3 = local_10 - 1;
    } while (local_10 - 1 != 0);
    local_10 = 0;
  }
  FUN_004e066d(param_1,&DAT_006c8c60);
  return;
}

