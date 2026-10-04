
void FUN_004e0191(uint param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_c;
  uint *local_8;
  
  uVar1 = (uint)param_2;
  *(undefined4 *)(param_1 + 8) = 1;
  uVar5 = *(uint *)((int)param_2 + 0xc);
  *(undefined4 *)((int)param_2 + 8) = 1;
  iVar4 = *(int *)(param_1 + 0xc);
  FUN_0063560a(param_1 + 0x10,iVar4,4,&LAB_004e028d);
  FUN_0063560a((int)param_2 + 0x10,uVar5,4,&LAB_004e028d);
  uVar6 = 0;
  if (iVar4 != 0) {
    param_2 = (uint *)(param_1 + 0x10);
    local_c = iVar4;
    do {
      if (uVar6 < uVar5) {
        local_8 = (uint *)(uVar1 + 0x10 + uVar6 * 4);
        uVar3 = uVar6;
        do {
          if ((*local_8 & 0xfffff000) == (*param_2 & 0xfffff000)) {
            *(undefined4 *)(uVar1 + 0x10 + uVar3 * 4) = 0;
            uVar6 = uVar3 + 1;
            *param_2 = 0;
            break;
          }
          if ((*param_2 & 0xfffff000) < (*local_8 & 0xfffff000)) break;
          local_8 = local_8 + 1;
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar5);
      }
      param_2 = param_2 + 1;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  if (iVar4 != 0) {
    puVar2 = (uint *)(param_1 + 0x10);
    do {
      if ((param_1 <= (*puVar2 & 0xfffff000)) &&
         ((*puVar2 & 0xfffff000) < *(int *)(param_1 + 4) + param_1)) {
        *puVar2 = 0;
      }
      puVar2 = puVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (uVar5 != 0) {
    puVar2 = (uint *)(uVar1 + 0x10);
    do {
      if ((uVar1 <= (*puVar2 & 0xfffff000)) &&
         ((*puVar2 & 0xfffff000) < *(int *)(uVar1 + 4) + uVar1)) {
        *puVar2 = 0;
      }
      puVar2 = puVar2 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}

