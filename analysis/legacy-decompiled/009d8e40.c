
undefined4 FUN_009d8e40(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00c50350;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(code **)(param_3 + 0x80) != (code *)0x0) {
    local_8 = 0;
    iVar2 = (**(code **)(param_3 + 0x80))
                      (param_2,"vkAcquireNextImageKHR",DAT_00dd0b80 ^ (uint)&stack0xfffffffc);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      local_8 = 1;
      iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkAllocateCommandBuffers");
      param_1[1] = iVar2;
      if (iVar2 != 0) {
        local_8 = 2;
        iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkAllocateDescriptorSets");
        param_1[2] = iVar2;
        if (iVar2 != 0) {
          local_8 = 3;
          iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkAllocateMemory");
          param_1[3] = iVar2;
          if (iVar2 != 0) {
            local_8 = 4;
            iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkBindBufferMemory");
            param_1[4] = iVar2;
            if (iVar2 != 0) {
              local_8 = 5;
              iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkBindImageMemory");
              param_1[5] = iVar2;
              if (iVar2 != 0) {
                local_8 = 6;
                iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateBuffer");
                param_1[6] = iVar2;
                if (iVar2 != 0) {
                  local_8 = 7;
                  iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateCommandPool");
                  param_1[7] = iVar2;
                  if (iVar2 != 0) {
                    local_8 = 8;
                    iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateComputePipelines");
                    param_1[8] = iVar2;
                    if (iVar2 != 0) {
                      local_8 = 9;
                      iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateDescriptorPool");
                      param_1[9] = iVar2;
                      if (iVar2 != 0) {
                        local_8 = 10;
                        iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateDescriptorSetLayout")
                        ;
                        param_1[10] = iVar2;
                        if (iVar2 != 0) {
                          local_8 = 0xb;
                          iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateFence");
                          param_1[0xb] = iVar2;
                          if (iVar2 != 0) {
                            local_8 = 0xc;
                            iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateFramebuffer");
                            param_1[0xc] = iVar2;
                            if (iVar2 != 0) {
                              local_8 = 0xd;
                              iVar2 = (**(code **)(param_3 + 0x80))
                                                (param_2,"vkCreateGraphicsPipelines");
                              param_1[0xd] = iVar2;
                              if (iVar2 != 0) {
                                local_8 = 0xe;
                                iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateImage");
                                param_1[0xe] = iVar2;
                                if (iVar2 != 0) {
                                  local_8 = 0xf;
                                  iVar2 = (**(code **)(param_3 + 0x80))(param_2,"vkCreateImageView")
                                  ;
                                  param_1[0xf] = iVar2;
                                  if (iVar2 != 0) {
                                    local_8 = 0x10;
                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                      (param_2,"vkCreatePipelineLayout");
                                    param_1[0x10] = iVar2;
                                    if (iVar2 != 0) {
                                      local_8 = 0x11;
                                      iVar2 = (**(code **)(param_3 + 0x80))
                                                        (param_2,"vkCreateRenderPass");
                                      param_1[0x11] = iVar2;
                                      if (iVar2 != 0) {
                                        local_8 = 0x12;
                                        iVar2 = (**(code **)(param_3 + 0x80))
                                                          (param_2,"vkCreateSampler");
                                        param_1[0x12] = iVar2;
                                        if (iVar2 != 0) {
                                          local_8 = 0x13;
                                          iVar2 = (**(code **)(param_3 + 0x80))
                                                            (param_2,"vkCreateSemaphore");
                                          param_1[0x13] = iVar2;
                                          if (iVar2 != 0) {
                                            local_8 = 0x14;
                                            iVar2 = (**(code **)(param_3 + 0x80))
                                                              (param_2,"vkCreateShaderModule");
                                            param_1[0x14] = iVar2;
                                            if (iVar2 != 0) {
                                              local_8 = 0x15;
                                              iVar2 = (**(code **)(param_3 + 0x80))
                                                                (param_2,"vkCreateSwapchainKHR");
                                              param_1[0x15] = iVar2;
                                              local_8 = 0xffffffff;
                                              if (iVar2 != 0) {
                                                cVar1 = FUN_009d8de0("vkDestroyBuffer",
                                                                     param_1 + 0x16);
                                                if (cVar1 != '\0') {
                                                  cVar1 = FUN_009d8de0("vkDestroyCommandPool",
                                                                       param_1 + 0x17);
                                                  if (cVar1 != '\0') {
                                                    cVar1 = FUN_009d8de0("vkDestroyDescriptorPool",
                                                                         param_1 + 0x18);
                                                    if (cVar1 != '\0') {
                                                      cVar1 = FUN_009d8de0(
                                                  "vkDestroyDescriptorSetLayout",param_1 + 0x19);
                                                  if (cVar1 != '\0') {
                                                    cVar1 = FUN_009d8de0("vkDestroyFence",
                                                                         param_1 + 0x1a);
                                                    if (cVar1 != '\0') {
                                                      cVar1 = FUN_009d8de0("vkDestroyFramebuffer",
                                                                           param_1 + 0x1b);
                                                      if (cVar1 != '\0') {
                                                        cVar1 = FUN_009d8de0("vkDestroyImage",
                                                                             param_1 + 0x1c);
                                                        if (cVar1 != '\0') {
                                                          cVar1 = FUN_009d8de0("vkDestroyImageView",
                                                                               param_1 + 0x1d);
                                                          if (cVar1 != '\0') {
                                                            cVar1 = FUN_009d8de0("vkDestroyPipeline"
                                                                                 ,param_1 + 0x1e);
                                                            if (cVar1 != '\0') {
                                                              cVar1 = FUN_009d8de0(
                                                  "vkDestroyPipelineLayout",param_1 + 0x1f);
                                                  if (cVar1 != '\0') {
                                                    cVar1 = FUN_009d8de0("vkDestroyRenderPass",
                                                                         param_1 + 0x20);
                                                    if (cVar1 != '\0') {
                                                      cVar1 = FUN_009d8de0("vkDestroySampler",
                                                                           param_1 + 0x21);
                                                      if (cVar1 != '\0') {
                                                        cVar1 = FUN_009d8de0("vkDestroySemaphore",
                                                                             param_1 + 0x22);
                                                        if (cVar1 != '\0') {
                                                          cVar1 = FUN_009d8de0(
                                                  "vkDestroyShaderModule",param_1 + 0x23);
                                                  if (cVar1 != '\0') {
                                                    cVar1 = FUN_009d8de0("vkDestroySwapchainKHR",
                                                                         param_1 + 0x24);
                                                    if (cVar1 != '\0') {
                                                      local_8 = 0x16;
                                                      iVar2 = (**(code **)(param_3 + 0x80))
                                                                        (param_2,"vkDeviceWaitIdle")
                                                      ;
                                                      param_1[0x25] = iVar2;
                                                      if (iVar2 != 0) {
                                                        local_8 = 0x17;
                                                        iVar2 = (**(code **)(param_3 + 0x80))
                                                                          (param_2,
                                                  "vkFlushMappedMemoryRanges");
                                                  param_1[0x26] = iVar2;
                                                  if (iVar2 != 0) {
                                                    local_8 = 0x18;
                                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                                      (param_2,
                                                  "vkFreeCommandBuffers");
                                                  param_1[0x27] = iVar2;
                                                  if (iVar2 != 0) {
                                                    local_8 = 0x19;
                                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                                      (param_2,
                                                  "vkFreeDescriptorSets");
                                                  param_1[0x28] = iVar2;
                                                  local_8 = 0xffffffff;
                                                  if (iVar2 != 0) {
                                                    cVar1 = FUN_009d8de0("vkFreeMemory",
                                                                         param_1 + 0x29);
                                                    if (cVar1 != '\0') {
                                                      local_8 = 0x1a;
                                                      iVar2 = (**(code **)(param_3 + 0x80))
                                                                        (param_2,
                                                  "vkGetBufferMemoryRequirements");
                                                  param_1[0x2a] = iVar2;
                                                  if (iVar2 != 0) {
                                                    local_8 = 0x1b;
                                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                                      (param_2,"vkGetDeviceQueue");
                                                    param_1[0x2b] = iVar2;
                                                    if (iVar2 != 0) {
                                                      local_8 = 0x1c;
                                                      iVar2 = (**(code **)(param_3 + 0x80))
                                                                        (param_2,"vkGetFenceStatus")
                                                      ;
                                                      param_1[0x2c] = iVar2;
                                                      if (iVar2 != 0) {
                                                        local_8 = 0x1d;
                                                        iVar2 = (**(code **)(param_3 + 0x80))
                                                                          (param_2,
                                                  "vkGetImageMemoryRequirements");
                                                  param_1[0x2d] = iVar2;
                                                  if (iVar2 != 0) {
                                                    local_8 = 0x1e;
                                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                                      (param_2,
                                                  "vkGetSwapchainImagesKHR");
                                                  param_1[0x2e] = iVar2;
                                                  if (iVar2 != 0) {
                                                    local_8 = 0x1f;
                                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                                      (param_2,
                                                  "vkInvalidateMappedMemoryRanges");
                                                  param_1[0x2f] = iVar2;
                                                  if (iVar2 != 0) {
                                                    local_8 = 0x20;
                                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                                      (param_2,"vkMapMemory");
                                                    param_1[0x30] = iVar2;
                                                    if (iVar2 != 0) {
                                                      local_8 = 0x21;
                                                      iVar2 = (**(code **)(param_3 + 0x80))
                                                                        (param_2,"vkQueuePresentKHR"
                                                                        );
                                                      param_1[0x31] = iVar2;
                                                      if (iVar2 != 0) {
                                                        local_8 = 0x22;
                                                        iVar2 = (**(code **)(param_3 + 0x80))
                                                                          (param_2,"vkQueueSubmit");
                                                        param_1[0x32] = iVar2;
                                                        if (iVar2 != 0) {
                                                          local_8 = 0x23;
                                                          iVar2 = (**(code **)(param_3 + 0x80))
                                                                            (param_2,
                                                  "vkQueueWaitIdle");
                                                  param_1[0x33] = iVar2;
                                                  if (iVar2 != 0) {
                                                    local_8 = 0x24;
                                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                                      (param_2,"vkResetCommandPool")
                                                    ;
                                                    param_1[0x34] = iVar2;
                                                    if (iVar2 != 0) {
                                                      local_8 = 0x25;
                                                      iVar2 = (**(code **)(param_3 + 0x80))
                                                                        (param_2,"vkResetFences");
                                                      param_1[0x35] = iVar2;
                                                      if (iVar2 != 0) {
                                                        local_8 = 0x26;
                                                        iVar2 = (**(code **)(param_3 + 0x80))
                                                                          (param_2,"vkUnmapMemory");
                                                        param_1[0x36] = iVar2;
                                                        if (iVar2 != 0) {
                                                          local_8 = 0x27;
                                                          iVar2 = (**(code **)(param_3 + 0x80))
                                                                            (param_2,
                                                  "vkUpdateDescriptorSets");
                                                  param_1[0x37] = iVar2;
                                                  if (iVar2 != 0) {
                                                    local_8 = 0x28;
                                                    iVar2 = (**(code **)(param_3 + 0x80))
                                                                      (param_2,"vkWaitForFences");
                                                    param_1[0x38] = iVar2;
                                                    if (iVar2 != 0) {
                                                      ExceptionList = local_10;
                                                      return 1;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}

